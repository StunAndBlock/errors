#include "cado/errors/utils.hpp"
#include <cado/errors.hpp>
#include <gtest/gtest.h>

#include <string>

#include <cado/errors.hpp>

TEST(UmbrellaHeader, ReexportsError) {
  cado::errors::Error err = cado::errors::new_e("something went wrong");
  EXPECT_EQ(std::string(err->what()), "something went wrong");
}

TEST(UmbrellaHeader, IsSelfContainedWhenIncludedTwice) {
  SUCCEED();
}

TEST(UmbrellaHeader, ErrorMessagesRoundTripThroughUmbrella) {
  const std::string msg = "multi\nline\tmessage with unicode \xE2\x9C\x93";
  cado::errors::Error err = cado::errors::new_e(msg);
  EXPECT_EQ(err->what(), msg);
}
