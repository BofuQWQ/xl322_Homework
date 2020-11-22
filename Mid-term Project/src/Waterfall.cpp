#include "Waterfall.h"
Waterfall::Waterfall() {
}

Waterfall::Waterfall(glm::vec2 _pos) {
	pos = _pos;
}

void Waterfall::applyForce(glm::vec2 force) {
	for (int i = 0; i < particles.size(); i++) {
		particles[i].applyForce(force);
	}
}

void Waterfall::update(int numNewParticles, int maxParticles) {
	for (int i = 0; i < numNewParticles; i++) {
		glm::vec2 vel = glm::vec2(ofRandom(-1.5,-1), ofRandom(5,12));
		Particle p = Particle(pos, vel,ofColor(115,168,165),100,4);
		particles.push_back(p);
	}
	for (int i = 0; i < particles.size(); i++) {
		particles[i].update();
	}
	while (particles.size() > maxParticles) {
		particles.erase(particles.begin());
	}

}

void Waterfall::draw() {
	for (int i = 0; i < particles.size(); i++) {
		particles[i].draw();
	}
}
