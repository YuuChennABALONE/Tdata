 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <modeling/MakeSphere.hpp>
#include <modeling/TransformShape.hpp>
#include <topomesh/BRepMeshIncrementalMesh.hpp>
#include <modeling/MakeShapeTool.hpp>
#include <geometry/Geom3Surface.hpp>
#include <geometry/Geom3Curve.hpp>
#include <modeling/MakeEdge.hpp>
#include <geometry/Geom3Plane.hpp>
#include <topology/TopoFace.hpp>
#include <topology/TopoTool.hpp>
#include <topology/TopoExplorer.hpp>
#include <topology/TopoVertex.hpp>
#include <math/Sphere.hpp>
#include <math/Line.hpp>
#include <modeling/MakeEdge2d.hpp>
#include <geometry/Geom3Surface.hpp>
#include <geometry/Geom3Curve.hpp>
#include <modeling/MakeEdge.hpp>
#include <geometry/Geom2Plane.hpp>
#include <geometry/Geom2Circle.hpp>
#include <topology/TopoEdge.hpp>
#include <topology/TopoExplorer.hpp>
#include <topology/TopoVertex.hpp>
#include <common/VectorT.hpp>
#include <modeling/MakeShapeTool.hpp>
#include <occtio/OCCTTool.hpp>
#include <topology/TopoTool.hpp>
using namespace AMCAX;
TEST_CASE("bug1: GeneralTransformShape ", "[modeling][GeneralTransformShape][fixbug]") {
	TopoShape s = MakeSphere(1.0);
	BRepMeshIncrementalMesh mesher(s, 0.005, true);
	MakeShapeTool::EnsureNormalConsistency(s);
	TopoFace sf = TopologyTool::Face(s, 1);
	Geom3Surface sf1;
	TopoTool::MapShape(sf, sf1);
	double r1 = Sphere::Radius(sf1);
	std::cout << " r1: " << r1 << std::endl;
	GeneralTransformation3 tr;
	tr.SetAffinity(Frame3(), 2.0);
	TopoShape s1 = GeneralTransformShape(s, tr, true);
	IndexSet<TopoShape> shape1;
	MakeShapeTool::Split(s1, shape1, 0.0, true);
	std::cout << "shape1: " << shape1.nbElements() << std::endl;
	for (TopoShape& s2 : shape1)
	{
		if (s2.Type() == ShapeType::Face)
		{
			Geom3Surface sf2;
			TopoTool::MapShape(s2, sf2);
			double r2 = Sphere::Radius(sf2);
			std::cout << " r2: " << r2 << std::endl;
		}
	}
}