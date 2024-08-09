/* "template<typename OtherScalar, typename OtherScalar2> [[nodiscard]] bool IsEqual(const DirectionT<OtherScalar, DIM>& other, const OtherScalar2& tol),\n",
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
	SECTION("Constructor from vector") {
        VectorT<double, 3> v(1.0, 2.0, 3.0);
        DirectionT<double, 3> result(v);
        CoordT<double, 3> expected(1.0 / sqrt(14.0), 2.0 / sqrt(14.0), 3.0 / sqrt(14.0));
        CHECK(result.Coord().IsEqual(expected, tol));
    }}