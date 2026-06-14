#include <cstdarg>
#include <cwchar>
#include "cado/errors/Errors.hpp"

namespace cado {
namespace errors {

Error Errors::Format(const char* format, ...) {
      va_list args;
      va_start(args, format);
      va_list args_copy;
      va_copy(args_copy, args);
      int size = vsnprintf(nullptr, 0, format, args_copy) + 1;
      va_end(args_copy);
      char *buffer = new char[size];
      vsnprintf(buffer, size, format, args);
      Error err = Error(buffer);
      delete[] buffer;
      return err;
}

WError Errors::Format(const wchar_t* format, ...) {
      va_list args;
      va_start(args, format);
      va_list args_copy;
      va_copy(args_copy, args);
      int size = vswprintf(nullptr, 0, format, args_copy) + 1;
      va_end(args_copy);
      wchar_t *buffer = new wchar_t[size];
      vswprintf(buffer, size, format, args);
      WError err = WError(buffer);
      delete[] buffer;
      return err;
}
Error Errors::MakeReferenceOf(Error &err, const Error &errRef) {
  err = Error(errRef);
  return err;
}
WError Errors::MakeReferenceOf(WError &err, const WError &errRef) {
  err = WError(errRef);
  return err;
}

bool Errors::IsReferenceOf(const Error &err, const Error &errRef) {
  return err == errRef;
}
bool Errors::IsReferenceOf(const WError &err, const WError &errRef) {
  return err == errRef;
}  
}
}
