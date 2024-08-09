 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
#include <occtio/OCCTTool.hpp>
#include <geometry/MakeArcOfHyperbola2d.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeVertex.hpp>
#include <modeling/MakeEdge2d.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::CalculateUvParameterOnCurve2D 1/4 ", "[math][CurveCalculation][P1][CalculateUvParameterOnCurve2D]") {
	OUTPUT_DIRECTORY(P1, CalculateUvParameterOnCurve2D);
	AMCAX::Point2 P(0.0, 0.0);
	AMCAX::Direction2 D(1.0, 0.0);
	AMCAX::Axis2  axis2(P, D);
	double radius = 5.0;
	AMCAX::Circle2 circle2(axis2, radius, true);
	std::shared_ptr<AMCAX::Curve2> curve2 = circle2;
	AMCAX::Point2  point2(2.0, 0.0);
	std::vector<std::pair<AMCAX::Point2, double>> result;
	double u = 0.0;
	double v = 0.0;
	bool isOnCurve2D = CurveCalculation::CalculateUvParameterOnCurve2D(curve2, point2, 0.0, 2 * M_PI, u, v, result);
	CHECK(isOnCurve2D == true);
	CHECK(u == 0.0);
	CHECK(v == 0.0);
	SECTION("CalculateUvParameterOnCurve2D 1/4 ") {
		std::vector<std::pair<AMCAX::Point2, double>> result;
		double u = 0.0;
		double v = 0.0;
		bool isOnCurve2D = CurveCalculation::CalculateUvParameterOnCurve2D(curve2, point2, 0.0, 2 * M_PI, u, v, result);
		CHECK(isOnCurve2D == true);
		CHECK(u == 0.0);
		CHECK(v == 0.0);
		AMCAX::Point2  point2_2(u, v);
		CHECK(result.size() == 1);
		CHECK(result[0].first.X() == Approx(u));
		CHECK(result[0].first.Y() == Approx(v));
		CHECK(result[0].second == Approx(0.0));
		CHECK(OCCTIO::OCCTTool::Write(MakeEdge2d(circle2), OUTPUT_PATH_PREFIX"CurveCalculation_CalculateUvParameterOnCurve2D_result2.brep"));
	}}