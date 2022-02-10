#include "ofApp.h"

void ofApp::setup()
{
	m_Game.Setup();
}

void ofApp::update()
{
	m_Game.Update();
}

void ofApp::draw()
{
	m_Game.Draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	m_Game.KeyPressed(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
	m_Game.KeyReleased(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y )
{
	m_Game.MouseMoved(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
	m_Game.MouseDragged(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
	m_Game.MousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
	m_Game.MouseReleased(x, y, button);
}