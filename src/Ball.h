#pragma once
#ifndef __Ball__
#define __Ball__


#include "DisplayObject.h"
#include "TextureManager.h"
#include "SoundManager.h"
#include "Tile.h"
#include "Scene.h"
class Ball :
	public DisplayObject
{
public:
	Ball();
	~Ball();

	virtual void draw() override;

	virtual void update() override;

	virtual void clean() override;
	void move();

	
	// pathfinding behaviours
	Tile* getTile();
	void setTile(Tile* newTile);

	void m_checkBounds();
	

private:

	Tile* m_currentTile;

};


#endif /* defined (__Ball__) */
