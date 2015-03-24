#pragma once

#include "ofMain.h"

class Shader {

	public:
		Shader();
		~Shader();

		void LoadImage(string path);
		void LoadShader(string path);

		void Begin();
		void Update();
		void End();

		void SetUniform1f(string name, float value);
		void SetUniform2f(string name, float value1, float value2);
		void SetUniformTexture(string name, ofTexture& texture, int location);

	private:
		ofImage of_image;
		ofShader of_shader;
};