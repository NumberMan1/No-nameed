#include "mobjectbybtn.h"

MObjectByBtn::MObjectByBtn(const ObjectType& _type,
                           QWidget* parent)
    : mType(_type)
    , QToolButton(parent)
{
    
}

MObjectByBtn::~MObjectByBtn() {}
