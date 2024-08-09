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
TEST_CASE("case1: CurveCalculation::IsoparametericCurve OnCone 1/4 ", "[math][IsoparametricCurve][P1][Cone]") {
	Frame3 frame;
	double radius = 5.0;
	double semiAngle = 45.0;
	double u = 0.0;
	bool isRight = true;
	AMCAX::Cone uiCone(frame, radius, semiAngle, isRight);
	Line3 line(uiCone);
	Point3 point1(line.Location().X(), line.Location().Y(), line.Location().Z());
	Direction3 dir1(line.Direction().X(), line.Direction().Y(), line.Direction().Z());
	Point3 point2(line.Location().X() + line.Direction().X() * 10.0, line.Location().Y() + line.Direction().Y() * 10.0, line.Location().Z() + line.Direction().Z() * 10.0);
	CHECK(uiCone.IsUPeriodic() == true);
	CHECK(uiCone.IsVPeriodic() == false);
	CHECK(uiCone.NUParameter() == Approx(2 * M_PI));
	CHECK(uiCone.NVParameter() == Approx(0.0));
	AMCAX::Point3 AMCAXpoint3 = AMCAX::CurveCalculation::IsoparametricCurve(uiCone, 0.0, 2 * M_PI, 1.0 / 100);
	OUTPUTSTL(uiCone, L"IsoparametricCurve_onCone5"##'_##_(int)##'.##extension");
	OUTPUTSTL(uiCone, L"IsoparametricCurve_onCone5"##'_##_(double)##'.##extension);
	OCCTIO::OCCTTool::Write(uiCone, outputDir + L"IsoparametricCurve_onCone5"##'.##stl");
	CHECK(point1.X() == AMCAXpoint3.X());
	CHECK(point1.Y() == AMCAXpoint3.Y());
	CHECK(point1.Z() == AMCAXpoint3.Z());
	CHECK(dir1.X() == AMCAXpoint3.X());
	CHECK(dir1.Y() == AMCAXpoint3.Y());
	CHECK(dir1.Z() == AMCAXpoint3.Z());
	CHECK(point2.X() == AMCAXpoint3.X() + dir1.X() * 10.0);
	CHECK(point2.Y() == AMCAXpoint3.Y() + dir1.Y() * 10.0);
	CHECK(point2.Z() == AMCAXpoint3.Z() + dir1.Z() * 10.0);
}