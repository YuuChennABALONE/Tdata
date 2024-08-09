/* "template<typename OtherScalar, typename OtherScalar2, typename OtherScalar3, int DIM2 = DIM, std::enable_if_t<DIM2 == 2, int> = 0> FrameT(const PointT<OtherScalar, DIM>& point, const DirectionT<OtherScalar2, DIM>& xdir, const DirectionT<OtherScalar3, DIM>& ydir),\n",
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
template<typename T, int DIM>
bool IsEqual(const AxisT<T, DIM>& result, const AxisT<T, DIM>& expected) {
	return result.Location().IsEqual(expected.Location(), tol) &&
		result.Direction().IsEqual(expected.Direction(), tol);
}
TEST_CASE("case1:this is a case for Frame3","[Common][Frame3]")
{
	SECTION("YDirection"){
		PointT<double, 3> p(1.0, 2.0, 3.0);
		DirectionT<double, 3> dz(1.0, 2.0, 3.0);
		DirectionT<double, 3> dy(-13.0, 2.0, 3.0);
		FrameT<double, 3> f1(p, dz);
		CHECK(f1.YDirection().IsEqual(dy, tol));
	}}