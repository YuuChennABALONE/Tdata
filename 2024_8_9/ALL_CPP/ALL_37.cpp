/* "AMCAX_API MakeRightPrism(const std::vector<Point3>& basepoints, const Point3& apex)\t @param apex A point on the top plane\n\t @param basepoints Points on the base plane\n\t @brief Construct a right prism with base points and a point on the top plane\n,\n",
      */
 #include<catch.hpp>
#include<testHelper.h>
#include<common/Exception.hpp>
#include <modeling/MakeRightPrism.hpp>
#include <hatch/BRepClassificationTools.hpp>
TEST_CASE("case3 MakeRightPrism(p1, p2, p3, apex)  ", "[modeling][MakeRightPrism][P1]")
{
    Point3 p1(0.0, 0.0, 0.0);
    Point3 p2(4.0, 0.0, 0.0);
    Point3 p3(2.0, 4.0, -2.0);
    Point3 apex(4.0, 0.0, -4.5);
    std::vector<Point3> points = { p1, p2, p3 };
    TopoShape shape = AMCAX::MakeRightPrism(p1, p2, p3, apex);
    AMCAX::GlobalProperty props;
    CHECK(GetSurfaceProperties(shape, props, true, false) == Approx(73.4242573984));
    CHECK(GetVolumeProperties(shape, props, true, false) == 36.0);
    CHECK(shape.Type() == ShapeType::Solid);
    OCCTIO::OCCTTool::Write(shape, OUTPUT_PATH_PREFIX"MakeRightPrism_03.brep");
    TopoSolid solid = AMCAX::TopoCast::Solid(shape);
    for (const Point3& p : points) {
        bool isPointOnSolid = AMCAX::BRepClassificationTools::IsPointInOnSolid(solid, p);
        CHECK(isPointOnSolid == true);
    }
    Point3 p4(2.0, 2.2, -5.6);
    bool isPointOnSolid = AMCAX::BRepClassificationTools::IsPointInOnSolid(solid, p4);
    CHECK(isPointOnSolid == true);
}