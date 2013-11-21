// ------------------------------------
// projects/allocator/TestLife.c++
// Copyright (C) 2013
// Justin Hust
// EID: jkh2367
// CS ID: jkhust
// Email: justin.hust@utexas.edu
// ------------------------------------

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

#include <iostream> // cout, endl
#include <sstream> // istringtstream, ostringstream
#include <string> // ==

// -----------------
// FredkinCell::outputType
// -----------------
TEST(FredkinCell, outputType_1) {
  FredkinCell fc(0, '-');

  std::ostringstream oss;  
  fc.outputType(oss);
  
  ASSERT_TRUE(oss.str() == "FredkinCell");

}

TEST(FredkinCell, outputType_2) {
  FredkinCell fc(0, '2');

  std::ostringstream oss;  
  fc.outputType(oss);
  
  ASSERT_TRUE(oss.str() == "FredkinCell");

}

TEST(FredkinCell, outputType_3) {
  FredkinCell fc(0, '9');

  std::ostringstream oss;  
  fc.outputType(oss);
  
  ASSERT_TRUE(oss.str() == "FredkinCell");

}

TEST(FredkinCell, outputType_4) {
  FredkinCell fc(0, '+');

  std::ostringstream oss;  
  fc.outputType(oss);
  
  ASSERT_TRUE(oss.str() == "FredkinCell");

}

// -----------------
// FredkinCell::draw
// -----------------
TEST(FredkinCell, draw_1) {
  FredkinCell fc(0, '-');

  std::ostringstream oss;  
  fc.draw(oss);
  
  ASSERT_TRUE(oss.str() == "-");

}

TEST(FredkinCell, draw_2) {
  FredkinCell fc(99, '0');

  std::ostringstream oss;  
  fc.draw(oss);
  
  ASSERT_TRUE(oss.str() == "0");

}

TEST(FredkinCell, draw_3) {
  FredkinCell fc(365, '4');

  std::ostringstream oss;  
  fc.draw(oss);
  
  ASSERT_TRUE(oss.str() == "4");

}

TEST(FredkinCell, draw_4) {
  FredkinCell fc(129, '9');

  std::ostringstream oss;  
  fc.draw(oss);
  
  ASSERT_TRUE(oss.str() == "9");

}


TEST(FredkinCell, draw_5) {
  FredkinCell fc(77, '+');

  std::ostringstream oss;  
  fc.draw(oss);
  
  ASSERT_TRUE(oss.str() == "+");

}


// -----------------
// FredkinCell::getCoord
// -----------------
TEST(FredkinCell, getCoord_1) {
  FredkinCell fc(0, '3');

  ASSERT_TRUE( fc.getCoord() == 0);

}

TEST(FredkinCell, getCoord_2) {
  FredkinCell fc(127, '-');

  ASSERT_TRUE( fc.getCoord() == 127);
 
}

TEST(FredkinCell, getCoord_3) {
  FredkinCell fc(99, '-');

  ASSERT_TRUE( fc.getCoord() == 99);
 
}

// -----------------
// FredkinCell::tallyAlive
// -----------------
TEST(FredkinCell, tallyAlive_1) {
  FredkinCell fc(0, '0');

  int i = 0;
  fc.tallyAlive(i);
  
  ASSERT_TRUE( i == 1 );

}

TEST(FredkinCell, tallyAlive_2) {
  FredkinCell fc(0, '-');

  int i = 0;
  fc.tallyAlive(i);
  
  ASSERT_TRUE( i == 0 );
 
}

TEST(FredkinCell, tallyAlive_3) {
  FredkinCell fc1(99, '1');
  FredkinCell fc2(199, '-');

  int i=0;
  fc1.tallyAlive(i);
  fc2.tallyAlive(i);
  
  ASSERT_TRUE( i == 1 );
 
}

TEST(FredkinCell, tallyAlive_4) {
  FredkinCell fc1(299, '-');
  FredkinCell fc2(599, '9');

  int i=0;
  fc1.tallyAlive(i);
  fc2.tallyAlive(i);
  
  ASSERT_TRUE( i == 1 );
 
}

TEST(FredkinCell, tallyAlive_5) {
  FredkinCell fc1(399, '1');
  FredkinCell fc2(509, '5');

  int i=0;
  fc1.tallyAlive(i);
  fc2.tallyAlive(i);
  
  ASSERT_TRUE( i == 2 );
 
}


TEST(FredkinCell, tallyAlive_6) {
  FredkinCell fc1(399, '1');
  FredkinCell fc2(509, '-');
  FredkinCell fc3(509, '+');

  int i=0;
  fc1.tallyAlive(i);
  fc2.tallyAlive(i);
  fc3.tallyAlive(i);
  
  ASSERT_TRUE( i == 2 );
 
}

