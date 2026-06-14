#ifndef CADO_ERRORS_ERRORS_HPP_
#define CADO_ERRORS_ERRORS_HPP_

#include "cado/errors/Error.hpp"

namespace cado {
namespace errors {
class CADO_API Errors {
public:
  Errors() = delete;
  ~Errors() = delete;
  static Error Format(const char*, ...);
  static WError Format(const wchar_t *, ...);
  static Error MakeReferenceOf(Error&, const Error&);
  static WError MakeReferenceOf(WError&, const WError&);
  static bool IsReferenceOf(const Error&, const Error&);
  static bool IsReferenceOf(const WError&, const WError&);
  };  
}
}



#endif //!CADO_ERRORS_ERRORS_HPP_

