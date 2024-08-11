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
bool IsInDirection(const FrameT<T, DIM>& result, const DirectionT<T, DIM>& direction)
{
	AxisT<T, DIM> axisDir(result.Location(), direction);
	DirectionT<T, DIM> dir(result.Location());
	return axisDir.IsCoaxial(axisDir, direction, dir, 1e-6, 1e-6);
}
template<typename T, int DIM>
bool IsInVector(const VectorT<T, DIM>& result, const VectorT<T, DIM>& vector)
{
	DirectionT<T, DIM> dir(result);
	PointT<T, DIM> p(result.Location());
	VectorT<T, DIM> vec(vector);
	return p.IsEqual(result.Location(), 1e-6) && dir.IsEqual(result.Direction(), 1e-6) && vec.IsEqual(result, 1e-6);
}
template<typename T, int DIM>
bool IsInFrame(const FrameT<T, DIM>& result, const FrameT<T, DIM>& frame)
{
	DirectionT<T, DIM> dir(result.Location());
	PointT<T, DIM> p(frame.Location());
	DirectionT<T, DIM> dir2(frame.Direction());
	return p.IsEqual(result.Location(), 1e-6) && dir.IsEqual(result.Direction(), 1e-6) && dir2.IsEqual(result.Direction2(), 1e-6);
}
TEST_CASE("case1:this is a case for Axis2", "[Common][Axis2]") {
	SECTION("IsCoaxial 2D") {
		AxisT<double, 2> a1(PointT<double, 2>(1.0, 2.0), DirectionT<double, 2>(1.0, 2.0));
		AxisT<double, 2> a2(PointT<double, 2>(2.0, 3.0), DirectionT<double, 2>(1.0, 2.0));
		CHECK(a1.IsCoaxial(a2, 1e-6, 1e-6) == true);
	}}