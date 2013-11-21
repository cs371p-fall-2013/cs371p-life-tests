// --------
// includes
// --------


// #include <cstdlib>   // rand, srand
// #include <stdexcept> // invalid_argument, out_of_range
// #include <iostream>
#include <string>
#include "gtest/gtest.h"
#include <utility>


#define protected public
#define private public

#include "Life.h"



/* Life Tests */

// ----
// Abstract isAlive
// ----

TEST(AbstractCell, abstractCell_isAlive_alive) {
	ConwayCell c(true);
	FredkinCell f(true);
	ASSERT_TRUE(c.isAlive());
	ASSERT_TRUE(f.isAlive());
}

TEST(AbstractCell, abstractCell_isAlive_dead) {
	ConwayCell c(false);
	FredkinCell f(false);
	ASSERT_TRUE(!c.isAlive());
	ASSERT_TRUE(!f.isAlive());

}

TEST(AbstractCell, abstractCell_isAlive_change) {
	ConwayCell c(true);
	FredkinCell f(true);
	ASSERT_TRUE(c.isAlive());
	ASSERT_TRUE(f.isAlive());
}

// ----
// Abstract changeAlive
// ----

TEST(AbstractCell, abstractCell_changeAlive_alive) {
	ConwayCell c(true);
	c.changeAlive();	
	ASSERT_TRUE(!c.isAlive());
}

TEST(AbstractCell, abstractCell_changeAlive_dead) {
	FredkinCell f(false);
	f.changeAlive();
	ASSERT_TRUE(f.isAlive());

}

TEST(AbstractCell, abstractCell_changeAlive_change) {
	ConwayCell c(true);
	c.changeAlive();
	c.changeAlive();
	ASSERT_TRUE(c.isAlive());
}

// ----
// Conway getState
// ----

TEST(ConwayCell, conway_getState_dead) {
	ConwayCell c(false);
	ASSERT_TRUE(c.getState() == '.');
}

TEST(ConwayCell, conway_getState_alive) {
	ConwayCell c(true);
	ASSERT_TRUE(c.getState() == '*');		
}

TEST(ConwayCell, conway_getState_changed) {
	ConwayCell c(true);
	c.changeAlive();
	ASSERT_TRUE(c.getState() == '.');	
}

// ----
// Conway changeState
// ----

TEST(ConwayCell, conway_changeState_cardinal) {
	pair<int, int> p(0, 3);
	ConwayCell c(false);
	c.changeState(p);
	ASSERT_TRUE(c.getState() == '*');
}

TEST(ConwayCell, conway_changeState_diagonal) {
	pair<int, int> p(3, 0);
	ConwayCell c(false);
	c.changeState(p);
	ASSERT_TRUE(c.getState() == '*');	
}

TEST(ConwayCell, conway_changeState_die) {
	pair<int, int> p(1, 0);
	ConwayCell c(true);
	c.changeState(p);
	ASSERT_TRUE(c.getState() == '.');	
}


// ----
// Conway clone
// ----

TEST(ConwayCell, conway_clone_alive) {
	ConwayCell c(true);
	ConwayCell *p = c.clone();
	ASSERT_TRUE((*p).isAlive() == true);
	delete p;

}

TEST(ConwayCell, conway_clone_dead) {
	ConwayCell c(false);
	ConwayCell *p = c.clone();
	ASSERT_TRUE((*p).isAlive() == false);
	delete p;	
}

TEST(ConwayCell, conway_clone_kill) {
	ConwayCell c(true);
	ConwayCell *p = c.clone();
	(*p).changeAlive();
	ASSERT_TRUE((*p).isAlive() == false);
	delete p;
}


// ----
// Fredkin getState
// ----

TEST(FredkinCell, fredkin_getState_dead) {
	FredkinCell c(false);
	ASSERT_TRUE(c.getState() == '-');

}

TEST(FredkinCell, fredkin_getState_alive) {
	FredkinCell c(true);
	ASSERT_TRUE(c.getState() == 0);
	
}

TEST(FredkinCell, fredkin_getState_changed) {
	FredkinCell c(true);
	c.changeAlive();
	ASSERT_TRUE(c.getState() == '-');
	
}

// ----
// Fredkin changeState
// ----

TEST(FredkinCell, fredkin_changeState_diagonal) {
	pair<int, int> p(0, 1);
	FredkinCell c(false);
	c.changeState(p);
	ASSERT_TRUE(c.getState() == 0);
}

