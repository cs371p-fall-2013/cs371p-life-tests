#define private public
#define protected public

// --------------------------------
// projects/collatz/TestCollatz.c++
// Copyright (C) 2013
// Glenn P. Downing
// --------------------------------

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

% g++ -pedantic -std=c++0x -Wall Collatz.c++ TestCollatz.c++ -o TestCollatz -lgtest -lpthread -lgtest_main

% valgrind TestCollatz > TestCollatz.out
*/

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream> // istringtstream, ostringstream
#include <string> // ==

#include "gtest/gtest.h"
#include "Life.h"

using namespace std;

TEST(AbstactCell, constructor1) {
    AbstractCell* c = new ConwayCell(true);

    assert(c->_alive);
}

TEST(AbstactCell, constructor2) {
    AbstractCell* c = new FredkinCell(true, 0);

    assert(c->_alive);
}

TEST(AbstactCell, constructor3) {
    AbstractCell* c = new ConwayCell(false);

    assert(!c->_alive);
}

TEST(AbstactCell, print1) {
    AbstractCell* c = new ConwayCell(false);

    ostringstream out;
    c->print(out);

    assert(out.str() == ".");
}

TEST(AbstactCell, print2) {
    AbstractCell* c = new ConwayCell(true);

    ostringstream out;
    c->print(out);

    assert(out.str() == "*");
}

TEST(AbstactCell, print3) {
    AbstractCell* c = new FredkinCell(true, 0);

    ostringstream out;
    c->print(out);

    assert(out.str() == "0");
    
}

TEST(AbstactCell, print4) {
    AbstractCell* c = new FredkinCell(false, 0);

    ostringstream out;
    c->print(out);

    assert(out.str() == "-");
    
}

TEST(AbstactCell, print5) {
    AbstractCell* c = new FredkinCell(true, 10);

    ostringstream out;
    c->print(out);

    assert(out.str() == "+");
    
}

TEST(AbstactCell, destructor1) {
    AbstractCell* c = new FredkinCell(true, 10);
    delete c;
    c = 0;
}

TEST(AbstactCell, destructor2) {
    AbstractCell* c = new ConwayCell(true);
    delete c;
    c = 0;
}

TEST(AbstactCell, destructor3) {
    AbstractCell* c = new ConwayCell(false);
    delete c;
    c = 0;
}

TEST(AbstactCell, clone1) {
    AbstractCell* c = new ConwayCell(false);
    AbstractCell* c2 = c->clone();
    assert(c != c2);
    assert(c->_alive == c2->_alive);    
}

TEST(AbstactCell, clone2) {
    AbstractCell* c = new FredkinCell(false, 0);
    AbstractCell* c2 = c->clone();
    assert(c != c2);
    assert(c->_alive == c2->_alive);
}

TEST(AbstactCell, clone3) {
    AbstractCell* c = new FredkinCell(false, 0);
    AbstractCell* c2 = c->clone();
    assert(c != c2);
    delete c;
    assert(!c2->_alive);
}

TEST(AbstactCell, evolve1) {
    AbstractCell* c = new FredkinCell(false, 0);
    assert(!c->_alive);
    c->evolve(1);
    assert(c->_alive);
}

TEST(AbstactCell, evolve2) {
    AbstractCell* c = new FredkinCell(true, 0);
    assert(c->_alive);
    c->evolve(2);
    assert(!c->_alive);
    
}

TEST(AbstactCell, evolve3) {
    AbstractCell* c = new ConwayCell(true);
    assert(c->_alive);
    c->evolve(1);
    assert(!c->_alive);
    
}

TEST(AbstactCell, evolve4) {
    AbstractCell* c = new ConwayCell(false);
    assert(!c->_alive);
    c->evolve(3);
    assert(c->_alive);
    
}

TEST(AbstactCell, evolve5) {
    AbstractCell* c = new ConwayCell(false);
    assert(!c->_alive);
    c->evolve(2);
    assert(!c->_alive);
}

TEST(ConwayCell, constructor1) {
    ConwayCell c(true);
    assert(c._alive);
}

TEST(ConwayCell, constructor2) {
    ConwayCell c(false);
    assert(!c._alive);
}

TEST(ConwayCell, constructor3) {
    ConwayCell c(true);
    ConwayCell c2 = c;
    assert(&c != &c2);
    assert(c._alive);
    assert(c2._alive);
}

