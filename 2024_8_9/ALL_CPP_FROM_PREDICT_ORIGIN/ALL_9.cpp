 #include<catch.hpp>
#include<testHelper.h>
#include <boolean/BoolBRepSection.hpp>
#include <common/CartesianCoordinateSystem.hpp>
#include <common/Transformation.hpp>
#include <topology/TopoEdge.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeVertex.hpp>
#include <common/PointT.hpp>
#include <hatch/BRepClassificationTools.hpp>
#include <modeling/MakeFace.hpp>
#include <topology/TopoFace.hpp>
#include <common/AxisT.hpp>
#include <topology/TopoTool.hpp>
#include <topology/TopoVertex.hpp>
#include <modeling/MakeVertex.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeWire.hpp>
#include <geometry/Geom3BezierCurve.hpp>
#include <modeling/MakeShape.hpp>
#include <occtio/OCCTTool.hpp>
#include <topomesh/BRepMeshIncrementalMesh.hpp>
#include <topology/TopoTool.hpp>
#include <topology/TopoExplorer.hpp>
#include <topology/TopoShape.hpp>
#include <math/Sphere.hpp>
#include <geometry/Geom3BSplineCurve.hpp>
#include <geometry/Geom3Circle.hpp>
#include <geometry/Geom3Line.hpp>
#include <geometry/Geom3TrimmedCurve.hpp>
#include <geometry/Geom3Ellipse.hpp>
#include <geometry/Geom3Hyperbola.hpp>
#include <geometry/Geom3Parabola.hpp>
#include <geometry/Geom3BezierCurve.hpp>
#include <geometry/Geom3BSplineCurve.hpp>
#include <geometry/Geom3OffsetCurve.hpp>
#include <geometry/Geom3SphericalSurface.hpp>
#include <geometry/Geom3SurfaceOfExtrusion.hpp>
#include <geometry/Geom3Plane.hpp>
#include <geometry/Geom3Cone.hpp>
#include <geometry/Geom3Cylinder.hpp>
#include <geometry/Geom3Sphere.hpp>
#include <geometry/Geom3Torus.hpp>
#include <geometry/Geom3TrimmedSurface.hpp>
#include <geometry/Geom3BezierSurface.hpp>
#include <geometry/Geom3BSplineSurface.hpp>
#include <geometry/Geom3OffsetSurface.hpp>
#include <geometry/Geom3SurfaceOfExtrusion.hpp>
#include <geometry/Geom3SurfaceOfRevolution.hpp>
using namespace AMCAX;
TEST_CASE("bug1: BoolBRepSection ", "[boolean][BoolBRepSection][fixbug]") {
	TopoEdge e1, e2;
	OCCTIO::OCCTTool::Read(e1, INPUT_PATH_PREFIX"edge.brep");
	OCCTIO::OCCTTool::Read(e2, INPUT_PATH_PREFIX"edge2.brep");
	{
		TopoEdge e;
		BoolBRepSection bbrs;
		bbrs.Build(e1, e2);
		CHECK(bbrs.NBGeneral() == 1);
		CHECK(bbrs.NBGeneral(1) == 1);
		CHECK(bbrs.NBGeneral(2) == 0);
		CHECK(bbrs.NBGeneral(3) == 0);
		AMCAX::GlobalProperty prop1;
		AMCAX::GlobalProperty prop2;
		AMCAX::GlobalProperty prop3;
		bbrs.LinearProperties(1, prop1);
		bbrs.LinearProperties(2, prop2);
		bbrs.LinearProperties(3, prop3);
		CHECK(prop1.Mass() == Approx(0.0));
		CHECK(prop2.Mass() == Approx(0.0));
		CHECK(prop3.Mass() == Approx(0.0));
	}
}