/*
 * David Woo
 * daw2399
*/

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>
#include <stdexcept>

#include "gtest/gtest.h"

#include "Cell.h"
#include "Life.h"

// --------
// TestLife
// --------

// ----------------------------
// =====ConwayCell tests=====
// ----------------------------

// ------------------------
// ConwayCell::ConwayCell()
// ------------------------

TEST(Life, ConwayCell_default_construction){
	ConwayCell cc = ConwayCell();

	ASSERT_FALSE(cc._is_alive);
}

TEST(Life, ConwayCell_initial_construction1){
	ConwayCell cc = ConwayCell(false);

	ASSERT_FALSE(cc._is_alive);
}

TEST(Life, ConwayCell_initial_construction2){
	ConwayCell cc = ConwayCell(true);

	ASSERT_TRUE(cc._is_alive);
}

TEST(Life, ConwayCell_copy_consructor_dead){
	ConwayCell cc1 = ConwayCell(false);

	ASSERT_FALSE(cc1._is_alive);

	ConwayCell cc2 = ConwayCell(cc1);

	ASSERT_FALSE(cc2._is_alive);
}

TEST(Life, ConwayCell_copy_consructor_live){
	ConwayCell cc1 = ConwayCell(true);

	ASSERT_TRUE(cc1._is_alive);

	ConwayCell cc2 = ConwayCell(cc1);

	ASSERT_TRUE(cc2._is_alive);
}

TEST(Life,ConwayCell_copy_assignment_dead){
	ConwayCell cc1 = ConwayCell(false);
	ConwayCell cc2 = ConwayCell(true);
	ASSERT_FALSE(cc1._is_alive);
	ASSERT_TRUE(cc2._is_alive);

	cc2 = cc1;
	ASSERT_FALSE(cc1._is_alive);
	ASSERT_FALSE(cc2._is_alive);
}

TEST(Life,ConwayCell_copy_assignment_live){
	ConwayCell cc1 = ConwayCell(false);
	ConwayCell cc2 = ConwayCell(true);
	ASSERT_FALSE(cc1._is_alive);
	ASSERT_TRUE(cc2._is_alive);

	cc1 = cc2;
	ASSERT_TRUE(cc1._is_alive);
	ASSERT_TRUE(cc2._is_alive);
}

// -----------------
// ConwayCell::str()
// -----------------

TEST(Life, ConwayCell_str_dead){
	ConwayCell cc = ConwayCell(false);
	std::string cell = cc.str();

	ASSERT_FALSE(cc._is_alive);
	ASSERT_EQ(".", cell);
}

TEST(Life, ConwayCell_str_live){
	ConwayCell cc = ConwayCell(true);
	std::string cell = cc.str();

	ASSERT_TRUE(cc._is_alive);
	ASSERT_EQ("*", cell);
}

TEST(Life, ConwayCell_str_dead_polymorph){
	ConwayCell cc = ConwayCell(false);
	AbstractCell* ac = &cc;
	std::string cell = ac->str();

	ASSERT_FALSE(cc._is_alive);
	ASSERT_FALSE(ac->_is_alive);
	ASSERT_EQ(".", cell);
}

TEST(Life, ConwayCell_str_live_polymorph){
	ConwayCell cc = ConwayCell(true);
	AbstractCell* ac = &cc;
	std::string cell = ac->str();

	ASSERT_TRUE(cc._is_alive);
	ASSERT_TRUE(ac->_is_alive);
	ASSERT_EQ("*", cell);
}

// ------------------
// ConwayCell::kill()
// ------------------

TEST(Life, ConwayCell_kill_live){
	ConwayCell cc = ConwayCell(true);

	ASSERT_TRUE(cc._is_alive);

	cc.kill();
	ASSERT_FALSE(cc._is_alive);
}

TEST(Life, ConwayCell_kill_dead){
	ConwayCell cc = ConwayCell(false);

	ASSERT_FALSE(cc._is_alive);

	cc.kill();
	ASSERT_FALSE(cc._is_alive);
}

TEST(Life, ConwayCell_kill_live_polymorph1){
	ConwayCell cc = ConwayCell(true);
	AbstractCell* ac = &cc;

	ASSERT_TRUE(cc._is_alive);
	ASSERT_TRUE(ac->_is_alive);

	ac->kill();
	ASSERT_FALSE(cc._is_alive);
	ASSERT_FALSE(ac->_is_alive);
}

TEST(Life, ConwayCell_kill_live_polymorph2){
	ConwayCell cc = ConwayCell(true);
	AbstractCell* ac = &cc;

	ASSERT_TRUE(cc._is_alive);
	ASSERT_TRUE(ac->_is_alive);

	ac->kill();
	ASSERT_FALSE(cc._is_alive);
	ASSERT_FALSE(ac->_is_alive);
}

TEST(Life, ConwayCell_kill_dead_polymorph1){
	ConwayCell cc = ConwayCell(false);
	AbstractCell* ac = &cc;

	ASSERT_FALSE(cc._is_alive);
	ASSERT_FALSE(ac->_is_alive);

	ac->kill();
	ASSERT_FALSE(cc._is_alive);
	ASSERT_FALSE(ac->_is_alive);
}

