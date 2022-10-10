#ifndef GARDENCONTROL_H
#define GARDENCONTROL_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QDomDocument>
#include <QGraphicsPixmapItem>

#include "gardenitem.h"

namespace Garden {

// 花园的控制模块
class GardenControl : public QObject
{
public:
    explicit GardenControl(QObject *parent);
    ~GardenControl();
    // 调用实例
    inline static GardenControl* Instance(QObject *parent) {
        if (!mInstance) {
            mInstance = new GardenControl(parent);
            return mInstance;
        } else {
            return mInstance;
        }
    }

    // 初始化花园
    void Init();

private:
    static GardenControl *mInstance;

    // 视图
    QGraphicsView mView;
    QGraphicsScene mScene;

    // 场景元素
    QGraphicsPixmapItem *mBackGroundPixmap;

    // 定时器


    // 容器


    // 背景音乐
    QMediaPlayer* mMediaPlayer;


};

} // namespace Garden

#endif // GARDENCONTROL_H
