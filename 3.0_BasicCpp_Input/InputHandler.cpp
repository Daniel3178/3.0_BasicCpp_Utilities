#pragma once
#include "InputHandler.h"
#include <iostream>
#include <Windows.h>
#include <tchar.h>
namespace CommonUtilities
{
	const char* InputHandler::ourKeyCodeName[91] = {
		"undefined       ",
		"Left mouse btn  ",
		"Right mouse btn ",
		"Control-break   ",
		"Middle mouse btn",
		"X1 mouse btn    ",
		"X2 mouse btn    ",
		"Undefined       ",
		"BACKSPACE       ",
		"TAB             ",
		"Reserved        ",
		"Reserved        ",
		"CLEAR           ",
		"ENTER           ",
		"Undefined       ",
		"Undefined       ",
		"SHIFT           ",
		"CTRL            ",
		"ALT             ",
		"PAUSE           ",
		"CAPS LOCK       ",
		"IME Kana mode   ",
		"IME On          ",
		"IME Junja mode  ",
		"IME final mode  ",
		"IME Kanji mode  ",
		"IME Off         ",
		"ESC key         ",
		"IME convert     ",
		"IME nonconvert  ",
		"IME accept      ",
		"IME mode change ",
		"SPACEBAR	     ",
		"PAGE UP key     ",
		"PAGE DOWN       ",
		"END 	         ",
		"HOME 	         ",
		"LEFT ARROW	     ",
		"UP ARROW	     ",
		"RIGHT ARROW     ",
		"DOWN ARROW	     ",
		"SELECT 	     ",
		"PRINT 	         ",
		"EXECUTE 	     ",
		"PRINT SCREEN 	 ",
		"INS 	         ",
		"DEL  	         ",
		"HELP   	     ",
		"0   	         ",
		"1               ",
		"2               ",
		"3               ",
		"4               ",
		"5               ",
		"6               ",
		"7               ",
		"8               ",
		"9               ",
		"undifined       ",
		"undifined       ",
		"undifined       ",
		"undifined       ",
		"undifined       ",
		"undifined       ",
		"undifined       ",
		"A               ",
		"B               ",
		"C               ",
		"D               ",
		"E               ",
		"F               ",
		"G               ",
		"H               ",
		"I               ",
		"J               ",
		"K               ",
		"L               ",
		"M               ",
		"N               ",
		"O               ",
		"P               ",
		"Q               ",
		"R               ",
		"S               ",
		"T               ",
		"U               ",
		"V               ",
		"W               ",
		"X               ",
		"Y               ",
		"Z               ",
	};

	enum class eKeys
	{
		eUNDEFINED_X0,
		eLEFT_MOUSE_BTN,
		eRIGHT_MOUSE_BTN,
		eCONTROL_BREAK,
		eMIDDLE_MOUSE_BTN,
		eX1_MOUSE_BTN,
		eX2_MOUSE_BTN,
		eUNDEFINED_X1,
		eBACKSPACE,
		eTAB,
		eREVERSED_X0,
		eREVERSED_X1,
		eCLEAR,
		eENTER,
		eUNDEFINED_X2,
		eUNDEFINED_X3,
		eSHIFT,
		eCTRL,
		eALT,
		ePAUSE,
		eCAPSLOCK,
		eIME_KANA_MODE,
		eIME_ON,
		eIME_JUNJA_MODE,
		eFINAL_MODE,
		eIME_KANJI_MODE,
		eIME_OFF,
		eESC_KEY,
		eIME_CONVERT,
		eIME_NONCONVERT,
		eIME_ACCEPT,
		eIME_MODE_CHANGE,
		eSPACEBAR,
		ePAGE_UP_KEY,
		ePAGE_DOWN,
		eEND,
		eHOME,
		eLEFT_ARROW,
		eUP_ARROW,
		eRIGHT_ARROW,
		eDOWN_ARROW,
		eSELECT,
		ePRINT,
		eEXECUTE,
		ePRINT_SCREEN,
		eINS,
		eDEL,
		eHELP,
		e0,
		e1,
		e2,
		e3,
		e4,
		e5,
		e6,
		e7,
		e8,
		e9,
		eUNDEFINED_X4,
		eUNDEFINED_X5,
		eUNDEFINED_X6,
		eUNDEFINED_X7,
		eUNDEFINED_X8,
		eUNDEFINED_X9,
		eUNDEFINED_XA,
		eA,
		eB,
		eC,
		eD,
		eE,
		eF,
		eG,
		eH,
		eI,
		eJ,
		eK,
		eL,
		eM,
		eN,
		eO,
		eP,
		eQ,
		eR,
		eS,
		eT,
		eU,
		eV,
		eW,
		eX,
		eY,
		eZ
	};

