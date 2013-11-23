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

% g++ -pedantic -std=c++0x -Wall Life.h TestLife.c++ -o TestLife -lgtest -lpthread -lgtest_main

% valgrind TestLife > TestLife.out
*/

// --------
// includes
// --------

#include "gtest/gtest.h"

#include "Life.h"
#include <fstream>

#include <iostream> // cout, endl
#include <sstream> // istringtstream, ostringstream
#include <string> // ==
#include "FredkinCell.h"
#include "ConwayCell.h"
// #include "Handle.h"

// -----------------
// FredkinCell::outputType
// -----------------
TEST(FredkinCell, constructor_1) {
  FredkinCell fred = FredkinCell();
  
  ASSERT_TRUE(fred.is_alive() == false);
  ASSERT_TRUE(fred.is_age() == 0);
  ASSERT_TRUE(fred.is_name() == '-');
}

TEST(FredkinCell, constructor_2) {
  FredkinCell fred = FredkinCell(false);
  ASSERT_TRUE(fred.is_alive() == false);
  ASSERT_TRUE(fred.is_age() == 0);
  ASSERT_TRUE(fred.is_name() == '-');
}

TEST(FredkinCell, constructor_3){
	FredkinCell fred = FredkinCell(true);
	ASSERT_TRUE(fred.is_alive() == true);
	ASSERT_TRUE(fred.is_age() == 0);
	ASSERT_TRUE(fred.is_name() == '0');
}

TEST(FredkinCell, turn_1){
	FredkinCell fred = FredkinCell();
	fred.turn(0);
	ASSERT_TRUE(fred.is_alive() == false);
	ASSERT_TRUE(fred.is_age() == 0);
}

TEST(FredkinCell, turn_2){
	FredkinCell fred = FredkinCell();
	fred.turn(1);
	ASSERT_TRUE(fred.is_alive() == true);
	ASSERT_TRUE(fred.is_age() == 0);
}

TEST(FredkinCell, turn_3){
	FredkinCell fred = FredkinCell(true);
	fred.turn(0);
	ASSERT_TRUE(fred.is_alive() == true);
	ASSERT_TRUE(fred.is_age() == 1);
}

TEST(FredkinCell, turn_4){
	FredkinCell fred = FredkinCell();
	fred.turn(1);
	ASSERT_TRUE(fred.is_alive() == true);
	ASSERT_TRUE(fred.is_age() == 0);
}

TEST(FredkinCell, turn_5){
	FredkinCell fred = FredkinCell(true);
	fred.turn(-1);
	fred.turn(0);
	ASSERT_TRUE(fred.is_alive() == false);
	ASSERT_TRUE(fred.is_age() == 0);
}
TEST(FredkinCell, turn_6){
	FredkinCell fred = FredkinCell();
	fred.turn(0);
	fred.turn(1);
	fred.turn(-1);
	ASSERT_TRUE(fred.is_alive() == false);
	ASSERT_TRUE(fred.is_age() == 0);
}

TEST(FredkinCell, turn_7){
	FredkinCell fred = FredkinCell();
	fred.turn(1);
	ASSERT_TRUE(fred.is_alive() == true);
	ASSERT_TRUE(fred.is_age() == 0);
}

TEST(FredkinCell, turn_8){
	FredkinCell fred = FredkinCell(true);
	fred.turn(0);
	fred.turn(1);
	fred.turn(0);
	ASSERT_TRUE(fred.is_alive() == true);
	ASSERT_TRUE(fred.is_age() == 2);
}

TEST(FredkinCell, turn_9){
	FredkinCell fred = FredkinCell();
	fred.turn(1);
	fred.turn(-1);
	ASSERT_TRUE(fred.is_alive() == false);
	ASSERT_TRUE(fred.is_age() == 0);
}

TEST(FredkinCell, turn_10){
	FredkinCell fred = FredkinCell(true);
	fred.turn(-1);
	fred.turn(1);
	fred.turn(-1);
	ASSERT_TRUE(fred.is_alive() == false);
	ASSERT_TRUE(fred.is_age() == 0);
}
TEST(FredkinCell, turn_11){
	FredkinCell fred = FredkinCell();
	fred.turn(0);
	fred.turn(-1);
	ASSERT_TRUE(fred.is_alive() == false);
	ASSERT_TRUE(fred.is_age() == 0);
}

