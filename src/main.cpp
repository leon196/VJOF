#include "ofMain.h"
#include "ofApp.h"

int main()
{
	ofSetLogLevel(OF_LOG_VERBOSE);
	ofSetupOpenGL(800,800, OF_WINDOW);
	ofRunApp(new ofApp());
}
