#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofBackground(0, 0, 0);


	//latitude, longitude, zoomfactor (1-15 for mapzen?), image size, image size always a factor of 256
	//allocates ofImage, updates maptiles while loading
	mapZen.createMapImage(49.829900, 6.731873, 12, 256 * 2, 256 * 2);

	for (int i = 0; i < 11; i++) {
		mapZen.createMapImage(ofRandom(-60.0, 60.0), ofRandom(-180.0, 180.0), ofRandom(6, 10), 256 * 2, 256 * 2);
	}

	/*Terrarium format PNG tiles contain raw elevation data in meters,
	in Web Mercator projection (EPSG:3857).
	All values are positive with a 32,768 offset, split into the red, green, and blue channels, with 16 bits of integer and 8 bits of fraction.

	To decode:
	(red * 256 + green + blue / 256) - 32768

	*/

}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	int size = 240;
	int x, y;
	for (int i = 0; i < mapZen.getMapImagesPtr()->size(); i++) {
		x = ((i % (ofGetWidth() / size)) * size);
		y = (size * (i / 4));
		mapZen.getMapImagesPtr()->at(i)->draw(x, y, size-5, size-5);
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {


	//press a key after loading to convert data to b&w

	float minV = 0;
	float maxV = 0;
	for (int i = 0; i < mapZen.getMapImagesPtr()->size(); i++) {
		if (mapZen.getMapImagesPtr()->back()->isAllocated()) {
			ofImage* Mapimg = mapZen.getMapImagesPtr()->at(i);
			int w = Mapimg->getWidth();
			int h = Mapimg->getHeight();
			for (int i = 0; i < w; i++) {
				for (int j = 0; j < h; j++) {
					ofColor c = Mapimg->getColor(i, j);
					float ele = (c.r * 256 + c.g + c.b / 256) - 32768;
					if (minV > ele) {
						minV = ele;
					}
					if (maxV < ele) {
						maxV = ele;
					}
				}
			}
			for (int i = 0; i < w; i++) {
				for (int j = 0; j < h; j++) {
					ofColor c = Mapimg->getColor(i, j);
					float ele = (c.r * 256 + c.g + c.b / 256) - 32768;
					Mapimg->setColor(i, j, ofMap(ele, minV, maxV, 0, 255));
				}
			}
			Mapimg->update();
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}