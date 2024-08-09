/* "AMCAX_API MakeTorus(const Frame3& frame, double r1, double r2, double angle1, double angle2)\t @param angle2 The end angle\n\t @param angle1 The start angle\n\t @param r2 The minor radius\n\t @param r1 The major radius\n\t @param frame The local coordinate system\n\t @brief Construct from a local coordinate system, a major radius, a minor radius and two angles that forms an arc of the section circle\n,\n",
      */
 #include<catch.hpp>
#include<testHelper.h>
#include <modeling/MakeTorus.hpp>
#include <common/CartesianCoordinateSystem.hpp>
#include <topology/TopoBuilder.hpp>
TEST_CASE("bug1: MakeTorus   ", "[modeling][MakeTorus][P1][fixbug]")
{
	std::vector<TopoShape> shapes;
	constexpr double major = 3.0;
	constexpr double minor = 1.0;
	auto addshape = [&](double angle1, double angle2, double angle)
	{
		Frame3 frame(Point3(0.0, 0.0, static_cast<double>(shapes.size()) * 3.0), CartesianCoordinateSystem::DZ());
		shapes.push_back(MakeTorus(frame, major, minor, angle1, angle2, angle));
	};
	addshape(0.0, 2.0 * M_PI, 2.0 * M_PI);
	addshape(0.0, 2.0 * M_PI, M_PI_2);
	addshape(0.0, M_PI, 2.0 * M_PI);
	addshape(M_PI_2, 3.0 * M_PI_2, 2.0 * M_PI);
	addshape(M_PI, 2.0 * M_PI, 2.0 * M_PI);
	addshape(-M_PI_2, M_PI_2, 2.0 * M_PI);
	addshape(M_PI_4, M_PI_4 * 3, 2.0 * M_PI);
	addshape(M_PI_4 * 3, M_PI_4 * 5, 2.0 * M_PI);
	addshape(M_PI_4 * 5, M_PI_4 * 7, 2.0 * M_PI);
	addshape(-M_PI_4, M_PI_4, 2.0 * M_PI);
	addshape(0.0, M_PI_2, M_PI_2);
	TopoShape result;
	TopoBuilder b;
	b.MakeCompound(TopoCast::Compound(result));
	for (const auto& s : shapes)
	{
		b.Add(result, s);
	}
	CHECK( OCCTIO::OCCTTool::Write(result, OUTPUT_PATH_PREFIX"MakeTorus_bug445.brep"));
	AMCAX::GlobalProperty props1, props2;
	CHECK(GetSurfaceProperties(result, props1, true, false) == Approx(831.9798765859));
	CHECK(GetVolumeProperties(result, props2, true, false) == Approx(255.8996));
}