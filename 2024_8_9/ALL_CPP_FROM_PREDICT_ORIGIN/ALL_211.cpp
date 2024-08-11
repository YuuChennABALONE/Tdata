 #include<catch.hpp>
#include<testHelper.h>
#include <geometry/MakeGeom2Circle.hpp>
#include <geometry/AdaptorGeom2Curve.hpp>
#include <geometry/Geom2TrimmedCurve.hpp>
#include <geometry/MakeGeom3Circle.hpp>
#include <geometry/AdaptorGeom3Curve.hpp>
#include <geometry/MakeGeom3Surface.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeFace.hpp>
#include <modeling/MakePrism.hpp>
#include <geometry/GeometryTool.hpp>
#include <hatch/BRepClassificationTools.hpp>
#include <topology/TopoTool.hpp>
using namespace AMCAX;
TEST_CASE("bug1: G3  ", "[geometry][G3][fixbug]") {
    Point3 P(-1.0, 0.0, -1.0);
    Point3 P2(-2.0, 0.0, -1.0);
    Direction3 D(0.0, 0.0, 1.0);
    Frame3 frame3(P, D);
    std::shared_ptr<Geom3Curve> c1 = MakeGeom3Circle(frame3, 2.0);
    AdaptorGeom3Curve circle(c1);
    Point3 s = circle.Position(0.0);
    double r = circle.Radius();
    std::shared_ptr<Geom3Surface> surf;
    {
        surf = MakeGeom3Surface(c1);
    }
    MakeFace face(surf, 0.0);
    bool bWriteresult = OCCTIO::OCCTTool::Write(face, OUTPUT_PATH_PREFIX"testbug3.brep");
    CHECK(bWriteresult == true);
    Point3 P3(-2.0, 0.0, 1.0);
    Point3 P4(-1.0, 0.0, 1.0);
    std::shared_ptr<Geom3Curve> c2 = MakeGeom3Circle(Frame3(P3, Direction3(0.0, 0.0, 1.0)), 2.0);
    AdaptorGeom3Curve circle2(c2);
    double square1 = GeometryTool::SquareDistance(circle.Position(0.0), circle2.Position(0.0));
    CHECK(square1 == Approx(4.0));
    std::shared_ptr<Geom3Curve> c3 = MakeGeom3Circle(Frame3(P4, Direction3(0.0, 0.0, 1.0)), 2.0);
    AdaptorGeom3Curve circle3(c3);
    double square2 = GeometryTool::SquareDistance(circle.Position(0.0), circle3.Position(0.0));
    CHECK(square2 == Approx(4.0));
    double square3 = GeometryTool::SquareDistance(circle.Position(0.0), circle2.Position(0.0));
    CHECK(square3 == Approx(4.0));
    GccCircle3Tangent circle3Tangent(circle, circle2, P, 0.0, 0.0);
    Point3 s2 = circle3Tangent.Location();
    CHECK(s2.X() == Approx(-1.0));
    CHECK(s2.Y() == Approx(0.0));
    CHECK(s2.Z() == Approx(-1.0));
    double r2 = circle3Tangent.Radius();
    CHECK(r2 == Approx(2.0));
    CHECK(circle3Tangent.Position(0.0).X() == Approx(-1.0));
    CHECK(circle3Tangent.Position(0.0).Y() == Approx(0.0));
    CHECK(circle3Tangent.Position(0.0).Z() == Approx(-1.0));
    CHECK(circle3Tangent.Position(2 * M_PI).X() == Approx(-1.0));
    CHECK(circle3Tangent.Position(2 * M_PI).Y() == Approx(0.0));
    CHECK(circle3Tangent.Position(2 * M_PI).Z() == Approx(-1.0));
    CHECK(circle3Tangent.Position(0.0).X() == circle.Position(0.0).X());
    CHECK(circle3Tangent.Position(0.0).Y() == circle.Position(0.0).Y());
    CHECK(circle3Tangent.Position(0.0).Z() == circle.Position(0.0).Z());
    CHECK(circle3Tangent.Position(2 * M_PI).X() == circle.Position(2 * M_PI).X());
    CHECK(circle3Tangent.Position(2 * M_PI).Y() == circle.Position(2 * M_PI).Y());
    CHECK(circle3Tangent.Position(2 * M_PI).Z() == circle.Position(2 * M_PI).Z());
    CHECK(circle3Tangent.Position(0.0).X() == Approx(s.X()));
    CHECK(circle3Tangent.Position(0.0).Y()"}