 #include<catch.hpp>
#include<testHelper.h>
#include <common/FrameT.hpp>
#include <modeling/MakeTorus.hpp>
#include <common/AxisT.hpp>
#include <math/CircleT.hpp>
#include <occtio/OCCTTool.hpp>
#include <modeling/MakeVertex.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeWire.hpp>
#include <modeling/MakeFace.hpp>
#include <modeling/MakePrism.hpp>
#include <iostream>
using namespace AMCAX;
TEST_CASE("case1:this is a case for Test MakeTorus  ", "[modeling][MakeTorus][P1]")
{
	Frame3 frame;
	double major = 5.0;
	double minor = 3.0;
	double angle1 = 0.0;
	double angle2 = 3.1415926 * 2.0;
	AMCAX::MakeTorus torus(frame, major, minor, angle1, angle2);
	TopoShape shape = torus.Shape();
	OCCTIO::OCCTTool::Write(shape, OUTPUT_PATH_PREFIX"MakeTorus_case01.brep");
	AMCAX::GlobalProperty props;
	AMCAX::BRepGlobalProperty::VolumeProperties(shape, props);
	CHECK(props.Mass() == Approx(130.89999999999998));
	CHECK(props.MomentOfInertiaX() == Approx(297.23399999999995));
	CHECK(props.MomentOfInertiaY() == Approx(297.23399999999995));
	CHECK(props.MomentOfInertiaZ() == Approx(467.327));
}