#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ori.load("1.jpg");
	width = ori.getWidth();
	height = ori.getHeight();
	size = width * height;
	bpp = 3;// ori.getPixels().getBitsPerChannel() / 8;
	data = ori.getPixels().getData();
	pixels = new unsigned char[width*height * 3];
	//sorted = ori.allocate(width, height, OF_IMAGE_COLOR);
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			//float red = ofRandom(255);
			//float green = ofRandom(255);
			//float blue = ofRandom(255);
			//ofColor color£¨red, green, blue);
			int i = bpp * (x + width * y);
			float red = data[i];
			float green = data[i+1];
			float blue = data[i+2];
			pixels[i] = red;
			pixels[i + 1] = green;
			pixels[i + 2] = blue;
		}
	}

	//sorted.allocate(width, height, OF_IMAGE_COLOR);
	//sorted.setColor(ofColor::white);
	ori.setFromPixels(pixels, width, height, OF_IMAGE_COLOR);
	delete[] pixels;
	
	//sorted.update();
	
	
}

//--------------------------------------------------------------
void ofApp::update() {
	/*
	glm::vec2 size = glm::vec2(width,height);
	sorted.update();
	for (int x = 0; x < sorted.getPixels().size(); x++) {
		float record = -1;
		int select = x;
		for (int y = x; y < sorted.getPixels().size(); y++) {
			ofColor color = ori.getPixels().getColor(y);
			float alpha = color.getBrightness();
			if (alpha > record) {
				select = y;
				record = alpha;
			}
		}
		ofColor temp= ori.getPixels().getColor(x);
		sorted.getPixels().
	}
	*/
	ofImage sorted=ori;
	for (int x = 1; x < width - 1; x++) {
		for (int y = 1; y < height - 1; y++) {
			ofColor c = sorted.getColor(x, y);
			ofColor n = sorted.getColor(x + 1, y);
			int b1 = c.getHue();
			int b2 = n.getHue();
			if (b1 < b2) {
				ofColor temp = c;
				sorted.setColor(x, y, n);
				sorted.setColor(x + 1, y, c);
			}
		}
	}
	ori = sorted;
}
	

//--------------------------------------------------------------

//--------------------------------------------------------------
void ofApp::draw(){
	ori.draw(0, 0,600,600);
	sorted.draw(600,0, 600, 600);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
