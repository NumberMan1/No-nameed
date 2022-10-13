#ifndef GARDENCONTROL_H
#define GARDENCONTROL_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QDomDocument>
#include <QGraphicsPixmapItem>
#include <QMainWindow>

#include "gardenitem.h"

namespace Ui {
class GardenUI;
}

namespace Garden {

// 花园的控制模块
class GardenControl : public QObject
{
public:
    ~GardenControl();
    // 调用实例
    inline static
    GardenControl* Instance(QObject *parent,
                            QMainWindow *_mainWindow) {
        if (!mInstance) {
            mInstance = new GardenControl(parent, _mainWindow);
            return mInstance;
        } else {
            return mInstance;
        }
    }

    // 初始化花园
    void Init();

private:
    explicit GardenControl(QObject *parent, QMainWindow *_mainWindow);
    static GardenControl *mInstance;
    Ui::GardenUI *mUI;

    // 视图
    QGraphicsScene mScene;

    // 场景元素
    QGraphicsPixmapItem mBackGroundPixmap;
    Shovel *mShovel;
    Glove *mGlove;

    // 定时器


    // 容器


    // 背景音乐
    QMediaPlayer* mMediaPlayer;


};

} // namespace Garden

#endif // GARDENCONTROL_H
