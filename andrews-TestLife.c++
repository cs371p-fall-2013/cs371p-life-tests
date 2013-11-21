// ------------------------------
// project4/TestLife.c++
// Copyright (C) 2013
// Andrew Solis/Mitch Stephan
// ------------------------------

// --------
// includes
// --------
#include "gtest/gtest.h"

// -------
// defines
// -------
#define protected public
#define private public

#include "Life.h"

// ------------------
// Conway constructor
// ------------------
TEST(ConwayCell, default_construct)
{
	ConwayCell cell;
	ASSERT_TRUE(cell._is_alive == false);
}

TEST(ConwayCell, construct_dead)
{
	ConwayCell cell(false);
	ASSERT_TRUE(cell._is_alive == false);
}

TEST(ConwayCell, construct_alive)
{
	ConwayCell cell(true);
	ASSERT_TRUE(cell._is_alive == true);
}

// ---------------------
// Conway change_state()
// ---------------------
TEST(ConwayCell, change_state_of_dead)
{
	ConwayCell cell;
	ASSERT_TRUE(cell._is_alive == false);
	cell.change_state();
	ASSERT_TRUE(cell._is_alive == true);
}

TEST(ConwayCell, change_state_of_alive)
{
	ConwayCell cell(true);
	ASSERT_TRUE(cell._is_alive == true);
	cell.change_state();
	ASSERT_TRUE(cell._is_alive == false);
}

// ---------------
// Conway evolve()
// ---------------
TEST(ConwayCell, evolve_when_dead_with_0_alive_becomes_dead)
{
	ConwayCell cell(false);
	bool alive_neighbors[8] = {false, false, false, false, false, false, false, false};
	char result = cell.evolve(alive_neighbors);
	ASSERT_TRUE(cell._is_alive == false);
	ASSERT_TRUE(result == '.');
}

TEST(ConwayCell, evolve_when_dead_with_1_alive_becomes_dead)
{
	ConwayCell cell(false);
	bool alive_neighbors[8] = {true, false, false, false, false, false, false, false};
	char result = cell.evolve(alive_neighbors);
	ASSERT_TRUE(cell._is_alive == false);
	ASSERT_TRUE(result == '.');
}

TEST(ConwayCell, evolve_when_dead_with_2_alive_becomes_dead)
{
	ConwayCell cell(false);
	bool alive_neighbors[8] = {true, true, false, false, false, false, false, false};
	char result = cell.evolve(alive_neighbors);
	ASSERT_TRUE(cell._is_alive == false);
	ASSERT_TRUE(result == '.');
}

TEST(ConwayCell, evolve_when_dead_with_3_alive_becomes_alive)
{
	ConwayCell cell(false);
	bool alive_neighbors[8] = {true, true, true, false, false, false, false, false};
	char result = cell.evolve(alive_neighbors);
	ASSERT_TRUE(cell._is_alive == true);
	ASSERT_TRUE(result == '*');
}

TEST(ConwayCell, evolve_when_dead_with_4_alive_becomes_dead)
{
	ConwayCell cell(false);
	bool alive_neighbors[8] = {true, true, true, true, false, false, false, false};
	char result = cell.evolve(alive_neighbors);
	ASSERT_TRUE(cell._is_alive == false);
	ASSERT_TRUE(result == '.');
}

TEST(ConwayCell, evolve_when_dead_with_5_alive_becomes_dead)
{
	ConwayCell cell(false);
	bool alive_neighbors[8] = {true, true, true, true, true, false, false, false};
	char result = cell.evolve(alive_neighbors);
	ASSERT_TRUE(cell._is_alive == false);
	ASSERT_TRUE(result == '.');
}

TEST(ConwayCell, evolve_when_dead_with_6_alive_becomes_dead)
{
	ConwayCell cell(false);
	bool alive_neighbors[8] = {true, true, true, true, true, true, false, false};
	char result = cell.evolve(alive_neighbors);
	ASSERT_TRUE(cell._is_alive == false);
	ASSERT_TRUE(result == '.');
}

