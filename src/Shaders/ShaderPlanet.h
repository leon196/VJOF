#pragma once

#include "ofMain.h"
#include "Shader.h"

class ShaderPlanet : public Shader {

	public:
		ShaderPlanet();
		~ShaderPlanet();

		void Update(float mouseX, float mouseY);
};