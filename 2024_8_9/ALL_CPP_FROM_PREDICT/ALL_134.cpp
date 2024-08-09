 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CartesianT.hpp>
#include <occtio/OCCTTool.hpp>
#include <geometry/MakeArcOfHyperbola2d.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeVertex.hpp>
#include <modeling/MakeEdge2d.hpp>
using namespace AMCAX;
TEST_CASE("case1: Frame3 To3d(const Frame3& pos, const Frame2& f) ", "[math][Convert][P1][To3d]") {
	Direction2 initialDir(1.0, 0.0); 
	Frame2 defaultFrame2(Point2(1.0, 1.0), initialDir); 
	Direction3 dir3(1.0, 0.0, 0.0); 
	Point3 point3(1.0, 1.0, 0.0); 
	Frame3 defaultFrame3(point3, dir3); 
	Frame3 result = defaultFrame3.To3d(defaultFrame2); 
	CHECK(result.Location().X() == Approx(1.0));
	CHECK(result.Location().Y() == Approx(1.0));
	CHECK(result.Location().Z() == Approx(0.0));
}