// --------
// includes
// --------

#include <iostream> // cout, endl
// #include <sstream>  // istringtstream, ostringstream
#include <string>   // ==
#include <stdexcept>

#include "gtest/gtest.h"
#define private public
#define protected public
#include "Life.h" 
#include "FredkinCell.h"
#include "ConwayCell.h"
#include "Cell.h"

typedef Life<Cell> CellLife;
typedef Life<ConwayCell> ConwayLife;
typedef Life<FredkinCell> FredkinLife;
// ------------
// Test Life<>
// ------------
// construct .. done 
// run .. done 1 for each cell types. 
// print .. done 
// countAlive .. done 
// countAliveAdj .. done 
// countAliveDiag .. done 
// getIdx .. done 

TEST(Life, getIdx1)
{
    CellLife::GridT g;
    CellLife l(g, 5, 3);
    int idx = l.getIdx_(4, 2);
    ASSERT_EQ(idx, 14); 
}
TEST(Life, getIdx2)
{
    CellLife::GridT g;
    CellLife l(g, 3, 5);
    int idx = l.getIdx_(2, 4);
    ASSERT_EQ(idx, 14); 
}
TEST(Life, getIdx3)
{
    CellLife::GridT g;
    CellLife l(g, 3, 3);
    int idx = l.getIdx_(2, 2);
    ASSERT_EQ(idx, 8); 
}
TEST(Life, getIdxNonSquare)
{
    ConwayLife::GridT grid;
    int r = 3;
    int c = 2;
    /* ..
       ..
       **

    */
    grid.push_back(ConwayCell(true));
    grid.push_back(ConwayCell(true));

    grid.push_back(ConwayCell(true));
    grid.push_back(ConwayCell(true));

    grid.push_back(ConwayCell(false));
    grid.push_back(ConwayCell(false));
    ConwayLife l(grid, r, c);
    ASSERT_EQ(l.getIdx_(2, 1), 5); 


}


TEST(Life, construct_cell)
{
    CellLife::GridT grid;
    int r = 3;
    int c = 3;
    /* ---
       -0-
       ---
    */
    grid.push_back(Cell(new FredkinCell(0, true)));
    grid.push_back(Cell(new FredkinCell(0, true)));
    grid.push_back(Cell(new FredkinCell(0, true)));

    grid.push_back(Cell(new FredkinCell(0, true)));
    grid.push_back(Cell(new FredkinCell(0, false)));
    grid.push_back(Cell(new FredkinCell(0, true)));

    grid.push_back(Cell(new FredkinCell(0, true)));
    grid.push_back(Cell(new FredkinCell(0, true)));
    grid.push_back(Cell(new FredkinCell(0, true)));

    CellLife l(grid, r, c);
    std::stringstream ss; 
    l.print(ss);
    std::string initial("Generation = 0, Population = 1.\n---\n-0-\n---\n");

    ASSERT_TRUE(ss.str() == initial); 
}

TEST(Life, construct_ConwayCell)
{
    ConwayLife::GridT grid;
    int r = 3;
    int c = 3;
    /* ***
       *.*
       ***
    */
    grid.push_back(ConwayCell(false));
    grid.push_back(ConwayCell(false));
    grid.push_back(ConwayCell(false));

    grid.push_back(ConwayCell(false));
    grid.push_back(ConwayCell(true));
    grid.push_back(ConwayCell(false));

    grid.push_back(ConwayCell(false));
    grid.push_back(ConwayCell(false));
    grid.push_back(ConwayCell(false));

    ConwayLife l(grid, r, c);
    std::stringstream ss; 
    l.print(ss);
    std::string initial("Generation = 0, Population = 8.\n***\n*.*\n***\n");

    ASSERT_TRUE(ss.str() == initial); 
}

