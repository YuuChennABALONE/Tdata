/* "AMCAXMeshing_API void Union()\t @brief apply (3)UNION and (4)put result to output mesh.\n,\n",
      */
 #include<catch.hpp>
#include<testHelperBase.h>
#define AMCAXMeshing_Enable_CommonTraits
#define AMCAXMeshing_Disable_StandardTraits
#define AMCAXMeshing_Enable_EigenTraits
#include "mesh/io/OBJReader.hpp"
#include "mesh/io/OBJWriter.hpp"
#include "mesh/io/STLReader.hpp"
#include "mesh/io/STLWriter.hpp"
#include "meshModeling/MeshBoolean.hpp"
#include "meshModeling/TriMeshRepair.hpp"
#include "meshModeling/MeshParameterization.hpp"
using EIAC = AMCAX::Meshing::Geometry::EIAC;
using TriSoupTraits = AMCAX::Meshing::Mesh::TriSoupTraits_Coord;
using Points = typename TriSoupTraits::Points;
using Triangles = typename TriSoupTraits::Triangles;
using OBJReader = AMCAX::Meshing::Mesh::OBJReader<TriSoupTraits>;
using OBJWriter = AMCAX::Meshing::Mesh::OBJWriter<TriSoupTraits>;
using STLReader = AMCAX::Meshing::Mesh::STLReader<TriSoupTraits>;
using STLWriter = AMCAX::Meshing::Mesh::STLWriter<TriSoupTraits>;
using IOOptions = AMCAX::Meshing::Mesh::IOOptions;
using MeshBoolean = AMCAX::Meshing::Boolean::MeshBoolean<EIAC, TriSoupTraits>;
void read_mesh11(const std::string& filename, Points& points,Triangles& triangles, IOOptions& io_options)
{
	if (AMCAX::Meshing::ends_with(filename, ".obj"))
	{
		OBJReader reader;
		reader.read(filename, io_options);
		points = std::move(reader.m_points);
		triangles = std::move(reader.m_triangles);
	}
	else if (AMCAX::Meshing::ends_with(filename, ".stl"))
	{
		STLReader reader;
		reader.read(filename, io_options);
		points = std::move(reader.m_points);
		triangles = std::move(reader.m_triangles);
	}
}
void write_mesh11(const std::string& filename, const Points& points,const Triangles& triangles, IOOptions& io_options)
{
	OBJWriter writer;
	writer.m_points = std::move(points);
	writer.m_triangles = std::move(triangles);
	bool bWriteObj = writer.write(filename, io_options, 10);
	CHECK(bWriteObj == true);
};
TEST_CASE("case1: MeshBoolean_MeshBoolean  ", "[meshModeling][MeshBoolean][P1]")
{
	OUTPUT_DIRECTORY(Boolean, Boolean);
	IOOptions io_options;
	io_options.vertex_has_point = true;
	Points    points1, points2, result_points;
	Triangles triangles1, triangles2, result_triangles;
	read_mesh11(INPUT_PATH_PREFIX"./meshModeling_data/MeshBoolean_data/bunny25k.obj", points1, triangles1, io_options);
	read_mesh11(INPUT_PATH_PREFIX"./meshModeling_data/MeshBoolean_data/cow.obj", points2, triangles2, io_options);
	MeshBoolean boolean( true);
	boolean.addTriMeshAsInput(points1, triangles1);
	boolean.addTriMeshAsInput(points2, triangles2);
	boolean.setTriMeshAsOutput(result_points, result_triangles);
	boolean.computeLabels();
	{
		boolean.Union();
		make_file_writable(outdir + "AMCAXMeshing_Union.obj");
		write_mesh11(outdir + "AMCAXMeshing_Union.obj", result_points,
			result_triangles, io_options);
	}
	{
		boolean.Intersection();
		make_file_writable(outdir + "AMCAXMeshing_Intersection.obj");
		write_mesh11(outdir + "AMCAXMeshing_Intersection.obj", result_points,
			result_triangles, io_options);
	}
	{
		boolean.Xor();
		make_file_writable(outdir + "AMCAXMeshing_Xor.obj");
		write_mesh11(outdir + "AMCAXMeshing_Xor.obj", result_points, result_triangles,
			io_options);
	}
	{
		boolean.Subtraction();
		make_file_writable(outdir + "AMCAXMeshing_Subtraction.obj");
		write_mesh11(outdir + "AMCAXMeshing_Subtraction.obj", result_points,
			result_triangles, io_options);
	}
}