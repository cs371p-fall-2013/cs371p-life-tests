// ------------------------------
// TestLife.c++
// Copyright (C) 2013
// Kurt E. Bixby & Chris W. Chung
// ------------------------------

///--------
///includes
///--------

#include <iostream>
#include <sstream>
#include <string>

#include "gtest/gtest.h"
#define private public
#define protected public
#define class struct
#include "Life.h"
#include "Handle.h"
#include "Cell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"

using std::endl;

/// --------
/// TestLife
/// --------

/// ------------
/// AbstractCell
/// ------------

/// --
/// ==
/// --

TEST(Life, Abstract_operator_equals_self) {
	ConwayCell c(true);
	ASSERT_TRUE(c == c);
}

TEST(Life, Abstract_operator_equals_other) {
	ConwayCell c(true);
	ConwayCell d(true);	
	ASSERT_TRUE(c == d);
}

TEST(Life, Abstract_operator_not_equals_other) {
	ConwayCell c(true);
	ConwayCell d(false);	
	ASSERT_TRUE(!(c == d));
}

/// --
/// <<
/// --

TEST(Life, Abstract_operator_out_alive) {
	std::ostringstream o;
	ConwayCell c(true);
	o << c;
	ASSERT_EQ(o.str(), "*");
}

TEST(Life, Abstract_operator_out_dead) {
	std::ostringstream o;
	ConwayCell c(false);
	o << c;
	ASSERT_EQ(o.str(), ".");
}

TEST(Life, Abstract_operator_out_both) {
	std::ostringstream o;
	ConwayCell c(false);
	ConwayCell d(true);
	o << c << d;
	ASSERT_EQ(o.str(), ".*");
}

/// -
/// =
/// -

TEST(Life, Abstract_assignment_other) {
	ConwayCell c;
	ConwayCell d(true);
	c = d;
	ASSERT_TRUE(c == d);
}

/// ------
/// equals
/// ------

TEST(Life, Abstract_equals_self) {
	ConwayCell c(true);
	ASSERT_TRUE(c.equals(c));
}

TEST(Life, Abstract_equals_other) {
	ConwayCell c(true);
	ConwayCell d(true);	
	ASSERT_TRUE(c.equals(d));
}

TEST(Life, Abstract_not_equals_other) {
	ConwayCell c(true);
	ConwayCell d(false);	
	ASSERT_TRUE(!c.equals(d));
}

/// -----------
/// constructor
/// -----------

TEST(Life, Abstract_construct_alive) {
	ConwayCell c(true);
	ASSERT_EQ(c._alive, true);
	ASSERT_EQ(c._next_alive, false);
}

TEST(Life, Abstract_construct_dead) {
	ConwayCell c(false);
	ASSERT_EQ(c._alive, false);
	ASSERT_EQ(c._next_alive, false);
}

TEST(Life, Abstract_construct_def) {
	ConwayCell c;
	ASSERT_EQ(c._alive, false);
	ASSERT_EQ(c._next_alive, false);
}

/// --------
/// is_alive
/// --------

TEST(Life, Abstract_is_alive_alive) {
	ConwayCell c(true);
	ASSERT_EQ(c.is_alive(), true);
}

TEST(Life, Abstract_is_dead_alive) {
	ConwayCell c(false);
	ASSERT_EQ(c.is_alive(), false);
}

/// -------
/// execute
/// -------

TEST(Life, Abstract_update_alive_to_dead) {
	ConwayCell c(true);
	c._next_alive = false;
	c.execute();
	ASSERT_EQ(c.is_alive(), false);
}

TEST(Life, Abstract_update_alive_to_alive) {
	ConwayCell c(true);
	c._next_alive = true;
	c.execute();
	ASSERT_EQ(c.is_alive(), true);
}

TEST(Life, Abstract_update_dead_to_dead) {
	ConwayCell c(false);
	c._next_alive = false;
	c.execute();
	ASSERT_EQ(c.is_alive(), false);
}

