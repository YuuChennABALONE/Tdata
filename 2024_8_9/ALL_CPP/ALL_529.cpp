/* "template<typename OtherScalar, int DIM2 = DIM, std::enable_if_t<DIM2 == 2, int> = 0> void SetXAxis(const AxisT<OtherScalar, DIM>& axis),\n",
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
bool IsEqual(const FrameT<T, DIM>& result, const FrameT<T, DIM>& expected)
{
	if constexpr (DIM == 1)
	{
		return result.Location().IsEqual(expected, tol) && result.Direction().IsEqual(expected.Direction(), tol);
	}
	else if constexpr (DIM == 2)
	{
		return result.Location().IsEqual(expected.Location(), tol) && result.YDirection().IsEqual(expected.YDirection(), tol) && result.XDirection().IsEqual(expected.XDirection(), tol);
	}
	else if constexpr (DIM == 3)
	{
		return result.Location().IsEqual(expected.Location(), tol) && result.Direction().IsEqual(expected.Direction(), tol) && result.YDirection().IsEqual(expected.YDirection(), tol) && result.XDirection().IsEqual(expected.XDirection(), tol);
	}
	else
	{
		return false;
	}
}
TEST_CASE("case1:this is a case for Frame2", "[Common][Frame2]") {
	SECTION("SetXAxis 2D") {
		PointT<double, 2> p(1.0, 2.0);
		PointT<double, 2> p2(3.0, 1.0);
		DirectionT<double, 2> dx(1.0, 3.0);
		FrameT<double, 2> f1(p, dx);
		DirectionT<double, 2> dx2(-1.0, -2.0);
		FrameT<double, 2> f2(p2, dx2);
		AxisT<double, 2> axis(p, dx);
		f2.SetXAxis(axis);
		CHECK(IsEqual(f1, f2));
	}}