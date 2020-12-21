#include "MainMenuScene.h"

void MainMenuScene::CheckInputs()
{
	if (GetAsyncKeyState(VK_RETURN))
		mrScenes.push(new SpriteEditorScene(mrScenes));
}

void MainMenuScene::Update()
{
}

void MainMenuScene::Draw()
{
	ce::Console::DrawString(1, 1, L"Main Menu");
}
