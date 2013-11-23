// ----------------------------
// /cs371p-life/TestLife.c++
// Copyright (C) 2013
// CS371p Fall 2013
// Kevin Tran
// Calvin Lau
// ----------------------------


#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==

#include "gtest/gtest.h"
#include "Life.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"

using namespace std;


TEST(ConwayCell, alive)
{
	ConwayCell aliveCell;
	ostringstream w;
	w << aliveCell;

	ASSERT_FALSE(w.str() == "*");
}

TEST(ConwayCell, clone)
{
	ConwayCell cell;
	ConwayCell* copy = cell.clone();
	ASSERT_FALSE(&cell == copy);
}

TEST(ConwayCell, dead)
{
	ConwayCell deadCell;
	ostringstream w;
	w << deadCell;

	ASSERT_TRUE(w.str() == ".");
}


TEST(FredkinCell, alive)
{
	FredkinCell aliveCell;
	ostringstream w;
	w << aliveCell;

	ASSERT_FALSE(w.str() == "0");
}

TEST(FredkinCell, clone)
{
	FredkinCell cell;
	FredkinCell* copy = cell.clone();
	ASSERT_FALSE(&cell == copy);
}

TEST(Cell, clone)
{
	Cell cell;
	Cell* copy = cell.clone();

	ASSERT_FALSE(&cell == copy);
}

TEST(FredkinCell, dead)
{
	FredkinCell deadCell;
	ostringstream w;
	w << deadCell;

	ASSERT_TRUE(w.str() == "-");
}


TEST(ConwayCell, mutate_1)
{
	ConwayCell cell;
	int neighbors = 3;
	bool result = cell.mutate(neighbors);
	ASSERT_TRUE(result);
}


TEST(ConwayCell, mutate_2)
{
	ConwayCell cell;
	int neighbors = 5;
	bool result = cell.mutate(neighbors);
	ASSERT_FALSE(result);
}


TEST(ConwayCell, mutate_3)
{
	ConwayCell cell;
	int neighbors = 2;
	bool result = cell.mutate(neighbors);
	ASSERT_FALSE(result);
}

TEST(ConwayCell, mutate_4)
{
	ConwayCell cell;
	int neighbors = 8;
	bool result = cell.mutate(neighbors);
	ASSERT_FALSE(result);
}

TEST(FredkinCell, mutate_1)
{
	FredkinCell cell;
	int neighbors = 2;
	bool result = cell.mutate(neighbors);
	ASSERT_FALSE(result);
}

TEST(FredkinCell, mutate_2)
{
	FredkinCell cell;
	int neighbors = 1;
	bool result = cell.mutate(neighbors);
	ASSERT_TRUE(result);
}

TEST(FredkinCell, mutate_3)
{
	FredkinCell cell;
	int neighbors = 4;
	bool result = cell.mutate(neighbors);
	ASSERT_FALSE(result);
}

TEST(FredkinCell, mutate_4)
{
	FredkinCell cell;
	int neighbors = 3;
	bool result = cell.mutate(neighbors);
	ASSERT_TRUE(result);
}

TEST(FredkinCell, mutate_5)
{
	FredkinCell cell;
	int neighbors = 0;
	bool result = cell.mutate(neighbors);
	ASSERT_FALSE(result);
}

TEST(Cell, mutate)
{
	Cell cell;
	int neighbors = 0;
	bool result = cell.mutate(neighbors);
	ASSERT_FALSE(result);
}

TEST(Cell, mutate_1)
{
	Cell cell;
	int neighbors = 1;
	bool result = cell.mutate(neighbors);
	ASSERT_TRUE(result);
}

TEST(Cell, mutate_2)
{
	Cell cell;
	int neighbors = 2;
	bool result = cell.mutate(neighbors);
	ASSERT_FALSE(result);
}


