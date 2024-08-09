/* "AMCAX_API ComputePointsAbscissa(const Adaptor3Curve& c, double abscissa, double u0, double ui, double tol)\t @param tol The tolerance\n\t @param ui The initial guess of the parameter\n\t @param u0 The starting parameter\n\t @param abscissa The arc length\n\t @param c The curve\n\t @brief Compute the parameter of a point on a 3D curve with given arc length, an initial guess, and a tolerance\n,\n",
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
TEST_CASE("tset the parameters for calculating a point on a 3D curve of a given arc length and the length of the 3D curve.", "[geometry][ComputePointsAbscissa][case5]")
{
	SECTION("offset curve")
    {
        Frame3 frame;
        double r = 2.0;
        std::shared_ptr<Geom3Curve> c = MakeGeom3Circle(frame, r).Value();
        shared_ptr<Geom3OffsetCurve> curve;
        double offset = -1.0;
        Direction3 direction(0.0, 0.0, 1.0);
        curve = make_shared<Geom3OffsetCurve>(c, offset, direction);
        double r2 = r + offset;
        double p = 2 * M_PI * r2;
        double l = 2.0;
        AdaptorGeom3Curve offs(curve);
        ComputePointsAbscissa cpa8(offs, 2.0, 0.0);
        double angle1 = l / r2;
        std::cout << "??????" << ": " << angle1 << '\n';
        double x = r2 * cos(angle1);
        double y = r2 * sin(angle1);
        double z = 0.0;
        std::cout << "x??" << ": " << x << '\n';
        std::cout << "y??" << ": " << y << '\n';
        double param8 = cpa8.Parameter();
        if (cpa8.IsDone())
        {
            std::cout << param8 << ": " << offs.Value(param8) << '\n';
        }
        Point3 s = offs.Value(param8);
        Point3 s1(x, y, z);
        std::cout << s << std::endl;
        CHECK(s.X() == Approx(s1.X()).margin(1e-2));
        CHECK(s.Y() == Approx(s1.Y()).margin(1e-2));
        CHECK(s.Z() == Approx(s1.Z()).margin(1e-2));
        std::cout << "??" << ComputePointsAbscissa::Length(offs) << '\n';
        CHECK(ComputePointsAbscissa::Length(offs) == Approx(p).margin(1e-2));
    }
}