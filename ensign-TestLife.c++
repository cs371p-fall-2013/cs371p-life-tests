 //---------------------------------------
// Katherine Ensign
// eid: krh524
// csid: ensign
// CS371P Project 5: Life
// 21 November 2013
//---------------------------------------
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

    % g++ -pedantic -std=c++0x -Wall Darwin.c++ TestDarwin.c++ -o TestDarwin -lgtest -lpthread -lgtest_main

    % valgrind TestDarwin > TestDarwin.out
*/

// --------
// includes
// --------

#include <string>
#include <cstdlib>
#include <stdexcept>
#include "gtest/gtest.h"

#define private public

#include "Life.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"
using namespace std; 

// ----------------
// Abstract Cell Tests
// ----------------

TEST(AbstractCell, isAlive_conway_true){
	ConwayCell cc('*');
	ASSERT_TRUE(cc.isAlive());
}

TEST(AbstractCell, isAlive_conway_false){
	ConwayCell cc;
	ASSERT_FALSE(cc.isAlive());
}

TEST(AbstractCell, isAlive_fredkin_true){
	FredkinCell fc('0');
	ASSERT_TRUE(fc.isAlive());
}

TEST(AbstractCell, isAlive_fredkin_false){
	FredkinCell fc;
	ASSERT_FALSE(fc.isAlive());
}

TEST(AbstractCell, isAlive_cell_true){
	AbstractCell* acp = new ConwayCell('*');
	Cell c(acp);
	ASSERT_TRUE(c.isAlive());
}

TEST(AbstractCell, isAlive_cell_false){
	AbstractCell* acp = new ConwayCell();
	Cell c(acp);
	ASSERT_FALSE(c.isAlive());
}

TEST(AbstractCell, makeAlive_conway){
	ConwayCell cc;
	cc.makeAlive();
	ASSERT_TRUE(cc.isAlive());
}

TEST(AbstractCell, makeDead_conway){
	ConwayCell cc('*');
	cc.makeDead();
	ASSERT_FALSE(cc.isAlive());
}

TEST(AbstractCell, makeAlive_fredkin){
	FredkinCell fc;
	fc.makeAlive();
	ASSERT_TRUE(fc.isAlive());
}

TEST(AbstractCell, makeDead_fredkin){
	FredkinCell fc('0');
	fc.makeDead();
	ASSERT_FALSE(fc.isAlive());
}

TEST(AbstractCell, makeAlive_cell){
	AbstractCell* acp = new ConwayCell();
	Cell c(acp);
	c.makeAlive();
	ASSERT_TRUE(c.isAlive());	
}

TEST(AbstractCell, makeDead_cell){
	AbstractCell* acp = new ConwayCell('*');
	Cell c(acp);
	c.makeDead();
	ASSERT_FALSE(c.isAlive());	
}

// ----------------
// ConwayCell Tests
// ----------------

TEST(ConwayCell, constructor_default){
	ConwayCell cc;
	ASSERT_FALSE(cc.isAlive());
	ASSERT_TRUE(cc.print() == '.');
}

TEST(ConwayCell, constructor_char_alive){
	ConwayCell cc('*');
	ASSERT_TRUE(cc.isAlive());
	ASSERT_TRUE(cc.print() == '*');
}

TEST(ConwayCell, constructor_char_dead){
	ConwayCell cc('.');
	ASSERT_FALSE(cc.isAlive());
	ASSERT_TRUE(cc.print() == '.');
}

TEST(ConwayCell, constructor_char_invalid){
	ConwayCell cc('h');
	ASSERT_FALSE(cc.isAlive());
	ASSERT_TRUE(cc.print() == '.');
}

TEST(ConwayCell, constructor_copy_dead){
	ConwayCell cc('.');
	ConwayCell cc2(cc);
	ASSERT_FALSE(cc2.isAlive());
	ASSERT_TRUE(cc2.print() == '.');
}

TEST(ConwayCell, constructor_copy_alive){
	ConwayCell cc('*');
	ConwayCell cc2(cc);
	ASSERT_TRUE(cc2.isAlive());
	ASSERT_TRUE(cc2.print() == '*');
}

TEST(ConwayCell, clone_alive){
	ConwayCell cc('*');
	AbstractCell* acp = cc.clone();
	ASSERT_TRUE(cc.print() == acp->print());
	delete acp;
}

