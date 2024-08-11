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
TEST_CASE("case1:this is a case for Line2", "[Common][Line2]") {
	SECTION("Contains") {
        LineT<double, 2> line(PointT<double, 2>{0.0, 0.0}, DirectionT<double, 2>{1.0, 1.0});
        PointT<double, 2> point1(0.0, 0.0);
        PointT<double, 2> point2(1.0, 1.0);
        PointT<double, 2> point3(1.0, 0.0);
        CHECK(line.Contains(point1, tol));
        CHECK(line.Contains(point2, tol));
        CHECK_FALSE(line.Contains(point3, tol));
    }}