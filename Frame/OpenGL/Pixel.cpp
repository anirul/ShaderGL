#include "Pixel.h"
#include <string>
#include <stdexcept>
#include <GL/glew.h>

namespace frame::opengl {

	frame::proto::PixelElementSize PixelElementSize_BYTE()
	{
		frame::proto::PixelElementSize pixel_element_size{};
		pixel_element_size.set_value(frame::proto::PixelElementSize::BYTE);
		return pixel_element_size;
	}

	frame::proto::PixelElementSize PixelElementSize_SHORT()
	{
		frame::proto::PixelElementSize pixel_element_size{};
		pixel_element_size.set_value(frame::proto::PixelElementSize::SHORT);
		return pixel_element_size;
	}

	frame::proto::PixelElementSize PixelElementSize_HALF()
	{
		frame::proto::PixelElementSize pixel_element_size{};
		pixel_element_size.set_value(frame::proto::PixelElementSize::HALF);
		return pixel_element_size;
	}

	frame::proto::PixelElementSize PixelElementSize_FLOAT()
	{
		frame::proto::PixelElementSize pixel_element_size{};
		pixel_element_size.set_value(frame::proto::PixelElementSize::FLOAT);
		return pixel_element_size;
	}

	frame::proto::PixelStructure PixelStructure_GREY()
	{
		frame::proto::PixelStructure pixel_structure{};
		pixel_structure.set_value(frame::proto::PixelStructure::GREY);
		return pixel_structure;
	}

	frame::proto::PixelStructure PixelStructure_GREY_ALPHA()
	{
		frame::proto::PixelStructure pixel_structure{};
		pixel_structure.set_value(frame::proto::PixelStructure::GREY_ALPHA);
		return pixel_structure;
	}

	frame::proto::PixelStructure PixelStructure_RGB()
	{
		frame::proto::PixelStructure pixel_structure{};
		pixel_structure.set_value(frame::proto::PixelStructure::RGB);
		return pixel_structure;
	}

	frame::proto::PixelStructure PixelStructure_RGB_ALPHA()
	{
		frame::proto::PixelStructure pixel_structure{};
		pixel_structure.set_value(frame::proto::PixelStructure::RGB_ALPHA);
		return pixel_structure;
	}

	bool operator==(
		const frame::proto::PixelStructure& l, 
		const frame::proto::PixelStructure& r)
	{
		return l.value() == r.value();
	}

	bool operator==(
		const frame::proto::PixelElementSize& l, 
		const frame::proto::PixelElementSize& r)
	{
		return l.value() == r.value();
	}

	int ConvertToGLType(
		const frame::proto::PixelElementSize& pixel_element_size)
	{
		switch (pixel_element_size.value())
		{
		case frame::proto::PixelElementSize::BYTE:
			return GL_UNSIGNED_BYTE;
		case frame::proto::PixelElementSize::SHORT:
			return GL_UNSIGNED_SHORT;
		case frame::proto::PixelElementSize::HALF:
			return GL_FLOAT; // Not half float.
		case frame::proto::PixelElementSize::FLOAT:
			return GL_FLOAT;
		}
		throw
			std::runtime_error(
				"unknown element size : " +
				std::to_string(static_cast<int>(pixel_element_size.value())));
	}

	int ConvertToGLType(
		const frame::proto::PixelStructure& pixel_structure)
	{
		switch (pixel_structure.value())
		{
		case frame::proto::PixelStructure::GREY:
			return GL_RED;
		case frame::proto::PixelStructure::GREY_ALPHA:
			return GL_RG;
		case frame::proto::PixelStructure::RGB:
			return GL_RGB;
		case frame::proto::PixelStructure::RGB_ALPHA:
			return GL_RGBA;
		}
		throw
			std::runtime_error(
				"unknown structure : " +
				std::to_string(static_cast<int>(pixel_structure.value())));
	}

	int ConvertToGLType(
		const frame::proto::PixelElementSize& pixel_element_size,
		const frame::proto::PixelStructure& pixel_structure)
	{
		switch (pixel_element_size.value())
		{
		case frame::proto::PixelElementSize::BYTE:
			switch (pixel_structure.value())
			{
			case frame::proto::PixelStructure::GREY:
				return GL_R8;
			case frame::proto::PixelStructure::GREY_ALPHA:
				return GL_RG8;
			case frame::proto::PixelStructure::RGB:
				return GL_RGB8;
			case frame::proto::PixelStructure::RGB_ALPHA:
				return GL_RGBA8;
			}
		case frame::proto::PixelElementSize::SHORT:
			switch (pixel_structure.value())
			{
			case frame::proto::PixelStructure::GREY:
				return GL_R16;
			case frame::proto::PixelStructure::GREY_ALPHA:
				return GL_RG16;
			case frame::proto::PixelStructure::RGB:
				return GL_RGB16;
			case frame::proto::PixelStructure::RGB_ALPHA:
				return GL_RGBA16;
			}
		case frame::proto::PixelElementSize::HALF:
			switch (pixel_structure.value())
			{
			case frame::proto::PixelStructure::GREY:
				return GL_R16F;
			case frame::proto::PixelStructure::GREY_ALPHA:
				return GL_RG16F;
			case frame::proto::PixelStructure::RGB:
				return GL_RGB16F;
			case frame::proto::PixelStructure::RGB_ALPHA:
				return GL_RGBA16F;
			}
		case frame::proto::PixelElementSize::FLOAT:
			switch (pixel_structure.value())
			{
			case frame::proto::PixelStructure::GREY:
				return GL_R32F;
			case frame::proto::PixelStructure::GREY_ALPHA:
				return GL_RG32F;
			case frame::proto::PixelStructure::RGB:
				return GL_RGB32F;
			case frame::proto::PixelStructure::RGB_ALPHA:
				return GL_RGBA32F;
			}
		}
		throw
			std::runtime_error(
				"unknown structure : " +
				std::to_string(static_cast<int>(pixel_structure.value())) +
				" or element size : " +
				std::to_string(static_cast<int>(pixel_element_size.value())));
	}

} // End namespace frame::opengl.