TEST(ConwayCell, clone_dead){
	ConwayCell cc;
	AbstractCell* acp = cc.clone();
	ASSERT_TRUE(cc.print() == acp->print());
	delete acp;
}

TEST(ConwayCell, evolve_dead2dead1){
	ConwayCell cc('.');
	cc.evolve(2, 0);
	ASSERT_FALSE(cc.isAlive());
	ASSERT_TRUE(cc.print() == '.');
}

TEST(ConwayCell, evolve_dead2dead2){
	ConwayCell cc('.');
	cc.evolve(2, 2);
	ASSERT_FALSE(cc.isAlive());
	ASSERT_TRUE(cc.print() == '.');
}

TEST(ConwayCell, evolve_dead2alive1){
	ConwayCell cc('.');
	cc.evolve(2, 1);
	ASSERT_TRUE(cc.isAlive());
	ASSERT_TRUE(cc.print() == '*');
}

TEST(ConwayCell, evolve_dead2alive2){
	ConwayCell cc('.');
	cc.evolve(0, 3);
	ASSERT_TRUE(cc.isAlive());
	ASSERT_TRUE(cc.print() == '*');
}

TEST(ConwayCell, evolve_alive2alive_2neighb){
	ConwayCell cc('*');
	cc.evolve(2, 0);
	ASSERT_TRUE(cc.isAlive());
	ASSERT_TRUE(cc.print() == '*');
}

TEST(ConwayCell, evolve_alive2alive_3neighb){
	ConwayCell cc('*');
	cc.evolve(2, 1);
	ASSERT_TRUE(cc.isAlive());
	ASSERT_TRUE(cc.print() == '*');
}

TEST(ConwayCell, evolve_alive2dead1){
	ConwayCell cc('*');
	cc.evolve(0, 1);
	ASSERT_FALSE(cc.isAlive());
	ASSERT_TRUE(cc.print() == '.');
}

TEST(ConwayCell, evolve_alive2dead2){
	ConwayCell cc('*');
	cc.evolve(3, 1);
	ASSERT_FALSE(cc.isAlive());
	ASSERT_TRUE(cc.print() == '.');
}

TEST(ConwayCell, evolve_alive2dead3){
	ConwayCell cc('*');
	cc.evolve(3, 2);
	ASSERT_FALSE(cc.isAlive());
	ASSERT_TRUE(cc.print() == '.');
}

TEST(ConwayCell, print_alive){
	ConwayCell cc('*');
	ASSERT_TRUE(cc.print() == '*');
}

TEST(ConwayCell, print_dead){
	ConwayCell cc;
	ASSERT_TRUE(cc.print() == '.');
}

TEST(ConwayCell, str){
	ASSERT_TRUE(ConwayCell::str() == "ConwayCell");
}

// ----------------
// FredkinCell Tests
// ----------------

TEST(FredkinCell, constructor_default){
	FredkinCell fc;
	ASSERT_FALSE(fc.isAlive());
	ASSERT_TRUE(fc.print() == '-');
}

TEST(FredkinCell, constructor_char_alive1){
	FredkinCell fc('0');
	ASSERT_TRUE(fc.isAlive());
	ASSERT_TRUE(fc._age == 0);
	ASSERT_TRUE(fc.print() == '0');
}

TEST(FredkinCell, constructor_char_alive2){
	FredkinCell fc('9');
	ASSERT_TRUE(fc.isAlive());
	ASSERT_TRUE(fc._age == 9);
	ASSERT_TRUE(fc.print() == '9');
}

TEST(FredkinCell, constructor_char_dead){
	FredkinCell fc('-');
	ASSERT_FALSE(fc.isAlive());
	ASSERT_TRUE(fc.print() == '-');
}

TEST(FredkinCell, constructor_char_invalid){
	FredkinCell fc('h');
	ASSERT_FALSE(fc.isAlive());
	ASSERT_TRUE(fc.print() == '-');
}

TEST(FredkinCell, constructor_copy_dead){
	FredkinCell fc('-');
	FredkinCell fc2(fc);
	ASSERT_FALSE(fc2.isAlive());
	ASSERT_TRUE(fc2.print() == '-');
}

TEST(FredkinCell, constructor_copy_alive){
	FredkinCell fc('1');
	FredkinCell fc2(fc);
	ASSERT_TRUE(fc2.isAlive());
	ASSERT_TRUE(fc2.print() == '1');
}

