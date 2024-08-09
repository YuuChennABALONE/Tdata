/* "AMCAX_API ComputePointsAbscissa(const Adaptor3Curve& c, double abscissa, double u0, double ui, double tol)\t @param tol The tolerance\n\t @param ui The initial guess of the parameter\n\t @param u0 The starting parameter\n\t @param abscissa The arc length\n\t @param c The curve\n\t @brief Compute the parameter of a point on a 3D curve with given arc length, an initial guess, and a tolerance\n,\n",
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
	SECTION("arc length-3D")
{
    Frame3 frame;
    double major = 5.0;
    double minor = 4.0;
    bool isRight = true;
    std::shared_ptr< Geom3Hyperbola >h1 = MakeGeom3Hyperbola(frame, major, minor);
    AdaptorGeom3Curve hyperbola(h1);
    ComputePointsAbscissa cpa3(hyperbola, 1.0, 0.0);
    double param3 = cpa3.Parameter();
    Point3 point1 = hyperbola.Value(param3);
    CHECK(cpa3.Parameter());
    MakeEdge edge1(h1, 0.0, param3);
    CHECK(BRepClassificationTools::IsPointInOnEdge(edge1, point1, 0.001) == true);
}}