TEST(Life, ConwayCell_kill_dead_polymorph2){
	ConwayCell cc = ConwayCell(false);
	AbstractCell* ac = &cc;

	ASSERT_FALSE(cc._is_alive);
	ASSERT_FALSE(ac->_is_alive);

	ac->kill();
	ASSERT_FALSE(cc._is_alive);
	ASSERT_FALSE(ac->_is_alive);
}

// --------------------
// ConwayCell::revive()
// --------------------

TEST(Life, ConwayCell_revive_dead){
	ConwayCell cc = ConwayCell(false);

	ASSERT_FALSE(cc._is_alive);

	cc.revive();
	ASSERT_TRUE(cc._is_alive);
}

TEST(Life, ConwayCell_revive_live){
	ConwayCell cc = ConwayCell(true);

	ASSERT_TRUE(cc._is_alive);

	cc.revive();
	ASSERT_TRUE(cc._is_alive);
}

TEST(Life, ConwayCell_revive_dead_polymorph1){
	ConwayCell cc = ConwayCell(false);
	AbstractCell* ac = &cc;

	ASSERT_FALSE(cc._is_alive);
	ASSERT_FALSE(ac->_is_alive);

	ac->revive();
	ASSERT_TRUE(cc._is_alive);
	ASSERT_TRUE(ac->_is_alive);
}

TEST(Life, ConwayCell_revive_dead_polymorph2){
	ConwayCell cc = ConwayCell(false);
	AbstractCell* ac = &cc;

	ASSERT_FALSE(cc._is_alive);
	ASSERT_FALSE(ac->_is_alive);

	ac->revive();
	ASSERT_TRUE(cc._is_alive);
	ASSERT_TRUE(ac->_is_alive);
}


TEST(Life, ConwayCell_revive_live_polymorph1){
	ConwayCell cc = ConwayCell(true);
	AbstractCell* ac = &cc;

	ASSERT_TRUE(cc._is_alive);
	ASSERT_TRUE(ac->_is_alive);

	ac->revive();
	ASSERT_TRUE(cc._is_alive);
	ASSERT_TRUE(ac->_is_alive);
}

TEST(Life, ConwayCell_revive_live_polymorph2){
	ConwayCell cc = ConwayCell(true);
	AbstractCell* ac = &cc;

	ASSERT_TRUE(cc._is_alive);
	ASSERT_TRUE(ac->_is_alive);

	ac->revive();
	ASSERT_TRUE(cc._is_alive);
	ASSERT_TRUE(ac->_is_alive);
}

// -------------------
// ConwayCell::clone()
// -------------------

TEST(Life, ConwayCell_clone_live){
	ConwayCell cc1 = ConwayCell(true);

	ASSERT_TRUE(cc1._is_alive);

	ConwayCell cc2 = *(cc1.clone());

	ASSERT_TRUE(cc2._is_alive);
}

TEST(Life, ConwayCell_clone_dead){
	ConwayCell cc1 = ConwayCell(false);

	ASSERT_FALSE(cc1._is_alive);

	ConwayCell cc2 = *(cc1.clone());

	ASSERT_FALSE(cc2._is_alive);
}

TEST(Life, ConwayCell_clone_live_polymorph){
	ConwayCell cc1 = ConwayCell(true);
	AbstractCell* ac1 = &cc1;

	ASSERT_TRUE(cc1._is_alive);
	ASSERT_TRUE(ac1->_is_alive);

	AbstractCell* ac2 = ac1->clone();

	ASSERT_TRUE(ac2->_is_alive);
}

TEST(Life, ConwayCell_clone_dead_polymorph){
	ConwayCell cc1 = ConwayCell(false);
	AbstractCell* ac1 = &cc1;

	ASSERT_FALSE(cc1._is_alive);
	ASSERT_FALSE(ac1->_is_alive);

	AbstractCell* ac2 = ac1->clone();

	ASSERT_FALSE(ac2->_is_alive);
}

// -----------------------
// ConwayCell::nextState()
// -----------------------

TEST(Life, ConwayCell_nextState1){
	ConwayCell cc = ConwayCell(true);

	std::vector<bool> neighbs = std::vector<bool>();
	neighbs.push_back(false);
	neighbs.push_back(false);
	neighbs.push_back(false);
	neighbs.push_back(false);
	neighbs.push_back(true); // itself
	neighbs.push_back(false);
	neighbs.push_back(false);
	neighbs.push_back(false);
	neighbs.push_back(false);
	// 0 live neighbors
	bool next = cc.nextState(neighbs);

	ASSERT_FALSE(next);
}

