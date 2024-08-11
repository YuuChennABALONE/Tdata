 #include<catch.hpp>
#include<testHelper.h>
#include <common/FrameT.hpp>
#include <math/EllipseT.hpp>
#include <geometry/MakeGeom2Ellipse.hpp>
#include <geometry/MakeGeom3Ellipse.hpp>
#include <geometry/MakeGeom2Hyperbola.hpp>
#include <geometry/MakeGeom3Hyperbola.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeVertex.hpp>
#include <geometry/GeometryTool.hpp>
#include <hatch/BRepClassificationTools.hpp>
#include <geometry/Geom2TrimmedCurve.hpp>
#include <geometry/Geom3TrimmedCurve.hpp>
#include <geometry/Geom2Ellipse.hpp>
#include <geometry/Geom3Ellipse.hpp>
#include <geometry/Geom2Hyperbola.hpp>
#include <geometry/Geom3Hyperbola.hpp>
#include <geometry/Geom2Parabola.hpp>
#include <geometry/Geom3Parabola.hpp>
#include<modeling/MakeEdge.hpp>
#include <modeling/MakeVertex.hpp>
#include <geometry/GeometryTool.hpp>
#include <hatch/BRepClassificationTools.hpp>
#include <geometry/Geom2TrimmedCurve.hpp>
#include <geometry/Geom3TrimmedCurve.hpp>
#include <geometry/Geom2Ellipse.hpp>
#include <geometry/Geom3Ellipse.hpp>
#include <geometry/Geom2Hyperbola.hpp>
#include <geometry/Geom3Hyperbola.hpp>
#include <geometry/Geom2Parabola.hpp>
#include <geometry/Geom3Parabola.hpp>
#include <topology/BRepExtremaDistShapeShape.hpp>
#include <geometry/Geom2Ellipse.hpp>
#include <geometry/Geom3Ellipse.hpp>
#include <geometry/Geom2Hyperbola.hpp>
#include <geometry/Geom3Hyperbola.hpp>
#include <geometry/Geom2Parabola.hpp>
#include <geometry/Geom3Parabola.hpp>
#include <geometry/Geom2Line.hpp>
#include <geometry/Geom3Line.hpp>
#include <geometry/Geom2OffsetCurve.hpp>
#include <geometry/Geom3OffsetCurve.hpp>
#include <geometry/Geom2Spiral.hpp>
#include <geometry/Geom3Spiral.hpp>
#include <geometry/Geom2BezierCurve.hpp>
#include <geometry/Geom3BezierCurve.hpp>
#include <geometry/Geom2BSplineCurve.hpp>
#include <geometry/Geom2BSplineCurve2.hpp>
#include <geometry/Geom3BSplineCurve.hpp>
#include <geometry/Geom3BSplineCurve2.hpp>
#include <topology/BRepExtremaDistShapeShape.hpp>
#include <topology/TopoTool.hpp>
#include <topology/TopoVertex.hpp>
#include <topology/TopoEdge.hpp>
#include <topology/TopoWire.hpp>
#include <topology/TopoFace.hpp>
#include <topology/TopoCompound.hpp>
#include <topology/TopoShape.hpp>
#include <topology/TopoTool.hpp>
#include <iostream>
using namespace AMCAX;
TEST_CASE("bug1: MakeGeom3Ellipse ", "[geometry][MakeGeom3Ellipse][fixbug]") {
	SECTION("test32") {
		Point3 s1(0.0, 0.0, 0.0);
		Point3 s2(1.0, 0.0, 0.0);
		Point3 s3(0.0, 1.0, 0.0);
		Ellipse3 ellipse3(s1, s2, s3);
		MakeGeom3Ellipse makeEllipse3;
		makeEllipse3.Set(s1, s2, s3);
		Ellipse3 ellipse31 = makeEllipse3.Value();
		CHECK(ellipse3.IsSimilar(ellipse31, 0.001, true, Point3(0.0, 0.0, 0.0), Frame3()));
		Point3 s4(-1.0, 0.0, 0.0);
		Ellipse3 ellipse32(s4, 1.0, 0.0);
		CHECK(ellipse32.IsSimilar(ellipse31, 0.001, true, Point3(0.0, 0.0, 0.0), Frame3()));
	}}