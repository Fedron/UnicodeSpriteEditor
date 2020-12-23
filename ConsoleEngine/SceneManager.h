#pragma once
#include <stack>
#include "Scene.h"

namespace ce {
	class SceneManager
	{
	public:
		SceneManager(const SceneManager&) = delete;
		SceneManager& operator=(const SceneManager&) = delete;
		SceneManager(SceneManager&&) = delete;
		SceneManager& operator=(SceneManager&&) = delete;

		/**
		 * Adds the specified scene to the scene stack and transitions
		 * to the scene in the next frame
		 *
		 * @param scene The scene to add to the stack
		 */
		static void addScene(Scene* scene) {
			SceneManager& r_scene_manager = getInstance();
			r_scene_manager.mScenes_.push(scene);
		}

		/**
		 * Gets the scene on top of the stack (the currently active
		 * scene that is being updated and rendered)
		 *
		 * @return The currently active scene
		 */
		static Scene& topScene() {
			SceneManager& r_scene_manager = getInstance();
			return *r_scene_manager.mScenes_.top();
		}

		/**
		 * Pops the top scene off the scene stack causing
		 * the transition to the previous scene the next frame
		 */
		static void popScene() {
			SceneManager& r_scene_manager = getInstance();
			r_scene_manager.mScenes_.pop();
		}

		/**
		 * @return Whether or not the scene stack is empty
		 */
		static bool isEmpty() {
			return getInstance().mScenes_.empty();
		}

		/**
		 * Deletes all the scenes in the stack
		 */
		static void Delete() {
			SceneManager& r_scene_manager = getInstance();
			for (int i = 0; i < r_scene_manager.mScenes_.size(); i++) {
				delete r_scene_manager.mScenes_.top();
				r_scene_manager.mScenes_.pop();
			}
		}

	private:
		SceneManager() = default;
		~SceneManager() = default;

		static SceneManager& getInstance()
		{
			static SceneManager instance;
			return instance;
		}

	private:
		std::stack<Scene*> mScenes_;
	};
}
