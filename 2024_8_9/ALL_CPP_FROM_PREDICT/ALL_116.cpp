 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <modeling/MakeFace.hpp>
#include <modeling/MakeEdge.hpp>
#include <topology/BRepExtremaDistShapeShape.hpp>
#include <io/OBJTool.hpp>
#include <topology/TopoFace.hpp>
#include <topology/TopoEdge.hpp>
#include <hatch/BRepClassificationTools.hpp>
using namespace AMCAX;
TEST_CASE("case1: BRepExtremaDistShapeShape ", "[topology][BRepExtremaDistShapeShape][P1]") {
	TopoEdge e1(readModelINPath(dataPath + "edge.dat"));
	TopoEdge e2(readModelINPath(dataPath + "edge2.dat"));
	double lastDist = -1.0;
	AMCAX::BRepExtremaDistShapeShape bres5(e1, e2);
	bres5.FindMinDistance();
	double dist = bres5.Distance();
	AMCAX::Point3 point1;
	AMCAX::Point3 point2;
	e1.ParameterAt(dist, point1);
	e2.ParameterAt(dist, point2);
	CHECK(bres5.NearPoint() == true);
	CHECK(dist == lastDist);
	CHECK(point1.X() == point2.X());
	CHECK(point1.Y() == point2.Y());
	CHECK(point1.Z() == point2.Z());
}