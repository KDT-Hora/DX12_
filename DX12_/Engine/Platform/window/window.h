#pragma once
#include <Windows.h>

namespace engine
{
	class Window
	{
		UINT WINDOW_WIDTH;
		UINT WINDOW_HEIGHT;

		void initWindow(const TCHAR* appName);
		void mainLoop();

		HINSTANCE mHInst;
		HWND mHWnd;


	public:

		/// <summary>
		/// コンストラクタ
		/// </summary>
		Window();

		/// <summary>
		/// 開始メソッド
		/// この中でメインループも回してる
		/// </summary>
		/// <param name="appName">ウィンドウ名</param>
		void Start(const TCHAR* appName);

		/// <summary>
		/// ウィンドウハンドルの取得メソッド
		/// </summary>
		/// <returns></returns>
		HWND GetWindow();

		/// <summary>
		/// ウィンドウ横幅取得メソッド
		/// </summary>
		/// <returns></returns>
		UINT GetWidth()const;

		/// <summary>
		/// ウィンドウ立幅取得メソッド
		/// </summary>
		/// <returns></returns>
		UINT GetHeight()const;
	};



}