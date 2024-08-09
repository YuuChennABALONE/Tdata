/* "AMCAX_API ComputePointsAbscissa(const Adaptor3Curve& c, double abscissa, double u0)\t @param u0 The starting parameter\n\t @param abscissa The arc length\n\t @param c The curve\n\t @brief Compute the parameter of a point on a 3D curve with given arc length\n,\n",
      */
 #include<catch.hpp>
#include<testHelper.h>
#include <geometry/MakeGeom2Circle.hpp>
#include <geometry/AdaptorGeom2Curve.hpp>
#include <geometry/ComputePointsAbscissa.hpp>
#include <geometry/MakeGeom3Circle.hpp>
#include <geometry/AdaptorGeom3Curve.hpp>
#include <geometry/MakeGeom2Hyperbola.hpp>
#include <geometry/Geom2Ellipse.hpp>
#include <geometry/MakeGeom2Ellipse.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeEdge2d.hpp>
#include <geometry/MakeGeom3Ellipse.hpp>
#include <geometry/MakeGeom3Hyperbola.hpp>
#include <geometry/Geom2Line.hpp>
#include <geometry/Geom2TrimmedCurve.hpp>
#include <geometry/Geom3Line.hpp>
#include <geometry/Geom3TrimmedCurve.hpp>
#include<modeling/MakeEdge.hpp>
#include <hatch/BRepClassificationTools.hpp>
#include <geometry/GeometryTool.hpp>
#include <geometry/Geom2Parabola.hpp>
#include <geometry/MakeGeom2Parabola.hpp>
#include <geometry/MakeGeom3Parabola.hpp>
#include <geometry/Geom2BezierCurve.hpp>
#include <geometry/Geom3BezierCurve.hpp>
#include <geometry/Geom2BSplineCurve.hpp>
#include <geometry/Geom2OffsetCurve.hpp>
#include <geometry/Geom3OffsetCurve.hpp>
TEST_CASE("test the arc length is negative - given arc length - 2D", "[geometry][ComputePointsAbscissa][case9]")
{
	SECTION("circle")
    {
        double r = 2.0;
        double l = -1.0;
        std::shared_ptr<Geom2Curve> c = MakeGeom2Circle(Point2(0.0, 0.0), 2.0).Value();
        AdaptorGeom2Curve circle(c);
        ComputePointsAbscissa cpa(circle, -1.0, 0.0);
        double angle1 = l / r;
        double x = r * cos(angle1);
        double y = r * sin(angle1);
        double param = cpa.Parameter();
        Point2 s = circle.Value(param);
        Point2 s1(x, y);
        CHECK(angle1 == cpa.Parameter());
        CHECK(s.X() == s1.X());
        CHECK(s.Y() == s1.Y());
    }}