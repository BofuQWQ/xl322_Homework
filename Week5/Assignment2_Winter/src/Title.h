#pragma once
#include "ofMain.h"

class Title {
public:
	Title();
	Title(glm::vec3 _pos, glm::vec3 _vel, ofImage _image1);
	Title(glm::vec3 _pos, glm::vec3 _vel, ofImage _image1, ofImage _image2);
	void update();
	void draw();
	void applyforce(glm::vec3 force);
	void reset();
	glm::vec3 pos, vel, acc;
	ofImage image1, image2;
	float alpha,alpha2;
	bool move=TRUE;
};