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
TEST_CASE("case1: CurveCalculation::LineValue() [1/10] ", "[math][CurveCalculation][P1][LineValue]") {
	AMCAX::Axis2 axis2;
	double length = 5;
	AMCAX::Point2 start(0.0, 0.0);
	AMCAX::Point2 end(5.0, 0.0);
	double lineSlope = (end.Y() - start.Y()) / (end.X() - start.X());
	double lineMidX = (start.X() + end.X()) / 2;
	double lineMidY = (start.Y() + end.Y()) / 2;
	double lineAngle = atan(lineSlope);
	std::cout << "lineAngle:" << lineAngle << '\n';
	AMCAX::Point2 lineDirectionCos = std::make_pair(cos(lineAngle), sin(lineAngle));
	std::cout << "lineDirectionCos:" << lineDirectionCos << '\n';
	std::cout << "lineDirectionSin:" << lineDirectionSin << '\n';
	std::cout << "lineDirectionTan:" << lineDirectionTan << '\n';
	std::cout << "lineDirectionCot:" << lineDirectionCot << '\n';
	std::cout << "lineDirectionDot:" << lineDirectionDot << '\n';
	AMCAX::Axis2 axis2Direction(lineMidX, lineMidY, lineDirectionCos);
	std::cout << "axis2Direction:" << axis2Direction << '\n';
	AMCAX::Line2 line(axis2);
	double lineParam1 = 0.0;
	double lineParam2 = length;
	Point2 lineStart = AMCAX::CurveCalculation::LineValue(lineParam1, line);
	Point2 lineEnd = AMCAX::CurveCalculation::LineValue(lineParam2, line);
	std::cout << "lineStart:" << lineStart << '\n';
	std::cout << "lineEnd:" << lineEnd << '\n';
	std::vector<Point2> points;
	for (double t = 0.0; t <= length; t += 0.1) {
		points.push_back(CurveCalculation::LineValue(t, line));
	}
	AMCAX::MakeEdge2d makeEdge2d(axis2, 0.0, length);
	AMCAX::Edge2 edge2 = AMCAX::MakeEdge2d(axis2Direction, 0.0, length);
	std::cout << "edge2:" << std::endl;
	std::cout << AMCAX::OCCTIO::OCCTTool::ToOCCVertex(edge2);
	std::cout << "line:" << std::endl;
	std::cout << AMCAX::OCCTIO::OCCTTool::ToOCCVertex(line);
	AMCAX::Point2 pointStart = AMCAX::CurveCalculation::LineValue(0.0, line);
	AMCAX::Point2 pointEnd = AMCAX::CurveCalculation::LineValue(length, line);
	std::cout << "pointStart:" << pointStart << '\n';
	std::cout << "pointEnd:" << pointEnd << '\n';
	AMCAX::Point2 pointOnLine(2.0, 0.0);
	std::cout << "pointOnLine:" << pointOnLine << '\n';
	std::cout << "lineValue2:" << CurveCalculation::LineValue(2.0, line) << '\n';
	AMCAX::Point2 lineValue2 = AMCAX::CurveCalculation::LineValue(2.0, line);
	std::cout << "lineValue2:" << lineValue2 << '\n';
	CHECK(lineStart.X() == Approx(0.0).margin(1e-12));
	CHECK(lineStart.Y() == Approx(0.0).margin(1e-12));
	CHECK(lineEnd.X() == Approx(5.0).margin(1e-12));
	CHECK(lineEnd.Y() == Approx(0.0).margin(1e-12));
	CHECK(pointStart.X() == Approx(0.0).margin(1e-12));
	CHECK(pointStart.Y() == Approx(0.0).margin(1e-12));
	CHECK(pointEnd.X() == Approx(5.0).margin(1e-12));
	CHECK(pointEnd.Y() == Approx(0.0).margin(1e-12));
	CHECK(pointOnLine.X() == Approx(2.0).margin(1e-12));
	CHECK(pointOnLine.Y() == Approx(0.0).margin(1"}