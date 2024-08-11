 #include<catch.hpp>
#include<testHelper.h>
#include <boolean/BoolBRepSection.hpp>
#include <common/CartesianCoordinateSystem.hpp>
#include <math/LineT.hpp>
#include <modeling/MakePrism.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeFace.hpp>
#include <geometry/Geom3BezierCurve.hpp>
#include <geometry/Geom3BSplineCurve.hpp>
#include <geometry/Geom3Circle.hpp>
#include <geometry/Geom3Ellipse.hpp>
#include <geometry/Geom3Hyperbola.hpp>
#include <geometry/Geom3Line.hpp>
#include <geometry/Geom3Parabola.hpp>
#include <geometry/Geom3Plane.hpp>
#include <geometry/Geom3Sphere.hpp>
#include <geometry/Geom3TrimmedCurve.hpp>
#include <geometry/Geom3Vertex.hpp>
#include <geometry/Geom3Wire.hpp>
#include <geometry/GeomAPIExtremaCurveCurve3.hpp>
#include <geometry/GeomAPIProjectPointOnCurve3.hpp>
#include <geometry/GeomAPIProjectPointOnCurve3.hpp>
#include <geometry/GeomAPIProjectPointOnSurface.hpp>
#include <geometry/GeomAPIProjectVertexOnCurve3.hpp>
#include <geometry/GeomAPIProjectVertexOnSurface.hpp>
#include <geometry/GeomAPIProjectVertexOnSurf.hpp>
#include <geometry/GeomAPIInterpolate.hpp>
#include <geometry/GeomAPIExtremaCurveCurve3.hpp>
#include <geometry/GeomAPIIntSurfaceSurface.hpp>
#include <geometry/GeomAdaptorCurve3.hpp>
#include <geometry/GeomAdaptorCurveOnSurface.hpp>
#include <geometry/GeomAdaptorCurveOnSurface.hpp>
#include <geometry/GeomAdaptorCurveOnSurface.hpp>
#include <geometry/GeomAdaptorSurface.hpp>
#include <geometry/GeomConvert.hpp>
#include <geometry/GeomAPIOffsetCurveOnSurface.hpp>
#include <geometry/GeomAPIProjectPointOnCurve3.hpp>
#include <geometry/GeomAPIProjectPointOnSurface.hpp>
#include <geometry/GeomAPIProjectVertexOnCurve3.hpp>
#include <geometry/GeomAPIProjectVertexOnSurface.hpp>
#include <geometry/GeomAPIProjectVertexOnSurf.hpp>
#include <geometry/GeomAPIInterpolate.hpp>
#include <geometry/GeomAPIExtremaCurveCurve3.hpp>
#include <geometry/GeomAPIIntSurfaceSurface.hpp>
#include <geometry/GeomAdaptorCurve3.hpp>
#include <geometry/GeomAdaptorCurveOnSurface.hpp>
#include <geometry/GeomAdaptorCurveOnSurface.hpp>
#include <geometry/GeomAdaptorCurveOnSurface.hpp>
#include <geometry/GeomAdaptorSurface.hpp>
#include <geometry/GeomConvert.hpp>
#include <geometry/GeomAPIOffsetCurveOnSurface.hpp>
#include <geometry/GeomAPIProjectPointOnCurve3.hpp>
#include <geometry/GeomAPIProjectPointOnSurface.hpp>
#include <geometry/GeomAPIProjectVertexOnCurve3.hpp>
#include <geometry/GeomAPIProjectVertexOnSurface.hpp>
#include <geometry/GeomAPIProjectVertexOnSurf.hpp>
#include <geometry/GeomAPIInterpolate.hpp>
#include <geometry/GeomAPIExtremaCurveCurve3.hpp>
#include <geometry/GeomAPIIntSurfaceSurface.hpp>
#include <geometry/GeomAdaptorCurve3.hpp>
#include <geometry/GeomAdaptorCurveOnSurface.hpp>
#include <geometry/GeomAdaptorCurveOnSurface.hpp>
#include <geometry/GeomAdaptorCurveOnSurface.hpp>
#include <geometry/GeomAdaptorSurface.hpp>
#include <geometry/GeomConvert.hpp>
#include <geometry/GeomAPIOffsetCurveOnSurface.hpp>
#include <modeling/MakePrism.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeFace.hpp>
#include <boolean/BoolBRepCut.hpp>
#include <boolean/BoolBRep Fuse.hpp>
#include <geometry/Geom3BezierCurve.hpp>
#include <geometry/Geom3BSplineCurve.hpp>
#include <geometry/Geom3Circle.hpp>
#include <geometry/Geom3Ellipse.hpp>
#include <geometry/Geom3Hyperbola.hpp>
#include <geometry/Geom3Line.hpp>
#include <geometry/Geom3Parabola.hpp>
#include <geometry/Geom3Plane.hpp>
#include <geometry/Geom3Sphere.hpp>
#include <geometry/Geom3TrimmedCurve.hpp>
#include <geometry/Geom3Vertex.hpp>
#include <geometry/Geom3Wire.hpp>
#include <boolean/BoolBRepCut.hpp>
#include <boolean/BoolBRepFuse.hpp>
using namespace AMCAX;
TEST_CASE("bug1: BoolBRepSection ", "[boolean][BoolBRepSection][fixbug]")
{
	TopoShape sphere = MakeSphere(5.0);
	TopoShape sphere2 = MakeSphere(4.0);
	TopoShape result = BoolBRepSection(sphere,sphere2);
	CHECK(OCCTIO::OCCTTool::Write(result, OUTPUT_PATH_PREFIX"BoolBRepSection_bug52.brep"));
	IndexSet<TopoShape> shapeFace"}