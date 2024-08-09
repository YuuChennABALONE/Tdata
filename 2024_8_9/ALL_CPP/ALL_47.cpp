/* "AMCAX_API MakePyramid(const std::vector<Point3>& basepoints, const Point3& apex)\t @param apex Apex point\n\t @param basepoints Points on the base plane\n\t @brief Construct a pyramid with base points and an apex point\n,\n",
      */
 #include<catch.hpp>
#include<testHelper.h>
#include <modeling/MakePyramid.hpp>
#include <hatch/BRepClassificationTools.hpp>
TEST_CASE("case1: MakePyramid(basepoints, apex)  ", "[modeling][MakePyramid][P1]")
{
    Point3 p1(-2.0, 1.0, 0.0);
    Point3 p2(1.0, -3.0, 0.0);
    Point3 p3(-1.0, -2.5, 0.0);
    Point3 apex(5.0, 3.0, 4.5);
    std::vector<Point3> points = { p1, p2, p3};
    TopoShape shape = AMCAX::MakePyramid(points, apex);
    AMCAX::GlobalProperty props;
    CHECK(GetSurfaceProperties(shape, props, true, false) == Approx(47.6096343921));
    CHECK(GetVolumeProperties(shape, props, true, false) == Approx(4.875));
    CHECK(shape.Type() == ShapeType::Solid);
    CHECK(OCCTIO::OCCTTool::Write(shape, OUTPUT_PATH_PREFIX"MakePyramid3_case01.brep"));
    TopoSolid solid = AMCAX::TopoCast::Solid(shape);
    CHECK(AMCAX::BRepClassificationTools::IsPointInOnSolid(solid, apex));
    for (const Point3& p : points) {
        bool isPointOnSolid = AMCAX::BRepClassificationTools::IsPointInOnSolid(solid, p);
        CHECK(isPointOnSolid == true);
    }
}