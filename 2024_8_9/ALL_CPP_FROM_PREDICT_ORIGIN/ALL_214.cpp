 #include<catch.hpp>
#include<testHelper.h>
#include<geomAlgo/LawConstant.hpp>
#include<geomAlgo/LawFunction.hpp>
using namespace std;
TEST_CASE("case1: this is a test case for LawConstant", "[geomAlgo][LawConstant][P1]")
{
	LawConstant cons;
	cons.Set(2.0, 4.0, 3.0);
	SECTION("D1")
	{
		double x = 1.0;
		double f = 0.0;
		double d = 0.0;
		cons.D1(x, f, d);
		CHECK(f == Approx(2.0));
		CHECK(d == Approx(0.0));
	}}