#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	ofEnableSmoothing();
	//glm::vec2 posi = glm::vec2(200, 0);
	//glm::vec2 velo = glm::vec2(0,0);
	//Particle p = Particle(posi);
	//particles.push_back(p);
	//gravity = glm::vec2(0, 0.05);
}

//--------------------------------------------------------------
void ofApp::update(){
	if (ofRandom(1) < 0.05) {
		Firework f;
		fireworks.push_back(f);
	}
	for (int i = 0; i < fireworks.size(); i++) {
		fireworks[i].update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	for (int i = 0; i < fireworks.size(); i++) {
		fireworks[i].draw();
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

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	//particles.push_back(Particle(glm::vec2(x, y)));
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
