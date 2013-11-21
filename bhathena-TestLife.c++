// ------------
// TestLife.c++
// ------------

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==

#include "gtest/gtest.h"

#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"
#include "Life.h"

// ---------
// TestLife
// ---------

// ----------
// ConwayCell
// ----------

// -------------------------------------
// ConwayCell constructor and isAlive()
// -------------------------------------
TEST(ConwayCell, constructor_isAlive) {
    ConwayCell c(true);
    ASSERT_TRUE(c.isAlive());
}

TEST(ConwayCell, constructor_isNotAlive) {
    ConwayCell c(false);
    ASSERT_TRUE(!c.isAlive());
}

// ------------------------
// ConwayCell update()
// ------------------------
TEST(ConwayCell, update_live_to_dead_1) {
    ConwayCell c(true);
    ConwayCell c2(true);
    ConwayCell c3(true);
    ConwayCell c4(true);
    ConwayCell c5(true);
    vector<AbstractCell*> neighbors;
    neighbors.push_back(&c2);
    neighbors.push_back(&c3);
    neighbors.push_back(&c4);
    neighbors.push_back(&c5);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(!c.isAlive());
}

TEST(ConwayCell, update_live_to_dead_2) {
    ConwayCell c(true);
    ConwayCell c2(true);
    vector<AbstractCell*> neighbors;
    neighbors.push_back(&c2);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(!c.isAlive());
}

TEST(ConwayCell, update_live_to_dead_3) {
    ConwayCell c(true);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(!c.isAlive());
}

TEST(ConwayCell, update_live_to_dead_4) {
    ConwayCell c(true);
    ConwayCell c2(true);
    ConwayCell c3(true);
    ConwayCell c4(true);
    ConwayCell c5(true);
    ConwayCell c6(true);
    vector<AbstractCell*> neighbors;
    neighbors.push_back(&c2);
    neighbors.push_back(&c3);
    neighbors.push_back(&c4);
    neighbors.push_back(&c5);
    neighbors.push_back(&c6);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(!c.isAlive());
}

TEST(ConwayCell, update_live_to_dead_5) {
    ConwayCell c(true);
    ConwayCell c2(true);
    ConwayCell c3(true);
    ConwayCell c4(true);
    ConwayCell c5(true);
    ConwayCell c6(true);
    ConwayCell c7(true);
    vector<AbstractCell*> neighbors;
    neighbors.push_back(&c2);
    neighbors.push_back(&c3);
    neighbors.push_back(&c4);
    neighbors.push_back(&c5);
    neighbors.push_back(&c6);
    neighbors.push_back(&c7);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(!c.isAlive());
}

TEST(ConwayCell, update_live_to_dead_6) {
    ConwayCell c(true);
    ConwayCell c2(true);
    ConwayCell c3(true);
    ConwayCell c4(true);
    ConwayCell c5(true);
    ConwayCell c6(true);
    ConwayCell c7(true);
    ConwayCell c8(true);
    vector<AbstractCell*> neighbors;
    neighbors.push_back(&c2);
    neighbors.push_back(&c3);
    neighbors.push_back(&c4);
    neighbors.push_back(&c5);
    neighbors.push_back(&c6);
    neighbors.push_back(&c7);
    neighbors.push_back(&c8);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(!c.isAlive());
}

TEST(ConwayCell, update_live_to_dead_7) {
    ConwayCell c(true);
    ConwayCell c2(true);
    ConwayCell c3(true);
    ConwayCell c4(true);
    ConwayCell c5(true);
    ConwayCell c6(true);
    ConwayCell c7(true);
    ConwayCell c8(true);
    ConwayCell c9(true);
    vector<AbstractCell*> neighbors;
    neighbors.push_back(&c2);
    neighbors.push_back(&c3);
    neighbors.push_back(&c4);
    neighbors.push_back(&c5);
    neighbors.push_back(&c6);
    neighbors.push_back(&c7);
    neighbors.push_back(&c8);
    neighbors.push_back(&c9);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(!c.isAlive());
}


TEST(ConwayCell, update_live_to_live_1) {
    ConwayCell c(true);
    ConwayCell c2(true);
    ConwayCell c3(true);
    vector<AbstractCell*> neighbors;
    neighbors.push_back(&c2);
    neighbors.push_back(&c3);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(c.isAlive());
}

