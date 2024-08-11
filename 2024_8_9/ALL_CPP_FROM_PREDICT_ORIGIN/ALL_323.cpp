 #include<catch.hpp>
#include<testHelper.h>
#include <topology/TopoShape.hpp>
#include <occtio/OCCTTool.hpp>
static bool ComparisonFields(const std::string& file1, const std::string& file2, const std::string& fields)
{
	std::ifstream in1(file1);
	if (!in1)
	{
		std::cout << "file " << file1 << " not exist" << std::endl;
		return false;
	}
	std::ifstream in2(file2);
	if (!in2)
	{
		std::cout << "file " << file2 << " not exist" << std::endl;
		return false;
	}
	std::string line1, line2;
	bool res = true;
	while (std::getline(in1, line1) && std::getline(in2, line2))
	{
		if (!line1.compare(fields) && !line2.compare(fields))
		{
			continue;
		}
		if (line1 != line2)
		{
			std::cout << "line1: " << line1 << std::endl;
			std::cout << "line2: " << line2 << std::endl;
			res = false;
			break;
		}
	}
	return res;
}
TEST_CASE("CASE2:OCCTIO::OCCTTool::Read(bool, TopoShape&, std::istream&) [1/10] ", "[occtio][OCCTTool][Read][P1]")
{
	TopoShape shape;
	OCCTIO::OCCTTool::Read(true, shape, INPUT_PATH_PREFIX"boolean/boolean.brep");
	TopoShape shape2;
	OCCTIO::OCCTTool::Read(true, shape2, INPUT_PATH_PREFIX"boolean/boolean.brep");
	CHECK(OCCTIO::OCCTTool::Write(shape, OUTPUT_PATH_PREFIX"OCCTIO_Read_01.brep"));
	CHECK(OCCTIO::OCCTTool::Write(shape2, OUTPUT_PATH_PREFIX"OCCTIO_Read_01_right.brep"));
	CHECK(OCCTIO::OCCTTool::Read(false, shape2, OUTPUT_PATH_PREFIX"OCCTIO_Read_01_right.brep"));
	CHECK(OCCTIO::OCCTTool::Read(false, shape, OUTPUT_PATH_PREFIX"OCCTIO_Read_01.brep"));
	CHECK(OCCTIO::OCCTTool::Read(false, shape, std::ifstream(OUTPUT_PATH_PREFIX"OCCTIO_Read_01.brep", std::ios::binary)));
	CHECK(OCCTIO::OCCTTool::Read(false, shape2, std::ifstream(OUTPUT_PATH_PREFIX"OCCTIO_Read_01_right.brep", std::ios::binary)));
	CHECK(OCCTIO::OCCTTool::Read(false, shape2, OUTPUT_PATH_PREFIX"OCCTIO_Read_01.brep"));
	CHECK(OCCTIO::OCCTTool::Read(false, shape, std::ifstream(INPUT_PATH_PREFIX"boolean/boolean.brep", std::ios::binary)));
	CHECK(OCCTIO::OCCTTool::Read(false, shape2, std::ifstream(INPUT_PATH_PREFIX"boolean/boolean.brep", std::ios::binary)));
	CHECK(OCCTIO::OCCTTool::Read(false, shape, std::wifstream(INPUT_PATH_PREFIX"boolean/boolean.brep", std::ios::binary)));
	CHECK(OCCTIO::OCCTTool::Read(false, shape2, std::wifstream(INPUT_PATH_PREFIX"boolean/boolean.brep", std::ios::binary)));
	CHECK(OCCTIO::OCCTTool::Read(false, shape, std::ifstream(INPUT_PATH_PREFIX"boolean/boolean.brep")));
	CHECK(OCCTIO::OCCTTool::Read(false, shape2, std::ifstream(INPUT_PATH_PREFIX"boolean/boolean.brep")));
	CHECK(OCCTIO::OCCTTool::Read(false, shape, std::wifstream(INPUT_PATH_PREFIX"boolean/boolean.brep")));
	CHECK(OCCTIO::OCCTTool::Read(false, shape2, std::wifstream(INPUT_PATH_PREFIX"boolean/boolean.brep")));
	std::string str1, str2;
	std::ifstream file1(INPUT_PATH_PREFIX"boolean/boolean.brep", std::ios::binary);
	std::ifstream file2(OUTPUT_PATH_PREFIX"OCCTIO_Read_01.brep", std::ios::binary);
	file1.seekg(-100, std::ios::end);
	file2.seekg(-100, std::ios::end);
	file1 >> std::ws >> str1;
	file2 >> std::ws >> str2;
	CHECK(str1 == str2);
}