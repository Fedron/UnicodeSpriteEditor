#pragma once

namespace ce {
	class GameInfo
	{
	public:
		GameInfo(GameInfo const&) = delete;
		void operator=(GameInfo const&) = delete;

	public:
		static void ShouldQuit() {
			rGetInstance().mRunning = false;
		}

		static bool IsRunning() {
			return rGetInstance().mRunning;
		}

		static void SetDeltaTime(float dt) {
			rGetInstance().mDeltaTime = dt;
		}

		static const float GetDeltaTime() {
			return rGetInstance().mDeltaTime;
		}

	private:
		GameInfo() = default;

		static GameInfo& rGetInstance() {
			static GameInfo instance;
			return instance;
		}

	private:
		bool mRunning = true;
		float mDeltaTime = 0.0f;
	};
}