TEST(ConwayCell, destructor1) {
    {
        ConwayCell c(false);
    }
}

TEST(ConwayCell, destructor2) {
    {
        ConwayCell c(true);
    }
}

TEST(ConwayCell, destructor3) {
    {
        ConwayCell c(false);
        ConwayCell c2 = c;
    }
}

TEST(ConwayCell, clone1) {
    ConwayCell c(true);
    ConwayCell* cp = c.clone();

    assert(cp != & c);
    assert(cp->_alive);
}

TEST(ConwayCell, clone2) {
    ConwayCell c(false);
    ConwayCell* cp = c.clone();

    assert(cp != & c);
    assert(!cp->_alive);
}

TEST(ConwayCell, clone3) {
    ConwayCell* cp;
    {
        ConwayCell c(true);
        cp = c.clone();
    }

    assert(cp);
    assert(cp->_alive);
}

TEST(ConwayCell, evolve1) {
    ConwayCell c(false);
    assert(!c._alive);

    c.evolve(1);
    assert(!c._alive);
}

TEST(ConwayCell, evolve2) {
    ConwayCell c(false);
    assert(!c._alive);

    c.evolve(3);
    assert(c._alive);
}

TEST(ConwayCell, evolve3) {
    ConwayCell c(false);
    assert(!c._alive);

    c.evolve(50);
    assert(!c._alive);
}

TEST(ConwayCell, evolve4) {
    ConwayCell c(true);
    assert(c._alive);

    c.evolve(2);
    assert(c._alive);
}

TEST(ConwayCell, evolve5) {
    ConwayCell c(true);
    assert(c._alive);

    c.evolve(1);
    assert(!c._alive);
}

TEST(ConwayCell, print1) {
    ConwayCell c(true);

    ostringstream out;
    c.print(out);

    assert(out.str() == "*");
}

TEST(ConwayCell, print2) {
    ConwayCell c(false);

    ostringstream out;
    c.print(out);

    assert(out.str() == ".");    
}

TEST(ConwayCell, print3) {
    ConwayCell c(false);
    ConwayCell* c2 = c.clone();
    c.evolve(3);

    ostringstream out;
    c.print(out);
    c2->print(out);

    assert(out.str() == "*.");  
}

// test corner cell
TEST(ConwayCell, neighbors1) {
    vector<ConwayCell> cells(9, ConwayCell(true));
    ConwayCell c = cells[0];
    assert(c.livingNeighbors(0, 0, 3, 3, &cells) == 3);
}

// test interior cell
TEST(ConwayCell, neighbors2) {
    vector<ConwayCell> cells(9, ConwayCell(true));
    ConwayCell c = cells[0];
    assert(c.livingNeighbors(1, 1, 3, 3, &cells) == 8);
}

// test edge cell
TEST(ConwayCell, neighbors3) {
    vector<ConwayCell> cells(9, ConwayCell(true));
    ConwayCell c = cells[0];
    assert(c.livingNeighbors(0, 1, 3, 3, &cells) == 5);
}

TEST(FredkinCell, constructor1) {
    FredkinCell f(true, 0);
    assert(f._alive);
    assert(f._age == 0);
}

TEST(FredkinCell, constructor2) {
    FredkinCell f(false, 0);
    assert(!f._alive);
    assert(f._age == 0);
}

TEST(FredkinCell, constructor3) {
    FredkinCell f(true, 3);
    assert(f._alive);
    assert(f._age == 3);
}

TEST(FredkinCell, destructor1) {
    {
        FredkinCell f(true, 0);
    }
}

TEST(FredkinCell, destructor2) {
    {
        FredkinCell f(false, 0);
    }
}

TEST(FredkinCell, destructor3) {
    {
        FredkinCell f(true, 0);
        FredkinCell f2 = f;
    }
}

TEST(FredkinCell, clone1) {
    FredkinCell f(true, 0);
    FredkinCell* f2 = f.clone();

    assert(f2 != &f);
    assert(f._alive == f2->_alive);
    assert(f._age == f2->_age);
}

TEST(FredkinCell, clone2) {
    FredkinCell f(true, 0);
    FredkinCell* f2 = f.clone();

    assert(f2 != &f);
    assert(f._alive == f2->_alive);
    assert(f._age == f2->_age);

    f2->_age = 3;
    assert(f2->_age != f._age);
}