TEST(Life, construct_FredkinCell)
{
    FredkinLife::GridT grid;
    int r = 3;
    int c = 3;
    /* ---
       -5-
       ---
    */
    grid.push_back(FredkinCell(0, true));
    grid.push_back(FredkinCell(0, true));
    grid.push_back(FredkinCell(0, true));

    grid.push_back(FredkinCell(0, true));
    grid.push_back(FredkinCell(5, false));
    grid.push_back(FredkinCell(0, true));

    grid.push_back(FredkinCell(0, true));
    grid.push_back(FredkinCell(0, true));
    grid.push_back(FredkinCell(0, true));

    FredkinLife l(grid, r, c);
    std::stringstream ss; 
    l.print(ss);
    std::string initial("Generation = 0, Population = 1.\n---\n-5-\n---\n");

    ASSERT_TRUE(ss.str() == initial); 
}

// --- getAlive
TEST(Life, getAlive1)
{
    ConwayLife::GridT grid;
    int r = 3;
    int c = 3;
    /* ***
       ***
       ***
    */
    grid.push_back(ConwayCell(false));
    grid.push_back(ConwayCell(false));
    grid.push_back(ConwayCell(false));

    grid.push_back(ConwayCell(false));
    grid.push_back(ConwayCell(false));
    grid.push_back(ConwayCell(false));

    grid.push_back(ConwayCell(false));
    grid.push_back(ConwayCell(false));
    grid.push_back(ConwayCell(false));

    ConwayLife l(grid, r, c);
    ASSERT_TRUE(l.countAlive_(0) == 1); 
}

TEST(Life, getAlive2)
{
    ConwayLife::GridT grid;
    int r = 1;
    int c = 1;
    // one dead cell. 
    grid.push_back(ConwayCell(true));

    ConwayLife l(grid, r, c);
    ASSERT_TRUE(l.countAlive_(0) == 0); 
}

TEST(Life, getAlive3)
{
    ConwayLife::GridT grid;
    int r = 1;
    int c = 1;
    // one dead cell. 
    grid.push_back(ConwayCell(true));

    ConwayLife l(grid, r, c);
    ASSERT_TRUE(l.countAlive_(-5) == 0); 
}


// --- getAliveAdj
TEST(Life, getAliveAdj1)
{
    ConwayLife::GridT grid;
    int r = 3;
    int c = 3;
    /* ***
       *.*
       ***
    */
    grid.push_back(ConwayCell(false));
    grid.push_back(ConwayCell(false));
    grid.push_back(ConwayCell(false));

    grid.push_back(ConwayCell(false));
    grid.push_back(ConwayCell(true));
    grid.push_back(ConwayCell(false));

    grid.push_back(ConwayCell(false));
    grid.push_back(ConwayCell(false));
    grid.push_back(ConwayCell(false));

    ConwayLife l(grid, r, c);
    uint32_t count = l.countAliveAdjacents_(1, 1); 
    ASSERT_TRUE(count == 4); 
}
TEST(Life, getAliveAdj2)
{
    ConwayLife::GridT grid;
    int r = 3;
    int c = 3;
    /* ***
       *.*
       ***
    */
    grid.push_back(ConwayCell(false));
    grid.push_back(ConwayCell(false));
    grid.push_back(ConwayCell(false));

    grid.push_back(ConwayCell(false));
    grid.push_back(ConwayCell(true));
    grid.push_back(ConwayCell(false));

    grid.push_back(ConwayCell(false));
    grid.push_back(ConwayCell(false));
    grid.push_back(ConwayCell(false));

    ConwayLife l(grid, r, c);
    ASSERT_TRUE(l.countAliveAdjacents_(0,0) == 2); 
}
TEST(Life, getAliveAdj3)
{
    ConwayLife::GridT grid;
    int r = 3;
    int c = 3;
    /* ***
       *.*
       ***
    */
    grid.push_back(ConwayCell(false));
    grid.push_back(ConwayCell(false));
    grid.push_back(ConwayCell(false));

    grid.push_back(ConwayCell(false));
    grid.push_back(ConwayCell(true));
    grid.push_back(ConwayCell(false));

    grid.push_back(ConwayCell(false));
    grid.push_back(ConwayCell(false));
    grid.push_back(ConwayCell(false));

    ConwayLife l(grid, r, c);
    ASSERT_TRUE(l.countAliveAdjacents_(1,2) == 2); 
}

