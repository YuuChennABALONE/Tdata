/* "[[nodiscard]] double Radius()\t @return The radius\n\t @brief Get the radius\n,\n",
      */
 #include<catch.hpp>
#include "testHelper.h"
#include<iostream>
#include <math/CircleT.hpp>
#include <common/AxisT.hpp>
#include <common/PointT.hpp>
TEST_CASE("CircleT Constructor Test", "[math][CircleT][P1]") {
	SECTION("2D Circle Construction") {
        AMCAX::Circle2 circle2;
        constexpr double maxr = std::numeric_limits<double>::max();
        CHECK(circle2.Radius() == Approx(maxr).epsilon(1e-15));
        CHECK(circle2.Area() == Approx(maxr * maxr * M_PI).epsilon(1e-15));
        double a, b, c, d, e, f;
        circle2.Coefficients(a, b, c, d, e, f);
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << c << std::endl;
        std::cout << d << std::endl;
        std::cout << e << std::endl;
        std::cout << f << std::endl;
        AMCAX::Point2 P(0.0, 1.0);
        double tolerance = 0.1;
        CHECK(circle2.Contains(P, tolerance)==false);
        CHECK(circle2.Distance(P) == Approx(maxr).epsilon(1e-15));
    }}