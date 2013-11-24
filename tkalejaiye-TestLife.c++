/* To test the program:
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

#define private public

#include <string>
#include <cstdlib>
#include <stdexcept>
#include "gtest/gtest.h"

#include "Life.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"

using namespace std; 

// --------
// tests
// --------

TEST(isAlive, ConwayisAlive0)
{
	// this was a triumph
	ConwayCell cc('*');
	assert(cc.checkLife());
}

TEST(isAlive, ConwayisAlive1)
{
	// i'm making a note here:
	ConwayCell cc('.');
	assert(!cc.checkLife());
}

TEST(isAlive, FredkinisAlive0)
{
	// HUGE SUCCESS
	FredkinCell fc('0');
	assert(fc.checkLife());
}

TEST(isAlive, FredkinisAlive1)
{
	// it's hard to overstate my satisfaction
	FredkinCell fc('8');
	assert(fc.checkLife());
}

TEST(isAlive, FredkinisAlive2)
{
	// Aperture Science
	FredkinCell fc('-');
	assert(!fc.checkLife());
}

TEST(Kill, Conwaykill0)
{
	// we do what we must, because, we can
	ConwayCell cc('*');
	cc.kill();
	assert(!cc.checkLife());
}

TEST(Kill, Conwaykill1)
{
	// for the good of all of us
	ConwayCell cc('-');
	cc.kill();
	assert(!cc.checkLife());
}

TEST(Kill, Fredkinkill0)
{
	// except the ones who are dead
	FredkinCell fc('0');
	fc.kill();
	assert(!fc.checkLife());
}

TEST(Kill, Fredkinkill1)
{
	// except the ones who are dead
	FredkinCell fc('-');
	fc.kill();
	assert(!fc.checkLife());
}

TEST(Kill, Fredkinkill2)
{
	FredkinCell fc('4');
	fc.kill();
	assert(!fc.checkLife());
}

TEST(Kill, Fredkinkill3)
{
	FredkinCell fc('+');
	fc.kill();
	assert(!fc.checkLife());
}

TEST(Age, initAge)
{
	FredkinCell fc('0');
	assert(fc.checkAge() == 0);
}

TEST(Age, grow0)
{
	FredkinCell fc('0');
	fc.grow();
	assert(fc.checkAge() == 1);
}

TEST(Age, grow1)
{
	FredkinCell fc('0');
	for(int i = 0; i < 4; i++) fc.grow();
	assert(fc.checkAge() == 4);
}

TEST(Age, grow2)
{
	FredkinCell fc('0');
	for(int i = 0; i < 8; i++) fc.grow();
	assert(fc.checkAge() == 8);
}

TEST(Age, grow3)
{
	FredkinCell fc('0');
	for(int i = 0; i < 12; i++) fc.grow();
	assert(fc.checkAge() == 12);
}

TEST(Print, ConwayPrint0)
{
	ConwayCell cc('*');
	assert(cc.print().compare("*") == 0);
}

TEST(Print, ConwayPrint1)
{
	ConwayCell cc('.');
	assert(cc.print().compare(".") == 0);
}

TEST(Print, FredkinPrint0)
{
	FredkinCell fc('0');
	assert(fc.print().compare("0") == 0);
}

TEST(Print, FredkinPrint1)
{
	FredkinCell fc('-');
	assert(fc.print().compare("-") == 0);
}

TEST(Print, GrowthPrint0)
{
	FredkinCell fc('0');
	for(int i = 0; i < 8; i++) fc.grow();
	assert(fc.print().compare("8") == 0);
}

TEST(Print, GrowthPrint1)
{
	FredkinCell fc('0');
	for(int i = 0; i < 16; i++) fc.grow();
	assert(fc.print().compare("+") == 0);
}

TEST(Print, GrowthPrint2)
{
	FredkinCell fc('-');
	fc.grow();
	assert(fc.print().compare("-") == 0);
}

// these tests will pass with (requested size + 2);
// we are using a gutter to avoid out of bounds, YMMV
TEST(LifeConstruct, construct0)
{
	Life<ConwayCell> li(64, 64);
	assert(li.board.size() == 66);
	assert(li.board[0].size() == 66);
}

TEST(LifeConstruct, construct1)
{
	Life<ConwayCell> li(256, 256);
	assert(li.board.size() == 258);
	assert(li.board[0].size() == 258);
}

TEST(LifeConstruct, construct2)
{
	Life<FredkinCell> li(512, 512);
	assert(li.board.size() == 514);
	assert(li.board[0].size() == 514);
}

TEST(LifeConstruct, construct3)
{
	Life<FredkinCell> li(1024, 1024);
	assert(li.board.size() == 1026);
	assert(li.board[0].size() == 1026);
}

TEST(LifePlacement, place0)
{
	Life<ConwayCell> li(4, 4);
	ConwayCell cc('*');
	li.place(2, 2, cc);
	assert(li.board[2][2].print().compare("*") == 0);
}

TEST(LifePlacement, place1)
{
	Life<ConwayCell> li(4, 4);
	ConwayCell cc('.');
	li.place(3, 3, cc);
	assert(li.board[3][3].print().compare(".") == 0);
}

TEST(LifePlacement, place2)
{
	Life<FredkinCell> li(4, 4);
	FredkinCell fc('0');
	li.place(1, 1, fc);
	assert(li.board[1][1].print().compare("0") == 0);
}

TEST(LifePlacement, place3)
{
	Life<FredkinCell> li(4, 4);
	FredkinCell fc('-');
	li.place(4, 4, fc);
	assert(li.board[4][4].print().compare("-") == 0);
}

TEST(Census, census0)
{
	Life<ConwayCell> li(3, 3);
	ConwayCell cc('*');
	li.place(1, 1, cc);
	li.place(1, 2, cc);
	assert(li.census() == 2);
}

TEST(Census, census1)
{
	Life<ConwayCell> li(20, 20);
	ConwayCell cc('*');
	li.place(1, 1, cc);
	li.place(1, 2, cc);
	li.place(1, 3, cc);
	li.place(1, 4, cc);
	li.place(1, 5, cc);
	assert(li.census() == 5);
}

TEST(ConwayLife, blinkerGen1)
{
	Life<ConwayCell> li(5, 5);
	ConwayCell cc('*');
	li.place(2, 3, cc);
	li.place(3, 3, cc);
	li.place(4, 3, cc);
	li.theNextGeneration();
	assert(li.board[3][2].print().compare("*") == 0);
	assert(li.board[3][4].print().compare("*") == 0);
	assert(li.board[3][4].print().compare("*") == 0);
}

TEST(ConwayLife, blinkerGen2)
{
	Life<ConwayCell> li(5, 5);
	ConwayCell cc('*');
	li.place(2, 3, cc);
	li.place(3, 3, cc);
	li.place(4, 3, cc);
	li.theNextGeneration();
	li.theNextGeneration();
	assert(li.board[2][3].print().compare("*") == 0);
	assert(li.board[3][3].print().compare("*") == 0);
	assert(li.board[4][3].print().compare("*") == 0);
}

TEST(ConwayLife, blockGen1)
{
	Life<ConwayCell> li(4, 4);
	ConwayCell cc('*');
	li.place(2, 2, cc);
	li.place(2, 3, cc);
	li.place(3, 2, cc);
	li.place(3, 3, cc);
	li.theNextGeneration();
	assert(li.board[2][2].print().compare("*") == 0);
	assert(li.board[2][3].print().compare("*") == 0);
	assert(li.board[3][2].print().compare("*") == 0);
	assert(li.board[3][3].print().compare("*") == 0);
}

TEST(ConwayLife, blockGen4)
{
	Life<ConwayCell> li(4, 4);
	ConwayCell cc('*');
	li.place(2, 2, cc);
	li.place(2, 3, cc);
	li.place(3, 2, cc);
	li.place(3, 3, cc);
	li.theNextGeneration();
	li.theNextGeneration();
	li.theNextGeneration();
	li.theNextGeneration();
	assert(li.board[2][2].print().compare("*") == 0);
	assert(li.board[2][3].print().compare("*") == 0);
	assert(li.board[3][2].print().compare("*") == 0);
	assert(li.board[3][3].print().compare("*") == 0);
}

TEST(FredkinLife, borderGen1)
{
	Life<FredkinCell> li(4, 4);
	FredkinCell fc('0');
	li.place(2, 2, fc);
	li.place(2, 3, fc);
	li.place(3, 2, fc);
	li.place(3, 3, fc);
	li.theNextGeneration();
	assert(li.board[1][2].print().compare("0") == 0);
	assert(li.board[1][3].print().compare("0") == 0);
	assert(li.board[2][1].print().compare("0") == 0);
	assert(li.board[3][1].print().compare("0") == 0);
	assert(li.board[4][2].print().compare("0") == 0);
	assert(li.board[4][3].print().compare("0") == 0);
	assert(li.board[2][4].print().compare("0") == 0);
	assert(li.board[3][4].print().compare("0") == 0);
}

TEST(FredkinLife, borderGen2)
{
	Life<FredkinCell> li(4, 4);
	FredkinCell fc('0');
	li.place(2, 2, fc);
	li.place(2, 3, fc);
	li.place(3, 2, fc);
	li.place(3, 3, fc);
	li.theNextGeneration();
	li.theNextGeneration();
	assert(li.board[1][2].print().compare("1") == 0);
	assert(li.board[1][3].print().compare("1") == 0);
	assert(li.board[2][1].print().compare("1") == 0);
	assert(li.board[3][1].print().compare("1") == 0);
	assert(li.board[4][2].print().compare("1") == 0);
	assert(li.board[4][3].print().compare("1") == 0);
	assert(li.board[2][4].print().compare("1") == 0);
	assert(li.board[3][4].print().compare("1") == 0);
}


TEST(FredkinLife, pairGen1)
{
	Life<FredkinCell> li(4, 4);
	FredkinCell fc('0');
	li.place(2, 2, fc);
	li.place(2, 3, fc);
	li.theNextGeneration();
	assert(li.board[1][2].print().compare("0") == 0);
	assert(li.board[1][3].print().compare("0") == 0);
	assert(li.board[2][2].print().compare("1") == 0);
	assert(li.board[2][3].print().compare("1") == 0);
	assert(li.board[3][2].print().compare("0") == 0);
	assert(li.board[3][3].print().compare("0") == 0);
}
