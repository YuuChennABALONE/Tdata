/* "template<typename OtherScalar, int DIM2 = DIM, std::enable_if_t<DIM2 == 3, int> = 0> DirectionT& Mirror(const FrameT<OtherScalar, DIM>& frame),\n",
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
TEST_CASE("case1:this is a case for Direction3", "[Common][Direction3]") {
	SECTION("Default constructor") {
        DirectionT<double, 3> p1;
        DirectionT<double, 3> p2(1.0, 0.0, 0.0);
        CHECK(p1.IsEqual(p2, tol));
    }}