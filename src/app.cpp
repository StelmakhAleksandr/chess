#include "app.h"

using namespace chess;

App::App(int argc, char *argv[]) : app_(argc, argv) {

}

int App::exec() {
    initTranslator();
    initEngine();
    return app_.exec();
}

void App::initTranslator() {
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "chess_" + QLocale(locale).name();
        if (translator_.load(":/i18n/" + baseName)) {
            app_.installTranslator(&translator_);
            break;
        }
    }
}

void App::initEngine() {
    const QUrl url(u"qrc:/chess/qml/main.qml"_qs);
    QObject::connect(&engine_, &QQmlApplicationEngine::objectCreated,
    &app_, [url](QObject * obj, const QUrl & objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine_.load(url);
}


