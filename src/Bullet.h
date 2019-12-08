#pragma once
#ifndef __Bullet__
#define __Bullet__


#include "DisplayObject.h"
#include "TextureManager.h"
#include "SoundManager.h"
#include "Tile.h"
#include "Scene.h"
class Bullet :
	public DisplayObject
{
public:
	Bullet();
	~Bullet();

	virtual void draw() override;

	virtual void update() override;

	virtual void clean() override;
	void move();
	void reset();


	// pathfinding behaviours
	Tile* getTile();
	void setTile(Tile* newTile);

	void m_checkBounds();

	bool getHit();
	void setHit(bool newHit);

private:
	bool m_hit = false; 
	Tile* m_currentTile;

};


#endif /* defined (__Bullet__) */