TEST(ConwayCell, update_live_to_live_2) {
    ConwayCell c(true);
    ConwayCell c2(true);
    ConwayCell c3(true);
    ConwayCell c4(true);
    vector<AbstractCell*> neighbors;
    neighbors.push_back(&c2);
    neighbors.push_back(&c3);
    neighbors.push_back(&c4);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(c.isAlive());
}

TEST(ConwayCell, update_dead_to_alive) {
    ConwayCell c(false);
    ConwayCell c2(true);
    ConwayCell c3(true);
    ConwayCell c4(true);
    vector<AbstractCell*> neighbors;
    neighbors.push_back(&c2);
    neighbors.push_back(&c3);
    neighbors.push_back(&c4);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(c.isAlive());
}

TEST(ConwayCell, dead_to_dead_1) {
    ConwayCell c(false);
    ConwayCell c2(true);
    vector<AbstractCell*> neighbors;
    neighbors.push_back(&c2);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(!c.isAlive());
}

TEST(ConwayCell, dead_to_dead_2) {
    ConwayCell c(false);
    ConwayCell c2(true);
    ConwayCell c3(true);
    vector<AbstractCell*> neighbors;
    neighbors.push_back(&c2);
    neighbors.push_back(&c3);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(!c.isAlive());
}

TEST(ConwayCell, dead_to_dead_3) {
    ConwayCell c(false);
    ConwayCell c2(true);
    ConwayCell c3(true);
    ConwayCell c4(true);
    ConwayCell c5(true);
    vector<AbstractCell*> neighbors;
    neighbors.push_back(&c2);
    neighbors.push_back(&c3);
    neighbors.push_back(&c4);
    neighbors.push_back(&c5);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(!c.isAlive());
}

TEST(ConwayCell, dead_to_dead_4) {
    ConwayCell c(false);
    ConwayCell c2(true);
    ConwayCell c3(true);
    ConwayCell c4(true);
    ConwayCell c5(true);
    ConwayCell c6(true);
    vector<AbstractCell*> neighbors;
    neighbors.push_back(&c2);
    neighbors.push_back(&c3);
    neighbors.push_back(&c4);
    neighbors.push_back(&c5);
    neighbors.push_back(&c6);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(!c.isAlive());
}

TEST(ConwayCell, dead_to_dead_5) {
    ConwayCell c(false);
    ConwayCell c2(true);
    ConwayCell c3(true);
    ConwayCell c4(true);
    ConwayCell c5(true);
    ConwayCell c6(true);
    ConwayCell c7(true);
    vector<AbstractCell*> neighbors;
    neighbors.push_back(&c2);
    neighbors.push_back(&c3);
    neighbors.push_back(&c4);
    neighbors.push_back(&c5);
    neighbors.push_back(&c6);
    neighbors.push_back(&c7);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(!c.isAlive());
}

TEST(ConwayCell, dead_to_dead_6) {
    ConwayCell c(false);
    ConwayCell c2(true);
    ConwayCell c3(true);
    ConwayCell c4(true);
    ConwayCell c5(true);
    ConwayCell c6(true);
    ConwayCell c7(true);
    ConwayCell c8(true);
    vector<AbstractCell*> neighbors;
    neighbors.push_back(&c2);
    neighbors.push_back(&c3);
    neighbors.push_back(&c4);
    neighbors.push_back(&c5);
    neighbors.push_back(&c6);
    neighbors.push_back(&c7);
    neighbors.push_back(&c8);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(!c.isAlive());
}

TEST(ConwayCell, dead_to_dead_7) {
    ConwayCell c(false);
    ConwayCell c2(true);
    ConwayCell c3(true);
    ConwayCell c4(true);
    ConwayCell c5(true);
    ConwayCell c6(true);
    ConwayCell c7(true);
    ConwayCell c8(true);
    ConwayCell c9(true);
    vector<AbstractCell*> neighbors;
    neighbors.push_back(&c2);
    neighbors.push_back(&c3);
    neighbors.push_back(&c4);
    neighbors.push_back(&c5);
    neighbors.push_back(&c6);
    neighbors.push_back(&c7);
    neighbors.push_back(&c8);
    neighbors.push_back(&c9);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(!c.isAlive());
}

TEST(ConwayCell, dead_to_dead_8) {
    ConwayCell c(false);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(!c.isAlive());
}

