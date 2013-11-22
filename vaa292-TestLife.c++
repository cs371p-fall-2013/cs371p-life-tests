// --------------------------------
// TestLife.c++
// Copyright (C) 2013
// Victor Aguilar and Josh Guan
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

*/

// --------
// includes
// --------


#include <iostream> // cout, endl
#include <sstream> // istringtstream, ostringstream
#include <string> // ==

#define private public

#include "gtest/gtest.h"
#include "Handle.h"
#include "Cell.h"
#include "Life.h"
#include "AbstractCell.h"


// --------
// TestLife
// --------

using namespace std;


// ------------
// AbstractCell
// ------------

TEST(Life, AbstractCell_allfunctions1) {
    //default constructor and default member values
    AbstractCell t;
    ASSERT_EQ(0, t.age);
    ASSERT_EQ(0, t.cn);
    ASSERT_EQ(0, t.dn);
    ASSERT_EQ(DEAD, t.state);
    ASSERT_EQ('X', t.symbol);
    ASSERT_EQ(0, t.immutable);



    //operator= and change_state
    AbstractCell q;
    q.change_state();
    t = q;
    ASSERT_EQ(ALIVE, t.state);

    //next_state
    ASSERT_EQ(DEAD, q.next_state(-1,-1));

    //get_age
    ASSERT_EQ(0, q.get_age());

    //mutate
    ASSERT_EQ(NULL, q.mutate());

    //clone
    ASSERT_EQ(NULL, q.clone());

    }

TEST(Life, AbstractCell_allfunctions2) {
    //default constructor and default member values
    AbstractCell t;
    ASSERT_EQ(0, t.age);
    ASSERT_EQ(0, t.cn);
    ASSERT_EQ(0, t.dn);
    ASSERT_EQ(DEAD, t.state);
    ASSERT_EQ('X', t.symbol);
    ASSERT_EQ(0, t.immutable);


    //operator= and change_state
    AbstractCell q;
    ASSERT_EQ(DEAD, t.state);
    q.change_state();
    t = q;
    ASSERT_EQ(ALIVE, t.state);

    //next_state
    ASSERT_EQ(DEAD, q.next_state(-1,-1));

    //get_age
    ASSERT_EQ(0, q.get_age());

    //mutate
    ASSERT_EQ(NULL, q.mutate());

    //clone
    ASSERT_EQ(NULL, q.clone());}

TEST(Life, AbstractCell_allfunctions3) {
    //default constructor and default member values
    AbstractCell t;
    ASSERT_EQ(0, t.age);
    ASSERT_EQ(0, t.cn);
    ASSERT_EQ(0, t.dn);
    ASSERT_EQ(DEAD, t.state);
    ASSERT_EQ('X', t.symbol);
    ASSERT_EQ(0, t.immutable);

    //operator= and change_state
    AbstractCell q;
    q.change_state();
    t = q;
    ASSERT_EQ(ALIVE, t.state);
    AbstractCell r;
    r = t;
    ASSERT_EQ(ALIVE, r.state);

    //next_state
    ASSERT_EQ(DEAD, q.next_state(-1,-1));

    //get_age
    ASSERT_EQ(0, q.get_age());

    //mutate
    ASSERT_EQ(NULL, q.mutate());

    //clone
    ASSERT_EQ(NULL, q.clone());}

// ----
// Cell
// ----

TEST(Life, Cell_allfunctions1) {
    //constructor and member variables;
    Cell t;
    ASSERT_EQ('-', t.symbol);
    ASSERT_EQ(DEAD, t.state);
    ASSERT_EQ(0, t.age);
    ASSERT_EQ(0, t.cross_neighbors);
    ASSERT_EQ(0, t.diagonal_neighbors);

    //get_state
    ASSERT_EQ(DEAD, t.get_state());

    //clone
    Cell* tc = t.clone();
    ASSERT_EQ('-', tc->symbol);
    delete tc; //for testing purposes

    //change_state
    t.change_state();
    ASSERT_EQ(ALIVE, t.get_state());

    //mutate and next_state
    t.mutate('*');
    ASSERT_EQ(ALIVE, t.next_state(1, 1));
    ASSERT_EQ(DEAD, t.next_state(0, 0));
}

