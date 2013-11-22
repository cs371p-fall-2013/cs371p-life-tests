// -----------------------------
// CS371P - Assignment #5 - Life
// Benjamin Pang
// bp7936 - bpang@utexas.edu
// -----------------------------

/*
To test the program:
    % ls -al /usr/include/gtest/
    ...
    gtest.h
    ...

    % locate libgtest.a
    /usr/lib/libgtest.a

    % locate libpthread.a
    /usr/lib/x86_64-linux-gnu/libpthread.a
    /usr/lib32/libpthread.a

    % locate libgtest_main.a
    /usr/lib/libgtest_main.a

    % g++ -pedantic -std=c++0x -Wall AbstractCell.c++ Cell.c++ ConwayCell.c++ FredkinCell.c++ TestLife.c++ -o TestLife -lgtest -lpthread -lgtest_main

    % valgrind TestLife > TestLife.out
*/

// --------
// TestLife
// --------

// -------
// defines
// -------

#define private public
#define protected public

// --------
// includes
// --------

#include "gtest/gtest.h"
#include <vector>
#include <sstream>

#include "AbstractCell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"
#include "Life.h"

// ----------
// namespaces
// ----------

using namespace std;

TEST(Life, abstractc_is_alive_1)
{
	ConwayCell c;
	ASSERT_FALSE(c.is_alive());
}

TEST(Life, abstractc_is_alive_2)
{
	FredkinCell c;
	ASSERT_FALSE(c.is_alive());
}

TEST(Life, abstractc_is_alive_3)
{
	ConwayCell c(true);
	ASSERT_TRUE(c.is_alive());
}

TEST(Life, abstractc_is_alive_4)
{
	FredkinCell c(true);
	ASSERT_TRUE(c.is_alive());
}

TEST(Life, abstractc_copy_assignment_1)
{
	ConwayCell c(true, '*');
	ConwayCell c2;
	c2 = c;
	ASSERT_EQ(c.is_alive(), c2.is_alive());
	ASSERT_EQ(c._c, c2._c);
}

TEST(Life, abstractc_copy_assignment_2)
{
	FredkinCell c(true, '+');
	FredkinCell c2;
	c2 = c;
	ASSERT_EQ(c.is_alive(), c2.is_alive());
	ASSERT_EQ(c._c, c2._c);
}

TEST(Life, abstractc_copy_assignment_3)
{
	ConwayCell c(false, '%');
	ConwayCell c2;
	ASSERT_FALSE(c._c == c2._c);
	c2 = c;
	ASSERT_EQ(c._c, c2._c);
}

TEST(Life, conwayc_constructor_1)
{
	ConwayCell c;
	ASSERT_FALSE(c.is_alive());
	ASSERT_EQ('.', c._c);
}

TEST(Life, conwayc_constructor_2)
{
	ConwayCell c(true);
	ASSERT_TRUE(c.is_alive());
	ASSERT_EQ('.', c._c);
}

TEST(Life, conwayc_constructor_3)
{
	ConwayCell c(true, '*');
	ASSERT_TRUE(c.is_alive());
	ASSERT_EQ('*', c._c);
}

TEST(Life, conwayc_evolve_1)
{
	ConwayCell c(true, '*');
	vector<bool> neighbors(8, false);
	ASSERT_FALSE(c.evolve(neighbors));
	ASSERT_FALSE(c.is_alive());
	ASSERT_EQ('.', c._c);
}

TEST(Life, conwayc_evolve_2)
{
	ConwayCell c(false);
	vector<bool> neighbors(8, false);
	for(int i = 0; i < 3; i++)
		neighbors[i] = true;
	ASSERT_FALSE(c.evolve(neighbors));
	ASSERT_TRUE(c.is_alive());
	ASSERT_EQ('*', c._c);
}

TEST(Life, conwayc_evolve_3)
{
	ConwayCell c(true, '*');
	vector<bool> neighbors(8, true);
	ASSERT_FALSE(c.evolve(neighbors));
	ASSERT_FALSE(c.is_alive());
	ASSERT_EQ('.', c._c);
}

