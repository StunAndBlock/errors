#include "cado/errors/Error.hpp"


namespace cado {
namespace errors {
Error::Pimpl::Pimpl(const std::string &msg, const Error *errRef, bool is) {
  msg_ = msg;
  errRef_ = errRef;
  is_ = is;
}
Error::Pimpl::Pimpl(const Error::Pimpl& pimplErr) {
  msg_ = pimplErr.msg_;
  errRef_ = pimplErr.errRef_;
  is_ = pimplErr.is_;
}

Error::Error() {
  pimpl_ = new Pimpl("", nullptr, false);
}

Error::Error(const Error& errRef) {
  pimpl_ = new Pimpl("", &errRef, true);
}


Error::Error(const std::string &msg) {
  pimpl_ = new Pimpl(msg, nullptr, true);
}
Error::~Error() {
  delete pimpl_;
}  
Error& Error::operator=(const Error& other) {
  if (this == &other){
        return *this;
  }
  delete pimpl_;
  pimpl_ = new Pimpl(*other.pimpl_);
  return *this;
}
bool Error::operator==(const Error& other) const {
  if (pimpl_->errRef_ == &other) {
    return true;
  }
  return false;
}
bool Error::operator!=(const Error& other) const {
  return !(*this == other);
}
const std::string& Error::What() const {
  if (pimpl_->errRef_ == nullptr) {
    return pimpl_->msg_;
  }
  return pimpl_->errRef_->What();
}
bool Error::Is() const {
  return pimpl_->is_;
}


WError::Pimpl::Pimpl(const std::wstring &msg, const WError *errRef, bool is) {
  msg_ = msg;
  errRef_ = errRef;
  is_ = is;
}
WError::Pimpl::Pimpl(const WError::Pimpl& pimplErr) {
  msg_ = pimplErr.msg_;
  errRef_ = pimplErr.errRef_;
  is_ = pimplErr.is_;
}

WError::WError() {
  pimpl_ = new Pimpl(L"", nullptr, false);
}

WError::WError(const WError& errRef) {
  pimpl_ = new Pimpl(L"", &errRef, true);
}

WError::WError(const std::wstring &msg) {
  pimpl_ = new Pimpl(msg, nullptr, true);
}
WError::~WError() {
  delete pimpl_;
}  
WError& WError::operator=(const WError& other) {
  if (this == &other){
        return *this;
  }
  delete pimpl_;
  pimpl_ = new Pimpl(*other.pimpl_);
  return *this;
}
bool WError::operator==(const WError& other) const {
  if (pimpl_->errRef_ == &other) {
    return true;
  }
  return false;
}
bool WError::operator!=(const WError& other) const {
  return !(*this == other);
}
const std::wstring& WError::What() const {
  if (pimpl_->errRef_ == nullptr) {
    return pimpl_->msg_;
  }
  return pimpl_->errRef_->What();
}
bool WError::Is() const {
  return pimpl_->is_;
}

}
}
