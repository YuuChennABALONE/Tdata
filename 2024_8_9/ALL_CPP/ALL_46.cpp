/* "AMCAX_API MakePyramid(const Frame3& frame, double radius, int nside, double height)\t @param height Height of the polygon\n\t @param nside Number of sides of the base polygon\n\t @param radius Radius of the circumcircle of the base polygon\n\t @param frame The local coordinate system\n\t @brief Construct a regular pyramid\n,\n",
      */
 #include<catch.hpp>
#include<testHelper.h>
#include <modeling/MakePyramid.hpp>
#include <hatch/BRepClassificationTools.hpp>
TEST_CASE("case2: MakePyramid(p1, p2, p3, p4, apex) ", "[modeling][MakePyramid][P1]")
{ 
    Point3 p1(-2.0, 1.0, -1.0);
    Point3 p2(1.0, 3.0, 0.0);
    Point3 p3(4.0, -1.0, 1.0);
    Point3 p4(-1.0, -2.0, 0.0);
    Point3 apex(1.0, -1.0, -4.5);
    CHECK_THROWS_AS( AMCAX::MakePyramid(p1, p2, p3, p4, apex), AMCAX::_ConstructionError );
}