/* "AMCAX_API Plane(double a, double b, double c, double d)\t @param a,b,c,d The coefficients\n\t @brief Construct from an algebraic representation: ax + by + cz + d = 0\n,\n",
      */
 #include "catch.hpp"
#include <testHelper.h>
#include <math/Plane.hpp>
using namespace AMCAX;
TEST_CASE("case1: Plane construction and methods", "[math][Plane][p1]") {
	SECTION("Construct from algebraic representation") {
        Plane plane(1., 1., 1., -3.);  
        double a, b, c, d;
        plane.Coefficients(a, b, c, d);  
        REQUIRE(a == Approx(1./std::sqrt(3)).margin(0.001));
        REQUIRE(b == Approx(1. / std::sqrt(3)).margin(0.001));
        REQUIRE(c == Approx(1. / std::sqrt(3)).margin(0.001));
        REQUIRE(d == Approx(-3. / std::sqrt(3)).margin(0.001));
    }}