// -----------------
// FredkinCell::ageState
// -----------------
TEST(FredkinCell, ageState_1) {
  FredkinCell fc(0, '-');
  
  ASSERT_TRUE( fc.ageState('-') == '-');
  
}

TEST(FredkinCell, ageState_2) {
  FredkinCell fc(0, '0');
  
  ASSERT_TRUE( fc.ageState('0') == '1');
  
}

TEST(FredkinCell, ageState_3) {
  FredkinCell fc(0, '9');
  
  ASSERT_TRUE( fc.ageState('9') == '+');
  
}

TEST(FredkinCell, ageState_4) {
  FredkinCell fc(0, '+');
  
  ASSERT_TRUE( fc.ageState('+') == '+');
  
}

// -----------------
// FredkinCell::projectNextState
// FredkinCell::flipState
// -----------------
TEST(FredkinCell, projectNextState_1) {
  FredkinCell fc(0, '-');
  
  // 1 neighbor, dead->alive
  bool neighbors[9] = {false, true, false, false, false, false, false, false, false };
  fc.projectNextState(neighbors);
  fc.flipState();

  std::ostringstream oss;  
  fc.draw(oss);
  
  ASSERT_TRUE(oss.str() == "0");
  
}

TEST(FredkinCell, projectNextState_2) {
  FredkinCell fc(0, '-');
  
  // 3 neighbors, dead->alive
  bool neighbors[9] = {false, true, false, true, false, false, false, true, false };
  fc.projectNextState(neighbors);
  fc.flipState();

  std::ostringstream oss;  
  fc.draw(oss);
  
  ASSERT_TRUE(oss.str() == "0");
  
}

TEST(FredkinCell, projectNextState_3) {
  FredkinCell fc(0, '0');

  // 2 neighbors, alive->dead
  bool neighbors[9] = {false, true, false, false, false, false, false, true, false };
  fc.projectNextState(neighbors);
  fc.flipState();

  std::ostringstream oss;  
  fc.draw(oss);
  
  ASSERT_TRUE(oss.str() == "-");
  
}

TEST(FredkinCell, projectNextState_4) {
  FredkinCell fc(0, '9');

  // 0 neighbors, alive->dead
  bool neighbors[9] = {false, false, false, false, false, false, false, false, false };
  fc.projectNextState(neighbors);
  fc.flipState();

  std::ostringstream oss;  
  fc.draw(oss);
  
  ASSERT_TRUE(oss.str() == "-");
  
}


TEST(FredkinCell, projectNextState_5) {
  FredkinCell fc(0, '7');

  // 4 neighbors, alive->dead
  bool neighbors[9] = {false, true, false, true, false, true, false, true, false };
  fc.projectNextState(neighbors);
  fc.flipState();

  std::ostringstream oss;  
  fc.draw(oss);
  
  ASSERT_TRUE(oss.str() == "-");
  
}



TEST(FredkinCell, projectNextState_6) {
  FredkinCell fc(0, '-');
  
  // 0 neighbors, stay dead
  bool neighbors[9] = {false, false, false, false, false, false, false, false, false };
  fc.projectNextState(neighbors);
  fc.flipState();

  std::ostringstream oss;  
  fc.draw(oss);
  
  ASSERT_TRUE(oss.str() == "-");
  
}

TEST(FredkinCell, projectNextState_7) {
  FredkinCell fc(0, '0');
  
  // 1 neighbor, alive and age
  bool neighbors[9] = {false, true, false, false, false, false, false, false, false };
  fc.projectNextState(neighbors);
  fc.flipState();

  std::ostringstream oss;  
  fc.draw(oss);
  
  fc.draw(std::cout);
  ASSERT_TRUE(oss.str() == "1");
  
}

TEST(FredkinCell, projectNextState_8) {
  FredkinCell fc(0, '2');
  
  // 3 neighbors, alive and age
  bool neighbors[9] = {false, false, false, true, false, true, false, true, false };
  fc.projectNextState(neighbors);
  fc.flipState();

  std::ostringstream oss;  
  fc.draw(oss);
  
  ASSERT_TRUE(oss.str() == "3");
  
}

TEST(FredkinCell, projectNextState_9) {
  FredkinCell fc(0, '9');
  
  // 3 neighbors, alive and age to +
  bool neighbors[9] = {false, true, false, false, false, true, false, true, false };
  fc.projectNextState(neighbors);
  fc.flipState();

  std::ostringstream oss;  
  fc.draw(oss);
  
  ASSERT_TRUE(oss.str() == "+");
  
}


TEST(FredkinCell, projectNextState_10) {
  FredkinCell fc(0, '+');
  
  // 3 neighbors, + remains +
  bool neighbors[9] = {false, true, false, false, false, true, false, true, false };
  fc.projectNextState(neighbors);
  fc.flipState();

  std::ostringstream oss;  
  fc.draw(oss);
  
  ASSERT_TRUE(oss.str() == "+");
  
}

