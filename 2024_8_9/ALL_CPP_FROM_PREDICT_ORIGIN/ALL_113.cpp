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
TEST_CASE("case1:this is a case for Direction3", "[Common][Direction3]") {
	SECTION("Rotated 3D") {
        DirectionT<double, 3> p1(1.0, 2.0, 3.0);
        DirectionT<double, 3> p2(2.0, 3.0, 4.0);
        AxisT<double, 3> a(p1, p2);
        DirectionT<double, 3> p3(-1.0, -1.0, -1.0);
        CHECK(p1.Rotated(a, M_PI_2).IsEqual(p3, tol));
    }}