TEST(FredkinCell, turn_12){
	FredkinCell fred = FredkinCell();
	fred.turn(-1);
	fred.turn(1);
	ASSERT_TRUE(fred.is_alive() == true);
	ASSERT_TRUE(fred.is_age() == 0);
}

TEST(FredkinCell, turn_13){
	FredkinCell fred = FredkinCell(true);
	fred.turn(0);
	fred.turn(0);
	fred.turn(-1);
	ASSERT_TRUE(fred.is_alive() == true);
	ASSERT_TRUE(fred.is_age() == 1);
}

TEST(FredkinCell, turn_14){
	FredkinCell fred = FredkinCell();
	fred.turn(1);
	fred.turn(-1);
	fred.turn(1);
	ASSERT_TRUE(fred.is_alive() == true);
	ASSERT_TRUE(fred.is_age() == 0);
}

TEST(FredkinCell, turn_15){
	FredkinCell fred = FredkinCell(true);
	fred.turn(-1);
	ASSERT_TRUE(fred.is_alive() == false);
	ASSERT_TRUE(fred.is_age() == 0);
}
TEST(FredkinCell, turn_16){
	FredkinCell fred = FredkinCell();
	fred.turn(0);
	ASSERT_TRUE(fred.is_alive() == false);
	ASSERT_TRUE(fred.is_age() == 0);
}

TEST(FredkinCell, turn_17){
	FredkinCell fred = FredkinCell();
	fred.turn(1);
	ASSERT_TRUE(fred.is_alive() == true);
	ASSERT_TRUE(fred.is_age() == 0);
}

TEST(FredkinCell, turn_18){
	FredkinCell fred = FredkinCell(true);
	fred.turn(0);
	ASSERT_TRUE(fred.is_alive() == true);
	ASSERT_TRUE(fred.is_age() == 1);
}

TEST(FredkinCell, turn_19){
	FredkinCell fred = FredkinCell();
	fred.turn(1);
	ASSERT_TRUE(fred.is_alive() == true);
	ASSERT_TRUE(fred.is_age() == 0);
}

TEST(FredkinCell, turn_20){
	FredkinCell fred = FredkinCell(true);
	fred.turn(-1);
	ASSERT_TRUE(fred.is_alive() == false);
	ASSERT_TRUE(fred.is_age() == 0);
}
TEST(FredkinCell, turn_21){
	FredkinCell fred = FredkinCell();
	fred.turn(0);
	ASSERT_TRUE(fred.is_alive() == false);
	ASSERT_TRUE(fred.is_age() == 0);
}

TEST(FredkinCell, turn_22){
	FredkinCell fred = FredkinCell();
	fred.turn(1);
	ASSERT_TRUE(fred.is_alive() == true);
	ASSERT_TRUE(fred.is_age() == 0);
}

TEST(FredkinCell, turn_23){
	FredkinCell fred = FredkinCell(true);
	fred.turn(0);
	ASSERT_TRUE(fred.is_alive() == true);
	ASSERT_TRUE(fred.is_age() == 1);
}

TEST(FredkinCell, turn_24){
	FredkinCell fred = FredkinCell();
	fred.turn(1);
	ASSERT_TRUE(fred.is_alive() == true);
	ASSERT_TRUE(fred.is_age() == 0);
}

TEST(FredkinCell, turn_25){
	FredkinCell fred = FredkinCell(true);
	fred.turn(-1);
	ASSERT_TRUE(fred.is_alive() == false);
	ASSERT_TRUE(fred.is_age() == 0);
}
TEST(FredkinCell, turn_26){
	FredkinCell fred = FredkinCell();
	fred.turn(0);
	ASSERT_TRUE(fred.is_alive() == false);
	ASSERT_TRUE(fred.is_age() == 0);
}

TEST(FredkinCell, turn_27){
	FredkinCell fred = FredkinCell();
	fred.turn(1);
	ASSERT_TRUE(fred.is_alive() == true);
	ASSERT_TRUE(fred.is_age() == 0);
}

TEST(FredkinCell, turn_28){
	FredkinCell fred = FredkinCell(true);
	fred.turn(0);
	ASSERT_TRUE(fred.is_alive() == true);
	ASSERT_TRUE(fred.is_age() == 1);
}

