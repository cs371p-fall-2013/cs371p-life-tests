
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

% g++ -pedantic -std=c++0x -Wall TestAllocator.c++ -o TestAllocator -lgtest -lpthread -lgtest_main

% valgrind TestLife > TestLife.out
*/

// --------
// includes
// --------

#include <algorithm> // count

#include "gtest/gtest.h"

#include "Life.h"

// -------------
// TestAllocator
// -------------

 TEST(Life, conway1)
 {
 	Life<ConwayCell> life(10,10);
 	int numAlive = 0;
 	for(unsigned i = 0; i < life.grid.size(); ++i)
 		for(unsigned j = 0; j < life.grid.size(); ++j)
 			if(life.grid.at(i).at(j).getAlive())
 				numAlive++;
 	ASSERT_TRUE(numAlive == 0);
 }

 TEST(Life, conway2)
 {
 	Life<ConwayCell> life(10, 10);
 	life.addCell(0, 0);
 	ASSERT_TRUE(life.grid.at(1).at(1).getAlive() == true);
 }

 TEST(Life, conway3)
 {
 	Life<ConwayCell> life(10, 10);
 	life.addCell(0, 0);
 	ASSERT_TRUE(life.grid.at(1).at(1).getAlive() == true);
 	life.executeTurn();
 	ASSERT_TRUE(life.grid.at(1).at(1).getAlive() == false);
 }

 TEST(Life, conway4)
 {
 	Life<ConwayCell> life(4, 4);
 	life.addCell(2, 1);
 	life.addCell(3, 1);
 	life.addCell(1, 1);
 	life.executeTurn();
 	ASSERT_TRUE(life.grid.at(2).at(2).getAlive() == false);
 	ASSERT_TRUE(life.grid.at(4).at(2).getAlive() == false);
 	ASSERT_TRUE(life.grid.at(3).at(2).getAlive() == true);
 	ASSERT_TRUE(life.grid.at(3).at(1).getAlive() == true);
 	ASSERT_TRUE(life.grid.at(3).at(3).getAlive() == true);
 }

 TEST(Life, conway5)
 {
 	Life<ConwayCell> life(4, 4);
 	life.addCell(1, 1);
 	life.addCell(2, 1);
 	life.addCell(3, 1);
 	life.executeTurn();
 	ASSERT_TRUE(life.grid.at(2).at(2).getAlive() == false);
 	ASSERT_TRUE(life.grid.at(4).at(2).getAlive() == false);
 	ASSERT_TRUE(life.grid.at(3).at(2).getAlive() == true);
 	ASSERT_TRUE(life.grid.at(3).at(1).getAlive() == true);
 	ASSERT_TRUE(life.grid.at(3).at(3).getAlive() == true);
 	life.executeTurn();
 	ASSERT_TRUE(life.grid.at(3).at(1).getAlive() == false);
 	ASSERT_TRUE(life.grid.at(3).at(3).getAlive() == false);
 	ASSERT_TRUE(life.grid.at(3).at(2).getAlive() == true);
 	ASSERT_TRUE(life.grid.at(2).at(2).getAlive() == true);
 	ASSERT_TRUE(life.grid.at(4).at(2).getAlive() == true);
 }

 TEST(Life, Fredkin1)
 {
 	Life<FredkinCell> life(4, 4);
 	life.addCell(0, 0);
 	ASSERT_TRUE(life.grid.at(1).at(1).getAlive() == true);
 	life.executeTurn();
 	ASSERT_TRUE(life.grid.at(2).at(1).getAlive() == true);
 	ASSERT_TRUE(life.grid.at(1).at(2).getAlive() == true);
 	ASSERT_TRUE(life.grid.at(1).at(1).getAlive() == false);
 }

  TEST(Life, Fredkin2)
 {
 	Life<FredkinCell> life(4, 4);
 	life.addCell(0, 0);
 	life.addCell(0, 1);
 	ASSERT_TRUE(life.grid.at(1).at(1).getAlive() == true);
 	ASSERT_TRUE(life.grid.at(1).at(2).getAlive() == true);
 	life.executeTurn();
 	ASSERT_TRUE(life.grid.at(1).at(1).getAlive() == true);
 	ASSERT_TRUE(life.grid.at(1).at(2).getAlive() == true);
 	ASSERT_TRUE(life.grid.at(2).at(1).getAlive() == true);
 	ASSERT_TRUE(life.grid.at(2).at(2).getAlive() == true);
 	ASSERT_TRUE(life.grid.at(1).at(3).getAlive() == true);
 	ASSERT_TRUE(life.grid.at(2).at(2).getAlive() == true);
 }


  TEST(Life, Fredkin3)
 {
 	Life<FredkinCell> life(8, 8);
 	life.addCell(0, 0);
 	life.addCell(0, 1);
 	ASSERT_TRUE(life.grid.at(1).at(1).getAlive() == true);
 	ASSERT_TRUE(life.grid.at(1).at(2).getAlive() == true);
 	life.executeTurn();
 	ASSERT_TRUE(life.grid.at(1).at(1).getAlive() == true);
 	ASSERT_TRUE(life.grid.at(1).at(2).getAlive() == true);
 	ASSERT_TRUE(life.grid.at(2).at(1).getAlive() == true);
 	ASSERT_TRUE(life.grid.at(2).at(2).getAlive() == true);
 	ASSERT_TRUE(life.grid.at(1).at(3).getAlive() == true);
 	ASSERT_TRUE(life.grid.at(2).at(2).getAlive() == true);
 	life.executeTurn();
 	ASSERT_TRUE(life.grid.at(1).at(1).getAlive() == false);
 	ASSERT_TRUE(life.grid.at(1).at(2).getAlive() == true);
 	ASSERT_TRUE(life.grid.at(1).at(3).getAlive() == true);
 	ASSERT_TRUE(life.grid.at(1).at(4).getAlive() == true);
 	life.executeTurn();
 }

 TEST(Life, Both)
 {
 	Life<Cell> life(8, 8);
 	life.addCell(0, 0);
 	life.executeTurn();


 }

