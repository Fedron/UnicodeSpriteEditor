#include "Console.h"

namespace ce {
	void Console::create(const std::wstring& windowTitle,
		const int width, const int height)
	{
		Console& instance = getInstance();

		instance.mWidth_ = width;
		instance.mHeight_ = height;
		instance.mWindowTitle_ = windowTitle;

		// Initialise handles
		instance.mhConsole_ = GetStdHandle(STD_OUTPUT_HANDLE);
		instance.mhConsoleInput_ = GetStdHandle(STD_INPUT_HANDLE);

		// Initialise the window
		instance.mWindowRect_ = { 0, 0, 1, 1 };
		SetConsoleWindowInfo(instance.mhConsole_, TRUE, &instance.mWindowRect_);
		SetConsoleMode(instance.mhConsoleInput_,
			ENABLE_EXTENDED_FLAGS | ~ENABLE_QUICK_EDIT_MODE);

		// Disable console window resizing and maximising
		auto* const hwnd = GetConsoleWindow();
		DWORD console_style = GetWindowLong(hwnd, GWL_STYLE);
		console_style &= ~WS_MAXIMIZEBOX & ~WS_SIZEBOX;
		SetWindowLong(hwnd, GWL_STYLE, console_style);

		// Initialise the screen buffer
		const COORD coord = { instance.mWidth_, instance.mHeight_ };
		SetConsoleScreenBufferSize(instance.mhConsole_, coord);
		SetConsoleActiveScreenBuffer(instance.mhConsole_);

		instance.mWindowRect_ = { 0, 0, instance.mWidth_ - 1, instance.mHeight_ - 1 };
		SetConsoleWindowInfo(instance.mhConsole_, TRUE, &instance.mWindowRect_);

		instance.mScreenBuf_ = new CHAR_INFO[
			static_cast<long long>(instance.mWidth_) * instance.mHeight_
		];
		memset(instance.mScreenBuf_, 0,
			sizeof(CHAR_INFO) * instance.mWidth_ * instance.mHeight_);
	}

	void Console::draw(const int x, const int y,
		const short glyph, Colour colour)
	{
		Console& console = getInstance();
		assert(x >= 0 && x < console.mWidth_ && y >= 0 && y <= console.mHeight_);

		if (x >= 0 && x < console.mWidth_ && y >= 0 && y <= console.mHeight_) {
			console.mScreenBuf_[y * console.mWidth_ + x].
				Char.UnicodeChar = glyph;
			console.mScreenBuf_[y * console.mWidth_ + x].
				Attributes = static_cast<short>(colour);
		}
	}

	void Console::drawLine(int x1, int y1, int x2, int y2,
		const short glyph, const Colour colour)
	{
		if (x2 - x1 == 0) {
			if (y2 < y1) {
				const int temp = y1;
				y1 = y2;
				y2 = temp;
			}

			for (int y = y1; y <= y2; y++) {
				draw(x1, y, glyph, colour);
			}
		}
		else {
			const int gradient = (y2 - y1) / (x2 - x1);

			if (x2 < x1) {
				const int temp = x1;
				x1 = x2;
				x2 = temp;
			}

			for (int x = x1; x <= x2; x++) {
				draw(x, gradient * x + y1, glyph, colour);
			}
		}
	}

	void Console::drawString(const int x, const int y,
		std::wstring text, const Colour colour)
	{
		Console& console = getInstance();
		assert(x >= 0 && x < console.mWidth_ && y >= 0 && y <= console.mHeight_);

		if (x >= 0 && x < console.mWidth_ && y >= 0 && y <= console.mHeight_) {
			for (int i = 0; i < text.size(); i++) {
				draw(x + i, y, text[i], colour);
			}
		}
	}

	void Console::render()
	{
		Console& console = getInstance();

		wchar_t title[256];
		swprintf_s(title, 256,
			L"%s - FPS: %d",
			console.mWindowTitle_.c_str(),
			static_cast<int>(1.0f / GameInfo::getDeltaTime()));
		SetConsoleTitle(title);
		
		WriteConsoleOutput(
			console.mhConsole_, console.mScreenBuf_,
			{ console.mWidth_, console.mHeight_ },
			{ 0, 0 },
			& console.mWindowRect_
		);

		// Clear screen buffer in preparation for the next render
		memset(console.mScreenBuf_, 0, sizeof(CHAR_INFO) * console.mWidth_ * console.mHeight_);
	}
}
