// ---------------------------------
// TestLife.c++
// Copyright (C) 2013
// Vitor Verissimo & Alyssa Williams
// ---------------------------------

///--------
///includes
///--------

#include <iostream>

#include "gtest/gtest.h"
#define private public
#define protected public
#define class struct
#include "Life.h"
#include "ConwayCell.h"
#include "FredkinCell.h"

using namespace std;

/// ----
/// Life
/// ----


// ------------
// constructors
// ------------

// Conway -----------------------------------------

TEST(Life, Life_constructor_Conway_size_1_1) {
	Life<ConwayCell> life(1, 1, ConwayCell());
	ASSERT_TRUE(!(life.grid[0][0]._isAlive));
	ASSERT_TRUE(life.grid.size() == 1);
	ASSERT_TRUE(life.grid[0].size() == 1);
	ASSERT_EQ(life._gen, 0);
	ASSERT_EQ(life._pop, 0);
}

TEST(Life, Life_constructor_Conway_size_2_2) {
	Life<ConwayCell> life(2, 2, ConwayCell());
	ASSERT_TRUE(!(life.grid[0][0]._isAlive));
	ASSERT_TRUE(!(life.grid[1][0]._isAlive));
	ASSERT_TRUE(!(life.grid[0][1]._isAlive));
	ASSERT_TRUE(!(life.grid[1][1]._isAlive));
	ASSERT_TRUE(life.grid.size() == 2);
	ASSERT_TRUE(life.grid[0].size() == 2);
	ASSERT_EQ(life._gen, 0);
	ASSERT_EQ(life._pop, 0);
}

TEST(Life, Life_constructor_Conway_size_1_5) {
	Life<ConwayCell> life(1, 5, ConwayCell());
	ASSERT_TRUE(!(life.grid[0][0]._isAlive));
	ASSERT_TRUE(!(life.grid[0][1]._isAlive));
	ASSERT_TRUE(!(life.grid[0][2]._isAlive));
	ASSERT_TRUE(!(life.grid[0][3]._isAlive));
	ASSERT_TRUE(!(life.grid[0][4]._isAlive));
	ASSERT_TRUE(life.grid.size() == 1);
	ASSERT_TRUE(life.grid[0].size() == 5);
	ASSERT_EQ(life._gen, 0);
	ASSERT_EQ(life._pop, 0);
}

// Fredkin -----------------------------------------

TEST(Life, Life_constructor_Fredkin_size_1_1) {
	Life<FredkinCell> life(1, 1, FredkinCell());
	ASSERT_TRUE(!(life.grid[0][0]._isAlive));
	ASSERT_TRUE(life.grid.size() == 1);
	ASSERT_TRUE(life.grid[0].size() == 1);
	ASSERT_EQ(life._gen, 0);
	ASSERT_EQ(life._pop, 0);
}

TEST(Life, Life_constructor_Fredkin_size_2_2) {
	Life<FredkinCell> life(2, 2, FredkinCell());
	ASSERT_TRUE(!(life.grid[0][0]._isAlive));
	ASSERT_TRUE(!(life.grid[1][0]._isAlive));
	ASSERT_TRUE(!(life.grid[0][1]._isAlive));
	ASSERT_TRUE(!(life.grid[1][1]._isAlive));
	ASSERT_TRUE(life.grid.size() == 2);
	ASSERT_TRUE(life.grid[0].size() == 2);
	ASSERT_EQ(life._gen, 0);
	ASSERT_EQ(life._pop, 0);
}

TEST(Life, Life_constructor_Fredkin_size_1_5) {
	Life<FredkinCell> life(1, 5, FredkinCell());
	ASSERT_TRUE(!(life.grid[0][0]._isAlive));
	ASSERT_TRUE(!(life.grid[0][1]._isAlive));
	ASSERT_TRUE(!(life.grid[0][2]._isAlive));
	ASSERT_TRUE(!(life.grid[0][3]._isAlive));
	ASSERT_TRUE(!(life.grid[0][4]._isAlive));
	ASSERT_TRUE(life.grid.size() == 1);
	ASSERT_TRUE(life.grid[0].size() == 5);
	ASSERT_EQ(life._gen, 0);
	ASSERT_EQ(life._pop, 0);
}

// Cell -----------------------------------------

TEST(Life, Life_constructor_Cell_size_1_1) {
	Life<Cell> life(1, 1, Cell(new FredkinCell()));
	ASSERT_TRUE(!(life.grid[0][0].isAlive()));
	ASSERT_TRUE(life.grid.size() == 1);
	ASSERT_TRUE(life.grid[0].size() == 1);
}

TEST(Life, Life_constructor_Cell_size_2_2) {
	Life<Cell> life(2, 2, Cell(new FredkinCell()));
	ASSERT_TRUE(!(life.grid[0][0].isAlive()));
	ASSERT_TRUE(!(life.grid[1][0].isAlive()));
	ASSERT_TRUE(!(life.grid[0][1].isAlive()));
	ASSERT_TRUE(!(life.grid[1][1].isAlive()));
	ASSERT_TRUE(life.grid.size() == 2);
	ASSERT_TRUE(life.grid[0].size() == 2);
}

TEST(Life, Life_constructor_Cell_size_1_5) {
	Life<Cell> life(1, 5, Cell(new FredkinCell()));
	ASSERT_TRUE(!(life.grid[0][0].isAlive()));
	ASSERT_TRUE(!(life.grid[0][1].isAlive()));
	ASSERT_TRUE(!(life.grid[0][2].isAlive()));
	ASSERT_TRUE(!(life.grid[0][3].isAlive()));
	ASSERT_TRUE(!(life.grid[0][4].isAlive()));
	ASSERT_TRUE(life.grid.size() == 1);
	ASSERT_TRUE(life.grid[0].size() == 5);
}

// --------
// populate
// --------

// Conway -----------------------------------------

TEST(Life, Life_populate_Conway_one) {
	Life<ConwayCell> life(2, 2, ConwayCell());
	std::istringstream r("*.\n..\n");
	life.populate(r);
	ASSERT_TRUE(life.grid[0][0]._isAlive);
	ASSERT_TRUE(!(life.grid[0][1]._isAlive));
	ASSERT_TRUE(!(life.grid[1][0]._isAlive));
	ASSERT_TRUE(!(life.grid[1][1]._isAlive));
}

TEST(Life, Life_populate_Conway_all) {
	Life<ConwayCell> life(2, 2, ConwayCell());
	std::istringstream r("**\n**\n");
	life.populate(r);
	ASSERT_TRUE(life.grid[0][0]._isAlive);
	ASSERT_TRUE(life.grid[0][1]._isAlive);
	ASSERT_TRUE(life.grid[1][0]._isAlive);
	ASSERT_TRUE(life.grid[1][1]._isAlive);
}

