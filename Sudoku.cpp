#include "Sudoku.h"
using std::endl;
using std::cout;


Sudoku::Sudoku(std::vector<std::vector<int>> v)
{
	board = v;
}


Sudoku::~Sudoku()
{
}

std::vector<std::vector<int>> Sudoku::solve()
{
	std::vector<EmptySquare> emptySquares;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (board[i][j] == 0) {
				emptySquares.push_back(EmptySquare(i, j, 0));
			}
		}
	}
	int square = 0;
	while (square < emptySquares.size()) {
		if (emptySquares[square].number < 10) {
			emptySquares[square].number++;
			board[emptySquares[square].row][emptySquares[square].column] = emptySquares[square].number;
			if (isLegal()) {
//				std::cout << "legal" << std::endl;
				square++;
			}
		}
		else {
//			cout << "backtracking" << endl;
			emptySquares[square].number = 0;
			board[emptySquares[square].row][emptySquares[square].column] = 0;
			square--;
		}
	}
	return board;
}

bool Sudoku::isLegal()
{
	bool* isInGroup = new bool[9];
	//check rows
	for (int row = 0; row < 9; row++) {
		for (int i = 0; i < 9; i++) isInGroup[i] = false;
		for (int column = 0; column < 9; column++) {
			if (board[row][column] == 0) {
				continue;
			}
			if (isInGroup[board[row][column] - 1]) {
				return false;
			}
			isInGroup[board[row][column] - 1] = true;
		}
	}
	//check columns
	for (int column = 0; column < 9; column++) {
		for (int i = 0; i < 9; i++) isInGroup[i] = false;
		for (int row = 0; row < 9; row++) {
			if (board[row][column] == 0) {
				continue;
			}
			if (isInGroup[board[row][column] - 1]) {
				return false;
			}
			isInGroup[board[row][column] - 1] = true;
		}
	}
	//check boxes
	//first create box groups
	std::vector<std::vector<int>> boxes;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::vector<int> box;
			for (int row = 0; row < 3; row++) {
				for (int column = 0; column < 3; column++) {
					box.push_back(board[row + i * 3][column + i * 3]);
				}
			}
			boxes.push_back(box);
		}
	}
	//check boxes
	for (int boxIndex = 0; boxIndex < 9; boxIndex++) {
		for (int i = 0; i < 9; i++) isInGroup[i] = false;
		for (int i = 0; i < 9; i++) {
			if (boxes[boxIndex][i] == 0) {
				continue;
			}
			if (isInGroup[boxes[boxIndex][i] - 1]) {
				return false;
			}
			isInGroup[boxes[boxIndex][i] - 1] = true;
		}
	}
	
	return true;
}
