#include <iostream>
#include "Game.h"
#include "MainMenuScene.h"
#include "SceneManager.h"

int main()
{
    ce::Console::Create(L"Unicode Sprite Editor", 180, 50);
    ce::Game* game = new ce::Game();
    ce::SceneManager::AddScene(new MainMenuScene);

    game->Run();
}
