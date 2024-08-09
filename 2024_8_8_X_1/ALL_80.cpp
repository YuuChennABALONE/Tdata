/* "[[nodiscard]] AMCAX_API double SquaredDistance(const Point3& point)\t @return The squared point-plane distance\n\t @param point The point\n\t @brief Compute the squared distance from a point to the plane\n,\n",
      */
 #include "catch.hpp"
#include <testHelper.h>
#include <math/Plane.hpp>
using namespace AMCAX;
TEST_CASE("case1: Plane construction and methods", "[math][Plane][p1]") {
	SECTION("Distance methods") {
        std::function<double(const Plane&, const Point3&)> pointToPlane = [](const Plane& plane, const Point3& point)->double {
            double a, b, c, d;
            plane.Coefficients(a, b, c, d);
            return std::fabs(a * point.X() + b * point.Y() + c * point.Z() + d);
        };
        std::function<double(const Plane&, const Line3&)> lineToPlane = [](const Plane& plane, const Line3& line)->double {
            Point3 point = line.Location();
            double a, b, c, d;
            plane.Coefficients(a, b, c, d);
            if (line.Direction().Dot(Vector3(a, b, c)) != 0)  
                return 0;
            return std::fabs(a * point.X() + b * point.Y() + c * point.Z() + d);
        };
        std::function<double(const Plane&, const Plane&)> planeToPlane = [](const Plane& plane1, const Plane& plane2)->double {
            double a1, b1, c1, d1, a2, b2, c2, d2;
            plane1.Coefficients(a1, b1, c1, d1);
            plane2.Coefficients(a2, b2, c2, d2);
            if (a1 != a2 || b1 != b2 || c1 != c2) return 0;
            return std::fabs(d1 - d2);
        };
        Plane plane(0., 0., 1., -1.); 
        Point3 point(1., 1., 2.);
        Line3 line(Point3(1., 1., 3.), Direction3(0., 0., 1.));
        Plane otherPlane1(0, 0, 1, -2); 
        Plane otherPlane2(1, 0, 1, -2); 
        REQUIRE(plane.Distance(point) == Approx(pointToPlane(plane, point)));
        REQUIRE(plane.SquaredDistance(point) == Approx(pointToPlane(plane, point) * pointToPlane(plane, point)));
        REQUIRE(plane.Distance(line) == Approx(lineToPlane(plane, line)));
        REQUIRE(plane.SquaredDistance(line) == Approx(lineToPlane(plane, line) * lineToPlane(plane, line)));
        REQUIRE(plane.Distance(otherPlane1) == Approx(planeToPlane(plane, otherPlane1)));
        REQUIRE(plane.SquaredDistance(otherPlane1) == Approx(planeToPlane(plane, otherPlane1) * planeToPlane(plane, otherPlane1)));
        REQUIRE(plane.Distance(otherPlane2) == Approx(planeToPlane(plane, otherPlane2)));
        REQUIRE(plane.SquaredDistance(otherPlane2) == Approx(planeToPlane(plane, otherPlane2) * planeToPlane(plane, otherPlane2)));
    }}