#include "ofApp.h"
//-------------------Magic Ball----------------------
int pattern=0;
void MagicBall::update() {

	//natural move
	if (v.x >= 0) {
		v -= a;
	}
	pos1 += v;
	pos1 -= g;
	pos2 -= v;
	pos2 -= g;
	//wind
	noi = ofMap(ofNoise(ofGetElapsedTimef()), 0, 1, 0, 5);
	
	ofVec3f wind = ofVec3f(noi, 0);
	
	if (pattern == 1) {
		pos1 += wind;
		pos2 += wind;
	}
	else if (pattern ==2) {
		pos1 -= wind;
		pos2 -= wind;
	}
}

void MagicBall::draw() {
	ofSetColor(0);
	ofDrawEllipse(pos1, 20, 20);
	ofDrawEllipse(pos2, 20, 20);
}
//--------------------------------------------------------------
//--------------------------------ofApp-----------------------------
void ofApp::setup(){
	ofSetBackgroundColor(255);
	MagicBall b;
}

//--------------------------------------------------------------
void ofApp::update(){
	for (int i = 0; i < magicball.size(); i++) {
		magicball[i].update();
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
//draw the platform
	ofSetColor(0);
	ofDrawRectangle(0, ofGetHeight() - 200, ofGetWidth(), 200);
//draw the shooter
	ofDrawEllipse(ofGetWidth() / 4, ofGetHeight() - 270, 30, 30); //head
	ofDrawRectangle(ofGetWidth() / 4 - 5, ofGetHeight() - 265, 10, 50); //body
	ofDrawRectangle(ofGetWidth() / 4 - 5, ofGetHeight() - 215, 3, 20); //legs
	ofDrawRectangle(ofGetWidth() / 4 + 2, ofGetHeight() - 215, 3, 20);
	//arms
	ofPushMatrix();  //left arm
	ofTranslate(ofGetWidth() / 4 - 5, ofGetHeight() - 255);
	ofRotateZDeg(30);
	ofDrawRectangle(0, 0, 3, 30);
	ofPopMatrix();
	ofDrawRectangle(ofGetWidth() / 4 + 5, ofGetHeight() - 255, 30, 3); //right arm
	ofDrawRectangle(ofGetWidth() / 4 + 34, ofGetHeight() - 257, 2, 4); //hand

//draw the shot person
	ofDrawEllipse(ofGetWidth() * 3 / 4 + 40, ofGetHeight() - 270, 30, 30); //head
	ofDrawRectangle(ofGetWidth() * 3 / 4 + 35, ofGetHeight() - 265, 10, 50); //body
	ofDrawRectangle(ofGetWidth() * 3 / 4 + 35, ofGetHeight() - 215, 3, 20); //legs
	ofDrawRectangle(ofGetWidth() * 3 / 4 + 42, ofGetHeight() - 215, 3, 20);
	//arms
	ofDrawRectangle(ofGetWidth()*3 / 4 + 5, ofGetHeight() - 255, 30, 3); //left arm
	ofDrawRectangle(ofGetWidth() *3/ 4 + 4, ofGetHeight() - 257, 2, 4); //hand
	ofPushMatrix();  //right arm
	ofTranslate(ofGetWidth() * 3 / 4 + 42, ofGetHeight() - 255);
	ofRotateZDeg(-30);
	ofDrawRectangle(0, 0, 3, 30);
	ofPopMatrix();

//draw the ball
	for (int i = 0; i < magicball.size(); i++) {
		magicball[i].draw();
	}

//text
	ofDrawBitmapString("Click right to summon the wind", 20, 20);
	if (pattern == 0) {
		ofDrawBitmapString("No wind", 20, 50);
	}
	else if (pattern == 1) {
		ofDrawBitmapString("Wind from Left", 20, 50);
	}
	else {
		ofDrawBitmapString("Wind from right", 20, 50);
	}
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
	if (ofGetMousePressed(OF_MOUSE_BUTTON_LEFT)) {
		MagicBall b;
		magicball.push_back(b);
	}
	if (ofGetMousePressed(OF_MOUSE_BUTTON_RIGHT)) {
		if (pattern == 2) {
			pattern = 0;
		}
		else {
			pattern+=1;
		}
	}
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
