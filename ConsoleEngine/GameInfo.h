#pragma once

namespace ce {
	class GameInfo
	{
	public:
		GameInfo(const GameInfo&) = delete;
		GameInfo& operator=(const GameInfo&) = delete;
		GameInfo(GameInfo&&) = delete;
		GameInfo& operator=(GameInfo&&) = delete;
		
		/**
		 * Lets the game-loop know to quit once the current frame is finished rendering
		 */
		static void shouldQuit() {
			getInstance().mRunning_ = false;
		}

		/**
		 * @return Returns whether or not the game-loop is running
		 */
		static bool isRunning() {
			return getInstance().mRunning_;
		}

		/**
		 * Updates the value of delta Time
		 *
		 * @param dt The new value of delta Time
		 */
		static void setDeltaTime(const float dt) {
			getInstance().mDeltaTime_ = dt;
		}

		/**
		 * Gets the current delta time
		 *
		 * @return the current value of delta time
		 */
		static float getDeltaTime()
		{
			return getInstance().mDeltaTime_;
		}

	private:
		GameInfo() = default;
		~GameInfo() = default;

		static GameInfo& getInstance() {
			static GameInfo instance;
			return instance;
		}
		
		bool mRunning_ = true;
		float mDeltaTime_ = 0.0f;
	};
}