// -----------------
// FredkinCell::clone
// -----------------
TEST(FredkinCell, clone_1) {
  FredkinCell fc(12, '9');

  AbstractCell *c = fc.clone();

  ASSERT_TRUE(c->getCoord() == 12);
  
  std::ostringstream oss;
  c->draw(oss);
  ASSERT_TRUE(oss.str() == "9");

  delete c;
  c = NULL;
  
}

TEST(FredkinCell, clone_2) {
  FredkinCell fc(888, '+');

  AbstractCell *c = fc.clone();

  ASSERT_TRUE(c->getCoord() == 888);
  
  std::ostringstream oss;
  c->draw(oss);
  ASSERT_TRUE(oss.str() == "+");

  delete c;
  c = NULL;
  
}


TEST(FredkinCell, clone_3) {
  FredkinCell fc(1253, '-');

  AbstractCell *c = fc.clone();

  ASSERT_TRUE(c->getCoord() == 1253);
  
  std::ostringstream oss;
  c->draw(oss);
  ASSERT_TRUE(oss.str() == "-");

  delete c;
  c = NULL;
  
}

// -----------------
// FredkinCell::mutate
// -----------------
TEST(FredkinCell, mutate_1) {
  FredkinCell fc(12, '9');

  AbstractCell *c = fc.mutate();

  ASSERT_TRUE(c->getCoord() == 12);
  
  std::ostringstream oss;
  c->draw(oss);
  ASSERT_TRUE(oss.str() == "*");

  delete c;
  c = NULL;
  
}

TEST(FredkinCell, mutate_2) {
  FredkinCell fc(2, '-');

  AbstractCell *c = fc.mutate();

  ASSERT_TRUE(c->getCoord() == 2);
  
  std::ostringstream oss;
  c->draw(oss);
  ASSERT_TRUE(oss.str() == "*");

  delete c;
  c = NULL;
  
}

TEST(FredkinCell, mutate_3) {
  FredkinCell fc(1299, '+');

  AbstractCell *c = fc.mutate();

  ASSERT_TRUE(c->getCoord() == 1299);
  
  std::ostringstream oss;
  c->draw(oss);
  ASSERT_TRUE(oss.str() == "*");

  delete c;
  c = NULL;
  
}

// -----------------
// ConwayCell::outputType
// -----------------
TEST(ConwayCell, outputType_1) {
  ConwayCell cc(0, '*');

  std::ostringstream oss;  
  cc.outputType(oss);
  
  ASSERT_TRUE(oss.str() == "ConwayCell");

}

TEST(ConwayCell, outputType_2) {
  ConwayCell cc(0, '.');

  std::ostringstream oss;  
  cc.outputType(oss);
  
  ASSERT_TRUE(oss.str() == "ConwayCell");

}

// -----------------
// ConwayCell::draw
// -----------------
TEST(ConwayCell, draw_1) {
  ConwayCell cc(0, '.');

  std::ostringstream oss;  
  cc.draw(oss);
  
  ASSERT_TRUE(oss.str() == ".");

}

TEST(ConwayCell, draw_2) {
  ConwayCell cc(3, '*');

  std::ostringstream oss;  
  cc.draw(oss);
  
  ASSERT_TRUE(oss.str() == "*");
  
}

// -----------------
// ConwayCell::getCoord
// -----------------
TEST(ConwayCell, getCoord_1) {
  ConwayCell cc(0, '*');

  ASSERT_TRUE( cc.getCoord() == 0);

}

TEST(ConwayCell, getCoord_2) {
  ConwayCell cc(127, '.');

  ASSERT_TRUE( cc.getCoord() == 127);
 
}

TEST(ConwayCell, getCoord_3) {
  ConwayCell cc(99, '.');

  ASSERT_TRUE( cc.getCoord() == 99);
 
}

// -----------------
// ConwayCell::tallyAlive
// -----------------
TEST(ConwayCell, tallyAlive_1) {
  ConwayCell cc(0, '*');

  int i = 0;
  cc.tallyAlive(i);
  
  ASSERT_TRUE( i == 1 );

}

TEST(ConwayCell, tallyAlive_2) {
  ConwayCell cc(0, '.');

  int i = 0;
  cc.tallyAlive(i);
  
  ASSERT_TRUE( i == 0 );
 
}

TEST(ConwayCell, tallyAlive_3) {
  ConwayCell cc1(99, '*');
  ConwayCell cc2(199, '.');

  int i=0;
  cc1.tallyAlive(i);
  cc2.tallyAlive(i);
  
  ASSERT_TRUE( i == 1 );
 
}

