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
	SECTION("arc length and tolerance- 2D")
{
    Axis2 axis;
    double major = 5.0;
    double minor = 4.0;
    bool isRight = true;
    std::shared_ptr< Geom2Hyperbola >h1 = MakeGeom2Hyperbola(axis, major, minor, isRight);
    AdaptorGeom2Curve hyperbola(h1);
    ComputePointsAbscissa cpa4(hyperbola, 1.0, 0.0);
    double param4 = cpa4.Parameter();
    if (cpa4.IsDone())
    {
        std::cout << param4 << ": " << hyperbola.Value(param4) << '\n';
    }
    Point2 s4 = hyperbola.Value(param4);
    MakeEdge2d he4(h1, 0.0, 0.0);
    CHECK(BRepClassificationTools::IsPointInOnEdge(he4, s4, 0.001));
    double param = cpa4.Parameter();
    Point2 s = hyperbola.Value(param);
    Point2 s2 = he4;
    std::cout << param << ": " << s << std::endl;
    std::cout << param << ": " << s2 << std::endl;
}}