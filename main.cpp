#include <iostream>

using namespace std;

int main(){

	char board[12][12];

	for (int i = 0; i < 12; i++)
	{

		for(int j = 0; j < 12; j++)
		{
			if (i == 0 || i == 11)
			{
				board[i][j] = 'X';
			}
			if (j == 0 || j == 11)
			{
				board[i][j] = 'X';
			}
			board[i][j] = '_';
		}
	}

	for (int i = 0; i < 12; i++)
	{

		for(int j = 0; j < 12; j++)
		{
			cout << board[i][j];
		}
		cout << endl;
	}

	return 0;
}