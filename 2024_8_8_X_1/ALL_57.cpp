/* "[[nodiscard]] double Length()\t @return The length of the circle\n\t @brief Get the length of the circle\n,\n",
      */
 #include <math/CircleT.hpp>
#include <common/CoordT.hpp>
#include <common/TransformationType.hpp>
#include <common/DirectionT.hpp>
#include <common/PointT.hpp>
#include <common/Precision.hpp>
#include <common/CoordT.hpp>
#include <common/TransformationType.hpp>
#include <topology/TopoEdge.hpp>
#include <modeling/MakeEdge.hpp>
#include <topology/TopoWire.hpp>
#include <modeling/MakeWire.hpp>
#include <geometry/GlobalProperty.hpp>
#include <topology/BRepGlobalProperty.hpp>
#include<iostream>
#include "catch.hpp" 
using namespace std;
using namespace AMCAX;
TEST_CASE("TestCircle2D", "[math][Circle2D]")
{
	AMCAX::CircleT<double, 2> circle2D;
	AMCAX::Point2 center2D(0.0, 0.0);
	double redius2D = 5.0;
	double tol = 0.1;
	circle2D.SetLocation(center2D);
	circle2D.SetRadius(redius2D);
	double area2D = circle2D.Area();
	double length2D = circle2D.Length();
	AMCAX::Point2 retcenter2D = circle2D.Location();
	double retarea2D = M_PI * redius2D * redius2D;
	double retlength2D = 2 * M_PI * redius2D;
	std::cout << area2D << std::endl;
	std::cout << length2D << std::endl;
	std::cout << retcenter2D.X() << std::endl;
	std::cout << retcenter2D.Y() << std::endl;
	CHECK(area2D == retarea2D);
	CHECK(length2D == retlength2D);
	CHECK(retcenter2D.X() == center2D.X());
	CHECK(retcenter2D.Y() == center2D.Y());
	double a, b, c, d, e, f;
	circle2D.Coefficients(a, b, c, d, e, f);
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << e << std::endl;
	std::cout << f << std::endl;
	CHECK(a == 1);
	CHECK(b == 1);
	CHECK(c == 0);
	CHECK(d == 0);
	CHECK(e == 0);
	CHECK(f == -25);
	std::vector < AMCAX::Point2> testPoints = {
		AMCAX::Point2(3.0, 4.0),
		AMCAX::Point2(5.0, 0.0),
		AMCAX::Point2(4.9, 0.0),
		AMCAX::Point2(5.1, 0.0),
		AMCAX::Point2(6.0, 0.0)
	};
	for (const auto& point : testPoints)
	{
		double distanceToCenter = std::sqrt(point.X() * point.X() + point.Y() * point.Y());
		bool expectedIsInCircle = distanceToCenter <= 5.0 + tol;
		bool isInCircle = circle2D.Contains(point, tol);
		CHECK(isInCircle == expectedIsInCircle);
	}
	for (const auto& point : testPoints)
	{
		double distance = circle2D.Distance(point);
		double expectedDistance = std::abs(std::sqrt(std::pow(point.X() - center2D.X(), 2) + std::pow(point.Y() - center2D.Y(), 2)) - redius2D);
		CHECK(distance == expectedDistance);
	}
	AMCAX::AxisT<double, 2> mirrorAxis(AMCAX::Point2(0.0, 0.0), AMCAX::Direction2(0.0, 1.0));
	circle2D.Mirror(mirrorAxis);
	AMCAX::Point2 mirroredCenter = circle2D.Location();
	std::cout << "Mirrored circle center: (" << mirroredCenter.X() << ", " << mirroredCenter.Y() << ")" << std::endl;
	CHECK(mirroredCenter.X() == center2D.X());
	CHECK(mirroredCenter.Y() == center2D.Y());
	const AMCAX::FrameT<double, 2>& frame = circle2D.Position();
	AMCAX::Point2 rotationPoint(0.0, 0.0);
	double  rotationAngle = M_PI / 4;
	auto rotatedCircle = circle2D.Rotated(rotationPoint, rotationAngle);
	double cosAngle = cos(rotationAngle);
	double sinAngle = sin(rotationAngle);
	double newX = cosAngle * (center2D.X() - rotationPoint.X()) - sinAngle * (center2D.Y() - rotationPoint.Y()) + rotationPoint.X();
	double newY = sinAngle * (center2D.X() - rotationPoint.X()) + cosAngle * (center2D.Y() - rotationPoint.Y()) + rotationPoint.Y();
	auto rotatedCenter = rotatedCircle.Location();
	CHECK(newX == center2D.X());
	CHECK(newY == center2D.Y());
	AMCAX::Point2 scalingCenter(0.0, 0.0);
	double scalingFactor = 2.0;
	auto scaledCircle = circle2D.Scale(scalingCenter, scalingFactor);
	double scaledRadius = scaledCircle.Radius();
	double expectedScaledRadius = redius2D * scalingFactor;
	CHECK(std::abs(scaledRadius - expectedScaledRadius) < 1e-6);
	AMCAX::VectorT<double, 2> translationVector(2.0, 3.0);
	auto translatedCircle = circle2D.Translated(translationVector);
	auto translatedCenter = translatedCircle.Location();
	double translatedX = center2D.X() + translationVector.X();
	CHECK(translatedX == translatedCenter.X());
	auto xAxis = circle2D.XAxis();
	auto directionAxis = xAxis.Direction();
	CHECK(directionAxis.X() == -1.0);
	CHECK(directionAxis.Y() == 0.0);
}