/* "EllipseS& Scale(const PointT<double, DIM>& point, double scale)\t @return The reference to self\n\t @param scale The scale value\n\t @param point The scaling center point\n\t @brief Scale the ellipse by a center point\n,\n",
      */
 #include <catch.hpp>
#include <testHelper.h>
#include <common/FrameT.hpp>
#include <common/TransformationT.hpp>
#include <common/VectorT.hpp>
#include <math/EllipseT.hpp>
using namespace AMCAX;
using namespace std;
TEST_CASE("case3:this is a case for Test-Ellipse2-Rotate", "[math][Ellipse2][P1]")
{
	Point2 point1(6.0, 0.0);
	Direction2 dir1(0.0, 1.0);
	Axis2 axis1(point1, dir1);
	double major = 5.0;
	double minor = 4.0;
	bool isRight = true;
	Ellipse2 ellipse(axis1, major, minor, isRight);
	double angle = M_PI_2;
	Point2 point_temp(0.0, 0.0);
	SECTION("Scale")
	{
		Ellipse2 scale_ellipse = ellipse.Scale(point, scale);
		CHECK(ellipse.Location().X() == Approx(2.5));
		CHECK(ellipse.Location().Y() == Approx(-1.0));
		CHECK(ellipse.MajorRadius() == Approx(2.5));
		CHECK(ellipse.MinorRadius() == Approx(2.0));
		CHECK(scale_ellipse.Location().X() == Approx(2.5));
		CHECK(scale_ellipse.Location().Y() == Approx(-1.0));
		CHECK(scale_ellipse.MajorRadius() == Approx(2.5));
		CHECK(scale_ellipse.MinorRadius() == Approx(2.0));
	}
	scale = -2.0;}