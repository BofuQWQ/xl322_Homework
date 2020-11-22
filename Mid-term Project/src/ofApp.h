#pragma once

#include "ofMain.h"
#include "Smoke.h"
#include "Cloud.h"
#include "Ripple.h"
#include "Waterfall.h"

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
		
		//initiate background
		int rollMode;
		bool start,rollL,rollR;
		ofImage background;
		glm::vec2 bgPos;

		//sound player
		ofSoundPlayer bgm;
		//timer
		unsigned long lastTime, Timer;
		float count;

		//logo
		ofImage logo;
		bool logoDisplay;
		float logoAlpha;
		//instruction
		ofTrueTypeFont font;
		int insNum;
		//scenery (images)
		ofImage mount, scene, water;
		glm::vec2 mountPos, scenePos, waterPos;
		float mountAlpha, sceneAlpha, waterAlpha;
		//clouds
		vector <glm::vec2> cloudPos;
		vector <Cloud> cloud;
		//ripple
		vector <Ripple> ripple;
		bool inWater;
		//boat (auto)
		ofImage boatA;
		glm::vec2 boatPos;


		//particle systems
		vector <Smoke> smoke;
		vector <Waterfall> waterfall;
		 
		
};
