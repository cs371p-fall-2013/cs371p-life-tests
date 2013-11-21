#include <iostream>
#include <sstream>
#include <string>

#include "gtest/gtest.h"

// expose functionality to make testing easier teehee
#define private public
#define protected public
#define class struct

#include "Life.h"

using namespace std;

// ----------
// ConwayCell
// ----------

TEST(ConwayCellTest, Constructors) {
	ConwayCell def;
	EXPECT_FALSE(def._alive);

	ConwayCell live(true);
	EXPECT_TRUE(live._alive);

	ConwayCell dead(false);
	EXPECT_FALSE(dead._alive);
}

TEST(ConwayCellTest, Clone) {
	ConwayCell cell(true);
	ConwayCell* ptr = cell.clone();
	EXPECT_TRUE(ptr->_alive);

	delete ptr;
}

TEST(ConwayCellTest, Mutate) {
	ConwayCell cell;
	EXPECT_FALSE(cell.mutate(EvolveActionType::STAY_ALIVE));
}

TEST(ConwayCellTest, HowToEvolveDie) {
	ConwayCell cell(true);
	vector<bool> neighbors(8, false);

	// 1 live neighbor
	neighbors[0] = true;
	EvolveActionType action = cell.how_to_evolve(neighbors);
	EXPECT_EQ(EvolveActionType::DIE, action);

	// 4 live neighbors
	neighbors[1] = neighbors[2] = neighbors[3] = true;
	action = cell.how_to_evolve(neighbors);
	EXPECT_EQ(EvolveActionType::DIE, action);
}

TEST(ConwayCellTest, HowToEvolveRevive) {
	ConwayCell cell(false);
	vector<bool> neighbors(8, false);

	// 3 live neighbors
	neighbors[0] = neighbors[1] = neighbors[2] = true;
	EvolveActionType action = cell.how_to_evolve(neighbors);
	EXPECT_EQ(EvolveActionType::REVIVE, action);
}

TEST(ConwayCellTest, HowToEvolveStayAlive) {
	ConwayCell cell(true);
	vector<bool> neighbors(8, false);

	// 2 live neighbors
	neighbors[0] = neighbors[1] = true;
	EvolveActionType action = cell.how_to_evolve(neighbors);
	EXPECT_EQ(EvolveActionType::STAY_ALIVE, action);

	// 3 live neighbors
	neighbors[2] = true;
	action = cell.how_to_evolve(neighbors);
	EXPECT_EQ(EvolveActionType::STAY_ALIVE, action);
}

TEST(ConwayCellTest, HowToEvolveStayDead) {
	ConwayCell cell(false);
	vector<bool> neighbors(8, false);

	// 2 live
	neighbors[0] = neighbors[1] = true;
	EvolveActionType action = cell.how_to_evolve(neighbors);
	EXPECT_EQ(EvolveActionType::STAY_DEAD, action);
}

TEST(ConwayCellTest, EvolveDie) {
	ConwayCell cell(true);
	cell.evolve(EvolveActionType::DIE);
	EXPECT_FALSE(cell._alive);
}

TEST(ConwayCellTest, EvolveRevive) {
	ConwayCell cell(false);
	cell.evolve(EvolveActionType::REVIVE);
	EXPECT_TRUE(cell._alive);
}

TEST(ConwayCellTest, EvolveStayAlive) {
	ConwayCell cell(true);
	cell.evolve(EvolveActionType::STAY_ALIVE);
	EXPECT_TRUE(cell._alive);
}

TEST(ConwayCellTest, EvolveStayDead) {
	ConwayCell cell(false);
	cell.evolve(EvolveActionType::STAY_DEAD);
	EXPECT_FALSE(cell._alive);
}

TEST(ConwayCellTest, EqualsAnotherConway) {
	ConwayCell first, second;
	EXPECT_EQ(first, second);

	first._alive = !first._alive;
	EXPECT_NE(first, second);
}

TEST(ConwayCellTest, EqualsNotConway) {
	ConwayCell conway;
	FredkinCell fredkin;
	EXPECT_NE(conway, fredkin);
}

