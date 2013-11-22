#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==

#include "gtest/gtest.h"

#include "AbstractCell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "stdexcept"
#include "Cell.h"
// -----------
// TestLife
// -----------

// -------------
// ConwayCell 
// -------------


// -------------
// ConwayCell default
// -------------

TEST(ConwayCell, conway_cell_const_1) {
	ConwayCell x1(true);
    ASSERT_TRUE(x1.is_alive());
}

TEST(ConwayCell, conway_cell_const_2) {
	ConwayCell x2(false);
    ASSERT_TRUE(!x2.is_alive());
}

TEST(ConwayCell, conway_cell_const_3) {
	ConwayCell x3(true);
    ASSERT_TRUE(x3.p_name() == '*');
}

TEST(ConwayCell, conway_cell_const_4) {
	ConwayCell x4(false);
    ASSERT_TRUE(x4.p_name() == '.');
}

// -------------
// ConwayCell clone
// -------------

TEST(ConwayCell, conway_cell_clone_1) {
	ConwayCell x1(true);

	ConwayCell *x1P;
	x1P = x1.clone();

    	ASSERT_TRUE(x1.is_alive());
	ASSERT_TRUE(x1.is_old_alive());
   	ASSERT_TRUE(x1P->is_alive());
	ASSERT_TRUE(x1P->is_old_alive());
	ASSERT_TRUE(x1P->name() == 'C');

    	x1P->change_state (1);

	ASSERT_TRUE(x1.is_alive());
	ASSERT_TRUE(x1.is_old_alive());
   	ASSERT_TRUE(! x1P->is_alive());
	ASSERT_TRUE(x1P->is_old_alive());

	delete x1P;    
}

TEST(ConwayCell, conway_cell_clone_2) {
	ConwayCell x2(false);

	ConwayCell *x2P;
	x2P = x2.clone();

    	ASSERT_TRUE(!x2.is_alive());
	ASSERT_TRUE(!x2.is_old_alive());
   	ASSERT_TRUE(!x2P->is_alive());
	ASSERT_TRUE(!x2P->is_old_alive());
	ASSERT_TRUE(x2P->name() == 'C');

    	x2P->change_state (3);

	ASSERT_TRUE(!x2.is_alive());
	ASSERT_TRUE(!x2.is_old_alive());
   	ASSERT_TRUE(x2P->is_alive());
	ASSERT_TRUE(!x2P->is_old_alive());

	delete x2P;    
}

TEST(ConwayCell, conway_cell_clone_3) {
	ConwayCell x3(true);

	ConwayCell *x3P;
	x3P = x3.clone();

    	ASSERT_TRUE(x3.is_alive());
	ASSERT_TRUE(x3.is_old_alive());
   	ASSERT_TRUE(x3P->is_alive());
	ASSERT_TRUE(x3P->is_old_alive());
	ASSERT_TRUE(x3P->name() == 'C');

    	x3P->change_state (4);

	ASSERT_TRUE(x3.is_alive());
	ASSERT_TRUE(x3.is_old_alive());
   	ASSERT_TRUE(! x3P->is_alive());
	ASSERT_TRUE(x3P->is_old_alive());

	delete x3P;    
}
// -------------
// ConwayCell change_state
// -------------

TEST(ConwayCell, change_state_1) {
	ConwayCell x1(true);
    ASSERT_TRUE(x1.is_alive());
    x1.change_state(1);
    ASSERT_TRUE(!x1.is_alive());
}

TEST(ConwayCell, change_state_2) {
	ConwayCell x2(false);
    ASSERT_TRUE(!x2.is_alive());
    x2.change_state(3);
    ASSERT_TRUE(x2.is_alive());
}

TEST(ConwayCell, change_state_3) {
	ConwayCell x3(true);
    ASSERT_TRUE(x3.is_alive());
    x3.change_state(1);
    ASSERT_TRUE(x3.is_old_alive());
}

TEST(ConwayCell, change_state_4) {
	ConwayCell x4(false);
    ASSERT_TRUE(!x4.is_alive());
    x4.change_state(3);
    ASSERT_TRUE(!x4.is_old_alive());
}
// -------------
// ConwayCell print_cell
// -------------

