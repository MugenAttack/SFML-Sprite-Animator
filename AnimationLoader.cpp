#include "stdafx.h"
#include "AnimationLoader.h"



AnimationLoader::AnimationLoader(void)
{
	ReaderFunc["Name"] = &AnimationLoader::Name;
	ReaderFunc["SheetId"] = &AnimationLoader::SheetId;
	ReaderFunc["FPS"] = &AnimationLoader::FPS;
	ReaderFunc["Loop"] = &AnimationLoader::Loop;
	ReaderFunc["Frame"] = &AnimationLoader::Frame;
	//ReaderFunc["Sheet"] = AnimationLoader::Sheet;
}


AnimationLoader::~AnimationLoader(void)
{

}

void AnimationLoader::ReadFile(string FileName, Animator &animator)
{
	ifstream aFile;
	aFile.open(FileName);
	Animation* Constructing = new Animation();
	string line;
	vector<string> info;
	int i = 0;
	
	do{
		
		getline(aFile,line);
		removeSpaces(line);
		split(line, ":", info);
		if (line != "" )
		{
			if (info[0] == "Sheet")
				Sheet(info[1],animator);
			else if (line == "AnimationStart")
			{
				delete Constructing;
				Constructing = new Animation();
			}
			else if (line == "AnimationEnd")
			{
				animator.addAnimation(*Constructing);
			}
			else
			{
				EventFunc f = ReaderFunc[info[0]];
				(this->*f)(info[1],*Constructing);
			}
			info.clear();
		}
		i++;
		
		
	}while(!aFile.eof());
	aFile.close();
	delete Constructing;
}

void AnimationLoader::split(const string& s, const string delim, vector<string>& ss)
{
	size_t start = 0;
	size_t end = 0;

	while (start != string::npos && end != string::npos)
	{
		start = s.find_first_not_of(delim, end);

		if (start != string::npos)
		{

			end = s.find_first_of(delim,start);

			if (end != string::npos)
				ss.push_back(s.substr(start,end-start));
			else
				ss.push_back(s.substr(start));


		}


	}

}

void AnimationLoader::Name(string param, Animation& anim)
{
	anim.setName(param);
}

void AnimationLoader::FPS(string param, Animation& anim)
{
	anim.setFPS(atof(param.c_str()));
}

void AnimationLoader::SheetId(string param, Animation& anim)
{
	anim.setTexture(atoi(param.c_str()));
}

void AnimationLoader::Frame(string param, Animation& anim)
{
	vector<string> separated;
	split(param,",",separated);
	anim.AddFrame(sf::IntRect(atoi(separated[0].c_str()),atoi(separated[1].c_str()),atoi(separated[2].c_str()),atoi(separated[3].c_str())),sf::Vector2f(atof(separated[4].c_str()),atof(separated[5].c_str())));
}

void AnimationLoader::Loop(string param, Animation& anim)
{
	anim.setLoop(param == "true");
}

void AnimationLoader::Sheet(string param, Animator& animator)
{
	sf::Texture tex;
	animator.textures.push_back(tex);
	animator.textures.back().loadFromFile(param);
}

void AnimationLoader::removeSpaces(string& param)
{
	param.erase( remove( param.begin(), param.end(), ' ' ), param.end() );

}


