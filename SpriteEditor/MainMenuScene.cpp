#include "MainMenuScene.h"

MainMenuScene::MainMenuScene(std::stack<Scene*>& scenes) :
	Scene(scenes)
{}

void MainMenuScene::CheckInputs()
{
	if (ce::Input::GetKeyState(VK_UP).mPressed) {
		activeButton--;
	}
	else if (ce::Input::GetKeyState(VK_DOWN).mPressed) {
		activeButton++;
	}

	// Clamp active button in the range of buttons[] and loop
	if (activeButton > 2)
		activeButton = 0;
	else if (activeButton < 0)
		activeButton = 2;

	// Set selected button
	for (int i = 0; i <= 2; i++) {
		buttons[i]->mIsSelected = i == activeButton;
	}
}

void MainMenuScene::Update()
{
}

void MainMenuScene::Draw()
{
	ce::Console::DrawString(1, 1, L"Unicode Sprite Editor");
	for (auto button : buttons) {
		button->Draw();
	}
}
