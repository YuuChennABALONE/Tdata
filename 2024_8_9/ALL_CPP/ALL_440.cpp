/* "VectorT()\t @details The default vector is (0, 0, ..., 0)\n\t @brief The default constructor\n,\n",
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
#define tolAng 0.01
using namespace AMCAX;
using namespace std;
TEST_CASE("case1:this is a case for Vector3", "[Common][Vector3]"){
	SECTION("Default constructor") {
        VectorT<double, 3> p1;
        VectorT<double, 3> p2(0.0, 0.0, 0.0);
        CHECK(p1.IsEqual(p2, tolDis, tolAng));
    }}