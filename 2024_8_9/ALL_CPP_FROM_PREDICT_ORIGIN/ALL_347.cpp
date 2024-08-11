 #include <catch.hpp>
#include <testHelper.h>
#include <math/LineT.hpp>
#include <modeling/MakeEdge2d.hpp>
using AMCAX::Line2;
#define ONE_RADIAN (M_PI / 180.)
TEST_CASE("case2: Line base method Test", "[math][Line2][p1]")
{
	SECTION("Scale Test")
	{
		Line2 line;
		Line2 line2(Point2(1., 1.), Direction2(1., 1.));
		Line2 line3 = line.Scale(Point2(), 1.5);
		CHECK(line3.Direction().X() == Approx(1.).margin(1e-5));
		CHECK(line3.Direction().Y() == Approx(1.).margin(1e-5));
		Line2 line4 = line.Scale(Point2(0., 0.), 1.5);
		CHECK(line4.Direction().X() == Approx(1.).margin(1e-5));
		CHECK(line4.Direction().Y() == Approx(1.).margin(1e-5));
		Line2 line5 = line.Scale(Point2(1., 1.), 1.5);
		CHECK(line5.Direction().X() == Approx(1.).margin(1e-5));
		CHECK(line5.Direction().Y() == Approx(1.).margin(1e-5));
		Line2 line6 = line.Scale(Point2(1., 0.), 1.5);
		CHECK(line6.Direction().X() == Approx(1.).margin(1e-5));
		CHECK(line6.Direction().Y() == Approx(1.).margin(1e-5));
		Line2 line7 = line.Scale(Point2(0., 1.), 1.5);
		CHECK(line7.Direction().X() == Approx(1.).margin(1e-5));
		CHECK(line7.Direction().Y() == Approx(1.).margin(1e-5));
		Line2 line8 = line.Scale(Point2(2., 2.), 1.5);
		CHECK(line8.Direction().X() == Approx(1.).margin(1e-5));
		CHECK(line8.Direction().Y() == Approx(1.).margin(1e-5));
		Line2 line9 = line.Scale(Point2(-1., -1.), 1.5);
		CHECK(line9.Direction().X() == Approx(1.).margin(1e-5));
		CHECK(line9.Direction().Y() == Approx(1.).margin(1e-5));
		Line2 line10 = line.Scale(Point2(-2., -2.), 1.5);
		CHECK(line10.Direction().X() == Approx(1.).margin(1e-5));
		CHECK(line10.Direction().Y() == Approx(1.).margin(1e-5));
		Line2 line11 = line.Scale(Point2(1., 1.5), 1.5);
		CHECK(line11.Direction().X() == Approx(1.).margin(1e-5));
		CHECK(line11.Direction().Y() == Approx(1.).margin(1e-5));
		Line2 line12 = line.Scale(Point2(1.5, 1.), 1.5);
		CHECK(line12.Direction().X() == Approx(1.).margin(1e-5));
		CHECK(line12.Direction().Y() == Approx(1.).margin(1e-5));
		Line2 line13 = line.Scale(Point2(1.5, 1.5), 1.5);
		CHECK(line13.Direction().X() == Approx(1.).margin(1e-5));
		CHECK(line13.Direction().Y() == Approx(1.).margin(1e-5));
		Line2 line14 = line.Scale(Point2(0.5, 0.5), 1.5);
		CHECK(line14.Direction().X() == Approx(1.).margin(1e-5));
		CHECK(line14.Direction().Y() == Approx(1.).margin(1e-5));
		Line2 line15 = line.Scale(Point2(-1., -1.5), 1.5);
		CHECK(line15.Direction().X() == Approx(1.).margin(1e-5));
		CHECK(line15.Direction().Y() == Approx(1.).margin(1e-5));
		Line2 line16 = line.Scale(Point2(-1.5, -1.), 1.5);
		CHECK(line16.Direction().X() == Approx(1.).margin(1e-5));
		CHECK(line16.Direction().Y() == Approx(1.).margin(1e-5));
		Line2 line17 = line.Scale(Point2(-1.5"}