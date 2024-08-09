/* "AMCAX_API void Coefficients(double& a, double& b, double& c, double& d)\t @param[out] a,b,c,d The coefficients\n\t @brief Get coefficients of algebraic representation: ax + by + cz + d = 0\n,\n",
      */
 #include "catch.hpp"
#include <testHelper.h>
#include <math/Plane.hpp>
using namespace AMCAX;
TEST_CASE("case1: Plane construction and methods", "[math][Plane][p1]") {
	SECTION("Default constructor") {
        Plane plane;
        double a, b, c, d;
        plane.Coefficients(a, b, c, d);
        REQUIRE(a == Approx(0));
        REQUIRE(b == Approx(0));
        REQUIRE(c == Approx(1));
        REQUIRE(d == Approx(0));
    }}