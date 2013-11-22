/*
name: Kyeong Su Park
eid: ksp499
csid: ksp499
github id: ksp499
email: ksp499@gmail.com
course: CS371p 10am
*/

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==
#include <stdexcept>

#include "gtest/gtest.h"

#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"
#include "Life.h"

// -----------
// TestLife
// -----------

// ----
// alive
// ----

TEST(Life, isAlive_1){
    ConwayCell cell(true);
    ASSERT_TRUE(cell.isAlive());
}

TEST(Life, isAlive_2){
    FredkinCell cell(false);
    ASSERT_TRUE(!(cell.isAlive()));
}

TEST(Life, isAlive_3){
    Cell cell(new FredkinCell(false));
    ASSERT_TRUE(!(cell.isAlive()));
}

// ----
// clone
// ----

TEST(Life, clone_1){
    Cell cell1;
    Cell cell2;
    cell2 = cell1;
    ASSERT_TRUE(cell1._p != cell2._p);
    ASSERT_TRUE(cell1._p->alive == cell2._p->alive);
}

TEST(Life, clone_2){
    Cell cell1;
    Cell cell2(new ConwayCell(true));
    cell2 = cell1;
    ASSERT_TRUE(cell1._p != cell2._p);
    ASSERT_TRUE(cell1._p->alive == cell2._p->alive);
}

TEST(Life, clone_3){
    Cell cell1(new ConwayCell(false));
    Cell cell2(new ConwayCell(true));
    cell2 = cell1;
    ASSERT_TRUE(cell1._p != cell2._p);
    ASSERT_TRUE(cell1._p->alive == cell2._p->alive);
}

// ----
// Cell::isEvolving
// ----

TEST(Life, Cell_isEvolving_1){
    Cell cell;
    bool b[] = {0, 0, 0, 1, 0, 0, 0, 0};
    cell.isEvolving(b);
    ASSERT_TRUE(cell.isAlive());
}

// ----
// Cell::mutatation
// ----

TEST(Life, Cell_mutation_1){
    Cell cell = new FredkinCell(true);
    AbstractCell* p = cell._p;
    std::ostringstream os;
    cell.mutation();
    cell.write(os);
    ASSERT_TRUE(cell._p->alive);
    ASSERT_TRUE(os.str() == "*");
    ASSERT_TRUE(cell._p != p);
}

// ----
// Cell::read
// ----

TEST(Life, Cell_read_1){
    Cell cell;
    std::istringstream is("5");
    cell.read(is);
    ASSERT_TRUE(cell.isAlive());
}

// ----
// Cell::write
// ----

TEST(Life, Cell_write_1){
    Cell cell;
    std::ostringstream os;
    cell.write(os);
    ASSERT_TRUE(os.str() == "-");
}

// ----
// ConwayCell::isEvolving
// ----

TEST(Life, ConwayCell_isEvolving_1){
    ConwayCell cell;
    bool b[] = {0, 0, 0, 1, 0, 1, 1, 0};
    cell.isEvolving(b);
    ASSERT_TRUE(cell.isAlive());
}

TEST(Life, ConwayCell_isEvolving_2){
    ConwayCell cell;
    bool b[] = {0, 0, 0, 0, 0, 1, 1, 0};
    cell.isEvolving(b);
    ASSERT_TRUE(!(cell.isAlive()));
}

TEST(Life, ConwayCell_isEvolving_3){
    ConwayCell cell(true);
    bool b[] = {0, 0, 0, 0, 0, 0, 0, 0};
    cell.isEvolving(b);
    ASSERT_TRUE(!(cell.isAlive()));
}

// ----
// ConwayCell::write
// ----

TEST(Life, ConwayCell_write_1){
    ConwayCell cell(true);
    std::ostringstream os;
    cell.write(os);
    ASSERT_TRUE(os.str() == "*");
}

TEST(Life, ConwayCell_write_2){
    ConwayCell cell(false);
    std::ostringstream os;
    cell.write(os);
    ASSERT_TRUE(os.str() == ".");
}

TEST(Life, ConwayCell_write_3){
    ConwayCell cell;
    std::ostringstream os;
    cell.write(os);
    cell.write(os);
    ASSERT_TRUE(os.str() == "..");
}

// ----
// ConwayCell::read
// ----

TEST(Life, ConwayCell_read_1){
    ConwayCell cell;
    std::istringstream is("*");
    cell.read(is);
    ASSERT_TRUE(cell.isAlive());
}

TEST(Life, ConwayCell_read_2){
    ConwayCell cell;
    std::istringstream is(".");
    cell.read(is);
    ASSERT_TRUE(!(cell.isAlive()));
}

TEST(Life, ConwayCell_read_3){
    ConwayCell cell;
    ASSERT_TRUE(!(cell.isAlive()));
    std::istringstream is("-");
    cell.read(is);
    ASSERT_TRUE(!(cell.isAlive()));
}

// ----
// FredkinCell::isEvolving
// ----

TEST(Life, FredkinCell_isEvolving_1){
    FredkinCell cell;
    bool b[] = {0, 0, 0, 1, 0, 0, 0, 0};
    cell.isEvolving(b);
    ASSERT_TRUE(cell.isAlive());
}

TEST(Life, FredkinCell_isEvolving_2){
    FredkinCell cell(true);
    bool b[] = {0, 1, 0, 1, 0, 0, 1, 0};
    cell.isEvolving(b);
    ASSERT_TRUE(cell.isAlive());
    ASSERT_TRUE(cell.age == 1);
}

