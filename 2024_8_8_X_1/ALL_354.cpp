/* "AMCAX_API BoolBRepSection()\t @details Only set the type of boolean operation to section\n\t @brief Default constructor\n,\n",
      */
 #include<catch.hpp>
#include<testHelper.h>
#include <boolean/BoolBRepSection.hpp>
#include <common/CartesianCoordinateSystem.hpp>
#include <math/LineT.hpp>
#include <modeling/MakePrism.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeFace.hpp>
#include <geometry/Geom3BezierCurve.hpp>
#include <modeling/MakeRevol.hpp>
#include <geometry/Geom3CylindricalSurface.hpp>
#include <topology/TopoTool.hpp>
using namespace AMCAX;
TEST_CASE("bug1: BoolBRepSection ", "[boolean][BoolBRepSection][fixbug]")
{
	Line3 line(CartesianCoordinateSystem::OZ());
	TopoShape infinitePlane1 = MakePrism(MakeEdge(line, 0.0, 1.0), Direction3(-1.0, 0.0, 0.0), false);
	TopoShape infinitePlane2 = MakePrism(MakeEdge(line, 0.0, 1.0), Direction3(1.0, 0.0, 0.0), false);
	TopoShape infinitePlane3 = MakePrism(MakeEdge(line, 0.0, 1.0), Direction3(0.0, 1.0, 0.0), false);
	TopoShape infinitePlane4 = MakePrism(MakeEdge(line, 0.0, 1.0), Direction3(0.0, -1.0, 0.0), false);
	std::vector<Point3> poles{ Point3(1.0, 0.0, 0.0), Point3(0.8, 0.0, 0.5), Point3(1.0, 0.0, 1.0) };
	auto bz = std::make_shared<Geom3BezierCurve>(poles);
	TopoEdge e2 = MakeEdge(bz);
	TopoShape revolshape = MakeRevol(e2, CartesianCoordinateSystem::OZ());
	auto surface1 = std::make_shared<Geom3CylindricalSurface>(Frame3(), 1.0);
	auto surface2 = TopoTool::Surface(TopoCast::Face(revolshape));
	TopoShape result1 = BoolBRepSection(infinitePlane1, surface2); 
	TopoShape result2 = BoolBRepSection(infinitePlane2, surface2); 
	TopoShape result3 = BoolBRepSection(infinitePlane3, surface2); 
	TopoShape result4 = BoolBRepSection(infinitePlane4, surface2); 
	GlobalProperty prop1, prop2, prop3, prop4 ;
	CHECK( GetLinearProperties(result1, prop1, true, false) == Approx(1.0260606301));
	CHECK( GetLinearProperties(result2, prop1, true, false) == Approx(1.0260606301));
	CHECK( GetLinearProperties(result3, prop1, true, false) == Approx(1.0260606301));
	CHECK( GetLinearProperties(result4, prop1, true, false) == Approx(1.0260606301));
}