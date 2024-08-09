/* "AMCAX_API static TopoShape FixShape(const TopoShape& shape, double prec, double maxTol)\t @return Fixed Shape\n\t @param maxTol The global max tolerance used when the algorithm needs to check the tolerance\n\t @param prec The global precision used when the algorithm needs to check the precision\n\t @param shape Input shape\n\t @brief Try to repair the shape to a valid shape\n,\n",
      */
 #include<catch.hpp>
#include<testHelper.h>
#include <healing/ShapeFixTool.hpp>
#include <common/Precision.hpp>
using namespace AMCAX;
TEST_CASE("bug1: ShapeFixTool ", "[healing][ShapeFixTool][fixbug]") {
	AMCAX::TopoShape readshape;
	AMCAX::OCCTIO::OCCTTool::Read(readshape, INPUT_PATH_PREFIX"FixShape-Crash.brep");
	readshape = AMCAX::ShapeFixTool::FixShape(readshape, AMCAX::Precision::Confusion(), 1E-1);
	AMCAX::OCCTIO::OCCTTool::Write(readshape, OUTPUT_PATH_PREFIX"ShapeFixTool_O_FixedShape.brep");
	GlobalProperty prop;
	BRepGlobalProperty::VolumeProperties(readshape, prop);
	CHECK(prop.Mass() == Approx(16486799.3305680156).epsilon(1e-2));
	Point3 vP = prop.CenterOfMass();
	CHECK(vP.X() == Approx(-260.8706721039).epsilon(1e-2));
	CHECK(vP.Y() == Approx(-154.6717940115).epsilon(1e-2));
	CHECK(vP.Z() == Approx(-0.1139512307).epsilon(1e-2));
}