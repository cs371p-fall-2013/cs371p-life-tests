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

    % g++ -pedantic -std=c++0x -Wall Life.h TestLife.c++ -o TestLife -lgtest -lpthread -lgtest_main

    % valgrind TestLife > TestLife.out
*/

// --------
// includes
// --------
#define private public
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <vector>
#include <stdexcept>
#include "Life.h"
#include "AbstractCell.h"
#include "FredkinCell.h"
#include "ConwayCell.h"
#include "gtest/gtest.h"

using namespace std;

// -----------
// TestDarwin
// -----------

TEST(AbstractCell, getSym1){
    ConwayCell test('.');
    ASSERT_TRUE(test.getSym() == '.');
}

TEST(AbstractCell, getSym2){
    ConwayCell test('*');
    ASSERT_TRUE(test.getSym() == '*');
}


TEST(AbstractCell, getSym3){
    ConwayCell test('f');
    ASSERT_TRUE(test.getSym() != '.');
}

TEST(AbstractCell, getStatus1){
    ConwayCell c('.');
    ASSERT_TRUE(c.getStatus() == false);
}

TEST(AbstractCell, getStatus2){
    ConwayCell c('*');
    ASSERT_TRUE(c.getStatus() == true);
}

TEST(AbstractCell, setNext){
    ConwayCell c ('.');
    ASSERT_TRUE(c.getStatus() == false);
    c.setNext(true);
    c.update();
    ASSERT_TRUE(c.getStatus() == true);
}

TEST(AbstractCell, setNext2){
    ConwayCell c ('.');
    ASSERT_TRUE(c.getStatus() == false);
    c.setNext(false);
    c.update();
    ASSERT_TRUE(c.getStatus() != true);
}

TEST(AbstractCell, setNext3){
    ConwayCell c ('*');
    ASSERT_TRUE(c.getStatus() == true);
    c.setNext(false);
    c.update();
    ASSERT_TRUE(c.getStatus() != true);
}

TEST(AbstractCell, setNext4){
    FredkinCell f ('-');
    ASSERT_TRUE(f.getStatus() == false);
    f.setNext(true);
    f.update();
    ASSERT_TRUE(f.getStatus() == true);
}


TEST(ConwayCell, constructor1){
    ConwayCell test('.');
    ASSERT_TRUE(test.getStatus() == false);
}

TEST(ConwayCell, constructor2){
    ConwayCell test('*');
    ASSERT_TRUE(test.getStatus() == true);
}

TEST(ConwayCell, constructor3){
    ConwayCell test('*');
    ASSERT_TRUE(test.getStatus() != false);
}


TEST(ConwayCell, update1){
    ConwayCell test('*');
    ASSERT_TRUE(test.getStatus() == true);
    test.setNext(true);
    test.update();
    ASSERT_TRUE(test.getStatus() == true);
}

TEST(ConwayCell, update2){
    ConwayCell test('.');
    ASSERT_TRUE(test.getStatus() == false);
    test.setNext(true);
    test.update();
    ASSERT_TRUE(test.getStatus() == true);
    ASSERT_TRUE(test.getSym() == '*');
}

TEST(ConwayCell, update3){
    ConwayCell test('*');
    ASSERT_TRUE(test.getStatus() == true);
    test.setNext(false);
    test.update();
    ASSERT_TRUE(test.getStatus() == false);
    ASSERT_TRUE(test.getSym() == '.');
}


TEST(ConwayCell, update4){
    ConwayCell test('.');
    ASSERT_TRUE(test.getStatus() == false);
    test.setNext(false);
    test.update();
    ASSERT_TRUE(test.getStatus() == false);
    ASSERT_TRUE(test.getSym() == '.');
}

TEST(ConwayCell, update5){
    ConwayCell test('.');
    ASSERT_TRUE(test.getStatus() == false);
    test.setNext(false);
    test.update();
    ASSERT_TRUE(test.getStatus() != true);
    ASSERT_TRUE(test.getSym() != '*');
}

TEST(FredkinCell, constructor1){
    FredkinCell test('5');
    ASSERT_TRUE(test.getStatus() == true);

}

TEST(FredkinCell, constructor2){
    FredkinCell test('9');
    ASSERT_TRUE(test.getStatus() == true);
    
}

TEST(FredkinCell, constructor3){
    FredkinCell test('+');
    ASSERT_TRUE(test.getStatus() == true);
    
}


TEST(FredkinCell, constructor4){
    FredkinCell test('-');
    ASSERT_TRUE(test.getStatus() == false);
    
}


TEST(FredkinCell, constructor5){
    FredkinCell test('1');
    ASSERT_TRUE(test.getStatus() == true);
    
}

TEST(FredkinCell, constructor6){
    FredkinCell test('8');
    ASSERT_TRUE(test.getStatus() == true);
    
}

