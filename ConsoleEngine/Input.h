#pragma once
#include <Windows.h>

namespace ce {
	class Input
	{
	public:
		struct KeyState {
			bool mPressed;
			bool mReleased;
			bool mHeld;
		};

	public:
		Input(Input const&) = delete;
		void operator=(Input const&) = delete;

		/**
		* Updates the states of the all the keys
		* Called by default in the ce::Game::Run()
		*/
		static void Update();

		static KeyState GetKeyState(int key) {
			Input& input = rGetInstance();
			return input.mKeys[key];
		}

	private:
		Input() {
			memset(mOldKeyStates, 0, 256 * sizeof(short));
			memset(mNewKeyStates, 0, 256 * sizeof(short));
			memset(mNewKeyStates, 0, 256 * sizeof(KeyState));
		}

		static Input& rGetInstance()
		{
			static Input instance;
			return instance;
		}

	private:
		short mOldKeyStates[256];
		short mNewKeyStates[256];

		KeyState mKeys[256];
	};
}
