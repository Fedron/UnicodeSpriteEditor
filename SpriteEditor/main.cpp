#include <iostream>
#include "Game.h"
#include "MainMenuScene.h"

int main()
{
    ce::Console::Create(L"Unicode Sprite Editor", 200, 50);
    ce::Game* game = new ce::Game();
    game->AddScene(new MainMenuScene(game->rGetScenes()));

    game->Run();
}
