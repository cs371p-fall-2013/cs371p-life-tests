// --------------------------------------------
// University of Texas - Austin
// CS371p: Object-Oriented Programming
// PROJECT 5: Life
// Ian A. Hays - IH2974
// --------------------------------------------


// ------------------------
// #includes, #defines
// ------------------------
#include <iostream> 	// cout, endl
#include <sstream>  	// istringtstream, ostringstream
#include <string>   	// ==
#include "gtest/gtest.h"//test interface
#include "Life.h"		//Life runtime class

// ------------------------------------------------
// ConwayCell Class Unit Tests
// ------------------------------------------------
// ------------------------
// ConwayCell::mutate
// ------------------------
TEST(ConwayCell, ConwayCell_mutate_livetodead) 
{
	ConwayCell cell1;
	cell1.alive = true;
	cell1.previousAlive = false;
	
	ASSERT_TRUE(cell1.mutate('.'));
	ASSERT_TRUE(cell1.representation() == '.');
	ASSERT_TRUE(!cell1.alive);
	ASSERT_TRUE(cell1.previousAlive);
}

TEST(ConwayCell, ConwayCell_mutate_deadtolive) 
{
	ConwayCell cell1;
	cell1.alive = true;
	cell1.previousAlive = false;
	
	ASSERT_TRUE(cell1.mutate('.'));
	ASSERT_TRUE(cell1.representation() == '.');
	ASSERT_TRUE(!cell1.alive);
	ASSERT_TRUE(cell1.previousAlive);
}

TEST(ConwayCell, ConwayCell_mutate_livetolive) 
{
	ConwayCell cell1;
	cell1.alive = true;
	cell1.previousAlive = false;
	
	ASSERT_TRUE(cell1.mutate('*'));
	ASSERT_TRUE(cell1.representation() == '*');
	ASSERT_TRUE(cell1.alive);
	ASSERT_TRUE(cell1.previousAlive);
}

TEST(ConwayCell, ConwayCell_mutate_invalid) 
{
	ConwayCell cell1;
	cell1.alive = true;
	cell1.previousAlive = false;
	
	ASSERT_FALSE(cell1.mutate('8'));
	ASSERT_TRUE(cell1.representation() == '*');
	ASSERT_TRUE(cell1.alive);
	ASSERT_TRUE(!cell1.previousAlive);
}
// ------------------------
// ConwayCell::nextGen
// ------------------------
TEST(ConwayCell, ConwayCell_nextGen_livetolive) 
{
	ConwayCell cell1;
	cell1.alive = true;
	cell1.previousAlive = false;
	
	cell1.nextGen(1,2);
	ASSERT_TRUE(cell1.representation() == '*');
	ASSERT_TRUE(cell1.alive);
	ASSERT_TRUE(cell1.previousAlive);
}

TEST(ConwayCell, ConwayCell_nextGen_livetodead) 
{
	ConwayCell cell1;
	cell1.alive = true;
	cell1.previousAlive = false;
	
	cell1.nextGen(0,1);
	ASSERT_TRUE(cell1.representation() == '.');
	ASSERT_TRUE(!cell1.alive);
	ASSERT_TRUE(cell1.previousAlive);
}

TEST(ConwayCell, ConwayCell_nextGen_livenochange) 
{
	ConwayCell cell1;
	cell1.alive = true;
	cell1.previousAlive = false;
	
	cell1.nextGen(1,1);
	ASSERT_TRUE(cell1.representation() == '*');
	ASSERT_TRUE(cell1.alive);
	ASSERT_TRUE(cell1.previousAlive);
}

TEST(ConwayCell, ConwayCell_nextGen_deadtolive) 
{
	ConwayCell cell1;
	cell1.alive = false;
	cell1.previousAlive = true;
	
	cell1.nextGen(3,0);
	ASSERT_TRUE(cell1.representation() == '*');
	ASSERT_TRUE(cell1.alive);
	ASSERT_TRUE(!cell1.previousAlive);
}

TEST(ConwayCell, ConwayCell_nextGen_deadtodead) 
{
	ConwayCell cell1;
	cell1.alive = false;
	cell1.previousAlive = true;
	
	cell1.nextGen(0,0);
	ASSERT_TRUE(cell1.representation() == '.');
	ASSERT_TRUE(!cell1.alive);
	ASSERT_TRUE(!cell1.previousAlive);
}

