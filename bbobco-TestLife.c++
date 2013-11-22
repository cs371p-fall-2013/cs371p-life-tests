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

%g++ -pedantic -std=c++0x -Wall TestLife.c++ AbstractCell.c++ Cell.c++ ConwayCell.c++ FredkinCell.c++ -o TestLife -lgtest -lpthread -lgtest_main

% valgrind TestLife > TestLife.out
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
#include "AbstractCell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"
#include <vector>

using namespace std;




TEST(Life, life_constructor){
  Life<ConwayCell> g(20,50);
  ASSERT_TRUE(g.rows==20);
  ASSERT_TRUE(g.cols==50);
}
TEST(Life, life_constructor2){
  Life<FredkinCell> g(210,2);
  ASSERT_TRUE(g.rows==210);
  ASSERT_TRUE(g.cols==2);
}
TEST(Life, life_constructor3){
  Life<Cell> g(5,1);
  ASSERT_TRUE(g.rows==5);
  ASSERT_TRUE(g.cols==1);
}

TEST(Life, inBounds){
  ASSERT_TRUE(Life<ConwayCell>::inBounds(1,2,5,5));
}
TEST(Life, inBounds2){
  ASSERT_FALSE(Life<FredkinCell>::inBounds(-1,2,50,50));
}
TEST(Life, inBounds3){
  ASSERT_FALSE(Life<Cell>::inBounds(5,0,5,5));
}

//for these steps t=top l= left m= middle, etc, so tl signifies top left
// will be using 3x3 grids and checking things for the middle Cell, so all neighbors are included

TEST(FredkinCell, simulate){
  Life<FredkinCell> g(3,3);      // ---
  FredkinCell middle(true);    // ---
  
  FredkinCell tl(true); g.grid[0]=tl;
  FredkinCell tm(true); g.grid[1]=tm;
  FredkinCell tr(true); g.grid[2]=tr;
  FredkinCell ml(true); g.grid[3]=ml;
  g.grid[4] = middle;
  FredkinCell mr(true); g.grid[5]=mr;
  FredkinCell bl(true); g.grid[6]=bl;
  FredkinCell bm(true); g.grid[7]=bm;
  FredkinCell br(true); g.grid[8]=br;   
  
  vector<bool> boolgrid(9);
  for(int i=0;i<9;i++) boolgrid[i] = g.grid[i].alive;

  middle.simulate(1,1,3,3,boolgrid);
  ASSERT_FALSE(middle.alive);
  
}

TEST(FredkinCell, simulate2){
   //alive to still alive --- 3 neighbors alive
  Life<FredkinCell> g(3,3);      // ---
  FredkinCell middle(true);    // ---
  
  FredkinCell tl(true); g.grid[0]=tl;
  FredkinCell tm(false); g.grid[1]=tm;
  FredkinCell tr(true); g.grid[2]=tr;
  FredkinCell ml(true); g.grid[3]=ml;
  g.grid[4] = middle;
  FredkinCell mr(true); g.grid[5]=mr;
  FredkinCell bl(true); g.grid[6]=bl;
  FredkinCell bm(true); g.grid[7]=bm;
  FredkinCell br(true); g.grid[8]=br;   
  
  vector<bool> boolgrid(9);
  for(int i=0;i<9;i++) boolgrid[i] = g.grid[i].alive;

  middle.simulate(1,1,3,3,boolgrid);
  ASSERT_TRUE(middle.alive);
  
}

TEST(FredkinCell, simulate3){
  //dead to alive, 3 neightbors alive
  Life<FredkinCell> g(3,3);      // ---
  FredkinCell middle(false);    // ---
  
  FredkinCell tl(true); g.grid[0]=tl;
  FredkinCell tm(false); g.grid[1]=tm;
  FredkinCell tr(true); g.grid[2]=tr;
  FredkinCell ml(true); g.grid[3]=ml;
  g.grid[4] = middle;
  FredkinCell mr(true); g.grid[5]=mr;
  FredkinCell bl(true); g.grid[6]=bl;
  FredkinCell bm(true); g.grid[7]=bm;
  FredkinCell br(true); g.grid[8]=br;   
  
  vector<bool> boolgrid(9);
  for(int i=0;i<9;i++) boolgrid[i] = g.grid[i].alive;

  middle.simulate(1,1,3,3,boolgrid);
  ASSERT_TRUE(middle.alive);
  
}

