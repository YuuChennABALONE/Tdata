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
TEST_CASE("case1: CurveCalculation::EllipseD2 4/4 ", "[math][CurveCalculation][P1][EllipseD2]") {
	Direction3 initialDir(0.0, 0.0, 1.0);
	Frame3 defaultFrame3(Point3(0.0, 0.0, 0.0), initialDir);
	double major = 5.0;
	double minor = 4.0;
	Vector3 vector3 = CurveCalculation::EllipseD2(M_PI_2, defaultFrame3, major, minor);
	std::cout << vector3.X() << " " << vector3.Y() << " " << vector3.Z() << std::endl;
	CHECK(vector3.X() == 0.0);
	CHECK(vector3.Y() == 5.0);
	CHECK(vector3.Z() == 0.0);
}