TEST(FredkinCell, clone_alive){
	FredkinCell fc('1');
	AbstractCell* acp = fc.clone();
	ASSERT_TRUE(fc.print() == acp->print());
	delete acp;
}

TEST(FredkinCell, clone_dead){
	FredkinCell fc;
	AbstractCell* acp = fc.clone();
	ASSERT_TRUE(fc.print() == acp->print());
	delete acp;
}

TEST(FredkinCell, evolve_dead2dead1){
	FredkinCell fc('-');
	fc.evolve(2, 1);
	ASSERT_FALSE(fc.isAlive());
	ASSERT_TRUE(fc.print() == '-');
}

TEST(FredkinCell, evolve_dead2dead2){
	FredkinCell fc('-');
	fc.evolve(0, 1);
	ASSERT_FALSE(fc.isAlive());
	ASSERT_TRUE(fc.print() == '-');
}

TEST(FredkinCell, evolve_dead2alive1){
	FredkinCell fc('-');
	fc.evolve(1, 1);
	ASSERT_TRUE(fc.isAlive());
	ASSERT_TRUE(fc.print() == '0');
}

TEST(FredkinCell, evolve_dead2alive2){
	FredkinCell fc('-');
	fc.evolve(3, 2);
	ASSERT_TRUE(fc.isAlive());
	ASSERT_TRUE(fc.print() == '0');
}

TEST(FredkinCell, evolve_alive2alive_1neighb){
	FredkinCell fc('9');
	fc.evolve(1, 1);
	ASSERT_TRUE(fc.isAlive());
	ASSERT_TRUE(fc.print() == '+');
}

TEST(FredkinCell, evolve_alive2alive_3neighb){
	FredkinCell fc('3');
	fc.evolve(3, 1);
	ASSERT_TRUE(fc.isAlive());
	ASSERT_TRUE(fc.print() == '4');
}

TEST(FredkinCell, evolve_alive2dead1){
	FredkinCell fc('1');
	fc.evolve(0, 1);
	ASSERT_FALSE(fc.isAlive());
	ASSERT_TRUE(fc.print() == '-');
	ASSERT_TRUE(fc._age == 1);
}

TEST(FredkinCell, evolve_alive2dead2){
	FredkinCell fc('3');
	fc.evolve(2, 1);
	ASSERT_FALSE(fc.isAlive());
	ASSERT_TRUE(fc.print() == '-');
	ASSERT_TRUE(fc._age == 3);
}

TEST(FredkinCell, evolve_alive2dead3){
	FredkinCell fc('+');
	fc.evolve(4, 2);
	ASSERT_FALSE(fc.isAlive());
	ASSERT_TRUE(fc.print() == '-');
}

TEST(FredkinCell, evolve_alive_dead_alive){
	FredkinCell fc('3');
	fc.evolve(2, 0);
	fc.evolve(1, 1);
	ASSERT_TRUE(fc.isAlive());
	ASSERT_TRUE(fc.print() == '3');
}

TEST(FredkinCell, print_alive_normal){
	FredkinCell fc('5');
	ASSERT_TRUE(fc.print() == '5');
}

TEST(FredkinCell, print_alive_old){
	FredkinCell fc('9');
	fc.evolve(1, 0);
	ASSERT_TRUE(fc.print() == '+');
}

TEST(FredkinCell, print_dead){
	FredkinCell fc;
	ASSERT_TRUE(fc.print() == '-');
}

TEST(FredkinCell, str){
	ASSERT_TRUE(FredkinCell::str() == "FredkinCell");
}

// -----------------
//    Cell Tests
// -----------------

TEST(Cell, constructor_default){
	Cell c;
	ASSERT_FALSE(c.isAlive());
}

TEST(Cell, constructor_copy_Conway_dead){
	ConwayCell* cc = new ConwayCell();
	Cell c(cc);
	ASSERT_FALSE(c.isAlive());
}

TEST(Cell, constructor_copy_Conway_alive){
	ConwayCell* cc = new ConwayCell('*');
	Cell c(cc);
	ASSERT_TRUE(c.isAlive());
}

TEST(Cell, constructor_copy_Fredkin_dead){
	FredkinCell* fc = new FredkinCell();
	Cell c(fc);
	ASSERT_FALSE(c.isAlive());
}

