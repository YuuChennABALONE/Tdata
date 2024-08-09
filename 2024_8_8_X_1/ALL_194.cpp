/* "template<typename OtherScalar, typename OtherScalar2, int DIM2 = DIM, typename = typename std::enable_if_t<DIM2 == 3>> void SetTransformation(const FrameT<OtherScalar, DIM>& frameFrom, const FrameT<OtherScalar2, DIM>& frameTo),\n",
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
	SECTION("SetTransformation 3D") {	
		FrameT<double, 3> f1(PointT<double, 3>(1.0, 2.0, 3.0), DirectionT<double, 3>(4.0, 5.0, 6.0), DirectionT<double, 3>(-3.0, -5.0, 1.0));
		FrameT<double, 3> f2(PointT<double, 3>(3.0, 1.0, -1.0), DirectionT<double, 3>(1.0, 5.0, -3.0), DirectionT<double, 3>(2.0, -2.0, 2.0));
		TransformationT<double, 3> tr;
		tr.SetTransformation(f1, f2);
		CoordT<double, 3> p(4.0, 1.0, 3.0);
		tr.Transform(p);
		CoordT<double, 3> p2(54.0 / std::sqrt(770.0) - 232.0 / (34.0 * std::sqrt(1155.0)) + 100.0 / (34.0 * std::sqrt(15.0)) - 2.0 / std::sqrt(10.0),
			-72.0 / (7.0 * std::sqrt(22.0)) - 1744.0 / (238.0 * std::sqrt(33.0)) + 94.0 / (34.0 * std::sqrt(21.0)) - 16.0 / std::sqrt(14.0),
			33.0 / (7.0 * std::sqrt(55.0)) - 8184.0 / (119.0 * std::sqrt(330.0)) - 60.0 / (17.0 * std::sqrt(210.0)) - 9.0 / std::sqrt(35.0));
		CHECK(IsEqual(p, p2));
	}}