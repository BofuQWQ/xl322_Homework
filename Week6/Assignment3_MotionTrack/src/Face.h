//FaceOSC template from https://github.com/CreativeInquiry/FaceOSC-Templates
#pragma once
#include "ofMain.h"
class ofxOscMessage;

class Face {

public:
	int found = 0;
	// pose
	float poseScale = 0;
	ofVec2f posePosition;     
	ofVec3f poseOrientation;
	// gesture
	float mouthWidth = 0;
	float mouthHeight = 0;
	float eyeLeft = 0;
	float eyeRight = 0;
	float eyebrowLeft = 0;
	float eyebrowRight = 0;
	float jaw = 0;
	float nostrils = 0;

	Face() {}
	bool parseOSC(ofxOscMessage& m);
	string toString();
};
