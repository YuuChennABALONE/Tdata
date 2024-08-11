 #include <catch.hpp>
#include <testHelper.h>
#include <common/FrameT.hpp>
#include <common/TransformationT.hpp>
#include <common/VectorT.hpp>
#include <math/CircleT.hpp>
using namespace AMCAX;
using namespace std;
TEST_CASE("case1:this is a case for Circle2", "[math][Circle2]")
{
	CircleT<double, 2> c1;
	c1.SetRadius(5.0);
	SECTION("Radius")
	{
		CHECK(c1.Radius() == Approx(5.0));
	}}