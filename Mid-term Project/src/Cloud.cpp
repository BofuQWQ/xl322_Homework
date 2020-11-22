#include "Cloud.h"

Cloud::Cloud() {
}

Cloud::Cloud(glm::vec2 _pos, float _alpha)
{
	pos = _pos;
	vel = glm::vec2 (ofRandom(0.01, 0.1),0);
	alpha = _alpha;
	acc = glm::vec2(0, 0);
	cloud1.load("cloud1.png");
	cloud2.load("cloud2.png");
	cloud3.load("cloud3.png");
	random = (int)ofRandom(1, 3);
}

void Cloud::applyForce(glm::vec2 force)
{
	acc += force;
}

void Cloud::update()
{
	vel += acc;
	pos += vel;
	acc *= 0;
}

void Cloud::draw()
{
	ofPushStyle();
	ofSetColor(255, alpha);
	
	if (random == 1) {
		cloud1.draw(pos);
	}
	else if (random == 2) {
		cloud2.draw(pos);
	}
	else {
		cloud3.draw(pos);
	}
	ofPopStyle();
}

void Cloud::disappear()
{
	alpha -= 2.5;
}