#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//umbrealla
	ofPoint central(0, 500,0);
	ofCircle(central, 100);
	circle.arc(central, 300, 300, 0, 360, 9);

	ofPoint top(0, 500, 100);
	umbrella.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
	umbrella.addVertex(top);
	umbrella.addColor(ofColor::black);
	for (int i = 0; i < circle.size(); i++) {
		umbrella.addVertex(circle[i]);
		umbrella.addColor(ofColor::white);
	}
	umbrella.addIndex(0);
	umbrella.addIndex(1);
	umbrella.addIndex(2);
	
	umbrella.addIndex(0);
	umbrella.addIndex(2);
	umbrella.addIndex(3);

	umbrella.addIndex(0);
	umbrella.addIndex(3);
	umbrella.addIndex(4);

	umbrella.addIndex(0);
	umbrella.addIndex(4);
	umbrella.addIndex(5);
	
	umbrella.addIndex(0);
	umbrella.addIndex(5);
	umbrella.addIndex(6);

	umbrella.addIndex(0);
	umbrella.addIndex(6);
	umbrella.addIndex(7);

	umbrella.addIndex(0);
	umbrella.addIndex(7);
	umbrella.addIndex(8);

	umbrella.addIndex(0);
	umbrella.addIndex(8);
	umbrella.addIndex(9);

	umbrella.addIndex(0);
	umbrella.addIndex(9);
	umbrella.addIndex(1);

	/*umbrella.addIndex(1);
	umbrella.addIndex(2);
	umbrella.addIndex(2);
	umbrella.addIndex(3);
	umbrella.addIndex(3);
	umbrella.addIndex(4);
	umbrella.addIndex(4);
	umbrella.addIndex(5);
	umbrella.addIndex(5);
	umbrella.addIndex(6);
	umbrella.addIndex(6);
	umbrella.addIndex(7);
	umbrella.addIndex(7);
	umbrella.addIndex(8);
	umbrella.addIndex(8);
	umbrella.addIndex(9);
	umbrella.addIndex(9);
	umbrella.addIndex(1);*/

	//snow
	for (int i = 0; i < 400; i++) {
		float xPos = ofRandom(-300,300);
		float yPos = ofRandom(-1000, 0);
		float zPos = ofRandom(-300, 300);
		glm::vec3 Pos(xPos, yPos, zPos);
		glm::vec3 Vel(ofRandom(-0.1, 0.1), ofRandom(0.07, 0.15), 0);
		snow s = snow(Pos, Vel, 3);
		snowfall.push_back(s);
	}
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update(){
	angle += TWO_PI / 90;
	//snow
	for (int i = 0; i < snowfall.size(); i++) {
		snowfall[i].applyforce(gravity);
		snowfall[i].update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackgroundGradient(ofColor::gray, ofColor::black, OF_GRADIENT_CIRCULAR);
	cam.begin();
	//umbrella
	ofPushMatrix();
	ofPushStyle();
	ofTranslate(0, 200, 500);
	ofRotateX(-90);
	//ofTranslate(0, -200, -500);
	
	//umbrella.add
	umbrella.draw();

	//ofSetColor(ofColor::white);
	//circle.draw();
	ofPopStyle();
	ofPopMatrix();
	
	ofPushMatrix();
	ofPushStyle();
	ofTranslate(0, -1100, -500);
	ofRotateX(90);
	umbrella.draw();
	ofPopStyle();
	ofPopMatrix();
	

	//snow
	for (int i = 0; i < snowfall.size(); i++) {
		snowfall[i].draw();
	}
	cam.end();
	ofDisableDepthTest();

	ofDrawBitmapStringHighlight("plz wait for a second", 20, 20);
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
