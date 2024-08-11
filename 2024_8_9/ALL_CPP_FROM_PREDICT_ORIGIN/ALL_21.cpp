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
bool IsInDirection(const Axis<T, DIM>& result, const Axis<T, DIM>& direction)
{
	Direction<T, DIM> resultDir = result.Direction();
	Direction<T, DIM> directionDir = direction.Direction();
	Frame<T, DIM> frameResult(result.Location(), resultDir);
	if (direction.IsInPlane(frameResult))
	{
		double param = 0.0;
		if (direction.Contains(result.Location(), param))
		{
			Direction<T, DIM> resultDir2 = result.Direction();
			Direction<T, DIM> directionDir2 = direction.Direction(Direction(result.Location(), resultDir2));
			return resultDir.IsInDirection(directionDir2, tol);
		}
	}
	return false;
}
template<typename T, int DIM>
bool IsInResultVector(const Vector<T, DIM>& result, const Vector<T, DIM>& vector)
{
	if (result.IsInDirection(vector, tol))
	{
		return true;
	}
	else
	{
		return false;
	}
}
TEST_CASE("case1:this is a case for Axis3","[Common][Axis3]")
{
	int i = 1;
	SECTION("IsCoaxial"){
		AxisT<double, 3> a1(PointT<double, 3>{0.0, 0.0, 0.0}, DirectionT<double, 3>{1.0, 2.0, 3.0});
		AxisT<double, 3> a2(PointT<double, 3>{2.0, 4.0, 6.0}, DirectionT<double, 3>{1.0, 2.0, 3.0});
		AxisT<double, 3> a3(PointT<double, 3>{2.0, 4.0, 6.0}, DirectionT<double, 3>{2.0, 4.0, 6.0});
		CHECK(a1.IsCoaxial(a2, 1e-6, 1e-6) == true);
		CHECK(a1.IsCoaxial(a3, 1e-6, 1e-6) == false);
	}}