TEST(FredkinCell, simulate4){
  //alive to dead, 0 neighbors alive
  Life<FredkinCell> g(3,3);      // ---
  FredkinCell middle(false);    // ---
  
  FredkinCell tl(true); g.grid[0]=tl;
  FredkinCell tm(false); g.grid[1]=tm;
  FredkinCell tr(true); g.grid[2]=tr;
  FredkinCell ml(false); g.grid[3]=ml;
  g.grid[4] = middle;
  FredkinCell mr(false); g.grid[5]=mr;
  FredkinCell bl(true); g.grid[6]=bl;
  FredkinCell bm(false); g.grid[7]=bm;
  FredkinCell br(true); g.grid[8]=br;   
  
  vector<bool> boolgrid(9);
  for(int i=0;i<9;i++) boolgrid[i] = g.grid[i].alive;

  middle.simulate(1,1,3,3,boolgrid);
  ASSERT_FALSE(middle.alive);
  
}

//now switching our cell to simulate to TOP RIGHT, to make sure we still handle it correctly when we dont have maximum number of neighbors
TEST(FredkinCell, simulate6){
  //alive to dead, 2 neighbors alive
  Life<FredkinCell> g(3,3);      // ---
  FredkinCell topleft(false);    // ---
  
  g.grid[0]=topleft;
  FredkinCell tm(false); g.grid[1]=tm;
  FredkinCell tr(true); g.grid[2]=tr;
  FredkinCell ml(false); g.grid[3]=ml;
  FredkinCell mm(false); g.grid[4] =mm;
  FredkinCell mr(false); g.grid[5]=mr;
  FredkinCell bl(true); g.grid[6]=bl;
  FredkinCell bm(false); g.grid[7]=bm;
  FredkinCell br(true); g.grid[8]=br;   
  
  vector<bool> boolgrid(9);
  for(int i=0;i<9;i++) boolgrid[i] = g.grid[i].alive;

  topleft.simulate(0,0,3,3,boolgrid);
  ASSERT_FALSE(topleft.alive);
  
}

TEST(FredkinCell, simulate7){
  //dead to alive -- 1 neighbor alive
  Life<FredkinCell> g(3,3);      // ---
  FredkinCell topleft(false);    // ---
  
  g.grid[0]=topleft;
  FredkinCell tm(true); g.grid[1]=tm;
  FredkinCell tr(true); g.grid[2]=tr;
  FredkinCell ml(false); g.grid[3]=ml;
  FredkinCell mm(false); g.grid[4] =mm;
  FredkinCell mr(false); g.grid[5]=mr;
  FredkinCell bl(true); g.grid[6]=bl;
  FredkinCell bm(false); g.grid[7]=bm;
  FredkinCell br(true); g.grid[8]=br;   
  
  vector<bool> boolgrid(9);
  for(int i=0;i<9;i++) boolgrid[i] = g.grid[i].alive;

  topleft.simulate(0,0,3,3,boolgrid);
  ASSERT_TRUE(topleft.alive);
  
}

//now conway cell simulate Tests

TEST(ConwayCell, simulate){
  //dead to alive -- 3 neighbors alive
  Life<ConwayCell> g(3,3);      // ---
  ConwayCell middle(false);    // ---
  
  ConwayCell tl(false); g.grid[0]=tl;
  ConwayCell tm(false); g.grid[1]=tm;
  ConwayCell tr(false); g.grid[2]=tr;
  ConwayCell ml(false); g.grid[3]=ml;
  g.grid[4] = middle;
  ConwayCell mr(false); g.grid[5]=mr;
  ConwayCell bl(true); g.grid[6]=bl;
  ConwayCell bm(true); g.grid[7]=bm;
  ConwayCell br(true); g.grid[8]=br;   
  
  vector<bool> boolgrid(9);
  for(int i=0;i<9;i++) boolgrid[i] = g.grid[i].alive;

  middle.simulate(1,1,3,3,boolgrid);
  ASSERT_TRUE(middle.alive);
  
}

