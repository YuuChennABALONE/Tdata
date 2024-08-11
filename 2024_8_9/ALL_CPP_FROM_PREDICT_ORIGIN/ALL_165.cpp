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
TEST_CASE("case1:this is a case for Transformation2", "[Common][Transformation2]") {
	SECTION("SetRotation 2D") {
		TransformationT<double, 2> tr;
		PointT<double, 2> p(1.0, 2.0);
		tr.SetRotation(p, M_PI_2);
		CHECK(tr.Determinant() == Approx(1.0));
		CHECK(tr.IsTranslationScaleRotation() == true);
		CHECK(tr.TranslationComponent().IsZero() == false);
		CHECK(tr.ScaleFactor() == Approx(1.0));
		CHECK(tr.RotationComponent().IsEqual(AxisT<double, 2>(p, DirectionT<double, 2>(0.0, 1.0)), tol));
		TransformationT<double, 2> tr2;
		tr2.SetRotation(p, M_PI_2);
		CHECK(IsEqual(tr, tr2));
	}}