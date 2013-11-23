
// ------------
// TestLife.c++
// ------------

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

    % g++ -pedantic -std=c++0x -Wall .c++ TestCollatz.c++ -o TestCollatz -lgtest -lpthread -lgtest_main

    % valgrind TestLife > TestLife.out
*/

#include <vector>
#include <string>
#include <sstream>
#include <iostream>

#include "gtest/gtest.h"
#include "Life.h"
#include "Cell.h"
#include "AbstractCell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"

using namespace std;

TEST(Life, place_at_row0_col0_dead)
{
	vector<vector<ConwayCell> > cell = vector<vector<ConwayCell> > (5, vector<ConwayCell>(7, ConwayCell('.')));
	Life<ConwayCell> life(cell);
    ASSERT_TRUE(life._world[1][1].getState() == '.');
}

TEST(Life, place_at_row0_col0_alive)
{
	vector<vector<ConwayCell> > cell = vector<vector<ConwayCell> > (5, vector<ConwayCell>(7, ConwayCell('*')));
	Life<ConwayCell> life(cell);
    ASSERT_TRUE(life._world[1][1].getState() == '*');
}

TEST(Life, test_conway_evolve_helper_1)
{
	vector< vector<ConwayCell> > conway_world = vector< vector<ConwayCell> > (12, vector<ConwayCell> (12, ConwayCell('*')));
	Life<ConwayCell> life(conway_world);
	bool test1 = life.conway_evolve_helper(10, 10, conway_world);

	ASSERT_TRUE(test1 == false);
}

TEST(Life, test_conway_evolve_helper_2)
{
	vector< vector<ConwayCell> > conway_world = vector< vector<ConwayCell> > (12, vector<ConwayCell> (12, ConwayCell('*')));
	Life<ConwayCell> life(conway_world);
	bool test2 = life.conway_evolve_helper(1, 1, conway_world);
	ASSERT_TRUE(test2 == false);
}

TEST(Life, test_conway_evolve_helper_3)
{
	vector< vector<ConwayCell> > conway_world = vector< vector<ConwayCell> > (12, vector<ConwayCell> (12, ConwayCell('*')));
	Life<ConwayCell> life(conway_world);
	bool test3 = life.conway_evolve_helper(1, 10, conway_world);
	ASSERT_TRUE(test3 == false);
}

TEST(Life, test_conway_evolve_helper_4)
{
	vector< vector<ConwayCell> > conway_world = vector< vector<ConwayCell> > (12, vector<ConwayCell> (12, ConwayCell('*')));
	Life<ConwayCell> life(conway_world);
	bool test4 = life.conway_evolve_helper(10, 1, conway_world);
	ASSERT_TRUE(test4 == false);
}

TEST(Life, test_conway_evolve_helper_5)
{
	vector< vector<ConwayCell> > conway_world = vector< vector<ConwayCell> > (12, vector<ConwayCell> (12, ConwayCell('*')));
	Life<ConwayCell> life(conway_world);
	bool test4 = life.conway_evolve_helper(5, 5, conway_world);
	ASSERT_TRUE(test4 == false);
}

TEST(Life, test_fredkin_evolve_helper_1)
{
	vector< vector<FredkinCell> > fredkin_world = vector< vector<FredkinCell> > (12, vector<FredkinCell> (12, FredkinCell('-')));
	Life<FredkinCell> life(fredkin_world);
	bool test1 = life.fredkin_evolve_helper(10, 10, fredkin_world);

	ASSERT_TRUE(test1 == false);
}

TEST(Life, test_fredkin_evolve_helper_2)
{
	vector< vector<FredkinCell> > fredkin_world = vector< vector<FredkinCell> > (12, vector<FredkinCell> (12, FredkinCell('-')));
	Life<FredkinCell> life(fredkin_world);
	bool test2 = life.fredkin_evolve_helper(10, 10, fredkin_world);

	ASSERT_TRUE(test2 == false);
}