// --- getAliveDiagonals
TEST(Life, getAliveDiagonals1)
{
    ConwayLife::GridT grid;
    int r = 3;
    int c = 3;
    /* ***
       *.*
       ***
    */
    grid.push_back(ConwayCell(false));
    grid.push_back(ConwayCell(false));
    grid.push_back(ConwayCell(false));

    grid.push_back(ConwayCell(false));
    grid.push_back(ConwayCell(true));
    grid.push_back(ConwayCell(false));

    grid.push_back(ConwayCell(false));
    grid.push_back(ConwayCell(false));
    grid.push_back(ConwayCell(false));

    ConwayLife l(grid, r, c);
    uint32_t count = l.countAliveDiagonals_(1, 1); 
    ASSERT_TRUE(count == 4); 
}
TEST(Life, getAliveDiagonals2)
{
    ConwayLife::GridT grid;
    int r = 3;
    int c = 3;
    /* ***
       *.*
       ***
    */
    grid.push_back(ConwayCell(false));
    grid.push_back(ConwayCell(false));
    grid.push_back(ConwayCell(false));

    grid.push_back(ConwayCell(false));
    grid.push_back(ConwayCell(true));
    grid.push_back(ConwayCell(false));

    grid.push_back(ConwayCell(false));
    grid.push_back(ConwayCell(false));
    grid.push_back(ConwayCell(false));

    ConwayLife l(grid, r, c);

    ASSERT_EQ(l.countAliveDiagonals_(0,0), 0);
    
}
TEST(Life, getAliveDiagonals3)
{
    ConwayLife::GridT grid;
    int r = 3;
    int c = 3;
    /* ***
       *.*
       ***
    */
    grid.push_back(ConwayCell(false));
    grid.push_back(ConwayCell(false));
    grid.push_back(ConwayCell(false));

    grid.push_back(ConwayCell(false));
    grid.push_back(ConwayCell(true));
    grid.push_back(ConwayCell(false));

    grid.push_back(ConwayCell(false));
    grid.push_back(ConwayCell(false));
    grid.push_back(ConwayCell(false));

    ConwayLife l(grid, r, c);
    ASSERT_TRUE(l.countAliveDiagonals_(2,2) == 0);
    ASSERT_TRUE(l.countAliveDiagonals_(2,0) == 0);
    ASSERT_TRUE(l.countAliveDiagonals_(1,0) == 2);
    ASSERT_TRUE(l.countAliveDiagonals_(2,1) == 2); 
}

// --- life run
TEST(Life, run1)
{
    ConwayLife::GridT grid;
    int r = 3;
    int c = 3;
    /* ...
       ...
       ***

       run once should be
       ...
       .*.
       ***
    */
    grid.push_back(ConwayCell(true));
    grid.push_back(ConwayCell(true));
    grid.push_back(ConwayCell(true));

    grid.push_back(ConwayCell(true));
    grid.push_back(ConwayCell(true));
    grid.push_back(ConwayCell(true));

    grid.push_back(ConwayCell(false));
    grid.push_back(ConwayCell(false));
    grid.push_back(ConwayCell(false));

    ConwayLife l(grid, r, c);
    ASSERT_EQ(l.num_alive_, 3);
    ASSERT_EQ(l.getIdx_(1,0), 3);
    ASSERT_TRUE(l.grid_[2].isAlive() == false);
    // l.print(std::cout);
    l.run(1);
    ASSERT_EQ(l.num_alive_, 2); 
    ASSERT_TRUE(l.countAlive_(l.getIdx_(1,1)) == 1);
}

