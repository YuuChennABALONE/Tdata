/* "AMCAX_API virtual void D1(double x, double& f, double& d)\t @param[out] d The function first derivative\n\t @param[out] f The function value\n\t @param[in] x The given parameter\n\t @brief Get the function first derivative at the given parameter\n,\n",
      */
 #include<catch.hpp>
#include<testHelper.h>
#include<geomAlgo/LawConstant.hpp>
#include<geomAlgo/LawFunction.hpp>
using namespace std;
TEST_CASE("case1: this is a test case for LawConstant", "[geomAlgo][LawFunction][P1]")
{
	LawConstant cons;
	cons.Set(2.0, 4.0, 10.0);
	SECTION("D1")
	{
		double x = 1.0;
		double f = 0.0; 
		double d = 0.0;
		cons.D1(x, f, d);
		CHECK(f == Approx(2.0));
		CHECK(d == Approx(0.0));
	}}