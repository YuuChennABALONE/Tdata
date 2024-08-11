 #include<catch.hpp>
#include<testHelper.h>
#include <geometry/MakeConic2FromConstraints.hpp>
#include <math/HyperbolaT.hpp>
#include <geometry/Geom2Hyperbola.hpp>
#include <modeling/MakeEdge.hpp>
#include <geometry/Geom2TrimmedCurve.hpp>
#include <geometry/Geom2Ellipse.hpp>
#include <geometry/Geom2Parabola.hpp>
#include <geometry/Geom2Circle.hpp>
#include <hatch/BRepClassificationTools.hpp>
#include <geometry/Geom2Hyperbola.hpp>
#include <geometry/Geom2Ellipse.hpp>
#include <geometry/Geom2Parabola.hpp>
#include <geometry/Geom2Circle.hpp>
#include <geometry/Geom2TrimmedCurve.hpp>
#include <geometry/GeomAPIProjectPointOnCurve3.hpp>
#include <topology/BRepExtremaDistShapeShape.hpp>
#include <modeling/MakeEdge.hpp>
#include <geometry/GeomAPIProjectPointOnCurve3.hpp>
#include <geometry/GeomAPIProjectCurve3OnSurface.hpp>
#include <geometry/Geom2OffsetCurve.hpp>
#include <geometry/GeomAPIProjectCurve3OnSurface.hpp>
#include <topology/BRepExtremaDistShapeShape.hpp>
#include <topology/TopoTool.hpp>
#include <topology/TopoTool.hpp>
#include <topology/TopoCast.hpp>
#include <topology/TopoFace.hpp>
#include <modeling/MakeFace.hpp>
#include <modeling/MakeEdge.hpp>
#include <geometry/GeomAPIProjectPointOnCurve3.hpp>
#include <modeling/MakeEdge.hpp>
#include <geometry/GeomAPIProjectPointOnCurve3.hpp>
#include <modeling/MakeEdge.hpp>
using namespace AMCAX;
TEST_CASE("case1: MakeConic2FromConstraints ", "[geometry][MakeConic2FromConstraints][P1]") {
	SECTION("ellipse") {
        Conic2Constraint startConstraint(Point2(0.0, 1.0), Direction2(0.0, 1.0), 0.0);
        Conic2Constraint endConstraint(Point2(2.0, 1.0), Direction2(0.0, 1.0), 0.0);
        double ellipse = 0.0;
        MakeConic2FromConstraints mc2c2fsc(startConstraint, endConstraint, ellipse);
        GlobalProperty props1;
        GlobalProperty props2;
        double s = 0.0;
        double e = 100.0;
        double inc = 1.0;
        for (s; s <= e; s += inc) {
            double param = s;
            std::shared_ptr<Geom3Curve> curve;
            if (mc2c2fsc.IsEllipse(param, curve)) {
                if (curve) {
                    GlobalProperty props3;
                    CHECK(mc2c2fsc.EllipseProperties(param, props3));
                    CHECK(props1.Mass() == Approx(props3.Mass()));
                    CHECK(props1.SurfaceArea() == Approx(props3.SurfaceArea()));
                    CHECK(props1.Volume() == Approx(props3.Volume()));
                    CHECK(props1.Centroid() == Approx(props3.Centroid()));
                    CHECK(props1.Moments() == Approx(props3.Moments()));
                    CHECK(props1.RadiusOfCurvature() == Approx(props3.RadiusOfCurvature()));
                }
            }
        }
    }}