TEST(ConwayCellTest, Read) {
	istringstream in("*.");
	ConwayCell cell;

	in >> cell;
	EXPECT_TRUE(cell._alive);

	in >> cell;
	EXPECT_FALSE(cell._alive);
}

TEST(ConwayCellTest, Write) {
	ostringstream out;
	out << ConwayCell(true);
	EXPECT_STREQ("*", out.str().c_str());

	out << ConwayCell(false);
	EXPECT_STREQ("*.", out.str().c_str());
}

// -----------
// FredkinCell
// -----------

TEST(FredkinCellTest, Constructors) {
	FredkinCell def;
	EXPECT_FALSE(def._alive);
	EXPECT_EQ(0, def._age);

	FredkinCell just_int(1);
	EXPECT_TRUE(just_int._alive);
	EXPECT_EQ(1, just_int._age);

	FredkinCell bool_int(false, 2);
	EXPECT_FALSE(bool_int._alive);
	EXPECT_EQ(2, bool_int._age);
}

TEST(FredkinCellTest, Clone) {
	FredkinCell cell(true, 3);
	FredkinCell* ptr = cell.clone();
	EXPECT_TRUE(ptr->_alive);
	EXPECT_EQ(3, ptr->_age);

	delete ptr;
}

TEST(FredkinCellTest, Mutate) {
	FredkinCell cell;
	EXPECT_FALSE(cell.mutate(EvolveActionType::STAY_ALIVE));
}

TEST(FredkinCellTest, CanMutate) {
	FredkinCell cell(true, 0);
	EXPECT_FALSE(cell.can_mutate(EvolveActionType::STAY_ALIVE));

	cell._alive = false;
	cell._age = 1;
	EXPECT_FALSE(cell.can_mutate(EvolveActionType::STAY_ALIVE));

	cell._alive = true;
	EXPECT_FALSE(cell.can_mutate(EvolveActionType::DIE));
	EXPECT_TRUE(cell.can_mutate(EvolveActionType::STAY_ALIVE));
}

TEST(FredkinCellTest, HowToEvolveDie) {
	FredkinCell cell(true, 3);
	vector<bool> neighbors(8, false);

	// 2 live neighbors
	neighbors[1] = neighbors[3] = true;
	EvolveActionType action = cell.how_to_evolve(neighbors);
	EXPECT_EQ(EvolveActionType::DIE, action);
}

TEST(FredkinCellTest, HowToEvolveRevive) {
	FredkinCell cell(false, 3);
	vector<bool> neighbors(8, false);

	// 1 live neighbor
	neighbors[1] = true;
	EvolveActionType action = cell.how_to_evolve(neighbors);
	EXPECT_EQ(EvolveActionType::REVIVE, action);
}

TEST(FredkinCellTest, HowToEvolveStayAlive) {
	FredkinCell cell(true, 3);
	vector<bool> neighbors(8, false);

	// 1 live neighbor
	neighbors[1] = true;
	EvolveActionType action = cell.how_to_evolve(neighbors);
	EXPECT_EQ(EvolveActionType::STAY_ALIVE, action);
}

TEST(FredkinCellTest, HowToEvolveStayDead) {
	FredkinCell cell(false, 3);
	vector<bool> neighbors(8, false);

	// 2 live neighbors
	neighbors[1] = neighbors[3] = true;
	EvolveActionType action = cell.how_to_evolve(neighbors);
	EXPECT_EQ(EvolveActionType::STAY_DEAD, action);
}

TEST(FredkinCellTest, EvolveDie) {
	FredkinCell cell(true, 3);
	cell.evolve(EvolveActionType::DIE);
	EXPECT_FALSE(cell._alive);
	EXPECT_EQ(3, cell._age);
}

TEST(FredkinCellTest, EvolveRevive) {
	FredkinCell cell(false, 3);
	cell.evolve(EvolveActionType::REVIVE);
	EXPECT_TRUE(cell._alive);
	EXPECT_EQ(3, cell._age);
}

