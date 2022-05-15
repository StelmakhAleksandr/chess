QT += quick

HEADERS += \
    src/app.h

SOURCES += \
        src/app.cpp \
        src/main.cpp

resources.files = qml/main.qml
resources.prefix = /$${TARGET}
RESOURCES += resources

TRANSLATIONS += \
    translations/chess_ru_RU.ts \
    translations/chess_uk_UA.ts

CONFIG += lrelease
CONFIG += embed_translations

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=


