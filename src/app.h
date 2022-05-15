#pragma once

#include <QObject>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QLocale>
#include <QTranslator>

namespace chess {
class App {
  public:
    App(int argc, char *argv[]);
    int exec();
  private:
    QGuiApplication app_;
    QTranslator translator_;
    QQmlApplicationEngine engine_;
    void initTranslator();
    void initEngine();
};
}

