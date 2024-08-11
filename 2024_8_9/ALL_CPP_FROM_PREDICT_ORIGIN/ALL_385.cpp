 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/Classifier2d.hpp>
using namespace AMCAX;
TEST_CASE("case1: Classifier2d ", "[math][Classifier2d][P1]") {
	TopoShape shape = ReadBRep(FIXTURE_PATH_PREFIX"/testMesh/Ship.brep");
	CHECK(shape.Type() == ShapeType::Solid);
	OCCTIO::OCCTTool::Read(shape, FIXTURE_PATH_PREFIX"/testMesh/Ship.brep");
	auto solids = AMCAX::TopoTool::Explode(shape);
	auto triShape = AMCAX::TopoTool::FirstShape(std::move(solids));
	auto tri = AMCAX::TopoTool::ToTriangle(triShape);
	auto points = AMCAX::GlobalProperty::PointsOnSurface(triShape, 500);
	Classifier2d classifier2d(points, 0.0, 0.0, 1.0, 1.0);
	SECTION("IsInOnBoundary()") {
		CHECK(classifier2d.IsInOnBoundary(points[0], 1e-5) == true);
		CHECK(classifier2d.IsInOnBoundary(points[1], 1e-5) == true);
		CHECK(classifier2d.IsInOnBoundary(points[2], 1e-5) == true);
		CHECK(classifier2d.IsInOnBoundary(points[3], 1e-5) == true);
	}}