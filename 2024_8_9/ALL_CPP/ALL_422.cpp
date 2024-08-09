/* "template<typename OtherScalar> VectorT& Mirror(const AxisT<OtherScalar, DIM>& axis),\n",
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
	SECTION("Mirror(axis) 3D") {
        VectorT<double, 3> p1(1.0, 2.0, 3.0);
        PointT<double, 3> p2(2.0, 3.0, 4.0);
        DirectionT<double, 3> d(7.0, 3.0, 2.0);
        AxisT<double, 3> a(p2, d);
        VectorT<double, 3> p3(102.0 / 31.0, -5.0 / 31.0, -55.0 / 31.0);
        CHECK(p1.Mirrored(a).IsEqual(p3, tolDis, tolAng));
    }}