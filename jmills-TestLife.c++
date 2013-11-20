#include <iostream>
#include <sstream>
#include <string>
#include "gtest/gtest.h"

#include "Life.h"
#include "Cell.h"

//---------------
// Conway Cells
//---------------

TEST(Life, Conway_dead) {
    ConwayCell c(false);
    ASSERT_TRUE(c.to_str() == ".");
}

TEST(Life, Conway_live) {
    ConwayCell c(true);
    ASSERT_TRUE(c.to_str() == "*");
}

TEST(Life, Conway_default) {
    ConwayCell c;
    ASSERT_TRUE(c.to_str() == ".");
}

TEST(Life, Conway_clone) {
    ConwayCell c;
    AbstractCell* d = c.clone();
    ASSERT_TRUE(d->to_str() == ".");
    delete d;
}

TEST(Life, Conway_neighbors_0_live) {
    ConwayCell c(true);
    AbstractCell* neighbors [8];
    ConwayCell d(false);
    for (int i = 0; i < 8; i++)
        neighbors[i] = &d;
    c.update_neighbors(neighbors);
    c.update_state();
    ASSERT_TRUE(c.to_str() == ".");
}

TEST(Life, Conway_neighbors_1_live) {
    ConwayCell c(true);
    AbstractCell* neighbors [8];
    ConwayCell d(false);
    ConwayCell l(true);
    for (int i = 0; i < 8; i++) {
        if (i < 7)
            neighbors[i] = &d;
        else
            neighbors[i] = &l;
    }
    c.update_neighbors(neighbors);
    c.update_state();
    ASSERT_TRUE(c.to_str() == ".");
}

TEST(Life, Conway_neighbors_2_live) {
    ConwayCell c(true);
    AbstractCell* neighbors [8];
    ConwayCell d(false);
    ConwayCell l(true);
    for (int i = 0; i < 8; i++) {
        if (i < 6)
            neighbors[i] = &d;
        else
            neighbors[i] = &l;
    }
    c.update_neighbors(neighbors);
    c.update_state();
    ASSERT_TRUE(c.to_str() == "*");
}

TEST(Life, Conway_neighbors_3_live) {
    ConwayCell c(true);
    AbstractCell* neighbors [8];
    ConwayCell d(false);
    ConwayCell l(true);
    for (int i = 0; i < 8; i++) {
        if (i < 5)
            neighbors[i] = &d;
        else
            neighbors[i] = &l;
    }
    c.update_neighbors(neighbors);
    c.update_state();
    ASSERT_TRUE(c.to_str() == "*");
}

TEST(Life, Conway_neighbors_4_live) {
    ConwayCell c(true);
    AbstractCell* neighbors [8];
    ConwayCell d(false);
    ConwayCell l(true);
    for (int i = 0; i < 8; i++) {
        if (i < 4)
            neighbors[i] = &d;
        else
            neighbors[i] = &l;
    }
    c.update_neighbors(neighbors);
    c.update_state();
    ASSERT_TRUE(c.to_str() == ".");
}

TEST(Life, Conway_neighbors_5_live) {
    ConwayCell c(true);
    AbstractCell* neighbors [8];
    ConwayCell d(false);
    ConwayCell l(true);
    for (int i = 0; i < 8; i++) {
        if (i < 3)
            neighbors[i] = &d;
        else
            neighbors[i] = &l;
    }
    c.update_neighbors(neighbors);
    c.update_state();
    ASSERT_TRUE(c.to_str() == ".");
}

TEST(Life, Conway_neighbors_6_live) {
    ConwayCell c(true);
    AbstractCell* neighbors [8];
    ConwayCell d(false);
    ConwayCell l(true);
    for (int i = 0; i < 8; i++) {
        if (i < 2)
            neighbors[i] = &d;
        else
            neighbors[i] = &l;
    }
    c.update_neighbors(neighbors);
    c.update_state();
    ASSERT_TRUE(c.to_str() == ".");
}

TEST(Life, Conway_neighbors_7_live) {
    ConwayCell c(true);
    AbstractCell* neighbors [8];
    ConwayCell d(false);
    ConwayCell l(true);
    for (int i = 0; i < 8; i++) {
        if (i < 1)
            neighbors[i] = &d;
        else
            neighbors[i] = &l;
    }
    c.update_neighbors(neighbors);
    c.update_state();
    ASSERT_TRUE(c.to_str() == ".");
}

