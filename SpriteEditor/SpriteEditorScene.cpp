#include "SpriteEditorScene.h"

void SpriteEditorScene::CheckInputs()
{
	if (ce::Input::GetKeyState(VK_ESCAPE).mPressed) {
		ce::SceneManager::PopScene();
		delete this;
	}
}

void SpriteEditorScene::Update()
{
}

void SpriteEditorScene::Draw()
{
	ce::Console::DrawString(1, 1, L"Sprite Editor");
}
