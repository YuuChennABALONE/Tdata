 #include<catch.hpp>
#include<testHelper.h>
#include <nurbs/NURBSAPIApprox.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeVertex.hpp>
#include <geometry/Geom3BSplineCurve.hpp>
#include <geometry/Geom3BSplineSurface.hpp>
#include <topology/BRepExtremaDistShapeShape.hpp>
#include <common/PointT.hpp>
#include <common/TransformationT.hpp>
#include <topology/TopoTool.hpp>
#include <topology/TopoCast.hpp>
#include <io/STLTool.hpp>
#include <common/IndexSet.hpp>
#include <topology/TopoExplorer.hpp>
#include <topology/TopoFace.hpp>
#include <topology/TopoTool.hpp>
#include <topology/TopoCast.hpp>
#include <geometry/Geom3Surface.hpp>
#include <geometry/Geom3BSplineCurve.hpp>
TEST_CASE("bug1: Approx 3D 10/25/2020", "[nurbs][Approx][fixbug]")
{
    std::vector<Point3> poles;
    poles.push_back(Point3(0.0, 0.0, 0.0));
    poles.push_back(Point3(1.0, 0.0, 0.0));
    poles.push_back(Point3(2.0, 0.0, 0.0));
    poles.push_back(Point3(3.0, 0.0, 0.0));
    poles.push_back(Point3(4.0, 0.0, 0.0));
    poles.push_back(Point3(5.0, 0.0, 0.0));
    poles.push_back(Point3(6.0, 0.0, 0.0));
    poles.push_back(Point3(7.0, 0.0, 0.0));
    poles.push_back(Point3(8.0, 0.0, 0.0));
    poles.push_back(Point3(9.0, 0.0, 0.0));
    std::shared_ptr<Geom3BSplineCurve> curve = NURBSAPIApprox::ApproxPoints(poles, 3, 3);
    OUTPUT_BREP/")"
    CHECK((static_cast<const Geom3BSplineCurve&>(curve)).Degree() == 3);
    CHECK((static_cast<const Geom3BSplineCurve&>(curve)).N poles() == 3);
    CHECK(((static_cast<const Geom3BSplineCurve&>(curve)).StartParameter() == 0.0));
    CHECK(((static_cast<const Geom3BSplineCurve&>(curve)).LastParameter() == 3.0));
    Point3 p(9.0, 0.0, 0.0);
    CHECK(curve->Value(9.0).IsEqual(p, 1e-5 * 1e-5) == false);
    CHECK(curve->Value(3.0).IsEqual(p, 1e-5 * 1e-5) == true);
    CHECK(curve->Length() == Approx(9.0));
    OUTPUT_BREP)
}