TEST(Life, Abstract_update_dead_to_alive) {
	ConwayCell c(false);
	c._next_alive = true;
	c.execute();
	ASSERT_EQ(c.is_alive(), true);
}



/// ----------
/// ConwayCell
/// ----------

/// -----
/// write
/// -----

TEST(Life, Conway_write_alive) {
	std::ostringstream o;
	ConwayCell c(true);
	c.write(o);
	ASSERT_EQ(o.str(), "*");
}

TEST(Life, Conway_write_dead) {
	std::ostringstream o;
	ConwayCell c(false);
	c.write(o);
	ASSERT_EQ(o.str(), ".");
}

/// -----------
/// will_be_old
/// -----------

TEST(Life, Conway_will_be_old_alive) {
	ASSERT_EQ(ConwayCell(true).will_be_old(2), false);
}

TEST(Life, Conway_will_be_old_dead) {
	ASSERT_EQ(ConwayCell(false).will_be_old(2), false);
}

/// ----
/// mark
/// ----

TEST(Life, Conway_age_dead_0_neighbors) {
	vector<vector<int> > v {{0,0,0},{0,0,0},{0,0,0}};
	ConwayCell c(false);
	c.mark(v);
	c.execute();
	ASSERT_EQ(c.is_alive(), false);
}

TEST(Life, Conway_age_alive_0_neighbors) {
	vector<vector<int> > v {{0,0,0},{0,0,0},{0,0,0}};
	ConwayCell c(true);
	c.mark(v);
	c.execute();
	ASSERT_EQ(c.is_alive(), false);
}

TEST(Life, Conway_age_dead_2_neighbors) {
	vector<vector<int> > v {{0,0,0},{1,0,0},{0,1,0}};
	ConwayCell c(false);
	c.mark(v);
	c.execute();
	ASSERT_EQ(c.is_alive(), false);
}

TEST(Life, Conway_age_alive_2_neighbors) {
	vector<vector<int> > v {{0,0,0},{1,0,0},{0,1,0}};
	ConwayCell c(true);
	c.mark(v);
	c.execute();
	ASSERT_EQ(c.is_alive(), true);
}

TEST(Life, Conway_age_dead_3_neighbors) {
	vector<vector<int> > v {{0,1,0},{1,0,0},{0,1,0}};
	ConwayCell c(false);
	c.mark(v);
	c.execute();
	ASSERT_EQ(c.is_alive(), true);
}

TEST(Life, Conway_age_alive_3_neighbors) {
	vector<vector<int> > v {{0,1,0},{1,0,0},{0,1,0}};
	ConwayCell c(true);
	c.mark(v);
	c.execute();
	ASSERT_EQ(c.is_alive(), true);
}

TEST(Life, Conway_age_dead_5_neighbors) {
	vector<vector<int> > v {{0,1,0},{1,0,1},{0,1,1}};
	ConwayCell c(false);
	c.mark(v);
	c.execute();
	ASSERT_EQ(c.is_alive(), false);
}

TEST(Life, Conway_age_alive_5_neighbors) {
	vector<vector<int> > v {{0,1,0},{1,0,1},{0,1,1}};
	ConwayCell c(true);
	c.mark(v);
	c.execute();
	ASSERT_EQ(c.is_alive(), false);
}

/// -----
/// clone
/// -----

TEST(Life, Conway_clone_alive) {
	ConwayCell c(true);
	ConwayCell* d = c.clone();
	ASSERT_TRUE(&c != d);
	ASSERT_TRUE(c.equals(*d));
	delete d;
}

TEST(Life, Conway_clone_dead) {
	ConwayCell c(false);
	ConwayCell* d = c.clone();
	ASSERT_TRUE(&c != d);
	ASSERT_TRUE(c.equals(*d));
	delete d;
}



/// -----------
/// FredkinCell
/// -----------

/// ------
/// equals
/// ------

