/* "AMCAX_API Classifier2d(const std::vector<Point2>& pts, double tolU, double tolV, double uMin, double vMin, double uMax, double vMax)\t @param vMax The upper bound of v\n\t @param uMax The upper bound of u\n\t @param vMin The lower bound of v\n\t @param uMin The lower bound of u\n\t @param tolV The tolerance of v bound\n\t @param tolU The tolerance of u bound\n\t @param pts The points of a 2D closed polygon, the last point does not required to repeat the first point\n\t @details Require uMax > uMin, vMax > vMin, and at least 3 points\n\t @brief Construct from a 2D polygon and uv-bounds\n,\n",
      */
 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/Classifier2d.hpp>
using namespace AMCAX;
TEST_CASE("case1: Classifier2d ", "[math][Classifier2d][P1]") {
    std::vector<Point2> pts = {
        Point2(2.0, 0.0),
        Point2(1.0, 1.0),
        Point2(2.0, 2.0),
        Point2(3.0, 2.0)
    }; 
    double tolU = 0.1;
    double tolV = 0.1;
    double uMin = 0.0;
    double vMin = 0.0;
    double uMax = 2.5;
    double vMax = 1.5;
    Classifier2d classifier(pts, tolU, tolV, uMin, vMin, uMax, vMax);
	SECTION("IsInOut Point normal set") {
        Point2 OutPoint(0.0, 0.0);
        Point2 OnPoint(1.0, 1.0);
        Point2 InPoint(2.0, 1.0);
        CHECK(classifier.IsInOut(OutPoint) == -1);
        CHECK(classifier.IsInOut(OnPoint) == 0);
        CHECK(classifier.IsInOut(InPoint) == 1);
    }}