#include "AbstractCell.h"
#include "Cell.h"
#include "Life.h"
#include "ConwayCell.h"
#include "gtest/gtest.h"
using namespace std;

TEST(CONWAYCELL, neighbors1) {
  ConwayCell c;
  bool grid[] = {1, 1, 1, 1, 1, 1, 1, 1};
  ASSERT_TRUE (c.count_neighbors (grid) == 8);
}
TEST(CONWAYCELL, neighbors2) {
  ConwayCell c;
  bool grid[] = {0, 0, 0, 0, 0, 0, 0, 0};
  ASSERT_TRUE (c.count_neighbors (grid) == 0);
}
TEST(CONWAYCELL, neighbors3) {
  ConwayCell c;
  bool grid[] = {1, 1, 1, 0, 1, 0, 1, 0};
  ASSERT_TRUE (c.count_neighbors (grid) == 5);
}
TEST(CONWAYCELL, neighbors4) {
  ConwayCell c;
  bool grid[] = {0, 0, 0, 1, 1, 1, 1, 1};
  ASSERT_TRUE (c.count_neighbors (grid) == 5);
}
TEST(CONWAYCELL, neighbors5) {
  ConwayCell c;
  bool grid[] = {1, 0, 1, 1, 1, 1, 1, 1};
  ASSERT_TRUE (c.count_neighbors (grid) == 7);
}
TEST(CONWAYCELL, neighbors6) {
  ConwayCell c;
  bool grid[] = {1, 1, 1, 0, 0, 1, 1, 1};
  ASSERT_TRUE (c.count_neighbors (grid) == 6);
}
TEST(CONWAYCELL, neighbors7) {
  ConwayCell c;
  bool grid[] = {1, 1, 0, 0, 0, 0, 0, 1};
  ASSERT_TRUE (c.count_neighbors (grid) == 3);
}
TEST(CONWAYCELL, neighbors8) {
  ConwayCell c;
  bool grid[] = {0, 0, 1, 1, 0, 0, 0, 0};
  ASSERT_TRUE (c.count_neighbors (grid) == 2);
}
TEST(CONWAYCELL, markalive1) {
  ConwayCell c = {true, true};
  bool grid[] = {0, 0, 1, 1, 0, 0, 0, 0};
  ASSERT_TRUE (c.mark (grid) == true);
}
TEST(CONWAYCELL, markalive2) {
  ConwayCell c = {true, true};
  bool grid[] = {1, 0, 1, 1, 0, 0, 0, 0};
  ASSERT_TRUE (c.mark (grid) == true);
}
TEST(CONWAYCELL, markalive3) {
  ConwayCell c = {true, true};
  bool grid[] = {0, 0, 0, 1, 0, 0, 0, 0};
  ASSERT_TRUE (c.mark (grid) == false);
}
TEST(CONWAYCELL, markalive4) {
  ConwayCell c = {true, true};
  bool grid[] = {0, 0, 1, 1, 1, 1, 1, 1};
  ASSERT_TRUE (c.mark (grid) == false);
}
TEST(CONWAYCELL, markalive5) {
  ConwayCell c = {true, true};
  bool grid[] = {0, 0, 1, 1, 0, 0, 0, 0};
  ASSERT_TRUE (c.mark (grid) == true);
}
TEST(CONWAYCELL, markalive6) {
  ConwayCell c = {true, true};
  bool grid[] = {0, 0, 0, 0, 0, 0, 0, 0};
  ASSERT_TRUE (c.mark (grid) == false);
}
TEST(CONWAYCELL, markalive7) {
  ConwayCell c = {true, true};
  bool grid[] = {1, 1, 1, 1, 0, 0, 0, 0};
  ASSERT_TRUE (c.mark (grid) == false);
}
TEST(CONWAYCELL, markalive8) {
  ConwayCell c = {true, true};
  bool grid[] = {1, 0, 0, 0, 0, 0, 0, 1};
  ASSERT_TRUE (c.mark (grid) == true);
}

