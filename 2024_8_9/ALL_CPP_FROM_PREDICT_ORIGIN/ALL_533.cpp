 #include<catch.hpp>
#include<testHelper.h>
#include<common/Exception.hpp>
#include <modeling/MakeRightPrism.hpp>
#include <hatch/BRepClassificationTools.hpp>
TEST_CASE("case2 MakeRightPrism(p1, p2, p3, p4, apex)  ", "[modeling][MakeRightPrism][P1]")
{
	SECTION("4 points on same line") {
        Point3 p1(-2.0, 0.0, 0.0);
        Point3 p2(0.0, 0.0, 0.0);
        Point3 p3(2.0, 0.0, 0.0);
        Point3 p4(4.0, 0.0, 0.0);
        Point3 apex(0.0, 1.0, 0.0);
        std::vector<Point3> points = { p1, p2, p3, p4 };
        CHECK_THROWS_AS(AMCAX::MakeRightPrism(p1, p2, p3, p4, apex), AMCAX::_ConstructionError);
    }}