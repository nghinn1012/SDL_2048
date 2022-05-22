
#ifndef DRAW_H_
#define DRAW_H_

#include "globalvars.h"

class Game
{
public:
	Game(const char* title, int width, int height);
	~Game();

	void draw_grid();
	void handleEvent();
	void render();
	void checkBestScore();
	void saveBestScore();
	void info(const char * txt); //result game
	void newGame();
	void close();
	 bool quit;
	 bool win;

private:
	void draw_label(const char * font, const int& size, SDL_Color color, const char * text, int x, int y, SDL_Renderer* renderer);
	void paint_tile(int& i, int& j, const char * text, const int font_size, SDL_Color color_bg, SDL_Color color);
	void updateScore();
	
	SDL_Renderer* renderer;
	SDL_Window* window;
	SDL_Event event;
	SDL_Rect background; //background 410x410
	SDL_Rect newgame; //button new game
	SDL_Rect tile[4][4];
};

#endif DRAW_H_