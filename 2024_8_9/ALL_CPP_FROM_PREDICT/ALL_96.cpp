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
	SECTION("SetFocal"){
		AxisT<double, 3> a1;
		a1.SetFocal(5.0, 7.0, 11.0);
		CHECK(a1.Focal() == Approx(5.0));
		CHECK(a1.SecondPrincipalAxis().Focal() == Approx(7.0));
		CHECK(a1.ThirdPrincipalAxis().Focal() == Approx(11.0));
	}}