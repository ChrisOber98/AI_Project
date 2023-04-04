#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

class Snake
{
private:
	int snake_x, snake_y, snake_length, prevInput, board_length, board_height;
	int apple_x, apple_y;
	int board[12][12];
	bool up, left, down, right, exit, eaten;


public:
	Snake()
	{
		up = false;
		left = false;
		down = false;
		right = false;
		exit = false;
		eaten = false;
		prevInput = 2;

		board_height = 12;
		board_length = 12;

		snake_x = 1;
		snake_y = 1;

		apple_x = 5;
		apple_y = 5;

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
		board[apple_x][apple_y] = 20;
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

	// instructions
	cout << "To play use 'wasd' to move." << endl;
	cout << "To exit use 'x'." << endl;
	cout << "Press enter to start." << endl;
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
			if (board[i][j] == -1){
				cout << 'X';
			} else if(board[i][j] == snake_length){
				cout << 'e';
			} else if(board[i][j] > 0 && board[i][j] != 20){
				cout << 'o';
			} else if (board[i][j] == 0){
				cout << '_';
			} else if(board[i][j] == 20){
				cout << 'a';
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
		updateBoard();
		displayBoard();

		// sleep and clear the input after each display
		// avoids multiple moves in one turn
		std::this_thread::sleep_for(std::chrono::milliseconds(250));
		fseek(stdin,0,SEEK_END);

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

	// Set terminal to raw mode 
	system("stty raw"); 
	// Wait for single character 
	input = getchar(); 
	// Reset terminal to normal "cooked" mode 
	system("stty cooked"); 

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
	else {
		switch(prevInput){
			case 1:
				up = true;
				break;
			case 2:
				right = true;
				break;
			case 3:
				down = true;
				break;
			case 4:
				left = true;
				break;
		}
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
}

void Snake::updateBoard()
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
	if(up){
		prevInput = 1;
	} else if(right){
		prevInput = 2;
	} else if(down){
		prevInput = 3;
	} else if(left){
		prevInput = 4;
	}

	if(eaten)
	{

	}
	board[apple_x][apple_y] = 20;
	board[snake_x][snake_y] = snake_length;	
}
