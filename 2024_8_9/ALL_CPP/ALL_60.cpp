/* "AMCAX_API MakeBox(const Point3& p, double dx, double dy, double dz)\t @param dx,dy,dz The size\n\t @param p The corner point\n\t @brief Construct from a corner point and its size\n,\n",
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
	SECTION("Box3")
	{
		OUTPUT_DIRECTORY(topology, OverlapFaces);
		MakeBox box2(Point3(-2.0, -2.0, -2.0), Point3(2.0,2.0,2.0));
		MakeBox box3;
		box3.Init(Point3(-2.0, -2.0, -2.0), Point3(2.0, 2.0, 2.0));
		TopoFace shape1 = box2.XMinFace();
		TopoFace shape2 = box2.XMaxFace();
		TopoFace shape3 = box2.YMinFace();
		TopoFace shape4 = box2.YMaxFace();
		TopoFace shape5 = box2.ZMinFace();
		TopoFace shape6 = box2.ZMaxFace();
		TopoShape shape = box2;
		TopoFace shape_1 = box3.XMinFace();
		TopoFace shape_2 = box3.XMaxFace();
		TopoFace shape_3 = box3.YMinFace();
		TopoFace shape_4 = box3.YMaxFace();
		TopoFace shape_5 = box3.ZMinFace();
		TopoFace shape_6 = box3.ZMaxFace();
		AMCAX::GlobalProperty prop1;
		double s_sahpe1 = GetSurfaceProperties(shape1, prop1, true, false);
		double s_sahpe2 = GetSurfaceProperties(shape2, prop1, true, false);
		double s_sahpe3 = GetSurfaceProperties(shape3, prop1, true, false);
		double s_sahpe4 = GetSurfaceProperties(shape4, prop1, true, false);
		double s_sahpe5 = GetSurfaceProperties(shape5, prop1, true, false);
		double s_sahpe6 = GetSurfaceProperties(shape6, prop1, true, false);
		double s_sahpe = GetSurfaceProperties(shape, prop1, true, false);
		double v_sahpe = GetVolumeProperties(shape, prop1, true, false);
		BRepClassificationTools brep;
		bool r1 = brep.IsPointInOnFace(shape1, Point3(-2.0, 0.0, 0.0), -1.0);
		bool r2 = brep.IsPointInOnFace(shape2, Point3(2.0, 0.0, 0.0), -1.0);
		bool r3 = brep.IsPointInOnFace(shape3, Point3(0.0, -2.0, 0.0), -1.0);
		bool r33 = brep.IsPointInOnFace(shape3, Point3(1.0, 0.5, 3.0), -1.0);
		bool r4 = brep.IsPointInOnFace(shape4, Point3(0.0, 2.0, 0.0), -1.0);
		bool r5 = brep.IsPointInOnFace(shape5, Point3(0.0, 0.0, -2.0), -1.0);
		bool r6 = brep.IsPointInOnFace(shape6, Point3(0.0, 0.0, 2.0), -1.0);
		double s_shape_1 = GetSurfaceProperties(shape_1, prop1, true, false);
		double s_shape_2 = GetSurfaceProperties(shape_2, prop1, true, false);
		double s_shape_3 = GetSurfaceProperties(shape_3, prop1, true, false);
		double s_shape_4 = GetSurfaceProperties(shape_4, prop1, true, false);
		double s_shape_5 = GetSurfaceProperties(shape_5, prop1, true, false);
		double s_shape_6 = GetSurfaceProperties(shape_6, prop1, true, false);
		bool r_1 = brep.IsPointInOnFace(shape_1, Point3(-2.0, 0.0, 0.0), -1.0);
		bool r_2 = brep.IsPointInOnFace(shape_2, Point3(2.0, 0.0, 0.0), -1.0);
		bool r_3 = brep.IsPointInOnFace(shape_3, Point3(0.0, -2.0, 0.0), -1.0);
		bool r_33 = brep.IsPointInOnFace(shape_3, Point3(1.0, 0.5, 3.0), -1.0);
		bool r_4 = brep.IsPointInOnFace(shape_4, Point3(0.0, 2.0, 0.0), -1.0);
		bool r_5 = brep.IsPointInOnFace(shape_5, Point3(0.0, 0.0, -2.0), -1.0);
		bool r_6 = brep.IsPointInOnFace(shape_6, Point3(0.0, 0.0, 2.0), -1.0);
		CHECK(s_sahpe1 == Approx(16.0).margin(1e-12));
		CHECK(s_sahpe2 == Approx(16.0).margin(1e-12));
		CHECK(s_sahpe3 == Approx(16.0).margin(1e-12));
		CHECK(s_sahpe4 == Approx(16.0).margin(1e-12));
		CHECK(s_sahpe5 == Approx(16.0).margin(1e-12));
		CHECK(s_sahpe6 == Approx(16.0).margin(1e-12));
		CHECK(v_sahpe == Approx(64.0).margin(1e-12));
		CHECK(s_sahpe == s_sahpe1 + s_sahpe2 + s_sahpe3 + s_sahpe4 + s_sahpe5 + s_sahpe6);
		CHECK(s_sahpe1 == s_shape_1);
		CHECK(s_sahpe2 == s_shape_2);
		CHECK(s_sahpe3 == s_shape_3);
		CHECK(s_sahpe4 == s_shape_4);
		CHECK(s_sahpe5 == s_shape_5);
		CHECK(s_sahpe6 == s_shape_6);
		CHECK(r1 == true);
		CHECK(r2 == true);
		CHECK(r3 == true);
		CHECK(r33 == false);
		CHECK(r4 == true);
		CHECK(r5 == true);
		CHECK(r6 == true);
		CHECK(r_1 == true);
		CHECK(r_2 == true);
		CHECK(r_3 == true);
		CHECK(r_33 == false);
		CHECK(r_4 == true);
		CHECK(r_5 == true);
		CHECK(r_6 == true);
		CHECK(OCCTIO::OCCTTool::Write(box2, outdir + "MakeBox3.brep"));
	}}