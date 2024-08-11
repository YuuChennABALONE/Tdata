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
TEST_CASE("case1:this is a case for Vector3", "[Common][Vector3]"){
	SECTION("Constructor from direction") {
        DirectionT<double, 3> v(1.0, 2.0, 3.0);
        VectorT<double, 3> result(v);
        VectorT<double, 3> expected(1.0 / sqrt(14.0), 2.0 / sqrt(14.0), 3.0 / sqrt(14.0));
        CHECK(result.IsEqual(expected, tolDis, tolAng));
    }}