// ------------------------------------
// projects/allocator/TestLife.c++
// Copyright (C) 2013
// Colin Murray
// EID: cdm2697
// CS ID: tashar
// Email: murray.colin43@gmail.com
// ------------------------------------

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

// --------
// includes
// --------

#include "gtest/gtest.h"
#include <sstream>  // istringtstream, ostringstream
#include <iostream> // cout, endl
#include <sstream> // istringtstream, ostringstream
#include <string> // ==
#include <vector>

#define private public
#define protected public
#include "Life.h"
#include "AbstractCell.h"
#include "FredkinCell.h"
#include "ConwayCell.h"



// -----------------
// FredkinCell::
// -----------------
TEST(FredkinCell, default_construct) {
    FredkinCell f;
    ASSERT_TRUE(!f.is_living());
    ASSERT_TRUE(f._age == 0);
}

TEST(FredkinCell, default_construct_vector) {
    std::vector<FredkinCell> v(10);
    for(int i=0; i<10; i++) {
        ASSERT_TRUE(!v[i].is_living());
        ASSERT_TRUE(v[i]._age == 0);}
}

TEST(FredkinCell, bool_construct) {
    FredkinCell f(false);
    ASSERT_TRUE(!f.is_living());
    ASSERT_TRUE(f._age == 0);
}

TEST(FredkinCell, bool_construct2) {
    FredkinCell f(true);
    ASSERT_TRUE(f.is_living());
    ASSERT_TRUE(f._age == 0);
}

TEST(FredkinCell, bool_int_construct) {
    FredkinCell f(false, 4);
    ASSERT_TRUE(!f.is_living());
    ASSERT_TRUE(f._age == 4);
}

TEST(FredkinCell, bool_int_construct2) {
    FredkinCell f(true, 4);
    ASSERT_TRUE(f.is_living());
    ASSERT_TRUE(f._age == 4);
}

TEST(FredkinCell, read) {
    std::istringstream in("-");
    FredkinCell f(true, 1);
    f.read(in);
    ASSERT_TRUE(!f.is_living());
    ASSERT_TRUE(f._age == 0);
}

TEST(FredkinCell, read2) {
    std::istringstream in("1");
    FredkinCell f;
    f.read(in);
    ASSERT_TRUE(f.is_living());
    ASSERT_TRUE(f._age == 1);
}

TEST(FredkinCell, read3) {
    std::istringstream in("+");
    FredkinCell f;
    f.read(in);
    ASSERT_TRUE(f.is_living());
    ASSERT_TRUE(f._age == 10);
}

TEST(FredkinCell, read4_unknownChar) {
    std::istringstream in("*");
    FredkinCell f;
    f.read(in);
    ASSERT_TRUE(!f.is_living());
    ASSERT_TRUE(f._age == 0);
}

TEST(FredkinCell, read5_using_op) {
    std::istringstream in("5");
    FredkinCell f;
    in >> f;
    ASSERT_TRUE(f.is_living());
    ASSERT_TRUE(f._age == 5);
}

TEST(FredkinCell, read_from_char) {
    FredkinCell f(true, 1);
    f.read_from_char('-');
    ASSERT_TRUE(!f.is_living());
    ASSERT_TRUE(f._age == 0);
}

TEST(FredkinCell, read_from_char2) {
    FredkinCell f;
    f.read_from_char('1');
    ASSERT_TRUE(f.is_living());
    ASSERT_TRUE(f._age == 1);
}

TEST(FredkinCell, read_from_char3) {
    FredkinCell f;
    f.read_from_char('+');
    ASSERT_TRUE(f.is_living());
    ASSERT_TRUE(f._age == 10);
}

TEST(FredkinCell, read_from_char4_unknown) {
    FredkinCell f;
    f.read_from_char('*');
    ASSERT_TRUE(!f.is_living());
    ASSERT_TRUE(f._age == 0);
}

