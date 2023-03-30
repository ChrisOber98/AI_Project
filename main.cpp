#include <iostream>

using namespace std;

class Snake
{
private:
	int snake_x, snake_y, snake_length, board_length, board_height;
	int board[12][12];
	bool up, left, down, right, exit;

public:
	Snake()
	{
		up = false;
		left = false;
		down = false;
		right = false;
		exit = false;

		board_height = 12;
		board_length = 12;

		snake_x = 1;
		snake_y = 1;
		snake_length = 5;

		for (int i = 0; i < board_height; i++)
		{
			for (int j = 0; j < board_length; j++)
			{
				if(i == 0 || i == 11)
				{
					board[i][j] = -1;
				}
				else if(j == 0 || j == 11)
				{
					board[i][j] = -1;
				}
				else
				{
					board[i][j] = 0;
				}
			}
		}
		board[snake_x][snake_y] = snake_length;
	}
	~Snake()
	{

	}

	void displayBoard(int length);
	void play();
	void getInput();
	void updatePlayer();
	void updateBoard(int length);

};

int main(){

	Snake my_snake;
	my_snake.play();
	return 0;
}

void Snake::displayBoard(int length)
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (board[i][j] == -1){
				cout << 'X';
			} else if(board[i][j] == length){
				cout << 'e';
			} else if(board[i][j] > 0){
				cout << 'o';
			} else cout << '_';
		}
		cout << endl;
	}		
}

void Snake::play()
{
	while(exit != true)
	{
		updatePlayer();
		updateBoard(snake_length);
		displayBoard(snake_length);
		getInput();
	}
}

void Snake::getInput()
{
	char input;

	up = false;
	left = false;
	down = false;
	right = false;
	exit = false;

	cout << "WASD or x to exit: ";
	cin >> input;

	if (input == 'w')
	{
		up = true;
	}
	else if (input == 'a')
	{
		left = true;
	}
	else if (input == 's')
	{
		down = true;
	}
	else if (input == 'd')
	{
		right = true;
	}	
	else if (input == 'x')
	{
		exit = true;
	}
	else
	{
		cout << "invalid input\n";
	}
}

void Snake::updatePlayer()
{
	if (up == true)
	{
		snake_x -= 1;
		if(snake_x == 0)
			snake_x += 1;
	}
	else if (left == true)
	{
		snake_y -= 1;
		if(snake_y == 0)
			snake_y += 1;
	}
	else if (down == true)
	{
		snake_x += 1;
		if(snake_x == 11)
			snake_x -= 1;
	}
	else if (right == true)
	{
		snake_y += 1;
		if(snake_y == 11)
			snake_y -= 1;

	}	
	else
	{
		
	}
}

void Snake::updateBoard(int length)
{
	for (int i = 1; i < board_height-1; i++)
	{
		for (int j = 1; j < board_length-1; j++)
		{
			if(board[i][j] > 0)
			{
				board[i][j]--;
			}
		}
	}
	board[snake_x][snake_y] = length;	
}