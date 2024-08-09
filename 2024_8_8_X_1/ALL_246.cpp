/* "template<typename OtherScalar> [[nodiscard]] auto Cross(const VectorT<OtherScalar, DIM>& other),\n",
      */
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
TEST_CASE("case1:this is a case for Vector2", "[Common][Vector2]"){
	SECTION("Cross 2D") {
        VectorT<double, 2> v1(1.0, 2.0);
        VectorT<double, 2> v2(2.0, 3.0);
        CHECK(v1.Cross(v2) == -1.0);
    }}