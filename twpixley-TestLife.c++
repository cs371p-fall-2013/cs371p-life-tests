// --------------------------------
// projects/darwin/TestLife.c++
// Copyright (C) 2013
// Tyler W. Pixley
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

    % g++ -pedantic -std=c++0x -Wall Cell.c++ AbstractCell.c++ ConwayCell.c++ FredkinCell.c++ TestLife.c++ -o TestCollatz -lgtest -lpthread -lgtest_main

    % valgrind TestLife > TestLife.out
*/

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <stdexcept> // invalid_argument, out_of_range
#include <string>   // ==

#include "gtest/gtest.h"

#define private public
#define protected public
#include "Cell.h"
#include "AbstractCell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Handle.h"

TEST (Conway, ReadDead) {
    ConwayCell cell;
    cell.read('.');
    ASSERT_FALSE(cell.alive);
    ASSERT_FALSE(cell.aliveNextTurn);
}

TEST (Conway, ReadAlive) {
    ConwayCell cell;
    cell.read('*');
    ASSERT_TRUE(cell.alive);
    ASSERT_FALSE(cell.aliveNextTurn);
}

TEST (Conway, Update1) {
	ConwayCell cell;
    cell.aliveNextTurn = true;
    cell.update();
    ASSERT_TRUE(cell.alive);
    ASSERT_FALSE(cell.aliveNextTurn);
}

TEST (Conway, Update2) {
    ConwayCell cell;
    cell.alive = true;
    cell.update();
    ASSERT_FALSE(cell.alive);
    ASSERT_FALSE(cell.aliveNextTurn);
}

TEST (Conway, Update3) {
    ConwayCell cell;
    cell.alive = true;
    cell.aliveNextTurn = true;
    cell.update();
    ASSERT_TRUE(cell.alive);
    ASSERT_FALSE(cell.aliveNextTurn);
}

TEST (Conway, Prepare1) {
    ConwayCell cell;
    cell.prepare(3);
    ASSERT_TRUE(cell.aliveNextTurn);
}

TEST (Conway, Prepare2) {
    ConwayCell cell;
    cell.alive = true;
    cell.prepare(0);
    ASSERT_FALSE(cell.aliveNextTurn);
}

TEST (Conway, Prepare3) {
    ConwayCell cell;
    cell.alive = true;
    cell.prepare(2);
    ASSERT_TRUE(cell.aliveNextTurn);
}

TEST (Conway, Clone) {
    ConwayCell cell1;
    AbstractCell* cell2 = cell1.clone();
    ASSERT_FALSE(cell2->alive);
    ASSERT_FALSE(cell2->aliveNextTurn);

    delete cell2;
}

TEST (Conway, NeighborCountInternal) {
    vector<ConwayCell> tempvect(3);
    vector<vector<ConwayCell> > cells(3, tempvect);
    ASSERT_TRUE(cells.size() == 3);
    ASSERT_TRUE(cells[0].size() == 3);
    ASSERT_FALSE(cells[0][0].alive);

    cells[0][1].alive = true;
    cells[1][0].alive = true;
    cells[0][0].alive = true;

    // cout << neighborCount(cells, 1, 1) << endl;
    ASSERT_TRUE(neighborCount(cells, 1, 1) == 3);
}

TEST (Conway, NeighborCountEdge) {
    vector<ConwayCell> tempvect(3);
    vector<vector<ConwayCell> > cells(3, tempvect);
    cells[2][0].alive = true;
    cells[0][0].alive = true;
    cells[0][1].alive = true;

    ASSERT_TRUE(neighborCount(cells, 1, 0) == 3);
}

TEST (Conway, NeighborCountCorner) {
    vector<ConwayCell> tempvect(3);
    vector<vector<ConwayCell> > cells(3, tempvect);
    cells[0][1].alive = true;
    cells[1][1].alive = true;

    ASSERT_TRUE(neighborCount(cells, 0, 0) == 2);
}

TEST (Conway, NeighborCountHandle1) {
    ConwayCell cell1 (true);
    FredkinCell cell2 (true);
    ConwayCell cell3;

    vector<AbstractCell*> cells(8);
    cells[0] = &cell1;
    cells[1] = &cell2;
    cells[2] = &cell3;

    ASSERT_TRUE(cell1.neighborCount(cells) == 2);
}

