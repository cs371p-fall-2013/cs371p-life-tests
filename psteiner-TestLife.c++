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

    % g++ -pedantic -std=c++0x -Wall Life.c++ TestLife.c++ -o TestLife -lgtest -lpthread -lgtest_main

    % valgrind TestLife > TestLife.out
*/

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==

#include "gtest/gtest.h"

#include "Life.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"

// -----------
// TestLife
// -----------

TEST(Cell, ConwayCell_dead) {
    ConwayCell cell(false);
    std::ostringstream w;
    w << cell;
    ASSERT_TRUE(w.str() == ".");
    ASSERT_FALSE(cell.isAlive(0));
}

TEST(Cell, ConwayCell_alive) {
    ConwayCell cell(true);
    std::ostringstream w;
    w << cell;
    ASSERT_TRUE(w.str() == "*");
    ASSERT_TRUE(cell.isAlive(0));
}

TEST(Cell, ConwayCell_dead_from_char) {
    ConwayCell cell('.');
    std::ostringstream w;
    w << cell;
    ASSERT_TRUE(w.str() == ".");
    ASSERT_FALSE(cell.isAlive(0));
}

TEST(Cell, ConwayCell_alive_from_char) {
    ConwayCell cell('*');
    std::ostringstream w;
    w << cell;
    ASSERT_TRUE(w.str() == "*");
    ASSERT_TRUE(cell.isAlive(0));
}

TEST(Cell, FredkinCell_dead) {
    FredkinCell cell(false);
    std::ostringstream w;
    w << cell;
    ASSERT_TRUE(w.str() == "-");
    ASSERT_FALSE(cell.isAlive(0));
}

TEST(Cell, FredkinCell_alive) {
    FredkinCell cell(true);
    std::ostringstream w;
    w << cell;
    ASSERT_TRUE(w.str() == "0");
    ASSERT_TRUE(cell.isAlive(0));
}

TEST(Cell, FredkinCell_dead_from_char) {
    FredkinCell cell('-');
    std::ostringstream w;
    w << cell;
    ASSERT_TRUE(w.str() == "-");
    ASSERT_FALSE(cell.isAlive(0));
}

TEST(Cell, FredkinCell_alive_from_char) {
    FredkinCell cell('0');
    std::ostringstream w;
    w << cell;
    ASSERT_TRUE(w.str() == "0");
    ASSERT_TRUE(cell.isAlive(0));
}

TEST(Cell, Cell_as_ConwayCell_dead) {
    Cell cell('.');
    std::ostringstream w;
    w << cell;
    ASSERT_TRUE(w.str() == ".");
    ASSERT_FALSE(cell.isAlive(0));
}

TEST(Cell, Cell_as_ConwayCell_alive) {
    Cell cell('*');
    std::ostringstream w;
    w << cell;
    ASSERT_TRUE(w.str() == "*");
    ASSERT_TRUE(cell.isAlive(0));
}

TEST(Cell, Cell_as_FredkinCell_dead) {
    Cell cell('-');
    std::ostringstream w;
    w << cell;
    ASSERT_TRUE(w.str() == "-");
    ASSERT_FALSE(cell.isAlive(0));
}

TEST(Cell, Cell_as_FredkinCell_alive) {
    Cell cell('0');
    std::ostringstream w;
    w << cell;
    ASSERT_TRUE(w.str() == "0");
    ASSERT_TRUE(cell.isAlive(0));
}

TEST(Cell, ConwayCell_invalid_arg) {
    
    try {
        ConwayCell cell('d');
        ASSERT_TRUE(false);
    } catch (const std::invalid_argument& e) {
        ASSERT_TRUE(true);
    } catch (...) {
        ASSERT_TRUE(false);
    }
    
}

TEST(Cell, FredkinCell_invalid_arg) {
    
    try {
        FredkinCell cell('d');
        ASSERT_TRUE(false);
    } catch (const std::invalid_argument& e) {
        ASSERT_TRUE(true);
    } catch (...) {
        ASSERT_TRUE(false);
    }
    
}

