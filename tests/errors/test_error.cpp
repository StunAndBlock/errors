#include "cado/errors/utils.hpp"
#include <cado/errors/error.hpp>
#include <cstdio>
#include <gtest/gtest.h>
#include <string>
using namespace cado;
using errors::Error;

static Error GlobEror = errors::new_e("global error");

TEST(ErrorTest, IsForGlobal) {
  Error err;
  {
    err = GlobEror;
  }

  EXPECT_TRUE(errors::is(err, GlobEror));
}

TEST(ErrorTest, IsFalseExpected) {
  Error err = errors::new_e("failed");
  EXPECT_FALSE(errors::is(err, GlobEror));
}

TEST(ErrorTest, IsForLocalChain) {
  Error err;
  {
    Error localErr = errors::new_e("failed");
    err = localErr;
  }
  Error errChained = err;

  EXPECT_TRUE(errors::is(errChained, err));
}

TEST(ErrorTest, EqOperatorForGlobal) {
  Error err;
  {
    err = GlobEror;
  }
  EXPECT_TRUE(err == GlobEror);
}

TEST(ErrorTest, ErrorExists) {
  Error err;
  {
    err = errors::new_e("new error");
  }
  EXPECT_TRUE(err != errors::null);
}

static Error ErrNotNegative = errors::new_e("value is not negative");
static bool ErrorReturn_compare_negatives(int a, int b, Error &outErr) {
  if (a > 0 || b > 0) {
    outErr = ErrNotNegative;
    return false;
  }
  return a > b;
}
TEST(ErrorTest, ErrorReturn) {
  Error err = nullptr;
  bool _ = ErrorReturn_compare_negatives(1, -1, err);
  if (err != nullptr) {
    std::printf("\n%s\n", err->what().c_str());
  }
  EXPECT_TRUE(errors::is(err, ErrNotNegative));
}

static bool ErrorReturn_explicit_no_error(Error &outErr) {
  outErr = nullptr;
  return true;
}
TEST(ErrorTest, ExcplictNoErrorReturn) {
  Error err = nullptr;
  bool _ = ErrorReturn_explicit_no_error(err);
  EXPECT_TRUE(err == nullptr);
}

static bool ErrorReturn_implicit_no_error(Error &outErr) {
  return true;
}
TEST(ErrorTest, ImplicitNoErrorReturn) {
  Error err = nullptr;
  bool _ = ErrorReturn_implicit_no_error(err);
  EXPECT_TRUE(err == nullptr);
}

class MyError : public errors::BaseError {
public:
  MyError(const std::string &msg, const std::string &field)
      : errors::BaseError(msg), field_(field) {};

  std::string what() const override {
    const size_t size_written = snprintf(
        nullptr, 0, "%s, field: %s", this->msg_.c_str(), this->field_.c_str());
    std::string what;
    what.resize(size_written);
    snprintf(what.data(), size_written + 1, "%s, field: %s", this->msg_.c_str(),
             this->field_.c_str());
    return what;
  };

private:
  const std::string field_;
};
TEST(ErrorTest, CustomError) {
  Error err = nullptr;
  {
    err = Error{new MyError("failed to do", "value24")};
  }
  printf("%s", err->what().c_str());
  EXPECT_EQ(err->what(), "failed to do, field: value24");
}
