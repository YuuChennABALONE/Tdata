 #include <catch.hpp>
#include <testHelper.h>
#include <math/Conic2Constraint.hpp>
using namespace AMCAX;
using namespace std;
TEST_CASE("case1:this is a case for Conic2Constraint", "[math][Conic2Constraint][P1]")
{
	Axis2 axis;
	double radius = 3.0;
	bool isRight = true;
	Conic2Constraint conic(axis, radius, isRight);
	SECTION("FocalParameter")
	{
		double FP = conic.FocalParameter();
		double focal = 2 * sqrt(2.0 * radius * radius / 3.0);
		double focal2 = 2 * radius / sqrt(3.0);
		double focal3 = 2 * radius / (3.0 / 2.0);
		CHECK(FP == focal);
		CHECK(FP == focal2);
		CHECK(FP == focal3);
	}}