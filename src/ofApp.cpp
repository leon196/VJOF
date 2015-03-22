#include "ofApp.h"

void ofApp::setup()
{
	ofBackground(34, 34, 34);
	ofSetVerticalSync(false);
	ofEnableAlphaBlending();
	ofEnableDepthTest();

	image.loadImage("images/texture.jpg");

	shadertoy = true;
	fboWidth = 512;
	fboHeight = 512;

	fbo.allocate(fboWidth, fboHeight, GL_RGBA32F_ARB);
	fbo.begin();
	ofClear(255,255,255, 0);
    fbo.end();

	shaderPlanet.load("shaders/planet.vert", "shaders/planet.frag");
	shaderSimple.load("shaders/simple.vert", "shaders/simple.frag");
	shaderFbo.load("shaders/fbo.vert", "shaders/fbo.frag");
}

void ofApp::exit()
{
    shaderPlanet.unload();
	shaderSimple.unload();
	shaderFbo.unload();
}

void ofApp::update()
{
    if (shadertoy)
    {
        fbo.begin();
		ofClear(255,255,255,0);
        drawFbo();
        fbo.end();
    }
}

void ofApp::drawFbo()
{
	ofPushMatrix();
	ofTranslate(fboWidth / 2, fboHeight / 2, 0);

    shaderPlanet.begin();
    shaderPlanet.setUniformTexture("uTexture0", image, 1);
    shaderPlanet.setUniform1f("uTime", ofGetElapsedTimef());
    shaderPlanet.setUniform1f("uDisplacementHeight", 0.2);
    shaderPlanet.setUniform2f("uMouse", mouseX - ofGetWidth()/2, ofGetHeight()/2-mouseY);
    shaderPlanet.setUniform2f("uResolution", ofGetWidth(), ofGetHeight());
    shaderPlanet.setUniform2f("uTextureResolution", image.getWidth(), image.getHeight());

    ofDrawPlane(0, 0, fboWidth, fboHeight);

    shaderPlanet.end();

	ofPopMatrix();
}

void ofApp::draw()
{
    if (shadertoy)
    {
        shaderFbo.begin();
        shaderFbo.setUniformTexture("uTexture0", fbo.getTextureReference(), 1);
        shaderFbo.setUniform2f("uResolution", ofGetWidth(), ofGetHeight());
        shaderFbo.setUniform2f("uTextureResolution", image.getWidth(), image.getHeight());
        shaderFbo.setUniform2f("uFboResolution", fboWidth, fboHeight);
        ofDrawPlane(ofGetWidth() / 2, ofGetHeight() / 2, ofGetWidth(), ofGetHeight());
        shaderFbo.end();
    }
    else
    {
        ofPushMatrix();
        ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2, 0);

		shaderSimple.begin();
	    shaderSimple.setUniformTexture("uTexture0", image, 1);
		shaderSimple.setUniform1f("uTime", ofGetElapsedTimef());
		shaderSimple.setUniform1f("uDisplacementHeight", 0.2);
	    shaderSimple.setUniform2f("uTextureResolution", image.getWidth(), image.getHeight());

		ofRotateX(mouseY);
		ofRotateY(mouseX);
		ofSetSphereResolution(200);
	    ofDrawSphere(0, 0, 0, ofGetHeight() * .25);

	    shaderSimple.end();
        ofPopMatrix();
    }

	ofSetColor(225);
	ofDrawBitmapString("fps: " + ofToString((int)ofGetFrameRate()), 10, 20);
}

void ofApp::keyPressed (int key)
{
}

void ofApp::keyReleased(int key)
{
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}

