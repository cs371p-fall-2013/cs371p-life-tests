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

    % g++ -pedantic -std=c++0x -Wall Life.c++ TestLife.c++ -o TestLife -lgtest -lpthread -lgtest_main

    % valgrind TestLife > TestLife.out
*/

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <string>   // ==
#include <stdexcept> // invalid_argument, out_of_range

#include "gtest/gtest.h"
#define private public
#define protected public

#include "Life.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"


// -----------
// TestLife
// -----------
TEST(Life, Conway_1) {
	ConwayCell cell(true);
	ASSERT_TRUE(cell.alive);
}

TEST(Life, Conway_2) {
	ConwayCell cell(false);
	ASSERT_FALSE(cell.alive);
}

TEST(Life, Conway_3) {
	ConwayCell cell;
	ASSERT_FALSE(cell.alive);
}

TEST(Life, conSetAlive_1) {
	ConwayCell cell;
	cell.setAlive('*');
	ASSERT_TRUE(cell.alive);
}

TEST(Life, conSetAlive_2) {
	ConwayCell cell;
	cell.setAlive('.');
	ASSERT_FALSE(cell.alive);
}

TEST(Life, conSetAlive_3) {
	ConwayCell cell;
	cell.setAlive('j');
	ASSERT_FALSE(cell.alive);
}

TEST(Life, conGetRep_1) {
	ConwayCell cell(false);
	ASSERT_EQ(cell.getRep(), '.');
}

TEST(Life, conGetRep_2) {
	ConwayCell cell(true);
	ASSERT_EQ(cell.getRep(), '*');
}

TEST(Life, conGetRep_3) {
	ConwayCell cell;
	ASSERT_EQ(cell.getRep(), '.');
}

TEST(Life, conClone_1) {
	ConwayCell c1;
	ConwayCell c2;
	c1 = c2;
	ASSERT_TRUE(c1.alive == c2.alive);
}

TEST(Life, conClone_2) {
	ConwayCell c1;
	ConwayCell c2(false);
	c1 = c2;
	ASSERT_TRUE(c1.alive == c2.alive);
}

TEST(Life, conClone_3) {
	ConwayCell c1(false);
	ConwayCell c2(true);
	c1 = c2;
	ASSERT_TRUE(c1.alive == c2.alive);
}

TEST(Life, conTurn_1) {
	ConwayCell cell;
	cell.turn(3, 3);
	ASSERT_TRUE(cell.alive);
}

TEST(Life, conTurn_2) {
	ConwayCell cell;
	cell.turn(3, 4);
	ASSERT_FALSE(cell.alive);
}

TEST(Life, conTurn_3) {
	ConwayCell cell(true);
	cell.turn(3, 3);
	ASSERT_TRUE(cell.alive);
}

TEST(Life, conTurn_4) {
	ConwayCell cell(true);
	cell.turn(3, 1);
	ASSERT_FALSE(cell.alive);
}

TEST(Life, conTurn_5) {
	ConwayCell cell(true);
	try {
		cell.turn(3, -1);
		ASSERT_FALSE(true);
	} catch (const std::invalid_argument&) {

	}
}

TEST(Life, cell_1) {
	Cell cell(new FredkinCell(true));
	ASSERT_TRUE(cell.isAlive());
}

TEST(Life, cell_2) {
	Cell cell(new FredkinCell(false));
	ASSERT_FALSE(cell.isAlive());
}

TEST(Life, cell_3) {
	Cell cell(new ConwayCell(true));
	ASSERT_TRUE(cell.isAlive());
}

TEST(Life, cell_4) {
	Cell cell(new ConwayCell(false));
	ASSERT_FALSE(cell.isAlive());
}

TEST(Life, cellSetAlive_1) {
	Cell cell;
	cell.setAlive('1');
	ASSERT_TRUE(cell.isAlive());
}

TEST(Life, cellSetAlive_2) {
	Cell cell(new FredkinCell(true));
	cell.setAlive('-');
	ASSERT_FALSE(cell.isAlive());
}

TEST(Life, cellSetAlive_3) {
	Cell cell(new ConwayCell(false));
	cell.setAlive('*');
	ASSERT_TRUE(cell.isAlive());
}

TEST(Life, cellSetAlive_4) {
	Cell cell(new ConwayCell(true));
	cell.setAlive('m');
	ASSERT_FALSE(cell.isAlive());
}

TEST(Life, cellSetAlive_5) {
	Cell cell;
	cell.setAlive('.');
	//This is because we assume FredkinCell like this
	ASSERT_TRUE(cell.isAlive());
}

