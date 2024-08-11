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
TEST_CASE("case1: GeneralTransformShape 3D ", "[math][GeneralTransformShape][P1]") {
	Direction3 dir3(0.0, 0.0, 1.0);
	Point3 point3(0.0, 0.0, 3.0);
	Frame3 frame3(point3, dir3);
	double major3 = 3.0, minor3 = 4.0;
	AMCAX::Circle3 circle3(frame3, major3, minor3);
	MakeEdge edge1(circle3);
	SECTION("Construct from a general transformation") {
		GeneralTransformation3 tr;
		tr.SetMirror(Frame3(Point3(1.0, 1.0, 1.0), Direction3(0.0, 0.0, 1.0)));
		GeneralTransformShape trs(tr);
		auto trs1 = GeneralTransformShape(tr);
		CHECK(trs.IsMirror());
		CHECK(trs1.IsMirror());
		double major = 3.0, minor = 4.0;
		AMCAX::Circle3 circle(frame3, major, minor);
		MakeEdge edge(circle);
		MakeEdge edge2 = tr.Transform(edge);
		MakeEdge edge3 = trs.Transform(edge);
		MakeEdge edge4 = trs1.Transform(edge1);
		CHECK(edge.Length() == Approx(edge2.Length()).margin(0.1));
		CHECK(edge.Length() == Approx(edge3.Length()).margin(0.1));
		CHECK(edge.Length() == Approx(edge4.Length()).margin(0.1));
	}}