TEST(ConwayCell, tallyAlive_4) {
  ConwayCell cc1(299, '.');
  ConwayCell cc2(599, '*');

  int i=0;
  cc1.tallyAlive(i);
  cc2.tallyAlive(i);
  
  ASSERT_TRUE( i == 1 );
 
}

TEST(ConwayCell, tallyAlive_5) {
  ConwayCell cc1(399, '*');
  ConwayCell cc2(509, '*');

  int i=0;
  cc1.tallyAlive(i);
  cc2.tallyAlive(i);
  
  ASSERT_TRUE( i == 2 );
 
}

// -----------------
// ConwayCell::ageState
// -----------------
TEST(ConwayCell, ageState_1) {
  ConwayCell cc(0, '.');
  
  ASSERT_TRUE( cc.ageState('.') == '.');
  
}

TEST(ConwayCell, ageState_2) {
  ConwayCell cc(0, '*');
  
  ASSERT_TRUE( cc.ageState('*') == '*');
  
}

// -----------------
// ConwayCell::projectNextState
// ConwayCell::flipState
// -----------------
TEST(ConwayCell, projectNextState_1) {
  ConwayCell cc(0, '*');
  
  bool neighbors[9] = {true, true, false, false, false, false, false, false, false };
  cc.projectNextState(neighbors);
  cc.flipState();

  std::ostringstream oss;  
  cc.draw(oss);
  
  ASSERT_TRUE(oss.str() == "*");
  
}

TEST(ConwayCell, projectNextState_2) {
  ConwayCell cc(0, '.');

  bool neighbors[9] = {false, true, false, false, false, false, true, false, false };
  cc.projectNextState(neighbors);
  cc.flipState();

  std::ostringstream oss;  
  cc.draw(oss);
  
  ASSERT_TRUE(oss.str() == ".");
  
}

TEST(ConwayCell, projectNextState_3) {
  ConwayCell cc(0, '.');
  
  bool neighbors[9] = {false, true, false, true, false, false, true, false, false };
  cc.projectNextState(neighbors);
  cc.flipState();

  std::ostringstream oss;  
  cc.draw(oss);
  
  ASSERT_TRUE(oss.str() == "*");
  
}

TEST(ConwayCell, projectNextState_4) {
  ConwayCell cc(0, '*');
  
  bool neighbors[9] = {false, false, false, false, false, false, false, false, false };
  cc.projectNextState(neighbors);
  cc.flipState();

  std::ostringstream oss;  
  cc.draw(oss);
  
  ASSERT_TRUE(oss.str() == ".");
  
}

TEST(ConwayCell, projectNextState_5) {
  ConwayCell cc(0, '*');
  
  bool neighbors[9] = {false, true, false, true, false, false, true, false, false };
  cc.projectNextState(neighbors);
  cc.flipState();

  std::ostringstream oss;  
  cc.draw(oss);
  
  ASSERT_TRUE(oss.str() == "*");
  
}

// -----------------
// ConwayCell::clone
// -----------------
TEST(ConwayCell, clone_1) {
  ConwayCell cc(12, '*');

  AbstractCell *c = cc.clone();

  ASSERT_TRUE(c->getCoord() == 12);
  
  std::ostringstream oss;
  c->draw(oss);
  ASSERT_TRUE(oss.str() == "*");

  delete c;
  c = NULL;
  
}

TEST(ConwayCell, clone_2) {
  ConwayCell cc(888, '.');

  AbstractCell *c = cc.clone();

  ASSERT_TRUE(c->getCoord() == 888);
  
  std::ostringstream oss;
  c->draw(oss);
  ASSERT_TRUE(oss.str() == ".");

  delete c;
  c = NULL;
  
}


TEST(ConwayCell, clone_3) {
  ConwayCell cc(1253, '*');

  AbstractCell *c = cc.clone();

  ASSERT_TRUE(c->getCoord() == 1253);
  
  std::ostringstream oss;
  c->draw(oss);
  ASSERT_TRUE(oss.str() == "*");

  delete c;
  c = NULL;
}

// -----------------
// Cell::ctor
// -----------------
TEST(Cell, ctor_1) {
  Cell c( 5, '-');
  
  ASSERT_TRUE( c.getCoord() == 5 );
  
  std::ostringstream oss;
  c.draw(oss);
  ASSERT_TRUE(oss.str() == "-");
  
  oss.str("");
  c.outputType(oss);
  ASSERT_TRUE(oss.str() == "Cell");

}

TEST(Cell, ctor_2) {
  Cell c( 55, '9');
  
  ASSERT_TRUE( c.getCoord() == 55 );
  
  std::ostringstream oss;
  c.draw(oss);
  ASSERT_TRUE(oss.str() == "9");
  
  oss.str("");
  c.outputType(oss);
  ASSERT_TRUE(oss.str() == "Cell");

}

