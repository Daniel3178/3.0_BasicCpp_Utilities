#pragma once 
#include <Windows.h>
namespace CommonUtilities
{
	enum class eKeys;
	class InputHandler
	{
	public: 
		InputHandler() : myAbsPoint{0}, myScrollDelta(0), myWparam(0), myLparam(0), myMessage(0), myHwnd(nullptr), myPoint {0}
		{
		}
		bool IsKeyDown(const int aKeyCode) const;
		bool IsKeyDown() const;
		bool IsKeyUp()const;
		bool IsLeftMouseDown() const;
		bool IsLeftMouseUp() const;
		bool IsRightMousDown()const;
		bool IsRightMouseUp()const;
		bool IsMouseMove() const;
		bool IsKeyPressed(const int aKeyCode) const;
		POINT GetMousePosition() const;
		UINT GetMyMessage() const;
		WPARAM GetWparam() const;
		LPARAM GetLparam() const;
		POINT GetMouseAbsPosition() const;
		int GetScrollDelta() const;
		bool UpdateEvents( UINT message, WPARAM wParam, LPARAM lParam, HWND hWnd);
		static const char* ourKeyCodeName[];
		eKeys GetKeysAndPrint(const int aKeyCode);
		void PrintCord(int x, int y);
		HWND Initilize(void* anything);
	private:
		void CaptureAnyInput( UINT& aMessage);
		HWND myHwnd;
		int myScrollDelta;
		UINT myMessage;
		WPARAM myWparam;
		POINT myPoint;
		POINT myAbsPoint;
		LPARAM myLparam;
	};
}