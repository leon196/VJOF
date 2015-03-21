#include "ofApp.h"

void ofApp::setup()
{
	ofBackground(34, 34, 34);
	ofSetVerticalSync(false);
	ofEnableAlphaBlending();
		
	image.loadImage("images/image.jpg");
	
	// #ifdef TARGET_OPENGLES
	// shader.load("shaders_gles/noise.vert","shaders_gles/noise.frag");
	// #else
	// if(ofGetGLProgrammableRenderer()){
		// shader.load("shaders_gl3/noise.vert", "shaders_gl3/noise.frag");
	// }else{
		shader.load("shaders/noise.vert", "shaders/noise.frag");
	// }
	// #endif
}

void ofApp::update()
{

}

void ofApp::draw()
{
	ofSetColor(225);
	ofDrawBitmapString("coucou", 10, 20);
	
	shader.begin();
    shader.setUniformTexture("uTexture0", image, 1);
	shader.setUniform1f("uTime", ofGetElapsedTimef());
	shader.setUniform2f("uMouse", mouseX - ofGetWidth()/2, ofGetHeight()/2-mouseY);
	shader.setUniform2f("uResolution", ofGetWidth(), ofGetHeight());
    shader.setUniform2f("uTextureResolution", image.getWidth(), image.getHeight());

	ofDrawPlane(ofGetWidth() * .5, ofGetHeight() * .5, ofGetWidth(), ofGetHeight());
	shader.end();
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

