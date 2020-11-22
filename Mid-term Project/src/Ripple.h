#pragma once

#include "ofMain.h"
class Ripple {
public:
	Ripple();
	Ripple(glm::vec2 _pos);
	void update();
	void draw();
	glm::vec2 pos;
	float radius = 0;
	float pct;
	float transparency = 150;
	float noise;
private:
};