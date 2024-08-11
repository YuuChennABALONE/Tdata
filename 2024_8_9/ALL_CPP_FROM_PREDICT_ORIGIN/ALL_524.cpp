 #include<catch.hpp>
#include<testHelper.h>
#include <modeling/MakeRevol.hpp>
#include <common/PointT.hpp>
#include <topology/TopoVertex.hpp>
#include <topology/TopoShape.hpp>
#include <topology/TopoExplorerTool.hpp>
#include <topology/TopoExplorer.hpp>
#include <topology/TopoTool.hpp>
#include <modeling/MakeVertex.hpp>
#include <topology/TopoFace.hpp>
#include <modeling/MakeFace.hpp>
#include <geometry/Geom3BezierCurve.hpp>
#include <geometry/Geom3BSplineCurve.hpp>
#include <modeling/MakeEdge.hpp>
#include <topology/TopoEdge.hpp>
#include <topology/TopoTool.hpp>
#include <modeling/MakePrism.hpp>
#include <topology/TopoCompound.hpp>
using namespace AMCAX;
TEST_CASE("bug1: MakeRevol ", "[modeling][MakeRevol][fixbug]") {
	TopoShape s = MakeVertex(Point3(0.0, 0.0, 1.0));
	TopoShape revol = MakeRevol(s, Direction3(0.0, 0.0, 1.0), 360.0);
	TopoShape shape = MakePrism(s, MakeEdge( MakeVertex(Point3(0.0, 0.0, 1.0)), MakeVertex(Point3(0.0, 1.0, 1.0))));
	TopoShape shape2 = MakePrism(MakeEdge2d(MakeVertex2d(Point3(0.0, 0.0)), MakeVertex2d(Point3(0.0, 1.0))), s);
	OCCTIO::OCCTTool::Write(revol, OUTPUT_PATH_PREFIX"MakeRevol_bug45.brep");
	OCCTIO::OCCTTool::Write(shape, OUTPUT_PATH_PREFIX"MakeRevol_bug45_2.brep");
	CHECK(OCCTIO::OCCTTool::Read(OUTPUT_PATH_PREFIX"MakeRevol_bug45.brep", revol));
	CHECK(OCCTIO::OCCTTool::Read(OUTPUT_PATH_PREFIX"MakeRevol_bug45_2.brep", shape));
	CHECK(OCCTIO::OCCTTool::Read(OUTPUT_PATH_PREFIX"MakeRevol_bug45_3.brep", shape2));
	CHECK(revol.Type() == ShapeType::Solid);
	CHECK(shape.Type() == ShapeType::Solid);
	CHECK(shape2.Type() == ShapeType::Solid);
	CHECK( GetSurfaceProperties(revol, Standard::Quantity::Length, 0.0, 0.0) == Approx(4.71238898038469));
	CHECK( GetSurfaceProperties(revol, Standard::Quantity::Surface, 0.0, 0.0) == Approx(3.14159265358979));
	CHECK( GetVolumeProperties(revol, Standard::Quantity::Volume, 0.0, 0.0) == Approx(3.14159265358979));
	CHECK( GetSurfaceProperties(shape, Standard::Quantity::Length, 0.0, 0.0) == Approx(4.71238898038469));
	CHECK( GetSurfaceProperties(shape, Standard::Quantity::Surface, 0.0, 0.0) == Approx(3.14159265358979));
	CHECK( GetVolumeProperties(shape, Standard::Quantity::Volume, 0.0, 0.0) == Approx(3.14159265358979));
	CHECK( GetSurfaceProperties(shape2, Standard::Quantity::Length, 0.0, 0.0) == Approx(4.71238898038469));
	CHECK( GetSurfaceProperties(shape2, Standard::Quantity::Surface, 0.0, 0.0) == Approx(3.14159265358979));
	CHECK( GetVolumeProperties(shape2, Standard::Quantity::Volume, 0.0, 0.0) == Approx(3.14159265358979));
	CHECK(revol.IsNull() == false);
	CHECK(shape.IsNull() == false);
	CHECK(shape2.IsNull() == false);
	CHECK( TopoExplorerTool::MapShapeCount(revol, TopoShapeType::Solid) == 1);
	CHECK( TopoExplorerTool::MapShapeCount(revol, TopoShapeType::Compound) == 1);
	CHECK( TopoExplorerTool::MapShapeCount(revol, TopoShapeType::Face)"}