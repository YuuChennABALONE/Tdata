/* "[[nodiscard]] double Distance(const PointT<double, DIM>& p)\t @return The distance from the point to the circle\n\t @param p The point\n\t @brief Compute the distance from a point to the circle\n,\n",
      */
 #include<catch.hpp>
#include "testHelper.h"
#include<iostream>
#include <math/CircleT.hpp>
#include <common/AxisT.hpp>
#include <common/PointT.hpp>
TEST_CASE("case1: create a Cirecle", "[math][CircleT][P1]") {
	AMCAX::Point2 P(0.0,0.0);
	AMCAX::Direction2 D(1.0,0.0);
	AMCAX::Axis2  axis2(P, D);
	float radius = 5.0f;
	AMCAX::Circle2 circle2(axis2, radius, true);
	CHECK(circle2.Area() == radius * radius * M_PI); 
    double a, b, c, d, e, f;
    circle2.Coefficients(a, b, c, d, e, f);  
    double x = 0, y = 5;
    CHECK(a * x * x + b * y * y + c * x * y + d * x + e * y + f == Approx(0.0).epsilon(1e-15));
    double x1 = 5 * sqrt(2) / 2;
    double y1 = 5 * sqrt(2) / 2;
    double x2 = 6;
    double y2 = 0;
    double x3 = 5.5;
    double y3 = 6.1;
    AMCAX::Point2 P1(x1,y1);
    AMCAX::Point2 P2(x2, y2);
    AMCAX::Point2 P3(x3, y3);
    double tolerance1 = 0.1;
    double tolerance2 = 1.0;
    CHECK(circle2.Contains(P1, tolerance1) == true);
    CHECK(circle2.Contains(P2, tolerance2) == true);
    CHECK(circle2.Contains(P3, tolerance2) == false);
    CHECK(circle2.Distance(P1) == Approx(0.0).epsilon(1e-15));
    CHECK(circle2.Distance(P2) == Approx(1.0).epsilon(1e-15));
    CHECK(circle2.Length() == Approx(2*M_PI*radius).epsilon(1e-15));
    AMCAX::Point2 locationP = circle2.Location();
    CHECK(locationP.X() == Approx(0.0).epsilon(1e-15));
    CHECK(locationP.Y() == Approx(0.0).epsilon(1e-15));
    AMCAX::Point2 mirrorAxisPoint(1.0, 0.0);
    AMCAX::Direction2 mirrorAxisDirection(0.0, 1.0);
    AMCAX::Axis2 mirrorAxis(mirrorAxisPoint, mirrorAxisDirection);
    circle2.Mirror(mirrorAxis);
    CHECK(circle2.Length() == Approx(2 * M_PI * radius).epsilon(1e-15));
    AMCAX::Point2 locationPmirror = circle2.Location();
    CHECK(locationPmirror.X() == Approx(2.0).epsilon(1e-15));
    CHECK(locationPmirror.Y() == Approx(0.0).epsilon(1e-15));
    AMCAX::Point2 P4(7.0, 0.0);  
    CHECK(circle2.Contains(P4, tolerance2) == true);
    AMCAX::Point2 mirroredAxisPoint(1.0, 0.0);
    AMCAX::Direction2 mirroredAxisDirection(0.0, 1.0);
    AMCAX::Axis2 mirroedrAxis(mirroredAxisPoint, mirroredAxisDirection);
    AMCAX::Circle2 circle2mirrored = circle2.Mirrored(mirroedrAxis);
    CHECK(circle2mirrored.Length() == Approx(2 * M_PI * radius).epsilon(1e-15));
    AMCAX::Point2 locationPmirrored = circle2mirrored.Location();
    CHECK(locationPmirrored.X() == Approx(0.0).epsilon(1e-15));
    CHECK(locationPmirrored.Y() == Approx(0.0).epsilon(1e-15));
    AMCAX::Frame2 frame2mirrored = circle2mirrored.Position(); 
    CHECK(frame2mirrored.Location().X() == Approx(0.0).epsilon(1e-15));
    CHECK(frame2mirrored.Location().Y() == Approx(0.0).epsilon(1e-15));
    const double& radiusmirrored = circle2mirrored.Radius(); 
    CHECK(radiusmirrored == Approx(radius).epsilon(1e-15));
    circle2mirrored.Scale(P,0.5); 
    AMCAX::Point2 scaleP1(0.0,-2.5);
    CHECK(circle2mirrored.Contains(scaleP1, 0) == true);
    AMCAX::Circle2 circle2Scaled = circle2mirrored.Scale(P, 2); 
    AMCAX::Point2 scaledP1(0.0, 5.0);
    CHECK(circle2Scaled.Contains(scaledP1, 0) == true);
    AMCAX::Point2 rotateP(0.0,0.0);
    double angle = 90.0 * (2 * M_PI / 360.0);
    circle2.Rotate(rotateP, angle); 
    AMCAX::Point2 P5(0.0, -3.0);
    CHECK(circle2.Contains(P5, 0) == true);
    double angle2 = -180.0 * (2 * M_PI / 360.0);
    AMCAX::Circle2 rotatedCircle2 = circle2.Rotated(rotateP, angle2); 
    AMCAX::Point2 P6(0.0, 3.0);
    CHECK(rotatedCircle2.Contains(P6, 0) == true); 
    AMCAX::Point2 newP(0.0, 0.0);
    rotatedCircle2.SetLocation(newP);
    CHECK(rotatedCircle2.Contains(P1, 0) == true);
    std::cout << circle2.Length() << std::endl;
}