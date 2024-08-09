/* "explicit Conic2Constraint(const Point2& point)\t @param point The point constraint\n\t @brief Construct from a point constraint\n,\n",
      */
 #include<catch.hpp>
#include<testHelper.h>
#include <geomAlgo/MakeConic2FromConstraints.hpp>
#include <geometry/GeometryTool.hpp>
#include <math/HyperbolaT.hpp>
#include <geometry/Geom2Hyperbola.hpp>
#include <geometry/Geom2TrimmedCurve.hpp>
#include <geometry/Geom2Ellipse.hpp>
#include <geometry/Geom2Parabola.hpp>
#include <modeling/MakeEdge.hpp>
#include <hatch/BRepClassificationTools.hpp>
#include <geometry/Geom2Circle.hpp>
#include <geometry/GeomAPIProjectPointOnCurve3.hpp>
#include <topology/BRepExtremaDistShapeShape.hpp>
#include <modeling/MakeVertex.hpp>
#include <modeling/MakeEdge.hpp>
TEST_CASE("bug1: MakeConic2FromConstraints ", "[geomAlgo][MakeConic2FromConstraints][fixbug]")
{
	Point2 a(0.0, 0.0);
	Point2 b(1.0, 1.0);
	Vector2 da(-0.5, 0.5);
	Vector2 db(1.0, -0.2);
	Point3 a1(a.X(), a.Y(), 0.0);
	Point3 b1(b.X(), b.Y(), 0.0);
	Vector3 da1(da.X(), da.Y(), 0.0);
	Vector3 db1(db.X(), db.Y(), 0.0);
	Conic2Constraint ca(a, da);
	Conic2Constraint cb(b, db);
	MakeConic2FromConstraints mc2fc(ca, cb, 0.0);
	shared_ptr<Geom3Curve> curve;
	curve = GeometryTool::To3d(Frame3(), mc2fc.Curve2d());
	CHECK(mc2fc.Curve2d() == nullptr);
	CHECK(curve == nullptr);
}