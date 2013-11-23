// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==
#include <stdexcept>

#include "gtest/gtest.h"

#include "Life.h"

// g++ -pedantic -std=c++0x -Wall TestLife.c++ Cell.c++ FredkinCell.c++ ConwayCell.c++ AbstractCell.c++ -o TestLife -lgtest -lpthread -lgtest_main

// -----------
// TestLife
// -----------

// -----------
// ConwayCell
// -----------

//Constructor +4 TESTS
TEST(Life, ConwayCellConstructor1){

	ConwayCell c(true);
	ASSERT_TRUE(c.is_alive());
	ASSERT_TRUE(c.get_type()=='C');	
}

TEST(Life, ConwayCellConstructor2){

	ConwayCell c(false);
	ASSERT_TRUE(!c.is_alive());
	ASSERT_TRUE(c.get_type()=='C');	
}

TEST(Life, ConwayCellConstructor3){

	ConwayCell c(true);
	ASSERT_TRUE(c.get_age()==0);	
}

TEST(Life, ConwayCellConstructor4){

	ConwayCell c(false);
	ASSERT_TRUE(c.get_age()==0);	
}

//Copy Constructor +4 TESTS
TEST(Life, ConwayCellCopyConstructor1){

	ConwayCell c(true);
	ConwayCell d(c);
	ASSERT_TRUE(c.is_alive());
	ASSERT_TRUE(c.get_type()=='C');	
	ASSERT_TRUE(d.is_alive());
	ASSERT_TRUE(d.get_type()=='C');	
}

TEST(Life, ConwayCellCopyConstructor2){

	ConwayCell c(false);
	ConwayCell d(c);
	ASSERT_TRUE(!c.is_alive());
	ASSERT_TRUE(c.get_type()=='C');	
	ASSERT_TRUE(!d.is_alive());
	ASSERT_TRUE(d.get_type()=='C');	
}

TEST(Life, ConwayCellCopyConstructor3){

	ConwayCell c(true);
	ConwayCell d(c);
	ASSERT_TRUE(c.get_age()==0);	
	ASSERT_TRUE(d.get_age()==0);	
}

TEST(Life, ConwayCellCopyConstructor4){

	ConwayCell c(false);
	ConwayCell d(c);
	ASSERT_TRUE(c.get_age()==0);
	ASSERT_TRUE(d.get_age()==0);
}

//kill +4 TESTS
TEST(Life, ConwayCellKill1){

	ConwayCell c(true);
	ASSERT_TRUE(c.is_alive());
	c.kill();
	ASSERT_TRUE(!c.is_alive());
}
TEST(Life, ConwayCellKill2){

	ConwayCell c(false);
	ASSERT_TRUE(!c.is_alive());
	c.kill();
	ASSERT_TRUE(!c.is_alive());
}
TEST(Life, ConwayCellCopyKill1){

	ConwayCell c(true);
	ConwayCell d(c);
	ASSERT_TRUE(d.is_alive());
	ASSERT_TRUE(c.is_alive());
	c.kill();
	ASSERT_TRUE(d.is_alive());
	ASSERT_TRUE(!c.is_alive());
}
TEST(Life, ConwayCellCopyKill2){

	ConwayCell c(false);
	ConwayCell d(c);
	ASSERT_TRUE(!d.is_alive());
	ASSERT_TRUE(!c.is_alive());
	c.kill();
	ASSERT_TRUE(!d.is_alive());
	ASSERT_TRUE(!c.is_alive());
}

//revive +4 TESTS
TEST(Life, ConwayCellRevive1){

	ConwayCell c(true);
	ASSERT_TRUE(c.is_alive());
	c.revive();
	ASSERT_TRUE(c.is_alive());
}
TEST(Life, ConwayCellRevive2){

	ConwayCell c(false);
	ASSERT_TRUE(!c.is_alive());
	c.revive();
	ASSERT_TRUE(c.is_alive());
}
TEST(Life, ConwayCellCopyRevive1){

	ConwayCell c(true);
	ConwayCell d(c);
	ASSERT_TRUE(d.is_alive());
	ASSERT_TRUE(c.is_alive());
	c.revive();
	ASSERT_TRUE(d.is_alive());
	ASSERT_TRUE(c.is_alive());
}
TEST(Life, ConwayCellCopyRevive2){

	ConwayCell c(false);
	ConwayCell d(c);
	ASSERT_TRUE(!d.is_alive());
	ASSERT_TRUE(!c.is_alive());
	c.revive();
	ASSERT_TRUE(!d.is_alive());
	ASSERT_TRUE(c.is_alive());
}