TEST(Life, Fredkin_equals_self) {
	FredkinCell c(true);
	ASSERT_TRUE(c.equals(c));
}

TEST(Life, Fredkin_equals_other) {
	FredkinCell c(true);
	FredkinCell d(true);	
	ASSERT_TRUE(c.equals(d));
}

TEST(Life, Fredkin_not_equals_older) {
	FredkinCell c(true);
	FredkinCell d(true);
	d._next_age = 2;
	d._next_alive = true;
	d.execute();	
	ASSERT_TRUE(!c.equals(d));
}

TEST(Life, Fredkin_not_equals_other) {
	FredkinCell c(true);
	FredkinCell d(false);	
	ASSERT_TRUE(!c.equals(d));
}

/// -----------
/// constructor
/// -----------

TEST(Life, Fredkin_construct_alive) {
	FredkinCell c(true);
	ASSERT_EQ(c._alive, true);
	ASSERT_EQ(c._next_alive, false);
	ASSERT_EQ(c._age, 0);
	ASSERT_EQ(c._next_age, 0);
}

TEST(Life, Fredkin_construct_dead) {
	FredkinCell c(false);
	ASSERT_EQ(c._alive, false);
	ASSERT_EQ(c._next_alive, false);
	ASSERT_EQ(c._age, 0);
	ASSERT_EQ(c._next_age, 0);
}

/// -----
/// write
/// -----

TEST(Life, Fredkin_write_alive) {
	std::ostringstream o;
	FredkinCell c(true);
	c.write(o);
	ASSERT_EQ(o.str(), "0");
}

TEST(Life, Fredkin_write_older) {
	std::ostringstream o;
	FredkinCell c(true);
	c._age = 9;
	c.write(o);
	ASSERT_EQ(o.str(), "9");
}

TEST(Life, Fredkin_write_oldest) {
	std::ostringstream o;
	FredkinCell c(true);
	c._age = 10;
	c.write(o);
	ASSERT_EQ(o.str(), "+");
}

TEST(Life, Fredkin_write_dead) {
	std::ostringstream o;
	FredkinCell c(false);
	c.write(o);
	ASSERT_EQ(o.str(), "-");
}

/// -----------
/// will_be_old
/// -----------

TEST(Life, Fredkin_will_be_old_alive_old) {
	FredkinCell c(true);
	c._next_age = 2;
	ASSERT_EQ(c.will_be_old(2), true);
}

TEST(Life, Fredkin_will_be_old_alive_young) {
	FredkinCell c(true);
	c._next_age = 1;
	ASSERT_EQ(c.will_be_old(2), false);
}

TEST(Life, Fredkin_will_be_old_alive_really_old) {
	FredkinCell c(true);
	c._next_age = 4;
	ASSERT_EQ(c.will_be_old(2), true);
}

TEST(Life, Fredkin_will_be_old_dead) {
	FredkinCell c(false);
	ASSERT_EQ(c.will_be_old(2), false);
}

/// -------
/// execute
/// -------

TEST(Life, Fredkin_update_alive_to_dead) {
	FredkinCell c(true);
	c._age = 2;
	c._next_alive = false;
	c._next_age = 0;
	c.execute();
	ASSERT_EQ(c.is_alive(), false);
	ASSERT_EQ(c._age, 0);
}

TEST(Life, Fredkin_update_alive_to_alive) {
	FredkinCell c(true);
	c._age = 2;
	c._next_alive = true;
	c._next_age = 3;
	c.execute();
	ASSERT_EQ(c.is_alive(), true);
	ASSERT_EQ(c._age, 3);
}

TEST(Life, Fredkin_update_dead_to_dead) {
	FredkinCell c(false);
	c._age = 3;
	c._next_alive = false;
	c._next_age = 0;
	c.execute();
	ASSERT_EQ(c.is_alive(), false);
}

TEST(Life, Fredkin_update_dead_to_alive) {
	FredkinCell c(false);
	c._next_alive = true;
	c.execute();
	ASSERT_EQ(c.is_alive(), true);
	ASSERT_EQ(c._age, 0);
}