TEST(Cell, ConwayCell_simulate_to_life) {
    
    ConwayCell cell('.');
    unsigned int generations = 0;
    ASSERT_FALSE(cell.isAlive(generations++));
    cell.simulate(0);
    ASSERT_FALSE(cell.isAlive(generations++));
    cell.simulate(1);
    ASSERT_FALSE(cell.isAlive(generations++));
    cell.simulate(2);
    ASSERT_FALSE(cell.isAlive(generations++));
    cell.simulate(4);
    ASSERT_FALSE(cell.isAlive(generations++));
    cell.simulate(5);
    ASSERT_FALSE(cell.isAlive(generations++));
    cell.simulate(6);
    ASSERT_FALSE(cell.isAlive(generations++));
    cell.simulate(7);
    ASSERT_FALSE(cell.isAlive(generations++));
    cell.simulate(8);
    ASSERT_FALSE(cell.isAlive(generations++));
    cell.simulate(3);
    ASSERT_TRUE(cell.isAlive(generations++));
}

TEST(Cell, ConwayCell_simulate_to_death0) {
    
    ConwayCell cell('*');
    unsigned int generations = 0;
    ASSERT_TRUE(cell.isAlive(generations++));
    cell.simulate(2);
    ASSERT_TRUE(cell.isAlive(generations++));
    cell.simulate(3);
    ASSERT_TRUE(cell.isAlive(generations++));
    cell.simulate(0);
    ASSERT_FALSE(cell.isAlive(generations++));
}

TEST(Cell, ConwayCell_simulate_to_death1) {
    
    ConwayCell cell('*');
    unsigned int generations = 0;
    ASSERT_TRUE(cell.isAlive(generations++));
    cell.simulate(2);
    ASSERT_TRUE(cell.isAlive(generations++));
    cell.simulate(3);
    ASSERT_TRUE(cell.isAlive(generations++));
    cell.simulate(1);
    ASSERT_FALSE(cell.isAlive(generations++));
}

TEST(Cell, ConwayCell_simulate_to_death4) {
    
    ConwayCell cell('*');
    unsigned int generations = 0;
    ASSERT_TRUE(cell.isAlive(generations++));
    cell.simulate(2);
    ASSERT_TRUE(cell.isAlive(generations++));
    cell.simulate(3);
    ASSERT_TRUE(cell.isAlive(generations++));
    cell.simulate(4);
    ASSERT_FALSE(cell.isAlive(generations++));
}

TEST(Cell, ConwayCell_simulate_to_death5) {
    
    ConwayCell cell('*');
    unsigned int generations = 0;
    ASSERT_TRUE(cell.isAlive(generations++));
    cell.simulate(2);
    ASSERT_TRUE(cell.isAlive(generations++));
    cell.simulate(3);
    ASSERT_TRUE(cell.isAlive(generations++));
    cell.simulate(5);
    ASSERT_FALSE(cell.isAlive(generations++));
}

TEST(Cell, ConwayCell_simulate_to_death6) {
    
    ConwayCell cell('*');
    unsigned int generations = 0;
    ASSERT_TRUE(cell.isAlive(generations++));
    cell.simulate(2);
    ASSERT_TRUE(cell.isAlive(generations++));
    cell.simulate(3);
    ASSERT_TRUE(cell.isAlive(generations++));
    cell.simulate(6);
    ASSERT_FALSE(cell.isAlive(generations++));
}

TEST(Cell, ConwayCell_simulate_to_death7) {
    
    ConwayCell cell('*');
    unsigned int generations = 0;
    ASSERT_TRUE(cell.isAlive(generations++));
    cell.simulate(2);
    ASSERT_TRUE(cell.isAlive(generations++));
    cell.simulate(3);
    ASSERT_TRUE(cell.isAlive(generations++));
    cell.simulate(7);
    ASSERT_FALSE(cell.isAlive(generations++));
}

