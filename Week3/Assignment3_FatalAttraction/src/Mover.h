#pragma once
#include "ofMain.h"

class Mover {
public:
	Mover();
	Mover(glm::vec2 _pos);

	void applyForce(glm::vec2 force);
	void update();
	void draw();

	glm::vec2 pos, vel, acc;
	glm::vec2 elasticForce;
	float mass;


};