#define CATCH_CONFIG_MAIN

#include "atoi.h"

#include "catch.hpp"

TEST_CASE("single digit positive integers are parsed") {
    REQUIRE(myAtoi("5") == 5);
}

TEST_CASE("triple digit positive integers are parsed") {
    REQUIRE(myAtoi("835") == 835);
}

TEST_CASE("0 is parsed") {
    REQUIRE(myAtoi("0") == 0);
}

TEST_CASE("single digit negative integers are parsed") {
    REQUIRE(myAtoi("-5") == -5);
}

TEST_CASE("triple digit negative integers are parsed") {
    REQUIRE(myAtoi("-835") == -835);
}