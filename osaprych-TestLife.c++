#define protected public
#define private public
#include <iostream>
#include <vector>
#include "gtest/gtest.h"
#include "Life.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"
#include "Handle.h"
#include <sstream>

TEST(ConwayCell, conway_print1){
	std::ostringstream w;
	ConwayCell c = ConwayCell(true, '*');
	ASSERT_TRUE(c.alive());
	c.print_c(w);
	ASSERT_STREQ("*", w.str().c_str());
}
TEST(ConwayCell, conway_print2){
	std::ostringstream w;
	ConwayCell c = ConwayCell(false, '.');
	ASSERT_FALSE(c.alive());
	c.print_c(w);
	ASSERT_STREQ(".", w.str().c_str());
}

TEST(ConwayCell, conway_print3){
	std::ostringstream w;
	std::ostringstream x;
	ConwayCell c = ConwayCell(false, '.');
	ASSERT_FALSE(c.alive());
	c.print_c(w);
	ASSERT_STREQ(".", w.str().c_str());

	c.change_life_state(3, 3);
	c.print_c(x);
	ASSERT_STREQ("*", x.str().c_str());
}

TEST(FredkinCell, fredkin_print1){
	std::ostringstream w;
	FredkinCell f = FredkinCell(true, '0');
	ASSERT_TRUE(f.alive());
	f.print_c(w);
	ASSERT_STREQ("0", w.str().c_str());
}

TEST(FredkinCell, fredkin_print2){
	std::ostringstream w;
	FredkinCell f = FredkinCell(false, '-');
	ASSERT_FALSE(f.alive());
	f.print_c(w);
	ASSERT_STREQ("-", w.str().c_str());
}
TEST(FredkinCell, fredkin_print3){
	std::ostringstream w;
	std::ostringstream x;
	FredkinCell f = FredkinCell(false, '-');
	ASSERT_FALSE(f.alive());
	f.print_c(w);
	ASSERT_STREQ("-", w.str().c_str());

	f.change_life_state(3, 3);
	f.print_c(x);
	ASSERT_STREQ("0", x.str().c_str());
}

TEST(FredkinCell, fredkin_print4){
	std::ostringstream w;
	std::ostringstream x;
	std::ostringstream y;
	FredkinCell f = FredkinCell(false, '-');
	ASSERT_FALSE(f.alive());
	f.print_c(w);
	ASSERT_STREQ("-", w.str().c_str());

	f.change_life_state(3, 3);
	f.print_c(x);
	ASSERT_STREQ("0", x.str().c_str());
	f.change_life_state(6, 6);
	f.change_life_state(6, 6);
	f.change_life_state(6, 6);
	f.print_c(y);
	ASSERT_STREQ("3", y.str().c_str());
}

TEST(FredkinCell, fredkin_print5){
	std::ostringstream w;
	std::ostringstream x;
	std::ostringstream y;
	FredkinCell f = FredkinCell(false, '-');
	ASSERT_FALSE(f.alive());
	f.print_c(w);
	ASSERT_STREQ("-", w.str().c_str());

	f.change_life_state(3, 3);
	f.print_c(x);
	ASSERT_STREQ("0", x.str().c_str());

	f.change_life_state(6, 6);
	f.change_life_state(6, 6);
	f.change_life_state(6, 6);
	f.change_life_state(6, 6);
	f.change_life_state(6, 6);
	f.change_life_state(6, 6);
	f.change_life_state(6, 6);
	f.change_life_state(6, 6);
	f.change_life_state(6, 6);
	f.change_life_state(6, 6);

	f.print_c(y);
	ASSERT_STREQ("+", y.str().c_str());
}

TEST(ConwayCell, conway_alive){
	ConwayCell c = ConwayCell(true, '*');
	ASSERT_TRUE(c.alive());
}

TEST(ConwayCell, conway_dead){
	ConwayCell c = ConwayCell(false, '.');
	ASSERT_FALSE(c.alive());
}


TEST(FredkinCell, fredkin_alive){
	FredkinCell f = FredkinCell(true, '0');
	ASSERT_TRUE(f.alive());
}

TEST(FredkinCell, fredkin_dead){
	FredkinCell f = FredkinCell(false, '-');
	ASSERT_FALSE(f.alive());
}

TEST(ConwayCell, conway_change_life_state_true1){
	ConwayCell c = ConwayCell(true, '*');
	ASSERT_TRUE(c.alive());
	c.change_life_state(1, 1);
	ASSERT_FALSE(c.alive());
}

TEST(ConwayCell, conway_change_life_state_true2){
	ConwayCell c = ConwayCell(true, '*');
	ASSERT_TRUE(c.alive());
	c.change_life_state(1, 2);
	ASSERT_TRUE(c.alive());
}

TEST(ConwayCell, conway_change_life_state_true3){
	ConwayCell c = ConwayCell(true, '*');
	ASSERT_TRUE(c.alive());
	c.change_life_state(1, 3);
	ASSERT_TRUE(c.alive());
}

TEST(ConwayCell, conway_change_life_state_true4){
	ConwayCell c = ConwayCell(true, '*');
	ASSERT_TRUE(c.alive());
	c.change_life_state(1, 4);
	ASSERT_FALSE(c.alive());
}

TEST(ConwayCell, conway_change_life_state_false1){
	ConwayCell c = ConwayCell(false, '.');
	ASSERT_FALSE(c.alive());
	c.change_life_state(1, 1);
	ASSERT_FALSE(c.alive());
}

TEST(ConwayCell, conway_change_life_state_false2){
	ConwayCell c = ConwayCell(false, '.');
	ASSERT_FALSE(c.alive());
	c.change_life_state(1, 2);
	ASSERT_FALSE(c.alive());
}

TEST(ConwayCell, conway_change_life_state_false3){
	ConwayCell c = ConwayCell(false, '.');
	ASSERT_FALSE(c.alive());
	c.change_life_state(1, 3);
	ASSERT_TRUE(c.alive());
}