TEST(FredkinCell, update1){
    FredkinCell test('8');
    ASSERT_TRUE(test.getStatus() == true);

    test.setNext(true);
    test.update();
    // cout  << test.getSym() << endl;
    ASSERT_TRUE(test.getStatus() == true);
    ASSERT_TRUE(test.getSym() == '9');
    
}

TEST(FredkinCell, update2){
    FredkinCell test('5');
    ASSERT_TRUE(test.getStatus() == true);

    test.setNext(true);
    test.update();
    ASSERT_TRUE(test.getStatus() == true);
    ASSERT_TRUE(test.getSym() == '6');
    
}
TEST(FredkinCell, update3){
    FredkinCell test('-');
    ASSERT_TRUE(test.getStatus() == false);

    test.setNext(true);
    test.update();
    ASSERT_TRUE(test.getStatus() == true);
    ASSERT_TRUE(test.getSym() == '0');
    
}
TEST(FredkinCell, update4){
    FredkinCell test('1');
    ASSERT_TRUE(test.getStatus() == true);

    test.setNext(true);
    test.update();
    ASSERT_TRUE(test.getStatus() == true);
    ASSERT_TRUE(test.getSym() == '2');
    
}
TEST(FredkinCell, update5){
    FredkinCell test('4');
    ASSERT_TRUE(test.getStatus() == true);

    test.setNext(true);
    test.update();
    ASSERT_TRUE(test.getStatus() == true);
    ASSERT_TRUE(test.getSym() == '5');
    
}


TEST(FredkinCell, update6){
    FredkinCell test('4');
    ASSERT_TRUE(test.getStatus() == true);

    test.setNext(false);
    test.update();
    ASSERT_TRUE(test.getStatus() == false);
    ASSERT_TRUE(test.getSym() == '-');
    test.setNext(true);
    test.update();
    ASSERT_TRUE(test.getStatus() == true);
    ASSERT_TRUE(test.getSym() == '4');
    
}


TEST(Cell, getSym1){
    Cell c =  0;
    c = new ConwayCell('.');
    ASSERT_TRUE(c.getSym()=='.');
}

TEST(Cell, getSym2){
    Cell c =  0;
    c = new FredkinCell('1');
    ASSERT_TRUE(c.getSym()=='1');
}

TEST(Cell, getSym3){
    Cell c =  0;
    c = new ConwayCell('*');
    ASSERT_TRUE(c.getSym()=='*');
}


TEST(Cell, update1){
    Cell c =  0;
    c = new ConwayCell('*');
    c.setNext(false);
    c.update();
    ASSERT_TRUE(c.getSym() == '.');
}

TEST(Cell, update2){
    Cell c =  0;
    c = new FredkinCell('1');
    c.setNext(false);
    c.update();
    ASSERT_TRUE(c.getSym() == '-');
}

TEST(Cell, update3){
    Cell c =  0;
    c = new FredkinCell('-');
    c.setNext(true);
    c.update();
    ASSERT_TRUE(c.getSym() == '0');
}

TEST(Cell, update4){
    Cell c =  0;
    c = new FredkinCell('-');
    c.setNext(false);
    c.update();
    ASSERT_TRUE(c.getSym() == '-');
}


TEST(Cell, isAlive1){
    Cell c =  0;
    c = new ConwayCell('.');
    ASSERT_TRUE(c.isAlive() == 0);
}

TEST(Cell, isAlive2){
    Cell c =  0;
    c = new FredkinCell('1');
    ASSERT_TRUE(c.isAlive() == 1);
}

TEST(Cell, isAlive3){
    Cell c =  0;
    c = new FredkinCell('-');
    ASSERT_TRUE(c.isAlive()== 0);
}

TEST(Cell, setNext1){
    Cell c =  0;
    c = new ConwayCell('.');
    c.setNext(false);
    c.update();
    ASSERT_TRUE(c.isAlive() == 0);
}


TEST(Cell, setNext2){
    Cell c =  0;
    c = new ConwayCell('*');
    c.setNext(false);
    c.update();
    ASSERT_TRUE(c.isAlive() == 0);
}


TEST(Cell, setNext3){
    Cell c =  0;
    c = new ConwayCell('*');
    c.setNext(true);
    c.update();
    ASSERT_TRUE(c.isAlive() == 1);
}

TEST(Cell, setNext4){
    Cell c =  0;
    c = new FredkinCell('1');
    c.setNext(true);
    c.update();
    ASSERT_TRUE(c.isAlive() == 1);
}

TEST(Cell, setNext5){
    Cell c =  0;
    c = new FredkinCell('-');
    c.setNext(true);
    c.update();
    ASSERT_TRUE(c.isAlive() == 1);
}

