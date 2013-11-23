/*
To test the program:

 % g++ -pedantic -std=c++0x -Wall Life.c++ TestLife.c++ -o TestLife -lgtest -lpthread -lgtest_main

 % valgrind TestLife > TestLife.out
*/

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==

#include "gtest/gtest.h"



#define private public
#define protected public
#include "Life.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"

using namespace std;

// -----------
// TestLife
// -----------

// ----------------------
// Cell.constructor
// ----------------------
TEST(Life, Cell_constructor) {
	Cell c(true);
	ASSERT_TRUE(c.isAlive() == true);
	ostringstream ss;
	c.print(ss);
	ASSERT_TRUE(ss.str() == "0");
}

// ----------------------
// ConwayCell.change1
// ----------------------
TEST(Life, ConwayCell_change1) {
	ConwayCell c(true);
	c.change(true);
	ASSERT_TRUE(c.alive == true);
}

// ----------------------
// ConwayCell.change2
// ----------------------
TEST(Life, ConwayCell_change2) {
	ConwayCell c(false);
	c.change(false);
	ASSERT_TRUE(c.alive == false);
}

// ----------------------
// ConwayCell.change3
// ----------------------
TEST(Life, ConwayCell_change3) {
	ConwayCell c(true);
	c.change(false);
	ASSERT_TRUE(c.alive == false);
}

// ----------------------
// ConwayCell.change4
// ----------------------
TEST(Life, ConwayCell_change4) {
	ConwayCell c(false);
	c.change(true);
	ASSERT_TRUE(c.alive == true);
}

// ----------------------
// FredkinCell.change1
// ----------------------
TEST(Life, FredkinCell_change1) {
	FredkinCell c(false);
	c.change(false);
	ASSERT_TRUE(c.age == 0);
	ASSERT_TRUE(c.alive == false);

}

// ----------------------
// FredkinCell.change2
// ----------------------
TEST(Life, FredkinCell_change2) {
	FredkinCell c(true);
	c.change(false);
	ASSERT_TRUE(c.age == 0);
	ASSERT_TRUE(c.alive == false);
}

// ----------------------
// FredkinCell.change3
// ----------------------
TEST(Life, FredkinCell_change3) {
	FredkinCell c(true);
	c.change(true);
	ASSERT_TRUE(c.age == 1);
	ASSERT_TRUE(c.alive == true);
}

// ----------------------
// FredkinCell.change4
// ----------------------
TEST(Life, FredkinCell_change4) {
	FredkinCell c(false);
	c.change(true);
	ASSERT_TRUE(c.age == 0);
	ASSERT_TRUE(c.alive == true);
}

// ----------------------
// FredkinCell.change5
// ----------------------
TEST(Life, FredkinCell_change5) {
	FredkinCell c(true);
	c.age = 9;
	c.change(true);
	ASSERT_TRUE(c.age == 10);
	ASSERT_TRUE(c.alive == true);
}

// ----------------------
// Cell.change1
// ----------------------
TEST(Life, Cell_change1) {
	Cell c(true);
	c.change(true);
	c.change(true);
	ASSERT_TRUE(c.isAlive() == true);
	ostringstream ss;
	c.print(ss);
	ASSERT_TRUE(ss.str() == "*");
}

// ----------------------
// Cell.change2
// ----------------------
TEST(Life, Cell_change2) {
	Cell c(true);
	c.change(true);
	ASSERT_TRUE(c.isAlive() == true);
	ostringstream ss;
	c.print(ss);
	ASSERT_TRUE(ss.str() == "1");
}

// ----------------------
// Cell.change3
// ----------------------
TEST(Life, Cell_change3) {
	Cell c(false);
	c.change(false);
	ASSERT_TRUE(c.isAlive() == false);
	ostringstream ss;
	c.print(ss);
	ASSERT_TRUE(ss.str() == "-");
}

//----------------------
//ConwayCell.shouldLive1
//----------------------
TEST(Life, ConwayCell_shouldLive1) {
	ConwayCell c (false);
	ASSERT_TRUE(c.shouldLive(1) == false);
}

//----------------------
//ConwayCell.shouldLive2
//----------------------
TEST(Life, ConwayCell_shouldLive2) {
	ConwayCell c (false);
	ASSERT_TRUE(c.shouldLive(3) == true);
}

//----------------------
//ConwayCell.shouldLive3
//----------------------
TEST(Life, ConwayCell_shouldLive3) {
	ConwayCell c (true);
	ASSERT_TRUE(c.shouldLive(2) == true);
}

