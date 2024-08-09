 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::CylinderD2 1/4 ", "[math][CurveCalculation][P1][CylinderD2]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir);
	double radius = 2.0;
	Vector3 tangentAt0 = AMCAX::CurveCalculation::CylinderD2(0.0, 0.0, defaultFrame3, radius);
	Vector3 tangentAt90Deg = AMCAX::CurveCalculation::CylinderD2(0.0, M_PI_2, defaultFrame3, radius);
	Vector3 tangentAt180Deg = AMCAX::CurveCalculation::CylinderD2(M_PI, M_PI_2, defaultFrame3, radius);
	Vector3 tangentAt270Deg = AMCAX::CurveCalculation::CylinderD2(M_PI, 0.0, defaultFrame3, radius);
	Vector3 tangentAt360Deg = AMCAX::CurveCalculation::CylinderD2(2 * M_PI, 0.0, defaultFrame3, radius);
	CHECK(tangentAt0.X() == Approx(0.0));
	CHECK(tangentAt0.Y() == Approx(2.0));
	CHECK(tangentAt0.Z() == Approx(0.0));
	CHECK(tangentAt90Deg.X() == Approx(-2.0));
	CHECK(tangentAt90Deg.Y() == Approx(0.0));
	CHECK(tangentAt90Deg.Z() == Approx(0.0));
	CHECK(tangentAt180Deg.X() == Approx(0.0));
	CHECK(tangentAt180Deg.Y() == Approx(-2.0));
	CHECK(tangentAt180Deg.Z() == Approx(0.0));
	CHECK(tangentAt270Deg.X() == Approx(2.0));
	CHECK(tangentAt270Deg.Y() == Approx(0.0));
	CHECK(tangentAt270Deg.Z() == Approx(0.0));
	CHECK(tangentAt360Deg.X() == Approx(0.0));
	CHECK(tangentAt360Deg.Y() == Approx(2.0));
	CHECK(tangentAt360Deg.Z() == Approx(0.0));
}