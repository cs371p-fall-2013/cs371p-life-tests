#include <iostream>
#include <string>
#include <cassert>
#include <fstream>
#include <stdlib.h>

#ifndef ConwayCellHeader
#define ConwayCellHeader
#include "ConwayCell.h"
#endif

#ifndef FredkinCellHeader
#define FredkinCellHeader
#include "FredkinCell.h"
#endif

#ifndef cellHeader
#define cellHeader
#include "Cell.h"
#endif

#include "Life.h"

#include "gtest/gtest.h"

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



//////////////////////////////////////////////////////////////////////
//Conwaycell Tests

//charConstructor
TEST(ConwayCell, charConstructor1){
using namespace std;
	ConwayCell c('.');
	assert(!c.isAlive());
	assert(c.toSymbol() == '.');
}

TEST(ConwayCell, charConstructor2){
using namespace std;
	ConwayCell c('*');
	assert(c.isAlive());
	assert(c.toSymbol() == '*');
}

TEST(ConwayCell, charConstructor3){
using namespace std;
	ConwayCell c('.');
	assert(c.isAlive() == false);
	assert(c.toSymbol() != '*');
}
////////////////////////////////////////////////
//clone
TEST(ConwayCell, clone1){
using namespace std;
	ConwayCell c('*');
	ConwayCell* temp = c.clone();
	assert(temp->toSymbol() == '*');
	delete temp;
}

TEST(ConwayCell, clone2){
using namespace std;
	ConwayCell c('*');
	ConwayCell* temp = c.clone();
	assert(temp->isAlive() == true);
	delete temp;
}

TEST(ConwayCell, clone3){
using namespace std;
	ConwayCell c('.');
	ConwayCell* temp = c.clone();
	assert(temp->toSymbol() == '.');
	delete temp;
}
///////////////////////////////////////////////////
//toSymbol
TEST(ConwayCell, toSymbol1){
using namespace std;
	ConwayCell x('.');
	assert(x.toSymbol() == '.');
}

TEST(ConwayCell, toSymbol2){
using namespace std;
	ConwayCell x('*');
	assert(x.toSymbol() == '*');
}

TEST(ConwayCell, toSymbol13){
using namespace std;
	ConwayCell x('*');
	ConwayCell y(x);
	assert(y.toSymbol() == '*');
}
//////////////////////////////////////////////////
//numNeighbors
TEST(ConwayCell, numNeighbors1){
using namespace std;
	ConwayCell x('.');
	assert(x.numNeighbors() == 8);
}

TEST(ConwayCell, numNeighbors2){
using namespace std;
	ConwayCell x('*');
	assert(x.numNeighbors() == 8);
}

TEST(ConwayCell, numNeighbors3){
using namespace std;
	ConwayCell x('.');
	ConwayCell y(x);
	assert(y.numNeighbors() == 8);
}
////////////////////////////////////////////////////
//isAlive
TEST(ConwayCell, isAlive1){
using namespace std;
	ConwayCell x('.');
	assert(!x.isAlive());
}

TEST(ConwayCell, isAlive2){
using namespace std;
	ConwayCell x('*');
	assert(x.isAlive());
}

TEST(ConwayCell, isAlive3){
using namespace std;
	ConwayCell x('.');
	ConwayCell yy(x);
	assert(!yy.isAlive());
}
//////////////////////////////////////////////////////
//updateNextState
TEST(ConwayCell, updateNextState1){
using namespace std;
	bool temp[8];
	ConwayCell p1('*');
	ConwayCell p2('*');
	ConwayCell p3('*');
	temp[0] = p1.isAlive();
	temp[1] = p2.isAlive();
	temp[2] = p3.isAlive();
	ConwayCell x('.');		//dead becoming alive
	assert(!x.isAlive());
	x.updateNextState(temp, 3);
	x.swapState();
	assert(x.isAlive());
}

TEST(ConwayCell, updateNextState2){
using namespace std;
	bool temp[8];
	ConwayCell p1('*');
	ConwayCell p2('*');
	ConwayCell p3('*');
	ConwayCell p4('*');
	temp[0] = p1.isAlive();
	temp[1] = p2.isAlive();
	temp[2] = p3.isAlive();
	temp[3] = p4.isAlive();
	ConwayCell x('*');		//alive becoming dead
	assert(x.isAlive());
	x.updateNextState(temp, 4);
	x.swapState();
	assert(!x.isAlive());
}

