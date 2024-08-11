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
bool IsEqual(const AxisT<T, DIM>& result, const AxisT<T, DIM>& expected){
	return result.Location().IsEqual(expected.Location(), tol) &&
		result.Direction().IsEqual(expected.Direction(), tol);
}
TEST_CASE("case1:this is a case for Axis3","[Common][Axis3]")
{
	int i = 1;
	SECTION("Transform"){
		AxisT<double, 3> a1(PointT<double, 3>{1.0, 2.0, 3.0}, DirectionT<double, 3>{1.0, 2.0, 3.0});
		TransformationT<double, 3> tr;
		tr.SetRotation(AxisT<double, 3>{PointT<double, 3>{2.0, 3.0, 4.0}, DirectionT<double, 3>{7.0, 3.0, 2.0}}, M_PI_2);
		AxisT<double, 3> a2(PointT<double, 3>{3.0 / sqrt(66.0) + 2.0, 19.0 / sqrt(66.0) + 3.0, -1.0 / sqrt(66.0) + 4.0}, DirectionT<double, 3>{-28.0 / sqrt(66.0), 9.0 / sqrt(66.0), -11.0 / sqrt(66.0)});
		CHECK(IsEqual(a1.Transformed(tr), a2));
	}}