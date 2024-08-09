/* "void SetRadius(double r)\t @param r The radius\n\t @brief Set the radius of the circle\n,\n",
      */
 #include<catch.hpp>
#include "testHelper.h"
#include<iostream>
#include <math/CircleT.hpp>
#include <common/AxisT.hpp>
#include <common/PointT.hpp>
TEST_CASE("CircleT Area and Length Test", "[CircleT]") {
    AMCAX::Circle2 circle2;
    circle2.SetRadius(5.0);
    CHECK(circle2.Area() == Approx(78.53982));
    CHECK(circle2.Length() == Approx(31.41593));
    AMCAX::Circle3 circle3;
    circle3.SetRadius(10.0);
    CHECK(circle3.Area() == Approx(314.15927));
    CHECK(circle3.Length() == Approx(62.83185));
}