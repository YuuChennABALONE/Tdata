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
	SECTION("IsParallel") {
        VectorT<double, 3> v1(1.0, 2.0, 3.0);
        VectorT<double, 3> v2(-1.0, -2.0, -3.01);
        CHECK(v1.IsParallel(v2, tolDis) == false);
        CHECK(v1.IsParallel(v2, 0.1) == true);
    }}