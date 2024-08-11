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
TEST_CASE("test the arc length is negative - given arc length - 3D", "[geometry][ComputePointsAbscissa][case26]")
{
	SECTION("circle")
    {
        Frame3 frame;
        double r = 2.0;
        double l = -1.0;
        std::shared_ptr<Geom3Curve> c = MakeGeom3Circle(frame, r).Value();
        AdaptorGeom3Curve circle(c);
        ComputePointsAbscissa cpa(circle, -1.0, 0.0);
        double angle1 = l / r;
        double x = r * cos(angle1);
        double y = r * sin(angle1);
        double z = 0;
        double param = cpa.Parameter();
        Point3 s = circle.Value(param);
        Point3 s1(x, y, z);
        CHECK(angle1 == cpa.Parameter());
        CHECK(s.X() == s1.X());
        CHECK(s.Y() == s1.Y());
        CHECK(s.Z() == s1.Z());
    }}