TEST(Cell, ConwayCell_simulate_to_death8) {
    
    ConwayCell cell('*');
    unsigned int generations = 0;
    ASSERT_TRUE(cell.isAlive(generations++));
    cell.simulate(2);
    ASSERT_TRUE(cell.isAlive(generations++));
    cell.simulate(3);
    ASSERT_TRUE(cell.isAlive(generations++));
    cell.simulate(8);
    ASSERT_FALSE(cell.isAlive(generations++));
}

TEST(Cell, FredkinCell_simulate_to_life1) {
    
    FredkinCell cell('-');
    unsigned int generations = 0;
    ASSERT_FALSE(cell.isAlive(generations++));
    cell.simulate(0);
    ASSERT_FALSE(cell.isAlive(generations++));
    cell.simulate(2);
    ASSERT_FALSE(cell.isAlive(generations++));
    cell.simulate(4);
    ASSERT_FALSE(cell.isAlive(generations++));
    cell.simulate(1);
    ASSERT_TRUE(cell.isAlive(generations++));
}

TEST(Cell, FredkinCell_simulate_to_life3) {
    
    FredkinCell cell('-');
    unsigned int generations = 0;
    ASSERT_FALSE(cell.isAlive(generations++));
    cell.simulate(0);
    ASSERT_FALSE(cell.isAlive(generations++));
    cell.simulate(2);
    ASSERT_FALSE(cell.isAlive(generations++));
    cell.simulate(4);
    ASSERT_FALSE(cell.isAlive(generations++));
    cell.simulate(3);
    ASSERT_TRUE(cell.isAlive(generations++));
}

TEST(Cell, FredkinCell_simulate_to_death0) {
    
    FredkinCell cell('0');
    unsigned int generations = 0;
    ASSERT_TRUE(cell.isAlive(generations++));
    cell.simulate(1);
    ASSERT_TRUE(cell.isAlive(generations++));
    cell.simulate(3);
    ASSERT_TRUE(cell.isAlive(generations++));
    cell.simulate(0);
    ASSERT_FALSE(cell.isAlive(generations++));
}

TEST(Cell, FredkinCell_simulate_to_death2) {
    
    FredkinCell cell('0');
    unsigned int generations = 0;
    ASSERT_TRUE(cell.isAlive(generations++));
    cell.simulate(1);
    ASSERT_TRUE(cell.isAlive(generations++));
    cell.simulate(3);
    ASSERT_TRUE(cell.isAlive(generations++));
    cell.simulate(2);
    ASSERT_FALSE(cell.isAlive(generations++));
}

TEST(Cell, FredkinCell_simulate_to_death4) {
    
    FredkinCell cell('0');
    unsigned int generations = 0;
    ASSERT_TRUE(cell.isAlive(generations++));
    cell.simulate(1);
    ASSERT_TRUE(cell.isAlive(generations++));
    cell.simulate(3);
    ASSERT_TRUE(cell.isAlive(generations++));
    cell.simulate(4);
    ASSERT_FALSE(cell.isAlive(generations++));
}

TEST(Cell, ConwayCell_simulate_out_of_range) {
    try {
        ConwayCell cell('*');
        ASSERT_TRUE(cell.isAlive(0));
        cell.simulate(9);
        ASSERT_TRUE(false);
    } catch (const std::out_of_range& e) {
        ASSERT_TRUE(true);
    } catch (...) {
        ASSERT_TRUE(false);
    }
}

TEST(Cell, FredkinCell_simulate_out_of_range) {
    try {
        FredkinCell cell('0');
        ASSERT_TRUE(cell.isAlive(0));
        cell.simulate(5);
        ASSERT_TRUE(false);
    } catch (const std::out_of_range& e) {
        ASSERT_TRUE(true);
    } catch (...) {
        ASSERT_TRUE(false);
    }
}

TEST(Cell, FredkinCell_age) {
    FredkinCell cell('-');
    std::ostringstream w;

    for (int i = 0; i < 10; i++) {
        cell.simulate(1);
        w.str(std::string());
        w.clear();
        w << cell;
        std::ostringstream s;
        s << i;
        ASSERT_TRUE(w.str() == s.str());
    }
    cell.simulate(1);
    w.str(std::string());
    w.clear();
    w << cell;
    ASSERT_TRUE(w.str() == "+");
}