TEST(ConwayCell, update_dead_live_dead_1) {
    ConwayCell c(false);
    ConwayCell c2(true);
    ConwayCell c3(true);
    ConwayCell c4(true);
    vector<AbstractCell*> neighbors;
    neighbors.push_back(&c2);
    neighbors.push_back(&c3);
    neighbors.push_back(&c4);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(c.isAlive());
    vector<AbstractCell*> neighbors2;
    c.setNeighbors(neighbors2);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(!c.isAlive());
}

TEST(ConwayCell, update_dead_live_dead_2) {
    ConwayCell c(false);
    ConwayCell c2(true);
    ConwayCell c3(true);
    ConwayCell c4(true);
    vector<AbstractCell*> neighbors;
    neighbors.push_back(&c2);
    neighbors.push_back(&c3);
    neighbors.push_back(&c4);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(c.isAlive());
    vector<AbstractCell*> neighbors2;
    ConwayCell c5(true);
    neighbors2.push_back(&c5);
    c.setNeighbors(neighbors2);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(!c.isAlive());
}

TEST(ConwayCell, update_dead_live_dead_3) {
    ConwayCell c(false);
    ConwayCell c2(true);
    ConwayCell c3(true);
    ConwayCell c4(true);
    vector<AbstractCell*> neighbors;
    neighbors.push_back(&c2);
    neighbors.push_back(&c3);
    neighbors.push_back(&c4);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(c.isAlive());
    ConwayCell c5(true);
    neighbors.push_back(&c5);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(!c.isAlive());
}

TEST(ConwayCell, update_dead_live_dead_4) {
    ConwayCell c(false);
    ConwayCell c2(true);
    ConwayCell c3(true);
    ConwayCell c4(true);
    vector<AbstractCell*> neighbors;
    neighbors.push_back(&c2);
    neighbors.push_back(&c3);
    neighbors.push_back(&c4);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(c.isAlive());
    ConwayCell c5(true);
    ConwayCell c6(true);
    neighbors.push_back(&c5);
    neighbors.push_back(&c6);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(!c.isAlive());
}

TEST(ConwayCell, update_dead_live_dead_5) {
    ConwayCell c(false);
    ConwayCell c2(true);
    ConwayCell c3(true);
    ConwayCell c4(true);
    vector<AbstractCell*> neighbors;
    neighbors.push_back(&c2);
    neighbors.push_back(&c3);
    neighbors.push_back(&c4);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(c.isAlive());
    ConwayCell c5(true);
    ConwayCell c6(true);
    ConwayCell c7(true);
    neighbors.push_back(&c5);
    neighbors.push_back(&c6);
    neighbors.push_back(&c7);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(!c.isAlive());
}

TEST(ConwayCell, update_dead_live_dead_6) {
    ConwayCell c(false);
    ConwayCell c2(true);
    ConwayCell c3(true);
    ConwayCell c4(true);
    vector<AbstractCell*> neighbors;
    neighbors.push_back(&c2);
    neighbors.push_back(&c3);
    neighbors.push_back(&c4);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(c.isAlive());
    ConwayCell c5(true);
    ConwayCell c6(true);
    ConwayCell c7(true);
    ConwayCell c8(true);
    neighbors.push_back(&c5);
    neighbors.push_back(&c6);
    neighbors.push_back(&c7);
    neighbors.push_back(&c8);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(!c.isAlive());
}

TEST(ConwayCell, update_dead_live_dead_7) {
    ConwayCell c(false);
    ConwayCell c2(true);
    ConwayCell c3(true);
    ConwayCell c4(true);
    vector<AbstractCell*> neighbors;
    neighbors.push_back(&c2);
    neighbors.push_back(&c3);
    neighbors.push_back(&c4);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(c.isAlive());
    ConwayCell c5(true);
    ConwayCell c6(true);
    ConwayCell c7(true);
    ConwayCell c8(true);
    ConwayCell c9(true);
    neighbors.push_back(&c5);
    neighbors.push_back(&c6);
    neighbors.push_back(&c7);
    neighbors.push_back(&c8);
    neighbors.push_back(&c9);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(!c.isAlive());
}

TEST(ConwayCell, update_live_dead_live_1) {
    ConwayCell c(true);
    vector<AbstractCell*> neighbors;
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(!c.isAlive());
    ConwayCell c2(true);
    ConwayCell c3(true);
    ConwayCell c4(true);
    neighbors.push_back(&c4);
    neighbors.push_back(&c3);
    neighbors.push_back(&c2);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(c.isAlive());
}

