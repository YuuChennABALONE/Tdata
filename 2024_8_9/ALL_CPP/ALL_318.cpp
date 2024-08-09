/* "AMCAX_API ComputePointsAbscissa(const Adaptor3Curve& c, double abscissa, double u0, double ui)\t @param ui The initial guess of the parameter\n\t @param u0 The starting parameter\n\t @param abscissa The arc length\n\t @param c The curve\n\t @brief Compute the parameter of a point on a 3D curve with given arc length and an initial guess\n,\n",
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
TEST_CASE("test the arc length parameter over the total length of the curve - given arc length - 2D", "[geometry][ComputePointsAbscissa][case18]")
{
	SECTION("line")
    {
        shared_ptr<Geom2Line> line;
        line = make_shared<Geom2Line>(Point2(0.0, 0.0), Direction2(1.0, 0.0));
        shared_ptr<Geom2TrimmedCurve> TrimmedCurve = make_shared<Geom2TrimmedCurve>(line, 0.0, 6.0);
        AdaptorGeom2Curve line1(TrimmedCurve);
        ComputePointsAbscissa cpa4(line1, 8.0, 0.0);
        double param4 = cpa4.Parameter();
        double x = 8.0;
        double y = 0.0;
        Point2 s5 = line1.Value(param4);
        Point2 s6(x, y);
        CHECK(cpa4.Parameter() == 8.0);
        CHECK(s5.X() == s6.X());
        CHECK(s5.Y() == s6.Y());
    }}