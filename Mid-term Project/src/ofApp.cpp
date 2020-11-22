#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//initiate background
	background.load("background.png");
	ofSetBackgroundAuto(false);
	bgPos=glm::vec2 (0,0);
	start = false;
	rollL = false;
	rollR = false;
	rollMode = 0; //autoMode

	//logo
	logo.load("logo.png");
	logoDisplay = false;

	//font (instruction)
	font.load("font.ttf", 15);
	insNum = 1;

	//sound
	bgm.setLoop(true);
	bgm.load("bgm.mp3");
	

	//initiate scenery
	mount.load("mount.png");
	mountPos = glm::vec2 (60,60);
	mountAlpha = 0;

	scene.load("scene.png");
	scenePos = glm::vec2 (60, 250);
	sceneAlpha = 0;

	water.load("water.png");
	waterPos = glm::vec2 (57, 350);
	waterAlpha = 0;

	//initiate objects
	//clouds
	for (int i = 0; i < 5; i++) {
		glm::vec2 clp = glm::vec2(120 + i * 400, 100 + (i % 2) * 50 + ofRandom(-20, 20));
		cloudPos.push_back(clp);
		Cloud c = Cloud(cloudPos[i], 180);
		cloud.push_back(c);
	}
	//ripple
	inWater = false;
	//auto boat
	boatA.load("boat1.png");
	boatPos = glm::vec2(820, 420);

	
	
	//initiate smoke
	glm::vec2 smokePos = glm::vec2(377,343);
	Smoke s = Smoke(smokePos);
	smoke.push_back(s);
	//initiate waterfall
	for (int i = 0; i < 20; i+=3) {
		glm::vec2 fallPos = glm::vec2(860+i, 104+ofRandom(-1,1));
		Waterfall w = Waterfall(fallPos);
		waterfall.push_back(w);
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	//set rolling mode
	if (rollMode == 1) {		  // Mode 1 - Automatic Scrolling
		bgPos.x -= 0.3;
	} else if (rollMode == 2) {	  // Mode 2 - Self-controlled Scrolling
		if (rollL == true) {
			bgPos.x += 10;		
		} else if (rollR == true) { 
			bgPos.x -= 10;
		}		
	} 

	//border detection
	if (bgPos.x <=-1600) { 
		bgPos.x = -1600;
	} else if (bgPos.x >= 0) {
		bgPos.x = 0;
	}
	cout << "test   " << bgPos.x << endl;

	//instruction
	lastTime = ofGetElapsedTimeMillis();
	if (lastTime - Timer > 4000) {
		insNum += 1;
		if (insNum = 4) {
			insNum = 1;
		}
		Timer = ofGetElapsedTimeMillis();
	}
	//draw scenery
	if (start == true) {	
		mountAlpha += 1;
		if (mountAlpha >= 125) {
			sceneAlpha += 1;
			if (sceneAlpha >= 125) {
				waterAlpha += 1;
			}
		}
	}

	//start updating
	if (rollMode == 1 || rollMode == 2) { 

		//translate
		ofPushMatrix();
		ofTranslate(bgPos);
		//update particle systems
		for (int i = 0; i < smoke.size(); i++) {
			//smoke[i].applyForce(wind);
			smoke[i].update();
		}
		for (int i = 0; i < waterfall.size(); i++) {
			waterfall[i].update(10,150);
		}

		//update clouds
		for (int i = 0; i < cloud.size(); i++) {
			cloud[i].update();
			if (cloudPos[i].x >= 2044) {
				cloud[i].disappear();
		//Cloud c = Cloud(cloudPos[0], 180);
		//cloud.push_back(c);
			}
		}

		/*float time = ofGetElapsedTimef();
		if ((int)time % 6000 == 0) {
			Cloud c = Cloud(cloudPos[0], 180);
			cloud.push_back(c);
		}*/

		//update water
		for (int i = 0; i < ripple.size(); i++) {
			if(inWater == true) {
				ripple[i].update();
			}
		}

		//update boat
		glm::vec2 addBoatPos = glm::vec2(-0.03, 0.04);
		if (boatPos.y <= 500) {
			boatPos += addBoatPos;
		}
		else {
			boatPos -= addBoatPos;
		}
		ofPopMatrix();
	}
	cout << "cloudPos " << cloudPos[4].x << endl;

	//
	//ballPos += force;
	/*else if (mode == 2) {		// Mode2-Scrolling with Mouse Move
		if (ofGetMouseX() >= ofGetWidth() - 100) {
			pos -= ofMap(ofGetMouseX(), 700, 800, 1, 4);
		}
	}*/

}

