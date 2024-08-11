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
#include <geometry/Geom2TCBSplineCurve.hpp>
#include <geometry/Geom3TCBSplineCurve.hpp>
#include <geometry/Geom2BSplineCurve2d.hpp>
#include <geometry/Geom3BSplineCurve.hpp>
#include <geometry/Geom2BSplineCurve.hpp>
#include <geometry/Geom2Hyperbola.hpp>
#include <geometry/Geom3Ellipse.hpp>
#include <geometry/Geom3Hyperbola.hpp>
{
	TEST_CASE("test the arc length parameter over the total length of the curve for different geometry 2D type", "[geometry][ComputePointsAbscissa][case18]")
	{
		SECTION("circle")
		{
			DOUBLE_T tol = 0.001;
			Point2 P(0.0, 0.0); 
			double r = 2.0;
			double l = 2 * M_PI * r;
			MakeGeom2Circle g2c(P, r);
			AdaptorGeom2Curve circle(g2c);
			ComputePointsAbscissa cpa2(cg2c, 0.0, l, tol);
			CHECK(cpa2.Length() == Approx(l).margin(tol));
		}}