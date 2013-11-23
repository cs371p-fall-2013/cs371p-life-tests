// --------------------
// TestLife.c++
// Copyright (C) 2013
// Ryan Niemann
// --------------------

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

#include "gtest/gtest.h"
#include <sstream>
#include <stdexcept>
#include <string>
#include "Life.h"

// -------
// defines
// -------

#define private public
#define protected public


using namespace std;

// ------------
// ConwayCell
// ------------

TEST(ConwayCell, constructor1){
	ConwayCell c = ConwayCell();
    
    ASSERT_FALSE(c.isAlive());
}

TEST(ConwayCell, constructor2){
	ConwayCell c = ConwayCell();
    
    ASSERT_TRUE(c.type() == "ConwayCell");
}

TEST(ConwayCell, constructor3){
	ConwayCell c = ConwayCell();
    
    ASSERT_TRUE(c.className() == "ConwayCell");
}

TEST(ConwayCell, changeState1){
	ConwayCell c = ConwayCell();
    
    ASSERT_FALSE(c.isAlive());
    c.setStateWillChange();
    c.changeState();
    ASSERT_TRUE(c.isAlive());
}

// -------------
// FredkinCell
// -------------

TEST(FredkinCell, constructor1){
	FredkinCell c = FredkinCell();
    
    ASSERT_FALSE(c.isAlive());
}

TEST(FredkinCell, constructor2){
	FredkinCell c = FredkinCell();
    
    ASSERT_TRUE(c.type() == "FredkinCell");
}

TEST(FredkinCell, constructor3){
	FredkinCell c = FredkinCell();
    
    ASSERT_TRUE(c.className() == "FredkinCell");
}

TEST(FredkinCell, changeState1){
	FredkinCell c = FredkinCell();
    
    ASSERT_FALSE(c.isAlive());
    c.setStateWillChange();
    c.changeState();
    ASSERT_TRUE(c.isAlive());
}

// ------
// Cell
// ------

TEST(Cell, constructor1){
	Cell c = Cell(new FredkinCell());
    
    ASSERT_FALSE(c.isAlive());
}

TEST(Cell, constructor2){
	Cell c = Cell(new FredkinCell());
    
    ASSERT_TRUE(c.type() == "FredkinCell");
}

TEST(Cell, constructor3){
	Cell c = Cell(new FredkinCell());
    
    ASSERT_TRUE(c.className() == "Cell");
}
