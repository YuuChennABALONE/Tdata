 #include<catch.hpp>
#include<testHelper.h>
#include <modeling/MakeTorus.hpp>
#include <common/FrameT.hpp>
#include <math/CartesianCoordinateSystem.hpp>
#include <common/AxisT.hpp>
#include <common/PointT.hpp>
#include <common/TransformationT.hpp>
#include <common/VectorT.hpp>
#include <hatch/BRepClassificationTools.hpp>
#include <topology/TopoEdge.hpp>
#include <modeling/MakeEdge2d.hpp>
#include <modeling/TransformShape.hpp>
#include <common/DirectionT.hpp>
#include <common/TransformationT.hpp>
TEST_CASE("bug1: MakeTorus   ", "[modeling][MakeTorus][P1][fixbug]")
{
	SECTION("280")
    {
        Point3 point1(0.0, 0.0, 0.0);
        Direction3 dir1(0.0, 0.0, 1.0);
        Frame3 fram3(point1, dir1);
        double major = 3.0, minor = 2.0;
        double angle1 = 0.0, angle2 = 2 * M_PI, angle = 2 * M_PI;
        TopoShape torus = MakeTorus(fram3, major, minor, angle1, angle2, angle);
        CHECK(TopoAbs::Type(BRepClassification::IsPointInOnShape(torus, point3toPoint5(0.0, 0.0, 0.0))), "3.0");
        Point3 point2(1.5, 0.0, 0.0);
        CHECK(angle1 == 0.0);
        CHECK(angle2 == 2 * M_PI);
        CHECK(angle == 2 * M_PI);
        CHECK(TopoAbs::Type(BRepClassification::IsPointInOnShape(torus, point3toPoint5(1.5, 0.0, 0.0))), "3.0");
        CHECK(Topo::Edge torusEdge = MakeEdge2d(Frame2(Point2(0.0, 0.0), Direction2(1.0, 0.0)), Frame2(Point2(1.5, 0.0), Direction2(1.0, 0.0)));
        TopoEdge toroEdge1 = MakeEdge2d(Frame2(Point2(0.0, 0.0), Direction2(1.0, 0.0)), Frame2(Point2(1.5, 0.0), Direction2(1.0, 0.0)));
        TopoEdge toroEdge2 = MakeEdge2d(Frame2(Point2(0.0, 0.0), Direction2(1.0, 0.0)), Frame2(Point2(1.5, 0.0), Direction2(1.0, 0.0)));
        TopoEdge toroEdge3 = MakeEdge2d(Frame2(Point2(0.0, 0.0), Direction2(1.0, 0.0)), Frame2(Point2(1.5, 0.0), Direction2(1.0, 0.0)));
        TopoEdge toroEdge4 = MakeEdge2d(Frame2(Point2(0.0, 0.0), Direction2(1.0, 0.0)), Frame2(Point2(1.5, 0.0), Direction2(1.0, 0.0)));
        CHECK(TransformShape(torusEdge, Transformation3(Point3(0.0, 0.0, 2.0), Direction3(0.0, 0.0, 1.0))));
        CHECK(TransformShape(toroEdge1, Transformation3(Point3(0.0, 0.0, 2.0), Direction3(0.0, 0.0, 1.0))));
        CHECK(TransformShape(toroEdge2, Transformation3(Point3(0.0, 0.0, 2.0), Direction3(0.0, 0.0, 1.0))));
        CHECK(TransformShape(toroEdge3, Transformation3(Point3(0.0, 0.0, 2.0), Direction3(0.0, 0.0, 1.0))));
        CHECK(TransformShape(toroEdge4, Transformation3(Point3(0.0, 0.0, 2.0), Direction3(0.0, 0.0, 1.0))));
        TopoEdge torusEdge1 = MakeEdge2d(Frame2(Point2(0.0, 0.0), Direction2(1.0, 0.0)), Frame2(Point2(1.5, 0.0),"}