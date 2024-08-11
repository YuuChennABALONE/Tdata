 #include<catch.hpp>
#include<testHelper.h>
#include <common/FrameT.hpp>
#include <common/PointT.hpp>
#include <common/TransformationT.hpp>
#include <math/ConeT.hpp>
using namespace AMCAX;
using namespace std;
TEST_CASE("case1:this is a case for TestCone", "[math][ConeT][P1]")
{
	Frame3 frame;
	double semiMajor = 3.0;
	double semiMinor = 4.0;
	ConeT cone(frame, semiMajor, semiMinor);
	SECTION("Apex")
	{
		Point3 point = cone.Apex();
		CHECK(point.X() == 0.0);
		CHECK(point.Y() == 0.0);
		CHECK(point.Z() == 0.0);
	}}