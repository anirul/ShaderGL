#pragma once

#include <GL/glew.h>
#include "Frame/Error.h"
#include "Frame/BufferInterface.h"

namespace frame::opengl {

	enum class BufferType : std::uint16_t
	{
		ARRAY_BUFFER				= GL_ARRAY_BUFFER,
		ATOMIC_COUNTER_BUFFER		= GL_ATOMIC_COUNTER_BUFFER,
		COPY_READ_BUFFER			= GL_COPY_READ_BUFFER,
		COPY_WRITE_BUFFER			= GL_COPY_WRITE_BUFFER,
		DISPATCH_INDIRECT_BUFFER	= GL_DISPATCH_INDIRECT_BUFFER,
		DRAW_INDIRECT_BUFFER		= GL_DRAW_INDIRECT_BUFFER,
		ELEMENT_ARRAY_BUFFER		= GL_ELEMENT_ARRAY_BUFFER,
		PIXEL_PACK_BUFFER			= GL_PIXEL_PACK_BUFFER,
		PIXEL_UNPACK_BUFFER			= GL_PIXEL_UNPACK_BUFFER,
		QUERY_BUFFER				= GL_QUERY_BUFFER,
		SHADER_STORAGE_BUFFER		= GL_SHADER_STORAGE_BUFFER,
		TEXTURE_BUFFER				= GL_TEXTURE_BUFFER,
		TRANSFORM_FEEDBACK_BUFFER	= GL_TRANSFORM_FEEDBACK_BUFFER,
		UNIFORM_BUFFER				= GL_UNIFORM_BUFFER,
	};

	enum class BufferUsage : std::uint16_t
	{
		STREAM_DRAW					= GL_STREAM_DRAW, 
		STREAM_READ					= GL_STREAM_READ, 
		STREAM_COPY					= GL_STREAM_COPY, 
		STATIC_DRAW					= GL_STATIC_DRAW, 
		STATIC_READ					= GL_STATIC_READ, 
		STATIC_COPY					= GL_STATIC_COPY, 
		DYNAMIC_DRAW				= GL_DYNAMIC_DRAW, 
		DYNAMIC_READ				= GL_DYNAMIC_READ, 
		DYNAMIC_COPY				= GL_DYNAMIC_COPY,
	};

	class Buffer : public BufferInterface
	{
	public:
		Buffer(
			const BufferType buffer_type = BufferType::ARRAY_BUFFER, 
			const BufferUsage buffer_usage = BufferUsage::STATIC_DRAW);
		virtual ~Buffer();
		void Copy(
			const std::size_t size, 
			const void* data = nullptr) const override;
		void Bind(const unsigned int slot = 0) const override;
		void UnBind() const override;
		void LockedBind() const override { locked_bind_ = true; }
		void UnlockedBind() const override { locked_bind_ = false; }
		unsigned int GetId() const override { return buffer_object_; }
		std::size_t GetSize() const override { return size_; }

	private:
		mutable std::size_t size_ = 0;
		mutable bool locked_bind_ = false;
		const BufferType buffer_type_;
		const BufferUsage buffer_usage_;
		unsigned int buffer_object_ = 0;
		const Error& error_ = Error::GetInstance();
	};

} // End namespace frame::opengl.