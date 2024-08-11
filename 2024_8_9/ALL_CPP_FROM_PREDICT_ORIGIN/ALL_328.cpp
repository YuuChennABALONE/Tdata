 #include <catch.hpp>
#include <testHelper.h>
#include <common/FrameT.hpp>
#include <common/TransformationT.hpp>
#include <common/VectorT.hpp>
#include <math/CircleT.hpp>
using namespace AMCAX;
using namespace std;
TEST_CASE("case1:this is a case for Circle2", "[math][Circle2]")
{
	Circle2 circle2;
	double r = 3.0;
	double x = 2.0;
	double y = 4.0;
	circle2.SetRadius(r);
	circle2.SetLocation(Point2(x, y));
	SECTION("SetRadius")
	{
		circle2.SetRadius(5.0);
		CHECK(circle2.Radius() == Approx(5.0));
		CHECK(circle2.Location().IsEqual(Point2(x, y), 1e-5));
	}}