TEST(Life, ConwayCell_nextState2){
	ConwayCell cc = ConwayCell(false);

	std::vector<bool> neighbs = std::vector<bool>();
	neighbs.push_back(true);	// live neighbor
	neighbs.push_back(false);
	neighbs.push_back(false);
	neighbs.push_back(false);
	neighbs.push_back(false);	// itself
	neighbs.push_back(false);
	neighbs.push_back(true);	// live neighbor
	neighbs.push_back(false);
	neighbs.push_back(true);	// live neighbor
	bool next = cc.nextState(neighbs);
	// 3 live neighbors

	ASSERT_TRUE(next);
}

TEST(Life, ConwayCell_nextState3){
	ConwayCell cc = ConwayCell(true);

	std::vector<bool> neighbs = std::vector<bool>();
	neighbs.push_back(false);
	neighbs.push_back(false);
	neighbs.push_back(false);
	neighbs.push_back(true);	// live neighbor
	neighbs.push_back(true);	// itself
	neighbs.push_back(true);	// live neighbor
	neighbs.push_back(false);
	neighbs.push_back(false);
	neighbs.push_back(false);
	// 2 live neighbors
	bool next = cc.nextState(neighbs);

	ASSERT_TRUE(next);
}

TEST(Life, ConwayCell_nextState4){
	ConwayCell cc = ConwayCell(false);

	std::vector<bool> neighbs = std::vector<bool>();
	neighbs.push_back(false);
	neighbs.push_back(true);	// live neighbor
	neighbs.push_back(false);
	neighbs.push_back(true);	// live neighbor
	neighbs.push_back(false);	// itself
	neighbs.push_back(true);	// live neighbor
	neighbs.push_back(false);
	neighbs.push_back(false);
	neighbs.push_back(true);	// live neighbor
	// 4 live neighbors
	bool next = cc.nextState(neighbs);

	ASSERT_FALSE(next);
}



// ----------------------------
// =====FredkinCell tests=====
// ----------------------------

// ------------------------
// FredkinCell::FredkinCell()
// ------------------------

TEST(Life, FredkinCell_default_construction){
	FredkinCell fc = FredkinCell();

	ASSERT_FALSE(fc._is_alive);
	ASSERT_EQ(0, fc._age);
}

TEST(Life, FredkinCell_initial_construction1){
	FredkinCell fc = FredkinCell(false);

	ASSERT_FALSE(fc._is_alive);
	ASSERT_EQ(0, fc._age);
}

TEST(Life, FredkinCell_initial_construction2){
	FredkinCell fc = FredkinCell(true, 4);

	ASSERT_TRUE(fc._is_alive);
	ASSERT_EQ(4, fc._age);
}

TEST(Life, FredkinCell_copy_consructor_dead){
	FredkinCell fc1 = FredkinCell(false);

	ASSERT_FALSE(fc1._is_alive);

	FredkinCell fc2 = FredkinCell(fc1);

	ASSERT_FALSE(fc2._is_alive);
}

TEST(Life, FredkinCell_copy_consructor_live){
	FredkinCell fc1 = FredkinCell(true, 2);

	ASSERT_TRUE(fc1._is_alive);
	ASSERT_EQ(2, fc1._age);

	FredkinCell fc2 = FredkinCell(fc1);

	ASSERT_TRUE(fc2._is_alive);
	ASSERT_EQ(2, fc2._age);
}

TEST(Life, FredkinCell_copy_assignment_dead){
	FredkinCell fc1 = FredkinCell(false);
	FredkinCell fc2 = FredkinCell(true);
	ASSERT_FALSE(fc1._is_alive);
	ASSERT_TRUE(fc2._is_alive);

	fc2 = fc1;
	ASSERT_FALSE(fc1._is_alive);
	ASSERT_FALSE(fc2._is_alive);
}

TEST(Life, FredkinCell_copy_assignment_live){
	FredkinCell fc1 = FredkinCell(false);
	FredkinCell fc2 = FredkinCell(true, 9);
	ASSERT_FALSE(fc1._is_alive);
	ASSERT_TRUE(fc2._is_alive);
	ASSERT_EQ(0, fc1._age);
	ASSERT_EQ(9, fc2._age);

	fc1 = fc2;
	ASSERT_TRUE(fc1._is_alive);
	ASSERT_TRUE(fc2._is_alive);
	ASSERT_EQ(9, fc1._age);
	ASSERT_EQ(9, fc2._age);
}

// -----------------
// FredkinCell::str()
// -----------------

TEST(Life, FredkinCell_str_dead){
	FredkinCell fc = FredkinCell(false);
	std::string cell = fc.str();

	ASSERT_FALSE(fc._is_alive);
	ASSERT_EQ("-", cell);
}

TEST(Life, FredkinCell_str_live1){
	FredkinCell fc = FredkinCell(true);
	std::string cell = fc.str();

	ASSERT_TRUE(fc._is_alive);
	ASSERT_EQ(0, fc._age);
	ASSERT_EQ("0", cell);
}

TEST(Life, FredkinCell_str_live2){
	FredkinCell fc = FredkinCell(true, 3);
	std::string cell = fc.str();

	ASSERT_TRUE(fc._is_alive);
	ASSERT_EQ(3, fc._age);
	ASSERT_EQ("3", cell);
}