TEST(Life, Cell_allfunctions2) {
    //constructor and member variables;
    Cell t;
    ASSERT_EQ('-', t.symbol);
    ASSERT_EQ(DEAD, t.state);
    ASSERT_EQ(0, t.age);
    ASSERT_EQ(0, t.cross_neighbors);
    ASSERT_EQ(0, t.diagonal_neighbors);

    //get_state
    ASSERT_EQ(DEAD, t.get_state());

    //clone
    Cell* tc = t.clone();
    ASSERT_EQ('-', tc->symbol);
    delete tc; //for testing purposes

    //change_state
    t.change_state();
    ASSERT_EQ(ALIVE, t.get_state());

    //mutate and next_state
    t.mutate('.');
    ASSERT_EQ(DEAD, t.next_state(1, 1));
    ASSERT_EQ(ALIVE, t.next_state(2, 1));
}

TEST(Life, Cell_allfunctions3) {
    //constructor and member variables;
    Cell t;
    ASSERT_EQ('-', t.symbol);
    ASSERT_EQ(DEAD, t.state);
    ASSERT_EQ(0, t.age);
    ASSERT_EQ(0, t.cross_neighbors);
    ASSERT_EQ(0, t.diagonal_neighbors);

    //get_state
    ASSERT_EQ(DEAD, t.get_state());

    //clone
    Cell* tc = t.clone();
    ASSERT_EQ('-', tc->symbol);
    delete tc; //for testing purposes

    //change_state
    t.change_state();
    ASSERT_EQ(ALIVE, t.get_state());

    //mutate and next_state
    t.mutate('*');
    ASSERT_EQ(ALIVE, t.next_state(1, 1));
    ASSERT_EQ(ALIVE, t.next_state(1, 2));
}



// ----------
// ConwayCell
// ----------

TEST(Life, ConwayCell_allfunctions1) {
    //constructor and member variables;
    ConwayCell t;
    ASSERT_EQ('.', t.symbol);
    ASSERT_EQ(DEAD, t.state);
    ASSERT_EQ(0, t.age);

    //get_state
    ASSERT_EQ(DEAD, t.state);

    //clone
    AbstractCell* tc = t.clone();
    ASSERT_EQ('.', tc->symbol);
    delete tc; //for testing purposes

    //change_state
    t.change_state();
    ASSERT_EQ(ALIVE, t.state);

    //next_state from A -> D or A
    ASSERT_EQ(ALIVE, t.next_state(1, 1));
    ASSERT_EQ(DEAD, t.next_state(0, 0));
}


TEST(Life, ConwayCell_allfunctions2) {
    //constructor and member variables;
    ConwayCell t('*');
    ASSERT_EQ('*', t.symbol);
    ASSERT_EQ(ALIVE, t.state);
    ASSERT_EQ(0, t.age);

    //get_state
    ASSERT_EQ(ALIVE, t.state);

    //clone
    AbstractCell* tc = t.clone();
    ASSERT_EQ('*', tc->symbol);
    delete tc; //for testing purposes

    //change_state
    t.change_state();
    ASSERT_EQ(DEAD, t.state);

    //next_state from D -> D or A
    ASSERT_EQ(ALIVE, t.next_state(2, 1));
    ASSERT_EQ(DEAD, t.next_state(0, 0));
}


TEST(Life, ConwayCell_allfunctions3) {
    //constructor and member variables;
    ConwayCell t;
    ASSERT_EQ('.', t.symbol);
    ASSERT_EQ(DEAD, t.state);
    ASSERT_EQ(0, t.age);

    //get_state
    ASSERT_EQ(DEAD, t.state);

    //clone
    AbstractCell* tc = t.clone();
    ASSERT_EQ('.', tc->symbol);
    delete tc; //for testing purposes

    //change_state
    t.change_state();
    ASSERT_EQ(ALIVE, t.state);

    //next_state from A -> D or A
    ASSERT_EQ(ALIVE, t.next_state(1, 1));
    ASSERT_EQ(DEAD, t.next_state(0, 0));
}

