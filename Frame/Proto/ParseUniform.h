#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>
#include "Frame/ProgramInterface.h"
#include "Frame/Proto/Proto.h"
#include "Frame/UniformInterface.h"

namespace frame::proto {

	// From proto to glm.
	
	// First start with simple type.
	template<typename T>
	T ParseUniform(const T& uniform_val)
	{
		return uniform_val;
	}

	// Specialization into glm types.
	glm::vec2 ParseUniform(const UniformVector2& uniform_vec2);
	glm::vec3 ParseUniform(const UniformVector3& uniform_vec3);
	glm::vec4 ParseUniform(const UniformVector4& uniform_vec4);
	glm::mat4 ParseUniform(const UniformMatrix4& uniform_mat4);
	glm::quat ParseUniform(const UniformQuaternion& uniform_quat);

	// Specialization into vector types.
	template<typename T, typename U>
	void ParseUniformVec(
		const std::string& name,
		const U& uniform_vec,
		const ProgramInterface& program_interface)
	{
		std::uint32_t counter = 0;
		for (const T& uniform_val : uniform_vec.values())
		{
			program_interface.Uniform(
				name + '[' + std::to_string(counter++) + ']',
				ParseUniform(uniform_val));
		}
	}

	// Register the uniform in the program.
	void RegisterUniformFromProto(
		const frame::proto::Uniform& uniform, 
		const UniformInterface& uniform_interface,
		const ProgramInterface& program_interface);

	// Register the uniform enum in the program.
	void RegisterUniformEnumFromProto(
		const std::string& name,
		const frame::proto::Uniform::UniformEnum& uniform_enum,
		const UniformInterface& uniform_interface,
		const ProgramInterface& program_interface);

	// Convert frame proto size into pair.
	std::pair<std::uint32_t, std::uint32_t> ParseSizeInt(
		const frame::proto::Size size);

}