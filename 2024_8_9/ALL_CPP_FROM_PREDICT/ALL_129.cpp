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
TEST_CASE("case1: Hyperbola3 [11/20] ", "[math][Hyperbola3][P1]") {
	Direction3 dir3(0.0, 0.0, 1.0);
	Point3 point3(0.0, 0.0, 0.0);
	Frame3 frame3(point3, dir3);
	Hyperbola3 hyperbola3(frame3, 5.0, 3.0); 
	double u1 = 0.0;
	double u2 = 2 * M_PI;
	AMCAX::Point3 AMCAX_arc3 = CurveCalculation::SampledPoint(5, hyperbola3, 0, 2 * M_PI);
	std::vector<AMCAX::Point3> Points;
	Points.push_back(point3);
	for (int i = 0; i < 5; i++)
	{
		Points.push_back(AMCAX_arc3[i]);
	}
	OCCTIO::OCCTTool::Write(Points, OUTPUT_PATH_PREFIX"Hyperbola3_to_Point3_case1.brep");
	CHECK(OCCTIO::OCCTTool::ReadAndCompare(OUTPUT_PATH_PREFIX"Hyperbola3_to_Point3_case1.brep", INPUT_PATH_PREFIX"Hyperbola3_to_Point3_case1.brep"));
}