#pragma once
#include "SpriteEditorScene.h"

class MainMenuScene :
    public ce::Scene
{
public:
    MainMenuScene(std::stack<Scene*>& scenes);

public:
    void CheckInputs();
    void Update();
    void Draw();

private:
	int activeButton = 0;
    ce::Button* buttons[3] = {
		new ce::Button(
			5, 3, L"New Sprite",
			ce::Colour::WHITE, ce::Colour::CYAN,
			L'\u2592', 1, 2, 1,
			ce::Colour::WHITE, ce::Colour::CYAN
		),
		new ce::Button(
			5, 10, L"Load Sprite",
			ce::Colour::WHITE, ce::Colour::CYAN,
			L'\u2592', 1, 2, 1,
			ce::Colour::WHITE, ce::Colour::CYAN
		),
		new ce::Button(
			5, 17, L"Quit",
			ce::Colour::WHITE, ce::Colour::RED,
			L'\u2592', 1, 2, 1,
			ce::Colour::WHITE, ce::Colour::RED
		)
    };
};