TEST(ConwayCell, update_live_dead_live_2) {
    ConwayCell c(true);
    ConwayCell c2(true);
    vector<AbstractCell*> neighbors;
    neighbors.push_back(&c2);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(!c.isAlive());
    ConwayCell c3(true);
    ConwayCell c4(true);
    neighbors.push_back(&c4);
    neighbors.push_back(&c3);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(c.isAlive());
}

TEST(ConwayCell, update_live_dead_live_3) {
    ConwayCell c(true);
    ConwayCell c2(true);
    ConwayCell c3(true);
    ConwayCell c4(true);
    ConwayCell c5(true);
    vector<AbstractCell*> neighbors;
    neighbors.push_back(&c2);
    neighbors.push_back(&c3);
    neighbors.push_back(&c4);
    neighbors.push_back(&c5);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(!c.isAlive());
    vector<AbstractCell*> neighbors2;
    ConwayCell c6(true);
    ConwayCell c7(true);
    ConwayCell c8(true);
    neighbors2.push_back(&c6);
    neighbors2.push_back(&c7);
    neighbors2.push_back(&c8);
    c.setNeighbors(neighbors2);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(c.isAlive());
}

TEST(ConwayCell, update_live_dead_live_4) {
    ConwayCell c(true);
    ConwayCell c2(true);
    ConwayCell c3(true);
    ConwayCell c4(true);
    ConwayCell c5(true);
    ConwayCell c6(true);
    vector<AbstractCell*> neighbors;
    neighbors.push_back(&c2);
    neighbors.push_back(&c3);
    neighbors.push_back(&c4);
    neighbors.push_back(&c5);
    neighbors.push_back(&c6);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(!c.isAlive());
    vector<AbstractCell*> neighbors2;
    ConwayCell c7(true);
    ConwayCell c8(true);
    ConwayCell c9(true);
    neighbors2.push_back(&c7);
    neighbors2.push_back(&c8);
    neighbors2.push_back(&c9);
    c.setNeighbors(neighbors2);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(c.isAlive());
}

TEST(ConwayCell, update_live_dead_live_5) {
    ConwayCell c(true);
    ConwayCell c2(true);
    ConwayCell c3(true);
    ConwayCell c4(true);
    ConwayCell c5(true);
    ConwayCell c6(true);
    ConwayCell c7(true);
    vector<AbstractCell*> neighbors;
    neighbors.push_back(&c2);
    neighbors.push_back(&c3);
    neighbors.push_back(&c4);
    neighbors.push_back(&c5);
    neighbors.push_back(&c6);
    neighbors.push_back(&c7);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(!c.isAlive());
    vector<AbstractCell*> neighbors2;
    ConwayCell c8(true);
    ConwayCell c9(true);
    ConwayCell c10(true);
    neighbors2.push_back(&c8);
    neighbors2.push_back(&c9);
    neighbors2.push_back(&c10);
    c.setNeighbors(neighbors2);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(c.isAlive());
}

TEST(ConwayCell, update_live_dead_live_6) {
    ConwayCell c(true);
    ConwayCell c2(true);
    ConwayCell c3(true);
    ConwayCell c4(true);
    ConwayCell c5(true);
    ConwayCell c6(true);
    ConwayCell c7(true);
    ConwayCell c8(true);
    vector<AbstractCell*> neighbors;
    neighbors.push_back(&c2);
    neighbors.push_back(&c3);
    neighbors.push_back(&c4);
    neighbors.push_back(&c5);
    neighbors.push_back(&c6);
    neighbors.push_back(&c7);
    neighbors.push_back(&c8);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(!c.isAlive());
    vector<AbstractCell*> neighbors2;
    ConwayCell c9(true);
    ConwayCell c10(true);
    ConwayCell c11(true);
    neighbors2.push_back(&c9);
    neighbors2.push_back(&c10);
    neighbors2.push_back(&c11);
    c.setNeighbors(neighbors2);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(c.isAlive());
}

