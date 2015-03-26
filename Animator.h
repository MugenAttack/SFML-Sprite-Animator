#pragma once
#include "Animation.h"
#include "SFML\Graphics.hpp"
#include "SFML\System.hpp"
class Animator
{
	
public:
	Animator();
	~Animator();
	void setSprite(sf::Sprite* pSprite);
	void addAnimation(Animation&);
	void setAnimation(string);
	void play();
	void reset();
	void pause();
	void setFrame();
	void stop();
	int getFrame();
	bool isFrame(int);
	bool isLastFrame();
	string getAnimationName();
	void Update(sf::Time);
	int getAnimationCount();
	void setNext(string);
	sf::Sprite* spriteImage;
	bool hasframeChanged();
	Animation getAnimationData(string);
    vector<sf::Texture> textures;
	void AddTexture(string);
	sf::Texture* getTexture(int);
	vector<string> getAnimationList();

private:
	
	std::map<std::string,Animation> Animations;
	vector<string> AnimationList;
	int CurrentFrame;
	Animation CurrentAnimation;
	string Next; //if a non looping animation is in play go to this animation after current is over
	sf::Time clock;
	bool frameChange;
	bool isPlaying;
	bool endFrame;
	bool lockTAddition;
};

