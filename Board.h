#pragma once
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Board
{
private:
	char squares[9];
	string current_player_move;
	string last_winner;

public:
	Board();
	void print() const;
	void next_move();
	void clear();
	bool is_square_used(int _square) const;
	char is_line() const;
	bool start();
};

