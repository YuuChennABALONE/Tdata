 #include<catch.hpp>
#include<testHelper.h>
#include <common/FrameT.hpp>
#include <common/TransformationT.hpp>
#include <modeling/MakeFace.hpp>
#include <common/AxisT.hpp>
#include <common/PointT.hpp>
#include <math/HyperbolaT.hpp>
#include <common/VectorT.hpp>
#include <occtio/OCCTTool.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeVertex.hpp>
#include <modeling/MakeEdge2d.hpp>
#include <modeling/MakeFace.hpp>
#include <topology/BRepGlobalProperty.hpp>
#include <topology/TopoTool.hpp>
#include <topology/TopoCast.hpp>
#include <topology/TopoExplorer.hpp>
#include <topology/TopoEdge.hpp>
#include <topology/TopoWire.hpp>
#include <topology/TopoFace.hpp>
#include <topology/TopoShape.hpp>
#include <iostream>
#define tol 0.001
#define tolDis 0.001
#define tolAng 0.01
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
	SECTION("Default constructor") {
		Hyperbola2 hyperbola2d_de;	
		CHECK(hyperbola2d_de.Location().X() == Approx(0.0));
		CHECK(hyperbola2d_de.Location().Y() == Approx(0.0));
		CHECK(hyperbola2d_de.MajorRadius() == Approx(1.0));
		CHECK(hyperbola2d_de.MinorRadius() == Approx(1.0));
		CHECK(hyperbola2d_de.Focal() == Approx(2.0));
		CHECK(hyperbola2d_de.Focus1().X() == Approx(1.0));
		CHECK(hyperbola2d_de.Focus1().Y() == Approx(0.0));
	}}