/* "AMCAX_API Geom3Ellipse(const Frame3& frame, double major, double minor)\t @param minor The minor radius\n\t @param major The major radius\n\t @param frame The local frame\n\t @brief Construct from a local frame, a major radius and a minor radius\n,\n",
      */
 #include <catch.hpp>
#include <testHelper.h>
#include <common/FrameT.hpp>
#include <math/EllipseT.hpp>
#include <geometry/Geom3Ellipse.hpp>
using namespace AMCAX;
using namespace std;
TEST_CASE("case1:this is a case for Test Geom3Ellipse", "[math][Geom3Ellipse][P1]")
{
	Frame3 frame;
	double major = 5.0;
	double minor = 4.0;
	Ellipse3 ellipse(frame, major, minor);
	Geom3Ellipse g3e(ellipse);
	SECTION("FocalParameter")
	{
		double FP = g3e.FocalParameter();
		double focal = 2 * sqrt(major * major - minor * minor);
		double fp = 2 * minor * minor / focal;;
		CHECK(FP == fp);
	}}