#ifndef CADO_ERRORS_ERROR_HPP_
#define CADO_ERRORS_ERROR_HPP_

#include <string>
#include "cado/errors/Export.hpp"

namespace cado {
namespace errors {

class CADO_API Error {
public:
  Error();
  Error(const Error &);  
  Error(const std::string &);
  ~Error();
  Error& operator=(const Error &);
  bool operator==(const Error &) const;
  bool operator!=(const Error &) const;
  const std::string& What() const;
  bool Is() const;
private:
  class Pimpl {
  public:
    Pimpl(const std::string &, const Error *, bool);
    Pimpl(const Pimpl&);  
    std::string msg_;
    bool is_;
    const Error* errRef_;
  };
  Pimpl* pimpl_;
};

class CADO_API WError{
public:
  WError();
  WError(const WError &);
  WError(const std::wstring &);
  ~WError();
  WError& operator=(const WError &);
  bool operator==(const WError &) const;
  bool operator!=(const WError &) const;
  const std::wstring& What() const;
  bool Is() const;
private:
  class Pimpl {
  public:
    Pimpl(const std::wstring &, const WError *, bool);
    Pimpl(const Pimpl&);  
    std::wstring msg_;
    bool is_;
    const WError* errRef_;
  };
  Pimpl* pimpl_;
};

}
}


#endif //!CADO_ERRORS_ERROR_HPP_

