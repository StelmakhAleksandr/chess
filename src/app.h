#pragma once

#include <QObject>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QLocale>
#include <QTranslator>

namespace chess {
class App : public QObject {
    Q_OBJECT
  public:
    App(int argc, char *argv[]);
    int exec();
  signals:
    void languageChanged();
  public slots:
    void changeLanguage(QString);
  private:
    QGuiApplication app_;
    QTranslator translator_;
    QQmlApplicationEngine engine_;
    void initTranslator();
    void initEngine();
};
}

