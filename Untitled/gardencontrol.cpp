#include "gardencontrol.h"
#include <QDebug>
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
    
    mInstance->mBackGroundPixmap.setPixmap(QPixmap(MDefine::loadingName));
    mInstance->mScene.setSceneRect
               (0, 0, MDefine::backGroundWidth, MDefine::backGroundHeight);
    mInstance->mUI->view->setScene(&mScene);

    // xml初始化
    QDomDocument doc;
    

    // 背景
    mInstance->mBackGroundPixmap.setPixmap(QPixmap(MDefine::backGroundName));
    mInstance->mScene.addItem(&mBackGroundPixmap);

}
