#include <catch2/catch.hpp>
#include <stdexcept>

#include "fac.h"

TEST_CASE("fac(0)", "[fac]") {
    REQUIRE( fac(0) == 1 );
}

TEST_CASE("fac(1)", "[fac]") {
    REQUIRE( fac(1) == 1 );
}

TEST_CASE("fac(3)", "[fac]") {
    REQUIRE( fac(3) == 6 );
}

TEST_CASE("fac(5)", "[fac]") {
    REQUIRE( fac(5) == 120 );
}

TEST_CASE("fac invalid argument", "[fac]") {
    REQUIRE_THROWS_AS( fac(-1), std::domain_error );
}

TEST_CASE("fac argument too large", "[fac]") {
    REQUIRE_THROWS_WITH( fac(20), "argument too large" );
}
