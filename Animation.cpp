#include "stdafx.h"
#include "Animation.h"


Animation::Animation(string pName,float pFPS,  bool pLoop)
{
	FPS = pFPS;
	Name = pName;
	Loop = pLoop;
	
}

Animation::Animation()
{
}

Animation::~Animation()
{
	texRect.clear();
	origin.clear();
}

void Animation::AddFrame(sf::IntRect ptexRect, sf::Vector2f porigin)
{
	texRect.push_back(ptexRect);
	origin.push_back(porigin);
}

void Animation::setTexture(int pTexture)
{
	texture = pTexture;
}

int Animation::getTexture()
{
	return texture;
}

int Animation::getFrameCount()
{
	return texRect.size();
}

sf::IntRect Animation::getFrameRect(int pframe)
{
	return texRect[pframe];
}
sf::Vector2f Animation::getFrameOrigin(int pframe)
{
	return origin[pframe];
}

string Animation::getName()
{
	return Name;
}

float Animation::getFPS()
{
	return FPS;
}

bool Animation::isLooping()
{
	return Loop;
}

void Animation::setFPS(float _FPS)
{
	FPS = _FPS;
}

void Animation::setName(string _Name)
{
	Name = _Name;
}

void Animation::setLoop(bool _Loop)
{
	Loop = _Loop;
}