/// ----
/// mark
/// ----

TEST(Life, Fredkin_age_dead_0_neighbors) {
	vector<vector<int> > v {{0,0,0},{0,0,0},{0,0,0}};
	FredkinCell c(false);
	c._age = 2;
	c.mark(v);
	c.execute();
	ASSERT_EQ(c.is_alive(), false);
	ASSERT_EQ(c._age, 0);
}

TEST(Life, Fredkin_age_alive_0_neighbors) {
	vector<vector<int> > v {{0,0,0},{0,0,0},{0,0,0}};
	FredkinCell c(true);
	c._age = 2;
	c.mark(v);
	c.execute();
	ASSERT_EQ(c.is_alive(), false);
	ASSERT_EQ(c._age, 0);
}

TEST(Life, Fredkin_age_dead_2_total_neighbors) {
	vector<vector<int> > v {{0,0,0},{1,0,0},{0,0,1}};
	FredkinCell c(false);
	c.mark(v);
	c.execute();
	ASSERT_EQ(c.is_alive(), true);
	ASSERT_EQ(c._age, 0);
}

TEST(Life, Fredkin_age_alive_2_total_neighbors) {
	vector<vector<int> > v {{0,0,0},{1,0,0},{0,0,1}};
	FredkinCell c(true);
	c._age = 3;
	c.mark(v);
	c.execute();
	ASSERT_EQ(c.is_alive(), true);
	ASSERT_EQ(c._age, 4);
}

TEST(Life, Fredkin_age_dead_2_actual_neighbors) {
	vector<vector<int> > v {{0,1,0},{1,0,0},{0,0,0}};
	FredkinCell c(false);
	c.mark(v);
	c.execute();
	ASSERT_EQ(c.is_alive(), false);
	ASSERT_EQ(c._age, 0);
}

TEST(Life, Fredkin_age_alive_3_actual_neighbors) {
	vector<vector<int> > v {{0,1,0},{1,0,0},{0,1,0}};
	FredkinCell c(true);
	c._age = 3;
	c.mark(v);
	c.execute();
	ASSERT_EQ(c.is_alive(), true);
	ASSERT_EQ(c._age, 4);
}

TEST(Life, Fredkin_age_dead_3_actual_neighbors) {
	vector<vector<int> > v {{0,1,0},{1,0,1},{0,0,1}};
	FredkinCell c(false);
	c.mark(v);
	c.execute();
	ASSERT_EQ(c.is_alive(), true);
	ASSERT_EQ(c._age, 0);
}

/// -----
/// clone
/// -----

TEST(Life, Fredkin_clone_alive) {
	FredkinCell c(true);
	FredkinCell* d = c.clone();
	ASSERT_TRUE(&c != d);
	ASSERT_TRUE(c.equals(*d));
	delete d;
}

TEST(Life, Fredkin_clone_alive_aged) {
	FredkinCell c(true);
	c._next_age = 2;
	c._next_alive = true;
	c.execute();
	FredkinCell* d = c.clone();
	ASSERT_TRUE(&c != d);
	ASSERT_TRUE(c.equals(*d));
	delete d;
}

TEST(Life, Fredkin_clone_dead) {
	FredkinCell c(false);
	FredkinCell* d = c.clone();
	ASSERT_TRUE(&c != d);
	ASSERT_TRUE(c.equals(*d));
	delete d;
}



/// ----
/// Cell
/// ----

/// -----------
/// constructor
/// -----------

TEST(Life, Cell_conway_alive) {
	Cell c(new ConwayCell(true));
	ASSERT_TRUE(c._p->equals(ConwayCell(true)));
}

TEST(Life, Cell_conway_dead) {
	Cell c(new ConwayCell(false));
	ASSERT_TRUE(c._p->equals(ConwayCell(false)));
}