TEST(FredkinCell, fredkin_changeState_cardinal) {
	pair<int, int> p(1, 0);
	FredkinCell c(true);
	c.changeState(p);
	ASSERT_TRUE(c.getState() == '-');
}

TEST(FredkinCell, fredkin_changeState_4) {
	pair<int, int> p(0, 4);
	FredkinCell c(true);
	c.changeState(p);
	ASSERT_TRUE(c.getState() == '-');
}


// ----
// Fredkin clone
// ----

TEST(FredkinCell, fredkin_clone_alive) {
	FredkinCell c(true);
	FredkinCell *p = c.clone();
	(*p).changeAlive();
	ASSERT_TRUE((*p).isAlive() == false);
	delete p;

}

TEST(FredkinCell, fredkin_clone_dead) {
	FredkinCell c(true);
	FredkinCell *p = c.clone();
	(*p).changeAlive();
	ASSERT_TRUE((*p).isAlive() == false);
	delete p;
	
}

TEST(FredkinCell, fredkin_clone_kill) {
	FredkinCell c(true);
	FredkinCell *p = c.clone();
	(*p).changeAlive();
	ASSERT_TRUE((*p).isAlive() == false);
	delete p;
	
}


// ----
// Life inBounds
// ----

TEST(Life, life_inBounds_out) {
	Life<ConwayCell> l(5,3);
	ASSERT_TRUE(l.inBounds(6,6) == false);
}

TEST(Life, life_inBounds_edge) {
	Life<ConwayCell> l1(5,3);
	ASSERT_TRUE(l1.inBounds(4,2) == true);	
}

TEST(Life, life_inBounds_in) {
	Life<ConwayCell> l2(5,3);
	ASSERT_TRUE(l2.inBounds(3,5) == false);
}

// ----
// Life neighbors
// ----

TEST(Life, life_neighbors_none) {
	Life<ConwayCell> l(3,3);
	ConwayCell *p = new ConwayCell(true);
	l._grid[1][1] = *p;
	pair<int, int> n = l.getNeighbors(1, 1);
	ASSERT_TRUE(n.first == 0);
	ASSERT_TRUE(n.second == 0);
	delete p;
	}

TEST(Life, life_neighbors_cardinal) {
	Life<ConwayCell> l(3,3);
	ConwayCell *p = new ConwayCell(true);
	l._grid[1][1] = *p;
	ConwayCell *p1 = new ConwayCell(true);
	l._grid[1][0] = *p1;
	ConwayCell *p2 = new ConwayCell(true);
	l._grid[1][2] = *p2;
	ConwayCell *p3 = new ConwayCell(true);
	l._grid[0][1] = *p3;
	pair<int, int> n = l.getNeighbors(1, 1);
	ASSERT_TRUE(n.first == 0);
	ASSERT_TRUE(n.second == 3);
	delete p; 
	delete p1; 
	delete p2; 
	delete p3;
	
}

TEST(Life, life_neighbors_diagonal) {
	Life<ConwayCell> l(3,3);
	ConwayCell *p = new ConwayCell(true);
	l._grid[1][1] = *p;
	ConwayCell *p1 = new ConwayCell(true);
	l._grid[0][0] = *p1;
	ConwayCell *p2 = new ConwayCell(true);
	l._grid[0][2] = *p2;
	ConwayCell *p3 = new ConwayCell(true);
	l._grid[2][0] = *p3;
	pair<int, int> n = l.getNeighbors(1, 1);
	ASSERT_TRUE(n.first == 3);
	ASSERT_TRUE(n.second == 0);
	delete p; 
	delete p1; 
	delete p2; 
	delete p3;
	
}

// ----
// Cell mutate
// ----


TEST(Cell, cell_mutate_alive) {
	Life<Cell> l(1,1);
	l._grid[0][0].mutate();
	l._grid[0][0].changeAlive();
	ASSERT_TRUE(l._grid[0][0].getState() == '*');
}

TEST(Cell, cell_mutate_dead) {
	Life<Cell> l(1,1);
	l._grid[0][0].mutate();
	ASSERT_TRUE(l._grid[0][0].getState() == '.');
}

TEST(Cell, cell_mutate_twice) {
	Life<Cell> l(1,1);
	l._grid[0][0].mutate();
	l._grid[0][0].changeAlive();
	l._grid[0][0].mutate();
	ASSERT_TRUE(l._grid[0][0].getState() == '.');
}