TEST(Life, FredkinCell_str_live3){
	FredkinCell fc = FredkinCell(true, 30);
	std::string cell = fc.str();

	ASSERT_TRUE(fc._is_alive);
	ASSERT_EQ(30, fc._age);
	ASSERT_EQ("+", cell);
}


TEST(Life, FredkinCell_str_dead_polymorph){
	FredkinCell fc = FredkinCell(false);
	AbstractCell* ac = &fc;
	std::string cell = ac->str();

	ASSERT_FALSE(fc._is_alive);
	ASSERT_FALSE(ac->_is_alive);
	ASSERT_EQ("-", cell);
}

TEST(Life, FredkinCell_str_live_polymorph1){
	FredkinCell fc = FredkinCell(true);
	AbstractCell* ac = &fc;
	std::string cell = ac->str();

	ASSERT_TRUE(fc._is_alive);
	ASSERT_TRUE(ac->_is_alive);
	ASSERT_EQ(0, fc._age);
	ASSERT_EQ("0", cell);
}

TEST(Life, FredkinCell_str_live_polymorph2){
	FredkinCell fc = FredkinCell(true, 6);
	AbstractCell* ac = &fc;
	std::string cell = ac->str();

	ASSERT_TRUE(fc._is_alive);
	ASSERT_TRUE(ac->_is_alive);
	ASSERT_EQ(6, fc._age);
	ASSERT_EQ("6", cell);
}

TEST(Life, FredkinCell_str_live_polymorph3){
	FredkinCell fc = FredkinCell(true, 10);
	AbstractCell* ac = &fc;
	std::string cell = ac->str();

	ASSERT_TRUE(fc._is_alive);
	ASSERT_TRUE(ac->_is_alive);
	ASSERT_EQ(10, fc._age);
	ASSERT_EQ("+", cell);
}

// ------------------
// FredkinCell::kill()
// ------------------

TEST(Life, FredkinCell_kill_live){
	FredkinCell fc = FredkinCell(true);

	ASSERT_TRUE(fc._is_alive);

	fc.kill();
	ASSERT_FALSE(fc._is_alive);
}

TEST(Life, FredkinCell_kill_dead){
	FredkinCell fc = FredkinCell(false);

	ASSERT_FALSE(fc._is_alive);

	fc.kill();
	ASSERT_FALSE(fc._is_alive);
}

TEST(Life, FredkinCell_kill_live_polymorph1){
	FredkinCell fc = FredkinCell(true);
	AbstractCell* ac = &fc;

	ASSERT_TRUE(fc._is_alive);
	ASSERT_TRUE(ac->_is_alive);

	ac->kill();
	ASSERT_FALSE(fc._is_alive);
	ASSERT_FALSE(ac->_is_alive);
}

TEST(Life, FredkinCell_kill_live_polymorph2){
	FredkinCell fc = FredkinCell(true);
	AbstractCell* ac = &fc;

	ASSERT_TRUE(fc._is_alive);
	ASSERT_TRUE(ac->_is_alive);

	ac->kill();
	ASSERT_FALSE(fc._is_alive);
	ASSERT_FALSE(ac->_is_alive);
}

TEST(Life, FredkinCell_kill_dead_polymorph1){
	FredkinCell fc = FredkinCell(false);
	AbstractCell* ac = &fc;

	ASSERT_FALSE(fc._is_alive);
	ASSERT_FALSE(ac->_is_alive);

	ac->kill();
	ASSERT_FALSE(fc._is_alive);
	ASSERT_FALSE(ac->_is_alive);
}

TEST(Life, FredkinCell_kill_dead_polymorph2){
	FredkinCell fc = FredkinCell(false);
	AbstractCell* ac = &fc;

	ASSERT_FALSE(fc._is_alive);
	ASSERT_FALSE(ac->_is_alive);

	ac->kill();
	ASSERT_FALSE(fc._is_alive);
	ASSERT_FALSE(ac->_is_alive);
}

// --------------------
// FredkinCell::revive()
// --------------------

TEST(Life, FredkinCell_revive_dead){
	FredkinCell fc = FredkinCell(false);

	ASSERT_FALSE(fc._is_alive);

	fc.revive();
	ASSERT_TRUE(fc._is_alive);
}

TEST(Life, FredkinCell_revive_live){
	FredkinCell fc = FredkinCell(true);

	ASSERT_TRUE(fc._is_alive);

	fc.revive();
	ASSERT_TRUE(fc._is_alive);
}

TEST(Life, FredkinCell_revive_dead_polymorph1){
	FredkinCell fc = FredkinCell(false);
	AbstractCell* ac = &fc;

	ASSERT_FALSE(fc._is_alive);
	ASSERT_FALSE(ac->_is_alive);

	ac->revive();
	ASSERT_TRUE(fc._is_alive);
	ASSERT_TRUE(ac->_is_alive);
}

