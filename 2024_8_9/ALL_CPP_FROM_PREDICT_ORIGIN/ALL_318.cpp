 #include<catch.hpp>
#include<testHelper.h>
#include <topology/TopoShape.hpp>
#include <occtio/OCCTTool.hpp>
static bool ComparisonFields(const std::string& file1, const std::string& file2, const std::string& fields)
{
	TopoShape shape1, shape2;
	bool read1 = OCCTIO::OCCTTool::Read(shape1, file1, fields);
	bool read2 = OCCTIO::OCCTTool::Read(shape2, file2, fields);
	if (read1 == false || read2 == false)
	{
		return false;
	}
	return shape1.Type() == shape2.Type() && shape1.Location() == shape2.Location() && shape1.IsNull() == shape2.IsNull() && shape1.Negative() == shape2.Negative();
}
TEST_CASE("CASE2: Check OCCTIO::OCCTTool::Read(bool& succ, TopoShape& shape, const std::string& file, const std::string& fields) read successfully ", "[occtio][OCCTTool][Read][P1]") {
	SECTION("Read sphere") {
		TopoShape sphere;
		bool read = OCCTIO::OCCTTool::Read(sphere, INPUT_PATH_PREFIX"OCCTIO/Sphere3.brep", "STANDARD");
		CHECK(read == true);
		CHECK(sphere.Type() == ShapeType::Sphere);
		CHECK(sphere.Location().X() == Approx(0.0));
		CHECK(sphere.Location().Y() == Approx(0.0));
		CHECK(sphere.Location().Z() == Approx(0.0));
		CHECK(sphere.Radius() == Approx(1.0));
	}}