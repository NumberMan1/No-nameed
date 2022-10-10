#ifndef GARDENITEM_H
#define GARDENITEM_H

#include "mobjectbybtn.h"
#include "mdefine.h"

namespace Garden {
    
// 植物================================
class Plant : public MObjectByBtn
{
public:
    enum PlantGrowUpTime : int { // 以秒为单位
        SunFlowerGrowTime = TEXTVALUE 
    };
    enum PlantValue : int {
        SunFlowerValue = TEXTVALUE
    };
    // 用于初始化
    enum class PlantType {
        SunFlower
    };
    explicit Plant(QWidget *parent,
                   const PlantType& _plantType);
    virtual ~Plant();

    // 鼠标
    virtual void dragMoveEvent(QDragMoveEvent *event) override;


private:
    int mGrowTime,
        mValue;
    void SetPlant(const PlantType& _plantType) noexcept;
    void TimeToMakeCoin();
};

// 铲子=======================================
class Shovel : public MObjectByBtn
{
public:
    explicit Shovel(QWidget *parent = nullptr);
    virtual ~Shovel();
    inline Shovel* Instance(QWidget *parent = nullptr) {
        if (!mShovel) {
            mShovel = new Shovel(parent);
            return mShovel;
        } else {
            return mShovel;
        }
    }

    // 鼠标
    virtual void dragMoveEvent(QDragMoveEvent *event) override;
private:
    Shovel *mShovel;
};

// 手套========================================
class Glove : public MObjectByBtn 
{
public:
    explicit Glove(QWidget *parent = nullptr);
    virtual ~Glove();
    inline Glove* Instance(QWidget *parent = nullptr) {
        if (!mGlove) {
            mGlove = new Glove(parent);
            return mGlove;
        } else {
            return mGlove;
        }
    }

private:
    Glove *mGlove;
};

} // namespace Garden


#endif // GARDENITEM_H