TEST(Life, FredkinCell_revive_dead_polymorph2){
	FredkinCell fc = FredkinCell(false);
	AbstractCell* ac = &fc;

	ASSERT_FALSE(fc._is_alive);
	ASSERT_FALSE(ac->_is_alive);

	ac->revive();
	ASSERT_TRUE(fc._is_alive);
	ASSERT_TRUE(ac->_is_alive);
}

TEST(Life, FredkinCell_revive_live_polymorph1){
	FredkinCell fc = FredkinCell(true);
	AbstractCell* ac = &fc;

	ASSERT_TRUE(fc._is_alive);
	ASSERT_TRUE(ac->_is_alive);

	ac->revive();
	ASSERT_TRUE(fc._is_alive);
	ASSERT_TRUE(ac->_is_alive);
}

TEST(Life, FredkinCell_revive_live_polymorph2){
	FredkinCell fc = FredkinCell(true);
	AbstractCell* ac = &fc;

	ASSERT_TRUE(fc._is_alive);
	ASSERT_TRUE(ac->_is_alive);

	ac->revive();
	ASSERT_TRUE(fc._is_alive);
	ASSERT_TRUE(ac->_is_alive);
}

// -------------------
// FredkinCell::clone()
// -------------------

TEST(Life, FredkinCell_clone_live){
	FredkinCell fc1 = FredkinCell(true);

	ASSERT_TRUE(fc1._is_alive);

	FredkinCell fc2 = *(fc1.clone());

	ASSERT_TRUE(fc2._is_alive);
}

TEST(Life, FredkinCell_clone_dead){
	FredkinCell fc1 = FredkinCell(false, 17);

	ASSERT_FALSE(fc1._is_alive);
	ASSERT_EQ(17, fc1._age);

	FredkinCell fc2 = *(fc1.clone());

	ASSERT_FALSE(fc2._is_alive);
	ASSERT_EQ(17, fc2._age);
}

TEST(Life, FredkinCell_clone_live_polymorph){
	FredkinCell fc1 = FredkinCell(true);
	AbstractCell* ac1 = &fc1;

	ASSERT_TRUE(fc1._is_alive);
	ASSERT_TRUE(ac1->_is_alive);

	AbstractCell* ac2 = ac1->clone();

	ASSERT_TRUE(ac2->_is_alive);
}

TEST(Life, FredkinCell_clone_dead_polymorph){
	FredkinCell fc1 = FredkinCell(false, 5);
	AbstractCell* ac1 = &fc1;

	ASSERT_FALSE(fc1._is_alive);
	ASSERT_FALSE(ac1->_is_alive);
	ASSERT_EQ(5, fc1._age);

	AbstractCell* ac2 = ac1->clone();

	ASSERT_FALSE(ac2->_is_alive);
}

// ---------------------------
// FredkinCell::incrementAge()
// ---------------------------

TEST(Life, FredkinCell_age1){
	FredkinCell fc = FredkinCell(false);
	ASSERT_FALSE(fc._is_alive);
	ASSERT_EQ(0, fc._age);
	
	fc.incrementAge();
	
	ASSERT_FALSE(fc._is_alive);
	ASSERT_EQ(0, fc._age);
}

TEST(Life, FredkinCell_age2){
	FredkinCell fc = FredkinCell(true);
	ASSERT_TRUE(fc._is_alive);
	ASSERT_EQ(0, fc._age);
	
	fc.incrementAge();
	
	ASSERT_TRUE(fc._is_alive);
	ASSERT_EQ(1, fc._age);
}

TEST(Life, FredkinCell_age3){
	FredkinCell fc = FredkinCell(true, 9);
	ASSERT_TRUE(fc._is_alive);
	ASSERT_EQ(9, fc._age);
	
	fc.incrementAge();
	
	ASSERT_TRUE(fc._is_alive);
	ASSERT_EQ(10, fc._age);
}

// ------------------------
// FredkinCell::nextState()
// ------------------------

TEST(Life, FredkinCell_nextState1){
	FredkinCell fc = FredkinCell(true);

	std::vector<bool> neighbs = std::vector<bool>();
	neighbs.push_back(true);
	neighbs.push_back(false);
	neighbs.push_back(true);
	neighbs.push_back(false);
	neighbs.push_back(true); // itself
	neighbs.push_back(false);
	neighbs.push_back(true);
	neighbs.push_back(false);
	neighbs.push_back(true);
	// 0 live neighbors
	bool next = fc.nextState(neighbs);

	ASSERT_FALSE(next);
}

TEST(Life, FredkinCell_nextState2){
	FredkinCell fc = FredkinCell(true);

	std::vector<bool> neighbs = std::vector<bool>();
	neighbs.push_back(true);
	neighbs.push_back(true);	// live neighbor
	neighbs.push_back(true);
	neighbs.push_back(true);	// live neighbor
	neighbs.push_back(true);	// itself
	neighbs.push_back(false);
	neighbs.push_back(true);
	neighbs.push_back(true);	// live neighbor
	neighbs.push_back(true);
	// 3 live neighbors
	bool next = fc.nextState(neighbs);

	ASSERT_TRUE(next);
}