TEST(ConwayCell, ConwayCell_nextGen_deadnochange) 
{
	ConwayCell cell1;
	cell1.alive = false;
	cell1.previousAlive = true;
	
	cell1.nextGen(0,2);
	ASSERT_TRUE(cell1.representation() == '.');
	ASSERT_TRUE(!cell1.alive);
	ASSERT_TRUE(!cell1.previousAlive);
}

// ------------------------
// ConwayCell::representation
// ------------------------
TEST(ConwayCell, ConwayCell_representation_1) 
{
	ConwayCell cell1;
	ASSERT_TRUE(cell1.representation() == '.');
}

TEST(ConwayCell, ConwayCell_representation_2) 
{
	ConwayCell cell1;
	cell1.alive = true;
	ASSERT_TRUE(cell1.representation() == '*');
}

// ------------------------
// ConwayCell::clone
// ------------------------
TEST(ConwayCell, ConwayCell_clone_1) 
{
	ConwayCell cell1;
	cell1.alive = true;
	cell1.previousAlive = true;
	AbstractCell *cell2 = cell1.clone();
	ASSERT_TRUE(cell2->representation() == '*');
	ASSERT_TRUE(cell2->alive);
	ASSERT_TRUE(cell2->previousAlive);
}

TEST(ConwayCell, ConwayCell_clone_2) 
{
	ConwayCell cell1;
	cell1.alive = false;
	cell1.previousAlive = true;
	AbstractCell *cell2 = cell1.clone();
	ASSERT_TRUE(cell2->representation() == '.');
	ASSERT_TRUE(!(cell2->alive));
	ASSERT_TRUE(cell2->previousAlive);
}

// ------------------------------------------------
// End of ConwayCell Class Unit Tests
// ------------------------------------------------
// ------------------------------------------------
// FredkinCell Class Unit Tests
// ------------------------------------------------
// ------------------------
// FredkinCell::mutate
// ------------------------
TEST(FredkinCell, FredkinCell_mutate_livetodead) 
{
	FredkinCell cell1;
	cell1.alive = true;
	cell1.previousAlive = false;
	
	ASSERT_TRUE(cell1.mutate('-'));
	ASSERT_TRUE(cell1.representation() == '-');
	ASSERT_TRUE(!cell1.alive);
	ASSERT_TRUE(cell1.previousAlive);
}

TEST(FredkinCell, FredkinCell_mutate_deadtolive) 
{
	FredkinCell cell1;
	cell1.alive = true;
	cell1.previousAlive = false;
	
	ASSERT_TRUE(cell1.mutate('0'));
	ASSERT_TRUE(cell1.representation() == '0');
	ASSERT_TRUE(cell1.alive);
	ASSERT_TRUE(cell1.previousAlive);
}

TEST(FredkinCell, FredkinCell_mutate_modifyAge) 
{
	FredkinCell cell1;
	cell1.alive = true;
	cell1.previousAlive = false;
	
	ASSERT_TRUE(cell1.mutate('5'));
	ASSERT_TRUE(cell1.representation() == '5');
	ASSERT_TRUE(cell1.alive);
	ASSERT_TRUE(cell1.previousAlive);
}

TEST(FredkinCell, FredkinCell_mutate_modifyAge2) 
{
	FredkinCell cell1;
	cell1.alive = false;
	cell1.previousAlive = true;
	
	ASSERT_TRUE(cell1.mutate('+'));
	ASSERT_TRUE(cell1.representation() == '+');
	ASSERT_TRUE(cell1.alive);
	ASSERT_TRUE(!cell1.previousAlive);
}

TEST(FredkinCell, FredkinCell_mutate_invalid) 
{
	FredkinCell cell1;
	cell1.alive = true;
	cell1.previousAlive = false;
	
	ASSERT_FALSE(cell1.mutate('a'));
	ASSERT_TRUE(cell1.representation() == '0');
	ASSERT_TRUE(cell1.alive);
	ASSERT_TRUE(!cell1.previousAlive);
}
// ------------------------
// FredkinCell::nextGen
// ------------------------
TEST(FredkinCell, FredkinCell_nextGen_ignoreDiagonal) 
{
	FredkinCell cell1;
	cell1.alive = true;
	cell1.previousAlive = false;
	
	cell1.nextGen(1,900);
	ASSERT_TRUE(cell1.representation() == '1');
	ASSERT_TRUE(cell1.alive);
	ASSERT_TRUE(cell1.previousAlive);
}