TEST(ConwayCell, evolve_when_dead_with_7_alive_becomes_dead)
{
	ConwayCell cell(false);
	bool alive_neighbors[8] = {true, true, true, true, true, true, true, false};
	char result = cell.evolve(alive_neighbors);
	ASSERT_TRUE(cell._is_alive == false);
	ASSERT_TRUE(result == '.');
}

TEST(ConwayCell, evolve_when_dead_with_8_alive_becomes_dead)
{
	ConwayCell cell(false);
	bool alive_neighbors[8] = {true, true, true, true, true, true, true, true};
	char result = cell.evolve(alive_neighbors);
	ASSERT_TRUE(cell._is_alive == false);
	ASSERT_TRUE(result == '.');
}

TEST(ConwayCell, evolve_when_alive_with_0_alive_becomes_dead)
{
	ConwayCell cell(true);
	bool alive_neighbors[8] = {false, false, false, false, false, false, false, false};
	char result = cell.evolve(alive_neighbors);
	ASSERT_TRUE(cell._is_alive == false);
	ASSERT_TRUE(result == '.');
}

TEST(ConwayCell, evolve_when_alive_with_1_alive_becomes_dead)
{
	ConwayCell cell(true);
	bool alive_neighbors[8] = {true, false, false, false, false, false, false, false};
	char result = cell.evolve(alive_neighbors);
	ASSERT_TRUE(cell._is_alive == false);
	ASSERT_TRUE(result == '.');
}

TEST(ConwayCell, evolve_when_alive_with_2_alive_becomes_alive)
{
	ConwayCell cell(true);
	bool alive_neighbors[8] = {true, true, false, false, false, false, false, false};
	char result = cell.evolve(alive_neighbors);
	ASSERT_TRUE(cell._is_alive == true);
	ASSERT_TRUE(result == '*');
}

TEST(ConwayCell, evolve_when_alive_with_3_alive_becomes_alive)
{
	ConwayCell cell(true);
	bool alive_neighbors[8] = {true, true, true, false, false, false, false, false};
	char result = cell.evolve(alive_neighbors);
	ASSERT_TRUE(cell._is_alive == true);
	ASSERT_TRUE(result == '*');
}

TEST(ConwayCell, evolve_when_alive_with_4_alive_becomes_dead)
{
	ConwayCell cell(true);
	bool alive_neighbors[8] = {true, true, true, true, false, false, false, false};
	char result = cell.evolve(alive_neighbors);
	ASSERT_TRUE(cell._is_alive == false);
	ASSERT_TRUE(result == '.');
}

TEST(ConwayCell, evolve_when_alive_with_5_alive_becomes_dead)
{
	ConwayCell cell(true);
	bool alive_neighbors[8] = {true, true, true, true, true, false, false, false};
	char result = cell.evolve(alive_neighbors);
	ASSERT_TRUE(cell._is_alive == false);
	ASSERT_TRUE(result == '.');
}

TEST(ConwayCell, evolve_when_alive_with_6_alive_becomes_dead)
{
	ConwayCell cell(true);
	bool alive_neighbors[8] = {true, true, true, true, true, true, false, false};
	char result = cell.evolve(alive_neighbors);
	ASSERT_TRUE(cell._is_alive == false);
	ASSERT_TRUE(result == '.');
}

TEST(ConwayCell, evolve_when_alive_with_7_alive_becomes_dead)
{
	ConwayCell cell(true);
	bool alive_neighbors[8] = {true, true, true, true, true, true, true, false};
	char result = cell.evolve(alive_neighbors);
	ASSERT_TRUE(cell._is_alive == false);
	ASSERT_TRUE(result == '.');
}

