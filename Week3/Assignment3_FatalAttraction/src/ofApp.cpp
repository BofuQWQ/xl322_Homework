#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255,167,185);
	num = 0;
	for (int i = 0; i < 5; i++) {
		ofRectangle rect;
		rectangles.push_back(rect);
		rectangles[i].set((ofGetWidth()/(i+1))-80, ofRandom(ofGetHeight()-60), 80, 60);
		
		bool b=false;
		clked.push_back(b);
	}
	Mover m1 = Mover(glm::vec2(20, 20));
	Mover m2 = Mover(glm::vec2(ofGetWidth()-20, 20));
	Mover m3 = Mover(glm::vec2(20, ofGetHeight()-20));
	Mover m4 = Mover(glm::vec2(ofGetWidth() - 20, ofGetHeight() - 20));
	movers.push_back(m1);
	movers.push_back(m2);
	movers.push_back(m3);
	movers.push_back(m4);
}

//--------------------------------------------------------------
void ofApp::update(){
	glm::vec2 mPos = glm::vec2(ofGetMouseX(), ofGetMouseY());
	for (int i = 0; i < movers.size(); i++) {
		glm::vec2 diff = mPos - movers[i].pos;
		float dist = glm::length(diff);
		if (dist != 0 && dist < 600) {
			glm::vec2 attraction = diff / dist;
			movers[i].applyForce(attraction);
		}
		movers[i].update();
		
			
		
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	for (int i = 0; i < movers.size(); i++){
		movers[i].draw();
	}

	for (int i = 0; i < rectangles.size(); i++) {
		ofPushStyle();
		if (clked[i]) {
			ofSetColor(ofColor::white);
			ofDrawRectangle(rectangles[i]);
			//rectangles.erase(rectangles.begin() + i - 1);
			/*for (int m=0; m < count.size(); m++) {
				if (count[m] != i) {
					count.push_back(i);
					num += 1;
				} 
			}		*/
		} else {
			ofSetColor(ofColor(250, 96, 145));
		}
		ofDrawRectangle(rectangles[i]);
		ofPopStyle();
	}

	//if (num == 4) {
		ofPushStyle();
		ofSetColor(255);
		ofDrawBitmapString("Avoid the ball and Click all the rectangles to white", 20, 20);
		ofPopStyle();
	//}
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
	for (int i = 0; i < rectangles.size(); i++) {
		if (rectangles[i].inside(x, y)) {
			clked[i] = true;
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
