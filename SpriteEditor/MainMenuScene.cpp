#include "MainMenuScene.h"

MainMenuScene::~MainMenuScene()
{
	for (int i = 0; i <= 2; i++) {
		delete buttons[i];
	}
}

void MainMenuScene::CheckInputs()
{
	if (ce::Input::GetKeyState(VK_UP).mPressed) {
		activeButton--;
	}
	else if (ce::Input::GetKeyState(VK_DOWN).mPressed) {
		activeButton++;
	}

	// Clamp active button in the range of buttons[] and loop round
	if (activeButton > 2)
		activeButton = 0;
	else if (activeButton < 0)
		activeButton = 2;

	// Set selected button
	for (int i = 0; i <= 2; i++) {
		buttons[i]->mIsSelected = i == activeButton;
	}

	// Button click event
	if (ce::Input::GetKeyState(VK_RETURN).mPressed) {
		switch (activeButton) {
		case 0: // "New Sprite" button
			ce::SceneManager::AddScene(new SpriteEditorScene);
			break;
		case 1: // "Load Sprite" button
			ce::SceneManager::AddScene(new SpriteEditorScene);
			break;
		case 2: // "Quit" button
			ce::GameInfo::ShouldQuit();
			break;
		}
	}
}

void MainMenuScene::Update()
{
}

void MainMenuScene::Draw()
{
	// TODO: Implement ASCII art title
	ce::Console::DrawString(
		(ce::Console::GetWidth() / 2) - 9, 2,
		L"Unicode Sprite Editor");
	for (auto button : buttons) {
		button->Draw();
	}
}
