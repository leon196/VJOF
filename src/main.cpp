#include "ofMain.h"
#include "ofApp.h"
//.#define TARGET_OPENGLES
//#ifdef TARGET_OPENGLES
// #include "ofGLProgrammableRenderer.h"
//#endif

int main()
{
	ofSetLogLevel(OF_LOG_VERBOSE);
	//#ifdef TARGET_OPENGLES
    // ofSetCurrentRenderer(ofGLProgrammableRenderer::TYPE);
	//#endif
	ofSetupOpenGL(800,800, OF_WINDOW);
	ofRunApp(new ofApp());
}