TEST(FredkinCell, fredkin_change_life_state_true1){
	FredkinCell f = FredkinCell(true, '0');
	ASSERT_TRUE(f.alive());
	f.change_life_state(0, 0);
	ASSERT_FALSE(f.alive());
}

TEST(FredkinCell, fredkin_change_life_state_true2){
	FredkinCell f = FredkinCell(true, '0');
	ASSERT_TRUE(f.alive());
	f.change_life_state(1, 0);
	ASSERT_TRUE(f.alive());
}

TEST(FredkinCell, fredkin_change_life_state_true3){
	FredkinCell f = FredkinCell(true, '0');
	ASSERT_TRUE(f.alive());
	f.change_life_state(2, 0);
	ASSERT_FALSE(f.alive());
}

TEST(FredkinCell, fredkin_change_life_state_true4){
	FredkinCell f = FredkinCell(true, '0');
	ASSERT_TRUE(f.alive());
	f.change_life_state(3, 0);
	ASSERT_TRUE(f.alive());
}

TEST(FredkinCell, fredkin_change_life_state_true5){
	FredkinCell f = FredkinCell(true, '0');
	ASSERT_TRUE(f.alive());
	f.change_life_state(4, 0);
	ASSERT_FALSE(f.alive());
}

TEST(FredkinCell, fredkin_change_life_state_false1){
	FredkinCell f = FredkinCell(false, '0');
	ASSERT_FALSE(f.alive());
	f.change_life_state(0, 0);
	ASSERT_FALSE(f.alive());
}

TEST(FredkinCell, fredkin_change_life_state_false2){
	FredkinCell f = FredkinCell(false, '0');
	ASSERT_FALSE(f.alive());
	f.change_life_state(1, 0);
	ASSERT_TRUE(f.alive());
}

TEST(FredkinCell, fredkin_change_life_state_false3){
	FredkinCell f = FredkinCell(false, '0');
	ASSERT_FALSE(f.alive());
	f.change_life_state(2, 0);
	ASSERT_FALSE(f.alive());
}

TEST(FredkinCell, fredkin_change_life_state_false4){
	FredkinCell f = FredkinCell(false, '0');
	ASSERT_FALSE(f.alive());
	f.change_life_state(3, 0);
	ASSERT_TRUE(f.alive());
}

TEST(FredkinCell, fredkin_change_life_state_age1){
	FredkinCell f = FredkinCell(true, '0');
	ASSERT_TRUE(f.alive());
	f.change_life_state(6, 6);
	ASSERT_TRUE(f.age() == 1);
}
TEST(FredkinCell, fredkin_change_life_state_age2){
	FredkinCell f = FredkinCell(true, '0');
	ASSERT_TRUE(f.alive());
	f.change_life_state(6, 6);
	f.change_life_state(6, 6);
	f.change_life_state(6, 6);
	ASSERT_TRUE(f.age() == 3);
}

TEST(FredkinCell, fredkin_change_life_state_age3){
	FredkinCell f = FredkinCell(true, '0');
	ASSERT_TRUE(f.alive());
	f.change_life_state(2, 2);
	ASSERT_FALSE(f.alive());
	ASSERT_TRUE(f.age() == 0);
	f.change_life_state(1, 2);
	ASSERT_TRUE(f.alive());
	ASSERT_TRUE(f.age() == 0);
	f.change_life_state(6, 6);
	ASSERT_TRUE(f.alive());
	ASSERT_TRUE(f.age() == 1);
}

TEST(Cell, cell_alive_conway1) {
	AbstractCell* ac;
	ac = new ConwayCell(true, '*');
	Cell c = ac;
	ASSERT_TRUE(c.alive());
}

TEST(Cell, cell_alive_conway2) {
	AbstractCell* ac;
	ac = new ConwayCell(false, '.');
	Cell c = ac;
	ASSERT_FALSE(c.alive());
}

TEST(Cell, cell_alive_conway3) {
	AbstractCell* ac;
	ac = new ConwayCell(false, '.');
	Cell c = ac;
	ASSERT_FALSE(c.alive());
	c.change_life_state(3, 3);
	ASSERT_TRUE(c.alive());
}


TEST(Cell, cell_alive_fredkin1) {
	AbstractCell* ac;
	ac = new FredkinCell(true, '0');
	Cell c = ac;
	ASSERT_TRUE(c.alive());
}

TEST(Cell, cell_alive_fredkin2) {
	AbstractCell* ac;
	ac = new FredkinCell(false, '-');
	Cell c = ac;
	ASSERT_FALSE(c.alive());
}

TEST(Cell, cell_alive_fredkin3) {
	AbstractCell* ac;
	ac = new FredkinCell(false, '-');
	Cell c = ac;
	ASSERT_FALSE(c.alive());
	c.change_life_state(1, 1);
	ASSERT_TRUE(c.alive());
}

TEST(Cell, cell_cell_state_fredkin1) {
	AbstractCell* ac;
	ac = new FredkinCell(true, '-');
	Cell c = ac;
	ASSERT_TRUE(c.alive());
	c.change_life_state(0, 0);
	ASSERT_FALSE(c.alive());
}

TEST(Cell, cell_cell_state_fredkin2) {
	AbstractCell* ac;
	ac = new FredkinCell(false, '.');
	Cell c = ac;
	ASSERT_FALSE(c.alive());
	c.change_life_state(1, 1);
	ASSERT_TRUE(c.alive());
}

TEST(Cell, cell_cell_state_conway1) {
	AbstractCell* ac;
	ac = new ConwayCell(false, '.');
	Cell c = ac;
	ASSERT_FALSE(c.alive());
	c.change_life_state(3, 3);
	ASSERT_TRUE(c.alive());
}

TEST(Cell, cell_cell_state_conway2) {
	AbstractCell* ac;
	ac = new ConwayCell(true, '*');
	Cell c = ac;
	ASSERT_TRUE(c.alive());
	c.change_life_state(1, 1);
	ASSERT_FALSE(c.alive());
}