TEST(FredkinCell, write) {
    std::ostringstream out;
    FredkinCell f;
    f.write(out);
    ASSERT_TRUE(out.str() == "-");
}

TEST(FredkinCell, write2) {
    std::ostringstream out;
    FredkinCell f(true);
    f.write(out);
    ASSERT_TRUE(out.str() == "0");
}

TEST(FredkinCell, write3) {
    std::ostringstream out;
    FredkinCell f(true, 11);
    f.write(out);
    ASSERT_TRUE(out.str() == "+");
}

TEST(FredkinCell, write4_using_op) {
    std::ostringstream out;
    FredkinCell f(true, 5);
    out<<f;
    ASSERT_TRUE(out.str() == "5");
}

TEST(FredkinCell, equals) {
    std::ostringstream out;
    FredkinCell f(true, 5);
    FredkinCell x(true, 5);
    ASSERT_TRUE(f.equals(x));
}

TEST(FredkinCell, equals2) {
    std::ostringstream out;
    FredkinCell f(true, 5);
    FredkinCell x(true, 2);
    ASSERT_TRUE(!f.equals(x));
}

TEST(FredkinCell, equals3) {
    std::ostringstream out;
    FredkinCell f(true, 5);
    FredkinCell x(false, 5);
    ASSERT_TRUE(!f.equals(x));
}

TEST(FredkinCell, equals_op) {
    std::ostringstream out;
    FredkinCell f(true, 5);
    FredkinCell x(true, 5);
    ASSERT_TRUE(f == x);
}

TEST(FredkinCell, equals_op2) {
    std::ostringstream out;
    FredkinCell f(true, 5);
    FredkinCell x(true, 2);
    ASSERT_TRUE(f != x);
}

TEST(FredkinCell, clone) {
    std::ostringstream out;
    FredkinCell f(true, 5);
    FredkinCell* x = f.clone();
    ASSERT_TRUE(f == *x);
    delete x;
}