TEST(Life, run2)
{
    FredkinLife::GridT grid;
    int r = 3;
    int c = 3;
    /* ...
       ...
       000

       run once should be
       ---
       000
       1-1
       
    */
    grid.push_back(FredkinCell(0, true));
    grid.push_back(FredkinCell(0, true));
    grid.push_back(FredkinCell(0, true));

    grid.push_back(FredkinCell(0, true));
    grid.push_back(FredkinCell(0, true));
    grid.push_back(FredkinCell(0, true));

    grid.push_back(FredkinCell(0, false));
    grid.push_back(FredkinCell(0, false));
    grid.push_back(FredkinCell(0, false));

    FredkinLife l(grid, r, c);
    ASSERT_EQ(l.num_alive_, 3);
    ASSERT_EQ(l.getIdx_(1,0), 3);
    ASSERT_TRUE(l.grid_[2].isAlive() == false);
    l.run(1);
    std::stringstream ss; 
    l.print(ss);
    std::string expected("Generation = 1, Population = 5.\n---\n000\n1-1\n");
    ASSERT_EQ(ss.str(), expected); 
    ASSERT_TRUE(l.countAlive_(l.getIdx_(1,1)) == 1);
}

TEST(Life, run3)
{
    CellLife::GridT grid;
    int r = 3;
    int c = 3;
    /* ---
       ---
       111

       run once should be
       ---
       000
       *-*
    */
    grid.push_back(new FredkinCell(0, true));
    grid.push_back(new FredkinCell(0, true));
    grid.push_back(new FredkinCell(0, true));

    grid.push_back(new FredkinCell(0, true));
    grid.push_back(new FredkinCell(0, true));
    grid.push_back(new FredkinCell(0, true));

    grid.push_back(new FredkinCell(1, false));
    grid.push_back(new FredkinCell(1, false));
    grid.push_back(new FredkinCell(1, false));

    CellLife l(grid, r, c);
    ASSERT_EQ(l.num_alive_, 3);
    ASSERT_EQ(l.getIdx_(1,0), 3);
    ASSERT_TRUE(l.grid_[2].isAlive() == false);
    l.run(1);
    std::stringstream ss; 
    l.print(ss);
    std::string expected("Generation = 1, Population = 5.\n---\n000\n*-*\n");
    ASSERT_EQ(ss.str(), expected); 
    ASSERT_TRUE(l.countAlive_(l.getIdx_(1,1)) == 1);
}

// ---- Life printing 
TEST(Life, print1)
{
    ConwayLife::GridT grid;
    int r = 3;
    int c = 2;
    /* ..
       ..
       **

    */
    grid.push_back(ConwayCell(true));
    grid.push_back(ConwayCell(true));

    grid.push_back(ConwayCell(true));
    grid.push_back(ConwayCell(true));

    grid.push_back(ConwayCell(false));
    grid.push_back(ConwayCell(false));

    ConwayLife l(grid, r, c);
    std::stringstream ss; 
    l.print(ss); 
    std::string expect("Generation = 0, Population = 2.\n..\n..\n**\n");
    EXPECT_EQ(ss.str(), expect);
}

// ---- Life printing 
TEST(Life, print2)
{
    FredkinLife::GridT grid;
    int r = 3;
    int c = 2;
    /* --
       --
       44

    */
    grid.push_back(FredkinCell(0, true));
    grid.push_back(FredkinCell(0, true));

    grid.push_back(FredkinCell(0, true));
    grid.push_back(FredkinCell(0, true));

    grid.push_back(FredkinCell(4, false));
    grid.push_back(FredkinCell(4, false));

    FredkinLife l(grid, r, c);
    std::stringstream ss; 
    l.print(ss); 
    std::string expect("Generation = 0, Population = 2.\n--\n--\n44\n");
    EXPECT_EQ(ss.str(), expect);
}

