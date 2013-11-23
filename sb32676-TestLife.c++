/*
        name: Seung Youp Baek
        EID: sb32676
        Github ID: sb32676
        CSID: sb32676
        Email: bsy6766@gmail.com
        Course: CS371p 10am
*/

// --------
// includes
// --------
#define private public

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==
#include <stdexcept>

#include "gtest/gtest.h"

#include "Life.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"
#include "AbstractCell.h"

using namespace std;

// -----------
// TestLife
// -----------

// -----------
// Life.h
// -----------

TEST(Life, Life1){
	istringstream iss("1\n1\n1");
	try{
		Life<ConwayCell> life(iss);
	}
	catch(const invalid_argument& ia){
		ASSERT_TRUE(strcmp(ia.what(), "Invalid argument") == 0);
	}
}

TEST(Life, Life2){
	istringstream iss("1\n1\n-");
	try{
		Life<ConwayCell> life(iss);
	}
	catch(const invalid_argument& ia){
		ASSERT_TRUE(strcmp(ia.what(), "Invalid argument") == 0);
	}
}

TEST(Life, Life3){
	istringstream iss("1\n1\n.");
	try{
		Life<FredkinCell> life(iss);
	}
	catch(const invalid_argument& ia){
		ASSERT_TRUE(strcmp(ia.what(), "Invalid argument") == 0);
	}
}

TEST(Life, Life4){
	istringstream iss("1\n1\n*");
	try{
		Life<FredkinCell> life(iss);
	}
	catch(const invalid_argument& ia){
		ASSERT_TRUE(strcmp(ia.what(), "Invalid argument") == 0);
	}
}

TEST(Life, Life5){
	istringstream iss("2\n2\n..\n..");
	try{
		Life<ConwayCell> life(iss);
		ASSERT_TRUE(life.rowSize == 2);
		ASSERT_TRUE(life.colSize == 2);
	}
	catch(const out_of_range& oor){
		ASSERT_TRUE(strcmp(oor.what(), "row or column is out of range") == 0);
	}
}

TEST(Life, Life6){
	istringstream iss("0\n2\n..\n..");
	try{
		Life<ConwayCell> life(iss);
	}
	catch(const out_of_range& oor){
		ASSERT_TRUE(strcmp(oor.what(), "row and column must be greater than 0") == 0);
	}
}

TEST(Life, nextTurn1){
	/*
		..
		..
	*/
	istringstream iss("2\n2\n..\n..");
	Life<ConwayCell> life(iss);
	life.nextTurn();
	for(int i = 0; i<2;i++){
		for(int j = 0; j<2; j++){
			ASSERT_TRUE(!life.map[i][j].getAlive());
		}
	}
}

TEST(Life, nextTurn2){
	/*
		**
		**
	*/
	istringstream iss("2\n2\n**\n**");
	Life<ConwayCell> life(iss);
	life.nextTurn();
	for(int i = 0; i<2;i++){
		for(int j = 0; j<2; j++){
			ASSERT_TRUE(life.map[i][j].getAlive());
		}
	}
}

TEST(Life, nextTurn3){
	/*
		*.
		.*
	*/
	istringstream iss("2\n2\n*.\n.*");
	Life<ConwayCell> life(iss);
	life.nextTurn();
	for(int i = 0; i<2;i++){
		for(int j = 0; j<2; j++){
			ASSERT_TRUE(!life.map[i][j].getAlive());
		}
	}
}

TEST(Life, nextTurn4){
	/*
		**
		*.
	*/
	istringstream iss("2\n2\n**\n*.");
	Life<ConwayCell> life(iss);
	life.nextTurn();
	for(int i = 0; i<2;i++){
		for(int j = 0; j<2; j++){
			ASSERT_TRUE(life.map[i][j].getAlive());
		}
	}
}