TEST (Conway, NeighborCountHandle2) {
    ConwayCell cell1 (true);
    FredkinCell cell2 (true);
    ConwayCell cell3 (true);
    FredkinCell cell4 (true);
    ConwayCell cell5 (true);
    FredkinCell cell6 (true);
    ConwayCell cell7 (true);
    FredkinCell cell8(true);

    vector<AbstractCell*> cells(8);
    cells[0] = &cell1;
    cells[1] = &cell2;
    cells[2] = &cell3;
    cells[3] = &cell4;
    cells[4] = &cell5;
    cells[5] = &cell6;
    cells[6] = &cell7;
    cells[7] = &cell8;

    ASSERT_TRUE(cell1.neighborCount(cells) == 8);
}

TEST (Conway, NeighborCountHandle3) {
    ConwayCell cell1;
    FredkinCell cell2;
    ConwayCell cell3;
    FredkinCell cell4;
    ConwayCell cell5;
    FredkinCell cell6;
    ConwayCell cell7;
    FredkinCell cell8;

    vector<AbstractCell*> cells(8);
    cells[0] = &cell1;
    cells[1] = &cell2;
    cells[2] = &cell3;
    cells[3] = &cell4;
    cells[4] = &cell5;
    cells[5] = &cell6;
    cells[6] = &cell7;
    cells[7] = &cell8;

    ASSERT_TRUE(cell1.neighborCount(cells) == 0);
}

TEST (Fredkin, ReadDead) {
    FredkinCell cell;
    cell.read('-');
    ASSERT_FALSE(cell.alive);
    ASSERT_FALSE(cell.aliveNextTurn);
}

TEST (Fredkin, ReadAlive) {
    FredkinCell cell;
    cell.read('0');
    ASSERT_TRUE(cell.alive);
    ASSERT_FALSE(cell.aliveNextTurn);
}

TEST (Fredkin, Update1) {
    FredkinCell cell;
    cell.aliveNextTurn = true;
    cell.update();
    ASSERT_TRUE(cell.alive);
    ASSERT_FALSE(cell.aliveNextTurn);
}

TEST (Fredkin, Update2) {
    FredkinCell cell;
    cell.alive = true;
    cell.update();
    ASSERT_FALSE(cell.alive);
    ASSERT_FALSE(cell.aliveNextTurn);
}

TEST (Fredkin, Update3) {
    FredkinCell cell;
    cell.alive = true;
    cell.aliveNextTurn = true;
    cell.update();
    ASSERT_TRUE(cell.alive);
    ASSERT_FALSE(cell.aliveNextTurn);
}

TEST (Fredkin, Prepare1) {
    FredkinCell cell;
    cell.prepare(3);
    ASSERT_TRUE(cell.aliveNextTurn);
}

TEST (Fredkin, Prepare2) {
    FredkinCell cell;
    cell.alive = true;
    cell.prepare(0);
    ASSERT_FALSE(cell.aliveNextTurn);
}

TEST (Fredkin, Prepare3) {
    FredkinCell cell;
    cell.alive = true;
    cell.prepare(1);
    ASSERT_TRUE(cell.aliveNextTurn);
}

TEST (Fredkin, Clone) {
    FredkinCell cell1;
    AbstractCell* cell2 = cell1.clone();
    ASSERT_FALSE(cell2->alive);
    ASSERT_FALSE(cell2->aliveNextTurn);
    ASSERT_TRUE((dynamic_cast<FredkinCell*>(cell2))->age == 0);

    delete cell2;
}

TEST (Fredkin, NeighborCountInternal) {
    vector<FredkinCell> tempvect(3);
    vector<vector<FredkinCell> > cells(3, tempvect);
    cells[0][1].alive = true;
    cells[1][0].alive = true;
    cells[0][0].alive = true;

    ASSERT_TRUE(neighborCount(cells, 1, 1) == 2);
}

TEST (Fredkin, NeighborCountEdge) {
    vector<FredkinCell> tempvect(3);
    vector<vector<FredkinCell> > cells(3, tempvect);
    cells[2][0].alive = true;
    cells[0][0].alive = true;
    cells[0][1].alive = true;

    ASSERT_TRUE(neighborCount(cells, 1, 0) == 2);
}

TEST (Fredkin, NeighborCountCorner) {
    vector<FredkinCell> tempvect(3);
    vector<vector<FredkinCell> > cells(3, tempvect);
    cells[0][1].alive = true;
    cells[1][1].alive = true;

    ASSERT_TRUE(neighborCount(cells, 0, 0) == 1);
}