TEST(ConwayCell, update_live_dead_live_7) {
    ConwayCell c(true);
    ConwayCell c2(true);
    ConwayCell c3(true);
    ConwayCell c4(true);
    ConwayCell c5(true);
    ConwayCell c6(true);
    ConwayCell c7(true);
    ConwayCell c8(true);
    ConwayCell c9(true);
    vector<AbstractCell*> neighbors;
    neighbors.push_back(&c2);
    neighbors.push_back(&c3);
    neighbors.push_back(&c4);
    neighbors.push_back(&c5);
    neighbors.push_back(&c6);
    neighbors.push_back(&c7);
    neighbors.push_back(&c8);
    neighbors.push_back(&c9);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(!c.isAlive());
    vector<AbstractCell*> neighbors2;
    ConwayCell c10(true);
    ConwayCell c11(true);
    ConwayCell c12(true);
    neighbors2.push_back(&c10);
    neighbors2.push_back(&c11);
    neighbors2.push_back(&c12);
    c.setNeighbors(neighbors2);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(c.isAlive());
}



// ------------------------
// ConwayCell prepareUpdate()
// ------------------------
TEST(ConwayCell, prepareUpdate_1) {
    ConwayCell c(true);
    ConwayCell c2(true);
    ConwayCell c3(true);
    ConwayCell c4(true);
    ConwayCell c5(true);
    vector<AbstractCell*> neighbors;
    neighbors.push_back(&c2);
    neighbors.push_back(&c3);
    neighbors.push_back(&c4);
    neighbors.push_back(&c5);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    ASSERT_TRUE(c.isAlive());
}

TEST(ConwayCell, prepareUpdate_2) {
    ConwayCell c(false);
    ConwayCell c2(true);
    ConwayCell c3(true);
    ConwayCell c4(true);
    vector<AbstractCell*> neighbors;
    neighbors.push_back(&c2);
    neighbors.push_back(&c3);
    neighbors.push_back(&c4);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    ASSERT_TRUE(!c.isAlive());
}



// ----------
// FredkinCell
// ----------

// -------------------------------------
// FredkinCell constructor and isAlive()
// -------------------------------------
TEST(FredkinCell, constructor_isAlive) {
    FredkinCell c(true);
    ASSERT_TRUE(c.isAlive());
}

TEST(FredkinCell, constructor_isNotAlive) {
    FredkinCell c(false);
    ASSERT_TRUE(!c.isAlive());
}

// ------------------------
// FredkinCell update()
// ------------------------
TEST(FredkinCell, update_live_to_dead_1) {
    FredkinCell c(true);
    FredkinCell c2(true);
    FredkinCell c3(true);
    FredkinCell c4(true);
    FredkinCell c5(true);
    vector<AbstractCell*> neighbors;
    neighbors.push_back(&c2);
    neighbors.push_back(&c3);
    neighbors.push_back(&c4);
    neighbors.push_back(&c5);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(!c.isAlive());
}

TEST(FredkinCell, update_live_to_dead_2) {
    FredkinCell c(true);
    FredkinCell c2(true);
    FredkinCell c3(true);
    vector<AbstractCell*> neighbors;
    neighbors.push_back(&c2);
    neighbors.push_back(&c3);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(!c.isAlive());
}

TEST(FredkinCell, update_live_to_dead_3) {
    FredkinCell c(true);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(!c.isAlive());
}

TEST(FredkinCell, update_dead_to_alive_1) {
    FredkinCell c(false);
    FredkinCell c2(true);
    FredkinCell c3(true);
    FredkinCell c4(true);
    vector<AbstractCell*> neighbors;
    neighbors.push_back(&c2);
    neighbors.push_back(&c3);
    neighbors.push_back(&c4);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(c.isAlive());
}

TEST(FredkinCell, update_dead_to_alive_2) {
    FredkinCell c(false);
    FredkinCell c2(true);
    vector<AbstractCell*> neighbors;
    neighbors.push_back(&c2);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(c.isAlive());
}

TEST(FredkinCell, update_live_to_live_1) {
    FredkinCell c(true);
    FredkinCell c2(true);
    FredkinCell c3(true);
    FredkinCell c4(true);
    vector<AbstractCell*> neighbors;
    neighbors.push_back(&c2);
    neighbors.push_back(&c3);
    neighbors.push_back(&c4);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(c.isAlive());
}

TEST(FredkinCell, update_live_to_live_2) {
    FredkinCell c(true);
    FredkinCell c2(true);
    vector<AbstractCell*> neighbors;
    neighbors.push_back(&c2);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(c.isAlive());
}