TEST(ConwayCell, evolve_when_alive_with_8_alive_becomes_dead)
{
	ConwayCell cell(true);
	bool alive_neighbors[8] = {true, true, true, true, true, true, true, true};
	char result = cell.evolve(alive_neighbors);
	ASSERT_TRUE(cell._is_alive == false);
	ASSERT_TRUE(result == '.');
}

// --------------
// Conway clone()
// --------------
TEST(ConwayCell, clone_alive_conway)
{
	ConwayCell cell(true);
	ConwayCell* p = cell.clone();
	ASSERT_TRUE(p->_is_alive);
	ASSERT_TRUE(p->to_char() == '*');
	p->change_state();
	ASSERT_TRUE(p->_is_alive == false);
	ASSERT_TRUE(p->to_char() == '.');
	delete p;
}

TEST(ConwayCell, clone_dead_conway)
{
	ConwayCell cell;
	ConwayCell* p = cell.clone();
	ASSERT_TRUE(p->_is_alive == false);
	ASSERT_TRUE(p->to_char() == '.');
	p->change_state();
	ASSERT_TRUE(p->_is_alive);
	ASSERT_TRUE(p->to_char() == '*');
	delete p;
}

// -------------------
// Fredkin constructor
// -------------------
TEST(FredkinCell, default_construct)
{
	FredkinCell cell;
	ASSERT_TRUE(cell._is_alive == false);
	ASSERT_TRUE(cell._age == 0);
}

TEST(FredkinCell, construct_dead)
{
	FredkinCell cell(false);
	ASSERT_TRUE(cell._is_alive == false);
	ASSERT_TRUE(cell._age == 0);
}

TEST(FredkinCell, construct_alive)
{
	FredkinCell cell(true, 0);
	ASSERT_TRUE(cell._is_alive == true);
	ASSERT_TRUE(cell._age == 0);
}

// ----------------------
// Fredkin change_state()
// ----------------------
TEST(FredkinCell, change_state_of_dead)
{
	FredkinCell cell;
	ASSERT_TRUE(cell._is_alive == false);
	cell.change_state();
	ASSERT_TRUE(cell._is_alive == true);
}

TEST(FredkinCell, change_state_of_alive)
{
	FredkinCell cell(true);
	ASSERT_TRUE(cell._is_alive == true);
	cell.change_state();
	ASSERT_TRUE(cell._is_alive == false);
}

// ---------------
// Fredkin evolve()
// ---------------
TEST(FredkinCell, evolve_when_dead_with_0_alive_becomes_dead)
{
	FredkinCell cell(false);
	bool alive_neighbors[8] = {false, false, false, false, false, false, false, false};
	char result = cell.evolve(alive_neighbors);
	ASSERT_TRUE(cell._is_alive == false);
	ASSERT_TRUE(cell._age == 0);
	ASSERT_TRUE(result == '-');
}

TEST(FredkinCell, evolve_when_dead_with_1_alive_becomes_alive)
{
	FredkinCell cell(false);
	bool alive_neighbors[8] = {false, true, false, false, false, false, false, false};
	char result = cell.evolve(alive_neighbors);
	ASSERT_TRUE(cell._is_alive == true);
	ASSERT_TRUE(cell._age == 0);
	ASSERT_TRUE(result == '0');
}

TEST(FredkinCell, evolve_when_dead_with_2_alive_becomes_dead)
{
	FredkinCell cell(false);
	bool alive_neighbors[8] = {false, true, false, true, false, false, false, false};
	char result = cell.evolve(alive_neighbors);
	ASSERT_TRUE(cell._is_alive == false);
	ASSERT_TRUE(cell._age == 0);
	ASSERT_TRUE(result == '-');
}

TEST(FredkinCell, evolve_when_dead_with_3_alive_becomes_alive)
{
	FredkinCell cell(false);
	bool alive_neighbors[8] = {false, true, false, true, true, false, false, false};
	char result = cell.evolve(alive_neighbors);
	ASSERT_TRUE(cell._is_alive == true);
	ASSERT_TRUE(cell._age == 0);
	ASSERT_TRUE(result == '0');
}

