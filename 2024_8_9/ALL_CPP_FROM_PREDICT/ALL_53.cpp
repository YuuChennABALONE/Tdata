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
TEST_CASE("case1: CurveCalculation::Circle2Sample 1/4 ", "[math][CurveCalculation][P1][Circle2Sample]") {
	Direction2 initialDir(1.0, 0.0); 
	Frame2 defaultFrame2(Point2(1.0, 1.0), initialDir); 
	double radius = 2.0;
	AMCAX::Circle2 circle2(defaultFrame2,radius);
	SECTION("IsoparametricCurve  u =0") {
		Line2  line2 = CurveCalculation::IsoparametricCurve(circle2, 0.0, 0.01, 0.0);
		CHECK(line2.Location().X() == Approx(1.0));
		CHECK(line2.Location().Y() == 2.0);
	}
}