#include <iostream>
#include <sstream>
#include <string>

#include "gtest/gtest.h"

#define private public
#define protected public

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==

#include "Life.h"


using namespace std;

// ----------
// ConwayCell
// ----------

TEST(ConwayCell, clone1) {
	ConwayCell c(true);
	ConwayCell* cloned = c.clone();
	ASSERT_TRUE(cloned->_isAlive);
	delete cloned;
}
TEST(ConwayCell, clone2) {
	ConwayCell c(false);
	ConwayCell* cloned = c.clone();
	ASSERT_TRUE(cloned->_isAlive == false);
	delete cloned;
}
TEST(ConwayCell, clone3) {
	ConwayCell* c = new ConwayCell();
	ConwayCell* cloned = c->clone();
	ASSERT_TRUE(cloned->_isAlive == true);
	delete cloned;
	delete c;
}
TEST(ConwayCell, nextGen1) {
	ConwayCell c(true);
	const ConwayCell* pArray[8] = { new ConwayCell(false), new ConwayCell(false), 
		new ConwayCell(false), new ConwayCell(false), new ConwayCell(false), 
		new ConwayCell(false), new ConwayCell(false), new ConwayCell(false)};
	c.nextGen(pArray);
	ASSERT_TRUE(c._nextIsAlive == false);
        for (int i =0; i < 8 ; i++) {
        	delete pArray[i];
        }
}
TEST(ConwayCell, nextGen2) {
        ConwayCell c(true);
        const ConwayCell* pArray[8] = { new ConwayCell(true), new ConwayCell(true), 
        	new ConwayCell(false), new ConwayCell(false), new ConwayCell(false), 
        	new ConwayCell(false), new ConwayCell(false), new ConwayCell(false)};
        c.nextGen(pArray);
        ASSERT_TRUE(c._nextIsAlive == true);
        for (int i =0; i < 8 ; i++) {
        	delete pArray[i];
        }
}
TEST(ConwayCell, nextGen3) {
        ConwayCell c(true);
        const ConwayCell* pArray[8] = { new ConwayCell(true), new ConwayCell(true), 
        	new ConwayCell(true), new ConwayCell(true), new ConwayCell(false), 
        	new ConwayCell(false), new ConwayCell(false), new ConwayCell(false)};
        c.nextGen(pArray);
        ASSERT_TRUE(c._nextIsAlive == false);
        for (int i =0; i < 8 ; i++) {
        	delete pArray[i];
        }
}
TEST(ConwayCell, nextGenAbstractCell1) {
	ConwayCell c(true);
	const AbstractCell* pArray[8] = { new ConwayCell(false), new ConwayCell(false), 
		new ConwayCell(false), new ConwayCell(false), new ConwayCell(false), 
		new ConwayCell(false), new ConwayCell(false), new ConwayCell(false)};
	c.nextGen(pArray);
	ASSERT_TRUE(c._nextIsAlive == false);
	for (int i =0; i < 8 ; i++) {
        delete pArray[i];
    }
}