TEST(Cell, FredkinCell_age2) {
    FredkinCell cell('+');
    cell.simulate(1);
    std::ostringstream w;
    w << cell;
    ASSERT_TRUE(w.str() == "+");

    cell = FredkinCell('9');
    cell.simulate(1);
    w.str(std::string());
    w.clear();
    w << cell;
    ASSERT_TRUE(w.str() == "+");

    for (int i = 8; i >= 0; i--) {
        cell = FredkinCell(static_cast<char>('0' + i));
        cell.simulate(1);
        w.str(std::string());
        w.clear();
        w << cell;
        std::ostringstream s;
        s << (i+1);
        ASSERT_TRUE(w.str() == s.str());
    } 
}

TEST(Cell, FredkinCell_age_skip_generation) {
    FredkinCell cell('0');
    std::ostringstream w;

    for (int i = 0; i < 10; i++) {
        cell.simulate(0);
        cell.simulate(1);
        w.str(std::string());
        w.clear();
        w << cell;
        ASSERT_TRUE(w.str() == "0");
    }
}

TEST(Cell, FredkinCell_age_skip_generation_no_reset) {
    FredkinCell cell('0');
    std::ostringstream w;

    for (int i = 0; i < 10; i++) {
        cell.simulate(1);
        w.str(std::string());
        w.clear();
        w << cell;
        ASSERT_TRUE(w.str() == "1");

        cell.simulate(0);
        w.str(std::string());
        w.clear();
        w << cell;
        ASSERT_TRUE(w.str() == "-");
    }
}

TEST(Cell, FredkinCell_age_skip_generation2) {
    FredkinCell cell('-');
    std::ostringstream w;

    for (int i = 0; i < 10; i++) {
        if ( i & 0x1 ) {
            cell.simulate(1);
            cell.simulate(1);
        } else {
            cell.simulate(0);
        }
    }
    w << cell;
    ASSERT_TRUE(w.str() == "5");
}

TEST(Cell, Cell_age_skip_generation_no_reset_no_mutate) {
    Cell cell('0');
    std::ostringstream w;

    for (int i = 0; i < 10; i++) {
        cell.simulate(1);
        w.str(std::string());
        w.clear();
        w << cell;
        ASSERT_TRUE(w.str() == "1");

        cell.simulate(0);
        w.str(std::string());
        w.clear();
        w << cell;
        ASSERT_TRUE(w.str() == "-");
    }
}

TEST(Cell, Cell_mutate_Fredkin_to_Conway) {
    Cell cell('-');
    std::ostringstream w;
    cell.simulate(1);
    w << cell;
    ASSERT_TRUE(w.str() == "0");

    for (int i = 0; i < 10; i++) {
        cell.simulate(1);
        w.str(std::string());
        w.clear();
        w << cell;
        ASSERT_TRUE(w.str() == "1");

        cell.simulate(0);
        w.str(std::string());
        w.clear();
        w << cell;
        ASSERT_TRUE(w.str() == "-");
    }

    cell.simulate(1);
    w.str(std::string());
    w.clear();
    w << cell;
    ASSERT_TRUE(w.str() == "1");
    cell.simulate(1);
    w.str(std::string());
    w.clear();
    w << cell;
    ASSERT_TRUE(w.str() == "*");
    
}

TEST(Life, hello_life_ConwayCell) {
    Life<ConwayCell> life(8, 8);
    std::ostringstream w;
    w << life;
    // std::cout << w.str() << std::endl;
    ASSERT_TRUE(w.str() == "Generation = 0, Population = 0.\n"
        "........\n"
        "........\n"
        "........\n"
        "........\n"
        "........\n"
        "........\n"
        "........\n"
        "........\n");
}

TEST(Life, hello_life_FredkinCell) {
    Life<FredkinCell> life(8, 8);
    std::ostringstream w;
    w << life;
    // std::cout << w.str() << std::endl;
    ASSERT_TRUE(w.str() == "Generation = 0, Population = 0.\n"
        "--------\n"
        "--------\n"
        "--------\n"
        "--------\n"
        "--------\n"
        "--------\n"
        "--------\n"
        "--------\n");
}

