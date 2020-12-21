#pragma once
#include "Console.h"

class Scene
{
public:
	Scene(std::stack<Scene*>& scenes) :
		mrScenes(scenes) {}

public:
	virtual void CheckInputs() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

protected:
	std::stack<Scene*>& mrScenes;
};
