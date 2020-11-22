#include "Particle.h"

Particle::Particle(){
}

Particle::Particle(glm::vec2 _pos, glm::vec2 _vel, ofColor _color, float _lifespan, float _pct)
{
	color = _color;
	pos = _pos;
	vel = _vel;
	lifespan = _lifespan;
	pct = _pct;
	acc = glm::vec2(0, 0);
	
}

void Particle::applyForce(glm::vec2 force)
{
	acc += force;
}

void Particle::update()
{
	vel += acc;
	pos += vel;
	lifespan -= pct;
	acc *= 0;
}

void Particle::draw()
{
	ofPushStyle();
	ofSetColor(color,lifespan);
	ofDrawCircle(pos,3);
	ofPopStyle();
}

/*bool Particle::isDead() {
	if (lifespan <= 0) {
		return true;
	}
	else {
		return false;
	}
}*/