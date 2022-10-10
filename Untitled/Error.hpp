#pragma once
#include <chrono>
#include <exception>
#include <fstream>
#include <iostream>
#include <stdexcept>

/*
  ERROR:
     辅助类Time, 异常类ErrorCode, 函数operator<<

     ErrorCode 实现异常信息与 log 日志的记录    PS: log 文件未打开, 程序直接崩溃

     operator<< 实现所有异常类的 log 记录, 全局空间直接调用

     例:
    try {
            throw ERROR::ErrorCode(__FILE__, __func__, __LINE__, "实验");
  //位置信息 } catch (exception const &err) { err << __FILE__ << ' ' << ' ' <<
  __func__ << ' ' << __LINE__;     //续写信息
        }
 */
namespace ERROR {
using namespace std;

struct Time {
  static char *Now() noexcept {  
    using namespace std::chrono;
    auto &&time = system_clock::now();
    time_t &&tt = system_clock::to_time_t(time); //数据截断
    auto &&time_tm = localtime(&tt);             // C格式函数

    sprintf(strTime, "%d-%02d-%02d %02d:%02d:%02d", time_tm->tm_year + 1900,
            time_tm->tm_mon + 1, time_tm->tm_mday, time_tm->tm_hour,
            time_tm->tm_min, time_tm->tm_sec);

    return strTime;
  }

private:
  static inline char strTime[20]{};
};

struct ErrorCode final : runtime_error { //方便捕获时对象切片
  ~ErrorCode() noexcept override;
  ErrorCode(ErrorCode const &) = delete; //禁止异常传递过程的拷贝
  ErrorCode(char const *file, char const *func, unsigned line,
            string const &massage) noexcept;

  friend exception const &operator<<(exception const &,
                                     auto &&); //访问文件的友元声明

private:
  static void Over() { //终止函数
    log << "\n------------------------------------------------------------\n"
           "                     异常扩散 , 程序终止                         "
           "\n------------------------------------------------------------\n"
        << "崩溃时间: " << Time::Now() << '\n';
    log.close();
  }

private:
  ofstream inline static log{"../File/Log.dat", ios::app};
  chrono::time_point inline static startTime = chrono::system_clock::now();
};

std::exception const &operator<<(std::exception const &err, auto &&what) {
  ErrorCode::log.is_open() ? ErrorCode::log << what : throw;
  return err;
}

using FileError = ErrorCode;
} // namespace ERROR
using ERROR::operator<<; //全局注入命名空间