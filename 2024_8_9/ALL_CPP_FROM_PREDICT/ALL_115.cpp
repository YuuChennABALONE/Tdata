 #include<catch.hpp>
#include<testHelper.h>
#include<common/DirectionT.hpp>
#include<common/FrameT.hpp>
#include<modeling/MakeFace.hpp>
#include<common/AxisT.hpp>
#include<math/HyperbolaT.hpp>
#include<modeling/MakeEdge2d.hpp>
#include <iostream>
using namespace AMCAX;
using namespace std;
TEST_CASE("case1: Hyperbola2", "[math][Hyperbola2][p1]") {
	Point2 point2(0.0, 0.0);	
	Direction2 dir2(1.0, 0.0);
	Axis2 major2(Axis2(point2, dir2));
	double major2r = 3.0;
	Direction2 dir3(0.0, 1.0);
	Axis2 minor2(Axis2(point2, dir3));
	double minor2r = 4.0;
	Hyperbola2 hyperbola2d1(major2, minor2, major2r, minor2r);
	MakeEdge2d edge2d1(hyperbola2d1, 0.0, 6.283185);
	SECTION("Deflection()") {
		hyperbola2d1.SetDeflection(0.1);
		CHECK(hyperbola2d1.Deflection() == Approx(0.1));
	}}