/* "AMCAX_API Geom3BSplineSurface(const Array2<Point3>& pts, const std::vector<double>& uKnots, const std::vector<double>& vKnots, const std::vector<int>& uMults, const std::vector<int>& vMults, int uDegree, int vDegree, bool uPeriodic = false, bool vPeriodic = false)\t @param vPeriodic Set whether the surface is periodic along the v direction\n\t @param uPeriodic Set whether the surface is periodic along the u direction\n\t @param vDegree The v degree\n\t @param uDegree The u degree\n\t @param vMults The v multiplicities\n\t @param uMults The u multiplicities\n\t @param vKnots The v knots\n\t @param uKnots The u knots\n\t @param pts The poles\n\t @brief Construct a B spline surface from poles, knots and multiplicities\n,\n",
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
TEST_CASE("case1: Geom3BSplineSurface::Geom3BSplineSurface() ", "[geometry][Geom3BSplineSurface][p1]") {
	Array2<Point3> poles(5, 4);
	poles(0, 0).SetCoord(0.0, 0.0, 0.0);
	poles(0, 1).SetCoord(0.0, 1.1, 2.0);
	poles(0, 2).SetCoord(0.0, 2.3, 1.0);
	poles(0, 3).SetCoord(0.0, 3.1, 1.5);
	poles(1, 0).SetCoord(1.1, 0.1, 2.0);
	poles(1, 1).SetCoord(1.2, 1.0, 0.0);
	poles(1, 2).SetCoord(1.3, 2.1, -1.0);
	poles(1, 3).SetCoord(1.23, 3.04, 1.32);
	poles(2, 0).SetCoord(2.3, 0.1, -2.0);
	poles(2, 1).SetCoord(2.1, 1.4, 2.0);
	poles(2, 2).SetCoord(2.2, 2.1, 1.0);
	poles(2, 3).SetCoord(2.23, 3.22, 1.26);
	poles(3, 0).SetCoord(3.13, 0.2, 0.0);
	poles(3, 1).SetCoord(3.12, 1.1, 0.0);
	poles(3, 2).SetCoord(3.21, 2.1, 1.0);
	poles(3, 3).SetCoord(3.33, 3.21, -1.2);
	poles(4, 0).SetCoord(4.9, 4.93, 0.31);
	poles(4, 1).SetCoord(5.3, 4.73, 0.33);
	poles(4, 2).SetCoord(5.1, 4.43, -1.31);
	poles(4, 3).SetCoord(9.2, 4.65, 3.31);
	std::vector<double> uknots = { 0.0, 0.5, 1.0 };
	std::vector<int> umults = { 4, 1, 4 };
	std::vector<double> vknots = { 0.0, 0.5, 1.0 };
	std::vector<int> vmults = { 3, 1, 3 };
	std::shared_ptr<Geom3BSplineSurface> s = std::make_shared<Geom3BSplineSurface>(poles, uknots, vknots, umults, vmults, 3, 2);
	TopoFace face = MakeFace(s,0.001);
	bool bWriteresult = OCCTIO::OCCTTool::Write(face, OUTPUT_PATH_PREFIX"Geom3BSplineSurface_case1.brep");
	CHECK(bWriteresult == true);
	AMCAX::GlobalProperty prop;
	AMCAX::BRepGlobalProperty::SurfaceProperties(face, prop);
	CHECK(prop.Mass() == Approx( 21.3633));
}
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
TEST_CASE("case1: Geom3BSplineSurface::Geom3BSplineSurface() ", "[geometry][Geom3BSplineSurface][p1]") {
	Array2<Point3> poles(5, 4);
	poles(0, 0).SetCoord(0.0, 0.0, 0.0);
	poles(0, 1).SetCoord(0.0, 1.1, 2.0);
	poles(0, 2).SetCoord(0.0, 2.3, 1.0);
	poles(0, 3).SetCoord(0.0, 3.1, 1.5);
	poles(1, 0).SetCoord(1.1, 0.1, 2.0);
	poles(1, 1).SetCoord(1.2, 1.0, 0.0);
	poles(1, 2).SetCoord(1.3, 2.1, -1.0);
	poles(1, 3).SetCoord(1.23, 3.04, 1.32);
	poles(2, 0).SetCoord(2.3, 0.1, -2.0);
	poles(2, 1).SetCoord(2.1, 1.4, 2.0);
	poles(2, 2).SetCoord(2.2, 2.1, 1.0);
	poles(2, 3).SetCoord(2.23, 3.22, 1.26);
	poles(3, 0).SetCoord(3.13, 0.2, 0.0);
	poles(3, 1).SetCoord(3.12, 1.1, 0.0);
	poles(3, 2).SetCoord(3.21, 2.1, 1.0);
	poles(3, 3).SetCoord(3.33, 3.21, -1.2);
	poles(4, 0).SetCoord(4.9, 4.93, 0.31);
	poles(4, 1).SetCoord(5.3, 4.73, 0.33);
	poles(4, 2).SetCoord(5.1, 4.43, -1.31);
	poles(4, 3).SetCoord(9.2, 4.65, 3.31);
	std::vector<double> uknots = { 0.0, 0.5, 1.0 };
	std::vector<int> umults = { 4, 1, 4 };
	std::vector<double> vknots = { 0.0, 0.5, 1.0 };
	std::vector<int> vmults = { 3, 1, 3 };
	std::shared_ptr<Geom3BSplineSurface> s = std::make_shared<Geom3BSplineSurface>(poles, uknots, vknots, umults, vmults, 3, 2);
	TopoFace face = MakeFace(s,0.001);
	bool bWriteresult = OCCTIO::OCCTTool::Write(face, OUTPUT_PATH_PREFIX"Geom3BSplineSurface_case1.brep");
	CHECK(bWriteresult == true);
	AMCAX::GlobalProperty prop;
	AMCAX::BRepGlobalProperty::SurfaceProperties(face, prop);
	CHECK(prop.Mass() == Approx( 21.3633));
}