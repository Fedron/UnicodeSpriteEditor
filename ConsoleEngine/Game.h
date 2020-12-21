#pragma once
#pragma warning( disable : 4244 )
#include <chrono>
#include "Console.h"

namespace ce {
	/**
	* Abstract class responsible for the game loop
	*/
	class Game
	{
	public:
		Game() {
			mRunning = true;

			mDeltaTime = 0.0f;
			mCurrentTime = std::chrono::system_clock::now();
			mLastTime = mCurrentTime;
		}

		/**
		* Starts the game loop which is responsible for
		* - Handling timing
		* - Handling quit conditions
		* - Game Update
		* - Game Draw
		* - Console Render
		*/
		void Run() {
			while (mRunning) {
				// Calculate delta time
				mCurrentTime = std::chrono::system_clock::now();
				mDeltaTime = (mCurrentTime - mLastTime).count();
				mLastTime = mCurrentTime;

				// TODO: Check for quit conditions e.g Espace key
				CheckInputs();

				Update();
				Draw();

				ce::Console::rGetInstance().Render();
			}
		}

	protected:
		virtual void CheckInputs() = 0;
		virtual void Update() = 0;
		virtual void Draw() = 0;

	protected:
		bool mRunning;
		float mDeltaTime;

	private:
		std::chrono::system_clock::time_point mLastTime;
		std::chrono::system_clock::time_point mCurrentTime;
	};
}
