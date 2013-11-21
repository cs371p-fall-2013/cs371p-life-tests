/******************************************************************************
 * Program:		Project 5: Life
 * Student:		Merrill Davis
 * UT EID:		davismc2
 * CS ID: 		davismc
 * Github:		davismc
 * Class: 		CS 371p
 * Fall 2013
 *
 * Purpose: 
 * A program to play the game of Life. Life is a simulation of cell automata.
 *****************************************************************************/

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==
#include <stdexcept> // invalid_argument, out_of_range

#include "gtest/gtest.h"

#define private public
#define protected public

#include "Life.h"
#include "Cell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"

// -----------
// TestDarwin
// -----------

// ------------
// Class Board<ConwayCell>
// ------------

Board<ConwayCell> b(4, 4);

TEST(BoardSetup, test_setup)
{
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			b.place(i, j, ConwayCell('.'));
}

TEST(BoardSetup, printBoard_empty_Board_4by4)
{
	std::ostringstream w;
    b.printBoard(w);
    //std::cout << w.str() << std::endl;
    ASSERT_TRUE(w.str() == "....\n....\n....\n....\n");
}

TEST(Board, getIndex_row1_col2_should_be_index_6_Board_4by4)
{
	std::ostringstream w;
    Board<ConwayCell> b(4, 4);	
    ASSERT_TRUE(b.getIndex(1, 2) == 6);
}

TEST(Board, getIndex_row3_col4_should_be_index_19_Board_5by5)
{
	std::ostringstream w;
    Board<ConwayCell> b(5, 5);	
    ASSERT_TRUE(b.getIndex(3, 4) == 19);
}

TEST(Board, getIndex_row0_col0_should_be_index_0_Board_7by7)
{
	std::ostringstream w;
    Board<ConwayCell> b(7, 7);	
    ASSERT_TRUE(b.getIndex(0, 0) == 0);
}

TEST(Board, getIndex_row14_col14_should_be_index_224_Board_15by15)
{
	std::ostringstream w;
    Board<ConwayCell> b(15, 15);	
    ASSERT_TRUE(b.getIndex(14, 14) == 224);
}

TEST(Board, place_at_row0_col0)
{
	Board<ConwayCell> b(5, 5);
	b.place(0, 0, ConwayCell('*'));
	ASSERT_TRUE(b.get(0, 0).isAlive());
}

TEST(Board, place_at_row3_col4_5by5)
{
	Board<ConwayCell> b(5, 5);
	b.place(3, 4, ConwayCell('*'));
	ASSERT_TRUE(b.get(3, 4).isAlive());
}

TEST(Board, place_at_row4_col4_bottom_right_corner_5by5)
{
	Board<ConwayCell> b(5, 5);
	b.place(4, 4, ConwayCell('*'));
	ASSERT_TRUE(b.get(4, 4).isAlive());
}

TEST(Board, get_row0_col0)
{
	Board<ConwayCell> b(5, 5);
	b.place(0, 0, ConwayCell('*'));
	ASSERT_TRUE(b.get(0, 0).isAlive());
}

TEST(Board, get_row3_col4_5by5)
{
	Board<ConwayCell> b(5, 5);
	b.place(3, 4, ConwayCell('*'));
	ASSERT_TRUE(b.get(3, 4).isAlive());
}

TEST(Board, get_row4_col4_bottom_right_corner_5by5)
{
	Board<ConwayCell> b(5, 5);
	b.place(4, 4, ConwayCell('*'));
	ASSERT_TRUE(b.get(4, 4).isAlive());
}

TEST(BoardSetup, printBoard_Board_4by4_conway_at_2_2)
{
	b.place(2, 2, ConwayCell('*'));
	std::ostringstream w;
    b.printBoard(w);
    //std::cout << w.str() << std::endl;
    ASSERT_TRUE(w.str() == "....\n....\n..*.\n....\n");
}

TEST(Board, isInBounds_row0_col0_5by5_expect_true)
{
	Board<ConwayCell> b(5,5);
	ASSERT_TRUE(b.isInBounds(0,0));
}

TEST(Board, isInBounds_row2_col3_5by5_expect_true)
{
	Board<ConwayCell> b(5,5);
	ASSERT_TRUE(b.isInBounds(2,3));
}