TEST(ConwayCell, updateNextState3){
using namespace std;
	bool temp[8];
	ConwayCell p1('*');
	ConwayCell p2('*');
	ConwayCell p3('*');
	temp[0] = p1.isAlive();
	temp[1] = p2.isAlive();
	temp[2] = p3.isAlive();
	ConwayCell x('*');		//live staying alive
	assert(x.isAlive());
	x.updateNextState(temp, 3);
	x.swapState();
	assert(x.isAlive());
}

TEST(ConwayCell, updateNextState4){
using namespace std;
	bool temp[8];
	ConwayCell p1('.');
	ConwayCell p2('*');
	ConwayCell p3('*');
	temp[0] = p1.isAlive();
	temp[1] = p2.isAlive();
	temp[2] = p3.isAlive();
	ConwayCell x('.');		//dead staying dead
	assert(!x.isAlive());
	x.updateNextState(temp, 3);
	x.swapState();
	assert(!x.isAlive());
}
////////////////////////////////////////////////
//swapState
TEST(ConwayCell, swapState1){
using namespace std;
	ConwayCell x('*');
	assert(x.isAlive());
	x.swapState();
	assert(x.isAlive());		//default nextState alive
}

TEST(ConwayCell, swapState2){
using namespace std;
	ConwayCell x('.');
	assert(!x.isAlive());
	x.swapState();
	assert(x.isAlive());		//default nextState alive
}

//////////////////////////////////////////////////////////////
//FredkinCell Tests

//constructor
TEST(FredkinCell, charConstructor1){
using namespace std;
	FredkinCell x('-');
	assert(!x.isAlive());
}

TEST(FredkinCell, charConstructor2){
using namespace std;
	FredkinCell x('0');
	assert(x.isAlive());
}

TEST(FredkinCell, charConstructor3){
using namespace std;
	FredkinCell x('-');
	FredkinCell y(x);
	assert(!y.isAlive());
}
/////////////////////////////////////////////////////////////
//clone
TEST(FredkinCell, clone1){
using namespace std;
	FredkinCell c('0');
	FredkinCell* temp = c.clone();
	assert(temp->toSymbol() == '0');
	delete temp;
}

TEST(FredkinCell, clone2){
using namespace std;
	FredkinCell c('0');
	FredkinCell* temp = c.clone();
	assert(temp->isAlive() == true);
	delete temp;
}

TEST(FredkinCell, clone3){
using namespace std;
	FredkinCell c('-');
	FredkinCell* temp = c.clone();
	assert(temp->toSymbol() == '-');
	delete temp;
}
//////////////////////////////////////////////////////////////
//toSymbol
TEST(FredkinCell, toSymbol1){
using namespace std;
	FredkinCell x('-');
	assert(x.toSymbol() == '-');
}

TEST(FredkinCell, toSymbol2){
using namespace std;
	FredkinCell x('0');
	assert(x.toSymbol() == '0');
}

TEST(FredkinCell, toSymbol13){
using namespace std;
	FredkinCell x('0');
	FredkinCell y(x);
	assert(y.toSymbol() == '0');
}
////////////////////////////////////////////////////////////
//numNeighbors
TEST(FredkinCell, numNeighbors1){
using namespace std;
	FredkinCell x('-');
	assert(x.numNeighbors() == 4);
}

TEST(FredkinCell, numNeighbors2){
using namespace std;
	FredkinCell x('0');
	assert(x.numNeighbors() == 4);
}

TEST(FredkinCell, numNeighbors3){
using namespace std;
	FredkinCell x('-');
	FredkinCell y(x);
	assert(y.numNeighbors() == 4);
}
/////////////////////////////////////////////////////////////////
//isAlive
TEST(FredkinCell, isAlive1){
using namespace std;
	FredkinCell x('-');
	assert(!x.isAlive());
}

TEST(FredkinCell, isAlive2){
using namespace std;
	FredkinCell x('0');
	assert(x.isAlive());
}

