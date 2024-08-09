/* "AMCAX_API explicit GeneralTransformShape(const GeneralTransformation3& t)\t @param t The general transformation\n\t @brief Construct from a general transformation\n,\n",
      */
 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <modeling/MakeSphere.hpp>
#include <modeling/TransformShape.hpp>
#include <topomesh/BRepMeshIncrementalMesh.hpp>
#include <modeling/MakeShapeTool.hpp>
#include <common/TransformationT.hpp>
#include <common/CartesianCoordinateSystem.hpp>
#include <common/GeneralTransformationT.hpp>
#include <modeling/GeneralTransformShape.hpp>
#include <geometry/GlobalProperty.hpp>
#include <occtio/OCCTTool.hpp>
#include <topology/BRepGlobalProperty.hpp>
#include <geometry/Geom3BSplineCurve.hpp>
#include <modeling/MakeEdge.hpp>
#include <topology/TopoTool.hpp>
#include <topology/BRepAdaptorCurve3.hpp>
using namespace AMCAX;
TEST_CASE("bug1: GeneralTransformShape  ", "[modeling][GeneralTransformShape][fixbug]") {
	TopoShape s = MakeSphere(1.0);
	BRepMeshIncrementalMesh mesher(s, 0.005, true);
	MakeShapeTool::EnsureNormalConsistency(s);
	GeneralTransformation3 tr;
	tr.SetAffinity(Frame3(), 5.0);
	s = GeneralTransformShape(s, tr);
	CHECK(s.Type() == AMCAX::ShapeType::Solid);
	CHECK(s.IsNull() == false);
	GlobalProperty prop;
	BRepGlobalProperty::VolumeProperties(s, prop);
	CHECK(prop.Mass() == Approx(20.934791259).epsilon(1e-11));
	Point3 vP = prop.CenterOfMass();
#ifndef WIN_CASE
	CHECK(vP.X() == Approx(0.0).margin(1e-3));
	CHECK(vP.Y() == Approx(0.0).margin(1e-12));
	CHECK(vP.Z() == Approx(0.0).margin(1e-12));
#else
	CHECK(vP.X() == Approx(-2.2218808037914858e-04).epsilon(1e-12));
	CHECK(vP.Y() == Approx(-1.0782779568197278e-16).epsilon(1e-12));
	CHECK(vP.Z() == Approx(-1.6920954211916623e-16).epsilon(1e-12));
#endif
}