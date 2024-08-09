/* "AMCAX_API MakeRightPrism(const Point3& p1, const Point3& p2, const Point3& p3, const Point3& apex)\t @param apex A point on the top plane\n\t @param p1,p2,p3 Points on the base plane\n\t @brief Construct a right triangular prism\n,\n",
      */
 #include<catch.hpp>
#include<testHelper.h>
#include<common/Exception.hpp>
#include <modeling/MakeRightPrism.hpp>
#include <hatch/BRepClassificationTools.hpp>
TEST_CASE("case1 MakeRightPrism(p1, p2, p3, apex)  ", "[modeling][MakeRightPrism][P1]")
{
    Point3 p1(0.0, 0.0, 0.0);
    Point3 p2(4.0, 0.0, 0.0);
    Point3 p3(2.0, 4.0, 0.0);
    Point3 apex(0.0, 0.0, 4.5);
    std::vector<Point3> points = { p1, p2, p3, apex };
    TopoShape shape = AMCAX::MakeRightPrism(p1, p2, p3, apex);
    AMCAX::GlobalProperty props;
    CHECK( GetSurfaceProperties(shape, props, true, false) == Approx( 74.249223595));
    CHECK( GetVolumeProperties(shape, props, true, false) == 36.0);
    CHECK(shape.Type() == ShapeType::Solid);
    OCCTIO::OCCTTool::Write(shape, OUTPUT_PATH_PREFIX"MakeRightPrism_01.brep");
    TopoSolid solid = AMCAX::TopoCast::Solid(shape);
    for (const Point3& p : points) {
        bool isPointOnSolid = AMCAX::BRepClassificationTools::IsPointInOnSolid(solid, p);
        CHECK(isPointOnSolid == true);
    }
}