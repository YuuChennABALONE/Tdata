/* "AMCAX_API static std::pair<NURBSSweepStatus, std::shared_ptr<Geom3BSplineSurface>> SweepWithTwoGuideCurves( const std::shared_ptr<Geom3BSplineCurve>& profile, const std::shared_ptr<Geom3BSplineCurve>& guide1, const std::shared_ptr<Geom3BSplineCurve>& guide2, Point3 anchorPoint1, Point3 anchorPoint2, const std::shared_ptr<Geom3BSplineCurve>& spine, double spineLeftBound, double spineRightBound),\n",
      */
 #include<catch.hpp>
#include<testHelper.h>
#include <filesystem>
#include <fstream>
#include <random>
#include <sstream>
#include <nurbs/NURBSAPIGetGeometry.hpp>
#include <nurbs/NURBSAPIConicalSweep.hpp>
#include <boolean/BoolBRepCut.hpp>
#include <common/CartesianCoordinateSystem.hpp>
#include <common/IndexMap.hpp>
#include <common/QuaternionT.hpp>
#include <geomAlgo/LawBSpline.hpp>
#include <geomAlgo/LawConstant.hpp>
#include <nurbs/NURBSAPISmooth.hpp>
#include <geomAlgo/MakeConic2FromConstraints.hpp>
#include <geometry/Adaptor3CurveOnSurface.hpp>
#include <geometry/AdaptorGeom2Curve.hpp>
#include <geometry/AdaptorGeom3Surface.hpp>
#include <geometry/Geom2BSplineCurve.hpp>
#include <geometry/Geom2Circle.hpp>
#include <geometry/Geom2Ellipse.hpp>
#include <geometry/Geom2Hyperbola.hpp>
#include <geometry/Geom2Parabola.hpp>
#include <geometry/Geom2TrimmedCurve.hpp>
#include <geometry/Geom3BSplineCurve.hpp>
#include <geometry/Geom3BSplineSurface.hpp>
#include <geometry/Geom3Circle.hpp>
#include <geometry/Geom3Line.hpp>
#include <geometry/Geom3OffsetCurve.hpp>
#include <geometry/Geom3Plane.hpp>
#include <geometry/Geom3SphericalSurface.hpp>
#include <geometry/Geom3Surface.hpp>
#include <geometry/Geom3TrimmedCurve.hpp>
#include <geometry/Geom3TrimmedSurface.hpp>
#include <geometry/GeomAPIExtremaCurveCurve3.hpp>
#include <geometry/GeomAPIProjectPointOnCurve2.hpp>
#include <geometry/GeomAPIProjectPointOnCurve3.hpp>
#include <geometry/GeomAPIProjectPointOnSurface.hpp>
#include <geometry/GeometryTool.hpp>
#include <geometry/GlobalProperty.hpp>
#include <healing/ShapeFixTool.hpp>
#include <io/STLTool.hpp>
#include <math/Sphere.hpp>
#include <math/TriangularMesh.hpp>
#include <modeling/CopyShape.hpp>
#include <modeling/MakeBox.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeFace.hpp>
#include <modeling/MakePrism.hpp>
#include <modeling/MakeRevol.hpp>
#include <modeling/MakeShapeTool.hpp>
#include <modeling/MakeVertex.hpp>
#include <modeling/MakeWire.hpp>
#include <modeling/TransformShape.hpp>
#include <nurbs/NURBSAPIApprox.hpp>
#include <nurbs/NURBSAPIBuildCurve.hpp>
#include <nurbs/NURBSAPICircularSweep.hpp>
#include <nurbs/NURBSAPIConvert.hpp>
#include <nurbs/NURBSAPICurveNetworkSurface.hpp>
#include <nurbs/NURBSAPIExplicitSweep.hpp>
#include <nurbs/NURBSAPIExplode.hpp>
#include <nurbs/NURBSAPIExtend.hpp>
#include <nurbs/NURBSAPIInterpolate.hpp>
#include <nurbs/NURBSAPIJoin.hpp>
#include <nurbs/NURBSAPILinearSweep.hpp>
#include <nurbs/NURBSAPILoft.hpp>
#include <nurbs/NURBSAPIMakeNURBSFromBoundaries.hpp>
#include <nurbs/NURBSAPIMatch.hpp>
#include <nurbs/NURBSAPIModifyEndToPlane.hpp>
#include <nurbs/NURBSAPIOffsetCurveOnSurface.hpp>
#include <nurbs/NURBSAPIProject.hpp>
#include <nurbs/NURBSAPIRebuild.hpp>
#include <nurbs/NURBSAPIReplaceEdge.hpp>
#include <nurbs/NURBSAPISweep.hpp>
#include <nurbs/NURBSAPISweep2.hpp>
#include <nurbs/NURBSAPISweepRotation.hpp>
#include <nurbs/NURBSAPITrim.hpp>
#include <nurbs/NURBSAPIUntrim.hpp>
#include <nurbs/NURBSLinearSweepWithDraftDirectionLength.hpp>
#include <occtio/OCCTTool.hpp>
#include <offset/MakePipe.hpp>
#include <offset/MakePipeShell.hpp>
#include <topology/BRepAdaptorCurve2.hpp>
#include <topology/BRepAdaptorCurve3.hpp>
#include <topology/BRepAdaptorSurface.hpp>
#include <topology/BRepGlobalProperty.hpp>
#include <topology/BRepTool.hpp>
#include <topology/TopoBuilder.hpp>
#include <topology/TopoCompound.hpp>
#include <topology/TopoEdge.hpp>
#include <topology/TopoExplorer.hpp>
#include <topology/TopoExplorerTool.hpp>
#include <topology/TopoFace.hpp>
#include <topology/TopoShape.hpp>
#include <topology/TopoShell.hpp>
#include <topology/TopoTool.hpp>
#include <topology/TopoVertex.hpp>
#include <topology/TopoWire.hpp>
#include <topology/WireExplorer.hpp>
#include <topomesh/BRepMeshIncrementalMesh.hpp>
#include <nurbs/NURBSAPIBlend.hpp>
#include <topology/BRepExtremaDistShapeShape.hpp>
#include <math/LineT.hpp>
#include <hatch/BRepClassificationTools.hpp>
using namespace AMCAX;
namespace
{
	std::shared_ptr<Geom3BSplineCurve> CurveChooser(const int id, const std::shared_ptr<Geom3BSplineCurve>& curve0, const std::shared_ptr<Geom3BSplineCurve>& curve1, const std::shared_ptr<Geom3BSplineCurve>& curve2)
	{
		std::shared_ptr<Geom3BSplineCurve> result;
		switch (id)
		{
		case 0:
		{
			result = curve0;
			break;
		}
		case 1:
		{
			result = curve1;
			break;
		}
		case 2:
		{
			result = curve2;
			break;
		}
		}
		return result;
	}
} 
TEST_CASE("case1:this is a case for ExplicitSweep", "[nurbs][forcase1][Explicit]") {
	GlobalProperty g;
	SECTION("TestExplicitSweepWithTwoGuideCurvesTwoPoints()")
	{
		std::string filedir = INPUT_PATH_PREFIX "/TestNURBS/TestExplicitSweepWithTwoGuideCurvesTwoPoints/";
		auto profile = ReadBRepCurve(filedir + "profile.brep");
		CHECK(OCCTIO::OCCTTool::Write(MakeEdge(profile), OUTPUT_PATH_PREFIX "TestExplicitSweepWithTwoGuideCurvesTwoPoints_profile.brep"));
		auto guide1 = ReadBRepCurve(filedir + "guide1.brep");
		CHECK(OCCTIO::OCCTTool::Write(MakeEdge(guide1), OUTPUT_PATH_PREFIX "TestExplicitSweepWithTwoGuideCurvesTwoPoints_guide1.brep"));
		auto guide2 = ReadBRepCurve(filedir + "guide2.brep");
		CHECK(OCCTIO::OCCTTool::Write(MakeEdge(guide2), OUTPUT_PATH_PREFIX "TestExplicitSweepWithTwoGuideCurvesTwoPoints_guide2.brep"));
		auto anchorPoint1 = ReadBRepPoint(filedir + "point1.brep");
		auto anchorPoint2 = ReadBRepPoint(filedir + "point2.brep");
		CHECK(OCCTIO::OCCTTool::Write(MakeVertex(anchorPoint1), OUTPUT_PATH_PREFIX "TestExplicitSweepWithTwoGuideCurvesTwoPoints_point1.brep"));
		CHECK(OCCTIO::OCCTTool::Write(MakeVertex(anchorPoint2), OUTPUT_PATH_PREFIX "TestExplicitSweepWithTwoGuideCurvesTwoPoints_point2.brep"));
		auto [status, surface] = NURBSAPIExplicitSweep::SweepWithTwoGuideCurves(profile, guide1, guide2, anchorPoint1, anchorPoint2, guide1, guide1->FirstParameter(), guide1->LastParameter());
		CHECK(status == NURBSSweepStatus::Success);
		if (status == NURBSSweepStatus::Success)
		{
			CHECK(OCCTIO::OCCTTool::Write(MakeFace(surface, 0.0), OUTPUT_PATH_PREFIX "TestExplicitSweepWithTwoGuideCurvesTwoPoints_result.brep"));
			AMCAX::BRepExtremaDistShapeShape len1(MakeFace(surface, 0.0), MakeEdge(guide1));
			AMCAX::BRepExtremaDistShapeShape len2(MakeFace(surface, 0.0), MakeEdge(guide2));
			AMCAX::BRepExtremaDistShapeShape len3(MakeFace(surface, 0.0), MakeEdge(profile));
			CHECK(len1.Value() == Approx(0.0).margin(0.1));
			CHECK(len2.Value() == Approx(0.0).margin(0.1));
			CHECK(len3.Value() == Approx(0.0).margin(0.1));
		}
		profile->IncreaseDegree(11);
		guide1->IncreaseDegree(11);
		guide2->IncreaseDegree(11);
		auto [status1, surface1] = NURBSAPIExplicitSweep::SweepWithTwoGuideCurves(profile, guide1, guide2, anchorPoint1, anchorPoint2, guide1, guide1->FirstParameter(), guide1->LastParameter());
		CHECK(status1 == NURBSSweepStatus::Success);
		if (status1 == NURBSSweepStatus::Success)
		{
			CHECK(OCCTIO::OCCTTool::Write(MakeFace(surface1, 0.0), OUTPUT_PATH_PREFIX "TestExplicitSweepWithTwoGuideCurvesTwoPoints_degree11result.brep"));
			AMCAX::BRepExtremaDistShapeShape len1(MakeFace(surface1, 0.0), MakeEdge(guide1));
			AMCAX::BRepExtremaDistShapeShape len2(MakeFace(surface1, 0.0), MakeEdge(guide2));
			AMCAX::BRepExtremaDistShapeShape len3(MakeFace(surface1, 0.0), MakeEdge(profile));
			CHECK(len1.Value() == Approx(0.0).margin(0.1));
			CHECK(len2.Value() == Approx(0.0).margin(0.1));
			CHECK(len3.Value() == Approx(0.0).margin(0.1));
			double bsp3s = GetSurfaceProperties(MakeFace(surface1, 0.0), g, true, true);
			double bsp4s = GetSurfaceProperties(MakeFace(surface, 0.0), g, true, true);
			CHECK(bsp3s == Approx(bsp4s).margin(0.04));
		}
	}}