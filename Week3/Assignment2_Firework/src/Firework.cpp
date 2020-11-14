#include "Firework.h"

Firework::Firework() {
	firework = Particle();
	gravity = glm::vec2(0, 0.04);
}

void Firework::update() {
	firework.applyForce(gravity);
	firework.update();

	if (firework.explode()) {
		for (int i = 0; i < 100; i++) {
			Particle p = Particle(firework.pos);
			particles.push_back(p);
		}
	}

	for (int i = 0; i < particles.size(); i++) {
		particles[i].applyForce(gravity);
		particles[i].update();
	}
}

void Firework::draw() {
	for (int i = 0; i<particles.size(); i++) {
		particles[i].draw();
		if (particles[i].isDead()) {
			particles.erase(particles.begin());
		}
	}
}
