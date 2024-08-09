/* "AMCAX_API void InsertUKnot(double u, int m, double parametricTolerance, bool add = true)\t @param add If true, the multiplicity is an incremental value; if false, the multiplicity is a final value\n\t @param parametricTolerance The tolerance of parameters\n\t @param m The multiplicity of the knot to be inserted\n\t @param u The knot to be inserted\n\t @brief Insert a u knot\n,\n",
      */
 #include<catch.hpp>
#include<testHelper.h>
#include <modeling/MakeFace.hpp>
#include <geometry/Geom3BSplineSurface.hpp>
#include <topology/TopoFace.hpp>
#include <topology/TopoTool.hpp>
using namespace AMCAX;
TEST_CASE("bug1: Geom3BSplineSurface::InsertUKnot() ", "[geometry][Geom3BSplineSurface][fixbug]") {
	TopoFace face;
	OCCTIO::OCCTTool::Read(face, INPUT_PATH_PREFIX"face.brep");
	auto surf = TopoTool::Surface(face);
	auto bsp = std::dynamic_pointer_cast<Geom3BSplineSurface>(surf);
	bsp->InsertUKnot(0.23, 1, 0.0, true);
	bool bWriteresult = OCCTIO::OCCTTool::Write(face, OUTPUT_PATH_PREFIX"result.brep");
	CHECK(bWriteresult == true);
}