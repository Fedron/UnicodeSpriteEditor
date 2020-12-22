#include "Button.h"

namespace ce {
	Button::Button(int x, int y, std::wstring text) :
		Button(x, y, text, Colour::WHITE, Colour::YELLOW)
	{}

	Button::Button(int x, int y, std::wstring text,
		Colour textColour, Colour textActiveColour) :
		Button(
			x, y, text, textColour, textActiveColour,
			L'\u2592', 1, 1, 1
		)
	{}

	Button::Button(int x, int y, std::wstring text,
		Colour textColour, Colour textActiveColour,
		short borderGlyph, int borderWidth, int paddingX, int paddingY) :
		Button(
			x, y, text, textColour, textActiveColour,
			borderGlyph, borderWidth, paddingX, paddingY,
			Colour::WHITE, Colour::YELLOW
		)
	{}

	Button::Button(int x, int y, std::wstring text,
		Colour textColour, Colour textActiveColour,
		short borderGlyph, int borderWidth, int paddingX, int paddingY,
		Colour borderColour, Colour borderActiveColour) :
		mx(x), my(y), mText(text),
		mTextColour(textColour), mTextActiveColour(textActiveColour),
		mBorderGlyph(borderGlyph), mBorderWidth(borderWidth),
		mPaddingX(paddingX), mPaddingY(paddingY),
		mBorderColour(borderColour), mBorderActiveColour(borderActiveColour)
	{
		mIsSelected = false;

		/*
		* TODO: Add another constructor to allow the user to specify the width
		* and height of the button. The text will then center align to fit the
		* dimensions
		*/
		#pragma warning ( suppress: 4267 26451 )
		mWidth = (paddingX * 2) + text.size() + (borderWidth * 2);
		mHeight = (paddingY * 2) + (borderWidth * 2) + 1;
	}

	void Button::Draw()
	{
		// Draw the borders
		for (int i = 0; i < mBorderWidth; i++) {
			Console::DrawLine( // Top border
				mx, my + i,
				mx + mWidth - 1, my + i,
				mBorderGlyph, mIsSelected ? mBorderActiveColour : mBorderColour
			);
		}
		
		for (int i = 0; i < mBorderWidth; i++) {
			Console::DrawLine( // Right border
				mx + mWidth - 1 - i, my,
				mx + mWidth - 1 - i, my + mHeight - 1,
				mBorderGlyph, mIsSelected ? mBorderActiveColour : mBorderColour
			);
		}

		for (int i = 0; i < mBorderWidth; i++) {
			Console::DrawLine( // Bottom border
				mx, my + mHeight - 1 - i,
				mx + mWidth - 1, my + mHeight - 1 - i,
				mBorderGlyph, mIsSelected ? mBorderActiveColour : mBorderColour
			);
		}

		for (int i = 0; i < mBorderWidth; i++) {
			Console::DrawLine( // Left border
				mx + i, my,
				mx + i, my + mHeight - 1,
				mBorderGlyph, mIsSelected ? mBorderActiveColour : mBorderColour
			);
		}

		// Draw the text
		Console::DrawString(
			mx + mPaddingX + mBorderWidth, my + mPaddingY + mBorderWidth,
			mText, mIsSelected ? mTextActiveColour : mTextColour
		);
	}
}
