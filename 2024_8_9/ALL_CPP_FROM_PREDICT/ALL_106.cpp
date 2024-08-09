 #include<catch.hpp>
#include<testHelper.h>
#include <modeling/MakeSphere.hpp>
#include <hatch/BRepClassificationTools.hpp>
#include <topology/TopoFace.hpp>
#include <topology/TopoTool.hpp>
#include <modeling/MakeFace.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeVertex.hpp>
#include <io/OBJTool.hpp>
#include <topology/TopoExplorer.hpp>
#include <topology/TopoVertex.hpp>
#include <topology/TopoEdge.hpp>
#include <topology/TopoShape.hpp>
#include <geometry/Geom3Surface.hpp>
#include <geometry/Geom3TrimmedCurve.hpp>
#include <geometry/Geom3CurveOnSurface.hpp>
#include <geometry/Geom3BSplineCurve.hpp>
#include <geometry/Geom3Surface.hpp>
#include <geometry/Geom3OffsetCurve.hpp>
#include <geometry/Geom3Line.hpp>
#include <geometry/Geom3Plane.hpp>
#include <geometry/Geom3Circle.hpp>
#include <geometry/Geom3Ellipse.hpp>
#include <geometry/Geom3Hyperbola.hpp>
#include <geometry/Geom3Parabola.hpp>
#include <geometry/Geom3BezierCurve.hpp>
#include <geometry/Geom3BSplineSurface.hpp>
#include <geometry/Geom3SphericalSurface.hpp>
#include <geometry/Geom3SweptSurface.hpp>
#include <geometry/Geom3SurfaceOfExtrusion.hpp>
#include <geometry/Geom3SurfaceOfRevolution.hpp>
TEST_CASE("test the surface on sphere with radius 4 and the longitude 0 <= theta <= 2 * M_PI, latitude 0 <= phi <= M_PI, and the point 2 <= r <= 4", "[math][BRepClassificationTools][P1]")
{
	SECTION("testSurface")
	{
		AMCAX::MakeSphere sphere(4.0, 0.0, M_PI);
		AMCAX::TopoFace sphereFace = AMCAX::BuildSurface(sphere);
		AMCAX::TopoShape point = AMCAX::MakeVertex(2.0, 0.0, 0.0);
		AMCAX::TopoShape result = AMCAX::BRepClassificationTools::Project(point, sphereFace);
		CHECK(AMCAX::TopoTool::Type(AMCAX::TopoCast::Face(result)) == "Vertex");
	}}