TEST(Life, Cell_fredkin_alive) {
	Cell c(new FredkinCell(true));
	ASSERT_TRUE(c._p->equals(FredkinCell(true)));
}

TEST(Life, Cell_fredkin_dead) {
	Cell c(new FredkinCell(false));
	ASSERT_TRUE(c._p->equals(FredkinCell(false)));
}

/// -----
/// write
/// -----

TEST(Life, Cell_operator_out_con_alive) {
	std::ostringstream o;
	Cell c(new ConwayCell(true));
	c.write(o);
	ASSERT_EQ(o.str(), "*");
}

TEST(Life, Cell_operator_out_con_dead) {
	std::ostringstream o;
	Cell c(new ConwayCell(false));
	c.write(o);
	ASSERT_EQ(o.str(), ".");
}

TEST(Life, Cell_operator_out_fred_alive) {
	std::ostringstream o;
	Cell c(new FredkinCell(true));
	c.write(o);
	ASSERT_EQ(o.str(), "0");
}

TEST(Life, Cell_operator_out_fred_dead) {
	std::ostringstream o;
	Cell c(new FredkinCell(false));
	c.write(o);
	ASSERT_EQ(o.str(), "-");
}

/// --
/// <<
/// --

TEST(Life, Cell_operator_out_alive) {
	std::ostringstream o;
	Cell c(new ConwayCell(true));
	o << c;
	ASSERT_EQ(o.str(), "*");
}

TEST(Life, Cell_operator_out_dead) {
	std::ostringstream o;
	Cell c(new ConwayCell(false));
	o << c;
	ASSERT_EQ(o.str(), ".");
}

TEST(Life, Cell_operator_out_both) {
	std::ostringstream o;
	Cell c (new ConwayCell(false));
	Cell d (new ConwayCell(true));
	o << c << d;
	ASSERT_EQ(o.str(), ".*");
}

/// --------
/// is_alive
/// --------

TEST(Life, Cell_is_alive_con_alive) {
	Cell c (new ConwayCell(true));
	ASSERT_TRUE(c.is_alive());
}

TEST(Life, Cell_is_alive_con_dead) {
	Cell c (new ConwayCell(false));
	ASSERT_TRUE(!c.is_alive());
}

TEST(Life, Cell_is_alive_fred_alive) {
	Cell c (new FredkinCell(true));
	ASSERT_TRUE(c.is_alive());
}

TEST(Life, Cell_is_alive_fred_dead) {
	Cell c (new FredkinCell(false));
	ASSERT_TRUE(!c.is_alive());
}

/// -------
/// execute
/// -------

TEST(Life, Cell_fredkin_update_alive_to_dead) {
	Cell c(new FredkinCell(true));
	c.get()->_next_alive = false;
	c.execute();
	ASSERT_EQ(c.is_alive(), false);
}

TEST(Life, Cell_fredkin_update_dead_to_alive) {
	Cell c(new FredkinCell(false));
	c.get()->_next_alive = true;
	c.execute();
	ASSERT_EQ(c.is_alive(), true);
}

TEST(Life, Cell_abstract_update_alive_to_dead) {
	Cell c(new ConwayCell(true));
	c.get()->_next_alive = false;
	c.execute();
	ASSERT_EQ(c.is_alive(), false);
}

TEST(Life, Cell_abstract_update_dead_to_alive) {
	Cell c(new ConwayCell(false));
	c.get()->_next_alive = true;
	c.execute();
	ASSERT_EQ(c.is_alive(), true);
}

/// ----
/// mark
/// ----

TEST(Life, Cell_fredkin_age_alive_0_neighbors) {
	vector<vector<int> > v {{0,0,0},{0,0,0},{0,0,0}};
	Cell c (new FredkinCell(true));
	c.mark(v);
	c.execute();
	ASSERT_EQ(c.is_alive(), false);
}

TEST(Life, Cell_fredkin_age_dead_3_actual_neighbors) {
	vector<vector<int> > v {{0,1,0},{1,0,1},{0,0,1}};
	Cell c (new FredkinCell(false));
	c.mark(v);
	c.execute();
	ASSERT_EQ(c.is_alive(), true);
}

