/* "AMCAX_API MakeBox(double dx, double dy, double dz)\t @param dx,dy,dz The size\n\t @brief Construct from its size in x, y, z directions\n,\n",
      */
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
TEST_CASE("case1:this is a case for MakeBox", "[MakeBox1]")
{
	SECTION("Box1") {
		OUTPUT_DIRECTORY(topology, OverlapFaces);
		MakeBox box(3.0, 2.0,2.0);
		TopoShape box2= box.Shape();
		box.Init(4.0, 5.0, 6.0);
		TopoFace shape = box.XMinFace(); 
		TopoFace shape1 = box.ZMinFace(); 
		TopoShape shape2 = box; 
		TopoShape shapeV = box;
		AMCAX::GlobalProperty prop1;
		double s_sahpe = GetSurfaceProperties(shape, prop1, true, false);
		double s_sahpe1 = GetSurfaceProperties(shape1, prop1, true, false);
		double s_sahpe2 = GetSurfaceProperties(shape2, prop1, true, false);
		double v_sahpe = GetVolumeProperties(shapeV, prop1, true, false);
		CHECK(s_sahpe == Approx(30.0).margin(1e-12));
		CHECK(s_sahpe1 == Approx(20.0).margin(1e-12));
		CHECK(s_sahpe2 == Approx(148.0).margin(1e-12));
		CHECK(v_sahpe == Approx(120.0).margin(1e-12));
		CHECK( OCCTIO::OCCTTool::Write(box, outdir + "MakeBox1.brep"));
	}}