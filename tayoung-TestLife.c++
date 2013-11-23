// ------------------------------
// projects/darwin/TestDarwin.c++
// Copyright (C) 2013
// Tyler A. Young
// ------------------------------

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

    % valgrind TestAllocator > TestAllocator.out
*/

// --------
// includes
// --------

#include <algorithm> // count
#include <memory>    // allocator

#include "gtest/gtest.h"

#include <cassert>   // assert
#include <cstdlib>   // rand, srand
#include <iostream>  // cout, endl
#include <stdexcept> // invalid_argument, out_of_range
#include <string>

#define private public
#define protected public
#define class struct

#include "AbstractCell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"
#include "Life.h"

void print_vectors(const std::vector<position>& v1, const std::vector<position>& v2)
{
	using namespace std;
	for(int i=0; i < v1.size(); i++)
		cout << "v[" << i << "] = " << v1[i] << ", neighbor[" << i << "] = " << v2[i] << endl;
}

// ------------------------------------------------------------------------- //
//                                   LIFE                                    //
// ------------------------------------------------------------------------- //

// ------------
// Constructors
// ------------
TEST(TestLife,constructor){
    using namespace std;
    Life<Cell> life(3,3, new ConwayCell());

    ASSERT_EQ(life.g.size(),3);
    ASSERT_EQ(life.g[0].size(),3);
}

// ---
// add
// ---
TEST(TestLife,add){
	using namespace std;
	Life<ConwayCell> life(5,5, new ConwayCell());
	life.add(new ConwayCell(1, 4, true));
	ASSERT_TRUE(life.g[1][4].get_state());
}

// ------------------------------------------------------------------------- //
//                                CONWAYCELL                                 //
// ------------------------------------------------------------------------- //

// ---------------
// get_status_char
// ---------------
TEST(TestConwayCell,get_status_char1){
	using namespace std;
	ConwayCell c(0, 0, true);
	ASSERT_EQ(c.get_status_char(),'*');
}
TEST(TestConwayCell,get_status_char2){
	using namespace std;
	ConwayCell c(0, 0, false);
	ASSERT_EQ(c.get_status_char(),'.');
}

// -------------
// get_neighbors
// -------------
TEST(TestConwayCell,get_neighbors1){
	using namespace std;
	ConwayCell c(0, 0, true);
	vector<position> v;
	v.push_back({1,0});
	v.push_back({1,1});
	v.push_back({0,1});
	vector<position> neighbors = *c.get_neighbors(3,3);
	ASSERT_EQ(v.size(), (c.get_neighbors(3,3))->size());

	bool vectors_match = neighbors == v;

	ASSERT_TRUE(vectors_match);
}
TEST(TestConwayCell,get_neighbors2){
	using namespace std;
	ConwayCell c(1, 0, true);
	vector<position> v;
	v.push_back({2,0});
	v.push_back({2,1});
	v.push_back({1,1});
	v.push_back({0,1});
	v.push_back({0,0});
	vector<position> neighbors = *c.get_neighbors(3,3);
	ASSERT_EQ(v.size(), (c.get_neighbors(3,3))->size());

//	print_vectors(v, neighbors);

	bool vectors_match = neighbors == v;

	ASSERT_TRUE(vectors_match);
}
TEST(TestConwayCell,get_neighbors3){
	using namespace std;
	ConwayCell c(1, 1, true);
	vector<position> v;
	v.push_back({1,0});
	v.push_back({2,0});
	v.push_back({2,1});
	v.push_back({2,2});
	v.push_back({1,2});
	v.push_back({0,2});
	v.push_back({0,1});
	v.push_back({0,0});
	vector<position> neighbors = *c.get_neighbors(8,8);
	ASSERT_EQ(v.size(), (c.get_neighbors(8,8))->size());

//	print_vectors(v, neighbors);

	bool vectors_match = neighbors == v;

	ASSERT_TRUE(vectors_match);
}
TEST(TestConwayCell,get_neighbors4){
	using namespace std;
	ConwayCell c(1, 8, true);
	vector<position> v;
	v.push_back({1,7});
	v.push_back({2,7});
	v.push_back({2,8});
	v.push_back({0,8});
	v.push_back({0,7});
	vector<position> neighbors = *c.get_neighbors(9,9);
	ASSERT_EQ(v.size(), (c.get_neighbors(9,9))->size());

//	print_vectors(v, neighbors);

	bool vectors_match = neighbors == v;

	ASSERT_TRUE(vectors_match);
}

