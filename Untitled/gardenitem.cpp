#include "gardenitem.h"

// 植物=============================================
Garden::Plant::Plant(QWidget *parent,
                     const PlantType& _plantType)
    : MObjectByBtn(ObjectType::Plant, parent)
{
    SetPlant(_plantType);
}

Garden::Plant::~Plant() {
    qDebug() << "Plant 销毁";
}

// 依据PlantType进行初始化
void Garden::Plant::SetPlant(const PlantType& _plantType) {
    switch (_plantType)
    {
    case PlantType::SunFlower : {
        mGrowTime = PlantGrowUpTime::SunFlowerGrowTime;
        mValue = PlantValue::SunFlowerValue;
        this->setFixedSize(MDefine::plantWidth, MDefine::plantHeight);
        this->setIcon(QIcon(MDefine::sunFlowerName));
        this->setIconSize(QSize(MDefine::plantWidth, MDefine::plantHeight));
        this->setAutoRaise(true);
        break;
    }
    
    default:
        break;
    }
}

// 铲子=========================================
Garden::Shovel::Shovel(QWidget *parent)
    : MObjectByBtn(ObjectType::Shovel, parent)
    , mShovel(nullptr)
{
    this->setFixedSize(MDefine::shovelWidth, MDefine::shovelHeight);
    this->setIcon(QIcon(MDefine::shovelName));
    this->setIconSize(QSize(MDefine::shovelWidth, MDefine::shovelHeight));
    this->setAutoRaise(true);
}

Garden::Shovel::~Shovel() {
    qDebug() << "shovel 销毁";
    if (mShovel) {
        mShovel->deleteLater();
    }
}

// 手套=========================================

Garden::Glove::Glove(QWidget *parent) 
    : MObjectByBtn(ObjectType::Glove, parent)
    , mGlove(nullptr)
{
    this->setFixedSize(MDefine::gloveWidth, MDefine::gloveHeight);
    this->setIcon(QIcon(MDefine::gloveName));
    this->setIconSize(QSize(MDefine::gloveWidth, MDefine::gloveHeight));
    this->setAutoRaise(true);
}

Garden::Glove::~Glove() {
    qDebug() << "glove 销毁";
    if (mGlove) {
        mGlove->deleteLater();
    }
}