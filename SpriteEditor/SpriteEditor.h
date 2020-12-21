#pragma once
#include "Game.h"

class SpriteEditor : public ce::Game
{
protected:
	void CheckInputs() override;
	void Update() override;
	void Draw() override;
};
