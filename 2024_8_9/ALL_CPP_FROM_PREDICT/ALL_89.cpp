 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <modeling/MakeEdge2d.hpp>
#include <modeling/MakeWire.hpp>
#include <topology/BRepExtremaProximityTool.hpp>
#include <modeling/MakeFace.hpp>
#include <topology/TopoFace.hpp>
#include <modeling/MakeEdge.hpp>
#include <topology/TopoEdge.hpp>
#include <geometry/Geom3BezierCurve.hpp>
#include <geometry/Geom3BSplineCurve.hpp>
#include <geometry/Adaptor3CurveOnSurface.hpp>
#include <geometry/Geom3Circle.hpp>
#include <geometry/Geom3Line.hpp>
#include <geometry/Geom3TrimmedCurve.hpp>
#include <geometry/Geom3Ellipse.hpp>
#include <geometry/Geom3Hyperbola.hpp>
#include <geometry/Geom3Parabola.hpp>
#include <geometry/GeomAPIProjectPointOnCurve3.hpp>
#include <geometry/Geom2BSplineCurve.hpp>
#include <geometry/Geom2Circle.hpp>
#include <geometry/Geom2Ellipse.hpp>
#include <geometry/Geom2Line.hpp>
#include <geometry/Geom2Parabola.hpp>
#include <geometry/Geom2Hyperbola.hpp>
#include <geometry/GeomAPIProjectPointOnCurve2.hpp>
#include <geometry/GeomAPIProjectPointOnCurve3.hpp>
#include <geometry/GeomAPIProjectPointOnSurface.hpp>
#include <geometry/GeomAPIProjectVertexOnCurve2.hpp>
#include <modeling/MakePrism.hpp>
#include <modeling/MakeRevol.hpp>
#include <modeling/MakeCompound.hpp>
#include <geometry/GeometryTool.hpp>
#include <geometry/GeomAPIExtremaCurveCurve3.hpp>
#include <geometry/GeomAPIExtremaSurfaceSurface.hpp>
#include <geometry/GeomAPIProjectCurveOnSurface.hpp>
#include <geometry/GeomAPIIntSurfaceSurface.hpp>
#include <geometry/GeomAPIInterCurveCurve.hpp>
#include <geometry/GeomAPIProjectCurveOnSurface.hpp>
#include <geometry/GeomAPIProjectVertexOnSurface.hpp>
#include <geometry/GeomAPITrimmedCurve.hpp>
#include <geometry/GeomAPIOffsetCurve2.hpp>
#include <geometry/GeomAPIOffsetCurve3.hpp>
#include <geometry/GeomAPIOffsetSurface.hpp>
#include <geometry/GeomAPIProjectPointOnCurve2.hpp>
#include <geometry/GeomAPIProjectVertexOnCurve2.hpp>
#include <geometry/GeomAPIProjectVertexOnCurve3.hpp>
#include <geometry/GeomAPIProjectVertexOnSurface.hpp>
#include <geometry/GeomAPIRebuildCurve.hpp>
#include <geometry/GeomAPIRebuildSurface.hpp>
#include <geometry/GeomAPITransformCurve.hpp>
#include <geometry/GeomAPITransformShape.hpp>
#include <geometry/GeomAPIProjectFaceOnSurface.hpp>
#include <geometry/GeomAPIProjectEdgeOnSurface.hpp>
#include <geometry/GeomAPIProjectFaceOnSurface.hpp>
#include <geometry/GeomAPIProjectEdgeOnSurface.hpp>
#include <geometry/GeomAPIProjectEdgeOnFace.hpp>
#include <geometry/GeomAPIProjectFaceOnFace.hpp>
#include <geometry/GeomAPIReflection.hpp>
#include <geometry/GeomAPIRotate.hpp>
#include <geometry/GeomAPIScale.hpp>
#include <geometry/GeomAPITranslate.hpp>
#include <geometry/GeomAPIWeld.hpp>
#include <geometry/GeomAdaptorCurve3.hpp>
#include <geometry/GeomAdaptorCurve2.hpp>
#include <geometry/GeomAdaptorSurface.hpp>
#include <geometry/GeomApproxCurve3.hpp>
#include <geometry/GeomApproxCurve2.hpp>
#include <geometry/GeomAPISurfaceProperty.hpp>
#include <geometry/GeomAPIVolumeProperty.hpp>
#include <geometry/GeomAPITransformVertex.hpp>
#include <geometry/GeomAPIProjectEdgeOnEdge.hpp>
#include <geometry/GeomAPIProjectEdgeOnEdge.hpp>
#include <geometry/GeomAPIProjectEdgeOnWire.hpp>
#include <geometry/GeomAPIProjectEdgeOnWire.hpp>
#include <geometry/GeomAPIProjectFaceOnWire.hpp>
#include <geometry/GeomAPIProjectFaceOnWire.hpp>
#include <geometry/GeomAPIProjectEdgeOnWire.hpp>
#include <geometry/GeomAPIProjectEdgeOnWire.hpp>
#include <geometry/GeomAPIProjectEdgeOnWire.hpp>
#include <geometry/GeomAPIProjectEdgeOnWire.hpp>
#include <geometry/GeomAPIProjectEdgeOnWire.hpp>
#include <geometry/GeomAPIProjectEdgeOnWire.hpp>
#include <geometry/GeomAPIProjectEdgeOnWire.hpp>
#include <geometry/GeomAPIProjectEdgeOnWire.hpp>
#include <geometry/GeomAPIProjectEdgeOnWire.hpp>
#include <geometry/GeomAPIProjectEdgeOnWire.hpp>
#include <geometry/GeomAPIProjectEdgeOnWire.hpp>
#include <geometry/GeomAPIProjectEdgeOnWire.hpp>
#include <geometry/GeomAPIProjectEdgeOnWire.hpp>
#include <geometry/GeomAPIProjectEdgeOnWire.hpp>
#include <geometry/GeomAPIProjectEdgeOnWire.hpp>
#include <geometry/GeomAPIProjectEdgeOn"
{