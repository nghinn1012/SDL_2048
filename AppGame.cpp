
#include "AppGame.h"
#include "draw.h"
#include "globalvars.h"

Application::Application()
{
	//tạo random 2 ô để bắt đầu game
	CreateRandomCard(); //tạo ô thứ nhất

	CreateRandomCard(); //tạo ô thứ 2
}

Application::~Application()
{

}

int Application::randomNumber()
{
	int a=rand()%20;
	if (!a) return 4;	//tỉ lệ ra 4: 5%
	else return 2;		//tỉ lệ ra 2: 95%
}

void Application::CreateRandomCard()
{
	int i = rand()%4, j = rand()%4;
	if (cards[i][j]==0){
		int number = randomNumber();
		cards[i][j] = number;
	}
	else{
		CreateRandomCard();
	}
}

bool Application::isFullBoard()
{
    // kiểm tra mảng trống không
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (cards[i][j] == 0)
			{
				return false;
			}
		}
	}
	return true;
}

bool Application::isCanMove()
{
    // kiểm tra xem còn có thể thao tác tiếp không
	for (int i=0; i<3; i++){
		for (int j=0; j<3; j++){
			if (cards[i][j]==cards[i][j+1] || cards[i][j]==cards[i+1][j]){
				return true;
			}
		}
	}
	return false;
}

bool Application::isLose()
{
    // kiểm tra thua
	if ( isFullBoard() == true && isCanMove() == false){
		return true; // thua
	}
	return false;
}


void Application::handleInput()
{
    // kiểm tra hành động và thực hiện hàm tương ứng
	SDL_Event e;
	SDL_WaitEvent(&e);
	switch(e.key.keysym.sym){
		case SDLK_UP:
			doUp();
			break;
		case SDLK_DOWN:
			doDown();
			break;
		case SDLK_LEFT:
			doLeft();
			break;
		case SDLK_RIGHT:
			doRight();
			break;
		case SDLK_ESCAPE:
			quit = true;
			break;
		default:
			break;
	}
}

bool Application::doUp()
{
    // hàm xử lý khi bấm lên trên
    bool isDo = false;
    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 3; x++)
        {
            for (int x1 = x + 1; x1 < 4; x1++)
            {
                if (cards[y][x1] > 0)
                {
                    if (cards[y][x] == 0)
                    {
                        cards[y][x] = cards[y][x1];
                        cards[y][x1] = 0;
                        x--;
                        isDo = true;
                    }
                    else if (cards[y][x] == cards[y][x1])
                    {
                        cards[y][x] *= 2;
                        cards[y][x1] = 0;
						score += cards[y][x];
                        isDo = true;
                    }
                    break;
                }
            }
        }
    }
    // nếu đúng tạo thêm một ô ngẫu nhiên
    if(isDo){
        CreateRandomCard();
	}
    return isDo;
}

bool Application::doDown()
{
    // hàm xử lý khi bấm xuống dưới
    bool isDo = false;
    for (int y = 0; y < 4; y++)
    {
        for (int x = 3; x >= 1; x--)
        {
            for (int x1 = x - 1; x1 >= 0; x1--)
            {
                if (cards[y][x1] > 0)
                {
                    if (cards[y][x] == 0)
                    {
                        cards[y][x] = cards[y][x1];
                        cards[y][x1] = 0;
                        x++;
                        isDo = true;
                    }
                    else if (cards[y][x] == cards[y][x1])
                    {
                        cards[y][x] *= 2;
						score += cards[y][x];
                        cards[y][x1] = 0;
                        isDo = true;
                    }
                    break;
                }
            }
        }
    }
    if (isDo)
		CreateRandomCard();
    return isDo;
}

bool Application::doLeft()
{
    // hàm xử lý khi qua trái
    bool isDo = false;
    for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int y1 = y + 1; y1 < 4; y1++)
            {
                if (cards[y1][x] > 0)
                {
                    if (cards[y][x] == 0)
                    {
                        cards[y][x] = cards[y1][x];
                        cards[y1][x] = 0;
                        y--;
                        isDo = true;
                    }
                    else if (cards[y][x] == cards[y1][x])
                    {
                        cards[y][x] *= 2;
						score += cards[y][x];
                        cards[y1][x] = 0;
                        isDo = true;
                    }
                    break;
                }
            }
        }
    }
    if (isDo)
        CreateRandomCard();
    return isDo;
}

bool Application::doRight()
{
    // hàm xử lý khi qua phải
    bool isDo = false;
    for (int x = 0; x < 4; x++)
    {
        //kiểm tra nếu ô bên phải trống thì chuyển ô đó về vị trí của ô bên phải
        for (int y = 3; y >= 1; y--)
        {
            for (int y1 = y - 1; y1 >= 0; y1--)
            {
                if (cards[y1][x] > 0)
                {
                    if (cards[y][x] == 0)
                    {
                        cards[y][x] = cards[y1][x];
                        cards[y1][x] = 0;
                        y++;
                        isDo = true;
                    }
                    // nếu 2 ô giống nhau thì gộp lại
                    else if (cards[y][x] == cards[y1][x])
                    {
                        cards[y][x] *= 2;
						score += cards[y][x];
                        cards[y1][x] = 0;
                        isDo = true;
                    }
                    break;
                }
            }
        }
    }
    if (isDo)
        CreateRandomCard();
    return isDo;
}
