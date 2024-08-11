 #include<catch.hpp>
#include<testHelper.h>
#include <nurbs/NURBSAPIBuildCurveFromSpline.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeVertex.hpp>
#include <geometry/Geom3BSplineCurve.hpp>
#include <geometry/Geom3BSplineSurface.hpp>
#include <topology/BRepExtremaDistShapeShape.hpp>
#include <topology/TopoTool.hpp>
#include <io/ShapeTool.hpp>
#include <hatch/BRepClassificationTools.hpp>
#include <geometry/Geom3Surface.hpp>
#include <geometry/Geom3Line.hpp>
#include <geometry/Geom3TrimmedCurve.hpp>
#include <topology/TopoExplorer.hpp>
#include <topology/TopoFace.hpp>
#include <topology/TopoTool.hpp>
#include <topology/TopoExplorerTool.hpp>
#include <topology/TopoCast.hpp>
#include <topology/TopoVertex.hpp>
#include <topology/TopoEdge.hpp>
#include <topology/TopoWire.hpp>
#include <topology/TopoShape.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeFace.hpp>
#include <topology/BRepExtremaDistShapeShape.hpp>
#include <geometry/Geom3Line.hpp>
#include <geometry/Geom3Plane.hpp>
#include <geometry/Geom3TrimmedSurface.hpp>
#include <geometry/Geom3Surface.hpp>
#include <math/Sphere.hpp>
#include <geometry/Geom3Ellipse.hpp>
#include <geometry/Geom3Hyperbola.hpp>
#include <geometry/Geom3Parabola.hpp>
using namespace AMCAX;
TEST_CASE("bug1: NURBSAPIBuildCurveFromSpline ", "[nurbs][NURBSAPIBuildCurveFromSpline][fixbug]") {
	Point3 p1(-0.1, 0.0, 0.0);
	Point3 p2(-0.1, 0.0, 0.1);
	Point3 p3(0.1, 0.0, 0.1);
	Point3 p4(0.1, 0.0, 0.0);
	Point3 p5(-0.1, 0.0, -0.1);
	Point3 p6(-0.1, 0.0, -0.0);
	Point3 p7(0.1, 0.0, -0.0);
	Point3 p8(0.1, 0.0, -0.1);
	std::vector<Point3> poles = { p1, p2, p3, p4, p5, p6, p7, p8 };
	std::vector<double> weights = { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 };
	std::vector<double> knots = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
	std::vector<int> mults = { 1, 1, 1, 1, 1, 1, 1, 1 };
	int degree = 3;
	bool isPeriodic = false;
	bool checkRational = true;
	AMCAX::Geom3BSplineCurve bspCurve(poles, weights, knots, mults, degree, isPeriodic, checkRational);
	CHECK(bspCurve.IsRational());
	AMCAX::Point3 sp = bspCurve.Value(0.0);
	CHECK(sp.X() == 0.0);
	CHECK(sp.Y() == 0.0);
	CHECK(sp.Z() == 0.0);
}