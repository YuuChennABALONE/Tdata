/* "template<typename OtherScalar, typename OtherScalar2> [[nodiscard]] AxisT Scaled(const PointT<OtherScalar, DIM> point, const OtherScalar2& scale),\n",
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
template<typename T, int DIM>
bool IsEqual(const AxisT<T, DIM>& result, const AxisT<T, DIM>& expected) {
	return result.Location().IsEqual(expected.Location(), tol) &&
		result.Direction().IsEqual(expected.Direction(), tol);
}
TEST_CASE("case1:this is a case for Axis2", "[Common][Axis2]") {
	SECTION("Scale 2D") {
		AxisT<double, 2> a1(PointT<double, 2>{1.0, 2.0}, DirectionT<double, 2>{1.0, 2.0});
		PointT<double, 2> p(2.0, 3.0);
		AxisT<double, 2> a2(PointT<double, 2>{0.5, 1.5}, DirectionT<double, 2>{1.0, 2.0});
		CHECK(IsEqual(a1.Scaled(p, 1.5), a2));
	}}