 #include<catch.hpp>
#include<testHelper.h>
#include<geomAlgo/LawConstant.hpp>
#include<geomAlgo/LawFunction.hpp>
using namespace std;
TEST_CASE("case1: this is a test case for LawConstant", "[geomAlgo][LawFunction][P1]")
{
	LawConstant cons;
	cons.Set(2.0, 3.0, 4.0);
	SECTION("Trim")
	{
		LawFunction law;
		law.SetLawType(LawType::Power);
		law.SetDegree(2);
		law.SetLawConstant(cons);
		double fp = 0.0;
		double lp = 5.0;
		double tol = 0.1;
	shared_ptr<LawFunction> lawTrim = law.Trim(fp, lp, tol);
	CHECK(lawTrim->Degree() == 2);
	CHECK(lawTrim->FunctionType() == FunctionType::Polynomial);
	double a = lawTrim->GetA();
	double b = lawTrim->GetB();
	double c = lawTrim->GetC();
	double d = lawTrim->GetD();
	double e = lawTrim->GetE();
	CHECK(a == Approx(2.0));
	CHECK(b == Approx(-1.0));
	CHECK(c == Approx(0.0));
	CHECK(d == Approx(0.0));
	CHECK(e == Approx(0.0));
	}}