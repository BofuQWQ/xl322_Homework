#pragma once
#include "ofMain.h"

class Particle{
	public:
		Particle();
		Particle(glm::vec2 _pos);
		void update();
		void draw();
		void applyForce(glm::vec2 force);
		bool explode();
		bool isDead();
		glm::vec2 pos;
		glm::vec2 vel;
		glm::vec2 acc;
		float duration;
		float radius;
		bool isSeed = false;
};
