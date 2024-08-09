/* "AMCAX_API int IsInOutOn(const Point2& p, double tol)\t @return 1: in; 0: on; -1: out\n\t @param tol The tolerance of the point\n\t @param p The test point\n\t @brief Check a point is in or out of the polygon\n,\n",
      */
 #include<catch.hpp>
#include<testHelper.h>
#include <common/PointT.hpp>
#include <math/Classifier2d.hpp>
using namespace AMCAX;
TEST_CASE("case3: Classifier2d ", "[math][Classifier2d][P1]") {
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
	SECTION("IsInOutOn Point normal set") {
        Point2 OutPoint(0.0, 0.0);
        Point2 OnPoint(1.0, 1.0);
        Point2 AnothOnPoint(2.0, 2.0);
        Point2 InPoint(2.0, 1.0);
        CHECK(classifier.IsInOutOn(OutPoint,0.0) == -1);
        CHECK(classifier.IsInOutOn(OnPoint,0.0) != 0);
        CHECK(classifier.IsInOutOn(OnPoint, 1.0) == 0);
        CHECK(classifier.IsInOutOn(AnothOnPoint, 1.0) == 0); 
        CHECK(classifier.IsInOutOn(InPoint,0.0) == 1);
    }}