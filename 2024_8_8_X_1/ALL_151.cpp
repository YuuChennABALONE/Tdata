/* "AMCAX_API static double Length(const Adaptor2Curve& c, double u1, double u2)\t @return The length of a curve in a given interval\n\t @param u2 The last parameter\n\t @param u1 The first parameter\n\t @param c The curve\n\t @brief Compute the length of a 2D curve in a given interval\n,\n",
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
TEST_CASE("tset the calculation of the parameters of a point on a 3D curve for a given arc length, initial guess parameters and tolerances and the length of the 3D curve within a given interval, as well as the length of the 3D curve for a given interval and tolerances", "[geometry][ComputePointsAbscissa][case8]")
{
	SECTION("line")
    {
        double t = 2.0;
        shared_ptr<Geom3Line> line;
        line = make_shared<Geom3Line>(Point3(0.0, 0.0, 0.0), Direction3(1.0, 2.0, 3.0));
        shared_ptr<Geom3TrimmedCurve> TrimmedCurve = make_shared<Geom3TrimmedCurve>(line, 0.0, 6.0);
        AdaptorGeom3Curve line1(TrimmedCurve);
        ComputePointsAbscissa cpa4(line1, 2.0, 0.0, 2.0, Precision::Confusion());
        double param4 = cpa4.Parameter();
        if (cpa4.IsDone())
        {
            std::cout << param4 << ": " << line1.Value(param4) << '\n';
        }
        Point3 start(0.0, 0.0, 0.0);
        Direction3 direction(1.0, 2.0, 3.0);
        double x = start.X() + t * direction.X();
        double y = start.Y() + t * direction.Y();
        double z = start.Z() + t * direction.Z();
        Point3 s5 = line1.Value(param4);
        Point3 s6(x, y, z);
        std::cout << s5 << std::endl;
        CHECK(cpa4.Parameter() == 2.0);
        CHECK(s5.X() == s6.X());
        CHECK(s5.Y() == s6.Y());
        CHECK(s5.Z() == s6.Z());
        std::cout << "ڶά߳Ϊ" << ComputePointsAbscissa::Length(line1, 0.0, 2.0) << '\n';
        std::cout << "ݲĶά߳Ϊ" << ComputePointsAbscissa::Length(line1, 0.0, 2.0, Precision::Confusion()) << '\n';
        CHECK(ComputePointsAbscissa::Length(line1, 0.0, 2.0) == 2.0);
        CHECK(ComputePointsAbscissa::Length(line1, 0.0, 2.0, Precision::Confusion()) == 2.0);
    }}