TEST(Cell, constructor_copy_Fredkin_alive1){
	FredkinCell* fc = new FredkinCell('0');
	Cell c(fc);
	ASSERT_TRUE(c.isAlive());
	ASSERT_TRUE(c.print() == '0');
}

TEST(Cell, constructor_copy_Fredkin_alive2){
	FredkinCell* fc = new FredkinCell('5');
	Cell c(fc);
	ASSERT_TRUE(c.isAlive());
	ASSERT_TRUE(c.print() == '5');
}

TEST(Cell, clone_alive_conway){
	Cell cc = new ConwayCell('*');
	AbstractCell* acp = cc.clone();
	ASSERT_TRUE(cc.print() == acp->print());
	delete acp;
}

TEST(Cell, clone_dead_conway){
	Cell cc = new ConwayCell();
	AbstractCell* acp = cc.clone();
	ASSERT_TRUE(cc.print() == acp->print());
	delete acp;
}

TEST(Cell, clone_alive_fredkin){
	Cell fc = new FredkinCell('1');
	AbstractCell* acp = fc.clone();
	ASSERT_TRUE(fc.print() == acp->print());
	delete acp;
}

TEST(Cell, clone_dead_fredkin){
	Cell fc = new FredkinCell();
	AbstractCell* acp = fc.clone();
	ASSERT_TRUE(fc.print() == acp->print());
	delete acp;
}

TEST(Cell, evolve_dead2dead1C){
	Cell cc = new ConwayCell('.');
	cc.evolve(2, 0);
	ASSERT_FALSE(cc.isAlive());
	ASSERT_TRUE(cc.print() == '.');
}

TEST(Cell, evolve_dead2dead2C){
	Cell cc = new ConwayCell('.');
	cc.evolve(2, 2);
	ASSERT_FALSE(cc.isAlive());
	ASSERT_TRUE(cc.print() == '.');
}

TEST(Cell, evolve_dead2alive1C){
	Cell cc = new ConwayCell('.');
	cc.evolve(2, 1);
	ASSERT_TRUE(cc.isAlive());
	ASSERT_TRUE(cc.print() == '*');
}

TEST(Cell, evolve_dead2alive2C){
	Cell cc = new ConwayCell('.');
	cc.evolve(0, 3);
	ASSERT_TRUE(cc.isAlive());
	ASSERT_TRUE(cc.print() == '*');
}

TEST(Cell, evolve_alive2alive_2neighbC){
	Cell cc = new ConwayCell('*');
	cc.evolve(2, 0);
	ASSERT_TRUE(cc.isAlive());
	ASSERT_TRUE(cc.print() == '*');
}

TEST(Cell, evolve_alive2alive_3neighbC){
	Cell cc = new ConwayCell('*');
	cc.evolve(2, 1);
	ASSERT_TRUE(cc.isAlive());
	ASSERT_TRUE(cc.print() == '*');
}

TEST(Cell, evolve_alive2dead1C){
	Cell cc = new ConwayCell('*');
	cc.evolve(0, 1);
	ASSERT_FALSE(cc.isAlive());
	ASSERT_TRUE(cc.print() == '.');
}

TEST(Cell, evolve_alive2dead2C){
	Cell cc = new ConwayCell('*');
	cc.evolve(3, 1);
	ASSERT_FALSE(cc.isAlive());
	ASSERT_TRUE(cc.print() == '.');
}

TEST(Cell, evolve_alive2dead3C){
	Cell cc = new ConwayCell('*');
	cc.evolve(3, 2);
	ASSERT_FALSE(cc.isAlive());
	ASSERT_TRUE(cc.print() == '.');
}

TEST(Cell, evolve_dead2dead1F){
	Cell fc = new FredkinCell('-');
	fc.evolve(2, 1);
	ASSERT_FALSE(fc.isAlive());
	ASSERT_TRUE(fc.print() == '-');
}

TEST(Cell, evolve_dead2dead2F){
	Cell fc = new FredkinCell('-');
	fc.evolve(0, 1);
	ASSERT_FALSE(fc.isAlive());
	ASSERT_TRUE(fc.print() == '-');
}

TEST(Cell, evolve_dead2alive1F){
	Cell fc = new FredkinCell('-');
	fc.evolve(1, 1);
	ASSERT_TRUE(fc.isAlive());
	ASSERT_TRUE(fc.print() == '0');
}

