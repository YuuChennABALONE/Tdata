 #include<catch.hpp>
#include <sstream>
#include <common/AxisT.hpp>
#include <common/DirectionT.hpp>
#include <common/FrameT.hpp>
#include <common/PointT.hpp>
#include <common/TransformationT.hpp>
#include <common/VectorT.hpp>
#include <iostream>
#define tol 0.001
#define tolDis 0.001
#define tolAng 0.01
using namespace AMCAX;
using namespace std;
TEST_CASE("case1:this is a case for Plane", "[Common][Plane]") {
	SECTION("Construct from algebraic representation") {
        Plane plane(1., 1., 1., -3.);  
        PointT<double, 3> p(1., 1., 1.);
        DirectionT<double, 3> d(1., 1., 1.);
        Plane plane2(p, d);
        CHECK(plane.Distance(p) < tol);
        CHECK(plane.Contains(p, tol));
        CHECK(frame2.FrameToGlobalCoordinateSystem() == plane.Position().Transform(frame2));
    }}