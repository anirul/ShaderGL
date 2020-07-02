#pragma once

#include <memory>
#include <map>
#include <array>
#include <functional>
#include <optional>
#include <SDL2/SDL.h>
#include "Program.h"
#include "Texture.h"
#include "../ShaderGLLib/Buffer.h"
#include "../ShaderGLLib/Mesh.h"
#include "../ShaderGLLib/Scene.h"
#include "../ShaderGLLib/Camera.h"
#include "../ShaderGLLib/Light.h"
#include "../ShaderGLLib/Material.h"

namespace sgl {

	// Definition of an effect interface.
	struct EffectInterface
	{
		// You will be able to add stuff in the constructor of the derived
		// class. Some thing like mesh, program, mipmap, textures and also
		// functions.
		// EffectInterface(<here come the stuff>);
		// Startup the Effect this is where the effect is created (this will be
		// called only once at the beginning).
		virtual void Startup(std::pair<std::uint32_t, std::uint32_t> size) = 0;
		// This is the draw interfaces.
		virtual void Draw(const double dt = 0.0) = 0;
		// Free everything.
		virtual void Delete() = 0;
		// Get the name of the effect.
		virtual const std::string GetName() const = 0;
	};

	class Device
	{
	public:
		// This will initialize the GL context and make the GLEW init.
		Device(
			void* gl_context, 
			const std::pair<std::uint32_t, std::uint32_t> size);

	public:
		// Pile up effect to be called before Startup.
		void AddEffect(std::shared_ptr<EffectInterface>& effect);
		// Startup the scene. Throw errors in case there is any, takes fov in 
		// degrees.
		void Startup(const float fov = 65.0f);
		// Draw what is on the scene.
		// Take the total time from the beginning of the program to now as a
		// const double parameter.
		void Draw(const double dt);
		// Draw to the deferred texture set.
		void DrawDeferred(
			const std::vector<std::shared_ptr<Texture>>& out_textures,
			const double dt);
		void DrawView(
			const std::vector<std::shared_ptr<Texture>>& out_textures,
			const double dt);
		// Draw the lighting texture from either the inside deferred textures or
		// from the provided deferred textures.
		void DrawLighting(
			std::shared_ptr<Texture>& out_texture,
			const std::vector<std::shared_ptr<Texture>>& in_textures = {});
		// Create a screen space ambient occlusion from either the texture
		// passed or the one from the physically based rendering path.
		void DrawScreenSpaceAmbientOcclusion(
			std::shared_ptr<Texture>& out_texture,
			const std::vector<std::shared_ptr<Texture>>& in_textures = {});
		// Add Bloom to the provided texture.
		void DrawBloom(
			std::shared_ptr<Texture>& out_texture,
			const std::shared_ptr<Texture>& texture);
		// Add HDR to a texture (with associated gamma and exposure).
		void DrawHighDynamicRange(
			std::shared_ptr<Texture>& out_texture,
			const std::shared_ptr<Texture>& texture,
			const float exposure = 1.0f,
			const float gamma = 2.2f);
		// Draw to multiple textures.
		void DrawMultiTextures(
			const std::vector<std::shared_ptr<Texture>>& out_textures,
			const std::shared_ptr<Program> program = nullptr,
			const double dt = 0.0);
		// Clear the view textures.
		void ClearView();
		// Clear the deferred textures.
		void ClearDeferred();
		void AddEnvironment(const std::string& environment_map);
		// Display a texture to the display.
		void Display(const std::shared_ptr<Texture>& texture);
		// Load scene from an OBJ file.
		void LoadSceneFromObjFile(const std::string& obj_file);
		// Debug access to the internals of device.
		const std::shared_ptr<Texture>& GetDeferredTexture(const int i) const;
		const std::shared_ptr<Texture>& GetViewTexture(const int i) const;
		const std::shared_ptr<Texture>& GetLightingTexture(const int i) const;
		const std::shared_ptr<Texture>& GetNoiseTexture() const;

	public:
		Camera GetCamera() const { return camera_; }
		void SetCamera(const Camera& camera) { camera_ = camera; }
		SceneTree GetSceneTree() const { return scene_tree_; }
		void SetSceneTree(const SceneTree& scene_tree) 
		{ 
			scene_tree_ = scene_tree;
		}
		LightManager GetLightManager() const { return light_manager_; }
		void SetLightManager(const LightManager& light_manager)
		{
			light_manager_ = light_manager;
		}
		const glm::mat4 GetProjection() const { return perspective_; }
		const glm::mat4 GetView() const { return view_; }
		const glm::mat4 GetModel() const { return model_; }
		void* GetDeviceContext() const { return gl_context_; }
		const std::string GetType() const { return "OpenGL"; }

	protected:
		void SetupCamera();

	private:
		std::shared_ptr<Program> pbr_program_ = nullptr;
		std::shared_ptr<Program> lighting_program_ = nullptr;
		std::shared_ptr<Program> ssao_program_ = nullptr;
		std::shared_ptr<Program> view_program_ = nullptr;
		std::shared_ptr<Program> blur_program_ = nullptr;
		std::shared_ptr<Texture> noise_texture_ = nullptr;
		std::vector<glm::vec3> kernel_ssao_vec_ = {};
		std::vector<std::shared_ptr<Texture>> deferred_textures_ = {};
		std::vector<std::shared_ptr<Texture>> lighting_textures_ = {};
		std::vector<std::shared_ptr<Texture>> view_textures_ = {};
		std::shared_ptr<Texture> final_texture_ = nullptr;
		std::shared_ptr<Material> material_ = nullptr;
		std::map<std::string, std::shared_ptr<Material>> materials_ = {};
		std::vector<std::shared_ptr<EffectInterface>> effects_ = {};
		SceneTree scene_tree_ = {};
		LightManager light_manager_ = {};
		// Camera storage.
		Camera camera_ = Camera({ 0.1f, 5.f, -7.f }, { -0.1f, -1.f, 2.f });
		// PVM matrices.
		glm::mat4 perspective_ = glm::mat4(1.0f);
		glm::mat4 view_ = glm::mat4(1.0f);
		glm::mat4 model_ = glm::mat4(1.0f);
		// Field of view (in degrees).
		float fov_ = 65.f;
		// Open GL context.
		void* gl_context_ = nullptr;
		// Constants.
		const std::pair<std::uint32_t, std::uint32_t> size_ = { 0, 0 };
		const PixelElementSize pixel_element_size_ = PixelElementSize::HALF;
		// Error setup.
		const Error& error_ = Error::GetInstance();
	};

} // End namespace sgl.
