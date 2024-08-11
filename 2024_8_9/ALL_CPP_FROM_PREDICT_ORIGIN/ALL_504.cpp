 #include<catch.hpp>
#include<testHelper.h>
#include <common/FrameT.hpp>
#include <modeling/MakeBox.hpp>
#include <common/AxisT.hpp>
#include <common/DirectionT.hpp>
#include <common/PointT.hpp>
#include <common/TransformationT.hpp>
#include <common/VectorT.hpp>
#include <iostream>
#define ONE_RADIAN (M_PI / 180.)
#define SQUARE(x) ((x) * (x))
using namespace AMCAX;
using namespace std;
TEST_CASE("case1:this is a case for MakeBox", "[modeling][MakeBox][P1]") {
	SECTION("Box") {
        Frame3 frame;
        double a = 4.;
        double b = 5.;
        double c = 6.;
        MakeBox mkbox(frame, a, b, c);
        AMCAX::GlobalProperty props;
        mkbox.CalculateProperties(props);
        CHECK(props.Mass() == Approx(120.));
        CHECK(props.Surface() == Approx(160.));
        CHECK(props.Volume() == Approx(120.));
        Point3 p1(2., 2., 2.);
        Point3 p2(4., 2., 2.);
        Point3 p3(2., 5., 2.);
        Point3 p4(2., 2., 6.);
        CHECK(mkbox.Contains(p1) == true);
        CHECK(mkbox.Contains(p2) == true);
        CHECK(mkbox.Contains(p3) == true);
        CHECK(mkbox.Contains(p4) == true);
        Point3 p5(2.5, 2.5, 2.5);
        Point3 p6(1.5, 1.5, 1.5);
        CHECK(mkbox.Contains(p5) == true);
        CHECK(mkbox.Contains(p6) == false);
    }}