TEST(FredkinCellTest, EvolveStayAlive) {
	FredkinCell cell(true, 3);
	cell.evolve(EvolveActionType::STAY_ALIVE);
	EXPECT_TRUE(cell._alive);
	EXPECT_EQ(4, cell._age);
}

TEST(FredkinCellTest, EvolveStayDead) {
	FredkinCell cell(false, 3);
	cell.evolve(EvolveActionType::STAY_DEAD);
	EXPECT_FALSE(cell._alive);
	EXPECT_EQ(3, cell._age);
}

TEST(FredkinCellTest, EqualsAnotherFredkin) {
	FredkinCell first, second;
	EXPECT_EQ(first, second);

	++first._age;
	EXPECT_NE(first, second);
}

TEST(FredkinCellTest, EqualsNotFredkin) {
	FredkinCell fredkin;
	ConwayCell conway;
	EXPECT_NE(fredkin, conway);
}

TEST(FredkinCellTest, Read) {
	istringstream in("-4+");
	FredkinCell cell;

	in >> cell;
	EXPECT_FALSE(cell._alive);
	EXPECT_EQ(0, cell._age);

	in >> cell;
	EXPECT_TRUE(cell._alive);
	EXPECT_EQ(4, cell._age);

	in >> cell;
	EXPECT_TRUE(cell._alive);
	EXPECT_EQ(10, cell._age);
}

TEST(FredkinCellTest, Write) {
	ostringstream out;
	out << FredkinCell(true, 5);
	EXPECT_STREQ("5", out.str().c_str());

	out << FredkinCell(true, 12);
	EXPECT_STREQ("5+", out.str().c_str());

	out << FredkinCell(false, 3);
	EXPECT_STREQ("5+-", out.str().c_str());
}

// ----
// Cell
// ----

TEST(CellTest, Constructors) {
	Cell c1;
	EXPECT_EQ(nullptr, c1._p);

	Cell c2 = new ConwayCell();
	EXPECT_NE(nullptr, c2._p);
}

TEST(CellTest, Equals) {
	Cell cell1 = new ConwayCell(true);
	Cell cell2 = new ConwayCell(true);
	EXPECT_EQ(cell1, cell2);

	cell2._p->_alive = false;
	EXPECT_NE(cell1, cell2);
}

TEST(CellTest, Assignment) {
	Cell cell = new ConwayCell(true);
	cell = new ConwayCell(false);
	EXPECT_FALSE(cell._p->_alive);
}

TEST(CellTest, MutateFredkin) {
	// begin as FredkinCell
	Cell cell = new FredkinCell(true, 1);
	bool mutated = cell.mutate(EvolveActionType::STAY_ALIVE);
	// right action and state
	EXPECT_TRUE(mutated);

	// make sure it has changed into a live ConwayCell
	ConwayCell* conway_ptr = dynamic_cast<ConwayCell*>(cell._p);
	EXPECT_NE(nullptr, conway_ptr);
	EXPECT_TRUE(conway_ptr->_alive);
}

TEST(CellTest, MutateFredkinFail) {
	Cell cell = new FredkinCell(true, 0);
	bool mutated = cell.mutate(EvolveActionType::STAY_ALIVE);
	// right action but wrong state
	EXPECT_FALSE(mutated);

	// make sure it hasn't changed into a ConwayCell (cast should fail)
	EXPECT_FALSE(dynamic_cast<ConwayCell*>(cell._p));

	cell.evolve(EvolveActionType::STAY_ALIVE);
	mutated = cell.mutate(EvolveActionType::DIE);
	// right state but wrong action
	EXPECT_FALSE(mutated);

	EXPECT_FALSE(dynamic_cast<ConwayCell*>(cell._p));
}

TEST(CellTest, MutateNotFredkin) {
	Cell cell = new ConwayCell(true);
	bool mutated = cell.mutate(EvolveActionType::STAY_ALIVE);
	EXPECT_FALSE(mutated);

	// make sure it is still a ConwayCell (cast should succeed)
	EXPECT_TRUE(dynamic_cast<ConwayCell*>(cell._p));
}

