#pragma once
#include <vector>
#include <list>
#include <iostream>
struct EmptySquare {
	int number;
	int row;
	int column;
	EmptySquare(int row, int column, int number) : number(number), row(row), column(column) {}
};

class Sudoku
{
public:
	Sudoku(std::vector< std::vector<int> > board);
	~Sudoku();
	std::vector< std::vector<int> > solve();
	void print();
	bool isLegal();
private:
	std::vector< std::vector<int> > board;
};

