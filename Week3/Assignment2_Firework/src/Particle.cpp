#include "Particle.h"
Particle::Particle() {
	pos = glm::vec2(ofRandom(ofGetWidth()), ofGetHeight());
	vel = glm::vec2(0, ofRandom(-12, -5));
	acc = glm::vec2(0, 0);
	duration = 30.0;
	isSeed = true;
}

Particle::Particle(glm::vec2 _pos) {
	pos = _pos;
	vel = glm::vec2(ofRandom(-1,1)*ofRandom(4, 8), ofRandom(-1, 1)*ofRandom(4, 8));
	//vel.operator*=(ofRandom(4, 8));
	acc = glm::vec2(0, 0);
	duration = 30.0;
	
}

void Particle::applyForce(glm::vec2 force) {
	acc += force;
}

void Particle::update() {
	vel += acc;
	pos += vel;
	if (!isSeed) {
		duration -= 5.0;
		vel *= 0.85;
	}
	acc *= 0;
}

void Particle::draw() {
	ofColor color = ofColor(ofRandom(160, 255));
	ofSetColor(color,duration);
	ofDrawCircle(pos, 5);	
}

bool Particle::explode() {
	if (vel.y > 0) {
		duration = 0;
		return true;
	} else {
		return false;
	}
}

bool Particle::isDead() {
	if (duration < 0.0) {
		return true;
	}
	else {
		return false;
	}
}

