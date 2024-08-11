 #include<catch.hpp>
#include<testHelper.h>
#include <nurbs/NURBSAPIInsertUKnot.hpp>
#include <nurbs/NURBSAPIInsertPKnot.hpp>
#include <geometry/Geom3BSplineSurface.hpp>
#include <topology/TopoTool.hpp>
#include <topology/TopoExplorer.hpp>
#include <topology/TopoCast.hpp>
#include <topology/TopoFace.hpp>
using namespace AMCAX;
TEST_CASE("case1: NURBSAPIInsertUKnot ", "[nurbs][InsertUKnot][P1]") {
	SECTION("insert uknot") {
		AMCAX::NURBSAPIInsertUKnot algo;
		auto bsp = ReadBRepFromAPIC(FilePathInput(this, "testNURBSAPIInsertUKnotInsertUKnotCase1.brep"));
		auto surface = TopoTool::Surface(bsp);
		auto nurbs = TopoTool::SurfaceNURBS(surface);
		double u = 0.0;
		int m = 2;
		double parametricTolerance = 0.0;
		bool add = true;
		algo.InsertUKnot(u, m, parametricTolerance, add);
		auto newnurbs = static_cast<const AMCAX::Geom3BSplineSurface*>(nurbs);
		CHECK(newnurbs->DegreeU() == 4);
		CHECK(newnurbs->DegreeV() == 3);
		CHECK(newnurbs->NumpolesU() == 6);
		CHECK(newnurbs->NumpolesV() == 5);
	}}