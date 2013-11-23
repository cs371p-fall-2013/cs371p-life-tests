#define private public

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==

#include "gtest/gtest.h"

#include "AbstractCell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"
#include "Life.h"

// AbstractCell tests (6*3) = 18

//
// AbstractCell()
//
TEST(Life, ac1) {
    AbstractCell c;
    ASSERT_TRUE(c.isAlive == false);
}

TEST(Life, ac2) {
    AbstractCell c;
    ASSERT_TRUE(c.tempIsAlive == false);
}

TEST(Life, ac3) {
    AbstractCell* c = new AbstractCell();
    ASSERT_TRUE(c->isAlive == false);
}

TEST(Life, ac4) {
    AbstractCell* c = new AbstractCell();
    ASSERT_TRUE(c->tempIsAlive == false);
}

//
// AbstractCell(bool isAlive)
//
TEST(Life, ac5) {
    AbstractCell c(true);
    ASSERT_TRUE(c.isAlive == true);
    ASSERT_TRUE(c.tempIsAlive == false);
}

TEST(Life, ac6) {
    AbstractCell c(false);
    ASSERT_TRUE(c.isAlive == false);
    ASSERT_TRUE(c.tempIsAlive == false);
}

TEST(Life, ac7) {
    AbstractCell* c = new AbstractCell(true);
    ASSERT_TRUE(c->isAlive == true);
    ASSERT_TRUE(c->tempIsAlive == false);
}

TEST(Life, ac8) {
    AbstractCell* c = new AbstractCell(false);
    ASSERT_TRUE(c->isAlive == false);
    ASSERT_TRUE(c->tempIsAlive == false);
}

//
// void latch()
//
TEST(Life, ac9) {
    AbstractCell c;
    c.isAlive = false;
    c.tempIsAlive = false;
    c.latch();
    ASSERT_TRUE(c.isAlive == false);
    ASSERT_TRUE(c.tempIsAlive == false);
}

TEST(Life, ac10) {
    AbstractCell c;
    c.isAlive = true;
    c.tempIsAlive = false;
    c.latch();
    ASSERT_TRUE(c.isAlive == false);
    ASSERT_TRUE(c.tempIsAlive == false);
}

TEST(Life, ac11) {
    AbstractCell c;
    c.isAlive = false;
    c.tempIsAlive = true;
    c.latch();
    ASSERT_TRUE(c.isAlive == true);
    ASSERT_TRUE(c.tempIsAlive == true);
}

TEST(Life, ac12) {
    AbstractCell c;
    c.isAlive = true;
    c.tempIsAlive = true;
    c.latch();
    ASSERT_TRUE(c.isAlive == true);
    ASSERT_TRUE(c.tempIsAlive == true);
}

// ConwayCell tests (18 - 12) + 6*3 = 24

//
// ConwayCell()
//
TEST(Life, cc1) {
    ConwayCell c;
    ASSERT_TRUE(c.isAlive == false);
}

TEST(Life, cc2) {
    ConwayCell c;
    ASSERT_TRUE(c.tempIsAlive == false);
}

TEST(Life, cc3) {
    ConwayCell* c = new ConwayCell();
    ASSERT_TRUE(c->isAlive == false);
}

TEST(Life, cc4) {
    ConwayCell* c = new ConwayCell();
    ASSERT_TRUE(c->tempIsAlive == false);
}

//
// ConwayCell(char ch)
//
TEST(Life, cc5) {
    ConwayCell c('*');
    ASSERT_TRUE(c.isAlive == true);
}

TEST(Life, cc6) {
    ConwayCell c('.');
    ASSERT_TRUE(c.isAlive == false);
}

TEST(Life, cc7) {
    for (int i = 0; i <= 255; i++) {
        if ((char)i == '*') {
            continue;
        }

        ConwayCell c((char)i);
        ASSERT_TRUE(c.isAlive == false);
    }
}

