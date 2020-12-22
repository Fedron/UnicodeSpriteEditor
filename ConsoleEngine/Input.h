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

		/**
		* Gets the state of a given key
		* 
		* @param key The virtual key-code of the key to get state for
		* @return The state of the key (pressed, released, and held states)
		*/
		static const KeyState GetKeyState(int key) {
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
