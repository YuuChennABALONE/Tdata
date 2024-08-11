 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/Geom3BSplineSurface.hpp>
using namespace AMCAX;
TEST_CASE("case1: Geom3BSplineSurface::Circle3 - constructor ", "[math][Geom3BSplineSurface][P1][ constructors]") {
	Frame3 frame;
	double radius = 3.0;
	Geom3BSplineSurface surface(frame, radius);
	SECTION("IsGeom2SurfaceType") {
		CHECK(surface.IsGeom2SurfaceType() == false);
	}}