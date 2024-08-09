/* "AMCAX_API explicit Geom3Ellipse(const Ellipse3& e)\t @param e The ellipse\n\t @brief Construct from an ellipse\n,\n",
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