#include "Shader.h"


Shader::Shader()
{
	LoadImage("images/texture.jpg");
	LoadShader("shaders/simple");
}

Shader::~Shader()
{
	of_shader.unload();
}

void Shader::LoadImage(string path)
{
	of_image.loadImage(path);
}

void Shader::LoadShader(string path)
{
	of_shader.load(path + ".vert", path + ".frag");
}

void Shader::Begin()
{
	of_shader.begin();
}

void Shader::Update()
{
    SetUniformTexture("uTexture0", of_image.getTextureReference(), 1);
    SetUniform2f("uResolution", ofGetWidth(), ofGetHeight());
    SetUniform2f("uTextureResolution", of_image.getWidth(), of_image.getHeight());
}

void Shader::End()
{
	of_shader.end();
}

void Shader::SetUniform1f(string name, float value)
{
	of_shader.setUniform1f(name, value);
}

void Shader::SetUniform2f(string name, float value1, float value2)
{
	of_shader.setUniform2f(name, value1, value2);
}

void Shader::SetUniformTexture(string name, ofTexture& texture, int location)
{
	of_shader.setUniformTexture(name, texture, location);
}