TEST(ConwayCell, nextGenAbstractCell2) {
	ConwayCell c(true);
	const AbstractCell* pArray[8] = { new ConwayCell(true), new ConwayCell(true), 
        	new ConwayCell(false), new ConwayCell(false), new ConwayCell(false), 
        	new ConwayCell(false), new ConwayCell(false), new ConwayCell(false)};
	c.nextGen(pArray);
	ASSERT_TRUE(c._nextIsAlive == true);
	for (int i =0; i < 8 ; i++) {
        delete pArray[i];
    }
}
TEST(ConwayCell, nextGenAbstractCell3) {
	ConwayCell c(true);
	const AbstractCell* pArray[8] = { new ConwayCell(true), new ConwayCell(true), 
        	new ConwayCell(true), new ConwayCell(true), new ConwayCell(false), 
        	new ConwayCell(false), new ConwayCell(false), new ConwayCell(false)};
	c.nextGen(pArray);
	ASSERT_TRUE(c._nextIsAlive == false);
	for (int i =0; i < 8 ; i++) {
        delete pArray[i];
    }
}
TEST(ConwayCell, print1) {
	ConwayCell c(true);
	std::ostringstream w;
	c.print(w);
	ASSERT_TRUE(w.str() == "*");
}
TEST(ConwayCell, print2) {
	ConwayCell c(false);
	std::ostringstream w;
	c.print(w);
	ASSERT_TRUE(w.str() == ".");
}
TEST(ConwayCell, print3) {
	ConwayCell* c = new ConwayCell();
	std::ostringstream w;
	c->print(w);
	ASSERT_TRUE(w.str() == "*");
	delete c;
}
TEST(ConwayCell, update1) {
	ConwayCell c(true);
	c._nextIsAlive = true;
	c.update();
	ASSERT_TRUE(c._isAlive == true);
}
TEST(ConwayCell, update2) {
	ConwayCell c(false);
	c._nextIsAlive = true;
	c.update();
	ASSERT_TRUE(c._isAlive == true);
}
TEST(ConwayCell, update3) {
	ConwayCell c(false);
	c._nextIsAlive = false;
	c.update();
	ASSERT_TRUE(c._isAlive == false);
}
TEST(FredkinCell, clone1) {
	FredkinCell c(true);
	FredkinCell* cloned = c.clone();
	ASSERT_TRUE(cloned->_isAlive);
	delete cloned;
}
TEST(FredkinCell, clone2) {
	FredkinCell c(false);
	FredkinCell* cloned = c.clone();
	ASSERT_TRUE(cloned->_isAlive == false);
	delete cloned;
}
TEST(FredkinCell, clone3) {
	FredkinCell* c = new FredkinCell();
	FredkinCell* cloned = c->clone();
	ASSERT_TRUE(cloned->_isAlive == false);
	delete cloned;
	delete c;
}
TEST(FredkinCell, nextGen1) {
	FredkinCell c(true);
	const FredkinCell* pArray[8] = { new FredkinCell(false), new FredkinCell(false), 
		new FredkinCell(false), new FredkinCell(false), new FredkinCell(false), 
		new FredkinCell(false), new FredkinCell(false), new FredkinCell(false)};
	c.nextGen(pArray);
	ASSERT_TRUE(c._nextIsAlive == false);
        for (int i =0; i < 8 ; i++) {
        	delete pArray[i];
        }
}
TEST(FredkinCell, nextGen2) {
        FredkinCell c(true);
        const FredkinCell* pArray[8] = { new FredkinCell(true), new FredkinCell(true), 
        	new FredkinCell(false), new FredkinCell(false), new FredkinCell(false), 
        	new FredkinCell(false), new FredkinCell(false), new FredkinCell(false)};
        c.nextGen(pArray);
        ASSERT_TRUE(c._nextIsAlive == true);
        for (int i =0; i < 8 ; i++) {
        	delete pArray[i];
        }
}
TEST(FredkinCell, nextGen3) {
        FredkinCell c(true);
        const FredkinCell* pArray[8] = { new FredkinCell(true), new FredkinCell(true), 
        	new FredkinCell(true), new FredkinCell(true), new FredkinCell(false), 
        	new FredkinCell(false), new FredkinCell(false), new FredkinCell(false)};
        c.nextGen(pArray);
        ASSERT_TRUE(c._nextIsAlive == false);
        for (int i =0; i < 8 ; i++) {
        	delete pArray[i];
        }
}
TEST(FredkinCell, nextGenAbstractCell1) {
	FredkinCell c(true);
	Cell* cArray[8] = { new Cell(new FredkinCell(false)), new Cell(new FredkinCell(false)),
		new Cell(new FredkinCell(false)), new Cell(new FredkinCell(false)),
		new Cell(new FredkinCell(false)), new Cell(new FredkinCell(false)),
		new Cell(new FredkinCell(false)), new Cell(new FredkinCell(false))}; 
	const AbstractCell* pArray[8] = {cArray[0]->get(), cArray[1]->get(), cArray[2]->get(),
	 cArray[3]->get(), cArray[4]->get(), cArray[5]->get(), cArray[6]->get(), cArray[7]->get()};
	c.nextGen(pArray);
	ASSERT_TRUE(c._nextIsAlive == false);
	for (int i =0; i < 8 ; i++) {
        	delete cArray[i];
        }
}
TEST(FredkinCell, nextGenAbstractCell2) {
	FredkinCell c(true);
	Cell* cArray[8] = { new Cell(new FredkinCell(true)), new Cell(new FredkinCell(false)),
		new Cell(new FredkinCell(true)), new Cell(new FredkinCell(false)),
		new Cell(new FredkinCell(false)), new Cell(new FredkinCell(true)),
		new Cell(new FredkinCell(false)), new Cell(new FredkinCell(true))}; 
	const AbstractCell* pArray[8] = {cArray[0]->get(), cArray[1]->get(), cArray[2]->get(),
	 cArray[3]->get(), cArray[4]->get(), cArray[5]->get(), cArray[6]->get(), cArray[7]->get()};
	c.nextGen(pArray);
	ASSERT_TRUE(c._nextIsAlive == false);
	for (int i =0; i < 8 ; i++) {
        	delete cArray[i];
        }
}
TEST(FredkinCell, nextGenAbstractCell3) {
	FredkinCell c(true);
	Cell* cArray[8] = { new Cell(new FredkinCell(false)), new Cell(new FredkinCell(true)),
		new Cell(new FredkinCell(false)), new Cell(new FredkinCell(false)),
		new Cell(new FredkinCell(false)), new Cell(new FredkinCell(false)),
		new Cell(new FredkinCell(false)), new Cell(new FredkinCell(false))}; 
	const AbstractCell* pArray[8] = {cArray[0]->get(), cArray[1]->get(), cArray[2]->get(),
	 cArray[3]->get(), cArray[4]->get(), cArray[5]->get(), cArray[6]->get(), cArray[7]->get()};
	c.nextGen(pArray);
	ASSERT_TRUE(c._nextIsAlive);
	for (int i =0; i < 8 ; i++) {
        	delete cArray[i];
        }
}
TEST(FredkinCell, update1) {
	FredkinCell c(true);
	c._nextIsAlive = true;
	c.update();
	ASSERT_TRUE(c._isAlive);
}
TEST(FredkinCell, update2) {
	FredkinCell c(true);
	c._nextIsAlive = false;
	c.update();
	ASSERT_TRUE(c._isAlive == false);
}
TEST(FredkinCell, update3) {
	FredkinCell c(false);
	c._nextIsAlive = true;
	c.update();
	ASSERT_TRUE(c._isAlive);
}
TEST(FredkinCell, print1) {
	FredkinCell c(true);
	std::ostringstream w;
	c.print(w);
	ASSERT_TRUE(w.str() == "0");
}
TEST(FredkinCell, print2) {
	FredkinCell c(false);
	std::ostringstream w;
	c.print(w);
	ASSERT_TRUE(w.str() == "-");
}
TEST(FredkinCell, print3) {
	FredkinCell* c = new FredkinCell(true);
	c->_age = 10;
	std::ostringstream w;
	c->print(w);
	ASSERT_TRUE(w.str() == "+");
	delete c;
}
TEST(FredkinCell, shouldMutate1) {
	FredkinCell c(true);
	ASSERT_TRUE(c.shouldMutate() == false);
}
TEST(FredkinCell, shouldMutate2) {
	FredkinCell c(false);
	c._age = 2;
	ASSERT_TRUE(c.shouldMutate() == false);
}
TEST(FredkinCell, shouldMutate3) {
	FredkinCell c(true);
	c._age = 2;
	ASSERT_TRUE(c.shouldMutate() == true);
}
TEST(FredkinCell, mutate1) {
	FredkinCell c(true);
	AbstractCell* a = c.mutate();
	ASSERT_TRUE(a->_isAlive);
	delete a;
}
TEST(FredkinCell, mutate2) {
	FredkinCell c(false);
	AbstractCell* a = c.mutate();
	ASSERT_TRUE(a->_isAlive);
	delete a;
}
TEST(FredkinCell, mutate3) {
	FredkinCell* c = new FredkinCell();
	AbstractCell* a = c->mutate();
	ASSERT_TRUE(a->_isAlive);
	delete a;
	delete c;
}
TEST(AbstractCell, shouldMutate1) {
	ConwayCell c(true);
	ASSERT_FALSE(c.shouldMutate());
}
TEST(AbstractCell, shouldMutate2) {
	AbstractCell* c = new ConwayCell(true);
	ASSERT_FALSE(c->shouldMutate());
	delete c;
}
TEST(AbstractCell, shouldMutate3) {
	ConwayCell* co = new ConwayCell(true);
	AbstractCell* c = (AbstractCell*)co;
	ASSERT_FALSE(c->shouldMutate());
	delete co;
}
TEST(AbstractCell, mutate1) {
	ConwayCell c(true);
	ASSERT_TRUE(c.mutate() == &c);
}
TEST(AbstractCell, mutate2) {
	AbstractCell* c = new ConwayCell(true);
	ASSERT_TRUE(c->mutate() == c);
	delete c;
}
TEST(AbstractCell, mutate3) {
	ConwayCell* co = new ConwayCell(true);
	AbstractCell* c = (AbstractCell*)co;
	ASSERT_TRUE(c->mutate() == c);
	delete co;
}
TEST(Cell, nextGen1) {
	Cell c(new ConwayCell(true));
	const Cell* cArray[8] = { new Cell(new FredkinCell(false)), new Cell(new FredkinCell(true)),
		new Cell(new FredkinCell(false)), new Cell(new FredkinCell(false)),
		new Cell(new FredkinCell(false)), new Cell(new FredkinCell(false)),
		new Cell(new FredkinCell(false)), new Cell(new FredkinCell(false))};
	c.nextGen(cArray);
	ASSERT_TRUE(c.get()->_nextIsAlive == false);
	for (int i =0; i < 8 ; i++) {
    	delete cArray[i];
    }
}
TEST(Cell, nextGen2) {
	Cell c(new ConwayCell(true));
	const Cell* cArray[8] = { new Cell(new FredkinCell(false)), new Cell(new FredkinCell(true)),
		new Cell(new FredkinCell(false)), new Cell(new FredkinCell(true)),
		new Cell(new FredkinCell(false)), new Cell(new FredkinCell(false)),
		new Cell(new FredkinCell(false)), new Cell(new FredkinCell(false))};
	c.nextGen(cArray);
	ASSERT_TRUE(c.get()->_nextIsAlive);
	for (int i =0; i < 8 ; i++) {
    	delete cArray[i];
    }
}
TEST(Cell, nextGen3) {
	Cell c(new ConwayCell(true));
	const Cell* cArray[8] = { new Cell(new FredkinCell(true)), new Cell(new FredkinCell(true)),
		new Cell(new FredkinCell(true)), new Cell(new FredkinCell(true)),
		new Cell(new FredkinCell(false)), new Cell(new FredkinCell(false)),
		new Cell(new FredkinCell(false)), new Cell(new FredkinCell(false))};
	c.nextGen(cArray);
	ASSERT_TRUE(c.get()->_nextIsAlive == false);
	for (int i =0; i < 8 ; i++) {
    	delete cArray[i];
    }
}
TEST(Cell, update1) {
	Cell c(new ConwayCell(true));
	c.get()->_nextIsAlive = false;
	c.update();
	ASSERT_TRUE(c.get()->_isAlive == false);
}
TEST(Cell, update2) {
	Cell c(new ConwayCell(true));
	c.get()->_nextIsAlive = true;
	c.update();
	ASSERT_TRUE(c.get()->_isAlive == true);
}
TEST(Cell, update3) {
	Cell c(new FredkinCell(false));
	c.get()->_nextIsAlive = true;
	c.update();
	ASSERT_TRUE(c.get()->_isAlive == true);
}
TEST(Cell, print1) {
	Cell c(new FredkinCell(false));
	ostringstream w;
	c.print(w);
	ASSERT_TRUE(w.str() == "-");
}
TEST(Cell, print2) {
	Cell c(new FredkinCell(true));
	ostringstream w;
	c.print(w);
	ASSERT_TRUE(w.str() == "0");
}
TEST(Cell, print3) {
	Cell c(new ConwayCell(false));
	ostringstream w;
	c.print(w);
	ASSERT_TRUE(w.str() == ".");
}
TEST(Life, nextGen1) {
	istringstream i("2\n2\n.*\n.*");
	Life<ConwayCell> life(i, false);
	life.nextGen();
	ASSERT_TRUE(life._world[1][1]._isAlive == false);
	ASSERT_TRUE(life._world[1][2]._isAlive == false);
	ASSERT_TRUE(life._world[2][1]._isAlive == false);
	ASSERT_TRUE(life._world[2][2]._isAlive == false);
}
TEST(Life, nextGen2) {
	istringstream i("2\n3\n0-0\n0-0\n");
	Life<FredkinCell> life(i, false);
	life.nextGen();
	ASSERT_TRUE(life._world[1][1]._isAlive == true);
	ASSERT_TRUE(life._world[1][2]._isAlive == false);
	ASSERT_TRUE(life._world[2][1]._isAlive == true);
	ASSERT_TRUE(life._world[2][2]._isAlive == false);
}
TEST(Life, nextGen3) {
	istringstream i("2\n2\n**\n**");
	Life<ConwayCell> life(i, false);
	life.nextGen();
	ASSERT_TRUE(life._world[1][1]._isAlive == true);
	ASSERT_TRUE(life._world[1][2]._isAlive == true);
	ASSERT_TRUE(life._world[2][1]._isAlive == true);
	ASSERT_TRUE(life._world[2][2]._isAlive == true);
}
TEST(Life, nextGen4) {
	istringstream i("3\n3\n.*.\n.*.\n.*.");
	Life<ConwayCell> life(i, false);
	life.nextGen();
	ASSERT_TRUE(life._world[1][1]._isAlive == false);
	ASSERT_TRUE(life._world[1][2]._isAlive == false);
	ASSERT_TRUE(life._world[2][1]._isAlive == true);
	ASSERT_TRUE(life._world[2][2]._isAlive == true);
}
TEST(Life, nextGen5) {
	istringstream i("3\n3\n.*.\n.*.\n.*.");
	Life<Cell> life(i, true);
	life.nextGen();
	ASSERT_TRUE(life._world[1][1].get()->_isAlive == false);
	ASSERT_TRUE(life._world[1][2].get()->_isAlive == false);
	ASSERT_TRUE(life._world[2][1].get()->_isAlive == true);
	ASSERT_TRUE(life._world[2][2].get()->_isAlive == true);
}
TEST(Life, nextGen6) {
	istringstream i("2\n3\n0-0\n0-0\n");
	Life<Cell> life(i, true);
	life.nextGen();
	life.nextGen();
	life.nextGen();
	ASSERT_TRUE(life._world[1][1].get()->_isAlive == false);
	ASSERT_TRUE(life._world[1][2].get()->_isAlive == false);
	ASSERT_TRUE(life._world[2][1].get()->_isAlive == false);
	ASSERT_TRUE(life._world[2][2].get()->_isAlive == false);
}