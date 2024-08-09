 #include<catch.hpp>
#include<testHelper.h>
#include <modeling/MakeSphere.hpp>
#include <hatch/BRepClassificationTools.hpp>
#include <topology/TopoFace.hpp>
#include <topology/TopoTool.hpp>
#include <modeling/TransformShape.hpp>
#include <modeling/MakeCylinder.hpp>
#include <boolean/BoolBRepFuse.hpp>
using namespace AMCAX;
TEST_CASE("case1: MakeSphere(sphere,radius) 1 of 3 ", "[modeling][MakeSphere][P1]") {
	TopoShape s1 = MakeSphere(1.0, 1.0, 2.0, 1.0, 1.0);
	TopoShape s2 = MakeSphere(2.0);
	CHECK(OCCTIO::OCCTTool::Write(s1, OUTPUT_PATH_PREFIX"MakeSphere01.brep"));
	TopoShape s3 = MakeSphere(2.0, 1.0);
	CHECK(OCCTIO::OCCTTool::Write(s3, OUTPUT_PATH_PREFIX"MakeSphere02.brep"));
	TopoShape s4 = MakeSphere(2.0, 1.0, 0.0, 0.0, 0.0);
	CHECK(OCCTIO::OCCTTool::Write(s4, OUTPUT_PATH_PREFIX"MakeSphere03.brep"));
	TopoShape s5 = MakeSphere(2.0, 1.0, 0.0, 0.0, 1.0);
	CHECK(OCCTIO::OCCTTool::Write(s5, OUTPUT_PATH_PREFIX"MakeSphere04.brep"));
	TopoShape s6 = MakeSphere(2.0, 1.0, 0.0, 1.0, 0.0);
	CHECK(OCCTIO::OCCTTool::Write(s6, OUTPUT_PATH_PREFIX"MakeSphere05.brep"));
	TopoShape s7 = MakeSphere(2.0, 1.0, 0.0, 1.0, 1.0);
	CHECK(OCCTIO::OCCTTool::Write(s7, OUTPUT_PATH_PREFIX"MakeSphere06.brep"));
}