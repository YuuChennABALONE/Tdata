 #include<catch.hpp>
#include<testHelper.h>
#include <modeling/MakePrism.hpp>
#include <modeling/TransformShape.hpp>
#include <topology/TopoExplorer.hpp>
#include <topology/TopoFace.hpp>
#include <hatch/BRepClassificationTools.hpp>
#include <topology/TopoEdge.hpp>
#include <topology/TopoTool.hpp>
#include <topology/TopoVertex.hpp>
#include <topology/TopoShape.hpp>
#include <topology/TopoExplorer.hpp>
#include <topology/TopoTool.hpp>
#include <topology/TopoVertex.hpp>
#include <topology/TopoEdge.hpp>
#include <topology/TopoFace.hpp>
#include <topology/TopoShape.hpp>
#include <geometry/Geom3Surface.hpp>
#include <geometry/Geom3Curve.hpp>
#include <io/OBJTool.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeVertex.hpp>
#include <hatch/BRepClassificationTools.hpp>
#include <math/Sphere.hpp>
#include <geometry/Geom3Surface.hpp>
#include <modeling/MakeFace.hpp>
#include <geometry/Geom3Curve.hpp>
TEST_CASE("case1: TransformShape 1/10  ", "[modeling][TransformShape][P1][fixme]") {
	SECTION("Mirror plane 2D") {
        TopoShape square = MakePrism(Square2(DPoint2(0.0, 0.0), 4.0), Direction3(0.0, 0.0, 1.0));
        TopoShape result = TransformShape(square, Mirror(Frame3(Point3(0.0, 1.0, 0.0), Direction3(0.0, 0.0, 1.0))));
        CHECK(OCCTIO::OCCTTool::Write(square, OUTPUT_PATH_PREFIX"MirrorShape_01_brep.brep"));
        TopoShape expected = MakePrism(Square2(DPoint2(0.0, 1.0), 4.0), Direction3(0.0, 0.0, 1.0));
        CHECK(GetTopoToolCount(expected) == GetTopoToolCount(result));
        CHECK(OCCTIO::OCCTTool::Write(expected, OUTPUT_PATH_PREFIX"MirrorShape_01_brepexpected.brep"));
        CHECK(OCCTIO::OCCTTool::Write(result, OUTPUT_PATH_PREFIX"MirrorShape_01_brepresult.brep"));
        TopoShape shape1 = ReadBrep(OUTPUT_PATH_PREFIX"MirrorShape_01_brepexpected.brep");
        TopoShape shape2 = ReadBrep(OUTPUT_PATH_PREFIX"MirrorShape_01_brepresult.brep");
        CHECK(OCCTIO::OCCTTool::Write(shape1, OUTPUT_PATH_PREFIX"MirrorShape_01_brepresult1.brep"));
        CHECK(OCCTIO::OCCTTool::Write(shape2, OUTPUT_PATH_PREFIX"MirrorShape_01_brepresult2.brep"));
        GlobalProperty prop1, prop2;
        GetLinearProperties(shape1, true, false, prop1);
        GetLinearProperties(shape2, true, false, prop2);
        std::cout << prop1 << std::endl;
        std::cout << prop2 << std::endl;
        CHECK(prop1.Mass() == Approx(prop2.Mass()));
        CHECK(prop1.MomentOfInertiaX() == Approx(prop2.MomentOfInertiaX()));
        CHECK(prop1.MomentOfInertiaY() == Approx(prop2.MomentOfInertiaY()));
        CHECK(prop1.MomentOfInertiaZ() == Approx(prop2.MomentOfInertiaZ()));
        CHECK(prop1.RadiusOfGyrationX() == Approx(prop2.RadiusOfGyrationX()));
        CHECK(prop1.RadiusOfGyrationY() == Approx(prop2.RadiusOfGyrationY()));
        CHECK(prop1.RadiusOfGyrationZ() == Approx(prop2.RadiusOfGyrationZ()));
        CHECK(shape1.Type() == shape2.Type());
        CHECK(OCCTIO::OCCTTool::Write(static_cast<const TopoShape&>(shape1), OUTPUT_PATH_PREFIX"MirrorShape_01_brepresult3.brep"));
        CHECK(OCCTIO::OCCTTool::Write(static_cast<const TopoShape&>(shape2), OUTPUT_PATH_PREFIX"MirrorShape_01_brepresult4.brep"));
        for (TopoShape const& shape : {shape1, shape2}) {
            for (TopoShape const& shape1 : GetTopoTool()
             }
        }
    }