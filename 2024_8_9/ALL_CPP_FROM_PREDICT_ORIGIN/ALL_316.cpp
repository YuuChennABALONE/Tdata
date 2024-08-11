 #include<catch.hpp>
#include<testHelper.h>
#include <hatch/BRepClassificationTools.hpp>
#include <common/PointT.hpp>
#include <topology/TopoVertex.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeWire.hpp>
#include <modeling/MakeFace.hpp>
#include <modeling/MakePrism.hpp>
#include <modeling/MakeEdge2d.hpp>
using namespace AMCAX;
TEST_CASE("bug1: BRepClassificationTools::IsPointInOnEdge2 1/4 ", "[hatch][BRepClassificationTools][fixbug][P1]") {
	Point2 p(0.0, 0.0);
	Point2 p2(0.0, 0.0);
	std::vector<Point2> points = { p,p2 };
	std::vector<Point2> points1 = { p };
	TopoVertex v1(p);
	TopoVertex v2(p2);
	TopoVertex v3(p);
	MakeEdge e1(v1);
	MakeEdge e2(v2);
	MakeEdge2d e3(v3, 0.0, 0.0, 1.0, 1.0);
	MakeWire w1(e1);
	MakeWire w2(e2);
	MakeWire w3(e3);
	TopoEdge e31(e3);
	TopoEdge e32(e3);
	TopoEdge2d e33(e3);
	TopoShape wire3(w3);
	TopoEdge edge1(e31);
	TopoEdge edge2(e32);
	TopoEdge2d edge3(e33);
	TopoWire wire1(w1);
	TopoWire wire2(w2);
	TopoWire wire3(w3);
	TopoShape shape1(edge1);
	TopoShape shape2(edge2);
	TopoShape shape3(edge3);
	TopoShape shape4(wire1);
	TopoShape shape5(wire2);
	TopoShape shape6(wire3);
	TopoShape shape7(shape1);
	TopoShape shape8(shape2);
	TopoShape shape9(shape3);
	TopoShape shape10(shape4);
	TopoShape shape11(shape5);
	TopoShape shape12(shape6);
	TopoShape shape13(shape7);
	TopoShape shape14(shape8);
	TopoShape shape15(shape9);
	TopoShape shape16(shape10);
	TopoShape shape17(shape11);
	TopoShape shape18(shape12);
	TopoShape shape19(shape13);
	TopoShape shape20(shape14);
	TopoShape shape21(shape15);
	TopoShape shape22(shape16);
	TopoShape shape23(shape17);
	TopoShape shape24(shape18);
	TopoShape shape25(shape19);
	TopoShape shape26(shape20);
	TopoShape shape27(shape21);
	TopoShape shape28(shape22);
	TopoShape shape29(shape23);
	TopoShape shape30(shape24);
	TopoShape shape31(shape25);
	TopoShape shape32(shape26);
	TopoShape shape33(shape27);
	TopoShape shape34(shape28);
	TopoShape shape35(shape29);
	TopoShape shape36(shape30);
	TopoShape shape37(shape31);
	TopoShape shape38(shape32);
	TopoShape shape39(shape33);
	TopoShape shape40(shape34);
	TopoShape shape41(shape35);
	TopoShape shape42(shape36);
	TopoShape shape43(shape37);
	TopoShape shape44(shape38);
	TopoShape shape45(shape39);
	TopoShape shape46(shape40);
	TopoShape shape47(shape41);
	TopoShape shape48(shape42);
	TopoShape shape49(shape43);
	TopoShape shape50(shape44);
	TopoShape shape51(shape45);
	TopoShape shape52(shape46);
	TopoShape shape53(shape47);
	TopoShape shape54(shape48);
	TopoShape shape55(shape49);
	TopoShape shape56(shape50);
	TopoShape shape57(shape51);
	TopoShape shape58(shape52);
	TopoShape shape59(shape53);
	TopoShape shape60(shape54);
	TopoShape shape61(shape"}