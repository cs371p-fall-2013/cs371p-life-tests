#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==

#include "gtest/gtest.h"

#include "AbstractCell.h"
#include "Cell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Handle.h"
#include "Life.h"

#include "stdexcept"

using namespace std;
// -----------
// TestLife
// -----------

// ----
// read
// ----

TEST(Life, init_cell_1) {
    ConwayCell c = new ConwayCell(true);
    bool result = c.get_status();
    ASSERT_TRUE(result == true);
}

TEST(Life, init_cell_2) {
    FredkinCell c = FredkinCell(true);
    bool result = c.get_status();
    ASSERT_TRUE(result == true);
}

TEST(Life, init_cell_3) {
    ConwayCell c = ConwayCell(true);
    char result = c.get_rep();
    ASSERT_TRUE(result == '*');
}

TEST(Life, init_cell_4) {
    FredkinCell c = FredkinCell(true);
    char result = c.get_rep();
    ASSERT_TRUE(result == '0');
}

TEST(Life, init_cell_5) {
    ConwayCell c = ConwayCell(false);
    char result = c.get_rep();
    ASSERT_TRUE(result == '.');
}

TEST(Life, init_cell_6) {
    FredkinCell c = FredkinCell(false);
    char result = c.get_rep();
    ASSERT_TRUE(result == '-');
}

TEST(Life, change_1) {
    FredkinCell c = FredkinCell(true);
    c.change(1);
    int result = c.get_age();
    ASSERT_TRUE(result == 1);
}

TEST(Life, change_2) {
    FredkinCell c = FredkinCell(true);
    c.change(1);
    int result = c.get_age();
    ASSERT_TRUE(result == 1);
}

TEST(Life, change_3) {
    FredkinCell c = FredkinCell(true);
    c.change(3);
    int result = c.get_age();
    ASSERT_TRUE(result == 1);
}

TEST(Life, change_4) {
    FredkinCell c = FredkinCell(true);
    c.change(0);
    char result = c.get_rep();
    ASSERT_TRUE(result == '-');
}

TEST(Life, change_5) {
    FredkinCell c = FredkinCell(true);
    c.change(2);
    char result = c.get_rep();
    ASSERT_TRUE(result == '-');
}

TEST(Life, change_6) {
    FredkinCell c = FredkinCell(true);
    c.change(4);
    char result = c.get_rep();
    ASSERT_TRUE(result == '-');
}

TEST(Life, change_7) {
    ConwayCell c = ConwayCell(false);
    c.change(3);
    char result = c.get_rep();
    ASSERT_TRUE(result == '*');
}

TEST(Life, change_8) {
    ConwayCell c = ConwayCell(true);
    c.change(0);
    char result = c.get_rep();
    ASSERT_TRUE(result == '.');
}

TEST(Life, change_9) {
    ConwayCell c = ConwayCell(true);
    c.change(1);
    char result = c.get_rep();
    ASSERT_TRUE(result == '.');
}

TEST(Life, change_10) {
    ConwayCell c = ConwayCell(true);
    c.change(4);
    char result = c.get_rep();
    ASSERT_TRUE(result == '.');
}

TEST(Life, change_11) {
    ConwayCell c = ConwayCell(true);
    c.change(5);
    char result = c.get_rep();
    ASSERT_TRUE(result == '.');
}

TEST(Life, change_12) {
    ConwayCell c = ConwayCell(true);
    c.change(6);
    char result = c.get_rep();
    ASSERT_TRUE(result == '.');
}

TEST(Life, change_13) {
    ConwayCell c = ConwayCell(true);
    c.change(2);
    char result = c.get_rep();
    ASSERT_TRUE(result == '*');
}

TEST(Life, change_14) {
    ConwayCell c = ConwayCell(true);
    c.change(3);
    char result = c.get_rep();
    ASSERT_TRUE(result == '*');
}

TEST(Life, mutate_1) {
    Cell c = Cell(new FredkinCell(true));
    char result = c.get_rep();
    ASSERT_TRUE(result == '0');
    c.mutate();
    result = c.get_rep();
    ASSERT_TRUE(result == '*');
}

TEST(Life, mutate_2) {
    Cell c = Cell(new FredkinCell(true));
    char result = c.get_rep();
    c.change(1);
    c.change(3);
    result = c.get_rep();
    ASSERT_TRUE(result == '*');
}

TEST(Life, ask_for_conway_neighbors_1) {
    ConwayCell c = ConwayCell(false);  
    vector<int> result;
    c.ask_for_neighbors(result, 5, 3);
    ASSERT_TRUE(result[0] == 4);
}

TEST(Life, ask_for_conway_neighbors_2) {
    ConwayCell c = ConwayCell(false);  
    vector<int> result;
    c.ask_for_neighbors(result, 5, 3);
    ASSERT_TRUE(result[1] == 2);
}