TEST(CellTest, HowToEvolve) {
	Cell cell = new ConwayCell(true);
	// 0 live neighbors, will die
	vector<bool> neighbors(8, false);
	EvolveActionType action = cell.how_to_evolve(neighbors);
	EXPECT_EQ(EvolveActionType::DIE, action);
}

TEST(CellTest, Evolve) {
	Cell cell = new ConwayCell(true);
	cell.evolve(EvolveActionType::DIE);
	EXPECT_FALSE(cell._p->_alive);
}

TEST(CellTest, ReadInitialize) {
	istringstream in(".*-5+");

	// uninitialized cell
	Cell cell = nullptr;
	in >> cell;
	ConwayCell* conway_ptr = dynamic_cast<ConwayCell*>(cell._p);
	EXPECT_NE(nullptr, conway_ptr);
	EXPECT_FALSE(conway_ptr->_alive);

	// re-uninitialize
	cell = nullptr;
	in >> cell;
	conway_ptr = dynamic_cast<ConwayCell*>(cell._p);
	EXPECT_NE(nullptr, conway_ptr);
	EXPECT_TRUE(conway_ptr->_alive);

	cell = nullptr;
	in >> cell;
	FredkinCell* fredkin_ptr = dynamic_cast<FredkinCell*>(cell._p);
	EXPECT_NE(nullptr, fredkin_ptr);
	EXPECT_FALSE(fredkin_ptr->_alive);
	EXPECT_EQ(0, fredkin_ptr->_age);

	cell = nullptr;
	in >> cell;
	fredkin_ptr = dynamic_cast<FredkinCell*>(cell._p);
	EXPECT_NE(nullptr, fredkin_ptr);
	EXPECT_TRUE(fredkin_ptr->_alive);
	EXPECT_EQ(5, fredkin_ptr->_age);

	cell = nullptr;
	in >> cell;
	fredkin_ptr = dynamic_cast<FredkinCell*>(cell._p);
	EXPECT_NE(nullptr, fredkin_ptr);
	EXPECT_TRUE(fredkin_ptr->_alive);
	EXPECT_EQ(10, fredkin_ptr->_age);
}

TEST(CellTest, ReadModify) {
	istringstream in("*5");

	Cell cell = new ConwayCell();
	in >> cell;
	EXPECT_TRUE(cell._p->_alive);

	cell = new FredkinCell();
	in >> cell;
	EXPECT_TRUE(cell._p->_alive);
	EXPECT_EQ(5, ((FredkinCell*)cell._p)->_age);
}

TEST(CellTest, Write) {
	ostringstream out;

	out << Cell(new ConwayCell());
	EXPECT_STREQ(".", out.str().c_str());

	out << Cell(new FredkinCell());
	EXPECT_STREQ(".-", out.str().c_str());
}

// ----
// Life
// ----

TEST(LifeTest, ReadConway) {
	istringstream in(string() +
		".*\n" +
		"*.\n"
	);

	Life<ConwayCell> life(2, 2);
	in >> life;

	EXPECT_EQ(2, life._current_population);

	ConwayCell dead(false);
	ConwayCell live(true);
	EXPECT_EQ(dead, life._cell_grid[0][0]);
	EXPECT_EQ(live, life._cell_grid[0][1]);
	EXPECT_EQ(live, life._cell_grid[1][0]);
	EXPECT_EQ(dead, life._cell_grid[1][1]);
}

TEST(LifeTest, ReadFredkin) {
	istringstream in(string() +
		"0-\n" +
		"-0\n"
	);

	Life<FredkinCell> life(2, 2);
	in >> life;

	EXPECT_EQ(2, life._current_population);

	FredkinCell dead(false, 0);
	FredkinCell live(true, 0);
	EXPECT_EQ(live, life._cell_grid[0][0]);
	EXPECT_EQ(dead, life._cell_grid[0][1]);
	EXPECT_EQ(dead, life._cell_grid[1][0]);
	EXPECT_EQ(live, life._cell_grid[1][1]);
}

