#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//ofSetBackgroundAuto();

	//set titles
	t1.load("1.png");
	t2.load("2.png");
	t3.load("3.png");
	t4.load("4.png");
	t0.load("5.png");
	t1x.load("1x.png");
	t2x.load("2x.png");
	t3x.load("3x.png");
	t4x.load("4x.png");

	t1pos = glm::vec3(25, 50,-200);
	t2pos = glm::vec3(600, 800, -150);
	t3pos = glm::vec3(900, 200, -50);
	t4pos = glm::vec3(1000, 400, -100);
	t0pos = glm::vec3(400, 400, -100);
	
	t1vel = glm::vec3(0, 2, 0);
	t2vel = glm::vec3(0, -3, 0);
	t3vel = glm::vec3(-2, 0, 0);
	t4vel = glm::vec3(-3, 0, 0);
	t0vel = glm::vec3(0,1, 0);

	Title title1 = Title(t1pos, t1vel, t1,t1x);
	Title title3 = Title(t2pos, t2vel, t2,t2x);
	Title title2 = Title(t3pos, t3vel, t3,t3x);
	Title title4 = Title(t4pos, t4vel, t4,t4x);
	Title title0 = Title(t0pos, t0vel, t0);

	titles.push_back(title0);
	titles.push_back(title1);
	titles.push_back(title2);
	titles.push_back(title3);
	titles.push_back(title4);
	

	//set up
	gravity = glm::vec3(0, 0.005, 0);
	angle = 0;
	for (int i = 0; i < 400; i++) {
		float xPos = ofRandom(ofGetWidth());
		float yPos = ofRandom(-400,ofGetHeight());
		float zPos = ofRandom(0,300);
		glm::vec3 Pos(xPos, yPos, zPos);
		glm::vec3 Vel(ofRandom(-0.1, 0.1), ofRandom(0.05,0.1), 0);
		snow s = snow(Pos, Vel, 3);
		snowfall.push_back(s);
	}

	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
}

//--------------------------------------------------------------
void ofApp::update(){
	//text
		//angle += TWO_PI/90;
		//tpos.z += sin(angle)*50;
	for (int i = 0; i < titles.size(); i++) {
		titles[i].update();
	}


	//snow
	for (int i = 0; i < snowfall.size(); i++) {
		snowfall[i].applyforce(gravity);
		snowfall[i].update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackgroundGradient(ofColor(0),ofColor(129),OF_GRADIENT_CIRCULAR);
	ofEnableDepthTest();
	//reference (solution to png not working in 3d: https://forum.openframeworks.cc/t/transparent-png-image-is-not-working-in-3d-world/26353)
	glAlphaFunc(GL_GREATER, 0.5);
	glEnable(GL_ALPHA_TEST);
	//ofDrawAxis(300);

	//text images (titles)
	//t1
	/*if (t1pos.y >= ofGetHeight() + 100) {
		t1pos.y = -100-t1.getHeight();
	}
	if (t1vel.y >= 4) {
		t1vel.y = 2;
	}

	//t2
	if (t2pos.x >= ofGetWidth() + 100) {
		t2pos.x = -100 - t2.getWidth();
	}*/

	ofPushMatrix();
	ofPushStyle();
	//ofTranslate(ofGetWidth() / 4 * 2, ofGetHeight() / 2);
	//ofRotateY(angle);
	for (int i = 0; i < titles.size(); i++) {
		titles[i].draw();
	}
	ofPopStyle();
	ofPopMatrix();

	//snow
	for (int i = 0; i < snowfall.size(); i++) {
		snowfall[i].draw();
	}
	ofDisableDepthTest();

	ofDrawBitmapStringHighlight("Try pressing the titles of poems.", 20, 20);
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
