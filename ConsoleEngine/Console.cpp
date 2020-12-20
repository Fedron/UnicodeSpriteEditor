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

	void Console::Draw(int x, int y, short value, Colour colour)
	{
		assert(x >= 0 && x < mWidth&& y >= 0 && y <= mHeight);

		if (x >= 0 && x < mWidth && y >= 0 && y <= mHeight) {
			mScreenBuf[y * mWidth + x].Char.UnicodeChar = value;
			mScreenBuf[y * mWidth + x].Attributes = static_cast<short>(colour);
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
