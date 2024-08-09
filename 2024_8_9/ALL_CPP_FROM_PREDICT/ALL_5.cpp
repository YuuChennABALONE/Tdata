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
TEST_CASE("case1: CurveCalculation::Circle3 TorusUIso 1/2 ", "[math][CurveCalculation][P1][TorusUIso]") {
	Direction3 initialDir(0.0, 0.0, 1.0);
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir);
	double majorRadius = 3.0;
	double minorRadius = 2.0;
	AMCAX::Circle3 circle3(defaultFrame3, majorRadius, minorRadius);
	SECTION("u isoparametric curve Test") {
		double u = 0.0;
		double v = M_PI / 4;
		std::vector<Point3> pointOnCurve;
		pointOnCurve.push_back(circle3.Location());
		for (int i = 1; i <= 10; i++) {
			double param = static_cast<double>(i) / 10 * 2 * M_PI;
			Point3 point = CurveCalculation::TorusUIso(circle3, u, v, param, majorRadius, minorRadius);
			pointOnCurve.push_back(point);
		}
		std::string filename = OUTPUT_PATH_PREFIX"CurveCalculation_TorusUIso_01.brep";
		OCCTIO::OCCTTool::Write(circle3, filename);
		for (int i = 1; i <= 11; i++) {
			Point3 p = pointOnCurve[i];
			MakeVertex v(p);
			MakeEdge2d e(p, p);
			MakeEdge edg(circle3);
			OCCTIO::OCCTTool::Write(v, filename);
			OCCTIO::OCCTTool::Write(e, filename);
			OCCTIO::OCCTTool::Write(edg, filename);
		}
		Point3 point = CurveCalculation::TorusUIso(circle3, u, v, 2 * M_PI, majorRadius, minorRadius);
		CHECK(point.X() == Approx(1.0));
		CHECK(point.Y() == Approx(3.0));
		CHECK(point.Z() == Approx(0.0));
	}}