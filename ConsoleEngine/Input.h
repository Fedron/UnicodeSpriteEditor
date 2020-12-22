#pragma once
#include <vector>
#include <algorithm>
#include <string>
#include <Windows.h>

namespace ce {
	class Input
	{
	public:
		struct KeyState {
			WORD mKeyCode;
			bool mPressed;
			bool mReleased;

			KeyState(WORD keyCode, bool pressed, bool released) : 
				mKeyCode(keyCode), mPressed(pressed), mReleased(released)
			{}
		};

	public:
		Input(Input const&) = delete;
		void operator=(Input const&) = delete;

		/**
		* Updates the states of the all the keys
		* Called by default in the ce::Game::Run()
		*/
		static void Update();

		static bool IsPressed(WORD keyCode);

		//static bool IsReleased(WORD keyCode);

	private:
		Input();

		static Input& rGetInstance()
		{
			static Input instance;
			return instance;
		}
		void ProcessKeyEvent(KEY_EVENT_RECORD record);

	private:
		HANDLE mStdin;
		DWORD mReadNum;
		INPUT_RECORD mInBuf[128];

		std::vector<KeyState> oldKeyStates;
		std::vector<KeyState> currentKeyStates;
	};
}
