/* "template<typename OtherScalar, typename OtherScalar2> VectorT(const PointT<OtherScalar, DIM>& p1, const PointT<OtherScalar2, DIM>& p2),\n",
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
	SECTION("Constructor from two points") {
        PointT<double, 3> p1(1.0, 2.0, 3.0);
        PointT<double, 3> p2(2.0, 3.0, 4.0);
        VectorT<double, 3> result(p1, p2);
        VectorT<double, 3> expected(1.0, 1.0, 1.0);
        CHECK(result.IsEqual(expected, tolDis, tolAng));
    }}