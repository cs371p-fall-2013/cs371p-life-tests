// --------------------------------
// projects/life/TestLife.c++
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

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==
#include "gtest/gtest.h"
#include <fstream>   // file reading
#include "Life.h"

    using namespace std;

// -----------
// TestLife
// -----------

// ----
// Life
// ----

TEST(Life, Life) {
    Life<ConwayCell> li;
    ASSERT_EQ(li.getRow(), 0);
    ASSERT_EQ(li.getColumn(), 0);
    ASSERT_EQ(li.getPopulation(), 0);

    istringstream r("3\n3\n...\n.*.\n...\n");
    li.setSize(r);
    li.populateEnvironment(r);

    ASSERT_EQ(li.getRow(), 3);
    ASSERT_EQ(li.getColumn(), 3);
}

TEST(Life, Life1) {
    Life<ConwayCell> li;
    ASSERT_EQ(li.getRow(), 0);
    ASSERT_EQ(li.getColumn(), 0);
    ASSERT_EQ(li.getPopulation(), 0);
    istringstream r("3\n3\n...\n.*.\n...\n");
    li.setSize(r);
    ASSERT_EQ(li.getRow(), 3);
    ASSERT_EQ(li.getColumn(), 3);
}


TEST(Life, ConwayCell) {
    ConwayCell c;
    ASSERT_TRUE(c.getType()  == '.');
}


TEST(Life, Fredkin) {
    FredkinCell c;
    ASSERT_TRUE(c.getType()  == '-');

}

TEST(Life, Cell) {
    Cell c;
    ASSERT_TRUE(c.getType()  == '-');
}




// ----
// setSize
// ----
TEST(Life, setSize) {
    Life<ConwayCell> li;
    ASSERT_EQ(li.getRow(), 0);
    ASSERT_EQ(li.getColumn(), 0);
    ASSERT_EQ(li.getPopulation(), 0);
    istringstream r("3\n3\n...\n.*.\n...\n");
    li.setSize(r);
    ASSERT_EQ(li.getRow(), 3);
    ASSERT_EQ(li.getColumn(), 3);
}

TEST(Life, setSize1) {
    Life<ConwayCell> li;
    ASSERT_EQ(li.getRow(), 0);
    ASSERT_EQ(li.getColumn(), 0);
    ASSERT_EQ(li.getPopulation(), 0);
    istringstream r("9\n20\n");
    li.setSize(r);
    ASSERT_EQ(li.getRow(), 9);
    ASSERT_EQ(li.getColumn(), 20);
}

TEST(Life, setSize2) {
    Life<ConwayCell> li;
    ASSERT_EQ(li.getRow(), 0);
    ASSERT_EQ(li.getColumn(), 0);
    ASSERT_EQ(li.getPopulation(), 0);
    istringstream r("0\n0\n");
    li.setSize(r);
    ASSERT_EQ(li.getRow(), 0);
    ASSERT_EQ(li.getColumn(), 0);
}




// ----
// populateEnvironment
// ----

TEST(Life, populateEnvironment) {
    Life<ConwayCell> li;
    std::istringstream r1("3\n3\n");
    li.setSize(r1);
    std::istringstream r2("...\n.*.\n...\n");
    li.populateEnvironment(r2);


    ASSERT_EQ(li.getCell(0, 0).getType(), '.');
    ASSERT_EQ(li.getCell(0, 1).getType(), '.');
    ASSERT_EQ(li.getCell(0, 2).getType(), '.');

    ASSERT_EQ(li.getCell(1, 0).getType(), '.');
    ASSERT_EQ(li.getCell(1, 1).getType(), '*');
    ASSERT_EQ(li.getCell(1, 2).getType(), '.');

    ASSERT_EQ(li.getCell(2, 0).getType(), '.');
    ASSERT_EQ(li.getCell(2, 1).getType(), '.');
    ASSERT_EQ(li.getCell(2, 2).getType(), '.');

}