TEST(ConwayCell, read_correct_vals_Conway1)
{
	Life<ConwayCell> board;
	istringstream r("5\n5\n.....\n..*..\n..*..\n..*..\n.....");
	board.life_read(r, false);
	ostringstream w;
	board.life_print(w);
	//cout << w.str() << endl;
	ASSERT_TRUE( w.str() == "Generation = 0, Population = 3.\n"
							".....\n"
							"..*..\n"
							"..*..\n"
							"..*..\n"
							".....\n\n");
}

TEST(ConwayCell, read_correct_vals_Conway2)
{
	Life<ConwayCell> board;
	istringstream r("3\n3\n...\n.*.\n..*");
	board.life_read(r, false);
	ostringstream w;
	board.life_print(w);
	//cout << w.str() << endl;
	ASSERT_TRUE( w.str() == "Generation = 0, Population = 2.\n"
							"...\n"
							".*.\n"
							"..*\n\n");
}

TEST(ConwayCell, read_correct_vals_Conway3)
{
	Life<ConwayCell> board;
	istringstream r("10\n10\n**********\n**********\n**********\n**********\n**********\n**********\n**********\n**********\n**********\n**********");
	board.life_read(r, false);
	ostringstream w;
	board.life_print(w);
	//cout << w.str() << endl;
	ASSERT_TRUE( w.str() == "Generation = 0, Population = 100.\n"
							"**********\n"
							"**********\n"
							"**********\n"
							"**********\n"
							"**********\n"
							"**********\n"
							"**********\n"
							"**********\n"
							"**********\n"
							"**********\n\n");
}


TEST(FredkinCell, read_correct_vals_Fredkin)
{
	Life<FredkinCell> board;
	istringstream r("5\n5\n-----\n--0--\n--0--\n--0--\n-----");
	board.life_read(r, false);
	ostringstream w;
	board.life_print(w);
	//cout << w.str() << endl;
	ASSERT_TRUE( w.str() == "Generation = 0, Population = 3.\n"
							"-----\n"
							"--0--\n"
							"--0--\n"
							"--0--\n"
							"-----\n\n");
}

TEST(FredkinCell, read_correct_vals_Fredkin_full)
{
	Life<FredkinCell> board;
	istringstream r("5\n5\n00000\n00000\n00000\n00000\n00000");
	board.life_read(r, false);
	ostringstream w;
	board.life_print(w);
	//cout << w.str() << endl;
	ASSERT_TRUE( w.str() == "Generation = 0, Population = 25.\n"
							"00000\n"
							"00000\n"
							"00000\n"
							"00000\n"
							"00000\n\n");
}

TEST(FredkinCell, read_correct_vals_Fredkin_empty)
{
	Life<FredkinCell> board;
	istringstream r("5\n5\n-----\n-----\n-----\n-----\n-----");
	board.life_read(r, false);
	ostringstream w;
	board.life_print(w);
	//cout << w.str() << endl;
	ASSERT_TRUE( w.str() == "Generation = 0, Population = 0.\n"
							"-----\n"
							"-----\n"
							"-----\n"
							"-----\n"
							"-----\n\n");
}

TEST(FredkinCell, read_correct_vals_Fredkin_invalid)
{
	Life<FredkinCell> board;
	istringstream r("5\n5\n--+--\n-23--\n-45--\n-67--\n-89--");
	board.life_read(r, false);
	ostringstream w;
	board.life_print(w);
	//cout << w.str() << endl;
	ASSERT_FALSE( w.str() == "Generation = 0, Population = 9.\n"
							"--+--\n"
							"-23--\n"
							"-45--\n"
							"-67--\n"
							"-89--\n\n");
	ASSERT_TRUE( w.str() == "Generation = 0, Population = 0.\n"
							"-----\n"
							"-----\n"
							"-----\n"
							"-----\n"
							"-----\n\n");
}

TEST(Cell, read_correct_vals_Cell)
{
	Life<Cell> board;
	istringstream r("5\n5\n-----\n--0--\n--0--\n--0--\n-----");
	board.life_read(r, false);
	ostringstream w;
	board.life_print(w);
	//cout << w.str() << endl;
	ASSERT_TRUE( w.str() == "Generation = 0, Population = 3.\n"
							"-----\n"
							"--0--\n"
							"--0--\n"
							"--0--\n"
							"-----\n\n");
}

