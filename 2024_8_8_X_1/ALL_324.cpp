/* "template<typename OtherScalar, typename OtherScalar2, int DIM2 = DIM, std::enable_if_t<DIM2 == 2, int> = 0> FrameT(const PointT<OtherScalar, DIM>& point, const DirectionT<OtherScalar2, DIM>& xdir, bool isright = true),\n",
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
	SECTION("Construction 2D") {
		PointT<double, 2> p(0.0, 0.0);
		DirectionT<double, 2> dx(1.0, 0.0);
		DirectionT<double, 2> dy(0.0, 1.0);
		FrameT<double, 2> f1;
		FrameT<double, 2> f2(p, dx, dy);
		CHECK(IsEqual(f1, f2));
	}}