TEST(Life, populateEnvironment1) {
    Life<ConwayCell> li;

    std::istringstream r("4\n3\n...\n.*.\n*..\n..*\n");
    li.setSize(r);
    li.populateEnvironment(r);

    ASSERT_EQ(li.getCell(0, 0).getType(), '.');
    ASSERT_EQ(li.getCell(0, 1).getType(), '.');
    ASSERT_EQ(li.getCell(0, 2).getType(), '.');

    ASSERT_EQ(li.getCell(1, 0).getType(), '.');
    ASSERT_EQ(li.getCell(1, 1).getType(), '*');
    ASSERT_EQ(li.getCell(1, 2).getType(), '.');

    ASSERT_EQ(li.getCell(2, 0).getType(), '*');
    ASSERT_EQ(li.getCell(2, 1).getType(), '.');
    ASSERT_EQ(li.getCell(2, 2).getType(), '.');

    ASSERT_EQ(li.getCell(3, 0).getType(), '.');
    ASSERT_EQ(li.getCell(3, 1).getType(), '.');
    ASSERT_EQ(li.getCell(3, 2).getType(), '*');
}

TEST(Life, populateEnvironment2) {
    Life<Cell> li;
    std::istringstream r("3\n3\n---\n---\n-0-\n");
    li.setSize(r);
    li.populateEnvironment(r);

    ASSERT_EQ(li.getCell(0, 0).getType(), '-');
    ASSERT_EQ(li.getCell(0, 1).getType(), '-');
    ASSERT_EQ(li.getCell(0, 2).getType(), '-');

    ASSERT_EQ(li.getCell(1, 0).getType(), '-');
    ASSERT_EQ(li.getCell(1, 1).getType(), '-');
    ASSERT_EQ(li.getCell(1, 2).getType(), '-');

    ASSERT_EQ(li.getCell(2, 0).getType(), '-');
    ASSERT_EQ(li.getCell(2, 1).getType(), '0');
    ASSERT_EQ(li.getCell(2, 2).getType(), '-');
}

TEST(Life, populateEnvironment3) {
    Life<FredkinCell> li;
    std::istringstream r("4\n3\n---\n---\n-0-\n--0");
    li.setSize(r);
    li.populateEnvironment(r);

    ASSERT_EQ(li.getCell(0, 0).getType(), '-');
    ASSERT_EQ(li.getCell(0, 1).getType(), '-');
    ASSERT_EQ(li.getCell(0, 2).getType(), '-');

    ASSERT_EQ(li.getCell(1, 0).getType(), '-');
    ASSERT_EQ(li.getCell(1, 1).getType(), '-');
    ASSERT_EQ(li.getCell(1, 2).getType(), '-');

    ASSERT_EQ(li.getCell(2, 0).getType(), '-');
    ASSERT_EQ(li.getCell(2, 1).getType(), '0');
    ASSERT_EQ(li.getCell(2, 2).getType(), '-');

    ASSERT_EQ(li.getCell(3, 0).getType(), '-');
    ASSERT_EQ(li.getCell(3, 1).getType(), '-');
    ASSERT_EQ(li.getCell(3, 2).getType(), '0');
}

// ----
// countNeighbors
// ----

TEST(Life, countNeighbors) {
    Life<ConwayCell> li;
    std::istringstream r("3\n3\n...\n.*.\n...\n");
    li.setSize(r);
    li.populateEnvironment(r);
    li.countNeighbors();

    ASSERT_EQ(li.getCell(0, 0).getNeighbors(), 1);
    ASSERT_EQ(li.getCell(0, 1).getNeighbors(), 1);
    ASSERT_EQ(li.getCell(0, 2).getNeighbors(), 1);

    ASSERT_EQ(li.getCell(1, 0).getNeighbors(), 1);
    ASSERT_EQ(li.getCell(1, 1).getNeighbors(), 0);
    ASSERT_EQ(li.getCell(1, 2).getNeighbors(), 1);

    ASSERT_EQ(li.getCell(2, 0).getNeighbors(), 1);
    ASSERT_EQ(li.getCell(2, 1).getNeighbors(), 1);
    ASSERT_EQ(li.getCell(2, 2).getNeighbors(), 1);
}