TEST(Life, Life_populate_Conway_some1) {
	Life<ConwayCell> life(3, 3, ConwayCell());
	std::istringstream r(".**\n**.\n...\n");
	life.populate(r);
	ASSERT_TRUE(!(life.grid[0][0]._isAlive));
	ASSERT_TRUE(life.grid[0][1]._isAlive);
	ASSERT_TRUE(life.grid[0][2]._isAlive);
	ASSERT_TRUE(life.grid[1][0]._isAlive);
	ASSERT_TRUE(life.grid[1][1]._isAlive);
	ASSERT_TRUE(!(life.grid[1][2]._isAlive));
	ASSERT_TRUE(!(life.grid[2][0]._isAlive));
	ASSERT_TRUE(!(life.grid[2][1]._isAlive));
	ASSERT_TRUE(!(life.grid[2][2]._isAlive));
}

TEST(Life, Life_populate_Conway_some2) {
	Life<ConwayCell> life(3, 3, ConwayCell());
	std::istringstream r("***\n**.\n***\n");
	life.populate(r);
	ASSERT_TRUE(life.grid[0][0]._isAlive);
	ASSERT_TRUE(life.grid[0][1]._isAlive);
	ASSERT_TRUE(life.grid[0][2]._isAlive);
	ASSERT_TRUE(life.grid[1][0]._isAlive);
	ASSERT_TRUE(life.grid[1][1]._isAlive);
	ASSERT_TRUE(!(life.grid[1][2]._isAlive));
	ASSERT_TRUE(life.grid[2][0]._isAlive);
	ASSERT_TRUE(life.grid[2][1]._isAlive);
	ASSERT_TRUE(life.grid[2][2]._isAlive);
}

// Fredkin -----------------------------------------

TEST(Life, Life_populate_Fredkin_one) {
	Life<FredkinCell> life(2, 2, FredkinCell());
	std::istringstream r("0-\n--\n");
	life.populate(r);
	ASSERT_TRUE(life.grid[0][0]._isAlive);
	ASSERT_TRUE(!(life.grid[0][1]._isAlive));
	ASSERT_TRUE(!(life.grid[1][0]._isAlive));
	ASSERT_TRUE(!(life.grid[1][1]._isAlive));
}

TEST(Life, Life_populate_Fredkin_all) {
	Life<FredkinCell> life(2, 2, FredkinCell());
	std::istringstream r("10\n21\n");
	life.populate(r);
	ASSERT_TRUE(life.grid[0][0]._isAlive);
	ASSERT_TRUE(life.grid[0][1]._isAlive);
	ASSERT_TRUE(life.grid[1][0]._isAlive);
	ASSERT_TRUE(life.grid[1][1]._isAlive);
}

TEST(Life, Life_populate_Fredkin_some1) {
	Life<FredkinCell> life(3, 3, FredkinCell());
	std::istringstream r("-00\n21-\n---\n");
	life.populate(r);
	ASSERT_TRUE(!(life.grid[0][0]._isAlive));
	ASSERT_TRUE(life.grid[0][1]._isAlive);
	ASSERT_TRUE(life.grid[0][2]._isAlive);
	ASSERT_TRUE(life.grid[1][0]._isAlive);
	ASSERT_TRUE(life.grid[1][1]._isAlive);
	ASSERT_TRUE(!(life.grid[1][2]._isAlive));
	ASSERT_TRUE(!(life.grid[2][0]._isAlive));
	ASSERT_TRUE(!(life.grid[2][1]._isAlive));
	ASSERT_TRUE(!(life.grid[2][2]._isAlive));
}

TEST(Life, Life_populate_Fredkin_some2) {
	Life<FredkinCell> life(3, 3, FredkinCell());
	std::istringstream r("123\n04-\n224\n");
	life.populate(r);
	ASSERT_TRUE(life.grid[0][0]._isAlive);
	ASSERT_TRUE(life.grid[0][1]._isAlive);
	ASSERT_TRUE(life.grid[0][2]._isAlive);
	ASSERT_TRUE(life.grid[1][0]._isAlive);
	ASSERT_TRUE(life.grid[1][1]._isAlive);
	ASSERT_TRUE(!(life.grid[1][2]._isAlive));
	ASSERT_TRUE(life.grid[2][0]._isAlive);
	ASSERT_TRUE(life.grid[2][1]._isAlive);
	ASSERT_TRUE(life.grid[2][2]._isAlive);
}

// Cell -----------------------------------------

TEST(Life, Life_populate_Cell_one) {
	Life<Cell> life(2, 2, Cell(new FredkinCell()));
	std::istringstream r("0-\n--\n\n");
	life.populate(r);
	ASSERT_TRUE(life.grid[0][0].isAlive());
	ASSERT_TRUE(!(life.grid[0][1].isAlive()));
	ASSERT_TRUE(!(life.grid[1][0].isAlive()));
	ASSERT_TRUE(!(life.grid[1][1].isAlive()));
}

TEST(Life, Life_populate_Cell_all) {
	Life<Cell> life(2, 2, Cell(new FredkinCell()));
	std::istringstream r("10\n11\n\n");
	life.populate(r);
	ASSERT_TRUE(life.grid[0][0].isAlive());
	ASSERT_TRUE(life.grid[0][1].isAlive());
	ASSERT_TRUE(life.grid[1][0].isAlive());
	ASSERT_TRUE(life.grid[1][1].isAlive());
}

TEST(Life, Life_populate_Cell_some1) {
	Life<Cell> life(3, 3, Cell(new FredkinCell()));
	std::istringstream r("-00\n01-\n---\n");
	life.populate(r);
	ASSERT_TRUE(!(life.grid[0][0].isAlive()));
	ASSERT_TRUE(life.grid[0][1].isAlive());
	ASSERT_TRUE(life.grid[0][2].isAlive());
	ASSERT_TRUE(life.grid[1][0].isAlive());
	ASSERT_TRUE(life.grid[1][1].isAlive());
	ASSERT_TRUE(!(life.grid[1][2].isAlive()));
	ASSERT_TRUE(!(life.grid[2][0].isAlive()));
	ASSERT_TRUE(!(life.grid[2][1].isAlive()));
	ASSERT_TRUE(!(life.grid[2][2].isAlive()));
}

