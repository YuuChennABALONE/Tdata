/* "AMCAX_API Geom3ConicalSurface(const Frame3& frame, double r, double angle)\t @param angle The semi-angle\n\t @param r The reference radius\n\t @param frame The local frame\n\t @brief Construct from a local frame, a reference radius and a semi-angle\n,\n",
      */
 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
#include <geometry/Geom3ConicalSurface.hpp>
using namespace AMCAX;
TEST_CASE("case1: Geom3ConicalSurface::CircleD1 1/4 ", "[math][Geom3ConicalSurface][P1][CircleD1]") {
	Direction3 initialDir(0.0, 0.0, 1.0); 
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir);
	AMCAX::Geom3ConicalSurface suface(defaultFrame3, 5.0, 1);
}