TEST(Cell, read_correct_vals_Cell_full)
{
	Life<Cell> board;
	istringstream r("5\n5\n00000\n00000\n00000\n00000\n00000");
	board.life_read(r, false);
	ostringstream w;
	board.life_print(w);
	//cout << w.str() << endl;
	ASSERT_TRUE( w.str() == "Generation = 0, Population = 25.\n"
							"00000\n"
							"00000\n"
							"00000\n"
							"00000\n"
							"00000\n\n");
}

TEST(Cell, read_correct_vals_Cell_empty)
{
	Life<Cell> board;
	istringstream r("5\n5\n-----\n-----\n-----\n-----\n-----");
	board.life_read(r, false);
	ostringstream w;
	board.life_print(w);
	//cout << w.str() << endl;
	ASSERT_TRUE( w.str() == "Generation = 0, Population = 0.\n"
							"-----\n"
							"-----\n"
							"-----\n"
							"-----\n"
							"-----\n\n");
}

TEST(FredkinCell, read_correct_vals_Cell_invalid)
{
	Life<Cell> board;
	istringstream r("5\n5\n--+--\n-23--\n-45--\n-67--\n-89--");
	board.life_read(r, false);
	ostringstream w;
	board.life_print(w);
	//cout << w.str() << endl;
	ASSERT_FALSE( w.str() == "Generation = 0, Population = 9.\n"
							"--+--\n"
							"-23--\n"
							"-45--\n"
							"-67--\n"
							"-89--\n\n");
	ASSERT_TRUE( w.str() == "Generation = 0, Population = 0.\n"
							"-----\n"
							"-----\n"
							"-----\n"
							"-----\n"
							"-----\n\n");
}


TEST(ConwayCell, in_range)
{
	Life<ConwayCell> board;
	istringstream r("5\n5\n.....\n..*..\n..*..\n..*..\n.....");
	board.life_read(r, false);
	ASSERT_TRUE(board.validRange(1, 1));
}


TEST(ConwayCell, in_range_2)
{
	Life<ConwayCell> board;
	istringstream r("5\n5\n.....\n..*..\n..*..\n..*..\n.....");
	board.life_read(r, false);
	ASSERT_FALSE(board.validRange(-3, 22));
}


TEST(ConwayCell, in_range_3)
{
	Life<ConwayCell> board;
	istringstream r("5\n5\n.....\n..*..\n..*..\n..*..\n.....");
	board.life_read(r, false);
	ASSERT_FALSE(board.validRange(5, 5));
}


TEST(FredkinCell, in_range_4)
{
	Life<FredkinCell> board;
	istringstream r("5\n5\n-----\n--0--\n--0--\n--0--\n-----");
	board.life_read(r, false);
	ASSERT_TRUE(board.validRange(0, 0));
}

TEST(FredkinCell, in_range_5)
{
	Life<FredkinCell> board;
	istringstream r("1\n1\n0");
	board.life_read(r, false);
	ASSERT_TRUE(board.validRange(0, 0));
}

TEST(FredkinCell, in_range_6)
{
	Life<FredkinCell> board;
	istringstream r("1\n1\n-");
	board.life_read(r, false);
	ASSERT_FALSE(board.validRange(2, 300));
}

TEST(Cell, in_range_7)
{
	Life<Cell> board;
	istringstream r("1\n5\n-----");
	board.life_read(r, false);
	ASSERT_TRUE(board.validRange(0, 3));
}

TEST(Cell, in_range_8)
{
	Life<Cell> board;
	istringstream r("1\n5\n-----");
	board.life_read(r, false);
	ASSERT_FALSE(board.validRange(0, 666));
}

TEST(Cell, in_range_9)
{
	Life<Cell> board;
	istringstream r("5\n5\n-----\n--0--\n--0--\n--0--\n-----");
	board.life_read(r, false);
	ASSERT_FALSE(board.validRange(6, 9));
}


