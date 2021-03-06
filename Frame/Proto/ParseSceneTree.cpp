#include "ParseSceneTree.h"
#include "Frame/File/FileSystem.h"
#include "Frame/File/Obj.h"
#include "Frame/Proto/ParseUniform.h"
#include "Frame/NodeCamera.h"
#include "Frame/NodeLight.h"
#include "Frame/NodeMatrix.h"
#include "Frame/NodeStaticMesh.h"
#include "Frame/OpenGL/Buffer.h"
#include "Frame/OpenGL/File/LoadStaticMesh.h"
#include "Frame/OpenGL/StaticMesh.h"

namespace frame::proto {

	namespace {

		std::shared_ptr<NodeMatrix> ParseSceneMatrix(
			const SceneMatrix& proto_scene_matrix)
		{
			auto scene_matrix = std::make_shared<NodeMatrix>(
				ParseUniform(proto_scene_matrix.matrix()));
			scene_matrix->SetName(proto_scene_matrix.name());
			scene_matrix->SetParentName(proto_scene_matrix.parent());
			return scene_matrix;
		}

		std::vector<std::shared_ptr<NodeStaticMesh>> ParseSceneStaticMesh(
			const SceneStaticMesh& proto_scene_static_mesh,
			LevelInterface* level)
		{
			if (proto_scene_static_mesh.file_name().empty())
			{
				if (proto_scene_static_mesh.mesh_enum() == 
					SceneStaticMesh::INVALID)
				{
					throw std::runtime_error(
						"Didn't find any mesh file name or any enum.");
				}
				// In this case there is only one material per mesh.
				EntityId mesh_id = 0;
				switch (proto_scene_static_mesh.mesh_enum())
				{
					case SceneStaticMesh::CUBE:
					{
						mesh_id = level->GetDefaultStaticMeshCubeId();
						break;
					}
					case SceneStaticMesh::QUAD:
					{
						mesh_id = level->GetDefaultStaticMeshQuadId();
						break;
					}
					default:
					{
						throw std::runtime_error(
							fmt::format(
								"unknown mesh enum value: {}", 
								proto_scene_static_mesh.mesh_enum()));
					}
				}
				const EntityId material_id =
					level->GetIdFromName(
						proto_scene_static_mesh.material_name());
				auto func = 
					[level](const std::string& name)->NodeInterface::Ptr 
					{
						if (level) {
							auto id = level->GetIdFromName(name);
							return level->GetSceneNodeMap().at(id);
						}
						return nullptr;
					};
				std::shared_ptr<NodeStaticMesh> ptr = 
					std::make_shared<NodeStaticMesh>(
						func, 
						mesh_id, 
						material_id);
				ptr->SetName(proto_scene_static_mesh.name());
				ptr->SetParentName(proto_scene_static_mesh.parent());
				std::vector<std::shared_ptr<NodeStaticMesh>> vec = { ptr };
				return vec;
			}
			else
			{
				auto vec_mesh = frame::opengl::file::LoadStaticMeshesFromFile(
					level, 
					"Asset/Model/" + proto_scene_static_mesh.file_name(), 
					proto_scene_static_mesh.name());
				int i = 0;
				for (const auto& mesh : vec_mesh)
				{
					auto str = fmt::format(
						"{}.{}", 
						proto_scene_static_mesh.name(), 
						i);
					mesh->SetName(str);
					mesh->SetParentName(proto_scene_static_mesh.parent());
					++i;
				}
				return vec_mesh;
			}
		}

		std::shared_ptr<NodeCamera> ParseSceneCamera(
			const frame::proto::SceneCamera& proto_scene_camera)
		{
			if (proto_scene_camera.fov_degrees() == 0.0)
			{
				throw std::runtime_error(
					"Need field of view degrees in camera.");
			}
			auto scene_camera = std::make_shared<NodeCamera>(
				ParseUniform(proto_scene_camera.position()),
				ParseUniform(proto_scene_camera.target()),
				ParseUniform(proto_scene_camera.up()),
				proto_scene_camera.fov_degrees());
			scene_camera->SetName(proto_scene_camera.name());
			scene_camera->SetParentName(proto_scene_camera.parent());
			return scene_camera;
		}

		std::shared_ptr<NodeLight> ParseSceneLight(
			const frame::proto::SceneLight& proto_scene_light)
		{
			switch (proto_scene_light.light_type())
			{
				case proto::SceneLight::POINT:
				{
					return std::make_shared<frame::NodeLight>(
						NodeLightEnum::POINT, 
						ParseUniform(proto_scene_light.position()),
						ParseUniform(proto_scene_light.color()));
				}
				case proto::SceneLight::DIRECTIONAL:
				{
					return std::make_shared<frame::NodeLight>(
						NodeLightEnum::DIRECTIONAL,
						ParseUniform(proto_scene_light.direction()),
						ParseUniform(proto_scene_light.color()));
				}
				case proto::SceneLight::AMBIENT:
					[[fallthrough]];
				case proto::SceneLight::SPOT:
					[[fallthrough]];
				case proto::SceneLight::INVALID:
					[[fallthrough]];
				default:
					throw std::runtime_error(
						fmt::format(
							"Unknown scene light type {}", 
							proto_scene_light.light_type()));
			}
			return nullptr;
		}

	} // End namespace.

	void ParseSceneTreeFile(
		const SceneTreeFile& proto_scene_tree_file,
		LevelInterface* level)
	{
		level->SetDefaultCameraName(
			proto_scene_tree_file.default_camera_name());
		level->SetDefaultRootSceneNodeName(
			proto_scene_tree_file.default_root_name());
		for (const auto& proto_matrix : proto_scene_tree_file.scene_matrices())
		{
			NodeInterface::Ptr ptr =
				std::dynamic_pointer_cast<NodeInterface>(
					ParseSceneMatrix(proto_matrix));
			level->AddSceneNode(ptr->GetName(), ptr);
		}
		for (const auto& proto_static_mesh :
			proto_scene_tree_file.scene_static_meshes())
		{
			auto vec_ptr = ParseSceneStaticMesh(proto_static_mesh, level);
			for (auto ptr : vec_ptr)
			{	
				level->AddSceneNode(
					ptr->GetName(), 
					std::dynamic_pointer_cast<NodeInterface>(ptr));
			}
		}
		for (const auto& proto_camera : proto_scene_tree_file.scene_cameras())
		{
			NodeInterface::Ptr ptr =
				std::dynamic_pointer_cast<NodeInterface>(
					ParseSceneCamera(proto_camera));
			level->AddSceneNode(ptr->GetName(), ptr);
		}
		for (const auto& proto_light : proto_scene_tree_file.scene_lights())
		{
			NodeInterface::Ptr ptr =
				std::dynamic_pointer_cast<NodeInterface>(
					ParseSceneLight(proto_light));
			level->AddSceneNode(ptr->GetName(), ptr);
		}
	}

} // End namespace frame::proto.
