 #include<catch.hpp>
#include<testHelper.h>
#include <boolean/BoolBRepDefeaturing.hpp>
#include <modeling/MakeTorus.hpp>
#include <modeling/MakeSphere.hpp>
#include <modeling/MakeCone.hpp>
#include <topology/TopoExplorer.hpp>
#include <topology/TopoFace.hpp>
#include <hatch/BRepClassificationTools.hpp>
using namespace AMCAX;
TEST_CASE("bug1: BoolBRepDefeaturing ", "[boolean][BoolBRepDefeaturing][fixbug]")
{
	TopoShape torus = MakeTorus(Frame3(Point3(0.0, 0.0, 2.0), Direction3(1.0, 0.0, 0.0)), 4.0, 2.0);
	TopoShape sphere = MakeSphere(4.0);
	TopoShape result = BoolBRepDefeaturing( torus, sphere, true, true );
	OUTPUT_DIRECTORY(boolean, BoolBRepDefeaturing, fixbug);
	CHECK( OCCTIO::OCCTTool::Write(result, outdir + "BoolBRepDefeaturing_result.brep"));
	TopoShape shape = ReadBRep(outdir"BoolBRepDefeaturing_result.brep");
	AMCAX::GlobalProperty prop;
	AMCAX::BRepGlobalProperty::VolumeProperties(shape, prop);
	CHECK(prop.Mass() == Approx(153.289481933));
}