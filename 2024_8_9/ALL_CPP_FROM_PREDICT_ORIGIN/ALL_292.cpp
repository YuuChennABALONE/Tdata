 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
#include <geometry/Geom3ConicalSurface.hpp>
using namespace AMCAX;
TEST_CASE("case1: Geom3ConicalSurface::CircleD1 1/4 ", "[math][Geom3ConicalSurface][P1][CircleD1]") {
	Frame3 frame;
	double major = 5.0;
	double minor = 4.0;
	double u1 = 0;
	double u2 = 2 * M_PI;
	Geom3ConicalSurface suface(frame, major, minor);
	OCCTIO::OCCTTool::Write(suface, OUTPUT_PATH_PREFIX"Geom3ConicalSurface_CircleD1.brep");
	IndexSet<TopoShape> vertices = GetTopoToolVertexsu1(suface, u1, u2, 10);
	IndexSet<TopoShape> vertices2 = GetTopoToolVertexsu1(suface, u1, u2, 10);
	TopoVertex v1 = static_cast<const TopoVertex&>(vertices[0]);
	TopoVertex v2 = static_cast<const TopoVertex&>(vertices2[0]);
	CHECK(OCCTIO::OCCTTool::Write(v1, OUTPUT_PATH_PREFIX"Geom3ConicalSurface_CircleD1_V1.brep"));
	CHECK(OCCTIO::OCCTTool::Write(v2, OUTPUT_PATH_PREFIX"Geom3ConicalSurface_CircleD1_V2.brep"));
	GlobalProperty props1, props2;
	double x, y, z;
	v1.Position().CartesianCoordinates(x, y, z);
	CHECK(x == Approx(5.0));
	CHECK(y == Approx(0.0));
	CHECK(z == Approx(0.0));
	v2.Position().CartesianCoordinates(x, y, z);
	CHECK(x == Approx(3.0));
	CHECK(y == Approx(4.0));
	CHECK(z == Approx(0.0));
}