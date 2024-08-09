/* "PointT()\t @details The default point is (0, 0, ..., 0)\n\t @brief Default constructor\n,\n",
      */
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
#define tolAng 0.1
using namespace AMCAX;
using namespace std;
TEST_CASE("case1:this is a case for Point3", "[Common][Point3]") {
	SECTION("Default constructor","[1]") {
        Point3  p1;
        Point3  p2(0.0, 0.0, 0.0);
        CHECK(p1.IsEqual(p2, tol));
    }}