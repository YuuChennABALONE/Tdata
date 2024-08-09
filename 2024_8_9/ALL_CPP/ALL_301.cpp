/* "AMCAX_API ComputePointsAbscissa(double tol, const Adaptor2Curve& c, double abscissa, double u0)\t @param u0 The starting parameter\n\t @param abscissa The arc length\n\t @param c The curve\n\t @param tol The tolerance\n\t @brief Compute the parameter of a point on a 2D curve with given arc length and a tolerance\n,\n",
      */
 #include<catch.hpp>
#include<testHelper.h>
#include <geometry/MakeGeom2Circle.hpp>
#include <geometry/AdaptorGeom2Curve.hpp>
#include <geometry/ComputePointsAbscissa.hpp>
#include <geometry/MakeGeom2Hyperbola.hpp>
#include <modeling/MakeEdge.hpp>
#include <geometry/GeometryTool.hpp>
#include <hatch/BRepClassificationTools.hpp>
#include <geometry/MakeGeom2Ellipse.hpp>
#include <geometry/Geom2BSplineCurve.hpp>
#include <geometry/AdaptorGeom3Curve.hpp>
#include <modeling/MakeEdge2d.hpp>
#include <geometry/MakeGeom3Hyperbola.hpp>
#include <geometry/MakeGeom3Ellipse.hpp>
TEST_CASE("bug2: ComputePointsAbscissa ", "[geometry][ComputePointsAbscissa][fixbug]")
{
	SECTION("arc length and tolerance-2D")
{
    Axis2 axis;
    double major = 5.0;
    double minor = 4.0;
    bool isRight = true;
    std::shared_ptr< Geom2Hyperbola >h1 = MakeGeom2Hyperbola(axis, major, minor, isRight);
    AdaptorGeom2Curve hyperbola(h1);
    ComputePointsAbscissa cpa3(Precision::Confusion(), hyperbola, 1.0, 0.0);
    double param3 = cpa3.Parameter();
    CHECK(cpa3.Parameter());
    Point2 s4 = hyperbola.Value(param3);
    shared_ptr<Geom3Curve> curve;
    curve = GeometryTool::To3d(Frame3(), h1);
    MakeEdge edge2(curve, 0.0, param3);
    Point3 point1(s4.X(), s4.Y(), 0.0);
    CHECK(BRepClassificationTools::IsPointInOnEdge(edge2, point1, 0.001) == true);
}}