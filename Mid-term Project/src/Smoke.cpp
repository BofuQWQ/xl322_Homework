#include "Smoke.h"
Smoke::Smoke(){
}

Smoke::Smoke(glm::vec2 _pos){
	pos = _pos; 
}

void Smoke::applyForce(glm::vec2 force){
	for (int i = 0; i < particles.size(); i++) {
		particles[i].applyForce(force);
	}
}

void Smoke::update(int numNewParticles, int maxParticles) {
	for (int i = 0; i < numNewParticles; i++) {
		glm::vec2 vel = glm::vec2(ofRandom(-0.5, -0.1), ofRandom(-2,-1));
		Particle p = Particle(pos, vel,ofColor::gray,100,2.5); 
		particles.push_back(p);
	}
	for (int i = 0; i < particles.size(); i++) {
		particles[i].update();
	}
	while (particles.size() > maxParticles) {
		particles.erase(particles.begin()); 
	}

}

void Smoke::draw() {
	for (int i = 0; i < particles.size(); i++) {
		particles[i].draw();
	}
}