TEST(ConwayCell, simulate2){
  //dead to alive -- 3 neighbors alive
  Life<ConwayCell> g(3,3);      // ---
  ConwayCell middle(false);    // ---
  
  ConwayCell tl(false); g.grid[0]=tl;
  ConwayCell tm(true); g.grid[1]=tm;
  ConwayCell tr(false); g.grid[2]=tr;
  ConwayCell ml(false); g.grid[3]=ml;
  g.grid[4] = middle;
  ConwayCell mr(false); g.grid[5]=mr;
  ConwayCell bl(false); g.grid[6]=bl;
  ConwayCell bm(true); g.grid[7]=bm;
  ConwayCell br(true); g.grid[8]=br;   
  
  vector<bool> boolgrid(9);
  for(int i=0;i<9;i++) boolgrid[i] = g.grid[i].alive;

  middle.simulate(1,1,3,3,boolgrid);
  ASSERT_TRUE(middle.alive);
  
}


TEST(ConwayCell, simulate3){
  //dead to alive -- 3 neighbors alive
  Life<ConwayCell> g(3,3);      // ---
  ConwayCell middle(false);    // ---
  
  ConwayCell tl(false); g.grid[0]=tl;
  ConwayCell tm(true); g.grid[1]=tm;
  ConwayCell tr(false); g.grid[2]=tr;
  ConwayCell ml(true); g.grid[3]=ml;
  g.grid[4] = middle;
  ConwayCell mr(false); g.grid[5]=mr;
  ConwayCell bl(false); g.grid[6]=bl;
  ConwayCell bm(false); g.grid[7]=bm;
  ConwayCell br(true); g.grid[8]=br;   
  
  vector<bool> boolgrid(9);
  for(int i=0;i<9;i++) boolgrid[i] = g.grid[i].alive;

  middle.simulate(1,1,3,3,boolgrid);
  ASSERT_TRUE(middle.alive);
  
}

TEST(ConwayCell, simulate4){
  //alive to alive -- 2 neighbors alive
  Life<ConwayCell> g(3,3);      // ---
  ConwayCell middle(true);    // ---
  
  ConwayCell tl(false); g.grid[0]=tl;
  ConwayCell tm(true); g.grid[1]=tm;
  ConwayCell tr(false); g.grid[2]=tr;
  ConwayCell ml(false); g.grid[3]=ml;
  g.grid[4] = middle;
  ConwayCell mr(false); g.grid[5]=mr;
  ConwayCell bl(false); g.grid[6]=bl;
  ConwayCell bm(false); g.grid[7]=bm;
  ConwayCell br(true); g.grid[8]=br;   
  
  vector<bool> boolgrid(9);
  for(int i=0;i<9;i++) boolgrid[i] = g.grid[i].alive;

  middle.simulate(1,1,3,3,boolgrid);
  ASSERT_TRUE(middle.alive);
  
}

