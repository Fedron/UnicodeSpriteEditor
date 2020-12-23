#include "Button.h"

namespace ce {
	Button::Button(const int x, const int y, const std::wstring& text) :
		Button(x, y, text, Colour::WHITE, Colour::YELLOW)
	{}

	Button::Button(const int x, const int y, const std::wstring& text,
	               const Colour textColour, const Colour textActiveColour) :
		Button(
			x, y, text, textColour, textActiveColour,
			L'\u2592', 1, 1, 1
		)
	{}

	Button::Button(const int x, const int y, const std::wstring& text,
	               const Colour textColour, const Colour textActiveColour,
	               const short borderGlyph, const int borderWidth,
	               const int paddingX, const int paddingY) :
		Button(
			x, y, text, textColour, textActiveColour,
			borderGlyph, borderWidth, paddingX, paddingY,
			Colour::WHITE, Colour::YELLOW
		)
	{}

	Button::Button(const int x, const int y, const std::wstring& text,
	               const Colour textColour, const Colour textActiveColour,
	               const short borderGlyph, const int borderWidth,
	               const int paddingX, const int paddingY,
	               const Colour borderColour, const Colour borderActiveColour) :
		mx_(x), my_(y), mText_(text),
		mTextColour_(textColour), mTextActiveColour_(textActiveColour),
		mBorderGlyph_(borderGlyph), mBorderWidth_(borderWidth),
		mPaddingX_(paddingX), mPaddingY_(paddingY),
		mBorderColour_(borderColour), mBorderActiveColour_(borderActiveColour)
	{
		mIsSelected = false;

		/*
		* TODO: Add another constructor to allow the user to specify the width
		* and height of the button. The text will then centre align to fit the
		* dimensions
		*/
		#pragma warning ( suppress: 4267 26451 )
		mWidth_ = (paddingX * 2) + text.size() + (borderWidth * 2);
		mHeight_ = (paddingY * 2) + (borderWidth * 2) + 1;
	}

	void Button::draw()
	{
		// Draw the borders
		for (int i = 0; i < mBorderWidth_; i++) {
			Console::drawLine( // Top border
				mx_, my_ + i,
				mx_ + mWidth_ - 1, my_ + i,
				mBorderGlyph_, mIsSelected ? mBorderActiveColour_ : mBorderColour_
			);
		}
		
		for (int i = 0; i < mBorderWidth_; i++) {
			Console::drawLine( // Right border
				mx_ + mWidth_ - 1 - i, my_,
				mx_ + mWidth_ - 1 - i, my_ + mHeight_ - 1,
				mBorderGlyph_, mIsSelected ? mBorderActiveColour_ : mBorderColour_
			);
		}

		for (int i = 0; i < mBorderWidth_; i++) {
			Console::drawLine( // Bottom border
				mx_, my_ + mHeight_ - 1 - i,
				mx_ + mWidth_ - 1, my_ + mHeight_ - 1 - i,
				mBorderGlyph_, mIsSelected ? mBorderActiveColour_ : mBorderColour_
			);
		}

		for (int i = 0; i < mBorderWidth_; i++) {
			Console::drawLine( // Left border
				mx_ + i, my_,
				mx_ + i, my_ + mHeight_ - 1,
				mBorderGlyph_, mIsSelected ? mBorderActiveColour_ : mBorderColour_
			);
		}

		// Draw the text
		Console::drawString(
			mx_ + mPaddingX_ + mBorderWidth_, my_ + mPaddingY_ + mBorderWidth_,
			mText_, mIsSelected ? mTextActiveColour_ : mTextColour_
		);
	}
}
