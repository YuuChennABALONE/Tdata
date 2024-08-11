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
	SECTION("Reverse") {
        DirectionT<double, 3> result;
        result.Reverse();
        CoordT<double, 3> expected(-1.0, 0.0, 0.0);
        CHECK(result.Coord().IsEqual(expected, tol));
    }}