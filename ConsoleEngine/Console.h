#pragma once
#include <string>
#include <cassert>

#ifndef UNICODE
#define UNICODE
#endif
#ifndef _UNICODE
#define _UNICODE
#endif
#include <Windows.h>

#include "Colour.h"
#include "GameInfo.h"

namespace ce
{
	/**
	* The Console class handles all the drawing to the console and rendering.
	* It does not handle any game loops or timing, that has to be taken care of
	* from a different class, this is purely for drawing to the console.
	* 
	* Console is a singleton and as a result only one object will exist for the
	* lifetime of the application. If you need to "create a new instance" of Console
	* you can change the configuration of the existing console via the Create() method
	*/
	class Console
	{
	public:
		Console(const Console&) = delete;
		Console& operator=(const Console&) = delete;
		Console(Console&&) = delete;
		Console& operator=(Console&&) = delete;
		
		/**
		* Creates a new instance of Console to replace the existing instance
		*
		* @param windowTitle Title of the console window
		* @param width Width of the console in columns
		* @param height Height of the console in rows
		*/
		static void create(const std::wstring& windowTitle, int width, int height);

		/**
		* Returns the width of the console
		* 
		* @return width of active Console
		*/
		static int getWidth()
		{
			return getInstance().mWidth_;
		}

		/**
		* Returns the height of the Console
		* 
		* @return height of active Console
		*/
		static int getHeight()
		{
			return getInstance().mHeight_;
		}

		/**
		* Draws a unicode character to the screen buffer at the specified position
		* and with the specified colour
		*
		* @param x The x coordinate (or column) in which to draw
		* @param y The y coordinate (or row) in which to draw
		* @param glyph The unicode character to draw
		* @param colour The foreground colour of the unicode character
		*/
		static void draw(const int x, const int y, const short glyph)
		{
			draw(x, y, glyph, Colour::WHITE);
		}

		static void draw(int x, int y, short glyph, Colour colour);

		/**
		* Draws a line between two points consisting of only the glyph
		* specified and one glyph thick
		* 
		* @param x1 The starting x coordinate (or column) of the line
		* @param y1 The starting y coordinate (or row) of the line
		* @param x2 The ending x coordinate (or column) of the line
		* @param y2 The ending y coordinate (or row) of the line
		* @param glyph The glyph to use
		* @param colour The colour of the line
		*/
		static void drawLine(const int x1, const int y1,
			const int x2, const int y2,
			const short glyph)
		{
			drawLine(x1, y1, x2, y2, glyph, Colour::WHITE);
		}

		static void drawLine(int x1, int y1,
			int x2, int y2, short glyph, Colour colour);

		/**
		* Draws text to the screen buffer at the specified position, with the
		* text going right from the specified position
		* 
		* @param x The x coordinate (or column) where the text starts
		* @param y The y coordinate (or row) where the text states
		* @param text The string that will be drawn
		* @param colour The foreground colour of the whole string
		*/
		static void drawString(const int x, const int y, const std::wstring& text)
		{
			drawString(x, y, text, Colour::WHITE);
		}

		static void drawString(int x, int y, std::wstring text, Colour colour);
		// TODO: Add another signature that supports text justify relative to the x and y

		/**
		* Renders the screen buffer to the console and updates the console window
		* title
		*/
		static void render();

	private:
		Console() :
			mWidth_(120),
			mHeight_(30),
			mWindowTitle_(L"Console Engine"),
			mScreenBuf_(),
			mhConsole_(),
			mhConsoleInput_(),
			mWindowRect_()
		{
		}

		~Console()
		{
			delete[] mScreenBuf_;
		}

		static Console& getInstance() {
			static Console instance;
			return instance;
		}

		short mWidth_;
		short mHeight_;
		std::wstring mWindowTitle_;

		CHAR_INFO* mScreenBuf_;
		HANDLE mhConsole_;
		HANDLE mhConsoleInput_;
		SMALL_RECT mWindowRect_;
	};
}
