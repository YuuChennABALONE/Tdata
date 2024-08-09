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
TEST_CASE("bug1: ComputePointsAbscissa ", "[geometry][ComputePointsAbscissa][fixbug]")
{
    double r = 0.0;
    std::shared_ptr<Geom2Curve> c = MakeGeom2Circle(Point2(0.0, 0.0), 0.0).Value();
    AdaptorGeom2Curve circle(c);
    ComputePointsAbscissa cpa(circle, 0.0, 0.0);
    double angle1 = 0;
    double x = r * cos(angle1);
    double y = r * sin(angle1);
    double param = cpa.Parameter();
    Point2 s = circle.Value(param);
    Point2 s1(x, y);
    CHECK(angle1 == cpa.Parameter());
    CHECK(s.X() == s1.X());
    CHECK(s.Y() == s1.Y());
    CHECK(ComputePointsAbscissa::Length(circle) == 0.0);
}