#include "gardencontrol.h"
#include <QDebug>
#include <QFile>
#include <QRegularExpression>
#include "./ui_Garden.h"

Garden::GardenControl* Garden::GardenControl::mInstance = nullptr;

Garden::GardenControl::GardenControl(QObject *parent, QMainWindow *_mainWindow)
    : QObject(parent)
    , mUI(new Ui::GardenUI)
{
    mUI->setupUi(_mainWindow);
}

Garden::GardenControl::~GardenControl() {
    if (mInstance) {
        mInstance->deleteLater();
    }
    delete mUI;
    qDebug() << "GardenControl 销毁";
}

void Garden::GardenControl::Init() {
    
    mBackGroundPixmap.setPixmap(QPixmap(MDefine::loadingName));
    mScene.setSceneRect
               (0, 0, MDefine::backGroundWidth, MDefine::backGroundHeight);
    mUI->view->setScene(&mScene);

    // xml初始化
    {
    
    QFile file(MDefine::gardenXML);
    if (!file.open(QIODeviceBase::ReadOnly)) {
        throw std::logic_error("gardenXML文件打开失败");
    }
    QDomDocument doc; // 初始化花盆植物
    doc.setContent(file.readAll());
    auto root = doc.firstChildElement("Root");
    auto PlantMap = root.firstChildElement("PlantMap");
    auto PlantMapDesc = PlantMap.text();
    using Line = QList<QString>;
    Line rowLine = PlantMapDesc.split('\n');
    for (int i = 1; i != 4; ++i) {
        rowLine[i].replace("        ", "");
    }

    qDebug() << PlantMapDesc;

    }

    // 背景
    mBackGroundPixmap.setPixmap(QPixmap(MDefine::backGroundName));
    mScene.addItem(&mBackGroundPixmap);

}