TEST(Life, test_fredkin_evolve_helper_3)
{
	vector< vector<FredkinCell> > fredkin_world = vector< vector<FredkinCell> > (12, vector<FredkinCell> (12, FredkinCell('-')));
	Life<FredkinCell> life(fredkin_world);
	bool test3 = life.fredkin_evolve_helper(10, 10, fredkin_world);

	ASSERT_TRUE(test3 == false);
}

TEST(Life, test_fredkin_evolve_helper_4)
{
	vector< vector<FredkinCell> > fredkin_world = vector< vector<FredkinCell> > (12, vector<FredkinCell> (12, FredkinCell('-')));
	Life<FredkinCell> life(fredkin_world);
	bool test4 = life.fredkin_evolve_helper(10, 10, fredkin_world);

	ASSERT_TRUE(test4 == false);
}

TEST(Life, test_fredkin_evolve_helper_5)
{
	vector< vector<FredkinCell> > fredkin_world = vector< vector<FredkinCell> > (12, vector<FredkinCell> (12, FredkinCell('-')));
	Life<FredkinCell> life(fredkin_world);
	bool test4 = life.fredkin_evolve_helper(5, 5, fredkin_world);

	ASSERT_TRUE(test4 == false);
}

TEST(Cell, ConwayCell_evolve_alive_4_neighbors_should_die)
{
	vector< vector<ConwayCell> > conway_world;
	vector<ConwayCell> line;
	line.push_back(ConwayCell('.'));
	line.push_back(ConwayCell('.'));
	line.push_back(ConwayCell('.'));
	line.push_back(ConwayCell('.'));
	line.push_back(ConwayCell('.'));
	conway_world.push_back(line);

	vector<ConwayCell> line2;
	line2.push_back(ConwayCell('.'));
	line2.push_back(ConwayCell('.'));
	line2.push_back(ConwayCell('*'));
	line2.push_back(ConwayCell('.'));
	line2.push_back(ConwayCell('.'));
	conway_world.push_back(line2);

	vector<ConwayCell> line3;
	line3.push_back(ConwayCell('.'));
	line3.push_back(ConwayCell('.'));
	line3.push_back(ConwayCell('.'));
	line3.push_back(ConwayCell('.'));
	line3.push_back(ConwayCell('.'));
	conway_world.push_back(line3);

	Life<ConwayCell> life(conway_world);

	life.evolve();
    ASSERT_TRUE(life._world[1][2].getState() == '.');
}

TEST(Cell, ConwayCell_evolve_alive_3_neighbors_should_alive)
{
	vector< vector<ConwayCell> > conway_world;
	vector<ConwayCell> line;
	line.push_back(ConwayCell('.'));
	line.push_back(ConwayCell('*'));
	line.push_back(ConwayCell('*'));
	line.push_back(ConwayCell('*'));
	line.push_back(ConwayCell('.'));
	conway_world.push_back(line);

	vector<ConwayCell> line2;
	line2.push_back(ConwayCell('.'));
	line2.push_back(ConwayCell('.'));
	line2.push_back(ConwayCell('.'));
	line2.push_back(ConwayCell('.'));
	line2.push_back(ConwayCell('.'));
	conway_world.push_back(line2);

	vector<ConwayCell> line3;
	line3.push_back(ConwayCell('.'));
	line3.push_back(ConwayCell('.'));
	line3.push_back(ConwayCell('.'));
	line3.push_back(ConwayCell('.'));
	line3.push_back(ConwayCell('.'));
	conway_world.push_back(line3);

	Life<ConwayCell> life(conway_world);

	life.evolve();
    ASSERT_TRUE(life._world[1][2].getState() == '*');
}

