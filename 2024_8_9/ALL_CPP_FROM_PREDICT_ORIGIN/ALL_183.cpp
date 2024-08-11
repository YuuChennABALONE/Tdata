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
template<typename T>
bool IsEqual(const T& result, const T& expected)
{
	return result == expected;
}
bool IsEqual(const double& result, const double& expected)
{
	return std::fabs(result - expected) <= 1e-6;
}
template<typename T, int DIM>
bool IsEqual(const CoordT<T, DIM>& result, const CoordT<T, DIM>& expected)
{
	for (int i = 0; i < DIM; i++)
	{
		if (!IsEqual(result[i], expected[i]))
		{
			return false;
		}
	}
	return true;
}
template<typename T, int ROW, int COL>
bool IsEqual(const MatrixT<T, ROW, COL>& result, const MatrixT<T, ROW, COL>& expected)
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (!IsEqual(result(i, j), expected(i, j)))
			{
				return false;
			}
		}
	}
	return true;
}
template<typename T, int DIM>
bool IsEqual(const PointT<T, DIM>& result, const PointT<T, DIM>& expected)
{
	return IsEqual(result.Coord(), expected.Coord());
}
template<typename T, int DIM>
bool IsEqual(const VectorT<T, DIM>& result, const VectorT<T, DIM>& expected)
{
	return IsEqual(result.Coord(), expected.Coord());
}
template<typename T, int DIM>
bool IsEqual(const DirectionT<T, DIM>& result, const DirectionT<T, DIM>& expected)
{
	return IsEqual(result.Coord(), expected.Coord());
}
template<typename T, int DIM>
bool IsEqual(const AxisT<T, DIM>& result, const AxisT<T, DIM>& expected)
{
	return IsEqual(result.Location(), expected.Location()) && IsEqual(result.Direction(), expected.Direction());
}
template<typename T, int DIM>
bool IsEqual(const FrameT<T, DIM>& result, const FrameT<T, DIM>& expected)
{
	if constexpr (DIM == 1)
	{
		return IsEqual(result.Location(), expected.Location()) && IsEqual(result.Direction(), expected.Direction());
	}
	else if constexpr (DIM == 2)
	{
		return IsEqual(result.Location(), expected.Location()) && IsEqual(result.YDirection(), expected.YDirection()) && IsEqual(result.XDirection(), expected.XDirection());
	}
	else if constexpr (DIM == 3)
	{
		return IsEqual(result.Location(), expected.Location()) && IsEqual(result.Direction(), expected.Direction()) && IsEqual(result.XDirection(), expected.XDirection()) && IsEqual(result.YDirection(), expected.YDirection());
	}
	else
	{
		return false;
	}
}
template<typename T, int DIM>
bool IsEqual(const TransformationT<T, DIM>& result, const TransformationT<T, DIM>& expected)
{
	return IsEqual(result.ScaleFactor(), expected.ScaleFactor()) && IsEqual(result.Type(), expected.Type()) && IsEqual(result.HVectorialPart(), expected.HVectorialPart()) && IsEqual(result.TranslationPart(), expected.TranslationPart());
}
TEST_CASE("case1:this is a case for Transformation3","[Common][Transformation3]")
{
	SECTION("Power 3D") {
		TransformationT<double, 3> tr;
		tr.SetRotation(Axis3(Point3(1.0, 2.0, 3.0), Direction3(1.0, 1.0, 1.0)), M_PI_2);
		TransformationT<double, 3> tr2 = tr.Power(2);
		CHECK(tr.ScaleFactor() == Approx(1).margin(1e-12));
		CHECK(tr.Type() == TransformationType::Rotation);
		CHECK(tr2.ScaleFactor() == Approx(1).margin(1e-12));
		CHECK(tr2.Type() == TransformationType::Rotation);
		CHECK(IsEqual(tr.HVectorialPart(), tr2.HVectorialPart()));
		CHECK(IsEqual(tr.TranslationPart(), tr2.TranslationPart()));
	}}