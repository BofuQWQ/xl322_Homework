#include "Title.h"

Title::Title() {
}

Title::Title(glm::vec3 _pos, glm::vec3 _vel, ofImage _image1)
{
	pos = _pos;
	vel = _vel;
	image1 = _image1;
	//image2 = NULL;
	alpha = 0;
}

Title::Title(glm::vec3 _pos, glm::vec3 _vel, ofImage _image1, ofImage _image2)
{
	pos = _pos;
	vel = _vel;
	image1 = _image1;
	image2 = _image2;
	alpha = 0;
	alpha2 = 0;
}

void Title::applyforce(glm::vec3 force)
{
	acc += force;
}

void Title::reset()
{
	if (pos.y >= ofGetHeight() + 100 && vel.y>0) {
		pos.y = -100 - image1.getHeight();
	}
	
	if (pos.y <= -100 - image1.getHeight() && vel.y < 0) {
		pos.y = ofGetHeight() + 100;
	}
	if (pos.x >= ofGetWidth() + 100) {
		pos.x = -100 - image1.getWidth();
	}
	if (pos.x <= -100 - image1.getWidth()) {
		pos.x = ofGetWidth() + 100;
	}
}

void Title::update()
{
	if (move==TRUE){   //should include all?
		alpha2 = 0;
		vel += acc;
		pos += vel;
		acc *= 0;
		alpha += 2;
	
		if (vel.y >= 4) {
			vel.y = 2;
		}
		if (vel.y <= -4) {
			vel.y = -2;
		}
		reset();
	}

	if (move == FALSE) {
		alpha2 += 5;
	}
}

void Title::draw()
{
	ofPushStyle();
	ofSetColor(255, alpha);
	image1.draw(pos);
	ofPopStyle();

	if (ofGetMouseX() >= pos.x && ofGetMouseX() <= pos.x + image1.getWidth()
		&& ofGetMouseY() >= pos.y && ofGetMouseY() <= pos.y + image1.getHeight()) {
		if (ofGetMousePressed() == TRUE) {
			move = FALSE;
		}
		else {
			move = TRUE;
		}
	}

	if (move == FALSE) {
		
		ofPushMatrix();
		ofPushStyle();
		ofSetColor(255, alpha2);
		if (vel.y != 0) {
			glm::vec3 addPos(image1.getWidth() + 50, -pos.y+ofGetMouseY(), 0);
			image2.draw(pos + addPos);
		}
		else {
			glm::vec3 addPos(-pos.x+ofGetMouseX() , image1.getHeight(), 0);
			image2.draw(pos + addPos);
		}
		
		ofPopStyle();
		ofPopMatrix();
	}
}

