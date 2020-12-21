#pragma once
#include <iostream>
#include <stdio.h>
#include <assert.h>

#ifndef UNICODE
#define UNICODE
#endif
#ifndef _UNICODE
#define _UNICODE
#endif
#include <Windows.h>
#include <WinUser.h>

#include "Colour.h"

namespace ce {
	/**
	* The Console class handles all the drawing to the console and rendering.
	* It does not handle any game loops or timing, that has to be taken care of
	* from a different class, this is purpely for drawing to the console.
	* 
	* Console is a singleton and as a result only one object will exist for the
	* lifetime of the application. If you need to "create a new instance" of Console
	* you can change the configuration of the existing console via the Create() method
	*/
	class Console
	{
	public:
		Console(Console const&) = delete;
		void operator=(Console const&) = delete;

		/**
		* Creates a new instance of Console to replace the existing instance
		*
		* @param windowTitle Title of the console window
		* @param width Width of the console in columns
		* @param height Height of the console in rows
		*/
		static void Create(std::wstring windowTitle, int width, int height);

		/**
		* Returns a references to active instance of Console
		* 
		* @return active instance of Console
		*/
		static Console& rGetInstance()
		{
			static Console instance;
			return instance;
		}

		/**
		* Returns the instance width of the Console
		* 
		* @return width of active Console
		*/
		const int GetWidth() const {
			return mWidth;
		}

		/**
		* Returns the instance height of the Console
		* 
		* @return height of active Console
		*/
		const int GetHeight() const {
			return mHeight;
		}

		/**
		* Draws a unicode character to the screen buffer at the specified position
		* and with the specified colour
		*
		* @param x The x coordinate (or column) in which to draw
		* @param y The y coordinate (or row) in which to draw
		* @param value The unicode character to draw
		* @param colour The foreground colour of the unicode character
		*/
		void Draw(int x, int y, short value) {
			Draw(x, y, value, Colour::FG_WHITE);
		}
		void Draw(int x, int y, short value, Colour colour);

		/**
		* Draws text to the screen buffer at the specified position, with the
		* text going right from the specified position
		* 
		* @param x The x coordinate (or column) where the text starts
		* @param y The y coordinate (or row) where the text states
		* @param text The string that will be drawn
		* @param colour The foreground colour of the whole string
		*/
		void Draw(int x, int y, std::wstring text) {
			Draw(x, y, text, Colour::FG_WHITE);
		}
		void Draw(int x, int y, std::wstring text, Colour colour);
		// TODO: Add another signature that supports text justify relative to the x and y

		/**
		* Renders the screen buffer to the console and updates the console window title
		*/
		void Render();

	private:
		Console() :
			mWidth(120),
			mHeight(30),
			mWindowTitle(L"Console Engine"),
			mScreenBuf(),
			mhConsole(),
			mhConsoleInput(),
			mWindowRect()
		{}
		~Console() {
			delete[] mScreenBuf;
		}

		short mWidth;
		short mHeight;
		std::wstring mWindowTitle;

		CHAR_INFO* mScreenBuf;
		HANDLE mhConsole;
		HANDLE mhConsoleInput;
		SMALL_RECT mWindowRect;
	};
}