TEST(Life, nextTurn5){
	/*
		--
		-0
	*/
	istringstream iss("2\n2\n--\n-0");
	Life<FredkinCell> life(iss);
	life.nextTurn();
	ASSERT_TRUE(!life.map[0][0].getAlive());
	ASSERT_TRUE(life.map[0][1].getAlive());
	ASSERT_TRUE(life.map[1][0].getAlive());
	ASSERT_TRUE(!life.map[1][1].getAlive());
}

TEST(Life, nextTurn6){
	/*
		-1
		10
	*/
	istringstream iss("2\n2\n-1\n10");
	Life<FredkinCell> life(iss);
	life.nextTurn();
	ASSERT_TRUE(!life.map[0][0].getAlive());
	ASSERT_TRUE(life.map[0][1].getAlive());
	ASSERT_TRUE(life.map[1][0].getAlive());
	ASSERT_TRUE(!life.map[1][1].getAlive());
}

TEST(Life, nextTurn7){
	/*
		-0
		-0
	*/
	istringstream iss("2\n2\n-0\n-0");
	Life<Cell> life(iss);
	life.nextTurn();
	ASSERT_TRUE(life.map[0][0].getAlive());
	ASSERT_TRUE(life.map[0][1].getAlive());
	ASSERT_TRUE(life.map[1][0].getAlive());
	ASSERT_TRUE(life.map[1][1].getAlive());
}

// ----------
// ConwayCell.c++
// ----------

TEST(LifeConwayCell, constructor1){
	istringstream iss("3\n3\n...\n.*.\n...");
	Life<ConwayCell> life(iss);
	ASSERT_TRUE( (life.map[1][1]).getAlive());
}

TEST(LifeConwayCell, constructor2){
	ConwayCell c(true);
	ASSERT_TRUE(c.getAlive());
}

TEST(LifeConwayCell, constructor3){
	ConwayCell c(false);
	ASSERT_TRUE(!c.getAlive());
}

TEST(LifeConwayCell, constructor4){
	ConwayCell c;
	ASSERT_TRUE(!c.getAlive());
}

TEST(LifeConwayCell, add1){
	ConwayCell c(true);
	ASSERT_TRUE(c.add('*'));
}

TEST(LifeConwayCell, add2){
	ConwayCell c(true);
	ASSERT_TRUE(c.add('.'));
}

TEST(LifeConwayCell, add3){
	ConwayCell c(false);
	ASSERT_TRUE(!c.add('0'));
}

TEST(LifeConwayCell, add4){
	ConwayCell c(false);
	ASSERT_TRUE(!c.add('+'));
}

TEST(LifeConwayCell, add5){
	ConwayCell c(false);
	ASSERT_TRUE(!c.add('-'));
}

TEST(LifeConwayCell, add6){
	ConwayCell c;
	try{
		c.add('0');
	}
	catch(const invalid_argument& ie){
		ASSERT_TRUE(strcmp(ie.what(), "received wrong instruction") == 0);
	}
}

TEST(LifeConwayCell, print1){
	ConwayCell c(true);
	ASSERT_TRUE(c.print() == '*');
}

TEST(LifeConwayCell, print2){
	ConwayCell c(false);
	ASSERT_TRUE(c.print() == '.');
}

TEST(LifeConwayCell, evolve1){
	ConwayCell c(true);
	ASSERT_TRUE(!c.evolve(0, 0));
	ASSERT_TRUE(!c.getAlive());
}

TEST(LifeConwayCell, evolve2){
	ConwayCell c(false);
	ASSERT_TRUE(!c.evolve(3, 0));
	ASSERT_TRUE(c.getAlive());
}

TEST(LifeConwayCell, evolve3){
	ConwayCell c(true);
	ASSERT_TRUE(!c.evolve(3, 1));
	ASSERT_TRUE(!c.getAlive());
}

TEST(LifeConwayCell, evolve4){
	ConwayCell c(true);
	try{
		c.evolve(2, 84653);
	}
	catch(const out_of_range& oor){
		ASSERT_TRUE(strcmp(oor.what(), "direct or diag must be less than 4 and greater than 0") == 0);
	}
}

