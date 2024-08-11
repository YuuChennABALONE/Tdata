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
TEST_CASE("test the calculation of the length of the 2D curve with a tolerance and the length of the 2D curve.", "[geometry][ComputePointsAbscissa][case1]")
{
	SECTION("circle")
    {
        double r = 2.0;
        double l = 2 * M_PI * r;
        std::shared_ptr<Geom2Curve> c = MakeGeom2Circle(Point2(0.0, 0.0), 2.0).Value();
        AdaptorGeom2Curve circle(c);
        ComputePointsAbscissa cpa(circle, 2 * M_PI, 0.0);
        double angle1 = 2 * M_PI / 10;
        std::vector<Point2> r1(10);
        for (int i = 0; i < 10; i++)
        {
            double angle = angle1 * i;
            double x = r * cos(angle);
            double y = r * sin(angle);
            r1[i].Set(x, y);
        }
        AdaptorGeom2Curve circle1(circle);
        for (int i = 0; i < 10; i++)
        {
            double param = i * 2 * M_PI / 10;
            Point2 s = circle1.Value(param);
            Point2 s1 = cpa.Value(i);
            std::cout << s << " " << s1 << std::endl;
            CHECK(s.X() == s1.X());
            CHECK(s.Y() == s1.Y());
        }
        CHECK(cpa.Length() == Approx(l).margin(0.1));
    }}