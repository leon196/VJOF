#pragma once

#include "ofMain.h"
#include "Entity.h"

class Camera : public Entity {

	public:
		Camera();
		~Camera();

		void Draw();
		void Begin();
		void End();

		float fieldOfView;
		float nearClip;
		float farClip;

	private:
		ofCamera of_camera;

		void SetupPerspective();
};