TEST(Life, conwayc_print_1)
{
	ostringstream output;
	ConwayCell c;
	c.print(output);
	ASSERT_EQ(".", output.str());
}

TEST(Life, conwayc_print_2)
{
	ostringstream output;
	ConwayCell c(true, '9');
	c.print(output);
	ASSERT_EQ("9", output.str());
}

TEST(Life, conwayc_print_3)
{
	ostringstream output;
	ConwayCell c(true, '*');
	c.print(output);
	ASSERT_EQ("*", output.str());
}

TEST(Life, conwayc_print_4)
{
	ostringstream output;
	ConwayCell c(true);
	c.print(output);
	ASSERT_EQ(".", output.str());
}

TEST(Life, conwayc_print_5)
{
	ostringstream output;
	ConwayCell c(true, '0');
	c.print(output);
	ASSERT_EQ("0", output.str());
}

TEST(Life, conwayc_print_6)
{
	ostringstream output;
	ConwayCell c(false, '%');
	c.print(output);
	ASSERT_EQ("%", output.str());
}

TEST(Life, conwayc_clone_1)
{
	ConwayCell c;
	ConwayCell c2 = c.clone();
	ASSERT_EQ(c._c, c2._c);
}

TEST(Life, conwayc_clone_2)
{
	ConwayCell c(true);
	ConwayCell c2 = c.clone();
	ASSERT_EQ(c.is_alive(), c2.is_alive());
}

TEST(Life, conwayc_clone_3)
{
	ConwayCell c(true, '*');
	ConwayCell c2 = c.clone();
	c2._c = c._c;
	ASSERT_EQ(c._c, c2._c);
}

TEST(Life, fredkinc_constructor_1)
{
	FredkinCell c;
	ASSERT_FALSE(c.is_alive());
	ASSERT_EQ('-', c._c);
	ASSERT_EQ(0, c._age);
}

TEST(Life, fredkinc_constructor_2)
{
	FredkinCell c(true, '+', 11);
	ASSERT_TRUE(c.is_alive());
	ASSERT_EQ('+', c._c);
	ASSERT_EQ(11, c._age);
}

TEST(Life, fredkinc_constructor_3)
{
	FredkinCell c(false, '0');
	ASSERT_FALSE(c.is_alive());
	ASSERT_EQ('0', c._c);
	ASSERT_EQ(0, c._age);
}

TEST(Life, fredkinc_evolve_1)
{
    FredkinCell c(false, '-');
    vector<bool> neighbors(8, false);
    ASSERT_FALSE(c.evolve(neighbors));
    ASSERT_FALSE(c.is_alive());
    ASSERT_EQ('-', c._c);
}

TEST(Life, fredkinc_evolve_2)
{
    FredkinCell c(true, '1', 1);
    vector<bool> neighbors(8, false);
	neighbors[1] = true;
    ASSERT_TRUE(c.evolve(neighbors));
    ASSERT_TRUE(c.is_alive());
    ASSERT_EQ('2', c._c);
}

TEST(Life, fredkinc_evolve_3)
{
    FredkinCell c(false, '-', 0);
    vector<bool> neighbors(8, false);
	neighbors[1] = true;
	neighbors[3] = true;
	neighbors[4] = true;
    ASSERT_FALSE(c.evolve(neighbors));
    ASSERT_TRUE(c.is_alive());
    ASSERT_EQ('0', c._c);
}

TEST(Life, fredkinc_print_1)
{
    ostringstream output;
    FredkinCell c;
    c.print(output);
    ASSERT_EQ("-", output.str());
}

TEST(Life, fredkinc_print_2)
{
	ostringstream output;
	FredkinCell c(true, '5', 5);
	c.print(output);
	ASSERT_EQ("5", output.str());
}

TEST(Life, fredkinc_print_3)
{
	ostringstream output;
	FredkinCell c(true, '+', 12);
	c.print(output);
	ASSERT_EQ("+", output.str());
}

TEST(Life, fredkinc_print_4)
{
	ostringstream output;
	FredkinCell c(false, '-', 5);
	c.print(output);
	ASSERT_EQ("-", output.str());
}

