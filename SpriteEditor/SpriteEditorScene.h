#pragma once
#include <Scene.h>

class SpriteEditorScene :
    public ce::Scene
{
public:
    SpriteEditorScene(std::stack<Scene*>& scenes) :
        Scene(scenes) {}

public:
    void CheckInputs();
    void Update();
    void Draw();
};