TEST(Cell, ConwayCell_evolve_alive_3_neighbors_should_alive2)
{
	vector< vector<ConwayCell> > conway_world;
	vector<ConwayCell> line;
	line.push_back(ConwayCell('.'));
	line.push_back(ConwayCell('*'));
	line.push_back(ConwayCell('*'));
	line.push_back(ConwayCell('*'));
	line.push_back(ConwayCell('.'));
	conway_world.push_back(line);

	vector<ConwayCell> line2;
	line2.push_back(ConwayCell('.'));
	line2.push_back(ConwayCell('.'));
	line2.push_back(ConwayCell('.'));
	line2.push_back(ConwayCell('.'));
	line2.push_back(ConwayCell('.'));
	conway_world.push_back(line2);

	vector<ConwayCell> line3;
	line3.push_back(ConwayCell('.'));
	line3.push_back(ConwayCell('.'));
	line3.push_back(ConwayCell('.'));
	line3.push_back(ConwayCell('.'));
	line3.push_back(ConwayCell('.'));
	conway_world.push_back(line3);

	Life<ConwayCell> life(conway_world);

	life.evolve();
    ASSERT_TRUE(life._world[0][2].getState() == '*');
}

TEST(Cell, test_getAge1)
{
	vector< vector<FredkinCell> > conway_world = vector< vector<FredkinCell> > (12, vector<FredkinCell> (12, FredkinCell('*')));
	Life<FredkinCell> life(conway_world);
	life.evolve();
	ASSERT_TRUE(life._world[10][1].getAge() == 0);
}

TEST(Cell, test_getAge2)
{
	vector< vector<ConwayCell> > conway_world = vector< vector<ConwayCell> > (12, vector<ConwayCell> (12, ConwayCell('*')));
	Life<ConwayCell> life(conway_world);
	life.evolve();
	ASSERT_TRUE(life._world[1][10].getAge() == 0);
}

TEST(Cell, test_getAge3)
{
	vector< vector<ConwayCell> > conway_world = vector< vector<ConwayCell> > (12, vector<ConwayCell> (12, ConwayCell('*')));
	Life<ConwayCell> life(conway_world);
	life.evolve();
	ASSERT_TRUE(life._world[1][1].getAge() == 0);
}

TEST(Cell, test_getAge4)
{
	vector< vector<ConwayCell> > conway_world = vector< vector<ConwayCell> > (12, vector<ConwayCell> (12, ConwayCell('*')));
	Life<ConwayCell> life(conway_world);
	life.evolve();
	ASSERT_TRUE(life._world[10][10].getAge() == 0);
}

TEST(Cell, test_getAge5)
{
	vector< vector<ConwayCell> > conway_world = vector< vector<ConwayCell> > (12, vector<ConwayCell> (12, ConwayCell('*')));
	Life<ConwayCell> life(conway_world);
	life.evolve();
	ASSERT_TRUE(life._world[5][5].getAge() == 0);
}

TEST(ConwayCell, test_life_conway_constructor_1)
{
	vector< vector<ConwayCell> > conway_world = vector< vector<ConwayCell> > (12, vector<ConwayCell> (12, ConwayCell('*')));
	Life<ConwayCell> life(conway_world);
	ASSERT_TRUE(conway_world[11][10].getState() == '*');
}

TEST(ConwayCell, test_life_conway_constructor_2)
{
	vector< vector<ConwayCell> > conway_world = vector< vector<ConwayCell> > (12, vector<ConwayCell> (12, ConwayCell('*')));
	Life<ConwayCell> life(conway_world);
	ASSERT_TRUE(conway_world[11][11].getState() == '*');
}

TEST(ConwayCell, test_life_conway_constructor_3)
{
	vector< vector<ConwayCell> > conway_world = vector< vector<ConwayCell> > (12, vector<ConwayCell> (12, ConwayCell('*')));
	Life<ConwayCell> life(conway_world);
	ASSERT_TRUE(conway_world[11][9].getState() == '*');
}

