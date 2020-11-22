#pragma once
#include "ofMain.h"
class Cloud {

public:

	Cloud();
	Cloud(glm::vec2 _pos, float _alpha);
	glm::vec2 pos, vel, acc;
	float alpha;
	int random;
	void applyForce(glm::vec2 force);
	void update();
	void draw();
	void disappear();
	ofImage cloud1, cloud2, cloud3;
};
