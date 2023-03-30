#include <iostream>

using namespace std;

class Snake
{
private:
	int snake_x, snake_y, board_length, board_height;
	char board[12][12];
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

		for (int i = 0; i < board_height; i++)
		{
			for (int j = 0; j < board_length; j++)
			{
				if(i == 0 || i == 11)
				{
					board[i][j] = 'X';
				}
				else if(j == 0 || j == 11)
				{
					board[i][j] = 'X';
				}
				else
				{
					board[i][j] = '_';
				}
			}
		}
		board[snake_x][snake_y] = 'O';
	}
	~Snake()
	{

	}

	void displayBoard();
	void play();
	void getInput();
	void updatePlayer();
	void updateBoard();

};

int main(){

	Snake my_snake;
	my_snake.play();
	return 0;
}

void Snake::displayBoard()
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			cout << board[i][j];
		}
		cout << endl;
	}		
}

void Snake::play()
{
	while(exit != true)
	{
		updatePlayer();
		updateBoard();
		displayBoard();
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

void Snake::updateBoard()
{
	for (int i = 0; i < board_height; i++)
	{
		for (int j = 0; j < board_length; j++)
		{
			if(i == 0 || i == 11)
			{
				board[i][j] = 'X';
			}
			else if(j == 0 || j == 11)
			{
				board[i][j] = 'X';
			}
			else
			{
				board[i][j] = '_';
			}
		}
	}
	board[snake_x][snake_y] = 'O';	
}