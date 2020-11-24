#pragma once

#include "ofMain.h"
#include "ofxGui.h"

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
		
		ofxPanel gui;
		ofParameter <ofVec3f> uiPosition;
		ofEasyCam cam;
		ofLight light;
		//ofMaterial material;

		ofBoxPrimitive head;
		glm::vec3 headPos;
		glm::vec3 hairPos;
		
		
		ofConePrimitive hair;
		float change;
		float radius;
		
		ofBoxPrimitive glassL;
		ofBoxPrimitive glassR;

		int colorPattern = 0;

		ofBoxPrimitive mouth;

		ofTrueTypeFont a;
		ofFbo fbo;
		ofRectangle b;
		ofTexture tex;

};
