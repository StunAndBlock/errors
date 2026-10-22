#ifndef CADO_ERRORS_ERROR_HPP_
#define CADO_ERRORS_ERROR_HPP_

#include <cstddef>
#include <memory>
#include <string>
namespace cado {
namespace errors {

class IError {
public:
  virtual ~IError() = default;
  virtual std::string what() const = 0;
};

class BaseError : public IError {
public:
  BaseError(const std::string &msg) : msg_(msg) {};
  std::string what() const override {
    return this->msg_;
  }
  ~BaseError() override = default;

protected:
  const std::string msg_;
};

using Error = std::shared_ptr<const IError>;
constexpr std::nullptr_t null = nullptr;
// bool Error::operator!=(const Error& other) const {
//   return !(*this == other);
// }
// const std::string& Error::What() const {
//   if (pimpl_->errRef_ == nullptr) {
//     return pimpl_->msg_;
//   }
//   return pimpl_->errRef_->What();
// }
// bool Error::Is() const {
//   return pimpl_->is_;
// }

} // namespace errors
} // namespace cado

#endif //! CADO_ERRORS_ERROR_HPP_
