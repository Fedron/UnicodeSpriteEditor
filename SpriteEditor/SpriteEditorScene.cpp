#include "SpriteEditorScene.h"

void SpriteEditorScene::CheckInputs()
{
	if (GetAsyncKeyState(VK_ESCAPE)) {
		mrScenes.pop();
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
