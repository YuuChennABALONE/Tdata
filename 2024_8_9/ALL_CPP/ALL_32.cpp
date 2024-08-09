/* "AMCAX_API MakeRightPrism(const Point3& baseLocation, const std::vector<Point3>& basepoints, const Point3& apex)\t @param apex A point on the top plane\n\t @param basepoints The base points that are projected onto the base plane\n\t @param baseLocation The location of the base plane\n\t @details The base plane are determined by the location point and the first two base points\n\t @brief Construct a right prism with a given location on the base plane\n,\n",
      */
 #include<catch.hpp>
#include<testHelper.h>
#include<common/Exception.hpp>
#include <modeling/MakeRightPrism.hpp>
#include <hatch/BRepClassificationTools.hpp>
TEST_CASE("case2 MakeRightPrism(p1, p2, p3, p4, apex)  ", "[modeling][MakeRightPrism][P1]")
{
	SECTION("4 points on same line") {
        Point3 p1(-1.0, 0.0, 0.0);
        Point3 p2(0.0, 0.0, 0.0);
        Point3 p3(2.0, 0.0, 0.0);
        Point3 p4(4.0, 0.0, 0.0);
        Point3 apex(2.0, 2.0, -4.5);
        std::vector<Point3> points = { p1, p2, p3,p4 };
        CHECK_THROWS_AS(AMCAX::MakeRightPrism(p1, p2, p3, p4, apex), AMCAX::_ConstructionError);
    }
}