#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==
#include <stdexcept> // invalid_argument, out_of_range

#include "gtest/gtest.h"

#define private public
#define protected public

#include "Life.h"
#include "AbstractCell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"


using namespace std;

//////////////////
// 	CONWAY CELL //
//////////////////


TEST(ConwayCell, Constructor){
	ConwayCell cell;

	ASSERT_TRUE(cell.m_currentState == AbstractCell::dead);
	ASSERT_TRUE(cell.m_sprite == '.');
	ASSERT_TRUE(cell.m_type == "ConwayCell");
}

TEST(ConwayCell, isAlive_False){
	ConwayCell cell;

	ASSERT_FALSE(cell.isAlive());
}

TEST(ConwayCell, isAlive_True){
	ConwayCell cell;
	cell.spark('*');

	ASSERT_TRUE(cell.isAlive());
}

TEST(ConwayCell, sparkAlive){
	ConwayCell cell;
	cell.spark('*');

	ASSERT_TRUE(cell.m_currentState == AbstractCell::alive);
	ASSERT_TRUE(cell.m_nextState == AbstractCell::alive);
	ASSERT_TRUE(cell.m_sprite == '*');
	ASSERT_TRUE(cell.isAlive());
}

TEST(ConwayCell, sparkDead){
	ConwayCell cell;
	cell.spark('*');
	cell.spark('.');

	ASSERT_TRUE(cell.m_currentState == AbstractCell::dead);
	ASSERT_TRUE(cell.m_nextState == AbstractCell::dead);
	ASSERT_TRUE(cell.m_sprite == '.');
	ASSERT_FALSE(cell.isAlive());
}

TEST(ConwayCell, LIVE_reviewSurroundings_underpopulation_A){
	ConwayCell cell;
	cell.spark('*');

	cell.reviewSurroundings(0);

	ASSERT_TRUE(cell.m_currentState == AbstractCell::alive);
	ASSERT_TRUE(cell.m_nextState == AbstractCell::dead);
}

TEST(ConwayCell, LIVE_reviewSurroundings_underpopulation_B){
	ConwayCell cell;
	cell.spark('*');

	cell.reviewSurroundings(1);

	ASSERT_TRUE(cell.m_currentState == AbstractCell::alive);
	ASSERT_TRUE(cell.m_nextState == AbstractCell::dead);
}

TEST(ConwayCell, LIVE_reviewSurroundings_overpopulation_A){
	ConwayCell cell;
	cell.spark('*');

	cell.reviewSurroundings(4);

	ASSERT_TRUE(cell.m_currentState == AbstractCell::alive);
	ASSERT_TRUE(cell.m_nextState == AbstractCell::dead);
}

TEST(ConwayCell, LIVE_reviewSurroundings_overpopulation_B){
	ConwayCell cell;
	cell.spark('*');

	cell.reviewSurroundings(5);

	ASSERT_TRUE(cell.m_currentState == AbstractCell::alive);
	ASSERT_TRUE(cell.m_nextState == AbstractCell::dead);
}

TEST(ConwayCell, LIVE_reviewSurroundings_overpopulation_C){
	ConwayCell cell;
	cell.spark('*');

	cell.reviewSurroundings(6);

	ASSERT_TRUE(cell.m_currentState == AbstractCell::alive);
	ASSERT_TRUE(cell.m_nextState == AbstractCell::dead);
}

TEST(ConwayCell, LIVE_reviewSurroundings_overpopulation_D){
	ConwayCell cell;
	cell.spark('*');

	cell.reviewSurroundings(7);

	ASSERT_TRUE(cell.m_currentState == AbstractCell::alive);
	ASSERT_TRUE(cell.m_nextState == AbstractCell::dead);
}

TEST(ConwayCell, LIVE_reviewSurroundings_overpopulation_E){
	ConwayCell cell;
	cell.spark('*');

	cell.reviewSurroundings(8);

	ASSERT_TRUE(cell.m_currentState == AbstractCell::alive);
	ASSERT_TRUE(cell.m_nextState == AbstractCell::dead);
}

TEST(ConwayCell, LIVE_reviewSurroundings_stablepopulation_A){
	ConwayCell cell;
	cell.spark('*');

	cell.reviewSurroundings(2);

	ASSERT_TRUE(cell.m_currentState == AbstractCell::alive);
	ASSERT_TRUE(cell.m_nextState == AbstractCell::alive);
}

