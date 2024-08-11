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
bool IsEqual(const TransformationT<T, DIM>& result, const TransformationT<T, DIM>& expected)
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
	SECTION("Construction 3D") {
		PointT<double, 3> p(1.0, -1.0, 0.0);
		DirectionT<double, 3> dz(1.0, 2.0, 3.0);
		DirectionT<double, 3> dx(1.0, 1.0, 0.0);
		TransformationT<double, 3> tr;
		tr.Set(p, dz, dx);
		TransformationT<double, 3> tr2;
		tr2.Set(p, dz);
		tr2.ScaleAt(p, 1.0);
		tr2.SetXDirection(dx);
		TransformationT<double, 3> tr3;
		tr3.Set(p, dz);
		tr3.SetXDirection(dx);
		CHECK(IsEqual(tr, tr2));
		CHECK(IsEqual(tr, tr3));
	}}