 #include<catch.hpp>
#include<testHelper.h>
#include <nurbs/NURBSAPIToBSpline.hpp>
#include <geometry/Geom3BSplineCurve.hpp>
#include <geometry/Geom3BSplineSurface.hpp>
#include <topology/TopoFace.hpp>
#include <topology/TopoTool.hpp>
#include <hatch/BRepClassificationTools.hpp>
using namespace AMCAX;
TEST_CASE("bug1: This is a bug test for NURBSAPIToBSpline  ", "[nurbs][NURBSAPIToBSpline][fixbug]") {
	TopoFace face;
	OCCTIO::OCCTTool::Read(face, INPUT_PATH_PREFIX"face.brep");
	auto bspCurve1 = NURBSAPIToBSpline::ToBSpline(face, 3);
	CHECK(bspCurve1 == nullptr);
}