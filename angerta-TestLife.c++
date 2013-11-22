/****************************************
TestLife.c++
Author: Aaron Angert
EID:    aa35226
 ****************************************/

#include <iostream> // cout, endl
#include <string>   // ==
#include <stdexcept> // invalid_argument, out_of_range
#include <fstream>  
#include <sstream>   

#include "gtest/gtest.h"

#include "Life.h"
#include "Cell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"

using namespace std;

TEST(ConwayCell, ConwayCell) 
{
        ConwayCell cell;
        
        ASSERT_TRUE(cell.alive);
        ASSERT_TRUE(cell.newAlive);
}

TEST(ConwayCell, ConwayCell_print) 
{
        ConwayCell cell;
        
        ASSERT_EQ(cell.print(),'*');
}

TEST(ConwayCell, ConwayCell_print2) 
{
        ConwayCell cell;
        cell.update('.');
        ASSERT_EQ(cell.print(),'.');
}

TEST(ConwayCell, ConwayCell_death) 
{
        ConwayCell cell;
        cell.update('.');
        ASSERT_TRUE(!cell.alive);
        ASSERT_TRUE(!cell.newAlive);
}

TEST(ConwayCell, ConwayCell_death2) 
{
        ConwayCell cell;
        cell.update('*');
        cell.update('.');
        ASSERT_TRUE(!cell.alive);
        ASSERT_TRUE(!cell.newAlive);
}

TEST(ConwayCell, ConwayCell_alive) 
{
        ConwayCell cell;
        ASSERT_TRUE(cell.isAlive());
}

TEST(ConwayCell, ConwayCell_alive2) 
{
        ConwayCell cell;
        cell.update('.');
        cell.updateState();
        ASSERT_TRUE(!cell.isAlive());
}

TEST(ConwayCell, neighbors) 
{
        ConwayCell cell;
        cell.mark(0,0);
        cell.updateState();
        ASSERT_TRUE(!cell.isAlive());
}
TEST(ConwayCell, neighbors2) 
{
        ConwayCell cell;
        cell.mark(1,0);
        cell.updateState();
        ASSERT_TRUE(!cell.isAlive());
}
TEST(ConwayCell, neighbors3) 
{
        ConwayCell cell;
        cell.mark(0,2);
        cell.updateState();
        ASSERT_TRUE(cell.isAlive());
}
TEST(ConwayCell, neighbors4) 
{
        ConwayCell cell;
        cell.mark(0,3);
        cell.updateState();
        ASSERT_TRUE(cell.isAlive());
}
TEST(ConwayCell, neighbors5) 
{
        ConwayCell cell;
        cell.mark(4,0);
        cell.updateState();
        ASSERT_TRUE(!cell.isAlive());
}
TEST(ConwayCell, neighbors6) 
{
        ConwayCell cell;
        cell.mark(0,5);
        cell.updateState();
        ASSERT_TRUE(!cell.isAlive());
}

TEST(FredkinCell, FredkinCell) 
{
        FredkinCell cell;
        
        ASSERT_TRUE(cell.alive);
        ASSERT_TRUE(cell.newAlive);
}

TEST(FredkinCell, FredkinCell_print) 
{
        FredkinCell cell;
        
        ASSERT_EQ(cell.print(),'0');
}

TEST(FredkinCell, FredkinCell_print2) 
{
        FredkinCell cell;
        cell.update('-');
        ASSERT_EQ(cell.print(),'-');
}

TEST(FredkinCell, FredkinCell_death) 
{
        FredkinCell cell;
        cell.update('-');
        ASSERT_TRUE(!cell.alive);
        ASSERT_TRUE(!cell.newAlive);
}

TEST(FredkinCell, FredkinCell_death2) 
{
        FredkinCell cell;
        cell.update('0');
        cell.update('-');
        ASSERT_TRUE(!cell.alive);
        ASSERT_TRUE(!cell.newAlive);
}

TEST(FredkinCell, FredkinCell_alive) 
{
        FredkinCell cell;
        ASSERT_TRUE(cell.isAlive());
}

TEST(FredkinCell, FredkinCell_alive2) 
{
        FredkinCell cell;
        cell.update('-');
        cell.updateState();
        ASSERT_TRUE(!cell.isAlive());
}

TEST(FredkinCell, FredkinCellneighbors) 
{
        FredkinCell cell;
        cell.mark(0,0);
        cell.updateState();
        ASSERT_TRUE(!cell.isAlive());
}
TEST(FredkinCell, FredkinCellneighbors2) 
{
        FredkinCell cell;
        cell.mark(1,1);
        cell.updateState();
        ASSERT_TRUE(cell.isAlive());
}
TEST(FredkinCell, FredkinCellneighbors3) 
{
        FredkinCell cell;
        cell.mark(0,2);
        cell.updateState();
        ASSERT_TRUE(!cell.isAlive());
}
TEST(FredkinCell, FredkinCellneighbors4) 
{
        FredkinCell cell;
        cell.mark(0,3);
        cell.updateState();
        ASSERT_TRUE(cell.isAlive());
}
TEST(FredkinCell, FredkinCellneighbors5) 
{
        FredkinCell cell;
        cell.mark(4,4);
        cell.updateState();
        ASSERT_TRUE(!cell.isAlive());
}


TEST(Cell, Cell) 
{
        Cell cell;
        
        ASSERT_TRUE(cell.isAlive());
}

