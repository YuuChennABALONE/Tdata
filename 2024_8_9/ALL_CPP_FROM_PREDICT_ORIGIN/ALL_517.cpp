 #include<catch.hpp>
#include<testHelper.h>
#include <modeling/MakePyramid.hpp>
#include <hatch/BRepClassificationTools.hpp>
TEST_CASE("case2 MakePyramid(p1, p2, p3, apex)  ", "[modeling][MakePyramid][P1]")
{
    Point3 p1(-2.0, 0.0, -2.0);
    Point3 p2(2.0, 0.0, -2.0);
    Point3 p3(0.0, 4.0, -2.0);
    Point3 apex(-1.0, 1.0, 2.0);
    std::vector<Point3> points = { p1, p2, p3, apex };
    TopoShape shape = AMCAX::MakePyramid(p1, p2, p3, apex);
    AMCAX::GlobalProperty props;
    CHECK( GetSurfaceProperties(shape, props, true, false) == Approx( 60.0 + 4.0 * sqrt(2) ).margin(0.1));
    CHECK( GetVolumeProperties(shape, props, true, false) == 40.0 );
    CHECK(shape.Type() == ShapeType::Solid);
    OCCTIO::OCCTTool::Write(shape, OUTPUT_PATH_PREFIX"MakePyramid_case02.brep");
    TopoSolid solid = AMCAX::TopoCast::Solid(shape);
    for (const Point3& p : points) {
        bool isPointOnSolid = AMCAX::BRepClassificationTools::IsPointInOnSolid(solid, p);
        CHECK(isPointOnSolid == true);
    }
}