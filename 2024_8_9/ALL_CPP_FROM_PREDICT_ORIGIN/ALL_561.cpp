 #include<catch.hpp>
#include<testHelper.h>
#include <modeling/MakeFace.hpp>
#include <geometry/GeometryTool.hpp>
#include <geometry/Geom3BSplineCurve.hpp>
#include <geometry/Geom3BSplineSurface.hpp>
#include <topology/TopoFace.hpp>
#include <topology/TopoTool.hpp>
#include <hatch/BRepClassificationTools.hpp>
#include <io/AMCAXOCCTTool.hpp>
#include <common/PointT.hpp>
#include <math/TriangularMesh.hpp>
#include <geometry/Geom3SurfaceSamples.hpp>
#include <topology/BRepExtremaDistShapeShape.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeEdge2d.hpp>
#include <topology/BRepAdaptorCurve3.hpp>
using namespace AMCAX;
TEST_CASE("bug1: this is a fix bug case for AMCAX::SweepWithTwoGuideCurves ", "[geometry][SweepWithTwoGuideCurves][fixbug]") {
	OUTPUT_DIRECTORY(topology, OverlapSurface/bug1);
	std::shared_ptr<Geom3BSplineCurve> profile = make_shared<Geom3BSplineCurve>(Point3(0.0, 0.0, 0.0), Direction3(0.0, 0.0, 1.0), make_shared<Geom3BezierCurve>(Vector3(0.0, 0.0, 0.0), Vector3(1.0, 0.0, 0.0), Vector3(2.0, 0.0, 0.0), Vector3(3.0, 0.0, 0.0)));
	std::shared_ptr<Geom3BSplineCurve> guide1 = make_shared<Geom3BSplineCurve>(Point3(0.0, 0.0, 0.0), Direction3(0.0, 0.0, 1.0), make_shared<Geom3BezierCurve>(Vector3(0.0, 0.0, 0.0), Vector3(1.0, 0.0, 0.0), Vector3(2.0, 0.0, 0.0), Vector3(3.0, 0.0, 0.0)));
	std::shared_ptr<Geom3BSplineCurve> guide2 = make_shared<Geom3BSplineCurve>(Point3(0.0, 0.0, 0.0), Direction3(0.0, 0.0, 1.0), make_shared<Geom3BezierCurve>(Vector3(0.0, 0.0, 0.0), Vector3(1.0, 0.0, 0.0), Vector3(2.0, 0.0, 0.0), Vector3(3.0, 0.0, 0.0)));
	Point3 anchorPoint(0.0, 0.0, 0.0);
	Direction3 anchorDirection(0.0, 0.0, 1.0);
	std::shared_ptr<Geom3BSplineCurve> spine = make_shared<Geom3BSplineCurve>(Point3(0.0, 0.0, 0.0), Direction3(0.0, 0.0, 1.0), make_shared<Geom3BezierCurve>(Vector3(0.0, 0.0, 0.0), Vector3(1.0, 0.0, 0.0), Vector3(2.0, 0.0, 0.0), Vector3(3.0, 0.0, 0.0)));
	double spineLeftBound = 0.0;
	double spineRightBound = 1.0;
	auto status = AMCAX::SweepWithTwoGuideCurves(profile, guide1, guide2, anchorPoint, anchorDirection, spine, spineLeftBound, spineRightBound);
	auto surface = std::dynamic_pointer_cast<Geom3BSplineSurface>(MakeFace(profile, 0.0));
	auto surface1 = std::dynamic_pointer_cast<Geom3BSplineSurface>(SweepWithTwoGuideCurves(profile, guide1, guide2, anchorPoint, anchorDirection, spine, spineLeftBound, spineRightBound));
	CHECK(OCCTIO::OCCTTool::Write(surface, outdir + "surface.brep"));
	CHECK(OCCTIO::OCCTTool::Write(surface1, outdir + "surface1.brep"));
	auto point1 = GlobalProperty::PointOnSurface(surface, 0.0);
	auto point2 = GlobalProperty::PointOnSurface(surface1, 0.0);
	CHECK(point1.X() == point2.X());
	CHECK(point1.Y() == point2.Y());
	CHECK(point1.Z() == point"}