#include "Mover.h"


Mover::Mover(){
}

Mover::Mover(glm::vec2 _pos)
{
	pos = _pos;
	vel = glm::vec2(0, 0);
	acc = glm::vec2(0, 0);
	mass = 5;
}

void Mover::applyForce(glm::vec2 force)
{
	acc += force / mass;
}

void Mover::update()
{
	vel += acc;
	pos += vel;
	acc *= 0;

	if (pos.x + mass * 4.0 >= ofGetWidth() || pos.x - mass * 4.0 <= 0) {
		vel.x *= -1;
	} else if (pos.y+mass*4.0>=ofGetHeight() || pos.y-mass*4.0<=0){
		vel.y *= -1;
	}
}

void Mover::draw()
{
	ofDrawCircle(pos, mass * 4.0);
}