TEST(LifeTest, ReadBoth) {
	istringstream in(string() +
		".*-\n" +
		"05+\n"
	);

	Life<Cell> life(2, 3);
	in >> life;

	EXPECT_EQ(4, life._current_population);

	EXPECT_EQ(ConwayCell(false), *(life._cell_grid[0][0]._p));
	EXPECT_EQ(ConwayCell(true), *(life._cell_grid[0][1]._p));
	EXPECT_EQ(FredkinCell(false, 0), *(life._cell_grid[0][2]._p));
	EXPECT_EQ(FredkinCell(true, 0), *(life._cell_grid[1][0]._p));
	EXPECT_EQ(FredkinCell(true, 5), *(life._cell_grid[1][1]._p));
	EXPECT_EQ(FredkinCell(true, 10), *(life._cell_grid[1][2]._p));
}

TEST(LifeTest, WriteConway) {
	ostringstream out;
	Life<ConwayCell> life(2, 2);

	life._cell_grid[0][0] = ConwayCell(false);
	life._cell_grid[0][1] = ConwayCell(false);
	life._cell_grid[1][0] = ConwayCell(true);
	life._cell_grid[1][1] = ConwayCell(true);
	out << life;

	string expected("..\n**\n");
	EXPECT_STREQ(expected.c_str(), out.str().c_str());
}

TEST(LifeTest, WriteFredkin) {
	ostringstream out;
	Life<FredkinCell> life(2, 2);

	life._cell_grid[0][0] = FredkinCell(false, 1);
	life._cell_grid[0][1] = FredkinCell(false, 0);
	life._cell_grid[1][0] = FredkinCell(true, 3);
	life._cell_grid[1][1] = FredkinCell(true, 11);
	out << life;

	string expected("--\n3+\n");
	EXPECT_STREQ(expected.c_str(), out.str().c_str());
}

TEST(LifeTest, WriteBoth) {
	ostringstream out;
	Life<Cell> life(2, 3);

	life._cell_grid[0][0] = new ConwayCell(true);
	life._cell_grid[0][1] = new FredkinCell(true, 0);
	life._cell_grid[0][2] = new FredkinCell(true, 2);
	life._cell_grid[1][0] = new FredkinCell(false, 8);
	life._cell_grid[1][1] = new FredkinCell(true, 11);
	life._cell_grid[1][2] = new ConwayCell(false);
	out << life;

	string expected("*02\n-+.\n");
	EXPECT_STREQ(expected.c_str(), out.str().c_str());
}

TEST(LifeTest, HowToEvolveCornerCells) {
	istringstream in(string() +
		"*.**\n" +
		"...*\n" +
		"**.*\n" +
		".**.\n"
	);

	Life<ConwayCell> life(4, 4);
	in >> life;

	vector< vector<EvolveActionType> > action_grid(4, vector<EvolveActionType>(4));
	life.how_to_evolve_corner_cells(action_grid);

	EXPECT_EQ(EvolveActionType::DIE, action_grid[0][0]);
	EXPECT_EQ(EvolveActionType::STAY_ALIVE, action_grid[0][3]);
	EXPECT_EQ(EvolveActionType::REVIVE, action_grid[3][0]);
	EXPECT_EQ(EvolveActionType::STAY_DEAD, action_grid[3][3]);
}

TEST(LifeTest, HowToEvolveEdgeCells) {
	istringstream in(string() +
		"**.*\n" +
		".***\n" +
		"..*.\n" +
		"*.*.\n"
	);

	Life<ConwayCell> life(4, 4);
	in >> life;

	vector< vector<EvolveActionType> > action_grid(4, vector<EvolveActionType>(4));
	life.how_to_evolve_edge_cells(action_grid);

	EXPECT_EQ(EvolveActionType::STAY_ALIVE, action_grid[0][1]);
	EXPECT_EQ(EvolveActionType::STAY_DEAD, action_grid[0][2]);
	EXPECT_EQ(EvolveActionType::REVIVE, action_grid[1][0]);
	EXPECT_EQ(EvolveActionType::STAY_DEAD, action_grid[2][0]);
	EXPECT_EQ(EvolveActionType::STAY_ALIVE, action_grid[1][3]);
	EXPECT_EQ(EvolveActionType::STAY_DEAD, action_grid[2][3]);
	EXPECT_EQ(EvolveActionType::REVIVE, action_grid[3][1]);
	EXPECT_EQ(EvolveActionType::DIE, action_grid[3][2]);
}

