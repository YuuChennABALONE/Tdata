 #include<catch.hpp>
#include<testHelper.h>
#include <modeling/MakeFace.hpp>
#include <common/PointT.hpp>
#include <math/CurveCalculation.hpp>
#include <geometry/Geom3TrimmedCurve.hpp>
#include <modeling/MakeEdge.hpp>
#include <topology/TopoBuilder.hpp>
#include <modeling/MakeVertex.hpp>
#include <geometry/Geom3BezierCurve.hpp>
#include <geometry/Geom3BSplineCurve.hpp>
#include <topology/BRepExtremaDistShapeShape.hpp>
#include <topology/TopoTool.hpp>
#include <topology/TopoCast.hpp>
#include <topology/TopoTool.hpp>
#include <topology/TopoExplorerTool.hpp>
#include <topology/TopoExplorer.hpp>
#include <topology/TopoExplorerTool.hpp>
#include <topology/TopoVertex.hpp>
#include <topology/TopoEdge.hpp>
#include <topology/TopoWire.hpp>
#include <topology/TopoFace.hpp>
#include <topology/TopoShape.hpp>
#include <topology/TopoCompound.hpp>
#include <topology/TopoTool.hpp>
TEST_CASE("bug1: MakeFace ", "[modeling][MakeFace][fixbug]")
{
    double tol = 0.0;
    std::shared_ptr<Geom3Surface> s;
    {
        std::vector<Point3> poles;
        std::vector<int> mults;
        std::vector<double> weights;
        poles.push_back(Point3(0.0, 0.0, 0.0));
        poles.push_back(Point3(1.0, 1.0, 0.0));
        poles.push_back(Point3(2.0, 3.0, 0.0));
        poles.push_back(Point3(3.0, 1.0, 0.0));
        mults.push_back(1);
        mults.push_back(1);
        mults.push_back(1);
        mults.push_back(1);
        weights.push_back(1.0);
        weights.push_back(1.0);
        weights.push_back(1.0);
        weights.push_back(1.0);
        std::shared_ptr<Geom3BezierCurve> bcurve1 = std::make_shared<Geom3BezierCurve>(poles, mults, weights);
        std::shared_ptr<Geom3BezierCurve> bcurve2 = std::make_shared<Geom3BezierCurve>(poles, mults, weights);
        std::vector<std::shared_ptr<Geom3Curve>> curves;
        curves.push_back(bcurve1);
        curves.push_back(bcurve2);
        std::vector<double> crvD;
        crvD.push_back(0.0);
        crvD.push_back(0.0);
        std::shared_ptr<Geom3TrimmedCurve> rCurve = std::make_shared<Geom3TrimmedCurve>(bcurve1, crvD);
        std::shared_ptr<Geom3TrimmedCurve> rCurve2 = std::make_shared<Geom3TrimmedCurve>(bcurve2, crvD);
        std::vector<std::shared_ptr<Geom3Curve>> crv;
        crv.push_back(rCurve);
        crv.push_back(rCurve2);
        std::vector<double> sp;
        sp.push_back(0.0);
        sp.push_back(0.0);
        std::shared_ptr<Geom3Surface> surf = MakeSurface(crv, sp, tol);
        s = surf;
    }
    CHECK( MakeFace(s, tol) == nullptr);
}