TEST(FredkinCell, dead_to_dead_1) {
    FredkinCell c(false);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(!c.isAlive());
}

TEST(FredkinCell, dead_to_dead_2) {
    FredkinCell c(false);
    FredkinCell c2(true);
    FredkinCell c3(true);
    vector<AbstractCell*> neighbors;
    neighbors.push_back(&c2);
    neighbors.push_back(&c3);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(!c.isAlive());
}

TEST(FredkinCell, dead_to_dead_3) {
    FredkinCell c(false);
    FredkinCell c2(true);
    FredkinCell c3(true);
    FredkinCell c4(true);
    FredkinCell c5(true);
    vector<AbstractCell*> neighbors;
    neighbors.push_back(&c2);
    neighbors.push_back(&c3);
    neighbors.push_back(&c4);
    neighbors.push_back(&c5);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(!c.isAlive());
}

TEST(FredkinCell, update_live_dead_live_1) {
    FredkinCell c(true);
    c.prepareUpdate();
    c.update();
    vector<AbstractCell*> neighbors;
    FredkinCell c2(true);
    neighbors.push_back(&c2);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(c.isAlive());
}

TEST(FredkinCell, update_live_dead_live_2) {
    FredkinCell c(true);
    c.prepareUpdate();
    c.update();
    vector<AbstractCell*> neighbors;
    FredkinCell c2(true);
    FredkinCell c3(true);
    FredkinCell c4(true);
    neighbors.push_back(&c2);
    neighbors.push_back(&c3);
    neighbors.push_back(&c4);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(c.isAlive());
}

TEST(FredkinCell, update_dead_live_dead) {
    FredkinCell c(false);
    vector<AbstractCell*> neighbors;
    FredkinCell c2(true);
    neighbors.push_back(&c2);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    FredkinCell c3(true);
    neighbors.push_back(&c3);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(!c.isAlive());
}

TEST(FredkinCell, update_dead_live_dead_2) {
    FredkinCell c(false);
    vector<AbstractCell*> neighbors;
    FredkinCell c2(true);
    neighbors.push_back(&c2);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    vector<AbstractCell*> neighbors2;
    c.setNeighbors(neighbors2);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(!c.isAlive());
}

TEST(FredkinCell, update_dead_live_dead_3) {
    FredkinCell c(false);
    vector<AbstractCell*> neighbors;
    FredkinCell c2(true);
    neighbors.push_back(&c2);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    FredkinCell c3(true);
    FredkinCell c4(true);
    FredkinCell c5(true);
    neighbors.push_back(&c3);
    neighbors.push_back(&c4);
    neighbors.push_back(&c5);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(!c.isAlive());
}

TEST(FredkinCell, update_dead_live_dead_4) {
    FredkinCell c(false);
    vector<AbstractCell*> neighbors;
    FredkinCell c2(true);
    FredkinCell c3(true);
    FredkinCell c4(true);
    neighbors.push_back(&c2);
    neighbors.push_back(&c3);
    neighbors.push_back(&c4);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    vector<AbstractCell*> neighbors2;
    c.setNeighbors(neighbors2);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(!c.isAlive());
}

TEST(FredkinCell, update_dead_live_dead_5) {
    FredkinCell c(false);
    vector<AbstractCell*> neighbors;
    FredkinCell c2(true);
    FredkinCell c3(true);
    FredkinCell c4(true);
    neighbors.push_back(&c2);
    neighbors.push_back(&c3);
    neighbors.push_back(&c4);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    vector<AbstractCell*> neighbors2;
    FredkinCell c5(true);
    FredkinCell c6(true);
    neighbors2.push_back(&c5);
    neighbors2.push_back(&c6);
    c.setNeighbors(neighbors2);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(!c.isAlive());
}

TEST(FredkinCell, update_dead_live_dead_6) {
    FredkinCell c(false);
    vector<AbstractCell*> neighbors;
    FredkinCell c2(true);
    FredkinCell c3(true);
    FredkinCell c4(true);
    neighbors.push_back(&c2);
    neighbors.push_back(&c3);
    neighbors.push_back(&c4);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    vector<AbstractCell*> neighbors2;
    FredkinCell c5(true);
    FredkinCell c6(true);
    FredkinCell c7(true);
    FredkinCell c8(true);
    neighbors2.push_back(&c5);
    neighbors2.push_back(&c6);
    neighbors2.push_back(&c7);
    neighbors2.push_back(&c8);
    c.setNeighbors(neighbors2);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(!c.isAlive());
}