//
// ConwayCell(bool isAlive)
//
TEST(Life, cc8) {
    ConwayCell c(true);
    ASSERT_TRUE(c.isAlive == true);
    ASSERT_TRUE(c.tempIsAlive == false);
}

TEST(Life, cc9) {
    ConwayCell c(false);
    ASSERT_TRUE(c.isAlive == false);
    ASSERT_TRUE(c.tempIsAlive == false);
}

TEST(Life, cc10) {
    ConwayCell* c = new ConwayCell(true);
    ASSERT_TRUE(c->isAlive == true);
    ASSERT_TRUE(c->tempIsAlive == false);
}

TEST(Life, cc11) {
    ConwayCell* c = new ConwayCell(false);
    ASSERT_TRUE(c->isAlive == false);
    ASSERT_TRUE(c->tempIsAlive == false);
}


//
// ConwayCell* clone()
//
TEST(Life, cc12) {
    ConwayCell* c = new ConwayCell(false);
    ConwayCell* d = c->clone();
    ASSERT_TRUE(c->isAlive == d->isAlive);
    ASSERT_TRUE(c->tempIsAlive == d->tempIsAlive);
    ASSERT_TRUE(c != d);
}

TEST(Life, cc13) {
    ConwayCell* c = new ConwayCell(true);
    ConwayCell* d = c->clone();
    ASSERT_TRUE(c->isAlive == d->isAlive);
    ASSERT_TRUE(c->tempIsAlive == d->tempIsAlive);
    ASSERT_TRUE(c != d);
}

TEST(Life, cc14) {
    ConwayCell* c = new ConwayCell(false);
    c->tempIsAlive = false;
    ConwayCell* d = c->clone();
    ASSERT_TRUE(c->isAlive == d->isAlive);
    ASSERT_TRUE(c->tempIsAlive == d->tempIsAlive);
    ASSERT_TRUE(c != d);
}

TEST(Life, cc15) {
    ConwayCell* c = new ConwayCell(true);
    c->tempIsAlive = true;
    ConwayCell* d = c->clone();
    ASSERT_TRUE(c->isAlive == d->isAlive);
    ASSERT_TRUE(c->tempIsAlive == d->tempIsAlive);
    ASSERT_TRUE(c != d);
}

//
// char display
//
TEST(Life, cc16) {
    ConwayCell* c = new ConwayCell(true);
    ASSERT_TRUE(c->display() == '*');
}

TEST(Life, cc17) {
    ConwayCell* c = new ConwayCell(false);
    ASSERT_TRUE(c->display() == '.');
}

TEST(Life, cc18) {
    ConwayCell* c = new ConwayCell(false);
    c->tempIsAlive = true;
    c->latch();
    ASSERT_TRUE(c->display() == '*');
}

TEST(Life, cc19) {
    ConwayCell* c = new ConwayCell(true);
    c->tempIsAlive = false;
    c->latch();
    ASSERT_TRUE(c->display() == '.');
}


// FredkinCell tests (24-20) + 18 = 22

//
// FredkinCell()
//
TEST(Life, fc1) {
    FredkinCell c;
    ASSERT_TRUE(c.isAlive == false);
}

TEST(Life, fc2) {
    FredkinCell c;
    ASSERT_TRUE(c.tempIsAlive == false);
}

TEST(Life, fc3) {
    FredkinCell* c = new FredkinCell();
    ASSERT_TRUE(c->isAlive == false);
}

TEST(Life, fc4) {
    FredkinCell* c = new FredkinCell();
    ASSERT_TRUE(c->tempIsAlive == false);
}

//
// FredkinCell(char ch)
//
TEST(Life, fc5) {
    FredkinCell c('0');
    ASSERT_TRUE(c.isAlive == true);
}

TEST(Life, fc6) {
    FredkinCell c('-');
    ASSERT_TRUE(c.isAlive == false);
}

TEST(Life, fc7) {
    for (int i = 0; i < 10; i++) {
        FredkinCell c((char)(i + '0'));
        ASSERT_TRUE(c.age == i);
    }
}

