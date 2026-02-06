#pragma once
#include <Windows.h>

namespace engine
{
	class Window
	{
		const UINT WINDOW_WIDTH = 1920;
		const UINT WINDOW_HEIGHT = 1080;

		void initWindow(const TCHAR* appName);
		void mainLoop();


	public:

		/// <summary>
		/// 開始メソッド
		/// この中でメインループも回してる
		/// </summary>
		/// <param name="appName">ウィンドウ名</param>
		void Start(const TCHAR* appName);

	};



}