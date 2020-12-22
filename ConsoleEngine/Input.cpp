#include "Input.h"

namespace ce {
	Input::Input() {
		mStdin = GetStdHandle(STD_INPUT_HANDLE);
		SetConsoleMode(mStdin, ENABLE_WINDOW_INPUT);
	}

	void Input::Update() {
		Input& input = rGetInstance();
		ReadConsoleInput(input.mStdin, input.mInBuf, 128, &input.mReadNum);

		//input.oldKeyStates = std::move(input.currentKeyStates);

		// Get all key states and push onto the current key state
		for (int i = 0; i < input.mReadNum; i++) {
			if (input.mInBuf[i].EventType == KEY_EVENT) {
				input.ProcessKeyEvent(input.mInBuf[i].Event.KeyEvent);
			}
		}

		// Process the current and old key states
		for (KeyState keyState : input.currentKeyStates) {
			auto oldKeyState = std::find_if(
				input.currentKeyStates.begin(),
				input.currentKeyStates.end(),
				[keyState](const KeyState& other) -> bool {
					return other.mKeyCode == keyState.mKeyCode;
				}
			);

			if (oldKeyState->mPressed)
				keyState.mPressed = false;
		}
	}

	bool Input::IsPressed(WORD keyCode)
	{
		Input& input = rGetInstance();

		for (KeyState keyState : input.currentKeyStates) {
			if (keyState.mKeyCode == keyCode) {
				OutputDebugString(std::to_wstring(keyState.mKeyCode).c_str());
				return keyState.mPressed;
			}
		}

		return false;
	}

	//bool Input::IsReleased(WORD keyCode)
	//{
	//	Input& input = rGetInstance();

	//	for (auto keyState : input.keyStates) {
	//		if (keyState.mKeyCode == keyCode) {
	//			return keyState.mReleased;
	//		}
	//	}

	//	return false;
	//}

	void Input::ProcessKeyEvent(KEY_EVENT_RECORD record)
	{
		currentKeyStates.push_back(KeyState(
			record.wVirtualKeyCode,
			record.bKeyDown,
			!record.bKeyDown
		));
	}
}