TEST(Life, countNeighbors1) {
    Life<ConwayCell> li;
    std::istringstream r("3\n3\n...\n.*.\n*..\n");
    li.setSize(r);
    li.populateEnvironment(r);
    li.countNeighbors();

    ASSERT_EQ(li.getCell(0, 0).getNeighbors(), 1);
    ASSERT_EQ(li.getCell(0, 1).getNeighbors(), 1);
    ASSERT_EQ(li.getCell(0, 2).getNeighbors(), 1);

    ASSERT_EQ(li.getCell(1, 0).getNeighbors(), 2);
    ASSERT_EQ(li.getCell(1, 1).getNeighbors(), 1);
    ASSERT_EQ(li.getCell(1, 2).getNeighbors(), 1);


    ASSERT_EQ(li.getCell(2, 0).getNeighbors(), 1);
    ASSERT_EQ(li.getCell(2, 1).getNeighbors(), 2);
    ASSERT_EQ(li.getCell(2, 2).getNeighbors(), 1);
}

TEST(Life, countNeighbors2) {
    Life<ConwayCell> li;
    std::istringstream r("2\n3\n*.*\n.*.\n");
    li.setSize(r);
    li.populateEnvironment(r);
    li.countNeighbors();


    ASSERT_EQ(li.getCell(0, 0).getNeighbors(), 1);
    ASSERT_EQ(li.getCell(0, 1).getNeighbors(), 3);
    ASSERT_EQ(li.getCell(0, 2).getNeighbors(), 1);

    ASSERT_EQ(li.getCell(1, 0).getNeighbors(), 2);
    ASSERT_EQ(li.getCell(1, 1).getNeighbors(), 2);
    ASSERT_EQ(li.getCell(1, 2).getNeighbors(), 2);
}

TEST(Life, countNeighbors3) {
    Life<FredkinCell> li;
    std::istringstream r("3\n3\n-0-\n-0-\n0--\n");
    li.setSize(r);
    li.populateEnvironment(r);
    li.countNeighbors();

    ASSERT_EQ(li.getCell(0, 0).getNeighbors(), 1);
    ASSERT_EQ(li.getCell(0, 1).getNeighbors(), 1);
    ASSERT_EQ(li.getCell(0, 2).getNeighbors(), 1);

    ASSERT_EQ(li.getCell(1, 0).getNeighbors(), 2);
    ASSERT_EQ(li.getCell(1, 1).getNeighbors(), 1);
    ASSERT_EQ(li.getCell(1, 2).getNeighbors(), 1);

    ASSERT_EQ(li.getCell(2, 0).getNeighbors(), 0);
    ASSERT_EQ(li.getCell(2, 1).getNeighbors(), 2);
    ASSERT_EQ(li.getCell(2, 2).getNeighbors(), 0);
}

TEST(Life, countNeighbors4) {
    Life<FredkinCell> li;
    std::istringstream r("3\n3\n-00\n0-0\n-0-\n");
    li.setSize(r);
    li.populateEnvironment(r);
    li.countNeighbors();

    ASSERT_EQ(li.getCell(0, 0).getNeighbors(), 2);
    ASSERT_EQ(li.getCell(0, 1).getNeighbors(), 1);
    ASSERT_EQ(li.getCell(0, 2).getNeighbors(), 2);

    ASSERT_EQ(li.getCell(1, 0).getNeighbors(), 0);
    ASSERT_EQ(li.getCell(1, 1).getNeighbors(), 4);
    ASSERT_EQ(li.getCell(1, 2).getNeighbors(), 1);

    ASSERT_EQ(li.getCell(2, 0).getNeighbors(), 2);
    ASSERT_EQ(li.getCell(2, 1).getNeighbors(), 0);
    ASSERT_EQ(li.getCell(2, 2).getNeighbors(), 2);
}

