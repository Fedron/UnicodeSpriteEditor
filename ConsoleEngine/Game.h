#pragma once
#pragma warning( disable : 4244 )
#include <chrono>
#include "Console.h"
#include "Scene.h"

namespace ce {
	/**
	* Responsible for the game loop
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
		~Game() {
			for (int i = 0; i < mScenes.size(); i++) {
				delete mScenes.top();
				mScenes.pop();
			}
		}

		void AddScene(Scene* scene) {
			mScenes.push(scene);
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
				if (mScenes.empty()) {
					mRunning = false;
					break;
				}

				// Calculate delta time
				mCurrentTime = std::chrono::system_clock::now();
				mDeltaTime = (mCurrentTime - mLastTime).count();
				mLastTime = mCurrentTime;

				mScenes.top()->CheckInputs();
				mScenes.top()->Update();
				mScenes.top()->Draw();

				ce::Console::rGetInstance().Render();
			}
		}

		std::stack<Scene*>& rGetScenes() {
			return mScenes;
		}

	private:
		bool mRunning;

		std::chrono::system_clock::time_point mLastTime;
		std::chrono::system_clock::time_point mCurrentTime;
		float mDeltaTime;
		
		std::stack<Scene*> mScenes;
	};
}