TEST(FredkinCell, FredkinCell_nextGen_ageIncrease) 
{
	FredkinCell cell1;
	cell1.alive = true;
	cell1.previousAlive = true;
	cell1.age = 8;
	
	cell1.nextGen(3,60);
	ASSERT_TRUE(cell1.representation() == '9');
	ASSERT_TRUE(cell1.alive);
	ASSERT_TRUE(cell1.previousAlive);
}

TEST(FredkinCell, FredkinCell_nextGen_ageDontIncrease) 
{
	FredkinCell cell1;
	cell1.alive = false;
	cell1.previousAlive = true;
	
	cell1.nextGen(1,1);
	ASSERT_TRUE(cell1.representation() == '0');
	ASSERT_TRUE(cell1.alive);
	ASSERT_TRUE(!cell1.previousAlive);
}

TEST(FredkinCell, FredkinCell_nextGen_livetodead) 
{
	FredkinCell cell1;
	cell1.alive = true;
	cell1.previousAlive = false;
	
	cell1.nextGen(2,89);
	ASSERT_TRUE(cell1.representation() == '-');
	ASSERT_TRUE(!cell1.alive);
	ASSERT_TRUE(cell1.previousAlive);
}

TEST(FredkinCell, FredkinCell_nextGen_preserveAge) 
{
	FredkinCell cell1;
	cell1.alive = true;
	cell1.previousAlive = false;
	cell1.age = 8;
	
	cell1.nextGen(4,89);
	ASSERT_TRUE(cell1.representation() == '-');
	ASSERT_TRUE(!cell1.alive);
	ASSERT_TRUE(cell1.previousAlive);
	ASSERT_TRUE(cell1.age == 8);
}

// ------------------------
// FredkinCell::representation
// ------------------------
TEST(FredkinCell, FredkinCell_representation_1) 
{
	FredkinCell cell1;
	ASSERT_TRUE(cell1.representation() == '-');
}

TEST(FredkinCell, FredkinCell_representation_2) 
{
	FredkinCell cell1;
	cell1.alive = true;
	ASSERT_TRUE(cell1.representation() == '0');
}

TEST(FredkinCell, FredkinCell_representation_3) 
{
	FredkinCell cell1;
	cell1.alive = true;
	cell1.age = 9;
	ASSERT_TRUE(cell1.representation() == '9');
}

TEST(FredkinCell, FredkinCell_representation_4) 
{
	FredkinCell cell1;
	cell1.alive = false;
	cell1.age = 12;
	ASSERT_TRUE(cell1.representation() == '-');
}

TEST(FredkinCell, FredkinCell_representation_5) 
{
	FredkinCell cell1;
	cell1.alive = true;
	cell1.age = 12;
	ASSERT_TRUE(cell1.representation() == '+');
}

// ------------------------
// FredkinCell::clone
// ------------------------
TEST(FredkinCell, FredkinCell_clone_1) 
{
	FredkinCell cell1;
	cell1.alive = true;
	cell1.previousAlive = true;
	cell1.age = 5;
	FredkinCell *cell2 = dynamic_cast<FredkinCell*>(cell1.clone());
	
	ASSERT_TRUE(cell2->alive);
	ASSERT_TRUE(cell2->age == 5);
	ASSERT_TRUE(cell2->previousAlive);
	ASSERT_TRUE(cell2->representation() == '5');
}

TEST(FredkinCell, FredkinCell_clone_2) 
{
	FredkinCell cell1;
	cell1.alive = false;
	cell1.previousAlive = true;
	cell1.age = 12;
	FredkinCell *cell2 = dynamic_cast<FredkinCell*>(cell1.clone());
	
	ASSERT_TRUE(!(cell2->alive));
	ASSERT_TRUE(cell2->age == 12);
	ASSERT_TRUE(cell2->previousAlive);
	ASSERT_TRUE(cell2->representation() == '-');
}