TEST(Cell, cell_mutate_fredkin1) {
	AbstractCell* ac;
	ac = new FredkinCell(false, '.');
	Cell c = ac;
	ASSERT_FALSE(c.alive());
	c.change_life_state(1, 1);
	ASSERT_TRUE(c.alive());
	c.change_life_state(6, 6);
	c.change_life_state(6, 6);
	c.mutate(1, 1);
	ASSERT_TRUE(dynamic_cast<ConwayCell * >(c.get()));

}

TEST(Cell, cell_mutate_fredkin2) {
	AbstractCell* ac;
	ac = new FredkinCell(false, '.');
	Cell c = ac;
	ASSERT_FALSE(c.alive());
	c.change_life_state(1, 1);
	ASSERT_TRUE(c.alive());
	c.change_life_state(6, 6);
	c.mutate(1, 1);
	ASSERT_TRUE(dynamic_cast<FredkinCell * >(c.get()));
}

TEST(Cell, cell_mutate_fredkin3) {
	AbstractCell* ac;
	ac = new FredkinCell(false, '.');
	Cell c = ac;
	ASSERT_FALSE(c.alive());
	c.change_life_state(1, 1);
	ASSERT_TRUE(c.alive());
	c.change_life_state(6, 6);
	c.change_life_state(6, 6);
	c.mutate(1, 1);

	for(int i = 0; i < 10; i++){
		c.mutate(1, 1);
		ASSERT_TRUE(dynamic_cast<ConwayCell * >(c.get()));
	}
}

TEST(Cell, cell_mutate_conway) {
	AbstractCell* ac;
	ac = new ConwayCell(false, '.');
	Cell c = ac;
	ASSERT_FALSE(c.alive());

	c.mutate(1, 1);
	ASSERT_TRUE(dynamic_cast<ConwayCell * >(c.get()));
}

TEST(Cell, cell_mutate_conway2) {
	AbstractCell* ac;
	ac = new ConwayCell(false, '.');
	Cell c = ac;
	ASSERT_FALSE(c.alive());

	for(int i = 0; i < 100; i++){
		c.change_life_state(1, 1);
		c.mutate(1, 1);
		ASSERT_TRUE(dynamic_cast<ConwayCell * >(c.get()));
	}
}

TEST(Cell, cell_fredkin_clone1){
	FredkinCell f = FredkinCell(true, '0');
	Cell c = 0;
	c = f.clone();
	ASSERT_TRUE(dynamic_cast<FredkinCell * >(c.get()));
}

TEST(Cell, cell_conway_clone2){
	ConwayCell cw = ConwayCell(true, '*');
	Cell c = 0;
	c = cw.clone();
	ASSERT_TRUE(dynamic_cast<ConwayCell * >(c.get()));
}

TEST(Life, populate_row1){
	Life<ConwayCell> life(5, 5);
	std::string s = "**..*";
	ASSERT_TRUE(life.populate_row(0, s));
}

TEST(Life, populate_row2){
	Life<FredkinCell> life(10, 4);
	std::string s = "-0-0";
	ASSERT_TRUE(life.populate_row(1, s));
}

TEST(Life, populate_row3){
	Life<FredkinCell> life(15, 1);
	std::string s = "0";
	ASSERT_TRUE(life.populate_row(2, s));
}

TEST(Life, populate_cell1){
	Life<Cell> life(5, 6);
	std::string s = "0*--..";
	ASSERT_TRUE(life.populate_cell(0, s));
}

TEST(Life, populate_cell2){
	Life<Cell> life(4, 7);
	std::string s = "0*--..0";
	ASSERT_TRUE(life.populate_cell(1, s));
}

TEST(Life, populate_cell3){
	Life<Cell> life(7, 7);
	std::string s = "000****";
	ASSERT_TRUE(life.populate_cell(4, s));
}

TEST(Life, change_cell_state_Conway){
	Life<ConwayCell> life(3, 3);
	std::string row1 = "*.*";
	std::string row2 = ".*.";
	std::string row3 = "*.*";
	life.populate_row(0, row1);
	life.populate_row(1, row2);
	life.populate_row(2, row3);
	const char* const expected_output = "Generation = 1, Population = 4.\n.*.\n*.*\n.*.\n";
	life.scan_neighbors();
	life.change_cell_state();
	std::ostringstream w;
	life.print(w, 1);
	ASSERT_STREQ(expected_output, w.str().c_str());
}

TEST(Life, change_cell_state_Fredkin){
	Life<FredkinCell> life(3, 3);
	std::string row1 = "0-0";
	std::string row2 = "-0-";
	std::string row3 = "0-0";
	life.populate_row(0, row1);
	life.populate_row(1, row2);
	life.populate_row(2, row3);
	const char* const expected_output = "Generation = 1, Population = 4.\n-0-\n0-0\n-0-\n";
	life.scan_neighbors();
	life.change_cell_state();
	std::ostringstream w;
	life.print(w, 1);
	ASSERT_STREQ(expected_output, w.str().c_str());
}

TEST(Life, change_cell_state_Cell){
	Life<Cell> life(3, 3);
	std::string row1 = "0.*";
	std::string row2 = "-*-";
	std::string row3 = "*.0";
	life.populate_cell(0, row1);
	life.populate_cell(1, row2);
	life.populate_cell(2, row3);
	const char* const expected_output = "Generation = 1, Population = 4.\n-*.\n0.0\n.*-\n";
	life.scan_neighbors();
	life.change_cell_state();
	std::ostringstream w;
	life.print(w, 1);
	ASSERT_STREQ(expected_output, w.str().c_str());
}

