/* "AMCAX_API Cylinder(const Frame3& frame, double r)\t @param r The radius\n\t @param frame The local frame\n\t @brief Construct from a local frame and a radius\n,\n",
      */
 #include <catch.hpp>
#include <testHelper.h>
#include <common/FrameT.hpp>
#include <modeling/MakeFace.hpp>
#include <common/AxisT.hpp>
#include <math/Cylinder.hpp>
#include <common/VectorT.hpp>
#include <occtio/OCCTTool.hpp>
#include <modeling/MakeCylinder.hpp>
#include <iostream>
using namespace AMCAX;
using namespace std;
TEST_CASE("bug1:Cylinder ", "[math][Cylinder][fixbug]")
{
	Point3 point_cy(6.0, 0.0, 0.0);
	Direction3 dir_cy(0.0, 0.0, 1.0);
	Frame3 frame_cy(point_cy, dir_cy);
	double radius_cy = 5.0;
	Cylinder cylinder(frame_cy, radius_cy);
	double r = 0.0;
	SECTION("SetRadius1")
	{
		cylinder.SetRadius(r);
		CHECK(cylinder.Radius() == Approx(0.0));
	}
	r = -1.0;
	string str1;
	string str2 = "[_DomainError]";}