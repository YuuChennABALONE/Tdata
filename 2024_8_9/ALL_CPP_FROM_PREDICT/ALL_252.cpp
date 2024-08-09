 #include<catch.hpp>
#include<testHelper.h>
#include <modeling/MakeTorus.hpp>
#include <common/PointT.hpp>
#include <common/TransformationT.hpp>
#include <topology/TopoExplorer.hpp>
#include <topology/TopoFace.hpp>
#include <hatch/BRepClassificationTools.hpp>
#include <topology/TopoEdge.hpp>
#include <modeling/MakeEdge2d.hpp>
#include <topology/TopoShape.hpp>
#include <io/OCCTIO.hpp>
#include <math/TriangularMesh.hpp>
#include <modeling/MakeFace.hpp>
#include <topology/TopoTool.hpp>
#include <topology/TopoVertex.hpp>
#include <modeling/MakeVertex.hpp>
#include <modeling/TransformShape.hpp>
#include <topology/TopoExplorerTool.hpp>
#include <topology/TopoTool.hpp>
#include <topology/TopoCast.hpp>
using namespace AMCAX;
TEST_CASE("bug1: MakeTorus [2/20] ", "[modeling][MakeTorus][P1][bug]") {
	TopoShape torus = MakeTorus(Frame3(Point3(0.0, 0.0, 2.0), Direction3(0.0, 0.0, 1.0)), 5.0, 3.0);
	AMCAX::GlobalProperty prop;
	AMCAX::BRepGlobalProperty::VolumeProperties(torus, prop);
	CHECK(prop.Mass() == Approx(209.34285714285714).epsilon(1e-11));
	CHECK(prop.MomentsOfInertia(1) == Approx(106.23678571428571).epsilon(1e-11));
	CHECK(prop.MomentsOfInertia(2) == Approx(209.34285714285714).epsilon(1e-11));
	CHECK(prop.MomentsOfInertia(3) == Approx(106.23678571428571).epsilon(1e-11));
	CHECK(prop.RadiusOfGyration(1) == Approx(3.262726952898368).epsilon(1e-11));
	CHECK(prop.RadiusOfGyration(2) == Approx(3.262726952898368).epsilon(1e-11));
	CHECK(prop.RadiusOfGyration(3) == Approx(3.262726952898368).epsilon(1e-11));
}