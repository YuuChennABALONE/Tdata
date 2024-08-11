 #include<catch.hpp>
#include<testHelper.h>
#include <modeling/MakeTorus.hpp>
#include <common/CartesianCoordinateSystem.hpp>
#include <topology/TopoBuilder.hpp>
TEST_CASE("bug1: MakeTorus   ", "[modeling][MakeTorus][P1][fixbug]")
{
	TopoShape torus = AMCAX::MakeTorus(3.0, 2.0, 0.0, 2 * M_PI);
	AMCAX::GlobalProperty props;
	AMCAX::OccioTool GetProperty(TopoShape shape, const AMCAX::GlobalProperty& property)
	{
		return std::bind(&AMCAX::GlobalProperty::AddSurfaceProperties, std::placeholders::_1, std::placeholders::_2, property);
	}
	AMCAX::OccioTool occTool;
	TopoShape shape1 = torus;
	TopoShape shape2 = TopoBuilder::Compound();
	shape2.Add(shape1);
	SECTION("SurfaceProperties")
	{
		TopoTool::SurfaceProperties props1;
		TopoTool::LinearProperties props2;
		TopoTool::VolumeProperties props3;
		TopoTool::ShellProperties props4;
		TopoTool::EdgeProperties props5;
		TopoTool::VertexProperties props6;
		TopoTool::TopoProperties props7;
		std::cout << "add surface properties: " << std::endl;
		occtio::GlobalProperty props;
		occtio::OccioTool::AddSurfaceProperties(shape1, props);
		std::cout << props.AddSurfaceProperties << std::endl;
		std::cout << "add linear properties: " << std::endl;
		occtio::OccioTool::AddLinearProperties(shape1, props);
		std::cout << props.AddLinearProperties << std::endl;
		std::cout << "add volume properties: " << std::endl;
		occtio::OccioTool::AddVolumeProperties(shape1, props);
		std::cout << props.AddVolumeProperties << std::endl;
		std::cout << "add shell properties: " << std::endl;
		occtio::OccioTool::AddShellProperties(shape1, props);
		std::cout << props.AddShellProperties << std::endl;
		std::cout << "add edge properties: " << std::endl;
		occtio::OccioTool::AddEdgeProperties(shape1, props);
		std::cout << props.AddEdgeProperties << std::endl;
		std::cout << "add vertex properties: " << std::endl;
		occtio::OccioTool::AddVertexProperties(shape1, props);
		std::cout << props.AddVertexProperties << std::endl;
		std::cout << "add topo properties: " << std::endl;
		occtio::OccioTool::AddTopoProperties(shape1, props);
		std::cout << props.AddTopoProperties << std::endl;
	}
}