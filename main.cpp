#include <iostream>
#include <chrono>
#include <thread>
#include <random>

using namespace std;

class Snake
{
private:
	int snake_x, snake_y, snake_length, prevInput, board_length, board_height;
	int apple_x, apple_y;
	int points;
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

		points = 0;

		snake_length = 3;

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
		board[apple_x][apple_y] = -10;
	}
	~Snake()
	{

	}

	void displayBoard();
	void play();
	void getInput();
	void updatePlayer();
	void updateBoard();
	void calc_m_board();
	void displayMBoard();

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
	cout << endl;
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (board[i][j] == -1){
				cout << 'X';
			} else if(board[i][j] == snake_length){
				cout << 'e';
			} else if(board[i][j] > 0){
				cout << 'o';
			} else if (board[i][j] == 0){
				cout << '_';
			} else if(board[i][j] == -10){
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
		calc_m_board();
		displayMBoard();

		// sleep and clear the input after each display
		// avoids multiple moves in one turn
		std::this_thread::sleep_for(std::chrono::milliseconds(250));
		fseek(stdin,0,SEEK_END);

<<<<<<< HEAD
		//getInput();
		exit = true;
=======
		if(!exit){
			getInput();
		}
>>>>>>> d7306acc63ef019e1fcbce569a77200dcfea45de
	}
	cout << "Points scored: " << points << endl;
}

void Snake::getInput()
{
	char input;

	up = false;
	left = false;
	down = false;
	right = false;
	//exit = false;

	// Set terminal to raw mode 
	system("stty raw"); 
	// Wait for single character 
	input = getchar(); 
	// Reset terminal to normal "cooked" mode 
	system("stty cooked"); 

	if (input == 'w')
	{
		up = true;
		if(board[snake_x - 1][snake_y] > 1 || board[snake_x - 1][snake_y] == -1){
			exit = true;
		}
	}
	else if (input == 'a')
	{
		left = true;
		if(board[snake_x][snake_y - 1] > 1 || board[snake_x][snake_y - 1] == -1){
			exit = true;
		}
	}
	else if (input == 's')
	{
		down = true;
		if(board[snake_x + 1][snake_y] > 1 || board[snake_x + 1][snake_y] == -1){
			exit = true;
		}
	}
	else if (input == 'd')
	{
		right = true;
		if(board[snake_x][snake_y + 1] > 1 || board[snake_x][snake_y + 1] == -1){
			exit = true;
		}
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
		// move the snake
		snake_x -= 1;
		// make sure we're not going out of bounds
		if(snake_x == 0){
			snake_x += 1;
		}
	}
	else if (left == true)
	{
		snake_y -= 1;
		if(snake_y == 0){
			snake_y += 1;
		}
	}
	else if (down == true)
	{
		snake_x += 1;
		if(snake_x == 11){
			snake_x -= 1;
		}
	}
	else if (right == true)
	{
		snake_y += 1;
		if(snake_y == 11){
			snake_y -= 1;
		}
	}

	// record if we are eating an apple
	if(snake_x == apple_x && snake_y == apple_y){
		eaten = true;
		points++;
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
		snake_length++;
		eaten = false;
		// increment all snake body
		for (int i = 1; i < board_height-1; i++)
		{
			for (int j = 1; j < board_length-1; j++)
			{
				if(board[i][j] > 0)
				{
					board[i][j]++;
				}
			}
		}

		//generate a new apple
		int randX;
		int randY;
		bool collision = true;
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> distr(1, 10);

		// make sure the apple appears on an empty spot
		do{
			randX = distr(gen);
			randY = distr(gen);
			if(board[randX][randY] == 0){
				apple_x = randX;
				apple_y = randY;
				board[apple_x][apple_y] = -10;
				collision = false;
			}
		}while(collision);
	}
	board[snake_x][snake_y] = snake_length;	
}

void Snake::calc_m_board()
{
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
				int x_dif = 0;
				int y_dif = 0;

				int man_dist = 0;

				x_dif = apple_x - i;
  				y_dif = apple_y - j;

  				if (x_dif < 0)
  					x_dif = -x_dif;

  				if (y_dif < 0)
  					y_dif = -y_dif;

  				board[i][j] = x_dif + y_dif;
			}
		}
	}
}

void Snake::displayMBoard()
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			cout << board[i][j];
			cout << "\t";
		}
		cout << endl;
	}		
}