TEST(Life, print3)
{
    CellLife::GridT grid;
    int r = 3;
    int c = 2;
    /* --
       -*
       44

    */
    grid.push_back(new FredkinCell(0, true));
    grid.push_back(new FredkinCell(0, true));

    grid.push_back(new FredkinCell(0, true));
    grid.push_back(new ConwayCell(false));

    grid.push_back(new FredkinCell(4, false));
    grid.push_back(new FredkinCell(4, false));

    CellLife l(grid, r, c);
    std::stringstream ss; 
    l.print(ss); 
    std::string expect("Generation = 0, Population = 3.\n--\n-*\n44\n");
    EXPECT_EQ(ss.str(), expect);
}

// --- Test ConwayCell
// Construct..done
// Copy construct..done
// clone .. done 
// isAlive .. done 
// prep .. done 
// update .. done 
// draw .. done 
TEST(ConwayCell, construct1)
{
    ConwayCell c(false);
    ASSERT_EQ(c.dead_, false); 
}
TEST(ConwayCell, construct2)
{
    ConwayCell c(true);
    ASSERT_EQ(c.dead_, true); 
}


TEST(ConwayCell, copy_construct1)
{
    ConwayCell c(false);
    ConwayCell copy(c);
    ASSERT_EQ(copy.dead_, false); 
}
TEST(ConwayCell, copy_construct2)
{
    ConwayCell c(true);
    ConwayCell copy(c); 
    ASSERT_EQ(copy.dead_, true); 
}
TEST(ConwayCell, copy_construct3)
{
    ConwayCell c(true);
    ConwayCell copy(c);
    ConwayCell copy2(copy); 
    ASSERT_EQ(copy.dead_, true);
}
// -- clone 
TEST(ConwayCell, clone_construct1)
{
    ConwayCell c(true);
    ConwayCell* copy = c.clone();
    ASSERT_EQ(copy->dead_, true);
    delete copy; 

}
TEST(ConwayCell, clone_construct2)
{
    ConwayCell c(false);
    ConwayCell* copy = c.clone();
    ASSERT_EQ(copy->dead_, false);
    delete copy;
}
TEST(ConwayCell, clone_construct3)
{
    ConwayCell c(false);
    ConwayCell c2(c);
    ConwayCell* c3 = c2.clone();
    ASSERT_EQ(c3->dead_, false);
    delete c3;
}

// -- is alive 
TEST(ConwayCell, conwayIsAlive1)
{
    ConwayCell c(true);
    ASSERT_EQ(c.isAlive(), false);

}
TEST(ConwayCell, conwayIsAlive2)
{
    ConwayCell c(false);
    ASSERT_EQ(c.isAlive(), true); 
}
TEST(ConwayCell, conwayIsAlive3)
{
    ConwayCell c(false);
    ConwayCell c2(c);
    ASSERT_EQ(c2.dead_, !c2.isAlive());
}

// -- prep
TEST(ConwayCell, conwayPrep1)
{
    ConwayCell c(true);
    c.prep(2, 3);
    ASSERT_EQ(c.diag_cnt_, 2);
    ASSERT_EQ(c.adj_cnt_, 3); 

}
TEST(ConwayCell, conwayPrep2)
{
    ConwayCell c(false);
    c.prep(4, 3);
    ASSERT_EQ(c.diag_cnt_, 4);
    ASSERT_EQ(c.adj_cnt_, 3); 
}
TEST(ConwayCell, conwayPrep3)
{
    ConwayCell c(false);
    c.prep(1,1); 
    ASSERT_EQ(c.adj_cnt_ + c.diag_cnt_, 2); 
}

// -- update
TEST(ConwayCell, conwayUpdate1)
{
    ConwayCell c(true);
    c.prep(0, 3);
    ASSERT_EQ(c.dead_, true);
    c.update(); 
    ASSERT_EQ(c.dead_, false);
}