TEST(Life, FredkinCell_nextState3){
	FredkinCell fc = FredkinCell(false);

	std::vector<bool> neighbs = std::vector<bool>();
	neighbs.push_back(true);
	neighbs.push_back(true);	// live neighbor
	neighbs.push_back(true);
	neighbs.push_back(true);	// live neighbor
	neighbs.push_back(false);	// itself
	neighbs.push_back(false);
	neighbs.push_back(true);
	neighbs.push_back(true);	// live neighbor
	neighbs.push_back(true);
	// 3 live neighbors
	bool next = fc.nextState(neighbs);

	ASSERT_TRUE(next);
}

TEST(Life, FredkinCell_nextState4){
	FredkinCell fc = FredkinCell(false);

	std::vector<bool> neighbs = std::vector<bool>();
	neighbs.push_back(true);
	neighbs.push_back(true);	// live neighbor
	neighbs.push_back(true);
	neighbs.push_back(false);
	neighbs.push_back(false);	// itself
	neighbs.push_back(true);	// live neighbor
	neighbs.push_back(true);
	neighbs.push_back(false);
	neighbs.push_back(true);
	// 2 live neighbors
	bool next = fc.nextState(neighbs);

	ASSERT_FALSE(next);
}

// ----------------------------
// =====Cell tests=====
// ----------------------------

// ------------------------
// Cell::Cell()
// ------------------------

TEST(Life, Cell_default_construction_Fredkin){
	Cell c (new FredkinCell());

	ASSERT_FALSE(c.get()->_is_alive);
	ASSERT_EQ(0, ((FredkinCell*)c.get())->_age);
}

TEST(Life, Cell_default_construction_Conway){
	Cell c (new ConwayCell());

	ASSERT_FALSE(c.get()->_is_alive);
}

TEST(Life, Cell_bool_construction1){
	Cell c = Cell(false);

	ASSERT_FALSE(c.get()->_is_alive);
	ASSERT_EQ(0, ((FredkinCell*)c.get())->_age);
}

TEST(Life, Cell_bool_construction2){
	Cell c = Cell(true);

	ASSERT_TRUE(c.get()->_is_alive);
	ASSERT_EQ(0, ((FredkinCell*)c.get())->_age);
}

TEST(Life, Cell_bool_int_construction1){
	Cell c = Cell(true, 2);

	ASSERT_TRUE(c.get()->_is_alive);
	ASSERT_EQ(2, ((FredkinCell*)c.get())->_age);
}

TEST(Life, Cell_bool_int_construction2){
	Cell c = Cell(false, 5);

	ASSERT_FALSE(c.get()->_is_alive);
	ASSERT_EQ(5, ((FredkinCell*)c.get())->_age);
}

TEST(Life, Cell_initial_construction1){
	Cell c = Cell(new FredkinCell(false, 4));

	ASSERT_FALSE(c.get()->_is_alive);
	ASSERT_EQ(4, ((FredkinCell*)c.get())->_age);
}

TEST(Life, Cell_initial_construction2){
	Cell c = Cell(new ConwayCell(true));

	ASSERT_TRUE(c.get()->_is_alive);
}

TEST(Life, Cell_copy_consructor_dead){
	Cell c1 = Cell(new FredkinCell(false));

	ASSERT_FALSE(c1.get()->_is_alive);

	Cell c2 = Cell(c1);

	ASSERT_FALSE(c2.get()->_is_alive);
}

TEST(Life, Cell_copy_consructor_live){
	Cell c1 = (new ConwayCell(true));

	ASSERT_TRUE(c1.get()->_is_alive);

	Cell c2 = Cell(c1);

	ASSERT_TRUE(c2.get()->_is_alive);
}

TEST(Life, Cell_copy_assignment_dead){
	Cell c1 = Cell(new FredkinCell(false));
	Cell c2 = Cell(new FredkinCell(true));
	ASSERT_FALSE(c1.get()->_is_alive);
	ASSERT_TRUE(c2.get()->_is_alive);

	c2 = c1;
	ASSERT_FALSE(c1.get()->_is_alive);
	ASSERT_FALSE(c2.get()->_is_alive);
}

TEST(Life, Cell_copy_assignment_live){
	Cell c1 = Cell(new ConwayCell(false));
	Cell c2 = Cell(new FredkinCell(true, 9));
	ASSERT_FALSE(c1.get()->_is_alive);
	ASSERT_TRUE(c2.get()->_is_alive);
//	ASSERT_EQ(0, c1.get()->_age);
	ASSERT_EQ(9, ((FredkinCell*)c2.get())->_age);

	c1 = c2;
	ASSERT_TRUE(c1.get()->_is_alive);
	ASSERT_TRUE(c2.get()->_is_alive);
	ASSERT_EQ(9, ((FredkinCell*)c1.get())->_age);
	ASSERT_EQ(9, ((FredkinCell*)c2.get())->_age);
}

// -----------------
// Cell::str()
// -----------------

