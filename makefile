sudoku: Sudoku.h Sudoku.cpp Source.cpp
		g++ Sudoku.cpp Source.cpp -o sudoku
		
run:	sudoku
		./sudoku

clean:
		rm -f sudoku