// ------------------------
// FredkinCell prepareUpdate()
// ------------------------
TEST(FredkinCell, prepareUpdate_1) {
    FredkinCell c(true);
    FredkinCell c2(true);
    FredkinCell c3(true);
    FredkinCell c4(true);
    FredkinCell c5(true);
    vector<AbstractCell*> neighbors;
    neighbors.push_back(&c2);
    neighbors.push_back(&c3);
    neighbors.push_back(&c4);
    neighbors.push_back(&c5);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    ASSERT_TRUE(c.isAlive());
}

TEST(FredkinCell, prepareUpdate_2) {
    FredkinCell c(false);
    FredkinCell c2(true);
    FredkinCell c3(true);
    FredkinCell c4(true);
    vector<AbstractCell*> neighbors;
    neighbors.push_back(&c2);
    neighbors.push_back(&c3);
    neighbors.push_back(&c4);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    ASSERT_TRUE(!c.isAlive());
}

// ------------------------
// FredkinCell getAge()
// ------------------------
TEST(FredkinCell, getAge_1) {
    FredkinCell c(true);
    FredkinCell c2(true);
    FredkinCell c3(true);
    FredkinCell c4(true);
    vector<AbstractCell*> neighbors;
    neighbors.push_back(&c2);
    neighbors.push_back(&c3);
    neighbors.push_back(&c4);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(c.getAge() == 1);
}

TEST(FredkinCell, getAge_2) {
    FredkinCell c(true);
    FredkinCell c2(true);
    vector<AbstractCell*> neighbors;
    neighbors.push_back(&c2);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(c.getAge() == 1);
}

TEST(FredkinCell, getAge_3) {
    FredkinCell c(true);
    FredkinCell c2(true);
    FredkinCell c3(true);
    FredkinCell c4(true);
    vector<AbstractCell*> neighbors;
    neighbors.push_back(&c2);
    neighbors.push_back(&c3);
    neighbors.push_back(&c4);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(c.getAge() == 2);
}

TEST(FredkinCell, getAge_4) {
    FredkinCell c(true);
    FredkinCell c2(true);
    FredkinCell c3(true);
    FredkinCell c4(true);
    vector<AbstractCell*> neighbors;
    neighbors.push_back(&c2);
    neighbors.push_back(&c3);
    neighbors.push_back(&c4);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    c.prepareUpdate();
    c.update();
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(c.getAge() == 3);
}

TEST(FredkinCell, getAge_5) {
    FredkinCell c(true);
    FredkinCell c2(true);
    FredkinCell c3(true);
    FredkinCell c4(true);
    vector<AbstractCell*> neighbors;
    neighbors.push_back(&c2);
    neighbors.push_back(&c3);
    neighbors.push_back(&c4);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    FredkinCell c5(true);
    FredkinCell c6(true);
    FredkinCell c7(false);
    vector<AbstractCell*> neighbors2;
    neighbors2.push_back(&c5);
    neighbors2.push_back(&c6);
    neighbors2.push_back(&c7);
    c.setNeighbors(neighbors2);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(c.getAge() == 1);
}

TEST(FredkinCell, getAge_6) {
    FredkinCell c(true);
    FredkinCell c2(true);
    FredkinCell c3(true);
    FredkinCell c4(true);
    vector<AbstractCell*> neighbors;
    neighbors.push_back(&c2);
    neighbors.push_back(&c3);
    neighbors.push_back(&c4);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    c.prepareUpdate();
    c.update();
    FredkinCell c5(true);
    FredkinCell c6(true);
    FredkinCell c7(false);
    vector<AbstractCell*> neighbors2;
    neighbors2.push_back(&c5);
    neighbors2.push_back(&c6);
    neighbors2.push_back(&c7);
    c.setNeighbors(neighbors2);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(c.getAge() == 2);
}

TEST(FredkinCell, getAge_7) {
    FredkinCell c(true);
    FredkinCell c2(true);
    FredkinCell c3(true);
    FredkinCell c4(true);
    vector<AbstractCell*> neighbors;
    neighbors.push_back(&c2);
    neighbors.push_back(&c3);
    neighbors.push_back(&c4);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    c.prepareUpdate();
    c.update();
    c.prepareUpdate();
    c.update();
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(c.getAge() == 4);
}

