// ------------------------------------
// Name: Jeffrey Fulkerson
// eid: jgf453
// cs user id: jeffreyf 
// email: jeffreyfulkerson@gmail.com
// ------------------------------------

// ------------------------------------
// Name: Steven Wilken
// eid: sdw845
// cs user id: swilken 
// email: blackrider@utexas.edu
// ------------------------------------

#include <iostream>
#include <cassert>
#include "gtest/gtest.h"
#define private public
#define protected public
#include "Life.h"

using namespace std;

TEST(ConwayCell, checkState_die){
	ConwayCell c = ConwayCell(true, '.');
	bool neighbors[] = {1, 1, 1, 1, 1, 1, 1, 1};
	c.checkState(neighbors);
	ASSERT_TRUE(c.update);

}

TEST(ConwayCell, checkState_die2){
	ConwayCell c = ConwayCell(true, '.');
	bool neighbors[] = {0, 0, 0, 0, 0, 0, 0, 1};
	c.checkState(neighbors);
	ASSERT_TRUE(c.update);
	
}

TEST(ConwayCell, checkState_die3){
	ConwayCell c = ConwayCell(true, '.');
	bool neighbors[] = {1, 1, 0, 0, 0, 0, 1, 1};
	c.checkState(neighbors);
	ASSERT_TRUE(c.update);
	
}

TEST(ConwayCell, checkState_stayAlive){
	ConwayCell c = ConwayCell(true, '.');
	bool neighbors[] = {0, 0, 0, 0, 0, 1, 1, 1};
	c.checkState(neighbors);
	ASSERT_TRUE(!c.update);
	
}

TEST(ConwayCell, checkState_stayAlive2){
	ConwayCell c = ConwayCell(true, '.');
	bool neighbors[] = {0, 0, 0, 0, 0, 0, 1, 1};
	c.checkState(neighbors);
	ASSERT_TRUE(!c.update);
	
}

TEST(ConwayCell, checkState_live){
	ConwayCell c = ConwayCell(false, '.');
	bool neighbors[] = {0, 0, 0, 0, 0, 1, 1, 1};
	c.checkState(neighbors);
	ASSERT_TRUE(c.update);
	
}

TEST(ConwayCell, checkState_stayDead){
	ConwayCell c = ConwayCell(false, '.');
	bool neighbors[] = {0, 0, 0, 0, 0, 0, 1, 1};
	c.checkState(neighbors);
	ASSERT_TRUE(!c.update);
	
}

TEST(ConwayCell, checkState_stayDead2){
	ConwayCell c = ConwayCell(false, '.');
	bool neighbors[] = {0, 0, 0, 0, 1, 1, 1, 1};
	c.checkState(neighbors);
	ASSERT_TRUE(!c.update);
	
}

TEST(ConwayCell, update){
	ConwayCell c = ConwayCell(false, '.');
	c.update = true;
	c.updateState();
	ASSERT_TRUE(c.alive);
	
}

TEST(ConwayCell, update2){
	ConwayCell c = ConwayCell(false, '.');
	c.update = false;
	c.updateState();
	ASSERT_TRUE(!c.alive);
	
}

TEST(FredkinCell, checkState_die){
	FredkinCell c = FredkinCell(true, '-');
	bool neighbors[] = {0, 0, 0, 0, 0, 0, 0, 0};
	c.checkState(neighbors);
	ASSERT_TRUE(c.update);

}

TEST(FredkinCell, checkState_die2){
	FredkinCell c = FredkinCell(true, '-');
	bool neighbors[] = {0, 1, 0, 1, 0, 0, 0, 0};
	c.checkState(neighbors);
	ASSERT_TRUE(c.update);
}

TEST(FredkinCell, checkState_die3){
	FredkinCell c = FredkinCell(true, '-');
	bool neighbors[] = {0, 1, 0, 1, 1, 0, 1, 0};
	c.checkState(neighbors);
	ASSERT_TRUE(c.update);
}

TEST(FredkinCell, checkState_stayAlive){
	FredkinCell c = FredkinCell(true, '-');
	bool neighbors[] = {0, 1, 0, 0, 0, 0, 0, 0};
	c.checkState(neighbors);
	ASSERT_TRUE(!c.update);
}