TEST(ConwayCell, simulate5){
  //alive to dead -- 1 neighbors alive
  Life<ConwayCell> g(3,3);      // ---
  ConwayCell middle(false);    // ---
  
  ConwayCell tl(false); g.grid[0]=tl;
  ConwayCell tm(false); g.grid[1]=tm;
  ConwayCell tr(false); g.grid[2]=tr;
  ConwayCell ml(false); g.grid[3]=ml;
  g.grid[4] = middle;
  ConwayCell mr(false); g.grid[5]=mr;
  ConwayCell bl(false); g.grid[6]=bl;
  ConwayCell bm(false); g.grid[7]=bm;
  ConwayCell br(true); g.grid[8]=br;   
  
  vector<bool> boolgrid(9);
  for(int i=0;i<9;i++) boolgrid[i] = g.grid[i].alive;

  middle.simulate(1,1,3,3,boolgrid);
  ASSERT_FALSE(middle.alive);
  
}
TEST(ConwayCell, simulate6){
  //alive to dead -- 0 neighbors alive
  Life<ConwayCell> g(3,3);      // ---
  ConwayCell middle(false);    // ---
  
  ConwayCell tl(false); g.grid[0]=tl;
  ConwayCell tm(false); g.grid[1]=tm;
  ConwayCell tr(false); g.grid[2]=tr;
  ConwayCell ml(false); g.grid[3]=ml;
  g.grid[4] = middle;
  ConwayCell mr(false); g.grid[5]=mr;
  ConwayCell bl(false); g.grid[6]=bl;
  ConwayCell bm(false); g.grid[7]=bm;
  ConwayCell br(false); g.grid[8]=br;   
  
  vector<bool> boolgrid(9);
  for(int i=0;i<9;i++) boolgrid[i] = g.grid[i].alive;

  middle.simulate(1,1,3,3,boolgrid);
  ASSERT_FALSE(middle.alive);
  
}
TEST(ConwayCell, simulate7){
  //alive to dead -- 1 neighbors alive
  Life<ConwayCell> g(3,3);      // ---
  ConwayCell middle(false);    // ---
  
  ConwayCell tl(false); g.grid[0]=tl;
  ConwayCell tm(false); g.grid[1]=tm;
  ConwayCell tr(false); g.grid[2]=tr;
  ConwayCell ml(false); g.grid[3]=ml;
  g.grid[4] = middle;
  ConwayCell mr(true); g.grid[5]=mr;
  ConwayCell bl(false); g.grid[6]=bl;
  ConwayCell bm(false); g.grid[7]=bm;
  ConwayCell br(false); g.grid[8]=br;   
  
  vector<bool> boolgrid(9);
  for(int i=0;i<9;i++) boolgrid[i] = g.grid[i].alive;

  middle.simulate(1,1,3,3,boolgrid);
  ASSERT_FALSE(middle.alive);
  
}
TEST(ConwayCell, simulate8){
  //alive to alive -- 3 neighbors alive
  Life<ConwayCell> g(3,3);      // ---
  ConwayCell middle(false);    // ---
  
  ConwayCell tl(true); g.grid[0]=tl;
  ConwayCell tm(false); g.grid[1]=tm;
  ConwayCell tr(true); g.grid[2]=tr;
  ConwayCell ml(false); g.grid[3]=ml;
  g.grid[4] = middle;
  ConwayCell mr(true); g.grid[5]=mr;
  ConwayCell bl(false); g.grid[6]=bl;
  ConwayCell bm(false); g.grid[7]=bm;
  ConwayCell br(false); g.grid[8]=br;   
  
  vector<bool> boolgrid(9);
  for(int i=0;i<9;i++) boolgrid[i] = g.grid[i].alive;

  middle.simulate(1,1,3,3,boolgrid);
  ASSERT_TRUE(middle.alive);
  
}

TEST(ConwayCell, simulate9){
  //alive to dead -- 4 neighbors alive
  Life<ConwayCell> g(3,3);      // ---
  ConwayCell middle(false);    // ---
  
  ConwayCell tl(true); g.grid[0]=tl;
  ConwayCell tm(false); g.grid[1]=tm;
  ConwayCell tr(true); g.grid[2]=tr;
  ConwayCell ml(true); g.grid[3]=ml;
  g.grid[4] = middle;
  ConwayCell mr(true); g.grid[5]=mr;
  ConwayCell bl(false); g.grid[6]=bl;
  ConwayCell bm(false); g.grid[7]=bm;
  ConwayCell br(false); g.grid[8]=br;   
  
  vector<bool> boolgrid(9);
  for(int i=0;i<9;i++) boolgrid[i] = g.grid[i].alive;

  middle.simulate(1,1,3,3,boolgrid);
  ASSERT_FALSE(middle.alive);
  
}

TEST(ConwayCell, simulate10){
  //alive to dead -- 8 neighbors alive
  Life<ConwayCell> g(3,3);      // ---
  ConwayCell middle(false);    // ---
  
  ConwayCell tl(true); g.grid[0]=tl;
  ConwayCell tm(true); g.grid[1]=tm;
  ConwayCell tr(true); g.grid[2]=tr;
  ConwayCell ml(true); g.grid[3]=ml;
  g.grid[4] = middle;
  ConwayCell mr(true); g.grid[5]=mr;
  ConwayCell bl(true); g.grid[6]=bl;
  ConwayCell bm(true); g.grid[7]=bm;
  ConwayCell br(true); g.grid[8]=br;   
  
  vector<bool> boolgrid(9);
  for(int i=0;i<9;i++) boolgrid[i] = g.grid[i].alive;

  middle.simulate(1,1,3,3,boolgrid);
  ASSERT_FALSE(middle.alive);
  
}

TEST(ConwayCell, simulate11){
  //alive to dead -- 5 neighbors alive
  Life<ConwayCell> g(3,3);      // ---
  ConwayCell middle(false);    // ---
  
  ConwayCell tl(true); g.grid[0]=tl;
  ConwayCell tm(false); g.grid[1]=tm;
  ConwayCell tr(true); g.grid[2]=tr;
  ConwayCell ml(false); g.grid[3]=ml;
  g.grid[4] = middle;
  ConwayCell mr(true); g.grid[5]=mr;
  ConwayCell bl(true); g.grid[6]=bl;
  ConwayCell bm(false); g.grid[7]=bm;
  ConwayCell br(true); g.grid[8]=br;   
  
  vector<bool> boolgrid(9);
  for(int i=0;i<9;i++) boolgrid[i] = g.grid[i].alive;

  middle.simulate(1,1,3,3,boolgrid);
  ASSERT_FALSE(middle.alive);
  
}

