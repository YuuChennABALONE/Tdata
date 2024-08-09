/* "AMCAX_API BoolBRepFuse()\t @details Only set the type of boolean operation to fuse\n\t @brief Default constructor\n,\n",
      */
 #include<catch.hpp>
#include<testHelper.h>
#include <boolean/BoolBRepFuse.hpp>
#include <boolean/BoolBRepCut.hpp>
using namespace AMCAX;
TEST_CASE("bug1: BoolBRepFuse ", "[boolean][BoolBRepFuse][fixbug]")
{
	TopoShape shape1, shape2;
	OCCTIO::OCCTTool::Read(shape1, INPUT_PATH_PREFIX"boolean/part.brep");
	OCCTIO::OCCTTool::Read(shape2, INPUT_PATH_PREFIX"boolean/box.brep");
	TopoShape result = BoolBRepFuse(shape1, shape2);
	CHECK(OCCTIO::OCCTTool::Write(result, OUTPUT_PATH_PREFIX"testbug-view-556.brep"));
	IndexSet<TopoShape> shapeFace, shapeEdge, shapeVertex ,shapeSolid;
	CHECK( GetTopoToolCount(result, AMCAX::ShapeType::Solid, shapeSolid)==1 );
}