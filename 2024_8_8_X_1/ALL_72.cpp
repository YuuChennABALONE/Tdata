/* "AMCAX_API static bool IsSolidBounded(const TopoSolid& s)\t @return True if the solid and the solid is bounded (The infinite point is outside);\n\t @param s The solid\n\t @brief Classify whether the solid is bounded (The infinite point is outside)\n,\n",
      */
 #include<catch.hpp>
#include<testHelper.h>
#include <io/ShapeTool.hpp>
#include <hatch/BRepClassificationTools.hpp>
#include <occtio/OCCTTool.hpp>
#include <topology/TopoShape.hpp>
#include <topology/TopoSolid.hpp>
#include <modeling/MakeSolid.hpp>
#include <modeling/MakeCylinder.hpp>
#include <boolean/BoolBRepFuse.hpp>
#include <boolean/BoolBRepCut.hpp>
#include <topomesh/BRepMeshIncrementalMesh.hpp>
#include <io/OBJTool.hpp>
#include <hatch/BRepSolidClassifier.hpp>
#include <healing/ShapeFixTool.hpp>
using namespace AMCAX;
bool ImpInSolid1(const Point3& pt)
{
	Point3 pc1(849.32865292949998, -105.60711735517, 528.53715478963011);
	Coord3 cs1 = pt.Coord() - pc1.Coord();
	bool isSolidIn1 = pt.Y() < 29.654882644830003 && pt.Y() > -105.60711735517 && (cs1.X() * cs1.X() + cs1.Z() * cs1.Z()) < 5.415 * 5.415;
	Point3 pc2(849.32865292763006, 12.992882644829002, 528.53715479109997);
	Coord3 cs2 = pt.Coord() - pc2.Coord();
	bool isSolidIn2 = pt.Z() < 543.83715479110003 && pt.Z() > 528.53715479109997 && (cs2.X() * cs2.X() + cs2.Y() * cs2.Y()) < 5.415 * 5.415;
	return isSolidIn1 || isSolidIn2;
}
Point3 SampleMethodCircle1()
{
	double u = (double)rand() / RAND_MAX * 4 - 0.5;
	double r = (double)rand() / RAND_MAX * 0.00002 + 5.41499;
	double x = 849.32865292949998 + r * std::cos(u);
	double z = 528.53715478963011 + r * std::sin(u);
	double y = (double)rand() / RAND_MAX * 136 - 106;
	return Point3(x, y, z);
}
TEST_CASE("bug: BRepClassificationTools::IsSolidBounded  related :", "[hatch][BRepClassificationTools][fixbug]") {
	AMCAX::TopoShape readshape;
	bool readstatus = AMCAX::OCCTIO::OCCTTool::Read(readshape, INPUT_PATH_PREFIX"0000-beforeFixShape.brep");
	CHECK(readstatus == true);
	readshape = AMCAX::ShapeFixTool::FixShape(readshape, AMCAX::Precision::Confusion(), 1E-1);
	AMCAX::TopoSolid readsolid = AMCAX::MakeSolid(AMCAX::TopoCast::Shell(readshape));
	CHECK(AMCAX::BRepClassificationTools::IsSolidBounded(readsolid) == true);
}