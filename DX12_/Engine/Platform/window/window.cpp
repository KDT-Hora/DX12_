#include "window.h"



LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		break;
	}

	return DefWindowProc(hWnd, msg, wp, lp);
}

//	ウィンドウの初期化
void engine::Window::initWindow(const TCHAR* appName)
{
	mHInst = GetModuleHandle(nullptr);
	if (mHInst == nullptr)
	{
		return;
	}

	//	ウィンドウ設定
	WNDCLASSEX wc = {};
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.hIcon = LoadIcon(mHInst, IDI_APPLICATION);
	wc.hCursor = LoadCursor(mHInst, IDC_ARROW);
	wc.hbrBackground = GetSysColorBrush(COLOR_BACKGROUND);
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = appName;
	wc.hIconSm = LoadIcon(mHInst, IDI_APPLICATION);

	RegisterClassEx(&wc);

	//	ウィンドウサイズ設定
	RECT rect = {};
	rect.right = static_cast<LONG>(WINDOW_WIDTH);
	rect.bottom = static_cast<LONG>(WINDOW_HEIGHT);

	//	ウィンドウスタイル設定
	auto style = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU;
	AdjustWindowRect(&rect, style, FALSE);

	//	ウィンドウの生成
	mHWnd = CreateWindowEx(
		0,
		appName,
		appName,
		style,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		rect.right - rect.left,
		rect.bottom - rect.top,
		nullptr,
		nullptr,
		mHInst,
		nullptr
	);

	//	ウィンドウの表示
	ShowWindow(mHWnd, SW_SHOWNORMAL);

	//	ウィンドウにフォーカスする
	SetFocus(mHWnd);

}

void engine::Window::mainLoop()
{
	MSG msg = {};
	while (WM_QUIT != msg.message)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE == TRUE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			//	描画処理を実行する箇所
		}
	}
}

/// <summary>
/// コンストラクタ
/// </summary>
engine::Window::Window()
	:WINDOW_WIDTH(1920),WINDOW_HEIGHT(1080)
	,mHWnd(NULL)
{
}

//	開始メソッド
void engine::Window::Start(const TCHAR* appName)
{
	//	ウィンドウ生成
	initWindow(appName);

	//	描画基盤や3Dモデルの初期化を行う

	//	メイン処理ループ
	mainLoop();

}

/// <summary>
/// ウィドウハンドル取得
/// </summary>
/// <returns></returns>
HWND engine::Window::GetWindow()
{
	return mHWnd;
}

/// <summary>
/// ウィンドウ横幅取得メソッド
/// </summary>
/// <returns></returns>
UINT engine::Window::GetWidth()const
{
	return WINDOW_WIDTH;
}

/// <summary>
/// ウィンドウ立幅取得メソッド
/// </summary>
/// <returns></returns>
UINT engine::Window::GetHeight()const
{
	return WINDOW_HEIGHT;
}
