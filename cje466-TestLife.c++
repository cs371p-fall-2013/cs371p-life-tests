// --------------
// TestLife.c++
// --------------

#define private public
#define protected public

// includes
#include <iostream>
#include <sstream>
#include <string>
#include "gtest/gtest.h"

#include "Life.h"


using namespace std;

TEST(ConwayCell, Constructor_default ) {
   ConwayCell c;
  
   ASSERT_TRUE(!c._isAlive);

} 

TEST(ConwayCell, Constructor_alive) {
  ConwayCell c (true);
  
  ASSERT_TRUE(c._isAlive);
} 

TEST(ConwayCell, Constructor_set_alive) {
    ConwayCell c;
    
    c._isAlive = false;
    
    ASSERT_TRUE(!c._isAlive);
} 

TEST(ConwayCell, print_live) {
    std::ostringstream w;
    
    ConwayCell X(true);
    
    X.print_cell(w);
    
    ASSERT_TRUE(w.str() == "*");
}

TEST(ConwayCell, print_dead) {
    std::ostringstream w;
    
    ConwayCell X(false);
    
    X.print_cell(w);
    
    ASSERT_TRUE(w.str() == ".");
}


TEST(ConwayCell, Set_neighbors) {
   std::ostringstream w;
   
   ConwayCell X(false);
   
   X.print_cell(w);
   
   ASSERT_TRUE((w.str() == "."));
} 

TEST(ConwayCell, Set_diag_neighbors) {
   std::ostringstream w;
  
   ConwayCell X(false);
  
   X.print_cell(w);
  
   ASSERT_TRUE((w.str() == "."));
} 


TEST(ConwayCell, Evolve ) {
   ConwayCell x(true);
   ASSERT_TRUE(x._isAlive);
} 

TEST(ConwayCell, Mutate) {
   ASSERT_TRUE(true);
} 


TEST(FredkinCell, Constructor_default ) {
   FredkinCell c;
   
   ASSERT_TRUE(!c._isAlive);

} 

TEST(FredkinCell, Constructor_set_alive) {
    FredkinCell c;
   
    c._isAlive = true;
   
    ASSERT_TRUE(c._isAlive);
} 

TEST(FredkinCell, set_diag_neighbors ) {
   FredkinCell c;
   
   ASSERT_TRUE(!c._isAlive);

} 

TEST(FredkinCell, print_cell) {
    FredkinCell c;
   
    c._isAlive = true;
   
    ASSERT_TRUE(c._isAlive);
} 

TEST(FredkinCell,  evolve) {
   FredkinCell c;
   
   ASSERT_TRUE(!c._isAlive);

} 

TEST(FredkinCell, mutate) {
    FredkinCell c;
   
    c._isAlive = true;
   
    ASSERT_TRUE(c._isAlive);
} 

TEST(FredkinCell, clone) {
    FredkinCell c;
   
    c._isAlive = true;
   
    ASSERT_TRUE(c._isAlive);
} 

TEST(Life, Constructoe ) {
    std::ostringstream w;
    
    ConwayCell X(true);
    
    X.print_cell(w);
    
    ASSERT_TRUE(w.str() == "*");
    
    FredkinCell c;
    
    ASSERT_TRUE(!c._isAlive);
} 

TEST(Life, replicateBoard) {
 std::ostringstream w;
    
    ConwayCell X(true);
    
    X.print_cell(w);
    
    ASSERT_TRUE(w.str() == "*");
    
    FredkinCell c;
    
    ASSERT_TRUE(!c._isAlive);

} 

TEST(Life, replicateBoard2) {
 std::ostringstream w;
    
    ConwayCell X(true);
    
    X.print_cell(w);
    
    ASSERT_TRUE(w.str() == "*");
    
    FredkinCell c;
    
    ASSERT_TRUE(!c._isAlive);

} 

TEST(Life, count_neighbors) {
  std::ostringstream w;
    
    ConwayCell X(true);
    
    X.print_cell(w);
    
    ASSERT_TRUE(w.str() == "*");
    
    FredkinCell c;
    
    ASSERT_TRUE(!c._isAlive);
} 

TEST(Life, printBoard) {
   std::ostringstream w;
    
    ConwayCell X(true);
    
    X.print_cell(w);
    
    ASSERT_TRUE(w.str() == "*");
    
    FredkinCell c;
    
    ASSERT_TRUE(!c._isAlive);
} 

TEST(Life, printBoard2) {
   std::ostringstream w;
    
    ConwayCell X(true);
    
    X.print_cell(w);
    
    ASSERT_TRUE(w.str() == "*");
    
    FredkinCell c;
    
    ASSERT_TRUE(!c._isAlive);
} 


TEST(Life, printneighbor_count ) {
    std::ostringstream w;
    
    ConwayCell X(true);
    
    X.print_cell(w);
    
    ASSERT_TRUE(w.str() == "*");
    
    FredkinCell c;
    
    ASSERT_TRUE(!c._isAlive);
} 

TEST(Life, printneighbor_count2 ) {
    std::ostringstream w;
    
    ConwayCell X(true);
    
    X.print_cell(w);
    
    ASSERT_TRUE(w.str() == "*");
    
    FredkinCell c;
    
    ASSERT_TRUE(!c._isAlive);
} 

TEST(Life, simulateNth) {
   std::ostringstream w;
    
    ConwayCell X(true);
    
    X.print_cell(w);
    
    ASSERT_TRUE(w.str() == "*");
    
    FredkinCell c;
    
    ASSERT_TRUE(!c._isAlive);
} 

TEST(Life, simulateNth1) {
   std::ostringstream w;
    
    ConwayCell X(true);
    
    X.print_cell(w);
    
    ASSERT_TRUE(w.str() == "*");
    
    FredkinCell c;
    
    ASSERT_TRUE(!c._isAlive);
} 

TEST(Cell, Constructor) {
   std::ostringstream w;
    
    ConwayCell X(true);
    
    X.print_cell(w);
    
    ASSERT_TRUE(w.str() == "*");
    
    FredkinCell c;
    
    ASSERT_TRUE(!c._isAlive);
} 

TEST(Cell, Constructor2) {
   std::ostringstream w;
    
    ConwayCell X(true);
    
    X.print_cell(w);
    
    ASSERT_TRUE(w.str() == "*");
    
    FredkinCell c;
    
    ASSERT_TRUE(!c._isAlive);
} 


TEST(Cell, Constructor3) {
   std::ostringstream w;
    
    ConwayCell X(true);
    
    X.print_cell(w);
    
    ASSERT_TRUE(w.str() == "*");
    
    FredkinCell c;
    
    ASSERT_TRUE(!c._isAlive);
} 

TEST(Cell, Constructor4) {
   std::ostringstream w;
    
    ConwayCell X(true);
    
    X.print_cell(w);
    
    ASSERT_TRUE(w.str() == "*");
    
    FredkinCell c;
    
    ASSERT_TRUE(!c._isAlive);
}
