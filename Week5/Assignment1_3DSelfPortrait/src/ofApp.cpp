#include "ofApp.h"
//reference: lighting & ofGui Code from Lewis Lepton https://www.youtube.com/watch?v=Amfr-MY96W8
//--------------------------------------------------------------
void ofApp::setup(){

	gui.setup();
	gui.add(uiPosition.set("position", ofVec3f(-200, 200, 300), ofVec3f(-500, -500, -500), ofVec3f(500, 500, 500)));
	//ofSetSmoothLighting(true);
	
	/*
	ofColor skinColor = ofColor(255, 218, 185);
	head.setMode(OF_PRIMITIVE_TRIANGLES);
	head.setResolution(300, 300, 300);
	head.setSideColor(head.SIDES_TOTAL, skinColor);
	head.setPosition(ofVec3f(0, 0, 0));
	head.set(400);*/
	
	//material.setDiffuseColor(ofColor::red);
	//material.setAmbientColor(ofColor::red);
	//material.setSpecularColor(ofColor::white);
	//material.setShininess(128);

	a.loadFont("a.ttf", 16, true, true);
	//reference:https://forum.openframeworks.cc/t/using-font-as-a-texture-on-a-3d-surface/8153/9
	b = a.getStringBoundingBox("click and move the mouse", 0, 0);
	ofEnableAlphaBlending();
	fbo.allocate(b.width, b.height);
	fbo.begin();
	ofClear(0, 0, 0, 0);
	ofSetColor(255, 0, 0);
	a.drawString("click and move the mouse", 0, b.height);
	fbo.end();
	tex = fbo.getTextureReference();
	

	//head
	ofColor skinColor = ofColor(255, 218, 185);
	headPos = glm::vec3(0, 0, 0);
	head.set(300,300,300);
	head.setMode(OF_PRIMITIVE_TRIANGLES);
	head.setResolution(300, 300, 300);
	head.setSideColor(head.SIDE_BACK, skinColor);
	head.setSideColor(head.SIDE_BOTTOM, ofColor::black);
	head.setSideColor(head.SIDE_FRONT, skinColor);
	head.setSideColor(head.SIDE_LEFT, skinColor);
	head.setSideColor(head.SIDE_RIGHT, skinColor);
	head.setSideColor(head.SIDE_TOP, skinColor);
	head.setPosition(headPos);
	
	//front hair
	//hair.setMode(OF_PRIMITIVE)
	hairPos = glm::vec3(25, -40, 0);
	change = 0;
	radius = TWO_PI / 90;

	//glass
	glm::vec3 glassLpos(70, -120, -5);
	glm::vec3 glassRpos(230, -120, -5);
	
	/*
	glassL.setSideColor(head.SIDE_BACK, ofColor::blue);
	glassL.setSideColor(head.SIDE_BOTTOM, ofColor::blue);
	glassL.setSideColor(head.SIDE_FRONT, ofColor::blue);
	glassL.setSideColor(head.SIDE_LEFT, ofColor::blue);
	glassL.setSideColor(head.SIDE_RIGHT, ofColor::blue);
	glassL.setSideColor(head.SIDE_TOP, ofColor::blue);*/
	glassL.set(100, 40, 20);
	glassL.setMode(OF_PRIMITIVE_TRIANGLES);
	glassL.setPosition(glassLpos);
	glassR.set(100, 40, 20);
	glassR.setMode(OF_PRIMITIVE_TRIANGLES);
	glassR.setPosition(glassRpos);

	//mouth
	glm::vec3 mouthpos(230, -240, -5);
	mouth.set(100, 5, 15);
	mouth.setMode(OF_PRIMITIVE_TRIANGLES);
	mouth.setSideColor(mouth.SIDE_FRONT, ofColor::red);
	mouth.setSideColor(mouth.SIDE_TOP, ofColor::red);
	mouth.setSideColor(mouth.SIDE_BOTTOM, ofColor::red);
	mouth.setSideColor(mouth.SIDE_LEFT, ofColor::red);
	mouth.setSideColor(mouth.SIDE_RIGHT, ofColor::red);
	mouth.setPosition(mouthpos);

}

//--------------------------------------------------------------
void ofApp::update(){
	light.setPosition(uiPosition->x, uiPosition->y, uiPosition->z);
	change += radius;

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
		glassL.setSideColor(glassL.SIDE_FRONT, ofColor::black);
		glassR.setSideColor(glassR.SIDE_FRONT, ofColor::black);
	}
	else if (colorPattern == 1) {
		glassL.setSideColor(glassL.SIDE_FRONT, ofColor(Red,Green,Blue));
		glassR.setSideColor(glassR.SIDE_FRONT, ofColor(Red, Green, Blue));
	}
	else if (colorPattern == 2) {
		glassL.setSideColor(glassL.SIDE_FRONT, ofColor::fromHsb(H, S, B));
		glassR.setSideColor(glassR.SIDE_FRONT, ofColor::fromHsb(H, S, B));
	}
	else if (colorPattern == 3) {
		glassL.setSideColor(glassL.SIDE_FRONT, ofColor::white);
		glassR.setSideColor(glassR.SIDE_FRONT, ofColor::white);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	//hair
	
	/*
	glm::vec3 pt1(0, 0, 0);
	glm::vec3 pt2(50, 0, 0);
	glm::vec3 pt3(25, -50 - sin(change) * 50, 10);
	hair.addVertex(pt1);
	hair.addColor(ofFloatColor(0));
	hair.addVertex(pt2);
	hair.addColor(ofFloatColor(0));
	hair.addVertex(pt3);
	hair.addColor(ofFloatColor(0));
	hair.addIndex(0);
	hair.addIndex(1);
	hair.addIndex(2);*/

	ofBackground(0);
	
	ofEnableDepthTest();
	cam.begin();
	light.enable();
	//material.begin();
	
	//ofDrawSphere(uiPosition->x, uiPosition->y, uiPosition->z, 32);
	//ofDrawAxis(500);
	
	head.draw();

	ofPushMatrix();
	ofTranslate(-150, 150, 150);
	//hair.draw();
	ofPushStyle();
	ofSetColor(0);
	//hair
	for (int i=0;i<6;i++){
		glm::vec3 addHair1(50, 0, 0);
		ofDrawCone(hairPos+addHair1*i, 25, 80);
		glm::vec3 addHair2(0, 0, -50);
		glm::vec3 leftHair(-25, 0, -20);
		ofDrawCone(hairPos + leftHair + addHair2 * i, 25, 80);
		glm::vec3 rightHair(300, 0, 0);
		ofDrawCone(hairPos + leftHair + rightHair+ addHair2 * i, 25, 80);
		glm::vec3 backHair(0, 0, -300);
		ofDrawCone(hairPos +backHair+ addHair1 * i, 25, 80);
	}
	ofPopStyle();
	//glasses
	glassL.draw();
	glassR.draw();
	mouth.draw();
	ofPopMatrix();
	tex.draw(ofGetMouseX()-600,-ofGetMouseY()+320,200);
	



	//material.end();
	light.disable();
	cam.end();
	ofDisableDepthTest();
	gui.draw();

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
