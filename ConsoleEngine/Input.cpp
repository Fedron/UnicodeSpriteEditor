#include "Input.h"

namespace ce {
	void Input::Update() {
		Input& input = rGetInstance();

		for (int i = 0; i < 256; i++)
		{
			input.mNewKeyStates[i] = GetAsyncKeyState(i);

			input.mKeys[i].mPressed = false;
			input.mKeys[i].mReleased = false;

			if (input.mNewKeyStates[i] != input.mOldKeyStates[i])
			{
				if (input.mNewKeyStates[i] & 0x8000)
				{
					input.mKeys[i].mPressed = !input.mKeys[i].mHeld;
					input.mKeys[i].mHeld = true;
				}
				else
				{
					input.mKeys[i].mReleased = true;
					input.mKeys[i].mHeld = false;
				}
			}

			input.mOldKeyStates[i] = input.mNewKeyStates[i];
		}
	}
}