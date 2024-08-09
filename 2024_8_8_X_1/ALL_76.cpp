/* "AMCAX_API static bool IsPlanarCurve(const std::shared_ptr<Geom3Curve>& c, Plane& plane, double tol = 1.0e-7)\t @return True if the curve is a planar curve\n\t @param tol The tolerance\n\t @param plane The plane found when the curve is planar curve\n\t @param c The input curve\n\t @details If the input curve, such as a line, is on more than one plane, it will return the plane in which any one is located\n\t @brief Check if a 3D curve is a planar curve, and if it is planar, find the plane\n,\n",
      */
 #include<catch.hpp>
#include<testHelper.h>
#include <geometry/GeometryTool.hpp>
#include <geometry/Geom2BezierCurve.hpp>
#include <geometry/Geom2BSplineCurve.hpp>
#include <geometry/MakeArcOfCircle2d.hpp>
#include <geometry/Geom2TrimmedCurve.hpp>
#include <modeling/MakeEdge.hpp>
#include<modeling/MakeEdge2d.hpp>
#include <geometry/Geom3OffsetCurve.hpp>
#include <geometry/Geom3Circle.hpp>
using namespace AMCAX;
std::shared_ptr<Geom2BezierCurve> MakeBezierCurve2d()
{
	std::vector<Point2> poles(4);
	poles[0].SetCoord(1.0, 0.0);
	poles[1].SetCoord(2.0, 1.0);
	poles[2].SetCoord(3.0, -1.0);
	poles[3].SetCoord(4.0, 0.0);
	return std::make_shared<Geom2BezierCurve>(poles);
}
std::shared_ptr<Geom2BSplineCurve> MakeBSplineCurve2d()
{
	std::vector<Point2> poles(7);
	poles[0].SetCoord(0.5, 0.5);
	poles[1].SetCoord(1.0, 3.0);
	poles[2].SetCoord(3.0, 1.0);
	poles[3].SetCoord(3.8, 2.0);
	poles[4].SetCoord(2.5, 3.5);
	poles[5].SetCoord(1.0, 0.5);
	poles[6].SetCoord(0.3, 2.0);
	std::vector<double> knots = { 0.0, 0.25, 0.5, 0.75, 1.0 };
	std::vector<int> mults = { 4, 1, 1, 1, 4 };
	return std::make_shared<Geom2BSplineCurve>(poles, knots, mults, 3);
}
std::shared_ptr<Geom3BSplineCurve> MakeBSplineCurve3d(int degree, bool rational)
{
	if (degree == 3)
	{
		std::vector<Point3> poles(7);
		poles[0].SetCoord(0.5, 0.5, 0.3);
		poles[1].SetCoord(1.0, 3.0, 0.4);
		poles[2].SetCoord(3.0, 1.0, 0.1);
		poles[3].SetCoord(3.8, 2.0, 0.6);
		poles[4].SetCoord(2.5, 3.5, 0.8);
		poles[5].SetCoord(1.0, 0.5, 0.9);
		poles[6].SetCoord(0.3, 2.0, 0.5);
		std::vector<double> weights = { 1.0, 2.0, 3.0, 4.0, 3.0, 2.0, 1.0 };
		std::vector<double> knots = { 0.0, 0.25, 0.5, 1.0 };
		std::vector<int> mults = { 4, 1, 2, 4 };
		return rational ? std::make_shared<Geom3BSplineCurve>(poles, weights, knots, mults, 3)
			: std::make_shared<Geom3BSplineCurve>(poles, knots, mults, 3);
	}
	else if (degree == 2)
	{
		std::vector<Point3> poles(6);
		poles[0].SetCoord(0.5, 0.5, 0.3);
		poles[1].SetCoord(1.0, 3.0, 0.4);
		poles[2].SetCoord(3.0, 1.0, 0.1);
		poles[3].SetCoord(3.8, 2.0, 0.6);
		poles[4].SetCoord(2.5, 3.5, 0.8);
		poles[5].SetCoord(1.0, 0.5, 0.9);
		std::vector<double> weights = { 1.0, 2.0, 3.0, 4.0, 3.0, 2.0 };
		std::vector<double> knots = { 0.0, 0.25, 0.5, 1.0 };
		std::vector<int> mults = { 3, 1, 2, 3 };
		return rational ? std::make_shared<Geom3BSplineCurve>(poles, weights, knots, mults, 2)
			: std::make_shared<Geom3BSplineCurve>(poles, knots, mults, 2);
	}
	return nullptr;
}
TEST_CASE("case2: IsPlanarCurve dev case ", "[geometry][IsPlanarCurve][P1]")
{
	shared_ptr<Geom3BSplineCurve> curve3 = MakeBSplineCurve3d(3,true) ;
	Plane plane;
	CHECK(GeometryTool::IsPlanarCurve(curve3, plane) == false);
}