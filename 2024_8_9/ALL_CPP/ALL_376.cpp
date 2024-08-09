/* "template<typename OtherScalar, typename OtherScalar2, int DIM2 = DIM, typename = typename std::enable_if_t<DIM2 == 2>> [[nodiscard]] PointT Rotated(const PointT<OtherScalar, DIM>& point, const OtherScalar2& angle),\n",
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
	SECTION("Rotate 2D") {
        PointT<double, 2> p1(1.0, 2.0);
        PointT<double, 2> p2(2.0, 3.0);
        PointT<double, 2> p3(3.0, 2.0);
        CHECK(p1.Rotated(p2, M_PI_2).IsEqual(p3, tol));
    }
}