TEST(Cell, evolve_dead2alive2F){
	Cell fc = new FredkinCell('-');
	fc.evolve(3, 2);
	ASSERT_TRUE(fc.isAlive());
	ASSERT_TRUE(fc.print() == '0');
}

TEST(Cell, evolve_alive2alive_1neighbF){
	Cell fc = new FredkinCell('9');
	fc.evolve(1, 1);
	ASSERT_TRUE(fc.isAlive());
	ASSERT_TRUE(fc.print() == '*');
}

TEST(Cell, evolve_alive2alive_3neighbF){
	Cell fc = new FredkinCell('0');
	fc.evolve(3, 1);
	ASSERT_TRUE(fc.isAlive());
	ASSERT_TRUE(fc.print() == '1');
}

TEST(Cell, evolve_alive2dead1F){
	Cell fc = new FredkinCell('1');
	fc.evolve(0, 1);
	ASSERT_FALSE(fc.isAlive());
	ASSERT_TRUE(fc.print() == '-');
}

TEST(Cell, evolve_alive2dead2F){
	Cell fc = new FredkinCell('3');
	fc.evolve(2, 1);
	ASSERT_FALSE(fc.isAlive());
	ASSERT_TRUE(fc.print() == '-');
}

TEST(Cell, evolve_alive2dead3F){
	Cell fc = new FredkinCell('+');
	fc.evolve(4, 2);
	ASSERT_FALSE(fc.isAlive());
	ASSERT_TRUE(fc.print() == '-');
}

TEST(Cell, evolve_alive_dead_aliveF){
	Cell fc = new FredkinCell('3');
	fc.evolve(2, 0);
	fc.evolve(1, 1);
	ASSERT_TRUE(fc.isAlive());
	ASSERT_TRUE(fc.print() == '3');
}

TEST(Cell, evolve_fredkin_to_conwayF){
	Cell fc = new FredkinCell('1');
	fc.evolve(1, 0);
	ASSERT_TRUE(fc.print() == '*');
}

TEST(Cell, mutate1){
	Cell c = new FredkinCell('0');
	c.mutate();
	ASSERT_TRUE(c.print() == '*');
}

TEST(Cell, mutate2){
	Cell c = new FredkinCell();
	c.mutate();
	ASSERT_TRUE(c.print() == '*');
}

TEST(Cell, print_conway_alive){
	Cell c = new ConwayCell('*');
	ASSERT_TRUE(c.print() == '*');
}

TEST(Cell, print_conway_dead){
	Cell c = new ConwayCell();
	ASSERT_TRUE(c.print() == '.');
}

TEST(Cell, print_fredkin_alive){
	Cell c = new FredkinCell('4');
	ASSERT_TRUE(c.print() == '4');
}

TEST(Cell, print_fredkin_dead){
	Cell c = new FredkinCell();
	ASSERT_TRUE(c.print() == '-');
}

TEST(Cell, str){
	ASSERT_TRUE(Cell::str() == "Cell");
}

TEST(Cell, initCell_conway){
	Cell c1;
	AbstractCell* acp = c1.initCell('*');
	Cell c2(acp);
	ASSERT_TRUE(c2.isAlive());
	ASSERT_TRUE(c2.print() == '*');
}

TEST(Cell, initCell_fredkin1){
	Cell c1;
	AbstractCell* acp = c1.initCell('0');
	Cell c2(acp);
	ASSERT_TRUE(c2.isAlive());
	ASSERT_TRUE(c2.print() == '0');
}

TEST(Cell, initCell_fredkin2){
	Cell c1;
	AbstractCell* acp = c1.initCell('-');
	Cell c2(acp);
	ASSERT_FALSE(c2.isAlive());
	ASSERT_TRUE(c2.print() == '-');
}
// -----------------
//    Life Tests
// -----------------

TEST(Life, constructor_valid1){
	Life<ConwayCell> l(4, 5);
	l.addCell('*', 1, 2);
	ASSERT_TRUE(l._grid.size() == 4);
	ASSERT_TRUE(l._grid[0].size() == 5);
	ASSERT_TRUE(l._population == 1);
}

TEST(Life, constructor_valid2){
	Life<ConwayCell> l(3, 2);
	for (int r = 0; r < 3; r++){
		for (int c = 0; c < 2; c++){
			l.addCell('*', r, c);
		}
	}
	ASSERT_TRUE(l._grid.size() == 3);
	ASSERT_TRUE(l._grid[0].size() == 2);
	ASSERT_TRUE(l._population == 6);
}

