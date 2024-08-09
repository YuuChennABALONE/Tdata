/* "[[nodiscard]] double Radius()\t @return The radius\n\t @brief Get the radius\n,\n",
      */
 #include<catch.hpp>
#include "testHelper.h"
#include<iostream>
#include <math/CircleT.hpp>
#include <common/AxisT.hpp>
#include <common/PointT.hpp>
TEST_CASE("CircleT Constructor Test", "[math][CircleT][P1]") {
	SECTION("3D Circle Construction") {
        AMCAX::Circle3 circle3;
        CHECK(circle3.Radius() == Approx(std::numeric_limits<double>::max()));
        circle3.Axis();
    }}