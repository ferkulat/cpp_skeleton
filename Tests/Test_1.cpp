//
// Created by marcel on 3/30/17.
//
#include "catch.hpp"
#include "fun.h"

TEST_CASE("First failling test")
{
    REQUIRE( 3 == fun(1) );
}
