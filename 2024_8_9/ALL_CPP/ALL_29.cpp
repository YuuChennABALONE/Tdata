/* "AMCAX_API TransformShape(const TopoShape& s, const Transformation3& tr, bool copyGeom = false, bool copyMesh = false)\t @param copyMesh Whether the mesh of the shape is copied\n\t @param copyGeom Whether the geometry of the shape is copied\n\t @param tr The transformation\n\t @param s The shape\n\t @brief Construct from a shape with a transformation\n,\n",
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
using namespace AMCAX;
TEST_CASE("bug1: TransformShape  ", "[modeling][TransformShape][fixbug]") {
	TopoShape s = MakeSphere(1.0);
	BRepMeshIncrementalMesh mesher(s, 0.005, true);
	MakeShapeTool::EnsureNormalConsistency(s);
	Transformation3 tr;
	tr.SetRotation(CartesianCoordinateSystem::OZ(), M_PI_2);
	s = TransformShape(s, tr, true, true);
	CHECK(s.IsNull() == false);
	CHECK(s.Type() == AMCAX::ShapeType::Solid);
	GlobalProperty prop;
	BRepGlobalProperty::VolumeProperties(s, prop);
	CHECK(prop.Mass() == Approx(4.1887902048).epsilon(1e-11));
	Point3 vP = prop.CenterOfMass();
#ifndef WIN_CASE
	CHECK(vP.X() == Approx(0.0).margin(1e-12));
	CHECK(vP.Y() == Approx(0.0).margin(1e-12));
	CHECK(vP.Z() == Approx(0.0).margin(1e-12));
#else
	CHECK(vP.X() == Approx(-4.0938241231662633e-18).epsilon(1e-12));
	CHECK(vP.Y() == Approx(-6.1820277995281757e-17).epsilon(1e-12));
	CHECK(vP.Z() == Approx(-3.1794228708137405e-17).epsilon(1e-12)); 
#endif
}