//----------------------------
// Jacob Kovar
// jrk2593
// CS371P 10 am - 11 am
// Professor Glenn Downing
// Project 5 - Life
// 11-21-13
//----------------------------

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

    % g++ -pedantic -std=c++0x -Wall Darwin.c++ TestLife.c++ -o TestLife -lgtest -lpthread -lgtest_main

    % valgrind TestLife > TestLife.out
*/

// --------
// includes
// --------

#include <string>   // ==
#include <stdexcept> // invalid_argument, out_of_range
#include <sstream>  // istringtstream, ostringstream

#include "gtest/gtest.h"

// -------------------------------
// defines to test private methods
// -------------------------------

#define private public
#define protected public
#define class struct

#include "Life.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"

template <typename T>
struct TestLife : testing::Test
{
    typedef Life<T> grid_type;
    typedef T       cell_type;
};

typedef ::testing::Types
    <
        ConwayCell,
        FredkinCell
    > my_types;

TYPED_TEST_CASE(TestLife, my_types);

//------------------------------------------------------------------------------------------------------------------------------------------------------------
// Testing Life.h
//------------------------------------------------------------------------------------------------------------------------------------------------------------

// -------------
// Life::Life<T>
// -------------

TYPED_TEST(TestLife, lconstructor_1)
{
    typedef typename TestFixture::grid_type grid_type;

    try
    {
        grid_type grid(0,0);
        ASSERT_TRUE(false);
    }
    catch (const std::invalid_argument&)
    {
        
    }
    catch (const std::out_of_range& e)
    {
        
    }
}

TYPED_TEST(TestLife, lconstructor_2)
{
    typedef typename TestFixture::grid_type grid_type;

    try
    {
        grid_type grid(-1,1);
        ASSERT_TRUE(false);
    }
    catch (const std::invalid_argument&)
    {
        
    }
    catch (const std::out_of_range&)
    {
        
    }
}

TYPED_TEST(TestLife, lconstructor_3)
{
    typedef typename TestFixture::grid_type grid_type;

    try
    {
        grid_type grid(1,-1);
        ASSERT_TRUE(false);
    }
    catch (const std::invalid_argument&)
    {
        
    }
    catch (const std::out_of_range&)
    {
        
    }
}

TYPED_TEST(TestLife, lconstructor_4)
{
    typedef typename TestFixture::grid_type grid_type;

    try
    {
        grid_type grid(-1,-1);
        ASSERT_TRUE(false);
    }
    catch (const std::invalid_argument&)
    {
        
    }
    catch (const std::out_of_range&)
    {
        
    }
}

TYPED_TEST(TestLife, lconstructor_5)
{
    typedef typename TestFixture::grid_type grid_type;

    try
    {
        grid_type grid(0,0);
        ASSERT_TRUE(false);
    }
    catch (const std::invalid_argument&)
    {
        
    }
    catch (const std::out_of_range&)
    {
        
    }
}

