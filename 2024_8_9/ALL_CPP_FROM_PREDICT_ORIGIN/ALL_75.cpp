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
TEST_CASE("case1:this is a case for Frame2", "[Common][Frame2]") {
	SECTION("Mirror axis 2D") {
		PointT<double, 2> p(1.0, 2.0);
		DirectionT<double, 2> d(1.0, 3.0);
		FrameT<double, 2> f1(p, d);
		PointT<double, 2> p2(2.0, 3.0);
		DirectionT<double, 2> d2(1.0, 4.0);
		AxisT<double, 2> axis(p2, d2);
		PointT<double, 2> p3(3.0, 5.0);
		FrameT<double, 2> f2(p3, d2);
		CHECK(IsEqual(f1.Mirrored(axis), f2));
	}}