TEST(ConwayCell, conwayUpdate2)
{
    ConwayCell c(true);
    c.prep(1, 2);
    ASSERT_EQ(c.dead_, true);
    c.update(); 
    ASSERT_EQ(c.dead_, false);
}
TEST(ConwayCell, conwayUpdate3)
{
    ConwayCell c(false);
    c.prep(1,3); 
    ASSERT_EQ(c.dead_, false);
    c.update(); 
    ASSERT_EQ(c.dead_, true);
}
TEST(ConwayCell, conwayUpdate4)
{
    ConwayCell c(false);
    c.prep(0,1); 
    ASSERT_EQ(c.dead_, false);
    c.update(); 
    ASSERT_EQ(c.dead_, true);
}
TEST(ConwayCell, conwayUpdate5)
{
    ConwayCell c(false);
    c.prep(0,0); 
    ASSERT_EQ(c.dead_, false);
    c.update(); 
    ASSERT_EQ(c.dead_, true);
}
TEST(ConwayCell, conwayUpdate6)
{
    ConwayCell c(false);
    c.prep(2,2); 
    ASSERT_EQ(c.dead_, false);
    c.update(); 
    ASSERT_EQ(c.dead_, true);
}

// draw
TEST(ConwayCell, conwayDraw1)
{
    ConwayCell c(true);
    std::stringstream ss;
    c.draw(ss);
    ASSERT_EQ(ss.str(), "."); 

}
TEST(ConwayCell, conwayDraw2)
{
    ConwayCell c(false);
    std::stringstream ss;
    c.draw(ss);
    ASSERT_EQ(ss.str(), "*"); 

}
TEST(ConwayCell, conwayDraw3)
{
    ConwayCell c(false);
    ConwayCell c2(c);
    std::stringstream ss;
    c.draw(ss);
    ASSERT_EQ(ss.str(), "*"); 
}



// --- Test FredkinCell
// Construct..done
// Copy construct..done
// clone .. done 
// isAlive .. done 
// prep .. done 
// update .. done 
// draw .. done 
TEST(FredkinCell, construct1)
{
    FredkinCell c(0, false);
    ASSERT_EQ(c.dead_, false); 
}
TEST(FredkinCell, construct2)
{
    FredkinCell c(0, true);
    ASSERT_EQ(c.dead_, true); 
}


TEST(FredkinCell, copy_construct1)
{
    FredkinCell c(0, false);
    FredkinCell copy(c);
    ASSERT_EQ(copy.dead_, false);
    ASSERT_EQ(copy.age_, 0); 
}
TEST(FredkinCell, copy_construct2)
{
    FredkinCell c(0, true);
    FredkinCell copy(c);
    ASSERT_EQ(copy.age_, 0); 
    ASSERT_EQ(copy.dead_, true); 
}
TEST(FredkinCell, copy_construct3)
{
    FredkinCell c(0, true);
    FredkinCell copy(c);
    FredkinCell copy2(copy);
    ASSERT_EQ(copy2.age_, 0); 
    ASSERT_EQ(copy.dead_, true);
}
// -- clone 
TEST(FredkinCell, clone_construct1)
{
    FredkinCell c(0, true);
    FredkinCell* copy = c.clone();
    ASSERT_EQ(copy->dead_, true);
    delete copy; 

}
TEST(FredkinCell, clone_construct2)
{
    FredkinCell c(0, false);
    FredkinCell* copy = c.clone();
    ASSERT_EQ(copy->dead_, false);
    delete copy;
}
TEST(FredkinCell, clone_construct3)
{
    FredkinCell c(0, false);
    FredkinCell c2(c);
    FredkinCell* c3 = c2.clone();
    ASSERT_EQ(c3->dead_, false);
    delete c3;
}

// -- is alive 
TEST(FredkinCell, FredkinIsAlive1)
{
    FredkinCell c(0, true);
    ASSERT_EQ(c.isAlive(), false);

}
TEST(FredkinCell, FredkinIsAlive2)
{
    FredkinCell c(0, false);
    ASSERT_EQ(c.isAlive(), true); 
}
TEST(FredkinCell, FredkinIsAlive3)
{
    FredkinCell c(0, false);
    FredkinCell c2(c);
    ASSERT_EQ(c2.dead_, !c2.isAlive());
}