TEST(Life, hello_life_Cell) {
    Life<Cell> life(8, 8);
    std::ostringstream w;
    w << life;
    // std::cout << w.str() << std::endl;
    ASSERT_TRUE(w.str() == "Generation = 0, Population = 0.\n"
        "........\n"
        "........\n"
        "........\n"
        "........\n"
        "........\n"
        "........\n"
        "........\n"
        "........\n");
}


TEST(Life, hello_24x24) {
    Life<ConwayCell> life(24, 24);
    std::ostringstream w;
    w << life;
    // std::cout << w.str() << std::endl;
    ASSERT_TRUE(w.str() == "Generation = 0, Population = 0.\n"
        "........................\n"
        "........................\n"
        "........................\n"
        "........................\n"
        "........................\n"
        "........................\n"
        "........................\n"
        "........................\n"
        "........................\n"
        "........................\n"
        "........................\n"
        "........................\n"
        "........................\n"
        "........................\n"
        "........................\n"
        "........................\n"
        "........................\n"
        "........................\n"
        "........................\n"
        "........................\n"
        "........................\n"
        "........................\n"
        "........................\n"
        "........................\n");
}


TEST(Life, hello_zero_life) {
    Life<ConwayCell> life;
    std::ostringstream w;
    w << life;
    // std::cout << w.str() << std::endl;
    ASSERT_TRUE(w.str() == "Generation = 0, Population = 0.\n");
}

TEST(Life, hello_1x0) {
    Life<ConwayCell> life(1,0);
    std::ostringstream w;
    w << life;
    // std::cout << w.str() << std::endl;
    ASSERT_TRUE(w.str() == "Generation = 0, Population = 0.\n\n");
}

TEST(Life, hello_0x1) {
    Life<ConwayCell> life(0,1);
    std::ostringstream w;
    w << life;
    // std::cout << w.str() << std::endl;
    ASSERT_TRUE(w.str() == "Generation = 0, Population = 0.\n");
}

TEST(Life, addCell) {
    
    Life<ConwayCell> life(4, 4);
    std::ostringstream w;
    w << life;
    ASSERT_TRUE(w.str() == "Generation = 0, Population = 0.\n"
        "....\n"
        "....\n"
        "....\n"
        "....\n");

    life.addCell('*', 2, 2);
    w.str(std::string(""));
    w.clear();
    w << life;
    // std::cout << w.str() << std::endl;
    ASSERT_TRUE(w.str() == "Generation = 0, Population = 1.\n"
        "....\n"
        "....\n"
        "..*.\n"
        "....\n");
}

TEST(Life, addCell_Conway_corners) {
    
    Life<ConwayCell> life(4, 4);
    std::ostringstream w;
    w << life;
    ASSERT_TRUE(w.str() == "Generation = 0, Population = 0.\n"
        "....\n"
        "....\n"
        "....\n"
        "....\n");

    life.addCell('*', 0, 0);
    w.str(std::string(""));
    w.clear();
    w << life;
    // std::cout << w.str() << std::endl;
    ASSERT_TRUE(w.str() == "Generation = 0, Population = 1.\n"
        "*...\n"
        "....\n"
        "....\n"
        "....\n");

    life.addCell('*', 0, 3);
    w.str(std::string(""));
    w.clear();
    w << life;
    // std::cout << w.str() << std::endl;
    ASSERT_TRUE(w.str() == "Generation = 0, Population = 2.\n"
        "*..*\n"
        "....\n"
        "....\n"
        "....\n");

    life.addCell('*', 3, 0);
    w.str(std::string(""));
    w.clear();
    w << life;
    // std::cout << w.str() << std::endl;
    ASSERT_TRUE(w.str() == "Generation = 0, Population = 3.\n"
        "*..*\n"
        "....\n"
        "....\n"
        "*...\n");

    life.addCell('*', 3, 3);
    w.str(std::string(""));
    w.clear();
    w << life;
    // std::cout << w.str() << std::endl;
    ASSERT_TRUE(w.str() == "Generation = 0, Population = 4.\n"
        "*..*\n"
        "....\n"
        "....\n"
        "*..*\n");

}

