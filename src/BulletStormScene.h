#pragma once
#ifndef __BULLET_SCENE__
#define __BULLET_SCENE__

#include "Scene.h"
#include "Label.h"
#include "Ship.h"
#include "MoveState.h"
#include "Planet.h"
#include "Mine.h"
#include "Bullet.h"
#include "CollisionManager.h"
#include "SoundManager.h"

class BulletStormScene : public Scene
{
public:
	BulletStormScene();
	~BulletStormScene();

	// Inherited via Scene
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;

private:
	/*Label* m_pStartLabel;
	Label* m_pInstructionsLabel;*/

	// Ship Stuff
	Ship* m_pShip;
	MoveState m_moveState;
	glm::vec2 m_speedFactor;

	//bullet
	Bullet* m_pBullet[10];

	glm::vec2 m_mousePosition;
	glm::vec2 m_prevMousePosition = glm::vec2(100.0f, 100.0f);

	glm::vec2 diff;
	// ImGui utility functions
	void m_ImGuiKeyMap();
	void m_ImGuiSetStyle();
	void m_updateUI();

	// ImGui menu variables
	bool m_exitApp = false;
	bool m_displayAbout = false;
	bool m_displayUI = true;

	// Physics Variables
	float m_gravity = 9.8f;
	int m_PPM = 10; // pixels per meter
	glm::vec2 m_position = glm::vec2(0.0f, 0.0f);
	glm::vec2 m_velocity = glm::vec2(0.0f, 0.0f);
	glm::vec2 m_acceleration = glm::vec2(0.0f, 0.0f);

	// Physics functions
	//void m_move();
};

#endif /* defined (__BULLET_SCENE__) */