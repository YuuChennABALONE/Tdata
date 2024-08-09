/* "AMCAX_API static TopoShape SewShape(const std::list<TopoShape>& shapes, double tolerance)\t @return The sewed shape\n\t @param tolerance The tolerance\n\t @param shapes The shapes to be sewed\n\t          If some edges do not coincide, the related faces remain unsewed.\n\t @details The border edges are merged to common edges under a given tolerance.\n\t @brief Sew faces to a shell\n,\n",
      */
 #include<catch.hpp>
#include<testHelper.h>
#include <modeling/MakeShapeTool.hpp>
#include<modeling/MakeFace.hpp>
#include<math/Plane.hpp>
#include <common/CartesianCoordinateSystem.hpp>
#include <topology/TopoExplorerTool.hpp>
TEST_CASE("case1-1: MakeShapeTool::SewShape ", "[modeling][MakeShapeTool][SewShape][P1]")
{
	std::list<TopoShape> shapes;
	shapes.push_back(MakeFace(Plane(), 0.0, 1.0, 0.0, 1.0));
	shapes.push_back(MakeFace(Plane(Frame3(Point3(1.0, 0.0, 0.0), CartesianCoordinateSystem::DX(), -CartesianCoordinateSystem::DZ())), 0.0, 1.0, 0.0, 1.0));
	TopoShape result = MakeShapeTool::SewShape(shapes, Precision::Confusion());
	CHECK(OCCTIO::OCCTTool::Write(result, OUTPUT_PATH_PREFIX"SewShapetest1-0.brep"));
	IndexSet<TopoShape> sf1, sf2, sf3;
	CHECK(GetTopoToolCount(result, AMCAX::ShapeType::Shell, sf1) == 1);
	CHECK(GetTopoToolCount(result, AMCAX::ShapeType::Compound, sf2) == 0);
	CHECK(GetTopoToolCount(result, AMCAX::ShapeType::Face, sf3) == 2);
}