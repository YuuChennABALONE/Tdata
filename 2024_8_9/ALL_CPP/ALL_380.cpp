/* "template<typename OtherScalar> PointT& Mirror(const PointT<OtherScalar, DIM>& p),\n",
      */
 #include<catch.hpp>
#include <common/AxisT.hpp>
#include <common/DirectionT.hpp>
#include <common/FrameT.hpp>
#include <common/PointT.hpp>
#include <common/TransformationT.hpp>
#include <iostream>
#define tol 0.001
using namespace AMCAX;
using namespace std;
TEST_CASE("case1:this is a case for Point2", "[Common][Point2]") {
	SECTION("Mirror(axis) 2D") {
        PointT<double, 2> p1(1.0, 2.0);
        PointT<double, 2> p2(2.0, 3.0);
        DirectionT<double, 2> d(7.0, 3.0);
        AxisT<double, 2> a(p2, d);
        PointT<double, 2> p3(17.0 / 29.0, 86.0 / 29.0);
        CHECK(p1.Mirrored(a).IsEqual(p3, tol));
    }}