TEST(Life, ask_for_conway_neighbors_3) {
    ConwayCell c = ConwayCell(false);  
    vector<int> result;
    c.ask_for_neighbors(result, 5, 3);
    ASSERT_TRUE(result[2] == 4);
}

TEST(Life, ask_for_conway_neighbors_4) {
    ConwayCell c = ConwayCell(false);  
    vector<int> result;
    c.ask_for_neighbors(result, 5, 3);
    ASSERT_TRUE(result[3] == 3);
}

TEST(Life, ask_for_conway_neighbors_5) {
    ConwayCell c = ConwayCell(false);  
    vector<int> result;
    c.ask_for_neighbors(result, 5, 3);
    ASSERT_TRUE(result[4] == 4);
}

TEST(Life, ask_for_conway_neighbors_6) {
    ConwayCell c = ConwayCell(false);  
    vector<int> result;
    c.ask_for_neighbors(result, 5, 3);
    ASSERT_TRUE(result[5] == 4);
}

TEST(Life, ask_for_conway_neighbors_7) {
    ConwayCell c = ConwayCell(false);  
    vector<int> result;
    c.ask_for_neighbors(result, 5, 3);
    ASSERT_TRUE(result[6] == 5);
}

TEST(Life, ask_for_conway_neighbors_8) {
    ConwayCell c = ConwayCell(false);  
    vector<int> result;
    c.ask_for_neighbors(result, 5, 3);
    ASSERT_TRUE(result[7] == 2);
}

TEST(Life, ask_for_conway_neighbors_9) {
    ConwayCell c = ConwayCell(false);  
    vector<int> result;
    c.ask_for_neighbors(result, 5, 3);
    ASSERT_TRUE(result[8] == 5);
}

TEST(Life, ask_for_conway_neighbors_10) {
    ConwayCell c = ConwayCell(false);  
    vector<int> result;
    c.ask_for_neighbors(result, 5, 3);
    ASSERT_TRUE(result[9] == 4);
}

TEST(Life, ask_for_conway_neighbors_11) {
    ConwayCell c = ConwayCell(false);  
    vector<int> result;
    c.ask_for_neighbors(result, 5, 3);
    ASSERT_TRUE(result[10] == 6);
}


TEST(Life, ask_for_conway_neighbors_12) {
    ConwayCell c = ConwayCell(false);  
    vector<int> result;
    c.ask_for_neighbors(result, 5, 3);
    ASSERT_TRUE(result[11] == 2);
}


TEST(Life, ask_for_conway_neighbors_13) {
    ConwayCell c = ConwayCell(false);  
    vector<int> result;
    c.ask_for_neighbors(result, 5, 3);
    ASSERT_TRUE(result[12] == 6);
}


TEST(Life, ask_for_conway_neighbors_14) {
    ConwayCell c = ConwayCell(false);  
    vector<int> result;
    c.ask_for_neighbors(result, 5, 3);
    ASSERT_TRUE(result[13] == 3);
}


TEST(Life, ask_for_conway_neighbors_15) {
    ConwayCell c = ConwayCell(false);  
    vector<int> result;
    c.ask_for_neighbors(result, 5, 3);
    ASSERT_TRUE(result[14] == 6);
}


TEST(Life, ask_for_conway_neighbors_16) {
    ConwayCell c = ConwayCell(false);  
    vector<int> result;
    c.ask_for_neighbors(result, 5, 3);
    ASSERT_TRUE(result[15] == 4);
}

TEST(Life, ask_for_fredkin_neighbors_1) {
    FredkinCell c = FredkinCell(false);  
    vector<int> result;
    c.ask_for_neighbors(result, 5, 3);
    ASSERT_TRUE(result[0] == 4);
}

TEST(Life, ask_for_fredkin_neighbors_2) {
    FredkinCell c = FredkinCell(false);  
    vector<int> result;
    c.ask_for_neighbors(result, 5, 3);
    ASSERT_TRUE(result[1] == 3);
}

TEST(Life, ask_for_fredkin_neighbors_3) {
    FredkinCell c = FredkinCell(false);  
    vector<int> result;
    c.ask_for_neighbors(result, 5, 3);
    ASSERT_TRUE(result[2] == 5);
}

TEST(Life, ask_for_fredkin_neighbors_4) {
    FredkinCell c = FredkinCell(false);  
    vector<int> result;
    c.ask_for_neighbors(result, 5, 3);
    ASSERT_TRUE(result[3] == 2);
}

TEST(Life, ask_for_fredkin_neighbors_5) {
    FredkinCell c = FredkinCell(false);  
    vector<int> result;
    c.ask_for_neighbors(result, 5, 3);
    ASSERT_TRUE(result[4] == 5);
}

