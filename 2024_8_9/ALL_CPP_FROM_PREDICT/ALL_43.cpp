 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::CylinderDN 1/2 ", "[math][CurveCalculation][P1][CylinderDN]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir);
	double radius = 2.0;
	AMCAX::Vector3 tangentAt0 = AMCAX::CurveCalculation::CylinderDN(0.0, 0.0, defaultFrame3, radius, 1, 0);
	std::cout << tangentAt0.X() << std::endl;
	CHECK(tangentAt0.X() == 0.0);
	CHECK(tangentAt0.Y() == 2.0);
	CHECK(tangentAt0.Z() == 0.0);
}