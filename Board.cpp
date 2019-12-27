#include "Board.h"

Board::Board()
{
	char temp_squares[] = { '1','2','3','4','5','6','7','8','9' };
	for (int i = 0; i < 9; ++i)
	{
		squares[i] = temp_squares[i];
	}
	current_player_move = "Player 1";
	last_winner = "Noone";
}

void Board::print() const
{
	cout << "TIC-TAC-TOE. Last game has ben won by: " << last_winner << endl << endl;
	cout << "Player 1 -> X" << endl;
	cout << "Player 2 -> O" << endl << endl;

	cout << " " << squares[0] << " : " << squares[1] << " : " << squares[2] << " " << endl;
	cout << "---:---:---" << endl;
	cout << " " << squares[3] << " : " << squares[4] << " : " << squares[5] << " " << endl;
	cout << "---:---:---" << endl;
	cout << " " << squares[6] << " : " << squares[7] << " : " << squares[8] << " " << endl << endl;

	cout << current_player_move << "! It's your move! Your choice: ";
}
void Board::next_move()
{
	int choice;
	while (1)
	{
		cin >> choice;
		if (!cin.fail() && choice >= 1 && choice <= 9 && !is_square_used(choice)) break;
		else if (!cin.fail() && choice >= 1 && choice <= 9 && is_square_used(choice))
		{
			cout << endl << "ERROR! This square is already used. Your choice: ";
			cin.clear();
			cin.ignore(256, '\n');
		}
		else
		{
			cout << endl << "ERROR! Bad choice. Your choice: ";
			cin.clear();
			cin.ignore(256, '\n');
		}
	}

	if (current_player_move == "Player 1")
	{
		squares[choice - 1] = 'X';
		current_player_move = "Player 2";
	}
	else
	{
		squares[choice - 1] = 'O';
		current_player_move = "Player 1";
	}
}
void Board::clear()
{
	char temp_squares[] = { '1','2','3','4','5','6','7','8','9' };
	for (int i = 0; i < 9; ++i)
	{
		squares[i] = temp_squares[i];
	}
	current_player_move = "Player 1";
}
bool Board::is_square_used(int _square) const
{
	if (squares[_square - 1] != 'X' && squares[_square - 1] != 'O') return false;
	else return true;
}
char Board::is_line() const
{
	if ((squares[0] == 'X' && squares[1] == 'X' && squares[2] == 'X') || (squares[3] == 'X' && squares[4] == 'X' && squares[5] == 'X') || (squares[6] == 'X' && squares[7] == 'X' && squares[8] == 'X') || (squares[0] == 'X' && squares[3] == 'X' && squares[6] == 'X') || (squares[1] == 'X' && squares[4] == 'X' && squares[7] == 'X') || (squares[2] == 'X' && squares[5] == 'X' && squares[8] == 'X') || (squares[0] == 'X' && squares[4] == 'X' && squares[8] == 'X') || (squares[2] == 'X' && squares[4] == 'X' && squares[6] == 'X')) return 'X';
	if ((squares[0] == 'O' && squares[1] == 'O' && squares[2] == 'O') || (squares[3] == 'O' && squares[4] == 'O' && squares[5] == 'O') || (squares[6] == 'O' && squares[7] == 'O' && squares[8] == 'O') || (squares[0] == 'O' && squares[3] == 'O' && squares[6] == 'O') || (squares[1] == 'O' && squares[4] == 'O' && squares[7] == 'O') || (squares[2] == 'O' && squares[5] == 'O' && squares[8] == 'O') || (squares[0] == 'O' && squares[4] == 'O' && squares[8] == 'O') || (squares[2] == 'O' && squares[4] == 'O' && squares[6] == 'O')) return 'O';
	else return '-';
}
bool Board::start()
{
	system("cls");
	print();
	while (is_line() == '-')
	{
		next_move();
		system("cls");
		print();
	}
	if (is_line() == 'X') last_winner = "Player 1";
	else last_winner = "Player 2";

	cout << endl << "Congratulation " << last_winner << "! Do you want to play next game? Y/N: ";
	char choice;
	while (1)
	{
		cin >> choice;
		if (!cin.fail() && (choice == 'y' || choice == 'n' || choice == 'Y' || choice == 'N')) break;
		cin.clear();
		cin.ignore(256, '\n');
		cout << endl << "ERROR! Bad choice. Your choice: ";
	}

	if (choice == 'n' || choice == 'N') return false;

	clear();
}