TEST(Life, Cell_FredkinCell_str_dead){
	Cell c = Cell(new FredkinCell(false));
	std::string cell = c.str();

	FredkinCell* fcp = (FredkinCell*) c.get();

	ASSERT_FALSE(fcp->_is_alive);
	ASSERT_EQ("-", cell);
}

TEST(Life, Cell_FredkinCell_str_live1){
	Cell c = Cell(new FredkinCell(true));
	std::string cell = c.str();

	FredkinCell* fcp = (FredkinCell*) c.get();

	ASSERT_TRUE(fcp->_is_alive);
	ASSERT_EQ(0, fcp->_age);
	ASSERT_EQ("0", cell);
}

TEST(Life, Cell_FredkinCell_str_live2){
	Cell c = Cell(new FredkinCell(true, 3));
	std::string cell = c.str();

	FredkinCell* fcp = (FredkinCell*) c.get();

	ASSERT_TRUE(fcp->_is_alive);
	ASSERT_EQ(3, fcp->_age);
	ASSERT_EQ("3", cell);
}

TEST(Life, Cell_FredkinCell_str_live3){
	Cell c = Cell(new FredkinCell(true, 30));
	std::string cell = c.str();

	FredkinCell* fcp = (FredkinCell*) c.get();

	ASSERT_TRUE(fcp->_is_alive);
	ASSERT_EQ(30, fcp->_age);
	ASSERT_EQ("+", cell);
}

TEST(Life, Cell_ConwayCell_str_dead){
	Cell c = Cell(new ConwayCell(false));
	std::string cell = c.str();

	ASSERT_FALSE(c.get()->_is_alive);
	ASSERT_EQ(".", cell);
}

TEST(Life, Cell_ConwayCell_str_live){
	Cell c = Cell(new ConwayCell(true));
	std::string cell = c.str();

	ASSERT_TRUE(c.get()->_is_alive);
	ASSERT_EQ("*", cell);
}

// ------------------
// Cell::kill()
// ------------------

TEST(Life, Cell_FredkinCell_kill_live){
	Cell c = Cell(new FredkinCell(true));

	ASSERT_TRUE(c.get()->_is_alive);

	c.kill();
	ASSERT_FALSE(c.get()->_is_alive);
}

TEST(Life, Cell_FredkinCell_kill_dead){
	Cell c = Cell(new FredkinCell(false));

	ASSERT_FALSE(c.get()->_is_alive);

	c.kill();
	ASSERT_FALSE(c.get()->_is_alive);
}

TEST(Life, Cell_ConwayCell_kill_live){
	Cell c = Cell(new ConwayCell(true));

	ASSERT_TRUE(c.get()->_is_alive);

	c.kill();
	ASSERT_FALSE(c.get()->_is_alive);
}

TEST(Life, Cell_ConwayCell_kill_dead){
	Cell c = Cell(new ConwayCell(false));

	ASSERT_FALSE(c.get()->_is_alive);

	c.kill();
	ASSERT_FALSE(c.get()->_is_alive);
}

// --------------------
// Cell::revive()
// --------------------

TEST(Life, Cell_revive_dead_Conway){
	Cell c = Cell(new ConwayCell(false));

	ASSERT_FALSE(c.get()->_is_alive);

	c.revive();
	ASSERT_TRUE(c.get()->_is_alive);
}

TEST(Life, Cell_revive_live_Conway){
	Cell c = Cell(new ConwayCell(true));

	ASSERT_TRUE(c.get()->_is_alive);

	c.revive();
	ASSERT_TRUE(c.get()->_is_alive);
}

TEST(Life, Cell_revive_dead_Fredkin){
	Cell c = Cell(new FredkinCell(false));

	ASSERT_FALSE(c.get()->_is_alive);

	c.revive();
	ASSERT_TRUE(c.get()->_is_alive);
}

TEST(Life, Cell_revive_live_Fredkin){
	Cell c = Cell(new FredkinCell(true));

	ASSERT_TRUE(c.get()->_is_alive);

	c.revive();
	ASSERT_TRUE(c.get()->_is_alive);
}

// -------------------
// Cell::clone()
// -------------------

TEST(Life, Cell_clone_live_Fredkin){
	Cell c1 = Cell(new FredkinCell(true));

	ASSERT_TRUE(c1.get()->_is_alive);

	Cell c2 = c1.clone();

	ASSERT_TRUE(c2.get()->_is_alive);
}

TEST(Life, Cell_clone_dead_Fredkin){
	Cell c1 = Cell(new FredkinCell(false, 17));

	ASSERT_FALSE(c1.get()->_is_alive);
	ASSERT_EQ(17, ((FredkinCell*)c1.get())->_age);

	Cell c2 = c1.clone();

	ASSERT_FALSE(c2.get()->_is_alive);
	ASSERT_EQ(17, ((FredkinCell*)c2.get())->_age);
}

// -----------------
// Cell::nextState()
// -----------------

