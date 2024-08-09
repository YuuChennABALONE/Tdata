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
TEST_CASE("case1: CurveCalculation::LineD2() [3/10] ", "[math][CurveCalculation][P1][LineD2]") {
	Direction2 initialDir(1.0, 0.0); 
	Frame2 defaultFrame2(Point2(1.0, 1.0), initialDir); 
    Axis2 axis2(defaultFrame2);
    Vector2 vector2 = CurveCalculation::LineD2(1.0, axis2);
    CHECK(vector2.X() == 0.0);
    CHECK(vector2.Y() == -1.0);
    CHECK(vector2.Length() == Approx(1.0));
}