TEST(FredkinCell, turn_29){
	FredkinCell fred = FredkinCell();
	fred.turn(1);
	ASSERT_TRUE(fred.is_alive() == true);
	ASSERT_TRUE(fred.is_age() == 0);
}

TEST(FredkinCell, turn_30){
	FredkinCell fred = FredkinCell(true);
	fred.turn(-1);
	ASSERT_TRUE(fred.is_alive() == false);
	ASSERT_TRUE(fred.is_age() == 0);
}

TEST(FredkinCell, is_age_1){
	FredkinCell fred = FredkinCell(true);
	ASSERT_TRUE(fred.is_age() == 0);
}

TEST(FredkinCell, is_age_2){
	FredkinCell fred = FredkinCell(true);
	fred.turn(0);
	ASSERT_TRUE(fred.is_age() == 1);
}

TEST(FredkinCell, is_age_3){
	FredkinCell fred = FredkinCell(true);
	fred.turn(0);
	fred.turn(0);
	fred.turn(0);
	ASSERT_TRUE(fred.is_age() == 3);
}

TEST(FredkinCell, is_age_4){
	FredkinCell fred = FredkinCell(false);
	fred.turn(1);
	fred.turn(0);
	ASSERT_TRUE(fred.is_age() == 1);
}

TEST(FredkinCell, is_age_5){
	FredkinCell fred = FredkinCell(false);
	fred.turn(1);
	fred.turn(0);
	fred.turn(0);
	fred.turn(-1);
	ASSERT_TRUE(fred.is_age() == 2);
}

TEST(FredkinCell, is_name_1){
	FredkinCell fred = FredkinCell(true);
	ASSERT_TRUE(fred.is_name() == '0');
	fred.turn(0);
	fred.turn(0);
	fred.turn(0);
	fred.turn(0);
	fred.turn(0);
	ASSERT_TRUE(fred.is_name() == '5');
}

TEST(FredkinCell, is_name_2){
	FredkinCell fred = FredkinCell(true);
	ASSERT_TRUE(fred.is_name() == '0');
	fred.turn(0);
	fred.turn(-1);
	fred.turn(1);
	for (int i = 0; i < 7; i++)
		fred.turn(0);
	ASSERT_TRUE(fred.is_name() == '8');
}

TEST(FredkinCell, is_name_3){
	FredkinCell fred = FredkinCell(true);
	ASSERT_TRUE(fred.is_name() == '0');
	for (int i = 0; i < 12; i++)
		fred.turn(0);
	ASSERT_TRUE(fred.is_name() == '+');
}

TEST(FredkinCell, is_name_4){
	FredkinCell fred = FredkinCell(true);
	ASSERT_TRUE(fred.is_name() == '0');
	fred.turn(0);
	fred.turn(-1);
	ASSERT_TRUE(fred.is_name() == '-');
}

TEST(ConwayCell, constructor_1) {
  ConwayCell fred = ConwayCell();
  
  ASSERT_TRUE(fred.is_alive() == false);
  ASSERT_TRUE(fred.name == '.');
}

TEST(ConwayCell, constructor_2) {
  ConwayCell fred = ConwayCell(false);
  ASSERT_TRUE(fred.is_alive() == false);
  ASSERT_TRUE(fred.name == '.');
}

TEST(ConwayCell, contructor_3){
	ConwayCell fred = ConwayCell(true);
	ASSERT_TRUE(fred.is_alive() == true);
	ASSERT_TRUE(fred.name == '*');
}

TEST(ConwayCell, turn_1){
	ConwayCell con = ConwayCell();
	con.turn(1);
	ASSERT_TRUE(con.is_alive() == true);
}

TEST(ConwayCell, turn_2){
	ConwayCell con = ConwayCell();
	con.turn(1);
	con.turn(0);
	con.turn(0);
	con.turn(-1);
	ASSERT_TRUE(con.is_alive() == false);
}

TEST(ConwayCell, turn_3){
	ConwayCell con = ConwayCell();
	con.turn(0);
	ASSERT_TRUE(con.is_alive() == false);
}

TEST(ConwayCell, turn_4){
	ConwayCell con = ConwayCell(true);
	con.turn(0);
	ASSERT_TRUE(con.is_alive() == true);
}

TEST(ConwayCell, turn_5){
	ConwayCell con = ConwayCell(true);
	con.turn(0);
	con.turn(-1);
	ASSERT_TRUE(con.is_alive() == false);
}

