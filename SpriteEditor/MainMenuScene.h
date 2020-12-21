#pragma once
#include "SpriteEditorScene.h"

class MainMenuScene :
    public Scene
{
public:
    MainMenuScene(std::stack<Scene*>& scenes) :
        Scene(scenes) {}

public:
    void CheckInputs();
    void Update();
    void Draw();
};