TEST(Life, addCell_Fredkin_corners) {
    
    Life<FredkinCell> life(4, 4);
    std::ostringstream w;
    w << life;
    ASSERT_TRUE(w.str() == "Generation = 0, Population = 0.\n"
        "----\n"
        "----\n"
        "----\n"
        "----\n");

    life.addCell('0', 0, 0);
    w.str(std::string(""));
    w.clear();
    w << life;
    // std::cout << w.str() << std::endl;
    ASSERT_TRUE(w.str() == "Generation = 0, Population = 1.\n"
        "0---\n"
        "----\n"
        "----\n"
        "----\n");

    life.addCell('1', 0, 3);
    w.str(std::string(""));
    w.clear();
    w << life;
    // std::cout << w.str() << std::endl;
    ASSERT_TRUE(w.str() == "Generation = 0, Population = 2.\n"
        "0--1\n"
        "----\n"
        "----\n"
        "----\n");

    life.addCell('9', 3, 0);
    w.str(std::string(""));
    w.clear();
    w << life;
    // std::cout << w.str() << std::endl;
    ASSERT_TRUE(w.str() == "Generation = 0, Population = 3.\n"
        "0--1\n"
        "----\n"
        "----\n"
        "9---\n");

    life.addCell('+', 3, 3);
    w.str(std::string(""));
    w.clear();
    w << life;
    // std::cout << w.str() << std::endl;
    ASSERT_TRUE(w.str() == "Generation = 0, Population = 4.\n"
        "0--1\n"
        "----\n"
        "----\n"
        "9--+\n");

}

TEST(Life, add_cell_invalid_argument_row) {
    
    try {
        Life<ConwayCell> life(2, 2);
        life.addCell('*', 1, 1);
        std::ostringstream w;
        w << life;
        // std::cout << w.str() << std::endl;
        ASSERT_TRUE(w.str() == "Generation = 0, Population = 1.\n"
                "..\n"
                ".*\n");

        life.addCell('.', 2, 1);
        ASSERT_TRUE(false);
    } catch (const std::invalid_argument& ia) {
        ASSERT_TRUE(true);
    } catch (...) {
        ASSERT_TRUE(false);
    }
}

TEST(Life, add_cell_invalid_argument_col) {
    
    try {
        Life<ConwayCell> life(2, 2);
        life.addCell('*', 1, 1);
        std::ostringstream w;
        w << life;
        // std::cout << w.str() << std::endl;
        ASSERT_TRUE(w.str() == "Generation = 0, Population = 1.\n"
                "..\n"
                ".*\n");

        life.addCell('.', 1, -1);
        ASSERT_TRUE(false);
    } catch (const std::invalid_argument& ia) {
        ASSERT_TRUE(true);
    } catch (...) {
        ASSERT_TRUE(false);
    }
}


TEST(Life, resize) {
    
    Life<ConwayCell> life;
    life.resize(2,2);
    std::ostringstream w;
    w << life;
    // std::cout << w.str() << std::endl;
    ASSERT_TRUE(w.str() == "Generation = 0, Population = 0.\n"
            "..\n"
            "..\n");

    life.resize(8,8);
    w.str(std::string(""));
    w.clear();
    w << life;
    ASSERT_TRUE(w.str() == "Generation = 0, Population = 0.\n"
        "........\n"
        "........\n"
        "........\n"
        "........\n"
        "........\n"
        "........\n"
        "........\n"
        "........\n");

    life.resize(1,10);
    w.str(std::string(""));
    w.clear();
    w << life;
    ASSERT_TRUE(w.str() == "Generation = 0, Population = 0.\n"
        "..........\n");

}