TEST(FredkinCell, state_transition) {
    bool b[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    FredkinCell f;
    f.state_transition(b);
    ASSERT_TRUE(f._transition_state == false);
}

TEST(FredkinCell, state_transition1) {
    bool b[8] = {0, 0, 1, 0, 0, 0, 0, 0};
    FredkinCell f;
    f.state_transition(b);
    ASSERT_TRUE(f._transition_state == true);
}

TEST(FredkinCell, state_transition2) {
    bool b[8] = {0, 1, 0, 0, 0, 0, 0, 0};
    FredkinCell f;
    f.state_transition(b);
    ASSERT_TRUE(f._transition_state == false);
}

TEST(FredkinCell, state_transition3) {
    bool b[8] = {0, 0, 1, 0, 1, 0, 0, 0};
    FredkinCell f;
    f.state_transition(b);
    ASSERT_TRUE(f._transition_state == false);
}

TEST(FredkinCell, state_transition4) {
    bool b[8] = {1, 0, 1, 0, 0, 0, 0, 0};
    FredkinCell f;
    f.state_transition(b);
    ASSERT_TRUE(f._transition_state == false);
}

TEST(FredkinCell, state_transition5) {
    bool b[8] = {1, 0, 1, 0, 1, 0, 0, 0};
    FredkinCell f;
    f.state_transition(b);
    ASSERT_TRUE(f._transition_state == true);
}

TEST(FredkinCell, state_transition6) {
    bool b[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    FredkinCell f(true);
    f.state_transition(b);
    ASSERT_TRUE(f._transition_state == true);
}

TEST(FredkinCell, state_transition7) {
    bool b[8] = {1, 1, 0, 0, 0, 0, 0, 0};
    FredkinCell f(true);
    f.state_transition(b);
    ASSERT_TRUE(f._transition_state == false);
}

TEST(FredkinCell, next_generation) {
    FredkinCell f(true);
    f._transition_state = false;
    ASSERT_TRUE(f.is_living());
    ASSERT_TRUE(!f.next_generation());
    ASSERT_TRUE(f.is_living());
    ASSERT_TRUE(f._transition_state == false);
}

TEST(FredkinCell, next_generation2) {
    FredkinCell f(true);
    f._transition_state = true;
    ASSERT_TRUE(f.is_living());
    ASSERT_TRUE(!f.next_generation());
    ASSERT_TRUE(!f.is_living());
    ASSERT_TRUE(f._transition_state == false);
}

TEST(FredkinCell, next_generation3) {
    FredkinCell f;
    f._transition_state = false;
    ASSERT_TRUE(!f.is_living());
    ASSERT_TRUE(!f.next_generation());
    ASSERT_TRUE(!f.is_living());
    ASSERT_TRUE(f._transition_state == false);
}

TEST(FredkinCell, next_generation4) {
    FredkinCell f;
    f._transition_state = true;
    ASSERT_TRUE(!f.is_living());
    ASSERT_TRUE(!f.next_generation());
    ASSERT_TRUE(f.is_living());
    ASSERT_TRUE(f._transition_state == false);
}

TEST(FredkinCell, next_generation_age) {
    FredkinCell f(true);
    f._transition_state = false;
    ASSERT_TRUE(f.is_living());
    ASSERT_TRUE(f._age == 0);
    ASSERT_TRUE(!f.next_generation());
    ASSERT_TRUE(f._age == 1);
    ASSERT_TRUE(f.is_living());
    ASSERT_TRUE(f._transition_state == false);
}

TEST(FredkinCell, next_generation_age2) {
    FredkinCell f(true, 1);
    f._transition_state = true;
    ASSERT_TRUE(f.is_living());
    ASSERT_TRUE(f._age == 1);
    ASSERT_TRUE(!f.next_generation());
    ASSERT_TRUE(f._age == 1);
    ASSERT_TRUE(!f.is_living());
    ASSERT_TRUE(f._transition_state == false);
}

TEST(FredkinCell, next_generation_age3) {
    FredkinCell f(true, 1);
    f._transition_state = false;
    ASSERT_TRUE(f.is_living());
    ASSERT_TRUE(f._age == 1);
    ASSERT_TRUE(f.next_generation());
    ASSERT_TRUE(f._age == 2);
    ASSERT_TRUE(f.is_living());
    ASSERT_TRUE(f._transition_state == false);
}

TEST(FredkinCell, can_read) {
    FredkinCell f;
    ASSERT_TRUE(f.can_read('-'));
}

TEST(FredkinCell, can_read2) {
    FredkinCell f;
    ASSERT_TRUE(f.can_read('2'));
}

TEST(FredkinCell, can_read3) {
    FredkinCell f;
    ASSERT_TRUE(f.can_read('+'));
}

TEST(FredkinCell, can_read4) {
    FredkinCell f;
    ASSERT_TRUE(!f.can_read('*'));
}

// ----------
// ConwayCell
// ----------

TEST(ConwayCell, default_construct) {
    ConwayCell f;
    ASSERT_TRUE(!f.is_living());
}

TEST(ConwayCell, default_construct_vector) {
    std::vector<ConwayCell> v(10);
    for(int i=0; i<10; i++) {
        ASSERT_TRUE(!v[i].is_living());}
}

TEST(ConwayCell, bool_construct) {
    ConwayCell f(false);
    ASSERT_TRUE(!f.is_living());
}

TEST(ConwayCell, bool_construct2) {
    ConwayCell f(true);
    ASSERT_TRUE(f.is_living());
}

TEST(ConwayCell, read) {
    std::istringstream in(".");
    ConwayCell f(true);
    f.read(in);
    ASSERT_TRUE(!f.is_living());
    
}

TEST(ConwayCell, read2) {
    std::istringstream in("*");
    ConwayCell f;
    f.read(in);
    ASSERT_TRUE(f.is_living());
}


TEST(ConwayCell, read3_unknownChar) {
    std::istringstream in("-");
    ConwayCell f;
    f.read(in);
    ASSERT_TRUE(!f.is_living());
}

TEST(ConwayCell, read4_using_op) {
    std::istringstream in("*");
    ConwayCell f;
    in >> f;
    ASSERT_TRUE(f.is_living());
}

TEST(ConwayCell, read_from_char) {
    ConwayCell f(true);
    f.read_from_char('.');
    ASSERT_TRUE(!f.is_living());
}

TEST(ConwayCell, read_from_char2) {
    ConwayCell f;
    f.read_from_char('*');
    ASSERT_TRUE(f.is_living());
}

TEST(ConwayCell, read_from_char4_unknown) {
    ConwayCell f;
    f.read_from_char('5');
    ASSERT_TRUE(!f.is_living());
}

TEST(ConwayCell, write) {
    std::ostringstream out;
    ConwayCell f;
    f.write(out);
    ASSERT_TRUE(out.str() == ".");
}

TEST(ConwayCell, write2) {
    std::ostringstream out;
    ConwayCell f(true);
    f.write(out);
    ASSERT_TRUE(out.str() == "*");
}

TEST(ConwayCell, write3_using_op) {
    std::ostringstream out;
    ConwayCell f;
    out<<f;
    ASSERT_TRUE(out.str() == ".");
}

TEST(ConwayCell, write4_using_op) {
    std::ostringstream out;
    ConwayCell f(true);
    out<<f;
    ASSERT_TRUE(out.str() == "*");
}

TEST(ConwayCell, equals) {
    std::ostringstream out;
    ConwayCell f(true);
    ConwayCell x(true);
    ASSERT_TRUE(f.equals(x));
}

TEST(ConwayCell, equals2) {
    std::ostringstream out;
    ConwayCell f(true);
    ConwayCell x(false);
    ASSERT_TRUE(!f.equals(x));
}

TEST(ConwayCell, equals_op) {
    std::ostringstream out;
    ConwayCell f(true);
    ConwayCell x(true);
    ASSERT_TRUE(f == x);
}

TEST(ConwayCell, equals_op2) {
    std::ostringstream out;
    ConwayCell f(true);
    ConwayCell x(false);
    ASSERT_TRUE(f != x);
}

TEST(ConwayCell, clone) {
    std::ostringstream out;
    ConwayCell f(true);
    ConwayCell* x = f.clone();
    ASSERT_TRUE(f == *x);
    delete x;
}

TEST(ConwayCell, state_transition) {
    bool b[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    ConwayCell f;
    f.state_transition(b);
    ASSERT_TRUE(f._transition_state == false);
}

TEST(ConwayCell, state_transition1) {
    bool b[8] = {0, 0, 1, 0, 0, 0, 0, 0};
    ConwayCell f;
    f.state_transition(b);
    ASSERT_TRUE(f._transition_state == false);
}

TEST(ConwayCell, state_transition2) {
    bool b[8] = {0, 1, 1, 0, 0, 1, 0, 0};
    ConwayCell f;
    f.state_transition(b);
    ASSERT_TRUE(f._transition_state == true);
}

TEST(ConwayCell, state_transition3) {
    bool b[8] = {0, 0, 1, 0, 1, 1, 1, 1};
    ConwayCell f;
    f.state_transition(b);
    ASSERT_TRUE(f._transition_state == false);
}

TEST(ConwayCell, state_transition4) {
    bool b[8] = {1, 0, 1, 0, 0, 0, 0, 0};
    ConwayCell f;
    f.state_transition(b);
    ASSERT_TRUE(f._transition_state == false);
}

TEST(ConwayCell, state_transition5) {
    bool b[8] = {1, 1, 0, 0, 0, 0, 0, 1};
    ConwayCell f;
    f.state_transition(b);
    ASSERT_TRUE(f._transition_state == true);
}

TEST(ConwayCell, state_transition6) {
    bool b[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    ConwayCell f(true);
    f.state_transition(b);
    ASSERT_TRUE(f._transition_state == true);
}

TEST(ConwayCell, state_transition7) {
    bool b[8] = {1, 1, 0, 0, 0, 0, 0, 0};
    ConwayCell f(true);
    f.state_transition(b);
    ASSERT_TRUE(f._transition_state == false);
}

TEST(ConwayCell, state_transition8) {
    bool b[8] = {1, 1, 1, 0, 0, 0, 0, 0};
    ConwayCell f(true);
    f.state_transition(b);
    ASSERT_TRUE(f._transition_state == false);
}

TEST(ConwayCell, state_transition9) {
    bool b[8] = {1, 1, 1, 1, 0, 0, 0, 0};
    ConwayCell f(true);
    f.state_transition(b);
    ASSERT_TRUE(f._transition_state == true);
}

TEST(ConwayCell, next_generation) {
    ConwayCell f(true);
    f._transition_state = false;
    ASSERT_TRUE(f.is_living());
    ASSERT_TRUE(!f.next_generation());
    ASSERT_TRUE(f.is_living());
    ASSERT_TRUE(f._transition_state == false);
}

TEST(ConwayCell, next_generation2) {
    ConwayCell f(true);
    f._transition_state = true;
    ASSERT_TRUE(f.is_living());
    ASSERT_TRUE(!f.next_generation());
    ASSERT_TRUE(!f.is_living());
    ASSERT_TRUE(f._transition_state == false);
}

TEST(ConwayCell, next_generation3) {
    ConwayCell f;
    f._transition_state = false;
    ASSERT_TRUE(!f.is_living());
    ASSERT_TRUE(!f.next_generation());
    ASSERT_TRUE(!f.is_living());
    ASSERT_TRUE(f._transition_state == false);
}

TEST(ConwayCell, next_generation4) {
    ConwayCell f;
    f._transition_state = true;
    ASSERT_TRUE(!f.is_living());
    ASSERT_TRUE(!f.next_generation());
    ASSERT_TRUE(f.is_living());
    ASSERT_TRUE(f._transition_state == false);
}

TEST(ConwayCell, can_read) {
    ConwayCell f;
    ASSERT_TRUE(f.can_read('.'));
}

TEST(ConwayCell, can_read2) {
    ConwayCell f;
    ASSERT_TRUE(f.can_read('*'));
}

TEST(ConwayCell, can_read3) {
    ConwayCell f;
    ASSERT_TRUE(!f.can_read('-'));
}

TEST(ConwayCell, can_read4) {
    ConwayCell f;
    ASSERT_TRUE(!f.can_read('5'));
}

// ----
// Cell
// ----

TEST(Cell, default_construct) {
    Cell c;
    ASSERT_TRUE(!c.is_living());
}

TEST(Cell, default_construct_vector) {
    std::vector<Cell> v(10);
    for(int i=0; i<10; i++) {
        ASSERT_TRUE(!v[i].is_living());}
}

TEST(Cell, conway_construct) {
    Cell c(new ConwayCell());
    ASSERT_TRUE(!c.is_living());
}

TEST(Cell, fredkin_construct) {
    Cell c(new FredkinCell(true));
    ASSERT_TRUE(c.is_living());
}

TEST(Cell, read) {
    std::istringstream in("-");
    Cell c;
    c.read(in);
    ASSERT_TRUE(!c.is_living());
}

TEST(Cell, read2) {
    std::istringstream in("1");
    Cell c;
    c.read(in);
    ASSERT_TRUE(c.is_living());
}

TEST(Cell, read3) {
    std::istringstream in(".");
    Cell c;
    c.read(in);
    ASSERT_TRUE(!c.is_living());
}

TEST(Cell, read4) {
    std::istringstream in("*");
    Cell c;
    c.read(in);
    ASSERT_TRUE(c.is_living());
}


TEST(Cell, write) {
    std::ostringstream out;
    Cell c;
    c.write(out);
    ASSERT_TRUE(out.str() == "-");
}

TEST(Cell, write2) {
    std::ostringstream out;
    Cell c(new FredkinCell(true));
    c.write(out);
    ASSERT_TRUE(out.str() == "0");
}

TEST(Cell, write3) {
    std::ostringstream out;
    Cell c(new ConwayCell(true));
    c.write(out);
    ASSERT_TRUE(out.str() == "*");
}

TEST(Cell, write4) {
    std::istringstream in(".");
    Cell c;
    c.read(in);
    std::ostringstream out;
    c.write(out);
    ASSERT_TRUE(out.str() == ".");
}



TEST(Cell, next_generation) {
    Cell c;
    bool b[8] = {0, 0, 1, 0, 0, 0, 0, 0};
    c.state_transition(b); //should go from dead to alive
    ASSERT_TRUE(!c.is_living());
    ASSERT_TRUE(!c.next_generation());
    ASSERT_TRUE(c.is_living());
}

TEST(Cell, next_generation2) {
    Cell c(new ConwayCell(true));
    bool b[8] = {0, 0, 1, 0, 0, 0, 0, 0};
    c.state_transition(b);
    ASSERT_TRUE(c.is_living());
    ASSERT_TRUE(!c.next_generation());
    ASSERT_TRUE(!c.is_living());
}

TEST(Cell, next_generation3_mutate) {
    Cell c(new FredkinCell(true, 1));
    bool b[8] = {0, 0, 1, 0, 0, 0, 0, 0};
    c.state_transition(b);
    ASSERT_TRUE(c.is_living());
    ASSERT_TRUE(c.next_generation());
    ASSERT_TRUE(c.is_living());
    std::ostringstream out;
    c.write(out);
    ASSERT_TRUE(out.str() == "*");
}

TEST(Cell, mutate) {
    std::ostringstream out;
    std::ostringstream out2;
    Cell c(new FredkinCell(true, 1));
    c.write(out);
    ASSERT_TRUE(out.str() == "1");
    c.mutate();
    c.write(out2);
    ASSERT_TRUE(out2.str() == "*");
}

TEST(Life, construct_conway_via_input_stream) {
    std::istringstream input("2\n2\n*.\n.*\n");
    std::ostringstream out;
    Life<ConwayCell> l(input);
    l.print(out);
    ASSERT_TRUE(out.str() == "\nGeneration = 0, Population = 2.\n*.\n.*\n");
}

TEST(Life, conway_take_turn) {
    std::istringstream input("2\n2\n*.\n..\n");
    std::ostringstream out;
    Life<ConwayCell> l(input);
    l.take_turn();
    l.print(out);
    ASSERT_TRUE(out.str() == "\nGeneration = 1, Population = 0.\n..\n..\n");
}

TEST(Life, construct_fredkin_via_input_stream) {
    std::istringstream input("2\n2\n0-\n-0\n");
    std::ostringstream out;
    Life<FredkinCell> l(input);
    l.print(out);
    ASSERT_TRUE(out.str() == "\nGeneration = 0, Population = 2.\n0-\n-0\n");
}

TEST(Life, fredkin_take_turn) {
    std::istringstream input("2\n2\n00\n00\n");
    std::ostringstream out;
    Life<FredkinCell> l(input);
    l.take_turn();
    l.print(out);
    ASSERT_TRUE(out.str() == "\nGeneration = 1, Population = 0.\n--\n--\n");
}

TEST(Life, construct_cell_via_input_stream) {
    std::istringstream input("2\n2\n.-\n.-\n");
    std::ostringstream out;
    Life<Cell> l(input);
    l.print(out);
    ASSERT_TRUE(out.str() == "\nGeneration = 0, Population = 0.\n.-\n.-\n");
}

TEST(Life, cell_take_turn) {
    std::istringstream input("2\n2\n.0\n.-\n");
    std::ostringstream out;
    Life<Cell> l(input);
    l.take_turn();
    l.print(out);
    ASSERT_TRUE(out.str() == "\nGeneration = 1, Population = 1.\n.-\n.0\n");
}