TEST(Life, Cell_ConwayCell_nextState1){
	Cell c = Cell(new ConwayCell(true));

	std::vector<bool> neighbs = std::vector<bool>();
	neighbs.push_back(false);
	neighbs.push_back(false);
	neighbs.push_back(false);
	neighbs.push_back(false);
	neighbs.push_back(true); // itself
	neighbs.push_back(false);
	neighbs.push_back(false);
	neighbs.push_back(false);
	neighbs.push_back(false);
	// 0 live neighbors
	bool next = c.nextState(neighbs);

	ASSERT_FALSE(next);
}

TEST(Life, Cell_ConwayCell_nextState2){
	Cell c = Cell(new ConwayCell(false));

	std::vector<bool> neighbs = std::vector<bool>();
	neighbs.push_back(true);	// live neighbor
	neighbs.push_back(false);
	neighbs.push_back(false);
	neighbs.push_back(false);
	neighbs.push_back(false);	// itself
	neighbs.push_back(false);
	neighbs.push_back(true);	// live neighbor
	neighbs.push_back(false);
	neighbs.push_back(true);	// live neighbor
	bool next = c.nextState(neighbs);
	// 3 live neighbors

	ASSERT_TRUE(next);
}

TEST(Life, Cell_ConwayCell_nextState3){
	Cell c = Cell(new ConwayCell(true));

	std::vector<bool> neighbs = std::vector<bool>();
	neighbs.push_back(false);
	neighbs.push_back(false);
	neighbs.push_back(false);
	neighbs.push_back(true);	// live neighbor
	neighbs.push_back(true);	// itself
	neighbs.push_back(true);	// live neighbor
	neighbs.push_back(false);
	neighbs.push_back(false);
	neighbs.push_back(false);
	// 2 live neighbors
	bool next = c.nextState(neighbs);

	ASSERT_TRUE(next);
}

TEST(Life, Cell_ConwayCell_nextState4){
	Cell c = Cell(new ConwayCell(false));

	std::vector<bool> neighbs = std::vector<bool>();
	neighbs.push_back(false);
	neighbs.push_back(true);	// live neighbor
	neighbs.push_back(false);
	neighbs.push_back(true);	// live neighbor
	neighbs.push_back(false);	// itself
	neighbs.push_back(true);	// live neighbor
	neighbs.push_back(false);
	neighbs.push_back(false);
	neighbs.push_back(true);	// live neighbor
	// 4 live neighbors
	bool next = c.nextState(neighbs);

	ASSERT_FALSE(next);
}

TEST(Life, Cell_FredkinCell_nextState1){
	Cell c = Cell(new FredkinCell(true));

	std::vector<bool> neighbs = std::vector<bool>();
	neighbs.push_back(true);
	neighbs.push_back(false);
	neighbs.push_back(true);
	neighbs.push_back(false);
	neighbs.push_back(true); // itself
	neighbs.push_back(false);
	neighbs.push_back(true);
	neighbs.push_back(false);
	neighbs.push_back(true);
	// 0 live neighbors
	bool next = c.nextState(neighbs);

	ASSERT_FALSE(next);
}

TEST(Life, Cell_FredkinCell_nextState2){
	Cell c = Cell(new FredkinCell(true));

	std::vector<bool> neighbs = std::vector<bool>();
	neighbs.push_back(true);
	neighbs.push_back(true);	// live neighbor
	neighbs.push_back(true);
	neighbs.push_back(true);	// live neighbor
	neighbs.push_back(true);	// itself
	neighbs.push_back(false);
	neighbs.push_back(true);
	neighbs.push_back(true);	// live neighbor
	neighbs.push_back(true);
	// 3 live neighbors
	bool next = c.nextState(neighbs);

	ASSERT_TRUE(next);
}

TEST(Life, Cell_FredkinCell_nextState3){
	Cell c = Cell(new FredkinCell(false));

	std::vector<bool> neighbs = std::vector<bool>();
	neighbs.push_back(true);
	neighbs.push_back(true);	// live neighbor
	neighbs.push_back(true);
	neighbs.push_back(true);	// live neighbor
	neighbs.push_back(false);	// itself
	neighbs.push_back(false);
	neighbs.push_back(true);
	neighbs.push_back(true);	// live neighbor
	neighbs.push_back(true);
	// 3 live neighbors
	bool next = c.nextState(neighbs);

	ASSERT_TRUE(next);
}

TEST(Life, Cell_FredkinCell_nextState4){
	Cell c = Cell(new FredkinCell(false));

	std::vector<bool> neighbs = std::vector<bool>();
	neighbs.push_back(true);
	neighbs.push_back(true);	// live neighbor
	neighbs.push_back(true);
	neighbs.push_back(false);
	neighbs.push_back(false);	// itself
	neighbs.push_back(true);	// live neighbor
	neighbs.push_back(true);
	neighbs.push_back(false);
	neighbs.push_back(true);
	// 2 live neighbors
	bool next = c.nextState(neighbs);

	ASSERT_FALSE(next);
}



// --------------------
// =====Life tests=====
// --------------------

TEST(Life, Life_){

}

