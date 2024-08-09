 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::ParabolaD3 1/4 ", "[math][CurveCalculation][P1][ParabolaD3]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
	double focal = 2.0;
	Vector3  vector3 = CurveCalculation::ParabolaD3(0.0, defaultFrame3, focal);
	AMCAX::PointT<double, 3> result;
	defaultFrame3.Transform(vector3, result);
	std::cout << result.X() << " " << result.Y() << " " << result.Z() << std::endl;
	CHECK(result.X() == 3.0);
	CHECK(result.Y() == Approx(3.0));
	CHECK(result.Z() == 0.0);
}