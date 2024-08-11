 #include<catch.hpp>
#include<testHelper.h>
#include <boolean/BoolBRepSection.hpp>
#include <common/CartesianCoordinateSystem.hpp>
#include <math/LineT.hpp>
#include <modeling/MakePrism.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeFace.hpp>
#include <geometry/Geom3BezierCurve.hpp>
#include <geometry/Geom3BSplineCurve.hpp>
#include <geometry/Geom3Circle.hpp>
#include <geometry/Geom3Line.hpp>
#include <geometry/Geom3OffsetCurve.hpp>
#include <geometry/Geom3TrimmedCurve.hpp>
#include <geometry/Geom3Ellipse.hpp>
#include <geometry/Geom3Hyperbola.hpp>
#include <geometry/Geom3Parabola.hpp>
using namespace AMCAX;
TEST_CASE("bug1: BoolBRepSection ", "[boolean][BoolBRepSection][fixbug]")
{
	TopoShape edge1 = MakeEdge(Ellipse3(AMCAX::Frame3(), 5.0, 3.0));
	TopoShape edge2 = MakeEdge(Ellipse3(Frame3(Point3(2.0, 0.0, 0.0), Direction3(1.0, 0.0), ZDirection3(0.0, 1.0)), 3.0, 2.0));
	TopoShape edge3 = MakeEdge(Line3(Frame3(Point3(0.0, 0.0, 0.0), Direction3(0.0, 0.0, 1.0))));
	TopoShape edge4 = MakeEdge(Line3(Frame3(Point3(0.0, 0.0, 0.0), Direction3(0.0, 1.0, 0.0))));
	TopoShape edge5 = MakeEdge(Line3(Frame3(Point3(0.0, 0.0, 0.0), Direction3(1.0, 0.0, 0.0))));
	TopoShape edge6 = MakeEdge(Line3(Frame3(Point3(0.0, 0.0, 0.0), Direction3(1.0, 1.0, 0.0))));
	TopoShape edge7 = MakeEdge(Line3(Frame3(Point3(0.0, 0.0, 0.0), Direction3(1.0, 1.0, 1.0))));
	TopoShape edge8 = MakeEdge(Line3(Frame3(Point3(0.0, 0.0, 0.0), Direction3(1.0, 0.0, 1.0))));
	TopoShape edge9 = MakeEdge(Line3(Frame3(Point3(0.0, 0.0, 0.0), Direction3(1.0, -1.0, 0.0))));
	TopoShape edge10 = MakeEdge(Line3(Frame3(Point3(0.0, 0.0, 0.0), Direction3(1.0, -1.0, 1.0))));
	TopoShape edge11 = MakeEdge(Line3(Frame3(Point3(0.0, 0.0, 0.0), Direction3(1.0, -1.0, -1.0))));
	TopoShape edge12 = MakeEdge(Line3(Frame3(Point3(0.0, 0.0, 0.0), Direction3(1.0, 1.0, -1.0))));
	TopoShape edge13 = MakeEdge(Line3(Frame3(Point3(0.0, 0.0, 0.0), Direction3(1.0, -1.0, -1.0))));
	TopoShape edge14 = MakeEdge(Line3(Frame3(Point3(0.0, 0.0, 0.0), Direction3(-1.0, 1.0, 0.0))));
	TopoShape edge15 = MakeEdge(Line3(Frame3(Point3(0.0, 0.0, 0.0), Direction3(-1.0, 1.0, 1.0))));
	TopoShape edge16 = MakeEdge(Line3(Frame3(Point3(0.0, 0.0, 0.0), Direction3(-1.0, 1.0, -1.0))));
	TopoShape edge17 = MakeEdge(Line3(Frame3(Point3(0.0, 0.0, 0.0), Direction3(-1.0, -1.0, 0.0))));
	TopoShape edge18 = MakeEdge(Line3(Frame3(Point3(0.0, 0.0, "}