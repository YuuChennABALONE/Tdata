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
	SECTION("AngleWithRef") {
        DirectionT<double, 3> v1(1.0, 2.0, 3.0);
        DirectionT<double, 3> v2(-3.0, 2.0, -1.0);
        DirectionT<double, 3> v3(1.0, 1.0, 1.0);
        CHECK(v1.AngleWithRef(v2, v3) == Approx(-acos(-1.0 / 7.0)));
    }}