TEST(Life, fredkinc_print_5)
{
	ostringstream output;
	FredkinCell c(false);
	c.print(output);
	ASSERT_EQ("-", output.str());
}

TEST(Life, fredkinc_print_6)
{
	ostringstream output;
	FredkinCell c(true, '9', 9);
	c.print(output);
	ASSERT_EQ("9", output.str());
}

TEST(Life, fredkinc_clone_1)
{
    FredkinCell c;
    FredkinCell c2 = c.clone();
    ASSERT_EQ(c._c, c2._c);
}

TEST(Life, fredkinc_clone_2)
{
    FredkinCell c(true);
    FredkinCell c2 = c.clone();
    ASSERT_EQ(c.is_alive(), c2.is_alive());
}

TEST(Life, fredkinc_clone_3)
{
    FredkinCell c(true, '0');
    FredkinCell c2 = c.clone();
    c2._c = c._c;
    ASSERT_EQ(c._c, c2._c);
}

TEST(Life, cell_evolve_1)
{
	Cell c;
	vector<bool> neighbors(8, false);
	neighbors[1] = true;
	neighbors[3] = true;
	neighbors[4] = true;
	ASSERT_FALSE(c.evolve(neighbors));
	ASSERT_TRUE(c.is_alive());
}

TEST(Life, cell_evolve_2)
{
	Cell c;
	vector<bool> neighbors(8, false);
	ASSERT_FALSE(c.evolve(neighbors));
	ASSERT_FALSE(c.is_alive());
}

TEST(Life, cell_evolve_3)
{
	Cell c;
	vector<bool> neighbors(8, false);
	neighbors[1] = true;
	ASSERT_FALSE(c.evolve(neighbors));
	ASSERT_TRUE(c.is_alive());
}

TEST(Life, cell_mutate_1)
{
	Cell c;
	c.mutate();
	ASSERT_TRUE(c.is_alive());
}

TEST(Life, cell_mutate_2)
{
	ostringstream output;
	Cell c;
	c.mutate();
	c.print(output);
	ASSERT_EQ("*", output.str());
}

TEST(Life, cell_mutate_3)
{
	Cell c;
	c.mutate();
	ASSERT_TRUE(c.is_alive());
	vector<bool> neighbors(8, false);
	c.evolve(neighbors);
	ASSERT_FALSE(c.is_alive());
	
}

TEST(Life, cell_is_alive_1)
{
	Cell c;
	ASSERT_FALSE(c.is_alive());
}

TEST(Life, cell_is_alive_2)
{
	Cell c;
	c.mutate();
	ASSERT_TRUE(c.is_alive());
}

TEST(Life, cell_is_alive_3)
{
	Cell c;
	vector<bool> neighbors(8, false);
	neighbors[1] = true;
	c.evolve(neighbors);
	ASSERT_TRUE(c.is_alive());
}

TEST(Life, cell_print_1)
{
	Cell c;
	ostringstream output;
	c.print(output);
	ASSERT_EQ("-", output.str());
}

TEST(Life, cell_print_2)
{
	Cell c;
	ostringstream output;
	c.mutate();
	c.print(output);
	ASSERT_EQ("*", output.str());
}

TEST(Life, cell_print_3)
{
	Cell c;
	ostringstream output;
	vector<bool> neighbors(8, false);
	neighbors[1] = true;
	c.evolve(neighbors);
	c.print(output);
	ASSERT_EQ("0", output.str());
}

TEST(Life, life_setup_grid_1)
{
	istringstream input("2\n2\n..\n..\n");
	Life<ConwayCell> sim(input);
	sim.setup_grid();
	ASSERT_EQ(2, sim._width);
	ASSERT_EQ(2, sim._height);	
}

TEST(Life, life_setup_grid_2)
{
	istringstream input("2\n4\n....\n....\n");
	Life<ConwayCell> sim(input);
	sim.setup_grid();
	ASSERT_EQ(4, sim._width);
	ASSERT_EQ(2, sim._height);
}

TEST(Life, life_setup_grid_3)
{
	istringstream input("3\n2\n..\n..\n..\n");
	Life<ConwayCell> sim(input);
	sim.setup_grid();
	ASSERT_EQ(2, sim._width);
	ASSERT_EQ(3, sim._height);
}