TEST(Cell, ctor_3) {
  Cell c( 515, '+');
  
  std::ostringstream oss;
  c.draw(oss);
  ASSERT_TRUE(oss.str() == "+");
  
  oss.str("");
  c.outputType(oss);
  ASSERT_TRUE(oss.str() == "Cell");
  
}



// -----------------
// Cell::getCoord
// -----------------
TEST(Cell, getCoord_1) {
  Cell c( new ConwayCell(5, '*') );

  ASSERT_TRUE( c.getCoord() == 5 );

}

TEST(Cell, getCoord_2) {
  Cell c( new FredkinCell(100, '-') );

  ASSERT_TRUE( c.getCoord() == 100 );

}


TEST(Cell, getCoord_3) {
  Cell c( new ConwayCell(101, '.') );

  ASSERT_TRUE( c.getCoord() == 101 );

}

TEST(Cell, getCoord_4) {
  Cell c( new FredkinCell(989, '8') );

  ASSERT_TRUE( c.getCoord() == 989 );

}

// -----------------
// Cell::draw
// -----------------
TEST(Cell, draw_1) {
  Cell c( new ConwayCell(5, '*') );

  std::ostringstream oss;
  c.draw(oss);
  ASSERT_TRUE(oss.str() == "*");
  
}

TEST(Cell, draw_2) {
  Cell c( new FredkinCell(100, '-') );

  std::ostringstream oss;
  c.draw(oss);
  ASSERT_TRUE(oss.str() == "-");

}


TEST(Cell, draw_3) {
  Cell c( new ConwayCell(101, '.') );

  std::ostringstream oss;
  c.draw(oss);
  ASSERT_TRUE(oss.str() == ".");

}

TEST(Cell, draw_4) {
  Cell c( new FredkinCell(989, '8') );

  std::ostringstream oss;
  c.draw(oss);
  ASSERT_TRUE(oss.str() == "8");

}

TEST(Cell, draw_5) {
  Cell c( new FredkinCell(9891, '9') );

  std::ostringstream oss;
  c.draw(oss);
  ASSERT_TRUE(oss.str() == "9");

}

TEST(Cell, draw_6) {
  Cell c( new FredkinCell(9891, '+') );

  std::ostringstream oss;
  c.draw(oss);
  ASSERT_TRUE(oss.str() == "+");

}

// -----------------
// Cell::clone
// -----------------
TEST(Cell, clone_1) {
  Cell c( new FredkinCell(9891, '+') );

  AbstractCell *c2 = c.clone();

  ASSERT_TRUE( c2->getCoord() == 9891 );
  
  std::ostringstream oss;
  c2->outputType(oss);
  ASSERT_TRUE(oss.str() == "FredkinCell");

  oss.str("");  
  c2->draw(oss);
  ASSERT_TRUE(oss.str() == "+");

  delete c2;
  c2 = NULL;
  
}

TEST(Cell, clone_2) {
  Cell c( new FredkinCell(1234, '6') );

  AbstractCell *c2 = c.clone();

  ASSERT_TRUE( c2->getCoord() == 1234 );
  
  std::ostringstream oss;
  c2->outputType(oss);
  ASSERT_TRUE(oss.str() == "FredkinCell");

  oss.str("");  
  c2->draw(oss);
  ASSERT_TRUE(oss.str() == "6");

  delete c2;
  c2 = NULL;
  
}

TEST(Cell, clone_3) {
  Cell c( new FredkinCell(4337, '-') );

  AbstractCell *c2 = c.clone();

  ASSERT_TRUE( c2->getCoord() == 4337 );
  
  std::ostringstream oss;
  c2->outputType(oss);
  ASSERT_TRUE(oss.str() == "FredkinCell");

  oss.str("");  
  c2->draw(oss);
  ASSERT_TRUE(oss.str() == "-");

  delete c2;
  c2 = NULL;
  
}


TEST(Cell, clone_4) {
  Cell c( new ConwayCell(8765, '.') );

  AbstractCell *c2 = c.clone();

  ASSERT_TRUE( c2->getCoord() == 8765 );
  
  std::ostringstream oss;
  c2->outputType(oss);
  ASSERT_TRUE(oss.str() == "ConwayCell");

  oss.str("");  
  c2->draw(oss);
  ASSERT_TRUE(oss.str() == ".");

  delete c2;
  c2 = NULL;
  
}

TEST(Cell, clone_5) {
  Cell c( new ConwayCell(2121, '*') );

  AbstractCell *c2 = c.clone();

  ASSERT_TRUE( c2->getCoord() == 2121 );
  
  std::ostringstream oss;
  c2->outputType(oss);
  ASSERT_TRUE(oss.str() == "ConwayCell");

  oss.str("");  
  c2->draw(oss);
  ASSERT_TRUE(oss.str() == "*");

  delete c2;
  c2 = NULL;
  
}