TEST(CONWAYCELL, markdead1) {
  ConwayCell c = {false, false};
  bool grid[] = {0, 0, 1, 1, 0, 0, 0, 0};
  ASSERT_TRUE (c.mark (grid) == false);
}
TEST(CONWAYCELL, markdead2) {
  ConwayCell c = {false, false};
  bool grid[] = {1, 0, 1, 1, 0, 0, 0, 0};
  ASSERT_TRUE (c.mark (grid) == true);
}
TEST(CONWAYCELL, markdead3) {
  ConwayCell c = {false, false};
  bool grid[] = {0, 0, 0, 1, 0, 0, 0, 0};
  ASSERT_TRUE (c.mark (grid) == false);
}
TEST(CONWAYCELL, markdead4) {
  ConwayCell c = {false, false};
  bool grid[] = {0, 0, 1, 1, 1, 1, 1, 1};
  ASSERT_TRUE (c.mark (grid) == false);
}
TEST(CONWAYCELL, markdead5) {
  ConwayCell c = {false, false};
  bool grid[] = {0, 0, 1, 1, 0, 0, 0, 0};
  ASSERT_TRUE (c.mark (grid) == false);
}
TEST(CONWAYCELL, markdead6) {
  ConwayCell c = {false, false};
  bool grid[] = {0, 0, 0, 0, 0, 0, 0, 0};
  ASSERT_TRUE (c.mark (grid) == false);
}
TEST(CONWAYCELL, markdead7) {
  ConwayCell c = {false, false};
  bool grid[] = {0, 0, 0, 1, 1, 1, 1, 0};
  ASSERT_TRUE (c.mark (grid) == false);
}
TEST(CONWAYCELL, markdead8) {
  ConwayCell c = {false, false};
  bool grid[] = {0, 0, 0, 0, 0, 0, 1, 1};
  ASSERT_TRUE (c.mark (grid) == false);
}
TEST(CONWAYCELL, markdead9) {
  ConwayCell c = {false, false};
  bool grid[] = {0, 0, 1, 1, 1, 1, 1, 1};
  ASSERT_TRUE (c.mark (grid) == false);
}
TEST(CONWAYCELL, markdead10) {
  ConwayCell c = {false, false};
  bool grid[] = {1, 1, 1, 1, 1, 1, 1, 1};
  ASSERT_TRUE (c.mark (grid) == false);
}

TEST(FREDKINCELL, fneighbors1) {
  FredkinCell c;
  bool grid[] = {1, 1, 1, 1, 1, 1, 1, 1};
  ASSERT_TRUE (c.count_neighbors (grid) == 4);
}
TEST(FREDKINCELL, fneighbors2) {
  FredkinCell c;
  bool grid[] = {0, 0, 0, 0, 0, 0, 0, 0};
  ASSERT_TRUE (c.count_neighbors (grid) == 0);
}
TEST(FREDKINCELL, fneighbors3) {
  FredkinCell c;
  bool grid[] = {1, 1, 1, 0, 1, 0, 1, 0};
  ASSERT_TRUE (c.count_neighbors (grid) == 3);
}
TEST(FREDKINCELL, fneighbors4) {
  FredkinCell c;
  bool grid[] = {0, 0, 0, 1, 1, 1, 1, 1};
  ASSERT_TRUE (c.count_neighbors (grid) == 3);
}
TEST(FREDKINCELL, fneighbors5) {
  FredkinCell c;
  bool grid[] = {1, 0, 1, 1, 1, 1, 1, 1};
  ASSERT_TRUE (c.count_neighbors (grid) == 3);
}
TEST(FREDKINCELL, fneighbors6) {
  FredkinCell c;
  bool grid[] = {0, 1, 0, 0, 0, 1, 0, 1};
  ASSERT_TRUE (c.count_neighbors (grid) == 1);
}
TEST(FREDKINCELL, fneighbors7) {
  FredkinCell c;
  bool grid[] = {1, 0, 0, 0, 0, 0, 0, 0};
  ASSERT_TRUE (c.count_neighbors (grid) == 0);
}
TEST(FREDKINCELL, fneighbors8) {
  FredkinCell c;
  bool grid[] = {0, 0, 1, 1, 0, 0, 1, 0};
  ASSERT_TRUE (c.count_neighbors (grid) == 2);
}