TEST(LifeTest, HowToEvolveInteriorCells) {
	istringstream in(string() +
		"..*.\n" +
		".*..\n" +
		"*.*.\n" +
		".***\n"
	);

	Life<ConwayCell> life(4, 4);
	in >> life;

	vector< vector<EvolveActionType> > action_grid(4, vector<EvolveActionType>(4));
	life.how_to_evolve_interior_cells(action_grid);

	EXPECT_EQ(EvolveActionType::STAY_ALIVE, action_grid[1][1]);
	EXPECT_EQ(EvolveActionType::REVIVE, action_grid[1][2]);
	EXPECT_EQ(EvolveActionType::STAY_DEAD, action_grid[2][1]);
	EXPECT_EQ(EvolveActionType::DIE, action_grid[2][2]);
}

TEST(LifeTest, HowToEvolveAllCells) {
	istringstream in(string() +
		"..*\n" +
		"**.\n" +
		"*..\n"
	);

	Life<ConwayCell> life(3, 3);
	in >> life;

	vector< vector<EvolveActionType> > action_grid(3, vector<EvolveActionType>(3));
	life.how_to_evolve_all_cells(action_grid);

	EXPECT_EQ(EvolveActionType::STAY_DEAD, action_grid[0][0]);
	EXPECT_EQ(EvolveActionType::REVIVE, action_grid[0][1]);
	EXPECT_EQ(EvolveActionType::DIE, action_grid[0][2]);
	EXPECT_EQ(EvolveActionType::STAY_ALIVE, action_grid[1][0]);
	EXPECT_EQ(EvolveActionType::STAY_ALIVE, action_grid[1][1]);
	EXPECT_EQ(EvolveActionType::STAY_DEAD, action_grid[1][2]);
	EXPECT_EQ(EvolveActionType::STAY_ALIVE, action_grid[2][0]);
	EXPECT_EQ(EvolveActionType::REVIVE, action_grid[2][1]);
	EXPECT_EQ(EvolveActionType::STAY_DEAD, action_grid[2][2]);
}

TEST(LifeTest, EvolveAllCellsConway) {
	istringstream in(string() +
		"..*\n" +
		"**.\n" +
		"*..\n"
	);

	Life<ConwayCell> life(3, 3);
	in >> life;
	life.evolve_all_cells();

	ostringstream out;
	out << life;

	string expected(string() +
		".*.\n" +
		"**.\n" +
		"**.\n"
	);

	EXPECT_STREQ(expected.c_str(), out.str().c_str());
	EXPECT_EQ(5, life.current_population());
}

TEST(LifeTest, EvolveAllCellsFredkin) {
	istringstream in(string() +
		"---\n" +
		"9--\n" +
		"321\n"
	);

	Life<FredkinCell> life(3, 3);
	in >> life;
	life.evolve_all_cells();

	ostringstream out;
	out << life;

	string expected(string() +
		"0--\n" +
		"+-0\n" +
		"--2\n"
	);

	EXPECT_STREQ(expected.c_str(), out.str().c_str());
	EXPECT_EQ(4, life.current_population());
}

TEST(LifeTest, EvolveAllCellsBoth) {
	istringstream in(string() +
		"+-0\n" +
		"1*.\n" +
		"0.-\n"
	);

	Life<Cell> life(3, 3);
	in >> life;
	life.evolve_all_cells();

	ostringstream out;
	out << life;

	string expected(string() +
		"+0-\n" +
		"*..\n" +
		"1*-\n"
	);

	EXPECT_STREQ(expected.c_str(), out.str().c_str());
	EXPECT_EQ(5, life.current_population());
}

