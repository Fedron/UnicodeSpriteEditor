#include "SpriteEditor.h"

void SpriteEditor::CheckInputs()
{
}

void SpriteEditor::Update()
{
}

void SpriteEditor::Draw()
{
	ce::Console::rGetInstance().Draw(
		ce::Console::rGetInstance().GetWidth() / 2 - 7,
		ce::Console::rGetInstance().GetHeight() / 2 - 1,
		L"Hello, world!", ce::Colour::FG_GREEN
	);
}
