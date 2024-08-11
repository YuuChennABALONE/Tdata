 #include<catch.hpp>
#include<testHelper.h>
#include <geometry/MakeGeom3Sweep.hpp>
#include <geometry/AdaptorGeom3Sweep.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeVertex.hpp>
#include <geometry/GeometryTool.hpp>
#include <geometry/Geom3Surface.hpp>
#include <geometry/Geom3Curve.hpp>
#include <geometry/Geom3Point.hpp>
#include <geometry/AdaptorGeom3Curve.hpp>
#include <geometry/GeometryTool.hpp>
#include <topology/BRepExtremaDistShapeShape.hpp>
#include <topology/TopoTool.hpp>
#include <topology/TopoVertex.hpp>
#include <topology/TopoEdge.hpp>
#include <topology/TopoFace.hpp>
#include <topology/TopoTool.hpp>
#include <topology/TopoShape.hpp
>
using namespace AMCAX;
TEST_CASE("bug1: this is a bug fix test for AMCAX::MakeGeom3Sweep", "[geometry][MakeGeom3Sweep][fixbug]") {
	std::vector<std::shared_ptr<Geom3Curve>> curves;
	curves.push_back(std::make_shared<Geom3TrimmedCurve>(Guideline1,D初等曲线(0.0,0.0,0.0),2.0));
	curves.push_back(std::make_shared<Geom3TrimmedCurve>(Guideline2,D初等曲线(0.0,0.0,0.0),2.0));
	curves.push_back(std::make_shared<Geom3Hyperbola>(Guideline3, Guideline4));
	curves.push_back(std::make_shared<Geom3Ellipse>(Guideline5, Guideline6));
	curves.push_back(std::make_shared<Geom3Circle>(Guideline7, 2.0));
	std::vector<std::pair<double, bool>> paramCorrespondece = MakeGeom3Sweep::CalcParamCorrespondece(curves, true, false);
	CHECK(paramCorrespondece.size() == 5);
	CHECK(paramCorrespondece[0].first == 0.0);
	CHECK(paramCorrespondece[0].second == true);
	CHECK(paramCorrespondece[1].first == 0.0);
	CHECK(paramCorrespondece[1].second == false);
	CHECK(paramCorrespondece[2].first == 0.0);
	CHECK(paramCorrespondece[2].second == true);
	CHECK(paramCorrespondece[3].first == 0.0);
	CHECK(paramCorrespondece[3].second == true);
	CHECK(paramCorrespondece[4].first == 0.0);
	CHECK(paramCorrespondece[4].second == true);
}