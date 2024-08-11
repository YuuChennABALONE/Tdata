 #include<catch.hpp>
#include<testHelper.h>
#include <modeling/MakeFace.hpp>
#include <geometry/Geom3BSplineSurface.hpp>
#include <topology/TopoFace.hpp>
#include <topology/TopoTool.hpp>
using namespace AMCAX;
TEST_CASE("bug1: Geom3BSplineSurface ", "[geometry][Geom3BSplineSurface][fixbug]")
{
    Array2<Point3> poles;
    poles(0, 0) = Point3(0.0, 0.0, 0.0);
    poles(1, 0) = Point3(1.0, 0.0, 0.0);
    poles(2, 0) = Point3(2.0, 0.0, 0.0);
    poles(3, 0) = Point3(3.0, 0.0, 0.0);
    poles(4, 0) = Point3(4.0, 0.0, 0.0);
    poles(5, 0) = Point3(5.0, 0.0, 0.0);
    poles(6, 0) = Point3(6.0, 0.0, 0.0);
    poles(7, 0) = Point3(7.0, 0.0, 0.0);
    poles(8, 0) = Point3(8.0, 0.0, 0.0);
    poles(9, 0) = Point3(9.0, 0.0, 0.0);
    poles(10, 0) = Point3(10.0, 0.0, 0.0);
    poles(11, 0) = Point3(11.0, 0.0, 0.0);
    poles(12, 0) = Point3(12.0, 0.0, 0.0);
    poles(13, 0) = Point3(13.0, 0.0, 0.0);
    poles(14, 0) = Point3(14.0, 0.0, 0.0);
    poles(15, 0) = Point3(15.0, 0.0, 0.0);
    poles(16, 0) = Point3(16.0, 0.0, 0.0);
    poles(17, 0) = Point3(17.0, 0.0, 0.0);
    poles(18, 0) = Point3(18.0, 0.0, 0.0);
    poles(19, 0) = Point3(19.0, 0.0, 0.0);
    poles(20, 0) = Point3(20.0, 0.0, 0.0);
    poles(21, 0) = Point3(21.0, 0.0, 0.0);
    poles(22, 0) = Point3(22.0, 0.0, 0.0);
    poles(23, 0) = Point3(23.0, 0.0, 0.0);
    poles(24, 0) = Point3(24.0, 0.0, 0.0);
    poles(25, 0) = Point3(25.0, 0.0, 0.0);
    poles(26, 0) = Point3(26.0, 0.0, 0.0);
    poles(27, 0) = Point3(27.0, 0.0, 0.0);
    poles(28, 0) = Point3(28.0, 0.0, 0.0);
    poles(29, 0) = Point3(29.0, 0.0, 0.0);
    poles(30, 0) = Point3(30.0, 0.0, 0.0);
    poles(31, 0) = Point3(31.0, 0.0, 0.0);
    poles(32, 0) = Point3(32.0, 0.0, 0.0);
    poles(33, 0) = Point3(33.0, 0.0, 0.0);
    poles"}