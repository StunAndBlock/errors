#ifndef CADO_ERRORS_UTILS_HPP_
#define CADO_ERRORS_UTILS_HPP_

#include <cado/errors/error.hpp>
#include <cstdarg>
#include <memory>
namespace cado {
namespace errors {
inline bool is(Error src, Error target) {
  return src == target;
}
inline Error new_e(const std::string &msg) {
  return std::make_shared<BaseError>(msg);
}
//
// inline Error new_e(const IError *err) {
//   return Error{err};
// }
inline Error format(const char *format, ...) {
  va_list args;
  va_start(args, format);
  va_list args_copy;
  va_copy(args_copy, args);
  int size = vsnprintf(nullptr, 0, format, args_copy) + 1;
  va_end(args_copy);
  char *buffer = new char[size];
  vsnprintf(buffer, size, format, args);
  Error err = new_e(buffer);
  delete[] buffer;
  return err;
}
} // namespace errors
} // namespace cado

#endif // CADO_ERRORS_UTILS_HPP_