// ------------------------------------------------
// End of FredkinCell Class Unit Tests
// ------------------------------------------------
// ------------------------------------------------
// Cell Class Unit Tests
// ------------------------------------------------
// ------------------------
// Cell::Cell
// ------------------------
TEST(Cell, Cell_Constructor_liveConway) 
{
	ConwayCell *con1 = new ConwayCell();
	con1->alive = true;
	con1->previousAlive = true;
	
	Cell cell1(con1);
		
	ASSERT_TRUE(cell1.alive);
	ASSERT_TRUE(cell1.previousAlive);
	ASSERT_TRUE(cell1.representation() == '*');
}

TEST(Cell, Cell_Constructor_liveFredkin) 
{
	FredkinCell *fred1 = new FredkinCell();
	fred1->alive = true;
	fred1->previousAlive = true;
	
	Cell cell1(fred1);
		
	ASSERT_TRUE(cell1.alive);
	ASSERT_TRUE(cell1.previousAlive);
	ASSERT_TRUE(cell1.representation() == '0');
}

TEST(Cell, Cell_Constructor_deadConway) 
{
	ConwayCell *con1 = new ConwayCell();
	con1->alive = false;
	con1->previousAlive = true;
	
	Cell cell1(con1);
		
	ASSERT_TRUE(!(cell1.alive));
	ASSERT_TRUE(cell1.previousAlive);
	ASSERT_TRUE(cell1.representation() == '.');
}

TEST(Cell, Cell_Constructor_deadFredkin) 
{
	FredkinCell *fred1 = new FredkinCell();
	fred1->alive = false;
	fred1->previousAlive = true;
	
	Cell cell1(fred1);
		
	ASSERT_TRUE(!(cell1.alive));
	ASSERT_TRUE(cell1.previousAlive);
	ASSERT_TRUE(cell1.representation() == '-');
}

// ------------------------
// Cell::mutate
// ------------------------
TEST(Cell, Cell_mutate_liveFredkinToDeadConway) 
{
	FredkinCell *fred1 = new FredkinCell();
	fred1->alive = true;
	fred1->previousAlive = true;
	
	Cell cell1(fred1);
	cell1.mutate('.');
	
	ASSERT_TRUE(!(cell1.alive));
	ASSERT_TRUE(cell1.previousAlive);
	ASSERT_TRUE(cell1.representation() == '.');
}

TEST(Cell, Cell_mutate_liveFredkinToLiveConway) 
{
	FredkinCell *fred1 = new FredkinCell();
	fred1->alive = false;
	fred1->previousAlive = true;
	
	Cell cell1(fred1);
	cell1.mutate('*');
	
	ASSERT_TRUE(cell1.alive);
	ASSERT_TRUE(!(cell1.previousAlive));
	ASSERT_TRUE(cell1.representation() == '*');
}

TEST(Cell, Cell_mutate_invalid) 
{
	FredkinCell *fred1 = new FredkinCell();
	fred1->alive = true;
	fred1->previousAlive = true;
	
	Cell cell1(fred1);
	ASSERT_FALSE(cell1.mutate('p'));
	
	ASSERT_TRUE(cell1.alive);
	ASSERT_TRUE(cell1.previousAlive);
	ASSERT_TRUE(cell1.representation() == '0');
}

TEST(Cell, Cell_mutate_ConwaySwitch) 
{
	ConwayCell *con1 = new ConwayCell();
	con1->alive = false;
	con1->previousAlive = true;
	
	Cell cell1(con1);
	cell1.mutate('*');
	
	ASSERT_TRUE(cell1.alive);
	ASSERT_TRUE(!(cell1.previousAlive));
	ASSERT_TRUE(cell1.representation() == '*');
}

TEST(Cell, Cell_mutate_FredkinSwitch) 
{
	FredkinCell *fred1 = new FredkinCell();
	fred1->alive = true;
	fred1->previousAlive = false;
	fred1->age = 7;
	
	Cell cell1(fred1);
	cell1.mutate('0');
	
	ASSERT_TRUE(cell1.alive);
	ASSERT_TRUE(cell1.previousAlive);
	ASSERT_TRUE(cell1.representation() == '0');
}

