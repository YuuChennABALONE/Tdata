/* "template<typename OtherScalar, typename OtherScalar2, int DIM2 = DIM, typename = typename std::enable_if_t<DIM2 == 3>> AxisT& Rotate(const AxisT<OtherScalar, DIM>& axis, const OtherScalar2& angle),\n",
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
	SECTION("Rotate 3D"){
		AxisT<double, 3> a1(PointT<double, 3>{1.0, 2.0, 3.0}, DirectionT<double, 3>{1.0, 2.0, 3.0});
		AxisT<double, 3> a2(PointT<double, 3>{2.0, 3.0, 4.0}, DirectionT<double, 3>{1.0, 1.0, 2.0});
		AxisT<double, 3> a3(PointT<double, 3>{(8.0 + std::sqrt(6.0)) / 6.0, (14.0 - std::sqrt(6.0)) / 6.0, 8.0 / 3.0}, DirectionT<double, 3>{(9.0 - std::sqrt(6.0)) / 6.0, (9.0 - std::sqrt(6.0)) / 6.0, 3.0 + 1.0 / std::sqrt(6.0)});
		CHECK(IsEqual(a1.Rotated(a2, M_PI_2), a3));
	}}