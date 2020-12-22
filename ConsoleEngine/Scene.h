#pragma once
#include "Button.h"
#include "GameInfo.h"

namespace ce {
	class Scene
	{
	public:
		virtual void CheckInputs() = 0;
		virtual void Update() = 0;
		virtual void Draw() = 0;
	};
}