// -----------------
// Cell::tallyAlive
// -----------------
TEST(Cell, tallyAlive_1) {
  Cell c( new FredkinCell(9891, '+') );

  int alive = 0;
  c.tallyAlive(alive);
  
  ASSERT_TRUE(alive == 1);
  
}

TEST(Cell, tallyAlive_2) {
  Cell c( new FredkinCell(1234, '6') );

  int alive = 0;
  c.tallyAlive(alive);
  
  ASSERT_TRUE(alive == 1);
  
}

TEST(Cell, tallyAlive_3) {
  Cell c( new FredkinCell(4337, '-') );

  int alive = 0;
  c.tallyAlive(alive);
  
  ASSERT_TRUE(alive == 0);
  
}

TEST(Cell, tallyAlive_4) {
  Cell c( new ConwayCell(8765, '.') );

  int alive = 0;
  c.tallyAlive(alive);
  
  ASSERT_TRUE(alive == 0);
  
}

TEST(Cell, tallyAlive_5) {
  Cell c( new ConwayCell(2121, '*') );

  int alive = 0;
  
  c.tallyAlive(alive);  
  ASSERT_TRUE(alive == 1);
  
  c.tallyAlive(alive);  
  ASSERT_TRUE(alive == 2);
  
}



// -----------------
// life::life
// -----------------
TEST(Life, ctor_1) {
  std::istringstream ss("1\n1\n.\n");
  Life <ConwayCell> l(ss);

}

TEST(Life, ctor_2) {
  std::istringstream ss("5\n3\n---\n-12\n+-3\n2-1\n+5+\n");
  Life <FredkinCell> l(ss);

}

TEST(Life, ctor_3) {
  std::istringstream ss("1\n7\n--+-31-\n");
  Life <Cell> l(ss);

}

// -----------------
// life::toCoord
// -----------------
TEST(Life, toCoord_1) {
  std::istringstream ss("1\n1\n.\n");
  Life <ConwayCell> l(ss);
  
  ASSERT_TRUE( l.toCoord(0, 0) == 0 );

}

TEST(Life, toCoord_2) {
  std::istringstream ss("3\n8\n..***...\n..*....*\n..**....\n");
  Life <ConwayCell> l(ss);
  
  ASSERT_TRUE( l.toCoord(2, 4) == 20 );

}

TEST(Life, toCoord_3) {
  std::istringstream ss("5\n5\n-----\n-----\n-----\n-----\n-----\n");
  Life <FredkinCell> l(ss);

  ASSERT_TRUE( l.toCoord(3, 3) == 18 );

}

TEST(Life, toCoord_4) {
  std::istringstream ss("2\n8\n-+7--34-\n-21--1-3\n");
  Life <Cell> l(ss);

  ASSERT_TRUE( l.toCoord(1, 5) == 13 );

}

// -----------------
// life::inBounds
// -----------------
TEST(Life, inBounds_1) {
  std::istringstream ss("1\n1\n.\n"); 
  Life <ConwayCell> l(ss);

  ASSERT_TRUE( l.inBounds(0, 0) );
  ASSERT_TRUE( !l.inBounds(-1, 10) );
  ASSERT_TRUE( !l.inBounds(30, 30) );

}

TEST(Life, inBounds_2) {
  std::istringstream ss("5\n5\n.....\n.....\n.....\n.....\n.....\n");
  Life <ConwayCell> l(ss);

  ASSERT_TRUE( l.inBounds(0, 0) );
  ASSERT_TRUE( l.inBounds(3, 3) );
  ASSERT_TRUE( !l.inBounds(5, 5) );
  ASSERT_TRUE( !l.inBounds(3, 10) );
  ASSERT_TRUE( !l.inBounds(30, 3) );

}

TEST(Life, inBounds_3) {
  std::istringstream ss("5\n8\n........\n........\n........\n........\n........\n");
  Life <ConwayCell> l(ss);
 
  ASSERT_TRUE( l.inBounds(0, 0) );
  ASSERT_TRUE( l.inBounds(3, 3) );
  ASSERT_TRUE( l.inBounds(4, 7) );
  ASSERT_TRUE( ! l.inBounds(30, 3) );
  ASSERT_TRUE( !l.inBounds(100, 50) );

}

// -----------------
// life::isValid
// -----------------
TEST(Life, isValid_1) {
  std::istringstream ss("1\n1\n.\n");
  Life <ConwayCell> l(ss);

  ASSERT_TRUE( l.isValid() );

}

TEST(Life, isValid_2) {
  std::istringstream ss("2\n2\n*.\n.*\n");
  Life <ConwayCell> l(ss);

  ASSERT_TRUE( l.isValid() );

}

TEST(Life, isValid_3) {
  std::istringstream ss("5\n5\n-2-5-\n----3\n-1-1-\n--+-+\n221--\n");
  Life <FredkinCell> l(ss);

  ASSERT_TRUE( l.isValid() );

}

