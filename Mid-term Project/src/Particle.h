#pragma once
#include "ofMain.h"
class Particle {

public:

	Particle();
	Particle(glm::vec2 _pos, glm::vec2 _vel, ofColor _color, float _lifespan, float pct);
	ofColor color;
	glm::vec2 pos, vel, acc;
	float lifespan, pct;
	//bool isDead();
	void applyForce(glm::vec2 force);
	void update();
	void draw();

};
