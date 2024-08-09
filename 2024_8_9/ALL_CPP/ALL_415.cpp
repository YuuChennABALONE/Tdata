/* "template<typename OtherScalar> [[nodiscard]] VectorT Scaled(const OtherScalar& scale),\n",
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
	SECTION("Scale") {
        VectorT<double, 3> p1(1.0, 2.0, 3.0);
        VectorT<double, 3> p3(1.5, 3.0, 4.5);
        CHECK(p1.Scaled(1.5).IsEqual(p3, tolDis, tolAng));
    }}