TEST(ConwayCell, turn_6){
	ConwayCell con = ConwayCell(true);
	con.turn(0);
	con.turn(0);
	con.turn(-1);
	con.turn(1);
	ASSERT_TRUE(con.is_alive() == true);
}

TEST(ConwayCell, turn_7){
	ConwayCell con = ConwayCell();
	con.turn(1);
	ASSERT_TRUE(con.is_alive() == true);
}

TEST(ConwayCell, turn_8){
	ConwayCell con = ConwayCell();
	con.turn(1);
	con.turn(0);
	con.turn(0);
	con.turn(-1);
	ASSERT_TRUE(con.is_alive() == false);
}

TEST(ConwayCell, turn_9){
	ConwayCell con = ConwayCell();
	con.turn(0);
	ASSERT_TRUE(con.is_alive() == false);
}

TEST(ConwayCell, turn_10){
	ConwayCell con = ConwayCell(true);
	con.turn(0);
	ASSERT_TRUE(con.is_alive() == true);
}

TEST(ConwayCell, turn_11){
	ConwayCell con = ConwayCell(true);
	con.turn(0);
	con.turn(-1);
	ASSERT_TRUE(con.is_alive() == false);
}

TEST(ConwayCell, turn_12){
	ConwayCell con = ConwayCell(true);
	con.turn(0);
	con.turn(0);
	con.turn(-1);
	con.turn(1);
	ASSERT_TRUE(con.is_alive() == true);
}

TEST(ConwayCell, clone_13){
	ConwayCell con = ConwayCell();
	AbstractCell* abst = con.clone();
	ASSERT_TRUE(abst->is_alive() == false);
}

TEST(ConwayCell, clone_14){
	ConwayCell con = ConwayCell();
	con.turn(1);
	AbstractCell* abst = con.clone();
	ASSERT_TRUE(abst->is_alive() == true);
}

TEST(ConwayCell, clone_15){
	ConwayCell con = ConwayCell();
	con.turn(1);
	con.turn(0);
	con.turn(0);
	con.turn(-1);
	AbstractCell* abst = con.clone();
	ASSERT_TRUE(abst->is_alive() == false);
}

TEST(ConwayCell, clone_16){
	ConwayCell con = ConwayCell(true);
	AbstractCell* abst = con.clone();
	ASSERT_TRUE(abst->is_alive() == true);
}

TEST(ConwayCell, clone_17){
	ConwayCell con = ConwayCell(true);
	con.turn(0);
	con.turn(-1);
	AbstractCell* abst = con.clone();
	ASSERT_TRUE(abst->is_alive() == false);
}

TEST(ConwayCell, clone_18){
	ConwayCell con = ConwayCell(false);
	con.turn(0);
	con.turn(1);
	con.turn(-1);
	AbstractCell* abst = con.clone();
	ASSERT_TRUE(abst->is_alive() == false);
}

TEST(ConwayCell, turn_19){
	ConwayCell con = ConwayCell();
	con.turn(1);
	ASSERT_TRUE(con.is_alive() == true);
}

TEST(ConwayCell, turn_20){
	ConwayCell con = ConwayCell();
	con.turn(1);
	con.turn(0);
	con.turn(0);
	con.turn(-1);
	ASSERT_TRUE(con.is_alive() == false);
}

TEST(ConwayCell, turn_21){
	ConwayCell con = ConwayCell();
	con.turn(0);
	ASSERT_TRUE(con.is_alive() == false);
}

TEST(ConwayCell, turn_22){
	ConwayCell con = ConwayCell(true);
	con.turn(0);
	ASSERT_TRUE(con.is_alive() == true);
}

TEST(ConwayCell, turn_23){
	ConwayCell con = ConwayCell(true);
	con.turn(0);
	con.turn(-1);
	ASSERT_TRUE(con.is_alive() == false);
}

TEST(ConwayCell, turn_24){
	ConwayCell con = ConwayCell(true);
	con.turn(0);
	con.turn(0);
	con.turn(-1);
	con.turn(1);
	ASSERT_TRUE(con.is_alive() == true);
}

TEST(ConwayCell, turn_25){
	ConwayCell con = ConwayCell();
	con.turn(1);
	ASSERT_TRUE(con.is_alive() == true);
}

