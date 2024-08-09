/* "[[nodiscard]] bool Contains(const PointT<double, DIM>& p, double tol)\t @return True if the point is on the line under the tolerance\n\t @param tol The tolerance\n\t @param p The point\n\t @brief Does the line contain a point under a distance tolerance\n,\n",
      */
 #include <catch.hpp>
#include <testHelper.h>
#include <math/LineT.hpp>
#include <modeling/MakeEdge2d.hpp>
using AMCAX::Line2;
#define ONE_RADIAN (M_PI / 180.)
TEST_CASE("case2: Line base method Test", "[math][Line2][p1]")
{
	SECTION("Contains")
	{
		Line2 line(Axis2(Point2(2., 1.), Direction2(1., 1.)));  
		Point2 point1(2., 1.);  
		Point2 point2(1., 1.);  
		CHECK(line.Contains(point1, 1e-5));
		CHECK_FALSE(line.Contains(point2, 1e-5));
		CHECK(line.Contains(point2, 1.));  
	}}