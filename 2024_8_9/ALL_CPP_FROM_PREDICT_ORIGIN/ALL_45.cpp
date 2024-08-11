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
	SECTION("Rotate 2D"){
		PointT<double, 2> p(1.0, 2.0);
		DirectionT<double, 2> d(1.0, 3.0);
		FrameT<double, 2> f1(p, d);
		PointT<double, 2> p2(2.0, 3.0);
		DirectionT<double, 2> d2(3.0, 1.0);
		DirectionT<double, 2> d3(-1.0, -2.0);
		FrameT<double, 2> f2(p2, d2);
		CHECK(IsEqual(f1.Rotated(p2, p, M_PI_2), f2));
		CHECK(IsEqual(f1.Rotated(p2, p, -M_PI_2), f2));
		CHECK(IsEqual(f1.Rotated(p2, p, M_PI), f2));
		CHECK(IsEqual(f1.Rotated(p2, p, -M_PI), f2));
		CHECK(IsEqual(f1.Rotated(p2, p, M_PI_4), f2));
		CHECK(IsEqual(f1.Rotated(p2, p, -M_PI_4), f2));
	}}