TEST(FredkinCell, isAlive3){
using namespace std;
	FredkinCell x('-');
	FredkinCell yy(x);
	assert(!yy.isAlive());
}
//////////////////////////////////////////////////////////////////////
//updateNextState
TEST(FredkinCell, updateNextState1){
using namespace std;
	bool temp[3];
	FredkinCell p1('0');
	FredkinCell p2('0');
	FredkinCell p3('0');
	temp[0] = p1.isAlive();
	temp[1] = p2.isAlive();
	temp[2] = p3.isAlive();
	FredkinCell x('-');		//dead becoming alive
	assert(!x.isAlive());
	x.updateNextState(temp, 3);
	x.swapState();
	assert(x.isAlive());
}

TEST(FredkinCell, updateNextState2){
using namespace std;
	bool temp[1];
	FredkinCell p1('0');
	temp[0] = p1.isAlive();
	FredkinCell x('-');		//dead becoming alive
	assert(!x.isAlive());
	x.updateNextState(temp, 1);
	x.swapState();
	assert(x.isAlive());
}

TEST(FredkinCell, updateNextState3){
using namespace std;
	bool temp[4];
	FredkinCell p1('0');		//4 alive cells
	FredkinCell p2('0');
	FredkinCell p3('0');
	FredkinCell p4('0');
	temp[0] = p1.isAlive();
	temp[1] = p2.isAlive();
	temp[2] = p3.isAlive();
	temp[3] = p4.isAlive();
	FredkinCell x('0');		//alive becoming dead
	assert(x.isAlive());
	x.updateNextState(temp, 4);
	x.swapState();
	assert(!x.isAlive());
}

TEST(FredkinCell, updateNextState4){
using namespace std;
	bool temp[2];
	FredkinCell p1('0');		//2 alive cells
	FredkinCell p2('0');
	temp[0] = p1.isAlive();
	temp[1] = p2.isAlive();
	FredkinCell x('0');		//alive becoming dead
	assert(x.isAlive());
	x.updateNextState(temp, 2);
	x.swapState();
	assert(!x.isAlive());
}

TEST(FredkinCell, updateNextState5){
using namespace std;
	bool temp[1];
	FredkinCell p1('-');		//0 alive cells
	temp[0] = p1.isAlive();
	FredkinCell x('0');		//alive becoming dead
	assert(x.isAlive());
	x.updateNextState(temp, 1);
	x.swapState();
	assert(!x.isAlive());
}
/////////////////////////////////////////////////////////////////
//swapState
TEST(FredkinCell, swapState1){
using namespace std;
	FredkinCell x('0');
	assert(x.isAlive());
	x.swapState();
	assert(x.isAlive());		//default nextState alive
}
///////////////////////////////////////////////////////////////////
//getAge
TEST(FredkinCell, getAge1){
using namespace std;
	FredkinCell x('0');
	assert(x.getAge() == 0);
	x.swapState();
	assert(x.getAge() == 1);		//default nextState alive
}

TEST(FredkinCell, getAge2){
using namespace std;
	FredkinCell x('0');
	assert(x.getAge() == 0);
	x.swapState();
	x.swapState();
	assert(x.getAge() == 2);		//default nextState alive
}

TEST(FredkinCell, getAge3){
using namespace std;
	FredkinCell x('0');
	assert(x.getAge() == 0);
	x.swapState();
	x.swapState();
	x.swapState();
	assert(x.getAge() == 3);		//default nextState alive
}
//////////////////////////////////////////////////////////////////
//getNextState
TEST(FredkinCell, getNextState1){
using namespace std;
	FredkinCell x('0');
	assert(x.getNextState());	//default true
}

TEST(FredkinCell, getNextState2){
using namespace std;
	bool temp[4];
	FredkinCell p1('0');		//4 alive cells
	FredkinCell p2('0');
	FredkinCell p3('0');
	FredkinCell p4('0');
	temp[0] = p1.isAlive();
	temp[1] = p2.isAlive();
	temp[2] = p3.isAlive();
	temp[3] = p4.isAlive();
	FredkinCell x('0');		//alive becoming dead
	assert(x.getNextState());
	x.updateNextState(temp, 4);
	assert(!x.getNextState());
}

