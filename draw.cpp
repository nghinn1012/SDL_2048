
#include "draw.h"
#include "AppGame.h"

Game::Game(const char* title, int width, int height)
{
	TTF_Init();
    SDL_Init(SDL_INIT_VIDEO);
    // tạo cửa sổ
	window = SDL_CreateWindow("2048",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	// tạo rederer để vẽ lên window
	renderer = SDL_CreateRenderer(window, -1, 0);
}

Game::~Game()
{

}

void Game::draw_label(const char * font, const int& size, SDL_Color color, const char * text, int x, int y, SDL_Renderer* renderer ){
	// font chữ
	TTF_Font * fonts = TTF_OpenFont(font, size);
	int texW = 20;
	int texH = 20;
	// tạo bảng gồm các ô trên texture
	SDL_Surface * surface = TTF_RenderText_Blended(fonts, text, color);
	SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
	SDL_Rect dstrect = { x, y, texW, texH };
	SDL_RenderCopy(renderer, texture, NULL, &dstrect);
	// giải phóng bộ nhớ
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
	TTF_CloseFont(fonts);
}

void Game::draw_grid(){
	int top = 200, left = 50, width_bg = 410;

	// màu cho bg các ô
	SDL_SetRenderDrawColor(renderer,245,245,220,250);
	SDL_RenderClear(renderer);

	// vẽ phần điểm và điểm cao nhất

	draw_label("fonts.ttf", FONT_SIZE_TINY, COLOR_TEXT , "Score:", 300, 10, renderer);
	draw_label("fonts.ttf", FONT_SIZE_TINY, COLOR_TEXT, "Best:", 300, 50, renderer);
	char buf[9];
	_itoa_s(score, buf, 10);
	draw_label("fonts.ttf", FONT_SIZE_SMALL, COLOR_TEXT, buf, 360, 5, renderer);

	char buffer[9];
	_itoa_s(highScore, buffer, 10);
	draw_label("fonts.ttf", FONT_SIZE_SMALL, COLOR_TEXT, buffer, 360, 45, renderer);

	// màu bg phần điểm
	SDL_SetRenderDrawColor(renderer, 139 ,137, 137,255);

	background.x = left;
	background.y = top;
	background.w = width_bg;
	background.h = width_bg;
	SDL_RenderFillRect(renderer, &background);

	// tạo nút new game
	SDL_SetRenderDrawColor(renderer,143,122,102, 255);

	newgame.x = 300;
	newgame.y = 120;
	newgame.w = 150;
	newgame.h = 40;

	SDL_RenderFillRect(renderer, &newgame);
	draw_label("fonts.ttf", FONT_SIZE_SMALL, COLOR_NUM_2, "New game", newgame.x + 10, newgame.y + 5, renderer);


	// thêm logo game 2048
	draw_label("fonts.ttf", FONT_SIZE_GREAT, COLOR_LOGO, "2048", 40, 40, renderer);

	// vẽ các ô
	int _x = left+10, _y = top+10;

	int _Step = 100, _w = 90, _h = 90; //tile 90x90

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			tile[i][j].x = _x + j*_Step;
			tile[i][j].y = _y + i*_Step;
			tile[i][j].w = _w;
			tile[i][j].h = _h;

			paint_tile(i, j, "", FONT_SIZE_TINY, COLOR_0, COLOR_NUM_1);
		}
	}

	// render
	SDL_RenderPresent(renderer);
}


void Game::updateScore()
{
	SDL_Rect rect = {360,0,100,100};
	SDL_SetRenderDrawColor(renderer,245,245,220,250);
	SDL_RenderFillRect(renderer, &rect);

	// cập nhật điểm
	char buf[9];
	_itoa_s(score, buf, 10);
	draw_label("fonts.ttf", FONT_SIZE_SMALL, COLOR_TEXT, buf, 360, 5, renderer);

	checkBestScore();
	char buffer[9];
	_itoa_s(highScore, buffer, 10);
	draw_label("fonts.ttf", FONT_SIZE_SMALL, COLOR_TEXT, buffer, 360, 45, renderer);
}

void Game::paint_tile(int& i, int& j, const char * text, int font_size, SDL_Color color_bg, SDL_Color color){
	SDL_SetRenderDrawColor(renderer,color_bg.r, color_bg.g, color_bg.b,255);
	SDL_RenderFillRect(renderer, &tile[i][j]);
	TTF_Font * fonts = TTF_OpenFont("fonts.ttf", font_size);
	SDL_Surface * surface = TTF_RenderText_Blended(fonts, text, color);
	SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_Rect srcRect;
	SDL_Rect desRect;
	TTF_SizeText(fonts, text, &srcRect.w, &srcRect.h);

	srcRect.x = 0;
	srcRect.y =  0;
	int leng_num = strlen(text);
	int __left = 0;
	int __top = 0;
	switch(leng_num)
	{
	 case 1:
		 __left = 30;
		 __top = 15;
		 break;
	 case 2:
		 __left = 15;
		 __top = 15;
		 break;
	 case 3:
		 __left = 5;
		 __top = 15;
		 break;
	 case 4:
		 __left = 3;
		 __top = 24;
		 break;
	 default:
		 __left = 0;
		 break;
	}
	desRect.x = tile[i][j].x+__left;
	desRect.y = tile[i][j].y+__top;

	desRect.w = srcRect.w;
	desRect.h = srcRect.h;
	SDL_QueryTexture(texture, NULL, NULL, &desRect.w, &desRect.h);
	SDL_RenderCopy(renderer, texture, &srcRect, &desRect);

	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
	TTF_CloseFont(fonts);
	SDL_RenderPresent(renderer);
}