TEST(Life, life_read_grid_1)
{
	istringstream input("3\n3\n***\n***\n***\n");
	Life<ConwayCell> sim(input);
	sim.setup_grid();
	sim.read_grid(input);
	ASSERT_EQ(sim._grid[0][1]._c, '*');
	ASSERT_EQ(sim._grid[1][1]._c, '*');
	ASSERT_EQ(sim._grid[2][1]._c, '*');
}

TEST(Life, life_read_grid_2)
{
	istringstream input("3\n3\n.*.\n...\n*.*\n");
	Life<ConwayCell> sim(input);
	sim.setup_grid();
	sim.read_grid(input);
	ASSERT_EQ(sim._grid[0][0]._c, '.');
	ASSERT_EQ(sim._grid[0][1]._c, '*');
	ASSERT_EQ(sim._grid[2][1]._c, '.');
}

TEST(Life, life_read_grid_3)
{
	istringstream input("3\n3\n---\n000\n---\n");
	Life<FredkinCell> sim(input);
	sim.setup_grid();
	sim.read_grid(input);
	ASSERT_EQ(sim._grid[0][0]._c, '-');
	ASSERT_EQ(sim._grid[1][2]._c, '0');
	ASSERT_EQ(sim._grid[2][1]._c, '-');
}

TEST(Life, life_find_neighbors_1)
{
	istringstream input("3\n3\n...\n*.*\n...\n");
	Life<ConwayCell> sim(input);
	vector<bool> neighbors(8, false);
	ASSERT_FALSE(neighbors[3]);
	ASSERT_FALSE(neighbors[4]);
	sim.find_neighbors(neighbors, 1, 1);
	ASSERT_TRUE(neighbors[3]);
	ASSERT_TRUE(neighbors[4]);
}

TEST(Life, life_find_neighbors_2)
{
	istringstream input("3\n3\n***\n*.*\n***\n");
	Life<ConwayCell> sim(input);
	vector<bool> neighbors(8, false);
	sim.find_neighbors(neighbors, 1, 1);
	ASSERT_TRUE(neighbors[0]);
	ASSERT_TRUE(neighbors[7]);
}

TEST(Life, life_find_neighbors_3)
{
	istringstream input("3\n3\n-+-\n+++\n-+-\n");
	Life<FredkinCell> sim(input);
	vector<bool> neighbors(8, false);
	sim.find_neighbors(neighbors, 1, 1);
	ASSERT_TRUE(neighbors[1]);
	ASSERT_TRUE(neighbors[3]);
	ASSERT_TRUE(neighbors[4]);
	ASSERT_TRUE(neighbors[6]);
	ASSERT_FALSE(neighbors[0]);
	ASSERT_FALSE(neighbors[2]);
	ASSERT_FALSE(neighbors[5]);
	ASSERT_FALSE(neighbors[7]);
}

TEST(Life, life_is_valid_coord_1)
{
	istringstream input("3\n3\n...\n...\n...\n");
	Life<ConwayCell> sim(input);
	ASSERT_FALSE(sim.is_valid_coord(-1, -1));
}

TEST(Life, life_is_valid_coord_2)
{
	istringstream input("3\n3\n...\n...\n...\n");
	Life<ConwayCell> sim(input);
	ASSERT_FALSE(sim.is_valid_coord(3, 1));
}

TEST(Life, life_is_valid_coord_3)
{
	istringstream input("3\n3\n---\n---\n---\n");
	Life<FredkinCell> sim(input);
	ASSERT_TRUE(sim.is_valid_coord(1, 1));
}

TEST(Life, life_update_temp_grid_1)
{
	istringstream input("3\n3\n...\n...\n...\n");
	Life<ConwayCell> sim(input);
	sim._grid[1][1]._alive = true;
	sim.update_temp_grid();
	ASSERT_TRUE(sim._temp_grid[1][1]);
}

