#include "Sudoku.h"
#include <iostream>

int main() {
	std::vector< std::vector<int> > v(9, std::vector<int>(9, 0));;
	v[0][4] = 6;
	v[0][8] = 5;
	v[1][0] = 5;
	v[1][5] = 9;
	v[1][6] = 4;
	v[1][8] = 8;
	v[2][1] = 6;
	v[2][5] = 5;
	v[2][6] = 2;
	v[2][7] = 9;
	v[3][1] = 2;
	v[3][3] = 1;
	v[3][5] = 3;
	v[3][6] = 9;
	v[4][4] = 7;
	v[5][2] = 7;
	v[5][3] = 4;
	v[5][5] = 8;
	v[5][7] = 5;
	v[6][1] = 8;
	v[6][2] = 9;
	v[6][3] = 5;
	v[6][7] = 2;
	v[7][0] = 3;
	v[7][2] = 1;
	v[7][3] = 6;
	v[7][8] = 9;
	v[8][0] = 6;
	v[8][4] = 1;
	Sudoku sudoku(v);
	std::vector< std::vector<int> > solution = sudoku.solve();
	sudoku.print();
}