TEST(Board, isInBounds_row4_col4_5by5_expect_true)
{
	Board<ConwayCell> b(5,5);
	ASSERT_TRUE(b.isInBounds(4,4));
}

TEST(Board, isInBounds_row5_col5_5by5_expect_throw_out_of_range)
{
	try {
		Board<ConwayCell> b(5,5);
		b.isInBounds(5, 5);
	}
	catch (const std::out_of_range&) {
		ASSERT_TRUE(true);
	}
}

TEST(Board, isInBounds_row_neg1_col1_5by5_expect_throw_out_of_range)
{
	try {
		Board<ConwayCell> b(5,5);
		b.isInBounds(-1, 1);
	}
	catch (const std::out_of_range&) {
		ASSERT_TRUE(true);
	}
}

TEST(Board, isInBounds_row1_col_neg1_5by5_expect_throw_out_of_range)
{
	try {
		Board<ConwayCell> b(5,5);
		b.isInBounds(1,-1);
	}
	catch (const std::out_of_range&) {
		ASSERT_TRUE(true);
	}
}

TEST(Board, isInBounds_row_neg1_col_neg1_5by5_expect_throw_out_of_range)
{
	try {
		Board<ConwayCell> b(5,5);
		b.isInBounds(-1,-1);
	}
	catch (const std::out_of_range&) {
		ASSERT_TRUE(true);
	}
}

TEST(Board, isInBounds_row6_col7_7by8_expect_true)
{
	Board<ConwayCell> b(7,8);
	ASSERT_TRUE(b.isInBounds(6,7));
}

TEST(Board, isInBounds_row7_col7_7by8_expect_throw_out_of_range)
{
	try {
		Board<ConwayCell> b(7,8);
		b.isInBounds(7,7);
	}
	catch (const std::out_of_range&) {
		ASSERT_TRUE(true);
	}
}

TEST(Board, isInBounds_row6_col8_7by8_expect_throw_out_of_range)
{
	try {
		Board<ConwayCell> b(7,8);
		b.isInBounds(6,8);
	}
	catch (const std::out_of_range&) {
		ASSERT_TRUE(true);
	}
}

TEST(ConwayCell, default_constructor_should_be_dead)
{
	Board<ConwayCell> b(5, 5);
	b.place(4, 4, ConwayCell());
	ASSERT_FALSE(b.get(4, 4).isAlive());
}

TEST(ConwayCell, one_arg_constructor_not_star_input_should_be_dead)
{
	Board<ConwayCell> b(5, 5);
	b.place(4, 4, ConwayCell('d'));
	ASSERT_FALSE(b.get(4, 4).isAlive());
}

TEST(ConwayCell, one_arg_constructor_period_input_should_be_dead)
{
	Board<ConwayCell> b(5, 5);
	b.place(4, 4, ConwayCell('.'));
	ASSERT_FALSE(b.get(4, 4).isAlive());
}

TEST(ConwayCell, one_arg_constructor_star_input_should_be_alive)
{
	Board<ConwayCell> b(5, 5);
	b.place(4, 4, ConwayCell('*'));
	ASSERT_TRUE(b.get(4, 4).isAlive());
}

TEST(ConwayCell, isAlive_should_be_dead)
{
	Board<ConwayCell> b(5, 5);
	b.place(4, 4, ConwayCell('.'));
	ASSERT_FALSE(b.get(4, 4).isAlive());
}

TEST(ConwayCell, isAlive_should_be_alive)
{
	Board<ConwayCell> b(5, 5);
	b.place(4, 4, ConwayCell('*'));
	ASSERT_TRUE(b.get(4, 4).isAlive());
}

