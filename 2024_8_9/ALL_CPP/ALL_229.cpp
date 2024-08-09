/* "[[nodiscard]] double Area()\t @return The area of the ellipse\n\t @brief Get the area of the ellipse\n,\n",
      */
 #include <catch.hpp>
#include <testHelper.h>
#include <common/FrameT.hpp>
#include <common/TransformationT.hpp>
#include <common/VectorT.hpp>
#include <math/EllipseT.hpp>
using namespace AMCAX;
using namespace std;
TEST_CASE("case1:this is a case for Test Ellipse3", "[math][Ellipse3][P1]")
{
	Frame3 frame;
	double major = 5.0;
	double minor = 4.0;
	Ellipse3 ellipse(frame, major, minor);
	SECTION("Area")
	{
		double S = ellipse.Area();
		CHECK(S == Approx(M_PI * major * minor));
	}}