TEST(Life, Cell_conway_age_alive_0_neighbors) {
	vector<vector<int> > v {{0,0,0},{0,0,0},{0,0,0}};
	Cell c(new ConwayCell (true));
	c.mark(v);
	c.execute();
	ASSERT_EQ(c.is_alive(), false);
}

TEST(Life, Cell_conway_age_dead_3_neighbors) {
	vector<vector<int> > v {{0,1,0},{1,0,0},{0,1,0}};
	Cell c(new ConwayCell (false));
	c.mark(v);
	c.execute();
	ASSERT_EQ(c.is_alive(), true);
}

/// ------
/// mutate
/// ------

TEST(Life, Cell_fredkin_0_to_conway) {
	std::ostringstream o;
	vector<vector<int> > v {{0,0,0},{1,0,0},{0,0,1}};
	Cell c(new FredkinCell(true));
	o << c;
	c.mark(v);
	c.execute();
	c.mark(v);
	c.execute();
	o << c;
	ASSERT_EQ(c.is_alive(), true);
	ASSERT_EQ(o.str(), "0*");
}

TEST(Life, Cell_fredkin_0_to_1) {
	std::ostringstream o;
	vector<vector<int> > v {{0,0,0},{1,0,0},{0,0,1}};
	Cell c(new FredkinCell(true));
	o << c;
	c.mark(v);
	c.execute();
	o << c;
	ASSERT_EQ(c.is_alive(), true);
	ASSERT_EQ(o.str(), "01");
}

TEST(Life, Cell_fredkin_0_to_conway_plus) {
	std::ostringstream o;
	vector<vector<int> > v {{0,0,0},{1,0,0},{0,0,1}};
	Cell c(new FredkinCell(true));
	o << c;
	c.mark(v);
	c.execute();
	c.mark(v);
	c.execute();
	o << c;
	c.mark(v);
	c.execute();
	o << c;
	ASSERT_EQ(c.is_alive(), true);
	ASSERT_EQ(o.str(), "0**");
}



/// ----
/// Life
/// ----

/// -----------
/// constructor
/// -----------

TEST(Life, Life_construct_con_22_dead) {
	std::ostringstream o;
	std::ostringstream p;
	Life<ConwayCell> life(2, 2, ConwayCell(false));
	life.print(o);
	p << "Generation = " << 0 << ", Population = " << 0 << "." << endl;
	p << ".." << endl << ".." << endl;
	ASSERT_EQ(o.str(), p.str());
}

TEST(Life, Life_construct_con_32_dead) {
	std::ostringstream o;
	std::ostringstream p;
	Life<ConwayCell> life(3, 2, ConwayCell(false));
	life.print(o);
	p << "Generation = " << 0 << ", Population = " << 0 << "." << endl;
	p << ".." << endl << ".." << endl << ".." << endl;
	ASSERT_EQ(o.str(), p.str());
}

TEST(Life, Life_construct_fred_32_dead) {
	std::ostringstream o;
	std::ostringstream p;
	Life<FredkinCell> life(3, 2, FredkinCell(false));
	life.print(o);
	p << "Generation = " << 0 << ", Population = " << 0 << "." << endl;
	p << "--" << endl << "--" << endl << "--" << endl;
	ASSERT_EQ(o.str(), p.str());
}

TEST(Life, Life_construct_cell_32_dead) {
	std::ostringstream o;
	std::ostringstream p;
	Life<Cell> life(3, 2, Cell(new FredkinCell(false)));
	life.print(o);
	p << "Generation = " << 0 << ", Population = " << 0 << "." << endl;
	p << "--" << endl << "--" << endl << "--" << endl;
	ASSERT_EQ(o.str(), p.str());
}


/// ----------
/// population
/// ----------

