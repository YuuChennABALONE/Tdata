 #include <catch.hpp>
#include <testHelper.h>
#include <common/FrameT.hpp>
#include <common/TransformationT.hpp>
#include <modeling/MakeFace.hpp>
#include <common/AxisT.hpp>
#include <math/EllipseT.hpp>
#include <occtio/OCCTTool.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeVertex.hpp>
#include <modeling/MakeFace.hpp>
#include <iostream>
using namespace AMCAX;
using namespace std;
TEST_CASE("case1:this is a case for Test Ellipse3", "[math][Ellipse3][p1]") {
	Frame3 frame;
	double major = 5.0;
	double minor = 4.0;
	Ellipse3 ellipse(frame, major, minor);
	SECTION("FocalParameter") {
		double FP = ellipse.FocalParameter();
		double focal = 2 * sqrt(major * major - minor * minor);
		double fp = 2 * minor * minor / focal;;
		CHECK(FP == fp);
	}}