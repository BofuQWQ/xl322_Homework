#pragma once

#include "ofMain.h"
#include "snow.h"
#include "Title.h"

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

		vector <snow> snowfall;
		vector <Title> titles;
		
		glm::vec3 gravity;
		ofImage t1,t2,t3,t4,t0;
		ofImage t1x,t2x,t3x,t4x;
		glm::vec3 t1pos,t2pos,t3pos,t4pos,t0pos;
		glm::vec3 t1vel, t2vel,t3vel,t4vel,t0vel;
		float angle;
		
		
};
