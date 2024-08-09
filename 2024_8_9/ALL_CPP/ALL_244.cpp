/* "AMCAX_API static bool Write(const TopoShape& s, const std::string& file, int format = 3)\t @return True if the output process is succeed\n\t @param format The format version\n\t @param file The output file\n\t @param s The shape\n\t @brief Write a shape to a file\n,\n",
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
TEST_CASE("CASE1:Check occtio read and write normal brep file function with different param ", "[occtio][OCCTTool][p1][XXX]") {
	AMCAX::TopoShape shape;
	bool isReadSuccess = AMCAX::OCCTIO::OCCTTool::Read(shape, INPUT_PATH_PREFIX"occtio/occtio_read_I_brephaveMesh-case1.brep");
	bool isWriteSuccess1f = AMCAX::OCCTIO::OCCTTool::Write(shape, OUTPUT_PATH_PREFIX"occtio_write_O_brephaveMesh-f1-f-case1.brep", false, 1);
	bool isWriteSuccess2f = AMCAX::OCCTIO::OCCTTool::Write(shape, OUTPUT_PATH_PREFIX"occtio_write_O_brephaveMesh-f2-f-case1.brep", false, 2);
	bool isWriteSuccess3f = AMCAX::OCCTIO::OCCTTool::Write(shape, OUTPUT_PATH_PREFIX"occtio_write_O_brephaveMesh-f3-f-case1.brep", false, 3);
	bool isWriteSuccess1t = AMCAX::OCCTIO::OCCTTool::Write(shape, OUTPUT_PATH_PREFIX"occtio_write_O_brephaveMesh-f1-t-case1.brep", true, 1);
	bool isWriteSuccess2t = AMCAX::OCCTIO::OCCTTool::Write(shape, OUTPUT_PATH_PREFIX"occtio_write_O_brephaveMesh-f2-t-case1.brep", true, 2);
	bool isWriteSuccess3t = AMCAX::OCCTIO::OCCTTool::Write(shape, OUTPUT_PATH_PREFIX"occtio_write_O_brephaveMesh-f3-t-case1.brep", true, 3);
	CHECK(isReadSuccess == true);
	CHECK(isWriteSuccess1f == true);
	CHECK(isWriteSuccess2f == true);
	CHECK(isWriteSuccess3f == true);
	CHECK(containsStringInFile(OUTPUT_PATH_PREFIX"occtio_write_O_brephaveMesh-f1-f-case1.brep", "Triangulations 0") == true);
	CHECK(containsStringInFile(OUTPUT_PATH_PREFIX"occtio_write_O_brephaveMesh-f1-f-case1.brep", "CASCADE Topology V1, (c) Matra-Datavision") == true);
	CHECK(containsStringInFile(OUTPUT_PATH_PREFIX"occtio_write_O_brephaveMesh-f2-f-case1.brep", "Triangulations 0") == true);
	CHECK(containsStringInFile(OUTPUT_PATH_PREFIX"occtio_write_O_brephaveMesh-f2-f-case1.brep", "CASCADE Topology V2, (c) Matra-Datavision") == true);
	CHECK(containsStringInFile(OUTPUT_PATH_PREFIX"occtio_write_O_brephaveMesh-f3-f-case1.brep", "Triangulations 0") == true);
	CHECK(containsStringInFile(OUTPUT_PATH_PREFIX"occtio_write_O_brephaveMesh-f3-f-case1.brep", "CASCADE Topology V3, (c) Open Cascade") == true);
	CHECK(isWriteSuccess1t == true);
	CHECK(isWriteSuccess2t == true);
	CHECK(isWriteSuccess3t == true);
	CHECK(containsStringInFile(OUTPUT_PATH_PREFIX"occtio_write_O_brephaveMesh-f1-t-case1.brep", "Triangulations 0") == false);
	CHECK(containsStringInFile(OUTPUT_PATH_PREFIX"occtio_write_O_brephaveMesh-f1-t-case1.brep", "CASCADE Topology V1, (c) Matra-Datavision") == true);
	CHECK(containsStringInFile(OUTPUT_PATH_PREFIX"occtio_write_O_brephaveMesh-f2-t-case1.brep", "Triangulations 0") == false);
	CHECK(containsStringInFile(OUTPUT_PATH_PREFIX"occtio_write_O_brephaveMesh-f2-t-case1.brep", "CASCADE Topology V2, (c) Matra-Datavision") == true);
	CHECK(containsStringInFile(OUTPUT_PATH_PREFIX"occtio_write_O_brephaveMesh-f3-t-case1.brep", "Triangulations 0") == false);
	CHECK(containsStringInFile(OUTPUT_PATH_PREFIX"occtio_write_O_brephaveMesh-f3-t-case1.brep", "CASCADE Topology V3, (c) Open Cascade") == true);
}