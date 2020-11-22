#include "Ripple.h"

Ripple::Ripple() {
}

Ripple::Ripple(glm::vec2 _pos) {
	pos = _pos;
	pct = 1;
	pct -= 0.01;
	ofSetCircleResolution(100);
}


void Ripple::update() {
	noise = ofMap((ofNoise(ofGetElapsedTimef())), 0, 1, 0, 255);
	radius += pct;
	if (radius >= 0.5) {
		transparency -= 2.5;
	}

}

void Ripple::draw() {
	ofPushStyle();
	ofSetColor(0, transparency);
	ofNoFill();
	ofDrawEllipse(pos, radius,radius/2);
	ofPopStyle();

}