TEST(FredkinCell, getNextState3){
using namespace std;
	bool temp[4];
	FredkinCell p1('0');		//2 alive cells
	FredkinCell p2('0');
	temp[0] = p1.isAlive();
	temp[1] = p2.isAlive();
	FredkinCell x('0');		//alive becoming dead
	assert(x.getNextState());
	x.updateNextState(temp, 2);
	assert(!x.getNextState());
}
/////////////////////////////////////////////////////////////
//Cell Tests

//cellCharacterConstructor
TEST(Cell, cellCharacterConstructor1){
	Cell y('.');
	assert(y.toSymbol() == '.');
}

TEST(Cell, cellCharacterConstructor2){
	Cell y('*');
	assert(y.toSymbol() == '*');
}

TEST(Cell, cellCharacterConstructor3){
	Cell y('0');
	assert(y.toSymbol() == '0');
}

TEST(Cell, cellCharacterConstructor4){
	Cell y('-');
	assert(y.toSymbol() == '-');
}
/////////////////////////////////////////////////////////////////
//toSYmbol

TEST(Cell, toSymbol1){
	Cell x('0');
	assert(x.toSymbol() != '*');
}

TEST(Cell, toSymbol2){
	Cell y('.');
	assert(y.toSymbol() != '-');
}
/////////////////////////////////////////////////////////////////
//numNeighbors

TEST(Cell, numNeighbors1){
using namespace std;
	Cell x('-');
	assert(x.numNeighbors() == 4);
}

TEST(Cell, numNeighbors2){
using namespace std;
	Cell x('0');
	assert(x.numNeighbors() == 4);
}

TEST(Cell, numNeighbors3){
using namespace std;
	Cell x('*');
	Cell y(x);
	assert(y.numNeighbors() == 8);
}

TEST(Cell, numNeighbors5){
using namespace std;
	Cell x('.');
	Cell y(x);
	assert(y.numNeighbors() == 8);
}
/////////////////////////////////////////////////////////////////////
//isAlive
TEST(Cell, isAlive1){
using namespace std;
	Cell x('-');
	assert(!x.isAlive());
}

TEST(Cell, isAlive2){
using namespace std;
	Cell x('0');
	assert(x.isAlive());
}

TEST(Cell, isAlive3){
using namespace std;
	Cell x('.');
	Cell yy(x);
	assert(!yy.isAlive());
}

TEST(Cell, isAlive4){
using namespace std;
	Cell x('*');
	Cell yy(x);
	assert(yy.isAlive());
}
/////////////////////////////////////////////////////////////////////////
//updateNextState
TEST(Cell, updateNextState1){
using namespace std;
	Cell x(new ConwayCell('.'));					//conwaycell, 3 live neighbors, dead turning alive
	bool temp[8];
	Cell f1(new FredkinCell('0'));
	Cell c1(new ConwayCell('*'));
	Cell f2(new FredkinCell('0'));
	temp[0] = f1.isAlive();
	temp[1] = f2.isAlive();
	temp[2] = c1.isAlive();
	temp[3] = false;
	temp[4] = false;
	temp[5] = false;
	temp[6] = false;
	temp[7] = false;
	assert(!x.isAlive());
	x.updateNextState(temp, 8);		//conway cell has 8 neighbors
	x.swapState();
	assert(x.isAlive());
}

TEST(Cell, updateNextState2){
using namespace std;
	Cell x(new ConwayCell('*'));					//conwaycell, 3 live neighbors, alive staying alive
	bool temp[8];
	Cell f1(new FredkinCell('0'));
	Cell c1(new ConwayCell('*'));
	Cell f2(new FredkinCell('0'));
	temp[0] = f1.isAlive();
	temp[1] = f2.isAlive();
	temp[2] = c1.isAlive();
	temp[3] = false;
	temp[4] = false;
	temp[5] = false;
	temp[6] = false;
	temp[7] = false;
	assert(x.isAlive());
	x.updateNextState(temp, 8);		//conway cell has 8 neighbors
	x.swapState();
	assert(x.isAlive());
}

TEST(Cell, updateNextState3){
using namespace std;
	Cell x(new FredkinCell('-'));					//fredkinCell, 1 live neighbors, dead turning alive
	bool temp[4];
	Cell f1(new FredkinCell('0'));
	temp[0] = f1.isAlive();
	temp[1] = false;
	temp[2] = false;
	temp[3] = false;
	assert(!x.isAlive());
	x.updateNextState(temp, 4);		//fredkincell has 4 neighbors
	x.swapState();
	assert(x.isAlive());
}

