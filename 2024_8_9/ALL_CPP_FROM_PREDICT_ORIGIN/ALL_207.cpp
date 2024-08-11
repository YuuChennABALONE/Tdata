 #include<catch.hpp>
#include<testHelper.h>
#include <modeling/MakeFace.hpp>
#include <hatch/BRepClassificationTools.hpp>
TEST_CASE("bug1: MakeFace ", "[modeling][MakeFace][fixbug]")
{
	TopoShape torus = GetShapeByBRepReaderFromASSET(INPUT_PATH_PREFIX"torus.brep");
	TopoWire wire = GetShapeByBRepReaderFromASSET(INPUT_PATH_PREFIX"edge2Wire.brep", 1);
	TopoFace face = AMCAX::MakeFace(torus, wire, true);
	CHECK(BRepClassificationTools::IsPointInOnFace(face, Point3(0.0, 1.0, 0.0), 0.0));
}