/* "AMCAX_API static bool Read(TopoShape& s, const std::string& file)\t @return True if the input process is succeed\n\t @param file The input file\n\t @param s The shape\n\t @brief Read a shape from a file\n,\n",
      */
 #include <catch.hpp>
#include<testHelper.h>
#include <topology/TopoShape.hpp>
#include <occtio/OCCTTool.hpp>
static bool ComparisonFields(const std::string& file1, const std::string& file2, const std::string& fields)
{
	ifstream file1Stream(file1);
	ifstream file2Stream(file2);
	if (file1Stream.is_open() == false || file2Stream.is_open() == false)
	{
		file1Stream.close();
		file2Stream.close();
		return false;
	}
	std::string line1, line2;
	while (std::getline(file1Stream, line1))
	{
		if (line1.find(fields) != std::string::npos) break;
	}
	while (std::getline(file2Stream, line2))
	{
		if (line2.find(fields) != std::string::npos) break;
	}
	file1Stream.close();
	file2Stream.close();
	return line1 == line2;
}
TEST_CASE("CASE3:Check occio read not exist file ", "[occtio][OCCTTool][p2]") {
	AMCAX::TopoShape shape;
	SECTION("OCCTIO::OCCTTool::Read") {
		bool isReadSuccess = AMCAX::OCCTIO::OCCTTool::Read(shape, INPUT_PATH_PREFIX"NOTEXIST.brep");
		CHECK(isReadSuccess == false);
	}}