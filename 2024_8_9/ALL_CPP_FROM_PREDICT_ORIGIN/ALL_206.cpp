 #include<catch.hpp>
#include<testHelper.h>
#include <modeling/MakeFace.hpp>
#include <hatch/BRepClassificationTools.hpp>
TEST_CASE("case1: MakeFace(sphere, wire) ", "[modeling][MakeFace][P1]")
{
    TopoShape sphere = ReadBRep(FIXTURE_PATH_PREFIX"sphere.brep");
    TopoWire wire = ReadBRep(FIXTURE_PATH_PREFIX"surfaceOfRevolution Wire.brep");
    TopoFace result = AMCAX::MakeFace(sphere, wire);
    AMCAX::GlobalProperty props1, props2;
    CHECK( GetSurfaceProperties(result, props1, true, false) == Approx( 509.88968745991299));
    CHECK( GetSurfaceProperties(result, props2, false, true) == Approx( 151.36350491200813));
    CHECK( GetVolumeProperties(result, props1, true, false) == Approx( 309.45733935399297));
    CHECK( GetSurfaceProperties(result, props2, false, true) == Approx( 0));
}