TEST(Life, FredkinCell_allfunctions1) {
    //constructor and member variables;
    FredkinCell t;
    ASSERT_EQ('-', t.symbol);
    ASSERT_EQ(DEAD, t.state);
    ASSERT_EQ(0, t.age);

    //get_state
    ASSERT_EQ(DEAD, t.state);

    //clone
    AbstractCell* tc = t.clone();
    ASSERT_EQ('-', tc->symbol);
    delete tc; //for testing purposes

    //change_state
    t.change_state();
    ASSERT_EQ(ALIVE, t.state);

    //next_state from A -> D or A
    ASSERT_EQ(ALIVE, t.next_state(1, 0));
    ASSERT_EQ(DEAD, t.next_state(0, 0));
}

TEST(Life, FredkinCell_allfunctions2) {
    //constructor and member variables;
    FredkinCell t('2');
    ASSERT_EQ('2', t.symbol);
    ASSERT_EQ(ALIVE, t.state);
    ASSERT_EQ(2, t.age);

    //get_state
    ASSERT_EQ(ALIVE, t.state);

    //clone
    AbstractCell* tc = t.clone();
    ASSERT_EQ('2', tc->symbol);
    delete tc; //for testing purposes

    //change_state
    t.change_state();
    ASSERT_EQ(DEAD, t.state);

    //next_state from D -> D or A
    ASSERT_EQ(ALIVE, t.next_state(1, 0));
    ASSERT_EQ(DEAD, t.next_state(0, 0));
}

TEST(Life, FredkinCell_allfunctions3) {
    //constructor and member variables;
    FredkinCell t('+');
    ASSERT_EQ('+', t.symbol);
    ASSERT_EQ(ALIVE, t.state);
    ASSERT_EQ(10, t.age);

    //get_state
    ASSERT_EQ(ALIVE, t.state);

    //clone
    AbstractCell* tc = t.clone();
    ASSERT_EQ('+', tc->symbol);
    delete tc; //for testing purposes

    //change_state
    t.change_state();
    ASSERT_EQ(DEAD, t.state);

    //next_state from D -> D or A
    ASSERT_EQ(ALIVE, t.next_state(1, 0));
    ASSERT_EQ(DEAD, t.next_state(0, 0));
}



// ------
// Handle
// ------
TEST(Life, Handle_allfunctions_with_ConwayCell) {
    //default constructor and get
    ConwayCell* ccp = NULL;
    Handle<AbstractCell> test1(ccp);

    ASSERT_EQ(NULL, test1.get());
    ConwayCell* ccp2 = NULL;
    const Handle<AbstractCell> test2(ccp2);
    ASSERT_EQ(NULL, test2.get());

    //pointer constructor and get const
    Handle<AbstractCell> test3(reinterpret_cast<ConwayCell *> (new ConwayCell(ALIVE)) );
    ASSERT_EQ(ALIVE, test3.get()->state);

    //copy constructor1 and get
    Handle<AbstractCell> test4(test2);
    ASSERT_EQ(NULL, test4.get());


    //copy constructor2 and get
    ConwayCell* cp3 = new ConwayCell();
    const Handle<AbstractCell> test5(cp3) ;
    Handle<AbstractCell> copyhandle(test5);
    ASSERT_EQ(DEAD, copyhandle.get()->state);
 

    //destructor
    // --> Valgrind gives strong evidence of no memory leaks
    int destructor_call = Handle<AbstractCell>::destructor_total;
    ConwayCell* cp4 = new ConwayCell(ALIVE);
    {
        Handle<AbstractCell> dhandle(cp4);
    }
    ASSERT_EQ(destructor_call + 1, Handle<AbstractCell>::destructor_total);
    
  
    //set method as well as get
    ConwayCell* cp5 = new ConwayCell('*');
    ConwayCell* cp6 = new ConwayCell();
    Handle<AbstractCell> switchHandle(cp5);

    ASSERT_EQ(ALIVE, switchHandle.get()->state);
   
    switchHandle.set(cp6);
    ASSERT_EQ(DEAD, switchHandle.get()->state);


    //swap method
    ConwayCell* cp7 = new ConwayCell('*');
    Handle<AbstractCell> h1(cp7);
    ConwayCell* cp8 = new ConwayCell();
    Handle<AbstractCell> h2(cp8);
    h2.swap(h1);
    ASSERT_EQ(ALIVE,h2.get()->state);
    ASSERT_EQ(DEAD,h1.get()->state);

    // operator= method
    h1 = h2;
    ASSERT_EQ(ALIVE,h1.get()->state);
    ASSERT_EQ(ALIVE,h2.get()->state);  
    
    }

