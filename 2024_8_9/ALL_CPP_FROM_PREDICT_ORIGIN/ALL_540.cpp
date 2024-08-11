 #include<catch.hpp>
#include<testHelper.h>
#include <boolean/MakeFace.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeFace.hpp>
#include <modeling/MakePrism.hpp>
#include <geometry/Geom3BSplineSurface.hpp>
#include <geometry/Geom3BSplineCurve.hpp>
#include <geometry/GeometryTool.hpp>
#include <topology/BRepExtremaDistShapeShape.hpp>
#include <topology/TopoEdge.hpp>
#include <topology/TopoFace.hpp>
#include <topology/TopoTool.hpp>
#include <topology/TopoVertex.hpp>
#include <hatch/BRepClassificationTools.hpp>
#include <geometry/Geom3Surface.hpp>
#include <geometry/Geom3Line.hpp>
#include <geometry/Geom3TrimmedCurve.hpp>
#include <geometry/GeomAPIProjectPointOnCurve3.hpp>
#include <geometry/GeometryTool.hpp>
#include <geometry/Geom3BezierCurve.hpp>
#include <geometry/Geom3Circle.hpp>
#include <geometry/Geom3OffsetCurve.hpp>
#include <geometry/Geom3Hyperbola.hpp>
#include <geometry/Geom3Ellipse.hpp>
#include <geometry/Geom3Line2d.hpp>
#include <geometry/Geom3Parabola.hpp>
#include <geometry/Geom3SphericalSurface.hpp>
#include <geometry/Geom3BezierSurface.hpp>
#include <geometry/Geom3Cone.hpp>
#include <geometry/Geom3Surface.hpp>
#include <geometry/Geom3Plane.hpp>
#include <geometry/Geom3Sphere.hpp>
#include <geometry/Geom3Torus.hpp>
#include <geometry/Geom3TrimmedSurface.hpp>
#include <geometry/Geom3UntrimmedSurface.hpp>
#include <geometry/Geom3BSplineCurve.hpp>
#include <geometry/GeomAPIExtremaCurveCurve3.hpp>
#include <geometry/GeomAPIInterpolate.hpp>
#include <geometry/GeomAPIProjectPointOnCurve2.hpp>
#include <geometry/GeomAPIProjectPointOnSurface.hpp>
#include <geometry/GeomAPIProjectVertexOnCurve3.hpp>
#include <geometry/GeomAPIProjectVertexOnSurface.hpp>
#include <geometry/GeomAPITrimmedSurface.hpp>
#include <geometry/Geom3BezierCurve.hpp>
#include <geometry/GeomAPIInterpolate.hpp>
#include <geometry/GeomAPIProjectPointOnCurve3.hpp>
#include <geometry/GeomAPIProjectPointOnSurface.hpp>
#include <geometry/GeomAPIProjectVertexOnCurve3.hpp>
#include <geometry/GeomAPIProjectVertexOnSurface.hpp>
#include <geometry/GeomAPITrimmedSurface.hpp>
#include <geometry/Geom3BSplineSurface.hpp>
#include <geometry/Geom3Cone.hpp>
#include <geometry/Geom3Hyperbola.hpp>
#include <geometry/Geom3Ellipse.hpp>
#include <geometry/Geom3Line2d.hpp>
#include <geometry/Geom3Parabola.hpp>
#include <geometry/Geom3SphericalSurface.hpp>
#include <geometry/Geom3BezierSurface.hpp>
#include <geometry/Geom3Circle.hpp>
#include <geometry/Geom3OffsetCurve.hpp>
#include <geometry/Geom3Plane.hpp>
#include <geometry/Geom3Sphere.hpp>
#include <geometry/Geom3Torus.hpp>
#include <geometry/Geom3TrimmedCurve.hpp>
#include <geometry/Geom3TrimmedSurface.hpp>
#include <geometry/Geom3UntrimmedSurface.hpp>
#include <geometry/Geom3Line.hpp>
#include <hatch/BRepClassificationTools.hpp>
#include <hatch/BRepClassificationTools.hpp>
#include <geometry/GeomAPIExtremaCurveCurve3.hpp>
#include <geometry/GeomAPIExtremaSurfaceSurface.hpp>
#include <geometry/GeomAPIProjectPointOnCurve2.hpp>
#include <geometry/GeomAPIProjectPointOnSurface.hpp>
#include <geometry/GeomAPIProjectVertexOnCurve3.hpp>
#include <geometry/GeomAPIProjectVertexOnSurface.hpp>
#include <geometry/GeomAPITrimmedSurface.hpp>
#include <iostream>
#include <sstream>
using namespace AMCAX;
using namespace std;
TEST_CASE("test the bug of BlendSurfaces ", "[geometry][BlendSurfaces][fixbug]") {
    shared_ptr<Geom3BSplineSurface> surf1 = make_shared<Geom3BSplineSurface>(Geom3Hyperbola(), 15, 15);
    shared_ptr<Geom3BSplineSurface> surf2 = make_shared<Geom3BSplineSurface>(Geom3Ellipse(), 15, 15);
    CHECK(BlendSurfaces(surf1, true, true, surf2, true, true, 0.0, 0.0, 0.0, true, true, 0.0) != nullptr);
}