TEST(Life, isValid_4) {
  std::istringstream ss("5\n8\n-+------\n-----9--\n-3----1-\n---22---\n-+---1--\n");
  Life <Cell> l(ss);

  ASSERT_TRUE( l.isValid() );

}

// -----------------
// life::outputBoard
// -----------------
TEST(Life, outputBoard_1) {
  std::istringstream iss("1\n1\n.\n");
  Life <ConwayCell> l(iss);

  std::ostringstream oss;
  l.outputBoard(oss);
  ASSERT_TRUE( oss.str() == "Generation = 0, Population = 0.\n.\n" );

}

TEST(Life, outputBoard_2) {
  std::istringstream iss("2\n3\n*..\n*.*\n");
  Life <ConwayCell> l(iss);

  std::ostringstream oss;
  l.outputBoard(oss);
  ASSERT_TRUE( oss.str() == "Generation = 0, Population = 3.\n*..\n*.*\n" );

}

TEST(Life, outputBoard_3) {
  std::istringstream iss("3\n3\n1+-\n-9-\n-+-\n");
  Life <FredkinCell> l(iss);

  std::ostringstream oss;
  l.outputBoard(oss);
  ASSERT_TRUE( oss.str() == "Generation = 0, Population = 4.\n1+-\n-9-\n-+-\n" );

}

TEST(Life, outputBoard_4) {
  std::istringstream iss("3\n5\n12---\n--9+-\n-33--\n");
  Life <Cell> l(iss);

  std::ostringstream oss;
  l.outputBoard(oss);
  ASSERT_TRUE( oss.str() == "Generation = 0, Population = 6.\n12---\n--9+-\n-33--\n" );

}

// -----------------
// life::getNeighbors
// -----------------
TEST(Life, getNeighbors_1) {
  std::istringstream iss("1\n1\n*\n");
  Life <ConwayCell> l(iss);
  
  bool neighbors[9];
  l.getNeighbors(0, neighbors);
  
  ASSERT_TRUE( neighbors[0] == false );
  ASSERT_TRUE( neighbors[1] == false );
  ASSERT_TRUE( neighbors[2] == false );
  ASSERT_TRUE( neighbors[3] == false );
  ASSERT_TRUE( neighbors[4] == false );
  ASSERT_TRUE( neighbors[5] == false );
  ASSERT_TRUE( neighbors[6] == false );
  ASSERT_TRUE( neighbors[7] == false );
  ASSERT_TRUE( neighbors[8] == false );
  
}

TEST(Life, getNeighbors_2) {
  std::istringstream iss("1\n3\n***\n");
  Life <ConwayCell> l(iss);
  
  bool neighbors[9];
  l.getNeighbors(1, neighbors);
  
  ASSERT_TRUE( neighbors[0] == false );
  ASSERT_TRUE( neighbors[1] == false );
  ASSERT_TRUE( neighbors[2] == false );
  ASSERT_TRUE( neighbors[3] == true );
  ASSERT_TRUE( neighbors[4] == false );
  ASSERT_TRUE( neighbors[5] == true );
  ASSERT_TRUE( neighbors[6] == false );
  ASSERT_TRUE( neighbors[7] == false );
  ASSERT_TRUE( neighbors[8] == false );
  
}

TEST(Life, getNeighbors_3) {
  std::istringstream iss("2\n3\n232\n94+\n");
  Life <FredkinCell> l(iss);

  bool neighbors[9];
  l.getNeighbors(1, neighbors);
  
  ASSERT_TRUE( neighbors[0] == false );
  ASSERT_TRUE( neighbors[1] == false );
  ASSERT_TRUE( neighbors[2] == false );
  ASSERT_TRUE( neighbors[3] == true );
  ASSERT_TRUE( neighbors[4] == false );
  ASSERT_TRUE( neighbors[5] == true );
  ASSERT_TRUE( neighbors[6] == true );
  ASSERT_TRUE( neighbors[7] == true );
  ASSERT_TRUE( neighbors[8] == true );
  
}

TEST(Life, getNeighbors_4) {
  std::istringstream iss("2\n3\n221\n919\n");
  Life <Cell> l(iss);

  bool neighbors[9];
  l.getNeighbors(3, neighbors);
  
  ASSERT_TRUE( neighbors[0] == false );
  ASSERT_TRUE( neighbors[1] == true );
  ASSERT_TRUE( neighbors[2] == true );
  ASSERT_TRUE( neighbors[3] == false );
  ASSERT_TRUE( neighbors[4] == false );
  ASSERT_TRUE( neighbors[5] == true );
  ASSERT_TRUE( neighbors[6] == false );
  ASSERT_TRUE( neighbors[7] == false );
  ASSERT_TRUE( neighbors[8] == false );
  
}