TEST(ConwayCell, updateNeighbors_0_neighbors)
{
	ConwayCell c('*');
	ASSERT_TRUE(c.isAlive());
	bool tmp[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	c.updateNeighbors(tmp);
	ASSERT_TRUE(c._numLiveNeighbors == 0);	
}

TEST(ConwayCell, updateNeighbors_1_neighbors)
{
	ConwayCell c('*');
	ASSERT_TRUE(c.isAlive());
	for (int i = 0; i < 9; ++i)
	{
		if (i == 4)		// Skip 4, that's the cell loc
			continue;
		bool tmp[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
		tmp[i] = 1;
		c.updateNeighbors(tmp);
		ASSERT_TRUE(c._numLiveNeighbors == 1);
	}
}

TEST(ConwayCell, updateNeighbors_1_to_8_neighbors)
{
	ConwayCell c('*');
	ASSERT_TRUE(c.isAlive());
	bool tmp[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	int expected = 0;
	for (int i = 0; i < 9; ++i)
	{
		if (i == 4) // Skip 4, thats the cell loc
			continue;
		tmp[i] = 1;
		c.updateNeighbors(tmp);
		++expected;
		ASSERT_TRUE(c._numLiveNeighbors == expected);
	}
}

TEST(ConwayCell, updateNeighbors_all_neighbors_vals_true_should_skip_cell_loc)
{
	ConwayCell c('*');
	ASSERT_TRUE(c.isAlive());
	bool tmp[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
	c.updateNeighbors(tmp);
	ASSERT_TRUE(c._numLiveNeighbors == 8);
}

TEST(ConwayCell, evolve_alive_2_neighbors_should_stay_alive)
{
	ConwayCell c('*');
	ASSERT_TRUE(c.isAlive());
	bool tmp[9] = {1, 1};
	c.updateNeighbors(tmp);
	c.evolve();
	ASSERT_TRUE(c.isAlive());
}

TEST(ConwayCell, evolve_alive_3_neighbors_should_stay_alive)
{
	ConwayCell c('*');
	ASSERT_TRUE(c.isAlive());
	bool tmp[9] = {1, 1, 1};
	c.updateNeighbors(tmp);
	c.evolve();
	ASSERT_TRUE(c.isAlive());
}

TEST(ConwayCell, evolve_alive_1_neighbor_should_die)
{
	ConwayCell c('*');
	ASSERT_TRUE(c.isAlive());
	bool tmp[9] = {1};
	c.updateNeighbors(tmp);
	c.evolve();
	ASSERT_FALSE(c.isAlive());
}

TEST(ConwayCell, evolve_alive_4_neighbors_should_die)
{
	ConwayCell c('*');
	ASSERT_TRUE(c.isAlive());
	bool tmp[9] = {1, 1, 1, 1};
	c.updateNeighbors(tmp);
	c.evolve();
	ASSERT_FALSE(c.isAlive());
}

TEST(ConwayCell, evolve_alive_4_to_8_neighbors_should_die)
{
	ConwayCell c('*');
	ASSERT_TRUE(c.isAlive());
	bool tmp[9] = {1, 1, 1, 1};
	for (int i = 5; i < 9; ++i)
	{
		tmp[i] = 1;
		c.updateNeighbors(tmp);
		c.evolve();
		ASSERT_FALSE(c.isAlive());
	}
}

TEST(ConwayCell, evolve_dead_3_neighbors_should_come_alive)
{
	ConwayCell c('.');
	ASSERT_FALSE(c.isAlive());
	bool tmp[9] = {1, 1, 1};
	c.updateNeighbors(tmp);
	c.evolve();
	ASSERT_TRUE(c.isAlive());
}

TEST(ConwayCell, evolve_dead_0_to_2_neighbors_should_stay_dead)
{
	ConwayCell c('.');
	ASSERT_FALSE(c.isAlive());
	bool tmp[9] = {0};
	for (int i = 0; i < 3; ++i)
	{
		c.updateNeighbors(tmp);
		c.evolve();
		ASSERT_FALSE(c.isAlive());
		tmp[i] = 1;
	}
}

TEST(ConwayCell, evolve_dead_more_than_3_neighbors_should_stay_dead)
{
	ConwayCell c('.');
	ASSERT_FALSE(c.isAlive());
	bool tmp[9] = {1, 1, 1};
	for (int i = 3; i < 9; ++i)
	{
		tmp[i] = 1;
		c.updateNeighbors(tmp);
		c.evolve();
		ASSERT_FALSE(c.isAlive());
	}
}

TEST(ConwayCell, printSelf_live_cell_should_get_star)
{
	ConwayCell c('*');
	ASSERT_TRUE(c.isAlive());
	std::ostringstream w;
    c.printSelf(w);
    //std::cout << w.str() << std::endl;
    ASSERT_TRUE(w.str() == "*");
}

TEST(ConwayCell, printSelf_dead_cell_should_get_period)
{
	ConwayCell c('.');
	ASSERT_FALSE(c.isAlive());
	std::ostringstream w;
    c.printSelf(w);
    //std::cout << w.str() << std::endl;
    ASSERT_TRUE(w.str() == ".");
}

TEST(ConwayCell, clone_should_return_pointer_to_deep_copy)
{
	ConwayCell c('*');
	ConwayCell* d = c.clone();
	ASSERT_TRUE(d != &c);
	delete d; 
}

TEST(ConwayCell, equals_same_type_both_alive_should_return_true)
{
	ConwayCell c('*');
	ConwayCell d('*');
	ASSERT_TRUE(c.equals(d));
}

TEST(ConwayCell, equals_same_type_one_alive_should_return_false)
{
	ConwayCell c('*');
	ConwayCell d('.');
	ASSERT_FALSE(c.equals(d));
}

TEST(ConwayCell, equals_different_type_both_alive_should_return_false)
{
	ConwayCell c('*');
	FredkinCell d('0');
	ASSERT_FALSE(c.equals(d));
}

TEST(FredkinCell, default_constructor_should_be_dead)
{
	Board<FredkinCell> b(5, 5);
	b.place(4, 4, FredkinCell());
	ASSERT_FALSE(b.get(4, 4).isAlive());
}

TEST(FredkinCell, one_arg_constructor_not_0_input_should_be_dead)
{
	Board<FredkinCell> b(5, 5);
	b.place(4, 4, FredkinCell('d'));
	ASSERT_FALSE(b.get(4, 4).isAlive());
}

TEST(FredkinCell, one_arg_constructor_underscore_input_should_be_dead)
{
	Board<FredkinCell> b(5, 5);
	b.place(4, 4, FredkinCell('-'));
	ASSERT_FALSE(b.get(4, 4).isAlive());
}

TEST(FredkinCell, one_arg_constructor_star_input_should_be_alive)
{
	Board<FredkinCell> b(5, 5);
	b.place(4, 4, FredkinCell('0'));
	ASSERT_TRUE(b.get(4, 4).isAlive());
}

TEST(FredkinCell, isAlive_should_be_dead)
{
	Board<FredkinCell> b(5, 5);
	b.place(4, 4, FredkinCell('-'));
	ASSERT_FALSE(b.get(4, 4).isAlive());
}

TEST(FredkinCell, isAlive_should_be_alive)
{
	Board<FredkinCell> b(5, 5);
	b.place(4, 4, FredkinCell('0'));
	ASSERT_TRUE(b.get(4, 4).isAlive());
}

TEST(FredkinCell, updateNeighbors_0_neighbors)
{
	FredkinCell c('0');
	ASSERT_TRUE(c.isAlive());
	bool tmp[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	c.updateNeighbors(tmp);
	ASSERT_TRUE(c._numLiveNeighbors == 0);	
}

TEST(FredkinCell, updateNeighbors_1_neighbors)
{
	FredkinCell c('0');
	ASSERT_TRUE(c.isAlive());
	for (int i = 0; i < 9; ++i)
	{
		if (i == 4)		// Skip 4, that's the cell loc
			continue;
		bool tmp[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
		tmp[i] = 1;
		c.updateNeighbors(tmp);
		if (i % 2 != 0 && i != 0)
			ASSERT_TRUE(c._numLiveNeighbors == 1);
	}
}

TEST(FredkinCell, updateNeighbors_all_true_should_return_4_neighbors)
{
	FredkinCell c('0');
	ASSERT_TRUE(c.isAlive());
	bool tmp[9] = {1, 1, 1, 1, 1, 1, 1, 1};
	c.updateNeighbors(tmp);
	ASSERT_TRUE(c._numLiveNeighbors == 4);	
}

TEST(FredkinCell, evolve_alive_1_neighbor_should_stay_alive)
{
	FredkinCell c('0');
	ASSERT_TRUE(c.isAlive());
	bool tmp[9] = {0, 1};
	c.updateNeighbors(tmp);
	c.evolve();
	ASSERT_TRUE(c.isAlive());
}

TEST(FredkinCell, evolve_alive_3_neighbors_should_stay_alive)
{
	FredkinCell c('0');
	ASSERT_TRUE(c.isAlive());
	bool tmp[9] = {0, 1, 0, 1, 0, 1};
	c.updateNeighbors(tmp);
	c.evolve();
	ASSERT_TRUE(c.isAlive());
}

TEST(FredkinCell, evolve_alive_0_neighbors_should_die)
{
	FredkinCell c('0');
	ASSERT_TRUE(c.isAlive());
	bool tmp[9] = {0};
	c.updateNeighbors(tmp);
	c.evolve();
	ASSERT_FALSE(c.isAlive());
}

TEST(FredkinCell, evolve_alive_2_neighbors_should_die)
{
	FredkinCell c('0');
	ASSERT_TRUE(c.isAlive());
	bool tmp[9] = {0, 1, 0, 1};
	c.updateNeighbors(tmp);
	c.evolve();
	ASSERT_FALSE(c.isAlive());
}

TEST(FredkinCell, evolve_alive_4_neighbors_should_die)
{
	FredkinCell c('0');
	ASSERT_TRUE(c.isAlive());
	bool tmp[9] = {0, 1, 0, 1, 0, 1, 0, 1};
	c.updateNeighbors(tmp);
	c.evolve();
	ASSERT_FALSE(c.isAlive());
}

TEST(FredkinCell, evolve_dead_1_live_neighbor_should_come_alive)
{
	FredkinCell c('-');
	ASSERT_FALSE(c.isAlive());
	bool tmp[9] = {0, 1};
	c.updateNeighbors(tmp);
	c.evolve();
	ASSERT_TRUE(c.isAlive());
}

TEST(FredkinCell, evolve_dead_3_live_neighbors_should_come_alive)
{
	FredkinCell c('-');
	ASSERT_FALSE(c.isAlive());
	bool tmp[9] = {0, 1, 0, 1, 0, 1};
	c.updateNeighbors(tmp);
	c.evolve();
	ASSERT_TRUE(c.isAlive());
}

TEST(FredkinCell, evolve_dead_0_live_neighbors_should_stay_dead)
{
	FredkinCell c('-');
	ASSERT_FALSE(c.isAlive());
	bool tmp[9] = {0};
	c.updateNeighbors(tmp);
	c.evolve();
	ASSERT_FALSE(c.isAlive());
}

TEST(FredkinCell, evolve_dead_2_live_neighbors_should_stay_dead)
{
	FredkinCell c('-');
	ASSERT_FALSE(c.isAlive());
	bool tmp[9] = {0, 1, 0, 1};
	c.updateNeighbors(tmp);
	c.evolve();
	ASSERT_FALSE(c.isAlive());
}

TEST(FredkinCell, evolve_dead_4_live_neighbors_should_stay_dead)
{
	FredkinCell c('-');
	ASSERT_FALSE(c.isAlive());
	bool tmp[9] = {0, 1, 0, 1, 0, 1, 0, 1, 0};
	c.updateNeighbors(tmp);
	c.evolve();
	ASSERT_FALSE(c.isAlive());
}

TEST(FredkinCell, evolve_to_10_output_should_be_plus)
{
	FredkinCell c('0');
	ASSERT_TRUE(c.isAlive());
	bool tmp[9] = {0, 1}; // 1 live neighbor
	c.updateNeighbors(tmp);
	std::ostringstream w;
	for (int i = 0; i < 11; ++i)
	{
		c.evolve();
		ASSERT_TRUE(c.isAlive());
	}
    c.printSelf(w);
    ASSERT_TRUE(w.str() == "+");
}

TEST(FredkinCell, printSelf_live_cell_should_get_age)
{
	FredkinCell c('0');
	ASSERT_TRUE(c.isAlive());
	std::ostringstream w;
    c.printSelf(w);
    //std::cout << w.str() << std::endl;
    ASSERT_TRUE(w.str() == "0");
}

TEST(FredkinCell, printSelf_live_cell_should_get_age_one_after_evolve)
{
	FredkinCell c('0');
	ASSERT_TRUE(c.isAlive());
	std::ostringstream w;
	bool tmp[9] = {0, 1};
	c.updateNeighbors(tmp);
	c.evolve();
    c.printSelf(w);
    //std::cout << w.str() << std::endl;
    ASSERT_TRUE(w.str() == "1");
}

TEST(FredkinCell, printSelf_dead_cell_should_get_underscore)
{
	FredkinCell c('-');
	ASSERT_FALSE(c.isAlive());
	std::ostringstream w;
    c.printSelf(w);
    //std::cout << w.str() << std::endl;
    ASSERT_TRUE(w.str() == "_");
}

TEST(FredkinCell, clone_should_return_pointer_to_deep_copy)
{
	FredkinCell c('0');
	FredkinCell* d = c.clone();
	ASSERT_TRUE(d != &c);
	delete d; 
}

TEST(FredkinCell, equals_same_type_both_alive_should_return_true)
{
	FredkinCell c('0');
	FredkinCell d('0');
	ASSERT_TRUE(c.equals(d));
}

TEST(FredkinCell, equals_same_type_one_alive_should_return_false)
{
	FredkinCell c('0');
	FredkinCell d('-');
	ASSERT_FALSE(c.equals(d));
}

TEST(FredkinCell, equals_different_type_both_alive_should_return_false)
{
	FredkinCell c('0');
	ConwayCell d('*');
	ASSERT_FALSE(c.equals(d));
}

TEST(Cell, fredkinCell_turns_to_ConwayCell_at_age2)
{
	Cell c(new FredkinCell('0'));
	ASSERT_TRUE(c.isAlive());
	bool tmp[9] = {0, 1}; // 1 live neighbor
	c.updateNeighbors(tmp);
	ASSERT_TRUE(c.evolve() == 1);
	ASSERT_TRUE(c.evolve() == -1);
	std::ostringstream w;
	c.printSelf(w);
    //std::cout << w.str() << std::endl;
    ASSERT_TRUE(w.str() == "*");
}

TEST(Cell, isAlive_live_fredkinCell)
{
	Cell c(new FredkinCell('0'));
	ASSERT_TRUE(c.isAlive());
}

TEST(Cell, isAlive_dead_fredkinCell)
{
	Cell c(new FredkinCell('-'));
	ASSERT_FALSE(c.isAlive());
}

TEST(Cell, isAlive_live_ConwayCell)
{
	Cell c(new ConwayCell('*'));
	ASSERT_TRUE(c.isAlive());
}

TEST(Cell, isAlive_dead_ConwayCell)
{
	Cell c(new ConwayCell('.'));
	ASSERT_FALSE(c.isAlive());
}

TEST(Cell, live_fredkinCell_printSelf)
{
	Cell c(new FredkinCell('0'));
	ASSERT_TRUE(c.isAlive());
	std::ostringstream w;
	c.printSelf(w);
    //std::cout << w.str() << std::endl;
    ASSERT_TRUE(w.str() == "0");
}

TEST(Cell, dead_fredkinCell_printSelf)
{
	Cell c(new FredkinCell('-'));
	ASSERT_FALSE(c.isAlive());
	std::ostringstream w;
	c.printSelf(w);
    //std::cout << w.str() << std::endl;
    ASSERT_TRUE(w.str() == "_");
}

TEST(Cell, live_ConwayCell_printSelf)
{
	Cell c(new ConwayCell('*'));
	ASSERT_TRUE(c.isAlive());
	std::ostringstream w;
	c.printSelf(w);
    //std::cout << w.str() << std::endl;
    ASSERT_TRUE(w.str() == "*");
}

TEST(Cell, dead_ConwayCell_printSelf)
{
	Cell c(new ConwayCell('.'));
	ASSERT_FALSE(c.isAlive());
	std::ostringstream w;
	c.printSelf(w);
    //std::cout << w.str() << std::endl;
    ASSERT_TRUE(w.str() == ".");
}

TEST(Cell, conwayCell_evolve_alive_2_neighbors_should_stay_alive)
{
	Cell c(new ConwayCell('*'));
	ASSERT_TRUE(c.isAlive());
	bool tmp[9] = {1, 1};
	c.updateNeighbors(tmp);
	c.evolve();
	ASSERT_TRUE(c.isAlive());
}

TEST(Cell, conwayCell_evolve_alive_3_neighbors_should_stay_alive)
{
	Cell c(new ConwayCell('*'));
	ASSERT_TRUE(c.isAlive());
	bool tmp[9] = {1, 1, 1};
	c.updateNeighbors(tmp);
	c.evolve();
	ASSERT_TRUE(c.isAlive());
}

TEST(Cell, conwayCell_evolve_alive_1_neighbor_should_die)
{
	Cell c(new ConwayCell('*'));
	ASSERT_TRUE(c.isAlive());
	bool tmp[9] = {1};
	c.updateNeighbors(tmp);
	c.evolve();
	ASSERT_FALSE(c.isAlive());
}

TEST(Cell, fredkinCell_evolve_alive_1_neighbor_should_stay_alive)
{
	Cell c(new FredkinCell('0'));
	ASSERT_TRUE(c.isAlive());
	bool tmp[9] = {0, 1};
	c.updateNeighbors(tmp);
	c.evolve();
	ASSERT_TRUE(c.isAlive());
}

TEST(Cell, fredkinCell_evolve_alive_3_neighbors_should_stay_alive)
{
	Cell c(new FredkinCell('0'));
	ASSERT_TRUE(c.isAlive());
	bool tmp[9] = {0, 1, 0, 1, 0, 1};
	c.updateNeighbors(tmp);
	c.evolve();
	ASSERT_TRUE(c.isAlive());
}

TEST(Cell, fredkinCell_evolve_alive_0_neighbors_should_die)
{
	Cell c(new FredkinCell('0'));
	ASSERT_TRUE(c.isAlive());
	bool tmp[9] = {0};
	c.updateNeighbors(tmp);
	c.evolve();
	ASSERT_FALSE(c.isAlive());
}

TEST(Cell, fredkinCell_evolve_alive_2_neighbors_should_die)
{
	Cell c(new FredkinCell('0'));
	ASSERT_TRUE(c.isAlive());
	bool tmp[9] = {0, 1, 0, 1};
	c.updateNeighbors(tmp);
	c.evolve();
	ASSERT_FALSE(c.isAlive());
}

TEST(Cell, fredkinCell_evolve_alive_4_neighbors_should_die)
{
	Cell c(new FredkinCell('0'));
	ASSERT_TRUE(c.isAlive());
	bool tmp[9] = {0, 1, 0, 1, 0, 1, 0, 1};
	c.updateNeighbors(tmp);
	c.evolve();
	ASSERT_FALSE(c.isAlive());
}

TEST(Cell, fredkinCell_evolve_dead_1_live_neighbor_should_come_alive)
{
	Cell c(new FredkinCell('-'));
	ASSERT_FALSE(c.isAlive());
	bool tmp[9] = {0, 1};
	c.updateNeighbors(tmp);
	c.evolve();
	ASSERT_TRUE(c.isAlive());
}

TEST(Cell, fredkinCell_printSelf_live_cell_should_get_age)
{
	Cell c(new FredkinCell('0'));
	ASSERT_TRUE(c.isAlive());
	std::ostringstream w;
    c.printSelf(w);
    //std::cout << w.str() << std::endl;
    ASSERT_TRUE(w.str() == "0");
}

TEST(Cell, fredkinCell_printSelf_live_cell_should_get_age_one_after_evolve)
{
	Cell c(new FredkinCell('0'));
	ASSERT_TRUE(c.isAlive());
	std::ostringstream w;
	bool tmp[9] = {0, 1};
	c.updateNeighbors(tmp);
	c.evolve();
    c.printSelf(w);
    //std::cout << w.str() << std::endl;
    ASSERT_TRUE(w.str() == "1");
}

TEST(Cell, fredkinCell_printSelf_dead_cell_should_get_underscore)
{
	Cell c(new FredkinCell('-'));
	ASSERT_FALSE(c.isAlive());
	std::ostringstream w;
    c.printSelf(w);
    //std::cout << w.str() << std::endl;
    ASSERT_TRUE(w.str() == "_");
}