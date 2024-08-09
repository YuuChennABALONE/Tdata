/* "AMCAX_API BoolBRepCut()\t @details Only set the type of boolean operation to cut\n\t @brief Default constructor\n,\n",
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