TEST(FREDKINCELL, fmarkalive1) {
  FredkinCell c = {0, true, true};
  bool grid[] = {1, 1, 1, 1, 1, 1, 1, 1};
  ASSERT_TRUE (c.count_neighbors (grid) == 4);
  ASSERT_TRUE (c.mark (grid) == false);
}
TEST(FREDKINCELL, fmarkalive2) {
  FredkinCell c = {0, true, true};
  bool grid[] = {0, 0, 0, 0, 0, 0, 0, 0};
  ASSERT_TRUE (c.count_neighbors (grid) == 0);
  ASSERT_TRUE (c.mark (grid) == false);
}
TEST(FREDKINCELL, fmarkalive3) {
  FredkinCell c = {0, true, true};
  bool grid[] = {1, 1, 1, 0, 1, 0, 1, 0};
  ASSERT_TRUE (c.count_neighbors (grid) == 3);
  ASSERT_TRUE (c.mark (grid) == true);
}
TEST(FREDKINCELL, fmarkalive4) {
  FredkinCell c = {0, true, true};
  bool grid[] = {0, 0, 0, 1, 1, 1, 1, 1};
  ASSERT_TRUE (c.count_neighbors (grid) == 3);
  ASSERT_TRUE (c.mark (grid) == true);
}
TEST(FREDKINCELL, fmarkalive5) {
  FredkinCell c = {0, true, true};
  bool grid[] = {1, 0, 1, 1, 1, 1, 1, 1};
  ASSERT_TRUE (c.count_neighbors (grid) == 3);
  ASSERT_TRUE (c.mark (grid) == true);
}
TEST(FREDKINCELL, fmarkalive6) {
  FredkinCell c = {0, true, true};
  bool grid[] = {0, 1, 0, 0, 0, 1, 0, 1};
  ASSERT_TRUE (c.count_neighbors (grid) == 1);
  ASSERT_TRUE (c.mark (grid) == true);
}
TEST(FREDKINCELL, fmarkalive7) {
  FredkinCell c = {0, true, true};
  bool grid[] = {1, 0, 0, 0, 0, 0, 0, 0};
  ASSERT_TRUE (c.count_neighbors (grid) == 0);
  ASSERT_TRUE (c.mark (grid) == false);
}
TEST(FREDKINCELL, fmarkalive8) {
  FredkinCell c = {0, true, true};
  bool grid[] = {0, 0, 1, 1, 0, 0, 1, 0};
  ASSERT_TRUE (c.count_neighbors (grid) == 2);
  ASSERT_TRUE (c.mark (grid) == false);
}

TEST(FREDKINCELL, fmarkalive9) {
  FredkinCell c = {0, true, true};
  bool grid[] = {1, 0, 1, 1, 0, 0, 1, 0};
  ASSERT_TRUE (c.count_neighbors (grid) == 2);
  ASSERT_TRUE (c.mark (grid) == false);
}
TEST(FREDKINCELL, fmarkdead1) {
  FredkinCell c = {0, false, false};
  bool grid[] = {1, 1, 1, 1, 1, 1, 1, 1};
  ASSERT_TRUE (c.count_neighbors (grid) == 4);
  ASSERT_TRUE (c.mark (grid) == false);
}
TEST(FREDKINCELL, fmarkdead2) {
  FredkinCell c = {0, false, false};
  bool grid[] = {0, 0, 0, 0, 0, 0, 0, 0};
  ASSERT_TRUE (c.count_neighbors (grid) == 0);
  ASSERT_TRUE (c.mark (grid) == false);
}
TEST(FREDKINCELL, fmarkdead3) {
  FredkinCell c = {0, false, false};
  bool grid[] = {1, 1, 1, 0, 1, 0, 1, 0};
  ASSERT_TRUE (c.count_neighbors (grid) == 3);
  ASSERT_TRUE (c.mark (grid) == true);
}
TEST(FREDKINCELL, fmarkdead4) {
  FredkinCell c = {0, false, false};
  bool grid[] = {0, 0, 0, 1, 1, 1, 1, 1};
  ASSERT_TRUE (c.count_neighbors (grid) == 3);
  ASSERT_TRUE (c.mark (grid) == true);
}
TEST(FREDKINCELL, fmarkdead5) {
  FredkinCell c = {0, false, false};
  bool grid[] = {1, 0, 1, 1, 1, 1, 1, 1};
  ASSERT_TRUE (c.count_neighbors (grid) == 3);
  ASSERT_TRUE (c.mark (grid) == true);
}
TEST(FREDKINCELL, fmarkdead6) {
  FredkinCell c = {0, false, false};
  bool grid[] = {0, 1, 0, 0, 0, 1, 0, 1};
  ASSERT_TRUE (c.count_neighbors (grid) == 1);
  ASSERT_TRUE (c.mark (grid) == true);
}
TEST(FREDKINCELL, fmarkdead7) {
  FredkinCell c = {0, false, false};
  bool grid[] = {1, 0, 0, 0, 0, 0, 0, 0};
  ASSERT_TRUE (c.count_neighbors (grid) == 0);
  ASSERT_TRUE (c.mark (grid) == false);
}
TEST(FREDKINCELL, fmarkdead8) {
  FredkinCell c = {0, false, false};
  bool grid[] = {0, 0, 1, 1, 0, 0, 1, 0};
  ASSERT_TRUE (c.count_neighbors (grid) == 2);
  ASSERT_TRUE (c.mark (grid) == true);
}

TEST(FREDKINCELL, fmarkdead9) {
  FredkinCell c = {0, false, false};
  bool grid[] = {1, 0, 1, 1, 0, 0, 1, 0};
  ASSERT_TRUE (c.count_neighbors (grid) == 2);
  ASSERT_TRUE (c.mark (grid) == true);
}
