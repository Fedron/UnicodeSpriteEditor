#pragma once
#pragma warning( disable : 4244 )
#include <chrono>
#include "Console.h"
#include "GameInfo.h"
#include "Input.h"
#include "SceneManager.h"

namespace ce {
	/**
	* Responsible for the game loop
	*/
	class Game
	{
	public:
		Game() {
			mCurrentTime_ = std::chrono::system_clock::now();
			mLastTime_ = mCurrentTime_;
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
		void run() {
			while (GameInfo::isRunning()) {
				if (SceneManager::isEmpty()) {
					GameInfo::shouldQuit();
					break;
				}

				// Calculate delta time
				mCurrentTime_ = std::chrono::system_clock::now();
				std::chrono::duration<float> elapsed_time = mCurrentTime_ - mLastTime_;
				GameInfo::setDeltaTime(elapsed_time.count());
				mLastTime_ = mCurrentTime_;

				Input::update();

				SceneManager::topScene().checkInputs();
				SceneManager::topScene().update();
				SceneManager::topScene().draw();

				ce::Console::render();
			}
		}

	private:
		std::chrono::system_clock::time_point mLastTime_;
		std::chrono::system_clock::time_point mCurrentTime_;
	};
}
