/* "AMCAX_API Geom3BSplineCurve(const std::vector<Point3>& pts, const std::vector<double>& weights, const std::vector<double>& knots, const std::vector<int>& multiplicities, int degree, bool isPeriodic = false, bool checkRational = true)\t @param checkRational To check whether the weights are rational\n\t @param isPeriodic Set the curve is periodic or not\n\t @param degree The degree of curve\n\t @param multiplicities The multiplicities\n\t @param knots The knots\n\t @param weights The weights\n\t @param pts The points\n\t @brief Construct a rational B spline curve from point, weights, knots and multiplicities with a given degree\n,\n",
      */
 #include<catch.hpp>
#include<testHelper.h>
#include <geometry/Geom3BSplineCurve.hpp>
#include <geometry/Geom3BSplineSurface.hpp>
#include <topology/TopoFace.hpp>
#include <topology/TopoTool.hpp>
using namespace AMCAX;
TEST_CASE("bug1: Geom3BSplineCurve ", "[geometry][Geom3BSplineCurve][fixbug]") {
	std::stringstream output1,output2;
	std::vector<Point3> poles{ Point3(0.0, 0.0, 0.0), Point3(0.0, 1.0, 0.0), Point3(0.0, 2.0, 0.0), Point3(0.0, 3.0, 0.0), Point3(0.0, 4.0, 0.0) };
	std::vector<double> knots{ 0.0, 1.0, 2.0, 3.0 };
	std::vector<int> mults{ 2, 2, 2, 2 };
	auto bc = std::make_shared<Geom3BSplineCurve>(poles, knots, mults, 2);
	double last = bc->LastParameter();
	std::cout << bc->Value(last) << '\n';
	std::cout << bc->DN(last, 0) << '\n';
	output1 << bc->Value(last) << '\n';
	output2 << bc->DN(last, 0) << '\n';
	auto case1 = output1.str();
	auto case2 = output2.str();
	auto expectValue = "0 3 0";
	auto expectDN = "0 3 0";
	CHECK(case1.find(expectValue) != std::string::npos);
	CHECK(case2.find(expectDN) != std::string::npos);
}