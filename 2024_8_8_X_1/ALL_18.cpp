/* "Derived& Transform(const TransformationT<double, DIM>& tr)\t @return The reference to self\n\t @param tr The transformation\n\t @brief Transform the line\n,\n",
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
TEST_CASE("case2: Line3 base method Test", "[math][Line3][p1]")
{
	SECTION("Transform")
	{
		Line3 line(Point3(), Direction3(0., 1., 0.));
		Transformation3 translationTransform;
		translationTransform.SetTranslation(Point3(0., 0., 0.), Point3(1., 1., 1.));  
		Line3 translationLine = line.Transformed(translationTransform);
		CHECK(translationLine.Direction().IsEqual(line.Direction(), 1e-6 * ONE_RADIAN));
		CHECK(translationLine.Contains(Point3(1., 1., 1.), 1e-6));
		Transformation3 rotationTransfrom;
		rotationTransfrom.SetRotation(Axis3(Point3(), Direction3(1., 0., 0.)), 90. * ONE_RADIAN);  
		Line3 rotationLine = line.Transformed(rotationTransfrom);
		CHECK(rotationLine.Direction().IsEqual(Direction3(0., 0., 1.), 1e-6 * ONE_RADIAN));
		CHECK(rotationLine.Contains(Point3(0., 0., 3.), 1e-6) == true);
		Transformation3 scaleTransfrom;
		scaleTransfrom.SetScale(Point3(1., 0., 1.), -1.); 
		Line3 scaleLine = line.Transformed(scaleTransfrom);
		CHECK(line.Distance(Point3(1., 0., 1.)) == scaleLine.Distance(Point3(1., 0., 1.)));
		CHECK(scaleLine.Direction().IsEqual(Direction3(0., -1., 0.), 1e-6*ONE_RADIAN));
		Transformation3 mirrorTransfrom;
		mirrorTransfrom.SetMirror(Frame3(Point3(0., 0., 0.), Direction3(1., 0., 0.)));
		Line3 mirrorLine = line.Transformed(mirrorTransfrom);
		CHECK(line.Distance(Point3(0., 0., 0.)) == mirrorLine.Distance(Point3(0., 0., 0.)));
		AMCAX::OCCTIO::OCCTTool::Write(MakeEdge(line), OUTPUT_PATH_PREFIX"Line3_Transform_InitialLine.brep");
		Transformation3 CombinedTransfrom = scaleTransfrom * mirrorTransfrom* translationTransform * rotationTransfrom;  
		line.Transform(CombinedTransfrom);
		AMCAX::OCCTIO::OCCTTool::Write(MakeEdge(line), OUTPUT_PATH_PREFIX"Line3_Transform_transformLine.brep");
		CHECK(line.Contains(Point3(3., -1., 1.), 1e-6) == true);
		CHECK(line.Direction().IsEqual(Direction3(0., 0., -1.), 1e-6 * ONE_RADIAN));
	}}