TEST(Life, life_update_temp_grid_2)
{
	istringstream input("3\n3\n...\n...\n...\n");
	Life<ConwayCell> sim(input);
	sim._grid[0][0]._alive = true;
	sim._grid[2][2]._alive = true;
	sim.update_temp_grid();
	ASSERT_TRUE(sim._temp_grid[0][0]);
	ASSERT_TRUE(sim._temp_grid[2][2]);
}

TEST(Life, life_update_temp_grid_3)
{
	istringstream input("3\n3\n***\n***\n***\n");
	Life<ConwayCell> sim(input);
	sim._grid[1][1]._alive = false;
	sim.update_temp_grid();
	ASSERT_TRUE(sim._temp_grid[1][0]);
	ASSERT_TRUE(sim._temp_grid[1][2]);
	ASSERT_FALSE(sim._temp_grid[1][1]);
}

TEST(Life, life_constructor_1)
{
	istringstream input("3\n3\n...\n...\n...\n");
	Life<ConwayCell> sim(input);
	ASSERT_EQ(3, sim._height);
	ASSERT_EQ(3, sim._width);
}

TEST(Life, life_constructor_2)
{
	istringstream input("2\n5\n.....\n.....\n");
	Life<ConwayCell> sim(input);
	ASSERT_EQ(2, sim._height);
	ASSERT_EQ(5, sim._width);
}

TEST(Life, life_constructor_3)
{
	istringstream input("2\n2\n--\n01\n");
	Life<FredkinCell> sim(input);
	ASSERT_EQ('0', sim._grid[1][0]._c);
	ASSERT_EQ('1', sim._grid[1][1]._c);
	ASSERT_EQ('-', sim._grid[0][0]._c);
	ASSERT_EQ('-', sim._grid[0][1]._c);
}

TEST(Life, life_simulate_generation_1)
{
	istringstream input("3\n3\n---\n000\n---\n");
	Life<FredkinCell> sim(input);
	sim.simulate_generation();
	ASSERT_EQ(1, sim._generation);
}

TEST(Life, life_simulate_generation_2)
{
	istringstream input("3\n3\n---\n000\n---\n");
	Life<FredkinCell> sim(input);
	sim.simulate_generation();
	ASSERT_FALSE(sim._grid[1][1].is_alive());
}

TEST(Life, life_simulate_generation_3)
{
	istringstream input("3\n3\n***\n*.*\n***\n");
	Life<ConwayCell> sim(input);
	sim.simulate_generation();
	ASSERT_FALSE(sim._grid[1][1].is_alive());
}

TEST(Life, life_simulate_life_1)
{
	istringstream input("3\n3\n...\n...\n...\n");
	Life<ConwayCell> sim(input);
	sim.simulate_life(5);
	ASSERT_EQ(5, sim._generation);
}

TEST(Life, life_simulate_life_2)
{
	istringstream input("2\n2\n*.\n**\n");
	Life<ConwayCell> sim(input);
	sim.simulate_life(3);
	ASSERT_EQ(3, sim._generation);
}

TEST(Life, life_simulate_life_3)
{
	istringstream input("2\n5\n--00-\n-00--\n");
	Life<FredkinCell> sim(input);
	sim.simulate_life(10);
	ASSERT_EQ(10, sim._generation);
}

TEST(Life, life_simulate_life_4)
{
	istringstream input("3\n3\n...\n...\n...\n");
	Life<ConwayCell> sim(input);
	sim.simulate_life(5);
	ASSERT_FALSE(sim._grid[1][1].is_alive());
}

TEST(Life, life_simulate_life_5)
{
	istringstream input("3\n3\n...\n.*.\n...\n");
	Life<ConwayCell> sim(input);
	sim.simulate_life(3);
	ASSERT_FALSE(sim._grid[1][1].is_alive());
}

TEST(Life, life_simulate_life_6)
{
	istringstream input("3\n3\n*..\n**.\n...\n");
	Life<ConwayCell> sim(input);
	sim.simulate_life(20);
	ASSERT_TRUE(sim._grid[0][0].is_alive());
	ASSERT_TRUE(sim._grid[1][0].is_alive());
	ASSERT_TRUE(sim._grid[1][1].is_alive());
}
