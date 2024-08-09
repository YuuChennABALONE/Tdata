/* "template<typename OtherScalar, typename OtherScalar2> [[nodiscard]] bool IsEqual(const PointT<OtherScalar, DIM>& other, const OtherScalar2& tol),\n",
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
	SECTION("SetZ") {
        PointT<double, 3> result;
        result.SetZ(1);
        PointT<double, 3> expected(0.0, 0.0, 1.0);
        CHECK(result.IsEqual(expected, tol));
    }}