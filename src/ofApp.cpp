#include "ofApp.h"

void ofApp::setup()
{
	ofBackground(34, 34, 34);
	ofSetVerticalSync(false);
	ofEnableAlphaBlending();
}

void ofApp::exit()
{
}

void ofApp::update()
{
    scene.Update(mouseX, mouseY);
}


void ofApp::draw()
{
    /*
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
    */

    scene.Draw();

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

