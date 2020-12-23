#pragma once
#include "Scene.h"
#include "SceneManager.h"

class SpriteEditorScene :
    public ce::Scene
{
public:
    ~SpriteEditorScene() = default;
	
    void checkInputs() override;
    void update() override;
    void draw() override;
};
