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

#include "gtest/gtest.h"
#include <sstream>
#include <stdexcept>
#include <string>

#define private public
#include "Life.h"
#include "FredkinCell.h"
#include "ConwayCell.h"
#include "Cell.h"
#include "Handle.h"
#include "AbstractCell.h"
#undef private

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
