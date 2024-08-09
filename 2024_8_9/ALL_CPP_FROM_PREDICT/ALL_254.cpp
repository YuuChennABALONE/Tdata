 #include <catch.hpp>
#include <testHelper.h>
#include <common/FrameT.hpp>
#include <common/TransformationT.hpp>
#include <modeling/MakeFace.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeVertex.hpp>
#include <modeling/MakeTorus.hpp>
#include <common/AxisT.hpp>
#include <math/TriangularMesh.hpp>
#include <common/VectorT.hpp>
#include <occtio/OCCTTool.hpp>
#include <modeling/MakePrism.hpp>
#include <hatch/BRepClassificationTools.hpp>
#include <topology/TopoTool.hpp>
#include <topology/TopoFace.hpp>
#include <common/DirectionT.hpp>
#include <modeling/MakeCutting.hpp>
#include <modeling/TransformShape.hpp>
#include <iostream>
using namespace AMCAX;
using namespace std;
TEST_CASE("case1:this is a case for MakeTorus", "[MakeTorus][P1]") {
	Point3 point3(0.0, 0.0, 1.0);
	Direction3 dir3(0.0, 0.0, 1.0);
	Frame3 fram3(point3, dir3);
	double r1 = 3.0, r2 = 2.0;
	AMCAX::Torus torus(fram3, r1, r2);
	MakeTorus torus1(0.0, 0.0, 1.0, 3.0, 2.0);
	SECTION("Volume") {
		double volume = torus.Volume();
		double volume1 = torus1.Volume();
		CHECK(volume == Approx(volume1));
	}}