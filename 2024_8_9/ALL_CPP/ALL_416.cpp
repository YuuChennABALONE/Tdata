/* "template<typename OtherScalar, typename OtherScalar2, int DIM2 = DIM, typename = typename std::enable_if_t<DIM2 == 3>> [[nodiscard]] VectorT Rotated(const AxisT<OtherScalar, DIM>& axis, const OtherScalar2& angle),\n",
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
	SECTION("Rotate 3D") {
        VectorT<double, 3> p1(1.0, 2.0, 3.0);
        PointT<double, 3> p2(2.0, 3.0, 4.0);
        DirectionT<double, 3> d(1.0, 1.0, 2.0);
        AxisT<double, 3> a(p2, d);
        VectorT<double, 3> p3((9.0 - std::sqrt(6.0)) / 6.0, (9.0 - std::sqrt(6.0)) / 6.0, 3.0 + 1.0 / std::sqrt(6.0));
        CHECK(p1.Rotated(a, M_PI_2).IsEqual(p3, tolDis, tolAng));
    }}