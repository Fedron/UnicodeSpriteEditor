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
		Input(const Input&) = delete;
		Input& operator=(const Input&) = delete;
		Input(Input&&) = delete;
		Input& operator=(Input&&) = delete;

		/**
		* Updates the states of the all the keys
		* Called by default in the ce::Game::Run()
		*/
		static void update();

		/**
		* Gets the state of a given key
		* 
		* @param key The virtual key-code of the key to get state for
		* @return The state of the key (pressed, released, and held states)
		*/
		static KeyState getKeyState(const int key)
		{
			Input& input = getInstance();
			return input.mKeys_[key];
		}

	private:
		Input() {
			memset(mOldKeyStates_, 0, 256 * sizeof(short));
			memset(mNewKeyStates_, 0, 256 * sizeof(short));
			memset(mNewKeyStates_, 0, 256 * sizeof(KeyState));
		}

		static Input& getInstance()
		{
			static Input instance;
			return instance;
		}

	private:
		short mOldKeyStates_[256];
		short mNewKeyStates_[256];

		KeyState mKeys_[256];
	};
}
