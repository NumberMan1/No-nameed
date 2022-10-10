#include "Error.hpp"

ERROR::ErrorCode::ErrorCode(
    char const *file, char const *func, unsigned line,
    string const &massage) noexcept // runtine_error 适应 exception 接口
    : runtime_error("\n异常信息: " + massage + "\n运行时长: " +
                    to_string(duration_cast<chrono::seconds>(
                                  chrono::system_clock::now() - startTime)
                                  .count()) +
                    "\n错误时间: " + Time::Now() +

                    "\n编译时间: " + __DATE__ + ' ' + __TIME__ +
                    "\n位置: 文件( " + file + " ) 函数( " + func + " ) 行数( " +
                    to_string(line) + " )\n") {
  if (bool static thread_local over = true; over) { //多线程预留接口
    over = false;
    set_terminate(Over);
  }

  *this << what();
}

ERROR::ErrorCode::~ErrorCode() noexcept {
  *this << "( 捕获位置 ) " << Time::Now() << "( 捕获时间 ), 异常已处理\n";
}
