#include "Frame/OpenGL/File/LoadTexture.h"
#include <algorithm>
#include <fstream>
#include <vector>
#include <set>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include "Frame/File/Image.h"
#include "Frame/OpenGL/Texture.h"

namespace frame::opengl::file {

	namespace {

		std::set<std::string> basic_byte_extention = { "jpeg", "jpg" };
		std::set<std::string> basic_rgba_extention = { "png" };
		std::set<std::string> cube_map_half_extention = { "hdr", "dds" };

	}

	std::shared_ptr<frame::TextureInterface> LoadTextureFromFileOpenGL(
		const std::string& file, 
		const proto::PixelElementSize pixel_element_size 
			/*= proto::PixelElementSize_BYTE()*/, 
		const proto::PixelStructure pixel_structure 
			/*= proto::PixelStructure_RGB()*/)
	{
		std::shared_ptr<TextureInterface> texture = nullptr;
		frame::file::Image image(file, pixel_element_size, pixel_structure);
		std::string extention = file.substr(file.find_last_of(".") + 1);
		if (cube_map_half_extention.count(extention))
		{
			texture = std::make_shared<frame::opengl::TextureCubeMap>(
				image.GetSize(),
				image.Data(),
				pixel_element_size,
				pixel_structure);
		}
		else
		{
			texture = std::make_shared<frame::opengl::Texture>(
				image.GetSize(),
				image.Data(),
				pixel_element_size,
				pixel_structure);
		}
		return texture;
	}

	std::shared_ptr<frame::TextureInterface> LoadCubeMapTextureFromFileOpenGL(
		const std::string& file, 
		const proto::PixelElementSize pixel_element_size 
			/*= proto::PixelElementSize_BYTE()*/, 
		const proto::PixelStructure pixel_structure 
			/*= proto::PixelStructure_RGB()*/)
	{
		throw std::runtime_error("Not implemented!");
	}

	std::shared_ptr<frame::TextureInterface> LoadCubeMapTextureFromFilesOpenGL(
		const std::array<std::string, 6> files, 
		const proto::PixelElementSize pixel_element_size 
			/*= proto::PixelElementSize_BYTE()*/, 
		const proto::PixelStructure pixel_structure 
			/*= proto::PixelStructure_RGB()*/)
	{
		throw std::runtime_error("Not implemented!");
	}

} // End namespace frame::file.
