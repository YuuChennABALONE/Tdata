 #include <catch.hpp>
#include <testHelper.h>
#include <common/FrameT.hpp>
#include <common/TransformationT.hpp>
#include <common/VectorT.hpp>
#include <math/CircleT.hpp>
using namespace AMCAX;
using namespace std;
TEST_CASE("case1:this is a case for Circle3", "[math][Circle3]") {
	SECTION("Length") {
        AMCAX::Circle3 circle3;
        double length = circle3.Length();
        double radius = circle3.Radius();
        double area = circle3.Area();
        CHECK(length == 2 * M_PI * radius);
        CHECK(length == 2 * M_PI * std::sqrt(2 * area / M_PI));
    }}