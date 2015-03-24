#include "Surface.h"

Surface::Surface()
{
    Translate(ofVec3f(0, 0, -0.5));

    width = 0.7;
    height = 0.5;
    fboWidth = 512;
    fboHeight = 512;

    fbo.allocate(fboWidth, fboHeight, GL_RGBA32F_ARB);
    fbo.begin();
    ofClear(255,255,255, 0);
    fbo.end();

    shader.load("shaders/screen.vert", "shaders/screen.frag");
}
Surface::~Surface()
{
	shader.unload();
}

void Surface::StartCapture()
{
    fbo.begin();
	ofClear(255,255,255,0);
}

void Surface::StopCapture()
{
    fbo.end();
}

void Surface::Draw()
{
    shader.begin();

    shader.setUniformTexture("uTexture0", fbo.getTextureReference(), 1);
    shader.setUniform2f("uFboResolution", fboWidth, fboHeight);

    ofDrawPlane(position.x, position.y, position.z, width, height);

    shader.end();

}