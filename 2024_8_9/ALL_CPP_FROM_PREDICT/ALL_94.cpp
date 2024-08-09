 #include <catch.hpp>
#include <testHelper.h>
#include <common/PointT.hpp>
#include <math/MakePolygon2.hpp>
#include <modeling/MakeEdge.hpp>
#include <modeling/MakePolygon2.hpp>
#include <common/AxisT.hpp>
#include <topology/BRepGlobalProperty.hpp>
#include <topology/TopoFace.hpp>
#include <modeling/MakeFace.hpp>
#include <iostream>
#define ONE_RADIAN (M_PI / 180.)
#define SQUARE(x) ((x) * (x))
TEST_CASE("bug1: MakePolygon2 1 cases", "[math][MakePolygon2][fixbug]")
{
	OUTPUT_DIRECTORY(poly, 2, 0);
	int nVertex = 6;
	Point2 vertexList[nVertex];
	std::cout << "AddPolygon2: " << std::endl;
	SECTION("add 6 vertices")
	{
		MakePolygon2 addPolygon2(nVertex);
		addPolygon2.AddVertex(Point2(0., 0.));
		addPolygon2.AddVertex(Point2(1., 0.));
		addPolygon2.AddVertex(Point2(1., 1.));
		addPolygon2.AddVertex(Point2(0., 1.));
		addPolygon2.AddVertex(Point2(-1., 1.));
		addPolygon2.AddVertex(Point2(-1., 0.));
		addPolygon2.AddVertex(Point2(-1. -1., 0.));
		addPolygon2.AddVertex(Point2(-1., -1.));
		addPolygon2.AddVertex(Point2(0., -1.));
		addPolygon2.AddVertex(Point2(1., -1.));
		addPolygon2.AddVertex(Point2(1., 0.));
		Point2 addVertex = addPolygon2.Value(1);
		CHECK(addVertex.X() == Approx(0.5));
		CHECK(addVertex.Y() == Approx(0.5));
		TopoShape polygon2 = addPolygon2 shape();
		AMCAX::GlobalProperty props;
		double surfaceArea = AMCAX::GlobalProperty::Surface(polygon2);
		CHECK(surfaceArea == Approx(6.));
	}}