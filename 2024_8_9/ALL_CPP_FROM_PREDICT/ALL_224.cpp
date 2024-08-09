 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
#include <occtio/OCCTTool.hpp>
#include <geometry/MakeArcOfHyperbola2d.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeVertex.hpp>
#include <modeling/MakeEdge2d.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::Parameter() Hyperbola3 [10/20] ", "[math][CurveCalculation][P1][Parameter]") {
	Direction3 dir3(0.0, 0.0, 1.0);
	Point3 point3(0.0, 0.0, 0.0);
	Frame3 frame3(point3, dir3);
	Hyperbola3 hyperbola3(frame3, 5.0, 3.0); 
	double u1 = CurveCalculation::Parameter(hyperbola3, 0.0);
	double x = hyperbola3.Location().X() + hyperbola3 majorRadius_ * cos(u1);
	double y = hyperbola3.Location().Y() + hyperbola3 majorRadius_ * sin(u1);
	double z = hyperbola3.Location().Z() + hyperbola3 majorRadius_ * sinh(u1);
	Point3 pointOnCire1 = hyperbola3.Location() + hyperbola3 majorRadius_ * std::cos(u1) * dir3 + hyperbola3 minorRadius_ * std::sin(u1) * dir3;
	CHECK(u1 == 0);
	CHECK(pointOnCire1.X() == 5.0);
	CHECK(pointOnCire1.Y() == 0.0);
	CHECK(pointOnCire1.Z() == 0.0);
}