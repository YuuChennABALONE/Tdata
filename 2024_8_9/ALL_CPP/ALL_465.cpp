/* "template<typename OtherScalar, typename = typename std::enable_if_t<DIM >= 4 && std::is_convertible_v<OtherScalar, Scalar>>> void SetW(const OtherScalar& w),\n",
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
	SECTION("SetX, SetY, SetZ, SetW"){
        DirectionT<double, 4> result;
        result.SetX(1);
        result.SetY(2);
        result.SetZ(3);
        result.SetW(4);
        CoordT<double, 4> expected(1.0 / sqrt(850.0), 2.0 / sqrt(850.0), 3.0 / sqrt(170), 4.0 / sqrt(17));
        CHECK(result.X() == Approx(1.0 / sqrt(850.0)));
        CHECK(result.Y() == Approx(2.0 / sqrt(850.0)));
        CHECK(result.Z() == Approx(3.0 / sqrt(170.0)));
        CHECK(result.W() == Approx(4.0 / sqrt(17.0)));
    }}