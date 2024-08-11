 #include <modeling/MakeBox.hpp>
#include<catch.hpp>
#include<testHelper.h>
#include <modeling/MakeBox.hpp>
#include <modeling/MakeCylinder.hpp>
#include <topology/BRepExtremaProximityTool.hpp>
#include <io/OBJTool.hpp>
#include <topology/TopoFace.hpp>
#include <modeling/TransformShape.hpp>
#include <topology/TopoExplorerTool.hpp>
#include <modeling/MakeTorus.hpp>
#include <hatch/BRepClassificationTools.hpp>
#include <topology/BRepExtremaDistShapeShape.hpp>
using namespace AMCAX;
TEST_CASE("bug1: this is a bug fix test ", "[io][OBJTool][fix]"") {
	TopoShape box = MakeBox(Point3(-5.0, -5.0, 0.0), Point3(5.0, 5.0, 2.0));
	TopoShape box1 = MakeBox(Point3(-5.0, -5.0, 0.0), Point3(5.0, 5.0, 2.0));
	TopoFace shape1 = box;
	TopoFace shape2 = box1;
	BRepExtremaDistShapeShape shapeshape1(shape1, shape2);
	CHECK(shapeshape1.Value() == Approx(0.0));
	SECTION("testWrite") {
		std::string fileout = OUTPUT_PATH_PREFIX"MakeBox_bug15.obj";
		OBJTool::Write(box, fileout);
		bool isReadSuccess = OBJTool::Read(fileout, box);
		CHECK(isReadSuccess == true);
		TopoShape box2 = ReadOBJFile(fileout);
		TopoFace face = box2;
		CHECK(BRepClassificationTools::IsPointInOnFace(box2, Point3(0.0, 0.0, 0.0), 0.0) == true);
		CHECK(BRepClassificationTools::IsPointInOnFace(box2, Point3(0.0, 0.0, 0.0), 0.01) == true);
		CHECK(BRepClassificationTools::IsPointInOnFace(box2, Point3(0.0, 0.0, 0.0), 0.1) == true);
		CHECK(BRepClassificationTools::IsPointInOnFace(box2, Point3(0.0, 0.0, 0.0), 0.2) == true);
		CHECK(BRepClassificationTools::IsPointInOnFace(box2, Point3(0.0, 0.0, 0.0), 0.3) == false);
	}}