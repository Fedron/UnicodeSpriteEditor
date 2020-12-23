#include <iostream>
#include "Game.h"
#include "MainMenuScene.h"
#include "SceneManager.h"

int main()
{
    ce::Console::create(L"Unicode Sprite Editor", 180, 50);
    auto* game = new ce::Game();
    ce::SceneManager::addScene(new MainMenuScene);

    game->run();
}
