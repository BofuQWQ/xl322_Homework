#include "ofApp.h"
//reference of inputting text: https://www.youtube.com/watch?v=6pecyHuP75Q
//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundColor(255, 218,185);
	//font
	pct = 0.05;
	font.load("a.ttf", 32);
	mouth = "Click the Mouse!";
	pos = ofVec3f(ofGetWidth()/2-font.stringWidth(mouth)/2, ofGetHeight()-150);
	//hair
	hair = 0;
	radius = TWO_PI / 90;
}

//--------------------------------------------------------------
void ofApp::update(){
	//font
	target = ofVec3f(ofGetMouseX(), ofGetMouseY());
	pos = pos * (1.0 - pct) + target * pct;
	//hair
	hair += radius;
}

//--------------------------------------------------------------
void ofApp::draw(){
	//glass
	ofSetColor(0);
	ofDrawRectangle(50, 200, 300, 150);
	ofDrawRectangle(450, 200, 300, 150);
	ofDrawRectangle(350, 260, 100, 30);

	int Red = ofMap(ofNoise(ofGetElapsedTimef()), 0, 1, 0, 255);
	int Green = ofMap(ofNoise(ofGetElapsedTimef()), 0, 1, 0, 255);
	int Blue = ofMap(ofNoise(ofGetElapsedTimef()), 0, 1, 0, 255);

	int H = ofMap((int)ofGetMouseX(), 0, 800, 0, 359);
	int S = ofMap((int)ofGetMouseY(), 0, 800, 50, 99);
		//ofMap(ofNoise(ofGetElapsedTimef()), 0, 1, 50, 100);
	int B = 99;
		//ofMap((int)ofGetMouseY(), 0, 800, 0, 100);
		//ofMap(ofNoise(ofGetElapsedTimef()), 0, 1, 50, 100);

	if (colorPattern == 0) {
		ofSetColor(255);
		ofDrawRectangle(70, 220, 260, 110);
		ofDrawRectangle(470, 220, 260, 110);
	}
	else if (colorPattern == 1) {
		ofPushMatrix();
		ofPushStyle();
		ofSetColor(Red, Green, Blue);
		ofDrawRectangle(70, 220, 260, 110);
		ofDrawRectangle(470, 220, 260, 110);
		ofPopStyle();
		ofPopMatrix();

	} 
	else if (colorPattern == 2) {
		ofSetColor(ofColor::fromHsb(H, S, B));
		ofDrawRectangle(70, 220, 260, 110);
		ofDrawRectangle(470, 220, 260, 110);
	}
	else if (colorPattern == 3) {
		ofSetColor(0);
		ofDrawRectangle(70, 220, 260, 110);
		ofDrawRectangle(470, 220, 260, 110);
	}

	
	//hair
	ofSetColor(0);
	for (int i = 0; i < 800; i += 100) {
		if ((i / 100) % 2 == 0) {
			ofDrawTriangle(i, 0, i + 100, 0, i + 50, 100 + sin(hair) * 50);
		}
		else {
			ofDrawTriangle(i, 0, i + 100, 0, i + 50, 100 + cos(hair) * 50);
		}
	}

	//font
	ofSetColor(255, 0, 0);
	font.drawString(mouth, pos.x, pos.y);
	
	//mouth
	
	if (ofGetFrameNum() % 2000 ==0) {
		
		ofSetColor(255, 0, 50);
		ofDrawRectangle(ofGetWidth() / 2 - 75, 600, 150, 100);
	}
	else {
		ofSetColor(0);
		ofDrawRectangle(ofGetWidth() / 2, 600, 150, 10);
		
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
	//colorPattern = (int)ofRandom(1, 3);
	if (colorPattern < 3) {
		colorPattern += 1;
	}
	else {
		colorPattern = 0;
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