TEST(Life, printConway){
	Life<ConwayCell> life(3, 3);
	std::string row1 = "*.*";
	std::string row2 = ".*.";
	std::string row3 = "*.*";
	life.populate_row(0, row1);
	life.populate_row(1, row2);
	life.populate_row(2, row3);
	const char* const expected_output = "Generation = 0, Population = 5.\n*.*\n.*.\n*.*\n";
	std::ostringstream w;
	life.print(w, 0);
	ASSERT_STREQ(expected_output, w.str().c_str());
}

TEST(Life, printFredkin){
	Life<FredkinCell> life(3, 3);
	std::string row1 = "0-0";
	std::string row2 = "-0-";
	std::string row3 = "0-0";
	life.populate_row(0, row1);
	life.populate_row(1, row2);
	life.populate_row(2, row3);
	const char* const expected_output = "Generation = 0, Population = 5.\n0-0\n-0-\n0-0\n";
	std::ostringstream w;
	life.print(w, 0);
	ASSERT_STREQ(expected_output, w.str().c_str());
}

TEST(Life, printCell){
	Life<Cell> life(3, 3);
	std::string row1 = "0.*";
	std::string row2 = "-*-";
	std::string row3 = "*.0";
	life.populate_cell(0, row1);
	life.populate_cell(1, row2);
	life.populate_cell(2, row3);
	const char* const expected_output = "Generation = 0, Population = 5.\n0.*\n-*-\n*.0\n";
	std::ostringstream w;
	life.print(w, 0);
	ASSERT_STREQ(expected_output, w.str().c_str());
}

TEST(Life, evolve_no_changes){
	Life<Cell> life(3, 3);
	std::string row1 = "0.*";
	std::string row2 = "-*-";
	std::string row3 = "*.0";
	life.populate_cell(0, row1);
	life.populate_cell(1, row2);
	life.populate_cell(2, row3);
	const char* const expected_output = "Generation = 0, Population = 5.\n0.*\n-*-\n*.0\n";
	std::ostringstream w;
	life.evolve();
	life.print(w, 0);
	ASSERT_STREQ(expected_output, w.str().c_str());
}

TEST(Life, evolve_cell_1st_gen){
	Life<Cell> life(3, 3);
	std::string row1 = "0.*";
	std::string row2 = "-*-";
	std::string row3 = "*.0";
	life.populate_cell(0, row1);
	life.populate_cell(1, row2);
	life.populate_cell(2, row3);
	const char* const expected_output = "Generation = 1, Population = 4.\n-*.\n0.0\n.*-\n";
	std::ostringstream w;
	life.scan_neighbors();
	life.change_cell_state();
	life.evolve();
	life.print(w, 1);
	ASSERT_STREQ(expected_output, w.str().c_str());
}

TEST(Life, evolve_cell_2nd_gen){
	Life<Cell> life(3, 4);
	std::string row1 = "0000";
	std::string row2 = "0000";
	std::string row3 = "0000";
	life.populate_cell(0, row1);
	life.populate_cell(1, row2);
	life.populate_cell(2, row3);
	const char* const expected_output = "Generation = 2, Population = 2.\n----\n*--*\n----\n";
	std::ostringstream w;
	life.scan_neighbors();
	life.change_cell_state();
	life.evolve();
	life.scan_neighbors();
	life.change_cell_state();
	life.evolve();
	life.print(w, 2);
	ASSERT_STREQ(expected_output, w.str().c_str());
}

TEST(Life, run_generation_Fredkin){
	Life<FredkinCell> life(1, 2);
	std::string row1 = "00";
	life.populate_row(0, row1);
	const char* const expected_output = "Generation = 1, Population = 2.\n11\n";
	std::ostringstream w;
	life.run_generation();
	life.print(w, 1);
	ASSERT_STREQ(expected_output, w.str().c_str());
}

TEST(Life, run_generation_Conway){
	Life<ConwayCell> life(2, 2);
	std::string row1 = "**";
	std::string row2 = "**";
	life.populate_row(0, row1);
	life.populate_row(1, row2);
	const char* const expected_output = "Generation = 1, Population = 4.\n**\n**\n";
	std::ostringstream w;
	life.run_generation();
	life.print(w, 1);
	ASSERT_STREQ(expected_output, w.str().c_str());
}

TEST(Life, run_generation_Cell){
	Life<Cell> life(3, 4);
	std::string row1 = "*00*";
	std::string row2 = "*..*";
	std::string row3 = "*--*";
	life.populate_cell(0, row1);
	life.populate_cell(1, row2);
	life.populate_cell(2, row3);
	const char* const expected_output = "Generation = 1, Population = 6.\n*--*\n*..*\n.00.\n";
	std::ostringstream w;
	life.run_generation();
	life.print(w, 1);
	ASSERT_STREQ(expected_output, w.str().c_str());
}

TEST(Life, clear_and_resize_cell){
	Life<Cell> life(3, 4);
	std::string row1 = "*00*";
	std::string row2 = "*..*";
	std::string row3 = "*--*";
	life.populate_cell(0, row1);
	life.populate_cell(1, row2);
	life.populate_cell(2, row3);
	life.scan_neighbors();
	life.change_cell_state();
	life.clear_and_resize();
	const char* const expected_output1 = "Generation = 1, Population = 6.\n*--*\n*..*\n.00.\n";
	std::ostringstream w;
	life.print(w, 1);
	ASSERT_STREQ(expected_output1, w.str().c_str());
	life.change_cell_state();
	std::ostringstream x;
	life.print(x, 1);
	const char* const expected_output2 = "Generation = 1, Population = 0.\n.--.\n....\n.--.\n";
	ASSERT_STREQ(expected_output2, x.str().c_str());
}

TEST(Life, clear_and_resize_fredkin){
	Life<FredkinCell> life(2, 3);
	std::string row1 = "000";
	std::string row2 = "---";
	life.populate_row(0, row1);
	life.populate_row(1, row2);
	life.scan_neighbors();
	life.change_cell_state();
	life.clear_and_resize();
	const char* const expected_output1 = "Generation = 1, Population = 5.\n1-1\n000\n";
	std::ostringstream w;
	life.print(w, 1);
	ASSERT_STREQ(expected_output1, w.str().c_str());
	life.change_cell_state();
	std::ostringstream x;
	life.print(x, 1);
	const char* const expected_output2 = "Generation = 1, Population = 0.\n---\n---\n";
	ASSERT_STREQ(expected_output2, x.str().c_str());
}

