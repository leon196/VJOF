#pragma once

#include "ofMain.h"

class Entity {

	public:
		Entity();
		~Entity();

		void Draw();
		void Translate(ofVec3f position);

		uint id;
		string name;
		ofVec3f position;
		ofVec3f rotation;
		ofVec3f scale;
};