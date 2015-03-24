#include "OrbitControl.h"

OrbitControl::OrbitControl()
{
	of_easyCam.setDistance(3.0f);
	of_easyCam.setNearClip(0.01f);
	of_easyCam.setFarClip(500.0f);
	of_easyCam.setPosition(0.4f, 0.2f, 0.8f);
	of_easyCam.lookAt(ofVec3f(0.0f, 0.0f, 0.0f));
}

OrbitControl::~OrbitControl()
{
}

void OrbitControl::Begin()
{
	of_easyCam.begin();
}

void OrbitControl::End()
{
	of_easyCam.end();
}