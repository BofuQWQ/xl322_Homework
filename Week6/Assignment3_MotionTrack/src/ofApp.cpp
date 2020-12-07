#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(TRUE);
	ofSetFrameRate(60);
	receiver.setup(8338);
	light.setPosition(glm::vec3(ofGetWidth() / 2, ofGetHeight() / 2, -200));
}

//--------------------------------------------------------------
void ofApp::update(){
	//FaceOSC template from https://github.com/CreativeInquiry/FaceOSC-Templates
	while (receiver.hasWaitingMessages()) {
		ofxOscMessage m;
		receiver.getNextMessage(m);
		myface.parseOSC(m);
	}
	m += TWO_PI / 90;
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackgroundGradient(ofColor::blue, ofColor::red);
	light.enable();
	if (myface.found > 0) {
		ofPushMatrix();
		ofTranslate(myface.posePosition);
		ofScale(myface.poseScale, myface.poseScale);
		ofSetColor(255, 100, 100);
		ofDrawBox(glm::vec3(-22, myface.eyeLeft*-8, 10), 30, 15, 5);
		ofDrawBox(glm::vec3(22, myface.eyeLeft*-8, 10), 30, 15, 5);
		ofSetColor(ofColor::white);
		ofDrawBox(glm::vec3(-20-sin(m)*6, myface.eyeLeft*-8, 5), 5, 15, 5);
		ofDrawBox(glm::vec3(20+sin(m)*6, myface.eyeLeft*-8, 5), 5, 15, 5);
		ofSetColor(ofColor::red);
		ofDrawSphere(glm::vec3(-7, myface.eyeLeft*-8 + 7.5,10), 7.5);
		ofDrawSphere(glm::vec3(7, myface.eyeLeft*-8 + 7.5, 10), 7.5);
		ofSetColor(ofColor::black);
		ofDrawBox(glm::vec3(-20, myface.eyebrowLeft * -5,10), 25, 5,5);
		ofDrawBox(glm::vec3( 20, myface.eyebrowRight * -5,10), 25, 5,5);
		ofSetColor(ofColor::red);
		ofDrawBox(glm::vec3(0, 20,30), myface.mouthWidth * 3, myface.mouthHeight * 3,20);
		ofPopMatrix();

	}
	light.disable();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
