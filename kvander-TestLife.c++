// ------------
// TestLife.c++
// ------------

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream> // istringtstream, ostringstream
#include <string> // ==

#include "gtest/gtest.h"

#define private public
#define protected public

#include "Life.h"
#include "Cell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"

using namespace std;

// --------
// TestLife
// --------

// -----
// alive
// -----

TEST(Life, alive1) {
    ConwayCell cct(true);
    ConwayCell ccf(false);
    ASSERT_TRUE(cct.alive());
    ASSERT_TRUE(!ccf.alive());
}

TEST(Life, alive2) {
    FredkinCell fct(true);
    FredkinCell fcf(false);
    ASSERT_TRUE(fct.alive());
    ASSERT_TRUE(!fcf.alive());
}

TEST(Life, alive3) {
    Cell ct(new FredkinCell(true));
    Cell cf(new ConwayCell(false));
    ASSERT_TRUE(ct.alive());
    ASSERT_TRUE(!cf.alive());
}

// -----
// clone
// -----

TEST(Life, clone1) {
    Cell c1(new FredkinCell(true));
    Cell c2;
    c1 = c2;
    ASSERT_TRUE(c1._p != c2._p);
    ASSERT_TRUE(c1._p->_alive == c2._p->_alive);
}

TEST(Life, clone2) {
    Cell c1;
    Cell c2;
    c1 = c2;
    ASSERT_TRUE(c1._p != c2._p);
    ASSERT_TRUE(c1._p->_alive == c2._p->_alive);
}

TEST(Life, clone3) {
    Cell c1(new FredkinCell(true));
    Cell c2(new ConwayCell(false));
    c1 = c2;
    ASSERT_TRUE(c1._p != c2._p);
    ASSERT_TRUE(c1._p->_alive == c2._p->_alive);
}

// ----
// read
// ----

// ---- ConwayCell ---- //

TEST(Life, cRead1) {
	ConwayCell cc;
	istringstream i(".");
	cc.read(i);
	ASSERT_TRUE(!cc.alive());
}

TEST(Life, cRead2) {
	ConwayCell cc;
	istringstream i("*");
	cc.read(i);
	ASSERT_TRUE(cc.alive());
}

TEST(Life, cRead3) {
	ConwayCell cc;
	istringstream i("-");
	cc.read(i);
	ASSERT_TRUE(!cc.alive());
}

// ---- FredkinCell ---- //

TEST(Life, fRead1) {
	FredkinCell fc;
	istringstream i("4");
	fc.read(i);
	ASSERT_TRUE(fc.alive());
	ASSERT_TRUE(fc._age == 4);
}

TEST(Life, fRead2) {
	FredkinCell fc;
	istringstream i("+");
	fc.read(i);
	ASSERT_TRUE(fc.alive());
	ASSERT_TRUE(fc._age == 10);
}

TEST(Life, fRead3) {
	FredkinCell fc;
	istringstream i("-");
	fc.read(i);
	ASSERT_TRUE(!fc.alive());
	ASSERT_TRUE(fc._age == 0);
}

// ---- Cell ---- //

TEST(Life, cellRead1) {
	Cell c;
	istringstream i("4");
	c.read(i);
	ASSERT_TRUE(c.alive());
}

TEST(Life, cellRead2) {
	Cell c;
	istringstream i("-");
	c.read(i);
	ASSERT_TRUE(!c.alive());
}

TEST(Life, cellRead3) {
	Cell c;
	istringstream i(".");
	c.read(i);
	ASSERT_TRUE(!c.alive());
}

// -----
// write
// -----

// ---- ConwayCell ---- //

TEST(Life, cWrite1) {
	ConwayCell cc(false);
	ostringstream o;
	o << cc;
	ASSERT_TRUE(o.str() == ".");
}

TEST(Life, cWrite2) {
	ConwayCell cc(true);
	ostringstream o;
	cc.write(o);
	ASSERT_TRUE(o.str() == "*");
}

// ---- FredkinCell ---- //

TEST(Life, fWrite1) {
	FredkinCell fc(false);
	ostringstream o;
	fc.write(o);
	ASSERT_TRUE(o.str() == "-");
}

TEST(Life, fWrite2) {
	FredkinCell fc(true);
	ostringstream o;
	fc.write(o);
	ASSERT_TRUE(o.str() == "0");
}

TEST(Life, fWrite3) {
	FredkinCell fc(true);
	fc._age = 10;
	ostringstream o;
	fc.write(o);
	ASSERT_TRUE(o.str() == "+");
}

// ---- Cell ---- //

TEST(Life, cellWrite1) {
	Cell c(new ConwayCell(true));
	ostringstream o;
	c.write(o);
	ASSERT_TRUE(o.str() == "*");
}

TEST(Life, cellWrite2) {
	Cell c(new FredkinCell(true));
	ostringstream o;
	c.write(o);
	ASSERT_TRUE(o.str() == "0");
}

TEST(Life, cellWrite3) {
	Cell c;
	ostringstream o;
	c.write(o);
	ASSERT_TRUE(o.str() == "-");
}

// ------------------
// initiate_evolution
// ------------------

// ---- ConwayCell ----//

TEST(Life, cEvolve1) {
	ConwayCell cc;
	bool border[] = {0, 0, 0, 0, 0, 0, 0, 0};
	cc.initiate_evolution(border);
	ASSERT_TRUE(!cc.alive());
}

TEST(Life, cEvolve2) {
	ConwayCell cc;
	bool border[] = {1, 1, 0, 1, 0, 0, 0, 0};
	cc.initiate_evolution(border);
	ASSERT_TRUE(cc.alive());
}