// ------------------------------------------------------------------------- //
//                                FREDKINCELL                                //
// ------------------------------------------------------------------------- //

// ---------------
// get_status_char
// ---------------
TEST(TestFredkinCell,get_status_char1){
	using namespace std;
	FredkinCell c(0, 0, true);
	c.age = 5;
	ASSERT_EQ(c.get_status_char(),'5');
}
TEST(TestFredkinCell,get_status_char2){
	using namespace std;
	FredkinCell c(0, 0, false);
	c.age = 5;
	ASSERT_EQ(c.get_status_char(),'-');
}
TEST(TestFredkinCell,get_status_char3){
	using namespace std;
	FredkinCell c(0, 0, true);
	c.age = 10;
	ASSERT_EQ(c.get_status_char(),'+');
}

// -------------
// get_neighbors
// -------------
TEST(TestFredkinCell,get_neighbors1){
	using namespace std;
	FredkinCell c(0, 0, true);
	vector<position> v;
	v.push_back({1,0});
	v.push_back({0,1});
	vector<position> neighbors = *c.get_neighbors(3,3);
	ASSERT_EQ(v.size(), (c.get_neighbors(3,3))->size());

	bool vectors_match = neighbors == v;

	ASSERT_TRUE(vectors_match);
}
TEST(TestFredkinCell,get_neighbors2){
	using namespace std;
	FredkinCell c(1, 0, true);
	vector<position> v;
	v.push_back({2,0});
	v.push_back({1,1});
	v.push_back({0,0});
	vector<position> neighbors = *c.get_neighbors(3,3);
	ASSERT_EQ(v.size(), (c.get_neighbors(3,3))->size());

//	print_vectors(v, neighbors);

	bool vectors_match = neighbors == v;

	ASSERT_TRUE(vectors_match);
}
TEST(TestFredkinCell,get_neighbors3){
	using namespace std;
	FredkinCell c(1, 1, true);
	vector<position> v;
	v.push_back({1,0});
	v.push_back({2,1});
	v.push_back({1,2});
	v.push_back({0,1});
	vector<position> neighbors = *c.get_neighbors(3,3);
	ASSERT_EQ(v.size(), (c.get_neighbors(3,3))->size());

	bool vectors_match = neighbors == v;

	ASSERT_TRUE(vectors_match);
}
TEST(TestFredkinCell,get_neighbors4){
	using namespace std;
	FredkinCell c(1, 2, true);
	vector<position> v;
	v.push_back({1,1});
	v.push_back({2,2});
	v.push_back({0,2});
	vector<position> neighbors = *c.get_neighbors(3,3);
	ASSERT_EQ(v.size(), (c.get_neighbors(3,3))->size());

	bool vectors_match = neighbors == v;

	ASSERT_TRUE(vectors_match);
}

// ------------------------------------------------------------------------- //
//                                   CELL                                    //
// ------------------------------------------------------------------------- //

// ------------
// Constructors
// ------------
TEST(TestCell,constructor1){
	using namespace std;
	Cell c = new ConwayCell(1,1, true);

	ASSERT_EQ(c.get_status_char(),'*');
}
TEST(TestCell,constructor2){
	using namespace std;
	Cell c = new FredkinCell(1,1, true);

	ASSERT_EQ(c.get_status_char(),'0');
}

// ---------
// get_state
// ---------
TEST(TestCell,get_state1){
	using namespace std;
	Cell c = new FredkinCell(1, 2, true);

	ASSERT_TRUE(c.get_state());
}
TEST(TestCell,get_state2){
	using namespace std;
	Cell c = new FredkinCell(1, 2, '0');

	ASSERT_TRUE(c.get_state());
}
TEST(TestCell,get_state3){
	using namespace std;
	Cell c = new FredkinCell(1, 2, '-');

	ASSERT_FALSE(c.get_state());
}

// --------------
// set_state_hard
// --------------
TEST(TestCell,set_state_hard1){
	using namespace std;
	Cell c = new ConwayCell(1, 2, true);
	c.set_state_hard();

	ASSERT_FALSE(c.get_state());
}
TEST(TestCell,set_state_hard2){
	using namespace std;
	Cell c = new ConwayCell(1, 2, false);
	c.set_state_hard();

	ASSERT_TRUE(c.get_state());
}

