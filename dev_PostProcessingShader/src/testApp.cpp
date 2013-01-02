#include "testApp.h"

ofShader shader;
ofTexture tex0;
ofImage tex0Source;
float drawWidth;
float drawHeight;
ofFbo fbo;
//--------------------------------------------------------------
void testApp::setup(){
	ofSetLogLevel(OF_LOG_VERBOSE);
	//ofDisableArbTex();
	tex0Source.loadImage("brick.jpg");
	drawWidth = tex0Source.getWidth();
	drawHeight = tex0Source.getHeight();
	
	tex0 = tex0Source.getTextureReference();
	tex0.setTextureWrap(GL_REPEAT, GL_REPEAT);
	shader.load("PostProcessing.vert", "PostProcessing.frag", "");
	fbo.allocate(ofGetWidth(), ofGetHeight());
	fbo.begin();
		ofClear(0, 0, 0, 0);
	fbo.end();
	ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void testApp::update(){
	fbo.begin();
	ofClear(0, 0, 0, 0);
		shader.begin();
			shader.setUniformTexture("tex0", tex0, 1);
			shader.setUniform1f("time", ofGetElapsedTimef());
			shader.setUniform2f("resolution", ofGetWidth(), ofGetHeight());
			ofRect(0, 0, ofGetWidth(), ofGetHeight());
		shader.end();
	fbo.end();
}

//--------------------------------------------------------------
void testApp::draw(){
	fbo.draw(0, 0);
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
	
	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){


}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}


//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
