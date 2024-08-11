 #include<catch.hpp>
#include<testHelper.h>
#include <modeling/MakePyramid.hpp>
#include <hatch/BRepClassificationTools.hpp>
TEST_CASE("case1: MakePyramid(p1, p2, p3, apex)  ", "[modeling][MakePyramid][P1]")
{
    Point3 p1(0.0, 0.0, 0.0);
    Point3 p2(4.0, 0.0, 0.0);
    Point3 p3(2.0, 4.0, 0.0);
    Point3 apex(0.0, 0.0, 4.5);
    std::vector<Point3> points = { p1, p2, p3, apex };
    TopoShape shape = AMCAX::MakePyramid(p1, p2, p3, apex);
    AMCAX::GlobalProperty props;
    CHECK( GetSurfaceProperties(shape, props, true, false) == Approx( 74.2492235988));
    CHECK( GetVolumeProperties(shape, props, true, false) == 18.0);
    CHECK(shape.Type() == ShapeType::Solid);
    CHECK( AMCAX::BRepClassificationTools::IsPointInOnSolid(shape, p1) == true);
    CHECK( AMCAX::BRepClassificationTools::IsPointInOnSolid(shape, p2) == true);
    CHECK( AMCAX::BRepClassificationTools::IsPointInOnSolid(shape, p3) == true);
    CHECK( AMCAX::BRepClassificationTools::IsPointInOnSolid(shape, apex) == true);
}