TEST(ConwayCell, turn_26){
	ConwayCell con = ConwayCell();
	con.turn(1);
	con.turn(0);
	con.turn(0);
	con.turn(-1);
	ASSERT_TRUE(con.is_alive() == false);
}

TEST(ConwayCell, turn_27){
	ConwayCell con = ConwayCell();
	con.turn(0);
	ASSERT_TRUE(con.is_alive() == false);
}

TEST(ConwayCell, turn_29){
	ConwayCell con = ConwayCell(true);
	con.turn(0);
	ASSERT_TRUE(con.is_alive() == true);
}

TEST(ConwayCell, turn_30){
	ConwayCell con = ConwayCell(true);
	con.turn(0);
	con.turn(-1);
	ASSERT_TRUE(con.is_alive() == false);
}

TEST(ConwayCell, turn_31){
	ConwayCell con = ConwayCell(true);
	con.turn(0);
	con.turn(0);
	con.turn(-1);
	con.turn(1);
	ASSERT_TRUE(con.is_alive() == true);
}

TEST(Cell, constructor_1){
	Cell fred = Cell(new FredkinCell());
	ASSERT_TRUE(fred.get()->is_alive() == false);
	ASSERT_TRUE(fred.get()->is_name() == '-');
	ASSERT_TRUE(fred.get()->is_id() == 'f');
}

TEST(Cell, constructor_2){
	Cell fred = Cell(new FredkinCell(false));
	ASSERT_TRUE(fred.get()->is_alive() == false);
	ASSERT_TRUE(fred.get()->is_name() == '-');
	ASSERT_TRUE(fred.get()->is_id() == 'f');
}

TEST(Cell, constructor_3){
	Cell fred = Cell(new FredkinCell(true));
	ASSERT_TRUE(fred.get()->is_alive() == true);
	ASSERT_TRUE(fred.get()->is_name() == '0');
	ASSERT_TRUE(fred.get()->is_id() == 'f');
}

TEST(Cell, constructor_4){
	Cell fred = Cell(new ConwayCell());
	ASSERT_TRUE(fred.get()->is_alive() == false);
	ASSERT_TRUE(fred.get()->is_name() == '.');
	ASSERT_TRUE(fred.get()->is_id() == 'c');
}

TEST(Cell, constructor_5){
	Cell fred = Cell(new ConwayCell(false));
	ASSERT_TRUE(fred.get()->is_alive() == false);
	ASSERT_TRUE(fred.get()->is_name() == '.');
	ASSERT_TRUE(fred.get()->is_id() == 'c');
}

TEST(Cell, constructor_6){
	Cell fred = Cell(new ConwayCell(true));
	ASSERT_TRUE(fred.get()->is_alive() == true);
	ASSERT_TRUE(fred.get()->is_name() == '*');
	ASSERT_TRUE(fred.get()->is_id() == 'c');
}

TEST(Cell, turn_1){
	Cell fred = Cell(new FredkinCell());
	fred.turn(0);
	fred.turn(0);
	ASSERT_TRUE(fred.get()->is_age() == 0);
}

TEST(Cell, turn_2){
	Cell fred = Cell(new FredkinCell());
	fred.turn(1);
	fred.turn(0);
	ASSERT_TRUE(fred.get()->is_age() == 1);
}

TEST(Cell, turn_3){
	Cell fred = Cell(new FredkinCell());
	fred.turn(1);
	fred.turn(0);
	fred.turn(-1);
	fred.turn(1);
	ASSERT_TRUE(fred.get()->is_age() == 1);
}
TEST(Cell, turn_4){
	Cell fred = Cell(new FredkinCell());
	fred.turn(1);
	fred.turn(0);
	fred.turn(0);
	fred.turn(0);
	fred.turn(-1);
	fred.turn(1);
	fred.turn(0);
	ASSERT_TRUE(fred.get()->is_age() == -1);// -1 indicates it mutated into a conway
}

TEST(Cell, turn_5){
	Cell fred = Cell(new ConwayCell());
	fred.turn(1);
	fred.turn(0);
	fred.turn(0);
	ASSERT_TRUE(fred.is_alive() == true);
}

TEST(Cell, turn_6){
	Cell fred = Cell(new ConwayCell());
	fred.turn(1);
	fred.turn(-1);
	fred.turn(0);
	fred.turn(1);
	fred.turn(-1);
	ASSERT_TRUE(fred.is_alive() == false);
}

