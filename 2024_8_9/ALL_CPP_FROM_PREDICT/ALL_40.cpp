 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
#include <occtio/OCCTTool.hpp>
#include <geometry/MakeArcOfHyperbola2d.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeCylinder.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::Circle3_CylinderVIso 1/2 ", "[math][CurveCalculation][P1][CylinderVIso]") {
	Frame3 frame;
	double radius = 5.0;
	double v = 0;
	std::shared_ptr<Curve3> curve = CylinderVIso(frame, v, radius);
	Point3 point1(frame.Location().X(), frame.Location().Y(), curve->Value(0).X(), curve->Value(0).Y());
	std::cout << point1 << std::endl;
	CHECK(point1.X() == 0.0);
	CHECK(point1.Y() == 5.0);
	CHECK(curve->FirstParameter() == Approx(0.0));
	std::vector<double> rat = CurveCalculation::CylindricalCoordinates(curve, 0.0, 0.0);
	CHECK(rat[0] == Approx(0.0));
	CHECK(rat[1] == Approx(0.0));
	CHECK(rat[2] == Approx(5.0));
}