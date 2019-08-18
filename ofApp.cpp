#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);
	ofSetLineWidth(3);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	auto size = 50;
	for (int x = -500; x <= 500; x += size) {

		for (int y = -500; y <= 500; y += size) {

			auto height = ofMap(ofNoise(x * 0.005, y * 0.005, ofGetFrameNum() * 0.01), 0, 1, 50, 500);
			
			for (int z = 0; z <= height; z += size) {

				ofColor fill_color(ofMap(z, 0, 500, 39, 239));

				ofFill();
				ofSetColor(fill_color);
				ofDrawBox(glm::vec3(x, y, z), size - 1);

				ofNoFill();
				ofSetColor(39);
				ofDrawBox(glm::vec3(x, y, z), size);
			}
		}

	}
	

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}