// -- prep
TEST(FredkinCell, FredkinPrep1)
{
    FredkinCell c(0, true);
    c.prep(2, 3);
    ASSERT_EQ(c.adj_cnt_, 3); 

}
TEST(FredkinCell, FredkinPrep2)
{
    FredkinCell c(0, false);
    c.prep(4, 3);
    ASSERT_EQ(c.adj_cnt_, 3); 
}
TEST(FredkinCell, FredkinPrep3)
{
    FredkinCell c(0, false);
    c.prep(1,1); 
    ASSERT_EQ(c.adj_cnt_ , 1); 
}

// -- update
TEST(FredkinCell, FredkinUpdate1)
{
    FredkinCell c(0, true);
    c.prep(0, 3);
    ASSERT_EQ(c.dead_, true);
    c.update(); 
    ASSERT_EQ(c.dead_, false);
}

TEST(FredkinCell, FredkinUpdate2)
{
    FredkinCell c(0, true);
    c.prep(1, 3);
    ASSERT_EQ(c.dead_, true);
    c.update(); 
    ASSERT_EQ(c.dead_, false);
    ASSERT_EQ(c.age_, 0); 
}
TEST(FredkinCell, FredkinUpdate3)
{
    FredkinCell c(0, false);
    c.prep(1,3); 
    ASSERT_EQ(c.dead_, false);
    c.update(); 
    ASSERT_EQ(c.dead_, false);
    ASSERT_EQ(c.age_, 1); 
}
TEST(FredkinCell, FredkinUpdate4)
{
    FredkinCell c(0, false);
    c.prep(0,2); 
    ASSERT_EQ(c.dead_, false);
    c.update(); 
    ASSERT_EQ(c.dead_, true);
    ASSERT_EQ(c.age_, 0); 
}
TEST(FredkinCell, FredkinUpdate5)
{
    FredkinCell c(0, false);
    c.prep(0,4); 
    ASSERT_EQ(c.dead_, false);
    c.update();
    ASSERT_EQ(c.age_, 0); 
    ASSERT_EQ(c.dead_, true);
}
TEST(FredkinCell, FredkinUpdate6)
{
    FredkinCell c(0, false);
    c.prep(2,0); 
    ASSERT_EQ(c.dead_, false);
    c.update();
    ASSERT_EQ(c.age_, 0); 
    ASSERT_EQ(c.dead_, true);
}

// draw
TEST(FredkinCell, FredkinDraw1)
{
    FredkinCell c(0, true);
    std::stringstream ss;
    c.draw(ss);
    ASSERT_EQ(ss.str(), "-"); 

}
TEST(FredkinCell, FredkinDraw2)
{
    FredkinCell c(0, false);
    std::stringstream ss;
    c.draw(ss);
    ASSERT_EQ(ss.str(), "0"); 

}
TEST(FredkinCell, FredkinDraw3)
{
    FredkinCell c(11, false);
    FredkinCell c2(c);
    std::stringstream ss;
    c.draw(ss);
    ASSERT_EQ(ss.str(), "+"); 
}



// --- Test Cell
// Construct..done
// Copy construct..done
// mutate .. done 
// isAlive .. done 
// prep .. done 
// update .. done 
// draw .. done 
TEST(Cell, construct1)
{
    Cell c(new FredkinCell(0, false));
    ASSERT_EQ(!c.isAlive(), false); 
}
TEST(Cell, construct2)
{
    Cell c(new FredkinCell(0, true));
    ASSERT_EQ(!c.isAlive(), true); 
}

