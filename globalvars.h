
#ifndef GLOBALVARS_H_
#define GLOBALVARS_H_

#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <Windows.h>
#include <SDL.h>
#include <SDL_ttf.h>

//const int size_array = 4;
extern int width, height;
extern int cards[4][4];
extern int score;
extern int highScore;
extern bool quit;
extern bool win;


//TEXT-FONT-SIZE
const int FONT_SIZE_TINY = 15;
const int FONT_SIZE_SMALL = 25;
const int FONT_SIZE_NORMAL = 35;
const int FONT_SIZE_MEDIUM = 45;
const int FONT_SIZE_BIG = 50;
const int FONT_SIZE_GREAT = 70;

//COLOR
const SDL_Color COLOR_TEXT = {190, 190, 190};
const SDL_Color COLOR_LOGO = {126, 120, 114};
const SDL_Color COLOR_NUM_1 = {119,110,101};
const SDL_Color COLOR_NUM_2 = {249, 246, 242};
const SDL_Color COLOR_0 = {205,193,180};
const SDL_Color COLOR_2 = {168, 208, 216};
const SDL_Color COLOR_4 = {232, 186, 189};
const SDL_Color COLOR_8 = { 243, 223, 126};
const SDL_Color COLOR_16 = {205, 179, 139};
const SDL_Color COLOR_32 = {246, 124, 95};
const SDL_Color COLOR_64 = {144, 238,144};
const SDL_Color COLOR_128 = {240,128,128};
const SDL_Color COLOR_256 = {238, 210, 238};
const SDL_Color COLOR_512 = {237, 200, 80};
const SDL_Color COLOR_1024 = {237, 197, 63};
const SDL_Color COLOR_2048 = {237, 194, 46};

#endif GLOBALVARS_H_
