
#ifndef APPGAME_H_
#define APPGAME_H_H

#include "draw.h"

class Application
{
public:
	Application();
	
	~Application();
	
	bool isLose();

	void handleInput();

	bool isCanMove();

private:

	int randomNumber();

	void CreateRandomCard();

	bool isFullBoard();

	bool doDown();

	bool doUp();

	bool doRight();

	bool doLeft();
};

#endif APPGAME_H_