 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/Classifier2d.hpp>
using namespace AMCAX;
TEST_CASE("case1: Classifier2d ", "[math][Classifier2d][P1]") {
    std::vector<Point2> pts = {
        Point2(0.0, 0.0),
        Point2(4.0, 0.0),
        Point2(4.0, 4.0),
        Point2(0.0, 4.0)
    }; 
    double tol = 0.1;
    Polygon2 poly(pts);
    Classifier2d classifiter(poly, tol);
	SECTION("IsInOutOn") {
        Point2 point(0.0, 0.01);
        CHECK(classifiter.IsInOutOn(point, tol) == 1);
        Point2 point2(4.0, 4.01);
        CHECK(classifiter.IsInOutOn(point2, tol) == -1);
        Point2 point3(1.0, 1.01);
        CHECK(classifiter.IsInOutOn(point3, tol) == 0);
    }}