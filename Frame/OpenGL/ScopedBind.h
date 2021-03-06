#pragma once
#include <utility>
#include <string>
#include "Frame/BindInterface.h"
#include "Frame/Error.h"

namespace frame::opengl {

	class ScopedBind
	{
	public:
		ScopedBind(
			const BindInterface& bind_locked,
			const unsigned int slot = 0);
		virtual ~ScopedBind();

	private:
		const Error& error_ = Error::GetInstance();
		const BindInterface& bind_locked_;
	};

} // End namespace frame::opengl.
