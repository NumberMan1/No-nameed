#ifndef MOBJECTBYBTN_H
#define MOBJECTBYBTN_H

#include <QToolButton>

// 用于按钮基类
class MObjectByBtn : public QToolButton
{
public:
    // 判断分类
    enum class ObjectType {
        Plant,
        Shovel,
        Glove
    };
    explicit MObjectByBtn(const ObjectType& _type,  
                          QWidget* parent = nullptr);
    virtual ~MObjectByBtn();
    inline ObjectType GetType() const {
        return mType;
    }

private:
    ObjectType mType;
};

#endif // MOBJECTBYBTN_H