TEST(Life, Life_population_fred) {
	Life<FredkinCell> life(2, 2, FredkinCell(false));
	life.create_cell(0, 1);
	ASSERT_EQ(life.population(), 1);
}

TEST(Life, Life_population_con) {
	Life<ConwayCell> life(2, 2, ConwayCell(false));
	life.create_cell(0, 1);
	ASSERT_EQ(life.population(), 1);
}

TEST(Life, Life_population_fred_3) {
	Life<FredkinCell> life(2, 2, FredkinCell(false));
	life.create_cell(0, 1);
	life.create_cell(1, 1);
	life.create_cell(1, 0);
	ASSERT_EQ(life.population(), 3);
}

TEST(Life, Life_population_con_3) {
	Life<ConwayCell> life(2, 2, ConwayCell(false));
	life.create_cell(0, 1);
	life.create_cell(1, 1);
	life.create_cell(1, 0);
	ASSERT_EQ(life.population(), 3);
}

TEST(Life, Life_population_fred_0) {
	Life<FredkinCell> life(2, 2, FredkinCell(false));
	ASSERT_EQ(life.population(), 0);
}

TEST(Life, Life_population_con_0) {
	Life<ConwayCell> life(2, 2, ConwayCell(false));
	ASSERT_EQ(life.population(), 0);
}

/// -----------
/// create_cell
/// -----------

TEST(Life, Life_create_cell_con) {
	std::ostringstream o;
	std::ostringstream p;
	Life<ConwayCell> life(2, 2, ConwayCell(false));
	life.create_cell(0, 0);
	life.print(o);
	p << "Generation = " << 0 << ", Population = " << 1 << "." << endl;
	p << "*." << endl << ".." << endl;
	ASSERT_EQ(o.str(), p.str());
}

TEST(Life, Life_create_cell_fred) {
	std::ostringstream o;
	std::ostringstream p;
	Life<FredkinCell> life(2, 2, FredkinCell(false));
	life.create_cell(0, 1);
	life.print(o);
	p << "Generation = " << 0 << ", Population = " << 1 << "." << endl;
	p << "-0" << endl << "--" << endl;
	ASSERT_EQ(o.str(), p.str());
}

TEST(Life, Life_create_cell_cell) {
	std::ostringstream o;
	std::ostringstream p;
	Life<Cell> life(2, 2, Cell(new FredkinCell(false)));
	life.create_cell(0, 1, Cell(new FredkinCell(true)));
	life.print(o);
	p << "Generation = " << 0 << ", Population = " << 1 << "." << endl;
	p << "-0" << endl << "--" << endl;
	ASSERT_EQ(o.str(), p.str());
}

/// ---------------
/// check_neighbors
/// ---------------

TEST(Life, Life_check_neighbors_middle) {
	Life<ConwayCell> life(3, 3, ConwayCell(false));
	life.create_cell(0, 0);
	life.create_cell(0, 1);
	life.create_cell(0, 2);
	life.create_cell(1, 0);
	life.create_cell(1, 1);
	life.create_cell(1, 2);
	life.create_cell(2, 0);
	life.create_cell(2, 1);
	life.create_cell(2, 2);
	vector<vector<int> > v(life.check_neighbors(1, 1));
	vector<vector<int> > r {{1,1,1},{1,0,1},{1,1,1}};
	ASSERT_EQ(v, r);
}

TEST(Life, Life_check_neighbors_top_left) {
	Life<ConwayCell> life(3, 3, ConwayCell(false));
	life.create_cell(0, 0);
	life.create_cell(0, 1);
	life.create_cell(0, 2);
	life.create_cell(1, 0);
	life.create_cell(1, 1);
	life.create_cell(1, 2);
	life.create_cell(2, 0);
	life.create_cell(2, 1);
	life.create_cell(2, 2);
	vector<vector<int> > v(life.check_neighbors(0, 0));
	vector<vector<int> > r {{0,0,0},{0,0,1},{0,1,1}};
	ASSERT_EQ(v, r);
}