TEST(Life, countNeighbors5) {
    Life<FredkinCell> li;
    std::istringstream r("3\n2\n0-\n-0\n00\n");
    li.setSize(r);
    li.populateEnvironment(r);
    li.countNeighbors();

    ASSERT_EQ(li.getCell(0, 0).getNeighbors(), 0);
    ASSERT_EQ(li.getCell(0, 1).getNeighbors(), 2);

    ASSERT_EQ(li.getCell(1, 0).getNeighbors(), 3);
    ASSERT_EQ(li.getCell(1, 1).getNeighbors(), 1);

    ASSERT_EQ(li.getCell(2, 0).getNeighbors(), 1);
    ASSERT_EQ(li.getCell(2, 1).getNeighbors(), 2);
}

// -----
// runSimulate
// -----


// -----
// runSimulate
// -----

TEST(Life, countPopulation0) {
     Life<FredkinCell> li;
    std::istringstream r("3\n2\n-\n-0\n00\n");
    li.setSize(r);
    //li.populateEnvironment(r);

    li.countPopulation();
    ASSERT_EQ(li.getPopulation(), 0);

}

TEST(Life, countPopulation) {
     Life<FredkinCell> li;
    std::istringstream r("3\n2\n0-\n-0\n00\n");
    li.setSize(r);
    li.populateEnvironment(r);

    li.countPopulation();
    ASSERT_EQ(li.getPopulation(), 4);

}

TEST(Life, countPopulation1) {
     Life<ConwayCell> li;
    std::istringstream r("3\n2\n*.\n.*\n**\n");
    li.setSize(r);
    li.populateEnvironment(r);

    li.countPopulation();
    ASSERT_EQ(li.getPopulation(), 4);
    
}

TEST(Life, countPopulation2) {
     Life<Cell> li;
    std::istringstream r("3\n2\n0-\n-0\n00\n");
    li.setSize(r);
    li.populateEnvironment(r);

    li.countPopulation();
    ASSERT_EQ(li.getPopulation(), 4);
    
}



TEST(Life, runSimulate1) {
    Life<ConwayCell> li;
    std::istringstream r1("3\n3\n");
    li.setSize(r1);
    std::istringstream r2("...\n.*.\n...\n");
    li.populateEnvironment(r2);
    li.runSimulate();

    ASSERT_EQ(li.getCell(0, 0).getType(), '.');
    ASSERT_EQ(li.getCell(0, 1).getType(), '.');
    ASSERT_EQ(li.getCell(0, 2).getType(), '.');

    ASSERT_EQ(li.getCell(1, 0).getType(), '.');
    ASSERT_EQ(li.getCell(1, 1).getType(), '.');
    ASSERT_EQ(li.getCell(1, 2).getType(), '.');

    ASSERT_EQ(li.getCell(2, 0).getType(), '.');
    ASSERT_EQ(li.getCell(2, 1).getType(), '.');
    ASSERT_EQ(li.getCell(2, 2).getType(), '.');


}

TEST(Life, runSimulate2) {

    Life<FredkinCell> li;
    std::istringstream r("4\n3\n---\n---\n-0-\n--0");
    li.setSize(r);
    li.populateEnvironment(r);
    li.runSimulate();

    ASSERT_EQ(li.getCell(0, 0).getType(), '-');
    ASSERT_EQ(li.getCell(0, 1).getType(), '-');
    ASSERT_EQ(li.getCell(0, 2).getType(), '-');

    ASSERT_EQ(li.getCell(1, 0).getType(), '-');
    ASSERT_EQ(li.getCell(1, 1).getType(), '0');
    ASSERT_EQ(li.getCell(1, 2).getType(), '-');

    ASSERT_EQ(li.getCell(2, 0).getType(), '0');
    ASSERT_EQ(li.getCell(2, 1).getType(), '-');
    ASSERT_EQ(li.getCell(2, 2).getType(), '-');

    ASSERT_EQ(li.getCell(3, 0).getType(), '-');
    ASSERT_EQ(li.getCell(3, 1).getType(), '-');
    ASSERT_EQ(li.getCell(3, 2).getType(), '-');


}