TEST(FredkinCell, clone3) {
    FredkinCell* f2;
    {
        FredkinCell f(true, 0);
        f2 = f.clone();
    }

    assert(f2);
    assert(f2->_alive);
    assert(0 == f2->_age);
}

TEST(FredkinCell, evolve1) {
    FredkinCell f(true, 0);

    assert(f._age == 0);

    f.evolve(1);
    assert(f._alive);
    assert(f._age == 1);
}

TEST(FredkinCell, evolve2) {
    FredkinCell f(false, 0);

    assert(f._age == 0);

    f.evolve(1);
    assert(f._alive);
    assert(f._age == 0);
}

TEST(FredkinCell, evolve3) {
    FredkinCell f(true, 0);

    assert(f._age == 0);

    f.evolve(2);
    assert(!f._alive);
    assert(f._age == 0);
}

TEST(FredkinCell, evolve4) {
    FredkinCell f(false, 0);

    assert(f._age == 0);

    f.evolve(2);
    assert(!f._alive);
    assert(f._age == 0);
}

TEST(FredkinCell, print1) {
    FredkinCell f(true, 0);

    ostringstream out;
    f.print(out);

    assert(out.str() == "0");
    
}

TEST(FredkinCell, print2) {
    FredkinCell f(false, 0);

    ostringstream out;
    f.print(out);

    assert(out.str() == "-");
}

TEST(FredkinCell, print3) {
    FredkinCell f(true, 7);

    ostringstream out;
    f.print(out);

    assert(out.str() == "7");
}

TEST(FredkinCell, print4) {
    FredkinCell f(true, 17);

    ostringstream out;
    f.print(out);

    assert(out.str() == "+");
}

// corner cell
TEST(FredkinCell, neighbors1) {
    vector<FredkinCell> cells(9, FredkinCell(true, 0));
    FredkinCell f = cells[0];
    assert(f.livingNeighbors(0, 0, 3, 3, &cells) == 2);
}

// inner cell
TEST(FredkinCell, neighbors2) {
    vector<FredkinCell> cells(9, FredkinCell(true, 0));
    FredkinCell f = cells[0];
    assert(f.livingNeighbors(1, 1, 3, 3, &cells) == 4);
}

// edge cell
TEST(FredkinCell, neighbors3) {
    vector<FredkinCell> cells(9, FredkinCell(true, 0));
    FredkinCell f = cells[0];
    assert(f.livingNeighbors(1, 0, 3, 3, &cells) == 3);
}

TEST(FredkinCell, mutate1) {
    FredkinCell f(true, 1);

    assert(!f.mutate());
}

TEST(FredkinCell, mutate2) {
    FredkinCell f(true, 2);

    assert(f.mutate());
}

TEST(FredkinCell, mutate3) {
    FredkinCell f(false, 2);

    assert(!f.mutate());
}

TEST(Cell, constructor1) {
    Cell c = new ConwayCell(true);

    assert(c.get());
    assert(c.get()->_alive);
}

TEST(Cell, constructor2) {
    Cell c = new FredkinCell(false, 0);

    assert(c.get());
    assert(!c.get()->_alive);
}

TEST(Cell, constructor3) {
    Cell c = new ConwayCell(true);
    Cell c2 = c;

    assert (&c != &c2);
    assert (c2.get()->_alive == c.get()->_alive);
}

TEST(Cell, evolve1) {
    Cell c = new ConwayCell(true);
    assert (c.get()->_alive);

    c.evolve(2);
    assert (c.get()->_alive);
}

TEST(Cell, evolve2) {
    Cell c = new ConwayCell(false);
    assert (!c.get()->_alive);
    
    c.evolve(2);
    assert (!c.get()->_alive);
}

TEST(Cell, evolve3) {
    Cell c = new FredkinCell(true, 0);
    assert (c.get()->_alive);
    
    c.evolve(2);
    assert (!c.get()->_alive);
}

TEST(Cell, evolve4) {
    Cell c = new FredkinCell(true, 0);
    assert (c.get()->_alive);
    
    c.evolve(3);
    assert (c.get()->_alive);
}

TEST(Cell, evolve5) {
    Cell c = new FredkinCell(true, 1);
    assert (c.get()->_alive);
    assert (dynamic_cast<FredkinCell*>(c.get()) != NULL);
    
    c.evolve(3);
    assert (c.get()->_alive);
    assert (dynamic_cast<ConwayCell*>(c.get()) != NULL);
}

