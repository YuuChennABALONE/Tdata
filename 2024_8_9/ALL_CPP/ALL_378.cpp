/* "template<typename OtherScalar> [[nodiscard]] PointT Mirrored(const PointT<OtherScalar, DIM>& p),\n",
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
	SECTION("Mirror(point) 2D") {
        PointT<double, 2> p1(1.0, 2.0);
        PointT<double, 2> p2(2.0, 4.0);
        PointT<double, 2> p3(3.0, 6.0);
        CHECK(p1.Mirrored(p2).IsEqual(p3, tol));
    }}