TEST(Life, runSimulate3) {

    Life<Cell> li;
    std::istringstream r("4\n3\n0--\n---\n-0-\n--0");
    li.setSize(r);
    li.populateEnvironment(r);
    li.runSimulate();

    ASSERT_EQ(li.getCell(0, 0).getType(), '-');
    ASSERT_EQ(li.getCell(0, 1).getType(), '0');
    ASSERT_EQ(li.getCell(0, 2).getType(), '-');

    ASSERT_EQ(li.getCell(1, 0).getType(), '0');
    ASSERT_EQ(li.getCell(1, 1).getType(), '0');
    ASSERT_EQ(li.getCell(1, 2).getType(), '-');

    ASSERT_EQ(li.getCell(2, 0).getType(), '0');
    ASSERT_EQ(li.getCell(2, 1).getType(), '-');
    ASSERT_EQ(li.getCell(2, 2).getType(), '-');

    ASSERT_EQ(li.getCell(3, 0).getType(), '-');
    ASSERT_EQ(li.getCell(3, 1).getType(), '-');
    ASSERT_EQ(li.getCell(3, 2).getType(), '-');


}

// -----
// getRow
// -----

TEST(Life, getRow) {
    Life<Cell> li;
    std::istringstream r("3\n2\n0-\n-0\n00\n");
    li.setSize(r);
    li.populateEnvironment(r);

    ASSERT_EQ(li.getRow(), 3);
}

TEST(Life, getRow1) {
    Life<Cell> li;
    std::istringstream r("2\n3\n*.*\n.*.\n");
    li.setSize(r);
    li.populateEnvironment(r);

    ASSERT_EQ(li.getRow(), 2);
}

TEST(Life, getRow2) {
    Life<Cell> li;
    std::istringstream r("4\n3\n...\n.*.\n*..\n..*\n");
    li.setSize(r);
    li.populateEnvironment(r);

    ASSERT_EQ(li.getRow(), 4);
}

// -----
// getColumn
// -----

TEST(Life, getColumn) {
    Life<Cell> li;
    std::istringstream r("3\n2\n0-\n-0\n00\n");
    li.setSize(r);
    li.populateEnvironment(r);

    ASSERT_EQ(li.getColumn(), 2);
}

TEST(Life, getColumn1) {
    Life<Cell> li;
    std::istringstream r("2\n3\n*.*\n.*.\n");
    li.setSize(r);
    li.populateEnvironment(r);

    ASSERT_EQ(li.getColumn(), 3);
}

TEST(Life, getColumn2) {
    Life<Cell> li;
    std::istringstream r("4\n4\n....\n.**.\n*.*.\n.*.*\n");
    li.setSize(r);
    li.populateEnvironment(r);

    ASSERT_EQ(li.getColumn(), 4);
}


// -----
// AbstractCell
// -----

