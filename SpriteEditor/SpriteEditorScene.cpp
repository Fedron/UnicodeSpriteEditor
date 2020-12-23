#include "SpriteEditorScene.h"

void SpriteEditorScene::checkInputs()
{
	if (ce::Input::getKeyState(VK_ESCAPE).mPressed) {
		ce::SceneManager::popScene();
		delete this;
	}
}

void SpriteEditorScene::update()
{
}

void SpriteEditorScene::draw()
{
	ce::Console::drawString(1, 1, L"Sprite Editor");
}