TEST(Life, Life_populate_Cell_some2) {
	Life<Cell> life(3, 3, Cell(new FredkinCell()));
	std::istringstream r("100\n01-\n010\n");
	life.populate(r);
	ASSERT_TRUE(life.grid[0][0].isAlive());
	ASSERT_TRUE(life.grid[0][1].isAlive());
	ASSERT_TRUE(life.grid[0][2].isAlive());
	ASSERT_TRUE(life.grid[1][0].isAlive());
	ASSERT_TRUE(life.grid[1][1].isAlive());
	ASSERT_TRUE(!(life.grid[1][2].isAlive()));
	ASSERT_TRUE(life.grid[2][0].isAlive());
	ASSERT_TRUE(life.grid[2][1].isAlive());
	ASSERT_TRUE(life.grid[2][2].isAlive());
}

// --------
// popCount
// --------

// Conway -----------------------------------------

TEST(Life, Life_popCount_Conway_none) {
	ConwayCell cell = ConwayCell();
	Life<ConwayCell> life(3, 3, cell);
	int ret = life.popCount();
	ASSERT_EQ(ret, 0);
}

TEST(Life, Life_popCount_Conway1) {
	Life<ConwayCell> life(2, 2, ConwayCell());
	std::istringstream r("*.\n..\n");
	life.populate(r);
	int ret = life.popCount();
	ASSERT_EQ(ret, 1);
}

TEST(Life, Life_popCount_Conway3) {
	Life<ConwayCell> life(2, 2, ConwayCell());
	std::istringstream r("**\n**\n");;
	life.populate(r);
	int ret = life.popCount();
	ASSERT_EQ(ret, 4);
}

TEST(Life, Life_popCount_Conway4) {
	Life<ConwayCell> life(3, 3, ConwayCell());
	std::istringstream r(".**\n**.\n...\n");
	life.populate(r);
	int ret = life.popCount();
	ASSERT_EQ(ret, 4);
}

TEST(Life, Life_popCount_Conway5) {
	Life<ConwayCell> life(3, 3, ConwayCell());
	std::istringstream r("***\n**.\n***\n");
	life.populate(r);
	int ret = life.popCount();
	ASSERT_EQ(ret, 8);
}

// Fredkin -----------------------------------------

TEST(Life, Life_popCount_Fredkin1) {
	Life<FredkinCell> life(2, 2, FredkinCell());
	std::istringstream r("0-\n--\n");
	life.populate(r);
	int ret = life.popCount();
	ASSERT_EQ(ret, 1);
}

TEST(Life, Life_popCount_Fredkin2) {
	Life<FredkinCell> life(2, 2, FredkinCell());
	std::istringstream r("10\n21\n");
	life.populate(r);
	int ret = life.popCount();
	ASSERT_EQ(ret, 4);
}

TEST(Life, Life_popCount_Fredkin3) {
	Life<FredkinCell> life(3, 3, FredkinCell());
	std::istringstream r("-00\n21-\n---\n");
	life.populate(r);
	int ret = life.popCount();
	ASSERT_EQ(ret, 4);
}

TEST(Life, Life_popCount_Fredkin4) {
	Life<FredkinCell> life(3, 3, FredkinCell());
	std::istringstream r("123\n04-\n224\n");
	life.populate(r);
	int ret = life.popCount();
	ASSERT_EQ(ret, 8);
}

// Cell -----------------------------------------

TEST(Life, Life_popCount_Cell1) {
	Life<Cell> life(2, 2, Cell(new FredkinCell()));
	std::istringstream r("0-\n--\n\n");
	life.populate(r);
	int ret = life.popCount();
	ASSERT_EQ(ret, 1);
}

TEST(Life, Life_popCount_Cell2) {
	Life<Cell> life(2, 2, Cell(new FredkinCell()));
	std::istringstream r("10\n11\n\n");
	life.populate(r);
	int ret = life.popCount();
	ASSERT_EQ(ret, 4);
}

TEST(Life, Life_popCount_Cell3) {
	Life<Cell> life(3, 3, Cell(new FredkinCell()));
	std::istringstream r("-00\n01-\n---\n");
	life.populate(r);
	int ret = life.popCount();
	ASSERT_EQ(ret, 4);
}

TEST(Life, Life_popCount_Cell4) {
	Life<Cell> life(3, 3, Cell(new FredkinCell()));
	std::istringstream r("100\n-1-\n010\n");
	life.populate(r);
	int ret = life.popCount();
	ASSERT_EQ(ret, 7);
}


// ---------
// neighbors
// ---------

// Conway -----------------------------------------

TEST(Life, Life_neighbors_Conway_none) {
	ConwayCell cell = ConwayCell();
	Life<ConwayCell> life(3, 3, cell);
	vector<int> nbors = life.neighbors(1, 1);
	ASSERT_TRUE(nbors[TOPLEFT] == 0);
	ASSERT_TRUE(nbors[TOP] == 0);
	ASSERT_TRUE(nbors[TOPRIGHT] == 0);
	ASSERT_TRUE(nbors[LEFT] == 0);
	ASSERT_TRUE(nbors[RIGHT] == 0);
	ASSERT_TRUE(nbors[BOTTOMLEFT] == 0);
	ASSERT_TRUE(nbors[BOTTOM] == 0);
	ASSERT_TRUE(nbors[BOTTOMRIGHT] == 0);
}

TEST(Life, Life_neighbors_Conway_filled) {
	ConwayCell cell = ConwayCell();
	Life<ConwayCell> life(3, 3, cell);
	std::istringstream r(".**\n**.\n...\n");
	life.populate(r);
	vector<int> nbors = life.neighbors(1, 1);
	vector<int> correct {0, 1, 1, 1, 0, 0, 0, 0};
	ASSERT_TRUE(nbors == correct);
}

TEST(Life, Life_neighbors_Conway_edge) {
	ConwayCell cell = ConwayCell();
	Life<ConwayCell> life(3, 3, cell);
	std::istringstream r("*.*\n**.\n.**\n");
	life.populate(r);
	vector<int> nbors = life.neighbors(1, 0);
	vector<int> correctleft {0, 1, 0, 0, 1, 0, 0, 1};
	ASSERT_TRUE(nbors == correctleft);
	nbors = life.neighbors(0, 1);
	vector<int> correcttop {0, 0, 0, 1, 1, 1, 1, 0};
	ASSERT_TRUE(nbors == correcttop);
	nbors = life.neighbors(1, 2);
	vector<int> correctright {0, 1, 0, 1, 0, 1, 1, 0};
	ASSERT_TRUE(nbors == correctright);
	nbors = life.neighbors(2, 1);
	vector<int> correctbottom {1, 1, 0, 0, 1, 0, 0, 0};
	ASSERT_TRUE(nbors == correctbottom);
}

