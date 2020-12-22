#pragma once
#include "Scene.h"

namespace ce {
	class SceneManager
	{
	public:
		SceneManager(SceneManager const&) = delete;
		void operator=(SceneManager const&) = delete;

		static void AddScene(Scene* scene) {
			SceneManager& rSceneManager = rGetInstance();
			rSceneManager.mScenes.push(scene);
		}

		static Scene& TopScene() {
			SceneManager& rSceneManager = rGetInstance();
			return *rSceneManager.mScenes.top();
		}

		static void PopScene() {
			SceneManager& rSceneManager = rGetInstance();
			rSceneManager.mScenes.pop();
		}

		static bool IsEmpty() {
			return rGetInstance().mScenes.empty();
		}

		static void Delete() {
			SceneManager& rSceneManager = rGetInstance();
			for (int i = 0; i < rSceneManager.mScenes.size(); i++) {
				delete rSceneManager.mScenes.top();
				rSceneManager.mScenes.pop();
			}
		}

	private:
		SceneManager() = default;

		static SceneManager& rGetInstance()
		{
			static SceneManager instance;
			return instance;
		}

	private:
		std::stack<Scene*> mScenes;
	};
}
