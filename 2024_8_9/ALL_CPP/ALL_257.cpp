/* "[[nodiscard]] AMCAX_API bool Contains(const Point3& point, double tol)\t @return True if the distance between the point and the plane is under the distance tolerance\n\t @param tol The distance tolerance\n\t @param point The point\n\t @brief Determines whether the plane contains a point under a tolerance or not\n,\n",
      */
 #include "catch.hpp"
#include <testHelper.h>
#include <math/Plane.hpp>
using namespace AMCAX;
TEST_CASE("case1: Plane construction and methods", "[math][Plane][p1]") {
	SECTION("Contains methods") {
        std::function<bool(const Plane&, const Point3&)> pointInPlane = [](const Plane& plane, const Point3& point)->bool {
            Point3 planePoint = plane.Location();  
            Vector3 planeVector(planePoint, point);  
            double a, b, c, d;
            plane.Coefficients(a, b, c, d);
            return planeVector.Dot(Vector3(a, b, c)) == 0;
        };
        Plane plane(0., 0., 1., -1.); 
        Point3 point(1., 1., 1.);
        Point3 point2(1., 1., 2.);
        Line3 line(Point3(1., 1., 1.), Direction3(1., 0., 0.));
        Line3 line2(Point3(1., 1., 1.), Direction3(0., 0., 1.));  
        Line3 line3(Point3(1., 1., 0.), Direction3(1., 0., 0.));
        REQUIRE(plane.Contains(point, 1e-6) == pointInPlane(plane, point));
        REQUIRE(plane.Contains(point2, 1e-6) == pointInPlane(plane, point2));
        REQUIRE(plane.Contains(line, 1e-6, 1e-6));
        REQUIRE_FALSE(plane.Contains(line2, 1e-6, 1e-6 * (M_PI / 180)));
        REQUIRE_FALSE(plane.Contains(line3, 1e-6, 1e-6 * (M_PI / 180)));
    }}