TEST(FredkinCell, evolve_when_dead_with_4_alive_becomes_dead)
{
	FredkinCell cell(false);
	bool alive_neighbors[8] = {false, true, false, true, true, false, true, false};
	char result = cell.evolve(alive_neighbors);
	ASSERT_TRUE(cell._is_alive == false);
	ASSERT_TRUE(cell._age == 0);
	ASSERT_TRUE(result == '-');
}

TEST(FredkinCell, evolve_when_alive_with_0_alive_becomes_dead)
{
	FredkinCell cell(true);
	bool alive_neighbors[8] = {false, false, false, false, false, false, false, false};
	char result = cell.evolve(alive_neighbors);
	ASSERT_TRUE(cell._is_alive == false);
	ASSERT_TRUE(cell._age == 0);
	ASSERT_TRUE(result == '-');
}

TEST(FredkinCell, evolve_when_alive_with_1_alive_becomes_alive)
{
	FredkinCell cell(true);
	bool alive_neighbors[8] = {false, true, false, false, false, false, false, false};
	char result = cell.evolve(alive_neighbors);
	ASSERT_TRUE(cell._is_alive == true);
	ASSERT_TRUE(cell._age == 1);
	ASSERT_TRUE(result == '1');
}

TEST(FredkinCell, evolve_when_alive_with_2_alive_becomes_dead)
{
	FredkinCell cell(true);
	bool alive_neighbors[8] = {false, true, false, true, false, false, false, false};
	char result = cell.evolve(alive_neighbors);
	ASSERT_TRUE(cell._is_alive == false);
	ASSERT_TRUE(result == '-');
}

TEST(FredkinCell, evolve_when_alive_with_3_alive_becomes_alive)
{
	FredkinCell cell(true);
	bool alive_neighbors[8] = {false, true, false, true, true, false, false, false};
	char result = cell.evolve(alive_neighbors);
	ASSERT_TRUE(cell._is_alive == true);
	ASSERT_TRUE(cell._age == 1);
	ASSERT_TRUE(result == '1');
}

TEST(FredkinCell, evolve_when_alive_with_4_alive_becomes_dead)
{
	FredkinCell cell(true);
	bool alive_neighbors[8] = {false, true, false, true, true, false, true, false};
	char result = cell.evolve(alive_neighbors);
	ASSERT_TRUE(cell._is_alive == false);
	ASSERT_TRUE(result == '-');
}

// --------------
// Fredkin clone()
// --------------
TEST(FredkinCell, clone_alive_fredkin)
{
	FredkinCell cell(true);
	FredkinCell* p = cell.clone();
	ASSERT_TRUE(p->_is_alive);
	ASSERT_TRUE(p->_age == 0);
	ASSERT_TRUE(p->to_char() == '0');
	p->change_state();
	ASSERT_TRUE(p->_is_alive == false);
	ASSERT_TRUE(p->_age == 0);
	ASSERT_TRUE(p->to_char() == '-');
	delete p;
}

TEST(FredkinCell, clone_dead_fredkin)
{
	FredkinCell cell;
	FredkinCell* p = cell.clone();
	ASSERT_TRUE(p->_is_alive == false);
	ASSERT_TRUE(p->_age == 0);
	ASSERT_TRUE(p->to_char() == '-');
	p->change_state();
	ASSERT_TRUE(p->_is_alive);
	ASSERT_TRUE(p->_age == 0);
	ASSERT_TRUE(p->to_char() == '0');
	delete p;
}

// ----------------
// Cell constructor
// ----------------
TEST(Cell, default_constructor)
{
	Cell cell;
}

TEST(Cell, assignment_constructor_with_dead_fredkin)
{
	Cell cell = new FredkinCell;
}