TEST(Life, getAlive1)
{
	ConwayCell cc(true);
	ASSERT_TRUE(cc.getAlive() == true);
}

TEST(Life, getAlive2)
{
	FredkinCell fc(0, true);
	ASSERT_TRUE(fc.getAlive() == true);
}

TEST(Life, getAlive3)
{
	Life<ConwayCell> life(4, 4);
	ASSERT_TRUE(life.grid.at(0).at(0).getAlive() == false);
}

TEST(Life, getAlive4)
{
	Life<FredkinCell> life(4, 4);
	ASSERT_TRUE(life.grid.at(0).at(0).getAlive() == false);
	life.executeTurn();
	ASSERT_TRUE(life.image.at(1).at(1) == '-');
}

TEST(Life, getAlive5)
{
	Life<Cell> life(4, 4);
	ASSERT_TRUE(life.grid.at(1).at(1).getAlive() == false);
	life.executeTurn();
	ASSERT_TRUE(life.image.at(1).at(1) == '-');
}

TEST(Life, putOnBoard1)
{
	FredkinCell fc(0, false);
	fc.putOnBoard();
	ASSERT_TRUE(fc.getAlive() == true);
}

TEST(Life, putOnBoard2)
{
	ConwayCell cc(false);
	cc.putOnBoard();
	ASSERT_TRUE(cc.getAlive() == true);
}

TEST(Life, putOnBoard3)
{
	Life<ConwayCell> life(8,8);
	life.grid.at(0).at(0).putOnBoard();
	life.grid.at(1).at(2).putOnBoard();
	life.grid.at(3).at(4).putOnBoard();
	ASSERT_TRUE(life.grid.at(0).at(0).getAlive() == true);
	ASSERT_TRUE(life.grid.at(1).at(2).getAlive() == true);
	ASSERT_TRUE(life.grid.at(3).at(4).getAlive() == true);
}

TEST(Life, addCell1)
{
	Life<ConwayCell> life(2, 2);
	life.addCell(0, 0);
	ASSERT_TRUE(life.grid.at(1).at(1).getAlive() == true);
}

TEST(Life, addCell2)
{
	Life<FredkinCell> life(4, 4);
	life.addCell(2, 2);
	ASSERT_TRUE(life.grid.at(3).at(3).getAlive() == true);
}


TEST(Life, addCell3)
{
	Life<Cell> life(5, 5);
	life.addCell(2, 2);
	ASSERT_TRUE(life.grid.at(3).at(3).getAlive() == true);
}

TEST(Life, mutate1)
{
	Life<Cell> life(8, 8);
 	life.addCell(0, 0);
 	life.grid.at(1).at(1).mutate();
 	life.executeTurn();
 	ASSERT_TRUE(life.image.at(1).at(1) == '*');
}

TEST(Life, mutate2)
{
	Life<Cell> life(8, 8);
 	life.addCell(0, 0);
 	life.addCell(1, 0);
 	life.addCell(0, 1);
 	life.grid.at(1).at(1).mutate();
 	life.executeTurn();
 	ASSERT_TRUE(life.image.at(1).at(1) == '*');
} 

TEST(Life, mutate3)
{
	Life<Cell> life(8, 8);
 	life.addCell(0, 0);
 	life.grid.at(1).at(1).mutate();
 	life.executeTurn();
 	ASSERT_TRUE(life.image.at(1).at(1) == '*');
 	life.executeTurn();
 	ASSERT_TRUE(life.image.at(1).at(1) == '.');
}

 TEST(Life, construct){
 	Life<Cell> life(4,4);
 	life.executeTurn();
 	life.addCell(3,4);
 	ASSERT_EQ(life.image.at(4).at(5) , '.');
 }