TEST(ConwayCell, place_cell_Conway)
{
	Life<ConwayCell> board;
	istringstream r("5\n5\n.....\n..*..\n..*..\n..*..\n.....");
	board.life_read(r, false);
	ostringstream w;
	board.life_place_cell(0, 1, '*');
	board.life_place_cell(4, 4, '*');
	board.life_print(w);
	//cout << w.str() << endl;
	ASSERT_TRUE( w.str() == "Generation = 0, Population = 5.\n"
							".*...\n"
							"..*..\n"
							"..*..\n"
							"..*..\n"
							"....*\n\n");
}

TEST(ConwayCell, place_cell_Conway_2)
{
	Life<ConwayCell> board;
	istringstream r("1\n1\n.");
	board.life_read(r, false);
	ostringstream w;
	board.life_place_cell(0, 0, '*');
	board.life_print(w);
	//cout << w.str() << endl;
	ASSERT_TRUE( w.str() == "Generation = 0, Population = 1.\n"
							"*\n\n");
}

TEST(ConwayCell, place_cell_Conway_corners)
{
	Life<ConwayCell> board;
istringstream r("5\n5\n.....\n.....\n.....\n.....\n.....");
	board.life_read(r, false);
	ostringstream w;
	board.life_place_cell(0, 0, '*');
	board.life_place_cell(1, 1, '*');
	board.life_place_cell(2, 2, '*');
	board.life_place_cell(3, 3, '*');
	board.life_place_cell(4, 4, '*');

	board.life_print(w);
	//cout << w.str() << endl;
	ASSERT_TRUE( w.str() == "Generation = 0, Population = 5.\n"
							"*....\n"
							".*...\n"
							"..*..\n"
							"...*.\n"
							"....*\n\n");
}


TEST(FredkinCell, place_cell_Fredkin)
{
	Life<FredkinCell> board;
	istringstream r("5\n5\n-----\n--0--\n--0--\n--0--\n-----");
	board.life_read(r, false);
	ostringstream w;
	board.life_place_cell(0, 1, '0');
	board.life_place_cell(4, 1, '0');
	board.life_print(w);

	ASSERT_TRUE( w.str() == "Generation = 0, Population = 5.\n"
							"-0---\n"
							"--0--\n"
							"--0--\n"
							"--0--\n"
							"-0---\n\n");
}

TEST(FredkinCell, place_cell_Fredkin_2)
{
	Life<FredkinCell> board;
	istringstream r("1\n1\n-");
	board.life_read(r, false);
	ostringstream w;
	board.life_place_cell(0, 0, '0');
	board.life_print(w);
	//cout << w.str() << endl;
	ASSERT_TRUE( w.str() == "Generation = 0, Population = 1.\n"
							"0\n\n");
}

TEST(FredkinCell, place_cell_Fredkin_corners)
{
	Life<FredkinCell> board;
	istringstream r("5\n5\n-----\n-----\n-----\n-----\n-----");
	board.life_read(r, false);
	ostringstream w;
	board.life_place_cell(0, 0, '0');
	board.life_place_cell(1, 1, '0');
	board.life_place_cell(2, 2, '0');
	board.life_place_cell(3, 3, '0');
	board.life_place_cell(4, 4, '0');

	board.life_print(w);
	//cout << w.str() << endl;
	ASSERT_TRUE( w.str() == "Generation = 0, Population = 5.\n"
							"0----\n"
							"-0---\n"
							"--0--\n"
							"---0-\n"
							"----0\n\n");
}

TEST(Cell, place_cell_3)
{
	Life<Cell> board;
	istringstream r("5\n5\n-----\n--0--\n--0--\n--0--\n-----");
	board.life_read(r, false);
	ostringstream w;
	board.life_place_cell(0, 1, '0');
	board.life_place_cell(4, 1, '0');
	board.life_place_cell(2, 3, '0');
	board.life_print(w);

	ASSERT_TRUE( w.str() == "Generation = 0, Population = 6.\n"
							"-0---\n"
							"--0--\n"
							"--00-\n"
							"--0--\n"
							"-0---\n\n");
}


