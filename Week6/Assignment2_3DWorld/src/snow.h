#pragma once
#include "ofMain.h"

class snow {
public:
	snow();
	snow(glm::vec3 _pos, glm::vec3 _vel, float _radius);
	void update();
	void draw();
	void applyforce(glm::vec3 force);
	void reset();
	glm::vec3 pos, vel, acc;
	float radius;
};