TEST(Life, constructor_invalid){
	try{
		Life<ConwayCell> l(-1, 2);
		ASSERT_TRUE(false);
	} catch (invalid_argument&){
		ASSERT_TRUE(true);
	}
}

TEST(Life, addCell_conway){
	Life<ConwayCell> l(1, 1);
	l.addCell('.', 0, 0);
	ASSERT_TRUE(l._grid[0][0].print() == '.');
}

TEST(Life, addCell_fredkin){
	Life<FredkinCell> l(1, 1);
	l.addCell('0', 0, 0);
	ASSERT_TRUE(l._grid[0][0].print() == '0');
}

TEST(Life, addCell_cell_conway_dead){
	Life<Cell> l(1, 1);
	l.addCell('.', 0, 0);
	ASSERT_TRUE(l._grid[0][0].print() == '.');
}

TEST(Life, addCell_cell_conway_alive){
	Life<Cell> l(1, 1);
	l.addCell('*', 0, 0);
	ASSERT_TRUE(l._grid[0][0].print() == '*');
}

TEST(Life, addCell_cell_fredkin_dead){
	Life<Cell> l(1, 1);
	l.addCell('-', 0, 0);
	ASSERT_TRUE(l._grid[0][0].print() == '-');
}

TEST(Life, addCell_cell_fredkin_alive){
	Life<Cell> l(1, 1);
	l.addCell('0', 0, 0);
	ASSERT_TRUE(l._grid[0][0].print() == '0');
}

TEST(Life, nextGeneration_Conway1){
	Life<ConwayCell> l(4, 5);
	l.addCell('*', 1, 2);
	l.addCell('*', 2, 2);
	l.addCell('*', 3, 2);
	l.nextGeneration();
	ASSERT_TRUE(l._population == 3);
	ASSERT_FALSE(l._grid[1][2].isAlive());
	ASSERT_FALSE(l._grid[3][2].isAlive());
	ASSERT_TRUE(l._grid[2][1].isAlive());
	ASSERT_TRUE(l._grid[2][2].isAlive());
	ASSERT_TRUE(l._grid[2][3].isAlive());
}

TEST(Life, nextGeneration_Conway2){
	Life<ConwayCell> l(2, 2);
	l.addCell('*', 0, 0);
	l.addCell('*', 0, 1);
	l.addCell('*', 1, 0);
	l.nextGeneration();
	ASSERT_TRUE(l._population == 4);
	ASSERT_TRUE(l._grid[0][0].isAlive());
	ASSERT_TRUE(l._grid[0][1].isAlive());
	ASSERT_TRUE(l._grid[1][0].isAlive());
	ASSERT_TRUE(l._grid[1][1].isAlive());
}

TEST(Life, nextGeneration_Fredkin1){
	Life<FredkinCell> l(4, 5);
	l.addCell('0', 1, 2);
	l.addCell('0', 2, 2);
	l.addCell('0', 3, 2);
	l.nextGeneration();
	ASSERT_TRUE(l._population == 9);
	ASSERT_TRUE(l._grid[1][1].isAlive());
	ASSERT_TRUE(l._grid[2][1].isAlive());
	ASSERT_TRUE(l._grid[3][1].isAlive());
	ASSERT_TRUE(l._grid[0][2].isAlive());
	ASSERT_TRUE(l._grid[1][2].isAlive());
	ASSERT_FALSE(l._grid[2][2].isAlive());
	ASSERT_TRUE(l._grid[3][2].isAlive());
	ASSERT_TRUE(l._grid[1][3].isAlive());
	ASSERT_TRUE(l._grid[2][3].isAlive());
	ASSERT_TRUE(l._grid[3][3].isAlive());
	ASSERT_TRUE(l._grid[1][2]._age == 1);
	ASSERT_TRUE(l._grid[3][2]._age == 1);
}

TEST(Life, nextGeneration_Conway1_cell){
	Life<Cell> l(4, 5);
	l.addCell('*', 1, 2);
	l.addCell('*', 2, 2);
	l.addCell('*', 3, 2);
	l.nextGeneration();
	ASSERT_TRUE(l._population == 8);
	ASSERT_FALSE(l._grid[1][2].isAlive());
	ASSERT_FALSE(l._grid[3][2].isAlive());
	ASSERT_TRUE(l._grid[2][1].isAlive());
	ASSERT_TRUE(l._grid[2][2].isAlive());
	ASSERT_TRUE(l._grid[2][3].isAlive());
}

