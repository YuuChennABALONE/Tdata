 #include<catch.hpp>
#include<testHelper.h>
#include <modeling/MakeTorus.hpp>
#include <common/FrameT.hpp>
#include <common/TransformationT.hpp>
#include <topology/TopoBuilder.hpp>
TEST_CASE("bug1: MakeTorus   ", "[modeling][MakeTorus][P1][fixbug]")
{
	Frame3 frame;
	double major = 3.0;
	double minor = 2.0;
	double angle1 = 0.0;
	double angle2 = M_PI_2;
	double angle = 2 * M_PI;
	TopoShape torus = AMCAX::MakeTorus(frame, major, minor, angle1, angle2, angle);
	AMCAX::GlobalProperty props;
	std::vector<double> res = AMCAX::CalculateProperties(torus, props);
	double major2 = 3 * 3;
	double minor2 = 2 * 2;
	double mass = 2 * M_PI * minor * major;
	double surfa = 2 * M_PI * major * minor2;
	double volum = (4.0 / 3.0) * M_PI * minor2 * major2;
	CHECK(res[0] == Approx(mass));
	CHECK(res[1] == Approx(volum));
	CHECK(res[2] == Approx(surfa));
	CHECK(res[3] == Approx(M_PI));
}