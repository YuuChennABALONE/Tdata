 #include<catch.hpp>
#include<testHelper.h>
#include <modeling/MakeShape.hpp>
#include <modeling/TransformShape.hpp>
#include <topomesh/BRepMeshIncrementalMesh.hpp>
#include <modeling/MakeShape.hpp>
#include <common/CartesianCoordinateSystem.hpp>
#include <math/Sphere.hpp>
#include <topology/TopoFace.hpp>
#include <modeling/MakeFace.hpp>
#include <common/PointT.hpp>
#include <common/TransformationT.hpp>
#include <common/AxisT.hpp>
#include <common/PointT.hpp>
#include <common/VectorT.hpp>
#include <common/FrameT.hpp>
#include <geometry/GlobalProperty.hpp>
#include <topology/TopoExplorer.hpp>
#include <topology/TopoExplorerTool.hpp>
#include <topology/TopoTool.hpp>
#include <topology/TopoCast.hpp>
#include <geometry/Geom3BSplineCurve.hpp>
#include <geometry/Geom3BSplineSurface.hpp>
#include <geometry/Geom3CylindricalSurface.hpp>
#include <geometry/Geom3HyperbolicSurface.hpp>
#include <geometry/Geom3SphericalSurface.hpp>
#include <geometry/Geom3TrimmedCurve.hpp>
#include <geometry/Geom3BezierCurve.hpp>
#include <geometry/Geom3Line2.hpp>
#include <geometry/Geom3Ellipse2.hpp>
#include <geometry/Geom3Parabola2.hpp>
#include <geometry/Geom3Hyperbola2.hpp>
#include <geometry/Geom3Plane.hpp>
#include <geometry/Geom3CylindricalSurface.hpp>
#include <geometry/Geom3ConicalSurface.hpp>
#include <geometry/Geom3SphericalSurface.hpp>
TEST_CASE("bug1: TransformShape ", "[modeling][TransformShape][fixbug]")
{
	TopoShape s = MakeShape(Sphere(), Translation(0.0, 0.0, 1.0));
	TopoShape s1 = TransformShape(s, Translation(0.0, 0.0, 1.0));
	CHECK(s.Type() == ShapeType::Solid);
	CHECK(s1.Type() == ShapeType::Solid);
	TopoSolid solid = TopoCast::Solid(s);
	TopoSolid solid1 = TopoCast::Solid(s1);
	GlobalProperty props1;
	GlobalProperty props2;
	TopoFace f1 = solid->SolidBoundary()[0];
	TopoFace f2 = solid1->SolidBoundary()[0];
	CHECK(GetSurfaceProperties(f1, props1, true, false) == GetSurfaceProperties(f2, props2, true, false));
	IndexSet<TopoShape> s2;
	s2.insert(s);
	s2.insert(s1);
	for (TopoShape shape : s2)
	{
		TopoShape s2 = TransformShape(shape, Rotation(CartesianCoordinateSystem::DefaultDirection(), CartesianCoordinateSystem::DefaultZ(), M_PI));
		CHECK(s2.Type() == shape.Type());
		int n1 = shape.NVertices();
		int n2 = s2.NVertices();
		for (int i = 0; i < n1; i++)
		{
			Point3 p1 = shape.Vertex(i).Coordinate();
			Point3 p2 = s2.Vertex(i).Coordinate();
			CHECK(p1.X() == Approx(p2.X()).margin(1e-2));
			CHECK(p1.Y() == Approx(p2.Y()).margin(1e-2));
			CHECK(p1.Z() == Approx(p2.Z()).margin(1e-2));
		}
	}
}