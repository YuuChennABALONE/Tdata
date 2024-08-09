/* "[[nodiscard]] double Distance(const PointT<double, DIM>& p)\t @return The distance from the point to the circle\n\t @param p The point\n\t @brief Compute the distance from a point to the circle\n,\n",
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
TEST_CASE("TestCircle3D", "[math][Circle3D]")
{
	AMCAX::Circle3 circle3D;
	AMCAX::Point3  center3D(0.0, 0.0, 0.0);
	double radius3D = 5.0;
	double tol = 0.1;
	circle3D.SetLocation(center3D);
	circle3D.SetRadius(radius3D);
	double area = circle3D.Area();
	auto axis = circle3D.Axis();
	AMCAX::Point3 expectedDirection(0.0, 0.0, 1.0);
	auto direction = axis.Direction();
	CHECK(area == Approx(78.5398));
	CHECK(direction.X() == Approx(expectedDirection.X()).margin(tol));
	CHECK(direction.Y() == Approx(expectedDirection.Y()).margin(tol));
	CHECK(direction.Z() == Approx(expectedDirection.Z()).margin(tol));
	std::vector <AMCAX::Point3> test3DPoints = {
		AMCAX::Point3(0.0, 0.0, 0.0),
		AMCAX::Point3(4.0, 0.0, 0.0),
	};
	for (const auto& point : test3DPoints)
	{
		double distanceToCenter = std::sqrt(std::pow(point.X() - center3D.X(), 2) + std::pow(point.Y() - center3D.Y(), 2) + std::pow(point.Z() - center3D.Z(), 2));
		bool expectedIsCircle = distanceToCenter <= 5.0 + tol;
		bool isInCircle = circle3D.Contains(point, tol);
		CHECK(!isInCircle == expectedIsCircle);
	}
	AMCAX::PointT<double, 3>  pointOutside(10.0, 0.0, 0.0);
	double expectedDistance = 5.0;
	CHECK(circle3D.Distance(pointOutside) == Approx(expectedDistance));
	double length = circle3D.Length();
	CHECK(length == Approx(31.4159));
	auto location = circle3D.Location();
	CHECK(location.X() == Approx(0.0));
	CHECK(location.Y() == Approx(0.0));
	CHECK(location.Z() == Approx(0.0));
	AMCAX::PointT<double, 3> mirrorPoint(1.0, 0.0, 0.0);
	circle3D.Mirror(mirrorPoint);
	auto mirroredLocation = circle3D.Location();
	CHECK(mirroredLocation.X() == Approx(2.0));
	CHECK(mirroredLocation.Y() == Approx(0.0));
	CHECK(mirroredLocation.Z() == Approx(0.0));
	auto position = circle3D.Position();   
	double r = circle3D.Radius();
	CHECK(r == 5.0);
	Direction3 zDirection(0.0, 0.0, 1.0);
	Axis3 zAxis(center3D, zDirection);
	Transformation3 rotation;
	rotation.SetRotation(zAxis, M_PI / 2);  
	Point3 newCenter1 = center3D.Transformed(rotation);
	CHECK(newCenter1.X() == 0.0);
	CHECK(newCenter1.Y() == 0.0);
	CHECK(newCenter1.Z() == 0.0);
	double angle = M_PI / 2;
	circle3D.Rotated(zAxis, angle);
	AMCAX::Frame3 frame = circle3D.Position();
	CHECK(frame.Location().X() == 2.0);
	CHECK(frame.Location().Y() == 0.0);
	CHECK(frame.Location().Z() == 0.0);
	double scale = 2.0;
	circle3D.Scale(center3D, scale);
	CHECK(circle3D.Radius() == radius3D * 2.0);
	AMCAX::PointT<double, 3> insidePoint(3.0, 4.0, 0.0);
	AMCAX::PointT<double, 3> onCirclePoint(5.0, 0.0, 0.0);
	AMCAX::PointT<double, 3> outsidePoint(8.0, 6.0, 0.0);
	double insideSquaredDistance = circle3D.SquaredDistance(insidePoint);
	double onCircleSquaredDistance = circle3D.SquaredDistance(onCirclePoint);
	double outsideSquaredDistance = circle3D.SquaredDistance(outsidePoint);
	CHECK(insideSquaredDistance == Approx(34.5378));
	CHECK(onCircleSquaredDistance == 81.0);
	CHECK(outsideSquaredDistance == Approx(7.7779));
	VectorT<double, 3> translationVector(5.0, 5.0, 0.0);
	circle3D.Translate(translationVector);
	CHECK(circle3D.Location().X() == 9.0);
	CHECK(circle3D.Location().Y() == 5.0);
	CHECK(circle3D.Location().Z() == 0.0);
	auto xAxis = circle3D.XAxis();
	auto yAxis = circle3D.YAxis();
	CHECK(xAxis.Direction().X() == Approx(-1.0));
	CHECK(yAxis.Direction().Y() == Approx(-1.0));
}