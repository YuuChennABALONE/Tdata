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
bool IsEqual(const CoordT<T, DIM>& result, const CoordT<T, DIM>& expected)
{
	return result.IsEqual(expected, tol);
}
TEST_CASE("case1:this is a case for Transformation3", "[Common][Transformation3]") {
	SECTION("Transform(point, vector) 3D") {
		PointT<double, 3> p(1.0, 2.0, 3.0);
		VectorT<double, 3> v(2.0, 3.0, 4.0);
		PointT<double, 3> p2(3.0, 4.5, 6.0);
		TransformationT<double, 3> tr;
		tr.SetRotation(p, v);
		TransformationT<double, 3> tr2;
		tr2.SetRotation(p2, v);
		CHECK(tr.Transform(p).IsEqual(p2, tol));
		CHECK(tr2.Transform(p).IsEqual(p2, tol));
	}}