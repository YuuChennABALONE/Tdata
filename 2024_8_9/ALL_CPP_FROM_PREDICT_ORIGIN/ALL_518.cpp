 #include<catch.hpp>
#include<testHelper.h>
#include <modeling/MakePyramid.hpp>
#include <hatch/BRepClassificationTools.hpp>
TEST_CASE("case1: MakePyramid(basepoints, apex)  ", "[modeling][MakePyramid][P1]")
{
    Point3 p1(-2.0, 1.0, 0.0);
    Point3 p2(1.0, -2.0, 0.0);
    Point3 p3(-1.0, -1.0, 2.0);
    Point3 apex(1.0, 0.0, 4.5);
    std::vector<Point3> points = { p1, p2, p3 };
    TopoShape shape = AMCAX::MakePyramid(points, apex);
    AMCAX::GlobalProperty props;
    CHECK(GetSurfaceProperties(shape, props, true, false) == Approx(47.6092969357));
    CHECK(GetVolumeProperties(shape, props, true, false) == Approx(3.0833333333));
    CHECK(shape.Type() == ShapeType::Solid);
    CHECK(OCCTIO::OCCTTool::Write(shape, OUTPUT_PATH_PREFIX"MakePyramid3_case01.brep"));
    TopoSolid solid = AMCAX::TopoCast::Solid(shape);
    CHECK(AMCAX::BRepClassificationTools::IsPointInOnSolid(solid, apex));
    for (const Point3& p : points) {
        bool isPointOnSolid = AMCAX::BRepClassificationTools::IsPointInOnSolid(solid, p);
        CHECK(isPointOnSolid == true);
    }
}