TEST(Life, nextGeneration_Conway2_cell){
	Life<Cell> l(2, 2);
	l.addCell('*', 0, 0);
	l.addCell('*', 0, 1);
	l.addCell('*', 1, 0);
	l.nextGeneration();
	ASSERT_TRUE(l._population == 3);
	ASSERT_TRUE(l._grid[0][0].isAlive());
	ASSERT_TRUE(l._grid[0][1].isAlive());
	ASSERT_TRUE(l._grid[1][0].isAlive());
	ASSERT_FALSE(l._grid[1][1].isAlive());
}

TEST(Life, nextGeneration_Fredkin1_cell){
	Life<Cell> l(4, 5);
	l.addCell('0', 1, 2);
	l.addCell('0', 2, 2);
	l.addCell('0', 3, 2);
	l.nextGeneration();
	ASSERT_TRUE(l._population == 9);
	ASSERT_TRUE(l._grid[1][1].isAlive());
	ASSERT_TRUE(l._grid[2][1].isAlive());
	ASSERT_TRUE(l._grid[3][1].isAlive());
	ASSERT_TRUE(l._grid[0][2].isAlive());
	ASSERT_TRUE(l._grid[1][2].isAlive());
	ASSERT_FALSE(l._grid[2][2].isAlive());
	ASSERT_TRUE(l._grid[3][2].isAlive());
	ASSERT_TRUE(l._grid[1][3].isAlive());
	ASSERT_TRUE(l._grid[2][3].isAlive());
	ASSERT_TRUE(l._grid[3][3].isAlive());
	ASSERT_TRUE(l._grid[1][2].print() == '1');
	ASSERT_TRUE(l._grid[3][2].print() == '1');
}

TEST(Life, nextGeneration_Fredkin2_cell){
	Life<Cell> l(2, 2);
	l.addCell('0', 0, 0);
	l.addCell('0', 0, 1);
	l.addCell('0', 1, 0);
	l.nextGeneration();
	ASSERT_TRUE(l._population == 2);
	ASSERT_FALSE(l._grid[0][0].isAlive());
	ASSERT_TRUE(l._grid[0][1].isAlive());
	ASSERT_TRUE(l._grid[1][0].isAlive());
	ASSERT_FALSE(l._grid[1][1].isAlive());
	ASSERT_TRUE(l._grid[0][0].print() == '-');
	ASSERT_TRUE(l._grid[0][1].print() == '1');
	ASSERT_TRUE(l._grid[1][0].print() == '1');
	ASSERT_TRUE(l._grid[1][1].print() == '-');
}

TEST(Life, print1){
	Life<FredkinCell> l(0, 0);
	std::stringstream ss;
	l.print(ss);
	ASSERT_TRUE(ss.str() == "\nGeneration = 0, Population = 0.\n");
}

TEST(Life, print2){
	Life<ConwayCell> l(1, 1);
	std::stringstream ss;
	l.print(ss);
	ASSERT_TRUE(ss.str() == "\nGeneration = 0, Population = 0.\n.\n");
}

TEST(Life, print3){
	Life<FredkinCell> l(1, 1);
	std::stringstream ss;
	l.print(ss);
	ASSERT_TRUE(ss.str() == "\nGeneration = 0, Population = 0.\n-\n");
}

TEST(Life, initializeGrid_normal){
	Life<ConwayCell>l(0, 0);
	l.initializeGrid(4, 3);
	ASSERT_TRUE(l._grid.size() == 4);
	ASSERT_TRUE(l._grid[0].size() == 3);
}

TEST(Life, initializeGrid_empty){
	Life<ConwayCell>l(0, 0);
	ASSERT_TRUE(l._grid.size() == 0);
	l.initializeGrid(0, 0);
	ASSERT_TRUE(l._grid.size() == 0);
}

TEST(Life, initializeGrid_invalid){
	Life<ConwayCell>l(0, 0);
	try{
		l.initializeGrid(-1, -3);
		ASSERT_TRUE(false);
	} catch (invalid_argument&){
		ASSERT_TRUE(true);
	}	
}
