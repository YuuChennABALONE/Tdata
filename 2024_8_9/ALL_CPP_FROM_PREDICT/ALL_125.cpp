 #include <catch.hpp>
#include <testHelper.h>
#include <common/FrameT.hpp>
#include <common/VectorT.hpp>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
#include <occtio/OCCTTool.hpp>
#include <geometry/MakeArcOfHyperbola2d.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeVertex.hpp>
#include <modeling/MakeEdge2d.hpp>
using namespace AMCAX;
using namespace std;
TEST_CASE("case1:this is a case for Hyperbola2", "[math][Hyperbola2][p1]") {
	Point2 point2_Hy(0.0, 0.0);	
	Direction2 dir2_Hy(1.0, 0.0);
	Frame2 frame2_Hy(point2_Hy, dir2_Hy);
	double major2_Hy = 3.0, minor2_Hy = 4.0;
	Hyperbola2 hyperbola2d_ax(frame2_Hy, major2_Hy, minor2_Hy);
	SECTION("FocalParameter") {
		double FP = hyperbola2d_ax.FocalParameter();
		double focal2 = 2 * sqrt(major2_Hy * major2_Hy + minor2_Hy * minor2_Hy);
		double fp = 2 * minor2_Hy * minor2_Hy / focal2;;
		CHECK(FP == fp);
	}}