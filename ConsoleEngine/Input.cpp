#include "Input.h"

namespace ce {
	void Input::update() {
		Input& input = getInstance();

		for (int i = 0; i < 256; i++)
		{
			input.mNewKeyStates_[i] = GetAsyncKeyState(i);

			input.mKeys_[i].mPressed = false;
			input.mKeys_[i].mReleased = false;

			if (input.mNewKeyStates_[i] != input.mOldKeyStates_[i])
			{
				if (input.mNewKeyStates_[i] & 0x8000)
				{
					input.mKeys_[i].mPressed = !input.mKeys_[i].mHeld;
					input.mKeys_[i].mHeld = true;
				}
				else
				{
					input.mKeys_[i].mReleased = true;
					input.mKeys_[i].mHeld = false;
				}
			}

			input.mOldKeyStates_[i] = input.mNewKeyStates_[i];
		}
	}
}