// ------------------------
// Cell::nextGen
// ------------------------
TEST(Cell, Cell_nextGen_fredkinNext) 
{
	FredkinCell *fred1 = new FredkinCell();
	fred1->alive = true;
	fred1->previousAlive = false;
	fred1->age = 7;
	
	Cell cell1(fred1);
	cell1.nextGen(1,20);
	
	ASSERT_TRUE(cell1.alive);
	ASSERT_TRUE(cell1.previousAlive);
	ASSERT_TRUE(cell1.representation() == '8');
}

TEST(Cell, Cell_nextGen_conwayNext) 
{
	ConwayCell *con1 = new ConwayCell();
	con1->alive = true;
	con1->previousAlive = true;
	
	Cell cell1(con1);
	cell1.nextGen(4,4);
	
	ASSERT_TRUE(!(cell1.alive));
	ASSERT_TRUE(cell1.previousAlive);
	ASSERT_TRUE(cell1.representation() == '.');
}

TEST(Cell, Cell_nextGen_FredkinSwitchToConway) 
{
	FredkinCell *fred1 = new FredkinCell();
	fred1->alive = true;
	fred1->previousAlive = false;
	fred1->age = 1;
	
	Cell cell1(fred1);
	cell1.nextGen(1,20);
	
	ASSERT_TRUE(cell1.alive);
	ASSERT_TRUE(cell1.previousAlive);
	ASSERT_TRUE(cell1.representation() == '*');
}

TEST(Cell, Cell_nextGen_FredkinSwitchToConway2) 
{
	FredkinCell *fred1 = new FredkinCell();
	fred1->alive = false;
	fred1->previousAlive = false;
	fred1->age = 1;
	
	Cell cell1(fred1);
	cell1.nextGen(3,20);
	
	ASSERT_TRUE(cell1.alive);
	ASSERT_TRUE(!(cell1.previousAlive));
	ASSERT_TRUE(cell1.representation() == '1');
}

TEST(Cell, Cell_nextGen_FredkinSwitchToConway3) 
{
	FredkinCell *fred1 = new FredkinCell();
	fred1->alive = false;
	fred1->previousAlive = false;
	fred1->age = 1;
	
	Cell cell1(fred1);
	cell1.nextGen(3,20);
	ASSERT_TRUE(cell1.representation() == '1');	
	
	cell1.nextGen(2,10);
	ASSERT_TRUE(cell1.representation() == '-');
	
	cell1.nextGen(3,20);
	ASSERT_TRUE(cell1.representation() == '1');	
	
	cell1.nextGen(2,10);
	ASSERT_TRUE(cell1.representation() == '-');
	
	cell1.nextGen(3,20);
	ASSERT_TRUE(cell1.representation() == '1');
}

// ------------------------------------------------
// End of Cell Class Unit Tests
// ------------------------------------------------
// ------------------------------------------------
// Life Class Unit Tests
// ------------------------------------------------
// ------------------------
// Life::Life and Life::printGrid
// ------------------------
TEST(Life, Life_Constructor_tiny) 
{
	Life<ConwayCell> life1(1,1);
	std::ostringstream correct_out;
	std::ostringstream test_out;

	correct_out << "Generation = 0, Population = 0.\n";
	correct_out <<  ".\n";
	
	correct_out << "\n";
	life1.printGrid(test_out);
	ASSERT_TRUE(test_out.str() == correct_out.str());
}

TEST(Life, Life_Constructor_largeConway) 
{
	Life<ConwayCell> life1(10,10);
	std::ostringstream correct_out;
	std::ostringstream test_out;

	correct_out  << "Generation = 0, Population = 0.\n";
	correct_out  <<  "..........\n"  <<
					 "..........\n"  <<
					 "..........\n"  <<
					 "..........\n"  <<
					 "..........\n"  <<
					 "..........\n"  <<
					 "..........\n"  <<
					 "..........\n"  <<
					 "..........\n"  <<
					 "..........\n";

	
	correct_out << "\n";
	life1.printGrid(test_out);
	ASSERT_TRUE(test_out.str() == correct_out.str());
}

