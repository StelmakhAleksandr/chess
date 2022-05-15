#include "app.h"

#include <QDebug>
#include <QDir>
#include <QQmlContext>
#include <QVariant>

using namespace chess;

App::App(int argc, char *argv[]) : QObject(nullptr), app_(argc, argv) {

}

int App::exec() {
    initTranslator();
    initEngine();
    QDir dir(":/i18n/");
    QStringList fileNames = dir.entryList(QStringList("*.qm"), QDir::Files,
                                          QDir::Name);
    qDebug() << fileNames.size();
    for (QString &fileName : fileNames) {
        fileName = dir.filePath(fileName);
        qDebug() << fileName;
    }

    return app_.exec();
}

void App::changeLanguage(QString languageName) {
    if(!translator_.load(":/i18n/" + languageName)) {
        qDebug() << "fail load " << languageName;
    }
    emit languageChanged();
    engine_.retranslate();
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
    engine_.rootContext()->setContextProperty("App", this);

    const QUrl url(u"qrc:/chess/qml/main.qml"_qs);
    QObject::connect(&engine_, &QQmlApplicationEngine::objectCreated,
    &app_, [url](QObject * obj, const QUrl & objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine_.load(url);
}


