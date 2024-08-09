/* "AMCAX_API GccCircle3Tangent(const GccQualifiedCurve& qualified1, const Point2& point1, const Point2& point2, double tolerance, double parameter1)\t @param parameter1 The initial guess of the parameter on the curve\n\t @param tolerance The tolerance\n\t @param point2 The second point\n\t @param point1 The first point\n\t @param qualified1 The tangent curve\n\t @brief Construct a circle tangent to a curve and passing throught two points\n,\n",
      */
 #include<catch.hpp>
#include<testHelper.h>
#include <geomAlgo/GccCircle3Tangent.hpp>
#include <geometry/Geom2Curve.hpp>
#include <geometry/MakeGeom2Line.hpp>
#include <geometry/MakeGeom2Circle.hpp>
#include <geomAlgo/GccEntity.hpp>
#include <geometry/AdaptorGeom2Curve.hpp>
#include <geomAlgo/GccEntity.hpp>
#include <geomAlgo/GccQualifiedCurve.hpp>
#include <sstream>
using namespace AMCAX;
TEST_CASE("bug1: GccCircle3Tangent  add 48 cases", "[geomAlgo][GccCircle3Tangent][fixbug]") {
	std::shared_ptr<Geom2Curve> l = MakeGeom2Line(Point2(0.0, 0.0), Point2(1.0, 0.0)).Value();
	std::shared_ptr<Geom2Curve> c1 = MakeGeom2Circle(Point2(0.0, 3.0), 2.0).Value();
	std::shared_ptr<Geom2Curve> c2 = MakeGeom2Circle(Point2(4.0, 3.0), 2.0).Value();
	AdaptorGeom2Curve line(l);
	AdaptorGeom2Curve circle1(c1);
	AdaptorGeom2Curve circle2(c2);
	auto lineEnclosed = GccEntity::Enclosed(line);
	auto lineOutside = GccEntity::Outside(line);
	auto lineUnqualified = GccEntity::Unqualified(line);
	auto circle1Enclosed = GccEntity::Enclosed(circle1);
	auto circle1Enclosing = GccEntity::Enclosing(circle1);
	auto circle1Outside = GccEntity::Outside(circle1);
	auto circle1Unqualified = GccEntity::Unqualified(circle1);
	auto circle2Enclosed = GccEntity::Enclosed(circle2);
	auto circle2Enclosing = GccEntity::Enclosing(circle2);
	auto circle2Outside = GccEntity::Outside(circle2);
	auto circle2Unqualified = GccEntity::Unqualified(circle2);
	auto gccl = GccEntity::Enclosed(AdaptorGeom2Curve(l));
	auto gccc1 = GccEntity::Enclosing(AdaptorGeom2Curve(c1));
	auto gccc2 = GccEntity::Outside(AdaptorGeom2Curve(c2));
	auto c3t = [](const GccQualifiedCurve& gccc1, const GccQualifiedCurve& gccc2, const GccQualifiedCurve& gccl)
	{
		std::stringstream output;
		GccCircle3Tangent gcc(gccc1, gccc2, gccl, Precision::Confusion(), 0.0, 0.0, 0.0);
		std::cout << "Test case: " << GccEntity::PositionToString(gccc1.Qualifier()) << ' ' << GccEntity::PositionToString(gccc2.Qualifier()) << ' ' << GccEntity::PositionToString(gccl.Qualifier()) << std::endl;
		std::cout << "Solution: " << gcc.NSolutions() << std::endl;
		output << "Test case: " << GccEntity::PositionToString(gccc1.Qualifier()) << ' ' << GccEntity::PositionToString(gccc2.Qualifier()) << ' ' << GccEntity::PositionToString(gccl.Qualifier()) << std::endl;
		output << "Solution: " << gcc.NSolutions() << std::endl;
		if (gcc.IsDone())
		{
			for (int i = 0; i < gcc.NSolutions(); i++)
			{
				GccPosition q1, q2, q3;
				gcc.Qualifier(i, q1, q2, q3);
				output << i << ": " << *MakeGeom2Circle(gcc.Solution(i)).Value() << std::endl;
				output << "  " << GccEntity::PositionToString(q1) << ' ' << GccEntity::PositionToString(q2) << ' ' << GccEntity::PositionToString(q3) << std::endl;
			}
		}
		else
		{
			std::cout << "gcc.IsDone is False" << std::endl;
			output << "gcc.IsDone is False" << std::endl;
		}
		return output.str();
	};
	auto case1 = c3t(circle1Enclosed, circle2Enclosed, lineEnclosed);
	auto expect1 = "Test case: Enclosed Enclosed Enclosed
Solution: 0
";
	CHECK(case1.find(expect1) != std::string::npos);
	auto case2 = c3t(circle1Enclosed, circle2Enclosed, lineOutside);
	auto expect2 = "Test case: Enclosed Enclosed Outside
Solution: 0
";
	CHECK(case2.find(expect2) != std::string::npos);
	auto case3 = c3t(circle1Enclosed, circle2Enclosed, lineUnqualified);
	auto expect3 = "Test case: Enclosed Enclosed Unqualified
Solution: 0
";
	CHECK(case3.find(expect3) != std::string::npos);
	auto case4 = c3t(circle1Enclosed, circle2Enclosing, lineEnclosed);
	auto expect4 = "Test case: Enclosed Enclosing Enclosed
Solution: 0
";
	CHECK(case4.find(expect4) != std::string::npos);
	auto case5 = c3t(circle1Enclosed, circle2Enclosing, lineOutside);
	auto expect5 = "Test case: Enclosed Enclosing Outside
Solution: 0
";
	CHECK(case5.find(expect5) != std::string::npos);
	auto case6 = c3t(circle1Enclosed, circle2Enclosing, lineUnqualified);
	auto expect6 = "Test case: Enclosed Enclosing Unqualified
Solution: 0
";
	CHECK(case6.find(expect6) != std::string::npos);
	auto case7 = c3t(circle1Enclosed, circle2Outside, lineEnclosed);
	auto expect7 = "Test case: Enclosed Outside Enclosed
Solution: 0
";
	CHECK(case7.find(expect7) != std::string::npos);
	auto case8 = c3t(circle1Enclosed, circle2Outside, lineOutside);
	auto expect8 = "Test case: Enclosed Outside Outside
Solution: 0
";
	CHECK(case8.find(expect8) != std::string::npos);
	auto case9 = c3t(circle1Enclosed, circle2Outside, lineUnqualified);
	auto expect9 = "Test case: Enclosed Outside Unqualified
Solution: 0
";
	CHECK(case9.find(expect9) != std::string::npos);
	auto case10 = c3t(circle1Enclosed, circle2Unqualified, lineEnclosed);
	auto expect10 = "Test case: Enclosed Unqualified Enclosed
Solution: 0
";
	CHECK(case10.find(expect10) != std::string::npos);
	auto case11 = c3t(circle1Enclosed, circle2Unqualified, lineOutside);
	auto expect11 = "Test case: Enclosed Unqualified Outside
Solution: 0
";
	CHECK(case11.find(expect11) != std::string::npos);
	auto case12 = c3t(circle1Enclosed, circle2Unqualified, lineUnqualified);
	auto expect12 = "Test case: Enclosed Unqualified Unqualified
Solution: 0
";
	CHECK(case12.find(expect12) != std::string::npos);
	auto case13 = c3t(circle1Enclosing, circle2Enclosed, lineEnclosed);
	auto expect13 = "Test case: Enclosing Enclosed Enclosed
Solution: 0
";
	CHECK(case13.find(expect13) != std::string::npos);
	auto case14 = c3t(circle1Enclosing, circle2Enclosed, lineOutside);
	auto expect14 = "Test case: Enclosing Enclosed Outside
Solution: 0
";
	CHECK(case14.find(expect14) != std::string::npos);
	auto case15 = c3t(circle1Enclosing, circle2Enclosed, lineUnqualified);
	auto expect15 = "Test case: Enclosing Enclosed Unqualified
Solution: 0
";
	CHECK(case15.find(expect15) != std::string::npos);
	auto case16 = c3t(circle1Enclosing, circle2Enclosing, lineEnclosed);
	auto expect16 = "Test case: Enclosing Enclosing Enclosed
Solution: 1
0: 2 2 4.5 1 0 -0 1 4.5
  Enclosing Enclosing Enclosed
";
	CHECK(case16.find(expect16) != std::string::npos);
	auto case17 = c3t(circle1Enclosing, circle2Enclosing, lineOutside);
	auto expect17 = "Test case: Enclosing Enclosing Outside
Solution: 0
";
	CHECK(case17.find(expect17) != std::string::npos);
	auto case18 = c3t(circle1Enclosing, circle2Enclosing, lineUnqualified);
	auto expect18 = "Test case: Enclosing Enclosing Unqualified
Solution: 1
0: 2 2 4.5 1 0 -0 1 4.5
  Enclosing Enclosing Enclosed
";
	CHECK(case18.find(expect18) != std::string::npos);
	auto case19 = c3t(circle1Enclosing, circle2Outside, lineEnclosed);
	auto expect19 = "Test case: Enclosing Outside Enclosed
Solution: 1
0: 2 -1 3 1 0 -0 1 3
  Enclosing Outside Enclosed
";
	CHECK(case19.find(expect19) != std::string::npos);
	auto case20 = c3t(circle1Enclosing, circle2Outside, lineOutside);
	auto expect20 = "Test case: Enclosing Outside Outside
Solution: 0
";
	CHECK(case20.find(expect20) != std::string::npos);
	auto case21 = c3t(circle1Enclosing, circle2Outside, lineUnqualified);
	auto expect21 = "Test case: Enclosing Outside Unqualified
Solution: 1
0: 2 -1 3 1 0 -0 1 3
  Enclosing Outside Enclosed
";
	CHECK(case21.find(expect21) != std::string::npos);
	auto case22 = c3t(circle1Enclosing, circle2Unqualified, lineEnclosed);
	auto expect22 = "Test case: Enclosing Unqualified Enclosed
Solution: 2
0: 2 -1 3 1 0 -0 1 3
  Enclosing Outside Enclosed
1: 2 2 4.5 1 0 -0 1 4.5
  Enclosing Enclosing Enclosed
";
	CHECK(case22.find(expect22) != std::string::npos);
	auto case23 = c3t(circle1Enclosing, circle2Unqualified, lineOutside);
	auto expect23 = "Test case: Enclosing Unqualified Outside
Solution: 0
";
	CHECK(case23.find(expect23) != std::string::npos);
	auto case24 = c3t(circle1Enclosing, circle2Unqualified, lineUnqualified);
	auto expect24 = "Test case: Enclosing Unqualified Unqualified
Solution: 2
0: 2 -1 3 1 0 -0 1 3
  Enclosing Outside Enclosed
1: 2 2 4.5 1 0 -0 1 4.5
  Enclosing Enclosing Enclosed
";
	CHECK(case24.find(expect24) != std::string::npos);
	auto case25 = c3t(circle1Outside, circle2Enclosed, lineEnclosed);
	auto expect25 = "Test case: Outside Enclosed Enclosed
Solution: 0
";
	CHECK(case25.find(expect25) != std::string::npos);
	auto case26 = c3t(circle1Outside, circle2Enclosed, lineOutside);
	auto expect26 = "Test case: Outside Enclosed Outside
Solution: 0
";
	CHECK(case26.find(expect26) != std::string::npos);
	auto case27 = c3t(circle1Outside, circle2Enclosed, lineUnqualified);
	auto expect27 = "Test case: Outside Enclosed Unqualified
Solution: 0
";
	CHECK(case27.find(expect27) != std::string::npos);
	auto case28 = c3t(circle1Outside, circle2Enclosing, lineEnclosed);
	auto expect28 = "Test case: Outside Enclosing Enclosed
Solution: 1
0: 2 5 3 1 0 -0 1 3
  Outside Enclosing Enclosed
";
	CHECK(case28.find(expect28) != std::string::npos);
	auto case29 = c3t(circle1Outside, circle2Enclosing, lineOutside);
	auto expect29 = "Test case: Outside Enclosing Outside
Solution: 0
";
	CHECK(case29.find(expect29) != std::string::npos);
	auto case30 = c3t(circle1Outside, circle2Enclosing, lineUnqualified);
	auto expect30 = "Test case: Outside Enclosing Unqualified
Solution: 1
0: 2 5 3 1 0 -0 1 3
  Outside Enclosing Enclosed
";
	CHECK(case30.find(expect30) != std::string::npos);
	auto case31 = c3t(circle1Outside, circle2Outside, lineEnclosed);
	auto expect31 = "Test case: Outside Outside Enclosed
Solution: 1
0: 2 2 0.9 1 0 -0 1 0.9
  Outside Outside Enclosed
";
	CHECK(case31.find(expect31) != std::string::npos);
	auto case32 = c3t(circle1Outside, circle2Outside, lineOutside);
	auto expect32 = "Test case: Outside Outside Outside
Solution: 0
";
	CHECK(case32.find(expect32) != std::string::npos);
	auto case33 = c3t(circle1Outside, circle2Outside, lineUnqualified);
	auto expect33 = "Test case: Outside Outside Unqualified
Solution: 1
0: 2 2 0.9 1 0 -0 1 0.9
  Outside Outside Enclosed
";
	CHECK(case33.find(expect33) != std::string::npos);
	auto case34 = c3t(circle1Outside, circle2Unqualified, lineEnclosed);
	auto expect34 = "Test case: Outside Unqualified Enclosed
Solution: 2
0: 2 2 0.9 1 0 -0 1 0.9
  Outside Outside Enclosed
1: 2 5 3 1 0 -0 1 3
  Outside Enclosing Enclosed
";
	CHECK(case34.find(expect34) != std::string::npos);
	auto case35 = c3t(circle1Outside, circle2Unqualified, lineOutside);
	auto expect35 = "Test case: Outside Unqualified Outside
Solution: 0
";
	CHECK(case35.find(expect35) != std::string::npos);
	auto case36 = c3t(circle1Outside, circle2Unqualified, lineUnqualified);
	auto expect36 = "Test case: Outside Unqualified Unqualified
Solution: 2
0: 2 2 0.9 1 0 -0 1 0.9
  Outside Outside Enclosed
1: 2 5 3 1 0 -0 1 3
  Outside Enclosing Enclosed
";
	CHECK(case36.find(expect36) != std::string::npos);
	auto case37 = c3t(circle1Unqualified, circle2Enclosed, lineEnclosed);
	auto expect37 = "Test case: Unqualified Enclosed Enclosed
Solution: 0
";
	CHECK(case37.find(expect37) != std::string::npos);
	auto case38 = c3t(circle1Unqualified, circle2Enclosed, lineOutside);
	auto expect38 = "Test case: Unqualified Enclosed Outside
Solution: 0
";
	CHECK(case38.find(expect38) != std::string::npos);
	auto case39 = c3t(circle1Unqualified, circle2Enclosed, lineUnqualified);
	auto expect39 = "Test case: Unqualified Enclosed Unqualified
Solution: 0
";
	CHECK(case39.find(expect39) != std::string::npos);
	auto case40 = c3t(circle1Unqualified, circle2Enclosing, lineEnclosed);
	auto expect40 = "Test case: Unqualified Enclosing Enclosed
Solution: 2
0: 2 5 3 1 0 -0 1 3
  Outside Enclosing Enclosed
1: 2 2 4.5 1 0 -0 1 4.5
  Enclosing Enclosing Enclosed
";
	CHECK(case40.find(expect40) != std::string::npos);
	auto case41 = c3t(circle1Unqualified, circle2Enclosing, lineOutside);
	auto expect41 = "Test case: Unqualified Enclosing Outside
Solution: 0
";
	CHECK(case41.find(expect41) != std::string::npos);
	auto case42 = c3t(circle1Unqualified, circle2Enclosing, lineUnqualified);
	auto expect42 = "Test case: Unqualified Enclosing Unqualified
Solution: 2
0: 2 5 3 1 0 -0 1 3
  Outside Enclosing Enclosed
1: 2 2 4.5 1 0 -0 1 4.5
  Enclosing Enclosing Enclosed
";
	CHECK(case42.find(expect42) != std::string::npos);
	auto case43 = c3t(circle1Unqualified, circle2Outside, lineEnclosed);
	auto expect43 = "Test case: Unqualified Outside Enclosed
Solution: 2
0: 2 2 0.9 1 0 -0 1 0.9
  Outside Outside Enclosed
1: 2 -1 3 1 0 -0 1 3
  Enclosing Outside Enclosed
";
	CHECK(case43.find(expect43) != std::string::npos);
	auto case44 = c3t(circle1Unqualified, circle2Outside, lineOutside);
	auto expect44 = "Test case: Unqualified Outside Outside
Solution: 0
";
	CHECK(case44.find(expect44) != std::string::npos);
	auto case45 = c3t(circle1Unqualified, circle2Outside, lineUnqualified);
	auto expect45 = "Test case: Unqualified Outside Unqualified
Solution: 2
0: 2 2 0.9 1 0 -0 1 0.9
  Outside Outside Enclosed
1: 2 -1 3 1 0 -0 1 3
  Enclosing Outside Enclosed
";
	CHECK(case45.find(expect45) != std::string::npos);
	auto case46 = c3t(circle1Unqualified, circle2Unqualified, lineEnclosed);
	auto expect46 = "Test case: Unqualified Unqualified Enclosed
Solution: 4
0: 2 2 0.9 1 0 -0 1 0.9
  Outside Outside Enclosed
1: 2 5 3 1 0 -0 1 3
  Outside Enclosing Enclosed
2: 2 -1 3 1 0 -0 1 3
  Enclosing Outside Enclosed
3: 2 2 4.5 1 0 -0 1 4.5
  Enclosing Enclosing Enclosed
";
	CHECK(case46.find(expect46) != std::string::npos);
	auto case47 = c3t(circle1Unqualified, circle2Unqualified, lineOutside);
	auto expect47 = "Test case: Unqualified Unqualified Outside
Solution: 0
";
	CHECK(case47.find(expect47) != std::string::npos);
	auto case48 = c3t(circle1Unqualified, circle2Unqualified, lineUnqualified);
	auto expect48 = "Test case: Unqualified Unqualified Unqualified
Solution: 4
0: 2 2 0.9 1 0 -0 1 0.9
  Outside Outside Enclosed
1: 2 5 3 1 0 -0 1 3
  Outside Enclosing Enclosed
2: 2 -1 3 1 0 -0 1 3
  Enclosing Outside Enclosed
3: 2 2 4.5 1 0 -0 1 4.5
  Enclosing Enclosing Enclosed";
	CHECK(case48.find(expect48) != std::string::npos);
}