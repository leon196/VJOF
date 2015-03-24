#include "ShaderPlanet.h"


ShaderPlanet::ShaderPlanet()
{
	LoadImage("images/texture.jpg");
	LoadShader("shaders/planet");
}

ShaderPlanet::~ShaderPlanet()
{
}

void ShaderPlanet::Update(float mouseX, float mouseY)
{
	Shader::Update();
    SetUniform1f("uTime", ofGetElapsedTimef());
    SetUniform1f("uDisplacementHeight", 0.2);
    SetUniform2f("uMouse", mouseX - ofGetWidth()/2, ofGetHeight()/2-mouseY);
}