TEST(ConwayCell, LIVE_reviewSurroundings_stablepopulation_B){
	ConwayCell cell;
	cell.spark('*');

	cell.reviewSurroundings(3);

	ASSERT_TRUE(cell.m_currentState == AbstractCell::alive);
	ASSERT_TRUE(cell.m_nextState == AbstractCell::alive);
}

TEST(ConwayCell, DEAD_reviewSurroundings_underpopulation_A){
	ConwayCell cell;
	

	cell.reviewSurroundings(0);

	ASSERT_TRUE(cell.m_currentState == AbstractCell::dead);
	ASSERT_TRUE(cell.m_nextState == AbstractCell::dead);
}

TEST(ConwayCell, DEAD_reviewSurroundings_underpopulation_B){
	ConwayCell cell;
	

	cell.reviewSurroundings(1);

	ASSERT_TRUE(cell.m_currentState == AbstractCell::dead);
	ASSERT_TRUE(cell.m_nextState == AbstractCell::dead);
}

TEST(ConwayCell, DEAD_reviewSurroundings_overpopulation_A){
	ConwayCell cell;
	

	cell.reviewSurroundings(4);

	ASSERT_TRUE(cell.m_currentState == AbstractCell::dead);
	ASSERT_TRUE(cell.m_nextState == AbstractCell::dead);
}

TEST(ConwayCell, DEAD_reviewSurroundings_overpopulation_B){
	ConwayCell cell;
	

	cell.reviewSurroundings(5);

	ASSERT_TRUE(cell.m_currentState == AbstractCell::dead);
	ASSERT_TRUE(cell.m_nextState == AbstractCell::dead);
}

TEST(ConwayCell, DEAD_reviewSurroundings_overpopulation_C){
	ConwayCell cell;
	

	cell.reviewSurroundings(6);

	ASSERT_TRUE(cell.m_currentState == AbstractCell::dead);
	ASSERT_TRUE(cell.m_nextState == AbstractCell::dead);
}

TEST(ConwayCell, DEAD_reviewSurroundings_overpopulation_D){
	ConwayCell cell;
	

	cell.reviewSurroundings(7);

	ASSERT_TRUE(cell.m_currentState == AbstractCell::dead);
	ASSERT_TRUE(cell.m_nextState == AbstractCell::dead);
}

TEST(ConwayCell, DEAD_reviewSurroundings_overpopulation_E){
	ConwayCell cell;
	

	cell.reviewSurroundings(8);

	ASSERT_TRUE(cell.m_currentState == AbstractCell::dead);
	ASSERT_TRUE(cell.m_nextState == AbstractCell::dead);
}

TEST(ConwayCell, DEAD_reviewSurroundings_stablepopulation_A){
	ConwayCell cell;
	

	cell.reviewSurroundings(2);

	ASSERT_TRUE(cell.m_currentState == AbstractCell::dead);
	ASSERT_TRUE(cell.m_nextState == AbstractCell::dead);
}

TEST(ConwayCell, DEAD_reviewSurroundings_stablepopulation_B){
	ConwayCell cell;
	

	cell.reviewSurroundings(3);

	ASSERT_TRUE(cell.m_currentState == AbstractCell::dead);
	ASSERT_TRUE(cell.m_nextState == AbstractCell::alive);
}

TEST(ConwayCell, DEAD_print){
	ConwayCell cell;

	std::ostringstream w;
    w << cell;
    ASSERT_EQ(".", w.str());
}

TEST(ConwayCell, LIVE_print){
	ConwayCell cell;
	cell.spark('*');

	std::ostringstream w;
    w << cell;
    ASSERT_EQ("*", w.str());
}










//////////////////
// FREDKIN CELL
//////////////////

TEST(FredkinCell, Constructor){
	FredkinCell cell;

	ASSERT_TRUE(cell.m_currentState == AbstractCell::dead);
	ASSERT_TRUE(cell.m_sprite == '-');
	ASSERT_TRUE(cell.m_type == "FredkinCell");
}

TEST(FredkinCell, isAlive_False){
	FredkinCell cell;

	ASSERT_FALSE(cell.isAlive());
}

TEST(FredkinCell, isAlive_True){
	FredkinCell cell;
	cell.spark('0');

	ASSERT_TRUE(cell.isAlive());
}