// -----------------
// life::runGeneration
// -----------------
TEST(Life, runGeneration_1) {
  std::istringstream iss("1\n1\n*\n");
  Life <ConwayCell> l(iss);
  
  std::ostringstream oss;
  l.outputBoard(oss);
  ASSERT_TRUE( oss.str() == "Generation = 0, Population = 1.\n*\n" );

  l.runGeneration();

  oss.str("");
  oss.clear();
  l.outputBoard(oss);
  ASSERT_TRUE( oss.str() == "Generation = 1, Population = 0.\n.\n" );

}

TEST(Life, runGeneration_2) {
  std::istringstream iss("1\n2\n**\n");
  Life <ConwayCell> l(iss);
  
  std::ostringstream oss;
  l.outputBoard(oss);
  ASSERT_TRUE( oss.str() == "Generation = 0, Population = 2.\n**\n" );

  l.runGeneration();

  oss.str("");
  oss.clear();
  l.outputBoard(oss);
  ASSERT_TRUE( oss.str() == "Generation = 1, Population = 0.\n..\n" );

}

TEST(Life, runGeneration_3) {
  std::istringstream iss("3\n3\n...\n***\n...\n");
  Life <ConwayCell> l(iss);
  
  std::ostringstream oss;
  l.outputBoard(oss);
  ASSERT_TRUE( oss.str() == "Generation = 0, Population = 3.\n...\n***\n...\n" );

  l.runGeneration();

  oss.str("");
  oss.clear();
  l.outputBoard(oss);
  ASSERT_TRUE( oss.str() == "Generation = 1, Population = 3.\n.*.\n.*.\n.*.\n" );

}

// -----------------
// life::outputHeader
// -----------------
TEST(Life, outputHeader_1) {
  std::istringstream iss("1\n1\n*\n");
  Life <ConwayCell> l(iss);
  
  std::ostringstream oss;
  l.outputHeader(oss);
  ASSERT_TRUE( oss.str() == "*** Life<ConwayCell> 1x1 ***\n\n" );
  
}

TEST(Life, outputHeader_2) {
  std::istringstream iss("1\n2\n**\n");
  Life <ConwayCell> l(iss);
  
  std::ostringstream oss;
  l.outputHeader(oss);
  ASSERT_TRUE( oss.str() == "*** Life<ConwayCell> 1x2 ***\n\n" );

}

TEST(Life, outputHeader_3) {
  std::istringstream iss("5\n3\n**.\n*.*\n*..\n.*.\n..*\n");
  Life <ConwayCell> l(iss);
  
  std::ostringstream oss;
  l.outputHeader(oss);
  ASSERT_TRUE( oss.str() == "*** Life<ConwayCell> 5x3 ***\n\n" );

}

TEST(Life, outputHeader_4) {
  std::istringstream iss("2\n2\n90\n14\n");
  Life <FredkinCell> l(iss);
  
  std::ostringstream oss;
  l.outputHeader(oss);
  ASSERT_TRUE( oss.str() == "*** Life<FredkinCell> 2x2 ***\n\n" );
  
}

TEST(Life, outputHeader_5) {
  std::istringstream iss("1\n2\n00\n");
  Life <FredkinCell> l(iss);
  
  std::ostringstream oss;
  l.outputHeader(oss);
  ASSERT_TRUE( oss.str() == "*** Life<FredkinCell> 1x2 ***\n\n" );

}

TEST(Life, outputHeader_6) {
  std::istringstream iss("5\n3\n12-\n34-\n7--\n-2-\n--1\n");
  Life <FredkinCell> l(iss);
  
  std::ostringstream oss;
  l.outputHeader(oss);
  ASSERT_TRUE( oss.str() == "*** Life<FredkinCell> 5x3 ***\n\n" );

}

TEST(Life, outputHeader_7) {
  std::istringstream iss("2\n2\n90\n14\n");
  Life <Cell> l(iss);
  
  std::ostringstream oss;
  l.outputHeader(oss);
  ASSERT_TRUE( oss.str() == "*** Life<Cell> 2x2 ***\n\n" );
  
}

TEST(Life, outputHeader_8) {
  std::istringstream iss("1\n2\n00\n");
  Life <Cell> l(iss);
  
  std::ostringstream oss;
  l.outputHeader(oss);
  ASSERT_TRUE( oss.str() == "*** Life<Cell> 1x2 ***\n\n" );

}

TEST(Life, outputHeader_9) {
  std::istringstream iss("5\n3\n12-\n34-\n7--\n-2-\n--1\n");
  Life <Cell> l(iss);
  
  std::ostringstream oss;
  l.outputHeader(oss);
  ASSERT_TRUE( oss.str() == "*** Life<Cell> 5x3 ***\n\n" );

}