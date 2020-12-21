#include "Console.h"

namespace ce {
	void Console::Create(std::wstring windowTitle, int width, int height)
	{
		Console& instance = rGetInstance();

		instance.mWidth = width;
		instance.mHeight = height;
		instance.mWindowTitle = windowTitle;

		// Initialize handles
		instance.mhConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		instance.mhConsoleInput = GetStdHandle(STD_INPUT_HANDLE);

		// Initialize the window
		instance.mWindowRect = { 0, 0, 1, 1 };
		SetConsoleWindowInfo(instance.mhConsole, TRUE, &instance.mWindowRect);
		SetConsoleMode(instance.mhConsoleInput,
			ENABLE_EXTENDED_FLAGS | ~ENABLE_QUICK_EDIT_MODE);

		// Initialize the screen buffer
		COORD coord = { instance.mWidth, instance.mHeight };
		SetConsoleScreenBufferSize(instance.mhConsole, coord);
		SetConsoleActiveScreenBuffer(instance.mhConsole);

		instance.mWindowRect = { 0, 0, instance.mWidth - 1, instance.mHeight - 1 };
		SetConsoleWindowInfo(instance.mhConsole, TRUE, &instance.mWindowRect);

		instance.mScreenBuf = new CHAR_INFO[
			(long long)instance.mWidth * instance.mHeight
		];
		memset(instance.mScreenBuf, 0,
			sizeof(CHAR_INFO) * instance.mWidth * instance.mHeight);
	}

	void Console::Draw(int x, int y, short glyph, Colour colour)
	{
		Console& console = rGetInstance();
		assert(x >= 0 && x < console.mWidth && y >= 0 && y <= console.mHeight);

		if (x >= 0 && x < console.mWidth && y >= 0 && y <= console.mHeight) {
			console.mScreenBuf[y * console.mWidth + x].
				Char.UnicodeChar = glyph;
			console.mScreenBuf[y * console.mWidth + x].
				Attributes = static_cast<short>(colour);
		}
	}

	void Console::DrawLine(int x1, int y1, int x2, int y2, short glyph, Colour colour)
	{
		if (x2 - x1 == 0) {
			if (y2 < y1) {
				int temp = y1;
				y1 = y2;
				y2 = temp;
			}

			for (int y = y1; y <= y2; y++) {
				Draw(x1, y, glyph, colour);
			}
		}
		else {
			int gradient = (y2 - y1) / (x2 - x1);

			if (x2 < x1) {
				int temp = x1;
				x1 = x2;
				x2 = temp;
			}

			for (int x = x1; x <= x2; x++) {
				Draw(x, gradient * x, glyph, colour);
			}
		}
	}

	void Console::DrawString(int x, int y, std::wstring text, Colour colour)
	{
		Console& console = rGetInstance();
		assert(x >= 0 && x < console.mWidth && y >= 0 && y <= console.mHeight);

		if (x >= 0 && x < console.mWidth && y >= 0 && y <= console.mHeight) {
			for (int i = 0; i < text.size(); i++) {
				Draw(x + i, y, text[i], colour);
			}
		}
	}

	void Console::Render()
	{
		SetConsoleTitle(mWindowTitle.c_str());
		WriteConsoleOutput(
			mhConsole, mScreenBuf,
			{ mWidth, mHeight }, { 0, 0 },
			&mWindowRect
		);

		// Clear screen buffer in preperation for the next render
		memset(mScreenBuf, 0, sizeof(CHAR_INFO) * mWidth * mHeight);
	}

}