TEST(Life, cellGetRep_1) {
	Cell cell;
	ASSERT_EQ(cell.getRep(), '-');
}

TEST(Life, cellGetRep_2) {
	Cell cell(new FredkinCell(true));
	ASSERT_EQ(cell.getRep(), '0');
}

TEST(Life, cellGetRep_3) {
	Cell cell(new ConwayCell(false));
	ASSERT_EQ(cell.getRep(), '.');
}

TEST(Life, cellGetRep_4) {
	Cell cell(new ConwayCell(true));
	ASSERT_EQ(cell.getRep(), '*');
}

TEST(Life, cellTurn_1) {
	Cell cell;
	cell.turn(1, 2);
	ASSERT_TRUE(cell.isAlive());
}

TEST(Life, cellTurn_2) {
	Cell cell(new ConwayCell(true));
	cell.turn(1, 1);
	ASSERT_FALSE(cell.isAlive());
}

TEST(Life, cellTurn_3) {
	Cell cell;
	cell.turn(1, 2);
	cell.turn(1, 2);
	cell.turn(1, 2);
	ASSERT_EQ(cell.getRep(), '*');
}

TEST(Life, cellTurn_4) {
	Cell cell;
	try {
		cell.turn(10, 10);
		ASSERT_FALSE(true);
	} catch (const std::invalid_argument&) {

	}
}

TEST(Life, fred_1) {
	FredkinCell cell(true);
	ASSERT_TRUE(cell.alive);
}

TEST(Life, fred_2) {
	FredkinCell cell(false);
	ASSERT_FALSE(cell.alive);
}

TEST(Life, fred_3) {
	FredkinCell cell;
	ASSERT_FALSE(cell.alive);
}

TEST(Life, fredSetAlive_1) {
	FredkinCell cell(true);
	cell.setAlive('-');
	ASSERT_FALSE(cell.alive);
}

TEST(Life, fredSetAlive_2) {
	FredkinCell cell(false);
	cell.setAlive('+');
	ASSERT_TRUE(cell.alive);
}

TEST(Life, fredSetAlive_3) {
	FredkinCell cell(true);
	cell.setAlive('3');
	ASSERT_EQ(cell.getRep(), '3');
}

TEST(Life, fredSetAlive_4) {
	FredkinCell cell(true);
	cell.setAlive('9');
	cell.turn(1, 3);
	ASSERT_EQ(cell.getRep(), '+');
}

TEST(Life, fredSetAlive_5) {
	FredkinCell cell(true);
	cell.setAlive('3');
	ASSERT_EQ(cell.getRep(), '3');
	cell.turn(2, 4);
	ASSERT_EQ(cell.getRep(), '-');
	cell.turn(1, 4);
	cell.turn(1, 4);
	ASSERT_EQ(cell.getRep(), '4');
}

TEST(Life, fredGetRep_1) {
	FredkinCell cell(true);
	ASSERT_EQ(cell.getRep(), '0');
}

TEST(Life, fredGetRep_2) {
	FredkinCell cell(false);
	ASSERT_EQ(cell.getRep(), '-');
}

TEST(Life, fredClone_1) {
	FredkinCell c1;
	FredkinCell c2;
	c1 = c2;
	ASSERT_TRUE(c1.alive == c2.alive);
}

TEST(Life, fredClone_2) {
	FredkinCell c1;
	FredkinCell c2(true);
	c1 = c2;
	ASSERT_TRUE(c1.alive == c2.alive);
}

TEST(Life, fredClone_3) {
	FredkinCell c1(true);
	FredkinCell c2(false);
	c1 = c2;
	ASSERT_TRUE(c1.alive == c2.alive);
}

TEST(Life, fredTurn_1) {
	FredkinCell cell;
	cell.turn(1,1);
	ASSERT_TRUE(cell.alive);
}

TEST(Life, fredTurn_2) {
	FredkinCell cell(true);
	cell.turn(2,4);
	ASSERT_FALSE(cell.alive);
}

TEST(Life, fredTurn_3) {
	FredkinCell cell;
	cell.turn(1,1);
	cell.turn(1,1);
	cell.turn(1,1);
	ASSERT_EQ(cell.getRep(), '2');
}

TEST(Life, fredTurn_4) {
	FredkinCell cell(true);
	try {
		cell.turn(-5, 1);
		ASSERT_FALSE(true);
	} catch (const std::invalid_argument&) {

	}
}

