 #include<catch.hpp>
#include<testHelper.h>
#include <modeling/MakeFace.hpp>
#include <common/CartesianCoordinateSystem.hpp>
#include <topology/TopoVertex.hpp>
#include <common/GlobalProperty.hpp>
#include <topology/TopoEdge.hpp>
#include <topology/TopoWire.hpp>
#include <modeling/MakeEdge2d.hpp>
#include <modeling/MakeEdge.hpp>
#include <topology/TopoShape.hpp>
#include <topology/TopoTool.hpp>
#include <topology/TopoExplorer.hpp>
#include <topology/TopoExplorerTool.hpp>
#include <topology/TopoExplorerShape.hpp>
#include <topology/TopoExplorerEdge.hpp>
#include <topology/TopoExplorerFace.hpp>
#include <topology/TopoExplorerShape.hpp>
#include <topology/TopoExplorerTool.hpp>
#include <topology/TopoExplorer.hpp>
#include <topology/TopoCast.hpp>
#include <topology/TopoTool.hpp>
#include <math/TriangularMesh.hpp>
#include <modeling/MakeShape.hpp>
#include <topology/TopoCompound.hpp>
#include <topology/TopoShape.hpp>
#include <topology/TopoExplorer.hpp>
TEST_CASE("bug1: MakeFace ", "[modeling][MakeFace][fixbug]")
{
	std::vector<Point3> v;
	v.push_back(Point3(0.0, 0.0, 0.0));
	v.push_back(Point3(2.0, 0.0, 0.0));
	v.push_back(Point3(2.0, 2.0, 0.0));
	v.push_back(Point3(0.0, 2.0, 0.0));
	std::vector<double> p;
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(1.0);
	p.push_back(1.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(1.0);
	p.push_back(1.0);
	p.push_back(1.0);
	p.push_back(1.0);
	p.push_back(0.0);
	p.push_back(1.0);
	p.push_back(1.0);
	p.push_back(0.0);
	p.push_back(1.0);
	p.push_back(0.0);
	p.push_back(1.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(1.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(1.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(1.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(0.0);
	p.push_back(0.0"}