TEST(Cell, print1) {
    Cell c = new FredkinCell(true, 10);

    ostringstream out;
    out << c;

    assert(out.str() == "+");
}

TEST(Cell, print2) {
    Cell c = new FredkinCell(false, 10);

    ostringstream out;
    out << c;

    assert(out.str() == "-");
}

TEST(Cell, print3) {
    Cell c = new ConwayCell(true);

    ostringstream out;
    out << c;

    assert(out.str() == "*");
}

TEST(Cell, print4) {
    Cell c = new ConwayCell(false);

    ostringstream out;
    out << c;

    assert(out.str() == ".");
}

TEST(Cell, print5) {
    Cell c = new FredkinCell(true, 3);

    ostringstream out;
    out << c;

    assert(out.str() == "3");
}

// corner conway
TEST(Cell, neighbors1) {
    vector<Cell> cells(9, new FredkinCell(true, 0));

    Cell c = new ConwayCell(true);
    assert(c.livingNeighbors(0, 0, 3, 3, &cells) == 3);
}

// interior conway
TEST(Cell, neighbors2) {
    vector<Cell> cells(9, new FredkinCell(true, 0));

    Cell c = new ConwayCell(true);
    assert(c.livingNeighbors(1, 1, 3, 3, &cells) == 8);
}

// side conway
TEST(Cell, neighbors3) {
    vector<Cell> cells(9, new FredkinCell(true, 0));

    Cell c = new ConwayCell(true);
    assert(c.livingNeighbors(1, 0, 3, 3, &cells) == 5);
}

// corner fredkin
TEST(Cell, neighbors4) {
    vector<Cell> cells(9, new FredkinCell(true, 0));

    Cell f = new FredkinCell(true, 0);
    assert(f.livingNeighbors(0, 0, 3, 3, &cells) == 2);
}

// interior fredkin
TEST(Cell, neighbors5) {
    vector<Cell> cells(9, new FredkinCell(true, 0));

    Cell f = new FredkinCell(true, 0);
    assert(f.livingNeighbors(1, 1, 3, 3, &cells) == 4);
}

// side fredkin
TEST(Cell, neighbors6) {
    vector<Cell> cells(9, new FredkinCell(true, 0));

    Cell f = new FredkinCell(true, 0);
    assert(f.livingNeighbors(1, 0, 3, 3, &cells) == 3);
}

TEST(Cell, mutate1) {
    Cell f = new FredkinCell(true, 0);
    assert(dynamic_cast<FredkinCell*>(f.get()) != NULL);

    f.mutate();
    assert(dynamic_cast<FredkinCell*>(f.get()) != NULL);
}

TEST(Cell, mutate2) {
    Cell f = new FredkinCell(true, 2);
    assert(dynamic_cast<FredkinCell*>(f.get()) != NULL);

    f.mutate();
    assert(dynamic_cast<FredkinCell*>(f.get()) == NULL);
}

TEST(Cell, mutate3) {
    Cell f = new FredkinCell(false, 2);
    assert(dynamic_cast<FredkinCell*>(f.get()) != NULL);

    f.mutate();
    assert(dynamic_cast<FredkinCell*>(f.get()) != NULL);
}

TEST(Cell, mutate4) {
    Cell c = new ConwayCell(true);
    assert(dynamic_cast<ConwayCell*>(c.get()) != NULL);

    c.mutate();
    assert(dynamic_cast<ConwayCell*>(c.get()) != NULL);
}

TEST(Life, constructor1) {
    Life<Cell> life(2,3);
    assert(life._pop == 0);
    assert(life._turn == 0);
    assert(life._rows == 2);
    assert(life._cols == 3);
}

TEST(Life, constructor2) {
    Life<Cell> life(5,3);
    assert(life._pop == 0);
    assert(life._turn == 0);
    assert(life._rows == 5);
    assert(life._cols == 3);
}

TEST(Life, constructor3) {
    Life<Cell> life(2,3);
    assert(life._pop == 0);
    assert(life._turn == 0);
    assert(life._rows == 2);
    assert(life._cols == 3);

    Life<Cell> l2 = life;
    assert(l2._pop == 0);
    assert(l2._turn == 0);
    assert(l2._rows == 2);
    assert(l2._cols == 3);
}

