/* "AMCAX_API static void AdjustPeriodic(double ufirst, double ulast, double precision, double& u1, double& u2)\t @param[in,out] u2 The second parameter to be adjust\n\t @param[in,out] u1 The first parameter to be adjust\n\t @param[in] precision The precision to check equality\n\t @param[in] ulast The upper bound of the period\n\t @param[in] ufirst The lower bound of the period\n\t          The parameter u2 is set in the range [u1, u1 + ulast - ufirst]\n\t @details The parameter u1 is set in the range [ufirst, ulast]\n\t @brief Adjust u1 and u2 to be in the period range.\n,\n",
      */
 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::AdjustPeriodic ", "[math][CurveCalculation][P1]") {
	double u1 = 0.0;
	double u2 = 2 * M_PI;
	double ufirst = 0.0;
	double ulast = 2 * M_PI; 
	double precision = 0.001; 
	AMCAX::CurveCalculation::AdjustPeriodic(ufirst, ulast, precision, u1, u2);
	CHECK(u1 == 0);
	CHECK(u2 == 2 * M_PI);
}