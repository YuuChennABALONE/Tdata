/* "[[nodiscard]] HyperbolaS ConjugateBranch1()\t @return The positive conjugate hyperbola\n\t @brief Get the conjugate hyperbola on the positive side of the minor axis\n,\n",
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
	SECTION("ConjugateBranch1()") {
		Hyperbola3 hyperbola3d_con = hyperbola3d_fr.ConjugateBranch1();
		CHECK(hyperbola3d_con.Location().X() == Approx(0.0));
		CHECK(hyperbola3d_con.Location().Y() == Approx(0.0));
		CHECK(hyperbola3d_con.Location().Z() == Approx(1.0));
		Point3 point1(0.0, 4.0, 1.0);
		Point3 point2(9.0 / 4.0, 5.0, 1.0);
		MakeEdge edge1(hyperbola3d_con);
		CHECK(BRepClassificationTools::IsPointInOnEdge(edge1, point1, 0.001) == true);
		CHECK(BRepClassificationTools::IsPointInOnEdge(edge1, point2, 0.001) == true);
		double major3d_con = hyperbola3d_con.MajorRadius();
		double minor3d_con = hyperbola3d_con.MinorRadius();
		CHECK(major3d_con == Approx(4.0));
		CHECK(minor3d_con == Approx(3.0));
	}}