TEST(Life, clear_and_resize_conway){
	Life<ConwayCell> life(4, 3);
	std::string row1 = "***";
	std::string row2 = "...";
	std::string row3 = "...";
	std::string row4 = "***";
	life.populate_row(0, row1);
	life.populate_row(1, row2);
	life.populate_row(1, row3);
	life.populate_row(1, row4);
	life.scan_neighbors();
	life.change_cell_state();
	life.clear_and_resize();
	const char* const expected_output1 = "Generation = 1, Population = 5.\n*.*\n*.*\n.*.\n...\n";
	std::ostringstream w;
	life.print(w, 1);
	ASSERT_STREQ(expected_output1, w.str().c_str());
	life.change_cell_state();
	std::ostringstream x;
	life.print(x, 1);
	const char* const expected_output2 = "Generation = 1, Population = 0.\n...\n...\n...\n...\n";
	ASSERT_STREQ(expected_output2, x.str().c_str());
}

TEST(Life, count_population_conway){
	Life<ConwayCell> life(4, 3);
	std::string row1 = "***";
	std::string row2 = "...";
	std::string row3 = "...";
	std::string row4 = "***";
	life.populate_row(0, row1);
	life.populate_row(1, row2);
	life.populate_row(2, row3);
	life.populate_row(3, row4);
	int poputalion = life.count_population();
	ASSERT_EQ(6, poputalion);
}

TEST(Life, count_population_fredkin){
	Life<FredkinCell> life(5, 5);
	std::string row1 = "00000";
	std::string row2 = "-----";
	std::string row3 = "00000";
	std::string row4 = "00000";
	std::string row5 = "-----";
	life.populate_row(0, row1);
	life.populate_row(1, row2);
	life.populate_row(2, row3);
	life.populate_row(3, row4);
	life.populate_row(4, row5);
	int poputalion = life.count_population();
	ASSERT_EQ(15, poputalion);
}

TEST(Life, count_population_cell){
	Life<Cell> life(1, 4);
	std::string row1 = "****";
	life.populate_cell(0, row1);
	int poputalion = life.count_population();
	ASSERT_EQ(4, poputalion);
}

TEST(Life, scan_neighbors_cell){
	Life<Cell> life(2, 4);
	std::string row1 = "*.*.";
	std::string row2 = ".*.*";
	life.populate_cell(0, row1);
	life.populate_cell(1, row2);
	life.scan_neighbors();
	life.change_cell_state();
	const char* const expected_output = "Generation = 1, Population = 4.\n.**.\n.**.\n";
	std::ostringstream w;
	life.print(w, 1);
	ASSERT_STREQ(expected_output, w.str().c_str());
}

TEST(Life, scan_neighbors_fredkin){
	Life<FredkinCell> life(3, 3);
	std::string row1 = "000";
	std::string row2 = "0-0";
	std::string row3 = "-0-";
	life.populate_row(0, row1);
	life.populate_row(1, row2);
	life.populate_row(2, row3);
	life.scan_neighbors();
	life.change_cell_state();
	const char* const expected_output = "Generation = 1, Population = 2.\n---\n1-1\n---\n";
	std::ostringstream w;
	life.print(w, 1);
	ASSERT_STREQ(expected_output, w.str().c_str());
}

TEST(Life, scan_neighbors_conway){
	Life<ConwayCell> life(3, 3);
	std::string row1 = "...";
	std::string row2 = "***";
	std::string row3 = "...";
	life.populate_row(0, row1);
	life.populate_row(1, row2);
	life.populate_row(2, row3);
	life.scan_neighbors();
	life.change_cell_state();
	const char* const expected_output = "Generation = 1, Population = 3.\n.*.\n.*.\n.*.\n";
	std::ostringstream w;
	life.print(w, 1);
	ASSERT_STREQ(expected_output, w.str().c_str());
}

/* conway neighbor checking */
TEST(Life, check_one_conway3) {
	Life<ConwayCell> life(1, 1);

	std::string row1 = "*";

	life.populate_row(0, row1);

	life.scan_neighbors();

	ASSERT_TRUE(life.c_neighbors[0][0] == 0);
}

TEST(Life, check_top_left_conway1) {
	Life<ConwayCell> life(3, 3);

	std::string row1 = "*..";
	std::string row2 = ".*.";
	std::string row3 = "...";

	life.populate_row(0, row1);
	life.populate_row(1, row2);
	life.populate_row(2, row3);

	life.scan_neighbors();

	ASSERT_TRUE(life.c_neighbors[0][0] == 1);
}

TEST(Life, check_top_left_conway2) {
	Life<ConwayCell> life(3, 3);

	std::string row1 = "**.";
	std::string row2 = "**.";
	std::string row3 = "...";

	life.populate_row(0, row1);
	life.populate_row(1, row2);
	life.populate_row(2, row3);

	life.scan_neighbors();

	ASSERT_TRUE(life.c_neighbors[0][0] == 3);
}

TEST(Life, check_top_left_conway3) {
	Life<ConwayCell> life(3, 3);

	std::string row1 = "**.";
	std::string row2 = "*..";
	std::string row3 = "...";

	life.populate_row(0, row1);
	life.populate_row(1, row2);
	life.populate_row(2, row3);

	life.scan_neighbors();

	ASSERT_TRUE(life.c_neighbors[0][0] == 2);
}

TEST(Life, check_top_right_conway1) {
	Life<ConwayCell> life(3, 3);

	std::string row1 = "*..";
	std::string row2 = "...";
	std::string row3 = "...";

	life.populate_row(0, row1);
	life.populate_row(1, row2);
	life.populate_row(2, row3);

	life.scan_neighbors();

	ASSERT_TRUE(life.c_neighbors[0][2] == 0);
}

