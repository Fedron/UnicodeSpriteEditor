#include "MainMenuScene.h"

MainMenuScene::~MainMenuScene()
{
	for (int i = 0; i <= 2; i++) {
		delete buttons_[i];
	}
}

void MainMenuScene::checkInputs()
{
	if (ce::Input::getKeyState(VK_UP).mPressed) {
		activeButton_--;
	}
	else if (ce::Input::getKeyState(VK_DOWN).mPressed) {
		activeButton_++;
	}

	// Clamp active button in the range of buttons[] and loop round
	if (activeButton_ > 2)
		activeButton_ = 0;
	else if (activeButton_ < 0)
		activeButton_ = 2;

	// Set selected button
	for (int i = 0; i <= 2; i++) {
		buttons_[i]->mIsSelected = i == activeButton_;
	}

	// Button click event
	if (ce::Input::getKeyState(VK_RETURN).mPressed) {
		switch (activeButton_) {
		case 0: // "New Sprite" button
			ce::SceneManager::addScene(new SpriteEditorScene);
			break;
		case 1: // "Load Sprite" button
			ce::SceneManager::addScene(new SpriteEditorScene);
			break;
		case 2: // "Quit" button
			ce::GameInfo::shouldQuit();
			break;
		}
	}

	// Alternate quit condition
	if (ce::Input::getKeyState(VK_ESCAPE).mPressed)
		ce::GameInfo::shouldQuit();
}

void MainMenuScene::update()
{
}

void MainMenuScene::draw()
{
	// TODO: Implement ASCII art title
	ce::Console::drawString(
		(ce::Console::getWidth() / 2) - 9, 2,
		L"Unicode Sprite Editor");
	for (auto* button : buttons_) {
		button->draw();
	}
}