TEST(Life, FredkinCell_isEvolving_3){
    FredkinCell cell(true);
    bool b[] = {0, 1, 0, 1, 1, 0, 1, 0};
    cell.isEvolving(b);
    ASSERT_TRUE(!(cell.isAlive()));
}

// ----
// FredkinCell::read
// ----

TEST(Life, FredkinCell_read_1){
    FredkinCell cell;
    std::istringstream is("5");
    cell.read(is);
    ASSERT_TRUE(cell.isAlive());
    ASSERT_TRUE(cell.age == 5);
}

TEST(Life, FredkinCell_read_2){
    FredkinCell cell;
    std::istringstream is("-");
    cell.read(is);
    ASSERT_TRUE(!(cell.isAlive()));
    ASSERT_TRUE(cell.age == 0);
}

TEST(Life, FredkinCell_read_3){
    FredkinCell cell;
    ASSERT_TRUE(!(cell.isAlive()));
    std::istringstream is("+++");
    cell.read(is);
    ASSERT_TRUE(cell.isAlive());
    ASSERT_TRUE(cell.age == 10);
}

// ----
// FredkinCell::write
// ----

void test_fc_write_1 () {
    FredkinCell cell(true);
    std::ostringstream os;
    cell.write(os);
    ASSERT_TRUE(os.str() == "0");
}

void test_fc_write_2 () {
    FredkinCell cell(false);
    std::ostringstream os;
    cell.write(os);
    ASSERT_TRUE(os.str() == "-");
}

void test_fc_write_3 () {
    FredkinCell cell(true);
    cell.age = 11;
    std::ostringstream os;
    cell.write(os);
    ASSERT_TRUE(os.str() == "+");
}

// ----
// Life::print
// ----

TEST(Life, Life_print_1){
    std::ostringstream os;
    std::istringstream is("3\n3\n.*.\n.*.\n.*.");
    Life<ConwayCell> life(is);
    life.print(os);
    ASSERT_TRUE(os.str() == "\nGeneration = 0, Population = 3.\n.*.\n.*.\n.*.\n");
}

TEST(Life, Life_print_2){
    std::ostringstream os;
    std::istringstream is("3\n3\n---\n-5-\n-+-");
    Life<FredkinCell> life(is);
    life.print(os);
    ASSERT_TRUE(os.str() == "\nGeneration = 0, Population = 2.\n---\n-5-\n-+-\n");
}

TEST(Life, Life_print_3){
    std::ostringstream os;
    std::istringstream is("3\n3\n---\n---\n---");
    Life<Cell> life(is);
    life.generation = 2;
    life.print(os);
    ASSERT_TRUE(os.str() == "\nGeneration = 2, Population = 0.\n---\n---\n---\n");
}

// ----
// Life::turn
// ----

TEST(Life, Life_generate_1){
    std::istringstream is("3\n3\n...\n***\n...");
    Life<ConwayCell> life(is);
    life.generate();
    ASSERT_TRUE(life.grid[0][1].isAlive());
    ASSERT_TRUE(life.grid[1][1].isAlive());
    ASSERT_TRUE(life.grid[2][1].isAlive());
    ASSERT_TRUE(!(life.grid[1][0].isAlive()));
    ASSERT_TRUE(!(life.grid[1][2].isAlive()));}

TEST(Life, Life_generate_2){
    std::istringstream is("3\n3\n-0-\n---\n---");
    Life<FredkinCell> life(is);
    life.generate();
    ASSERT_TRUE(life.grid[0][0].isAlive());
    ASSERT_TRUE(life.grid[0][2].isAlive());
    ASSERT_TRUE(life.grid[1][1].isAlive());
    ASSERT_TRUE(!(life.grid[0][1].isAlive()));
    ASSERT_TRUE(life.grid[0][0].age == 0);}

TEST(Life, Life_generate_3){
    std::istringstream is("3\n3\n000\n-0-\n---");
    Life<Cell> life(is);
    life.generate();
    life.generate();
    ASSERT_TRUE(life.grid[0][0].isAlive());
    ASSERT_TRUE(life.grid[0][1].isAlive());
    ASSERT_TRUE(life.grid[0][2].isAlive());
    ASSERT_TRUE(!(life.grid[1][0].isAlive()));
    ASSERT_TRUE(!(life.grid[1][1].isAlive()));
    ASSERT_TRUE(!(life.grid[1][2].isAlive()));
    ASSERT_TRUE(life.grid[2][0].isAlive());
    ASSERT_TRUE(life.grid[2][1].isAlive());
    ASSERT_TRUE(life.grid[2][2].isAlive());}

// ----
// Life::multiple_generation
// ----

TEST(Life, Life_multiple_generation_1){
    std::istringstream is("3\n3\n...\n***\n...");
    Life<ConwayCell> life(is);
    life.multiple_generation(5);
    ASSERT_TRUE(!(life.grid[0][0].isAlive()));
    ASSERT_TRUE(life.grid[0][1].isAlive());
    ASSERT_TRUE(!(life.grid[0][2].isAlive()));
    ASSERT_TRUE(!(life.grid[1][0].isAlive()));
    ASSERT_TRUE(life.grid[1][1].isAlive());
    ASSERT_TRUE(!(life.grid[1][2].isAlive()));
    ASSERT_TRUE(!(life.grid[2][0].isAlive()));
    ASSERT_TRUE(life.grid[2][1].isAlive());
    ASSERT_TRUE(!(life.grid[2][2].isAlive()));}