/* "AMCAX_API Cylinder& Scale(const Point3& point, double scale)\t @return The reference to self\n\t @param scale The scale value\n\t @param point The scaling center point\n\t @brief Scale the cylinder by a point\n,\n",
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
TEST_CASE("case2:this is a case for Test Cylinder_Mirror&Mirrored/Rotate&Rotated/Scale&Scaled", "[math][Cylinder][P1]")
{
	Point3 point_cy(6.0, 0.0, 0.0);
	Direction3 dir_cy(0.0, 0.0, 1.0);
	Frame3 frame_cy(point_cy, dir_cy);
	double radius_cy = 5.0;
	Cylinder cylinder(frame_cy, radius_cy);
	SECTION("Scale")
	{
		Cylinder scale_cylinder = cylinder.Scale(point_cy, scale);
		CHECK(cylinder.Radius() == Approx(2.5));
		CHECK(cylinder.Location().X() == Approx(6.0));
		CHECK(cylinder.Location().Y() == Approx(0.0));
		CHECK(cylinder.Location().Z() == Approx(0.0));
		CHECK(cylinder.Axis().Direction().X() == 0.0);
		CHECK(cylinder.Axis().Direction().Y() == 0.0);
		CHECK(cylinder.Axis().Direction().Z() == 1.0);
		CHECK(scale_cylinder.Radius() == Approx(2.5));
		CHECK(scale_cylinder.Location().X() == Approx(6.0));
		CHECK(scale_cylinder.Location().Y() == Approx(0.0));
		CHECK(scale_cylinder.Location().Z() == Approx(0.0));
		CHECK(scale_cylinder.Axis().Direction().X() == 0.0);
		CHECK(scale_cylinder.Axis().Direction().Y() == 0.0);
		CHECK(scale_cylinder.Axis().Direction().Z() == 1.0);
	}
	scale = 2.0;}