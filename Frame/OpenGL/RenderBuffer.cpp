#include "RenderBuffer.h"
#include <stdexcept>
#include <GL/glew.h>
#include "Pixel.h"

namespace frame::opengl {

	RenderBuffer::RenderBuffer()
	{
		glGenRenderbuffers(1, &render_id_);
		error_.Display(__FILE__, __LINE__ - 1);
	}

	RenderBuffer::~RenderBuffer()
	{
		glDeleteRenderbuffers(1, &render_id_);
	}

	void RenderBuffer::Bind(const unsigned int slot /*= 0*/) const
	{
		assert(slot == 0);
		if (locked_bind_) return;
		glBindRenderbuffer(GL_RENDERBUFFER, render_id_);
		error_.Display(__FILE__, __LINE__ - 1);
	}

	void RenderBuffer::UnBind() const
	{
		if (locked_bind_) return;
		glBindRenderbuffer(GL_RENDERBUFFER, 0);
		error_.Display(__FILE__, __LINE__ - 1);
	}

	void RenderBuffer::CreateStorage(
		const std::pair<std::uint32_t, std::uint32_t> size) const
	{
		Bind();
		glRenderbufferStorage(
			GL_RENDERBUFFER,
			GL_DEPTH_COMPONENT32,
			size.first,
			size.second);
		error_.Display(__FILE__, __LINE__ - 5);
		UnBind();
	}

} // End namespace frame::opengl.
