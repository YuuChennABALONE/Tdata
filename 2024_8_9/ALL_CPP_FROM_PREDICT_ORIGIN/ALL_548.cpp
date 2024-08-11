 #include<catch.hpp>
#include<testHelper.h>
#include <nurbs/NURBSAPIBuildCurveFromPoints.hpp>
#include <geometry/MakeFace.hpp>
#include <topology/TopoFace.hpp>
#include <topology/TopoTool.hpp>
using namespace AMCAX;
TEST_CASE("case1: NURBSAPIBuildCurveFromPoints ", "[nurbs][NURBSAPIBuildCurveFromPoints][P1]")
{
	int npoints = 10;
	std::vector<Point3> points;
	for (int i = 0; i < npoints; i++)
	{
		double x = 1.0 * i / npoints;
		double y = sin(2 * M_PI * x);
		double z = cos(2 * M_PI * x);
		Point3 p(x, y, z);
		points.push_back(p);
	}
	int npoles = npoints - 1;
	SECTION("isPeriodic true")
	{
		bool isPeriodic = true;
		AMCAX::NURBSAPIBuildCurveFromPoints buildCurve(points, npoles, isPeriodic);
		CHECK(buildCurve.N poles() == npoles);
		CHECK(buildCurve.IsPeriodic() == isPeriodic);
		CHECK(buildCurve.Degree() == 3);
		TopoFace face = MakeFace(buildCurve, 0.001);
		CHECK(TopoTool::Surface(Face())->Type() == AMCAX::SurfaceType::BSphere);
	}}