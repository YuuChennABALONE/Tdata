/* "[[nodiscard]] VectorT Normalized()\t @return The normalized vector\n\t @brief Get the normalized vector\n,\n",
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
	SECTION("Normalize") {
        VectorT<double, 3> v1(1.0, 2.0, 2.0);
        VectorT<double, 3> v2(1.0 / 3.0, 2.0 / 3.0, 2.0 / 3.0);
        CHECK(v1.Normalized().IsEqual(v2, tolDis, tolAng));
    }}