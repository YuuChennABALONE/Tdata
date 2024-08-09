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
TEST_CASE("case1: Parabola3::SetDefault()  Add 1 cases", "[math][Parabola3][P1][SetDefault]") {
	Frame3 frame;
	double focal = 5.0;
	Parabola3 parabola3(frame, focal);
	SECTION("SetDefault()") {
		parabola3.SetDefault();
		CHECK(parabola3.Location().X() == Approx(0.0));
		CHECK(parabola3.Location().Y() == Approx(0.0));
		CHECK(parabola3.Location().Z() == Approx(0.0));
		CHECK(parabola3.Focal() == Approx(5.0));
	}}