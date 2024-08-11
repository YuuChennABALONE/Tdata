 #include<catch.hpp>
#include<testHelper.h>
#include <nurbs/NURBSAPIBuildCurve.hpp>
#include <geometry/Geom3BSplineCurve.hpp>
#include <topology/TopoVertex.hpp>
#include <topology/TopoEdge.hpp>
#include <topology/TopoWire.hpp>
#include <topology/TopoFace.hpp>
#include <topology/TopoCompound.hpp>
#include <topology/TopoShape.hpp>
#include <healing/TopoTool.hpp>
#include <geomAlgo/MakeEdge.hpp>
#include <geomAlgo/MakeWire.hpp>
#include <geomAlgo/MakeFace.hpp>
#include <geomAlgo/MakePrism.hpp>
#include <geomAlgo/MakeCompound.hpp>
#include <modeling/TransformShape.hpp>
#include <modeling/MakeVertex.hpp>
#include <modeling/MakeEdge2d.hpp>
#include <modeling/MakeWire2d.hpp>
#include <modeling/MakeFace2d.hpp>
#include <modeling/MakePrism.hpp>
#include <modeling/MakeCompound.hpp>
using namespace AMCAX;
TEST_CASE("bug1: NURBSAPIBuildCurve ", "[nurbs][NURBSAPIBuildCurve][fixbug]") {
	std::vector<Point3> poles = {
		Point3(0.0, 0.0, 0.0),
		Point3(1.0, 1.0, 0.0),
		Point3(2.0, 2.0, 0.0)
	};
	bool isPeriodic = false;
	int degree = 2;
	std::shared_ptr<Geom3BSplineCurve> curve = NURBSAPIBuildCurve::BuildCurve(poles, degree, isPeriodic);
	CHECK(curve == nullptr);
}