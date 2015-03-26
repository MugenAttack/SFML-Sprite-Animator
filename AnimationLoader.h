#pragma once
#include "Animation.h"
#include "Animator.h"
#include <fstream>
#include <iostream>
class AnimationLoader
{

public:
	typedef void (AnimationLoader::*EventFunc)(string,Animation&);
	AnimationLoader(void);
	~AnimationLoader(void);
	void ReadFile(string, Animator&);
	void Name(string,Animation&);
	void SheetId(string,Animation&);
	void FPS(string,Animation&);
	void Loop(string,Animation&);
	void Frame(string,Animation&);
	void Sheet(string,Animator&);
	void split(const string&, const string ,vector<string>&);
	void removeSpaces(string&);

private:
	std::map<string,EventFunc> ReaderFunc;
	

};

