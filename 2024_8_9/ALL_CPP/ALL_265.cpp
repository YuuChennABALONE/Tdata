/* "AMCAX_API Geom3Ellipse(const Frame3& frame, double major, double minor)\t @param minor The minor radius\n\t @param major The major radius\n\t @param frame The local frame\n\t @brief Construct from a local frame, a major radius and a minor radius\n,\n",
      */
 #include<catch.hpp>
#include<testHelper.h>
#include <geometry/MakeGeom3Ellipse.hpp>
#include <common/DirectionT.hpp>
#include <common/PointT.hpp>
#include <common/Precision.hpp>
#include <topology/TopoEdge.hpp>
#include <topology/TopoWire.hpp>
#include <topology/TopoFace.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeWire.hpp>
#include <modeling/MakeFace.hpp>
#include <modeling/MakePrism.hpp>
#include <topomesh/BRepMeshIncrementalMesh.hpp>
#include <topology/TopoExplorerTool.hpp>
#include <topology/TopoExplorer.hpp>
#include <topology/TopoCast.hpp>
#include <topology/TopoTool.hpp>
#include <math/TriangularMesh.hpp>
using namespace AMCAX;
TEST_CASE("bug1: MakeGeom3Ellipse ", "[geometry][MakeGeom3Ellipse][fixbug]") {
	MakeGeom3Ellipse makeEllipse(Frame3(), 3.0, 1.0);
	std::shared_ptr<Geom3Curve> curve = makeEllipse.Value();
	TopoEdge e = MakeEdge(curve);
	TopoWire w = MakeWire(e);
	TopoFace f = MakeFace(w);
	TopoShape s = MakePrism(f, Vector3(0.0, 0.0, 1.0));
	BRepMeshIncrementalMesh mesher(s, 0.005, true);
	int counttest = 0;
	for (TopoExplorer ex(s, ShapeType::Face); ex.More(); ex.Next())
	{
		const auto& face = TopoCast::Face(ex.Current());
		TopoLocation l;
		auto tri = TopoTool::Triangulation(face, l);
		CHECK(tri); 
		if (tri)
		{
			counttest = counttest + 1;
			if (counttest == 1)
			{
				CHECK(tri->NVertices() == 84);
				CHECK(tri->NTriangles() == 82);
			}
			if (counttest == 2)
			{
				CHECK(tri->NVertices() == 41);
				CHECK(tri->NTriangles() == 39);
			}
			if (counttest == 3)
			{
				CHECK(tri->NVertices() == 41);
				CHECK(tri->NTriangles() == 39);
			}
		}
	}
}