//----------------------
//ConwayCell.shouldLive4
//----------------------
TEST(Life, ConwayCell_shouldLive4) {
	ConwayCell c (true);
	ASSERT_TRUE(c.shouldLive(0) == false);
}

//-----------------------
//FredkinCell.shouldLive1
//-----------------------
TEST(Life, FredkinCell_shouldLive1) {
	FredkinCell c (false);
	ASSERT_TRUE(c.shouldLive(2) == false);
}

//-----------------------
//FredkinCell.shouldLive2
//-----------------------
TEST(Life, FredkinCell_shouldLive2) {
	FredkinCell c (false);
	ASSERT_TRUE(c.shouldLive(3) == true);
}

//-----------------------
//FredkinCell.shouldLive3
//-----------------------
TEST(Life, FredkinCell_shouldLive3) {
	FredkinCell c (true);
	ASSERT_TRUE(c.shouldLive(1) == true);
}

//-----------------------
//FredkinCell.shouldLive4
//-----------------------
TEST(Life, FredkinCell_shouldLive4) {
	FredkinCell c (true);
	ASSERT_TRUE(c.shouldLive(0) == false);
}

//----------------
//Cell.shouldLive1
//----------------
TEST(Life, Cell_shouldLive1) {
	Cell c (true);
	ASSERT_TRUE(c.shouldLive(0) == false);
}

//----------------
//Cell.shouldLive2
//----------------
TEST(Life, Cell_shouldLive2) {
	Cell c (true);
	ASSERT_TRUE(c.shouldLive(1) == true);
}

//----------------
//Cell.shouldLive3
//----------------
TEST(Life, Cell_shouldLive3) {	//should now be a ConwayCell
	Cell c (true);
	c.change(true);
	c.change(true);
	ASSERT_TRUE(c.shouldLive(2) == true);
}

//----------------
//Cell.shouldLive4
//----------------
TEST(Life, Cell_shouldLive4) {
	Cell c (true);
	c.change(true);
	c.change(true);
	ASSERT_TRUE(c.shouldLive(1) == false);
}

//-----------------
//ConwayCell.print1
//-----------------
TEST(Life, ConwayCell_print1) {
	ConwayCell c (false);
	ostringstream ss;
	c.print(ss);
	ASSERT_TRUE(ss.str() == ".");
}

//-----------------
//ConwayCell.print2
//-----------------
TEST(Life, ConwayCell_print2) {
	ConwayCell c (true);
	ostringstream ss;
	c.print(ss);
	ASSERT_TRUE(ss.str() == "*");
}

//-----------------
//ConwayCell.print3
//-----------------
TEST(Life, ConwayCell_print3) {
	ConwayCell c (true);
	c.change(false);
	ostringstream ss;
	c.print(ss);
	ASSERT_TRUE(ss.str() == ".");
}

//-----------------
//ConwayCell.print4
//-----------------
TEST(Life, ConwayCell_print4) {
	ConwayCell c (false);
	c.change(true);
	ostringstream ss;
	c.print(ss);
	ASSERT_TRUE(ss.str() == "*");
}

//------------------
//FredkinCell.print1
//------------------
TEST(Life, Fredkin_print1) {
	FredkinCell c (false);
	ostringstream ss;
	c.print(ss);
	ASSERT_TRUE(ss.str() == "-");
}

//------------------
//FredkinCell.print2
//------------------
TEST(Life, Fredkin_print2) {
	FredkinCell c (true);
	ostringstream ss;
	c.print(ss);
	ASSERT_TRUE(ss.str() == "0");
}

//------------------
//FredkinCell.print3
//------------------
TEST(Life, Fredkin_print3) {
	FredkinCell c (true);
	c.age = 4;
	ostringstream ss;
	c.print(ss);
	ASSERT_TRUE(ss.str() == "4");
}

//------------------
//FredkinCell.print4
//------------------
TEST(Life, Fredkin_print4) {
	FredkinCell c (true);
	c.age = 10;
	ostringstream ss;
	c.print(ss);
	ASSERT_TRUE(ss.str() == "+");
}

//------------------
//Cell.print1
//------------------
TEST(Life, Cell_print1) {
	Cell c (true);
	ostringstream ss;
	c.print(ss);
	ASSERT_TRUE(ss.str() == "0");
}

//------------------
//Cell.print2
//------------------
TEST(Life, Cell_print2) {
	Cell c (true);
	c.change(false);
	ostringstream ss;
	c.print(ss);
	ASSERT_TRUE(ss.str() == "-");
}

