/* "AMCAXMeshing_API void computeInterSegments()\t after computing labels.\n\t @brief In order to obtain the intersection segments, we need call this\n,\n",
      */
 #include<catch.hpp>
#include<testHelperBase.h>
#define AMCAXMeshing_Enable_EigenTraits
#define AMCAXMeshing_Enable_CommonTraits
#define AMCAXMeshing_Disable_StandardTraits
#include "mesh/TriSoup.hpp"
#include "meshModeling/MeshBoolean.hpp"
#include "mesh/io/OBJReader.hpp"
#include "mesh/io/OBJWriter.hpp"
#include "mesh/io/STLReader.hpp"
#include "mesh/io/STLWriter.hpp"
#ifdef AMCAXMeshing_Enable_CommonTraits
using TriSoupTraits = AMCAX::Meshing::Mesh::TriSoupTraits_Coord;
#endif
using EIAC = AMCAX::Meshing::Geometry::EIAC;
using Points = typename TriSoupTraits::Points;
using Triangles = typename TriSoupTraits::Triangles;
using OBJReader = AMCAX::Meshing::Mesh::OBJReader<TriSoupTraits>;
using OBJWriter = AMCAX::Meshing::Mesh::OBJWriter<TriSoupTraits>;
using STLReader = AMCAX::Meshing::Mesh::STLReader<TriSoupTraits>;
using STLWriter = AMCAX::Meshing::Mesh::STLWriter<TriSoupTraits>;
using IOOptions = AMCAX::Meshing::Mesh::IOOptions;
using MeshBoolean = AMCAX::Meshing::Boolean::MeshBoolean<EIAC, TriSoupTraits>;
template <typename TriIndexT>
struct InterSegments
{
    using ti_t = TriIndexT;
    std::vector<ti_t> vertex_ids;
    bool closed;
};
void read_mesh2(const std::string& filename, Points& points,
    Triangles& triangles, IOOptions& io_options)
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
void write_mesh2(const std::string& filename, const Points& points,
    const Triangles& triangles, IOOptions& io_options)
{
    if (AMCAX::Meshing::ends_with(filename, ".obj"))
    {
        OBJWriter writer;
        writer.m_points = std::move(points);
        writer.m_triangles = std::move(triangles);
        writer.write(filename, io_options, 10);
    }
    else if (AMCAX::Meshing::ends_with(filename, ".stl"))
    {
        STLWriter writer;
        writer.m_points = std::move(points);
        writer.m_triangles = std::move(triangles);
        writer.write(filename, io_options, 10);
    }
};
TEST_CASE("bug2: MeshBoolean_InterSegments ", "[meshModeling][MeshBoolean_InterSegments][bug]")
{
    IOOptions io_options;
    io_options.vertex_has_point = true;
    Points      points1, points2, points3, result_points;
    Triangles   triangles1, triangles2, triangles3, result_triangles;
	SECTION("stl-stl-obj")
    {
        OUTPUT_DIRECTORY(MeshBoolean, InterSegments_stl);
        read_mesh2(INPUT_PATH_PREFIX"./meshModeling_data/MeshBoolean_data/cow1.stl", points1, triangles1, io_options);
        read_mesh2(INPUT_PATH_PREFIX"./meshModeling_data/MeshBoolean_data/bunny1.stl", points2, triangles2, io_options);
        read_mesh2(INPUT_PATH_PREFIX"./meshModeling_data/MeshBoolean_data/bunny1.obj", points3, triangles3, io_options);
        MeshBoolean boolean(true);
        boolean.addTriMeshAsInput(points1, triangles1);
        boolean.addTriMeshAsInput(points2, triangles2);
        boolean.addTriMeshAsInput(points3, triangles3);
        boolean.setTriMeshAsOutput(result_points, result_triangles);
        boolean.computeLabels();
        boolean.computeInterSegments();
        boolean.Subtraction();
        const auto& inter_segs = boolean.getInterSegments();
        for (size_t s_id = 0; s_id < inter_segs.size(); ++s_id)
        {
            std::ofstream ofs(outdir + "stl_" + std::to_string(s_id) + ".obj");
            size_t v_num = inter_segs[s_id].vertex_ids.size();
            ofs << "# v_num: " << v_num << std::endl;
            size_t l_num = inter_segs[s_id].closed ? inter_segs[s_id].vertex_ids.size() : inter_segs[s_id].vertex_ids.size() - 1;
            ofs << "# l_num: " << l_num << std::endl;
            ofs << std::endl;
            for (auto v_id : inter_segs[s_id].vertex_ids)
            {
                ofs << "v " << result_points[v_id].x() << " " << result_points[v_id].y() << " " << result_points[v_id].z() << std::endl;
            }
            ofs << std::endl;
            for (size_t i = 0; i < inter_segs[s_id].vertex_ids.size() - 1; ++i)
            {
                ofs << "l " << i + 1 << " " << i + 2 << std::endl;
            }
            if (inter_segs[s_id].closed)
            {
                ofs << "l " << inter_segs[s_id].vertex_ids.size() << " " << 1 << std::endl;
            }
            ofs.close();
            write_mesh2(outdir + "InterSubtraction.stl", result_points, result_triangles, io_options);
        }
    }}