TEST(Life, Life_Constructor_largeFredkin) 
{
	Life<FredkinCell> life1(10,10);
	std::ostringstream correct_out;
	std::ostringstream test_out;

	correct_out  << "Generation = 0, Population = 0.\n";
	correct_out  <<  "----------\n"  <<
					 "----------\n"  << 
					 "----------\n"  << 
					 "----------\n"  << 
					 "----------\n"  << 
					 "----------\n"  << 
					 "----------\n"  << 
					 "----------\n"  << 
					 "----------\n"  << 
					 "----------\n";
	
	correct_out << "\n";
	life1.printGrid(test_out);
	ASSERT_TRUE(test_out.str() == correct_out.str());
}

TEST(Life, Life_Constructor_largeCell) 
{
	Life<Cell> life1(10,10);
	std::ostringstream correct_out;
	std::ostringstream test_out;

	correct_out  << "Generation = 0, Population = 0.\n";
	correct_out  <<  "----------\n"  <<
					 "----------\n"  << 
					 "----------\n"  << 
					 "----------\n"  << 
					 "----------\n"  << 
					 "----------\n"  << 
					 "----------\n"  << 
					 "----------\n"  << 
					 "----------\n"  << 
					 "----------\n";
	
	correct_out << "\n";
	life1.printGrid(test_out);
	ASSERT_TRUE(test_out.str() == correct_out.str());
}

// ------------------------
// Life::initCell
// ------------------------
TEST(Life, Life_initCell_Fredkin1) 
{
	Life<FredkinCell> life1(10,10);
	std::ostringstream correct_out;
	std::ostringstream test_out;

	life1.initCell(0,0,'0');
	life1.initCell(5,2,'3');
	life1.initCell(9,9,'+');
	correct_out  << "Generation = 0, Population = 3.\n";
	correct_out  <<  "0---------\n"  <<
					 "----------\n"  << 
					 "----------\n"  << 
					 "----------\n"  << 
					 "----------\n"  << 
					 "--3-------\n"  << 
					 "----------\n"  << 
					 "----------\n"  << 
					 "----------\n"  << 
					 "---------+\n";
	
	correct_out << "\n";
	life1.printGrid(test_out);
	ASSERT_TRUE(test_out.str() == correct_out.str());
}

TEST(Life, Life_initCell_invalidFredkin) 
{
	Life<FredkinCell> life1(10,10);
	std::ostringstream correct_out;
	std::ostringstream test_out;

	life1.initCell(0,0,'0');
	life1.initCell(5,2,'d');
	life1.initCell(9,9,'+');
	
	correct_out  << "Generation = 0, Population = 2.\n";
	correct_out  <<  "0---------\n"  <<
					 "----------\n"  << 
					 "----------\n"  << 
					 "----------\n"  << 
					 "----------\n"  << 
					 "----------\n"  << 
					 "----------\n"  << 
					 "----------\n"  << 
					 "----------\n"  << 
					 "---------+\n";
	
	correct_out << "\n";
	life1.printGrid(test_out);
	ASSERT_TRUE(test_out.str() == correct_out.str());
}

TEST(Life, Life_initCell_Conway1) 
{
	Life<ConwayCell> life1(10,10);
	std::ostringstream correct_out;
	std::ostringstream test_out;

	life1.initCell(0,0,'*');
	life1.initCell(5,2,'.');
	life1.initCell(9,9,'*');
	
	correct_out  << "Generation = 0, Population = 2.\n";
	correct_out  <<  "*.........\n"  <<
					 "..........\n"  <<
					 "..........\n"  <<
					 "..........\n"  <<
					 "..........\n"  <<
					 "..........\n"  <<
					 "..........\n"  <<
					 "..........\n"  <<
					 "..........\n"  <<
					 ".........*\n";
	
	correct_out << "\n";
	life1.printGrid(test_out);
	ASSERT_TRUE(test_out.str() == correct_out.str());
}

TEST(Life, Life_initCell_invalidConway) 
{
	Life<ConwayCell> life1(10,10);
	std::ostringstream correct_out;
	std::ostringstream test_out;

	life1.initCell(0,0,'*');
	life1.initCell(5,2,'a');
	life1.initCell(9,9,'*');
	
	correct_out  << "Generation = 0, Population = 2.\n";
	correct_out  <<  "*.........\n"  <<
					 "..........\n"  <<
					 "..........\n"  <<
					 "..........\n"  <<
					 "..........\n"  <<
					 "..........\n"  <<
					 "..........\n"  <<
					 "..........\n"  <<
					 "..........\n"  <<
					 ".........*\n";
	
	correct_out << "\n";
	life1.printGrid(test_out);
	ASSERT_TRUE(test_out.str() == correct_out.str());
}