TEST(ConwayCell, print_cell_1) {
	std::ostringstream w;
	ConwayCell x1(true);
	x1.printCell(w);
    //collatz_print(w, 1, 10, 20);
    ASSERT_TRUE(w.str() == "*");
}

TEST(ConwayCell, print_cell_2) {
	std::ostringstream w;
	ConwayCell x2(false);
	x2.printCell(w);
    //collatz_print(w, 1, 10, 20);
    ASSERT_TRUE(w.str() == ".");
}

TEST(ConwayCell, print_cell_3) {
	std::ostringstream w;
	ConwayCell x3(true);
	x3.printCell(w);
    //collatz_print(w, 1, 10, 20);
    ASSERT_TRUE(w.str() != ".");
}

TEST(ConwayCell, print_cell_4) {
	std::ostringstream w;
	ConwayCell x4(false);
	x4.printCell(w);
    //collatz_print(w, 1, 10, 20);
    ASSERT_TRUE(w.str() != "*");
}
// -------------
// ConwayCell name_1
// -------------

TEST(ConwayCell, name_1) {
	ConwayCell x1(false);
    ASSERT_TRUE(!x1.is_alive());
    ASSERT_TRUE(x1.name() == 'C');
}

TEST(ConwayCell, name_2) {
	ConwayCell x2(true);
    ASSERT_TRUE(x2.is_alive());
    ASSERT_TRUE(x2.name() == 'C');
}

TEST(ConwayCell, name_3) {
	ConwayCell x3(false);
    ASSERT_TRUE(!x3.is_alive());
    ASSERT_TRUE(x3.name() != 'D');
}

TEST(ConwayCell, name_4) {
	ConwayCell x4(true);
    ASSERT_TRUE(x4.is_alive());
    ASSERT_TRUE(x4.name() != 'A');
}
// -------------
// ConwayCell p_name
// -------------

TEST(ConwayCell, p_name_1) {
	ConwayCell x1(false);
    ASSERT_TRUE(!x1.is_alive());
    ASSERT_TRUE(x1.p_name() == '.');
}

TEST(ConwayCell, p_name_2) {
	ConwayCell x2(true);
    ASSERT_TRUE(x2.is_alive());
    ASSERT_TRUE(x2.p_name() == '*');
}

TEST(ConwayCell, p_name_3) {
	ConwayCell x3(false);
    ASSERT_TRUE(!x3.is_alive());
    ASSERT_TRUE(x3.p_name() != '*');
}

TEST(ConwayCell, p_name_4) {
	ConwayCell x4(true);
    ASSERT_TRUE(x4.is_alive());
    ASSERT_TRUE(x4.p_name() != '.');
}
// -------------
// ConwayCell read
// -------------

TEST(ConwayCell, read_1) {
	ConwayCell x1(false);
	std::istringstream r("*");
	x1.read(r);
    ASSERT_TRUE(x1.is_alive());
    ASSERT_TRUE(x1.p_name() == '*');
}

TEST(ConwayCell, read_2) {
	ConwayCell x2(true);
	std::istringstream r(".");
	x2.read(r);
    ASSERT_TRUE(!x2.is_alive());
    ASSERT_TRUE(x2.p_name() == '.');
}

TEST(ConwayCell, read_3) {
	ConwayCell x3(false);
	std::istringstream r("*");
	x3.read(r);
    ASSERT_TRUE(x3.is_old_alive());
    ASSERT_TRUE(x3.p_name() == '*');
}

TEST(ConwayCell, read_4) {
	ConwayCell x4(true);
	std::istringstream r(".");
	x4.read(r);
    ASSERT_TRUE(!x4.is_old_alive());
    ASSERT_TRUE(x4.p_name() == '.');
}
//*********************************8FredkinCell *******************************

// -------------
// FredkinCell const
// -------------

TEST(FredkinCell, fredkin_cell_const_1) {
	FredkinCell x1(true);
    ASSERT_TRUE(x1.is_alive());
}

TEST(FredkinCell, fredkin_cell_const_2) {
	FredkinCell x2(false);
    ASSERT_TRUE(!x2.is_alive());
}

TEST(FredkinCell, fredkin_cell_const_3) {
	FredkinCell x3(true);
    ASSERT_TRUE(x3.is_old_alive());
}

