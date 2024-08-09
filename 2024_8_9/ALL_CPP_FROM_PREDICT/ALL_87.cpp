 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::CircleCalculation ", "[math][CurveCalculation][P1]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir); 
	double radius = 2.0; 
	double u1 = 0.0; 
	double u2 = M_PI_2; 
	Polygon3 polygon3 = Polygon3(4, defaultFrame3, initialDir, radius, u1, u2, false); 
	std::shared_ptr<Geom3Curve> curve = CurveCalculation::CircleCalculation(polygon3, 0.0); 
	AMCAX::GlobalProperty props1, props2;
	CHECK(curve->Properties(0.0, 1.0, props1, true, false) == Approx(12.5663706143591729).margin(1e-12));
	CHECK(curve->Properties(0.0, 1.0, props2, false, true) == Approx(2.0).margin(1e-12));
}