/* "AMCAX_API double Parameter()\t @return The parameter of the point\n\t @brief Get the parameter of the point\n,\n",
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
TEST_CASE("test the calculation of parameters at a point on a two-dimensional curve with a given arc length and initial guess parameters", "[geometry][ComputePointsAbscissa][case3]")
{
	SECTION("bezier")
    {
        std::vector<Point2> pts2 = {
       Point2(0.0, 0.0),
       Point2(2.0, 2.0),
       Point2(4.0, 3.0),
        };
        std::shared_ptr<Geom2BezierCurve> bez2 = make_shared<Geom2BezierCurve>(pts2);
        AdaptorGeom2Curve b(bez2);
        ComputePointsAbscissa cpa6(b, 2.0, 0.0, 0.37);
        double param6 = cpa6.Parameter();
        if (cpa6.IsDone())
        {
            std::cout << param6 << ": " << b.Value(param6) << '\n';
        }
        double x = 1.0;
        double y = 1.0;
        Point2 s7 = b.Value(param6);
        Point2 s8(x, y);
        std::cout << s7 << std::endl;
        CHECK(cpa6.Parameter() != 0);
        shared_ptr<Geom3Curve> curve2;
        curve2 = GeometryTool::To3d(Frame3(), bez2);
        MakeEdge edge2(curve2, 0.0, param6);
        Point3 s9(s7.X(), s7.Y(), 0.0);
        CHECK(BRepClassificationTools::IsPointInOnEdge(edge2, s9, 0.001) == true);
        std::cout << "߳Ϊ" << ComputePointsAbscissa::Length(b) << '\n';
    }}