TEST(Life, Life_check_neighbors_bottom_right) {
	Life<ConwayCell> life(3, 3, ConwayCell(false));
	life.create_cell(0, 0);
	life.create_cell(0, 1);
	life.create_cell(0, 2);
	life.create_cell(1, 0);
	life.create_cell(1, 1);
	life.create_cell(1, 2);
	life.create_cell(2, 0);
	life.create_cell(2, 1);
	life.create_cell(2, 2);
	vector<vector<int> > v(life.check_neighbors(2, 2));
	vector<vector<int> > r {{1,1,0},{1,0,0},{0,0,0}};
	ASSERT_EQ(v, r);
}

TEST(Life, Life_check_neighbors_middle_right) {
	Life<ConwayCell> life(3, 3, ConwayCell(false));
	life.create_cell(0, 0);
	life.create_cell(0, 1);
	life.create_cell(0, 2);
	life.create_cell(1, 0);
	life.create_cell(1, 1);
	life.create_cell(1, 2);
	life.create_cell(2, 0);
	life.create_cell(2, 1);
	life.create_cell(2, 2);
	vector<vector<int> > v(life.check_neighbors(1, 2));
	vector<vector<int> > r {{1,1,0},{1,0,0},{1,1,0}};
	ASSERT_EQ(v, r);
}

TEST(Life, Life_check_neighbors_middle_left) {
	Life<ConwayCell> life(3, 3, ConwayCell(false));
	life.create_cell(0, 0);
	life.create_cell(0, 1);
	life.create_cell(0, 2);
	life.create_cell(1, 0);
	life.create_cell(1, 1);
	life.create_cell(1, 2);
	life.create_cell(2, 0);
	life.create_cell(2, 1);
	life.create_cell(2, 2);
	vector<vector<int> > v(life.check_neighbors(1, 0));
	vector<vector<int> > r {{0,1,1},{0,0,1},{0,1,1}};
	ASSERT_EQ(v, r);
}

/// --------
/// simulate
/// --------

TEST(Life, Life_simulate_con_one_to_none) {
	std::ostringstream o;
	std::ostringstream p;
	Life<ConwayCell> life(2, 2, ConwayCell(false));
	life.create_cell(0, 1);
	life.simulate();
	life.print(o);
	p << "Generation = " << 1 << ", Population = " << 0 << "." << endl;
	p << ".." << endl << ".." << endl;
	ASSERT_EQ(o.str(), p.str());
}

TEST(Life, Life_simulate_con_three_to_four) {
	std::ostringstream o;
	std::ostringstream p;
	Life<ConwayCell> life(2, 2, ConwayCell(false));
	life.create_cell(0, 1);
	life.create_cell(1, 1);
	life.create_cell(1, 0);
	life.simulate();
	life.print(o);
	p << "Generation = " << 1 << ", Population = " << 4 << "." << endl;
	p << "**" << endl << "**" << endl;
	ASSERT_EQ(o.str(), p.str());
}

TEST(Life, Life_simulate_fred_one_to_none) {
	std::ostringstream o;
	std::ostringstream p;
	Life<FredkinCell> life(2, 2, FredkinCell(false));
	life.create_cell(0, 1);
	life.simulate();
	life.print(o);
	p << "Generation = " << 1 << ", Population = " << 2 << "." << endl;
	p << "0-" << endl << "-0" << endl;
	ASSERT_EQ(o.str(), p.str());
}

TEST(Life, Life_simulate_fred_three_to_two) {
	std::ostringstream o;
	std::ostringstream p;
	Life<FredkinCell> life(2, 2, FredkinCell(false));
	life.create_cell(0, 1);
	life.create_cell(1, 1);
	life.create_cell(1, 0);
	life.simulate();
	life.print(o);
	p << "Generation = " << 1 << ", Population = " << 2 << "." << endl;
	p << "-1" << endl << "1-" << endl;
	ASSERT_EQ(o.str(), p.str());
}
