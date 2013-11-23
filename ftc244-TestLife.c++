// --------------------------------
// projects/Darwin/TestDarwin.c++
// Frank Cerasoli
// --------------------------------

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

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==

#include "gtest/gtest.h"

#include "Cell.h"
#include "AbstractCell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Handle.h"
#include "Life.h"

// -----------
// TestLife
// -----------

TEST(Game, conwayStructor_1){
	ConwayCell conway (10, 10);
        ASSERT_TRUE(conway.getX() == 10);
        ASSERT_TRUE(conway.getY() == 10);
}
TEST(Game, conwayStructor_2){
	ConwayCell conway (1, 10);
        ASSERT_TRUE(conway.getX() == 1);
        ASSERT_TRUE(conway.getY() == 10);
}
TEST(Game, conwayStructor_3){
	ConwayCell conway (10, 1);
        ASSERT_TRUE(conway.getX() == 10);
        ASSERT_TRUE(conway.getY() == 1);
}
TEST(Game, conwayStructor_4){
	ConwayCell conway (100, 100);
        ASSERT_TRUE(conway.getX() == 100);
        ASSERT_TRUE(conway.getY() == 100);
}
TEST(Game, conwayStructor_5){
	ConwayCell conway (10, 10);
        ASSERT_TRUE(conway.printSelf() == '.');
}
TEST(Game, conwayStructor_6){
	ConwayCell conway (10, 10);
	conway.currentAlive = true;
        ASSERT_TRUE(conway.printSelf() == '*');
}
TEST(Game, conwayStructor_7){
	ConwayCell conway (20, 12);
        ASSERT_TRUE(conway.getX() == 20);
        ASSERT_TRUE(conway.getY() == 12);
	ASSERT_TRUE(conway.printSelf() == '.');
}
TEST(Game, fredkinStructor_1){
	FredkinCell fredkin (10, 10);
        ASSERT_TRUE(fredkin.getX() == 10);
        ASSERT_TRUE(fredkin.getY() == 10);
}
TEST(Game, fredkinStructor_2){
	FredkinCell fredkin (1, 10);
        ASSERT_TRUE(fredkin.getX() == 1);
        ASSERT_TRUE(fredkin.getY() == 10);
}
TEST(Game, fredkinStructor_3){
	FredkinCell fredkin (10, 1);
        ASSERT_TRUE(fredkin.getX() == 10);
        ASSERT_TRUE(fredkin.getY() == 1);
}
TEST(Game, fredkinStructor_4){
	FredkinCell fredkin (100, 100);
        ASSERT_TRUE(fredkin.getX() == 100);
        ASSERT_TRUE(fredkin.getY() == 100);
}
TEST(Game, fredkinStructor_5){
	FredkinCell fredkin (10, 10);
        ASSERT_TRUE(fredkin.printSelf() == '-');
}
TEST(Game, fredkinStructor_6){
	FredkinCell fredkin (10, 10);
	fredkin.currentAlive = true;
        ASSERT_TRUE(fredkin.printSelf() == '0');
}
TEST(Game, fredkinStructor_7){
	FredkinCell fredkin (20, 12);
        ASSERT_TRUE(fredkin.getX() == 20);
        ASSERT_TRUE(fredkin.getY() == 12);
	ASSERT_TRUE(fredkin.printSelf() == '-');
}
TEST(Game, fredkinStructor_8){
	FredkinCell fredkin (20, 12);
	fredkin.setAge(1);
	fredkin.currentAlive = true;
        ASSERT_TRUE(fredkin.getX() == 20);
        ASSERT_TRUE(fredkin.getY() == 12);
	ASSERT_TRUE(fredkin.printSelf() == '1');
}
TEST(Game, fredkinStructor_9){
	FredkinCell fredkin (2, 2);
	fredkin.setAge(3);
	fredkin.currentAlive = true;
        ASSERT_TRUE(fredkin.getX() == 2);
        ASSERT_TRUE(fredkin.getY() == 2);
	ASSERT_TRUE(fredkin.printSelf() == '3');
}
TEST(Game, fredkinStructor_10){
	FredkinCell fredkin (0, 1);
	fredkin.setAge(10);
	fredkin.currentAlive = true;
        ASSERT_TRUE(fredkin.getX() == 0);
        ASSERT_TRUE(fredkin.getY() == 1);
	ASSERT_TRUE(fredkin.printSelf() == '+');
}
TEST(Game, fredkinStructor_11){
	FredkinCell fredkin (20, 12);
	fredkin.setAge(100);
	fredkin.currentAlive = true;
        ASSERT_TRUE(fredkin.getX() == 20);
        ASSERT_TRUE(fredkin.getY() == 12);
	ASSERT_TRUE(fredkin.printSelf() == '+');
}
TEST(Game, fredkinStructor_12){
	FredkinCell fredkin (20, 12);
	fredkin.setAge(100);
	fredkin.currentAlive = true;
        ASSERT_TRUE(fredkin.getX() == 20);
        ASSERT_TRUE(fredkin.getY() == 12);
	ASSERT_TRUE(fredkin.printSelf() == '+');
}
TEST(Game, cellStructor_1){
	Cell cell (10, 10);
        ASSERT_TRUE(cell.getX() == 10);
        ASSERT_TRUE(cell.getY() == 10);
}
TEST(Game, cellStructor_2){
	Cell cell (1, 10);
        ASSERT_TRUE(cell.getX() == 1);
        ASSERT_TRUE(cell.getY() == 10);
}
TEST(Game, cellStructor_3){
	Cell cell (10, 1);
        ASSERT_TRUE(cell.getX() == 10);
        ASSERT_TRUE(cell.getY() == 1);
}
TEST(Game, cellStructor_4){
	Cell cell (100, 100);
        ASSERT_TRUE(cell.getX() == 100);
        ASSERT_TRUE(cell.getY() == 100);
}
TEST(Game, cellStructor_5){
	Cell cell (10, 10);
        ASSERT_TRUE(cell.printSelf() == '-');
}
TEST(Game, cellStructor_6){
	Cell cell (10, 10);
	cell.currentAlive = true;
        ASSERT_TRUE(cell.printSelf() == '0');
}
TEST(Game, cellStructor_7){
	Cell cell (20, 12);
        ASSERT_TRUE(cell.getX() == 20);
        ASSERT_TRUE(cell.getY() == 12);
	ASSERT_TRUE(cell.printSelf() == '-');
}
TEST(Game, cellStructor_8){
	Cell cell (20, 12);
	cell.setAge(1);
	cell.currentAlive = true;
        ASSERT_TRUE(cell.getX() == 20);
        ASSERT_TRUE(cell.getY() == 12);
	ASSERT_TRUE(cell.printSelf() == '1');
}
TEST(Game, cellStructor_9){
	Cell cell (2, 2);
	cell.setAge(3);
	cell.currentAlive = true;
        ASSERT_TRUE(cell.getX() == 2);
        ASSERT_TRUE(cell.getY() == 2);
	ASSERT_TRUE(cell.printSelf() == '*');
}
TEST(Game, cellStructor_10){
	Cell cell (0, 1);
	cell.setAge(10);
	cell.currentAlive = true;
        ASSERT_TRUE(cell.getX() == 0);
        ASSERT_TRUE(cell.getY() == 1);
	ASSERT_TRUE(cell.printSelf() == '*');
}
TEST(Game, cellStructor_11){
	Cell cell (20, 12);
	cell.setAge(2);
	cell.currentAlive = true;
        ASSERT_TRUE(cell.getX() == 20);
        ASSERT_TRUE(cell.getY() == 12);
	ASSERT_TRUE(cell.printSelf() == '*');
}
TEST(Game, cellStructor_12){
	Cell cell (20, 12);
	cell.setAge(100);
	cell.currentAlive = true;
        ASSERT_TRUE(cell.getX() == 20);
        ASSERT_TRUE(cell.getY() == 12);
	ASSERT_TRUE(cell.printSelf() == '*');
}TEST(Game, cellStructor_13){
	Cell cell (1, 1);
	cell.setAge(1);
	cell.currentAlive = true;
        ASSERT_TRUE(cell.getX() == 1);
        ASSERT_TRUE(cell.getY() == 1);
        ASSERT_TRUE(cell.type == '+');
}
TEST(Game, cellStructor_14){
	Cell cell (1, 10);
	cell.setAge(1);
	cell.currentAlive = true;
        ASSERT_TRUE(cell.getX() == 1);
        ASSERT_TRUE(cell.getY() == 10);
        ASSERT_TRUE(cell.printSelf() == '1');
}
TEST(Game, cellStructor_15){
	Cell cell (10, 1);
        ASSERT_TRUE(cell.getX() == 10);
        ASSERT_TRUE(cell.getY() == 1);
}
TEST(Game, cellStructor_16){
	Cell cell (100, 100);
        ASSERT_TRUE(cell.getX() == 100);
        ASSERT_TRUE(cell.getY() == 100);
}
TEST(Game, cellStructor_17){
	Cell cell (10, 10);
        ASSERT_TRUE(cell.printSelf() == '-');
}
TEST(Game, cellStructor_18){
	Cell cell (10, 10);
	cell.currentAlive = true;
        ASSERT_TRUE(cell.printSelf() == '0');
}
TEST(Game, cellStructor_19){
	Cell cell (20, 12);
        ASSERT_TRUE(cell.getX() == 20);
        ASSERT_TRUE(cell.getY() == 12);
	ASSERT_TRUE(cell.printSelf() == '-');
}
TEST(Game, cellStructor_20){
	Cell cell (20, 12);
	cell.setAge(1);
	cell.currentAlive = true;
        ASSERT_TRUE(cell.getX() == 20);
        ASSERT_TRUE(cell.getY() == 12);
	ASSERT_TRUE(cell.printSelf() == '1');
}
TEST(Game, cellStructor_21){
	Cell cell (2, 2);
	cell.setAge(3);
	cell.currentAlive = true;
        ASSERT_TRUE(cell.getX() == 2);
        ASSERT_TRUE(cell.getY() == 2);
	ASSERT_TRUE(cell.printSelf() == '*');
}
TEST(Game, cellStructor_22){
	Cell cell (0, 1);
	cell.setAge(10);
	cell.currentAlive = true;
        ASSERT_TRUE(cell.getX() == 0);
        ASSERT_TRUE(cell.getY() == 1);
	ASSERT_TRUE(cell.printSelf() == '*');
}
TEST(Game, cellStructor_23){
	Cell cell (20, 12);
	cell.setAge(50);
	cell.currentAlive = true;
        ASSERT_TRUE(cell.getX() == 20);
        ASSERT_TRUE(cell.getY() == 12);
	ASSERT_TRUE(cell.printSelf() == '*');
}
TEST(Game, cellStructor_24){
	Cell cell (20, 12);
	cell.setAge(100);
	cell.currentAlive = true;
        ASSERT_TRUE(cell.getX() == 20);
        ASSERT_TRUE(cell.getY() == 12);
	ASSERT_TRUE(cell.printSelf() == '*');
}
TEST(Game, lifeConstructor){
	Life<Cell> life;
        ASSERT_TRUE(life.population == 0);
}
TEST(Game, lifeConstructor_2){
	Life<ConwayCell> life;
        ASSERT_TRUE(life.population == 0);
}
TEST(Game, lifeConstructor_3){
	Life<FredkinCell> life;
        ASSERT_TRUE(life.population == 0);
}
TEST(Game, lifeConstructor_4){
	Life<AbstractCell> life;
        ASSERT_TRUE(life.population == 0);
}
TEST(Game, lifeConstructor_5){
	Life<Cell> life;
	Cell cell (10, 10);
	life.addCell(&cell, "1010");
        ASSERT_TRUE(life.population == 0);
}