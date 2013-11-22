// ------------------------------------
// projects/life/TestLife.c++
// Copyright (C) 2013
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

    % g++ -pedantic -std=c++0x -Wall TestLife.c++ -o TestLife -lgtest -lpthread -lgtest_main

    % valgrind TestLife > TestLife.out
*/

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream> // istringtstream, ostringstream
#include <string> 

#include "gtest/gtest.h"

// #include "ConwayCell.h"
// #include "FredkinCell.h"
#include "Life.h"

using namespace std;

// -------------
// TestLife
// -------------


 TEST(TestConwayCell, Default_Constructor1) {
   ConwayCell c = ConwayCell();
   ASSERT_TRUE(c.print() == '.');
 }
 
 TEST(TestConwayCell, Constructor1) {
   ConwayCell* c = new ConwayCell(false, 0, 0);
   ASSERT_TRUE(!c->dead());
   ASSERT_TRUE(c->print() == '*');
 }
 
 TEST(TestConwayCell, Constructor2) {
   ConwayCell* c = new ConwayCell(1, 0, 0);
   ASSERT_TRUE(c->dead());
   ASSERT_TRUE(c->print() == '.');
 }
 
 TEST(TestConwayCell, Constructor3) {
   ConwayCell* c = new ConwayCell(0, 0, 0);
   ASSERT_TRUE(!c->dead());
   ASSERT_TRUE(c->print() == '*');
 } 

 TEST(TestConwayCell, Constructor4) {
   ConwayCell* c = new ConwayCell(true, 0, 0);
   ASSERT_TRUE(c->dead());
   ASSERT_TRUE(c->print() == '.');
 }  
 
 TEST(TestConwayCell, isDead_true) {
   ConwayCell* c = new ConwayCell();
   ASSERT_TRUE(c->dead());
 }

 TEST(TestConwayCell, isDead_true2) {
   ConwayCell* c = new ConwayCell(1, 0, 0);
   ASSERT_TRUE(c->dead());
 } 

 TEST(TestConwayCell, isDead_false) {
   ConwayCell* c = new ConwayCell(false, 0, 0);
   ASSERT_TRUE(!c->dead());
 }
 
 TEST(TestConwayCell, isDead_false2) {
   ConwayCell* c = new ConwayCell(0, 0, 0);
   ASSERT_TRUE(!c->dead());
 } 
 
 TEST(TestConwayCell, print1) {
   ConwayCell* c = new ConwayCell(0, 0, 0);
   ASSERT_TRUE(!c->dead());
   ASSERT_TRUE(c->print() == '*');
 } 
 
 TEST(TestConwayCell, print2) {
   ConwayCell* c = new ConwayCell(1, 0, 0);
   ASSERT_TRUE(c->dead());
   ASSERT_TRUE(c->print() == '.');
 }
 
 TEST(TestConwayCell, print3) {
   ConwayCell* c = new ConwayCell();
   ASSERT_TRUE(c->print() == '.');
 } 

 
 
 TEST(TestConwayCell, countNeighbors_1) {
   vector<vector<AbstractCell*> > grid = vector<vector<AbstractCell*> >(3, vector<AbstractCell*>(3));
   grid[0][0] = new ConwayCell(1, 0, 0);
   grid[0][1] = new ConwayCell(1, 0, 1);
   grid[0][2] = new ConwayCell(1, 0, 2);
   grid[1][0] = new ConwayCell(1, 1, 0);
   grid[1][2] = new ConwayCell(1, 1, 2);
   grid[2][0] = new ConwayCell(1, 2, 0);
   grid[2][1] = new ConwayCell(1, 2, 1);
   grid[2][2] = new ConwayCell(1, 2, 2);
   
   ConwayCell* c = new ConwayCell(0, 1, 1);
   grid[1][1] = c;
   ASSERT_TRUE(c->countNeighbors(grid) == 0);

   // ConwayCell c = ConwayCell(0, 1, 1);
   // grid[1][1] = &c;  

;

 }

 
 
  TEST(TestConwayCell, countNeighbors_2) {
   vector<vector<AbstractCell*> > grid = vector<vector<AbstractCell*> >(3, vector<AbstractCell*>(3));
   grid[0][1] = new ConwayCell(0, 0, 1);
   grid[1][0] = new ConwayCell(0, 1, 0);
   grid[0][0] = new ConwayCell(0, 0, 0);
   ConwayCell* c = new ConwayCell(0, 1, 1);
   grid[0][2] = new ConwayCell(1, 0, 2);
   grid[1][2] = new ConwayCell(1, 1, 2);
   grid[2][0] = new ConwayCell(1, 2, 0);
   grid[2][1] = new ConwayCell(1, 2, 1);
   grid[2][2] = new ConwayCell(1, 2, 2);

   grid[1][1] = c;
   ASSERT_TRUE(c->countNeighbors(grid) == 3);
 }
 
 TEST(TestConwayCell, countNeighbors_3) {
   vector<vector<AbstractCell*> > grid = vector<vector<AbstractCell*> >(3, vector<AbstractCell*>(3));
   ConwayCell c0 = ConwayCell(0, 0, 0);
   grid[0][0] = &c0;
   ConwayCell c1 = ConwayCell(0, 0, 1);
   grid[0][1] = &c1;
   ConwayCell c2 = ConwayCell(0, 1, 0);
   grid[1][0] = &c2;
   ConwayCell c3 = ConwayCell(0, 1, 1);
   grid[1][1] = &c3;
   ConwayCell c4 = ConwayCell(0, 0, 2);
   grid[0][2] = &c4;
   ConwayCell c5 = ConwayCell(0, 1, 2);
   grid[1][2] = &c5;
   ConwayCell c6 = ConwayCell(0, 2, 0);
   grid[2][0] = &c6;
   ConwayCell c7 = ConwayCell(0, 2, 1);
   grid[2][1] = &c7;
   ConwayCell c8 = ConwayCell(0, 2, 2);
   grid[2][2] = &c8;

   ASSERT_TRUE(grid[1][1]->countNeighbors(grid) == 8);
 }
 
 TEST(TestConwayCell, countNeighbors_4) {
   vector<vector<AbstractCell*> > grid = vector<vector<AbstractCell*> >(3, vector<AbstractCell*>(3));
   grid[0][0] = new ConwayCell(0, 0, 0);
   grid[0][1] = new ConwayCell(0, 0, 1);
   grid[0][2] = new ConwayCell(1, 0, 2);
   grid[1][0] = new ConwayCell(0, 1, 0);
   grid[1][2] = new ConwayCell(1, 1, 2);
   grid[2][0] = new ConwayCell(1, 2, 0);
   grid[2][1] = new ConwayCell(0, 2, 1);
   grid[2][2] = new ConwayCell(1, 2, 2);
   
   ConwayCell* c = new ConwayCell(0, 1, 1);
   grid[1][1] = c;
   ASSERT_TRUE(c->countNeighbors(grid) == 4);
 }

 TEST(TestConwayCell, countNeighbors_6) {
   vector<vector<AbstractCell*> > grid = vector<vector<AbstractCell*> >(5, vector<AbstractCell*>(5));
   grid[0][0] = new ConwayCell(1, 0, 0);
   grid[0][1] = new ConwayCell(1, 0, 1);
   grid[0][2] = new ConwayCell(1, 0, 2);
   grid[0][3] = new ConwayCell(1, 0, 3);
   grid[0][4] = new ConwayCell(1, 0, 4);
   grid[1][0] = new ConwayCell(1, 1, 0);
   grid[1][2] = new ConwayCell(0, 1, 2);
   grid[1][3] = new ConwayCell(0, 1, 3);
   grid[1][4] = new ConwayCell(1, 1, 4);
   grid[2][0] = new ConwayCell(1, 2, 0);
   grid[2][1] = new ConwayCell(0, 2, 1);
   grid[2][3] = new ConwayCell(1, 2, 3);
   grid[2][4] = new ConwayCell(0, 2, 4);
   grid[3][0] = new ConwayCell(1, 3, 0);
   grid[3][1] = new ConwayCell(1, 3, 1);
   grid[3][2] = new ConwayCell(1, 3, 2);
   grid[3][3] = new ConwayCell(1, 3, 3);
   grid[3][4] = new ConwayCell(1, 3, 4);
   grid[4][0] = new ConwayCell(1, 4, 0);
   grid[4][1] = new ConwayCell(1, 4, 1);
   grid[4][2] = new ConwayCell(1, 4, 2);
   grid[4][3] = new ConwayCell(1, 4, 3);
   grid[4][4] = new ConwayCell(1, 4, 4);
   
   ConwayCell* c = new ConwayCell(1, 1, 1);
   ConwayCell* d = new ConwayCell(0, 2, 2);
   grid[1][1] = c;
   grid[2][2] = d;
   ASSERT_TRUE(c->countNeighbors(grid) == 3);
   ASSERT_TRUE(d->countNeighbors(grid) == 3);
 }  
 
 TEST(TestConwayCell, transform_1) {
   vector<vector<AbstractCell*> > grid = vector<vector<AbstractCell*> >(3, vector<AbstractCell*>(3));
   grid[0][0] = new ConwayCell(1, 0, 0);
   grid[0][1] = new ConwayCell(1, 0, 1);
   grid[0][2] = new ConwayCell(1, 0, 2);
   grid[1][0] = new ConwayCell(1, 1, 0);
   grid[1][2] = new ConwayCell(1, 1, 2);
   grid[2][0] = new ConwayCell(1, 2, 0);
   grid[2][1] = new ConwayCell(1, 2, 1);
   grid[2][2] = new ConwayCell(1, 2, 2);

   ConwayCell* c = new ConwayCell(0, 1, 1);
   grid[1][1] = c;
   ASSERT_TRUE(c->countNeighbors(grid) == 0);
   
   c = c->transform(false);
   ASSERT_TRUE(c->dead());
   ASSERT_TRUE(c->print() == '.');
 }
 
 TEST(TestConwayCell, transform_2) {
   vector<vector<AbstractCell*> > grid = vector<vector<AbstractCell*> >(3, vector<AbstractCell*>(3));
   grid[0][1] = new ConwayCell(0, 0, 1);
   grid[1][0] = new ConwayCell(0, 1, 0);
   grid[0][0] = new ConwayCell(0, 0, 0);
   ConwayCell* c = new ConwayCell(0, 1, 1);
   grid[0][2] = new ConwayCell(1, 0, 2);
   grid[1][2] = new ConwayCell(1, 1, 2);
   grid[2][0] = new ConwayCell(1, 2, 0);
   grid[2][1] = new ConwayCell(1, 2, 1);
   grid[2][2] = new ConwayCell(1, 2, 2);
   
   grid[1][1] = c;
   
   ASSERT_TRUE(c->countNeighbors(grid) == 3);
   
   c = c->transform(false);
   
   ASSERT_TRUE(!c->dead());   
   ASSERT_TRUE(c->print() == '*');
 }
 
 TEST(TestConwayCell, transform_3) {
   vector<vector<AbstractCell*> > grid = vector<vector<AbstractCell*> >(3, vector<AbstractCell*>(3));
   grid[0][0] = new ConwayCell(0, 0, 0);
   grid[0][1] = new ConwayCell(0, 0, 1);
   grid[0][2] = new ConwayCell(0, 0, 2);
   grid[1][0] = new ConwayCell(0, 1, 0);
   grid[1][2] = new ConwayCell(0, 1, 2);
   grid[2][0] = new ConwayCell(0, 2, 0);
   grid[2][1] = new ConwayCell(0, 2, 1);
   grid[2][2] = new ConwayCell(0, 2, 2);
   
   ConwayCell* c = new ConwayCell(0, 1, 1);
   grid[1][1] = c;
   ASSERT_TRUE(c->countNeighbors(grid) == 8);
   
   c = c->transform(false);
   ASSERT_TRUE(c->dead());
   ASSERT_TRUE(c->print() == '.');
 }
 
 TEST(TestConwayCell, transform_4) {
   vector<vector<AbstractCell*> > grid = vector<vector<AbstractCell*> >(3, vector<AbstractCell*>(3));
   grid[0][0] = new ConwayCell(0, 0, 0);
   grid[0][1] = new ConwayCell(0, 0, 1);
   grid[0][2] = new ConwayCell(1, 0, 2);
   grid[1][0] = new ConwayCell(0, 1, 0);
   grid[1][2] = new ConwayCell(1, 1, 2);
   grid[2][0] = new ConwayCell(1, 2, 0);
   grid[2][1] = new ConwayCell(0, 2, 1);
   grid[2][2] = new ConwayCell(1, 2, 2);
   
   ConwayCell* c = new ConwayCell(0, 1, 1);
   grid[1][1] = c;
   ASSERT_TRUE(c->countNeighbors(grid) == 4);
   
   c = c->transform(false);
   ASSERT_TRUE(c->dead());
   ASSERT_TRUE(c->print() == '.');
 }
 
 TEST(TestConwayCell, transform_6) {
   vector<vector<AbstractCell*> > grid = vector<vector<AbstractCell*> >(5, vector<AbstractCell*>(5));
   grid[0][0] = new ConwayCell(1, 0, 0);
   grid[0][1] = new ConwayCell(1, 0, 1);
   grid[0][2] = new ConwayCell(1, 0, 2);
   grid[0][3] = new ConwayCell(1, 0, 3);
   grid[0][4] = new ConwayCell(1, 0, 4);
   grid[1][0] = new ConwayCell(1, 1, 0);
   grid[1][2] = new ConwayCell(0, 1, 2);
   grid[1][3] = new ConwayCell(0, 1, 3);
   grid[1][4] = new ConwayCell(1, 1, 4);
   grid[2][0] = new ConwayCell(1, 2, 0);
   grid[2][1] = new ConwayCell(0, 2, 1);
   grid[2][3] = new ConwayCell(1, 2, 3);
   grid[2][4] = new ConwayCell(0, 2, 4);
   grid[3][0] = new ConwayCell(1, 3, 0);
   grid[3][1] = new ConwayCell(1, 3, 1);
   grid[3][2] = new ConwayCell(1, 3, 2);
   grid[3][3] = new ConwayCell(1, 3, 3);
   grid[3][4] = new ConwayCell(1, 3, 4);
   grid[4][0] = new ConwayCell(1, 4, 0);
   grid[4][1] = new ConwayCell(1, 4, 1);
   grid[4][2] = new ConwayCell(1, 4, 2);
   grid[4][3] = new ConwayCell(1, 4, 3);
   grid[4][4] = new ConwayCell(1, 4, 4);
   
   ConwayCell* c = new ConwayCell(1, 1, 1);
   ConwayCell* d = new ConwayCell(0, 2, 2);
   grid[1][1] = c;
   grid[2][2] = d;
   ASSERT_TRUE(c->countNeighbors(grid) == 3);
   ASSERT_TRUE(d->countNeighbors(grid) == 3);
   
   c = c->transform(false);
   d = d->transform(false);
   
   ASSERT_TRUE(c->print() == '*');
   ASSERT_TRUE(d->print() == '*');
 } 
 
 
 TEST(TestFredkinCell, Default_Constructor1) {
  FredkinCell* c = new FredkinCell();
  ASSERT_TRUE(c->neighbors == 0);
  ASSERT_TRUE(c->row == -1);
  ASSERT_TRUE(c->column == -1);
 }

 TEST(TestFredkinCell, Default_Constructor2) {
  FredkinCell* c = new FredkinCell();
  ASSERT_TRUE(c->isDead == true);
  ASSERT_TRUE(c->isPhoenix == false);
  // ASSERT_TRUE(c->age == -1);
 }

  TEST(TestFredkinCell, Constructor1) {
   FredkinCell* c = new FredkinCell(0, 0, 0);
   // ASSERT_TRUE(c->age == 0);
   ASSERT_TRUE(c->row == 0);
   ASSERT_TRUE(c->column == 0);
 }
 
 TEST(TestFredkinCell, Constructor2) {
   FredkinCell* c = new FredkinCell(1, 2, 5);
   // ASSERT_TRUE(c->age == 1);
   ASSERT_TRUE(c->row == 2);
   ASSERT_TRUE(c->column == 5);
 }

  TEST(TestFredkinCell, Constructor3) {
   FredkinCell* c = new FredkinCell(10, 9, 8);
   // ASSERT_TRUE(c->age == 10);
   ASSERT_TRUE(c->row == 9);
   ASSERT_TRUE(c->column == 8);
 }

 TEST(TestFredkinCell, print1) {
  FredkinCell* c = new FredkinCell();
  ASSERT_TRUE(c->print() == '-');
 }

  TEST(TestFredkinCell, print2) {
  FredkinCell* c = new FredkinCell(0, 0, 0);
  ASSERT_TRUE(c->print() == '0');
 }

  TEST(TestFredkinCell, print3) {
  FredkinCell* c = new FredkinCell(10, 0, 0);
  ASSERT_TRUE(c->print() == '+');
 }
 
 TEST(TestFredkinCell, isDead_true) {
  FredkinCell* c = new FredkinCell();
  ASSERT_TRUE(c->print() == '-');
 }

 TEST(TestFredkinCell, isDead_false) {
   FredkinCell* c = new FredkinCell(0, 0, 0);
   ASSERT_TRUE(!c->dead());
 }


 TEST(TestFredkinCell, countNeighbors_1) {
   vector<vector<AbstractCell*> > grid = vector<vector<AbstractCell*> >(3, vector<AbstractCell*>(3));
   grid[0][0] = new FredkinCell(-1, 0, 0);
   grid[0][1] = new FredkinCell(0, 0, 1);
   grid[0][2] = new FredkinCell(-1, 0, 2);
   grid[1][0] = new FredkinCell(0, 1, 0);
   grid[1][2] = new FredkinCell(-1, 1, 2);
   grid[2][0] = new FredkinCell(-1, 2, 0);
   grid[2][1] = new FredkinCell(-1, 2, 1);
   grid[2][2] = new FredkinCell(-1, 2, 2);

   FredkinCell* c = new FredkinCell(0, 1, 1);
   grid[1][1] = c;
   ASSERT_TRUE(c->countNeighbors(grid) == 2);
   ASSERT_TRUE(c->print() == '0');
 }

  TEST(TestFredkinCell, countNeighbors_2) {
   vector<vector<AbstractCell*> > grid = vector<vector<AbstractCell*> >(3, vector<AbstractCell*>(3));

   grid[0][0] = new FredkinCell(-1, 0, 0);
   grid[0][1] = new FredkinCell(-1, 0, 1);
   grid[1][0] = new FredkinCell(-1, 1, 0);
   FredkinCell* c = new FredkinCell(-1, 1, 1);
   grid[1][1] = c;
   grid[0][2] = new FredkinCell(-1, 0, 2);
   grid[1][2] = new FredkinCell(-1, 1, 2);
   grid[2][0] = new FredkinCell(-1, 2, 0);
   grid[2][1] = new FredkinCell(-1, 2, 1);
   grid[2][2] = new FredkinCell(-1, 2, 2);

   ASSERT_TRUE(c->countNeighbors(grid) == 0);
   ASSERT_TRUE(c->print() == '-');
 }

  TEST(TestFredkinCell, countNeighbors_3) {
   vector<vector<AbstractCell*> > grid = vector<vector<AbstractCell*> >(3, vector<AbstractCell*>(3));

   grid[0][0] = new FredkinCell(0, 0, 0);
   grid[0][1] = new FredkinCell(-1, 0, 1);
   grid[1][0] = new FredkinCell(-1, 1, 0);
   FredkinCell* c = new FredkinCell(0, 1, 1);
   grid[1][1] = c;
   grid[0][2] = new FredkinCell(0, 0, 2);
   grid[1][2] = new FredkinCell(-1, 1, 2);
   grid[2][0] = new FredkinCell(0, 2, 0);
   grid[2][1] = new FredkinCell(-1, 2, 1);
   grid[2][2] = new FredkinCell(0, 2, 2);

   ASSERT_TRUE(c->countNeighbors(grid) == 0);
   ASSERT_TRUE(c->print() == '0');
 }

  TEST(TestFredkinCell, transform_1) {
   vector<vector<AbstractCell*> > grid = vector<vector<AbstractCell*> >(3, vector<AbstractCell*>(3));

   grid[0][0] = new FredkinCell(0, 0, 0);
   grid[0][1] = new FredkinCell(0, 0, 1);
   grid[1][0] = new FredkinCell(0, 1, 0);
   FredkinCell* c = new FredkinCell(0, 1, 1);
   grid[1][1] = c;
   grid[0][2] = new FredkinCell(0, 0, 2);
   grid[1][2] = new FredkinCell(0, 1, 2);
   grid[2][0] = new FredkinCell(0, 2, 0);
   grid[2][1] = new FredkinCell(0, 2, 1);
   grid[2][2] = new FredkinCell(0, 2, 2);

   ASSERT_TRUE(c->countNeighbors(grid) == 4);
   ASSERT_TRUE(c->print() == '0');

   grid[1][1] = c->transform(false);

   ASSERT_TRUE(grid[1][1]->dead());
 }

 TEST(TestFredkinCell, transform_2) {
   vector<vector<AbstractCell*> > grid = vector<vector<AbstractCell*> >(3, vector<AbstractCell*>(3));

   grid[0][0] = new FredkinCell(-1, 0, 0);
   grid[0][1] = new FredkinCell(-1, 0, 1);
   grid[1][0] = new FredkinCell(-1, 1, 0);
   FredkinCell* c = new FredkinCell(0, 1, 1);
   grid[1][1] = c;
   grid[0][2] = new FredkinCell(-1, 0, 2);
   grid[1][2] = new FredkinCell(0, 1, 2);
   grid[2][0] = new FredkinCell(-1, 2, 0);
   grid[2][1] = new FredkinCell(-1, 2, 1);
   grid[2][2] = new FredkinCell(-1, 2, 2);

   ASSERT_TRUE(c->countNeighbors(grid) == 1);
   ASSERT_TRUE(c->print() == '0');

   grid[1][1] = c->transform(false);
   // c = grid[1][1];

   ASSERT_TRUE(grid[1][1]->countNeighbors(grid) == 1);
   ASSERT_TRUE(grid[1][1]->print() == '1');
 }

  TEST(TestFredkinCell, transform_3) {
   vector<vector<AbstractCell*> > grid = vector<vector<AbstractCell*> >(3, vector<AbstractCell*>(3));

   grid[0][0] = new FredkinCell(0, 0, 0);
   grid[0][1] = new FredkinCell(-1, 0, 1);
   grid[1][0] = new FredkinCell(0, 1, 0);
   FredkinCell* c = new FredkinCell(0, 1, 1);
   grid[1][1] = c;
   grid[0][2] = new FredkinCell(0, 0, 2);
   grid[1][2] = new FredkinCell(0, 1, 2);
   grid[2][0] = new FredkinCell(0, 2, 0);
   grid[2][1] = new FredkinCell(0, 2, 1);
   grid[2][2] = new FredkinCell(0, 2, 2);

   ASSERT_TRUE(c->countNeighbors(grid) == 3);
   ASSERT_TRUE(c->print() == '0');

   grid[1][1] = c->transform(false);

   grid[1][1]->countNeighbors(grid);
   grid[1][1] = grid[1][1]->transform(false);

   ASSERT_TRUE(((grid[1][1])->print()) == '2');

 }


  TEST(TestFredkinCell, transform_4) {
   vector<vector<AbstractCell*> > grid = vector<vector<AbstractCell*> >(3, vector<AbstractCell*>(3));

   grid[0][0] = new FredkinCell(0, 0, 0);
   grid[0][1] = new FredkinCell(-1, 0, 1);
   grid[1][0] = new FredkinCell(0, 1, 0);
   FredkinCell* c = new FredkinCell(0, 1, 1);
   grid[1][1] = c;
   grid[0][2] = new FredkinCell(0, 0, 2);
   grid[1][2] = new FredkinCell(0, 1, 2);
   grid[2][0] = new FredkinCell(0, 2, 0);
   grid[2][1] = new FredkinCell(0, 2, 1);
   grid[2][2] = new FredkinCell(0, 2, 2);

   ASSERT_TRUE(c->countNeighbors(grid) == 3);
   ASSERT_TRUE(c->print() == '0');

   grid[1][1] =  c->transform(false);
   ASSERT_TRUE(grid[1][1]->print() == '1');

   grid[0][1]->isDead = false;

   grid[1][1]->countNeighbors(grid);
   grid[1][1] = grid[1][1]->transform(false);
   ASSERT_TRUE(grid[1][1]->print() == '-');

   grid[0][1]->isDead = true;

   grid[1][1]->countNeighbors(grid);
   grid[1][1] = grid[1][1]->transform(false);
   ASSERT_TRUE(grid[1][1]->print() == '1');
 }

   TEST(TestFredkinCell, oldFredkinCell_1) {
   vector<vector<AbstractCell*> > grid = vector<vector<AbstractCell*> >(3, vector<AbstractCell*>(3));

   grid[0][0] = new FredkinCell(0, 0, 0);
   grid[0][1] = new FredkinCell(-1, 0, 1);
   grid[1][0] = new FredkinCell(0, 1, 0);
   FredkinCell* c = new FredkinCell(0, 1, 1);
   grid[1][1] = c;
   grid[0][2] = new FredkinCell(0, 0, 2);
   grid[1][2] = new FredkinCell(0, 1, 2);
   grid[2][0] = new FredkinCell(0, 2, 0);
   grid[2][1] = new FredkinCell(0, 2, 1);
   grid[2][2] = new FredkinCell(0, 2, 2);

   ASSERT_TRUE(c->countNeighbors(grid) == 3);
   ASSERT_TRUE(c->print() == '0');

   grid[1][1] =  c->transform(false);
   ASSERT_TRUE(grid[1][1]->print() == '1');

   grid[1][1]->countNeighbors(grid);
   grid[1][1] = grid[1][1]->transform(false);
   grid[1][1] = grid[1][1]->transform(false);
   grid[1][1] = grid[1][1]->transform(false);
   grid[1][1] = grid[1][1]->transform(false);
   grid[1][1] = grid[1][1]->transform(false);
   grid[1][1] = grid[1][1]->transform(false);
   grid[1][1] = grid[1][1]->transform(false);
   grid[1][1] = grid[1][1]->transform(false);
   ASSERT_TRUE(grid[1][1]->print() == '9');
 }

   TEST(TestFredkinCell, oldFredkinCell_2) {
   vector<vector<AbstractCell*> > grid = vector<vector<AbstractCell*> >(3, vector<AbstractCell*>(3));

   grid[0][0] = new FredkinCell(0, 0, 0);
   grid[0][1] = new FredkinCell(-1, 0, 1);
   grid[1][0] = new FredkinCell(0, 1, 0);
   FredkinCell* c = new FredkinCell(0, 1, 1);
   grid[1][1] = c;
   grid[0][2] = new FredkinCell(0, 0, 2);
   grid[1][2] = new FredkinCell(0, 1, 2);
   grid[2][0] = new FredkinCell(0, 2, 0);
   grid[2][1] = new FredkinCell(0, 2, 1);
   grid[2][2] = new FredkinCell(0, 2, 2);

   ASSERT_TRUE(c->countNeighbors(grid) == 3);
   ASSERT_TRUE(c->print() == '0');

   grid[1][1] =  c->transform(false);
   ASSERT_TRUE(grid[1][1]->print() == '1');

   grid[1][1]->countNeighbors(grid);
   grid[1][1] = grid[1][1]->transform(false);
   grid[1][1] = grid[1][1]->transform(false);
   grid[1][1] = grid[1][1]->transform(false);
   grid[1][1] = grid[1][1]->transform(false);
   grid[1][1] = grid[1][1]->transform(false);
   grid[1][1] = grid[1][1]->transform(false);
   grid[1][1] = grid[1][1]->transform(false);
   grid[1][1] = grid[1][1]->transform(false);
   grid[1][1] = grid[1][1]->transform(false);
   ASSERT_TRUE(grid[1][1]->print() == '+');
 }

    TEST(TestFredkinCell, oldFredkinCell_3) {
   vector<vector<AbstractCell*> > grid = vector<vector<AbstractCell*> >(3, vector<AbstractCell*>(3));

   grid[0][0] = new FredkinCell(0, 0, 0);
   grid[0][1] = new FredkinCell(-1, 0, 1);
   grid[1][0] = new FredkinCell(0, 1, 0);
   FredkinCell* c = new FredkinCell(0, 1, 1);
   grid[1][1] = c;
   grid[0][2] = new FredkinCell(0, 0, 2);
   grid[1][2] = new FredkinCell(0, 1, 2);
   grid[2][0] = new FredkinCell(0, 2, 0);
   grid[2][1] = new FredkinCell(0, 2, 1);
   grid[2][2] = new FredkinCell(0, 2, 2);

   ASSERT_TRUE(c->countNeighbors(grid) == 3);
   ASSERT_TRUE(c->print() == '0');

   grid[1][1] =  c->transform(false);
   ASSERT_TRUE(grid[1][1]->print() == '1');

   grid[1][1]->countNeighbors(grid);
   grid[1][1] = grid[1][1]->transform(false);
   grid[1][1] = grid[1][1]->transform(false);
   grid[1][1] = grid[1][1]->transform(false);
   grid[1][1] = grid[1][1]->transform(false);
   grid[1][1] = grid[1][1]->transform(false);
   grid[1][1] = grid[1][1]->transform(false);
   grid[1][1] = grid[1][1]->transform(false);
   grid[1][1] = grid[1][1]->transform(false);
   grid[1][1] = grid[1][1]->transform(false);
   grid[1][1] = grid[1][1]->transform(false);
   grid[1][1] = grid[1][1]->transform(false);
   grid[1][1] = grid[1][1]->transform(false);
   grid[1][1] = grid[1][1]->transform(false);
   grid[1][1] = grid[1][1]->transform(false);
   grid[1][1] = grid[1][1]->transform(false);
   grid[1][1] = grid[1][1]->transform(false);
   grid[1][1] = grid[1][1]->transform(false);
   grid[1][1] = grid[1][1]->transform(false);
   ASSERT_TRUE(grid[1][1]->print() == '+');
 }

    TEST(TestFredkinCell, resumeFredkinCell_1) {
   vector<vector<AbstractCell*> > grid = vector<vector<AbstractCell*> >(3, vector<AbstractCell*>(3));

   grid[0][0] = new FredkinCell(0, 0, 0);
   grid[0][1] = new FredkinCell(-1, 0, 1);
   grid[1][0] = new FredkinCell(0, 1, 0);
   FredkinCell* c = new FredkinCell(0, 1, 1);
   grid[1][1] = c;
   grid[0][2] = new FredkinCell(0, 0, 2);
   grid[1][2] = new FredkinCell(0, 1, 2);
   grid[2][0] = new FredkinCell(0, 2, 0);
   grid[2][1] = new FredkinCell(0, 2, 1);
   grid[2][2] = new FredkinCell(0, 2, 2);

   ASSERT_TRUE(c->countNeighbors(grid) == 3);
   ASSERT_TRUE(c->print() == '0');

   grid[1][1] =  c->transform(false);
   ASSERT_TRUE(grid[1][1]->print() == '1');


   grid[1][1]->countNeighbors(grid);
   grid[1][1] = grid[1][1]->transform(false);
   grid[1][1] = grid[1][1]->transform(false);
   grid[1][1] = grid[1][1]->transform(false);
   grid[1][1] = grid[1][1]->transform(false);
   grid[1][1] = grid[1][1]->transform(false);
   grid[1][1] = grid[1][1]->transform(false);
   grid[1][1] = grid[1][1]->transform(false);
   grid[1][1] = grid[1][1]->transform(false);
   
   ASSERT_TRUE(grid[1][1]->print() == '9');
   
   grid[0][1]->isDead = false;

   grid[1][1]->countNeighbors(grid);
   grid[1][1] = grid[1][1]->transform(false);
   ASSERT_TRUE(grid[1][1]->print() == '-');

   grid[0][1]->isDead = true;

   grid[1][1]->countNeighbors(grid);
   grid[1][1] = grid[1][1]->transform(false);
   ASSERT_TRUE(grid[1][1]->print() == '9');
 }

    TEST(TestFredkinCell, resumeFredkinCell_2) {
   vector<vector<AbstractCell*> > grid = vector<vector<AbstractCell*> >(3, vector<AbstractCell*>(3));

   grid[0][0] = new FredkinCell(0, 0, 0);
   grid[0][1] = new FredkinCell(-1, 0, 1);
   grid[1][0] = new FredkinCell(0, 1, 0);
   FredkinCell* c = new FredkinCell(0, 1, 1);
   grid[1][1] = c;
   grid[0][2] = new FredkinCell(0, 0, 2);
   grid[1][2] = new FredkinCell(0, 1, 2);
   grid[2][0] = new FredkinCell(0, 2, 0);
   grid[2][1] = new FredkinCell(0, 2, 1);
   grid[2][2] = new FredkinCell(0, 2, 2);

   ASSERT_TRUE(c->countNeighbors(grid) == 3);
   ASSERT_TRUE(c->print() == '0');

   grid[1][1] =  c->transform(false);
   ASSERT_TRUE(grid[1][1]->print() == '1');


   grid[1][1]->countNeighbors(grid);
   grid[1][1] = grid[1][1]->transform(false);
   grid[1][1] = grid[1][1]->transform(false);
   grid[1][1] = grid[1][1]->transform(false);
   grid[1][1] = grid[1][1]->transform(false);
   grid[1][1] = grid[1][1]->transform(false);
   grid[1][1] = grid[1][1]->transform(false);
   grid[1][1] = grid[1][1]->transform(false);
   grid[1][1] = grid[1][1]->transform(false);
   grid[1][1] = grid[1][1]->transform(false);

   ASSERT_TRUE(grid[1][1]->print() == '+');
   
   grid[0][1]->isDead = false;

   grid[1][1]->countNeighbors(grid);
   grid[1][1] = grid[1][1]->transform(false);
   ASSERT_TRUE(grid[1][1]->print() == '-');

   grid[0][1]->isDead = true;

   grid[1][1]->countNeighbors(grid);
   grid[1][1] = grid[1][1]->transform(false);
   ASSERT_TRUE(grid[1][1]->print() == '+');
 }

  TEST(TestLife, Constructor_Conway1) {
    istringstream r("1\n1\n.\n");
    ostringstream w;
    Life<ConwayCell> life;

    life.read(r);
    life.printGrid(w);

    ASSERT_TRUE(w.str() == "\nGeneration = 0, Population = 0.\n.\n");
 }
   TEST(TestLife, Constructor_Conway2) {
    istringstream r("1\n1\n*\n");
    ostringstream w;
  
    Life<ConwayCell> life;

    life.read(r);
    life.printGrid(w);

    ASSERT_TRUE(w.str() == "\nGeneration = 0, Population = 1.\n*\n");
 }

  TEST(TestLife, Constructor_Fredkin1) {
    istringstream r("1\n1\n-\n");

    ostringstream w;
    Life<FredkinCell> life;

    life.read(r);
    life.printGrid(w);

    ASSERT_TRUE(w.str() == "\nGeneration = 0, Population = 0.\n-\n");
 }

   TEST(TestLife, Constructor_Fredkin2) {
    istringstream r("1\n1\n0\n");

    ostringstream w;
    Life<FredkinCell> life;

    life.read(r);
    life.printGrid(w);

    ASSERT_TRUE(w.str() == "\nGeneration = 0, Population = 1.\n0\n");
 }
 
 TEST(TestLife, Constructor_CellConway1) {
    istringstream r("1\n1\n.\n");

    ostringstream w;
    
    Life<Cell> life;

    life.read(r);
    life.printGrid(w);

    ASSERT_TRUE(w.str() == "\nGeneration = 0, Population = 0.\n.\n");
 }

  TEST(TestLife, Constructor_CellConway2) {
    istringstream r("1\n1\n*\n");

    ostringstream w;
    
    Life<Cell> life;

    life.read(r);
    life.printGrid(w);

    ASSERT_TRUE(w.str() == "\nGeneration = 0, Population = 1.\n*\n");
 }
 
 TEST(TestLife, Constructor_CellFredkin1) {
    istringstream r("1\n1\n-\n");

    ostringstream w;
    
    Life<Cell> life;

    life.read(r);
    life.printGrid(w);

    ASSERT_TRUE(w.str() == "\nGeneration = 0, Population = 0.\n-\n");
 }

  TEST(TestLife, Constructor_CellFredkin2) {
    istringstream r("1\n1\n0\n");

    ostringstream w;
    
    Life<Cell> life;

    life.read(r);
    life.printGrid(w);

    ASSERT_TRUE(w.str() == "\nGeneration = 0, Population = 1.\n0\n");
 }
 
 TEST(TestLife, Constructor_CellBoth1) {
    istringstream r("1\n2\n.-\n");

    ostringstream w;
    
    Life<Cell> life;

    life.read(r);
    life.printGrid(w);

    ASSERT_TRUE(w.str() == "\nGeneration = 0, Population = 0.\n.-\n");
 } 

 TEST(TestLife, Constructor_CellBoth2) {
    istringstream r("1\n2\n*0\n");

    ostringstream w;
    
    Life<Cell> life;

    life.read(r);
    life.printGrid(w);

    ASSERT_TRUE(w.str() == "\nGeneration = 0, Population = 2.\n*0\n");
 }

  TEST(TestLife, ConwaycalcNeighbors1) {
    istringstream r("1\n1\n.\n");

    ostringstream w;
    
    Life<ConwayCell> life;

    life.read(r);
    life.nextGen();

    life.printGrid(w);

    ASSERT_TRUE(w.str() == "\nGeneration = 1, Population = 0.\n.\n");
 }

   TEST(TestLife, ConwaycalcNeighbors2) {
    istringstream r("3\n1\n.\n.\n.\n");

    ostringstream w;
    
    Life<ConwayCell> life;

    life.read(r);
    life.nextGen();

    life.printGrid(w);

    ASSERT_TRUE(w.str() == "\nGeneration = 1, Population = 0.\n.\n.\n.\n");
 }

   TEST(TestLife, ConwaycalcNeighbors3) {
    istringstream r("1\n3\n...\n");

    ostringstream w;
    
    Life<ConwayCell> life;

    life.read(r);
    life.nextGen();

    life.printGrid(w);

    ASSERT_TRUE(w.str() == "\nGeneration = 1, Population = 0.\n...\n");
 }

   TEST(TestLife, ConwaycalcNeighbors4) {
    istringstream r("3\n3\n*..\n...\n...\n");

    ostringstream w;
    
    Life<ConwayCell> life;

    life.read(r);
    life.nextGen();

    life.printGrid(w);

    ASSERT_TRUE(w.str() == "\nGeneration = 1, Population = 0.\n...\n...\n...\n");
 }

   TEST(TestLife, FredkincalcNeighbors1) {
    istringstream r("1\n1\n-\n");

    ostringstream w;
    
    Life<FredkinCell> life;

    life.read(r);
    life.nextGen();

    life.printGrid(w);

    ASSERT_TRUE(w.str() == "\nGeneration = 1, Population = 0.\n-\n");
 }

    TEST(TestLife, FredkincalcNeighbors2) {
    istringstream r("3\n1\n-\n-\n-\n");

    ostringstream w;
    
    Life<FredkinCell> life;

    life.read(r);
    life.nextGen();

    life.printGrid(w);

    ASSERT_TRUE(w.str() == "\nGeneration = 1, Population = 0.\n-\n-\n-\n");
 }

   TEST(TestLife, FredkincalcNeighbors3) {
    istringstream r("1\n3\n---\n");

    ostringstream w;
    
    Life<FredkinCell> life;

    life.read(r);
    life.nextGen();

    life.printGrid(w);

    ASSERT_TRUE(w.str() == "\nGeneration = 1, Population = 0.\n---\n");
 }

   TEST(TestLife, FredkincalcNeighbors4) {
    istringstream r("3\n3\n0--\n---\n---\n");

    ostringstream w;
    
    Life<FredkinCell> life;

    life.read(r);
    life.nextGen();

    life.printGrid(w);

    ASSERT_TRUE(w.str() == "\nGeneration = 1, Population = 2.\n-0-\n0--\n---\n");
 }

   TEST(TestLife, CellcalcNeighbors1_1) {
    istringstream r("1\n1\n.\n");

    ostringstream w;
    
    Life<Cell> life;

    life.read(r);
    life.nextGen();

    life.printGrid(w);

    ASSERT_TRUE(w.str() == "\nGeneration = 1, Population = 0.\n.\n");
 }

    TEST(TestLife, CellcalcNeighbors1_2) {
    istringstream r("3\n1\n.\n.\n.\n");

    ostringstream w;
    
    Life<Cell> life;

    life.read(r);
    life.nextGen();

    life.printGrid(w);

    ASSERT_TRUE(w.str() == "\nGeneration = 1, Population = 0.\n.\n.\n.\n");
 }

   TEST(TestLife, CellcalcNeighbors1_3) {
    istringstream r("1\n3\n...\n");

    ostringstream w;
    
    Life<Cell> life;

    life.read(r);
    life.nextGen();

    life.printGrid(w);

    ASSERT_TRUE(w.str() == "\nGeneration = 1, Population = 0.\n...\n");
 }

   TEST(TestLife, CellcalcNeighbors1_4) {
    istringstream r("3\n3\n*..\n...\n...\n");

    ostringstream w;
    
    Life<Cell> life;

    life.read(r);
    life.nextGen();

    life.printGrid(w);

    ASSERT_TRUE(w.str() == "\nGeneration = 1, Population = 0.\n...\n...\n...\n");
 }

    TEST(TestLife, CellcalcNeighbors2_1) {
    istringstream r("1\n1\n-\n");

    ostringstream w;
    
    Life<Cell> life;

    life.read(r);
    life.nextGen();

    life.printGrid(w);

    ASSERT_TRUE(w.str() == "\nGeneration = 1, Population = 0.\n-\n");
 }

    TEST(TestLife, CellcalcNeighbors2_2) {
    istringstream r("3\n1\n-\n-\n-\n");

    ostringstream w;
    
    Life<Cell> life;

    life.read(r);
    life.nextGen();

    life.printGrid(w);

    ASSERT_TRUE(w.str() == "\nGeneration = 1, Population = 0.\n-\n-\n-\n");
 }

   TEST(TestLife, CellcalcNeighbors2_3) {
    istringstream r("1\n3\n---\n");

    ostringstream w;
    
    Life<Cell> life;

    life.read(r);
    life.nextGen();

    life.printGrid(w);

    ASSERT_TRUE(w.str() == "\nGeneration = 1, Population = 0.\n---\n");
 }

   TEST(TestLife, CellcalcNeighbors2_4) {
    istringstream r("3\n3\n0--\n---\n---\n");

    ostringstream w;
    
    Life<Cell> life;

    life.read(r);
    life.nextGen();

    life.printGrid(w);

    ASSERT_TRUE(w.str() == "\nGeneration = 1, Population = 2.\n-0-\n0--\n---\n");
 }
 
 TEST(TestLife, nextGen_Con_1) {
    istringstream r("3\n3\n.*.\n...\n...\n");

    ostringstream w;
    
    Life<ConwayCell> life;

    life.read(r);
    life.nextGen();

    life.printGrid(w);

    ASSERT_TRUE(w.str() == "\nGeneration = 1, Population = 0.\n...\n...\n...\n");
 }
 
 TEST(TestLife, nextGen_Con_2) { 
    istringstream r("3\n3\n.*.\n.**\n.*.\n");

    ostringstream w;
    
    Life<ConwayCell> life;

    life.read(r);
    life.nextGen();

    life.printGrid(w);

    ASSERT_TRUE(w.str() == "\nGeneration = 1, Population = 7.\n.**\n***\n.**\n");
 } 
 
 TEST(TestLife, nextGen_Con_3) {
    istringstream r("3\n3\n***\n***\n***\n");

    ostringstream w;
     
    Life<ConwayCell> life;

    life.read(r);
    life.nextGen();

    life.printGrid(w);

    ASSERT_TRUE(w.str() == "\nGeneration = 1, Population = 4.\n*.*\n...\n*.*\n");
 }

  TEST(TestLife, nextGen_Con_4) {
    istringstream r("3\n3\n...\n***\n...\n");

    ostringstream w;
     
    Life<ConwayCell> life;

    life.read(r);
    life.nextGen();

    life.printGrid(w);

    ASSERT_TRUE(w.str() == "\nGeneration = 1, Population = 3.\n.*.\n.*.\n.*.\n");
 }


  TEST(TestLife, nextGen_Con_5) {
    istringstream r("3\n3\n.*.\n.*.\n.*.\n");

    ostringstream w;
     
    Life<ConwayCell> life;

    life.read(r);
    life.nextGen();

    life.printGrid(w);

    ASSERT_TRUE(w.str() == "\nGeneration = 1, Population = 3.\n...\n***\n...\n");
 }
 
 TEST(TestLife, nextGen_Fred_1) {
    istringstream r("3\n3\n-0-\n---\n---\n");

    ostringstream w;
    ostringstream x;
    Life<FredkinCell> life;
    
    

    life.read(r);

    life.printGrid(x);

    life.nextGen();

    life.printGrid(w);

    ASSERT_TRUE(w.str() == "\nGeneration = 1, Population = 3.\n0-0\n-0-\n---\n");
 }

 TEST(TestLife, nextGen_Fred_2) {
    istringstream r("3\n3\n-0-\n-00\n--0\n");

    ostringstream w;
    ostringstream x;
    Life<FredkinCell> life;

    life.read(r);
    life.printGrid(x);

    life.nextGen();

    life.printGrid(w);

    ASSERT_TRUE(w.str() == "\nGeneration = 1, Population = 4.\n01-\n0--\n--1\n");
 }
 
 TEST(TestLife, nextGen_Fred_3) {
    istringstream r("3\n3\n000\n000\n000\n");

    ostringstream w;
    
    Life<FredkinCell> life;

    life.read(r);
    life.nextGen();

    life.printGrid(w);

    ASSERT_TRUE(w.str() == "\nGeneration = 1, Population = 4.\n-1-\n1-1\n-1-\n");
 }

  TEST(TestLife, nextGen_Fred_4) {
    istringstream r("3\n3\n---\n---\n0-0\n");

    ostringstream w;
    ostringstream x;
    Life<Cell> life;

    life.read(r);

    
    life.nextGen();
    life.nextGen();

    life.printGrid(w);

    ASSERT_TRUE(w.str() == "\nGeneration = 2, Population = 4.\n0-0\n---\n0-0\n");

    life.nextGen();
    life.printGrid(x);


    ASSERT_TRUE(x.str() == "\nGeneration = 3, Population = 0.\n---\n---\n---\n");
 }
 
   TEST(TestLife, nextGen_Fred_5) {
    istringstream r("3\n3\n---\n---\n0--\n");

    ostringstream w;
    ostringstream x;
    Life<Cell> life;

    life.read(r);

    
    life.nextGen();
    life.nextGen();
    life.nextGen();
    life.nextGen();
    life.nextGen();

    life.printGrid(w);


    ASSERT_TRUE(w.str() == "\nGeneration = 5, Population = 0.\n---\n---\n---\n");
 }

  TEST(TestLife, nextGen_ConFred_1) {
    istringstream r("3\n3\n-*.\n.0.\n---\n");

    ostringstream w;
    
    Life<Cell> life;

    life.read(r);
    life.nextGen();

    life.printGrid(w);

    ASSERT_TRUE(w.str() == "\nGeneration = 1, Population = 3.\n0..\n.1.\n-0-\n");
 }

 TEST(TestLife, mutate_1) {
    istringstream r("3\n3\n-0-\n-00\n--0\n");

    ostringstream w;
    ostringstream x;
    Life<Cell> life;

    life.read(r);

    
    life.nextGen();

    life.printGrid(w);

    ASSERT_TRUE(w.str() == "\nGeneration = 1, Population = 4.\n01-\n0--\n--1\n");

    life.nextGen();
    life.printGrid(x);


    ASSERT_TRUE(x.str() == "\nGeneration = 2, Population = 6.\n-*0\n1-0\n00-\n");
 }

  TEST(TestLife, DONTmutate_1) {
    istringstream r("3\n3\n-0-\n-00\n--0\n");

    ostringstream w;
    ostringstream x;
    Life<FredkinCell> life;

    life.read(r);

    
    life.nextGen();

    life.printGrid(w);

    ASSERT_TRUE(w.str() == "\nGeneration = 1, Population = 4.\n01-\n0--\n--1\n");

    life.nextGen();
    life.printGrid(x);


    ASSERT_TRUE(x.str() == "\nGeneration = 2, Population = 6.\n-20\n1-0\n00-\n");
 }

   TEST(TestLife, oldFredkin_1) {
    istringstream r("3\n3\n999\n---\n---\n");

    ostringstream w;
    ostringstream x;
    Life<FredkinCell> life;

    life.read(r);

    
    life.nextGen();
    life.printGrid(w);

    ASSERT_TRUE(w.str() == "\nGeneration = 1, Population = 5.\n+-+\n000\n---\n");
 }

    TEST(TestLife, oldFredkin_2) {
    istringstream r("3\n3\n+++\n---\n---\n");

    ostringstream w;
    ostringstream x;
    Life<FredkinCell> life;

    life.read(r);

    
    life.nextGen();
    life.printGrid(w);

    ASSERT_TRUE(w.str() == "\nGeneration = 1, Population = 5.\n+-+\n000\n---\n");
 }

     TEST(TestLife, resumeFredkin_1) {
    istringstream r("3\n3\n+-+\n---\n---\n");

    ostringstream w;
    ostringstream x;
    Life<FredkinCell> life;

    life.read(r);

    
    life.nextGen();
    life.nextGen();

    life.printGrid(w);

    ASSERT_TRUE(w.str() == "\nGeneration = 2, Population = 4.\n+-+\n---\n0-0\n");
 }

 TEST(TestLife, resumeFredkin_2) {
    istringstream r("3\n3\n5-5\n---\n---\n");

    ostringstream w;
    ostringstream x;
    Life<FredkinCell> life;

    life.read(r);

    
    life.nextGen();
    life.nextGen();

    life.printGrid(w);

    ASSERT_TRUE(w.str() == "\nGeneration = 2, Population = 4.\n5-5\n---\n0-0\n");
 }

   TEST(TestLife, ConwayLoops1) {
    istringstream r("4\n4\n....\n.***\n***.\n....\n");

    ostringstream w;
    ostringstream x;
    Life<ConwayCell> life;

    life.read(r);
    life.nextGen();

    life.printGrid(w);

    ASSERT_TRUE(w.str() == "\nGeneration = 1, Population = 6.\n..*.\n*..*\n*..*\n.*..\n");

    life.nextGen();
    life.printGrid(x);


    ASSERT_TRUE(x.str() == "\nGeneration = 2, Population = 6.\n....\n.***\n***.\n....\n");
 }

   TEST(TestLife, ConwayLoops2) {
    istringstream r("4\n4\n**..\n**..\n..**\n..**\n");

    ostringstream w;
    ostringstream x;
    Life<ConwayCell> life;

    life.read(r);
    life.nextGen();

    life.printGrid(w);

    ASSERT_TRUE(w.str() == "\nGeneration = 1, Population = 6.\n**..\n*...\n...*\n..**\n");

    life.nextGen();
    life.printGrid(x);


    ASSERT_TRUE(x.str() == "\nGeneration = 2, Population = 8.\n**..\n**..\n..**\n..**\n");
 }

   TEST(TestLife, ConwayLoops3) {
    istringstream r("6\n6\n.****.\n*....*\n*..*.*\n*...**\n*.*..*\n.****.\n");

    ostringstream w;
    ostringstream x;
    Life<ConwayCell> life;

    life.read(r);
    life.nextGen();

    life.printGrid(w);

    ASSERT_TRUE(w.str() == "\nGeneration = 1, Population = 19.\n.****.\n*....*\n**...*\n*..*.*\n*.*..*\n.****.\n");

    life.nextGen();
    life.printGrid(x);


    ASSERT_TRUE(x.str() == "\nGeneration = 2, Population = 19.\n.****.\n*..*.*\n**...*\n*.*..*\n*....*\n.****.\n");
 }
