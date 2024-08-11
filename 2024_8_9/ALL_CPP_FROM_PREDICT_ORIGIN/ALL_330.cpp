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
TEST_CASE("case1:this is a case for Point3", "[Common][Point3]") {
	SECTION("Distance") {
        PointT<double, 3> p1(1.0, 2.0, 3.0);
        PointT<double, 3> p2(2.0, 3.0, 4.0);
        CHECK(p1.Distance(p2) == sqrt(4.0 + 5.0 + 7.0));
    }}