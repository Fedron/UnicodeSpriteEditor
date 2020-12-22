#pragma once
#include <functional>
#include "Console.h"

namespace ce {
	class Button
	{
	public:
		/**
		* Draws a button on the console
		* 
		* @param x The x coordinate of the top-left corner of the button
		* @param y The y coordinate of the top-left corner of the button
		* @param text The text of the button
		* @param textColour The colour of the text when the button isn't
		*	selected. (Default = ce::Colour::WHITE)
		* @param textActiveColour the colour of the text when the button
		*	is selected. (Default = ce::Colour::YELLOW)
		* @param borderGlyph The glyph used for the border
		*	(Default = L'\u2592')
		* @param borderWidth The width of the border
		*	(Default = 1)
		* @param paddingX The spacing between the top and bottom borders
		*	and the text (Default = 1)
		* @param paddingY The spacing between the left and right borders
		*	and the text(Default = 1)
		* @param borderColour The colour of the border when the button
		*	isn't selected (Default = ce::Colour::WHITE)
		* @param borderActiveColour The colour of the border when the
		*	button is selcted (Default = ce::Colour::YELLOW)
		*/
		Button(int x, int y, std::wstring text);
		Button(int x, int y, std::wstring text,
			Colour textColour, Colour textActiveColour);
		Button(int x, int y, std::wstring text,
			Colour textColour, Colour textActiveColour,
			short borderGlyph, int borderWidth, int paddingX, int paddingY);
		Button(int x, int y, std::wstring text,
			Colour textColour, Colour textActiveColour,
			short borderGlyph, int borderWidth, int paddingX, int paddingY,
			Colour borderColour, Colour borderActiveColour);

	public:
		void Draw();

	public:
		bool mIsSelected;

	private:
		int mx;
		int my;
		int mWidth;
		int mHeight;

		std::wstring mText;
		Colour mTextColour;
		Colour mTextActiveColour;

		short mBorderGlyph;
		int mBorderWidth;
		int mPaddingX;
		int mPaddingY;
		Colour mBorderColour;
		Colour mBorderActiveColour;
	};
}