void Game::render()
{
	Game::updateScore();
	for (int i=0; i<4; i++){
		for (int j=0; j<4; j++){
			switch(cards[i][j])
			{
			case 2:
				paint_tile(j, i, "2", FONT_SIZE_BIG, COLOR_2, COLOR_NUM_1);
				break;
			case 4:
				paint_tile(j, i, "4", FONT_SIZE_BIG, COLOR_4, COLOR_NUM_1);
				break;
			case 8:
				paint_tile(j, i, "8", FONT_SIZE_BIG, COLOR_8, COLOR_NUM_2);
				break;
			case 16:
				paint_tile(j, i, "16", FONT_SIZE_BIG, COLOR_16, COLOR_NUM_2);
				break;
			case 32:
				paint_tile(j, i, "32", FONT_SIZE_BIG, COLOR_32, COLOR_NUM_2);
				break;
			case 64:
				paint_tile(j, i, "64", FONT_SIZE_BIG, COLOR_64, COLOR_NUM_2);
				break;
			case 128:
				paint_tile(j, i, "128", FONT_SIZE_MEDIUM, COLOR_128, COLOR_NUM_2);
				break;
			case 256:
				paint_tile(j, i, "256", FONT_SIZE_MEDIUM, COLOR_256, COLOR_NUM_2);
				break;
			case 512:
				paint_tile(j, i, "512", FONT_SIZE_MEDIUM, COLOR_512, COLOR_NUM_2);
				break;
			case 1024:
				paint_tile(j, i, "1024", FONT_SIZE_NORMAL, COLOR_1024, COLOR_NUM_2);
				break;
			case 2048:
				paint_tile(j, i, "2048", FONT_SIZE_NORMAL, COLOR_2048, COLOR_NUM_2);
				win = true;
				break;
			default:
				paint_tile(j, i, "", FONT_SIZE_TINY, COLOR_0, COLOR_NUM_1);
				break;
			}
		}
	}
}

void Game::handleEvent()
{
	//Event
	SDL_WaitEvent(&event);
		switch (event.type)
			{
			case SDL_QUIT:
				Game::quit = true;
				break;

			case SDL_MOUSEBUTTONDOWN:
				if (event.button.button==SDL_BUTTON_LEFT){
							int X=event.button.x;
							int Y=event.button.y;
							if (X>newgame.x && X < newgame.x + newgame.w && Y>newgame.y && Y < newgame.y + newgame.h){
								Game::newGame();
							}
				}
				break;
			case SDL_MOUSEMOTION:
				int mouseX=event.motion.x;
				int mouseY=event.motion.y;
				if (mouseX>newgame.x && mouseX < newgame.x + newgame.w && mouseY>newgame.y && mouseY < newgame.y + newgame.h){
					SDL_Cursor* cursor;
					cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);
					SDL_SetCursor(cursor);
				}
				else{
					SDL_Cursor* cursor;
					cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
					SDL_SetCursor(cursor);
				}
				break;
		}
}

void Game::checkBestScore()
{
	std::fstream f;

	//đọc file
	f.open("score.txt", std::ios::in);

	if(f.is_open())
	{
		f >> highScore;
		f.close();
	}
	else
		std::cout << "can't open file";

}

void Game::saveBestScore()
{
	std::fstream f;
	if (score>highScore)
	{
		//mở file ghi điểm cao
		f.open("score.txt", std::ios::out);
		f << score;
		f.close();
	}
}

void Game::newGame()
{
	// làm mới
	score = 0;
	win = false;
	for (int i = 0; i < 4; i++)
	{
		for(int j= 0; j < 4; j++)
		{
			cards[i][j] = 0;
		}
	}
	draw_grid();
	Application* a;
	a = new Application();
}

void Game::info(const char * txt)
{
	TTF_Font * fonts = TTF_OpenFont("fonts.ttf", FONT_SIZE_GREAT);
	int texW = 20;
	int texH = 20;
	SDL_Surface * surface = TTF_RenderText_Blended(fonts, txt, COLOR_NUM_1);
	SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
	SDL_Rect dstrect = { 100, 350, texW, texH };
	SDL_RenderCopy(renderer, texture, NULL, &dstrect);
	// giải phóng
	SDL_RenderPresent(renderer);
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
	TTF_CloseFont(fonts);
}

void Game::close()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TTF_Quit();
	SDL_Quit();
}
