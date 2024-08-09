/* "AMCAX_API MakeRevol(const TopoShape& s, const Axis3& a, double d, bool copy = false)\t @param copy Whether copy the base shape\n\t @param d The rotation angle\n\t @param a The rotation axis\n\t @param s The base shape\n\t @brief Construct from a base shape, a rotation axis and a rotation angle\n,\n",
      */
 #include <catch.hpp>
#include<testHelper.h>
#include <modeling/MakeRevol.hpp>
#include <common/PointT.hpp>
#include <topology/TopoVertex.hpp>
#include <common/CartesianCoordinateSystem.hpp>
#include <occtio/OCCTTool.hpp>
#include <topology/TopoBuilder.hpp>
#include <modeling/MakeVertex.hpp>
#include <common/IndexSet.hpp>
#include <topology/TopoExplorerTool.hpp>
#include <topology/TopoTool.hpp>
#include <topology/TopoCast.hpp>
using namespace AMCAX;
TEST_CASE("BUG1:create MakeRevol bug   ", "[modeling][MakeRevol][fixbug][P1]") {
	Point3 p(1.0, 0.0, 0.0);
	TopoVertex v0 = MakeVertex(p);
	TopoShape e = MakeRevol(v0, CartesianCoordinateSystem::OZ(), M_PI_2);
	TopoShape f = MakeRevol(e, CartesianCoordinateSystem::OX(), M_PI_2);
	IndexSet<TopoShape> vertices;
	TopoExplorerTool::MapShapes(f, ShapeType::Vertex, vertices);
	std::cout << TopoTool::Tolerance(TopoCast::Vertex(vertices[0])) << std::endl;
	CHECK(TopoTool::Tolerance(TopoCast::Vertex(vertices[0])) == 1e-07);
}