/* "AMCAX_API MakePyramid(const Point3& p1, const Point3& p2, const Point3& p3, const Point3& apex)\t @param apex Apex point\n\t @param p1,p2,p3 Points on the base plane\n\t @brief Construct a tetrahedron\n,\n",
      */
 #include<catch.hpp>
#include<testHelper.h>
#include <modeling/MakePyramid.hpp>
#include <hatch/BRepClassificationTools.hpp>
TEST_CASE("case1 MakePyramid(p1, p2, p3, apex)  ", "[modeling][MakePyramid][P1]")
{
    Point3 p1(0.0, 0.0, 0.0);
    Point3 p2(4.0, 0.0, 0.0);
    Point3 p3(2.0, 4.0, 0.0);
    Point3 apex(0.0, 0.0, 4.5);
    std::vector<Point3> points = { p1, p2, p3, apex };
    TopoShape shape = AMCAX::MakePyramid(p1, p2, p3, apex);
    AMCAX::GlobalProperty props;
    CHECK(GetSurfaceProperties(shape, props, true, false) == Approx(39.9172660309));
    CHECK(GetVolumeProperties(shape, props, true, false) == Approx(12.0));
    CHECK(shape.Type() == ShapeType::Solid);
    OCCTIO::OCCTTool::Write(shape, OUTPUT_PATH_PREFIX"MakePyramid_case01.brep");
    TopoSolid solid = AMCAX::TopoCast::Solid(shape);
    for (const Point3& p : points) {
        bool isPointOnSolid = AMCAX::BRepClassificationTools::IsPointInOnSolid(solid, p);
        CHECK(isPointOnSolid == true);
    }
}