#include "Camera.h"

Camera::Camera()
{
	fieldOfView = 60;
	nearClip = 0.01;
	farClip = 100;

	SetupPerspective();
}

Camera::~Camera()
{

}

void Camera::Draw()
{
    ofMultMatrix(of_camera.getProjectionMatrix().getInverse());
    
    ofPushStyle();
    ofNoFill();
    ofDrawBox(2.0f);
    ofPopStyle();
    
    of_camera.restoreTransformGL();
}

void Camera::Begin()
{
	of_camera.begin();
}

void Camera::End()
{
	of_camera.end();
}

void Camera::SetupPerspective()
{
	of_camera.setupPerspective(true, fieldOfView, nearClip, farClip);
    of_camera.setPosition(ofVec3f(0, 0, 0));
}