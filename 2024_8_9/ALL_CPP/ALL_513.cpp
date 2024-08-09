/* "AMCAX_API BoolBRepDefeaturing()\t @brief Default constructor\n,\n",
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
TEST_CASE("bug1: BoolBRepDefeaturing ", "[boolean][BRepDefeaturing]")
{
	TopoShape box = MakeBox(Point3(-5.0, -5.0, 0.0), Point3(5.0, 5.0, 3.0));
	TopoShape cyl = MakeCylinder(Frame3(Point3(0.0, 0.0, 0.0), Direction3(0.0, 0.0, 1.0)), 3.0, 5.0);
	TopoShape shape = BoolBRepCut(box, cyl);
	AMCAX::GlobalProperty prop1, prop2, prop3, prop4, prop5, prop6;
	BRepGlobalProperty::LinearProperties(box, prop1, true, true);
	BRepGlobalProperty::LinearProperties(box, prop2, true, false);
	double result1 = prop1.Mass();
	double result2 = prop2.Mass();
	CHECK(result1 == Approx(10 * 8 + 3 * 4));
	CHECK(result2 == Approx(10 * 8 + 3 * 4));
	BRepGlobalProperty::SurfaceProperties(box, prop3, true, true);
	BRepGlobalProperty::SurfaceProperties(box, prop4, true, false);
	double result3 = prop3.Mass();
	double result4 = prop4.Mass();
	CHECK(result3 == Approx(2 * (10 * 10) + 4 * (10 * 3)));
	CHECK(result4 == Approx(2 * (10 * 10) + 4 * (10 * 3)));
	BRepGlobalProperty::VolumeProperties(box, prop5, true, true);
	BRepGlobalProperty::VolumeProperties(box, prop6, true, false);
	double result5 = prop5.Mass();
	double result6 = prop6.Mass();
	CHECK(result5 == Approx(10 * 10 * 3));
	CHECK(result6 == Approx(10 * 10 * 3));
}