TEST(FredkinCell, getAge_8) {
    FredkinCell c(true);
    FredkinCell c2(true);
    FredkinCell c3(true);
    FredkinCell c4(true);
    vector<AbstractCell*> neighbors;
    neighbors.push_back(&c2);
    neighbors.push_back(&c3);
    neighbors.push_back(&c4);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    c.prepareUpdate();
    c.update();
    c.prepareUpdate();
    c.update();
    FredkinCell c5(true);
    FredkinCell c6(true);
    FredkinCell c7(false);
    vector<AbstractCell*> neighbors2;
    neighbors2.push_back(&c5);
    neighbors2.push_back(&c6);
    neighbors2.push_back(&c7);
    c.setNeighbors(neighbors2);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(c.getAge() == 3);
}

TEST(FredkinCell, getAge_alive_dead_alive) {
    FredkinCell c(true);
    FredkinCell c2(true);
    FredkinCell c3(true);
    FredkinCell c4(true);
    vector<AbstractCell*> neighbors;
    neighbors.push_back(&c2);
    neighbors.push_back(&c3);
    neighbors.push_back(&c4);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    FredkinCell c5(true);
    FredkinCell c6(true);
    FredkinCell c7(false);
    vector<AbstractCell*> neighbors2;
    neighbors2.push_back(&c5);
    neighbors2.push_back(&c6);
    neighbors2.push_back(&c7);
    c.setNeighbors(neighbors2);
    c.prepareUpdate();
    c.update();
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(c.getAge() == 1);
}

TEST(FredkinCell, getAge_dead_alive) {
    FredkinCell c(false);
    FredkinCell c2(true);
    FredkinCell c3(true);
    FredkinCell c4(true);
    vector<AbstractCell*> neighbors;
    neighbors.push_back(&c2);
    neighbors.push_back(&c3);
    neighbors.push_back(&c4);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(c.getAge() == 0);
}

TEST(FredkinCell, getAge_dead_alive_2) {
    FredkinCell c(false);
    FredkinCell c2(true);
    FredkinCell c3(true);
    FredkinCell c4(true);
    vector<AbstractCell*> neighbors;
    neighbors.push_back(&c2);
    neighbors.push_back(&c3);
    neighbors.push_back(&c4);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(c.getAge() == 1);
}

TEST(FredkinCell, getAge_dead_alive_3) {
    FredkinCell c(false);
    FredkinCell c2(true);
    FredkinCell c3(true);
    FredkinCell c4(true);
    vector<AbstractCell*> neighbors;
    neighbors.push_back(&c2);
    neighbors.push_back(&c3);
    neighbors.push_back(&c4);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    c.prepareUpdate();
    c.update();
    c.prepareUpdate();
    c.update();
    c.prepareUpdate();
    c.update();
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(c.getAge() == 4);
}

TEST(FredkinCell, getAge_dead_alive_4) {
    FredkinCell c(false);
    FredkinCell c2(true);
    FredkinCell c3(true);
    FredkinCell c4(true);
    vector<AbstractCell*> neighbors;
    neighbors.push_back(&c2);
    neighbors.push_back(&c3);
    neighbors.push_back(&c4);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    c.prepareUpdate();
    c.update();
    c.prepareUpdate();
    c.update();
    c.prepareUpdate();
    c.update();
    c.prepareUpdate();
    c.update();
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(c.getAge() == 5);
}

TEST(FredkinCell, getAge_dead_alive_dead_alive) {
    FredkinCell c(false);
    FredkinCell c2(true);
    FredkinCell c3(true);
    FredkinCell c4(true);
    vector<AbstractCell*> neighbors;
    neighbors.push_back(&c2);
    neighbors.push_back(&c3);
    neighbors.push_back(&c4);
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    vector<AbstractCell*> neighbors2;
    FredkinCell c5(true);
    FredkinCell c6(true);
    FredkinCell c7(false);
    neighbors2.push_back(&c5);
    neighbors2.push_back(&c6);
    neighbors2.push_back(&c7);
    c.setNeighbors(neighbors2);
    c.prepareUpdate();
    c.update();
    c.setNeighbors(neighbors);
    c.prepareUpdate();
    c.update();
    ASSERT_TRUE(c.getAge() == 0);
}