TEST(ConwayCell, test_life_conway_constructor_4)
{
	vector< vector<ConwayCell> > conway_world = vector< vector<ConwayCell> > (12, vector<ConwayCell> (12, ConwayCell('*')));
	Life<ConwayCell> life(conway_world);
	ASSERT_TRUE(conway_world[11][10].getState() == '*');
}

TEST(ConwayCell, test_life_conway_constructor_5)
{
	vector< vector<ConwayCell> > conway_world = vector< vector<ConwayCell> > (12, vector<ConwayCell> (12, ConwayCell('*')));
	Life<ConwayCell> life(conway_world);
	ASSERT_TRUE(conway_world[11][11].getState() == '*');
}

TEST(ConwayCell, test_life_conway_constructor_6)
{
	vector< vector<ConwayCell> > conway_world = vector< vector<ConwayCell> > (12, vector<ConwayCell> (12, ConwayCell('*')));
	Life<ConwayCell> life(conway_world);
	ASSERT_TRUE(conway_world[11][0].getState() == '*');
}

TEST(ConwayCell, test_setState1)
{
	vector< vector<ConwayCell> > conway_world = vector< vector<ConwayCell> > (12, vector<ConwayCell> (12, ConwayCell('*')));
	Life<ConwayCell> life(conway_world);
	life._world[10][1].setState('.');
	ASSERT_TRUE(life._world[10][1].getState() == '.');
}

TEST(ConwayCell, test_setState2)
{
	vector< vector<ConwayCell> > conway_world = vector< vector<ConwayCell> > (12, vector<ConwayCell> (12, ConwayCell('*')));
	Life<ConwayCell> life(conway_world);
	life._world[1][10].setState('.');
	ASSERT_TRUE(life._world[1][10].getState() == '.');
}

TEST(ConwayCell, test_setState3)
{
	vector< vector<ConwayCell> > conway_world = vector< vector<ConwayCell> > (12, vector<ConwayCell> (12, ConwayCell('*')));
	Life<ConwayCell> life(conway_world);
	life._world[1][1].setState('.');
	ASSERT_TRUE(life._world[1][1].getState() == '.');
}

TEST(ConwayCell, test_setState4)
{
	vector< vector<ConwayCell> > conway_world = vector< vector<ConwayCell> > (12, vector<ConwayCell> (12, ConwayCell('*')));
	Life<ConwayCell> life(conway_world);
	life._world[10][10].setState('.');
	ASSERT_TRUE(life._world[10][10].getState() == '.');
}

TEST(ConwayCell, test_setState5)
{
	vector< vector<ConwayCell> > conway_world = vector< vector<ConwayCell> > (12, vector<ConwayCell> (12, ConwayCell('*')));
	Life<ConwayCell> life(conway_world);
	life._world[5][10].setState('.');
	ASSERT_TRUE(life._world[5][10].getState() == '.');
}

TEST(ConwayCell, test_getState1)
{
	vector< vector<ConwayCell> > conway_world = vector< vector<ConwayCell> > (12, vector<ConwayCell> (12, ConwayCell('*')));
	Life<ConwayCell> life(conway_world);
	ASSERT_TRUE(life._world[10][1].getState() == '*');
}

TEST(ConwayCell, test_getState2)
{
	vector< vector<ConwayCell> > conway_world = vector< vector<ConwayCell> > (12, vector<ConwayCell> (12, ConwayCell('*')));
	Life<ConwayCell> life(conway_world);
	life._world[10][1].setState('.');
	ASSERT_TRUE(life._world[10][1].getState() == '.');
}

TEST(ConwayCell, test_getState3)
{
	vector< vector<ConwayCell> > conway_world = vector< vector<ConwayCell> > (12, vector<ConwayCell> (12, ConwayCell('.')));
	Life<ConwayCell> life(conway_world);
	life._world[10][1].setState('*');
	ASSERT_TRUE(life._world[10][1].getState() == '*');
}