TEST(Life, Conway_neighbors_8_live) {
    ConwayCell c(true);
    AbstractCell* neighbors [8];
    ConwayCell l(true);
    for (int i = 0; i < 8; i++)
        neighbors[i] = &l;
    c.update_neighbors(neighbors);
    c.update_state();
    ASSERT_TRUE(c.to_str() == ".");
}

TEST(Life, Conway_neighbors_0_dead) {
    ConwayCell c(false);
    AbstractCell* neighbors [8];
    ConwayCell d(false);
    for (int i = 0; i < 8; i++)
        neighbors[i] = &d;
    c.update_neighbors(neighbors);
    c.update_state();
    ASSERT_TRUE(c.to_str() == ".");
}

TEST(Life, Conway_neighbors_1_dead) {
    ConwayCell c(false);
    AbstractCell* neighbors [8];
    ConwayCell d(false);
    ConwayCell l(true);
    for (int i = 0; i < 8; i++) {
        if (i < 7)
            neighbors[i] = &d;
        else
            neighbors[i] = &l;
    }
    c.update_neighbors(neighbors);
    c.update_state();
    ASSERT_TRUE(c.to_str() == ".");
}

TEST(Life, Conway_neighbors_2_dead) {
    ConwayCell c(false);
    AbstractCell* neighbors [8];
    ConwayCell d(false);
    ConwayCell l(true);
    for (int i = 0; i < 8; i++) {
        if (i < 6)
            neighbors[i] = &d;
        else
            neighbors[i] = &l;
    }
    c.update_neighbors(neighbors);
    c.update_state();
    ASSERT_TRUE(c.to_str() == ".");
}

TEST(Life, Conway_neighbors_3_dead) {
    ConwayCell c(false);
    AbstractCell* neighbors [8];
    ConwayCell d(false);
    ConwayCell l(true);
    for (int i = 0; i < 8; i++) {
        if (i < 5)
            neighbors[i] = &d;
        else
            neighbors[i] = &l;
    }
    c.update_neighbors(neighbors);
    c.update_state();
    ASSERT_TRUE(c.to_str() == "*");
}

TEST(Life, Conway_neighbors_4_dead) {
    ConwayCell c(false);
    AbstractCell* neighbors [8];
    ConwayCell d(false);
    ConwayCell l(true);
    for (int i = 0; i < 8; i++) {
        if (i < 4)
            neighbors[i] = &d;
        else
            neighbors[i] = &l;
    }
    c.update_neighbors(neighbors);
    c.update_state();
    ASSERT_TRUE(c.to_str() == ".");
}

TEST(Life, Conway_neighbors_5_dead) {
    ConwayCell c(false);
    AbstractCell* neighbors [8];
    ConwayCell d(false);
    ConwayCell l(true);
    for (int i = 0; i < 8; i++) {
        if (i < 3)
            neighbors[i] = &d;
        else
            neighbors[i] = &l;
    }
    c.update_neighbors(neighbors);
    c.update_state();
    ASSERT_TRUE(c.to_str() == ".");
}

TEST(Life, Conway_neighbors_6_dead) {
    ConwayCell c(false);
    AbstractCell* neighbors [8];
    ConwayCell d(false);
    ConwayCell l(true);
    for (int i = 0; i < 8; i++) {
        if (i < 2)
            neighbors[i] = &d;
        else
            neighbors[i] = &l;
    }
    c.update_neighbors(neighbors);
    c.update_state();
    ASSERT_TRUE(c.to_str() == ".");
}

TEST(Life, Conway_neighbors_7_dead) {
    ConwayCell c(false);
    AbstractCell* neighbors [8];
    ConwayCell d(false);
    ConwayCell l(true);
    for (int i = 0; i < 8; i++) {
        if (i < 1)
            neighbors[i] = &d;
        else
            neighbors[i] = &l;
    }
    c.update_neighbors(neighbors);
    c.update_state();
    ASSERT_TRUE(c.to_str() == ".");
}

TEST(Life, Conway_neighbors_8_dead) {
    ConwayCell c(false);
    AbstractCell* neighbors [8];
    ConwayCell l(true);
    for (int i = 0; i < 8; i++)
        neighbors[i] = &l;
    c.update_neighbors(neighbors);
    c.update_state();
    ASSERT_TRUE(c.to_str() == ".");
}


//---------------
// Fredkin Cells
//---------------

TEST(Life, Fredkin_dead) {
    FredkinCell c(false);
    ASSERT_TRUE(c.to_str() == "-");
}

