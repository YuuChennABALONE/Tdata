/* "template<typename OtherScalar> void SetCoord(const CoordT<OtherScalar, DIM>& v),\n",
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
	SECTION("SetCoord(x, y, z)") {
        VectorT<double, 3> result;
        result.SetCoord(1.0, 2.0, 3.0);
        VectorT<double, 3> expected(1.0, 2.0, 3.0);
        CHECK(result.IsEqual(expected, tolDis, tolAng));
    }}