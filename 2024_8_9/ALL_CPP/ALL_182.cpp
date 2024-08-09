/* "LineS& Mirror(const Frame3& frame)\t @return The reference to self\n\t @param frame The mirror frame\n\t @brief Mirror the line by a frame\n,\n",
      */
 #include <catch.hpp>
#include <testHelper.h>
#include <math/LineT.hpp>
#include <math/Plane.hpp>
#include <modeling/MakeFace.hpp>
#include <modeling/MakeEdge.hpp>
using AMCAX::Line3;
using AMCAX::MakeEdge;
using AMCAX::MakeFace;
#define ONE_RADIAN (M_PI / 180.)
#define SQUARE(x) ((x) * (x))
TEST_CASE("case1: Derived class interface unit testing", "[math][Line3][p1]")
{
	SECTION("Mirror")
	{
		Line3 line(Point3(1.0, 2.0, 3.0), Direction3(1.0, 0.0, 0.0));
		Line3 originalLine(Point3(1.0, 2.0, 3.0), Direction3(1.0, 0.0, 0.0));
		Frame3 frame(Point3(0.0, 0.0, 0.0), Direction3(0.0, 1.0, 0.0));
		line.Mirror(frame);
		CHECK(line.Distance(Point3(0.0, 0.0, 0.0)) == Approx(originalLine.Distance(Point3(0., 0., 0.))).margin(std::numeric_limits<double>::min()));
		Direction3 dir(originalLine.Location().X() - line.Location().X(),
					   originalLine.Location().Y() - line.Location().Y(),
					   originalLine.Location().Z() - line.Location().Z());
		CHECK(dir.IsParallel(Direction3(0.0, 1.0, 0.0), 1e-5 * ONE_RADIAN));
		Line3 line2(Point3(1.2, -4.6, 2.3), Direction3(1.8, 97.4, -12.8));
		Frame3 frame2(Point3(87.0, 2.3, 10.14), Direction3(-92.3, 2.6, 1.0));
		Line3 mirrorLine2 = line2.Mirrored(frame2);
		CHECK(line2.Distance(Point3(87.0, 2.3, 10.14)) == Approx(mirrorLine2.Distance(Point3(87.0, 2.3, 10.14))).margin(std::numeric_limits<double>::min()));
		Direction3 dir2(line2.Location().X() - mirrorLine2.Location().X(),
					    line2.Location().Y() - mirrorLine2.Location().Y(),
					    line2.Location().Z() - mirrorLine2.Location().Z());
		CHECK(dir2.IsParallel(Direction3(-92.3, 2.6, 1.0), 1e-5 * ONE_RADIAN));
		TopoFace face = MakeFace(Plane(frame2), 0., 4., 0., 4.);
		TopoEdge edgeLine2 = MakeEdge(line2, 0., 1.);
		TopoEdge edgeMirrorLine2 = MakeEdge(mirrorLine2, 0., 1.);
		AMCAX::OCCTIO::OCCTTool::Write(face, OUTPUT_PATH_PREFIX"Line3_Mirror_face2.brep");
		AMCAX::OCCTIO::OCCTTool::Write(edgeLine2, OUTPUT_PATH_PREFIX"Line3_Mirror_edge.brep");
		AMCAX::OCCTIO::OCCTTool::Write(edgeMirrorLine2, OUTPUT_PATH_PREFIX"Line3_Mirror_Mirroredge.brep");
	}}