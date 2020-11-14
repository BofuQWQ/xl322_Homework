#pragma once
#include "ofMain.h"
#include "Particle.h"

class Firework {
public:
	Firework();
	//void applyForce(glm::vec2 force);
	void update();
	void draw();
	vector<Particle> particles;
	Particle firework;
	glm::vec2 pos;
	glm::vec2 gravity;
	


};