TEST(ConwayCell, life_simulate_Conway)
{
	Life<ConwayCell> board;
	istringstream r("5\n5\n.....\n..*..\n..*..\n..*..\n.....");
	board.life_read(r, false);
	ostringstream w;
	board.life_simulate(1, false, w);
	board.life_print(w);

	ASSERT_TRUE( w.str() == "Generation = 1, Population = 3.\n"
							".....\n"
							".....\n"
							".***.\n"
							".....\n"
							".....\n\n");
}


TEST(ConwayCell, life_simulate_Conway_2)
{
	Life<ConwayCell> board;
	istringstream r("3\n3\n...\n.*.\n...");
	board.life_read(r, false);
	ostringstream w;
	board.life_simulate(1, false, w);
	board.life_print(w);

	ASSERT_TRUE( w.str() == "Generation = 1, Population = 0.\n"
							"...\n"
							"...\n"
							"...\n\n");
}


TEST(ConwayCell, life_simulate_Conway_3)
{
	Life<ConwayCell> board;
	istringstream r("5\n5\n.....\n..*..\n..*..\n..*..\n.....");
	board.life_read(r, false);
	ostringstream w;
	board.life_simulate(6, false, w);
	board.life_print(w);
	//cout << w.str() << endl;
	ASSERT_TRUE( w.str() == "Generation = 6, Population = 3.\n"
							".....\n"
							"..*..\n"
							"..*..\n"
							"..*..\n"
							".....\n\n");
}


TEST(FredkinCell, life_simulate_Fredkin)
{
	Life<FredkinCell> board;
	istringstream r("5\n5\n-----\n--0--\n--0--\n--0--\n-----");
	board.life_read(r, false);
	ostringstream w;
	board.life_simulate(1, false, w);
	board.life_print(w);
	//cout << w.str() << endl;
	ASSERT_TRUE( w.str() == "Generation = 1, Population = 10.\n"
							"--0--\n"
							"-010-\n"
							"-0-0-\n"
							"-010-\n"
							"--0--\n\n");
}


TEST(FredkinCell, life_simulate_Fredkin_2)
{
	Life<FredkinCell> board;
	istringstream r("3\n3\n---\n-0-\n---");
	board.life_read(r, false);
	ostringstream w;
	board.life_simulate(1, false, w);
	board.life_print(w);

	ASSERT_TRUE( w.str() == "Generation = 1, Population = 4.\n"
							"-0-\n"
							"0-0\n"
							"-0-\n\n");
	
}

TEST(FredkinCell, life_simulate_Fredkin_plus)
{
	Life<FredkinCell> board;
	istringstream r("5\n5\n00000\n00000\n-----\n00000\n00000");
	board.life_read(r, false);
	ostringstream w;
	board.life_simulate(10, false, w);
	board.life_print(w);
	//cout << w.str() << endl;
	ASSERT_TRUE( w.str() == "Generation = 10, Population = 12.\n"
							"8-+-8\n"
							"8-+-8\n"
							"-----\n"
							"8-+-8\n"
							"8-+-8\n\n");

}

TEST(FredkinCell, life_simulate_Fredkin_allPlus)
{
	Life<FredkinCell> board;
	istringstream r("5\n5\n0-0-0\n0-0-0\n-----\n0-0-0\n0-0-0");
	board.life_read(r, false);
	ostringstream w;
	board.life_simulate(10, false, cout);
	board.life_print(w);
	//cout << w.str() << endl;
	
	ASSERT_TRUE( w.str() == "Generation = 10, Population = 12.\n"
							"+-+-+\n"
							"+-+-+\n"
							"-----\n"
							"+-+-+\n"
							"+-+-+\n\n");
	

}


