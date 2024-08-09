 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::EllipseValues 1/4 ", "[math][CurveCalculation][P1][EllipseValues]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir);
	double major = 3.0;
	double minor = 2.0;
	std::vector<Point3> result = AMCAX::CurveCalculation::EllipseValues(defaultFrame3, major, minor, 0.0, 2 * M_PI, 100);
	CHECK(result.size() == 100);
	for (int i = 0; i < result.size(); i++) {
		Point3 resultPoint = result[i];
		double x = resultPoint.X();
		double y = resultPoint.Y();
		double z = resultPoint.Z();
		double x2 = major * major * x + minor * minor * x * x;
		double y2 = major * major * y + minor * minor * y * y;
		CHECK(x2 + y2 == Approx(9.0));
	}
}