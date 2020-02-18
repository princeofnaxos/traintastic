QT += core gui widgets network

TARGET = traintastic-client
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

greaterThan(QT_MINOR_VERSION, 11): { # >= 5.12
  CONFIG += c++17
} else {
  QMAKE_CXXFLAGS += -std=c++17
}

INCLUDEPATH += \
  ../shared/src \
  thirdparty

SOURCES += \
    src/main.cpp \
    src/mainwindow.cpp \
    src/dialog/connectdialog.cpp \
    src/network/client.cpp \
    src/network/object.cpp \
    thirdparty/QtWaitingSpinner/waitingspinnerwidget.cpp \
    src/widget/alertwidget.cpp \
    src/network/utils.cpp \
    src/network/tablemodel.cpp \
    src/widget/serverconsolewidget.cpp \
    src/widget/tablewidget.cpp \
    src/widget/objectlistwidget.cpp \
    src/widget/decoderlistwidget.cpp \
    src/widget/commandstationlistwidget.cpp \
    src/widget/objecteditwidget.cpp \
    src/widget/serversettingswidget.cpp \
    src/network/property.cpp \
    src/network/interfaceitems.cpp \
    src/network/interfaceitem.cpp \
    src/widget/propertycheckbox.cpp \
    src/widget/propertylineedit.cpp \
    src/widget/propertyspinbox.cpp \
    src/widget/propertydirectioncontrol.cpp \
    src/widget/propertytextedit.cpp \
    src/widget/propertyvaluelabel.cpp \
    src/network/objectproperty.cpp \
    src/widget/luascriptlistwidget.cpp \
    src/widget/propertycombobox.cpp \
    src/widget/inputlistwidget.cpp \
    src/subwindow/objectsubwindow.cpp \
    src/widget/createwidget.cpp

HEADERS += \
    src/mainwindow.hpp \
    src/dialog/connectdialog.hpp \
    src/network/client.hpp \
    src/network/object.hpp \
    ../shared/src/message.hpp \
    thirdparty/QtWaitingSpinner/waitingspinnerwidget.h \
    src/widget/alertwidget.hpp \
    src/network/utils.hpp \
    src/network/tablemodel.hpp \
    src/network/tablemodelptr.hpp \
    src/network/handle.hpp \
    src/network/objectptr.hpp \
    src/widget/serverconsolewidget.hpp \
    src/widget/tablewidget.hpp \
    src/widget/objectlistwidget.hpp \
    src/widget/commandstationlistwidget.hpp \
    src/widget/decoderlistwidget.hpp \
    src/widget/objecteditwidget.hpp \
    src/widget/serversettingswidget.hpp \
    src/network/property.hpp \
    src/network/interfaceitems.hpp \
    src/network/interfaceitem.hpp \
    src/widget/propertycheckbox.hpp \
    src/network/abstractproperty.hpp \
    src/widget/propertylineedit.hpp \
    src/widget/propertyspinbox.hpp \
    src/widget/propertydirectioncontrol.hpp \
    src/widget/propertytextedit.hpp \
    src/widget/propertyvaluelabel.hpp \
    src/network/objectproperty.hpp \
    src/widget/luascriptlistwidget.hpp \
    src/widget/propertycombobox.hpp \
    src/widget/inputlistwidget.hpp \
    src/subwindow/objectsubwindow.hpp \
    src/widget/createwidget.hpp

RESOURCES += \
    dark.qrc
