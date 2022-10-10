#include "gardencontrol.h"
#include <QDebug>

Garden::GardenControl* Garden::GardenControl::mInstance = nullptr;

Garden::GardenControl::GardenControl(QObject *parent)
    : QObject(parent)
{

}

Garden::GardenControl::~GardenControl() {
    if (mInstance) {
        mInstance->deleteLater();
    }
    qDebug() << "GardenControl 销毁";
}

void Garden::GardenControl::Init() {
    mInstance->mScene.setSceneRect
               (0, 0, MDefine::backGroundWidth, MDefine::backGroundHeight);
    mInstance->mView.setScene(&mScene);
    // 背景
    mInstance->mBackGroundPixmap->setPixmap(QPixmap(MDefine::backGroundName));
    mInstance->mScene.addItem(mBackGroundPixmap);

    
}