//
// FredkinCell(bool isAlive, int age)
//
TEST(Life, fc8) {
    FredkinCell c(true, 0);
    ASSERT_TRUE(c.isAlive == true);
    ASSERT_TRUE(c.tempIsAlive == false);
    ASSERT_TRUE(c.age == 0);
}

TEST(Life, fc9) {
    FredkinCell c(false, 42);
    ASSERT_TRUE(c.isAlive == false);
    ASSERT_TRUE(c.tempIsAlive == false);
    ASSERT_TRUE(c.age == 42);
}

TEST(Life, fc10) {
    FredkinCell* c = new FredkinCell(true, -39);
    ASSERT_TRUE(c->isAlive == true);
    ASSERT_TRUE(c->tempIsAlive == false);
    ASSERT_TRUE(c->age == -39);
}

TEST(Life, fc11) {
    FredkinCell* c = new FredkinCell(false, 1324);
    ASSERT_TRUE(c->isAlive == false);
    ASSERT_TRUE(c->tempIsAlive == false);
    ASSERT_TRUE(c->age == 1324);
}


//
// FredkinCell* clone()
//
TEST(Life, fc12) {
    FredkinCell* c = new FredkinCell(false, 10);
    FredkinCell* d = c->clone();
    ASSERT_TRUE(c->isAlive == d->isAlive);
    ASSERT_TRUE(c->tempIsAlive == d->tempIsAlive);
    ASSERT_TRUE(c->age == d->age);
    ASSERT_TRUE(c != d);
}

TEST(Life, fc13) {
    FredkinCell* c = new FredkinCell(true, 0);
    FredkinCell* d = c->clone();
    ASSERT_TRUE(c->isAlive == d->isAlive);
    ASSERT_TRUE(c->tempIsAlive == d->tempIsAlive);
    ASSERT_TRUE(c->age == d->age);
    ASSERT_TRUE(c != d);
}

TEST(Life, fc14) {
    FredkinCell* c = new FredkinCell(false, -123);
    c->tempIsAlive = false;
    FredkinCell* d = c->clone();
    ASSERT_TRUE(c->isAlive == d->isAlive);
    ASSERT_TRUE(c->tempIsAlive == d->tempIsAlive);
    ASSERT_TRUE(c->age == d->age);
    ASSERT_TRUE(c != d);
}

TEST(Life, fc15) {
    FredkinCell* c = new FredkinCell(true, 9);
    c->tempIsAlive = true;
    FredkinCell* d = c->clone();
    ASSERT_TRUE(c->isAlive == d->isAlive);
    ASSERT_TRUE(c->tempIsAlive == d->tempIsAlive);
    ASSERT_TRUE(c->age == d->age);
    ASSERT_TRUE(c != d);
}

//
// char display()
//
TEST(Life, fc16) {
    FredkinCell* c = new FredkinCell(false, 0);
    ASSERT_TRUE(c->display() == '-');
}

TEST(Life, fc17) {
    FredkinCell* c = new FredkinCell(false, 1);
    ASSERT_TRUE(c->display() == '-');
}

TEST(Life, fc18) {
    FredkinCell* c = new FredkinCell(true, 0);
    ASSERT_TRUE(c->display() == '0');
}

TEST(Life, fc19) {
    FredkinCell* c = new FredkinCell(true, 5);
    ASSERT_TRUE(c->display() == '5');
}

TEST(Life, fc20) {
    FredkinCell* c = new FredkinCell(true, 9);
    ASSERT_TRUE(c->display() == '9');
}

TEST(Life, fc21) {
    FredkinCell* c = new FredkinCell(true, 10);
    ASSERT_TRUE(c->display() == '+');
}

// 
// latch with display
//
TEST(Life, fc22) {
    FredkinCell* c = new FredkinCell(false, 0);
    c->tempIsAlive = true;
    c->latch();
    ASSERT_TRUE(c->display() == '0');
}

