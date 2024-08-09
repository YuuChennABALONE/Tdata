/* "template<int DIM2 = DIM, typename = typename std::enable_if_t<DIM2 >= 1>> [[nodiscard]] const DirectionT<Scalar, DIM>& XDirection(),\n",
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
	SECTION("Mirror axis 2D") {
		PointT<double, 2> p(1.0, 2.0);
		DirectionT<double, 2> d(1.0, 3.0);
		FrameT<double, 2> f1(p, d);
		PointT<double, 2> p2(2.0, 3.0);
		DirectionT<double, 2> d2(1.0, 4.0);
		AxisT<double, 2> axis(p2, d2);
		PointT<double, 2> p3(41.0 / 17.0, 28.0 / 17.0);
		DirectionT<double, 2> d3(9.0, 53.0);
		DirectionT<double, 2> d4(53.0, -9.0);
		FrameT<double, 2> f2 = f1.Mirrored(axis);
		CHECK(f2.Location().IsEqual(p3, tol));
		CHECK(f2.XDirection().IsEqual(d3, tol));
		CHECK(f2.YDirection().IsEqual(d4, tol));
	}}