TEST(Life, check_top_right_conway2) {
	Life<ConwayCell> life(3, 3);

	std::string row1 = "**.";
	std::string row2 = "***";
	std::string row3 = "...";

	life.populate_row(0, row1);
	life.populate_row(1, row2);
	life.populate_row(2, row3);

	life.scan_neighbors();

	ASSERT_TRUE(life.c_neighbors[0][2] == 3);
}

TEST(Life, check_top_right_conway3) {
	Life<ConwayCell> life(3, 3);

	std::string row1 = "**.";
	std::string row2 = "*.*";
	std::string row3 = "...";

	life.populate_row(0, row1);
	life.populate_row(1, row2);
	life.populate_row(2, row3);

	life.scan_neighbors();

	ASSERT_TRUE(life.c_neighbors[0][2] == 2);
}

TEST(Life, check_bottom_left_conway1) {
	Life<ConwayCell> life(3, 3);

	std::string row1 = "*..";
	std::string row2 = "...";
	std::string row3 = "*..";

	life.populate_row(0, row1);
	life.populate_row(1, row2);
	life.populate_row(2, row3);

	life.scan_neighbors();

	ASSERT_TRUE(life.c_neighbors[2][0] == 0);
}

TEST(Life, check_bottom_left_conway2) {
	Life<ConwayCell> life(3, 3);

	std::string row1 = "**.";
	std::string row2 = "***";
	std::string row3 = "*..";

	life.populate_row(0, row1);
	life.populate_row(1, row2);
	life.populate_row(2, row3);

	life.scan_neighbors();

	ASSERT_TRUE(life.c_neighbors[2][0] == 2);
}

TEST(Life, check_bottom_left_conway3) {
	Life<ConwayCell> life(3, 3);

	std::string row1 = "**.";
	std::string row2 = "*.*";
	std::string row3 = "...";

	life.populate_row(0, row1);
	life.populate_row(1, row2);
	life.populate_row(2, row3);

	life.scan_neighbors();

	ASSERT_TRUE(life.c_neighbors[2][0] == 1);
}

TEST(Life, check_bottom_right_conway1) {
	Life<ConwayCell> life(3, 3);

	std::string row1 = "*..";
	std::string row2 = "...";
	std::string row3 = "*..";

	life.populate_row(0, row1);
	life.populate_row(1, row2);
	life.populate_row(2, row3);

	life.scan_neighbors();

	ASSERT_TRUE(life.c_neighbors[2][2] == 0);
}

TEST(Life, check_bottom_right_conway2) {
	Life<ConwayCell> life(3, 3);

	std::string row1 = "**.";
	std::string row2 = "***";
	std::string row3 = "*..";

	life.populate_row(0, row1);
	life.populate_row(1, row2);
	life.populate_row(2, row3);

	life.scan_neighbors();

	ASSERT_TRUE(life.c_neighbors[2][2] == 2);
}

TEST(Life, check_bottom_right_conway3) {
	Life<ConwayCell> life(3, 3);

	std::string row1 = "**.";
	std::string row2 = "***";
	std::string row3 = ".*.";

	life.populate_row(0, row1);
	life.populate_row(1, row2);
	life.populate_row(2, row3);

	life.scan_neighbors();

	ASSERT_TRUE(life.c_neighbors[2][2] == 3);
}

TEST(Life, check_top_edge_conway1) {
	Life<ConwayCell> life(3, 3);

	std::string row1 = "*..";
	std::string row2 = "...";
	std::string row3 = "*..";

	life.populate_row(0, row1);
	life.populate_row(1, row2);
	life.populate_row(2, row3);

	life.scan_neighbors();

	ASSERT_TRUE(life.c_neighbors[0][1] == 1);
}

TEST(Life, check_top_edge_conway2) {
	Life<ConwayCell> life(3, 3);

	std::string row1 = "**.";
	std::string row2 = "***";
	std::string row3 = "*..";

	life.populate_row(0, row1);
	life.populate_row(1, row2);
	life.populate_row(2, row3);

	life.scan_neighbors();

	ASSERT_TRUE(life.c_neighbors[0][1] == 4);
}

TEST(Life, check_top_edge_conway3) {
	Life<ConwayCell> life(3, 3);

	std::string row1 = "***";
	std::string row2 = "***";
	std::string row3 = ".*.";

	life.populate_row(0, row1);
	life.populate_row(1, row2);
	life.populate_row(2, row3);

	life.scan_neighbors();

	ASSERT_TRUE(life.c_neighbors[0][1] == 5);
}

TEST(Life, check_left_edge_conway1) {
	Life<ConwayCell> life(3, 3);

	std::string row1 = "*..";
	std::string row2 = "...";
	std::string row3 = "*..";

	life.populate_row(0, row1);
	life.populate_row(1, row2);
	life.populate_row(2, row3);

	life.scan_neighbors();

	ASSERT_TRUE(life.c_neighbors[1][0] == 2);
}

TEST(Life, check_left_edge_conway2) {
	Life<ConwayCell> life(3, 3);

	std::string row1 = "**.";
	std::string row2 = "***";
	std::string row3 = "*..";

	life.populate_row(0, row1);
	life.populate_row(1, row2);
	life.populate_row(2, row3);

	life.scan_neighbors();

	ASSERT_TRUE(life.c_neighbors[1][0] == 4);
}

TEST(Life, check_left_edge_conway3) {
	Life<ConwayCell> life(3, 3);

	std::string row1 = ".**";
	std::string row2 = "..*";
	std::string row3 = "...";

	life.populate_row(0, row1);
	life.populate_row(1, row2);
	life.populate_row(2, row3);

	life.scan_neighbors();

	ASSERT_TRUE(life.c_neighbors[1][0] == 1);
}

