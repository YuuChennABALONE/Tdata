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
TEST_CASE("case1: CurveCalculation::PlaneVIso() [2/10] ", "[math][CurveCalculation][P1][PlaneVIso]") {
	Direction3 initialDir(0.0, 0.0, 1.0);
	Frame3 defaultFrame3(Point3(0.0, 0.0, 0.0), initialDir);
	double major = 5.0, minor = 4.0;
	AMCAX::Plane3 plane3(defaultFrame3);
	AMCAX::Line3 line3 = AMCAX::CurveCalculation::PlaneVIso(plane3, 0.0);
	CHECK(line3.Location().X() == 5.0);
	CHECK(line3.Location().Y() == 0.0);
	CHECK(line3.Location().Z() == 0.0);
}