TEST(Life, ask_for_fredkin_neighbors_6) {
    FredkinCell c = FredkinCell(false);  
    vector<int> result;
    c.ask_for_neighbors(result, 5, 3);
    ASSERT_TRUE(result[5] == 4);
}

TEST(Life, ask_for_fredkin_neighbors_7) {
    FredkinCell c = FredkinCell(false);  
    vector<int> result;
    c.ask_for_neighbors(result, 5, 3);
    ASSERT_TRUE(result[6] == 6);
}

TEST(Life, ask_for_fredkin_neighbors_8) {
    FredkinCell c = FredkinCell(false);  
    vector<int> result;
    c.ask_for_neighbors(result, 5, 3);
    ASSERT_TRUE(result[7] == 3);
}

TEST(Life, ask_for_conway_neighbors_17) {
    ConwayCell c = ConwayCell(false);  
    vector<int> result;
    c.ask_for_neighbors(result, 7, 7);
    ASSERT_TRUE(result[0] == 6);
}

TEST(Life, ask_for_conway_neighbors_18) {
    ConwayCell c = ConwayCell(false);  
    vector<int> result;
    c.ask_for_neighbors(result, 7, 7);
    ASSERT_TRUE(result[1] == 6);
}

TEST(Life, ask_for_conway_neighbors_19) {
    ConwayCell c = ConwayCell(false);  
    vector<int> result;
    c.ask_for_neighbors(result, 7, 7);
    ASSERT_TRUE(result[2] == 6);
}

TEST(Life, ask_for_conway_neighbors_20) {
    ConwayCell c = ConwayCell(false);  
    vector<int> result;
    c.ask_for_neighbors(result, 7, 7);
    ASSERT_TRUE(result[3] == 7);
}

TEST(Life, ask_for_conway_neighbors_21) {
    ConwayCell c = ConwayCell(true);  
    vector<int> result;
    c.ask_for_neighbors(result, 7, 7);
    ASSERT_TRUE(result[4] == 6);
}

TEST(Life, ask_for_conway_neighbors_22) {
    ConwayCell c = ConwayCell(false);  
    vector<int> result;
    c.ask_for_neighbors(result, 7, 7);
    ASSERT_TRUE(result[5] == 8);
}

TEST(Life, ask_for_conway_neighbors_23) {
    ConwayCell c = ConwayCell(false);  
    vector<int> result;
    c.ask_for_neighbors(result, 7, 7);
    ASSERT_TRUE(result[6] == 7);
}

TEST(Life, ask_for_conway_neighbors_24) {
    ConwayCell c = ConwayCell(false);  
    vector<int> result;
    c.ask_for_neighbors(result, 7, 7);
    ASSERT_TRUE(result[7] == 6);
}

TEST(Life, ask_for_conway_neighbors_25) {
    ConwayCell c = ConwayCell(false);  
    vector<int> result;
    c.ask_for_neighbors(result, 7, 7);
    ASSERT_TRUE(result[8] == 7);
}

TEST(Life, ask_for_conway_neighbors_26) {
    ConwayCell c = ConwayCell(false);  
    vector<int> result;
    c.ask_for_neighbors(result, 7, 7);
    ASSERT_TRUE(result[9] == 8);
}

TEST(Life, ask_for_conway_neighbors_27) {
    ConwayCell c = ConwayCell(false);  
    vector<int> result;
    c.ask_for_neighbors(result, 7, 7);
    ASSERT_TRUE(result[10] == 8);
}


TEST(Life, ask_for_conway_neighbors_28) {
    ConwayCell c = ConwayCell(false);  
    vector<int> result;
    c.ask_for_neighbors(result, 7, 7);
    ASSERT_TRUE(result[11] == 6);
}


TEST(Life, ask_for_conway_neighbors_29) {
    ConwayCell c = ConwayCell(false);  
    vector<int> result;
    c.ask_for_neighbors(result, 7, 7);
    ASSERT_TRUE(result[12] == 8);
}


TEST(Life, ask_for_conway_neighbors_30) {
    ConwayCell c = ConwayCell(false);  
    vector<int> result;
    c.ask_for_neighbors(result, 7, 7);
    ASSERT_TRUE(result[13] == 7);
}


TEST(Life, ask_for_conway_neighbors_31) {
    ConwayCell c = ConwayCell(false);  
    vector<int> result;
    c.ask_for_neighbors(result, 7, 7);
    ASSERT_TRUE(result[14] == 8);
}


TEST(Life, ask_for_conway_neighbors_32) {
    ConwayCell c = ConwayCell(false);  
    vector<int> result;
    c.ask_for_neighbors(result, 7, 7);
    ASSERT_TRUE(result[15] == 8);
}