TEST(FredkinCell, fredkin_cell_const_4) {
	FredkinCell x4(false);
    ASSERT_TRUE(!x4.is_old_alive());
}
// -------------
// FredkinCell clone
// -------------

TEST(FredkinCell, fredkin_cell_clone_1) {
	FredkinCell x1(true);

	FredkinCell *x1P;
	x1P = x1.clone();

    ASSERT_TRUE(x1.is_alive());
	ASSERT_TRUE(x1.is_old_alive());
   	ASSERT_TRUE(x1P->is_alive());
	ASSERT_TRUE(x1P->is_old_alive());
	ASSERT_TRUE(x1P->name() == 'F');

    	x1P->change_state (2);

	ASSERT_TRUE(x1.is_alive());
	ASSERT_TRUE(x1.is_old_alive());
   	ASSERT_TRUE(! x1P->is_alive());
	ASSERT_TRUE(x1P->is_old_alive());

	delete x1P;    
}

TEST(FredkinCell, fredkin_cell_clone_2) {
	FredkinCell x2(false);

	FredkinCell *x2P;
	x2P = x2.clone();

    ASSERT_TRUE(!x2.is_alive());
	ASSERT_TRUE(!x2.is_old_alive());
   	ASSERT_TRUE(!x2P->is_alive());
	ASSERT_TRUE(!x2P->is_old_alive());
	ASSERT_TRUE(x2P->name() == 'F');

    	x2P->change_state (3);

	ASSERT_TRUE(!x2.is_alive());
	ASSERT_TRUE(!x2.is_old_alive());
   	ASSERT_TRUE( x2P->is_alive());
	ASSERT_TRUE(!x2P->is_old_alive());

	delete x2P;    
}

TEST(FredkinCell, fredkin_cell_clone_3) {
	FredkinCell x3(true);

	FredkinCell *x3P;
	x3P = x3.clone();

    ASSERT_TRUE(x3.is_alive());
	ASSERT_TRUE(x3.is_old_alive());
   	ASSERT_TRUE(x3P->is_alive());
	ASSERT_TRUE(x3P->is_old_alive());
	ASSERT_TRUE(x3P->name() == 'F');

    	x3P->change_state (4);

	ASSERT_TRUE(x3.is_alive());
	ASSERT_TRUE(x3.is_old_alive());
   	ASSERT_TRUE(! x3P->is_alive());
	ASSERT_TRUE(x3P->is_old_alive());

	delete x3P;    
}

// -------------
// FredkinCell change_state
// -------------

TEST(FredkinCell, change_state_1) {
	FredkinCell x1(true);
    ASSERT_TRUE(x1.is_alive());
    x1.change_state(2);
    ASSERT_TRUE(!x1.is_alive());
}

TEST(FredkinCell, change_state_2) {
	FredkinCell x2(false);
    ASSERT_TRUE(!x2.is_alive());
    x2.change_state(3);
    ASSERT_TRUE(x2.is_alive());
}

TEST(FredkinCell, change_state_3) {
	FredkinCell x3(true);
    ASSERT_TRUE(x3.is_alive());
    x3.change_state(0);
    ASSERT_TRUE(x3.is_old_alive());
}

TEST(FredkinCell, change_state_4) {
	FredkinCell x4(false);
    ASSERT_TRUE(!x4.is_alive());
    x4.change_state(3);
    ASSERT_TRUE(!x4.is_old_alive());
}
// -------------
// FredkinCell print_cell
// -------------

TEST(FredkinCell, print_cell_1) {
	std::ostringstream w;
	FredkinCell x1(true);
	x1.printCell(w);
    //collatz_print(w, 1, 10, 20);
    ASSERT_TRUE(w.str() == "0");
}

TEST(FredkinCell, print_cell_2) {
	std::ostringstream w;
	FredkinCell x2(false);
	x2.printCell(w);
    //collatz_print(w, 1, 10, 20);
    ASSERT_TRUE(w.str() == "-");
}

TEST(FredkinCell, print_cell_3) {
	std::ostringstream w;
	FredkinCell x3(true);
	x3.change_state(1);
	x3.change_state(1);
	x3.change_state(1);
	x3.printCell(w);
    //collatz_print(w, 1, 10, 20);
    ASSERT_TRUE(w.str() == "3");
}

