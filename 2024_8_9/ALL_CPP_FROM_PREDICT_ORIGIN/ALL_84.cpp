 #include<catch.hpp>
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
TEST_CASE("case1:this is a case for Direction2", "[Common][Direction2]") {
	SECTION("Constructor from vector") {
        VectorT<double, 2> v(1.0, 2.0);
        DirectionT<double, 2> result(v);
        CoordT<double, 2> expected(1.0 / sqrt(5.0), 2.0 / sqrt(5.0));
        CHECK(result.Coord().IsEqual(expected, tol));
    }}