TEST(Life, Life_neighbors_Conway_corner) {
	ConwayCell cell = ConwayCell();
	Life<ConwayCell> life(3, 3, cell);
	std::istringstream r("*.*\n.**\n.*.\n");
	life.populate(r);
	vector<int> nbors = life.neighbors(0, 0);
	vector<int> correcttopleft {0, 0, 0, 0, 0, 0, 0, 1};
	ASSERT_TRUE(nbors == correcttopleft);
	nbors = life.neighbors(0, 2);
	vector<int> correcttopright {0, 0, 0, 0, 0, 1, 1, 0};
	ASSERT_TRUE(nbors == correcttopright);
	nbors = life.neighbors(2, 0);
	vector<int> correctbottomleft {0, 0, 1, 0, 1, 0, 0, 0};
	ASSERT_TRUE(nbors == correctbottomleft);
	nbors = life.neighbors(2, 2);
	vector<int> correctbottomright {1, 1, 0, 1, 0, 0, 0, 0};
	ASSERT_TRUE(nbors == correctbottomright);
}

// Fredkin -----------------------------------------

TEST(Life, Life_neighbors_Fred_none) {
	FredkinCell cell = FredkinCell();
	Life<FredkinCell> life(3, 3, cell);
	vector<int> nbors = life.neighbors(1, 1);
	ASSERT_TRUE(nbors[TOPLEFT] == 0);
	ASSERT_TRUE(nbors[TOP] == 0);
	ASSERT_TRUE(nbors[TOPRIGHT] == 0);
	ASSERT_TRUE(nbors[LEFT] == 0);
	ASSERT_TRUE(nbors[RIGHT] == 0);
	ASSERT_TRUE(nbors[BOTTOMLEFT] == 0);
	ASSERT_TRUE(nbors[BOTTOM] == 0);
	ASSERT_TRUE(nbors[BOTTOMRIGHT] == 0);
}

TEST(Life, Life_neighbors_Fred_filled) {
	FredkinCell cell = FredkinCell();
	Life<FredkinCell> life(3, 3, cell);
	std::istringstream r("-01\n40-\n---\n");
	life.populate(r);
	vector<int> nbors = life.neighbors(1, 1);
	vector<int> correct {0, 1, 1, 1, 0, 0, 0, 0};
	ASSERT_TRUE(nbors == correct);
}

TEST(Life, Life_neighbors_Fred_edge) {
	FredkinCell cell = FredkinCell();
	Life<FredkinCell> life(3, 3, cell);
	std::istringstream r("5-1\n72-\n-38\n");
	life.populate(r);
	vector<int> nbors = life.neighbors(1, 0);
	vector<int> correctleft {0, 1, 0, 0, 1, 0, 0, 1};
	ASSERT_TRUE(nbors == correctleft);
	nbors = life.neighbors(0, 1);
	vector<int> correcttop {0, 0, 0, 1, 1, 1, 1, 0};
	ASSERT_TRUE(nbors == correcttop);
	nbors = life.neighbors(1, 2);
	vector<int> correctright {0, 1, 0, 1, 0, 1, 1, 0};
	ASSERT_TRUE(nbors == correctright);
	nbors = life.neighbors(2, 1);
	vector<int> correctbottom {1, 1, 0, 0, 1, 0, 0, 0};
	ASSERT_TRUE(nbors == correctbottom);
}

TEST(Life, Life_neighbors_Fred_corner) {
	FredkinCell cell = FredkinCell();
	Life<FredkinCell> life(3, 3, cell);
	std::istringstream r("1-1\n-22\n-3-\n");
	life.populate(r);
	vector<int> nbors = life.neighbors(0, 0);
	vector<int> correcttopleft {0, 0, 0, 0, 0, 0, 0, 1};
	ASSERT_TRUE(nbors == correcttopleft);
	nbors = life.neighbors(0, 2);
	vector<int> correcttopright {0, 0, 0, 0, 0, 1, 1, 0};
	ASSERT_TRUE(nbors == correcttopright);
	nbors = life.neighbors(2, 0);
	vector<int> correctbottomleft {0, 0, 1, 0, 1, 0, 0, 0};
	ASSERT_TRUE(nbors == correctbottomleft);
	nbors = life.neighbors(2, 2);
	vector<int> correctbottomright {1, 1, 0, 1, 0, 0, 0, 0};
	ASSERT_TRUE(nbors == correctbottomright);
}

// Cell -----------------------------------------

TEST(Life, Life_neighbors_Cell_none) {
	Life<Cell> life(3, 3, Cell(new FredkinCell()));
	vector<int> nbors = life.neighbors(1, 1);
	ASSERT_TRUE(nbors[TOPLEFT] == 0);
	ASSERT_TRUE(nbors[TOP] == 0);
	ASSERT_TRUE(nbors[TOPRIGHT] == 0);
	ASSERT_TRUE(nbors[LEFT] == 0);
	ASSERT_TRUE(nbors[RIGHT] == 0);
	ASSERT_TRUE(nbors[BOTTOMLEFT] == 0);
	ASSERT_TRUE(nbors[BOTTOM] == 0);
	ASSERT_TRUE(nbors[BOTTOMRIGHT] == 0);
}

TEST(Life, Life_neighbors_Cell_filled) {
	Life<Cell> life(3, 3, Cell(new FredkinCell()));
	std::istringstream r("-00\n00-\n---\n");
	life.populate(r);
	vector<int> nbors = life.neighbors(1, 1);
	vector<int> correct {0, 1, 1, 1, 0, 0, 0, 0};
	ASSERT_TRUE(nbors == correct);
}

TEST(Life, Life_neighbors_Cell_edge) {
	Life<Cell> life(3, 3, Cell(new FredkinCell()));
	std::istringstream r("0-0\n00-\n-00\n");
	life.populate(r);
	vector<int> nbors = life.neighbors(1, 0);
	vector<int> correctleft {0, 1, 0, 0, 1, 0, 0, 1};
	ASSERT_TRUE(nbors == correctleft);
	nbors = life.neighbors(0, 1);
	vector<int> correcttop {0, 0, 0, 1, 1, 1, 1, 0};
	ASSERT_TRUE(nbors == correcttop);
	nbors = life.neighbors(1, 2);
	vector<int> correctright {0, 1, 0, 1, 0, 1, 1, 0};
	ASSERT_TRUE(nbors == correctright);
	nbors = life.neighbors(2, 1);
	vector<int> correctbottom {1, 1, 0, 0, 1, 0, 0, 0};
	ASSERT_TRUE(nbors == correctbottom);
} 

