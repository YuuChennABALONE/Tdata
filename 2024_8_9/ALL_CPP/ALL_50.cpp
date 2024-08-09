/* "AMCAX_API void Add(const Point3& p)\t @param p The point\n\t @brief Add a new point to the polygon\n,\n",
      */
 #include<catch.hpp>
#include<iostream>
#include <modeling/MakePolygon.hpp>
#include <topology/TopoVertex.hpp>
#include <topology/TopoEdge.hpp>
#include <topology/TopoExplorerTool.hpp>
#include <topology/TopoShape.hpp>
#include <topology/TopoTool.hpp>
TEST_CASE("void AMCAX::MakePolygon::Add(const Point3 & p) - case1 add valid 3D point", "[modeling][MakePolygon][P1]") {
        AMCAX::Point3 p1(1.0, 2.0, 3.0);
        AMCAX::Point3 p2(4.1, 5.1, 6.1);
        AMCAX::MakePolygon polygon(p1, p2);
        bool lastAdded1 = polygon.Added();
        CHECK(lastAdded1 == true);
        const AMCAX::TopoEdge &lastEdge = polygon.Edge();
        CHECK(lastEdge.IsNull() == false);
        CHECK(lastEdge.NChildren() == 2);
        CHECK(lastEdge.Type() == AMCAX::ShapeType::Edge);
        AMCAX::TopoVertex v1,v2;
        AMCAX::TopoExplorerTool::Vertices(lastEdge, v1, v2,false);
        CHECK_FALSE(v1.IsNull());
        CHECK_FALSE(v2.IsNull());
        CHECK(v1.Type() == AMCAX::ShapeType::Vertex);
        CHECK(v2.Type() == AMCAX::ShapeType::Vertex);
        AMCAX::Point3 vpoint1;
        vpoint1 = AMCAX::TopoTool::Point(v1);
        CHECK(vpoint1.X() == 1.0);
        CHECK(vpoint1.Y() == 2.0);
        CHECK(vpoint1.Z() == 3.0);
        AMCAX::Point3 p3(4.1, 5.1, 6.1);
        polygon.Add(p3);
        bool lastAdded2 = polygon.Added();
        CHECK(lastAdded2 == false);
        AMCAX::Point3 p4(7.0, 8.0, 9.0);
        polygon.Add(p4);
        bool lastAdded3 = polygon.Added();
        CHECK(lastAdded3 == true);
}