// ---------
// get_pos
// ---------
TEST(TestCell,get_pos1){
	using namespace std;
	Cell c = new ConwayCell(1, 2, false);
	position p = {1,2};

	ASSERT_EQ(c.get_pos(),p);
}
TEST(TestCell,get_pos2){
	using namespace std;
	Cell c = new ConwayCell(4, 5, false);
	position p = {4,5};

	ASSERT_EQ(c.get_pos(),p);
}
TEST(TestCell,get_pos3){
	using namespace std;
	Cell c = new FredkinCell(3, 2, '+');
	position p = {3,2};

	ASSERT_EQ(c.get_pos(),p);
}

// ---------
// set_state
// ---------
TEST(TestCell,set_state1){
	using namespace std;
	Cell c = new ConwayCell(1, 2, true);
	c.set_state('.');

	ASSERT_FALSE(c.get_state());
}
TEST(TestCell,set_state2){
	using namespace std;
	Cell c = new FredkinCell(1, 2, '-');
	c.set_state('+');

	ASSERT_TRUE(c.get_state());
}
TEST(TestCell,set_state3){
	using namespace std;
	Cell c = new FredkinCell(1, 2, '0');
	c.set_state('-');

	ASSERT_FALSE(c.get_state());
}
TEST(TestCell,set_state4){
	using namespace std;
	Cell c = new FredkinCell(1, 2, '-');
	c.set_state('9');

	ASSERT_TRUE(c.get_state());
}
TEST(TestCell,set_state5){
	using namespace std;
	Cell c = new FredkinCell(1, 2, '0');
	c.set_state('1');

	ASSERT_TRUE(c.get_state());
}

// ---------------
// get_status_char
// ---------------
TEST(TestCell,get_status_char1){
	using namespace std;
	Cell c = new ConwayCell(1, 2, true);

	ASSERT_EQ(c.get_status_char(),'*');
}
TEST(TestCell,get_status_char2){
	using namespace std;
	Cell c = new ConwayCell(1, 2, false);

	ASSERT_EQ(c.get_status_char(),'.');
}
TEST(TestCell,get_status_char3){
	using namespace std;
	Cell c = new FredkinCell(1, 2, false);

	ASSERT_EQ(c.get_status_char(),'-');
}
TEST(TestCell,get_status_char4){
	using namespace std;
	Cell c = new FredkinCell(1, 2, '0');

	ASSERT_EQ(c.get_status_char(),'0');
}
TEST(TestCell,get_status_char5){
	using namespace std;
	Cell c = new FredkinCell(1, 2, '1');

	ASSERT_EQ(c.get_status_char(),'1');
}
TEST(TestCell,get_status_char6){
	using namespace std;
	Cell c = new FredkinCell(1, 2, '+');

	ASSERT_EQ(c.get_status_char(),'+');
}
TEST(TestCell,get_status_char7){
	using namespace std;
	Cell c = new FredkinCell(1, 2, '7');

	ASSERT_EQ(c.get_status_char(),'7');
}

// ------
// evolve
// ------
TEST(TestCell,evolve1){
	using namespace std;
	Cell c = new FredkinCell(1, 2, true);
   
	ASSERT_TRUE(c.evolve(0));
}
TEST(TestCell,evolve2){
	using namespace std;
	Cell c = new FredkinCell(1, 2, true);

	ASSERT_TRUE(c.evolve(2));
}
TEST(TestCell,evolve3){
	using namespace std;
	Cell c = new FredkinCell(1, 2, true);

	ASSERT_TRUE(c.evolve(4));
}
TEST(TestCell,evolve4){
	using namespace std;
	Cell c = new ConwayCell(1, 2, false);

	ASSERT_TRUE(c.evolve(3));
}
TEST(TestCell,evolve5){
	using namespace std;
	Cell c = new ConwayCell(1, 2, false);

	ASSERT_FALSE(c.evolve(0));
}
TEST(TestCell,evolve6){
	using namespace std;
	Cell c = new ConwayCell(1, 2, true);

	ASSERT_TRUE(c.evolve(5));
}
TEST(TestCell,evolve7){
	using namespace std;
	Cell c = new ConwayCell(1, 2, false);

	ASSERT_FALSE(c.evolve(2));
}

// ------
// mutate
// ------
TEST(TestCell,mutate){
	using namespace std;
	Cell c = new FredkinCell(1, 2, true);
	c.mutate();

	ASSERT_EQ(c.get_status_char(),'*');
}