TEST(FredkinCell, checkState_stayAlive2){
	FredkinCell c = FredkinCell(true, '-');
	bool neighbors[] = {0, 1, 0, 1, 1, 0, 0, 0};
	c.checkState(neighbors);
	ASSERT_TRUE(!c.update);
}

TEST(FredkinCell, checkState_live){
	FredkinCell c = FredkinCell(false, '-');
	bool neighbors[] = {0, 1, 0, 0, 0, 0, 0, 0};
	c.checkState(neighbors);
	ASSERT_TRUE(c.update);
}

TEST(FredkinCell, checkState_live2){
	FredkinCell c = FredkinCell(false, '-');
	bool neighbors[] = {0, 1, 0, 1, 1, 0, 0, 0};
	c.checkState(neighbors);
	ASSERT_TRUE(c.update);
}

TEST(FredkinCell, checkState_stayDead){
	FredkinCell c = FredkinCell(false, '-');
	bool neighbors[] = {0, 0, 0, 0, 0, 0, 0, 0};
	c.checkState(neighbors);
	ASSERT_TRUE(!c.update);
}

TEST(FredkinCell, checkState_stayDead2){
	FredkinCell c = FredkinCell(false, '-');
	bool neighbors[] = {0, 1, 0, 1, 0, 0, 0, 0};
	c.checkState(neighbors);
	ASSERT_TRUE(!c.update);
}

TEST(FredkinCell, checkState_stayDead3){
	FredkinCell c = FredkinCell(false, '-');
	bool neighbors[] = {0, 1, 0, 1, 1, 0, 1, 0};
	c.checkState(neighbors);
	ASSERT_TRUE(!c.update);
}

TEST(FredkinCell, update){
	FredkinCell c = FredkinCell(false, '-');
	c.update = true;
	c.updateState();
	ASSERT_TRUE(c.alive);
	
}

TEST(FredkinCell, update2){
	FredkinCell c = FredkinCell(false, '-');
	c.update = false;
	c.updateState();
	ASSERT_TRUE(!c.alive);
	
}

TEST(FredkinCell, update3){
	FredkinCell c = FredkinCell(true, '-');
	c.update = false;
	c.updateState();
	ASSERT_TRUE(c.age == 1);
	
}

TEST(Cell, createCell_Conway){
	Cell c = Cell(true, '*');
	ConwayCell* p = (ConwayCell*) c.createCell(true, '*');
	ASSERT_TRUE(p->alive);
	delete p;
}

TEST(Cell, createCell_Fredkin){
	Cell c = Cell(true, '*');
	FredkinCell* p = (FredkinCell*) c.createCell(true, '0');
	ASSERT_TRUE(p->age == 0);
	delete p;
}

TEST(Life, find_inBounds){
	istringstream r("....\n..*.\n....\n....\0");
	Life<Cell> l = Life<Cell>(r, 4, 4);
	ASSERT_TRUE(l.find(1, 2)->isAlive());
}

TEST(Life, find_outOfBounds){
	istringstream r("....\n..*.\n....\n....\0");
	Life<Cell> l = Life<Cell>(r, 4, 4);
	ASSERT_TRUE(l.find(4, 4) == NULL);
}

TEST(Life, find_rowEnd){
	istringstream r("....\n...*\n....\n....\0");
	Life<Cell> l = Life<Cell>(r, 4, 4);
	ASSERT_TRUE(l.find(1, 3)->isAlive());
}

TEST(Life, find_colEnd){
	istringstream r("...*\n..*.\n....\n....\0");
	Life<Cell> l = Life<Cell>(r, 4, 4);
	ASSERT_TRUE(l.find(0, 3)->isAlive());
}

TEST(Life, find_rowBegin){
	istringstream r("...*\n....\n....\n....\0");
	Life<Cell> l = Life<Cell>(r, 4, 4);
	ASSERT_TRUE(l.find(0, 3)->isAlive());
}

TEST(Life, find_colBegin){
	istringstream r("....\n....\n....\n*...\0");
	Life<Cell> l = Life<Cell>(r, 4, 4);
	ASSERT_TRUE(l.find(3, 0)->isAlive());
}

TEST(Life, step){
	istringstream r("....\n....\n....\n*...\0");
	Life<Cell> l = Life<Cell>(r, 4, 4);
	l.step(50);
	ASSERT_TRUE(l.generation == 50);
}