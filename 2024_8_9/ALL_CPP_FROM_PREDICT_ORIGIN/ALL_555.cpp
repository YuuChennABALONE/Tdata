 #include<catch.hpp>
#include<testHelper.h>
#include <modeling/MakeEdge.hpp>
#include <geometry/Geom3BSplineCurve.hpp>
#include <geometry/Geom3BSplineSurface.hpp>
#include <geometry/GeometryTool.hpp>
#include <geometry/GeomAPIInterpolate.hpp>
#include <topology/TopoEdge.hpp>
#include <topology/TopoFace.hpp>
#include <hatch/BRepClassificationTools.hpp>
#include <geometry/Geom3CylindricalSurface.hpp>
#include <geometry/Geom3HyperbolicSurface.hpp>
#include <geometry/Geom3QuadricSurface.hpp>
#include <geometry/Geom3SphericalSurface.hpp>
#include <geometry/Geom3TrimmedCurve.hpp>
#include <geometry/Geom3EllipticalSurface.hpp>
#include <geometry/Geom3SphericalSurface.hpp>
#include <geometry/Geom3Plane.hpp>
#include <topology/TopoTool.hpp>
#include <topology/TopoFace.hpp>
#include <modeling/MakeFace.hpp>
#include <modeling/MakeEdge.hpp>
#include <topology/TopoExplorer.hpp>
#include <topology/TopoExplorerTool.hpp>
#include <topology/TopoExplorerTool.hpp>
#include <topology/TopoTool.hpp>
#include <topology/TopoShape.hpp>
#include <topology/TopoCast.hpp>
#include <topology/TopoFace.hpp>
#include <topology/TopoEdge.hpp>
#include <topology/TopoExplorer.hpp>
TEST_CASE("SweepWithCurveOnTangencySurface: test surface type ", "[geometry][SweepWithCurveOnTangencySurface][p1]") {
	SECTION("CylindricalSurface") {
        std::shared_ptr<Geom3BSplineCurve> guideCurve = ReadBRepCurve(case060_CylindricalSurface_file);
        CHECK(guideCurve->IsPeriodic() == true);
        CHECK(guideCurve->Length() == Approx(20.942));
        CHECK(guideCurve->Period() == Approx(2 * M_PI));
        std::shared_ptr<Geom3BSplineSurface> surface = SweepWithCurveOnTangencySurface(guideCurve, case060_CylindricalSurface_surface, case060_CylindricalSurface_radiusLaw, case060_CylindricalSurface_angle1Law, case060_CylindricalSurface_angle2Law, nullptr, 0.0, 20.942);
        CHECK(surface->IsCylindricalSurface() == true);
        CHECK(static_cast<const Geom3CylindricalSurface&>(*surface).Location().X() == Approx(0.0));
        CHECK(static_cast<const Geom3CylindricalSurface&>(*surface).Location().Y() == Approx(0.0));
        CHECK(static_cast<const Geom3CylindricalSurface&>(*surface).Location().Z() == Approx(0.0));
        CHECK(static_cast<const Geom3CylindricalSurface&>(*surface).MajorRadius() == Approx(2.0));
        CHECK(static_cast<const Geom3CylindricalSurface&>(*surface).MinorRadius() == Approx(1.0));
    }}