TEST(Life, fc23) {
    FredkinCell* c = new FredkinCell(false, 1);
    c->tempIsAlive = true;
    c->latch();
    ASSERT_TRUE(c->display() == '1');
}

TEST(Life, fc24) {
    FredkinCell* c = new FredkinCell(false, 9);
    c->tempIsAlive = true;
    c->latch();
    ASSERT_TRUE(c->display() == '9');
}

TEST(Life, fc25) {
    FredkinCell* c = new FredkinCell(false, 10);
    c->tempIsAlive = true;
    c->latch();
    ASSERT_TRUE(c->display() == '+');
}

TEST(Life, fc26) {
    FredkinCell* c = new FredkinCell(true, 5);
    ASSERT_TRUE(c->display() == '5');
    c->tempIsAlive = false;
    c->latch();
    ASSERT_TRUE(c->display() == '-');
    c->tempIsAlive = true;
    c->latch();
    ASSERT_TRUE(c->display() == '5');
}

// Cell tests (22-26) + 3*6 = 12

//
// Cell()
//
TEST(Life, cell1) {
    Cell c;
    ASSERT_TRUE(c.cell == 0);
    ASSERT_TRUE(c.age == 0);
    ASSERT_TRUE(c.hasBecomeConway == false);
    ASSERT_TRUE(c.isAlive == false);
}

TEST(Life, cell2) {
    Cell* c = new Cell();
    ASSERT_TRUE(c->cell == 0);
    ASSERT_TRUE(c->age == 0);
    ASSERT_TRUE(c->hasBecomeConway == false);
    ASSERT_TRUE(c->isAlive == false);
}

//
// Cell(Abstract *c)
//
TEST(Life, cell3) {
    FredkinCell* cc = new FredkinCell();
    Cell c = cc;
    ASSERT_TRUE(c.cell == cc);
    ASSERT_TRUE(c.age == 0);
    ASSERT_TRUE(c.hasBecomeConway == false);
    ASSERT_TRUE(c.isAlive == false);
}

TEST(Life, cell4) {
    FredkinCell* cc = new FredkinCell('0');
    Cell c = cc;
    ASSERT_TRUE(c.cell == cc);
    ASSERT_TRUE(c.age == 0);
    ASSERT_TRUE(c.hasBecomeConway == false);
    ASSERT_TRUE(c.isAlive == true);
}

TEST(Life, cell5) {
    FredkinCell* cc = new FredkinCell(true, 10);
    Cell c = cc;
    ASSERT_TRUE(c.cell == cc);
    ASSERT_TRUE(c.age == 0);
    ASSERT_TRUE(c.hasBecomeConway == false);
    ASSERT_TRUE(c.isAlive == true);
}

TEST(Life, cell6) {
    ConwayCell* cc = new ConwayCell();
    Cell c = cc;
    ASSERT_TRUE(c.cell == cc);
    ASSERT_TRUE(c.age == 0);
    ASSERT_TRUE(c.hasBecomeConway == true);
    ASSERT_TRUE(c.isAlive == false);
}

TEST(Life, cell7) {
    ConwayCell* cc = new ConwayCell('*');
    Cell c = cc;
    ASSERT_TRUE(c.cell == cc);
    ASSERT_TRUE(c.age == 0);
    ASSERT_TRUE(c.hasBecomeConway == true);
    ASSERT_TRUE(c.isAlive == true);
}

TEST(Life, cell8) {
    ConwayCell* cc = new ConwayCell(true);
    Cell c = cc;
    ASSERT_TRUE(c.cell == cc);
    ASSERT_TRUE(c.age == 0);
    ASSERT_TRUE(c.hasBecomeConway == true);
    ASSERT_TRUE(c.isAlive == true);
}

//
// Cell& operator = (const Cell& rhs)
//