TEST(Cell, assignment_constructor_with_alive_conway)
{
	Cell cell = new ConwayCell(true);
}

// --------------
// Cell to_char()
// --------------
TEST(Cell, to_char_alive_conway)
{
	Cell cell = new ConwayCell(true);
	ASSERT_TRUE(cell.to_char() == '*');
}

TEST(Cell, to_char_dead_fredkin)
{
	Cell cell;
	ASSERT_TRUE(cell.to_char() == '-');
}

// -------------------
// Cell change_state()
// -------------------
TEST(Cell, change_state_conway)
{
	Cell cell = new ConwayCell;
	ASSERT_TRUE(cell.to_char() == '.');
	cell.change_state();
	ASSERT_TRUE(cell.to_char() == '*');
	cell.change_state();
	ASSERT_TRUE(cell.to_char() == '.');
}

TEST(Cell, change_state_fredkin)
{
	Cell cell;
	ASSERT_TRUE(cell.to_char() == '-');
	cell.change_state();
	ASSERT_TRUE(cell.to_char() == '0');
	cell.change_state();
	ASSERT_TRUE(cell.to_char() == '-');
}

// -------------
// Cell mutate()
// -------------
TEST(Cell, mutate)
{
	FredkinCell* p = new FredkinCell(true);
	p->_age = 2;
	Cell cell(p);
	ASSERT_TRUE(cell.to_char() == '2');
	cell.mutate();
	ASSERT_TRUE(cell.to_char() == '*');
}

// -------------
// Cell evolve()
// -------------
TEST(Cell, evolve_conway)
{
	Cell cell = new ConwayCell;
	ASSERT_TRUE(cell.to_char() == '.');
	bool alive_neighbors[8] = {true, true, true, false, false, false, false, false};
	cell.evolve(alive_neighbors);
	ASSERT_TRUE(cell.to_char() == '*');
}

TEST(Cell, evolve_fredkin)
{
	Cell cell;
	ASSERT_TRUE(cell.to_char() == '-');
	bool alive_neighbors[8] = {false, true, false, false, false, false, false, false};
	cell.evolve(alive_neighbors);
	ASSERT_TRUE(cell.to_char() == '0');
}

TEST(Cell, evolve_with_mutate)
{
	FredkinCell* p = new FredkinCell(true);
	p->_age = 1;
	Cell cell(p);
	ASSERT_TRUE(cell.to_char() == '1');
	bool alive_neighbors[8] = {false, true, false, false, false, false, false, false};
	cell.evolve(alive_neighbors);
	ASSERT_TRUE(cell.to_char() == '*');
}

// ----------------
// Life constructor
// ----------------
TEST(Life, construct_conway_10x10)
{
	Life<ConwayCell> life(10, 10);
	ASSERT_TRUE(life._world.size() == 10);
	ASSERT_TRUE(life._world[0].size() == 10);
	ASSERT_TRUE(life._board.size() == 10);
	ASSERT_TRUE(life._board[0].size() == 10);
	ASSERT_TRUE(life._population == 0);
	ASSERT_TRUE(life._generation == 0);
}

TEST(Life, construct_fredkin_10x10)
{
	Life<FredkinCell> life(10, 10);
	ASSERT_TRUE(life._world.size() == 10);
	ASSERT_TRUE(life._world[0].size() == 10);
	ASSERT_TRUE(life._board.size() == 10);
	ASSERT_TRUE(life._board[0].size() == 10);
	ASSERT_TRUE(life._population == 0);
	ASSERT_TRUE(life._generation == 0);
}

TEST(Life, construct_cell_10x10)
{
	Life<Cell> life(10, 10);
	ASSERT_TRUE(life._world.size() == 10);
	ASSERT_TRUE(life._world[0].size() == 10);
	ASSERT_TRUE(life._board.size() == 10);
	ASSERT_TRUE(life._board[0].size() == 10);
	ASSERT_TRUE(life._population == 0);
	ASSERT_TRUE(life._generation == 0);
}