TEST (Fredkin, NeighborCountHandle1) {
    FredkinCell cell1 (true);
    ConwayCell cell2 (true);
    FredkinCell cell3;

    vector<AbstractCell*> cells(8);
    cells[0] = &cell1;
    cells[1] = &cell2;
    cells[2] = &cell3;

    ASSERT_TRUE(cell1.neighborCount(cells) == 2);
}

TEST (Fredkin, NeighborCountHandle2) {
    ConwayCell cell1 (true);
    FredkinCell cell2 (true);
    ConwayCell cell3 (true);
    FredkinCell cell4 (true);
    ConwayCell cell5 (true);
    FredkinCell cell6 (true);
    ConwayCell cell7 (true);
    FredkinCell cell8 (true);

    vector<AbstractCell*> cells(8);
    cells[0] = &cell1;
    cells[1] = &cell2;
    cells[2] = &cell3;
    cells[3] = &cell4;
    cells[4] = &cell5;
    cells[5] = &cell6;
    cells[6] = &cell7;
    cells[7] = &cell8;

    ASSERT_TRUE(cell2.neighborCount(cells) == 4);
}

TEST (Fredkin, NeighborCountHandle3) {
    ConwayCell cell1;
    FredkinCell cell2;
    ConwayCell cell3;
    FredkinCell cell4;
    ConwayCell cell5;
    FredkinCell cell6;
    ConwayCell cell7;
    FredkinCell cell8;

    vector<AbstractCell*> cells(8);
    cells[0] = &cell1;
    cells[1] = &cell2;
    cells[2] = &cell3;
    cells[3] = &cell4;
    cells[4] = &cell5;
    cells[5] = &cell6;
    cells[6] = &cell7;
    cells[7] = &cell8;

    ASSERT_TRUE(cell2.neighborCount(cells) == 0);
}

TEST (Cell, ReadDeadConway) {
    Cell cell (new ConwayCell());
    cell.read('.');
    ASSERT_FALSE(cell._p->alive);
    ASSERT_FALSE(cell._p->aliveNextTurn);
}

TEST (Cell, ReadAliveConway) {
    Cell cell (new ConwayCell());
    cell.read('*');
    ASSERT_TRUE(cell._p->alive);
    ASSERT_FALSE(cell._p->aliveNextTurn);
}

TEST (Cell, ReadDeadFredkin) {
    Cell cell (new FredkinCell());
    cell.read('-');
    ASSERT_FALSE(cell._p->alive);
    ASSERT_FALSE(cell._p->aliveNextTurn);
}

TEST (Cell, ReadAliveFredkin) {
    Cell cell (new FredkinCell());
    cell.read('0');
    ASSERT_TRUE(cell._p->alive);
    ASSERT_FALSE(cell._p->aliveNextTurn);
}

TEST (Cell, Update1Conway) {
    Cell cell (new ConwayCell());
    cell._p->aliveNextTurn = true;
    cell.update();
    ASSERT_TRUE(cell._p->alive);
    ASSERT_FALSE(cell._p->aliveNextTurn);
}

TEST (Cell, Update2Conway) {
    Cell cell (new ConwayCell());
    cell._p->alive = true;
    cell.update();
    ASSERT_FALSE(cell._p->alive);
    ASSERT_FALSE(cell._p->aliveNextTurn);
}

TEST (Cell, Update3Conway) {
    Cell cell (new ConwayCell());
    cell._p->alive = true;
    cell._p->aliveNextTurn = true;
    cell.update();
    ASSERT_TRUE(cell._p->alive);
    ASSERT_FALSE(cell._p->aliveNextTurn);
}

TEST (Cell, Prepare1Conway) {
    Cell cell (new ConwayCell());
    cell.prepare(3);
    ASSERT_TRUE(cell._p->aliveNextTurn);
}

TEST (Cell, Prepare2Conway) {
    Cell cell (new ConwayCell());
    cell._p->alive = true;
    cell.prepare(0);
    ASSERT_FALSE(cell._p->aliveNextTurn);
}

TEST (Cell, Prepare3Conway) {
    Cell cell (new ConwayCell());
    cell._p->alive = true;
    cell.prepare(1);
    ASSERT_FALSE(cell._p->aliveNextTurn);
}

