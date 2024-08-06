{"instruction": "Generate a test program based on the following method declarations and parameter parsing.",
 "input": "void SetRadius(double r)	 @param r The radius
	 @brief Set the radius of the circle
",
 "output": "#include<catch.hpp>
#include<testHelper.h>
#include <geomAlgo/GccCircle3Tangent.hpp>
#include <geometry/Geom2Curve.hpp>
#include <geometry/MakeGeom2Line.hpp>
#include <geometry/MakeGeom2Circle.hpp>
#include <geomAlgo/GccEntity.hpp>
#include <geometry/AdaptorGeom2Curve.hpp>
#include <geomAlgo/GccQualifiedCurve.hpp>

TEST_CASE(\"SetRadius Test\") {
	CircleS circle;
	circle.SetRadius(5.0);
	CHECK(circle.Radius() == 5.0);
}"},
{"instruction": "Generate a test program based on the following method declarations and parameter parsing.",
 "input": "[nodiscard]] double Radius()	 @return The radius
	 @brief Get the radius
",
 "output": "#include<catch.hpp>
#include<testHelper.h>
#include <geomAlgo/GccCircle3Tangent.hpp>
#include <geometry/Geom2Curve.hpp>
#include <geometry/MakeGeom2Line.hpp>
#include <geometry/MakeGeom2Circle.hpp>
#include <geomAlgo/GccEntity.hpp>
#include <geometry/AdaptorGeom2Curve.hpp>
#include <geomAlgo/GccQualifiedCurve.hpp>

TEST_CASE(\"Radius Test\") {
	CircleS circle;
	circle.SetRadius(3.0);
	CHECK(circle.Radius() == 3.0);
}"},
{"instruction": "Generate a test program based on the following method declarations and parameter parsing.",
 "input": "[[nodiscard]] double Length()	 @return The length of the circle
	 @brief Get the length of the circle
",
 "output": "#include<catch.hpp>
#include<testHelper.h>
#include <geomAlgo/GccCircle3Tangent.hpp>
#include <geometry/Geom2Curve.hpp>
#include <geometry/MakeGeom2Line.hpp>
#include <geometry/MakeGeom2Circle.hpp>
#include <geomAlgo/GccEntity.hpp>
#include <geometry/AdaptorGeom2Curve.hpp>
#include <geomAlgo/GccQualifiedCurve.hpp>

TEST_CASE(\"Length Test\") {
	CircleS circle;
	circle.SetRadius(2.0);
	CHECK(circle.Length() == 2 * 3.14159);
}"},
{"instruction": "Generate a test program based on the following method declarations and parameter parsing.",
 "input": "[[nodiscard]] double Distance(const PointT<double, DIM>& p)	 @return The distance from the point to the circle
	 @param p The point
	 @brief Compute the distance from a point to the circle
",
 "output": "#include<catch.hpp>
#include<testHelper.h>
#include <geomAlgo/GccCircle3Tangent.hpp>
#include <geometry/Geom2Curve.hpp>
#include <geometry/MakeGeom2Line.hpp>
#include <geometry/MakeGeom2Circle.hpp>
#include <geomAlgo/GccEntity.hpp>
#include <geometry/AdaptorGeom2Curve.hpp>
#include <geomAlgo/GccQualifiedCurve.hpp>

TEST_CASE(\"Distance Test\") {
	CircleS circle;
	circle.SetRadius(5.0);
	PointT<double, 2> point(0.0, 0.0);
	CHECK(circle.Distance(point) == 5.0);
}"},
{"instruction": "Generate a test program based on the following method declarations and parameter parsing.",
 "input": "[[nodiscard] double SquaredDistance(const PointT<double, DIM>& p)	 @return The squared distance from the point to the circle
	 @param p The point
	 @brief Compute the squared distance from a point to the circle
",
 "output": "#include<catch.hpp>
#include<testHelper.h>
#include <geomAlgo/GccCircle3Tangent.hpp>
#include <geometry/Geom2Curve.hpp>
#include <geometry/MakeGeom2Line.hpp>
#include <geometry/MakeGeom2Circle.hpp>
#include <geomAlgo/GccEntity.hpp>
#include <geometry/AdaptorGeom2Curve.hpp>
#include <geomAlgo/GccQualifiedCurve.hpp>

TEST_CASE(\"SquaredDistance Test\") {
	CircleS circle;
	circle.SetRadius(3.0);
	PointT<double, 2> point(0.0, 0.0);
	CHECK(circle.SquaredDistance(point) == 9.0);
}"},
{"instruction": "Generate a test program based on the following method declarations and parameter parsing.",
 "input": "CircleS& Scale(const PointT<double, DIM>& p, double scale)	 @return The reference to self
	 @param scale The scale value
	 @param p The scaling center point
	 @brief Scale the circle by a center point
",
 "output": "#include<catch.hpp>
#include<testHelper.h>
#include <geomAlgo/GccCircle3Tangent.hpp>
#include <geometry/Geom2Curve.hpp>
#include <geometry/MakeGeom2Line.hpp>
#include <geometry/MakeGeom2Circle.hpp>
#include <geomAlgo/GccEntity.hpp>
#include <geometry/AdaptorGeom2Curve.hpp>
#include <geomAlgo/GccQualifiedCurve.hpp>

TEST_CASE(\"Scale Test\") {
	CircleS circle;
	circle.SetRadius(2.0);
	circle.Scale(PointT<double, 2>(1.0, 1.0), 2.0);
	CHECK(circle.Radius() == 4.0);
}"},
{"instruction": "Generate a test program based on the following method declarations and parameter parsing.",
 "input": "CircleS& Transform(const TransformationT<double, DIM>& tr)	 @return The reference to self
	 @param tr The transformation
	 @brief Transform the circle
",
 "output": "#include<catch.hpp>
#include<testHelper.h>
#include <geomAlgo/GccCircle3Tangent.hpp>
#include <geometry/Geom2Curve.hpp>
#include <geometry/MakeGeom2Line.hpp>
#include <geometry/MakeGeom2Circle.hpp>
#include <geomAlgo/GccEntity.hpp>
#include <geometry/AdaptorGeom2Curve.hpp>
#include <geomAlgo/GccQualifiedCurve.hpp>

TEST_CASE(\"Transform Test\") {
	CircleS circle;
	circle.SetRadius(2.0);
	TransformationT<double, 2> transformation; // assume this is defined
	circle.Transform(transformation);
	// Check some properties of the transformed circle
}"} {"instruction": "Generate a test program based on the following method declarations and parameter parsing.",
 "input": "void SetRadius(double r)	 @param r The radius
	 @brief Set the radius of the circle
",
 "output": "#include<catch.hpp>
#include<testHelper.h>

#include <common/VectorT.hpp>
#include <common/PointT.hpp>
#include <geometry/Geom2TrimmedCurve.hpp>
#include <geometry/MakeArcOfCircle2d.hpp>
#include <sstream>

using namespace AMCAX;



TEST_CASE(\"bug1: MakeArcOfCircle2d http://192.168.2.72:8080/bug-view-63.html add 1 cases\", \"geomAlgo][MakeArcOfCircle2d][fixbug]\") 
	
	std::stringstream output;
	std::shared_ptr<Geom2TrimmedCurve> c = MakeArcOfCircle2d(Point2(0.0, 1.0), Vector2(1.0, 0.0), Point2(1.0, 0.0));
	std::cout << *c << std::endl;
	output << *c << std::endl;

	auto case1 = output.str();
	auto expect1 = \"8 4.71239 6.28319\";
	auto expect2 = \"2 0 -0 1 0 0 -1 1\";
	CHECK(case1.find(expect1) != std::string::npos);
	CHECK(case1.find(expect2) != std::string::npos);




"}
{"instruction": "Generate a test program based on the following method declarations and parameter parsing.",
 "input": "[[nodiscard]] double Radius()	 @return The radius
	 @brief Get the radius
",
 "output": "#include<catch.hpp>
#include<testHelper.h>

#include <common/VectorT.hpp>
#include <common/PointT.hpp>
#include <geometry/Geom2TrimmedCurve.hpp>
#include <geometry/MakeArcOfCircle2d.hpp>
#include <sstream>

using namespace AMCAX;



TEST_CASE(\"bug1: MakeArcOfCircle2d http://192.168.2.72:8080/bug-view-63.html add 1 cases\", \"[geomAlgo][MakeArcOfCircle2d][fixbug]\") 
	
	std::stringstream output;
	std::shared_ptr<Geom2TrimmedCurve> c = MakeArcOfCircle2d(Point2(0.0, 1.0), Vector2(1.0, 0.0), Point2(1.0, 0.0));
	std::cout << *c << std::endl;
	output << *c << std::endl;

	auto case1 = output.str();
	auto expect1 = \"8 4.71239 6.28319\";
	auto expect2 = \"2 0 -0 1 0 0 -1 1\";
	CHECK(case1.find(expect1) != std::string::npos);
	CHECK(case1.find(expect2) != std::string::npos);




"}
{"instruction": "Generate a test program based on the following method declarations and parameter parsing.",
 "input": "[[nodiscard]] double Length()	 @return The length of the circle
	 @brief Get the length of the circle
",
 "output": "#include<catch.hpp>
#include<testHelper.h>

#include <common/VectorT.hpp>
#include <common/PointT.hpp>
#include <geometry/Geom2TrimmedCurve.hpp>
#include <geometry/MakeArcOfCircle2d.hpp>
#include <sstream>

using namespace AMCAX;



TEST_CASE(\"bug1: MakeArcOfCircle2d http://192.168.2.72:8080/bug-view-63.html add 1 cases\", \"[geomAlgo][MakeArcOfCircle2d][fixbug]\") 
	
	std::stringstream output;
	std::shared_ptr<Geom2TrimmedCurve> c = MakeArcOfCircle2d(Point2(0.0, 1.0), Vector2(1.0, 0.0), Point2(1.0, 0.0));
	std::cout << *c << std::endl;
	output << *c << std::endl;

	auto case1 = output.str();
	auto expect1 = \"8 4.71239 6.28319\";
	auto expect2 = \"2 0 -0 1 0 0 -1 1\";
	CHECK(case1.find(expect1) != std::string::npos);
	CHECK(case1.find(expect2) != std::string::npos);




"}
{"instruction": "Generate a test program based on the following method declarations and parameter parsing.",
 "input": "[[nodiscard]] double Distance(const PointT<double, DIM>& p)	 @return The distance from the point to the circle
	 @param p The point
	 @brief Compute the distance from a point to the circle
",
 "output": "#include<catch.hpp>
#include<testHelper.h>

#include <common/VectorT.hpp>
#include <common/PointT.hpp>
#include <geometry/Geom2TrimmedCurve.hpp>
#include <geometry/MakeArcOfCircle2d.hpp>
#include <sstream>

using namespace AMCAX;



TEST_CASE(\"bug1: MakeArcOfCircle2d http://192.168.2.72:8080/bug-view-63.html add 1 cases\", \"[geomAlgo][MakeArcOfCircle2d][fixbug]\") 
	
	std::stringstream output;
	std::shared_ptr<Geom2TrimmedCurve> c = MakeArcOfCircle2d(Point2(0.0, 1.0), Vector2(1.0, 0.0), Point2(1.0, 0.0));
	std::cout << *c << std::endl;
	output << *c << std::endl;

	auto case1 = output.str();
	auto expect1 = \"8 4.71239 6.28319\";
	auto expect2 = \"2 0 -0 1 0 0 -1 1\";
	CHECK(case1.find(expect1) != std::string::npos);
	CHECK(case1.find(expect2) != std::string::npos);




"}
{"instruction": "Generate a test program based on the following method declarations and parameter parsing.",
 "input": "[[nodiscard]] double SquaredDistance(const PointT<double, DIM>& p)	 @return The squared distance from the point to the circle
	 @param p The point
	 @brief Compute the squared distance from a point to the circle
",
 "output": "#include<catch.hpp>
#include<testHelper.h>

#include <common/VectorT.hpp>
#include <common/PointT.hpp>
#include <geometry/Geom2TrimmedCurve.hpp>
#include <geometry/MakeArcOfCircle2d.hpp>
#include <sstream>

using namespace AMCAX;



TEST_CASE(\"bug1: MakeArcOfCircle2d http://192.168.2.72:8080/bug-view-63.html add 1 cases\", \"[geomAlgo][MakeArcOfCircle2d][fixbug]\") 
	
	std::stringstream output;
	std::shared_ptr<Geom2TrimmedCurve> c = MakeArcOfCircle2d(Point2(0.0, 1.0), Vector2(1.0, 0.0), Point2(1.0, 0.0));
	std::cout << *c << std::endl;
	output << *c << std::endl;

	auto case1 = output.str();
	auto expect1 = \"8 4.71239 6.28319\";
	auto expect2 = \"2 0 -0 1 0 0 -1 1\";
	CHECK(case1.find(expect1) != std::string::npos);
	CHECK(case1.find(expect2) != std::string::npos);




"}
{"instruction": "Generate a test program based on the following method declarations and parameter parsing.",
 "input": "CircleS& Scale(const PointT<double, DIM>& p, double scale)	 @return The reference to self
	 @param scale The scale value
	 @param p The scaling center point
	 @brief Scale the circle by a center point
",
 "output": "#include<catch.hpp>
#include<testHelper.h>

#include <common/VectorT.hpp>
#include <common/PointT.hpp>
#include <geometry/Geom2TrimmedCurve.hpp>
#include <geometry/MakeArcOfCircle2d.hpp>
#include <sstream>

using namespace AMCAX;



TEST_CASE(\"bug1: MakeArcOfCircle2d http://192.168.2.72:8080/bug-view-63.html add 1 cases\", \"[geomAlgo][MakeArcOfCircle2d][fixbug]\") 
	
	std::stringstream output;
	std::shared_ptr<Geom2TrimmedCurve> c = MakeArcOfCircle2d(Point2(0.0, 1.0), Vector2(1.0, 0.0), Point2(1.0, 0.0));
	std::cout << *c << std::endl;
	output << *c << std::endl;

	auto case1 = output.str();
	auto expect1 = \"8 4.71239 6.28319\";
	auto expect2 = \"2 0 -0 1 0 0 -1 1\";
	CHECK(case1.find(expect1) != std::string::npos);
	CHECK(case1.find(expect2) != std::string::npos);




"}
{"instruction": "Generate a test program based on the following method declarations and parameter parsing.",
 "input": "CircleS& Transform(const TransformationT<double, DIM>& tr)	 @return The reference to self
	 @param tr The transformation
	 @brief Transform the circle
",
 "output": "#include<catch.hpp>
#include<testHelper.h>

#include <common/VectorT.hpp>
#include <common/PointT.hpp>
#include <geometry/Geom2TrimmedCurve.hpp>
#include <geometry/MakeArcOfCircle2d.hpp>
#include <sstream>

using namespace AMCAX;



TEST_CASE(\"bug1: MakeArcOfCircle2d http://192.168.2.72:8080/bug-view-63.html add 1 cases\", \"[geomAlgo][MakeArcOfCircle2d][fixbug\") 
	
	std::stringstream output;
	std::shared_ptr<Geom2TrimmedCurve> c = MakeArcOfCircle2d(Point2(0.0, 1.0), Vector2(1.0, 0.0), Point2(1.0, 0.0));
	std::cout << *c << std::endl;
	output << *c << std::endl;

	auto case1 = output.str();
	auto expect1 = \"8 4.71239 6.28319\";
	auto expect2 = \"2 0 -0 1 0 0 -1 1\";
	CHECK(case1.find(expect1) != std::string::npos);
	CHECK(case1.find(expect2) != std::string::npos);




"}{"instruction": "Generate a test program based on the following method declarations and parameter parsing.",
 "input": "void SetRadius(double r)	 @param r The radius
	 @brief Set the radius of the circle
",
 "output": "#include<catch.hpp>
#include \"testHelper.h\"
#include<iostream>
#include <math/CircleT.hpp>
#include <common/AxisT.hpp>
#include <common/PointT.hpp>

TEST_CASE(\"case1: create a Circle\", \"math][CircleT][P1]\") 

	AMCAX::Point2 P(0.0,0.0);
	AMCAX::Direction2 D(1.0,0.0);
	AMCAX::Axis2  axis2(P, D);
	float radius = 5.0f;
	AMCAX::Circle2 circle2(axis2, radius, true);
	CHECK(circle2.Area() == radius * radius * M_PI);
    double a, b, c, d, e, f;
    circle2.Coefficients(a, b, c, d, e, f);  //test Coefficients()
    ..."},
{"instruction": "Generate a test program based on the following method declarations and parameter parsing.",
 "input": "[[nodiscard]] double Radius()	 @return The radius
	 @brief Get the radius
",
 "output": "#include<catch.hpp>
#include \"testHelper.h\"
#include<iostream>
#include <math/CircleT.hpp>
#include <common/AxisT.hpp>
#include <common/PointT.hpp>

TEST_CASE(\"CircleT Constructor Test\", \"[math][CircleT][P1]\") 
    SECTION(\"2D Circle Construction\") 
        AMCAX::Circle2 circle2;
        constexpr double maxr = std::numeric_limits<double>::max();
        CHECK(circle2.Radius() == Approx(maxr).epsilon(1e-15));
        ..."},
{"instruction": "Generate a test program based on the following method declarations and parameter parsing.",
 "input": "[[nodiscard]] double Length()	 @return The length of the circle
	 @brief Get the length of the circle
",
 "output": "#include<catch.hpp>
#include \"testHelper.h\"
#include<iostream>
#include <math/CircleT.hpp>
#include <common/AxisT.hpp>
#include <common/PointT.hpp>

TEST_CASE(\"CircleT Area and Length Test\", \"[CircleT]\") 
    AMCAX::Circle2 circle2;
    circle2.SetRadius(5.0);
    CHECK(circle2.Area() == Approx(78.53982));
    CHECK(circle2.Length() == Approx(31.41593));
    ..."},
{"instruction": "Generate a test program based on the following method declarations and parameter parsing.",
 "input": "[[nodiscard]] double Distance(const PointT<double, DIM>& p)	 @return The distance from the point to the circle
	 @param p The point
	 @brief Compute the distance from a point to the circle
",
 "output": "#include<catch.hpp>
#include \"testHelper.h\"
#include<iostream>
#include <math/CircleT.hpp>
#include <common/AxisT.hpp>
#include <common/PointT.hpp>

TEST_CASE(\"case1: create a Circle with Distance\", \"[math][CircleT][P1]\") 
	AMCAX::Point2 P(0.0,0.0);
	AMCAX::Circle2 circle2;
	circle2.SetRadius(5.0);
	CHECK(circle2.Distance(P) == Approx(5.0).epsilon(1e-15));
    ..."},
{"instruction": "Generate a test program based on the following method declarations and parameter parsing.",
 "input": "[[nodiscard]] double SquaredDistance(const PointT<double, DIM>& p)	 @return The squared distance from the point to the circle
	 @param p The point
	 @brief Compute the squared distance from a point to the circle
",
 "output": "#include<catch.hpp>
#include \"testHelper.h\"
#include<iostream>
#include <math/CircleT.hpp>
#include <common/AxisT.hpp>
#include <common/PointT.hpp>

TEST_CASE(\"case1: create a Circle with Squared Distance\", \"[math][CircleT][P1]\") 
	AMCAX::Point2 P(0.0,0.0);
	AMCAX::Circle2 circle2;
	circle2.SetRadius(5.0);
	CHECK(circle2.SquaredDistance(P) == Approx(25.0).epsilon(1e-15));
    ..."},
{"instruction": "Generate a test program based on the following method declarations and parameter parsing.",
 "input": "CircleS& Scale(const PointT<double, DIM>& p, double scale)	 @return The reference to self
	 @param scale The scale value
	 @param p The scaling center point
	 @brief Scale the circle by a center point
",
 "output": "#include<catch.hpp>
#include \"testHelper.h\"
#include<iostream>
#include <math/CircleT.hpp>
#include <common/AxisT.hpp>
#include <common/PointT.hpp>

TEST_CASE(\"case1: Scale Circle\", \"[math][CircleT][P1]\") 
	AMCAX::Circle2 circle;
	circle.SetRadius(5.0);
	AMCAX::Point2 center(0.0, 0.0);
	circle.Scale(center, 2.0);
	CHECK(circle.Radius() == Approx(10.0).epsilon(1e-15));
    ..."},
{"instruction": "Generate a test program based on the following method declarations and parameter parsing.",
 "input": "CircleS& Transform(const TransformationT<double, DIM>& tr)	 @return The reference to self
	 @param tr The transformation
	 @brief Transform the circle
",
 "output": "#include<catch.hpp>
#include \"testHelper.h\"
#include<iostream>
#include <math/CircleT.hpp>
#include <common/AxisT.hpp>
#include <common/PointT.hpp>

TEST_CASE(\"case1: Transform Circle\", \"[math][CircleT][P1\") 
	AMCAX::Circle2 circle;
	circle.SetRadius(5.0);
	TransformationT<double, 2> transformation;
	circle.Transform(transformation);
	..."}{"instruction": "Generate a test program based on the following method declarations and parameter parsing.",
 "input": "void SetRadius(double r)	 @param r The radius
	 @brief Set the radius of the circle
[nodiscard]] double Radius()	 @return The radius
	 @brief Get the radius
",
 "output": "#include <math/CircleT.hpp>
#include <common/CoordT.hpp>
#include <common/TransformationType.hpp>
#include <common/DirectionT.hpp>
#include <common/PointT.hpp>
#include <common/Precision.hpp>
#include <iostream>
#include \"catch.hpp\"

using namespace std;

TEST_CASE(\"TestCircle2D\", \"[math][Circle2D]\") {
	AMCAX::CircleT<double, 2> circle2D;
	circle2D.SetRadius(5.0);
	CHECK(circle2D.Radius() == 5.0);
}"},
{"instruction": "Generate a test program based on the following method declarations and parameter parsing.",
 "input": "[[nodiscard]] double Length()	 @return The length of the circle
	 @brief Get the length of the circle
",
 "output": "#include <math/CircleT.hpp>
#include <common/CoordT.hpp>
#include <common/TransformationType.hpp>
#include <common/DirectionT.hpp>
#include <common/PointT.hpp>
#include <common/Precision.hpp>
#include <iostream>
#include \"catch.hpp\"

using namespace std;

TEST_CASE(\"TestCircleLength\", \"[math][Circle]\") {
	AMCAX::CircleT<double, 2> circle2D;
	circle2D.SetRadius(5.0);
	CHECK(circle2D.Length() == Approx(31.4159));
}"},
{"instruction": "Generate a test program based on the following method declarations and parameter parsing.",
 "input": "[[nodiscard]] double Distance(const PointT<double, DIM>& p)	 @return The distance from the point to the circle
	 @param p The point
	 @brief Compute the distance from a point to the circle
",
 "output": "#include <math/CircleT.hpp>
#include <common/CoordT.hpp>
#include <common/TransformationType.hpp>
#include <common/DirectionT.hpp>
#include <common/PointT.hpp>
#include <common/Precision.hpp>
#include <iostream>
#include \"catch.hpp\"

using namespace std;

TEST_CASE(\"TestCircleDistance\", \"[math][Circle]\") {
	AMCAX::CircleT<double, 2> circle2D;
	AMCAX::PointT<double, 2> point(3.0, 4.0);
	circle2D.SetRadius(5.0);
	CHECK(circle2D.Distance(point) == Approx(1.0));
}"},
{"instruction": "Generate a test program based on the following method declarations and parameter parsing.",
 "input": "[[nodiscard]] double SquaredDistance(const PointT<double, DIM>& p)	 @return The squared distance from the point to the circle
	 @param p The point
	 @brief Compute the squared distance from a point to the circle
",
 "output": "#include <math/CircleT.hpp>
#include <common/CoordT.hpp>
#include <common/TransformationType.hpp>
#include <common/DirectionT.hpp>
#include <common/PointT.hpp>
#include <common/Precision.hpp>
#include <iostream>
#include \"catch.hpp\"

using namespace std;

TEST_CASE(\"TestCircleSquaredDistance\", \"[math][Circle]\") {
	AMCAX::CircleT<double, 2> circle2D;
	AMCAX::PointT<double, 2> point(3.0, 4.0);
	circle2D.SetRadius(5.0);
	CHECK(circle2D.SquaredDistance(point) == Approx(1.0));
}"},
{"instruction": "Generate a test program based on the following method declarations and parameter parsing.",
 "input": "CircleS& Scale(const PointT<double, DIM>& p, double scale)	 @return The reference to self
	 @param scale The scale value
	 @param p The scaling center point
	 @brief Scale the circle by a center point
",
 "output": "#include <math/CircleT.hpp>
#include <common/CoordT.hpp>
#include <common/TransformationType.hpp>
#include <common/DirectionT.hpp>
#include <common/PointT.hpp>
#include <common/Precision.hpp>
#include <iostream>
#include \"catch.hpp\"

using namespace std;

TEST_CASE(\"TestCircleScale\", \"[math][Circle]\") {
	AMCAX::CircleT<double, 2> circle2D;
	AMCAX::PointT<double, 2> center(0.0, 0.0);
	circle2D.SetRadius(5.0);
	circle2D.Scale(center, 2.0);
	CHECK(circle2D.Radius() == Approx(10.0));
}"},
{"instruction": "Generate a test program based on the following method declarations and parameter parsing.",
 "input": "CircleS& Transform(const TransformationT<double, DIM>& tr)	 @return The reference to self
	 @param tr The transformation
	 @brief Transform the circle
",
 "output": "#include <math/CircleT.hpp>
#include <common/CoordT.hpp>
#include <common/TransformationType.hpp>
#include <common/DirectionT.hpp>
#include <common/PointT.hpp>
#include <common/Precision.hpp>
#include <iostream>
#include \"catch.hpp\"

using namespace std;

TEST_CASE(\"TestCircleTransform\", \"[math][Circle\") {
	AMCAX::CircleT<double, 2> circle2D;
	circle2D.SetRadius(5.0);
	TransformationT<double, 2> transform;
	circle2D.Transform(transform);
	// Add checks for transformed circle properties
}"}{"instruction": "Generate a test program based on the following method declarations and parameter parsing.",
 "input": "AMCAX_API Classifier2d(const std::vector<Point2>& pts, double tolU, double tolV, double uMin, double vMin, double uMax, double vMax)	 @param vMax The upper bound of v
	 @param uMax The upper bound of u
	 @param vMin The lower bound of v
	 @param uMin The lower bound of u
	 @param tolV The tolerance of v bound
	 @param tolU The tolerance of u bound
	 @param pts The points of a 2D closed polygon, the last point does not required to repeat the first point
	 @details Require uMax > uMin, vMax > vMin, and at least 3 points
	 @brief Construct from a 2D polygon and uv-bounds",
 "output": "#include<catch.hpp>
#include<testHelper.h>

#include <common/PointT.hpp>
#include <math/Classifier2d.hpp>

using namespace AMCAX;

TEST_CASE(\"case1: Classifier2d \", \"math][Classifier2d][P1]\") 

    std::vector<Point2> pts = 
        Point2(2.0, 0.0),
        Point2(1.0, 1.0),
        Point2(2.0, 2.0),
        Point2(3.0, 2.0)
    ;

    double tolU = 0.1;
    double tolV = 0.1;
    double uMin = 0.0;
    double vMin = 0.0;
    double uMax = 2.5;
    double vMax = 1.5;

    Classifier2d classifier(pts, tolU, tolV, uMin, vMin, uMax, vMax);

    SECTION(\"IsInOut Point normal set\") 
        CHECK(classifier.IsInOut(Point2(0.0, 0.0)) == -1);
        CHECK(classifier.IsInOut(Point2(1.0, 1.0)) == 0);
        CHECK(classifier.IsInOut(Point2(2.0, 1.0)) == 1);
    

    SECTION(\"IsInOut Point normal set2 \") 
        CHECK(classifier.IsInOut(Point2(2.5, 1.9)) == -1);
        CHECK(classifier.IsInOut(Point2(1.5, 0.5)) == 0);
        CHECK(classifier.IsInOut(Point2(1.5, 1.0)) == 1);
        CHECK(classifier.IsInOut(Point2(2.0, 1.5)) == 1);
    

TEST_CASE(\"case2: Classifier2d \", \"[math][Classifier2d][P1]\") 

    std::vector<Point2> pts = 
        Point2(1.0, -2.0),
        Point2(1.0, 2.0),
        Point2(3.0, 1.0),
        Point2(3.0, -1.0)
    ;

    double tolU = 0.1;
    double tolV = 0.1;
    double uMin = 2.0;
    double vMin = -2.0;
    double uMax = 4.0;
    double vMax =  2.0;

    Classifier2d classifier(pts, tolU, tolV, uMin, vMin, uMax, vMax);

    SECTION(\"IsInOut Point normal set\") 
        CHECK(classifier.IsInOut(Point2(1.0, 2.0)) == -1);
        CHECK(classifier.IsInOut(Point2(1.5, 1.0)) == -1);
        CHECK(classifier.IsInOut(Point2(1.9, -1.6)) == 0);
        CHECK(classifier.IsInOut(Point2(2.5, -1.0)) == 1);
    

    SECTION(\"IsInOut Point normal set2 \") 
        CHECK(classifier.IsInOut(Point2(-0.5, -0.6)) == -1);
        CHECK(classifier.IsInOut(Point2(4.5, -0.4)) == -1);
        CHECK(classifier.IsInOut(Point2(3.0, -0.0)) == 0);
        CHECK(classifier.IsInOut(Point2(2.0,-0.0)) == 1);
        CHECK(classifier.IsInOut(Point2(2.8,-0.90)) == 1);
    

TEST_CASE(\"case3: Classifier2d \", \"[math][Classifier2d][P1\") 

    std::vector<Point2> pts = 
        Point2(2.0, 0.0),
        Point2(1.0, 1.0),
        Point2(2.0, 2.0),
        Point2(3.0, 2.0)
    ;

    double tolU = 0.1;
    double tolV = 0.1;
    double uMin = 0.0;
    double vMin = 0.0;
    double uMax = 2.5;
    double vMax = 1.5;

    Classifier2d classifier(pts, tolU, tolV, uMin, vMin, uMax, vMax);

    SECTION(\"IsInOutOn Point normal set\") 
        CHECK(classifier.IsInOutOn(Point2(0.0, 0.0), 0.0) == -1);
        CHECK(classifier.IsInOutOn(Point2(1.0, 1.0), 0.0) != 0);
        CHECK(classifier.IsInOutOn(Point2(1.0, 1.0), 1.0) == 0);
        CHECK(classifier.IsInOutOn(Point2(2.0, 1.0), 0.0) == 1);
    

    SECTION(\"IsInOutOn Point normal set2 \") 
        CHECK(classifier.IsInOutOn(Point2(2.5, 1.9), 0.3) == -1);
        CHECK(classifier.IsInOutOn(Point2(1.5, 0.5), 0.0) != 0);
        CHECK(classifier.IsInOutOn(Point2(1.5, 1.0), 1.0) == 1);
        CHECK(classifier.IsInOutOn(Point2(2.0, 1.5), 0.0) == 1);
    
"}{"instruction": "Generate a test program based on the following method declarations and parameter parsing.",
 "input": "[nodiscard]] AMCAX_API Point3 Apex()	 @return The apex point
	 @brief Get the apex of the cone",
 "output": "#include<iostream>
#include \"catch.hpp\"
#include <common/FrameT.hpp>
#include <modeling/MakeFace.hpp>
#include <common/AxisT.hpp>
#include <common/FrameT.hpp>
#include <common/VectorT.hpp>
#include <math/Cone.hpp>
using namespace AMCAX;
using namespace std;

TEST_CASE(\"TestCone\", \"[math][Cone]\")

	AMCAX::Frame3 frame;
	double radius = 5.0;
	double angle = M_PI / 4;
	AMCAX::Cone cone(frame, radius, angle);
	AMCAX::Point3 apex = cone.Apex();
	CHECK(apex.X() == 0.0);
	CHECK(apex.Y() == 0.0);
	CHECK(apex.Z() == Approx(-5.0));"},
{"instruction": "Generate a test program based on the following method declarations and parameter parsing.",
 "input": "[[nodiscard]] AMCAX_API double SemiAngle()	 @return The semi-angle
	 @brief Get the semi-angle",
 "output": "#include<iostream>
#include \"catch.hpp\"
#include <common/FrameT.hpp>
#include <modeling/MakeFace.hpp>
#include <common/AxisT.hpp>
#include <common/FrameT.hpp>
#include <common/VectorT.hpp>
#include <math/Cone.hpp>
using namespace AMCAX;
using namespace std;

TEST_CASE(\"TestCone\", \"[math][Cone]\")

	AMCAX::Frame3 frame;
	double radius = 5.0;
	double angle = M_PI / 4;
	AMCAX::Cone cone(frame, radius, angle);
	double semiCone = cone.SemiAngle();
	CHECK(semiCone == Approx(0.785398));"},
{"instruction": "Generate a test program based on the following method declarations and parameter parsing.",
 "input": "Cone()	 @brief Default constructor",
 "output": "#include<iostream>
#include \"catch.hpp\"
#include <common/FrameT.hpp>
#include <modeling/MakeFace.hpp>
#include <common/AxisT.hpp>
#include <common/FrameT.hpp>
#include <common/VectorT.hpp>
#include <math/Cone.hpp>
using namespace AMCAX;
using namespace std;

TEST_CASE(\"TestCone\", \"[math][Cone]\")

	AMCAX::Frame3 frame;
	double radius = 5.0;
	double angle = M_PI / 4;
	AMCAX::Cone cone(frame, radius, angle);"},
{"instruction": "Generate a test program based on the following method declarations and parameter parsing.",
 "input": "AMCAX_API Cone(const Frame3& frame, double r, double angle)	 @param angle The semi-angle
	@param r The reference radius
	@param frame The local frame
	@brief Construct from a local frame, a reference radius and a semi-angle",
 "output": "#include<iostream>
#include \"catch.hpp\"
#include <common/FrameT.hpp>
#include <modeling/MakeFace.hpp>
#include <common/AxisT.hpp>
#include <common/FrameT.hpp>
#include <common/VectorT.hpp>
#include <math/Cone.hpp>
using namespace AMCAX;
using namespace std;

TEST_CASE(\"TestCone\", \"[math][Cone]\")

	AMCAX::Frame3 frame;
	double radius = 5.0;
	double angle = M_PI / 4;
	AMCAX::Cone cone(frame, radius, angle);"},
{"instruction": "Generate a test program based on the following method declarations and parameter parsing.",
 "input": "AMCAX_API Cone& Scale(const Point3& point, double scale)	 @return The reference to self
	@param scale The scale value
	@param point The scaling center point
	@brief Scale the cone by a point",
 "output": "#include<iostream>
#include \"catch.hpp\"
#include <common/FrameT.hpp>
#include <modeling/MakeFace.hpp>
#include <common/AxisT.hpp>
#include <common/FrameT.hpp>
#include <common/VectorT.hpp>
#include <math/Cone.hpp>
using namespace AMCAX;
using namespace std;

TEST_CASE(\"TestCone\", \"[math][Cone]\")

	AMCAX::Frame3 frame;
	double radius = 5.0;
	double angle = M_PI / 4;
	AMCAX::Cone cone(frame, radius, angle);
	double scaleCone = 2.0;
	cone.Scale(cone.Location(), scaleCone);"},
{"instruction": "Generate a test program based on the following method declarations and parameter parsing.",
 "input": "AMCAX_API Cone& Transform(const Transformation3& tr)	 @return The reference to self
	@param tr The transformation
	@brief Transform the cone",
 "output": "#include<iostream>
#include \"catch.hpp\"
#include <common/FrameT.hpp>
#include <modeling/MakeFace.hpp>
#include <common/AxisT.hpp>
#include <common/FrameT.hpp>
#include <common/VectorT.hpp>
#include <math/Cone.hpp>
using namespace AMCAX;
using namespace std;

TEST_CASE(\"TestCone\", \"[math][Cone\")

	AMCAX::Frame3 frame;
	double radius = 5.0;
	double angle = M_PI / 4;
	AMCAX::Cone cone(frame, radius, angle);
	AMCAX::Transformation3 tr;
	tr.SetTranslation(Vector3(1.0, 2.0, 3.0));
	cone.Transform(tr);"}    {
        "instruction": "Generate a test program based on the following method declarations and parameter parsing.",
        "input": "[[nodiscard]] AMCAX_API Point3 Apex()	 @return The apex point
	 @brief Get the apex of the cone",
        "output": "#include<catch.hpp>
#include<testHelperBase.h>

#include <polymeshAPI/MeshMakeCone.hpp>
#include <polymesh/PolyMeshIO.hpp>
#include <polymeshAPI/MeshSubdivideHE.hpp>

using namespace AMCAX;

TEST_CASE(\"case1:MeshMakeCone  \", \"[polymeshAPI][SubD][MeshMakeCone][P1]\") 
	double r = 1;
	double h = 1;
	SubD::MeshMakeCone meshmakeCone(r, h);
	AMCAX::SubD::PolyMesh* mesh = meshmakeCone.BuildMesh();
	CHECK(mesh != nullptr);
	AMCAX::SubD::MeshSubdivideHE::CatmullClark(mesh, 3);
	bool result = AMCAX::SubD::PolyMeshIO::WriteMesh(OUTPUT_PATH_PREFIX\"MeshMakeCone_case01.obj\", mesh);
	CHECK(result == true);"
    },
    {
        "instruction": "Generate a test program based on the following method declarations and parameter parsing.",
        "input": "[[nodiscard]] AMCAX_API double SemiAngle()	 @return The semi-angle
	 @brief Get the semi-angle",
        "output": "#include<catch.hpp>
#include<testHelperBase.h>

#include <polymeshAPI/MeshMakeCone.hpp>
#include <polymesh/PolyMeshIO.hpp>
#include <polymeshAPI/MeshSubdivideHE.hpp>

using namespace AMCAX;

TEST_CASE(\"case1:MeshMakeCone  \", \"[polymeshAPI][SubD][MeshMakeCone][P1]\") 
	double r = 1;
	double h = 1;
	SubD::MeshMakeCone meshmakeCone(r, h);
	AMCAX::SubD::PolyMesh* mesh = meshmakeCone.BuildMesh();
	CHECK(mesh != nullptr);
	AMCAX::SubD::MeshSubdivideHE::CatmullClark(mesh, 3);
	bool result = AMCAX::SubD::PolyMeshIO::WriteMesh(OUTPUT_PATH_PREFIX\"MeshMakeCone_case01.obj\", mesh);
	CHECK(result == true);"
    },
    {
        "instruction": "Generate a test program based on the following method declarations and parameter parsing.",
        "input": "Cone()	 @brief Default constructor",
        "output": "#include<catch.hpp>
#include<testHelperBase.h>

#include <polymeshAPI/MeshMakeCone.hpp>
#include <polymesh/PolyMeshIO.hpp>
#include <polymeshAPI/MeshSubdivideHE.hpp>

using namespace AMCAX;

TEST_CASE(\"case1:MeshMakeCone  \", \"[polymeshAPI][SubD][MeshMakeCone][P1]\") 
	double r = 1;
	double h = 1;
	SubD::MeshMakeCone meshmakeCone(r, h);
	AMCAX::SubD::PolyMesh* mesh = meshmakeCone.BuildMesh();
	CHECK(mesh != nullptr);
	AMCAX::SubD::MeshSubdivideHE::CatmullClark(mesh, 3);
	bool result = AMCAX::SubD::PolyMeshIO::WriteMesh(OUTPUT_PATH_PREFIX\"MeshMakeCone_case01.obj\", mesh);
	CHECK(result == true);"
    },
    {
        "instruction": "Generate a test program based on the following method declarations and parameter parsing.",
        "input": "AMCAX_API Cone(const Frame3& frame, double r, double angle)	 @param angle The semi-angle
	@param r The reference radius
	@param frame The local frame
	 @brief Construct from a local frame, a reference radius and a semi-angle",
        "output": "#include<catch.hpp>
#include<testHelperBase.h>

#include <polymeshAPI/MeshMakeCone.hpp>
#include <polymesh/PolyMeshIO.hpp>
#include <polymeshAPI/MeshSubdivideHE.hpp>

using namespace AMCAX;

TEST_CASE(\"case1:MeshMakeCone  \", \"[polymeshAPI][SubD][MeshMakeCone][P1]\") 
	double r = 1;
	double h = 1;
	SubD::MeshMakeCone meshmakeCone(r, h);
	AMCAX::SubD::PolyMesh* mesh = meshmakeCone.BuildMesh();
	CHECK(mesh != nullptr);
	AMCAX::SubD::MeshSubdivideHE::CatmullClark(mesh, 3);
	bool result = AMCAX::SubD::PolyMeshIO::WriteMesh(OUTPUT_PATH_PREFIX\"MeshMakeCone_case01.obj\", mesh);
	CHECK(result == true);"
    },
    {
        "instruction": "Generate a test program based on the following method declarations and parameter parsing.",
        "input": "AMCAX_API Cone& Scale(const Point3& point, double scale)	 @return The reference to self
	@param scale The scale value
	@param point The scaling center point
	 @brief Scale the cone by a point",
        "output": "#include<catch.hpp>
#include<testHelperBase.h>

#include <polymeshAPI/MeshMakeCone.hpp>
#include <polymesh/PolyMeshIO.hpp>
#include <polymeshAPI/MeshSubdivideHE.hpp>

using namespace AMCAX;

TEST_CASE(\"case1:MeshMakeCone  \", \"[polymeshAPI][SubD][MeshMakeCone][P1]\") 
	double r = 1;
	double h = 1;
	SubD::MeshMakeCone meshmakeCone(r, h);
	AMCAX::SubD::PolyMesh* mesh = meshmakeCone.BuildMesh();
	CHECK(mesh != nullptr);
	AMCAX::SubD::MeshSubdivideHE::CatmullClark(mesh, 3);
	bool result = AMCAX::SubD::PolyMeshIO::WriteMesh(OUTPUT_PATH_PREFIX\"MeshMakeCone_case01.obj\", mesh);
	CHECK(result == true);"
    },
    {
        "instruction": "Generate a test program based on the following method declarations and parameter parsing.",
        "input": "AMCAX_API Cone& Transform(const Transformation3& tr)	 @return The reference to self
	@param tr The transformation
	 @brief Transform the cone",
        "output": "#include<catch.hpp>
#include<testHelperBase.h>

#include <polymeshAPI/MeshMakeCone.hpp>
#include <polymesh/PolyMeshIO.hpp>
#include <polymeshAPI/MeshSubdivideHE.hpp>

using namespace AMCAX;

TEST_CASE(\"case1:MeshMakeCone  \", \"[polymeshAPI][SubD][MeshMakeCone][P1]\") 
	double r = 1;
	double h = 1;
	SubD::MeshMakeCone meshmakeCone(r, h);
	AMCAX::SubD::PolyMesh* mesh = meshmakeCone.BuildMesh();
	CHECK(mesh != nullptr);
	AMCAX::SubD::MeshSubdivideHE::CatmullClark(mesh, 3);
	bool result = AMCAX::SubD::PolyMeshIO::WriteMesh(OUTPUT_PATH_PREFIX\"MeshMakeCone_case01.obj\", mesh);
	CHECK(result == true);"
    }