TEST(Life, cEvolve3) {
	ConwayCell cc;
	bool border[] = {1, 1, 1, 1, 1, 1, 1, 1};
	cc.initiate_evolution(border);
	ASSERT_TRUE(!cc.alive());
}

// ---- FredkinCell ---- //

TEST(Life, fEvolve1) {
	FredkinCell fc;
	bool border[] = {0, 0, 0, 0, 0, 0, 0, 0};
	fc.initiate_evolution(border);
	ASSERT_TRUE(!fc.alive());
}

TEST(Life, fEvolve2) {
	FredkinCell fc(true);
	bool border[] = {0, 1, 0, 1, 0, 0, 1, 0};
	fc.initiate_evolution(border);
	fc.initiate_evolution(border);
	ASSERT_TRUE(fc.alive());
	ASSERT_TRUE(fc._age == 2);
}

TEST(Life, fEvolve3) {
	FredkinCell fc(true);
	bool border[] = {1, 1, 1, 1, 1, 1, 1, 1};
	fc.initiate_evolution(border);
	ASSERT_TRUE(!fc.alive());
}

// ---- Cell ---- //

TEST(Life, cellEvolve1) {
	Cell c;
	bool border[] = {0, 0, 0, 1, 0, 0, 0, 0};
	c.initiate_evolution(border);
	ASSERT_TRUE(c.alive());
}

TEST(Life, cellEvolve2) {
	Cell c(new FredkinCell(true));
	bool border[] = {0, 1, 0, 1, 0, 0, 1, 0};
	c.initiate_evolution(border);
	c.initiate_evolution(border);
	ASSERT_TRUE(c.alive());
}

TEST(Life, cellEvolve3) {
	Cell c(new ConwayCell(true));
	bool border[] = {1, 1, 1, 1, 1, 1, 1, 1};
	c.initiate_evolution(border);
	ASSERT_TRUE(!c.alive());
}

// ------
// evolve
// ------

TEST(Life, evolve) {
	Cell c(new FredkinCell(true));
	ostringstream o;
	c.evolve();
	c.write(o);
	ASSERT_TRUE(o.str() == "*");
	ASSERT_TRUE(c._p->_alive);
}

// -----
// print
// -----

TEST(Life, print1) {
	istringstream i("3\n3\n...\n.*.\n.*.");
	ostringstream o;
	Life<ConwayCell> lc(i);
	lc.print(o);
	ASSERT_TRUE(o.str() == "\nGeneration = 0, Population = 2.\n...\n.*.\n.*.\n");
}

TEST(Life, print2) {
	istringstream i("3\n3\n---\n-5-\n-+-");
	ostringstream o;
	Life<FredkinCell> lf(i);
	lf.print(o);
	ASSERT_TRUE(o.str() == "\nGeneration = 0, Population = 2.\n---\n-5-\n-+-\n");
}

TEST(Life, print3) {
	istringstream i("3\n3\n---\n---\n-5-");
	ostringstream o;
	Life<Cell> lc(i);
	lc.print(o);
	ASSERT_TRUE(o.str() == "\nGeneration = 0, Population = 1.\n---\n---\n-5-\n");
}

// ----
// turn
// ----

TEST(Life, turn1) {
	istringstream i("3\n3\n***\n...\n...");
	Life<ConwayCell> lc(i);
	lc.turn();
	ASSERT_TRUE(lc._board[1][1].alive());
	ASSERT_TRUE(lc._board[0][1].alive());
	ASSERT_TRUE(!lc._board[0][0].alive());
	ASSERT_TRUE(!lc._board[0][2].alive());
}

TEST(Life, turn2) {
	istringstream i("3\n3\n-0-\n---\n---");
	Life<FredkinCell> lf(i);
	lf.turn();
	ASSERT_TRUE(lf._board[0][0].alive());
    ASSERT_TRUE(lf._board[0][2].alive());
    ASSERT_TRUE(lf._board[1][1].alive());
    ASSERT_TRUE(!lf._board[0][1].alive());
    ASSERT_TRUE(lf._board[0][0]._age == 0);
}

TEST(Life, turn3) {
	istringstream i("3\n3\n000\n-0-\n---");
	Life<Cell> lcell(i);
	lcell.turn();
	lcell.turn();
	ASSERT_TRUE(lcell._board[0][0].alive());
    ASSERT_TRUE(lcell._board[0][1].alive());
    ASSERT_TRUE(lcell._board[0][2].alive());
    ASSERT_TRUE(lcell._board[2][0].alive());
    ASSERT_TRUE(lcell._board[2][1].alive());
    ASSERT_TRUE(lcell._board[2][2].alive());
    ASSERT_TRUE(!lcell._board[1][0].alive());
    ASSERT_TRUE(!lcell._board[1][1].alive());
    ASSERT_TRUE(!lcell._board[1][2].alive());
}

// --------
// simulate
// --------
TEST(Life, simulate) {
	istringstream i("3\n3\n...\n***\n...");
	Life<ConwayCell> lc(i);
	lc.simulate(5);
	ASSERT_TRUE(lc._board[0][1].alive());
    ASSERT_TRUE(lc._board[1][1].alive());
    ASSERT_TRUE(lc._board[2][1].alive());
    ASSERT_TRUE(!lc._board[0][0].alive());
    ASSERT_TRUE(!lc._board[0][2].alive());
    ASSERT_TRUE(!lc._board[1][0].alive());
    ASSERT_TRUE(!lc._board[1][2].alive());
    ASSERT_TRUE(!lc._board[2][0].alive());
    ASSERT_TRUE(!lc._board[2][2].alive());
}