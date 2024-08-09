/* "template<typename OtherScalar, typename OtherScalar2> AxisT(const PointT<OtherScalar, DIM>& point, const DirectionT<OtherScalar2, DIM>& dir),\n",
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
	SECTION("IsCoaxial 2D") {
		AxisT<double, 2> a1(PointT<double, 2>{0.0, 0.0}, DirectionT<double, 2>{1.0, 2.0});
		AxisT<double, 2> a2(PointT<double, 2>{2.0, 4.0}, DirectionT<double, 2>{1.0, 2.0});
		AxisT<double, 2> a3(PointT<double, 2>{2.0, 4.0}, DirectionT<double, 2>{2.0, 2.0});
		AxisT<double, 2> a4(PointT<double, 2>{1.0, 4.0}, DirectionT<double, 2>{1.0, 2.0});
		CHECK(a1.IsCoaxial(a2, 1e-6, 1e-6) == true);
		CHECK(a1.IsCoaxial(a3, 1e-6, 1e-6) == false);
		CHECK(a1.IsCoaxial(a4, 1e-6, 1e-6) == false);
	}}