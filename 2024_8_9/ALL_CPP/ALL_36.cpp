/* "AMCAX_API MakeRightPrism(const Frame3& frame, double radius, int nside, double height)\t @param height Height of the polygon\n\t @param nside Number of sides of the base polygon\n\t @param radius Radius of the circumcircle of the base polygon\n\t @param frame The local coordinate system\n\t @brief Construct a right regular prism\n,\n",
      */
 #include<catch.hpp>
#include<testHelper.h>
#include<common/Exception.hpp>
#include <modeling/MakeRightPrism.hpp>
#include <hatch/BRepClassificationTools.hpp>
TEST_CASE("bug:case5 MakeRightPrism(p1, p2, p3, apex)  ", "[modeling][MakeRightPrism][P1][fixbug]")
{
    Point3 p1(0.0, 0.0, 0.0);
    Point3 p2(4.0, 0.0, 0.0);
    Point3 p3(6.0, 0.0, 0.0);
    Point3 apex(2.0, 2.0, -4.5);
    std::vector<Point3> points = { p1, p2, p3, apex };
    CHECK_THROWS_AS(AMCAX::MakeRightPrism(p1, p2, p3, apex), AMCAX::_ConstructionError);
}