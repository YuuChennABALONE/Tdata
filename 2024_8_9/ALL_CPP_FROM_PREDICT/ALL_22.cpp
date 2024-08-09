 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::SphereD2 1/4 ", "[math][CurveCalculation][P1][SphereD2]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
	double radius = 2.0; 
	Vector3 tangentAt0 = AMCAX::CurveCalculation::SphereD2(0.0, 0.0, defaultFrame3, radius);
	Vector3 tangentAt180 = AMCAX::CurveCalculation::SphereD2(M_PI, 0.0, defaultFrame3, radius);
	Vector3 tangentAt360 = AMCAX::CurveCalculation::SphereD2(2 * M_PI, 0.0, defaultFrame3, radius);
	Vector3 tangentAt90 = AMCAX::CurveCalculation::SphereD2(M_PI_2, 0.0, defaultFrame3, radius);
	Vector3 tangentAt270 = AMCAX::CurveCalculation::SphereD2(3 * M_PI_2, 0.0, defaultFrame3, radius);
	Vector3 tangentAt135 = AMCAX::CurveCalculation::SphereD2(3 * M_PI_4, 0.0, defaultFrame3, radius);
	Vector3 tangentAt225 = AMCAX::CurveCalculation::SphereD2(5 * M_PI_4, 0.0, defaultFrame3, radius);
	Vector3 tangentAt315 = AMCAX::CurveCalculation::SphereD2(7 * M_PI_4, 0.0, defaultFrame3, radius);
	Vector3 tangentAt45 = AMCAX::CurveCalculation::SphereD2(M_PI_4, 0.0, defaultFrame3, radius);
	Vector3 tangentAt235 = AMCAX::CurveCalculation::SphereD2(11 * M_PI_4, 0.0, defaultFrame3, radius);
	CHECK(tangentAt0.X() == Approx(0.0).margin(1e-12));
	CHECK(tangentAt0.Y() == Approx(2.0).margin(1e-12));
	CHECK(tangentAt0.Z() == Approx(-1.0).margin(1e-12));
	CHECK(tangentAt180.X() == Approx(-2.0).margin(1e-12));
	CHECK(tangentAt180.Y() == Approx(0.0).margin(1e-12));
	CHECK(tangentAt180.Z() == Approx(-1.0).margin(1e-12));
	CHECK(tangentAt360.X() == Approx(0.0).margin(1e-12));
	CHECK(tangentAt360.Y() == Approx(-2.0).margin(1e-12));
	CHECK(tangentAt360.Z() == Approx(-1.0).margin(1e-12));
	CHECK(tangentAt90.X() == Approx(1.0).margin(1e-12));
	CHECK(tangentAt90.Y() == Approx(0.0).margin(1e-12));
	CHECK(tangentAt90.Z() == Approx(0.0).margin(1e-12));
	CHECK(tangentAt270.X() == Approx(-1.0).margin(1e-12));
	CHECK(tangentAt270.Y() == Approx(0.0).margin(1e-12));
	CHECK(tangentAt270.Z() == Approx(2.0).margin(1e-12));
	CHECK(tangentAt135.X() == Approx(1.0).margin(1e-12));
	CHECK(tangentAt135.Y() == Approx(1.0).margin(1e-12));
	CHECK(tangentAt135.Z() == Approx(0.0).margin(1e-12));
	CHECK(tangentAt225.X() == Approx(-1.0).margin(1e-12));
	CHECK(tangentAt225.Y() == Approx(-1.0).margin(1e-12));
	CHECK(tangentAt225.Z() == Approx(0.0).margin(1e-12));
	CHECK(tangentAt315.X() == Approx(1.0).margin(1e-12));
	CHECK(tangentAt315.Y() == Approx(-1.0).margin(1e-12));
	CHECK(tangentAt315"}