TEST(Cell, life_simulate_cell)
{
	Life<Cell> board;
	istringstream r("3\n3\n---\n000\n-0-");
	board.life_read(r, false);
	ostringstream w;
	board.life_simulate(2, false, cout);
	board.life_print(w);
	//cout << w.str() << endl;
	
	ASSERT_TRUE( w.str() == "Generation = 2, Population = 2.\n"
							"-1-\n"
							"---\n"
							"-*-\n\n");
	

}

TEST(Cell, life_simulate_cell_2)
{
	Life<Cell> board;
	istringstream r("5\n5\n00000\n00000\n-----\n00000\n00000");
	board.life_read(r, false);
	ostringstream w;
	board.life_simulate(5, false, cout);
	board.life_print(w);
	//cout << w.str() << endl;
	
	ASSERT_TRUE( w.str() == "Generation = 5, Population = 8.\n"
							"*-.-*\n"
							"*-.-*\n"
							"-----\n"
							"*-.-*\n"
							"*-.-*\n\n");
	

}

TEST(Cell, life_simulate_cell_3)
{
	Life<Cell> board;
	istringstream r("5\n5\n0-0-0\n0-0-0\n----\n0-0-0\n0-0-0");
	board.life_read(r, false);
	ostringstream w;
	board.life_simulate(20, false, cout);
	board.life_print(w);
	//cout << w.str() << endl;
	ASSERT_TRUE( w.str() == "Generation = 20, Population = 0.\n"
							".....\n"
							"...-.\n"
							".....\n"
							".....\n"
							"....-\n\n");

}

TEST(ConwayCell, ConwayCounter)
{
	Life<ConwayCell>board;
	istringstream r("5\n5\n.....\n..*..\n..*..\n..*..\n.....");
	board.life_read(r, false);
	//cout << board.count_helper(1, 2) << endl;
	ASSERT_TRUE(board.count_helper(0, 2) == 1);
	ASSERT_TRUE(board.count_helper(1, 2) == 1);
	ASSERT_TRUE(board.count_helper(2, 2) == 2);
	ASSERT_TRUE(board.count_helper(3, 2) == 1);
	ASSERT_TRUE(board.count_helper(2, 1) == 3);
	ASSERT_TRUE(board.count_helper(2, 3) == 3);
	ASSERT_TRUE(board.count_helper(3, 1) == 2);
	ASSERT_TRUE(board.count_helper(3, 3) == 2);
	ASSERT_TRUE(board.count_helper(4, 2) == 1);
}



TEST(ConwayCell, ConwayCounter_2)
{
	Life<ConwayCell>board;
	istringstream r("3\n3\n***\n***\n***");
	board.life_read(r, false);
	//cout << board.count_helper(1, 2) << endl;
	ASSERT_TRUE(board.count_helper(0, 0) == 3);
	ASSERT_TRUE(board.count_helper(0, 1) == 5);
	ASSERT_TRUE(board.count_helper(0, 2) == 3);
	ASSERT_TRUE(board.count_helper(1, 0) == 5);
	ASSERT_TRUE(board.count_helper(1, 1) == 8);
	ASSERT_TRUE(board.count_helper(1, 2) == 5);
	ASSERT_TRUE(board.count_helper(2, 0) == 3);
	ASSERT_TRUE(board.count_helper(2, 1) == 5);
	ASSERT_TRUE(board.count_helper(2, 2) == 3);
}


TEST(ConwayCell, ConwayCounter_3)
{
	Life<ConwayCell>board;
	istringstream r("3\n3\n...\n...\n...");
	board.life_read(r, false);
	//cout << board.count_helper(1, 2) << endl;
	ASSERT_TRUE(board.count_helper(0, 0) == 0);
	ASSERT_TRUE(board.count_helper(0, 1) == 0);
	ASSERT_TRUE(board.count_helper(0, 2) == 0);
	ASSERT_TRUE(board.count_helper(1, 0) == 0);
	ASSERT_TRUE(board.count_helper(1, 1) == 0);
	ASSERT_TRUE(board.count_helper(1, 2) == 0);
	ASSERT_TRUE(board.count_helper(2, 0) == 0);
	ASSERT_TRUE(board.count_helper(2, 1) == 0);
	ASSERT_TRUE(board.count_helper(2, 2) == 0);
}

