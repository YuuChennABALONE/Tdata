 #include<catch.hpp>
#include<testHelper.h>
#include <geometry/MakeConic2FromConstraints.hpp>
#include <geometry/Conic2Constraint.hpp>
#include <math/LineT.hpp>
#include <geometry/MakeEdge2.hpp>
#include <modeling/MakeEdge2.hpp>
#include <geometry/GeometryTool.hpp>
#include <geometry/Geom2Hyperbola.hpp>
#include <geometry/Geometry2Circle.hpp>
#include <geometry/Geometry2Ellipse.hpp>
#include <geometry/Geometry2Parabola.hpp>
#include <hatch/BRepClassificationTools.hpp>
#include <geometry/GeometryTool.hpp>
#include <geometry/Geom2Ellipse.hpp>
#include <geometry/Geom2Hyperbola.hpp>
#include <geometry/Geom2Parabola.hpp>
#include <geometry/GeomAPIProjectPointOnCurve3.hpp>
#include <geometry/Geom3Hyperbola.hpp>
#include <geometry/Geom3Ellipse.hpp>
#include <geometry/Geom3Parabola.hpp>
#include <geometry/MakeEdge2.hpp>
#include <geometry/MakeEdge3.hpp>
#include <geometry/GeomAPIProjectPointOnCurve3.hpp>
#include <geometry/TransformTools.hpp>
#include <modeling/MakeEdge2.hpp>
#include <modeling/MakeEdge3.hpp>
#include <modeling/MakeFace.hpp>
#include <geometry/GeomAPIProjectPointOnCurve3.hpp>
#include <geometry/TransformTools.hpp>
#include <geometry/GeometryTool.hpp>
#include <topology/BRepExtremaDistShapeShape.hpp>
#include <modeling/MakeEdge2.hpp>
#include <modeling/MakeEdge3.hpp>
#include <modeling/MakeFace.hpp>
#include <geometry/GeomAPIProjectPointOnCurve3.hpp>
#include <geometry/TransformTools.hpp>
#include <geometry/GeometryTool.hpp>
#include <topology/BRepExtremaDistShapeShape.hpp>
using namespace AMCAX;
TEST_CASE("bug1: MakeConic2FromConstraints ", "[geometry][MakeConic2FromConstraints][fixbug]")
{
	Point2 a(0.0, 0.0);
	Point2 b(1.0, 1.0);
	Vector2 da(-1.0, 0.0);
	Vector2 db(0.0, 1.0);
	Line2 daLine(a, da);
	Line2 dbLine(b, db);
	MakeConic2FromConstraints mc2fc1(a, da, b, db);
	shared_ptr<Geom3Curve> curve = std::make_shared<Geom2Hyperbola>(mc2fc1);
	CHECK(curve->Location().X() == Approx(0.0));
	CHECK(curve->Location().Y() == Approx(0.0));
	CHECK(curve->Location().Z() == Approx(0.0));
	CHECK(mc2fc1.ConicType() == AMCAX::HYPERBOLA);
	CHECK(curve->Type() == AMCAX::HYPERBOLA);
	double major = curve->MajorRadius();
	double minor = curve->MinorRadius();
	CHECK(major == 1.0);
	CHECK(minor == 1.0);
}