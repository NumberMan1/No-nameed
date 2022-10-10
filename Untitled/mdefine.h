#ifndef MDEFINE_H
#define MDEFINE_H

#include <QString>

// 单纯用来测试的宏
#define TEXTVALUE 20

namespace Garden {

class MDefine
{
public:
    MDefine() = delete;
    MDefine(const MDefine&) = delete;
    MDefine(MDefine&&) = delete;
    MDefine& operator=(const MDefine*) = delete;
    MDefine& operator=(MDefine&&) = delete;

    // 窗口大小
    static const int backGroundWidth = 1280,
                     backGroundHeight = 720;

    // 植物大小
    static const int plantWidth = 160,
                     plantHeight = 181;

    // 资源文件的路径
    static const QString sunFlowerName,
                         gloveName,
                         shovelName,
                         backGroundName,
                         loadingName;
    
    // 铲子和手套等工具
    static const int shovelWidth = 160,
                     shovelHeight = 181,
                     gloveWidth = 160,
                     gloveHeight = 181;

    // 所需操作
    enum class TheRequiredOperating {

    };
};



} // namespace Garen

#endif // MDEFINE_H
