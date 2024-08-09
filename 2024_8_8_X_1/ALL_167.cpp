/* "template<typename OtherScalar, int DIM2 = DIM, std::enable_if_t<DIM2 == 3, int> = 0> [[nodiscard]] PointT Mirrored(const FrameT<OtherScalar, DIM>& frame),\n",
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
#define tolAng 0.1
using namespace AMCAX;
using namespace std;
TEST_CASE("case1:this is a case for Point3", "[Common][Point3]") {
	SECTION("Mirror(point) 3D") {
        PointT<double, 3> p1(1.0, 2.0, 3.0);
        PointT<double, 3> p2(2.0, 4.0, 5.0);
        PointT<double, 3> p3(3.0, 6.0, 7.0);
        CHECK(p1.Mirrored(p2).IsEqual(p3, tol));
    }}