#include <iostream>
#include <Windows.h>
#include <tchar.h>
#include "InputHandler.h"
#include <cstdio>

CommonUtilities::InputHandler myInputHandler;


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	myInputHandler.UpdateEvents(message, wParam, lParam, hWnd);
	return DefWindowProc(hWnd, message, wParam, lParam);
}


int main(void)
{

	HINSTANCE hInstance = GetModuleHandle(NULL);
	WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, _T("YourWindowClass"), NULL };
	RegisterClassEx(&wc);
	HWND hWnd = CreateWindow(wc.lpszClassName, _T("Capture Input Window"), WS_OVERLAPPEDWINDOW, 100, 100, 800, 600, NULL, NULL, wc.hInstance, NULL);
	ShowWindow(hWnd, SW_SHOWDEFAULT);
	UpdateWindow(hWnd);
	MSG msg;
	while(GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);

		/*KEYBOARD-TEST*/

		if(myInputHandler.IsKeyDown('A'))
		{
			printf("A is down!\n");
		}

		if(myInputHandler.IsKeyPressed('A'))
		{
			printf("A is Pressed\n");
		}

		if(myInputHandler.IsKeyDown())
		{
			myInputHandler.GetKeysAndPrint(static_cast<int>(myInputHandler.GetWparam()));
		}

		if(myInputHandler.IsKeyUp())
		{
			myInputHandler.GetKeysAndPrint(static_cast<int>(myInputHandler.GetWparam()));
		}

		/*SCROLLER-TEST*/

		if(myInputHandler.GetScrollDelta() > 0)
		{
			printf("Scrolling up ...\n");
		}

		if(myInputHandler.GetScrollDelta() < 0)
		{
			printf("Scrolling down ...\n");
		}


		/*MOUSE-TEST*/

		if(myInputHandler.IsMouseMove())
		{
			printf("(%d, %d) mouse position\n", myInputHandler.GetMouseAbsPosition().x, myInputHandler.GetMouseAbsPosition().y);
		}
		if(myInputHandler.IsRightMousDown())
		{
			printf("Right mouse button is pressed!\n");
		}

		if(myInputHandler.IsLeftMouseDown())
		{
			printf("Right mouse button is pressed!\n");
		}

		if(myInputHandler.IsRightMouseUp())
		{
			printf("Right mouse button is released!\n");
		}
		if(myInputHandler.IsLeftMouseUp())
		{
			printf("Left mouse button is released!\n");
		}
	}
	return 0;
}