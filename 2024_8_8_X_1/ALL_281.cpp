/* "template<typename OtherScalar> explicit DirectionT(const CoordT<OtherScalar, DIM>& v),\n",
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
TEST_CASE("case1:this is a case for Direction2", "[Common][Direction2]") {
	SECTION("Mirror(point) 2D") {
        DirectionT<double, 2> p1(1.0, 2.0);
        DirectionT<double, 2> p2(2.0, 3.0);
        DirectionT<double, 2> p3(19.0 / 13.0, 22.0 / 13.0);
        CHECK(p1.Mirrored(p2).IsEqual(p3, tol));
    }}