/* "AMCAX_API MakeFace(const Cone& c, const TopoWire& w, bool inside = true)\t @param inside Whether the face is inside the wire\n\t @param w The wire\n\t @param c The cone\n\t @brief Construct from a cone and a wire\n,\n",
      */
 #include <catch.hpp>
#include "testHelper.h"
#include<iostream>
#include <common/PointT.hpp>
#include <topology/TopoEdge.hpp>
#include <modeling/MakeWire.hpp>
#include <modeling/MakeEdge2d.hpp>
#include <topology/TopoWire.hpp>
#include <topology/TopoShape.hpp>
#include <topology/TopoFace.hpp>
#include <modeling/MakeFace.hpp>
AMCAX::TopoFace crashbug1() {
    double h1 = 7., h2 = 3.;
    AMCAX::Point2 p1(0., h1 / 2.0), p2(30., h2 / 2.0), p3(30., -h2 / 2.0), p4(0., -h1 / 2.0);
    std::vector<AMCAX::Point2> v_p;
    v_p.push_back(p1);
    v_p.push_back(p2);
    v_p.push_back(p3);
    v_p.push_back(p4);
    AMCAX::TopoEdge e;
    std::list<AMCAX::TopoShape> edges_polygon;
    for (int i = 1; i < v_p.size(); i++) {
        e = AMCAX::MakeEdge2d(v_p[i - 1], v_p[i]);
        edges_polygon.push_back(e);
    }
    e = AMCAX::MakeEdge2d(v_p[3], v_p[0]);
    edges_polygon.push_back(e);
    AMCAX::MakeWire mkw;
    mkw.Add(edges_polygon);
    AMCAX::TopoWire w_poly = mkw;
    AMCAX::TopoFace f_poly = AMCAX::MakeFace(w_poly, true);
    return f_poly;
}
#include <catch.hpp>
#include "testHelper.h"
#include<iostream>
#include <common/PointT.hpp>
#include <topology/TopoEdge.hpp>
#include <modeling/MakeWire.hpp>
#include <modeling/MakeEdge2d.hpp>
#include <topology/TopoWire.hpp>
#include <topology/TopoShape.hpp>
#include <topology/TopoFace.hpp>
#include <modeling/MakeFace.hpp>
AMCAX::TopoFace crashbug1() {
    double h1 = 7., h2 = 3.;
    AMCAX::Point2 p1(0., h1 / 2.0), p2(30., h2 / 2.0), p3(30., -h2 / 2.0), p4(0., -h1 / 2.0);
    std::vector<AMCAX::Point2> v_p;
    v_p.push_back(p1);
    v_p.push_back(p2);
    v_p.push_back(p3);
    v_p.push_back(p4);
    AMCAX::TopoEdge e;
    std::list<AMCAX::TopoShape> edges_polygon;
    for (int i = 1; i < v_p.size(); i++) {
        e = AMCAX::MakeEdge2d(v_p[i - 1], v_p[i]);
        edges_polygon.push_back(e);
    }
    e = AMCAX::MakeEdge2d(v_p[3], v_p[0]);
    edges_polygon.push_back(e);
    AMCAX::MakeWire mkw;
    mkw.Add(edges_polygon);
    AMCAX::TopoWire w_poly = mkw;
    AMCAX::TopoFace f_poly = AMCAX::MakeFace(w_poly, true);
    return f_poly;
}