TYPED_TEST(TestLife, lconstructor_6)
{
    typedef typename TestFixture::grid_type grid_type;

    try
    {
        grid_type grid(1,1);
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

// -----------------
// Life::add_to_grid
// -----------------

TYPED_TEST(TestLife, add_to_grid_1)
{
    typedef typename TestFixture::grid_type grid_type;
    typedef typename TestFixture::cell_type cell_type;

    try
    {
        cell_type cell(ALIVE);
        grid_type grid(10,10);

        grid.add_to_grid(0, 0, cell);
        ASSERT_TRUE(grid.grid[1][1] == cell);
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TYPED_TEST(TestLife, add_to_grid_2)
{
    typedef typename TestFixture::grid_type grid_type;
    typedef typename TestFixture::cell_type cell_type;

    try
    {
        cell_type cell(ALIVE);
        grid_type grid(10,10);

        grid.add_to_grid(-1,0, cell);
        ASSERT_TRUE(false);
    }
    catch (const std::invalid_argument&)
    {
        
    }
    catch (const std::out_of_range&)
    {

    }
}

TYPED_TEST(TestLife, add_to_grid_3)
{
    typedef typename TestFixture::grid_type grid_type;
    typedef typename TestFixture::cell_type cell_type;

    try
    {
        cell_type cell(ALIVE);
        grid_type grid(10,10);

        grid.add_to_grid(0,-1, cell);
        ASSERT_TRUE(false);
    }
    catch (const std::invalid_argument&)
    {
        
    }
    catch (const std::out_of_range&)
    {

    }
}

TYPED_TEST(TestLife, add_to_grid_4)
{
    typedef typename TestFixture::grid_type grid_type;
    typedef typename TestFixture::cell_type cell_type;

    try
    {
        cell_type cell(ALIVE);
        grid_type grid(10,10);
        grid.add_to_grid(-1,-1, cell);
        ASSERT_TRUE(false);
    }
    catch (const std::invalid_argument&)
    {
        
    }
    catch (const std::out_of_range&)
    {

    }
}

TYPED_TEST(TestLife, add_to_grid_5)
{
    typedef typename TestFixture::grid_type grid_type;
    typedef typename TestFixture::cell_type cell_type;

    try
    {
        cell_type cell(ALIVE);
        grid_type grid(10,10);
        grid.add_to_grid(0, 0, cell);
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TYPED_TEST(TestLife, add_to_grid_6)
{
    typedef typename TestFixture::grid_type grid_type;
    typedef typename TestFixture::cell_type cell_type;

    try
    {
        cell_type cell(ALIVE);
        grid_type grid(10,10);
        grid.add_to_grid(9, 9, cell);
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TYPED_TEST(TestLife, add_to_grid_7)
{
    typedef typename TestFixture::grid_type grid_type;
    typedef typename TestFixture::cell_type cell_type;

    try
    {
        cell_type cell(ALIVE);
        grid_type grid(10,10);
        grid.add_to_grid(0, 9, cell);
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TYPED_TEST(TestLife, add_to_grid_8)
{
    typedef typename TestFixture::grid_type grid_type;
    typedef typename TestFixture::cell_type cell_type;

    try
    {
        cell_type cell(ALIVE);
        grid_type grid(10,10);
        grid.add_to_grid(9, 0, cell);
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TYPED_TEST(TestLife, add_to_grid_9)
{
    typedef typename TestFixture::grid_type grid_type;
    typedef typename TestFixture::cell_type cell_type;

    try
    {
        cell_type cell(ALIVE);
        grid_type grid(10,10);
        grid.add_to_grid(10, 10, cell);
        ASSERT_TRUE(false);
    }
    catch (const std::invalid_argument&)
    {
        
    }
    catch (const std::out_of_range&)
    {
        
    }
}

TYPED_TEST(TestLife, add_to_grid_10)
{
    typedef typename TestFixture::grid_type grid_type;
    typedef typename TestFixture::cell_type cell_type;

    try
    {
        cell_type cell(ALIVE);
        grid_type grid(10,10);
        grid.add_to_grid(10, 0, cell);
        ASSERT_TRUE(false);
    }
    catch (const std::invalid_argument&)
    {
        
    }
    catch (const std::out_of_range&)
    {
        
    }
}

TYPED_TEST(TestLife, add_to_grid_11)
{
    typedef typename TestFixture::grid_type grid_type;
    typedef typename TestFixture::cell_type cell_type;

    try
    {
        cell_type cell(ALIVE);
        grid_type grid(10,10);
        grid.add_to_grid(0, 10, cell);
        ASSERT_TRUE(false);
    }
    catch (const std::invalid_argument&)
    {
        
    }
    catch (const std::out_of_range&)
    {
        
    }
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------
// \Testing Life.h
//------------------------------------------------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------------------------------------------------
// Testing AbstractCell.c++
//------------------------------------------------------------------------------------------------------------------------------------------------------------

// -------------------
// AbstractCell(State)
// -------------------

TYPED_TEST(TestLife, aconstructors_1)
{
    typedef typename TestFixture::grid_type grid_type;
    typedef typename TestFixture::cell_type cell_type;

    try
    {
        cell_type cell(ALIVE);
        
        ASSERT_TRUE(cell.state == ALIVE);
        ASSERT_TRUE(cell.next_state == ALIVE);
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TYPED_TEST(TestLife, aconstructors_2)
{
    typedef typename TestFixture::grid_type grid_type;
    typedef typename TestFixture::cell_type cell_type;

    try
    {
        cell_type cell(DEAD);
        
        ASSERT_TRUE(cell.state == DEAD);
        ASSERT_TRUE(cell.next_state == DEAD);
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TYPED_TEST(TestLife, aconstructors_3)
{
    typedef typename TestFixture::grid_type grid_type;
    typedef typename TestFixture::cell_type cell_type;

    try
    {
        cell_type cell;
        ASSERT_TRUE(cell.state == DEAD);
        ASSERT_TRUE(cell.next_state == DEAD);
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

// ------
// equals
// ------

TYPED_TEST(TestLife, aequals_1)
{
    typedef typename TestFixture::grid_type grid_type;
    typedef typename TestFixture::cell_type cell_type;

    try
    {
        cell_type cell(ALIVE);
        cell_type cell2(ALIVE);
        ASSERT_TRUE(cell.equals(cell2));
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TYPED_TEST(TestLife, aequals_2)
{
    typedef typename TestFixture::grid_type grid_type;
    typedef typename TestFixture::cell_type cell_type;

    try
    {
        cell_type cell(DEAD);
        cell_type cell2(DEAD);
        ASSERT_TRUE(cell.equals(cell2));
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TYPED_TEST(TestLife, aequals_3)
{
    typedef typename TestFixture::grid_type grid_type;
    typedef typename TestFixture::cell_type cell_type;

    try
    {
        cell_type cell(ALIVE);
        cell_type cell2(DEAD);
        ASSERT_TRUE(!cell.equals(cell2));
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TYPED_TEST(TestLife, aequals_4)
{
    typedef typename TestFixture::grid_type grid_type;
    typedef typename TestFixture::cell_type cell_type;

    try
    {
        cell_type cell(DEAD);
        cell_type cell2(ALIVE);
        ASSERT_TRUE(!cell.equals(cell2));
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

// -------------
// is_cell_alive
// -------------

TYPED_TEST(TestLife, is_alive_1)
{
    typedef typename TestFixture::grid_type grid_type;
    typedef typename TestFixture::cell_type cell_type;

    try
    {
        cell_type cell(ALIVE);
        ASSERT_TRUE(cell.is_cell_alive());
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TYPED_TEST(TestLife, is_alive_2)
{
    typedef typename TestFixture::grid_type grid_type;
    typedef typename TestFixture::cell_type cell_type;

    try
    {
        cell_type cell(DEAD);
        ASSERT_TRUE(!cell.is_cell_alive());
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TYPED_TEST(TestLife, is_alive_3)
{
    typedef typename TestFixture::grid_type grid_type;
    typedef typename TestFixture::cell_type cell_type;

    try
    {
        cell_type cell;
        ASSERT_TRUE(!cell.is_cell_alive());
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

// -----------------
// assume_next_state
// -----------------

TYPED_TEST(TestLife, as_ne_st_1)
{
    typedef typename TestFixture::grid_type grid_type;
    typedef typename TestFixture::cell_type cell_type;

    try
    {
        cell_type cell(ALIVE);
        cell.next_state = DEAD;
        cell.assume_next_state();

        ASSERT_TRUE(cell.state == DEAD);
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TYPED_TEST(TestLife, as_ne_st_2)
{
    typedef typename TestFixture::grid_type grid_type;
    typedef typename TestFixture::cell_type cell_type;

    try
    {
        cell_type cell(DEAD);
        cell.next_state = ALIVE;
        cell.assume_next_state();

        ASSERT_TRUE(cell.state == ALIVE);
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TYPED_TEST(TestLife, as_ne_st_3)
{
    typedef typename TestFixture::grid_type grid_type;
    typedef typename TestFixture::cell_type cell_type;

    try
    {
        cell_type cell(DEAD);
        cell.next_state = DEAD;
        cell.assume_next_state();

        ASSERT_TRUE(cell.state == DEAD);
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TYPED_TEST(TestLife, as_ne_st_4)
{
    typedef typename TestFixture::grid_type grid_type;
    typedef typename TestFixture::cell_type cell_type;

    try
    {
        cell_type cell(ALIVE);
        cell.next_state = ALIVE;
        cell.assume_next_state();

        ASSERT_TRUE(cell.state == ALIVE);
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------
// \Testing AbstractCell.c++
//------------------------------------------------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------------------------------------------------
// Testing ConwayCell.c++
//------------------------------------------------------------------------------------------------------------------------------------------------------------

// ------------------
// ConwayCell::equals
// ------------------

TEST(ConwayCell, eq_1)
{
    try
    {
        ConwayCell cell(ALIVE);
        ConwayCell cell2(ALIVE);

        ASSERT_TRUE(cell.equals(cell2));
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TEST(ConwayCell, eq_2)
{
    try
    {
        ConwayCell cell(ALIVE);
        ConwayCell cell2(DEAD);

        ASSERT_TRUE(!cell.equals(cell2));
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TEST(ConwayCell, eq_3)
{
    try
    {
        ConwayCell cell(DEAD);
        ConwayCell cell2(DEAD);

        ASSERT_TRUE(cell.equals(cell2));
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TEST(ConwayCell, eq_4)
{
    try
    {
        ConwayCell cell(DEAD);
        ConwayCell cell2(ALIVE);

        ASSERT_TRUE(!cell.equals(cell2));
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TEST(ConwayCell, eq_5)
{
    try
    {
        ConwayCell cell(ALIVE);
        FredkinCell cell2(ALIVE);

        ASSERT_TRUE(!cell.equals(cell2));
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TEST(ConwayCell, eq_6)
{
    try
    {
        ConwayCell cell(DEAD);
        FredkinCell cell2(DEAD);

        ASSERT_TRUE(!cell.equals(cell2));
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TEST(ConwayCell, eq_7)
{
    try
    {
        ConwayCell cell(ALIVE);
        FredkinCell cell2(DEAD);

        ASSERT_TRUE(!cell.equals(cell2));
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TEST(ConwayCell, eq_8)
{
    try
    {
        ConwayCell cell(DEAD);
        FredkinCell cell2(ALIVE);

        ASSERT_TRUE(!cell.equals(cell2));
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

// -----------------
// ConwayCell::write
// -----------------

TEST(ConwayCell, wr_1)
{
    try
    {
        ConwayCell cell(ALIVE);

        std::ostringstream out;
        cell.write(out);

        ASSERT_TRUE(out.str() == "*");
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TEST(ConwayCell, wr_2)
{
    try
    {
        ConwayCell cell(DEAD);

        std::ostringstream out;
        cell.write(out);

        ASSERT_TRUE(out.str() == ".");
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TEST(ConwayCell, wr_3)
{
    try
    {
        ConwayCell cell(ALIVE);
        cell.state = DEAD;

        std::ostringstream out;
        cell.write(out);

        ASSERT_TRUE(out.str() == ".");
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TEST(ConwayCell, wr_4)
{
    try
    {
        ConwayCell cell(DEAD);
        cell.state = ALIVE;

        std::ostringstream out;
        cell.write(out);

        ASSERT_TRUE(out.str() == "*");
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

// --------------------------------
// ConwayCell::determine_next_state
// --------------------------------

TEST(ConwayCell, de_ne_st_1)
{
    try
    {
        ConwayCell cell(ALIVE);
        //                   W      N     E     S      NW     NE     SE     SW
        bool neighbors[] = {true, true, true, false, false, false, false, false};
        cell.determine_next_state(neighbors);

        ASSERT_TRUE(cell.next_state == ALIVE);
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TEST(ConwayCell, de_ne_st_2)
{
    try
    {
        ConwayCell cell(ALIVE);
        //                   W      N     E     S      NW     NE     SE     SW
        bool neighbors[] = {true, true, false, false, false, false, false, false};
        cell.determine_next_state(neighbors);

        ASSERT_TRUE(cell.next_state == ALIVE);
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TEST(ConwayCell, de_ne_st_3)
{
    try
    {
        ConwayCell cell(DEAD);
        //                   W      N     E     S      NW     NE     SE     SW
        bool neighbors[] = {true, true, true, false, false, false, false, false};
        cell.determine_next_state(neighbors);

        ASSERT_TRUE(cell.next_state == ALIVE);
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TEST(ConwayCell, de_ne_st_4)
{
    try
    {
        ConwayCell cell(ALIVE);
        //                   W       N      E     S      NW     NE     SE     SW
        bool neighbors[] = {true, false, false, false, false, false, false, false};
        cell.determine_next_state(neighbors);

        ASSERT_TRUE(cell.next_state == DEAD);
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TEST(ConwayCell, de_ne_st_5)
{
    try
    {
        ConwayCell cell(ALIVE);
        //                   W     N      E     S     NW     NE     SE     SW
        bool neighbors[] = {true, true, true, true, false, false, false, false};
        cell.determine_next_state(neighbors);

        ASSERT_TRUE(cell.next_state == DEAD);
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TEST(ConwayCell, de_ne_st_6)
{
    try
    {
        ConwayCell cell(DEAD);
        //                   W     N      E     S     NW     NE     SE     SW
        bool neighbors[] = {true, true, true, true, false, false, false, false};
        cell.determine_next_state(neighbors);

        ASSERT_TRUE(cell.next_state == DEAD);
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TEST(ConwayCell, de_ne_st_7)
{
    try
    {
        ConwayCell cell(DEAD);
        //                   W     N      E      S     NW     NE     SE     SW
        bool neighbors[] = {true, true, false, false, false, false, false, false};
        cell.determine_next_state(neighbors);

        ASSERT_TRUE(cell.next_state == DEAD);
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

// -----------------
// ConwayCell::clone
// -----------------

TEST(ConwayCell, cl_1)
{
    try
    {
        ConwayCell cell(ALIVE);
        ConwayCell* cell2 = cell.clone();

        ASSERT_TRUE(cell == *cell2);
        ASSERT_TRUE(cell.state == cell2->state);
        ASSERT_TRUE(cell.next_state == cell2->next_state);

        delete cell2;
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TEST(ConwayCell, cl_2)
{
    try
    {
        ConwayCell cell(DEAD);
        ConwayCell* cell2 = cell.clone();

        ASSERT_TRUE(cell == *cell2);
        ASSERT_TRUE(cell.state == cell2->state);
        ASSERT_TRUE(cell.next_state == cell2->next_state);

        delete cell2;
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TEST(ConwayCell, cl_3)
{
    try
    {
        ConwayCell cell(ALIVE);
        ConwayCell* cell2 = cell.clone();
        cell.state = DEAD;
        cell.next_state = DEAD;

        ASSERT_FALSE(cell == *cell2);
        ASSERT_FALSE(cell.state == cell2->state);
        ASSERT_FALSE(cell.next_state == cell2->next_state);

        delete cell2;
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------
// Testing \ConwayCell.c++
//------------------------------------------------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------------------------------------------------
// Testing FredkinCell.c++
//------------------------------------------------------------------------------------------------------------------------------------------------------------

// -------------------
// FredkinCell::equals
// -------------------

TEST(FredkinCell, eq_1)
{
    try
    {
        FredkinCell cell(ALIVE);
        FredkinCell cell2(ALIVE);

        ASSERT_TRUE(cell.equals(cell2));
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TEST(FredkinCell, eq_2)
{
    try
    {
        FredkinCell cell(ALIVE);
        FredkinCell cell2(DEAD);

        ASSERT_TRUE(!cell.equals(cell2));
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TEST(FredkinCell, eq_3)
{
    try
    {
        FredkinCell cell(DEAD);
        FredkinCell cell2(DEAD);

        ASSERT_TRUE(cell.equals(cell2));
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TEST(FredkinCell, eq_4)
{
    try
    {
        FredkinCell cell(DEAD);
        FredkinCell cell2(ALIVE);

        ASSERT_TRUE(!cell.equals(cell2));
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TEST(FredkinCell, eq_5)
{
    try
    {
        FredkinCell cell(ALIVE);
        ConwayCell cell2(ALIVE);

        ASSERT_TRUE(!cell.equals(cell2));
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TEST(FredkinCell, eq_6)
{
    try
    {
        FredkinCell cell(DEAD);
        ConwayCell cell2(DEAD);

        ASSERT_TRUE(!cell.equals(cell2));
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TEST(FredkinCell, eq_7)
{
    try
    {
        FredkinCell cell(ALIVE);
        ConwayCell cell2(DEAD);

        ASSERT_TRUE(!cell.equals(cell2));
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TEST(FredkinCell, eq_8)
{
    try
    {
        FredkinCell cell(DEAD);
        ConwayCell cell2(ALIVE);

        ASSERT_TRUE(!cell.equals(cell2));
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

// ------------------
// FredkinCell::write
// ------------------

TEST(FredkinCell, wr_1)
{
    try
    {
        FredkinCell cell(ALIVE);

        std::ostringstream out;
        cell.write(out);

        ASSERT_TRUE(out.str() == "0");
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TEST(FredkinCell, wr_2)
{
    try
    {
        FredkinCell cell(DEAD);

        std::ostringstream out;
        cell.write(out);

        ASSERT_TRUE(out.str() == "-");
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TEST(FredkinCell, wr_3)
{
    try
    {
        FredkinCell cell(ALIVE);
        cell.state = DEAD;

        std::ostringstream out;
        cell.write(out);

        ASSERT_TRUE(out.str() == "-");
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TEST(FredkinCell, wr_4)
{
    try
    {
        FredkinCell cell(DEAD);
        cell.state = ALIVE;

        std::ostringstream out;
        cell.write(out);

        ASSERT_TRUE(out.str() == "0");
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TEST(FredkinCell, wr_5)
{
    try
    {
        FredkinCell cell(ALIVE);
        cell.age = 9;

        std::ostringstream out;
        cell.write(out);

        ASSERT_TRUE(out.str() == "9");
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TEST(FredkinCell, wr_6)
{
    try
    {
        FredkinCell cell(ALIVE);
        cell.age = 10;

        std::ostringstream out;
        cell.write(out);

        ASSERT_TRUE(out.str() == "+");
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

// ---------------------------------
// FredkinCell::determine_next_state
// ---------------------------------

TEST(FredkinCell, de_ne_st_1)
{
    try
    {
        FredkinCell cell(ALIVE);
        //                   W      N     E     S     
        bool neighbors[] = {true, true, true, false};
        cell.determine_next_state(neighbors);

        ASSERT_TRUE(cell.next_state == ALIVE);
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TEST(FredkinCell, de_ne_st_2)
{
    try
    {
        FredkinCell cell(ALIVE);
        //                   W       N     E      S
        bool neighbors[] = {false, true, false, false};
        cell.determine_next_state(neighbors);

        ASSERT_TRUE(cell.next_state == ALIVE);
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TEST(FredkinCell, de_ne_st_3)
{
    try
    {
        FredkinCell cell(DEAD);
        //                   W       N     E      S
        bool neighbors[] = {false, true, false, false};
        cell.determine_next_state(neighbors);

        ASSERT_TRUE(cell.next_state == ALIVE);
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TEST(FredkinCell, de_ne_st_4)
{
    try
    {
        FredkinCell cell(ALIVE);
        //                   W      N     E     S    
        bool neighbors[] = {true, true, false, false};
        cell.determine_next_state(neighbors);

        ASSERT_TRUE(cell.next_state == DEAD);
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TEST(FredkinCell, de_ne_st_5)
{
    try
    {
        FredkinCell cell(ALIVE);
        //                   W     N      E     S  
        bool neighbors[] = {true, true, true, true};
        cell.determine_next_state(neighbors);

        ASSERT_TRUE(cell.next_state == DEAD);
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TEST(FredkinCell, de_ne_st_6)
{
    try
    {
        FredkinCell cell(DEAD);
        //                   W     N      E     S  
        bool neighbors[] = {true, true, true, true};
        cell.determine_next_state(neighbors);

        ASSERT_TRUE(cell.next_state == DEAD);
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TEST(FredkinCell, de_ne_st_7)
{
    try
    {
        FredkinCell cell(DEAD);
        //                    W      N      E      S    
        bool neighbors[] = {false, false, false, false};
        cell.determine_next_state(neighbors);

        ASSERT_TRUE(cell.next_state == DEAD);
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

// ------------------------------
// FredkinCell::assume_next_state
// ------------------------------

TEST(FredkinCell, as_ne_st_1)
{
    try
    {
        FredkinCell cell(ALIVE);
        cell.assume_next_state();

        ASSERT_TRUE(cell.state == ALIVE);
        ASSERT_TRUE(cell.age == 1);
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TEST(FredkinCell, as_ne_st_2)
{
    try
    {
        FredkinCell cell(DEAD);
        cell.assume_next_state();

        ASSERT_TRUE(cell.state == DEAD);
        ASSERT_TRUE(cell.age == 0);
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TEST(FredkinCell, as_ne_st_3)
{
    try
    {
        FredkinCell cell(DEAD);
        cell.next_state = ALIVE;
        cell.assume_next_state();

        ASSERT_TRUE(cell.state == ALIVE);
        ASSERT_TRUE(cell.age == 0);
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TEST(FredkinCell, as_ne_st_4)
{
    try
    {
        FredkinCell cell(ALIVE);
        cell.next_state = DEAD;
        cell.assume_next_state();

        ASSERT_TRUE(cell.state == DEAD);
        ASSERT_TRUE(cell.age == 0);
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

// --------------------------
// FredkinCell::is_older_than
// --------------------------

TEST(FredkinCell, is_ol_th_1)
{
    try
    {
        FredkinCell cell(ALIVE);
        
        ASSERT_TRUE(!cell.is_older_than(0));
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TEST(FredkinCell, is_ol_th_2)
{
    try
    {
        FredkinCell cell(ALIVE);
        cell.age = 1;

        ASSERT_TRUE(cell.is_older_than(0));
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TEST(FredkinCell, is_ol_th_3)
{
    try
    {
        FredkinCell cell(ALIVE);
        
        ASSERT_TRUE(!cell.is_older_than(1));
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

// ------------------
// FredkinCell::clone
// ------------------

TEST(FredkinCell, cl_1)
{
    try
    {
        FredkinCell cell(ALIVE);
        FredkinCell* cell2 = cell.clone();

        ASSERT_TRUE(cell == *cell2);
        ASSERT_TRUE(cell.age == cell2->age);
        ASSERT_TRUE(cell.state == cell2->state);
        ASSERT_TRUE(cell.next_state == cell2->next_state);

        delete cell2;
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TEST(FredkinCell, cl_2)
{
    try
    {
        FredkinCell cell(DEAD);
        FredkinCell* cell2 = cell.clone();

        ASSERT_TRUE(cell == *cell2);
        ASSERT_TRUE(cell.age == cell2->age);
        ASSERT_TRUE(cell.state == cell2->state);
        ASSERT_TRUE(cell.next_state == cell2->next_state);

        delete cell2;
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TEST(FredkinCell, cl_3)
{
    try
    {
        FredkinCell cell(ALIVE);
        FredkinCell* cell2 = cell.clone();
        cell.age = 1;
        cell.state = DEAD;
        cell.next_state = DEAD;

        ASSERT_FALSE(cell == *cell2);
        ASSERT_FALSE(cell.age == cell2->age);
        ASSERT_FALSE(cell.state == cell2->state);
        ASSERT_FALSE(cell.next_state == cell2->next_state);

        delete cell2;
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TEST(FredkinCell, cl_4)
{
    try
    {
        FredkinCell cell(ALIVE);
        FredkinCell* cell2 = cell.clone();
        cell.age = 1;

        ASSERT_FALSE(cell == *cell2);

        delete cell2;
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------
// \Testing FredkinCell.c++
//------------------------------------------------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------------------------------------------------
// Testing Cell.c++
//------------------------------------------------------------------------------------------------------------------------------------------------------------

// ----------
// Cell::Cell
// ----------

TYPED_TEST(TestLife, cell_con_1)
{
    typedef typename TestFixture::grid_type grid_type;
    typedef typename TestFixture::cell_type cell_type;

    try
    {
        AbstractCell *pcell = new cell_type(ALIVE);
        Cell cell(pcell);

        ASSERT_TRUE(cell._p == pcell);
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TEST(Cell, cell_con_2)
{
    try
    {
        Cell cell(0);

        ASSERT_TRUE(cell._p == 0);
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TEST(Cell, cell_con_3)
{
    try
    {
        Cell cell;

        ASSERT_TRUE(cell._p == 0);
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

// --------------------------
// Cell::determine_next_state
// --------------------------

TYPED_TEST(TestLife, de_ne_st_1)
{
    typedef typename TestFixture::grid_type grid_type;
    typedef typename TestFixture::cell_type cell_type;

    try
    {
        AbstractCell *pcell = new cell_type(ALIVE);
        Cell cell(pcell);

        if(const ConwayCell* const p = dynamic_cast<const ConwayCell*>(pcell))
        {
            //                   W      N     E     S      NW     NE     SE     SW
            bool neighbors[] = {true, true, true, false, false, false, false, false};
            cell.determine_next_state(neighbors);

            ASSERT_TRUE(cell._p->next_state == ALIVE);
        }
        else
        {
            //                   W      N     E     S     
            bool neighbors[] = {true, true, true, false};
            cell.determine_next_state(neighbors);

            ASSERT_TRUE(cell._p->next_state == ALIVE);
        }
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TYPED_TEST(TestLife, de_ne_st_2)
{
    typedef typename TestFixture::grid_type grid_type;
    typedef typename TestFixture::cell_type cell_type;

    try
    {
        AbstractCell *pcell = new cell_type(ALIVE);
        Cell cell(pcell);

        if(const ConwayCell* const p = dynamic_cast<const ConwayCell*>(pcell))
        {
            //                   W      N     E     S      NW     NE     SE     SW
            bool neighbors[] = {true, true, false, false, false, false, false, false};
            cell.determine_next_state(neighbors);

            ASSERT_TRUE(cell._p->next_state == ALIVE);
        }
        else
        {
            //                   W       N     E      S
            bool neighbors[] = {false, true, false, false};
            cell.determine_next_state(neighbors);

            ASSERT_TRUE(cell._p->next_state == ALIVE);
        }
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TYPED_TEST(TestLife, de_ne_st_3)
{
    typedef typename TestFixture::grid_type grid_type;
    typedef typename TestFixture::cell_type cell_type;

    try
    {
        AbstractCell *pcell = new cell_type(DEAD);
        Cell cell(pcell);

        if(const ConwayCell* const p = dynamic_cast<const ConwayCell*>(pcell))
        {
            //                   W      N     E     S      NW     NE     SE     SW
            bool neighbors[] = {true, true, true, false, false, false, false, false};
            cell.determine_next_state(neighbors);

            ASSERT_TRUE(cell._p->next_state == ALIVE);
        }
        else
        {
            //                   W       N     E      S
            bool neighbors[] = {false, true, false, false};
            cell.determine_next_state(neighbors);

            ASSERT_TRUE(cell._p->next_state == ALIVE);
        }
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TYPED_TEST(TestLife, de_ne_st_4)
{
    typedef typename TestFixture::grid_type grid_type;
    typedef typename TestFixture::cell_type cell_type;

    try
    {
        AbstractCell *pcell = new cell_type(ALIVE);
        Cell cell(pcell);

        if(const ConwayCell* const p = dynamic_cast<const ConwayCell*>(pcell))
        {
            //                   W       N      E     S      NW     NE     SE     SW
            bool neighbors[] = {true, false, false, false, false, false, false, false};
            cell.determine_next_state(neighbors);

            ASSERT_TRUE(cell._p->next_state == DEAD);
        }
        else
        {
            //                   W      N     E     S    
            bool neighbors[] = {true, true, false, false};
            cell.determine_next_state(neighbors);

            ASSERT_TRUE(cell._p->next_state == DEAD);
        }
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TYPED_TEST(TestLife, de_ne_st_5)
{
    typedef typename TestFixture::grid_type grid_type;
    typedef typename TestFixture::cell_type cell_type;

    try
    {
        AbstractCell *pcell = new cell_type(ALIVE);
        Cell cell(pcell);

        if(const ConwayCell* const p = dynamic_cast<const ConwayCell*>(pcell))
        {
            //                   W     N      E     S     NW     NE     SE     SW
            bool neighbors[] = {true, true, true, true, false, false, false, false};
            cell.determine_next_state(neighbors);

            ASSERT_TRUE(cell._p->next_state == DEAD);
        }
        else
        {
            //                   W     N      E     S  
            bool neighbors[] = {true, true, true, true};
            cell.determine_next_state(neighbors);

            ASSERT_TRUE(cell._p->next_state == DEAD);
        }
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TYPED_TEST(TestLife, de_ne_st_6)
{
    typedef typename TestFixture::grid_type grid_type;
    typedef typename TestFixture::cell_type cell_type;

    try
    {
        AbstractCell *pcell = new cell_type(DEAD);
        Cell cell(pcell);

        if(const ConwayCell* const p = dynamic_cast<const ConwayCell*>(pcell))
        {
            //                   W     N      E     S     NW     NE     SE     SW
            bool neighbors[] = {true, true, true, true, false, false, false, false};
            cell.determine_next_state(neighbors);

            ASSERT_TRUE(cell._p->next_state == DEAD);
        }
        else
        {
            //                   W     N      E     S  
            bool neighbors[] = {true, true, true, true};
            cell.determine_next_state(neighbors);

            ASSERT_TRUE(cell._p->next_state == DEAD);
        }
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TYPED_TEST(TestLife, de_ne_st_7)
{
    typedef typename TestFixture::grid_type grid_type;
    typedef typename TestFixture::cell_type cell_type;

    try
    {
        AbstractCell *pcell = new cell_type(DEAD);
        Cell cell(pcell);

        if(const ConwayCell* const p = dynamic_cast<const ConwayCell*>(pcell))
        {
            //                   W     N      E      S     NW     NE     SE     SW
            bool neighbors[] = {true, true, false, false, false, false, false, false};
            cell.determine_next_state(neighbors);

            ASSERT_TRUE(cell._p->next_state == DEAD);
            }
        else
        {
            //                    W      N      E      S    
            bool neighbors[] = {false, false, false, false};
            cell.determine_next_state(neighbors);

            ASSERT_TRUE(cell._p->next_state == DEAD);
        }
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

// -------------------
// Cell::is_cell_alive
// -------------------

TYPED_TEST(TestLife, is_ce_al_1)
{
    typedef typename TestFixture::grid_type grid_type;
    typedef typename TestFixture::cell_type cell_type;

    try
    {
        AbstractCell *pcell = new cell_type(ALIVE);
        Cell cell(pcell);

        ASSERT_TRUE(cell.is_cell_alive());
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TYPED_TEST(TestLife, is_ce_al_2)
{
    typedef typename TestFixture::grid_type grid_type;
    typedef typename TestFixture::cell_type cell_type;

    try
    {
        AbstractCell *pcell = new cell_type(DEAD);
        Cell cell(pcell);

        ASSERT_TRUE(!cell.is_cell_alive());
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TEST(Cell, is_ce_al_3)
{
    try
    {
        Cell cell(0);

        ASSERT_TRUE(!cell.is_cell_alive());
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TEST(Cell, is_ce_al_4)
{
    try
    {
        Cell cell;

        ASSERT_TRUE(!cell.is_cell_alive());
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

// -----------------------
// Cell::assume_next_state
// -----------------------

TYPED_TEST(TestLife, cell_as_ne_st_1)
{
    typedef typename TestFixture::grid_type grid_type;
    typedef typename TestFixture::cell_type cell_type;

    try
    {
        AbstractCell *pcell = new cell_type(ALIVE);
        Cell cell(pcell);
        cell._p->next_state = DEAD;
        cell.assume_next_state();

        ASSERT_TRUE(cell._p->state == DEAD);
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TYPED_TEST(TestLife, cell_as_ne_st_2)
{
    typedef typename TestFixture::grid_type grid_type;
    typedef typename TestFixture::cell_type cell_type;

    try
    {
        AbstractCell *pcell = new cell_type(DEAD);
        Cell cell(pcell);
        cell._p->next_state = ALIVE;
        cell.assume_next_state();

        ASSERT_TRUE(cell._p->state == ALIVE);
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TYPED_TEST(TestLife, cell_as_ne_st_3)
{
    typedef typename TestFixture::grid_type grid_type;
    typedef typename TestFixture::cell_type cell_type;

    try
    {
        AbstractCell *pcell = new cell_type(DEAD);
        Cell cell(pcell);
        cell._p->next_state = DEAD;
        cell.assume_next_state();

        ASSERT_TRUE(cell._p->state == DEAD);
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TYPED_TEST(TestLife, cell_as_ne_st_4)
{
    typedef typename TestFixture::grid_type grid_type;
    typedef typename TestFixture::cell_type cell_type;

    try
    {
        AbstractCell *pcell = new cell_type(ALIVE);
        Cell cell(pcell);
        cell._p->next_state = ALIVE;
        cell.assume_next_state();

        ASSERT_TRUE(cell._p->state == ALIVE);
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TEST(Cell, cell_as_ne_st_5)
{
    try
    {
        FredkinCell *pcell = new FredkinCell(ALIVE);
        pcell->age = 2;

        Cell cell(pcell);
        cell.assume_next_state();

        ASSERT_TRUE(cell._p != pcell);

        const ConwayCell* const p = dynamic_cast<const ConwayCell*>(cell._p);

        ASSERT_TRUE(p != 0);
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TEST(Cell, cell_as_ne_st_6)
{
    try
    {
        FredkinCell *pcell = new FredkinCell(ALIVE);
        pcell->age = 10;

        Cell cell(pcell);
        cell.assume_next_state();

        ASSERT_TRUE(cell._p != pcell);

        const ConwayCell* const p = dynamic_cast<const ConwayCell*>(cell._p);

        ASSERT_TRUE(p != 0);
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TEST(Cell, cell_as_ne_st_7)
{
    try
    {
        FredkinCell *pcell = new FredkinCell(ALIVE);
        pcell->age = 0;

        Cell cell(pcell);
        cell.assume_next_state();

        ASSERT_TRUE(cell._p == pcell);

        const ConwayCell* const p = dynamic_cast<const ConwayCell*>(cell._p);

        ASSERT_TRUE(p == 0);
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

// ------------
// Cell::mutate
// ------------

TEST(Cell, mu_1)
{
    try
    {
        FredkinCell *pcell = new FredkinCell(ALIVE);
        pcell->age = 2;

        Cell cell(pcell);
        cell.mutate();

        ASSERT_TRUE(cell._p != pcell);

        const ConwayCell* const p = dynamic_cast<const ConwayCell*>(cell._p);

        ASSERT_TRUE(p != 0);
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TEST(Cell, mu_2)
{
    try
    {
        FredkinCell *pcell = new FredkinCell(ALIVE);
        pcell->age = 10;

        Cell cell(pcell);
        cell.mutate();

        ASSERT_TRUE(cell._p != pcell);

        const ConwayCell* const p = dynamic_cast<const ConwayCell*>(cell._p);

        ASSERT_TRUE(p != 0);
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TEST(Cell, mu_3)
{
    try
    {
        FredkinCell *pcell = new FredkinCell(ALIVE);
        pcell->age = 0;

        Cell cell(pcell);
        cell.mutate();

        ASSERT_TRUE(cell._p == pcell);

        const ConwayCell* const p = dynamic_cast<const ConwayCell*>(cell._p);

        ASSERT_TRUE(p == 0);
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TEST(Cell, mu_4)
{
    try
    {
        ConwayCell *pcell = new ConwayCell(ALIVE);

        Cell cell(pcell);
        cell.mutate();

        ASSERT_TRUE(cell._p == pcell);
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

// -----------------------
// Cell::friend operator<<
// -----------------------

TYPED_TEST(TestLife, fr_op_1)
{
    typedef typename TestFixture::grid_type grid_type;
    typedef typename TestFixture::cell_type cell_type;

    try
    {
        AbstractCell *pcell = new cell_type(DEAD);
        Cell cell(pcell);

        std::ostringstream out;
        out << cell;

        if(const ConwayCell* const p = dynamic_cast<const ConwayCell*>(pcell))
        {
            ASSERT_TRUE(out.str() == ".");
        }
        else
        {
            ASSERT_TRUE(out.str() == "-");
        }
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TYPED_TEST(TestLife, fr_op_2)
{
    typedef typename TestFixture::grid_type grid_type;
    typedef typename TestFixture::cell_type cell_type;

    try
    {
        AbstractCell *pcell = new cell_type(ALIVE);
        Cell cell(pcell);

        std::ostringstream out;
        out << cell;

        if(const ConwayCell* const p = dynamic_cast<const ConwayCell*>(pcell))
        {
            ASSERT_TRUE(out.str() == "*");
        }
        else
        {
            ASSERT_TRUE(out.str() == "0");
        }
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TYPED_TEST(TestLife, fr_op_3)
{
    typedef typename TestFixture::grid_type grid_type;
    typedef typename TestFixture::cell_type cell_type;

    try
    {
        AbstractCell *pcell = new cell_type(ALIVE);
        Cell cell(pcell);

        std::ostringstream out;

        if(FredkinCell* const p = dynamic_cast<FredkinCell*>(pcell))
        {
            p->age = 2;
            cell.mutate();

            out << cell;
            ASSERT_TRUE(out.str() == "*");
        }
        else
        {
            out << cell;
            ASSERT_TRUE(out.str() == "*");
        }
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

TYPED_TEST(TestLife, fr_op_4)
{
    typedef typename TestFixture::grid_type grid_type;
    typedef typename TestFixture::cell_type cell_type;

    try
    {
        AbstractCell *pcell = new cell_type(ALIVE);
        Cell cell(pcell);

        std::ostringstream out;

        if(FredkinCell* const p = dynamic_cast<FredkinCell*>(cell._p))
        {
            p->age = 0;
            cell.mutate();

            out << cell;
            ASSERT_TRUE(out.str() == "0");   
        }
        else
        {
            out << cell;
            ASSERT_TRUE(out.str() == "*");
        }
    }
    catch (const std::invalid_argument&)
    {
        ASSERT_TRUE(false);
    }
    catch (const std::out_of_range&)
    {
        ASSERT_TRUE(false);
    }
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------
// \Testing Cell.c++
//------------------------------------------------------------------------------------------------------------------------------------------------------------