TEST(Life, load1) {
    Life<ConwayCell> life(2,3);

    vector<ConwayCell> vec(6, ConwayCell(true));

    life.loadCells(vec, 6);
    assert(life._pop == 6);
    assert(life._turn == 0);
    assert(life._rows == 2);
    assert(life._cols == 3);
    assert(life._cells.size() == 6);
}

TEST(Life, load2) {
    Life<ConwayCell> life(2,3);

    vector<ConwayCell> vec(6, ConwayCell(false));

    life.loadCells(vec, 0);
    assert(life._pop == 0);
    assert(life._turn == 0);
    assert(life._rows == 2);
    assert(life._cols == 3);
    assert(life._cells.size() == 6);
}

TEST(Life, load3) {
    Life<FredkinCell> life(2,3);

    vector<FredkinCell> vec(6, FredkinCell(false, 0));

    life.loadCells(vec, 0);
    assert(life._pop == 0);
    assert(life._turn == 0);
    assert(life._rows == 2);
    assert(life._cols == 3);
    assert(life._cells.size() == 6);
}

TEST(Life, print1) {
    Life<ConwayCell> life(1, 1);

    vector<ConwayCell> vec(1, ConwayCell(true));
    life.loadCells(vec, 1);

    ostringstream out;
    life.print(out);

    assert(out.str() == "\nGeneration = 0, Population = 1.\n*\n");
}

TEST(Life, print2) {
    Life<ConwayCell> life(2, 2);

    vector<ConwayCell> vec(4, ConwayCell(true));
    life.loadCells(vec, 4);

    ostringstream out;
    life.print(out);

    assert(out.str() == "\nGeneration = 0, Population = 4.\n**\n**\n");
}

TEST(Life, print3) {
    Life<FredkinCell> life(2, 2);

    vector<FredkinCell> vec(4, FredkinCell(true, 0));
    life.loadCells(vec, 4);

    ostringstream out;
    life.print(out);

    assert(out.str() == "\nGeneration = 0, Population = 4.\n00\n00\n");
}

TEST(Life, run1) {
    Life<FredkinCell> life(2, 2);

    vector<FredkinCell> vec(4, FredkinCell(true, 0));
    life.loadCells(vec, 4);
    assert(life._pop == 4);

    life.run();
    assert(life._pop == 0);
}

TEST(Life, run2) {
    Life<ConwayCell> life(2, 2);

    vector<ConwayCell> vec(4, ConwayCell(true));
    life.loadCells(vec, 4);
    assert(life._pop == 4);

    life.run();
    assert(life._pop == 4);
}

TEST(Life, run3) {
    Life<ConwayCell> life(2, 2);

    vector<ConwayCell> vec(4, ConwayCell(true));
    vec[3] = ConwayCell(false);
    life.loadCells(vec, 3);
    assert(life._pop == 3);

    life.run();
    assert(life._pop == 4);
}

TEST(Handle, constructor1) {
    int* x = new int(5);
    Handle<int> h(x);

    assert(h._p == x);
}

TEST(Handle, constructor2) {
    int* x = new int(5);
    Handle<int> h(x);

    *x = 7;

    assert(h._p == x);
    assert(*(h._p) == 7);
}

TEST(Handle, eq1) {
    int* x = new int(5);
    int* y = new int(5);
    Handle<int> h(x);
    Handle<int> h2(y);

    assert(h._p == x);
    assert(h2._p == y);
    assert(h == h2);
}

TEST(Handle, eq2) {
    int* x = new int(5);
    int* y = new int(7);
    Handle<int> h(x);
    Handle<int> h2(y);

    assert(h._p == x);
    assert(h2._p == y);
    assert(h != h2);
}

TEST(Handle, eq3) {
    int* x = new int(5);
    int* y = new int(7);
    Handle<int> h(x);
    Handle<int> h2(y);

    assert(h._p == x);
    assert(h2._p == y);
    assert(h != h2);

    *y = 5;
    assert(h == h2);
}

TEST(Handle, get1) {
    int* x = new int(5);
    int* y = new int(5);
    Handle<int> h(x);
    Handle<int> h2(y);

    int* p = h.get();
    assert(p == x);
}

TEST(Handle, get2) {
    int* x = new int(5);
    int* y = new int(5);
    Handle<int> h(x);
    Handle<int> h2(y);

    int* p = h2.get();
    assert(p == y);
}

TEST(Handle, get3) {
    int* x = new int(5);
    Handle<int> h(x);

    int* p = h.get();
    x = new int(5);
    assert(p != x);
}