#define private public
#define protected public

#include <sstream>
#include <fstream>
#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"
#include "Life.h"

using namespace std;

TEST(alive, conway1) {
    ConwayCell c;
    ASSERT_TRUE(!c.isAlive());
}

TEST(alive, conway2) {
    ConwayCell c;
    c._a = true;
    ASSERT_TRUE(c.isAlive());
}

TEST(alive, fredkin1) {
    FredkinCell c;
    c._a = true;
    ASSERT_TRUE(c.isAlive());
}

TEST(alive, fredkin2) {
    FredkinCell c;
    ASSERT_TRUE(!c.isAlive());
}

TEST(alive, cell1) {
    Cell *cell = new Cell();
    ASSERT_TRUE(!cell->isAlive());
}

TEST(alive, cell2) {
    FredkinCell c;
    c._a = true;
    Cell *cell = new Cell(&c);
    ASSERT_TRUE(cell->isAlive());
}

TEST(read, conway1) {
    ConwayCell c;
    string s = ".";
    istringstream iss(s);
    c.read(iss);
    ASSERT_TRUE(!c.isAlive());
}

TEST(read, conway2) {
    ConwayCell c;
    string s = "*";
    istringstream iss(s);
    c.read(iss);
    ASSERT_TRUE(c.isAlive());
}

TEST(read, conway3) {
    ConwayCell c;
    string s = "*.";
    istringstream iss(s);
    c.read(iss);
    ASSERT_TRUE(c.isAlive());
}

TEST(read, fredkin1) {
    FredkinCell c;
    string s = "5";
    istringstream iss(s);
    c.read(iss);
    ASSERT_TRUE(c.isAlive() && c._age == 5);
}

TEST(read, fredkin2) {
    FredkinCell c;
    string s = "1";
    istringstream iss(s);
    c.read(iss);
    ASSERT_TRUE(c.isAlive() && c._age == 1);
}

TEST(read, fredkin3) {
    FredkinCell c;
    string s = "-";
    istringstream iss(s);
    c.read(iss);
    ASSERT_TRUE(!c.isAlive() && c._age == 0);
}

TEST(read, cell1) {
    ConwayCell c;
    Cell *cell = new Cell(&c);
    string s = ".";
    istringstream iss(s);
    cell->read(iss);
    ASSERT_TRUE(!cell->isAlive());
}

TEST(read, cell2) {
    FredkinCell c;
    Cell *cell = new Cell(&c);
    string s = "1";
    istringstream iss(s);
    cell->read(iss);
    ASSERT_TRUE(cell->isAlive());
}

TEST(read, cell3) {
    FredkinCell c;
    Cell *cell = new Cell(&c);
    string s = "-";
    istringstream iss(s);
    cell->read(iss);
    ASSERT_TRUE(!cell->isAlive());
}

TEST(write, conway1) {
    ConwayCell c;
    ostringstream oss;
    c.write(oss);
    ASSERT_EQ(oss.str(), ".");
}

TEST(write, conway2) {
    ConwayCell c;
    c._a = true;
    ostringstream oss;
    c.write(oss);
    ASSERT_EQ(oss.str(), "*");
}

TEST(write, fredkin1) {
    FredkinCell c;
    ostringstream oss;
    c.write(oss);
    ASSERT_EQ(oss.str(), "-");
}

TEST(write, fredkin2) {
    FredkinCell c;
    c._a = true;
    ostringstream oss;
    c.write(oss);
    ASSERT_EQ(oss.str(), "0");
}

TEST(write, fredkin3) {
    FredkinCell c;
    c._a = true;
    c._age = 2;
    ostringstream oss;
    c.write(oss);
    ASSERT_EQ(oss.str(), "2");
}

TEST(write, fredkin4) {
    FredkinCell c;
    c._a = true;
    c._age = 10;
    ostringstream oss;
    c.write(oss);
    ASSERT_EQ(oss.str(), "+");
}

TEST(write, fredkin5) {
    FredkinCell c;
    c._a = false;
    c._age = 10;
    ostringstream oss;
    c.write(oss);
    ASSERT_EQ(oss.str(), "-");
}

TEST(write, cell1) {
    ConwayCell c;
    Cell *cell = new Cell(&c);
    ostringstream oss;
    cell->write(oss);
    ASSERT_EQ(oss.str(), ".");
}

TEST(write, cell2) {
    FredkinCell c;
    Cell *cell = new Cell(&c);
    ostringstream oss;
    cell->write(oss);
    ASSERT_EQ(oss.str(), "-");
}

TEST(write, cell3) {
    FredkinCell c;
    c._a = true;
    c._age = 10;
    Cell *cell = new Cell(&c);
    ostringstream oss;
    cell->write(oss);
    ASSERT_EQ(oss.str(), "+");
}

TEST(write, cell4) {
    FredkinCell c;
    c._a = true;
    c._age = 5;
    Cell *cell = new Cell(&c);
    ostringstream oss;
    cell->write(oss);
    ASSERT_EQ(oss.str(), "5");
}

TEST(advance, conway1) {
    ConwayCell c;
    c.advance(3, 0);
    ASSERT_TRUE(c.isAlive());
}

TEST(advance, conway2) {
    ConwayCell c;
    c._a = true;
    c.advance(1, 0);
    ASSERT_TRUE(!c.isAlive());
}

TEST(advance, conway3) {
    ConwayCell c;
    c._a = true;
    c.advance(5, 0);
    ASSERT_TRUE(!c.isAlive());
}

TEST(advance, fredkin1) {
    FredkinCell c;
    c._a = true;
    c.advance(0, 0);
    ASSERT_TRUE(!c.isAlive());
}

TEST(advance, fredkin2) {
    FredkinCell c;
    c.advance(0, 1);
    ASSERT_TRUE(c.isAlive());
}

TEST(advance, fredkin3) {
    FredkinCell c;
    c.advance(0, 3);
    ASSERT_TRUE(c.isAlive());
}

TEST(advance, fredkin4) {
    FredkinCell c;
    c._a = true;
    c.advance(0, 5);
    ASSERT_TRUE(c.isAlive() && c._age == 1);
}

TEST(advance, cell1) {
    ConwayCell c;
    Cell *cell = new Cell(&c);
    cell->advance(3, 0);
    ASSERT_TRUE(cell->isAlive());
}

TEST(advance, cell2) {
    FredkinCell c;
    c._a = true;
    Cell *cell = new Cell(&c);
    cell->advance(0, 2);
    ASSERT_TRUE(!cell->isAlive());
}

TEST(advance, cell3) {
    FredkinCell c;
    c._a = true;
    c._age = 2;
    Cell *cell = new Cell(&c);
    c.advance(0, 5);
    ASSERT_TRUE(cell->isAlive() && c._age == 3);
}

TEST(mutate, 1) {
    Cell *cell = new Cell();
    ostringstream oss;
    cell->mutate();
    cell->write(oss);
    ASSERT_EQ(oss.str(), "*");
}

TEST(mutate, 2) {
    FredkinCell c;
    c._age = 3;
    Cell *cell = new Cell();
    ostringstream oss;
    cell->mutate();
    cell->write(oss);
    ASSERT_EQ(oss.str(), "*");
}




int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
