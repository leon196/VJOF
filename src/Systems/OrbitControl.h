#pragma once

#include "ofMain.h"

class OrbitControl {

	public:
		OrbitControl();
		~OrbitControl();

		void Begin();
		void End();

	private:
		ofVec2f mouse;
		ofEasyCam of_easyCam;
};