TEST(Life, Life_neighbors_Cell_corner) {
	Life<Cell> life(3, 3, Cell(new FredkinCell()));
	std::istringstream r("0-0\n-00\n-0-\n");
	life.populate(r);
	vector<int> nbors = life.neighbors(0, 0);
	vector<int> correcttopleft {0, 0, 0, 0, 0, 0, 0, 1};
	ASSERT_TRUE(nbors == correcttopleft);
	nbors = life.neighbors(0, 2);
	vector<int> correcttopright {0, 0, 0, 0, 0, 1, 1, 0};
	ASSERT_TRUE(nbors == correcttopright);
	nbors = life.neighbors(2, 0);
	vector<int> correctbottomleft {0, 0, 1, 0, 1, 0, 0, 0};
	ASSERT_TRUE(nbors == correctbottomleft);
	nbors = life.neighbors(2, 2);
	vector<int> correctbottomright {1, 1, 0, 1, 0, 0, 0, 0};
	ASSERT_TRUE(nbors == correctbottomright);
}

/// ----------
/// ConwayCell
/// ----------

// ------------
// constructors
// ------------

TEST(Life, ConwayCell_constr_default) {
    ConwayCell cell = ConwayCell();
    ASSERT_EQ(cell._isAlive, false);
}

TEST(Life, ConwayCell_constr_bool1) {
    ConwayCell cell = ConwayCell(true);
    ASSERT_EQ(cell._isAlive, true);
}

TEST(Life, ConwayCell_constr_bool2) {
    ConwayCell cell = ConwayCell(false);
    ASSERT_EQ(cell._isAlive, false);
}

// -----
// clone
// -----

TEST(Life, ConwayCell_clone) {
    ConwayCell cell = ConwayCell();
    AbstractCell* p = cell.clone();
    ASSERT_EQ(p->_isAlive, false);
    delete p;
}

TEST(Life, ConwayCell_clone2) {
    ConwayCell cell = ConwayCell();
    AbstractCell* p = cell.clone();
    ASSERT_TRUE(p != &cell);
    delete p;
}

TEST(Life, ConwayCell_clone3) {
    ConwayCell cell = ConwayCell();
    AbstractCell* p = cell.clone();
    ASSERT_TRUE(p != &cell);
    delete p;
}

// -----------
// decideState
// -----------

TEST(Life, ConwayCell_decideState1) {
    ConwayCell cell = ConwayCell();
    vector<int> nbors = {0, 1, 1, 1, 0, 0, 0, 0};
    cell.decideState(nbors);
    ASSERT_EQ(cell._isAliveNext, true);
    nbors = {0, 0, 1, 1, 0, 0, 0, 0};
    cell.decideState(nbors);
    ASSERT_EQ(cell._isAliveNext, false);
}

TEST(Life, ConwayCell_decideState2) {
    ConwayCell cell = ConwayCell();
    vector<int> nbors = {0, 1, 1, 1, 1, 1, 1, 0};
    cell.decideState(nbors);
    ASSERT_EQ(cell._isAliveNext, false);
    nbors = {0, 0, 1, 1, 0, 0, 0, 0};
    cell.decideState(nbors);
    ASSERT_EQ(cell._isAliveNext, false);
}

TEST(Life, ConwayCell_decideState3) {
    ConwayCell cell = ConwayCell(true);
    vector<int> nbors = {0, 1, 1, 1, 1, 1, 1, 1};
    cell.decideState(nbors);
    ASSERT_EQ(cell._isAliveNext, false);
    nbors = {0, 0, 1, 1, 1, 0, 0, 0};
    cell.decideState(nbors);
    ASSERT_EQ(cell._isAliveNext, true);
    nbors = {0, 0, 1, 1, 0, 0, 1, 0};
    cell.decideState(nbors);
    ASSERT_EQ(cell._isAliveNext, true);
}

TEST(Life, ConwayCell_decideState4) {
    ConwayCell cell = ConwayCell();
    vector<int> nbors = {1, 1, 1, 1, 1, 1, 1, 1};
    cell.decideState(nbors);
    ASSERT_EQ(cell._isAliveNext, false);
    nbors = {0, 0, 0, 0, 0, 0, 0, 0};
    cell.decideState(nbors);
    ASSERT_EQ(cell._isAliveNext, false);
    nbors = {0, 0, 1, 0, 0, 0, 1, 1};
    cell.decideState(nbors);
    ASSERT_EQ(cell._isAliveNext, true);
}

TEST(Life, ConwayCell_decideState5) {
    ConwayCell cell = ConwayCell(false);
    vector<int> nbors = {1, 0, 1, 0, 0, 1, 1, 1};
    cell.decideState(nbors);
    ASSERT_EQ(cell._isAliveNext, false);
    nbors = {0, 0, 0, 0, 0, 0, 0, 1};
    cell.decideState(nbors);
    ASSERT_EQ(cell._isAliveNext, false);
    nbors = {0, 0, 1, 0, 0, 0, 0, 0};
    cell.decideState(nbors);
    ASSERT_EQ(cell._isAliveNext, false);
}

TEST(Life, ConwayCell_decideState6) {
    ConwayCell cell = ConwayCell(true);
    vector<int> nbors = {1, 0, 1, 0, 0, 1, 1, 1};
    cell.decideState(nbors);
    ASSERT_EQ(cell._isAliveNext, false);
    nbors = {0, 0, 0, 0, 0, 0, 0, 1};
    cell.decideState(nbors);
    ASSERT_EQ(cell._isAliveNext, false);
    nbors = {0, 0, 1, 0, 0, 1, 0, 1};
    cell.decideState(nbors);
    ASSERT_EQ(cell._isAlive, true);
}

// -----
// print
// -----

TEST(Life, ConwayCell_print_defaultdead) {
    ConwayCell cell = ConwayCell();
    char ret = cell.print();
    ASSERT_EQ(ret, '.');
}

TEST(Life, ConwayCell_print_alive) {
    ConwayCell cell = ConwayCell(true);
    char ret = cell.print();
    ASSERT_EQ(ret, '*');
}

TEST(Life, ConwayCell_print_dead) {
    ConwayCell cell = ConwayCell(false);
    char ret = cell.print();
    ASSERT_EQ(ret, '.');
}

// ---------------
// decideInitState
// ---------------

TEST(Life, ConwayCell_decideInitState_alive1) {
    ConwayCell cell = ConwayCell();
    cell.decideInitState('*');
    ASSERT_EQ(cell._isAlive, true);
}

TEST(Life, ConwayCell_decideInitState_dead1) {
    ConwayCell cell = ConwayCell();
    cell.decideInitState('.');
    ASSERT_EQ(cell._isAlive, false);
}

TEST(Life, ConwayCell_decideInitState_alive2) {
    ConwayCell cell = ConwayCell(true);
    cell.decideInitState('*');
    ASSERT_EQ(cell._isAlive, true);
}