TEST(Life, Handle_allfunctions_with_FredkinCell) {
    //default constructor and get
    FredkinCell* ccp = NULL;
    Handle<AbstractCell> test1(ccp);

    ASSERT_EQ(NULL, test1.get());
    FredkinCell* ccp2 = NULL;
    const Handle<AbstractCell> test2(ccp2);
    ASSERT_EQ(NULL, test2.get());

    //pointer constructor and get const
    Handle<AbstractCell> test3(reinterpret_cast<FredkinCell *> (new FredkinCell(ALIVE)) );
    ASSERT_EQ(ALIVE, test3.get()->state);

    //copy constructor1 and get
    Handle<AbstractCell> test4(test2);
    ASSERT_EQ(NULL, test4.get());


    //copy constructor2 and get
    FredkinCell* cp3 = new FredkinCell();
    const Handle<AbstractCell> test5(cp3) ;
    Handle<AbstractCell> copyhandle(test5);
    ASSERT_EQ(DEAD, copyhandle.get()->state);
 

    //destructor
    // --> Valgrind gives strong evidence of no memory leaks
    int destructor_call = Handle<AbstractCell>::destructor_total;
    FredkinCell* cp4 = new FredkinCell(ALIVE);
    {
        Handle<AbstractCell> dhandle(cp4);
    }
    ASSERT_EQ(destructor_call + 1, Handle<AbstractCell>::destructor_total);
    
  
    //set method as well as get
    FredkinCell* cp5 = new FredkinCell('2');
    FredkinCell* cp6 = new FredkinCell();
    Handle<AbstractCell> switchHandle(cp5);

    ASSERT_EQ(ALIVE, switchHandle.get()->state);
   
    switchHandle.set(cp6);
    ASSERT_EQ(DEAD, switchHandle.get()->state);


    //swap method
    FredkinCell* cp7 = new FredkinCell('+');
    Handle<AbstractCell> h1(cp7);
    FredkinCell* cp8 = new FredkinCell();
    Handle<AbstractCell> h2(cp8);
    h2.swap(h1);
    ASSERT_EQ(ALIVE,h2.get()->state);
    ASSERT_EQ(DEAD,h1.get()->state);

    // operator= method
    h1 = h2;
    ASSERT_EQ(ALIVE,h1.get()->state);
    ASSERT_EQ(ALIVE,h2.get()->state);  
    
    }




// ----
// Life
// ----

TEST(Life, Life_h_allfunctions_with_cell) {
    // constructor, read_in, get, data member variables 
    // and constructor_total
    int constructor_count = Life<Cell>::constructor_total;
    Life<Cell> t("test2.txt");
    ASSERT_EQ(constructor_count + 1, Life<Cell>::constructor_total);
    ASSERT_EQ(0, t.rows);
    ASSERT_EQ(0, t.cols);
    ASSERT_EQ(0, t.generations);
    ASSERT_EQ(0, t.population);

    //print_grid
    t.print_grid(); //works; check by inspection

    //next_test_case and read_in
    t.next_test_case();
    ASSERT_EQ(3, t.rows);
    ASSERT_EQ(3, t.cols);
    ASSERT_EQ(0, t.generations);
    ASSERT_EQ(0, t.population);

    //cross_neighbors and get (internal)
    int cn = t.cross_neighbors(0,0);
    ASSERT_EQ(0, cn);

    //diagonal_neighbors and get (internal)
    int dn = t.diagonal_neighbors(0,0);
    ASSERT_EQ(0, dn);

    //next_generation
    t.next_generation();
    ASSERT_EQ(3, t.rows);
    ASSERT_EQ(3, t.cols);
    ASSERT_EQ(1, t.generations);
    ASSERT_EQ(0, t.population);  

    //count_population
    t.count_population();
    ASSERT_EQ(0, t.population);  

    //next_test_case and read_in    
    ASSERT_FALSE(t.next_test_case());  
    }


