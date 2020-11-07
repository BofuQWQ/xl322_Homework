#pragma once

#include "ofMain.h"
class MagicBall {
public:
	MagicBall() {}
	~MagicBall() {}

	void update();
	void draw();

	ofVec3f pos1 = ofVec3f(ofGetWidth() / 4 + 40, ofGetHeight() - 255);
	ofVec3f pos2 = ofVec3f(ofGetWidth() *3/ 4 -2, ofGetHeight() - 255);

	//natural move of the ball
	ofVec3f v = ofVec3f(10, 0);
	ofVec3f a = ofVec3f(0.2, 0);
	ofVec3f g = ofVec3f(0, 1);
	//simulate the wind
	float noi;
};


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		vector <MagicBall> magicball;
};