TEST(ConwayCell, test_getState4)
{
	vector< vector<ConwayCell> > conway_world = vector< vector<ConwayCell> > (12, vector<ConwayCell> (12, ConwayCell('*')));
	Life<ConwayCell> life(conway_world);
	life._world[10][1].setState('.');
	life._world[10][1].setState('*');
	ASSERT_TRUE(life._world[10][1].getState() == '*');
}

TEST(ConwayCell, test_getState5)
{
	vector< vector<ConwayCell> > conway_world = vector< vector<ConwayCell> > (12, vector<ConwayCell> (12, ConwayCell('*')));
	Life<ConwayCell> life(conway_world);
	life._world[10][1].setState('.');
	life._world[10][1].setState('*');
	life._world[10][1].setState('.');
	ASSERT_TRUE(life._world[10][1].getState() == '.');
}

TEST(ConwayCell, test_generation1)
{
	vector< vector<ConwayCell> > conway_world = vector< vector<ConwayCell> > (12, vector<ConwayCell> (12, ConwayCell('*')));
	Life<ConwayCell> life(conway_world);
	ASSERT_TRUE(life._world[10][10].generation(3));
}

TEST(ConwayCell, test_generation2)
{
	vector< vector<ConwayCell> > conway_world = vector< vector<ConwayCell> > (12, vector<ConwayCell> (12, ConwayCell('*')));
	Life<ConwayCell> life(conway_world);
	ASSERT_FALSE(life._world[10][10].generation(1));
}

TEST(ConwayCell, test_generation3)
{
	vector< vector<ConwayCell> > conway_world = vector< vector<ConwayCell> > (12, vector<ConwayCell> (12, ConwayCell('*')));
	Life<ConwayCell> life(conway_world);
	ASSERT_FALSE(life._world[10][10].generation(4));
}

TEST(ConwayCell, test_generation4)
{
	vector< vector<ConwayCell> > conway_world = vector< vector<ConwayCell> > (12, vector<ConwayCell> (12, ConwayCell('*')));
	Life<ConwayCell> life(conway_world);
	ASSERT_TRUE(life._world[10][10].generation(2));
}

TEST(ConwayCell, test_generation5)
{
	vector< vector<ConwayCell> > conway_world = vector< vector<ConwayCell> > (12, vector<ConwayCell> (12, ConwayCell('*')));
	Life<ConwayCell> life(conway_world);
	life._world[10][10].setState('.');
	ASSERT_FALSE(life._world[10][10].generation(2));
}

TEST(FredkinCell, test_life_fredkin_constructor_1)
{
	vector< vector<FredkinCell> > fredkin_world = vector< vector<FredkinCell> > (22, vector<FredkinCell> (22, FredkinCell('-')));
	Life<FredkinCell> life(fredkin_world);
	ASSERT_TRUE(fredkin_world[11][10].getState() == '-');
}

TEST(FredkinCell, test_life_fredkin_constructor_2)
{
	vector< vector<FredkinCell> > fredkin_world = vector< vector<FredkinCell> > (22, vector<FredkinCell> (22, FredkinCell('-')));
	Life<FredkinCell> life(fredkin_world);
	ASSERT_TRUE(fredkin_world[11][11].getState() == '-');
}

TEST(FredkinCell, test_life_fredkin_constructor_3)
{
	vector< vector<FredkinCell> > fredkin_world = vector< vector<FredkinCell> > (22, vector<FredkinCell> (22, FredkinCell('-')));
	Life<FredkinCell> life(fredkin_world);
	ASSERT_TRUE(fredkin_world[11][9].getState() == '-');
}

TEST(FredkinCell, test_life_fredkin_constructor_4)
{
	vector< vector<FredkinCell> > fredkin_world = vector< vector<FredkinCell> > (22, vector<FredkinCell> (22, FredkinCell('-')));
	Life<FredkinCell> life(fredkin_world);
	ASSERT_TRUE(fredkin_world[11][10].getState() == '-');
}

