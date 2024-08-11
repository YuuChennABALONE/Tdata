 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <topology/TopoTool.hpp>
using namespace AMCAX;
TEST_CASE("bug1: TopoTool::MakePolygon  ", "[topology][TopoTool][fixbug]") {
	Point3 p1(0.0, 0.0, 0.0);
	Point3 p2(1.0, 0.0, 0.0);
	TopoShape polygon = TopoTool::MakePolygon(p1, p2);
	CHECK(polygon.Type() == ShapeType::Polygon);
	CHECK(OCCTIO::OCCTTool::Write(polygon, OUTPUT_PATH_PREFIX"TopoTool_Polygon.brep"));
}