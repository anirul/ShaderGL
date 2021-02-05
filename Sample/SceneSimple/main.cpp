#include <iostream>
#include <vector>
#include <utility>

#if defined(_WIN32) || defined(_WIN64)
#define WINDOWS_LEAN_AND_MEAN
#include <windows.h>
#endif

#include "Frame/Error.h"
#include "Frame/Window.h"
#include "Sample/Common/Application.h"
#include "Sample/SceneSimple/Name.h"


#if defined(_WIN32) || defined(_WIN64)
int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nShowCmd)
#else
int main(int ac, char** av)
#endif
{
	try
	{
		Application app(
			std::make_shared<Name>(),
			frame::CreateSDLOpenGL({ 640, 480 }));
		app.Startup();
		app.Run();
	}
	catch (std::exception ex)
	{
		if (!frame::Error::GetInstance().AlreadyRaized())
		{
#if defined(_WIN32) || defined(_WIN64)
			MessageBox(nullptr, ex.what(), "Exception", MB_ICONEXCLAMATION);
#else
			std::cerr << "Error: " << ex.what() << std::endl;
#endif
		}
		return -2;
	}
	return 0;
}