TEST(FredkinCell, test_life_fredkin_constructor_5)
{
	vector< vector<FredkinCell> > fredkin_world = vector< vector<FredkinCell> > (22, vector<FredkinCell> (22, FredkinCell('-')));
	Life<FredkinCell> life(fredkin_world);
	ASSERT_TRUE(fredkin_world[11][5].getState() == '-');
}

TEST(FredkinCell, test_life_fredkin_constructor_6)
{
	vector< vector<FredkinCell> > fredkin_world = vector< vector<FredkinCell> > (22, vector<FredkinCell> (22, FredkinCell('-')));
	Life<FredkinCell> life(fredkin_world);
	ASSERT_TRUE(fredkin_world[11][11].getState() == '-');
}

TEST(FredkinCell, test_setState1)
{
	vector< vector<FredkinCell> > fredkin_world = vector< vector<FredkinCell> > (22, vector<FredkinCell> (22, FredkinCell('-')));
	Life<FredkinCell> life(fredkin_world);
	ASSERT_TRUE(fredkin_world[11][11].getState() == '-');
}

TEST(FredkinCell, test_setState2)
{
	vector< vector<FredkinCell> > fredkin_world = vector< vector<FredkinCell> > (22, vector<FredkinCell> (22, FredkinCell('-')));
	Life<FredkinCell> life(fredkin_world);
	ASSERT_TRUE(fredkin_world[1][11].getState() == '-');
}

TEST(FredkinCell, test_setState3)
{
	vector< vector<FredkinCell> > fredkin_world = vector< vector<FredkinCell> > (22, vector<FredkinCell> (22, FredkinCell('-')));
	Life<FredkinCell> life(fredkin_world);
	ASSERT_TRUE(fredkin_world[1][1].getState() == '-');
}

TEST(FredkinCell, test_setState4)
{
	vector< vector<FredkinCell> > fredkin_world = vector< vector<FredkinCell> > (22, vector<FredkinCell> (22, FredkinCell('-')));
	Life<FredkinCell> life(fredkin_world);
	ASSERT_TRUE(fredkin_world[11][1].getState() == '-');
}

TEST(FredkinCell, test_setState5)
{
	vector< vector<FredkinCell> > fredkin_world = vector< vector<FredkinCell> > (22, vector<FredkinCell> (22, FredkinCell('-')));
	Life<FredkinCell> life(fredkin_world);
	ASSERT_TRUE(fredkin_world[10][11].getState() == '-');
}

TEST(FredkinCell, test_getAge1)
{
	vector< vector<FredkinCell> > conway_world = vector< vector<FredkinCell> > (12, vector<FredkinCell> (12, FredkinCell('*')));
	Life<FredkinCell> life(conway_world);
	life.evolve();
	ASSERT_TRUE(life._world[10][1].getAge() == 0);
}

TEST(FredkinCell, test_getAge2)
{
	vector< vector<ConwayCell> > conway_world = vector< vector<ConwayCell> > (12, vector<ConwayCell> (12, ConwayCell('*')));
	Life<ConwayCell> life(conway_world);
	life.evolve();
	ASSERT_TRUE(life._world[1][10].getAge() == 0);
}

TEST(FredkinCell, test_getAge3)
{
	vector< vector<ConwayCell> > conway_world = vector< vector<ConwayCell> > (12, vector<ConwayCell> (12, ConwayCell('*')));
	Life<ConwayCell> life(conway_world);
	life.evolve();
	ASSERT_TRUE(life._world[1][1].getAge() == 0);
}

TEST(FredkinCell, test_getAge4)
{
	vector< vector<ConwayCell> > conway_world = vector< vector<ConwayCell> > (12, vector<ConwayCell> (12, ConwayCell('*')));
	Life<ConwayCell> life(conway_world);
	life.evolve();
	ASSERT_TRUE(life._world[10][10].getAge() == 0);
}

