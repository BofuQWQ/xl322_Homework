#include "snow.h"

snow::snow(){
}

snow::snow(glm::vec3 _pos, glm::vec3 _vel, float _radius)
{
	pos = _pos;
	vel = _vel;
	radius = _radius;
}

void snow::applyforce(glm::vec3 force)
{
	acc += force;
}

void snow::reset()
{
	float xPos = ofRandom(ofGetWidth());
	float yPos = ofRandom(-ofGetHeight() , -100);
	float zPos = ofRandom(0,300);
	glm::vec3 Pos(xPos, yPos, zPos);
	pos = Pos;
	glm::vec3 Vel(ofRandom(-0.1, 0.1), ofRandom(0.3, 0.5), 0);
	vel = Vel;
}
void snow::update()
{
	vel += acc;
	pos += vel;
	acc *= 0;

	//reset
	if (pos.y + radius >= ofGetHeight()+100) {
		reset();
	}

	if (pos.x + radius <= 0) {
		reset();
	}

	if (pos.x - radius >= ofGetWidth()) {
		reset();
	}
}

void snow::draw()
{
	ofPushStyle();
	ofSetColor(255);
	ofDrawSphere(pos, radius);
	ofPopStyle();
}

