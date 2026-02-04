#include <Windows.h>

#include "Engine/window/window.h"

//int WINAPI wWinMain(
//	HINSTANCE hInstance,
//	HINSTANCE hPrevInstance,
//	PWSTR pCmdLine,
//	int nCmdShow) 
//{
//	engine::Window win;
//	win.Start(TEXT("DirectX12"));
//
//
//	return 0;
//}

int wmain(int argc, wchar_t** argv, wchar_t** envp)
{
	engine::Window win;
	win.Start(TEXT("DirectX12"));
	return 0;
}