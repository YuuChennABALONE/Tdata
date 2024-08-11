 #include<catch.hpp>
#include<testHelper.h>
#include <modeling/MakePyramid.hpp>
#include <hatch/BRepClassificationTools.hpp>
TEST_CASE("case2: MakePyramid(p1, p2, p3, p4)  ", "[modeling][MakePyramid][P1]")
{
	SECTION("4 points")
{
    Point3 p1(-2.0, 1.0, -1.0);
    Point3 p2(1.0, 3.0, 0.0);
    Point3 p3(2.0, -1.0, 1.0);
    Point3 p4(-1.0, -2.0, 0.0);
    std::vector<Point3> points = { p1, p2, p3, p4 };
    TopoShape shape = AMCAX::MakePyramid(p1, p2, p3, p4);
    AMCAX::GlobalProperty props;
    CHECK(GetSurfaceProperties(shape, props, true, false) == Approx(46.051889));
    CHECK(GetVolumeProperties(shape, props, true, false) == Approx(16.5));
    CHECK(shape.Type() == ShapeType::Solid);
    OCCTIO::OCCTTool::Write(shape, OUTPUT_PATH_PREFIX"MakePyramid_02.brep");
    TopoSolid solid = AMCAX::TopoCast::Solid(shape);
    for (const Point3& p : points) {
        bool isPointOnSolid = AMCAX::BRepClassificationTools::IsPointInOnSolid(solid, p);
        CHECK(isPointOnSolid == true);
    }
}}