// ---------------------
// Life generate_board()
// ---------------------
TEST(Life, generate_board_for_all_dead_5x5)
{
	Life<FredkinCell> life(5, 5);
	life.generate_board();

	for (size_t i = 0; i < 5; ++i)
	{
		for (size_t j = 0; j < 5; ++j)
		{
			ASSERT_TRUE(life._board[i][j] == '-');
		}
	}
	ASSERT_TRUE(life._population == 0);
}

TEST(Life, generate_board_for_all_alive_2x17)
{
	Life<ConwayCell> life(2, 17);

	for (size_t i = 0; i < 2; ++i)
	{
		for (size_t j = 0; j < 17; ++j)
		{
			life._world[i][j].change_state();
		}
	}
	life.generate_board();

	for (size_t i = 0; i < 2; ++i)
	{
		for (size_t j = 0; j < 17; ++j)
		{
			ASSERT_TRUE(life._board[i][j] == '*');
		}
	}
	ASSERT_TRUE(life._population == 34);
}

TEST(Life, generate_board_for_dead_and_alive_1x2)
{
	Life<FredkinCell> life(5, 5);
	life._world[0][0].change_state();
	life._world[0][1].change_state();
	life._world[0][1].change_state();
	life.generate_board();
	ASSERT_TRUE(life._board[0][0] == '0');
	ASSERT_TRUE(life._board[0][1] == '-');
	ASSERT_TRUE(life._population == 1);
}

// -----------------
// Life read_world()
// -----------------
TEST(Life, read_world_dead_1x2)
{
	Life<ConwayCell> life(1, 2);
	std::istringstream input("..");

	ASSERT_TRUE(life.read_world(input));

	for (size_t i = 0; i < 1; ++i)
	{
		for (size_t j = 0; j < 2; ++j)
		{
			ASSERT_TRUE(life._board[i][j] == '.');
		}
	}
	ASSERT_TRUE(life._population == 0);
}

TEST(Life, read_world_alive_2x4)
{
	Life<FredkinCell> life(2, 4);
	std::istringstream input("0000\n0000\n");

	ASSERT_TRUE(life.read_world(input));

	for (size_t i = 0; i < 2; ++i)
	{
		for (size_t j = 0; j < 4; ++j)
		{
			ASSERT_TRUE(life._board[i][j] == '0');
		}
	}
	ASSERT_TRUE(life._population == 8);
}

// -----------------
// Life print_life()
// -----------------
TEST(Life, print_life_dead_1x2)
{
	Life<FredkinCell> life(1, 2);
	std::ostringstream output;
	life.generate_board();
	life.print_life(output);
	ASSERT_TRUE(output.str() == "\nGeneration = 0, Population = 0.\n--\n");
}

TEST(Life, print_life_alive_4x2)
{
	Life<ConwayCell> life(4, 2);
	std::ostringstream output;

	for (size_t i = 0; i < 4; ++i)
	{
		for (size_t j = 0; j < 2; ++j)
		{
			life._world[i][j].change_state();
		}
	}

	life.generate_board();
	life.print_life(output);
	ASSERT_TRUE(output.str() == "\nGeneration = 0, Population = 8.\n**\n**\n**\n**\n");
}

// ----------------------
// Life build_neighbors()
// ----------------------
TEST(Life, build_neighbors_when_all_dead)
{
	Life<ConwayCell> life(3, 3);
	bool alive_neighbors[8] = {};
	life.generate_board();

	int num_alive = life.build_neighbors(1, 1, alive_neighbors);

	for (size_t i = 0; i < 8; ++i)
	{
		if (alive_neighbors[i])
		{
			ASSERT_TRUE(false);
		}
	}

	ASSERT_TRUE(num_alive == 0);
}