TEST(Cell, updateNextState4){
using namespace std;
	Cell x(new FredkinCell('-'));					//fredkinCell, 2 live neighbors, dead staying dead
	bool temp[4];
	Cell f1(new FredkinCell('0'));
	Cell c1(new ConwayCell('*'));
	temp[0] = f1.isAlive();
	temp[1] = c1.isAlive();
	temp[2] = false;
	temp[3] = false;
	assert(!x.isAlive());
	x.updateNextState(temp, 4);		//fredkincell has 4 neighbors
	x.swapState();
	assert(!x.isAlive());
}

TEST(Cell, updateNextState5){
using namespace std;
	Cell x(new FredkinCell('0'));					//fredkinCell, 1 live neighbor, alive staying alive
	bool temp[4];
	Cell f1(new FredkinCell('0'));
	temp[0] = f1.isAlive();
	temp[1] = false;
	temp[2] = false;
	temp[3] = false;
	assert(x.isAlive());
	x.updateNextState(temp, 4);		//fredkincell has 4 neighbors
	x.swapState();
	assert(x.isAlive());
}

TEST(Cell, updateNextState6){
using namespace std;
	Cell x(new ConwayCell('.'));					//conwaycell, 2 live neighbors, dead staying dead
	bool temp[8];
	Cell f1(new FredkinCell('0'));
	Cell c1(new ConwayCell('*'));
	temp[0] = f1.isAlive();
	temp[1] = false;
	temp[2] = c1.isAlive();
	temp[3] = false;
	temp[4] = false;
	temp[5] = false;
	temp[6] = false;
	temp[7] = false;
	assert(!x.isAlive());
	x.updateNextState(temp, 8);		//conway cell has 8 neighbors
	x.swapState();
	assert(!x.isAlive());
}
/////////////////////////////////////////////////////////////////////////////
//mutate
TEST(Cell, mutate1){
using namespace std;
	Cell x(new FredkinCell('0'));		//mutating fredkincell to conwaycell			
	assert(x.toSymbol() == '0');
	x.mutate();
	assert(x.toSymbol() == '*');
}
////////////////////////////////////////////////////////////////////////////////
//life tests
TEST(Life, simulation1){
using namespace std;
	ifstream inputConway("RunLifeConway.in");
	string line;
	int testCount = 0;
	//main loop for reading conway cell test cases
	while(getline(inputConway, line)){
		if(testCount != 0)
			getline(inputConway, line);
		int rows = atoi(line.c_str());
		getline(inputConway, line);
		int cols = atoi(line.c_str());
		Life<ConwayCell> newlife(rows, cols);
		newlife.populate(inputConway, rows, cols);
		//loop for going through generations. specify which grid to print in here
		for(int i = 0; i < 5; i++){				
			newlife.gridNextState();
			newlife.updateGrid();
		}
		testCount++;
	}
}

TEST(Life, simulation2){
using namespace std;
	ifstream inputFredkin("RunLifeFredkin.in");
	int testCount = 0;
	string line2;
	while(getline(inputFredkin, line2)){
		if(testCount != 0)
			getline(inputFredkin, line2);
		int rows = atoi(line2.c_str());
		getline(inputFredkin, line2);
		int cols = atoi(line2.c_str());
		Life<FredkinCell> newlife(rows, cols);
		newlife.populate(inputFredkin, rows, cols);
		//loop for going through generations. specify which grid to print in here
		for(int i = 0; i < 5; i++){				
			newlife.gridNextState();
			newlife.updateGrid();
		}
		testCount++;
	}
}

TEST(Life, simulation3){
using namespace std;
	ifstream inputCell("RunLifeCell.in");
	int testCount = 0;
	string line3;
	while(getline(inputCell, line3)){
		if(testCount != 0)
			getline(inputCell, line3);
		int rows = atoi(line3.c_str());
		getline(inputCell, line3);
		int cols = atoi(line3.c_str());
		Life<Cell> newlife(rows, cols);
		newlife.populate(inputCell, rows, cols);
		//loop for going through generations. specify which grid to print in here
		for(int i = 0; i < 5; i++){				
			newlife.gridNextState();
			newlife.updateGrid();
		}
		testCount++;
	}  
}