	eKeys InputHandler::GetKeysAndPrint(const int aKeyCode)
	{
		if(aKeyCode < sizeof(ourKeyCodeName) / sizeof(char*) && aKeyCode != 7 && aKeyCode != 0 && (aKeyCode < 58 || aKeyCode >64))
		{

			std::cout << "The button " << ourKeyCodeName[aKeyCode] << " is";
			myMessage == WM_KEYDOWN ? std::cout << " pressed!\n" : std::cout << " released!\n";
			return static_cast<eKeys>(aKeyCode);
		}
		return static_cast<eKeys>(0);
	}



	bool InputHandler::IsKeyDown()const
	{
		return myMessage == WM_KEYDOWN;
	}

	bool InputHandler::IsKeyUp()const
	{
		return myMessage == WM_KEYUP;
	}

	bool InputHandler::IsLeftMouseDown()const
	{
		return myMessage == WM_LBUTTONDOWN;
	}

	bool InputHandler::IsLeftMouseUp()const
	{
		return myMessage == WM_LBUTTONUP;
	}

	bool InputHandler::IsRightMousDown()const
	{
		return myMessage == WM_RBUTTONDOWN;
	}

	bool InputHandler::IsRightMouseUp()const
	{
		return myMessage == WM_RBUTTONUP;
	}
	bool InputHandler::IsMouseMove()const
	{
		return myMessage == WM_MOUSEMOVE;
	}


	void InputHandler::PrintCord(int x, int y)
	{
		std::cout << "The (x, y) cordinates of the cursor are : (" << x << " ," << y << ")";
	}

	WPARAM InputHandler::GetWparam() const
	{
		return myWparam;
	}
	int InputHandler::GetScrollDelta() const
	{
		return myScrollDelta;
	}
	UINT InputHandler::GetMyMessage() const
	{
		return myMessage;
	}

	LPARAM InputHandler::GetLparam() const
	{
		return myLparam;
	}


	POINT InputHandler::GetMousePosition() const
	{
		return myPoint;
	}

	bool InputHandler::IsKeyDown(const int aKeyCode) const
	{
		return (myMessage == WM_KEYDOWN && static_cast<int>(myWparam) == aKeyCode);
	}

	bool InputHandler::IsKeyPressed(const int aKeyCode) const
	{
		return (myMessage == WM_KEYUP && static_cast<int>(myWparam) == aKeyCode);
	}
	POINT InputHandler::GetMouseAbsPosition()const
	{
		return myAbsPoint;
	}
	bool InputHandler::UpdateEvents(UINT message, WPARAM wParam, LPARAM lParam, HWND hWnd)
	{
		myMessage = message;
		myWparam = wParam;
		myLparam = lParam;
		GetCursorPos(&myPoint);
		GetCursorPos(&myAbsPoint);
		ScreenToClient(hWnd, &myAbsPoint);
		myHwnd = hWnd;
		myScrollDelta = GET_WHEEL_DELTA_WPARAM(wParam);
		return false;
	}

	void InputHandler::CaptureAnyInput(UINT& aMessage)
	{
		switch(myMessage)
		{
		case WM_KEYDOWN:
		{

			std::cout << "\tThe button : ";
			GetKeysAndPrint(static_cast<int>(myWparam));
			std::cout << " is pressed!\n";
			break;

		}
		case WM_KEYUP:
			std::cout << "\tThe button : ";
			GetKeysAndPrint(static_cast<int>(myWparam));
			std::cout << " is released!\n";
			break;
		case WM_MOUSEMOVE:
			PrintCord(static_cast<int>(LOWORD(myLparam)), static_cast<int>(HIWORD(myLparam)));
			std::cout << '\n';
			break;
		case WM_LBUTTONDOWN:
			std::cout << "\tLeft mouse button is pressed!\n";
			break;
		case WM_RBUTTONDOWN:
			std::cout << "\tRight mouse button is pressed!\n";
			break;
		case WM_LBUTTONUP:
			std::cout << "\tLeft mouse button is released!\n";
			break;
		case WM_RBUTTONUP:
			std::cout << "\tRight mouse button is released!\n";
			break;
		case WM_LBUTTONDBLCLK:
			std::cout << "\tLeft mouse button is clicked!\n";
			break;
		case WM_RBUTTONDBLCLK:
			std::cout << "\tRight mouse button is clicked!\n";
			break;
		case WM_MOUSEHWHEEL:
		{
			int scrollDelta = GET_WHEEL_DELTA_WPARAM(myWparam);
			if(scrollDelta > 0)
			{
				std::cout << "\tScrolling up ...\n";
			}
			else if(scrollDelta < 0)
			{
				std::cout << "\tScrolling down ...\n";
			}
			break;
		}
		case WM_MOUSEWHEEL:
		{
			int scrollDelta = GET_WHEEL_DELTA_WPARAM(myWparam);
			if(scrollDelta > 0)
			{
				std::cout << "\tScrolling up ...\n";
			}
			else if(scrollDelta < 0)
			{
				std::cout << "\tScrolling down ...\n";
			}
			break;
		}
		}
	}
}