//get_type +2 TESTS
TEST(Life, ConwayCellGetType1){

	ConwayCell c(false);
	ASSERT_TRUE(c.get_type()=='C');
}
TEST(Life, ConwayCellGetType2){

	ConwayCell c(true);
	ASSERT_TRUE(c.get_type()=='C');
}

//clone +2 TESTS
TEST(Life, ConwayCellClone1){

	ConwayCell c(false);
	AbstractCell* dp = c.clone();
	AbstractCell& d = *dp;

	ASSERT_TRUE(d.is_alive()==c.is_alive());
	ASSERT_TRUE(c.get_type()==d.get_type());
	delete dp;
}
TEST(Life, ConwayCellClone2){

	ConwayCell c(true);
	AbstractCell* dp = c.clone();
	AbstractCell& d = *dp;

	ASSERT_TRUE(d.is_alive()==c.is_alive());
	ASSERT_TRUE(c.get_type()==d.get_type());
	delete dp;
}

// -----------
//	FredkinCell
// -----------

//Constructor +4 TESTS
TEST(Life, FredkinCellConstructor1){

	FredkinCell c(true);
	ASSERT_TRUE(c.is_alive());
	ASSERT_TRUE(c.get_type()=='F');
	ASSERT_TRUE(c.get_age()==0);
}

TEST(Life, FredkinCellConstructor2){

	FredkinCell c(false);
	ASSERT_TRUE(!c.is_alive());
	ASSERT_TRUE(c.get_type()=='F');	
	ASSERT_TRUE(c.get_age()==0);
}

TEST(Life, FredkinCellConstructor3){

	FredkinCell c(true,'5');
	ASSERT_TRUE(c.is_alive());
	ASSERT_TRUE(c.get_age()==5);	
}

TEST(Life, FredkinCellConstructor4){

	FredkinCell c(false,'+');
	ASSERT_TRUE(!c.is_alive());
	ASSERT_TRUE(c.get_age()>9);	
}

//Copy Constructor +4 TESTS
TEST(Life, FredkinCellCopyConstructor1){

	FredkinCell c(true);
	FredkinCell d(c);
	ASSERT_TRUE(c.is_alive()==d.is_alive());
	ASSERT_TRUE(c.get_type()==d.get_type());
	ASSERT_TRUE(c.get_age()==d.get_age());
}

TEST(Life, FredkinCellCopyConstructor2){

	FredkinCell c(false);
	FredkinCell d(c);
	ASSERT_TRUE(c.is_alive()==d.is_alive());
	ASSERT_TRUE(c.get_type()==d.get_type());
	ASSERT_TRUE(c.get_age()==d.get_age());
}

TEST(Life, FredkinCellCopyConstructor3){

	FredkinCell c(true,'6');
	FredkinCell d(c);
	ASSERT_TRUE(c.is_alive()==d.is_alive());
	ASSERT_TRUE(c.get_type()==d.get_type());
	ASSERT_TRUE(c.get_age()==d.get_age());	
}

TEST(Life, FredkinCellCopyConstructor4){

	FredkinCell c(false,'0');
	FredkinCell d(c);
	ASSERT_TRUE(c.is_alive()==d.is_alive());
	ASSERT_TRUE(c.get_type()==d.get_type());
	ASSERT_TRUE(c.get_age()==d.get_age());
}

//kill +4 TESTS
TEST(Life, FredkinCellKill1){

	FredkinCell c(true);
	ASSERT_TRUE(c.is_alive());
	c.kill();
	ASSERT_TRUE(!c.is_alive());
}
TEST(Life, FredkinCellKill2){

	FredkinCell c(false);
	ASSERT_TRUE(!c.is_alive());
	c.kill();
	ASSERT_TRUE(!c.is_alive());
}
TEST(Life, FredkinCellKill3){

	FredkinCell c(true);
	FredkinCell d(c);
	ASSERT_TRUE(d.is_alive());
	ASSERT_TRUE(c.is_alive());
	c.kill();
	ASSERT_TRUE(d.is_alive());
	ASSERT_TRUE(!c.is_alive());
}
TEST(Life, FredkinCellKill4){

	FredkinCell c(false);
	FredkinCell d(c);
	ASSERT_TRUE(!d.is_alive());
	ASSERT_TRUE(!c.is_alive());
	c.kill();
	ASSERT_TRUE(!d.is_alive());
	ASSERT_TRUE(!c.is_alive());
}

