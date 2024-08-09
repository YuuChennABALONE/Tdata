/* "HyperbolaS& Scale(const PointT<double, DIM>& point, double scale)\t @return The reference to self\n\t @param scale The scale value\n\t @param point The scaling center point\n\t @brief Scale the hyperbola by a center point\n,\n",
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
	SECTION("Scale()") {		
		Point3 point1(0.0, 0.0, 1.0);
		hyperbola3d_fr.Scale(point1, 0.5);
		CHECK(hyperbola3d_fr.Location().X() == Approx(0.0));
		CHECK(hyperbola3d_fr.Location().Y() == Approx(0.0));
		CHECK(hyperbola3d_fr.Location().Z() == Approx(1.0));
		Point3 point2(1.5, 0.0, 1.0);
		MakeEdge edge1(hyperbola3d_fr);
		CHECK(BRepClassificationTools::IsPointInOnEdge(edge1, point2, 0.001) == true);
	}}