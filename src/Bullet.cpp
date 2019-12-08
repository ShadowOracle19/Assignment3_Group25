#include "Bullet.h"
#include "Game.h"
#include "ship.h"
Bullet::Bullet() :
	m_currentTile(NULL)
{

	TheTextureManager::Instance()->load("../Assets/textures/bullet.png",
		"bullet", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("bullet");
	setWidth(size.x);
	setHeight(size.y);

	setPosition(glm::vec2(300.0f, 300.0f));
	setVelocity(glm::vec2(0.0f, 5.0f));

	setIsColliding(false);
	setAcceleration(glm::vec2(100.0f, 100.0f));
	setType(GameObjectType::BALL);

}

Bullet::~Bullet()
{
}

void Bullet::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("bullet", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void Bullet::update()
{
	move();
	m_checkBounds();
}

void Bullet::clean()
{
	delete m_currentTile;
	m_currentTile = NULL;
}

void Bullet::move()
{

	glm::vec2 newPosition = getPosition() + getVelocity();
	setPosition(newPosition);
}

void Bullet::reset()
{

}


Tile* Bullet::getTile()
{
	return m_currentTile;
}

void Bullet::setTile(Tile* newTile)
{
	m_currentTile = newTile;
}

bool Bullet::getHit()
{
	return m_hit;
}

void Bullet::setHit(bool newHit)
{
	m_hit = newHit;
}

void Bullet::m_checkBounds()
{
	if (getPosition().y > Config::SCREEN_HEIGHT)
	{
		setPosition(glm::vec2(Util::RandomRange(getWidth() * 0.5, 800.0f - getWidth()), 0.0f));
		m_hit = false;

	}

}






