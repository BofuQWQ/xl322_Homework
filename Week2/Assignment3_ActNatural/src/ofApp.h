#pragma once

#include "ofMain.h"
class Ripple {
public:
	Ripple();
	void setup(float _x, float _y);
	void update();
	void draw();
	float xpos, ypos;
	float radius=0;
	float pct;
	float transparency=255;
	float noise;
private:
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
		vector <Ripple> ripple;
		float xpos;
		float ypos;
		//fish
		ofImage fish;
		ofVec3f fishPos=ofVec3f(ofGetWidth()/4,ofGetHeight()/2);
		ofVec3f target;
		float angle;
		float pct2;
};