TEST(Cell, Cell_print) 
{
        Cell cell;
        cell.update('0');
        ASSERT_EQ(cell.print(),'0');
}

TEST(Cell, Cell_print2) 
{
        Cell cell;
        cell.update('-');
        ASSERT_EQ(cell.print(),'-');
}

TEST(Cell, Cell_death) 
{
        Cell cell;
        cell.update('-');
        ASSERT_TRUE(!cell.isAlive());
}

TEST(Cell, Cell_death2) 
{
        Cell cell;
        cell.update('0');
        cell.update('-');
        ASSERT_TRUE(!cell.isAlive());
}

TEST(Cell, Cell_alive2) 
{
        Cell cell;
        cell.update('-');
        cell.updateState();
        ASSERT_TRUE(!cell.isAlive());
}

TEST(Cell, Cellneighbors) 
{
        Cell cell;
        cell.mark(0,0);
        cell.updateState();
        ASSERT_TRUE(!cell.isAlive());
}
TEST(Cell, Cellneighbors2) 
{
        Cell cell;
        cell.mark(1,1);
        cell.updateState();
        ASSERT_TRUE(cell.isAlive());
}
TEST(Cell, Cellneighbors3) 
{
        Cell cell;
        cell.mark(0,2);
        cell.updateState();
        ASSERT_TRUE(!cell.isAlive());
}
TEST(Cell, Cellneighbors4) 
{
        Cell cell;
        cell.mark(0,3);
        cell.updateState();
        ASSERT_TRUE(cell.isAlive());
}
TEST(Cell, Cellneighbors5) 
{
        Cell cell;
        cell.mark(4,4);
        cell.updateState();
        ASSERT_TRUE(!cell.isAlive());
}

TEST(Cell, mutate) 
{
        Cell cell;
        cell.update('1');
        cell.mark(0,3);
        cell.updateState();
        ASSERT_EQ(cell.print(),'*');
}

TEST(Cell, mutate2) 
{
        Cell cell;
        cell.update('1');
        cell.mark(0,4);
        cell.updateState();
        ASSERT_EQ(cell.print(),'-');
}

TEST(Placement, conwayPopulation)
{
        std::istringstream iss("3\n3\n.*.\n.*.\n.*.");
        Life<ConwayCell> l(iss);
        ASSERT_EQ(l.population(),3);
}

TEST(Placement, conwayPopulation2)
{
        std::istringstream iss("3\n3\n.*.\n.*.\n...");
        Life<ConwayCell> l(iss);
        ASSERT_EQ(l.population(),2);
}

TEST(Placement, conwayPopulation3)
{
        std::istringstream iss("3\n3\n...\n...\n...");
        Life<ConwayCell> l(iss);
        ASSERT_EQ(l.population(),0);
}

TEST(Placement, FredkinPopulation)
{
        std::istringstream iss("3\n3\n-0-\n-0-\n-0-");
        Life<FredkinCell> l(iss);
        ASSERT_EQ(l.population(),3);
}

TEST(Placement, FredkinPopulation2)
{
        std::istringstream iss("3\n3\n-0-\n-0-\n---");
        Life<FredkinCell> l(iss);
        ASSERT_EQ(l.population(),2);
}

TEST(Placement, FredkinPopulation3)
{
        std::istringstream iss("3\n3\n---\n---\n---");
        Life<FredkinCell> l(iss);
        ASSERT_EQ(l.population(),0);
}


TEST(Placement, neighbors)
{
        std::istringstream iss("3\n3\n.*.\n...\n...");
        Life<ConwayCell> l(iss);
        ASSERT_EQ(l.getAliveCornerNeighbors(0,1),0);
}

TEST(Placement, neighbors2)
{
        std::istringstream iss("3\n3\n.*.\n*..\n...");
        Life<ConwayCell> l(iss);
        ASSERT_EQ(l.getAliveCornerNeighbors(0,1),1);
}

TEST(Placement, neighbors3)
{
        std::istringstream iss("3\n3\n.*.\n*.*\n...");
        Life<ConwayCell> l(iss);
        ASSERT_EQ(l.getAliveCornerNeighbors(0,1),2);
}

TEST(Placement, neighborAlive)
{
        std::istringstream iss("3\n3\n.*.\n*.*\n...");
        Life<ConwayCell> l(iss);
        ASSERT_EQ(l.neighborIsalive(0,1),1);
}

TEST(Placement, neighborAlive2)
{
        std::istringstream iss("3\n3\n.*.\n*.*\n...");
        Life<ConwayCell> l(iss);
        ASSERT_EQ(l.neighborIsalive(0,0),0);
}


TEST(Placement, runworld)
{
        std::istringstream iss("3\n3\n.*.\n...\n...");
        Life<ConwayCell> l(iss);
        l.runWorldTurn();
        ASSERT_EQ(l.population(),0);
}

TEST(Placement, runworld2)
{
        std::istringstream iss("3\n3\n***\n...\n...");
        Life<ConwayCell> l(iss);
        l.runWorldTurn();
        ASSERT_EQ(l.population(),2);
}

TEST(Placement, runworld3)
{
        std::istringstream iss("3\n3\n***\n.*.\n.*.");
        Life<ConwayCell> l(iss);
        l.runWorldTurn();
        ASSERT_EQ(l.population(),3);
}