TEST(Life, ConwayCell_decideInitState_dead2) {
    ConwayCell cell = ConwayCell(true);
    cell.decideInitState('.');
    ASSERT_EQ(cell._isAlive, false);
}

TEST(Life, ConwayCell_decideInitState_alive3) {
    ConwayCell cell = ConwayCell(false);
    cell.decideInitState('*');
    ASSERT_EQ(cell._isAlive, true);
}

TEST(Life, ConwayCell_decideInitState_dead3) {
    ConwayCell cell = ConwayCell(false);
    cell.decideInitState('.');
    ASSERT_EQ(cell._isAlive, false);
}

/// -----------
/// FredkinCell
/// -----------

// ------------
// constructors
// ------------

TEST(Life, FredkinCell_constr_default) {
    FredkinCell cell = FredkinCell();
    ASSERT_EQ(cell._isAlive, false);
}

TEST(Life, FredkinCell_constr_bool1) {
    FredkinCell cell = FredkinCell(true);
    ASSERT_EQ(cell._isAlive, true);
    ASSERT_EQ(cell._age, 0);
}

TEST(Life, FredkinCell_constr_bool2) {
    FredkinCell cell = FredkinCell(false);
    ASSERT_EQ(cell._isAlive, false);
    ASSERT_EQ(cell._age, 0);
}

TEST(Life, FredkinCell_constr_age1) {
    FredkinCell cell = FredkinCell(true, 3);
    ASSERT_EQ(cell._isAlive, true);
    ASSERT_EQ(cell._age, 3);
}

TEST(Life, FredkinCell_constr_age2) {
    FredkinCell cell = FredkinCell(true, 1);
    ASSERT_EQ(cell._isAlive, true);
    ASSERT_EQ(cell._age, 1);
}

// -----
// clone
// -----

TEST(Life, FredkinCell_clone) {
    FredkinCell cell = FredkinCell();
    AbstractCell* p = cell.clone();
    ASSERT_EQ(p->_isAlive, false);
    delete p;
}

TEST(Life, FredkinCell_clone2) {
    FredkinCell cell = FredkinCell();
    AbstractCell* p = cell.clone();
    ASSERT_TRUE(p != &cell);
    delete p;
}

TEST(Life, FredkinCell_clone3) {
    FredkinCell cell = FredkinCell();
    AbstractCell* p = cell.clone();
    ASSERT_TRUE(p != &cell);
    delete p;
}

// -----------
// decideState
// -----------

// x TOP x LEFT RIGHT x BOTTOM x

TEST(Life, FredkinCell_decideState1) {
    FredkinCell cell = FredkinCell();
    vector<int> nbors = {0, 1, 1, 1, 0, 0, 0, 0};
    cell.decideState(nbors);
    ASSERT_EQ(cell._isAliveNext, false);
    nbors = {0, 0, 1, 1, 0, 0, 0, 0};
    cell.decideState(nbors);
    ASSERT_EQ(cell._isAliveNext, true);
}

TEST(Life, FredkinCell_decideState2) {
    FredkinCell cell = FredkinCell();
    vector<int> nbors = {0, 1, 1, 1, 1, 1, 0, 0};
    cell.decideState(nbors);
    ASSERT_EQ(cell._isAliveNext, true);
    nbors = {0, 0, 1, 1, 0, 0, 0, 0};
    cell.decideState(nbors);
    ASSERT_EQ(cell._isAliveNext, true);
}

TEST(Life, FredkinCell_decideState3) {
    FredkinCell cell = FredkinCell(true, 3);
    vector<int> nbors = {0, 1, 1, 1, 1, 1, 1, 1};
    cell.decideState(nbors);
    ASSERT_EQ(cell._isAliveNext, false);
    nbors = {0, 0, 1, 1, 1, 0, 0, 0};
    cell.decideState(nbors);
    ASSERT_EQ(cell._isAliveNext, false);
    nbors = {0, 0, 1, 1, 0, 0, 0, 0};
    cell.decideState(nbors);
    ASSERT_EQ(cell._isAliveNext, true);
}

TEST(Life, FredkinCell_decideState4) {
    FredkinCell cell = FredkinCell();
    vector<int> nbors = {1, 0, 1, 1, 1, 1, 1, 1};
    cell.decideState(nbors);
    ASSERT_EQ(cell._isAliveNext, true);
    nbors = {0, 0, 0, 0, 0, 0, 1, 0};
    cell.decideState(nbors);
    ASSERT_EQ(cell._isAliveNext, true);
    nbors = {0, 0, 1, 0, 0, 0, 0, 1};
    cell.decideState(nbors);
    ASSERT_EQ(cell._isAliveNext, false);
}

TEST(Life, FredkinCell_decideState5) {
    FredkinCell cell = FredkinCell(false);
    vector<int> nbors = {1, 0, 1, 0, 0, 1, 1, 1};
    cell.decideState(nbors);
    ASSERT_EQ(cell._isAliveNext, true);
    nbors = {0, 0, 0, 0, 0, 0, 0, 1};
    cell.decideState(nbors);
    ASSERT_EQ(cell._isAliveNext, false);
    nbors = {0, 0, 1, 0, 0, 0, 0, 0};
    cell.decideState(nbors);
    ASSERT_EQ(cell._isAliveNext, false);
}

TEST(Life, FredkinCell_decideState6) {
    FredkinCell cell = FredkinCell(true, 6);
    vector<int> nbors = {1, 0, 1, 0, 0, 1, 1, 1};
    cell.decideState(nbors);
    ASSERT_EQ(cell._isAliveNext, true);
    nbors = {0, 0, 0, 0, 0, 0, 0, 1};
    cell.decideState(nbors);
    ASSERT_EQ(cell._isAliveNext, false);
    nbors = {0, 0, 1, 0, 0, 1, 0, 1};
    cell.decideState(nbors);
    ASSERT_EQ(cell._isAliveNext, false);
}

// -----------
// changeState
// -----------

TEST(Life, FredkinCell_changeState1) {
    FredkinCell cell = FredkinCell();
    vector<int> nbors = {0, 1, 1, 1, 0, 0, 0, 0};
    cell.decideState(nbors);
    ASSERT_EQ(cell._isAliveNext, false);
    cell.changeState();
    ASSERT_EQ(cell._age, 0);
    nbors = {0, 0, 1, 1, 0, 0, 0, 0};
    cell.decideState(nbors);
    ASSERT_EQ(cell._isAliveNext, true);
    cell.changeState();
}

