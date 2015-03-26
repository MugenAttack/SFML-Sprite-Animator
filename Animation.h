#pragma once
#include "SFML\Graphics.hpp"

using namespace std;
class Animation
{
public:
	Animation(string, float,  bool);
	Animation();
	~Animation();
	void AddFrame(sf::IntRect,sf::Vector2f);
	void setTexture(int);
	int getTexture();
	int getFrameCount();
	sf::IntRect getFrameRect(int);
	sf::Vector2f getFrameOrigin(int);
	string getName();
	void setName(string);
	void setLoop(bool);
	void setFPS(float);
	float getFPS();
	bool isLooping();

private:
	vector<sf::IntRect> texRect;
	vector<sf::Vector2f> origin;
	int texture;
	float FPS;
	string Name;
	bool Loop;
};

