 #include<catch.hpp>
#include<testHelper.h>
#include <modeling/MakeBox.hpp>
#include <common/PointT.hpp>
#include <modeling/MakeBox.hpp>
#include <topology/BRepGlobalProperty.hpp>
#include <topology/TopoFace.hpp>
#include <topology/TopoEdge.hpp>
#include <topology/TopoVertex.hpp>
TEST_CASE("case1: MakeBox(p,d)  add 2020/10/29", "[modeling][MakeBox][P1]")
{
	SECTION("10x10x1")
    {
        TopoShape box = AMCAX::MakeBox(Point3(1.0, 1.0, 1.0), 10.0, 10.0, 1.0);
        TopoShape box2 = AMCAX::MakeBox(Point3(1.0, 1.0, 1.0), 10.0);
        CHECK(OCCTIO::OCCTTool::Write(box, OUTPUT_PATH_PREFIX"MakeBox10x10x1_case1.brep"));
        CHECK(OCCTIO::OCCTTool::Write(box2, OUTPUT_PATH_PREFIX"MakeBox10x10x1_case1.brep"));
        AMCAX::GlobalProperty prop1;
        TopoFace face1 = AMCAX::TopoCast::Face(box);
        AMCAX::BRepGlobalProperty::VolumeProperties faceProp1(face1, prop1);
        double v1 = faceProp1.Mass();
        CHECK(v1 == Approx(100.0));
        AMCAX::GlobalProperty prop2;
        TopoFace face2 = AMCAX::TopoCast::Face(box2);
        AMCAX::BRepGlobalProperty::SurfaceProperties faceProp2(face2, prop2);
        double s1 = faceProp2.Mass();
        CHECK(s1 == Approx(100.0));
        double s2 = faceProp2.SurfacesSquare();
        CHECK(s2 == Approx(110.0));
        double s3 = faceProp2.SurfacesPerimeter();
        CHECK(s3 == Approx(40.0));
    }}