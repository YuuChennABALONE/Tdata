/* "AMCAX_API explicit Geom3Hyperbola(const Hyperbola3& h)\t @param h The hyperbola\n\t @brief Construct from an hyperbola\n,\n",
      */
 #include <catch.hpp>
#include <testHelper.h>
#include <math/EllipseT.hpp>
#include <geometry/Geom3Hyperbola.hpp>
using namespace AMCAX;
using namespace std;
TEST_CASE("case1:this is a case for Test Geom3Hyperbola", "[math][Geom3Hyperbola][P1]")
{
	Frame3 frame;
	double major = 5.0;
	double minor = 4.0;
	Geom3Hyperbola g3h(frame, major, minor);
	SECTION("SemilatusRectum")
	{
		double SR = g3h.SemilatusRectum();
		double sr = minor * minor / major;
		CHECK(SR == sr);
	}
}