TEST(Life, ConwayCell1) {
    Life<Cell> li;
    std::istringstream r("4\n4\n....\n.**.\n*.*.\n.*.*\n");
    li.setSize(r);
    li.populateEnvironment(r);
    ASSERT_TRUE(li.getPopulation() == 6);

}



 TEST(TestLife, Runsim) {
    istringstream r("3\n3\n-0-\n-00\n--0\n");
    Life<FredkinCell> life;

    life.setSize(r);
    life.populateEnvironment(r);
    ASSERT_TRUE(life.getPopulation() == 4);
    life.runSimulate();
    life.countPopulation();
    ASSERT_TRUE(life.getPopulation() == 4);
 }

 TEST(TestLife, Runsim1) {
    istringstream r("3\n3\n-0-\n-00\n--0\n");
    Life<FredkinCell> life;

    life.setSize(r);
    life.populateEnvironment(r);
    ASSERT_TRUE(life.getPopulation() == 4);
    life.runSimulate();
    life.countPopulation();
    ASSERT_TRUE(life.getPopulation() == 4);
    life.countPopulation();
    life.runSimulate();
    ASSERT_TRUE(life.getPopulation() == 6);
 }
 
    TEST(TestLife, Runsim2) {
    istringstream r("3\n3\n---\n---\n0--\n");
    Life<FredkinCell> life;

    life.setSize(r);
    life.populateEnvironment(r);
    ASSERT_TRUE(life.getPopulation() == 1);
    life.runSimulate();
    life.runSimulate();
    life.runSimulate();
    life.runSimulate();
    life.runSimulate();
    life.countPopulation();
    ASSERT_TRUE(life.getPopulation() == 0);

 }

 TEST(TestLife, Runsim3) {
    istringstream r("3\n3\n.*.\n.**\n.*.\n");
    Life<ConwayCell> life;

    life.setSize(r);
    life.populateEnvironment(r);
    life.countPopulation();
    ASSERT_TRUE(life.getPopulation() == 4);
    life.runSimulate();
    life.countPopulation();
    ASSERT_TRUE(life.getPopulation() == 7);
 } 

  TEST(TestLife, predictFuture) {
    ConwayCell c('*');
    c.predictFuture();
    ASSERT_TRUE(!c.willSurvive());
 } 

   TEST(TestLife, predictFuture1) {
    ConwayCell c('*');
    c.setNeighbors(8);
    c.predictFuture();
    ASSERT_TRUE(!c.willSurvive());
 } 

   TEST(TestLife, predictFuture3) {
    ConwayCell c('*');
    c.setNeighbors(0);
    c.predictFuture();
    ASSERT_TRUE(!c.willSurvive());
 } 

   TEST(TestLife, predictFuture4) {
    ConwayCell c('.');
    c.setNeighbors(3);
    c.predictFuture();
    ASSERT_TRUE(c.willSurvive());
 } 
   TEST(TestLife, predictFuture5) {
    ConwayCell c('.');
    c.setNeighbors(1);
    c.predictFuture();
    ASSERT_TRUE(!c.willSurvive());
 } 

   TEST(TestLife, predictFuture6) {
    ConwayCell c('*');
    c.setNeighbors(8);
    c.predictFuture();
    ASSERT_TRUE(!c.willSurvive());
 } 

   TEST(TestLife, predictFuture7) {
    ConwayCell c('*');
    c.setNeighbors(3);
    c.predictFuture();
    ASSERT_TRUE(c.willSurvive());
 } 

    TEST(TestLife, predictFuture8) {
    FredkinCell c('-');
    c.setNeighbors(1);
    c.predictFuture();
    ASSERT_TRUE(c.willSurvive());
 } 

    TEST(TestLife, predictFuture9) {
    FredkinCell c('-');
    c.setNeighbors(3);
    c.predictFuture();
    ASSERT_TRUE(c.willSurvive());
 } 

     TEST(TestLife, predictFuture10) {
    FredkinCell c('0');
    c.setNeighbors(0);
    c.predictFuture();
    ASSERT_TRUE(!c.willSurvive());
 } 

    TEST(TestLife, predictFuture11) {
    FredkinCell c('0');
    c.setNeighbors(2);
    c.predictFuture();
    ASSERT_TRUE(!c.willSurvive());
 } 

     TEST(TestLife, predictFuture12) {
    FredkinCell c('0');
    c.setNeighbors(4);
    c.predictFuture();
    ASSERT_TRUE(!c.willSurvive());
 } 



    TEST(TestLife, predictFuture13) {
    FredkinCell c('0');
    c.setNeighbors(4);
    c.predictFuture();
    ASSERT_TRUE(!c.willSurvive());
 } 

    TEST(TestLife, evolve) {
    ConwayCell c('.');
    c.setNeighbors(4);
    c.predictFuture();
    c.evolve(false);
    ASSERT_TRUE(!c.isAlive());
 }


    TEST(TestLife, evolve1) {
    ConwayCell c('.');
    c.setNeighbors(2);
    c.predictFuture();
    c.evolve(false);
    ASSERT_TRUE(!c.isAlive());
 }

    TEST(TestLife, evolve2) {
    ConwayCell c('.');
    c.setNeighbors(2);
    c.predictFuture();
    c.evolve(false);
    ASSERT_TRUE(!c.isAlive());
 }

     TEST(TestLife, evolve3) {
    ConwayCell c('.');
    c.setNeighbors(3);
    c.predictFuture();
    c.evolve(false);
    ASSERT_TRUE(c.isAlive());
 }

    TEST(TestLife, evolve4) {
    ConwayCell c('*');
    c.setNeighbors(2);
    c.predictFuture();
    c.evolve(false);
    ASSERT_TRUE(c.isAlive());
 }

     TEST(TestLife, evolve5) {
    ConwayCell c('*');
    c.setNeighbors(1);
    c.predictFuture();
    c.evolve(false);
    ASSERT_TRUE(!c.isAlive());
 }

     TEST(TestLife, evolve6) {
    ConwayCell c('*');
    c.setNeighbors(4);
    c.predictFuture();
    c.evolve(false);
    ASSERT_TRUE(!c.isAlive());
 }

      TEST(TestLife, evolve7) {
    FredkinCell c('-');
    c.setNeighbors(1);
    c.predictFuture();
    c.evolve(false);
    ASSERT_TRUE(c.isAlive());
 }

    TEST(TestLife, evolve8) {
    FredkinCell c('-');
    c.setNeighbors(3);
    c.predictFuture();
    c.evolve(false);
    ASSERT_TRUE(c.isAlive());
 }


    TEST(TestLife, evolve9) {
    FredkinCell c('0');
    c.setNeighbors(0);
    c.predictFuture();
    c.evolve(false);
    ASSERT_TRUE(!c.isAlive());
 }


    TEST(TestLife, evolve10) {
    FredkinCell c('0');
    c.setNeighbors(2);
    c.predictFuture();
    c.evolve(false);
    ASSERT_TRUE(!c.isAlive());
 }

     TEST(TestLife, evolve11) {
    FredkinCell c('0');
    c.setNeighbors(4);
    c.predictFuture();
    c.evolve(false);
    ASSERT_TRUE(!c.isAlive());
 }

      TEST(TestLife, evolve12) {
    FredkinCell c('0');
    c.setNeighbors(8);
    c.predictFuture();
    c.evolve(false);
    ASSERT_TRUE(c.isAlive());
 }

    TEST(TestLife, evolve13) {
    FredkinCell c('0');
    c.predictFuture();
    c.evolve(false);
    ASSERT_TRUE(!c.isAlive());
 }
 

    TEST(TestLife, evolve14) {
    Cell c;
    c.setNeighbors(0);
    c.predictFuture();
    c.evolve(false);
    ASSERT_TRUE(!c.isAlive());
 }


    TEST(TestLife, evolve15) {
    Cell c;
    c.setNeighbors(2);
    c.predictFuture();
    c.evolve(false);
    ASSERT_TRUE(!c.isAlive());
 }

     TEST(TestLife, evolve16) {
    Cell c;
    c.setNeighbors(4);
    c.predictFuture();
    c.evolve(false);
    ASSERT_TRUE(!c.isAlive());
 }


    TEST(TestLife, evolve17) {
    Cell c;
    c.predictFuture();
    c.evolve(false);
    ASSERT_TRUE(!c.isAlive());
 }
 


    TEST(TestLife, isAlive) {
    ConwayCell c;
    c.setNeighbors(4);
    c.predictFuture();
    c.evolve(false);
    ASSERT_TRUE(!c.isAlive());
 }

     TEST(TestLife, isAlive1) {
    FredkinCell c;
    c.setNeighbors(0);
    c.predictFuture();
    c.evolve(false);
    ASSERT_TRUE(!c.isAlive());
 }

      TEST(TestLife, isAlive2) {
    Cell c;
    c.setNeighbors(0);
    c.predictFuture();
    c.evolve(false);
    ASSERT_TRUE(!c.isAlive());
 }
