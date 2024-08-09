/* "AMCAX_API virtual std::shared_ptr<LawFunction> Trim(double fp, double lp, double tol)\t @return The new law\n\t @param tol The given tolerance, not all laws use this parameter\n\t @param lp The second parameter\n\t @param fp The first parameter\n\t @brief Get the trimmed law of this\n,\n",
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
	SECTION("Trim")
	{
		shared_ptr<LawFunction>tr;
		double fp = 1.0;
		double lp = 5.0;
		double tol = 0.1;
		double fp1 = 0.0;
		double lp1 = 0.0;
		tr = cons.Trim(fp, lp, tol);
		tr->Bounds(fp1, lp1);
		CHECK(fp1 == fp);
		CHECK(lp1 == lp);
	}}