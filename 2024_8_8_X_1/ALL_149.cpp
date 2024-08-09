/* "AMCAX_API static double Length(const Adaptor2Curve& c, double u1, double u2, double tol)\t @return The length of a curve in a given interval\n\t @param tol The tolerance\n\t @param u2 The last parameter\n\t @param u1 The first parameter\n\t @param c The curve\n\t @brief Compute the length of a 2D curve in a given interval with a tolerance\n,\n",
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
TEST_CASE("test the calculation of the parameters of a point on a 2D curve for a given arc length, initial guess parameters and tolerances and the length of the 2D curve in a given interval, as well as the length of the 2D curve for a given interval and tolerances", "[geometry][ComputePointsAbscissa][case4]")
{
	SECTION("circle")
    {
        double r = 3.0;
        double l = 2.0;
        std::shared_ptr<Geom2Curve> c = MakeGeom2Circle(Point2(0.0, 0.0), 3.0).Value();
        AdaptorGeom2Curve circle(c);
        ComputePointsAbscissa cpa(circle, 2.0, 0.0, 1.5, Precision::Confusion());
        double angle1 = l / r;
        std::cout << "ԲĽǵĻֵΪ" << ": " << angle1 << '\n';
        double x = r * cos(angle1);
        double y = r * sin(angle1);
        std::cout << "xֵΪ" << ": " << x << '\n';
        std::cout << "yֵΪ" << ": " << y << '\n';
        double param = cpa.Parameter();
        if (cpa.IsDone())
        {
            std::cout << param << ": " << circle.Value(param) << '\n';
        }
        Point2 s = circle.Value(param);
        Point2 s1(x, y);
        std::cout << s << std::endl;
        CHECK(s.X() == s1.X());
        CHECK(s.Y() == s1.Y());
        std::cout << "ڶά߳Ϊ" << ComputePointsAbscissa::Length(circle, 0.0, 0.666667) << '\n';
        std::cout << "ݲĶά߳Ϊ" << ComputePointsAbscissa::Length(circle, 0.0, 0.666667, Precision::Confusion()) << '\n';
        CHECK(angle1 == cpa.Parameter());
        CHECK(ComputePointsAbscissa::Length(circle, 0.0, 0.6666666667) == Approx(l).margin(1e-2));
        CHECK(ComputePointsAbscissa::Length(circle, 0.0, 0.6666666667, Precision::Confusion()) == Approx(l).margin(1e-2));
    }}