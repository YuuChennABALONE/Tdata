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
bool IsEqual(const AxisT<T, DIM>& result, const AxisT<T, DIM>& expected) {
	return result.Location().IsEqual(expected.Location(), tol) &&
		result.Direction().IsEqual(expected.Direction(), tol);
}
TEST_CASE("case1:this is a case for Axis3","[Common][Axis3]")
{
	int i = 1;
	SECTION("Construction 3D") {
		DirectionT<double, 3> dz(0.0, 0.0, 1.0);
		FrameT<double, 3> frame;
		AxisT<double, 3> axis(frame, dz);
		PointT<double, 3> p(0.0, 0.0, 0.0);
		DirectionT<double, 3> d(1.0, 0.0, 0.0);
		AxisT<double, 3> axis2(p, d);
		CHECK(IsEqual(axis, axis2));
	}}