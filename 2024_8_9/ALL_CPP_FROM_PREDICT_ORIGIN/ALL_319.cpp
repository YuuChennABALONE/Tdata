 #include<catch.hpp>
#include<testHelper.h>
#include <modeling/MakeTorus.hpp>
#include <topology/TopoExplorerTool.hpp>
#include <topology/TopoShape.hpp>
#include <io/ShapeTool.hpp>
#include <hatch/BRepClassificationTools.hpp>
TEST_CASE("case1: This is a test case for MakeTorus", "[modeling][MakeTorus][P1]")
{
    Point3 p(0.0, 0.0, 1.0);
    Direction3 d(0.0, 0.0, 1.0);
    Frame3 f(p, d);
    double r1 = 3.0, r2 = 2.0;
    TopoShape torus = MakeTorus(f, r1, r2);
    CHECK(ShapeTool::Write(torus, OUTPUT_PATH_PREFIX"MakeTorus_case1.brep"));
    TopoShape torus1;
    std::ifstream ifs(OUTPUT_PATH_PREFIX"MakeTorus_case1.brep");
    if (ifs.is_open())
    {
        std::string line;
        std::getline(ifs, line);
        std::istringstream iss(line);
        std::string shapeType;
        iss >> shapeType;
        CHECK(shapeType == "Torus");
        torus1 = ShapeTool::Read(ifs);
    }
    IndexSet<TopoShape> shapes;
    TopoExplorerTool::MapShapes(torus1, ShapeType::Face, shapes);
    for (const auto& shape : shapes)
    {
        CHECK(BRepClassificationTools::IsPointInOnFace(shape, p, 0.0));
    }
}