TEST(Cell, simulate1){
  //dead to alive, 3 neightbors alive
  Life<Cell> g(3,3);      // ---
  Cell middle = new FredkinCell(false);    // ---
  
  Cell tl = new FredkinCell(true); g.grid[0]=tl;
  Cell tm = new FredkinCell(false); g.grid[1]=tm;
  Cell tr=new FredkinCell(true); g.grid[2]=tr;
  Cell ml=new FredkinCell(true); g.grid[3]=ml;
  g.grid[4] = middle;
  Cell mr=new FredkinCell(true); g.grid[5]=mr;
  Cell bl=new FredkinCell(true); g.grid[6]=bl;
  Cell bm=new FredkinCell(true); g.grid[7]=bm;
  Cell br=new FredkinCell(true); g.grid[8]=br;   
  
  vector<bool> boolgrid(9);
  for(int i=0;i<9;i++) boolgrid[i] = g.grid[i].alive();

  middle.simulate(1,1,3,3,boolgrid);
  ASSERT_TRUE(middle.alive());
  
}

TEST(FredkinCell, constructor){
  FredkinCell f(false);
  ASSERT_FALSE(f.alive);
}
TEST(FredkinCell, constructor2){
  FredkinCell f(true);
  ASSERT_TRUE(f.alive);
}
TEST(ConwayCell, constructor){
  ConwayCell c(false);
  ASSERT_FALSE(c.alive);
}
TEST(ConwayCell, constructor2){
  ConwayCell c(true);
  ASSERT_TRUE(c.alive);
}
TEST(Cell, constructor){
  Cell c = new ConwayCell(false);
  ASSERT_FALSE(c.alive());
}
TEST(Cell, constructor2){
  Cell c = new ConwayCell(true);
  ASSERT_TRUE(c.alive());
}
TEST(Cell, constructor3){
  Cell c = new FredkinCell(false);
  ASSERT_FALSE(c.alive());
}
TEST(Cell, constructor4){
  Cell c = new FredkinCell(true);
  ASSERT_TRUE(c.alive());
}

//make sure we know when to mutate
TEST(FredkinCell, mutate1){
  Life<FredkinCell> g(3,3);      // ---
  FredkinCell middle(true);    // ---
  
  FredkinCell tl(true); g.grid[0]=tl;
  FredkinCell tm(false); g.grid[1]=tm;
  FredkinCell tr(true); g.grid[2]=tr;
  FredkinCell ml(true); g.grid[3]=ml;
  g.grid[4] = middle;
  FredkinCell mr(true); g.grid[5]=mr;
  FredkinCell bl(true); g.grid[6]=bl;
  FredkinCell bm(true); g.grid[7]=bm;
  FredkinCell br(true); g.grid[8]=br;   
  
  vector<bool> boolgrid(9);
  for(int i=0;i<9;i++) boolgrid[i] = g.grid[i].alive;

  bool mutate = middle.simulate(1,1,3,3,boolgrid);
  ASSERT_FALSE(mutate);  
}

TEST(FredkinCell, mutate2){
  //gonna become age 2, so should return true for mutate
  Life<FredkinCell> g(3,3);      // ---
  FredkinCell middle(true);    // ---
  middle.age=1;
  
  FredkinCell tl(true); g.grid[0]=tl;
  FredkinCell tm(false); g.grid[1]=tm;
  FredkinCell tr(true); g.grid[2]=tr;
  FredkinCell ml(true); g.grid[3]=ml;
  g.grid[4] = middle;
  FredkinCell mr(true); g.grid[5]=mr;
  FredkinCell bl(true); g.grid[6]=bl;
  FredkinCell bm(true); g.grid[7]=bm;
  FredkinCell br(true); g.grid[8]=br;   
  
  vector<bool> boolgrid(9);
  for(int i=0;i<9;i++) boolgrid[i] = g.grid[i].alive;

  bool mutate = middle.simulate(1,1,3,3,boolgrid);
  ASSERT_TRUE(mutate);  
}












