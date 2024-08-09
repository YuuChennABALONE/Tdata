/* "void SetMinorRadius(double r)\t @param r The new minor radius\n\t @brief Set the minor radius\n,\n",
      */
 #include <catch.hpp>
#include <testHelper.h>
#include <common/DirectionT.hpp>
#include <common/FrameT.hpp>
#include <modeling/MakeFace.hpp>
#include <common/AxisT.hpp>
#include <math/HyperbolaT.hpp>
#include <occtio/OCCTTool.hpp>
#include <common/VectorT.hpp>
#include <hatch/BRepClassificationTools.hpp>
#include <topology/TopoEdge.hpp>
#include <modeling/MakeEdge2d.hpp>
#include <modeling/MakeEdge.hpp>
#include <common/TransformationT.hpp>
#include <iostream>
using namespace AMCAX;
using namespace std;
TEST_CASE("case1:this is a case for Hyperbola2", "[math][Hyperbola2][p1]") {
	Point2 point2_Hy(0.0, 0.0);	
	Direction2 dir2_Hy(1.0, 0.0);
	Axis2 major2_Axis(point2_Hy, dir2_Hy);
	double major2 = 3.0, minor2 = 4.0;
	Hyperbola2 hyperbola2d_ax(major2_Axis, major2, minor2, true);
	Point2 point2_fr(1.0, 1.0);
	Direction2 dir2_fr(0.0, 1.0);
	Frame2 frame2(point2_fr, dir2_fr);
	Hyperbola2 hyperbola2d_fr(frame2, major2, minor2);
	SECTION("SetMinorRadius()") {
		hyperbola2d_ax.SetMinorRadius(3.0);
		CHECK(hyperbola2d_ax.Location().X() == Approx(0.0));
		CHECK(hyperbola2d_ax.Location().Y() == Approx(0.0));
		CHECK(hyperbola2d_ax.MajorRadius() == Approx(3.0));
		CHECK(hyperbola2d_ax.MinorRadius() == Approx(3.0));
		Point3 point1(3.0, 0.0, 0.0);
		MakeEdge2d edge1(hyperbola2d_ax);
		CHECK(BRepClassificationTools::IsPointInOnEdge(edge1, point1, 0.001) == true);
	}}