 #include<catch.hpp>
#include<testHelper.h>
#include<common/FrameT.hpp>
#include <modeling/MakeBox.hpp>
#include <common/AxisT.hpp>
#include <common/DirectionT.hpp>
#include <common/PointT.hpp>
#include <common/TransformationT.hpp>
#include <common/VectorT.hpp>
#include <math/CartesianAlgebra.hpp>
#include <occtio/OCCTTool.hpp>
#include <modeling/MakeCylinder.hpp>
#include <modeling/MakeTorus.hpp>
#include <topology/BRepExtremaProximityTool.hpp>
#include <topology/TopoTool.hpp>
#include <topology/TopoFace.hpp>
#include <common/MethodType.hpp>
#include <modeling/MakePrism.hpp>
#include <modeling/MakeConicalSurface.hpp>
#include <modeling/MakeLinearSweep.hpp>
#include <modeling/MakeRevol.hpp>
#include <geometry/Geom3BSplineCurve.hpp>
#include <modeling/MakeEdge2d.hpp>
#include <modeling/MakeEdge.hpp>
#include <geometry/Geom3BSplineSurface.hpp>
#include <modeling/MakeSurface.hpp>
using namespace AMCAX;
TEST_CASE("case1: MakeBox(frame, dx, dy, dz) ", "[modeling][MakeBox][P1]") {
	Frame3 frame;
	double dx = 5.0;
	double dy = 4.0;
	double dz = 3.0;
	AMCAX::MakeBox box(frame, dx, dy, dz);
	std::vector<TopoShape> shapes = box.Shape();
	CHECK(shapes.size() == 1);
	TopoFace face = shapes[0];
	CHECK(TopoTool::MapShape(face, 0.0, 0.0, 0.0) == Point3(0.0, 0.0, 0.0));
	CHECK(TopoTool::MapShape(face, 5.0, 0.0, 0.0) == Point3(5.0, 0.0, 0.0));
	CHECK(TopoTool::MapShape(face, 5.0, 4.0, 0.0) == Point3(5.0, 4.0, 0.0));
	CHECK(TopoTool::MapShape(face, 5.0, 4.0, 3.0) == Point3(5.0, 4.0, 3.0));
	CHECK(TopoTool::MapShape(face, 0.0, 0.0, 3.0) == Point3(0.0, 0.0, 3.0));
	CHECK(TopoTool::MapShape(face, 0.0, 4.0, 3.0) == Point3(0.0, 4.0, 3.0));
	CHECK(TopoTool::MapShape(face, 5.0, 0.0, 3.0) == Point3(5.0, 0.0, 3.0));
	CHECK(TopoTool::MapShape(face, 5.0, 4.0, 3.0) == Point3(5.0, 4.0, 3.0));
}