//------------------
//Cell.print3
//------------------
TEST(Life, Cell_print3) {		//proves that age is maintained through death
	Cell c (true);
	c.change(true);
	c.change(false);
	c.change(true);
	ostringstream ss;
	c.print(ss);
	ASSERT_TRUE(ss.str() == "1");
}

//------------------
//Cell.print4
//------------------
TEST(Life, Cell_print4) {		//proves that print changes when Cell changes from pointing to ConwayCell to pointing to FredkinCell
	Cell c (true);
	c.change(true);
	c.change(false);
	c.change(true);
	c.change(true);
	ostringstream ss;
	c.print(ss);
	ASSERT_TRUE(ss.str() == "*");
}

//----------------------
//ConwayCell.isNeighbor1
//----------------------
TEST(Life, Conway_isNeighbor1) {
	ConwayCell c (true);
	ASSERT_TRUE(c.isNeighbor(1, 1));
}

//----------------------
//ConwayCell.isNeighbor2
//----------------------
TEST(Life, Conway_isNeighbor2) {
	ConwayCell c (true);
	ASSERT_FALSE(c.isNeighbor(0, 0));
}

//----------------------
//ConwayCell.isNeighbor3
//----------------------
TEST(Life, Conway_isNeighbor3) {
	ConwayCell c (true);
	ASSERT_FALSE(c.isNeighbor(2, 0));
}

//----------------------
//ConwayCell.isNeighbor4
//----------------------
TEST(Life, Conway_isNeighbor4) {
	ConwayCell c (true);
	ASSERT_TRUE(c.isNeighbor(1, 0));
}

//-----------------------
//FredkinCell.isNeighbor1
//-----------------------
TEST(Life, Fredkin_isNeighbor1) {
	FredkinCell c (true);
	ASSERT_FALSE(c.isNeighbor(0, 0));
}

//-----------------------
//FredkinCell.isNeighbor2
//-----------------------
TEST(Life, Fredkin_isNeighbor2) {
	FredkinCell c (true);
	ASSERT_TRUE(c.isNeighbor(1, 0));
}

//-----------------------
//FredkinCell.isNeighbor3
//-----------------------
TEST(Life, Fredkin_isNeighbor3) {
	FredkinCell c (true);
	ASSERT_FALSE(c.isNeighbor(1, 1));
}

//-----------------------
//FredkinCell.isNeighbor4
//-----------------------
TEST(Life, Fredkin_isNeighbor4) {
	FredkinCell c (true);
	ASSERT_FALSE(c.isNeighbor(2, 0));
}

//-----------------------
//Cell.isNeighbor1
//-----------------------
TEST(Life, Cell_isNeighbor1) {
	Cell c (false);
	ASSERT_TRUE(c.isNeighbor(1, 0));
}

//-----------------------
//Cell.isNeighbor2
//-----------------------
TEST(Life, Cell_isNeighbor2) {
	Cell c (true);
	ASSERT_FALSE(c.isNeighbor(1, 1));
}

//-----------------------
//Cell.isNeighbor3
//-----------------------
TEST(Life, Cell_isNeighbor3) {
	Cell c (true);
	c.change(true);
	c.change(true);
	c.change(true);
	ASSERT_TRUE(c.isNeighbor(1, 1));
}

//-------------------
//Life.getPopulation1
//-------------------
TEST(Life, Life_getPopulation1) {
	vector<Position> aliveCells;
	aliveCells.push_back(Position(0, 0));
	Life<ConwayCell> life(3, 3, aliveCells);
	ASSERT_TRUE(life.getPopulation()==1);
}

//-------------------
//Life.getPopulation2
//-------------------
TEST(Life, Life_getPopulation2) {
	vector<Position> aliveCells;
	aliveCells.push_back(Position(0, 0));
	aliveCells.push_back(Position(1, 0));
	aliveCells.push_back(Position(2, 2));
	Life<FredkinCell> life(3, 3, aliveCells);
	ASSERT_TRUE(life.getPopulation()==3);
}

//-------------------
//Life.getPopulation3
//-------------------
TEST(Life, Life_getPopulation3) {
	vector<Position> aliveCells;
	for(int i = 0; i < 20; i++)
		for(int j = 0; j < 20; j++)
			aliveCells.push_back(Position(i, j));
	Life<Cell> life(20, 20, aliveCells);
	ASSERT_TRUE(life.getPopulation()==(20*20));
}

//-------------------
//Life.getPopulation4
//-------------------
TEST(Life, Life_getPopulation4) {
	vector<Position> aliveCells;
	Life<Cell> life(200, 200, aliveCells);
	ASSERT_TRUE(life.getPopulation()==0);
}