/* "AMCAX_API MakePolygon(const Point3& p1, const Point3& p2)\t @param p2 The second point\n\t @param p1 The first point\n\t @brief Construct from two points\n,\n",
      */
 #include<catch.hpp>
#include<iostream>
#include <modeling/MakePolygon.hpp>
#include <topology/TopoVertex.hpp>
#include <topology/TopoEdge.hpp>
#include <topology/TopoExplorerTool.hpp>
#include <topology/TopoShape.hpp>
#include <topology/TopoTool.hpp>
TEST_CASE("MakePolygon Invalid input points", "[modeling][MakePolygon][P3]") {
        AMCAX::Point3 p1(0.0, 0.0, 0.0);
        AMCAX::MakePolygon polygon(p1, p1);
        bool lastAdded = polygon.Added();
        CHECK(lastAdded == false);
    }