TEST(Life, resize_invalid_arg) {
    
    Life<ConwayCell> life/*(4, 4)*/;

/*    std::ostringstream w;
    w << life;
    ASSERT_TRUE(w.str() == "Generation = 0, Population = 0.\n"
        "....\n"
        "....\n"
        "....\n"
        "....\n");
*/
    try {
        life.resize(-1,2);
        ASSERT_TRUE(false);
    } catch (const std::invalid_argument& ia) {
        ASSERT_TRUE(true);
    } catch (...) {
        ASSERT_TRUE(false);
    }
/*
    w.str(std::string(""));
    w.clear();
    w << life;
    ASSERT_TRUE(w.str() == "Generation = 0, Population = 0.\n"
        "....\n"
        "....\n"
        "....\n"
        "....\n");
*/
    try {
        life.resize(-1,2);
        ASSERT_TRUE(false);
    } catch (const std::invalid_argument& ia) {
        ASSERT_TRUE(true);
    } catch (...) {
        ASSERT_TRUE(false);
    }
/*
    w.str(std::string(""));
    w.clear();
    w << life;
    ASSERT_TRUE(w.str() == "Generation = 0, Population = 0.\n"
        "....\n"
        "....\n"
        "....\n"
        "....\n");
*/
}

TEST(Life, simulate_ConwayCell_blink) {
    
    Life<ConwayCell> life(5, 7);
    life.addCell('*', 1, 3); 
    life.addCell('*', 2, 3);
    life.addCell('*', 3, 3);
    std::ostringstream w;
    w << life;
    ASSERT_TRUE(w.str() == "Generation = 0, Population = 3.\n"
        ".......\n"
        "...*...\n"
        "...*...\n"
        "...*...\n"
        ".......\n");

    life.simulate();

    w.str(std::string(""));
    w.clear();
    w << life;
    ASSERT_TRUE(w.str() == "Generation = 1, Population = 3.\n"
        ".......\n"
        ".......\n"
        "..***..\n"
        ".......\n"
        ".......\n");

}

TEST(Life, simulate_ConwayCell_full) {
    
    Life<ConwayCell> life(5, 7);
    for (int r = 0; r < 5; r++)
        for (int c = 0; c < 7; c++ )
            life.addCell('*', r, c); 
    
    std::ostringstream w;
    w << life;
    ASSERT_TRUE(w.str() == "Generation = 0, Population = 35.\n"
        "*******\n"
        "*******\n"
        "*******\n"
        "*******\n"
        "*******\n");

    life.simulate();

    w.str(std::string(""));
    w.clear();
    w << life;
    // std::cout << w.str() << std::endl;
    ASSERT_TRUE(w.str() == "Generation = 1, Population = 4.\n"
        "*.....*\n"
        ".......\n"
        ".......\n"
        ".......\n"
        "*.....*\n");

    life.simulate();

    w.str(std::string(""));
    w.clear();
    w << life;
    // std::cout << w.str() << std::endl;
    ASSERT_TRUE(w.str() == "Generation = 2, Population = 0.\n"
        ".......\n"
        ".......\n"
        ".......\n"
        ".......\n"
        ".......\n");
}

TEST(Life, simulate_Fredkin) {
    
    Life<FredkinCell> life(5, 7);
    life.addCell('0', 2, 3); 
    std::ostringstream w;
    w << life;
    // std::cout << w.str() << std::endl;
    ASSERT_TRUE(w.str() == "Generation = 0, Population = 1.\n"
        "-------\n"
        "-------\n"
        "---0---\n"
        "-------\n"
        "-------\n");

    life.simulate();

    w.str(std::string(""));
    w.clear();
    w << life;
    // std::cout << w.str() << std::endl;
    ASSERT_TRUE(w.str() == "Generation = 1, Population = 4.\n"
        "-------\n"
        "---0---\n"
        "--0-0--\n"
        "---0---\n"
        "-------\n");

    life.simulate();

    w.str(std::string(""));
    w.clear();
    w << life;
    // std::cout << w.str() << std::endl;
    ASSERT_TRUE(w.str() == "Generation = 2, Population = 4.\n"
        "---0---\n"
        "-------\n"
        "-0---0-\n"
        "-------\n"
        "---0---\n");

    life.simulate();

    w.str(std::string(""));
    w.clear();
    w << life;
    // std::cout << w.str() << std::endl;
    ASSERT_TRUE(w.str() == "Generation = 3, Population = 14.\n"
        "--0-0--\n"
        "-0-0-0-\n"
        "0-0-0-0\n"
        "-0-0-0-\n"
        "--0-0--\n");

}