TEST(Life, life_1) {
	std::istringstream in("1\n1\n.");
	std::ostringstream o;
	Life<ConwayCell> life(in, o);
	ASSERT_FALSE(life.grid[0][0].alive);
}

TEST(Life, life_2) {
	std::istringstream in("1\n1\n0");
	std::ostringstream o;
	Life<FredkinCell> life(in, o);
	ASSERT_TRUE(life.grid[0][0].alive);
}

TEST(Life, life_3) {
	std::istringstream in("3\n3\n...\n.*.\n...");
	std::ostringstream o;
	Life<ConwayCell> life(in, o);
	ASSERT_TRUE(life.grid[1][1].alive);
}

TEST(Life, life_4) {
	std::istringstream in("3\n3\n---\n.*.\n---");
	std::ostringstream o;
	Life<Cell> life(in, o);
	ASSERT_TRUE(life.grid[1][1].isAlive());
	ASSERT_FALSE(life.grid[0][0].isAlive());
}

TEST(Life, print_1) {
	std::string st = "\nGeneration = 0, Population = 0.\n.\n";
	std::istringstream in("1\n1\n.");
	std::ostringstream oi;
	Life<ConwayCell> life(in, oi);
	std::ostringstream o;
	life.print(o);
	ASSERT_EQ(o.str(), st);
}

TEST(Life, print_2) {
	std::string st = "\nGeneration = 0, Population = 1.\n...\n.*.\n...\n";
	std::istringstream in("3\n3\n...\n.*.\n...");
	std::ostringstream oi;
	Life<ConwayCell> life(in, oi);
	std::ostringstream o;
	life.print(o);
	ASSERT_EQ(o.str(), st);
}

TEST(Life, print_3) {
	std::string st = "\nGeneration = 1, Population = 0.\n.\n";
	std::istringstream in("1\n1\n.");
	std::ostringstream oi;
	Life<ConwayCell> life(in, oi);
	life.turn();
	std::ostringstream o;
	life.print(o);
	ASSERT_EQ(o.str(), st);
}

TEST(Life, lifeTurn_1) {
	std::string st = "\nGeneration = 1, Population = 0.\n.\n";
	std::istringstream in("1\n1\n*");
	std::ostringstream oi;
	Life<ConwayCell> life(in, oi);
	life.turn();
	std::ostringstream o;
	life.print(o);
	ASSERT_EQ(o.str(), st);
}

TEST(Life, lifeTurn_2) {
	std::string st = "\nGeneration = 1, Population = 2.\n-1\n1-\n";
	std::istringstream in("2\n2\n-0\n00");
	std::ostringstream oi;
	Life<FredkinCell> life(in, oi);
	life.turn();
	std::ostringstream o;
	life.print(o);
	ASSERT_EQ(o.str(), st);
}

TEST(Life, lifeTurn_3) {
	std::string st = "\nGeneration = 1, Population = 2.\n-*\n*-\n";
	std::istringstream in("2\n2\n-1\n10");
	std::ostringstream oi;
	Life<Cell> life(in, oi);
	life.turn();
	std::ostringstream o;
	life.print(o);
	ASSERT_EQ(o.str(), st);
}

TEST(Life, lifeTurn_4) {
	std::string st = "\nGeneration = 1, Population = 3.\n...\n***\n...\n";
	std::istringstream in("3\n3\n.*.\n.*.\n.*.");
	std::ostringstream oi;
	Life<ConwayCell> life(in, oi);
	life.turn();
	std::ostringstream o;
	life.print(o);
	ASSERT_EQ(o.str(), st);
}

TEST(Life, count_1) {
	std::istringstream in("2\n2\n-1\n10");
	std::ostringstream oi;
	Life<Cell> life(in, oi);
	ASSERT_EQ(life.count(1,1), 1);
}

TEST(Life, count_2) {
	std::istringstream in("2\n2\n-1\n10");
	std::ostringstream oi;
	Life<Cell> life(in, oi);
	ASSERT_EQ(life.count(0,0), 0);
}

TEST(Life, count_3) {
	std::istringstream in("2\n2\n-1\n10");
	std::ostringstream oi;
	Life<Cell> life(in, oi);
	ASSERT_EQ(life.count(-1,21), 0);
}

TEST(Life, count_4) {
	std::istringstream in("3\n3\n...\n...\n...");
	std::ostringstream oi;
	Life<ConwayCell> life(in, oi);
	ASSERT_EQ(life.count(2,2), 0);
}

