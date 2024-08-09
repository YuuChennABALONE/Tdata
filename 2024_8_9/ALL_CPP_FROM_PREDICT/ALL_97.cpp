 #include <catch.hpp>
#include <testHelper.h>
#include <common/FrameT.hpp>
#include <modeling/MakeFace.hpp>
#include <common/AxisT.hpp>
#include <math/Parabola3.hpp>
#include <occtio/OCCTTool.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeVertex.hpp>
#include <modeling/MakeFace.hpp>
#include <iostream>
using namespace AMCAX;
using namespace std;
TEST_CASE("case1:this is a case for Test Parabola3", "[math][Parabola3][P1]")
{
	Point3 point3_fr(0.0, 0.0, 0.0);
	Direction3 dir3_fr(0.0, 0.0, 1.0);
	Frame3 frame3_fr(point3_fr, dir3_fr);
	double focal3 = 2.0;
	Parabola3 parabola3d_fr(frame3_fr, focal3);
	SECTION("FocalParameter")
	{
		double FP = parabola3d_fr.FocalParameter();
		double fp = 2.0 / 3.0;
		CHECK(FP == fp);
	}}