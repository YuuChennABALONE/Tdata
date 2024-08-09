/* "[[nodiscard]] AxisT<double, DIM> Asymptote1()\t @return The positive asymptote\n\t @brief Get the asymptote of the hyperbola with positive slope\n,\n",
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
#include <iostream>
using namespace AMCAX;
using namespace std;
TEST_CASE("case1:this is a case for Hyperbola3", "[math][Hyperbola3][p1]") {
	Point3 point3_fr(0.0, 0.0, 1.0);
	Direction3 dir3_fr(0.0, 0.0, 1.0);
	Frame3 frame3(point3_fr, dir3_fr);
	double major3 = 3.0, minor3 = 4.0;
	Hyperbola3 hyperbola3d_fr(frame3, major3, minor3);
	SECTION("Asymptote1()") {
		Axis3 axis3d_asy = hyperbola3d_fr.Asymptote1();
		CHECK(axis3d_asy.Direction().X() / axis3d_asy.Direction().Y() == Approx(3.0 / 4.0));
		CHECK(axis3d_asy.Direction().Z() == Approx(0.0));
		Point3 point1(0.0, 0.0, 1.0);
		Line3 line3d_asy(axis3d_asy);
		MakeEdge edge1(line3d_asy);
		CHECK(BRepClassificationTools::IsPointInOnEdge(edge1, point1, 0.001) == true);
	}}