TEST(Cell, copy_construct1)
{
    Cell c(new FredkinCell(0, false));
    Cell copy(c);
    ASSERT_EQ(copy.isAlive(), true);
}
// -- clone 
TEST(Cell, mutate1)
{
    Cell c(new FredkinCell(0, true));
    c.mutate(new ConwayCell(false)); 
    ASSERT_EQ(c.isAlive(), true);
}
TEST(Cell, mutate2)
{
    Cell c(new ConwayCell(true)); 
    c.mutate(new FredkinCell(0, false)); 
    ASSERT_EQ(c.isAlive(), true);
}
TEST(Cell, mutate3)
{
    Cell c(new FredkinCell(0, false));
    c.mutate(new FredkinCell(0, false)); 
    ASSERT_EQ(c.isAlive(), true);
}

// -- is alive 
TEST(Cell, FredkinIsAlive1)
{
    Cell c(new FredkinCell(0, true));
    ASSERT_EQ(c.isAlive(), false);

}

TEST(Cell, FredkinIsAlive2)
{
    Cell c(new FredkinCell(0, false));
    ASSERT_EQ(c.isAlive(), true); 
}
TEST(Cell, FredkinIsAlive3)
{
    Cell c(new FredkinCell(0, false));
    Cell c2(c);
    ASSERT_EQ(c2.isAlive(), c.isAlive());
}

// -- prep
TEST(Cell, FredkinPrep1)
{
    Cell c(new FredkinCell(0, true));
    c.prep(2, 3);
    // there is no way to test the prep.
    ASSERT_EQ(static_cast<FredkinCell*>(c.handle_.get())->adj_cnt_, 3);
}

TEST(Cell, FredkinPrep2)
{
    Cell c(new FredkinCell(0, true));
    c.prep(2, 0);
    // there is no way to test the prep.
    ASSERT_EQ(static_cast<FredkinCell*>(c.handle_.get())->adj_cnt_, 0);
 
}
TEST(Cell, FredkinPrep3)
{
    Cell c(new FredkinCell(0, true));
    c.prep(2, 1);
    // there is no way to test the prep.
    ASSERT_EQ(static_cast<FredkinCell*>(c.handle_.get())->adj_cnt_, 1);

}

// -- update
TEST(Cell, FredkinUpdate1)
{
    Cell c(new FredkinCell(1, false));
    c.prep(0, 1);
    c.update();
    // since age went to 2, it becomes a conway cell.
    ASSERT_TRUE(dynamic_cast<ConwayCell*>(c.handle_.get()) != NULL); 
}

TEST(Cell, FredkinUpdate2)
{
    Cell c(new FredkinCell(0, false));
    c.prep(0, 1);
    c.update();
    // We didn't mutate
    ASSERT_TRUE(dynamic_cast<ConwayCell*>(c.handle_.get()) == NULL);
    c.update();
    // our age mutated us.
    ASSERT_TRUE(dynamic_cast<ConwayCell*>(c.handle_.get()) != NULL);
}

TEST(Cell, FredkinUpdate3)
{
    Cell c(new ConwayCell(false));
    c.prep(0, 1);
    c.update();
    // We didn't mutate
    ASSERT_EQ(c.isAlive(), false); 
}

// draw
TEST(Cell, FredkinDraw1)
{
    Cell c(new FredkinCell(0, true));
    std::stringstream ss;
    c.draw(ss);
    ASSERT_EQ(ss.str(), "-"); 

}
TEST(Cell, FredkinDraw2)
{
    Cell c(new FredkinCell(0, false));
    std::stringstream ss;
    c.draw(ss);
    ASSERT_EQ(ss.str(), "0"); 

}
TEST(Cell, FredkinDraw3)
{
    Cell c(new FredkinCell(11, false));
    std::stringstream ss;
    c.draw(ss);
    ASSERT_EQ(ss.str(), "+"); 
}

TEST(Cell, FredkinDraw4)
{
    Cell c(new ConwayCell(false));
    std::stringstream ss;
    c.draw(ss);
    ASSERT_EQ(ss.str(), "*"); 
}
TEST(Cell, FredkinDraw5)
{
    Cell c(new ConwayCell(true));
    std::stringstream ss;
    c.draw(ss);
    ASSERT_EQ(ss.str(), "."); 
}

