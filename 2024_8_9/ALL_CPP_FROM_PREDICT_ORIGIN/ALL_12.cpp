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
bool IsInDirection(const Axis<T, DIM>& result, const Axis<T, DIM>& expected) {
	Direction<T, DIM> dir1 = result.Direction();
	Direction<T, DIM> dir2 = expected.Direction();
	Frame<T, DIM> frame1(result.Location());
	Frame<T, DIM> frame2(expected.Location());
	double dot = dir1.Dot(dir2);
	double mag1 = dir1.Magnitude();
	double mag2 = dir2.Magnitude();
	if (std::fabs(dot - 1.0) <= tol && mag1 <= tol && mag2 <= tol) {
		return true;
	}
	else {
		return false;
	}
}
template<typename T, int DIM>
bool IsInVector(const Axis<T, DIM>& result, const Axis<T, DIM>& expected) {
	Vector<T, DIM> vector1 = result.Direction();
	Vector<T, DIM> vector2 = expected.Direction();
	Direction<T, DIM> direction1 = result.Direction();
	Direction<T, DIM> direction2 = expected.Direction();
	Frame<T, DIM> frame1(result.Location());
	Frame<T, DIM> frame2(expected.Location());
	double dot = vector1.Dot(vector2);
	double mag1 = vector1.Magnitude();
	double mag2 = vector2.Magnitude();
	if (std::fabs(dot - 1.0) <= tol && mag1 <= tol && mag2 <= tol) {
		return true;
	}
	else if (std::fabs(dot - 1.0) <= tol && mag1 <= tol && mag2 <= tol) {
		return true;
	}
	else {
		return false;
	}
}
template<typename T, int DIM>
bool IsInFrame(const Axis<T, DIM>& result, const Axis<T, DIM>& expected) {
	Direction<T, DIM> dir1 = result.Direction();
	Direction<T, DIM> dir2 = expected.Direction();
	Frame<T, DIM> frame1(result.Location());
	Frame<T, DIM> frame2(expected.Location());
	double dot = dir1.Dot(dir2);
	double mag1 = dir1.Magnitude();
	double mag2 = dir2.Magnitude();
	if (std::fabs(dot - 1.0) <= tol && mag1 <= tol && mag2 <= tol) {
		return true;
	}
	else {
		return false;
	}
}
TEST_CASE("case1:this is a case for Axis3","[Common][Axis3]")
{
	SECTION("IsCoaxial 3D"){
		AxisT<double, 3> a1(PointT<double, 3>{0.0, 0.0, 0.0}, DirectionT<double, 3>{1.0, 2.0, 3.0});
		AxisT<double, 3> a2(PointT<double, 3>{2.0, 4.0, 6.0}, DirectionT<double, 3>{1.0, 2.0, 3.0});
		AxisT<double, 3> a3(PointT<double, 3>{2.0, 4.0, 6.0}, DirectionT<double, 3>{2.0, 4.0, 6.0});
		AxisT<double, 3> a4(PointT<double, 3>{1.0, 2.0, 3.0}, DirectionT<double, 3>{1.0, 2.0, 3.0});
		CHECK(a1.IsCoaxial(a2, 1e-6, 1e-6) == true);
		CHECK(a1.IsCoaxial(a3, 1e-6, 1e-6) == false);
		CHECK(a1.IsCoaxial(a4, 1e-6, 1e-6) == false);
	}}