TEST (Cell, NeighborCountInternalConway) {
    vector<Cell> tempvect(3, new ConwayCell());
    vector<vector<Cell> > cells(3, tempvect);
    cells[0][1]._p->alive = true;
    cells[1][0]._p->alive = true;
    cells[0][0]._p->alive = true;

    ASSERT_TRUE(neighborCount(cells, 1, 1) == 3);
}

TEST (Cell, NeighborCountEdgeConway) {
    vector<Cell> tempvect(3, new ConwayCell());
    vector<vector<Cell> > cells(3, tempvect);
    cells[2][0]._p->alive = true;
    cells[0][0]._p->alive = true;
    cells[0][1]._p->alive = true;

    ASSERT_TRUE(neighborCount(cells, 1, 0) == 3);
}

TEST (Cell, NeighborCountCornerConway) {
    vector<Cell> tempvect(3, new ConwayCell());
    vector<vector<Cell> > cells(3, tempvect);
    cells[0][1]._p->alive = true;
    cells[1][1]._p->alive = true;

    ASSERT_TRUE(neighborCount(cells, 0, 0) == 2);
}

TEST (Cell, Update1Fredkin) {
    Cell cell (new FredkinCell());
    cell._p->aliveNextTurn = true;
    cell.update();
    ASSERT_TRUE(cell._p->alive);
    ASSERT_FALSE(cell._p->aliveNextTurn);
}

TEST (Cell, Update2Fredkin) {
    Cell cell (new FredkinCell());
    cell._p->alive = true;
    cell.update();
    ASSERT_FALSE(cell._p->alive);
    ASSERT_FALSE(cell._p->aliveNextTurn);
}

TEST (Cell, Update3Fredkin) {
    Cell cell (new FredkinCell());
    cell._p->alive = true;
    cell._p->aliveNextTurn = true;
    cell.update();
    ASSERT_TRUE(cell._p->alive);
    ASSERT_FALSE(cell._p->aliveNextTurn);
    ASSERT_TRUE((dynamic_cast<FredkinCell*>(cell._p))->age == 0);
}

TEST (Cell, Prepare1Fredkin) {
    Cell cell (new FredkinCell());
    cell.prepare(3);
    ASSERT_TRUE(cell._p->aliveNextTurn);
}

TEST (Cell, Prepare2Fredkin) {
    Cell cell (new FredkinCell());
    cell._p->alive = true;
    cell.prepare(0);
    ASSERT_FALSE(cell._p->aliveNextTurn);
}

TEST (Cell, Prepare3Fredkin) {
    Cell cell (new FredkinCell());
    cell._p->alive = true;
    cell.prepare(1);
    ASSERT_TRUE(cell._p->aliveNextTurn);
    ASSERT_TRUE((dynamic_cast<FredkinCell*>(cell._p))->age == 1);
}

TEST (Cell, PrepareFredkinMutate) {
    Cell cell (new FredkinCell());
    cell._p->alive = true;
    (dynamic_cast<FredkinCell*>(cell._p))->age = 1;
    AbstractCell* p = cell._p;
    cell.prepare(1);
    ASSERT_TRUE(p != cell._p);
}

TEST (Cell, NeighborCountInternalFredkin) {
    vector<Cell> tempvect(3, new FredkinCell());
    vector<vector<Cell> > cells(3, tempvect);
    cells[0][1]._p->alive = true;
    cells[1][0]._p->alive = true;
    cells[0][0]._p->alive = true;

    ASSERT_TRUE(neighborCount(cells, 1, 1) == 2);
}

TEST (Cell, NeighborCountEdgeFredkin) {
    vector<Cell> tempvect(3, new FredkinCell());
    vector<vector<Cell> > cells(3, tempvect);
    cells[2][0]._p->alive = true;
    cells[0][0]._p->alive = true;
    cells[0][1]._p->alive = true;

    ASSERT_TRUE(neighborCount(cells, 1, 0) == 2);
}

TEST (Cell, NeighborCountCornerFredkin) {
    vector<Cell> tempvect(3, new FredkinCell());
    vector<vector<Cell> > cells(3, tempvect);
    cells[0][1]._p->alive = true;
    cells[1][1]._p->alive = true;

    ASSERT_TRUE(neighborCount(cells, 0, 0) == 1);
}

TEST (Cell, Mutate) {
    Cell cell(new FredkinCell());
    AbstractCell* p = cell._p;
    cell.mutate();
    ASSERT_TRUE(p != cell._p);
}