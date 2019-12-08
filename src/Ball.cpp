#include "Ball.h"
#include "Game.h"
Ball::Ball() : 
	m_currentTile(NULL)
{
	
	TheTextureManager::Instance()->load("../Assets/textures/pokeball.png",
		"pokeball", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("pokeball");
	setWidth(size.x);
	setHeight(size.y);

	setPosition(glm::vec2(300.0f, 300.0f));
	setVelocity(glm::vec2(10.0f, 10.0f));

	setIsColliding(false);
	setAcceleration(glm::vec2(100.0f,100.0f));
	setType(GameObjectType::BALL);

}

Ball::~Ball()
{
}

void Ball::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("pokeball", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void Ball::update()
{
	move();
	m_checkBounds();
}

void Ball::clean()
{
	delete m_currentTile;
	m_currentTile = NULL;
}

void Ball::move()
{
	setVelocity(getVelocity() * 0.99f);
	glm::vec2 newPosition = getPosition() + getVelocity();
	setPosition(newPosition);
}


Tile* Ball::getTile()
{
	return m_currentTile;
}

void Ball::setTile(Tile* newTile)
{
	m_currentTile = newTile;
}


void Ball::m_checkBounds()
{
	
	if (getPosition().x > Config::SCREEN_WIDTH)
	{
		setPosition(glm::vec2(800.0f, getPosition().y));
		setVelocity(glm::vec2((getVelocity().x * -0.9f), getVelocity().y));
	}

	if (getPosition().x < 0)
	{
		setPosition(glm::vec2(0.0f, getPosition().y));
		setVelocity(glm::vec2((getVelocity().x * -0.9f) , getVelocity().y));
	}

	if (getPosition().y > Config::SCREEN_HEIGHT)
	{
		setPosition(glm::vec2(getPosition().x, 600.0f));
		setVelocity(glm::vec2((getVelocity().x), getVelocity().y * -0.9f));
		/*if (getVelocity().x == 0)
		{
			setVelocity();
		}*/
		
	}

	if (getPosition().y < 0)
	{
		setPosition(glm::vec2(getPosition().x, 0.0f));
		setVelocity(glm::vec2((getVelocity().x), getVelocity().y * -0.9f));
		
	}

	

}





