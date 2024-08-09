/* "AMCAX_API explicit BoolBRepDefeaturing(const TopoShape& shape)\t @param shape The shape that require remove feature\n\t @brief Construct from a shape.\n,\n",
      */
 #include<catch.hpp>
#include<testHelper.h>
#include <modeling/MakeBox.hpp>
#include <modeling/MakeCylinder.hpp>
#include <boolean/BoolBRepCut.hpp>
#include <topomesh/BRepMeshIncrementalMesh.hpp>
#include <io/OBJTool.hpp>
#include <topology/TopoFace.hpp>
#include <geometry/Geom3Surface.hpp>
#include <topology/TopoTool.hpp>
#include <hatch/BRepClassificationTools.hpp>
#include <boolean/BoolBRepDefeaturing.hpp>
#include <topology/TopoEdge.hpp>
#include <common/IndexSet.hpp>
using namespace AMCAX;
TEST_CASE("case1: test BoolBRepDefeaturing Algorithm", "[boolean][BRepDefeaturing]")
{
	OUTPUT_DIRECTORY(Boolean, BRepDefeaturing);
	TopoShape box = MakeBox(Point3(-5.0, -5.0, 0.0), Point3(5.0, 5.0, 3.0));
	TopoShape cyl = MakeCylinder(Frame3(Point3(0.0, 0.0, 0.0), Direction3(0.0, 0.0, 1.0)), 3.0, 5.0);
	TopoShape shape = BoolBRepCut(box, cyl);
	OCCTIO::OCCTTool::Write(shape, outdir + "testResultTemp.brep");
	BRepMeshIncrementalMesh meshT(shape, 0.01, true);
	OBJTool::WriteShape(shape, outdir + "testResultTemp.obj");
	IndexSet<TopoShape> shapeFace, shapeEdge, shapeVertex;
	CHECK(GetTopoToolCount(shape, ShapeType::Face, shapeFace) == 7);
	CHECK(GetTopoToolCount(shape, ShapeType::Edge, shapeEdge) == 15);
	CHECK(GetTopoToolCount(shape, ShapeType::Vertex, shapeVertex) == 10);
	TopoFace cy;
	std::list<TopoShape> faceToRemove;
	for (TopoExplorer expF(shape, ShapeType::Face); expF.More(); expF.Next())
	{
		TopoFace f = static_cast<const TopoFace&>(expF.Current());
		std::shared_ptr<Geom3Surface> surface = TopoTool::Surface(f);
		if (surface->Type() == SurfaceType::Cylinder)
		{
			cy = f;
			OCCTIO::OCCTTool::Write(f, outdir + "RemoveFace.brep");
			faceToRemove.push_back(f);
		}
	}
	BoolBRepDefeaturing defeature(shape);
	defeature.AddFaceToRemove(faceToRemove);
	defeature.Build();
	TopoShape newShape = defeature.Shape();
	Point3 p(-3.0, 0.0, 1.0);
	double tol = -1.0;
	bool isIn = BRepClassificationTools::IsPointInFace(cy, p, tol);
	CHECK(isIn == true);
	for (TopoExplorer expF(newShape, ShapeType::Face); expF.More(); expF.Next())
	{
		TopoFace newFace = static_cast<const TopoFace&>(expF.Current());
		bool isIn1 = BRepClassificationTools::IsPointInFace(newFace, p, tol);
		CHECK(isIn1 == false);
	}
	for (TopoExplorer expF1(newShape, ShapeType::Face); expF1.More(); expF1.Next())
	{
		bool result;
		TopoFace f1 = static_cast<const TopoFace&>(expF1.Current());
		std::shared_ptr<Geom3Surface> surface1 = TopoTool::Surface(f1);
		if (surface1->Type() == SurfaceType::Cylinder)
		{
			result = false;
		}
		else
		{
			result = true;
		}
		CHECK(result == true);
	}
	AMCAX::GlobalProperty props1, props2, props3;
	IndexSet<TopoShape> newshapeFace, newshapeEdge, newshapeVertex;
	CHECK(newShape.Type() == ShapeType::Compound);
	CHECK(GetTopoToolCount(newShape, ShapeType::Face, newshapeFace) == 6);
	CHECK(GetTopoToolCount(newShape, ShapeType::Edge, newshapeEdge) == 12);
	CHECK(GetTopoToolCount(newShape, ShapeType::Vertex, newshapeVertex) == 8);
	CHECK(GetLinearProperties(newShape,props1,true,false)== Approx(10 * 8 + 3 * 4));
	CHECK(GetSurfaceProperties(newShape, props2, true, false) == Approx(2 * (10 * 10) + 4*(10 * 3)));
	CHECK(GetVolumeProperties(newShape, props3, true, false) == Approx(10*10*3));
	Point3 point = props3.CenterOfMass();
	CHECK(point.X() == Approx(0.0).margin(1e-12));
	CHECK(point.Y() == Approx(0.0).margin(1e-12));
	CHECK(point.Z() == Approx(1.5).margin(1e-12));
	std::cout << "defeature ok " << std::endl;
	OCCTIO::OCCTTool::Write(newShape, outdir + "testResult.brep");
	BRepMeshIncrementalMesh meshR(newShape, 0.01, true);
	OBJTool::WriteShape(newShape, outdir + "testResult.obj");
}