TEST(FredkinCell, test_getAge5)
{
	vector< vector<ConwayCell> > conway_world = vector< vector<ConwayCell> > (12, vector<ConwayCell> (12, ConwayCell('*')));
	Life<ConwayCell> life(conway_world);
	life.evolve();
	ASSERT_TRUE(life._world[5][5].getAge() == 0);
}

TEST(FredkinCell, test_updateAge1)
{
	vector< vector<FredkinCell> > fredkin_world = vector< vector<FredkinCell> > (22, vector<FredkinCell> (22, FredkinCell('-')));
	Life<FredkinCell> life(fredkin_world);
	life._world[10][1].updateAge();
	ASSERT_TRUE(life._world[10][1].getAge() == 1);
}

TEST(FredkinCell, test_updateAge2)
{
	vector< vector<FredkinCell> > fredkin_world = vector< vector<FredkinCell> > (22, vector<FredkinCell> (22, FredkinCell('-')));
	Life<FredkinCell> life(fredkin_world);
	life._world[1][10].updateAge();
	ASSERT_TRUE(life._world[1][10].getAge() == 1);
}

TEST(FredkinCell, test_updateAge3)
{
	vector< vector<FredkinCell> > fredkin_world = vector< vector<FredkinCell> > (22, vector<FredkinCell> (22, FredkinCell('-')));
	Life<FredkinCell> life(fredkin_world);
	life._world[5][10].updateAge();
	ASSERT_TRUE(life._world[5][10].getAge() == 1);
}

TEST(FredkinCell, test_updateAge4)
{
	vector< vector<FredkinCell> > fredkin_world = vector< vector<FredkinCell> > (22, vector<FredkinCell> (22, FredkinCell('-')));
	Life<FredkinCell> life(fredkin_world);
	life._world[1][1].updateAge();
	ASSERT_TRUE(life._world[1][1].getAge() == 1);
}

TEST(FredkinCell, test_updateAge5)
{
	vector< vector<FredkinCell> > fredkin_world = vector< vector<FredkinCell> > (22, vector<FredkinCell> (22, FredkinCell('-')));
	Life<FredkinCell> life(fredkin_world);
	life._world[10][10].updateAge();
	ASSERT_TRUE(life._world[10][10].getAge() == 1);
}

TEST(FredkinCell, test_generation1)
{
	vector< vector<FredkinCell> > fredkin_world = vector< vector<FredkinCell> > (22, vector<FredkinCell> (22, FredkinCell('-')));
	Life<FredkinCell> life(fredkin_world);
	ASSERT_TRUE(life._world[10][10].generation(3));
}

TEST(FredkinCell, test_generation2)
{
	vector< vector<FredkinCell> > fredkin_world = vector< vector<FredkinCell> > (22, vector<FredkinCell> (22, FredkinCell('-')));
	Life<FredkinCell> life(fredkin_world);
	ASSERT_TRUE(life._world[10][10].generation(1));
}

TEST(FredkinCell, test_generation3)
{
	vector< vector<FredkinCell> > fredkin_world = vector< vector<FredkinCell> > (22, vector<FredkinCell> (22, FredkinCell('-')));
	Life<FredkinCell> life(fredkin_world);
	ASSERT_FALSE(life._world[10][10].generation(0));
}

TEST(FredkinCell, test_generation4)
{
	vector< vector<FredkinCell> > fredkin_world = vector< vector<FredkinCell> > (22, vector<FredkinCell> (22, FredkinCell('-')));
	Life<FredkinCell> life(fredkin_world);
	ASSERT_FALSE(life._world[10][10].generation(2));
}

TEST(FredkinCell, test_generation5)
{
	vector< vector<FredkinCell> > fredkin_world = vector< vector<FredkinCell> > (22, vector<FredkinCell> (22, FredkinCell('-')));
	Life<FredkinCell> life(fredkin_world);
	ASSERT_FALSE(life._world[10][10].generation(4));
}