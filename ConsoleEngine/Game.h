#pragma once
#pragma warning( disable : 4244 )
#include <chrono>
#include "Console.h"
#include "SceneManager.h"
#include "GameInfo.h"

namespace ce {
	/**
	* Responsible for the game loop
	*/
	class Game
	{
	public:
		Game() {
			mCurrentTime = std::chrono::system_clock::now();
			mLastTime = mCurrentTime;
		}

		~Game() {
			SceneManager::Delete();
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
			while (GameInfo::IsRunning()) {
				if (SceneManager::IsEmpty()) {
					GameInfo::ShouldQuit();
					break;
				}

				// Calculate delta time
				mCurrentTime = std::chrono::system_clock::now();
				GameInfo::SetDeltaTime((mCurrentTime - mLastTime).count());
				mLastTime = mCurrentTime;

				Input::Update();

				SceneManager::TopScene().CheckInputs();
				SceneManager::TopScene().Update();
				SceneManager::TopScene().Draw();

				ce::Console::Render();
			}
		}

	private:
		std::chrono::system_clock::time_point mLastTime;
		std::chrono::system_clock::time_point mCurrentTime;
	};
}
