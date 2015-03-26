#include "stdafx.h"
#include "Animator.h"


Animator::Animator()
{
	CurrentFrame = 0;
	clock = sf::Time::Zero;
	isPlaying = true;
	lockTAddition = false;
}

Animator::~Animator()
{}

void Animator::addAnimation(Animation& Anim)
{
	Animations[Anim.getName()] = Anim;
	AnimationList.push_back(Anim.getName());
	lockTAddition = true;

}

int Animator::getFrame()
{
	return CurrentFrame;
}

bool Animator::isFrame(int Frame)
{
	return (CurrentFrame == Frame);
}

void Animator::Update(sf::Time deltaTime)
{
	// check to see if non looping animation is over
	if (isPlaying)
	{
		if (endFrame = true && !CurrentAnimation.isLooping())
			setAnimation(Next);
		endFrame = false;
		clock += deltaTime;
		sf::Time FPS = sf::seconds(1.f/CurrentAnimation.getFPS());
		if (clock > FPS)
		{
			frameChange = true;
			CurrentFrame++;
			clock = sf::Time::Zero;
			if (CurrentFrame == CurrentAnimation.getFrameCount())
			{
				CurrentFrame = 0;
				endFrame = true;
			}
			spriteImage->setOrigin(CurrentAnimation.getFrameOrigin(CurrentFrame));
			spriteImage->setTextureRect(CurrentAnimation.getFrameRect(CurrentFrame));
		}
		else
		{endFrame = false;frameChange=false;}
	}
}

void Animator::setAnimation(string name)
{
	CurrentAnimation = Animations[name];
	sf::Texture* P_Texture = &textures[CurrentAnimation.getTexture()];
	spriteImage->setTexture(*P_Texture);
	frameChange = true;
	CurrentFrame = 0;
	clock = sf::Time::Zero;
	spriteImage->setOrigin(CurrentAnimation.getFrameOrigin(CurrentFrame));
	spriteImage->setTextureRect(CurrentAnimation.getFrameRect(CurrentFrame));
}

int Animator::getAnimationCount()
{
	return Animations.size();
}

void Animator::setSprite(sf::Sprite* pSprite)
{
	spriteImage = pSprite;
}

void Animator::play()
{
	isPlaying = true;
}

void Animator::pause()
{
	isPlaying = false;
}

void Animator::reset()
{
	isPlaying = true;
	CurrentFrame = 0;
}

void Animator::stop()
{
	isPlaying = false;
	CurrentFrame = 0;
}

bool Animator::isLastFrame()
{
	return endFrame;
}

string Animator::getAnimationName()
{
	return CurrentAnimation.getName();
}

bool Animator::hasframeChanged()
{
	return frameChange;
}

void Animator::AddTexture(string FileName)
{
	if (!lockTAddition)
	{
		sf::Texture nTex;
		nTex.loadFromFile(FileName);
		textures.push_back(nTex);
	}
}

sf::Texture* Animator::getTexture(int id)
{
	return &textures[id];
}

vector<string> Animator::getAnimationList()
{
	return AnimationList;
}