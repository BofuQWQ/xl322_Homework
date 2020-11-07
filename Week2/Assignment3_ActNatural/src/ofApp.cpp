#include "ofApp.h"
//---------------------------Ripple-------------------------------
Ripple::Ripple() {
}

void Ripple::setup(float _x, float _y) {
	xpos = _x;
	ypos = _y;
	pct = 1;
	pct -= 0.01;
	ofSetCircleResolution(100);

}


void Ripple::update() {
	noise = ofMap((ofNoise(ofGetElapsedTimef())),0,1,0,255);
	radius += pct;
	if (radius >= 15) {
		transparency -= 1;
	}
	
}

void Ripple::draw() {
	ofPushMatrix();
	ofSetColor(0,transparency);		
	ofNoFill();
	ofDrawCircle(xpos,ypos,radius);
	ofPopMatrix();
	
}




//-------------------------ofApp--------------------------------
//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundColor(255);
	ofSetCurveResolution(100);
	//set the fish
	fish.load("fish.png");
	pct2 = 0.05;
	
	
}

//--------------------------------------------------------------
void ofApp::update(){
	for (int i = 0; i < ripple.size(); i++) {
		ripple[i].update();
	}
	//set the fish
	fishPos = fishPos * (1.0 - pct2) + target * pct2;
	target = ofVec3f(ofGetMouseX(), ofGetMouseY());
	ofVec3f direction = target - fishPos;
	float radians = atan2(direction.y, direction.x);	
	float angle = ofRadToDeg(radians);
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofVec3f initial = ofVec3f(-20,10);
	for (int i = 0; i < ripple.size(); i++) {
		ripple[i].draw();
	}
	ofPushMatrix();
	ofTranslate(fishPos);
	ofRotate(angle);
	ofPushStyle();
	ofSetColor(0, 255);
	fish.draw(initial, 20, 10);
	ofPopStyle();
	ofPopMatrix();
	//text
	ofSetColor(0, 255);
	ofDrawBitmapString("click", 10, 10);
	
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
	Ripple a;
	a.setup(x,y);
	ripple.push_back(a);
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
