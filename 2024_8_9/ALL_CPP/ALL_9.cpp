/* "AMCAX_API static std::shared_ptr<Geom3BSplineCurve> ToBSpline(const std::shared_ptr<Geom3Curve>& curve)\t @return Result BSpline curve\n\t @param curve The given curve\n\t @brief Convert a common curve to a BSpline curve\n,\n",
      */
 #include<catch.hpp>
#include<testHelper.h>
#include<common/Exception.hpp>
#include <nurbs/NURBSAPIConvert.hpp>
#include <topology/TopoEdge.hpp>
#include <topology/TopoTool.hpp>
#include <topology/TopoVertex.hpp>
#include <geometry/Geom3TrimmedCurve.hpp>
#include <geometry/Geom3BSplineCurve.hpp>
#include <occtio/OCCTTool.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeFace.hpp>
#include <geometry/Geom3Circle.hpp>
#include <geometry/Geom3OffsetCurve.hpp>
#include <geometry/Geom3Line.hpp>
#include <geometry/Geom3BezierCurve.hpp>
#include <geometry/Geom3Ellipse.hpp>
#include <geometry/Geom3Hyperbola.hpp>
#include <geometry/Geom3Parabola.hpp>
#include <geometry/Geom3SphericalSurface.hpp>
#include <math/Sphere.hpp>
#include <geometry/Geom3Surface.hpp>
#include <geometry/Geom3BSplineSurface.hpp>
#include <geometry/Geom3TrimmedSurface.hpp>
#include <geometry/Geom3ElementarySurface.hpp>
#include <geometry/Geom3OffsetSurface.hpp>
#include <geometry/Geom3SweptSurface.hpp>
#include <geometry/Geom3SurfaceOfExtrusion.hpp>
#include <geometry/Geom3BezierSurface.hpp>
#include <math/Cone.hpp>
#include <geometry/Geom3ConicalSurface.hpp>
#include <geometry/Geom3CylindricalSurface.hpp>
#include <geometry/Geom3Plane.hpp>
#include <geometry/Geom3ToroidalSurface.hpp>
#include <geometry/Geom3SurfaceOfExtrusion.hpp>
#include <geometry/Geom3SurfaceOfRevolution.hpp>
using namespace std;
using namespace AMCAX;
double NurbsLinearCurve(const shared_ptr<Geom3Curve>& curve1, const shared_ptr<Geom3BSplineCurve>& curve2)
{
    TopoShape edge1 = MakeEdge(curve1);
    TopoShape edge2 = MakeEdge(curve2);
    GlobalProperty props1, props2;
    double len1 = GetLinearProperties(edge1, props1, true, false);
    double len2 = GetLinearProperties(edge2, props2, true, false);
    double len = abs(len1 - len2);
    return len;
}
double NurbsSurfaceResult(const shared_ptr<Geom3Surface>& surface1, const shared_ptr<Geom3BSplineSurface>& surface2)
{
    TopoFace f1 = MakeFace(surface1, 0.0);
    TopoFace f2 = MakeFace(surface2, 0.0);
    GlobalProperty props1, props2;
    double s1 = GetSurfaceProperties(f1, props1, true, false);
    double s2 = GetSurfaceProperties(f2, props2, true, false);
    double res = abs(s1 - s2);
    return res;
}
TEST_CASE("bug1: ConvertToBSplineCurve ", "[nurbs][convert][fixbug]")
{
    double res;
    double tol = 0.1;
    Point3 p(0.0, 0.0, 0.0);
    Direction3 dir(0.0, 0.0, 1.0);
    Direction3 dir1(1.0, 0.0, 0.0);
    shared_ptr<Geom3Curve> curve;
    curve = make_shared<Geom3Circle>(Frame3(p, dir), 1.0);
	SECTION("TrimmedCurve = M_PI")
    {
        shared_ptr<Geom3TrimmedCurve> TrimmedCurve = make_shared<Geom3TrimmedCurve>(curve, 0.0, M_PI);
        Axis3 axis(p, dir1);
        shared_ptr<Geom3SweptSurface> surf;
        surf = make_shared<Geom3SurfaceOfRevolution>(TrimmedCurve, axis);
        shared_ptr<Geom3BSplineSurface> bspSurf = NURBSAPIConvert::ToBSpline(surf);
        res = NurbsSurfaceResult(surf, bspSurf);
        CHECK(res <= tol);
    }}