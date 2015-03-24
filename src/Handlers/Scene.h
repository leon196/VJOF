#pragma once

#include "ofMain.h"
#include "Entity.h"
#include "Camera.h"
#include "Surface.h"
#include "OrbitControl.h"
#include "ShaderPlanet.h"

class Scene : public Entity {

	public:
		Scene();
		~Scene();

		void Draw();
		void Update(float mouseX, float mouseY);

	private:
		Camera mainCamera;
		Surface surface;
		vector<Entity> entities;

		OrbitControl orbitControl;
		ShaderPlanet shaderPlanet;
};