TEST(FredkinCell, sparkAlive){
	FredkinCell cell;
	cell.spark('0');

	ASSERT_TRUE(cell.m_currentState == AbstractCell::alive);
	ASSERT_TRUE(cell.m_nextState == AbstractCell::alive);
	ASSERT_TRUE(cell.m_sprite == '0');
	ASSERT_TRUE(cell.isAlive());
}

TEST(FredkinCell, sparkDead){
	FredkinCell cell;
	cell.spark('0');
	cell.spark('-');

	ASSERT_TRUE(cell.m_currentState == AbstractCell::dead);
	ASSERT_TRUE(cell.m_nextState == AbstractCell::dead);
	ASSERT_TRUE(cell.m_sprite == '-');
	ASSERT_FALSE(cell.isAlive());
}


TEST(FredkinCell, LIVE_reviewSurroundings_underpopulation_B){
	FredkinCell cell;
	cell.spark('0');

	cell.reviewSurroundings(1);

	ASSERT_TRUE(cell.m_currentState == AbstractCell::alive);
	ASSERT_TRUE(cell.m_nextState == AbstractCell::alive);
}

TEST(FredkinCell, LIVE_reviewSurroundings_stablepopulation_B){
	FredkinCell cell;
	cell.spark('0');

	cell.reviewSurroundings(3);

	ASSERT_TRUE(cell.m_currentState == AbstractCell::alive);
	ASSERT_TRUE(cell.m_nextState == AbstractCell::alive);
}

TEST(FredkinCell, LIVE_reviewSurroundings_underpopulation_A){
	FredkinCell cell;
	cell.spark('0');

	cell.reviewSurroundings(0);

	ASSERT_TRUE(cell.m_currentState == AbstractCell::alive);
	ASSERT_TRUE(cell.m_nextState == AbstractCell::dead);
}

TEST(FredkinCell, LIVE_reviewSurroundings_stablepopulation_A){
	FredkinCell cell;
	cell.spark('0');

	cell.reviewSurroundings(2);

	ASSERT_TRUE(cell.m_currentState == AbstractCell::alive);
	ASSERT_TRUE(cell.m_nextState == AbstractCell::dead);
}

TEST(FredkinCell, LIVE_reviewSurroundings_overpopulation_A){
	FredkinCell cell;
	cell.spark('0');

	cell.reviewSurroundings(4);

	ASSERT_TRUE(cell.m_currentState == AbstractCell::alive);
	ASSERT_TRUE(cell.m_nextState == AbstractCell::dead);
}

TEST(FredkinCell, DEAD_reviewSurroundings_underpopulation_B){
	FredkinCell cell;
	

	cell.reviewSurroundings(1);

	ASSERT_TRUE(cell.m_currentState == AbstractCell::dead);
	ASSERT_TRUE(cell.m_nextState == AbstractCell::alive);
}

TEST(FredkinCell, DEAD_reviewSurroundings_stablepopulation_B){
	FredkinCell cell;
	

	cell.reviewSurroundings(3);

	ASSERT_TRUE(cell.m_currentState == AbstractCell::dead);
	ASSERT_TRUE(cell.m_nextState == AbstractCell::alive);
}

TEST(FredkinCell, DEAD_reviewSurroundings_underpopulation_A){
	FredkinCell cell;
	

	cell.reviewSurroundings(0);

	ASSERT_TRUE(cell.m_currentState == AbstractCell::dead);
	ASSERT_TRUE(cell.m_nextState == AbstractCell::dead);
}

TEST(FredkinCell, DEAD_reviewSurroundings_stablepopulation_A){
	FredkinCell cell;
	

	cell.reviewSurroundings(2);

	ASSERT_TRUE(cell.m_currentState == AbstractCell::dead);
	ASSERT_TRUE(cell.m_nextState == AbstractCell::dead);
}

TEST(FredkinCell, DEAD_reviewSurroundings_overpopulation_A){
	FredkinCell cell;
	

	cell.reviewSurroundings(4);

	ASSERT_TRUE(cell.m_currentState == AbstractCell::dead);
	ASSERT_TRUE(cell.m_nextState == AbstractCell::dead);
}
TEST(FredkinCell, DEAD_print){
	FredkinCell cell;

	std::ostringstream w;
    w << cell;
    ASSERT_EQ("-", w.str());
}

TEST(FredkinCell, LIVE_print){
	FredkinCell cell;
	cell.spark('0');

	std::ostringstream w;
    w << cell;
    ASSERT_EQ("0", w.str());
}