TEST(Cell, setNext6){
    Cell c =  0;
    c = new FredkinCell('-');
    c.setNext(false);
    c.update();
    ASSERT_TRUE(c.isAlive() == 0);
}

TEST(Cell, mutate1){
    Cell c = 0;
    c = new FredkinCell('1');
    Cell test = c.mutate();
    ASSERT_TRUE(test.getSym() == '*');

}


TEST(Cell, mutate2){
    Cell c = 0;
    c = new FredkinCell('1');
    Cell test = c.mutate();
    ASSERT_TRUE(test.isAlive() == 1);

}


TEST(Cell, mutate3){
    Cell c = 0;
    c = new FredkinCell('1');
    Cell test = c.mutate();
    ASSERT_TRUE(test.isAlive() != 0);

}

TEST(Life, constructor1){
    string s = "3\n2\n..\n..\n..\n";
    std::istringstream is(s);
    Life<ConwayCell> test(is, cout);
    ASSERT_TRUE(test._row == 3);
    ASSERT_TRUE(test._col == 2);
}



TEST(Life, constructor2){
    string s = "5\n2\n..\n..\n..\n..\n..\n";
    std::istringstream is(s);
    Life<ConwayCell> test(is, cout);
    ASSERT_TRUE(test._row == 5);
    ASSERT_TRUE(test._col == 2);
}


TEST(Life, constructor3){
    string s = "1\n2\n..\n";
    std::istringstream is(s);
    Life<ConwayCell> test(is, cout);
    ASSERT_TRUE(test._row == 1);

    ASSERT_TRUE(test._col == 2);
}

TEST(Life, print1){
    string s = "1\n2\n..\n";
    std::istringstream is(s);
    std::ostringstream w;

    Life<ConwayCell> test(is, w);
    test.print();
    ASSERT_TRUE(test._row == 1);
    ASSERT_TRUE(test._col == 2);
    ASSERT_TRUE(w.str() == "Generation: 0 Population: 0\n..\n\n");
}

TEST(Life, print2){
    string s = "2\n2\n..\n*.\n";
    std::istringstream is(s);
    std::ostringstream w;

    Life<ConwayCell> test(is, w);
    test.print();
    ASSERT_TRUE(test._row == 2);
    ASSERT_TRUE(test._col == 2);
    ASSERT_TRUE(w.str() == "Generation: 0 Population: 1\n..\n*.\n\n");
}

TEST(Life, print3){
    string s = "3\n5\n.**..\n.*..*\n***.*\n";
    std::istringstream is(s);
    std::ostringstream w;

    Life<ConwayCell> test(is, w);
    test.print();
    ASSERT_TRUE(test._row == 3);
    ASSERT_TRUE(test._col == 5);
    ASSERT_TRUE(w.str() == "Generation: 0 Population: 8\n.**..\n.*..*\n***.*\n\n");
}


TEST(Life, updatePop1){
    string s = "1\n2\n*.\n";
    std::istringstream is(s);
    Life<ConwayCell> test(is, cout);
    test.updatePopulation();
    ASSERT_TRUE(test._pop == 1);
}



TEST(Life, updatePop2){
    string s = "1\n2\n**\n";
    std::istringstream is(s);
    Life<ConwayCell> test(is, cout);
    test.updatePopulation();
    ASSERT_TRUE(test._pop == 2);
}

TEST(Life, updatePop3){
    string s = "5\n2\n*.\n..\n.*\n.*\n.*\n";
    std::istringstream is(s);
    Life<ConwayCell> test(is, cout);
    test.updatePopulation();
    ASSERT_TRUE(test._pop == 4);
}

TEST(Life, simulate){
    string s = "5\n2\n..\n..\n..\n.*\n..\n";
    std::istringstream is(s);
    Life<ConwayCell> test(is, cout);
    test.updatePopulation();
    ASSERT_TRUE(test._pop == 1);
    test.simulate();
    test.updatePopulation();
    ASSERT_TRUE(test._pop == 0);
}


TEST(Life, simulate2){
    string s = "5\n3\n...\n.*.\n.*.\n.*.\n...\n";
    std::istringstream is(s);
    Life<ConwayCell> test(is, cout);
    test.updatePopulation();
    ASSERT_TRUE(test._pop == 3);
    test.simulate();
    test.updatePopulation();
    
    ASSERT_TRUE(test._pop == 3);
}

TEST(Life, simulate3){
    string s = "5\n3\n...\n.*.\n...\n.*.\n...\n";
    std::istringstream is(s);
    Life<ConwayCell> test(is, cout);
    test.updatePopulation();
    ASSERT_TRUE(test._pop == 2);
    test.simulate();
    test.updatePopulation();
   
    ASSERT_TRUE(test._pop == 0);
}