TEST(FredkinCell, FredkinCounter)
{
	Life<FredkinCell>board;
	istringstream r("5\n5\n-----\n--0--\n--0--\n--0--\n-----");
	board.life_read(r, false);
	ASSERT_TRUE(board.count_helper(0, 2) == 1);
	ASSERT_TRUE(board.count_helper(1, 2) == 1);
	ASSERT_TRUE(board.count_helper(2, 2) == 2);
	ASSERT_TRUE(board.count_helper(3, 2) == 1);
	ASSERT_TRUE(board.count_helper(4, 2) == 1);
}



TEST(FredkinCell, FredkinCounter_2)
{
	Life<FredkinCell>board;
	istringstream r("3\n3\n000\n000\n000");
	board.life_read(r, false);
	ASSERT_TRUE(board.count_helper(0, 0) == 2);
	ASSERT_TRUE(board.count_helper(0, 1) == 3);
	ASSERT_TRUE(board.count_helper(0, 2) == 2);
	ASSERT_TRUE(board.count_helper(1, 0) == 3);
	ASSERT_TRUE(board.count_helper(1, 1) == 4);
	ASSERT_TRUE(board.count_helper(1, 2) == 3);
	ASSERT_TRUE(board.count_helper(2, 0) == 2);
	ASSERT_TRUE(board.count_helper(2, 1) == 3);
	ASSERT_TRUE(board.count_helper(2, 2) == 2);
}


TEST(FredkinCell, FredkinCounter_3)
{
	Life<ConwayCell>board;
	istringstream r("3\n3\n---\n---\n---");
	board.life_read(r, false);
	//cout << board.count_helper(1, 2) << endl;
	ASSERT_TRUE(board.count_helper(0, 0) == 0);
	ASSERT_TRUE(board.count_helper(0, 1) == 0);
	ASSERT_TRUE(board.count_helper(0, 2) == 0);
	ASSERT_TRUE(board.count_helper(1, 0) == 0);
	ASSERT_TRUE(board.count_helper(1, 1) == 0);
	ASSERT_TRUE(board.count_helper(1, 2) == 0);
	ASSERT_TRUE(board.count_helper(2, 0) == 0);
	ASSERT_TRUE(board.count_helper(2, 1) == 0);
	ASSERT_TRUE(board.count_helper(2, 2) == 0);
}

TEST(Cell, CellCounter)
{
	Life<Cell>board;
	istringstream r("5\n5\n--*--\n--0--\n--0--\n--0--\n-----");
	board.life_read(r, false);
	ASSERT_TRUE(board.count_helper(0, 2) == 1);
	ASSERT_TRUE(board.count_helper(1, 2) == 2);
	ASSERT_TRUE(board.count_helper(2, 2) == 2);
	ASSERT_TRUE(board.count_helper(3, 2) == 1);
	ASSERT_TRUE(board.count_helper(4, 2) == 1);
}



TEST(Cell, CellCounter_2)
{
	Life<Cell>board;
	istringstream r("3\n3\n0*0\n*00\n00*");
	board.life_read(r, false);
	ASSERT_TRUE(board.count_helper(0, 0) == 2);
	ASSERT_TRUE(board.count_helper(0, 1) == 3);
	ASSERT_TRUE(board.count_helper(0, 2) == 2);
	ASSERT_TRUE(board.count_helper(1, 0) == 3);
	ASSERT_TRUE(board.count_helper(1, 1) == 4);
	ASSERT_TRUE(board.count_helper(1, 2) == 3);
	ASSERT_TRUE(board.count_helper(2, 0) == 2);
	ASSERT_TRUE(board.count_helper(2, 1) == 3);
	ASSERT_TRUE(board.count_helper(2, 2) == 2);
}


