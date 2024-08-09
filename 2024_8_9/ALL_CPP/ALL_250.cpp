/* "AMCAX_API explicit BRepFaceClassifier(const TopoFace& f)\t @param f The input face\n\t @brief Construct from the face to be processed\n,\n",
      */
 #include<catch.hpp>
#include<testHelper.h>
#include <hatch/BRepFaceClassifier.hpp>
#include <common/FrameT.hpp>
#include <math/CircleT.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakeWire.hpp>
#include <modeling/MakeFace.hpp>
#include <boolean/BoolBRepFuse.hpp>
#include <common/IndexSet.hpp>
#include <topology/TopoExplorerTool.hpp>
using namespace AMCAX;
TopoFace WrenchFace()
{
	Frame3 fm1(Point3(0., 0., 0.), Direction3(0., 0., 1.0));
	Circle3 c1 = Circle3(fm1, 2.);
	TopoEdge ec1 = MakeEdge(c1);
	TopoWire wc1 = MakeWire(ec1);
	TopoFace F1 = MakeFace(wc1);
	TopoEdge edge1 = MakeEdge(Point3(-4., -1.0, 0.0), Point3(4., -1.0, 0.0));
	TopoEdge edge2 = MakeEdge(Point3(4., -1.0, 0.0), Point3(4., 1.0, 0.0));
	TopoEdge edge3 = MakeEdge(Point3(4., 1.0, 0.0), Point3(-4., 1.0, 0.0));
	TopoEdge edge4 = MakeEdge(Point3(-4., 1.0, 0.0), Point3(-4., -1.0, 0.0));
	TopoWire wireR = MakeWire(edge1, edge2, edge3, edge4);
	TopoFace F3 = MakeFace(wireR);
	BoolBRepFuse fuse(F1, F3);
	fuse.Build();
	fuse.SimplifyResult();
	TopoShape res = fuse.Shape();
	IndexSet<TopoShape> resFaces;
	TopoExplorerTool::MapShapes(res, ShapeType::Face, resFaces);
	std::cout << resFaces.size() << std::endl;
	TopoFace face = static_cast<const TopoFace&>(resFaces[0]);
	return face;
}
bool ImpInWrenchFace(const Point2& pt)
{
	bool isFaceIn1 = pt.X() * pt.X() + pt.Y() * pt.Y() < 2 * 2;
	bool isFaceIn2 = pt.X() > -4 && pt.X() < 4 && pt.Y() > -1 && pt.Y() < 1;
	return isFaceIn1 || isFaceIn2;
}
Point2 SampleMethodFace()
{
	double x = (double)rand() / RAND_MAX * 10 - 5;
	double y = (double)rand() / RAND_MAX * 5 - 2.0;
	return Point2(x, y);
}
TEST_CASE("case1: BRepFaceClassifier 3.6.0 added API. ", "[hatch][BRepFaceClassifier][P1]") {
		TopoFace face = WrenchFace();
		BRepFaceClassifier classify(face);
		int n = 10000;
		int inSize = 0, intime = 0, ontime = 0;
		for (int i = 0; i < n; ++i)
		{
			Point2 pt = SampleMethodFace();
			bool isIn = ImpInWrenchFace(pt);
			classify.Perform(pt, Precision::Confusion());
			bool isCIn = classify.State() == StateType::In;
			bool isCon = classify.State() == StateType::On;
			if (isIn)
			{
				inSize++;
				if (isCIn)
				{
					intime++;
				}
				if (isCon)
				{
					ontime++;
				}
			}
		}
		std::cout << inSize << " " << intime << " " << ontime << std::endl;
		CHECK(inSize == (intime + ontime));
}