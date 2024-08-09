/* "template<typename OtherScalar, typename OtherScalar2> VectorT(const PointT<OtherScalar, DIM>& p1, const PointT<OtherScalar2, DIM>& p2),\n",
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
	SECTION("Angle 2D") {
        VectorT<double, 2> v1(1.0, 3.0);
        VectorT<double, 2> v2(-1.0, 2.0);
        CHECK(v1.Angle(v2) == Approx(acos(M_SQRT1_2)));
    }}