TEST(FredkinCell, print_cell_4) {
	std::ostringstream w;
	FredkinCell x4(false);
	x4.change_state(1);
	x4.change_state(1);
	x4.change_state(1);
	x4.change_state(1);
	x4.change_state(1);
	x4.change_state(1);
	x4.change_state(1);
	x4.change_state(1);
	x4.printCell(w);
    //collatz_print(w, 1, 10, 20);
    ASSERT_TRUE(w.str() == "7");
}
// -------------
// FredkinCell name
// -------------

TEST(FredkinCell, name_1) {
	FredkinCell x1(false);
    ASSERT_TRUE(!x1.is_alive());
    ASSERT_TRUE(x1.name() == 'F');
}

TEST(FredkinCell, name_2) {
	FredkinCell x2(true);
    ASSERT_TRUE(x2.is_alive());
    ASSERT_TRUE(x2.name() == 'F');
}

TEST(FredkinCell, name_3) {
	FredkinCell x3(false);
    ASSERT_TRUE(!x3.is_alive());
    ASSERT_TRUE(x3.name() != 'D');
}

TEST(FredkinCell, name_4) {
	FredkinCell x4(true);
    ASSERT_TRUE(x4.is_alive());
    ASSERT_TRUE(x4.name() != 'A');
}
// -------------
// FredkinCell p_name
// -------------

TEST(FredkinCell, p_name_1) {
	FredkinCell x1(false);
    ASSERT_TRUE(!x1.is_alive());
    ASSERT_TRUE(x1.p_name() == '-');
}

TEST(FredkinCell, p_name_2) {
	FredkinCell x2(true);
    ASSERT_TRUE(x2.is_alive());
    ASSERT_TRUE(x2.p_name() == '0');
}

TEST(FredkinCell, p_name_3) {
	FredkinCell x3(true);
    ASSERT_TRUE(x3.is_alive());
    x3.change_state(1);
	x3.change_state(1);
	x3.change_state(1);
    ASSERT_TRUE(x3.p_name() == '3');
}

TEST(FredkinCell, p_name_4) {
	FredkinCell x4(false);
    ASSERT_TRUE(!x4.is_alive());
    x4.change_state(1);
	x4.change_state(1);
	x4.change_state(1);
	x4.change_state(1);
	x4.change_state(1);
	x4.change_state(1);
	x4.change_state(1);
	x4.change_state(1);
    ASSERT_TRUE(x4.p_name() == '7');
}
// -------------
// FredkinCell read
// -------------

TEST(FredkinCell, read_1) {
	FredkinCell x1(false);
	std::istringstream r("0");
	x1.read(r);
    ASSERT_TRUE(x1.is_alive());
    ASSERT_TRUE(x1.p_name() == '0');
}

TEST(FredkinCell, read_2) {
	FredkinCell x2(false);
	std::istringstream r("-");
	x2.read(r);
    ASSERT_TRUE(!x2.is_alive());
    ASSERT_TRUE(x2.p_name() == '-');
}

TEST(FredkinCell, read_3) {
	FredkinCell x3(true);
	std::istringstream r("0");
	x3.read(r);
	x3.change_state(1);
	x3.change_state(1);
	x3.change_state(1);
    ASSERT_TRUE(x3.is_alive());
    ASSERT_TRUE(x3.p_name() == '3');
}

TEST(FredkinCell, read_4) {
	FredkinCell x4(true);
	std::istringstream r("0");
	x4.read(r);
	x4.change_state(1);
	x4.change_state(1);
	x4.change_state(1);
	x4.change_state(1);
	x4.change_state(1);
	x4.change_state(1);
	x4.change_state(1);
	x4.change_state(1);
	x4.change_state(1);
	x4.change_state(1);
    ASSERT_TRUE(x4.is_alive());
    ASSERT_TRUE(x4.p_name() == '+');
}
//*********************************Cell *******************************


// -------------
// Cell change_state
// -------------

