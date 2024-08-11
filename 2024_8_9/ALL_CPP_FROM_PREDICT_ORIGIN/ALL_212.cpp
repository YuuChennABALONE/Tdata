 #include<catch.hpp>
#include<testHelper.h>
#include <geometry/MakeGeom2Circle.hpp>
#include <geometry/AdaptorGeom2Curve.hpp>
#include <geometry/Geom2TrimmedCurve.hpp>
#include <geometry/ComputePointsAbscissa.hpp>
#include <geometry/MakeGeom3Circle.hpp>
#include <geometry/AdaptorGeom3Curve.hpp>
#include <geometry/Geom2TrimmedCurve.hpp>
#include <geometry/MakeGeom2TrimmedCurve.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeEdge2d.hpp>
#include <geometry/GeometryTool.hpp>
#include <hatch/BRepClassificationTools.hpp>
#include <geometry/MakeGeom3TrimmedCurve.hpp>
#include <geometry/Geom3Surface.hpp>
#include <geometry/GeomAPIProjectPointOnCurve3.hpp>
#include <geometry/Geom3TrimmedCurve.hpp>
#include <topology/BRepExtremaDistShapeShape.hpp>
#include <modeling/MakeFace.hpp>
#include <topology/TopoFace.hpp>
#include <topology/TopoTool.hpp>
#include <topology/TopoCast.hpp>
#include <topology/TopoExplorer.hpp>
#include <topology/TopoEdge.hpp>
#include <topology/TopoExplorerTool.hpp>
#include <topology/TopoExplorerShapeTool.hpp>
#include <topology/TopoWire.hpp>
#include <topology/TopoExplorerTopoTool.hpp>
#include <topology/TopoCompound.hpp>
#include <topology/TopoExplorerBRepTool.hpp>
#include <topology/TopoVertex.hpp>
#include <math/Sphere.hpp>
#include <geometry/GeometryTool.hpp>
#include <geometry/MakeGeom2Hyperbola.hpp>
#include <geometry/AdaptorGeom2Curve.hpp>
#include <geometry/MakeGeom3Ellipse.hpp>
#include <geometry/AdaptorGeom3Curve.hpp>
#include <geometry/Geom2Ellipse.hpp>
#include <geometry/MakeGeom2Ellipse.hpp>
#include <geometry/MakeGeom3Hyperbola.hpp>
#include <geometry/Geom2Ellipse.hpp>
#include <geometry/Geom2Ellipse.hpp>
#include <geometry/Geom2Line.hpp>
#include <geometry/Geom2TrimmedCurve.hpp>
#include <geometry/MakeGeom2TrimmedCurve.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeEdge2d.hpp>
#include <geometry/GeometryTool.hpp>
#include <hatch/BRepClassificationTools.hpp>
#include <geometry/MakeGeom3TrimmedCurve.hpp>
#include <geometry/Geom3Surface.hpp>
#include <geometry/MakeGeom3TrimmedCurve.hpp>
#include <modeling/MakeFace.hpp>
#include <geometry/Geom3TrimmedCurve.hpp>
#include <geometry/Geom3TrimmedCurve.hpp>
#include <math/LineT.hpp>
#include <math/Plane.hpp>
#include <geometry/MakeGeom2Parabola.hpp>
#include <geometry/AdaptorGeom2Curve.hpp>
#include <geometry/MakeGeom3Parabola.hpp>
#include <geometry/AdaptorGeom3Curve.hpp>
#include <geometry/Geom2Parabola.hpp>
#include <geometry/Geom2TrimmedCurve.hpp>
#include <geometry/MakeGeom2TrimmedCurve.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeEdge2d.hpp>
#include <geometry/GeometryTool.hpp>
#include <hatch/BRepClassificationTools.hpp>
#include <geometry/MakeGeom3TrimmedCurve.hpp>
#include <geometry/Geom3Surface.hpp>
#include <geometry/MakeGeom3TrimmedCurve.hpp>
#include <modeling/MakeFace.hpp>
#include <geometry/Geom3TrimmedCurve.hpp>
#include <geometry/Geom3TrimmedCurve.hpp>
using namespace AMCAX;
TEST_CASE("case1:this is a case for GccCircle3Tangent", "[geometry][GccCircle3Tangent][P1]") {
	SECTION("Tangent to a curve and passing throught two points 3D") {
        Point3 p1(1.0, 0.0, 0.0);
        Direction3 d1(0.0, 0.0, 1.0);
        Frame3 fram3(p1, d1);
        double r = 3.0;
        std::shared_ptr<Geom3Curve> curve = make_shared<Geom3Curve>(MakeGeom3Circle(fram3, r));
        AdaptorGeom3Curve circle(curve);
        double param1 = 0.0;
        double param2 = 3.1415926;
        Point3 s1 = circle.Value(param1);
        Point3 s2 = circle.Value(param2);
        MakeGeom3TrimmedCurve mkcrv(circle, param1, param2);
        shared_ptr<Geom3Curve> crv1 = mkcrv.Value();
        shared_ptr<Geom3TrimmedCurve> crv2 = mkcr"}