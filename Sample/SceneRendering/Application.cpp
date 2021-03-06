#include "Application.h"
#include <glm/gtc/matrix_transform.hpp>
#include "Draw.h"
#include "Input.h"

Application::Application(const std::shared_ptr<frame::WindowInterface> window) :
	window_(window) {}

void Application::Startup() 
{
	auto device = window_->GetUniqueDevice();
	// device->Startup();
	throw std::runtime_error("no way to do this yet.");
	// device->LoadSceneFromObjFile("Asset/Model/Scene.obj");
	// device->AddEnvironment("Asset/CubeMap/Shiodome.hdr");
}

void Application::Run()
{
	window_->SetDrawInterface(
		std::make_shared<Draw>(window_->GetUniqueDevice()));
	window_->SetInputInterface(
		std::make_shared<Input>(window_->GetUniqueDevice()));
	window_->Run();
}