TEST(Life, Fredkin_live) {
    FredkinCell c(true);
    ASSERT_TRUE(c.to_str() == "0");
}

TEST(Life, Fredkin_default) {
    FredkinCell c;
    ASSERT_TRUE(c.to_str() == "-");
}

TEST(Life, Fredkin_clone) {
    FredkinCell c;
    AbstractCell* d = c.clone();
    ASSERT_TRUE(d->to_str() == "-");
    delete d;
}

TEST(Life, Fredkin_neighbors_0_live) {
    FredkinCell c(true);
    AbstractCell* neighbors [8];
    FredkinCell d(false);
    for (int i = 0; i < 8; i++)
        neighbors[i] = &d;
    c.update_neighbors(neighbors);
    c.update_state();
    ASSERT_TRUE(c.to_str() == "-");
}

TEST(Life, Fredkin_neighbors_1_live) {
    FredkinCell c(true);
    AbstractCell* neighbors [8];
    FredkinCell d(false);
    FredkinCell l(true);
    for (int i = 0; i < 8; i++) {
        if (i < 7)
            neighbors[i] = &d;
        else
            neighbors[i] = &l;
    }
    c.update_neighbors(neighbors);
    c.update_state();
    ASSERT_TRUE(c.to_str() == "-");
}

TEST(Life, Fredkin_neighbors_2_live) {
    FredkinCell c(true);
    AbstractCell* neighbors [8];
    FredkinCell d(false);
    FredkinCell l(true);
    for (int i = 0; i < 8; i++) {
        if (i < 6)
            neighbors[i] = &d;
        else
            neighbors[i] = &l;
    }
    c.update_neighbors(neighbors);
    c.update_state();
    ASSERT_TRUE(c.to_str() == "1");
}

TEST(Life, Fredkin_neighbors_3_live) {
    FredkinCell c(true);
    AbstractCell* neighbors [8];
    FredkinCell d(false);
    FredkinCell l(true);
    for (int i = 0; i < 8; i++) {
        if (i < 5)
            neighbors[i] = &d;
        else
            neighbors[i] = &l;
    }
    c.update_neighbors(neighbors);
    c.update_state();
    ASSERT_TRUE(c.to_str() == "1");
}

TEST(Life, Fredkin_neighbors_4_live) {
    FredkinCell c(true);
    AbstractCell* neighbors [8];
    FredkinCell d(false);
    FredkinCell l(true);
    for (int i = 0; i < 8; i++) {
        if (i < 4)
            neighbors[i] = &d;
        else
            neighbors[i] = &l;
    }
    c.update_neighbors(neighbors);
    c.update_state();
    ASSERT_TRUE(c.to_str() == "-");
}

TEST(Life, Fredkin_neighbors_5_live) {
    FredkinCell c(true);
    AbstractCell* neighbors [8];
    FredkinCell d(false);
    FredkinCell l(true);
    for (int i = 0; i < 8; i++) {
        if (i < 3)
            neighbors[i] = &d;
        else
            neighbors[i] = &l;
    }
    c.update_neighbors(neighbors);
    c.update_state();
    ASSERT_TRUE(c.to_str() == "1");
}

TEST(Life, Fredkin_neighbors_6_live) {
    FredkinCell c(true);
    AbstractCell* neighbors [8];
    FredkinCell d(false);
    FredkinCell l(true);
    for (int i = 0; i < 8; i++) {
        if (i < 2)
            neighbors[i] = &d;
        else
            neighbors[i] = &l;
    }
    c.update_neighbors(neighbors);
    c.update_state();
    ASSERT_TRUE(c.to_str() == "1");
}

TEST(Life, Fredkin_neighbors_7_live) {
    FredkinCell c(true);
    AbstractCell* neighbors [8];
    FredkinCell d(false);
    FredkinCell l(true);
    for (int i = 0; i < 8; i++) {
        if (i < 1)
            neighbors[i] = &d;
        else
            neighbors[i] = &l;
    }
    c.update_neighbors(neighbors);
    c.update_state();
    ASSERT_TRUE(c.to_str() == "-");
}

TEST(Life, Fredkin_neighbors_8_live) {
    FredkinCell c(true);
    AbstractCell* neighbors [8];
    FredkinCell l(true);
    for (int i = 0; i < 8; i++)
        neighbors[i] = &l;
    c.update_neighbors(neighbors);
    c.update_state();
    ASSERT_TRUE(c.to_str() == "-");
}