//revive +4 TESTS
TEST(Life, FredkinCellRevive1){

	FredkinCell c(true);
	ASSERT_TRUE(c.is_alive());
	c.revive();
	ASSERT_TRUE(c.is_alive());
}
TEST(Life, FredkinCellRevive2){

	FredkinCell c(false);
	ASSERT_TRUE(!c.is_alive());
	c.revive();
	ASSERT_TRUE(c.is_alive());
}
TEST(Life, FredkinCellCopyRevive1){

	FredkinCell c(true,'+');
	FredkinCell d(c);
	ASSERT_TRUE(d.is_alive());
	ASSERT_TRUE(c.is_alive());
	c.revive();
	ASSERT_TRUE(d.is_alive());
	ASSERT_TRUE(c.is_alive());
}
TEST(Life, FredkinCellCopyRevive2){

	FredkinCell c(false,'0');
	FredkinCell d(c);
	ASSERT_TRUE(!d.is_alive());
	ASSERT_TRUE(!c.is_alive());
	c.revive();
	ASSERT_TRUE(!d.is_alive());
	ASSERT_TRUE(c.is_alive());
}

//get_type +4 TESTS
TEST(Life, FredkinCellGetType1){

	FredkinCell c(false);
	ASSERT_TRUE(c.get_type()=='F');
}
TEST(Life, FredkinCellGetType2){

	FredkinCell c(true);
	ASSERT_TRUE(c.get_type()=='F');
}
TEST(Life, FredkinCellGetType3){

	FredkinCell c(false,'+');
	ASSERT_TRUE(c.get_type()=='F');
}
TEST(Life, FredkinCellGetType4){

	FredkinCell c(true,'0');
	ASSERT_TRUE(c.get_type()=='F');
}

//clone +2 TESTS
TEST(Life, FredkinCellClone1){

	FredkinCell c(false);
	AbstractCell* dp = c.clone();
	AbstractCell& d = *dp;

	ASSERT_TRUE(d.is_alive()==c.is_alive());
	ASSERT_TRUE(c.get_type()==d.get_type());
	delete dp;
}
TEST(Life, FredkinCellClone2){

	FredkinCell c(true);
	AbstractCell* dp = c.clone();
	AbstractCell& d = *dp;

	ASSERT_TRUE(d.is_alive()==c.is_alive());
	ASSERT_TRUE(c.get_type()==d.get_type());
	delete dp;
}

//get_age +4 TESTS
TEST(Life, FredkinCellGetAge1){

	FredkinCell c(false);
	ASSERT_TRUE(c.get_age()==0);
}
TEST(Life, FredkinCellGetAge2){

	FredkinCell c(true);
	ASSERT_TRUE(c.get_age()==0);
}
TEST(Life, FredkinCellGetAge3){

	FredkinCell c(false,'9');
	ASSERT_TRUE(c.get_age()==9);
}
TEST(Life, FredkinCellGetAge4){

	FredkinCell c(true,'+');
	ASSERT_TRUE(c.get_age()>9);
}

// -----------
//	Cell
// -----------

//Constructor +4 TESTS
TEST(Life, CellConstructor1){

	Cell c(new ConwayCell(true));
	ASSERT_TRUE(c.is_alive());
	ASSERT_TRUE(c.get_type()=='C');	
}

TEST(Life, CellConstructor2){

	Cell c(new ConwayCell(false));
	ASSERT_TRUE(!c.is_alive());
	ASSERT_TRUE(c.get_type()=='C');	
}

TEST(Life, CellConstructor3){

	Cell c(new FredkinCell(true));
	ASSERT_TRUE(c.get_age()==0);	
	ASSERT_TRUE(c.get_type()=='F');
}

TEST(Life, CellConstructor4){

	Cell c(new FredkinCell(true,'5'));;
	ASSERT_TRUE(c.get_age()==5);
	ASSERT_TRUE(c.get_type()=='F');	
}

