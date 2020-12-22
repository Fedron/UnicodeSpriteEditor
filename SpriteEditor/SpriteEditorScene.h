#pragma once
#include "Scene.h"
#include "SceneManager.h"

class SpriteEditorScene :
    public ce::Scene
{
public:
    void CheckInputs();
    void Update();
    void Draw();
};
