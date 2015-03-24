#pragma once

#include "ofMain.h"
#include "Entity.h"

class Surface : public Entity {

	public:
		Surface();
		~Surface();

		void StartCapture();
		void StopCapture();
		void Draw();
		
		float width;
		float height;
		float fboWidth;
		float fboHeight;

	private:
		ofFbo fbo;
		ofShader shader;
};