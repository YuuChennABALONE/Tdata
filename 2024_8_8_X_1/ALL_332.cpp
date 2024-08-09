/* "template<typename OtherScalar> [[nodiscard]] AxisT Mirrored(const PointT<OtherScalar, DIM>& point),\n",
      */
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
	SECTION("Mirror(frame) 3D"){
		AxisT<double, 3> a1(PointT<double, 3>{1.0, 2.0, 3.0}, DirectionT<double, 3>{1.0, 2.0, 3.0});
		FrameT<double, 3> f(PointT<double, 3>{2.0, 3.0, 4.0}, DirectionT<double, 3>{7.0, 3.0, 2.0});
		AxisT<double, 3> a2(PointT<double, 3>{115.0 / 31.0, 98.0 / 31.0, 117.0 / 31.0}, DirectionT<double, 3>{-102.0 / 31.0, 5.0 / 31.0, 55.0 / 31.0});
		CHECK(IsEqual(a1.Mirror(f), a2));
	}}