TEST(Cell, turn_7){
	Cell fred = Cell(new FredkinCell());
	fred.turn(1);
	fred.turn(0);
	fred.turn(0);
	fred.turn(0);
	fred.turn(-1);
	fred.turn(1);
	ASSERT_TRUE(fred.is_alive() == true);
}

TEST(Cell, turn_8){
	Cell fred = Cell(new FredkinCell());
	fred.turn(1);
	fred.turn(0);
	fred.turn(-1);
	fred.turn(1);
	fred.turn(-1);
	fred.turn(1);
	ASSERT_TRUE(fred.is_alive() == true);
}

TEST(Cell, turn_9){
	Cell fred = Cell(new FredkinCell());
	fred.turn(1);
	fred.turn(0);
	fred.turn(0);
	fred.turn(0);
	fred.turn(0);
	fred.turn(0);
	fred.turn(-1);
	fred.turn(1);
	ASSERT_TRUE(fred.is_alive() == true);
}

TEST(Cell, turn_10){
	Cell fred = Cell(new FredkinCell());
	fred.turn(1);
	fred.turn(0);
	fred.turn(0);
	fred.turn(0);
	fred.turn(-1);
	fred.turn(0);
	fred.turn(0);
	fred.turn(1);
	ASSERT_TRUE(fred.is_alive() == true);
}

TEST(Cell, turn_11){
	Cell fred = Cell(new FredkinCell());
	fred.turn(1);
	fred.turn(0);
	fred.turn(0);
	fred.turn(0);
	fred.turn(0);
	fred.turn(0);
	fred.turn(0);
	fred.turn(0);
	fred.turn(-1);
	fred.turn(1);
	ASSERT_TRUE(fred.is_alive() == true);
}

TEST(Cell, turn_12){
	Cell fred = Cell(new FredkinCell());
	fred.turn(1);
	fred.turn(0);
	fred.turn(0);
	fred.turn(0);
	fred.turn(-1);
	fred.turn(1);
	fred.turn(0);
	fred.turn(0);
	fred.turn(-1);
	fred.turn(1);
	ASSERT_TRUE(fred.is_alive() == true);
}

TEST(Cell, turn_13){
	Cell fred = Cell(new FredkinCell());
	fred.turn(1);
	fred.turn(0);
	fred.turn(0);
	fred.turn(0);
	fred.turn(-1);
	fred.turn(1);
	fred.turn(0);
	fred.turn(0);
	fred.turn(-1);
	fred.turn(1);
	fred.turn(0);
	ASSERT_TRUE(fred.is_alive() == true);
}

TEST(Cell, turn_14){
	Cell fred = Cell(new FredkinCell());
	fred.turn(1);
	fred.turn(0);
	fred.turn(0);
	fred.turn(0);
	fred.turn(-1);
	fred.turn(1);
	fred.turn(-1);
	fred.turn(1);
	ASSERT_TRUE(fred.is_alive() == true);
}

TEST(Cell, turn_15){
	Cell fred = Cell(new FredkinCell());
	fred.turn(1);
	fred.turn(0);
	fred.turn(0);
	fred.turn(0);
	fred.turn(-1);
	fred.turn(1);
	ASSERT_TRUE(fred.is_alive() == true);
}

TEST(Cell, turn_16){
	Cell fred = Cell(new FredkinCell());
	fred.turn(1);
	fred.turn(0);
	fred.turn(0);
	fred.turn(0);
	fred.turn(-1);
	fred.turn(1);
	fred.turn(1);
	ASSERT_TRUE(fred.is_alive() == true);
}

TEST(Cell, turn_17){
	Cell fred = Cell(new FredkinCell());
	fred.turn(1);
	fred.turn(0);
	fred.turn(0);
	fred.turn(0);
	fred.turn(-1);
	fred.turn(-1);
	ASSERT_TRUE(fred.is_alive() == false);
}

TEST(Cell, turn_18){
	Cell fred = Cell(new FredkinCell());
	fred.turn(0);
	fred.turn(0);
	fred.turn(-1);
	fred.turn(1);
	fred.turn(0);
	fred.turn(-1);
	fred.turn(1);
	ASSERT_TRUE(fred.is_alive() == true);
}