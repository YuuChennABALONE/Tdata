 #include <catch.hpp>
#include <testHelper.h>
#include <common/FrameT.hpp>
#include <topology/Polygon3.hpp>
#include <common/AxisT.hpp>
using namespace AMCAX;
using namespace std;
TEST_CASE("case1:this is a case for Test Polygon3", "[topology][Polygon3]")
{
	Frame3 frame;
	double area = 0.0;
	Polygon3 polygon(frame, 5, 3.0);
	SECTION("Area")
	{
		CHECK(polygon.Area() == Approx(area).margin(0.1));
	}}