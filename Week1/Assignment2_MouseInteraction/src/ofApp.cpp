#include "ofApp.h"
//--------------------------------------------------------------
Ball::Ball() {
}

void Ball::setup(float _x, float _y) {
	//size, position, and speed	
	xPos = _x;
	yPos = _y;
	radius = ofRandom(10, 50);
	xSpeed = ofRandom(-10, 10);
	ySpeed = ofRandom(-10, 10);
	float theta = 0;
	float frames = 90;

	ofSetCircleResolution(100);
}

void Ball::update() {
	
	//angle transforming
	theta += TWO_PI / frames;
	//move ball
	xPos += xSpeed;
	yPos += ySpeed;
	//border detection
	if (xPos <= radius) {
		//xPos = radius;
		xSpeed = -xSpeed;
		colour = ofColor(0);
	}
	else if (xPos >= ofGetWidth() - radius) {
		//xPos = ofGetWidth() - radius;
		xSpeed = -xSpeed;
		colour = ofColor(255, 0, 0);
	}
	if (yPos <= radius) {
		//yPos = radius;
		ySpeed = -ySpeed;
		colour = ofColor(0, 255, 0);
	}
	else if (yPos >= ofGetHeight() - radius) {
		//yPos = ofGetHeight() - radius;
		ySpeed = -ySpeed;
		colour = ofColor(0, 0,255);
	}
}


// draw the ball
void Ball::draw() {

	ofSetColor(colour);				// set the GLOBAL color
	ofDrawCircle(xPos, yPos, radius);		// and draw
}

//----------------------------ofApp--------------------------------
//--------------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255);
	
}

//--------------------------------------------------------------
void ofApp::update(){	

	for (int i = 0; i < BallArray.size(); i++) {
		BallArray[i].update();		
	}
	for (int m = 0; m < BallArray.size(); m++) {
		for (int n = m; n < BallArray.size(); n++) {
			if (ofDist(BallArray[m].xPos, BallArray[m].yPos, BallArray[n].xPos, BallArray[n].yPos) < (BallArray[m].radius + BallArray[n].radius)) {
				BallArray[m].xSpeed *= -1;
				BallArray[n].xSpeed *= -1;
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	for (int i = 0; i < BallArray.size(); i++) {
		BallArray[i].draw();
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
	Ball ball;
	ball.setup(x, y);
	BallArray.push_back(ball);

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