//kill +4 TESTS
TEST(Life, CellKill1){

	Cell c(new ConwayCell(true));
	ASSERT_TRUE(c.is_alive());
	c.kill();
	ASSERT_TRUE(!c.is_alive());
}
TEST(Life, CellKill2){

	Cell c(new ConwayCell(false));
	ASSERT_TRUE(!c.is_alive());
	c.kill();
	ASSERT_TRUE(!c.is_alive());
}
TEST(Life, CellKill3){

	Cell c(new FredkinCell(true));

	ASSERT_TRUE(c.is_alive());
	c.kill();
	ASSERT_TRUE(!c.is_alive());
}
TEST(Life, CellKill4){

	Cell c(new FredkinCell(false));

	ASSERT_TRUE(!c.is_alive());
	c.kill();
	ASSERT_TRUE(!c.is_alive());
}

//revive +4 TESTS
TEST(Life, CellRevive1){

	Cell c(new ConwayCell(true));
	ASSERT_TRUE(c.is_alive());
	c.revive();
	ASSERT_TRUE(c.is_alive());
}
TEST(Life, CellRevive2){

	Cell c(new ConwayCell(false));
	ASSERT_TRUE(!c.is_alive());
	c.revive();
	ASSERT_TRUE(c.is_alive());
}
TEST(Life, CellRevive3){

	Cell c(new FredkinCell(true));
	ASSERT_TRUE(c.is_alive());
	c.revive();
	ASSERT_TRUE(c.is_alive());
}
TEST(Life, CellRevive4){

	Cell c(new FredkinCell(false,'0'));
	ASSERT_TRUE(!c.is_alive());
	c.revive();
	ASSERT_TRUE(c.is_alive());
}

//get_type +4 TESTS
TEST(Life, CellGetType1){

	Cell c(new ConwayCell(false));
	ASSERT_TRUE(c.get_type()=='C');
}
TEST(Life, CellGetType2){

	Cell c(new ConwayCell(true));
	ASSERT_TRUE(c.get_type()=='C');
}
TEST(Life, CellGetType3){

	Cell c(new FredkinCell(false));
	ASSERT_TRUE(c.get_type()=='F');
}
TEST(Life, CellGetType4){

	Cell c(new FredkinCell(true,'9'));
	ASSERT_TRUE(c.get_type()=='F');
}

//clone +4 TESTS
TEST(Life, CellClone1){

	Cell c(new ConwayCell(false));
	AbstractCell* dp = c.clone();
	AbstractCell& d= *dp; 

	ASSERT_TRUE(d.is_alive()==c.is_alive());
	ASSERT_TRUE(c.get_type()==d.get_type());
	delete dp;
}
TEST(Life, CellClone2){

	Cell c(new ConwayCell(true));
	AbstractCell* dp = c.clone();
	AbstractCell& d= *dp; 

	ASSERT_TRUE(d.is_alive()==c.is_alive());
	ASSERT_TRUE(c.get_type()==d.get_type());
	delete dp;
}
TEST(Life, CellClone3){

	Cell c(new FredkinCell(false,'+'));
	AbstractCell* dp = c.clone();
	AbstractCell& d= *dp; 

	ASSERT_TRUE(d.is_alive()==c.is_alive());
	ASSERT_TRUE(c.get_type()==d.get_type());
	ASSERT_TRUE(c.get_age()==d.get_age());
	delete dp;
}
TEST(Life, CellClone4){

	Cell c(new FredkinCell(true));
	AbstractCell* dp = c.clone();
	AbstractCell& d= *dp; 

	ASSERT_TRUE(d.is_alive()==c.is_alive());
	ASSERT_TRUE(c.get_type()==d.get_type());
	ASSERT_TRUE(c.get_age()==d.get_age());
	delete dp;
}

//mutate +3 TESTS
TEST(Life, CellMutate1){

	Cell c(new FredkinCell(true));
	ASSERT_TRUE(c.get_type()=='F');

	c.mutate();
	ASSERT_TRUE(c.get_type()=='C');
	ASSERT_TRUE(c.is_alive());
}
TEST(Life, CellMutate2){

	Cell c(new FredkinCell(true,'+'));
	ASSERT_TRUE(c.get_type()=='F');

	c.mutate();
	ASSERT_TRUE(c.get_type()=='C');
	ASSERT_TRUE(c.get_age()==0);
	ASSERT_TRUE(c.is_alive());
}
TEST(Life, CellMutate3){

	Cell c(new FredkinCell(false,'5'));
	ASSERT_TRUE(c.get_type()=='F');

	c.mutate();
	ASSERT_TRUE(c.get_type()=='C');
	ASSERT_TRUE(c.get_age()==0);
	ASSERT_TRUE(c.is_alive());
}

