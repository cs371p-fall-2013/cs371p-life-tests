#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==
#include <cassert>   // assert
#include <stdexcept> // invalid_argument, out_of_range
#include "Cell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"

#include "gtest/gtest.h"

#include "Life.h"


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

    % g++ -pedantic -std=c++0x -Wall AbstractCell.c++ Cell.c++ ConwayCell.c++ FredkinCell.c++ TestLife.c++ -o TestLife -lgtest -lpthread -lgtest_main

    % valgrind TestLife > TestLife.out
*/

TEST(Life, ConwayCell1) {
	ConwayCell ConCell;
	ASSERT_TRUE(!ConCell.getStatus());
}

TEST(Life, FredkinCell1) {
	FredkinCell fredCell;
	ASSERT_TRUE(!fredCell.getStatus());
}

TEST(Life, Cell1) {
	Cell testCell;
	ASSERT_TRUE(!testCell.getStatus());
}

TEST(Life, ConwayCopy1) {
	ConwayCell ConCell;
	AbstractCell* ConCellCopy = ConCell.copy();
	ASSERT_TRUE( (ConwayCell*)(ConCellCopy) != &ConCell);
}

TEST(Life, FredkinCopy1) {
	FredkinCell FredCell;
	AbstractCell* FredCellCopy = FredCell.copy();
	ASSERT_TRUE((FredkinCell*)(FredCellCopy) != &FredCell);
}

TEST(Life, ConwayChangeStatus1) {
	ConwayCell ConCell;
	ConCell.changeStatus('*');
	ASSERT_TRUE(ConCell.getStatus());
}
TEST(Life, ConwayChangeStatus2) {
	ConwayCell ConCell;
	ConCell.changeStatus('.');
	ASSERT_TRUE(!ConCell.getStatus());
}

TEST(Life, FredkinChangeStatus1) {
	FredkinCell FredCell;
	FredCell.changeStatus('0');
	ASSERT_TRUE(FredCell.getStatus());
}
TEST(Life, FredkinChangeStatus2) {
	FredkinCell FredCell;
	FredCell.changeStatus('-');
	ASSERT_TRUE(!FredCell.getStatus());
}
TEST(Life, FredkinChangeStatus3) {
	FredkinCell FredCell;
	FredCell.changeStatus('5');
	ASSERT_TRUE(FredCell.getStatus());
}
TEST(Life, CellChangeStatus1) {
	Cell testCell;
	testCell.changeStatus('0');
	ASSERT_TRUE(testCell.getStatus());
}
TEST(Life, CellChangeStatus2) {
	Cell testCell;
	testCell.changeStatus('*');
	ASSERT_TRUE(testCell.getStatus());
}
TEST(Life, CellChangeStatus3) {
	Cell testCell;
	testCell.changeStatus('.');
	ASSERT_TRUE(!testCell.getStatus());
}
TEST(Life, CellChangeStatus4) {
	Cell testCell;
	testCell.changeStatus('5');
	ASSERT_TRUE(testCell.getStatus());
}


TEST(Life, ConwayMutate1) {
	ConwayCell ConCell;
	ConCell.changeStatus('.');
	ConCell.mutate(3);
	ASSERT_TRUE(ConCell.getStatus());
}
TEST(Life, ConwayMutate2) {
	ConwayCell ConCell;
	ConCell.changeStatus('*');
	ConCell.mutate(10);
	ASSERT_TRUE(!ConCell.getStatus());
}
TEST(Life, ConwayMutate3) {
	ConwayCell ConCell;
	ConCell.changeStatus('*');
	ConCell.mutate(0);
	ASSERT_TRUE(!ConCell.getStatus());
}
TEST(Life, ConwayMutate4) {
	ConwayCell ConCell;
	ConCell.changeStatus('*');
	ConCell.mutate(7);
	ASSERT_TRUE(!ConCell.getStatus());
}
TEST(Life, ConwayMutate5) {
	ConwayCell ConCell;
	ConCell.changeStatus('*');
	ConCell.mutate(2);
	ASSERT_TRUE(ConCell.getStatus());
}
TEST(Life, ConwayChangePrint1) {
	ConwayCell ConCell;
	ConCell.changeStatus('*');
	ASSERT_TRUE(ConCell.printStatus() == '*');
}
TEST(Life, ConwayChangePrint2) {
	ConwayCell ConCell;
	ConCell.changeStatus('.');
	ASSERT_TRUE(ConCell.printStatus() == '.');
}

TEST(Life, FredkinMutate1) {
	ConwayCell FredCell;
	FredCell.changeStatus('0');
	FredCell.mutate(3);
	ASSERT_TRUE(FredCell.getStatus());
}
TEST(Life, FredkinMutate2) {
	FredkinCell FredCell;
	FredCell.changeStatus('-');
	FredCell.mutate(2);
	ASSERT_TRUE(!FredCell.getStatus());
}
TEST(Life, FredkinMutate3) {
	FredkinCell FredCell;
	FredCell.changeStatus('-');
	FredCell.mutate(3);
	ASSERT_TRUE(FredCell.getStatus());
}
TEST(Life, FredkinMutate4) {
	FredkinCell FredCell;
	FredCell.changeStatus('-');
	FredCell.mutate(4);
	ASSERT_TRUE(!FredCell.getStatus());
}
TEST(Life, FredkinNeighbor1) {
	FredkinCell FredCell;
	FredCell.changeStatus('-');
	
	ASSERT_TRUE(!FredCell.isNeighbor(1,5));
}
TEST(Life, FredkinNeighbor2) {
	FredkinCell FredCell;
	FredCell.changeStatus('-');
	
	ASSERT_TRUE(FredCell.isNeighbor(0,5));
}
TEST(Life, FredkinNeighbor3) {
	FredkinCell FredCell;
	FredCell.changeStatus('-');
	
	ASSERT_TRUE(FredCell.isNeighbor(1,0));
}
TEST(Life, FredkinPrint1) {
	FredkinCell FredCell;
	FredCell.changeStatus('6');
	
	ASSERT_TRUE(FredCell.printStatus() == '6');
}
TEST(Life, FredkinPrint2) {
	FredkinCell FredCell;
	FredCell.changeStatus('-');

	ASSERT_TRUE(FredCell.printStatus() == '-');
}

	


