 #include<catch.hpp>
#include<testHelper.h>
#include <geomAlgo/GccCircle3Tangent.hpp>
#include <geomAlgo/GccCurveCalculation.hpp>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
#include <geometry/Geom3Circle.hpp>
#include <geometry/Geom3TrimmedCurve.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeVertex.hpp>
#include <geometry/Geom3BezierCurve.hpp>
#include <hatch/BRepClassificationTools.hpp>
#include <topology/TopoEdge.hpp>
#include <modeling/MakeEdge2d.hpp>
#include <geometry/Geom3BSplineCurve.hpp>
#include <geometry/GeomAPIProjectPointOnCurve3.hpp>
#include <topology/TopoFace.hpp>
#include <modeling/MakeFace.hpp>
#include <modeling/MakeEdge2d.hpp>
#include <topology/TopoVertex.hpp>
#include <geometry/GeomAPIProjectPointOnCurve2.hpp>
#include <iostream>
using namespace AMCAX;
TEST_CASE("case1: GccCircle3Tangent::TestCircle3Circles ", "[geomAlgo][GccCircle3Tangent][P1][Circle3]") {
	Direction3 initialDir1(0.0, 0.0, 1.0);
	Frame3 defaultFrame3(Point3(1.0, 0.0, 0.0), initialDir1);
	Frame3 frame3;
	double radius1 = 0.0;
	double radius2 = 2.0;
	double radius3 = 3.0;
	AMCAX::Geom3Circle circle1(defaultFrame3, radius1);
	AMCAX::Geom3Circle circle2(frame3, radius2);
	AMCAX::Geom3Circle circle3(defaultFrame3, radius3);
	SECTION("3 circles tangent to each other") {
		GccCircle3Circles gccCircle3Circles1(circle1, circle2, circle3, 0.001);
		std::shared_ptr<Geom3Curve> curve3 = gccCircle3Circles1.Curve3();
		CHECK(gccCircle3Circles1.State() == AMCAX::GccType::Concentric);
		AMCAX::Geom3Circle circleResult(defaultFrame3, 4.0);
		CHECK(curve3->IsSimilar(circleResult, 0.001, true));
	}}