TEST(LifeConwayCell, evolve5){
	ConwayCell c(true);
	try{
		c.evolve(462346, 3);
	}
	catch(const out_of_range& oor){
		ASSERT_TRUE(strcmp(oor.what(), "direct or diag must be less than 4 and greater than 0") == 0);
	}
}

TEST(LifeConwayCell, evolve6){
	ConwayCell c(true);
	try{
		c.evolve(-548, 3);
	}
	catch(const out_of_range& oor){
		ASSERT_TRUE(strcmp(oor.what(), "direct or diag must be less than 4 and greater than 0") == 0);
	}
}

TEST(LifeConwayCell, evolve7){
	ConwayCell c(true);
	try{
		c.evolve(1, -353);
	}
	catch(const out_of_range& oor){
		ASSERT_TRUE(strcmp(oor.what(), "direct or diag must be less than 4 and greater than 0") == 0);
	}
}
// ----------
// Fredkin.c++
// ----------

TEST(LifeFredkinCell, constructor1){
	istringstream iss("2\n2\n--\n0-");
	Life<FredkinCell> life(iss);
	ASSERT_TRUE(life.map[1][0].getAlive());
}

TEST(LifeFredkinCell, constructor2){
	FredkinCell f(true);
	ASSERT_TRUE(f.getAlive());
}

TEST(LifeFredkinCell, constructor3){
	FredkinCell f(false);
	ASSERT_TRUE(!f.getAlive());
}

TEST(LifeFredkinCell, constructor4){
	FredkinCell f;
	ASSERT_TRUE(!f.getAlive());
}

TEST(LifeFredkinCell, add1){
	FredkinCell f(true);
	f.add('4');
	ASSERT_TRUE(f.getAlive());
}

TEST(LifeFredkinCell, add2){
	FredkinCell f(false);
	f.add('.');
	ASSERT_TRUE(!f.getAlive());
}

TEST(LifeFredkinCell, add3){
	FredkinCell f(true);
	f.add('+');
	ASSERT_TRUE(f.getAlive());
}

TEST(LifeFredkinCell, add4){
	FredkinCell f(true);
	f.add('9');
	ASSERT_TRUE(f.getAlive());
}

TEST(LifeFredkinCell, add5){
	FredkinCell f(true);
	f.add('-');
	ASSERT_TRUE(!f.getAlive());
}

TEST(LifeFredkinCell, print1){
	FredkinCell f(true);
	f.add('0');
	ASSERT_TRUE(f.print() == '0');
}

TEST(LifeFredkinCell, print2){
	FredkinCell f(false);
	f.add('-');
	ASSERT_TRUE(f.print() == '-');
}

TEST(LifeFredkinCell, evolvePrint1){
	FredkinCell f(true);
	f.add('9');
	f.evolve(3, 0);
	ASSERT_TRUE(f.print() == '+');
}

TEST(LifeFredkinCell, evolvePrint2){
	FredkinCell f(true);
	f.add('9');
	f.evolve(2, 0);
	ASSERT_TRUE(f.print() == '-');
}


TEST(LifeFredkinCell, evolve1){
	FredkinCell f(true);
	f.add('0');
	ASSERT_TRUE(!f.evolve(0, 0));
	ASSERT_TRUE(!f.getAlive());
}

TEST(LifeFredkinCell, evolve2){
	FredkinCell f(false);
	f.add('-');
	ASSERT_TRUE(!f.evolve(3, 0));
	ASSERT_TRUE(f.getAlive());
}

TEST(LifeFredkinCell, evolve3){
	FredkinCell f(true);
	f.add('0');
	ASSERT_TRUE(!f.evolve(3, 1));
	ASSERT_TRUE(f.getAlive());
}

TEST(LifeFredkinCell, evolve4){
	FredkinCell f(true);
	f.add('0');
	try{
		f.evolve(2, 84653);
	}
	catch(const out_of_range& oor){
		ASSERT_TRUE(strcmp(oor.what(), "direct or diag must be less than 4 and greater than 0") == 0);
	}
}