TEST(Life, build_neighbors_when_all_out_of_bounds)
{
	Life<ConwayCell> life(1, 1);
	bool alive_neighbors[8] = {};
	life.generate_board();

	int num_alive = life.build_neighbors(0, 0, alive_neighbors);

	for (size_t i = 0; i < 8; ++i)
	{
		if (alive_neighbors[i])
		{
			ASSERT_TRUE(false);
		}
	}

	ASSERT_TRUE(num_alive == 0);
}

TEST(Life, build_neighbors_when_all_alive)
{
	Life<ConwayCell> life(3, 3);
	bool alive_neighbors[8] = {};

	life._world[0][0].change_state();
	life._world[0][1].change_state();
	life._world[0][2].change_state();
	life._world[1][0].change_state();
	life._world[1][2].change_state();
	life._world[2][0].change_state();
	life._world[2][1].change_state();
	life._world[2][2].change_state();

	life.generate_board();

	int num_alive = life.build_neighbors(1,1, alive_neighbors);

	for (size_t i = 0; i < 8; ++i)
	{
		if (alive_neighbors[i])
		{
			ASSERT_TRUE(true);
		}
	}
	ASSERT_TRUE(num_alive == 8);
}


TEST(Life, build_neighbors_when_one_alive_in_corner)
{
	Life<ConwayCell> life(3, 3);
	bool alive_neighbors[8] = {};
	int num_alive;

	life._world[0][0].change_state();
	life.generate_board();
	
	num_alive = life.build_neighbors(0, 0, alive_neighbors);
	ASSERT_TRUE(num_alive == 0);

	num_alive = life.build_neighbors(0, 1, alive_neighbors);
	ASSERT_TRUE(num_alive == 1);

	num_alive = life.build_neighbors(1, 0, alive_neighbors);
	ASSERT_TRUE(num_alive == 1);

	num_alive = life.build_neighbors(1, 1, alive_neighbors);
	ASSERT_TRUE(num_alive == 1);
}

TEST(Life, build_neighbors_around_one_alive)
{
	Life<ConwayCell> life(3, 3);
	bool alive_neighbors[8] = {};
	int num_alive;

	life._world[1][1].change_state();
	life.generate_board();

	num_alive = life.build_neighbors(0, 0, alive_neighbors);
	ASSERT_TRUE(num_alive == 1);
	ASSERT_TRUE(alive_neighbors[7]);

	num_alive = life.build_neighbors(0, 1, alive_neighbors);
	ASSERT_TRUE(num_alive == 1);
	ASSERT_TRUE(alive_neighbors[6]);

	num_alive = life.build_neighbors(0, 2, alive_neighbors);
	ASSERT_TRUE(num_alive == 1);
	ASSERT_TRUE(alive_neighbors[5]);

	num_alive = life.build_neighbors(1, 0, alive_neighbors);
	ASSERT_TRUE(num_alive == 1);
	ASSERT_TRUE(alive_neighbors[4]);

	num_alive = life.build_neighbors(1, 1, alive_neighbors);
	ASSERT_TRUE(num_alive == 0);

	num_alive = life.build_neighbors(1, 2, alive_neighbors);
	ASSERT_TRUE(num_alive == 1);
	ASSERT_TRUE(alive_neighbors[3]);

	num_alive = life.build_neighbors(2, 0, alive_neighbors);
	ASSERT_TRUE(num_alive == 1);
	ASSERT_TRUE(alive_neighbors[2]);

	num_alive = life.build_neighbors(2, 1, alive_neighbors);
	ASSERT_TRUE(num_alive == 1);
	ASSERT_TRUE(alive_neighbors[1]);

	num_alive = life.build_neighbors(2, 2, alive_neighbors);
	ASSERT_TRUE(num_alive == 1);
	ASSERT_TRUE(alive_neighbors[0]);
}

