 #include<catch.hpp>
#include<testHelper.h>
#include <modeling/MakeFace.hpp>
#include <common/PointT.hpp>
#include <topology/BRepGlobalProperty.hpp>
TEST_CASE("bug1: MakeFace ", "[modeling][MakeFace][fixbug]")
{
	SECTION("Plane z 0")
	{
		TopoShape shape;
		TopoFace face;
		{
			TopoShape shape;
			TopoFace face;
			MakeFace shape, face, Plane(Point3(0.0, 0.0, 0.0), Direction3(0.0, 0.0, 1.0));
			CHECK(face.Type() == ShapeType::Face);
			CHECK(face.Area() == Approx(0.0));
		}}
}