TEST(Life, Life_h_allfunctions_with_conwaycell) {
    // constructor, read_in, get, data member variables 
    // and constructor_total
    int constructor_count = Life<ConwayCell>::constructor_total;
    Life<ConwayCell> t("test.txt");
    ASSERT_EQ(constructor_count + 1, Life<ConwayCell>::constructor_total);
    ASSERT_EQ(0, t.rows);
    ASSERT_EQ(0, t.cols);
    ASSERT_EQ(0, t.generations);
    ASSERT_EQ(0, t.population);

    //print_grid
    t.print_grid(); //works; check by inspection

    //next_test_case and read_in
    t.next_test_case();
    ASSERT_EQ(10, t.rows);
    ASSERT_EQ(10, t.cols);
    ASSERT_EQ(0, t.generations);
    ASSERT_EQ(0, t.population);

    //cross_neighbors and get (internal)
    int cn = t.cross_neighbors(0,0);
    ASSERT_EQ(0, cn);

    //diagonal_neighbors and get (internal)
    int dn = t.diagonal_neighbors(0,0);
    ASSERT_EQ(0, dn);

    //next_generation
    t.next_generation();
    ASSERT_EQ(10, t.rows);
    ASSERT_EQ(10, t.cols);
    ASSERT_EQ(1, t.generations);
    ASSERT_EQ(0, t.population);  

    //count_population
    t.count_population();
    ASSERT_EQ(0, t.population);  
    //NEXT TEST CASE
    //next_test_case and read_in    
    ASSERT_TRUE(t.next_test_case());
    t.print_grid();


    ASSERT_EQ(10, t.rows);
    ASSERT_EQ(10, t.cols);
    ASSERT_EQ(0, t.generations);
    ASSERT_EQ(4, t.population);

    //cross_neighbors and get (internal)
    cn = t.cross_neighbors(0,0);
    ASSERT_EQ(0, cn);

    //diagonal_neighbors and get (internal)
    dn = t.diagonal_neighbors(0,0);
    ASSERT_EQ(0, dn);

    //next_generation
    t.next_generation();
    t.print_grid();
    ASSERT_EQ(10, t.rows);
    ASSERT_EQ(10, t.cols);
    ASSERT_EQ(1, t.generations);
    ASSERT_EQ(4, t.population);  

    //count_population
    t.count_population();
    ASSERT_EQ(4, t.population);  
    ASSERT_FALSE(t.next_test_case());
    }


TEST(Life, Life_h_allfunctions_with_fredkincell) {
    // constructor, read_in, get, data member variables 
    // and constructor_total
    int constructor_count = Life<FredkinCell>::constructor_total;
    Life<FredkinCell> t("test3.txt");
    ASSERT_EQ(constructor_count + 1, Life<FredkinCell>::constructor_total);
    ASSERT_EQ(0, t.rows);
    ASSERT_EQ(0, t.cols);
    ASSERT_EQ(0, t.generations);
    ASSERT_EQ(0, t.population);

    //print_grid
    t.print_grid(); //works; check by inspection

    //next_test_case and read_in
    t.next_test_case();
    t.print_grid();
    ASSERT_EQ(2, t.rows);
    ASSERT_EQ(1, t.cols);
    ASSERT_EQ(0, t.generations);
    ASSERT_EQ(2, t.population);

    //cross_neighbors and get (internal)
    int cn = t.cross_neighbors(0,0);
    ASSERT_EQ(1, cn);

    //diagonal_neighbors and get (internal)
    int dn = t.diagonal_neighbors(0,0);
    ASSERT_EQ(0, dn);

    //next_generation
    t.next_generation();
    t.print_grid();
    ASSERT_EQ(2, t.rows);
    ASSERT_EQ(1, t.cols);
    ASSERT_EQ(1, t.generations);
    ASSERT_EQ(2, t.population);

    //count_population
    t.count_population();
    ASSERT_EQ(2, t.population);  
    //NEXT TEST CASE
    //next_test_case and read_in    
    ASSERT_FALSE(t.next_test_case());
 }