TEST(Cell, change_state_1) {
	Cell x1(new FredkinCell());
    ASSERT_TRUE(!x1.is_alive());
    ASSERT_TRUE(x1.name() == 'F');
    x1.change_state(1);
    ASSERT_TRUE(x1.is_alive());
    x1.change_state(1);
    ASSERT_TRUE(x1.is_alive());
    x1.change_state(1);
    ASSERT_TRUE(x1.name() == 'C');
}

TEST(Cell, change_state_2) {
	Cell x2(new ConwayCell(true));
    ASSERT_TRUE(x2.is_alive());
    ASSERT_TRUE(x2.name() == 'C');
    x2.change_state(1);
    ASSERT_TRUE(!x2.is_alive());
    x2.change_state(3);
    ASSERT_TRUE(x2.is_alive());
    x2.change_state(1);
    ASSERT_TRUE(x2.p_name() == 'X');
}

TEST(Cell, change_state_3) {
	Cell x3(new FredkinCell());
    ASSERT_TRUE(!x3.is_alive());
    ASSERT_TRUE(x3.name() == 'F');
    x3.change_state(1);
    ASSERT_TRUE(x3.is_alive());
    x3.change_state(1);
    ASSERT_TRUE(x3.is_alive());
    ASSERT_TRUE(x3.p_name() == 'X');
}

// -------------
// Cell printCell
// -------------

TEST(Cell, print_cell_1) {
	std::ostringstream w;
	Cell x1(new FredkinCell());
	x1.printCell(w);
    //collatz_print(w, 1, 10, 20);
    ASSERT_TRUE(w.str() == "-");
}

TEST(Cell, print_cell_2) {
	std::ostringstream w;
	Cell x2(new FredkinCell());
	x2.change_state(1);
	x2.change_state(1);
	x2.change_state(1);
	x2.printCell(w);
    //collatz_print(w, 1, 10, 20);
    ASSERT_TRUE(w.str() == "*");
}

TEST(Cell, print_cell_3) {
	std::ostringstream w;
	Cell x3(new ConwayCell());
	x3.printCell(w);
    //collatz_print(w, 1, 10, 20);
    ASSERT_TRUE(w.str() == ".");
}

// -------------
// Cell name
// -------------

TEST(Cell, name_1) {
	Cell x1(new FredkinCell());
    ASSERT_TRUE(!x1.is_alive());
    ASSERT_TRUE(x1.name() == 'F');
}

TEST(Cell, name_2) {
	Cell x2(new ConwayCell(true));
    ASSERT_TRUE(x2.is_alive());
    ASSERT_TRUE(x2.name() == 'C');
}

TEST(Cell, name_3) {
	Cell x3(new FredkinCell());
	x3.change_state(1);
	x3.change_state(1);
	x3.change_state(1);
    ASSERT_TRUE(x3.is_alive());
    ASSERT_TRUE(x3.name() == 'C');
}

// -------------
// Cell p_name
// -------------

TEST(Cell, p_name_1) {
	Cell x1(new FredkinCell());
    ASSERT_TRUE(!x1.is_alive());
    ASSERT_TRUE(x1.p_name() == 'X');
}

TEST(Cell, p_name_2) {
	Cell x2(new ConwayCell(true));
    ASSERT_TRUE(x2.is_alive());
    ASSERT_TRUE(x2.p_name() == 'X');
}

TEST(Cell, p_name_3) {
	Cell x3(new FredkinCell(true));
    ASSERT_TRUE(x3.is_alive());
    ASSERT_TRUE(x3.p_name() == 'X');
}
// -------------
// Cell read
// -------------

TEST(Cell, read_1) {
	Cell x1(new FredkinCell());
	std::istringstream r("0");
	x1.read(r);
    ASSERT_TRUE(x1.is_alive());
    ASSERT_TRUE(x1.p_name() == 'X');
}

TEST(Cell, read_2) {
	Cell x2(new FredkinCell(false));
	std::istringstream r("-");
	x2.read(r);
    ASSERT_TRUE(!x2.is_alive());
    ASSERT_TRUE(x2.name() == 'F');
}

TEST(Cell, read_3) {
	Cell x3(new ConwayCell());
	std::istringstream r("*");
	x3.read(r);
    ASSERT_TRUE(x3.is_alive());
    ASSERT_TRUE(x3.name() == 'C');
}
/********************************** Life ********************************/



