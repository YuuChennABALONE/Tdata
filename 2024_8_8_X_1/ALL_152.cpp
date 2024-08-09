/* "AMCAX_API static double Length(const Adaptor3Curve& c, double u1, double u2)\t @return The length of a curve in a given interval\n\t @param u2 The last parameter\n\t @param u1 The first parameter\n\t @param c The curve\n\t @brief Compute the length of a 3D curve in a given interval\n,\n",
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
	SECTION("ellipse")
    {
        Frame3 frame;
        double major = 5.0;
        double minor = 4.0;
        bool isRight = true;
        std::shared_ptr< Geom3Ellipse >g2e = MakeGeom3Ellipse(frame, major, minor);
        AdaptorGeom3Curve ellipse(g2e);
        double t = minor / major;
        std::cout << "t" << t << '\n';
        double T = 3.15129643210828;
        double L = T * (minor + major);
        std::cout << "L" << L << '\n';
        ComputePointsAbscissa cpa2(ellipse, L, 0.0, 0.5, Precision::Confusion());
        double param2 = cpa2.Parameter();
        if (cpa2.IsDone())
        {
            std::cout << param2 << ": " << ellipse.Value(param2) << '\n';
        }
        Point3 s2 = ellipse.Value(param2);
        Point3 s3(5.0, 0.0, 0.0);
        std::cout << s2 << std::endl;
        CHECK(s2.X() == Approx(s3.X()).margin(1e-2));
        CHECK(s2.Y() == Approx(s3.Y()).margin(1e-2));
        CHECK(s2.Z() == Approx(s3.Z()).margin(1e-2));
        std::cout << "ڶά߳Ϊ" << ComputePointsAbscissa::Length(ellipse, 0.0, 6.28319) << '\n';
        std::cout << "ݲĶά߳Ϊ" << ComputePointsAbscissa::Length(ellipse, 0.0, 6.28319, Precision::Confusion()) << '\n';
        CHECK(cpa2.Parameter() == Approx(2 * M_PI).margin(1e-2));
        CHECK(ComputePointsAbscissa::Length(ellipse, 0.0, 6.28319) == Approx(L).margin(1e-2));
        CHECK(ComputePointsAbscissa::Length(ellipse, 0.0, 6.28319, Precision::Confusion()) == Approx(L).margin(1e-2));
    }}