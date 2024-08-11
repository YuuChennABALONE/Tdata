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
    double tolU = 0.1;
    double tolV = 0.1;
    double uMin = 0.0;
    double vMin = 0.0;
    double uMax = 4.0;
    double vMax = 4.0;
    Classifier2d classifier(pts, tolU, tolV, uMin, vMin, uMax, vMax);
	SECTION("IsInOut point out") {
        Point2 outPoint(1.0, 1.0);
        CHECK(classifier.IsInOut(outPoint) == -1);
    }}