TEST(LifeFredkinCell, evolve5){
	FredkinCell f(true);
	f.add('-');
	try{
		f.evolve(462346, 3);
	}
	catch(const out_of_range& oor){
		ASSERT_TRUE(strcmp(oor.what(), "direct or diag must be less than 4 and greater than 0") == 0);
	}
}

TEST(LifeFredkinCell, evolve6){
	FredkinCell f(true);
	f.add('-');
	try{
		f.evolve(-41869, 3);
	}
	catch(const out_of_range& oor){
		ASSERT_TRUE(strcmp(oor.what(), "direct or diag must be less than 4 and greater than 0") == 0);
	}
}

TEST(LifeFredkinCell, evolve7){
	FredkinCell f(true);
	f.add('-');
	try{
		f.evolve(1, -844825);
	}
	catch(const out_of_range& oor){
		ASSERT_TRUE(strcmp(oor.what(), "direct or diag must be less than 4 and greater than 0") == 0);
	}
}

// ----------
// Cell.c++
// ----------


TEST(LifeCell, constructor1){
	istringstream iss("2\n2\n--\n0-");
	Life<Cell> life(iss);
	ASSERT_TRUE(life.map[1][0].getAlive());
}

TEST(LifeCell, constructor2){
	Cell c;
	ASSERT_TRUE(!c.getAlive());
}

TEST(LifeCell, add1){
	Cell c;
	c.add('4');
	ASSERT_TRUE(c.getAlive());
}

TEST(LifeCell, add2){
	Cell c;
	c.add('.');
	ASSERT_TRUE(!c.getAlive());
}

TEST(LifeCell, add3){
	Cell c;
	c.add('+');
	ASSERT_TRUE(c.getAlive());
}

TEST(LifeCell, add4){
	Cell c;
	c.add('9');
	ASSERT_TRUE(c.getAlive());
}

TEST(LifeCell, add5){
	Cell c;
	c.add('-');
	ASSERT_TRUE(!c.getAlive());
}

TEST(LifeCell, print1){
	Cell c;
	ASSERT_TRUE(c.print() == '-');
}

TEST(LifeCell, print2){
	Cell c;
	c.add('0');
	ASSERT_TRUE(c.print() == '0');
}

TEST(LifeCell, evolve1){
	Cell c;
	ASSERT_TRUE(!c.evolve(0, 0));
	ASSERT_TRUE(!c.getAlive());
}

TEST(LifeCell, evolve2){
	Cell c;
	ASSERT_TRUE(!c.evolve(3, 0));
	ASSERT_TRUE(c.getAlive());
}

TEST(LifeCell, evolve3){
	Cell c;
	ASSERT_TRUE(!c.evolve(3, 1));
	ASSERT_TRUE(c.getAlive());
}

TEST(LifeCell, evolve4){
	Cell c;
	try{
		c.evolve(2, 84653);
	}
	catch(const out_of_range& oor){
		ASSERT_TRUE(strcmp(oor.what(), "direct or diag must be less than 4 and greater than 0") == 0);
	}
}

TEST(LifeCell, evolve5){
	Cell c;
	try{
		c.evolve(462346, 3);
	}
	catch(const out_of_range& oor){
		ASSERT_TRUE(strcmp(oor.what(), "direct or diag must be less than 4 and greater than 0") == 0);
	}
}

TEST(LifeCell, evolve6){
	Cell c;
	try{
		c.evolve(2, -41891);
	}
	catch(const out_of_range& oor){
		ASSERT_TRUE(strcmp(oor.what(), "direct or diag must be less than 4 and greater than 0") == 0);
	}
}

TEST(LifeCell, evolve7){
	Cell c;
	try{
		c.evolve(2, -3);
	}
	catch(const out_of_range& oor){
		ASSERT_TRUE(strcmp(oor.what(), "direct or diag must be less than 4 and greater than 0") == 0);
	}
}

TEST(LifeCell, mutate){
	Cell c;
	c.add('1');
	c.mutate();
	ASSERT_TRUE(c.print() == '*');
}