TEST(Life, check_bottom_edge_conway1) {
	Life<ConwayCell> life(3, 3);

	std::string row1 = "*..";
	std::string row2 = "...";
	std::string row3 = "...";

	life.populate_row(0, row1);
	life.populate_row(1, row2);
	life.populate_row(2, row3);

	life.scan_neighbors();

	ASSERT_TRUE(life.c_neighbors[2][1] == 0);
}

TEST(Life, check_bottom_edge_conway2) {
	Life<ConwayCell> life(3, 3);

	std::string row1 = "**.";
	std::string row2 = "***";
	std::string row3 = "*.*";

	life.populate_row(0, row1);
	life.populate_row(1, row2);
	life.populate_row(2, row3);

	life.scan_neighbors();

	ASSERT_TRUE(life.c_neighbors[2][1] == 5);
}

TEST(Life, check_bottom_edge_conway3) {
	Life<ConwayCell> life(3, 3);

	std::string row1 = ".**";
	std::string row2 = "..*";
	std::string row3 = "...";

	life.populate_row(0, row1);
	life.populate_row(1, row2);
	life.populate_row(2, row3);

	life.scan_neighbors();

	ASSERT_TRUE(life.c_neighbors[2][1] == 1);
}


TEST(Life, check_right_edge_conway1) {
	Life<ConwayCell> life(3, 3);

	std::string row1 = "*..";
	std::string row2 = "...";
	std::string row3 = "...";

	life.populate_row(0, row1);
	life.populate_row(1, row2);
	life.populate_row(2, row3);

	life.scan_neighbors();

	ASSERT_TRUE(life.c_neighbors[1][2] == 0);
}

TEST(Life, check_right_edge_conway2) {
	Life<ConwayCell> life(3, 3);

	std::string row1 = "**.";
	std::string row2 = "***";
	std::string row3 = "*.*";

	life.populate_row(0, row1);
	life.populate_row(1, row2);
	life.populate_row(2, row3);

	life.scan_neighbors();

	ASSERT_TRUE(life.c_neighbors[1][2] == 3);
}

TEST(Life, check_right_edge_conway3) {
	Life<ConwayCell> life(3, 3);

	std::string row1 = ".**";
	std::string row2 = ".**";
	std::string row3 = ".**";

	life.populate_row(0, row1);
	life.populate_row(1, row2);
	life.populate_row(2, row3);

	life.scan_neighbors();

	ASSERT_TRUE(life.c_neighbors[1][2] == 5);
}

TEST(Life, check_interior_conway1) {
	Life<ConwayCell> life(3, 3);

	std::string row1 = "*..";
	std::string row2 = "...";
	std::string row3 = "...";

	life.populate_row(0, row1);
	life.populate_row(1, row2);
	life.populate_row(2, row3);

	life.scan_neighbors();

	ASSERT_TRUE(life.c_neighbors[1][1] == 1);
}

TEST(Life, check_interior_conway2) {
	Life<ConwayCell> life(3, 3);

	std::string row1 = "**.";
	std::string row2 = "***";
	std::string row3 = "*.*";

	life.populate_row(0, row1);
	life.populate_row(1, row2);
	life.populate_row(2, row3);

	life.scan_neighbors();

	ASSERT_TRUE(life.c_neighbors[1][1] == 6);
}

TEST(Life, check_interior_conway3) {
	Life<ConwayCell> life(3, 3);

	std::string row1 = ".**";
	std::string row2 = ".**";
	std::string row3 = ".**";

	life.populate_row(0, row1);
	life.populate_row(1, row2);
	life.populate_row(2, row3);

	life.scan_neighbors();

	ASSERT_TRUE(life.c_neighbors[1][1] == 5);
}





/* fredkin neighbor checking */
TEST(Life, check_one_fredkin1) {
	Life<FredkinCell> life(1, 1);

	std::string row1 = "0";

	life.populate_row(0, row1);

	life.scan_neighbors();

	ASSERT_TRUE(life.f_neighbors[0][0] == 0);
}

TEST(Life, check_top_left_fredkin1) {
	Life<FredkinCell> life(3, 3);

	std::string row1 = "0--";
	std::string row2 = "-0-";
	std::string row3 = "---";

	life.populate_row(0, row1);
	life.populate_row(1, row2);
	life.populate_row(2, row3);

	life.scan_neighbors();

	ASSERT_TRUE(life.f_neighbors[0][0] == 0);
}

TEST(Life, check_top_left_fredkin2) {
	Life<FredkinCell> life(3, 3);

	std::string row1 = "00-";
	std::string row2 = "00-";
	std::string row3 = "---";

	life.populate_row(0, row1);
	life.populate_row(1, row2);
	life.populate_row(2, row3);

	life.scan_neighbors();

	ASSERT_TRUE(life.f_neighbors[0][0] == 2);
}

TEST(Life, check_top_left_fredkin3) {
	Life<FredkinCell> life(3, 3);

	std::string row1 = "00-";
	std::string row2 = "0--";
	std::string row3 = "---";

	life.populate_row(0, row1);
	life.populate_row(1, row2);
	life.populate_row(2, row3);

	life.scan_neighbors();

	ASSERT_TRUE(life.f_neighbors[0][0] == 2);
}

TEST(Life, check_top_right_fredkin1) {
	Life<FredkinCell> life(3, 3);

	std::string row1 = "0--";
	std::string row2 = "-0-";
	std::string row3 = "---";

	life.populate_row(0, row1);
	life.populate_row(1, row2);
	life.populate_row(2, row3);

	life.scan_neighbors();

	ASSERT_TRUE(life.f_neighbors[0][2] == 0);
}

TEST(Life, check_top_right_fredkin2) {
	Life<FredkinCell> life(3, 3);

	std::string row1 = "00-";
	std::string row2 = "00-";
	std::string row3 = "---";

	life.populate_row(0, row1);
	life.populate_row(1, row2);
	life.populate_row(2, row3);

	life.scan_neighbors();

	ASSERT_TRUE(life.f_neighbors[0][2] == 1);
}