// -----------------------
// Life, next_generation()
// -----------------------
TEST(Life, next_generation_with_conway)
{
	Life<ConwayCell> life(3, 3);

	life._world[0][0].change_state();
	life._world[0][2].change_state();
	life._world[2][1].change_state();
	life.generate_board();
	ASSERT_TRUE(life._population == 3);

	life.next_generation();
	ASSERT_TRUE(life._population == 1);
	ASSERT_TRUE(life._board[0][0] == '.');
	ASSERT_TRUE(life._board[0][2] == '.');
	ASSERT_TRUE(life._board[2][1] == '.');
	ASSERT_TRUE(life._board[1][1] == '*');

	life.next_generation();
	ASSERT_TRUE(life._population == 0);
	ASSERT_TRUE(life._board[0][0] == '.');
	ASSERT_TRUE(life._board[0][2] == '.');
	ASSERT_TRUE(life._board[2][1] == '.');
	ASSERT_TRUE(life._board[1][1] == '.');
}

TEST(Life, next_generation_with_fredkin)
{
	Life<FredkinCell> life(3, 3);
	life._world[0][0].change_state();
	life._world[2][1].change_state();
	life.generate_board();
	ASSERT_TRUE(life._population == 2);

	life.next_generation();
	ASSERT_TRUE(life._generation == 1);
	ASSERT_TRUE(life._population == 5);
	ASSERT_TRUE(life._board[0][0] == '-');
	ASSERT_TRUE(life._board[0][1] == '0');
	ASSERT_TRUE(life._board[0][2] == '-');
	ASSERT_TRUE(life._board[1][0] == '0');
	ASSERT_TRUE(life._board[1][1] == '0');
	ASSERT_TRUE(life._board[1][2] == '-');
	ASSERT_TRUE(life._board[2][0] == '0');
	ASSERT_TRUE(life._board[2][1] == '-');
	ASSERT_TRUE(life._board[2][2] == '0');

	life.next_generation();
	ASSERT_TRUE(life._generation == 2);
	ASSERT_TRUE(life._population == 4);
	ASSERT_TRUE(life._board[0][0] == '-');
	ASSERT_TRUE(life._board[0][1] == '1');
	ASSERT_TRUE(life._board[0][2] == '0');
	ASSERT_TRUE(life._board[1][0] == '-');
	ASSERT_TRUE(life._board[1][1] == '-');
	ASSERT_TRUE(life._board[1][2] == '-');
	ASSERT_TRUE(life._board[2][0] == '1');
	ASSERT_TRUE(life._board[2][1] == '0');
	ASSERT_TRUE(life._board[2][2] == '-');

	life.next_generation();
	ASSERT_TRUE(life._generation == 3);
	ASSERT_TRUE(life._population == 8);
	ASSERT_TRUE(life._board[0][0] == '0');
	ASSERT_TRUE(life._board[0][1] == '2');
	ASSERT_TRUE(life._board[0][2] == '1');
	ASSERT_TRUE(life._board[1][0] == '0');
	ASSERT_TRUE(life._board[1][1] == '-');
	ASSERT_TRUE(life._board[1][2] == '0');
	ASSERT_TRUE(life._board[2][0] == '2');
	ASSERT_TRUE(life._board[2][1] == '1');
	ASSERT_TRUE(life._board[2][2] == '0');

	life.next_generation();
	ASSERT_TRUE(life._generation == 4);
	ASSERT_TRUE(life._population == 0);
	ASSERT_TRUE(life._board[0][0] == '-');
	ASSERT_TRUE(life._board[0][1] == '-');
	ASSERT_TRUE(life._board[0][2] == '-');
	ASSERT_TRUE(life._board[1][0] == '-');
	ASSERT_TRUE(life._board[1][1] == '-');
	ASSERT_TRUE(life._board[1][2] == '-');
	ASSERT_TRUE(life._board[2][0] == '-');
	ASSERT_TRUE(life._board[2][1] == '-');
	ASSERT_TRUE(life._board[2][2] == '-');
}
// end of file