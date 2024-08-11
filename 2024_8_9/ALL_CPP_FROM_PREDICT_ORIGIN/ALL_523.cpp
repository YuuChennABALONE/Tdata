 #include<catch.hpp>
#include<testHelper.h>
#include <modeling/MakePyramid.hpp>
#include <hatch/BRepClassificationTools.hpp>
TEST_CASE("case2: MakePyramid(p1, p2, p3, p4, apex) ", "[modeling][MakePyramid][P1]")
{ 
    Point3 p1(-2.0, 1.0, -1.0);
    Point3 p2(1.0, 2.0, 0.0);
    Point3 p3(2.0, -1.0, 1.0);
    Point3 p4(-1.0, -2.0, 2.0);
    Point3 apex(1.0, -1.0, -2.0);
    std::vector<Point3> points = { p1, p2, p3, p4 };
    TopoShape shape = AMCAX::MakePyramid(p1, p2, p3, p4, apex);
    AMCAX::GlobalProperty props;
    CHECK( GetSurfaceProperties(shape, props, true, false) == Approx( 10.333333333333333).significant(3));
    CHECK( GetVolumeProperties(shape, props, true, false) == Approx( 3.0).significant(3));
    CHECK(shape.Type() == ShapeType::Solid);
    CHECK( AMCAX::BRepClassificationTools::IsPointInOnSolid(shape, p1) == true);
    CHECK( AMCAX::BRepClassificationTools::IsPointInOnSolid(shape, p2) == true);
    CHECK( AMCAX::BRepClassificationTools::IsPointInOnSolid(shape, p3) == true);
    CHECK( AMCAX::BRepClassificationTools::IsPointInOnSolid(shape, p4) == true);
    CHECK( AMCAX::BRepClassificationTools::IsPointInOnSolid(shape, apex) == true);
    CHECK( AMCAX::BRepClassificationTools::IsPointInOnSolid(shape, Point3(1.0, -2.5, -1.2)) == true);
    CHECK( AMCAX::BRepClassificationTools::IsPointInOnSolid(shape, Point3(1.0, -2.5, -1.1)) == true);
    CHECK( AMCAX::BRepClassificationTools::IsPointInOnSolid(shape, Point3(1.0, -2.5, -1.3)) == false);
}