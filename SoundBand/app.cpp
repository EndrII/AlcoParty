#include "app.h"
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "syncengine.h"
#include "imageprovider.h"
#include "serverlistmodel.h"


App::App(QObject* ptr):
    QObject(ptr)
{
    qmlEngine = new QQmlApplicationEngine();
    syncEngine = new SyncEngine();
    imageProvider = new ImageProvider(syncEngine);
    serverListModel = new ServerListModel();
    serverListModel->setSource(syncEngine);
}

bool App::run(){


    qmlEngine->addImageProvider(QLatin1String("collection"), imageProvider);

    QQmlContext *ctxt = qmlEngine->rootContext();
    ctxt->setContextProperty("syncEngine", syncEngine);
    ctxt->setContextProperty("serverListModel", serverListModel);

    qmlEngine->load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (qmlEngine->rootObjects().isEmpty())
        return false;

    return true;
}

App::~App(){
    delete serverListModel;
    delete syncEngine;
    delete qmlEngine;
}
