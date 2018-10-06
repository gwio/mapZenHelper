#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofBackground(0, 0, 0);
	ofSetFrameRate(60);

	//latitude, longitude, zoomfactor (1-15 for mapzen?), image size, type ("Terrarium", "Normal") -image size always a factor of 256
	//allocates ofImage, updates maptiles while loading
    
    //prepare mapZen object to load 12 images
    mapZen.prepareContainer(12);
    
	mapZen.createMapImage(49.829900, 6.731873, 12, 256 * 2, 256 * 2, "Normal", 0);
	
	for (int i = 0; i < 11; i++) {
		mapZen.createMapImage(ofRandom(-60.0, 60.0), ofRandom(-180.0, 180.0), ofRandom(8, 12), 256 * 2, 256 * 2, "Normal", i+1);
	}

	/*Terrarium format PNG tiles contain raw elevation data in meters,
	in Web Mercator projection (EPSG:3857).
	All values are positive with a 32,768 offset, split into the red, green, and blue channels, with 16 bits of integer and 8 bits of fraction.

	To decode:
	(red * 256 + green + blue / 256) - 32768

	------

	Normal format PNG tiles are processed elevation data with the the red, green, and blue values corresponding to the direction the pixel “surface” is facing (its XYZ vector),
	in Web Mercator projection (EPSG:3857). The alpha channel contains quantized elevation data with values suitable for common hypsometric tint ranges.

	red = x vector
	green = y vector
	blue = z vector
	alpha = quantized elevation data
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

	ofDrawBitmapString(ofToString(ofGetFrameRate()), 20, 20);
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
