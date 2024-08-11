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
	SECTION("SetTranslation vec 3D"){
		AxisT<double, 3> a1;
		VectorT<double, 3> p(1.0, 2.0, 3.0);
		a1.SetLocation(p);
		VectorT<double, 3> p2(2.0, 3.0, 4.0);
		a1.SetTranslation(p2);
		AxisT<double, 3> a2(p, p2);
		CHECK(IsEqual(a1, a2));
	}}