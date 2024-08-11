 #include<catch.hpp>
#include<testHelper.h>
#include <boolean/BoolBRepSection.hpp>
#include <common/CartesianCoordinateSystem.hpp>
#include <math/LineT.hpp>
#include <modeling/MakePrism.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeFace.hpp>
#include <modeling/MakeVertex.hpp>
#include <geometry/Geom3BezierCurve.hpp>
#include <geometry/Geom3BSplineCurve.hpp>
#include <geometry/Geom3Circle.hpp>
#include <geometry/Geom3Line.hpp>
#include <geometry/Geom3OffsetCurve.hpp>
#include <geometry/Geom3TrimmedCurve.hpp>
#include <geometry/Geom3Ellipse.hpp>
#include <geometry/Geom3Hyperbola.hpp>
#include <geometry/Geom3Parabola.hpp>
#include <geometry/Geom3Plane.hpp>
#include <geometry/Geom3Point.hpp>
#include <geometry/Geom3Sphere.hpp>
#include <geometry/Geom3Torus.hpp>
#include <geometry/Geom3TrimmedSurface.hpp>
#include <geometry/Geom3Surface.hpp>
#include <geometry/Geom3CylindricalSurface.hpp>
#include <geometry/Geom3SphericalSurface.hpp>
#include <geometry/Geom3SweepSurface.hpp>
#include <geometry/Geom3SweptSurface.hpp>
#include <geometry/Geom3SphericalSurface.hpp>
#include <geometry/Geom3SurfaceOfExtrusion.hpp>
#include <geometry/Geom3SurfaceOfHypersurface.hpp>
#include <geometry/Geom3SurfaceOfParametricSweepSurface.hpp>
#include <geometry/Geom3SurfaceOfSphericalSurface.hpp>
#include <geometry/Geom3SurfaceOfSweepSurface.hpp>
#include <geometry/Geom3SurfaceOfSurfaceOfExtrusion.hpp>
#include <geometry/Geom3SurfaceOfSurfaceOfSweepSurface.hpp>
using namespace AMCAX;
TEST_CASE("bug1: BoolBRepSection ", "[boolean][BoolBRepSection][fixbug]")
{
	TopoShape result;
	SECTION("case1: ")
	{
		TopoShape s1, s2;
		TopoVertex v1(0.0, 0.0, 0.0);
		TopoVertex v2(1.0, 0.0, 0.0);
		TopoVertex v3(1.0, 1.0, 0.0);
		TopoVertex v4(0.0, 1.0, 0.0);
		TopoEdge e1(v1, v2);
		TopoEdge e2(v2, v3);
		TopoEdge e3(v3, v4);
		TopoEdge e4(v4, v1);
		TopoShape s2 = MakePrism(MakeEdge(e1), MakeEdge(e2));
		TopoShape s1 = MakePrism(MakeEdge(e3), MakeEdge(e4));
		result = BoolBRepSection(s1, s2);
		CHECK(OCCTIO::OCCTTool::Write(result, OUTPUT_PATH_PREFIX"BoolBRepSection_bug345.brep"));
		AMCAX::GlobalProperty prop1, prop2;
		CHECK(GetSurfaceProperties(result, prop1, true, false) == Approx(14.0));
		CHECK(GetVolumeProperties(result, prop2, true, false) == Approx(1.0));
	}}