TEST(Life, Fredkin_neighbors_0_dead) {
    FredkinCell c(false);
    AbstractCell* neighbors [8];
    FredkinCell d(false);
    for (int i = 0; i < 8; i++)
        neighbors[i] = &d;
    c.update_neighbors(neighbors);
    c.update_state();
    ASSERT_TRUE(c.to_str() == "-");
}

TEST(Life, Fredkin_neighbors_1_dead) {
    FredkinCell c(false);
    AbstractCell* neighbors [8];
    FredkinCell d(false);
    FredkinCell l(true);
    for (int i = 0; i < 8; i++) {
        if (i < 7)
            neighbors[i] = &d;
        else
            neighbors[i] = &l;
    }
    c.update_neighbors(neighbors);
    c.update_state();
    ASSERT_TRUE(c.to_str() == "-");
}

TEST(Life, Fredkin_neighbors_2_dead) {
    FredkinCell c(false);
    AbstractCell* neighbors [8];
    FredkinCell d(false);
    FredkinCell l(true);
    for (int i = 0; i < 8; i++) {
        if (i < 6)
            neighbors[i] = &d;
        else
            neighbors[i] = &l;
    }
    c.update_neighbors(neighbors);
    c.update_state();
    ASSERT_TRUE(c.to_str() == "0");
}

TEST(Life, Fredkin_neighbors_3_dead) {
    FredkinCell c(false);
    AbstractCell* neighbors [8];
    FredkinCell d(false);
    FredkinCell l(true);
    for (int i = 0; i < 8; i++) {
        if (i < 5)
            neighbors[i] = &d;
        else
            neighbors[i] = &l;
    }
    c.update_neighbors(neighbors);
    c.update_state();
    ASSERT_TRUE(c.to_str() == "0");
}

TEST(Life, Fredkin_neighbors_4_dead) {
    FredkinCell c(false);
    AbstractCell* neighbors [8];
    FredkinCell d(false);
    FredkinCell l(true);
    for (int i = 0; i < 8; i++) {
        if (i < 4)
            neighbors[i] = &d;
        else
            neighbors[i] = &l;
    }
    c.update_neighbors(neighbors);
    c.update_state();
    ASSERT_TRUE(c.to_str() == "-");
}

TEST(Life, Fredkin_neighbors_5_dead) {
    FredkinCell c(false);
    AbstractCell* neighbors [8];
    FredkinCell d(false);
    FredkinCell l(true);
    for (int i = 0; i < 8; i++) {
        if (i < 3)
            neighbors[i] = &d;
        else
            neighbors[i] = &l;
    }
    c.update_neighbors(neighbors);
    c.update_state();
    ASSERT_TRUE(c.to_str() == "0");
}

TEST(Life, Fredkin_neighbors_6_dead) {
    FredkinCell c(false);
    AbstractCell* neighbors [8];
    FredkinCell d(false);
    FredkinCell l(true);
    for (int i = 0; i < 8; i++) {
        if (i < 2)
            neighbors[i] = &d;
        else
            neighbors[i] = &l;
    }
    c.update_neighbors(neighbors);
    c.update_state();
    ASSERT_TRUE(c.to_str() == "0");
}

TEST(Life, Fredkin_neighbors_7_dead) {
    FredkinCell c(false);
    AbstractCell* neighbors [8];
    FredkinCell d(false);
    FredkinCell l(true);
    for (int i = 0; i < 8; i++) {
        if (i < 1)
            neighbors[i] = &d;
        else
            neighbors[i] = &l;
    }
    c.update_neighbors(neighbors);
    c.update_state();
    ASSERT_TRUE(c.to_str() == "-");
}

TEST(Life, Fredkin_neighbors_8_dead) {
    FredkinCell c(false);
    AbstractCell* neighbors [8];
    FredkinCell l(true);
    for (int i = 0; i < 8; i++)
        neighbors[i] = &l;
    c.update_neighbors(neighbors);
    c.update_state();
    ASSERT_TRUE(c.to_str() == "-");
}

TEST(Life, Fredkin_old) {
    FredkinCell c(true);
    AbstractCell* neighbors [8];
    FredkinCell d(false);
    FredkinCell l(true);
    for (int i = 0; i < 8; i++) {
        if (i < 2)
            neighbors[i] = &d;
        else
            neighbors[i] = &l;
    }
    for (int i = 0; i < 10; i++) {
        c.update_neighbors(neighbors);
        c.update_state();
    }
    ASSERT_TRUE(c.to_str() == "+");
}