 #include <catch.hpp>
#include <testHelper.h>
#include <common/FrameT.hpp>
#include <common/TransformationT.hpp>
#include <common/VectorT.hpp>
#include <math/CylinderT.hpp>
using namespace AMCAX;
using namespace std;
TEST_CASE("case1:this is a case for Cylinder3", "[math][Cylinder3]") {
	SECTION("inputCylinder") {
        CylinderT<double, 3> cylinder1;
        cylinder1.SetFrame(FrameT<double, 3>(VectorT<double, 3>(0.0, 0.0, 0.0), DirectionT<double, 3>(0.0, 0.0, 1.0)));
        cylinder1.SetRadius(5.0);
        CylinderT<double, 3> cylinder2;
        CHECK(cylinder1.Radius() == Approx(5.0));
        CHECK(cylinder1.Location().IsEqual(cylinder2.Location(), 1e-5));
        CHECK(cylinder1.Direction().IsEqual(cylinder2.Direction(), 1e-5));
        CHECK(cylinder1.Radius() == 5.0);
    }}