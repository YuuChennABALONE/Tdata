/* "Cylinder()\t @brief Default constructor\n,\n",
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
TEST_CASE("case1:this is a case for Test Cylinder", "[math][Cylinder][P1]")
{
	Frame3 frame;
	double radius = 5.0;
	Cylinder cylinder(frame, radius);
	SECTION("Cylinder")
	{
		CHECK(cylinder.Radius() == Approx(radius));
		CHECK(cylinder.Location().X() == Approx(0.0));
		CHECK(cylinder.Location().Y() == Approx(0.0));
		CHECK(cylinder.Location().Z() == Approx(0.0));
		Cylinder cylinder1;
		CHECK(cylinder1.Location().X() == Approx(0.0));
		CHECK(cylinder1.Location().Y() == Approx(0.0));
		CHECK(cylinder1.Location().Z() == Approx(0.0));
	}}