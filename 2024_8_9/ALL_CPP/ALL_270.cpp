/* "AMCAX_API Cone(const Frame3& frame, double r, double angle)\t @param angle The semi-angle\n\t @param r The reference radius\n\t @param frame The local frame\n\t @brief Construct from a local frame, a reference radius and a semi-angle\n,\n",
      */
 #include<iostream>
#include "catch.hpp"
#include <common/FrameT.hpp>
#include <modeling/MakeFace.hpp>
#include <common/AxisT.hpp>
#include <common/FrameT.hpp>
#include <common/VectorT.hpp>
#include <math/Cone.hpp>
using namespace AMCAX;
using namespace std;
TEST_CASE("TestCone", "[math][Cone]")
{
	AMCAX::Frame3 frame;
	double radius = 5.0;
	double angle = M_PI / 4;
	AMCAX::Cone cone(frame, radius, angle);
	AMCAX::Point3 apex = cone.Apex();
	CHECK(apex.X() == 0.0);
	CHECK(apex.Y() == 0.0);
	CHECK(apex.Z() == Approx(-5.0));
	AMCAX::Axis3 axis = cone.Axis();
	std::cout << axis.Direction().X() << std::endl;
	std::cout << axis.Direction().Y() << std::endl;
	std::cout << axis.Direction().Z() << std::endl;
	CHECK(axis.Direction().X() == 0.0);
	CHECK(axis.Direction().Y() == 0.0);
	CHECK(axis.Direction().Z() == 1.0);
	double a1, a2, a3, b1, b2, b3, c1, c2, c3, d;
	cone.Coefficients(a1, a2, a3, b1, b2, b3, c1, c2, c3, d);
	std::cout << "a1: " << a1 << ", a2: " << a2 << ", a3: " << a3 << std::endl;
	std::cout << "b1: " << b1 << ", b2: " << b2 << ", b3: " << b3 << std::endl;
	std::cout << "c1: " << c1 << ", c2: " << c2 << ", c3: " << c3 << std::endl;
	std::cout << "d: " << d << std::endl;
	CHECK(a1 == 1.0);
	CHECK(a2 == 1.0);
	CHECK(a3 == Approx(-1.0));
	CHECK(b1 == 0);
	CHECK(b2 == 0);
	CHECK(b3 == 0);
	CHECK(c1 == 0);
	CHECK(c2 == 0);
	CHECK(c3 == Approx(-5.0));
	CHECK(d == -25.0);
	CHECK(cone.IsDirect() == true);
	CHECK(cone.Location().X() == 0.0);
	CHECK(cone.Location().Y() == 0.0);
	CHECK(cone.Location().Z() == 0.0);
	AMCAX::PointT<double, 3>mirrorPoint(5.0, 0.0, 0.0);
	cone.Mirror(mirrorPoint);
	auto mirroredLocation = cone.Location();
	CHECK(mirroredLocation.X() == 10.0);
	CHECK(mirroredLocation.Y() == 0.0);
	CHECK(mirroredLocation.Z() == 0.0);
	AMCAX::Frame3 coneFrame = cone.Position();
	CHECK(frame.Location().X() == 0.0);
	CHECK(frame.Location().Y() == 0.0);
	CHECK(frame.Location().Z() == 0.0);
	CHECK(cone.Radius() == 5.0);
	double  scaleCone = 2.0;
	cone.Scale(cone.Location(), scaleCone);
	CHECK(cone.Radius() == radius * 2.0);
	double semiCone = cone.SemiAngle();
	CHECK(semiCone == Approx(0.785398));
	const  Frame3& position = cone.Position();
	std::cout << position.XAxis() << std::endl;
	std::cout << position.YAxis() << std::endl;
	Direction3 zDirection(0.0, 0.0, 1.0);
	AMCAX::Point3  centerCone(0.0, 0.0, 0.0);
	Axis3 zAxis(centerCone, zDirection);
	cone.Rotated(zAxis, angle);
	AMCAX::Frame3 coneFrame2 = cone.Position();
	CHECK(coneFrame.Location().X() == 10.0);
	CHECK(coneFrame.Location().Y() == 0.0);
	CHECK(coneFrame.Location().Z() == 0.0);
	double scale = 2.0;
	cone.Scale(centerCone, scale);
	CHECK(cone.Radius() == radius * 4.0);
	double semiAngle = cone.SemiAngle();
	std::cout << semiAngle << std::endl;
	CHECK(semiAngle == Approx(0.785398));
	VectorT<double, 3> translationVector(5.0, 5.0, 0.0);
	cone.Translate(translationVector);
	CHECK(cone.Location().X() == 25.0);
	CHECK(cone.Location().Y() == 5.0);
	CHECK(cone.Location().Z() == 0.0);
	auto xAxis = cone.XAxis();
	auto yAxis = cone.YAxis();
	CHECK(xAxis.Direction().X() == Approx(-1.0));
	CHECK(yAxis.Direction().Y() == Approx(-1.0));
	AMCAX::Transformation3 tr;
	tr.SetTranslation(Vector3(1.0, 2.0, 3.0));
	cone.Transform(tr);
	Axis3 newXAxis = cone.Position().XAxis();
	CHECK(newXAxis.Location().X() == 26.0);
	CHECK(newXAxis.Location().Y() == 7.0);
	CHECK(newXAxis.Location().Z() == 3.0);
}