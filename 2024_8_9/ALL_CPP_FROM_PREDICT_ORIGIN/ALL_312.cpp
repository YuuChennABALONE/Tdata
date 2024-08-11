 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
#include <geometry/MakeGeom3Ellipse.hpp>
#include <geometry/Geom3Ellipse.hpp>
#include <geometry/GeometryTool.hpp>
#include <iostream>
#define ONE_RADIAN (M_PI / 180.)
#define SQUARE(x) ((x) * (x))
TEST_CASE("case1: MakeGeom3Ellipse construction ellipse3 [1] ", "[geometry][MakeGeom3Ellipse][P1]")
{
	SECTION("majorRadius = 5.0; minorRadius = 4.0;")
	{
		Ellipse3 ellipse;
		MakeGeom3Ellipse makeEllipse;
		makeEllipse.SetMajorRadius(5.);
		makeEllipse.SetMinorRadius(4.);
		makeEllipse.SetLocation(ellipse.Location());
		makeEllipse.SetFrame(ellipse.Position());
		makeEllipse.SetMajorRadiusDirection(ellipse.MajorRadiusDirection());
		MakeGeom3Ellipse::Type t = makeEllipse.Type();
		CHECK(t == Type::Ellipse);
		Ellipse3 ellipse1 = makeEllipse;
		CHECK(ellipse1.Location().X() == ellipse.Location().X());
		CHECK(ellipse1.Location().Y() == ellipse.Location().Y());
		CHECK(ellipse1.Location().Z() == ellipse.Location().Z());
		CHECK(ellipse1.Position().X() == ellipse.Position().X());
		CHECK(ellipse1.Position().Y() == ellipse.Position().Y());
		CHECK(ellipse1.Position().Z() == ellipse.Position().Z());
		CHECK(ellipse1.MajorRadiusDirection().X() == ellipse.MajorRadiusDirection().X());
		CHECK(ellipse1.MajorRadiusDirection().Y() == ellipse.MajorRadiusDirection().Y());
		CHECK(ellipse1.MajorRadiusDirection().Z() == ellipse.MajorRadiusDirection().Z());
		CHECK(ellipse1.Focal() == Approx(9.));
		CHECK(ellipse1.Focus1().X() == Approx(2.666666667));
		CHECK(ellipse1.Focus1().Y() == Approx(0.));
		CHECK(ellipse1.Focus1().Z() == Approx(0.));
		CHECK(ellipse1.Focus2().X() == Approx(3.333333333));
		CHECK(ellipse1.Focus2().Y() == Approx(0.));
		CHECK(ellipse1.Focus2().Z() == Approx(0.));
		CHECK(ellipse1.MajorRadius() == Approx(5.));
		CHECK(ellipse1.MinorRadius() == Approx(4.));
		CHECK(ellipse1.Axis().IsSimilar(Axis3(Direction3(0., 0., 1.), 5.), 1e-6 * ONE_RADIAN));
		CHECK(ellipse1.Type() == Type::Ellipse);
		CHECK(ellipse1.IsCircular() == true);
		CHECK(GeometryTool::IsCircular(ellipse1, 0.0, 1e-5));
		CHECK(ellipse1 majorRadius = 5.0; minorRadius = 4.0;")
	{
		Ellipse3 ellipse;
		MakeGeom3Ellipse makeEllipse;
		makeEllipse.SetMajorRadius(5.);
		makeEllipse.SetMinorRadius(4.);
		makeEllipse.SetLocation(ellipse.Location());
		makeEllipse.SetFrame(ellipse.Position());
		makeEllipse.SetMajorRadiusDirection(ellipse.MajorRadiusDirection());
		MakeGeom3Ellipse::Type t = makeEllipse.Type();
		CHECK(t == Type::Ellipse);
		Ellipse3 ellipse1 = makeEllipse;
		CHECK(ellipse1.Location().X() == ellipse.Location().X());
		CHECK(ellipse1.Location().Y() == ellipse.Location().Y());
		CHECK(ellipse1.Location().Z() == ellipse.Location().Z());
		CHECK(ellipse1.Position().X() == ellipse.Position().X());
		CHECK(ellipse1.Position().Y() == ellipse.Position().Y());
		CHECK(ellipse1.Position().Z() == ellipse.Position().Z());
		CHECK(ellipse1.MajorRadiusDirection().X() == ellipse.MajorRadiusDirection().X());
		CHECK(ellipse1.MajorRadiusDirection().Y() == ellipse.MajorRadiusDirection().Y());
		CHECK(ellipse1.MajorRadiusDirection().Z() == ellipse.MajorRadiusDirection().Z());
		CHECK(ellipse1.Focal() == Approx(9.));
		CHECK(ellipse1.Focus1().X() == Approx(2.666666667));
		CHECK(ellipse1.Focus1().Y() == Approx(0.));
		CHECK(ellipse1.Focus1().Z() == Approx(0.));
		CHECK(ellipse1.Focus2().X() == Approx(3.333333333));
		CHECK(ellipse1.Focus2().Y() == Approx(0.));
		CHECK(ellipse1.Focus2().Z()"}