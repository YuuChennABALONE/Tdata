 #include<catch.hpp>
#include<testHelper.h>
#include <nurbs/NURBSAPIGetGeometry.hpp>
#include <geometry/Geom3Curve.hpp>
#include <geometry/Geom3TrimmedCurve.hpp>
#include <geometry/Geom3Surface.hpp>
#include <geometry/Geom3TrimmedSurface.hpp>
#include <topology/TopoEdge.hpp>
#include <topology/TopoFace.hpp>
#include <topology/TopoTool.hpp>
#include <topology/TopoCompound.hpp>
#include <topology/TopoExplorer.hpp>
#include <topology/TopoExplorerTool.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeFace.hpp>
#include <modeling/MakePrism.hpp>
#include <modeling/MakeRevol.hpp>
#include <modeling/MakeCut.hpp>
#include <modeling/MakeShape.hpp>
#include <modeling/MakeTranslation.hpp>
#include <modeling/MakeMirror.hpp>
#include <modeling/MakeCompound.hpp>
#include <io/ShapeTool.hpp>
#include <hatch/BRepClassificationTools.hpp>
#include <topomesh/BRepMeshIncrementalMesh.hpp>
#include <topology/TopoExplorerTool.hpp>
using namespace AMCAX;
TEST_CASE("bug1: NURBSAPIGetGeometry ", "[nurbs][NURBSAPIGetGeometry][fixbug]") {
	Point3 point1(-1.0, 0.0, 0.0);
	Point3 point2(0.0, 0.0, 1.0);
	Point3 point3(1.0, 0.0, 0.0);
	Point3 point4(0.0, 1.0, 0.0);
	Direction3 dir1(0.0, 0.0, 1.0);
	Frame3 framex(point1, dir1);
	Frame3 framey(point2, dir1);
	Frame3 framez(point3, dir1);
	Frame3 frame(point4, dir1);
	double u1 = 0.0, u2 = 1.0, u3 = 0.0, u4 = 1.0;
	bool isRight = true;
	Geom3Curve curve1;
	{
		Geom3Curve line1(point1, point2);
		Geom3Curve line2(point2, point3);
		Geom3Curve line3(point3, point4);
		Geom3Curve line4(point4, point1);
		curve1 = MakeEdge(line1);
	}
	{
		Geom3Curve line1(point1, point2);
		Geom3Curve line2(point2, point3);
		Geom3Curve line3(point3, point4);
		Geom3Curve line4(point4, point1);
		curve1 = MakeEdge(line1);
	}
	SECTION("IsPlanarCurve 3D") {
		Geom3TrimmedCurve trimCurve1(curve1, 0.0, 1.0);
		TopoEdge e1 = MakeEdge(curve1);
		TopoFace f1 = MakeFace(e1);
		TopoCompound fc = MakePrism(e1, framez);
		TopoCompound fc1 = MakeRevol(fc, framex);
		TopoCompound fc2 = MakeRevol(fc1, framey);
		TopoCompound fc3 = MakeRevol(fc2, frame);
		TopoFace f2 = MakeFace(fc3);
		TopoFace f3 = MakeFace(fc);
		TopoShape f4 = MakeShape(e1);
		TopoShape f5 = MakeShape(f1);
		TopoShape f6 = MakeShape(f2);
		TopoShape f7 = MakeShape(f3);
		TopoShape f8 = MakeShape(f4);
		TopoShape f9 = MakeShape(f5);
		TopoShape f10 = MakeShape(f6);
		TopoShape f11 = MakeShape(f7);
		TopoShape f12 = MakeShape(f8);
		TopoShape f13 = MakeShape(f9);
		TopoShape f14 = MakeShape(f10);
		TopoShape f15 = MakeShape(f11);
		TopoShape f16 = MakeShape(f12);
		TopoShape f17 = MakeShape(f13);
		TopoShape f18 = MakeShape(f14);
		TopoShape f19 = MakeShape(f15);
		TopoShape f20 = MakeShape(f16);
		TopoShape f21 = MakeShape(f17);
		TopoShape f22 = MakeShape(f18);
	"}