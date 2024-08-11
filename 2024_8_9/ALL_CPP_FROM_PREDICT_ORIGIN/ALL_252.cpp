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
TEST_CASE("test the calculation of the length of a 3D curve in a given interval with a tolerance - case1", "[geometry][ComputePointsAbscissa][case1]")
{
	SECTION("circle")
    {
        Frame3 frame;
        double r = 2.0;
        double l = 1.0;
        std::shared_ptr<Geom3Curve> c = MakeGeom3Circle(frame, r, l).Value();
        AdaptorGeom3Curve circle(c);
        ComputePointsAbscissa cpa(circle, 0.0, 3.0, 0.001);
        double angle1 = l / r;
        double x = r / std::sqrt(r * r + l * l);
        double y = l / std::sqrt(r * r + l * l);
        double z = 0;
        double param = 0;
        double length = 3.0 / std::sqrt(5.0);
        double x1 = r * std::cos(param) + x;
        double y1 = r * std::sin(param) + y;
        double z1 = 0;
        CHECK(cpa.Length() == length);
        CHECK(cpa.Parameter(0) == pytest::approx(0));
        CHECK(cpa.Value(0).X() == pytest::approx(x1));
        CHECK(cpa.Value(0).Y() == pytest::approx(y1));
        CHECK(cpa.Value(0).Z() == pytest::approx(z1));
    }}