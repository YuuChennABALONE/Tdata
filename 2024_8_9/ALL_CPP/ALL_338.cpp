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
TEST_CASE("test the parameters for calculating a point on a 3D curve with a given arc length and tolerance, and the length of the 3D curve with tolerance.", "[geometry][ComputePointsAbscissa][case6]")
{
	SECTION("bezier")
    {
        std::vector<Point3> pts3 = {
       Point3(0.0, 0.0,0.0),
       Point3(2.0, 2.0,2.0),
       Point3(4.0, 3.0,5.0),
       Point3(6.0,2.0,4.0)
        };
        std::shared_ptr<Geom3BezierCurve> bez3 = make_shared<Geom3BezierCurve>(pts3);
        AdaptorGeom3Curve b2(bez3);
        ComputePointsAbscissa cpa6(Precision::Confusion(), b2, 2.0, 0.0);
        double param6 = cpa6.Parameter();
        if (cpa6.IsDone())
        {
            std::cout << param6 << ": " << b2.Value(param6) << '\n';
        }
        Point3 s7 = b2.Value(param6);
        std::cout << s7 << std::endl;
        CHECK(cpa6.Parameter() != 0);
        MakeEdge edge2(bez3);
        CHECK(BRepClassificationTools::IsPointInOnEdge(edge2, s7, 0.001) == true);
        std::cout << "??" << ComputePointsAbscissa::Length(b2, Precision::Confusion()) << '\n';
        GlobalProperty props1;
        TopoShape result1 = MakeEdge(bez3);
        CHECK(GetLinearProperties(result1, props1, true, true) == Approx(ComputePointsAbscissa::Length(b2, Precision::Confusion())).margin(0.1));
    }}