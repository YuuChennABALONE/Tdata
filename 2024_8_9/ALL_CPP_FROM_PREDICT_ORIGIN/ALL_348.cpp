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
TEST_CASE("case1:this is a case for Frame3","[Common][Frame3]")
{
	SECTION("Translate vector 3D"){
		PointT<double, 3> p(1.0, -1.0, 0.0);
		DirectionT<double, 3> dz(1.0, 2.0, 3.0);
		FrameT<double, 3> f1(p, dz);
		PointT<double, 3> p2(1.0, 2.0, 3.0);
		VectorT<double, 3> v(1.0, 2.0, 3.0);
		PointT<double, 3> p3(2.0, 4.0, 6.0);
		FrameT<double, 3> f2(p3, dz);
		CHECK(IsEqual(f1.Translated(v), f2));
	}}