// --------
// includes
// --------

#include <iostream>
#include <sstream>
#include <string>
#include "gtest/gtest.h"
#include "FredkinCell.h"
#include "ConwayCell.h"
#include "Cell.h"
#include "Life.h"
// ----------
// Life Tests
// ----------

// -------------
// Fredkin Tests
// -------------

// constructor

TEST(Life, FredkinCell_alive) {
  FredkinCell Cell(true);
  ASSERT_TRUE(Cell.isAlive());
}

TEST(Life, FredkinCell_dead) {
  FredkinCell Cell(false);
  ASSERT_TRUE(!Cell.isAlive());
}

TEST(Life, FredkinCell_age) {
  FredkinCell Cell(true, 2);
  ASSERT_TRUE(Cell._age == 2);
}

// change state

TEST(Life, FredkinCell_kill_cell) {
  FredkinCell Cell(true);
  Cell.changeState(0, 2);
  ASSERT_TRUE(!Cell.isAlive());
}

TEST(Life, FredkinCell_resurrect_cell) {
  FredkinCell Cell(false);
  Cell.changeState(0, 1);
  ASSERT_TRUE(Cell.isAlive());
}

TEST(Life, FredkinCell_reset_age) {
  FredkinCell Cell(false);
  Cell.changeState(0, 1);
  ASSERT_TRUE(Cell._age == 0);
}

TEST(Life, FredkinCell_increment_age) {
  FredkinCell Cell(true);
  Cell.changeState(0, 1);
  ASSERT_TRUE(Cell._age == 1);
}

TEST(Life, FredkinCell_increment_age_old) {
  FredkinCell Cell(true, 2); 
  Cell.changeState(0,1);
  ASSERT_TRUE(Cell._age == 3);
}

// clone

TEST(Life, cloneFred) {
  FredkinCell Cell(true, 2);
  FredkinCell* newCell = Cell.clone();
  ASSERT_TRUE(newCell->_age == 2 && newCell->isAlive() && newCell != &Cell);
}

// ------------
// Conway Tests
// ------------

// constructor

TEST(Life, ConwayCell_alive) {
  ConwayCell Cell(true);
  ASSERT_TRUE(Cell.isAlive());
}

TEST(Life, ConwayCell_dead) {
  ConwayCell Cell(false);
  ASSERT_TRUE(!Cell.isAlive());
}

// change state

TEST(Life, ConwayCell_resurrect) {
  ConwayCell Cell(false);
  Cell.changeState(1,2);
  ASSERT_TRUE(Cell.isAlive());
}

TEST(Life, ConwayCell_kill1) {
  ConwayCell Cell(true);
  Cell.changeState(1,3);
  ASSERT_TRUE(!Cell.isAlive());
}

TEST(Life, ConwayCell_kill2) {
  ConwayCell Cell(true);
  Cell.changeState(1,0);
  ASSERT_TRUE(!Cell.isAlive());
}

TEST(Life, ConwayCell_keep_alive) {
  ConwayCell Cell(true);
  Cell.changeState(1,1);
  ASSERT_TRUE(Cell.isAlive());
}

TEST(Life, ConwayCell_keep_dead) {
  ConwayCell Cell(false);
  Cell.changeState(1,1);
  ASSERT_TRUE(!Cell.isAlive());
}

// Clone

TEST(Life, cloneCon) {
  ConwayCell Cell(true);
  ConwayCell* newCell = Cell.clone();
  ASSERT_TRUE(newCell->isAlive() && newCell != &Cell);
}

// ----------
// Cell Tests
// ----------

// Constructor

TEST(Life, cell_live) {
  Cell cell(true);
  ASSERT_TRUE(cell._p->isAlive() && cell._type == cellTypeFredkin);
}

TEST(Life, cell_dead) {
  Cell cell(false);
  ASSERT_TRUE(!(cell._p->isAlive()) && cell._type == cellTypeFredkin);
}

// Change State 

TEST(Life, cell_change_Fred) {
  Cell cell(true);
  cell.changeState(0,1);
  ASSERT_TRUE(cell._p->isAlive() && cell._type == cellTypeFredkin);
}

TEST(Life, cell_change_FredToCon) {
  Cell cell(true);
  cell.changeState(0,1);
  cell.changeState(0,1);
  ASSERT_TRUE(cell._p->isAlive() && cell._type == cellTypeConway);
}

TEST(Life, cell_change_con) {
  Cell cell(true);
  cell.changeState(0,1);
  cell.changeState(0,1);
  cell.changeState(0,1);
  ASSERT_TRUE(!cell._p->isAlive() && cell._type == cellTypeConway);
}

// Is Alive

TEST(Life, isAlive_one) {
  Cell cell(true);
  ASSERT_TRUE(cell.isAlive());
}

TEST(Life, isAlive_two) {
  ConwayCell conCell(false);
  Cell cell(true);
  cell._p = &conCell;
  ASSERT_TRUE(!cell.isAlive());
}

// ------------
// Life.h tests
// ------------
std::istringstream conOne("1\n1\n*\n");
std::istringstream conTwo("2\n2\n..\n**");
std::istringstream fredOne("1\n1\n0\n");
std::istringstream fredTwo("2\n2\n--\n00");
// constructor

TEST(Life, construct_conway_one) {
  Life<ConwayCell> oneLife(conOne);
  ASSERT_TRUE(oneLife.board[1][1].isAlive());
}

TEST(Life, construct_conway_two) {
  Life<ConwayCell> twoLife(conTwo);
  ASSERT_TRUE(!twoLife.board[1][1].isAlive() && twoLife.board[2][2].isAlive());
}

TEST(Life, construct_fredkin_one) {
  Life<FredkinCell> oneLife(fredOne);
  ASSERT_TRUE(oneLife.board[1][1].isAlive());
}

TEST(Life, construct_fredkin_two) {
  Life<FredkinCell> twoLife(fredTwo);
  ASSERT_TRUE(!twoLife.board[1][1].isAlive() && twoLife.board[2][2].isAlive());
}

TEST(Life, construct_cell_one) {
  Life<Cell> oneLife(fredOne);
  ASSERT_TRUE(!oneLife.board[1][1].isAlive());
}

TEST(Life, construct_cell_two) {
  Life<Cell> twoLife(fredTwo);
  ASSERT_TRUE(!twoLife.board[1][1].isAlive());
}