TEST(Life, Life_initCell_Cell1) 
{
	Life<Cell> life1(10,10);
	std::ostringstream correct_out;
	std::ostringstream test_out;

	life1.initCell(0,0,'.');
	life1.initCell(5,2,'3');
	life1.initCell(0,5,'0');
	life1.initCell(9,9,'*');
	
	correct_out  << "Generation = 0, Population = 3.\n";
	correct_out  <<  ".----0----\n"  <<
					 "----------\n"  << 
					 "----------\n"  << 
					 "----------\n"  << 
					 "----------\n"  << 
					 "--3-------\n"  << 
					 "----------\n"  << 
					 "----------\n"  << 
					 "----------\n"  << 
					 "---------*\n";
	
	correct_out << "\n";
	life1.printGrid(test_out);
	ASSERT_TRUE(test_out.str() == correct_out.str());
}

TEST(Life, Life_initCell_invalidCell) 
{
	Life<Cell> life1(10,10);
	std::ostringstream correct_out;
	std::ostringstream test_out;

	life1.initCell(0,0,'k');
	life1.initCell(5,2,'+');
	life1.initCell(9,9,'*');
	
	correct_out  << "Generation = 0, Population = 2.\n";
	correct_out  <<  "----------\n"  <<
					 "----------\n"  << 
					 "----------\n"  << 
					 "----------\n"  << 
					 "----------\n"  << 
					 "--+-------\n"  << 
					 "----------\n"  << 
					 "----------\n"  << 
					 "----------\n"  << 
					 "---------*\n";
	
	correct_out << "\n";
	life1.printGrid(test_out);
	ASSERT_TRUE(test_out.str() == correct_out.str());
}

// ------------------------
// Life::nextGen
// ------------------------
TEST(Life, Life_nextGen_Conway1) 
{
	Life<ConwayCell> life1(10,10);
	std::ostringstream correct_out;
	std::ostringstream test_out;

	life1.initCell(0,0,'*');
	life1.initCell(0,1,'*');
	life1.initCell(1,0,'*');
	life1.nextGen();
	
	correct_out  << "Generation = 1, Population = 4.\n";
	correct_out  <<  "**........\n"  <<
					 "**........\n"  <<
					 "..........\n"  <<
					 "..........\n"  <<
					 "..........\n"  <<
					 "..........\n"  <<
					 "..........\n"  <<
					 "..........\n"  <<
					 "..........\n"  <<
					 "..........\n";
	
	correct_out << "\n";
	life1.printGrid(test_out);
	ASSERT_TRUE(test_out.str() == correct_out.str());
}

TEST(Life, Life_nextGen_Conway2) 
{
	Life<ConwayCell> life1(2,3);
	std::ostringstream correct_out;
	std::ostringstream test_out;

	life1.initCell(0,0,'*');
	life1.initCell(0,1,'*');
	life1.initCell(1,0,'*');
	life1.initCell(1,1,'*');
	life1.initCell(0,2,'*');
	life1.initCell(1,2,'*');
	life1.nextGen();
	
	correct_out  << "Generation = 1, Population = 4.\n";
	correct_out  <<  "*.*\n"  <<
					 "*.*\n";
	
	correct_out << "\n";
	life1.printGrid(test_out);
	ASSERT_TRUE(test_out.str() == correct_out.str());
}

TEST(Life, Life_nextGen_Fredkin1) 
{
	Life<FredkinCell> life1(1,1);
	std::ostringstream correct_out;
	std::ostringstream test_out;

	life1.initCell(0,0,'5');
	life1.nextGen();
	
	correct_out  << "Generation = 1, Population = 0.\n";
	correct_out  <<  "-\n"  ;
	
	correct_out << "\n";
	life1.printGrid(test_out);
	ASSERT_TRUE(test_out.str() == correct_out.str());
}
// ------------------------------------------------
// End of Life Class Unit Tests
// ------------------------------------------------