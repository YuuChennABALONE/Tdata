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
TEST_CASE("case1:this is a case for Transformation3", "[Common][Transformation3]") {
	SECTION("SetTranslation(p1,p2)") {
		PointT<double, 3> p1(1.0, 2.0, 3.0);
		PointT<double, 3> p2(2.0, 3.0, 4.0);
		TransformationT<double, 3> tr;
		tr.SetTranslation(p1, p2);
		PointT<double, 3> p3(11.0 / 3.0, 17.0 / 3.0, 25.0 / 3.0);
		TransformationT<double, 3> tr2;
		tr2.SetTranslation(p3);
		CHECK(IsEqual(tr, tr2));
	}}