TEST(Life, simulate_Fredkin_age) {
    
    Life<FredkinCell> life(9, 2);

    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 2; c++)
            if (r*2+c < 9)
                life.addCell(static_cast<char>('0' + (r*2+c+1)), r*2, c);
    }
    life.addCell('+', 8, 1);

    std::ostringstream w;
    w << life;
    ASSERT_TRUE(w.str() == "Generation = 0, Population = 10.\n"
        "12\n"
        "--\n"
        "34\n"
        "--\n"
        "56\n"
        "--\n"
        "78\n"
        "--\n"
        "9+\n");

    life.simulate();
    w.str(std::string(""));
    w.clear();
    w << life;
    ASSERT_TRUE(w.str() == "Generation = 1, Population = 10.\n"
        "23\n"
        "--\n"
        "45\n"
        "--\n"
        "67\n"
        "--\n"
        "89\n"
        "--\n"
        "++\n");

    life.simulate();
    w.str(std::string(""));
    w.clear();
    w << life;
    ASSERT_TRUE(w.str() == "Generation = 2, Population = 10.\n"
        "34\n"
        "--\n"
        "56\n"
        "--\n"
        "78\n"
        "--\n"
        "9+\n"
        "--\n"
        "++\n");

    life.simulate(6);
    w.str(std::string(""));
    w.clear();
    w << life;
    ASSERT_TRUE(w.str() == "Generation = 8, Population = 10.\n"
        "9+\n"
        "--\n"
        "++\n"
        "--\n"
        "++\n"
        "--\n"
        "++\n"
        "--\n"
        "++\n");
}

TEST(Life, simulate_Cell) {
    
    Life<Cell> life(6, 7);
    
    life.addCell('0', 2, 3);
    life.addCell('0', 3, 3);
    std::ostringstream w;
    w << life;
    ASSERT_TRUE(w.str() == "Generation = 0, Population = 2.\n"
        ".......\n"
        ".......\n"
        "...0...\n"
        "...0...\n"
        ".......\n"
        ".......\n");

    life.simulate();
    w.str(std::string(""));
    w.clear();
    w << life;
    ASSERT_TRUE(w.str() == "Generation = 1, Population = 2.\n"
        ".......\n"
        ".......\n"
        "...1...\n"
        "...1...\n"
        ".......\n"
        ".......\n");

    life.simulate();
    w.str(std::string(""));
    w.clear();
    w << life;
    ASSERT_TRUE(w.str() == "Generation = 2, Population = 2.\n"
        ".......\n"
        ".......\n"
        "...*...\n"
        "...*...\n"
        ".......\n"
        ".......\n");

    life.simulate();
    w.str(std::string(""));
    w.clear();
    w << life;
    ASSERT_TRUE(w.str() == "Generation = 3, Population = 0.\n"
        ".......\n"
        ".......\n"
        ".......\n"
        ".......\n"
        ".......\n"
        ".......\n");

}

TEST(Life, simulate_Cell2) {
    
    Life<Cell> life(6, 7);
    for (int r = 0; r < 6; r++) 
        for (int c = 0; c < 7; c++)
            life.addCell('-', r, c);

    life.addCell('1', 2, 3);
    life.addCell('1', 3, 3);
    std::ostringstream w;
    w << life;
    ASSERT_TRUE(w.str() == "Generation = 0, Population = 2.\n"
        "-------\n"
        "-------\n"
        "---1---\n"
        "---1---\n"
        "-------\n"
        "-------\n");

    life.simulate();

    w.str(std::string(""));
    w.clear();
    w << life;
    ASSERT_TRUE(w.str() == "Generation = 1, Population = 8.\n"
        "-------\n"
        "---0---\n"
        "--0*0--\n"
        "--0*0--\n"
        "---0---\n"
        "-------\n");
}