TEST(Life, FredkinCell_changeState2) {
    FredkinCell cell = FredkinCell();
    vector<int> nbors = {0, 1, 1, 1, 1, 1, 0, 0};
    cell.decideState(nbors);
    ASSERT_EQ(cell._isAliveNext, true);
    cell.changeState();
    nbors = {0, 0, 1, 1, 0, 0, 0, 0};
    cell.decideState(nbors);
    ASSERT_EQ(cell._isAliveNext, true);
    cell.changeState();
}

TEST(Life, FredkinCell_changeState3) {
    FredkinCell cell = FredkinCell(true, 3);
    vector<int> nbors = {0, 1, 1, 1, 1, 1, 1, 1};
    cell.decideState(nbors);
    ASSERT_EQ(cell._isAliveNext, false);
    cell.changeState();
    ASSERT_EQ(cell._age, 3);
    nbors = {0, 0, 1, 1, 1, 0, 0, 0};
    cell.decideState(nbors);
    ASSERT_EQ(cell._isAliveNext, false);
    cell.changeState();
    ASSERT_EQ(cell._age, 3);
    nbors = {0, 0, 1, 1, 0, 0, 0, 0};
    cell.decideState(nbors);
    ASSERT_EQ(cell._isAliveNext, true);
    cell.changeState();
}

TEST(Life, FredkinCell_changeState4) {
    FredkinCell cell = FredkinCell();
    vector<int> nbors = {1, 0, 1, 1, 1, 1, 1, 1};
    cell.decideState(nbors);
    ASSERT_EQ(cell._isAliveNext, true);
    cell.changeState();
    nbors = {0, 0, 0, 0, 0, 0, 1, 0};
    cell.decideState(nbors);
    ASSERT_EQ(cell._isAliveNext, true);
    cell.changeState();
    nbors = {0, 0, 1, 0, 0, 0, 0, 1};
    cell.decideState(nbors);
    ASSERT_EQ(cell._isAliveNext, false);
    cell.changeState();
}

TEST(Life, FredkinCell_changeState5) {
    FredkinCell cell = FredkinCell(false);
    vector<int> nbors = {1, 0, 1, 0, 0, 1, 1, 1};
    cell.decideState(nbors);
    ASSERT_EQ(cell._isAliveNext, true);
    cell.changeState();
    nbors = {0, 0, 0, 0, 0, 0, 0, 1};
    cell.decideState(nbors);
    ASSERT_EQ(cell._isAliveNext, false);
    cell.changeState();
    nbors = {0, 0, 1, 0, 0, 0, 0, 0};
    cell.decideState(nbors);
    ASSERT_EQ(cell._isAliveNext, false);
    cell.changeState();
}

TEST(Life, FredkinCell_changeState6) {
    FredkinCell cell = FredkinCell(true, 6);
    vector<int> nbors = {1, 0, 1, 0, 0, 1, 1, 1};
    cell.decideState(nbors);
    ASSERT_EQ(cell._isAliveNext, true);
    cell.changeState();
    ASSERT_EQ(cell._age, 7);
    nbors = {0, 0, 0, 0, 0, 0, 0, 1};
    cell.decideState(nbors);
    ASSERT_EQ(cell._isAliveNext, false);
    cell.changeState();
    ASSERT_EQ(cell._age, 7);
    nbors = {0, 0, 1, 0, 0, 1, 0, 1};
    cell.decideState(nbors);
    ASSERT_EQ(cell._isAliveNext, false);
    cell.changeState();
    ASSERT_EQ(cell._age, 7);
}

// -----
// print
// -----

TEST(Life, FredkinCell_print_defaultdead) {
    FredkinCell cell = FredkinCell();
    char ret = cell.print();
    ASSERT_EQ(ret, '-');
}

TEST(Life, FredkinCell_print_alive) {
    FredkinCell cell = FredkinCell(true);
    char ret = cell.print();
    ASSERT_EQ(ret, '0');
}

TEST(Life, FredkinCell_print_dead) {
    FredkinCell cell = FredkinCell(false);
    char ret = cell.print();
    ASSERT_EQ(ret, '-');
}

TEST(Life, FredkinCell_print_alive_age) {
    FredkinCell cell = FredkinCell(true, 3);
    char ret = cell.print();
    ASSERT_EQ(ret, '3');
}

TEST(Life, FredkinCell_print_alive_age2) {
    FredkinCell cell = FredkinCell(true, 11);
    char ret = cell.print();
    ASSERT_EQ(ret, '+');
}

// ---------------
// decideInitState
// ---------------

TEST(Life, FredkinCell_decideInitState_alive1) {
    FredkinCell cell = FredkinCell();
    cell.decideInitState('0');
    ASSERT_EQ(cell._isAlive, true);
    ASSERT_EQ(cell._age, 0);
}

TEST(Life, FredkinCell_decideInitState_dead1) {
    FredkinCell cell = FredkinCell();
    cell.decideInitState('-');
    ASSERT_EQ(cell._isAlive, false);
    ASSERT_EQ(cell._age, 0);
}

TEST(Life, FredkinCell_decideInitState_alive2) {
    FredkinCell cell = FredkinCell(true);
    cell.decideInitState('0');
    ASSERT_EQ(cell._isAlive, true);
    ASSERT_EQ(cell._age, 0);
}

TEST(Life, FredkinCell_decideInitState_dead2) {
    FredkinCell cell = FredkinCell(true);
    cell.decideInitState('-');
    ASSERT_EQ(cell._isAlive, false);
    ASSERT_EQ(cell._age, 0);
}

TEST(Life, FredkinCell_decideInitState_alive3) {
    FredkinCell cell = FredkinCell(false);
    cell.decideInitState('0');
    ASSERT_EQ(cell._isAlive, true);
    ASSERT_EQ(cell._age, 0);
}

TEST(Life, FredkinCell_decideInitState_dead3) {
    FredkinCell cell = FredkinCell(false);
    cell.decideInitState('-');
    ASSERT_EQ(cell._isAlive, false);
    ASSERT_EQ(cell._age, 0);
}

/// ----
/// Cell
/// ----

// ------------
// constructors
// ------------

//FREDKIN
TEST(Life, Cell_constr_Fredkin_default) {
    Cell cell(new FredkinCell());
    ASSERT_EQ(((FredkinCell*)(cell.get()))->_isAlive, false);
}

TEST(Life, Cell_constr_Fredkin_bool1) {
    Cell cell(new FredkinCell(true));
    ASSERT_EQ(((FredkinCell*)(cell.get()))->_isAlive, true);
    ASSERT_EQ(((FredkinCell*)(cell.get()))->_age, 0);
}

TEST(Life, Cell_constr_Fredkin_bool2) {
    Cell cell(new FredkinCell(false));
    ASSERT_EQ(((FredkinCell*)(cell.get()))->_isAlive, false);
    ASSERT_EQ(((FredkinCell*)(cell.get()))->_age, 0);
}

