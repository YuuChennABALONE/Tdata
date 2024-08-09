/* "AMCAX_API BoolBRepCut(const TopoShape& s1, const TopoShape& s2, bool isForward = true)\t @param isForward Cut s1 by s2 if true, and cut s2 by s1 if false\n\t @param s2 The tool shape\n\t @param s1 The argument shape\n\t @brief Compute the cut operation of two shapes\n,\n",
      */
 #include<catch.hpp>
#include<testHelper.h>
#include <boolean/BoolBRepCut.hpp>
#include <modeling/MakeTorus.hpp>
#include <modeling/MakeSphere.hpp>
#include <modeling/MakeCone.hpp>
#include <topology/TopoExplorer.hpp>
#include <topology/TopoFace.hpp>
#include <hatch/BRepClassificationTools.hpp>
using namespace AMCAX;
TEST_CASE("bug1: in Debug mode: BoolBuilder  ", "[boolean][BoolBRepCut][P1][fixbug]") {
	TopoShape torus = MakeTorus(Frame3(Point3(0.0, 0.0, 2.0), Direction3(1.0, 0.0, 0.0)), 4.0, 2.0);
	TopoShape sphere = MakeSphere(4.0);
	TopoShape result = BoolBRepCut(sphere, torus);
	AMCAX::GlobalProperty prop;
	AMCAX::BRepGlobalProperty::VolumeProperties(result, prop);
	CHECK(prop.Mass() == Approx(153.229)); 
	bool isWriteSuccess = AMCAX::OCCTIO::OCCTTool::Write(result, OUTPUT_PATH_PREFIX"BoolBRepCut_bug72.brep", false);
	CHECK(isWriteSuccess == true);
}