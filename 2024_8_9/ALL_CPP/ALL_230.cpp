/* "EllipseS& Transform(const TransformationT<double, DIM>& tr)\t @return The reference to self\n\t @param tr The transformation\n\t @brief Transform the ellipse\n,\n",
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
	SECTION("Transform")
	{
		Ellipse2 Transfor_ellipse = ellipse.Transform(tr);
		CHECK(ellipse.Location().X() == Approx(5.0));
		CHECK(ellipse.Location().Y() == Approx(-2.0));
		CHECK(ellipse.MajorRadius() == Approx(5.0));
		CHECK(ellipse.MinorRadius() == Approx(4.0));
		CHECK(Transfor_ellipse.Location().X() == Approx(5.0));
		CHECK(Transfor_ellipse.Location().Y() == Approx(-2.0));
		CHECK(Transfor_ellipse.MajorRadius() == Approx(5.0));
		CHECK(Transfor_ellipse.MinorRadius() == Approx(4.0));
	}}