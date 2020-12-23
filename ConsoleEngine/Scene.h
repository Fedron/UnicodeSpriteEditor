#pragma once
#include "Button.h"
#include "GameInfo.h"
#include "Input.h"

namespace ce {
	class Scene
	{
	public:
		/**
		 * Called each frame in the game-loop before the update and draw methods.
		 * Meant to be used for getting inputs before carrying out updates on entities
		 */
		virtual void checkInputs() = 0;
		
		/**
		 * Called each frame after checkInputs(), and before any drawing it done.
		 * Meant to be used for updating Scene data
		 */
		virtual void update() = 0;

		/**
		 * Called at the end of each frame.
		 * To be used to draw stuff to the console
		 */
		virtual void draw() = 0;
	};
}