TEST(Life, check_top_right_fredkin3) {
	Life<FredkinCell> life(3, 3);

	std::string row1 = "00-";
	std::string row2 = "0-0";
	std::string row3 = "---";

	life.populate_row(0, row1);
	life.populate_row(1, row2);
	life.populate_row(2, row3);

	life.scan_neighbors();

	ASSERT_TRUE(life.f_neighbors[0][2] == 2);
}

TEST(Life, check_bottom_left_fredkin1) {
	Life<FredkinCell> life(3, 3);

	std::string row1 = "0--";
	std::string row2 = "-0-";
	std::string row3 = "---";

	life.populate_row(0, row1);
	life.populate_row(1, row2);
	life.populate_row(2, row3);

	life.scan_neighbors();

	ASSERT_TRUE(life.f_neighbors[2][0] == 0);
}

TEST(Life, check_bottom_left_fredkin2) {
	Life<FredkinCell> life(3, 3);

	std::string row1 = "00-";
	std::string row2 = "00-";
	std::string row3 = "---";

	life.populate_row(0, row1);
	life.populate_row(1, row2);
	life.populate_row(2, row3);

	life.scan_neighbors();

	ASSERT_TRUE(life.f_neighbors[2][0] == 1);
}

TEST(Life, check_bottom_left_fredkin3) {
	Life<FredkinCell> life(3, 3);

	std::string row1 = "00-";
	std::string row2 = "0-0";
	std::string row3 = "-0-";

	life.populate_row(0, row1);
	life.populate_row(1, row2);
	life.populate_row(2, row3);

	life.scan_neighbors();

	ASSERT_TRUE(life.f_neighbors[2][0] == 2);
}

TEST(Life, check_bottom_right_fredkin1) {
	Life<FredkinCell> life(3, 3);

	std::string row1 = "0--";
	std::string row2 = "-0-";
	std::string row3 = "---";

	life.populate_row(0, row1);
	life.populate_row(1, row2);
	life.populate_row(2, row3);

	life.scan_neighbors();

	ASSERT_TRUE(life.f_neighbors[2][2] == 0);
}

TEST(Life, check_bottom_right_fredkin2) {
	Life<FredkinCell> life(3, 3);

	std::string row1 = "00-";
	std::string row2 = "00-";
	std::string row3 = "-0-";

	life.populate_row(0, row1);
	life.populate_row(1, row2);
	life.populate_row(2, row3);

	life.scan_neighbors();

	ASSERT_TRUE(life.f_neighbors[2][2] == 1);
}

TEST(Life, check_bottom_right_fredkin3) {
	Life<FredkinCell> life(3, 3);

	std::string row1 = "00-";
	std::string row2 = "000";
	std::string row3 = "-0-";

	life.populate_row(0, row1);
	life.populate_row(1, row2);
	life.populate_row(2, row3);

	life.scan_neighbors();

	ASSERT_TRUE(life.f_neighbors[2][2] == 2);
}

TEST(Life, check_top_edge_fredkin1) {
	Life<FredkinCell> life(3, 3);

	std::string row1 = "0--";
	std::string row2 = "-0-";
	std::string row3 = "---";

	life.populate_row(0, row1);
	life.populate_row(1, row2);
	life.populate_row(2, row3);

	life.scan_neighbors();

	ASSERT_TRUE(life.f_neighbors[0][1] == 2);
}

TEST(Life, check_top_edge_fredkin2) {
	Life<FredkinCell> life(3, 3);

	std::string row1 = "-0-";
	std::string row2 = "0--";
	std::string row3 = "-0-";

	life.populate_row(0, row1);
	life.populate_row(1, row2);
	life.populate_row(2, row3);

	life.scan_neighbors();

	ASSERT_TRUE(life.f_neighbors[0][1] == 0);
}

TEST(Life, check_top_edge_fredkin3) {
	Life<FredkinCell> life(3, 3);

	std::string row1 = "000";
	std::string row2 = "000";
	std::string row3 = "-0-";

	life.populate_row(0, row1);
	life.populate_row(1, row2);
	life.populate_row(2, row3);

	life.scan_neighbors();

	ASSERT_TRUE(life.f_neighbors[0][1] == 3);
}


TEST(Cell, check_top_left_cell){
	Life<Cell> life(3, 3);

	std::string row1 = "---";
	std::string row2 = "000";
	std::string row3 = "-0-";

	life.populate_cell(0, row1);
	life.populate_cell(1, row2);
	life.populate_cell(2, row3);

	life.scan_neighbors();

	ASSERT_TRUE(life.f_neighbors[0][0] == 1);
}

TEST(Cell, check_top_right_cell){
	Life<Cell> life(3, 3);

	std::string row1 = "-0-";
	std::string row2 = "000";
	std::string row3 = "-0-";

	life.populate_cell(0, row1);
	life.populate_cell(1, row2);
	life.populate_cell(2, row3);

	life.scan_neighbors();

	ASSERT_TRUE(life.f_neighbors[0][2] == 2);
}

TEST(Cell, check_botom_right_cell){
	Life<Cell> life(3, 3);

	std::string row1 = "-0-";
	std::string row2 = "000";
	std::string row3 = "-0-";

	life.populate_cell(0, row1);
	life.populate_cell(1, row2);
	life.populate_cell(2, row3);

	life.scan_neighbors();

	ASSERT_TRUE(life.f_neighbors[2][0] == 2);
}

TEST(Cell, check_interior_mixed_cell){
	Life<Cell> life(3, 3);

	std::string row1 = "-0-";
	std::string row2 = "0*0";
	std::string row3 = "-0-";

	life.populate_cell(0, row1);
	life.populate_cell(1, row2);
	life.populate_cell(2, row3);

	life.scan_neighbors();

	ASSERT_TRUE(dynamic_cast<ConwayCell *>(life.grid[1][1].get()));
	ASSERT_TRUE(life.c_neighbors[1][1] == 4);
}