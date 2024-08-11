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
	SECTION("arc length 0")
{
    Frame3 frame;
    double major = 5.0;
    double minor = 4.0;
    bool isRight = true;
    std::shared_ptr< Geom3Hyperbola >h1 = MakeGeom3Hyperbola(frame, major, minor);
    AdaptorGeom3Curve hyperbola(h1);
    ComputePointsAbscissa cpa3(hyperbola, 0.0, 0.0);
    double param3 = cpa3.Parameter();
    if (cpa3.IsDone())
    {
        std::cout << param3 << ": " << hyperbola.Value(param3) << '\n';
    }
    Point3 point1(hyperbola.Value(param3));
    CHECK(cpa3.Parameter());
    MakeEdge edge1(h1, 0.0, param3);
    CHECK(BRepClassificationTools::IsPointInOnEdge(edge1, point1, 0.001) == true);
}
}