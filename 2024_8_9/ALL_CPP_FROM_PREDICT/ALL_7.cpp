 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
using namespace AMCAX;
TEST_CASE("case1: CurveCalculation::TorusDN 1/2 ", "[math][CurveCalculation][P1][TorusDN]") {
	Direction3 initialDir(0.0, 0.0, 1.0);
	Frame3 defaultFrame3(Point3(1.0, 1.0, 0.0), initialDir);
	double majorRadius = 2.0;
	double minorRadius = 1.0;
	int nu = 12;
	int nv = 8;
	Vector3 tangentAt0u0v = CurveCalculation::TorusDN(0.0, 0.0, defaultFrame3, majorRadius, minorRadius, nu, nv);
	Vector3 tangentAt0uPiOver2v = CurveCalculation::TorusDN(0.0, M_PI_2, defaultFrame3, majorRadius, minorRadius, nu, nv);
	Vector3 tangentAtPiOver2u0v = CurveCalculation::TorusDN(M_PI_2, 0.0, defaultFrame3, majorRadius, minorRadius, nu, nv);
	Vector3 tangentAtPiOver2uPiOver2v = CurveCalculation::TorusDN(M_PI_2, M_PI_2, defaultFrame3, majorRadius, minorRadius, nu, nv);
	Vector3 tangentAtPiu0v = CurveCalculation::TorusDN(M_PI, 0.0, defaultFrame3, majorRadius, minorRadius, nu, nv);
	Vector3 tangentAtPiv0v = CurveCalculation::TorusDN(0.0, M_PI, defaultFrame3, majorRadius, minorRadius, nu, nv);
	Vector3 tangentAtPiuPiOver2v = CurveCalculation::TorusDN(M_PI, M_PI_2, defaultFrame3, majorRadius, minorRadius, nu, nv);
	Vector3 tangentAtPivPiOver2v = CurveCalculation::TorusDN(M_PI, M_PI_2, defaultFrame3, majorRadius, minorRadius, nu, nv);
	Vector3 tangentAt2Pu2Piv = CurveCalculation::TorusDN(2.0 * M_PI, 2.0 * M_PI, defaultFrame3, majorRadius, minorRadius, nu, nv);
	std::cout << tangentAt0u0v.X() << std::endl;
	std::cout << tangentAt0uPiOver2v.X() << std::endl;
	std::cout << tangentAtPiOver2u0v.X() << std::endl;
	std::cout << tangentAtPiOver2uPiOver2v.X() << std::endl;
	std::cout << tangentAtPiu0v.X() << std::endl;
	std::cout << tangentAtPiv0v.X() << std::endl;
	std::cout << tangentAtPiuPiOver2v.X() << std::endl;
	std::cout << tangentAtPivPiOver2v.X() << std::endl;
	std::cout << tangentAt2Pu2Piv.X() << std::endl;
}