//--------------------------------------------------------------
void ofApp::draw() {
	background.draw(bgPos, 2400, 600);
	//scroll.draw(posX, posY, 2000, 600);

	//draw objects
	ofPushMatrix();
	ofPushStyle();
	ofTranslate(bgPos);

	//draw scenery
	ofSetColor(255, mountAlpha);
	mount.draw(mountPos);
	ofSetColor(255, sceneAlpha);
	scene.draw(scenePos, 2282, 256);
	ofSetColor(255, waterAlpha);
	water.draw(waterPos, 2284, 193);
	ofPopStyle();



	if (rollMode == 1 || rollMode == 2) {  //start drawing

	//draw particle systems
		ofPushStyle();
		for (int i = 0; i < smoke.size(); i++) {
			ofSetColor(255, sceneAlpha);
			smoke[i].draw();
		}
		for (int i = 0; i < waterfall.size(); i++) {
			ofSetColor(255, mountAlpha);
			waterfall[i].draw();
		}

		//draw clouds
		for (int i = 0; i < cloud.size(); i++) {
			ofSetColor(255, mountAlpha);
			cloud[i].draw();
		}
		ofPopStyle();

		//draw ripple (water)
			//detect if in water
		if (ofGetMouseX() >= 57 && ofGetMouseX() <= 400 && ofGetMouseY() <= 450 && ofGetMouseY() >= 300) {
			inWater = true;
		}
		
		for (int i = 0; i < ripple.size(); i++) {
			if (inWater==true) {
				ripple[i].draw();
			}
		}

		//draw boat (auto)
		ofPushStyle();
		ofSetColor(255, waterAlpha);
		boatA.draw(boatPos, 50, 32);
		ofPopStyle();
	}
	ofPopMatrix();
	//display the logo
	if (logoDisplay==true) {
		logo.draw(100, 100);
	}

	//instructions
	ofPushStyle();
	ofSetColor(0, 180);
	if (insNum == 1) {
		font.drawString("Tips: Press Space to get started!", 15, 35);
	}
	else if (insNum == 2) {
		font.drawString("Tips: Press Space to enable controlling by A & D key!", 15, 35);
	}
	else if (insNum == 3) {
		font.drawString("Tips: Why not try clicke on the lake?", 15, 35);
	}
	else {
		font.drawString("Tips: Press Shift to display the logo!", 15, 35);
	}
	
	ofPopStyle();
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == ' ') {
		if (rollMode == 0) {			//switch to auto mode
			start = true;
			//rollMode = 2; //
			if (mountAlpha >= 255 && sceneAlpha >= 255 && waterAlpha >= 255) {
				rollMode = 1;
				bgm.play();
			}
		}
		else if (rollMode == 1) {		//switch to self-controlled mode
			rollMode = 2;
		}
		else {							//switch to auto mode
			rollMode = 1;
		}
	}

	//switch the screen (background)
	if (key == 'a' || key == 'A') {
		rollL = true;
	}
	else if (key == 'd' || key == 'D') {
		rollR = true;
	}

	//display the logo
	if (key == OF_KEY_SHIFT) {
		logoDisplay = true;
	}

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	

	//switch the screen (background)
	if (key == 'a' || key == 'A') {
		rollL = false;
	}
	else if (key == 'd' || key == 'D') {
		rollR = false;
	}

	//not display the logo
	if (key == OF_KEY_SHIFT) {
		logoDisplay = false;
	}
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
	glm::vec2 posi = glm::vec2(x, y);
	Ripple r = Ripple(posi);
	ripple.push_back(r);

	/*if (rollMode == 1 || rollMode == 2) {
		if (inWater == true) {
			glm::vec2 posi = glm::vec2(x, y);
			Ripple a=Ripple(posi);
			ripple.push_back(a);
		}
	}*/


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