TEST(Life, cell9) {
    Cell c = new ConwayCell();
    c.age = 1618; 
    
    Cell c2;
    c2 = c;
    
    ASSERT_TRUE(c.cell != c2.cell);
    ASSERT_TRUE(c.age == c2.age);
    ASSERT_TRUE(c.hasBecomeConway == c2.hasBecomeConway);
    ASSERT_TRUE(c.isAlive == c2.isAlive);
}

TEST(Life, cell10) {
    Cell c = new ConwayCell('*');
    c.age = 1618; 
    
    Cell c2;
    c2 = c;    

    ASSERT_TRUE(c.cell != c2.cell);
    ASSERT_TRUE(c.age == c2.age);
    ASSERT_TRUE(c.hasBecomeConway == c2.hasBecomeConway);
    ASSERT_TRUE(c.isAlive == c2.isAlive);
}

TEST(Life, cell11) {
    Cell c = new ConwayCell(true);
    c.age = 1618; 
    
    Cell c2;
    c2 = c;
    
    ASSERT_TRUE(c.cell != c2.cell);
    ASSERT_TRUE(c.age == c2.age);
    ASSERT_TRUE(c.hasBecomeConway == c2.hasBecomeConway);
    ASSERT_TRUE(c.isAlive == c2.isAlive);
}

TEST(Life, cell12) {
    Cell c = new FredkinCell();
    c.age = 10; 
    
    Cell c2;
    c2 = c;
    
    ASSERT_TRUE(c.cell != c2.cell);
    ASSERT_TRUE(c.age == c2.age);
    ASSERT_TRUE(c.hasBecomeConway == c2.hasBecomeConway);
    ASSERT_TRUE(c.isAlive == c2.isAlive);
}

TEST(Life, cell13) {
    Cell c = new FredkinCell('5');
    c.age = 10; 
    
    Cell c2;
    c2 = c;    

    ASSERT_TRUE(c.cell != c2.cell);
    ASSERT_TRUE(c.age == c2.age);
    ASSERT_TRUE(c.hasBecomeConway == c2.hasBecomeConway);
    ASSERT_TRUE(c.isAlive == c2.isAlive);
}

TEST(Life, cell14) {
    Cell c = new FredkinCell(true, 12466);
    c.age = 10; 
    
    Cell c2;
    c2 = c;
    
    ASSERT_TRUE(c.cell != c2.cell);
    ASSERT_TRUE(c.age == c2.age);
    ASSERT_TRUE(c.hasBecomeConway == c2.hasBecomeConway);
    ASSERT_TRUE(c.isAlive == c2.isAlive);
}

// char display()

TEST(Life, cell15) {
    Cell c = new FredkinCell(false, 0);
    ASSERT_TRUE(c.display() == '-');
}

TEST(Life, cell16) {
    Cell c = new FredkinCell(false, 1);
    ASSERT_TRUE(c.display() == '-');
}

TEST(Life, cell17) {
    Cell c = new FredkinCell(true, 0);
    ASSERT_TRUE(c.display() == '0');
}

TEST(Life, cell18) {
    Cell c = new FredkinCell(true, 5);
    ASSERT_TRUE(c.display() == '5');
}

TEST(Life, cell19) {
    Cell c = new FredkinCell(true, 9);
    ASSERT_TRUE(c.display() == '9');
}

TEST(Life, cell20) {
    Cell c = new FredkinCell(true, 10);
    ASSERT_TRUE(c.display() == '+');
}

TEST(Life, cell21) {
    Cell c = new ConwayCell(true);
    ASSERT_TRUE(c.display() == '*');
}

TEST(Life, cell22) {
    Cell c = new ConwayCell(false);
    ASSERT_TRUE(c.display() == '.');
}

TEST(Life, cell23) {
    Cell c = new ConwayCell(false);
    c.cell->tempIsAlive = true;
    c.latch();
    ASSERT_TRUE(c.display() == '*');
}

TEST(Life, cell24) {
    Cell c = new ConwayCell(true);
    c.cell->tempIsAlive = false;
    c.latch();
    ASSERT_TRUE(c.display() == '.');
}

// Life tests (24 - 12) + 3*3 = 0

