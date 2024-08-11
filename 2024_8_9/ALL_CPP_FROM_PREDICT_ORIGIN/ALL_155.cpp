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
template<typename T, int DIM>
bool IsEqual(const AxisT<T, DIM>& result, const AxisT<T, DIM>& expected) {
	return result.Location().IsEqual(expected.Location(), tol) &&
		result.Direction().IsEqual(expected.Direction(), tol);
}
TEST_CASE("case1:this is a case for Transformation3","[Common][Transformation3]")
{
	SECTION("SetTransformation axis3") {
		PointT<double, 3> p(1.0, -1.0, 0.0);
		DirectionT<double, 3> dz(1.0, 2.0, 3.0);
		FrameT<double, 3> f1(p, dz);
		DirectionT<double, 3> dz2(-1.0, -2.0, -3.0);
		DirectionT<double, 3> dx2(0.0, 3.0, -2.0);
		AxisT<double, 3> axis(p, dz);
		AxisT<double, 3> axis2(p, dz2);
		DirectionT<double, 3> dx(p.X() + dz.X() * 2.0, p.Y() + dz.Y() * 2.0, p.Z() + dz.Z() * 2.0);
		DirectionT<double, 3> dy(p.Y() + dz.X() * (-1.0), p.X() - dz.Y() * (-1.0), p.Z() + dz.Z() * (-1.0));
		FrameT<double, 3> f2(dx, dy);
		TransformationT<double, 3> tr;
		tr.SetTransformation(axis, axis2);
		CHECK(IsEqual(tr.Location(), p));
		CHECK(IsEqual(tr.Rotation().XDirection(), dx2));
		CHECK(IsEqual(tr.Rotation().YDirection(), dy));
		CHECK(IsEqual(tr.Rotation().ZDirection(), dz2));
	}}