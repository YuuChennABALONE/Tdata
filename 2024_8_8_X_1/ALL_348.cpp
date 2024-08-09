/* "AMCAX_API void SimplifyResult(bool isUnfiyEdges = true, bool isUnifyFaces = true, double angularTol = Precision::Angular()\t @param angularTol The angular tolerance for checking parallel\n\t @param isUnifyFaces Set whether unify faces\n\t @param isUnfiyEdges Set whether unify edges\n\t @brief Simplify the boolean result, remove redundant edges and faces\n,\n",
      */
 #include<catch.hpp>
#include<testHelper.h>
#include <boolean/BoolBuilder.hpp>
#include <modeling/MakeBox.hpp>
#include <boolean/BoolBRepFuse.hpp>
#include <common/IndexSet.hpp>
#include <topology/TopoExplorerTool.hpp>
using namespace AMCAX;
TEST_CASE("case1: BoolBuilder added SimplifyResult() API at 3.6.0. ", "[boolean][BoolBuilder][P1]") {
	TopoShape box1 = MakeBox(Point3(0., 0., 0.), Point3(2., 2., 2.));
	TopoShape box2 = MakeBox(Point3(1., 1., 0.), Point3(3., 3., 2.));
	BoolBRepFuse fuse(box1, box2);
	TopoShape shape1 = fuse.Shape();
	fuse.SimplifyResult();
	TopoShape shape2 = fuse.Shape();
	IndexSet<TopoShape> shape1Faces, shape2Faces;
	TopoExplorerTool::MapShapes(shape1, ShapeType::Face, shape1Faces);
	TopoExplorerTool::MapShapes(shape2, ShapeType::Face, shape2Faces);
	std::cout << shape1Faces.size() << "  " << shape2Faces.size() << std::endl;
	CHECK(shape1Faces.size() == 14);
	CHECK(shape2Faces.size() == 10);
}
#include<catch.hpp>
#include<testHelper.h>
#include <boolean/BoolBuilder.hpp>
#include <modeling/MakeBox.hpp>
#include <boolean/BoolBRepFuse.hpp>
#include <common/IndexSet.hpp>
#include <topology/TopoExplorerTool.hpp>
using namespace AMCAX;
TEST_CASE("case1: BoolBuilder added SimplifyResult() API at 3.6.0. ", "[boolean][BoolBuilder][P1]") {
	TopoShape box1 = MakeBox(Point3(0., 0., 0.), Point3(2., 2., 2.));
	TopoShape box2 = MakeBox(Point3(1., 1., 0.), Point3(3., 3., 2.));
	BoolBRepFuse fuse(box1, box2);
	TopoShape shape1 = fuse.Shape();
	fuse.SimplifyResult();
	TopoShape shape2 = fuse.Shape();
	IndexSet<TopoShape> shape1Faces, shape2Faces;
	TopoExplorerTool::MapShapes(shape1, ShapeType::Face, shape1Faces);
	TopoExplorerTool::MapShapes(shape2, ShapeType::Face, shape2Faces);
	std::cout << shape1Faces.size() << "  " << shape2Faces.size() << std::endl;
	CHECK(shape1Faces.size() == 14);
	CHECK(shape2Faces.size() == 10);
}