TEST(Cell, CellCounter_3)
{
	Life<Cell>board;
	istringstream r("3\n3\n.--\n.--\n-.-");
	board.life_read(r, false);
	//cout << board.count_helper(1, 2) << endl;
	ASSERT_TRUE(board.count_helper(0, 0) == 0);
	ASSERT_TRUE(board.count_helper(0, 1) == 0);
	ASSERT_TRUE(board.count_helper(0, 2) == 0);
	ASSERT_TRUE(board.count_helper(1, 0) == 0);
	ASSERT_TRUE(board.count_helper(1, 1) == 0);
	ASSERT_TRUE(board.count_helper(1, 2) == 0);
	ASSERT_TRUE(board.count_helper(2, 0) == 0);
	ASSERT_TRUE(board.count_helper(2, 1) == 0);
	ASSERT_TRUE(board.count_helper(2, 2) == 0);
}

TEST(ConwayCell, makeWorld)
{
	Life<ConwayCell> board;
	board.makeWorld(20, 20);
	ASSERT_TRUE(board.validRange(0, 0));
	ASSERT_TRUE(board.validRange(0, 19));
	ASSERT_TRUE(board.validRange(19, 0));
	ASSERT_TRUE(board.validRange(19, 19));

}

TEST(ConwayCell, makeWorld_2)
{
	Life<ConwayCell> board;
	board.makeWorld(20, 20);
	ASSERT_FALSE(board.validRange(-1, 0));
	ASSERT_FALSE(board.validRange(0, 20));
	ASSERT_FALSE(board.validRange(20, 0));
	ASSERT_FALSE(board.validRange(20, 20));

}

TEST(ConwayCell, makeWorld_3)
{
	Life<ConwayCell> board;
	board.makeWorld(20, 20);
	ASSERT_FALSE(board.validRange(-1, 0));
	ASSERT_TRUE(board.validRange(0, 19));
	ASSERT_FALSE(board.validRange(20, 0));
	ASSERT_TRUE(board.validRange(5, 8));

}

TEST(FredkinCell, makeWorld)
{
	Life<FredkinCell> board;
	board.makeWorld(20, 20);
	ASSERT_TRUE(board.validRange(0, 0));
	ASSERT_TRUE(board.validRange(0, 19));
	ASSERT_TRUE(board.validRange(19, 0));
	ASSERT_TRUE(board.validRange(19, 19));

}

TEST(FredkinCell, makeWorld_2)
{
	Life<FredkinCell> board;
	board.makeWorld(20, 20);
	ASSERT_FALSE(board.validRange(-1, 0));
	ASSERT_FALSE(board.validRange(0, 20));
	ASSERT_FALSE(board.validRange(20, 0));
	ASSERT_FALSE(board.validRange(20, 20));

}

TEST(FredkinCell, makeWorld_3)
{
	Life<FredkinCell> board;
	board.makeWorld(20, 20);
	ASSERT_FALSE(board.validRange(-1, 0));
	ASSERT_TRUE(board.validRange(0, 19));
	ASSERT_FALSE(board.validRange(20, 0));
	ASSERT_TRUE(board.validRange(5, 8));

}

TEST(Cell, makeWorld)
{
	Life<Cell> board;
	board.makeWorld(20, 20);
	ASSERT_TRUE(board.validRange(0, 0));
	ASSERT_TRUE(board.validRange(0, 19));
	ASSERT_TRUE(board.validRange(19, 0));
	ASSERT_TRUE(board.validRange(19, 19));

}

TEST(Cell, makeWorld_2)
{
	Life<Cell> board;
	board.makeWorld(20, 20);
	ASSERT_FALSE(board.validRange(-1, 0));
	ASSERT_FALSE(board.validRange(0, 20));
	ASSERT_FALSE(board.validRange(20, 0));
	ASSERT_FALSE(board.validRange(20, 20));

}

TEST(Cell, makeWorld_3)
{
	Life<Cell> board;
	board.makeWorld(20, 20);
	ASSERT_FALSE(board.validRange(-1, 0));
	ASSERT_TRUE(board.validRange(0, 19));
	ASSERT_FALSE(board.validRange(20, 0));
	ASSERT_TRUE(board.validRange(5, 8));

}