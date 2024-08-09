 #include<catch.hpp>
#include<testHelper.h>
#include <modeling/MakeSphere.hpp>
#include <hatch/BRepClassificationTools.hpp>
#include <topology/TopoFace.hpp>
#include <topology/TopoTool.hpp>
#include <modeling/TransformShape.hpp>
#include <modeling/MakeCylinder.hpp>
#include <io/OBJTool.hpp>
#include <geometry/Geom3Surface.hpp>
#include <geometry/Geom3Curve.hpp>
#include <geometry/Geom3TrimmedCurve.hpp>
#include <geometry/Geom3BSplineCurve.hpp>
#include <geometry/Adaptor3CurveOnSurface.hpp>
#include <geometry/Geom3Plane.hpp>
#include <geometry/LocalProperty.hpp>
#include <geometry/GlobalProperty.hpp>
#include <healing/ShapeFixTool.hpp>
#include <topology/TopoExplorer.hpp>
#include <topology/TopoExplorerTool.hpp>
#include <topology/TopoShape.hpp>
#include <topology/TopoEdge.hpp>
using namespace AMCAX;
TEST_CASE("case1: MakeSphere 100mm radius  ", "[modeling][MakeSphere][P1]")
{
	MakeSphere sphere(100.0);
	sphere.SetCenter(Point3(10.0, 20.0, 30.0));
	std::vector<Point3> expectedVertices = {
		Point3(10.0, 20.0, 30.0),
		Point3(-9.0, 20.0, 30.0),
		Point3(10.0, 19.0, 30.0),
		Point3(10.0, 21.0, 30.0),
		Point3(10.0, 20.0, 29.0),
		Point3(10.0, 20.0, 31.0)
	};
	std::vector<TriangularMesh> expectedMeshes = {
		TriangularMesh(Point3(10.0, 20.0, 30.0), Point3(9.0, 20.0, 30.0), Point3(10.0, 19.0, 30.0)),
		TriangularMesh(Point3(10.0, 20.0, 30.0), Point3(10.0, 19.0, 30.0), Point3(10.0, 20.0, 29.0)),
		TriangularMesh(Point3(10.0, 20.0, 30.0), Point3(10.0, 20.0, 29.0), Point3(10.0, 21.0, 30.0)),
		TriangularMesh(Point3(10.0, 20.0, 30.0), Point3(10.0, 21.0, 30.0), Point3(10.0, 20.0, 31.0)),
		TriangularMesh(Point3(10.0, 20.0, 30.0), Point3(10.0, 20.0, 31.0), Point3(9.0, 20.0, 30.0)),
		TriangularMesh(Point3(10.0, 20.0, 30.0), Point3(10.0, 20.0, 31.0), Point3(10.0, 20.0, 29.0)),
		TriangularMesh(Point3(10.0, 20.0, 30.0), Point3(10.0, 20.0, 29.0), Point3(10.0, 19.0, 30.0)),
		TriangularMesh(Point3(10.0, 20.0, 30.0), Point3(10.0, 19.0, 30.0), Point3(10.0, 20.0, 31.0)),
	};
	TopoShape sphere1 = sphere.Sphere();
	CHECK(OCCTIO::OCCTTool::Write(sphere1, OUTPUT_PATH_PREFIX"MakeSphere100.rte"));
	AMCAX::GlobalProperty props;
	AMCAX::LocalProperty props1;
	CHECK(sphere1.IsNull() == false);
	CHECK(sphere.ShapeType() == AMCAX::ShapeType::Sphere);
	CHECK(sphere"}