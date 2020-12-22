#pragma once
#include "SpriteEditorScene.h"

class MainMenuScene :
	public ce::Scene
{
public:
	~MainMenuScene();

public:
    void CheckInputs();
    void Update();
    void Draw();

private:
	int activeButton = 0;
    ce::Button* buttons[3] = {
		new ce::Button(
			(ce::Console::GetWidth() / 2) - 10, 5, L"Create New Sprite",
			ce::Colour::WHITE, ce::Colour::CYAN,
			L'\u2592', 1, 2, 1,
			ce::Colour::WHITE, ce::Colour::CYAN
		),
		new ce::Button(
			(ce::Console::GetWidth() / 2) - 12, 12, L"Load Existing Sprite.",
			ce::Colour::WHITE, ce::Colour::CYAN,
			L'\u2592', 1, 2, 1,
			ce::Colour::WHITE, ce::Colour::CYAN
		),
		new ce::Button(
			(ce::Console::GetWidth() / 2) - 4, 19, L"Quit",
			ce::Colour::WHITE, ce::Colour::RED,
			L'\u2592', 1, 2, 1,
			ce::Colour::WHITE, ce::Colour::RED
		)
    };
};