TEST(Life, Cell_constr_Fredkin_age1) {
    Cell cell(new FredkinCell(true, 3));
    ASSERT_EQ(((FredkinCell*)(cell.get()))->_isAlive, true);
    ASSERT_EQ(((FredkinCell*)(cell.get()))->_age, 3);
}

TEST(Life, Cell_constr_Fredkin_age2) {
    Cell cell(new FredkinCell(true, 11));
    ASSERT_EQ(((FredkinCell*)(cell.get()))->_isAlive, true);
    ASSERT_EQ(((FredkinCell*)(cell.get()))->_age, 11);
}

//CONWAY
TEST(Life, Cell_constr_Conway_default) {
    Cell cell(new ConwayCell());
    ASSERT_EQ(((FredkinCell*)(cell.get()))->_isAlive, false);
}

TEST(Life, Cell_constr_Conway_bool1) {
    Cell cell(new ConwayCell(true));
    ASSERT_EQ(((FredkinCell*)(cell.get()))->_isAlive, true);
}

TEST(Life, Cell_constr_Conway_bool2) {
    Cell cell(new ConwayCell(false));
    ASSERT_EQ(((FredkinCell*)(cell.get()))->_isAlive, false);
}


// -----
// print
// -----

//FREDKIN
TEST(Life, Cell_print_Fredkin_defaultdead) {
    Cell cell (new FredkinCell());
    char ret = cell.print();
    ASSERT_EQ(ret, '-');
}

TEST(Life, Cell_print_Fredkin_alive) {
    Cell cell(new FredkinCell(true));
    char ret = cell.print();
    ASSERT_EQ(ret, '0');
}

TEST(Life, Cell_print_Fredkin_dead) {
    Cell cell(new FredkinCell(false));
    char ret = cell.print();
    ASSERT_EQ(ret, '-');
}

TEST(Life, Cell_print_Fredkin_alive_age) {
    Cell cell(new FredkinCell(true, 3));
    char ret = cell.print();
    ASSERT_EQ(ret, '3');
}

//CONWAY
TEST(Life, Cell_print_Conway_defaultdead) {
    Cell cell(new ConwayCell());
    char ret = cell.print();
    ASSERT_EQ(ret, '.');
}

TEST(Life, Cell_print_Conway_alive) {
    Cell cell(new ConwayCell(true));
    char ret = cell.print();
    ASSERT_EQ(ret, '*');
}

TEST(Life, Cell_print_Conway_dead) {
    Cell cell(new ConwayCell(false));
    char ret = cell.print();
    ASSERT_EQ(ret, '.');
}

// ---------------
// decideInitState
// ---------------

//FREDKIN
TEST(Life, Cell_decideInitState_Fredkin_alive1) {
    Cell cell(new FredkinCell());
    cell.decideInitState('0');
    ASSERT_EQ(cell._p->_isAlive, true);
}

TEST(Life, Cell_decideInitState_Fredkin_dead1) {
    Cell cell(new FredkinCell());
    cell.decideInitState('-');
    ASSERT_EQ(cell._p->_isAlive, false);
}

TEST(Life, Cell_decideInitState_Fredkin_alive2) {
    Cell cell(new FredkinCell(true));
    cell.decideInitState('0');
    ASSERT_EQ(cell._p->_isAlive, true);
}

TEST(Life, Cell_decideInitState_Fredkin_dead2) {
    Cell cell(new FredkinCell(true));
    cell.decideInitState('-');
    ASSERT_EQ(cell._p->_isAlive, false);
}

TEST(Life, Cell_decideInitState_Fredkin_alive3) {
    Cell cell(new FredkinCell(false));
    cell.decideInitState('0');
    ASSERT_EQ(cell._p->_isAlive, true);
}

TEST(Life, Cell_decideInitState_Fredkin_dead3) {
    Cell cell(new FredkinCell(false));
    cell.decideInitState('-');
    ASSERT_EQ(cell._p->_isAlive, false);
}

//CONWAY
TEST(Life, Cell_decideInitState_Conway_alive1) {
    Cell cell(new ConwayCell());
    cell.decideInitState('*');
    ASSERT_EQ(cell._p->_isAlive, true);
}

TEST(Life, Cell_decideInitState_Conway_dead1) {
    Cell cell(new ConwayCell());
    cell.decideInitState('.');
    ASSERT_EQ(cell._p->_isAlive, false);
}

TEST(Life, Cell_decideInitState_Conway_alive2) {
    Cell cell(new ConwayCell(false));
    cell.decideInitState('*');
    ASSERT_EQ(cell._p->_isAlive, true);
}

TEST(Life, Cell_decideInitState_Conway_dead2) {
    Cell cell(new ConwayCell(true));
    cell.decideInitState('.');
    ASSERT_EQ(cell._p->_isAlive, false);
}

TEST(Life, Cell_decideInitState_Conway_alive3) {
    Cell cell(new ConwayCell(false));
    cell.decideInitState('*');
    ASSERT_EQ(cell._p->_isAlive, true);
}

TEST(Life, Cell_decideInitState_Conway_dead3) {
    Cell cell(new ConwayCell(false));
    cell.decideInitState('.');
    ASSERT_EQ(cell._p->_isAlive, false);
}

// -------
// isAlive
// -------

TEST(Life, Cell_isAlive_Fredkin_default) {
	Cell cell(new FredkinCell());
	bool ret = cell.isAlive();
	ASSERT_EQ(ret, false);
}

TEST(Life, Cell_isAlive_Fredkin_alive) {
	Cell cell(new FredkinCell(true));
	bool ret = cell.isAlive();
	ASSERT_EQ(ret, true);
}

TEST(Life, Cell_isAlive_Fredkin_dead) {
	Cell cell(new FredkinCell(false));
	bool ret = cell.isAlive();
	ASSERT_EQ(ret, false);
}

TEST(Life, Cell_isAlive_Fredkin_age) {
	Cell cell(new FredkinCell(true, 3));
	bool ret = cell.isAlive();
	ASSERT_EQ(ret, true);
}

TEST(Life, Cell_isAlive_Conway_default) {
	Cell cell(new ConwayCell());
	bool ret = cell.isAlive();
	ASSERT_EQ(ret, false);
}

TEST(Life, Cell_isAlive_Conway_alive) {
	Cell cell(new ConwayCell(true));
	bool ret = cell.isAlive();
	ASSERT_EQ(ret, true);
}

TEST(Life, Cell_isAlive_Conway_dead) {
	Cell cell(new ConwayCell(false));
	bool ret = cell.isAlive();
	ASSERT_EQ(ret, false);
}