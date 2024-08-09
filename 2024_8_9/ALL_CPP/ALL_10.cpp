/* "AMCAX_API static std::pair<NURBSSweepStatus, std::vector<std::shared_ptr<Geom3BSplineSurface>>> SweepWithCurveOnTangencySurface(const std::shared_ptr<Geom3BSplineCurve>& guide, const std::shared_ptr<Geom3BSplineSurface>& tangencySurface, const LawFunction& radiusLaw, const LawFunction& angleLaw1, const LawFunction& angleLaw2, const std::shared_ptr<Geom3BSplineCurve>& spine, double spineLeftBound, double spineRightBound),\n",
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
#include <geometry/GeomAPIIntSurfaceSurface.hpp>
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
TEST_CASE("case1:this is a case for CircularSweep", "[nurbs][forcase1][Circular]")
{
	GlobalProperty g;
	SECTION("TestCircularSweepWithCurveOnTangencySurface()")	
		{
			std::string filedir(INPUT_PATH_PREFIX "/TestNURBS/TestCircularSweepWithCurveOnTangencySurface/");
			auto guide = ReadBRepCurve(filedir + "guide.brep");
			auto surface = ReadBRepSurface(filedir + "surface.brep");
			auto spine = ReadBRepCurve(filedir + "spine.brep");
			CHECK(OCCTIO::OCCTTool::Write(MakeEdge(guide), OUTPUT_PATH_PREFIX "TestCircularSweepWithCurveOnTangencySurface_guide.brep"));
			CHECK(OCCTIO::OCCTTool::Write(MakeEdge(spine), OUTPUT_PATH_PREFIX "TestCircularSweepWithCurveOnTangencySurface_spine.brep"));
			CHECK(OCCTIO::OCCTTool::Write(MakeFace(surface, 0.0), OUTPUT_PATH_PREFIX "TestCircularSweepWithCurveOnTangencySurface_surface.brep"));
			LawConstant radiusLaw, angleLaw1, angleLaw2;
			radiusLaw.Set(10.0, 0.0, 1.0);
			angleLaw1.Set(0.0, 0.0, 1.0);
			angleLaw2.Set(M_PI_2, 0.0, 1.0);
			auto [status, surfaces] = NURBSAPICircularSweep::SweepWithCurveOnTangencySurface(guide, surface, radiusLaw, angleLaw1, angleLaw2, spine, spine->FirstParameter(), spine->LastParameter());
			CHECK(status == NURBSSweepStatus::Success);
			if (status == NURBSSweepStatus::Success && !surfaces.empty())
			{
				int nsurfaces = static_cast<int>(surfaces.size());
				for (int i = 0; i < nsurfaces; i++)
				{
					CHECK(OCCTIO::OCCTTool::Write(MakeFace(surfaces[i], 0.0), OUTPUT_PATH_PREFIX "TestCircularSweepWithCurveOnTangencySurface_result" + std::to_string(i) + ".brep"));
					CHECK(IsCurveOnSurf(1000, 0.1, guide, surfaces[i], 0.5));
					AMCAX::BRepExtremaDistShapeShape len(MakeFace(surface, 0.0), MakeFace(surfaces[i], 0.0));
					AMCAX::BRepExtremaDistShapeShape len1(MakeFace(surfaces[i], 0.0), MakeEdge(guide));
					CHECK(len1.Value() < 1.0);
					CHECK(len.Value() < 0.1);
				}
			}
			std::string filedir1 = OUTPUT_PATH_PREFIX;
			IndexSet<TopoShape> newshapeEdge1;
			IndexSet<TopoShape> newshapeEdge2;
			TopoExplorerTool::MapShapes(MakeFace(surfaces[0], 0.0), ShapeType::Edge, newshapeEdge1);
			TopoExplorerTool::MapShapes(MakeFace(surfaces[1], 0.0), ShapeType::Edge, newshapeEdge2);
			std::cout << "newshapedege.size" << newshapeEdge1.size() << endl;
			CHECK(OCCTIO::OCCTTool::Write(newshapeEdge1[0], OUTPUT_PATH_PREFIX "TestCircularSweepWithCurveOnTangencySurface_newshapeEdge1[0].brep"));
			CHECK(OCCTIO::OCCTTool::Write(newshapeEdge2[1], OUTPUT_PATH_PREFIX "TestCircularSweepWithCurveOnTangencySurface_newshapeEdge2[1].brep"));
			CHECK(OCCTIO::OCCTTool::Write(newshapeEdge2[2], OUTPUT_PATH_PREFIX "TestCircularSweepWithCurveOnTangencySurface_newshapeEdge2[2].brep"));
			CHECK(OCCTIO::OCCTTool::Write(newshapeEdge2[0], OUTPUT_PATH_PREFIX "TestCircularSweepWithCurveOnTangencySurface_newshapeEdge2[0].brep"));
			CHECK(OCCTIO::OCCTTool::Write(newshapeEdge2[3], OUTPUT_PATH_PREFIX "TestCircularSweepWithCurveOnTangencySurface_newshapeEdge2[3].brep"));
			auto edge0 = ReadBRepCurve(filedir1 + "TestCircularSweepWithCurveOnTangencySurface_newshapeEdge1[0].brep");
			auto edge1 = ReadBRepCurve(filedir1 + "TestCircularSweepWithCurveOnTangencySurface_newshapeEdge2[0].brep");
			CHECK(IsSurfTangent(100, 0.6, edge0, surface, surfaces[0], 20, 0));
			CHECK(IsSurfTangent(100, 0.6, edge1, surface, surfaces[0], 20, 0));
			guide->IncreaseDegree(5);
			spine->IncreaseDegree(5);
			surface->IncreaseDegree(5, 5);
			auto [status1, surfaces1] = NURBSAPICircularSweep::SweepWithCurveOnTangencySurface(guide, surface, radiusLaw, angleLaw1, angleLaw2, spine, spine->FirstParameter(), spine->LastParameter());
			CHECK(status1 == NURBSSweepStatus::Success);
			if (status1 == NURBSSweepStatus::Success && !surfaces.empty())
			{
				int nsurfaces = static_cast<int>(surfaces.size());
				for (int i = 0; i < nsurfaces; i++)
				{
					CHECK(OCCTIO::OCCTTool::Write(MakeFace(surfaces1[i], 0.0), OUTPUT_PATH_PREFIX "TestCircularSweepWithCurveOnTangencySurface_degree5result" + std::to_string(i) + ".brep"));
					CHECK(IsCurveOnSurf(1000, 0.1, guide, surfaces1[i], 0.5));
					double bsp3s = GetSurfaceProperties(MakeFace(surfaces1[i], 0.0), g, true, true);
					double bsp4s = GetSurfaceProperties(MakeFace(surfaces[i], 0.0), g, true, true);
					CHECK(bsp3s == Approx(bsp4s).margin(0.02));
				}
			}
		}}