// --------
// includes
// --------

#include <string>
#include <vector>
#include <iostream>

#include "gtest/gtest.h"

#define protected public //access protected methods for testing
#include "Cell.h"

#define class struct //access private variables for testing
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Life.h"

using namespace std;

// ----------
// ConwayCell
// ----------

//read
TEST(Life, ConwayCell_read_alive){
	ConwayCell c(false);
	istringstream r("*");
	c.read(r);
	ASSERT_TRUE(c.isAlive());
}

TEST(Life, ConwayCell_read_dead){
	ConwayCell c(true);
	istringstream r(".");
	c.read(r);
	ASSERT_TRUE(!c.isAlive());
}

//write
TEST(Life, ConwayCell_write_alive){
	ConwayCell c(true);
	ostringstream w;
	c.write(w);
	ASSERT_EQ("*", w.str());
}

TEST(Life, ConwayCell_write_dead){
	ConwayCell c(false);
	ostringstream w;
	c.write(w);
	ASSERT_EQ(".", w.str());
}

//constructor
TEST(Life, ConwayCell_constructor_alive){
	ConwayCell c(true);
	ASSERT_TRUE(c.isAlive());
}

TEST(Life, ConwayCell_constructor_dead){
	ConwayCell c(false);
	ASSERT_TRUE(!c.isAlive());
}

//isAlive
TEST(Life, ConwayCell_isAlive){
	ConwayCell c(true);
	ASSERT_TRUE(c.isAlive());
}

TEST(Life, ConwayCell_isNotAlive){
	ConwayCell c(false);
	ASSERT_TRUE(!c.isAlive());
}

//survive
TEST(Life, ConwayCell_survive){
	ConwayCell c(true);
	c.survive();
	ASSERT_TRUE(c.isAlive());
}

//die
TEST(Life, ConwayCell_die){
	ConwayCell c(true);
	c.die();
	ASSERT_TRUE(!c.isAlive());
}

TEST(Life, ConwayCell_stayDead){
	ConwayCell c(false);
	c.die();
	ASSERT_TRUE(!c.isAlive());
}

//clone
TEST(Life, ConwayCell_clone_alive){
	ConwayCell c(true);
	ConwayCell* c2p = c.clone();
	ConwayCell& c2 = *c2p;
	ASSERT_TRUE(c.isAlive());
	ASSERT_TRUE(c2.isAlive());
	delete c2p;
}

TEST(Life, ConwayCell_clone_dead){
	ConwayCell c(false);
	ConwayCell* c2p = c.clone();
	ConwayCell& c2 = *c2p;
	ASSERT_TRUE(!c.isAlive());
	ASSERT_TRUE(!c2.isAlive());
	delete c2p;
}

TEST(Life, ConwayCell_clone_changeState){
	ConwayCell c(true);
	ConwayCell* c2p = c.clone();
	ConwayCell& c2 = *c2p;
	c.die();
	ASSERT_TRUE(!c.isAlive());
	ASSERT_TRUE(c2.isAlive());
	delete c2p;
}

//cellType
TEST(Life, ConwayCell_cellType_alive){
	ConwayCell c(true);
	ASSERT_TRUE('c' == c.cellType());
}

TEST(Life, ConwayCell_cellType_dead){
	ConwayCell c(false);
	ASSERT_TRUE('c' == c.cellType());
}

//getAge
TEST(Life, ConwayCell_getAge_alive){
	ConwayCell c(true);
	ASSERT_EQ(-1, c.getAge());
}

TEST(Life, ConwayCell_getAge_dead){
	ConwayCell c(false);
	ASSERT_EQ(-1, c.getAge());
}

// -----------
// FredkinCell
// -----------

//read
TEST(Life, FredkinCell_read_alive){
	FredkinCell c(false);
	istringstream r("0");
	c.read(r);
	ASSERT_TRUE(c.isAlive());
}

TEST(Life, FredkinCell_read_dead){
	FredkinCell c(true);
	istringstream r("-");
	c.read(r);
	ASSERT_TRUE(!c.isAlive());
}

//write
TEST(Life, FredkinCell_write_alive){
	FredkinCell c(true);
	ostringstream w;
	c.write(w);
	ASSERT_EQ("0", w.str());
}

TEST(Life, FredkinCell_write_dead){
	FredkinCell c(false);
	ostringstream w;
	c.write(w);
	ASSERT_EQ("-", w.str());
}

TEST(Life, FredkinCell_write_age1){
	FredkinCell c(true);
	c.age = 1;
	ostringstream w;
	c.write(w);
	ASSERT_EQ("1", w.str());
}

TEST(Life, FredkinCell_write_age10){
	FredkinCell c(true);
	c.age = 10;
	ostringstream w;
	c.write(w);
	ASSERT_EQ("+", w.str());
}

//constructor
TEST(Life, FredkinCell_constructor_alive){
	FredkinCell c(true);
	ASSERT_TRUE(c.isAlive());
}

TEST(Life, FredkinCell_constructor_dead){
	FredkinCell c(false);
	ASSERT_TRUE(!c.isAlive());
}

//isAlive
TEST(Life, FredkinCell_isAlive){
	FredkinCell c(true);
	ASSERT_TRUE(c.isAlive());
}

TEST(Life, FredkinCell_isNotAlive){
	FredkinCell c(false);
	ASSERT_TRUE(!c.isAlive());
}

//survive
TEST(Life, FredkinCell_survive){
	FredkinCell c(true);
	int oldAge = c.age;
	c.survive();
	ASSERT_TRUE(c.isAlive());
	ASSERT_TRUE(c.age == oldAge+1);
}

//die
TEST(Life, FredkinCell_die){
	FredkinCell c(true);
	int oldAge = c.age;
	c.die();
	ASSERT_TRUE(!c.isAlive());
	ASSERT_TRUE(c.age == oldAge);
	
}

//clone
TEST(Life, FredkinCell_clone_alive){
	FredkinCell c(true);
	FredkinCell* c2p = c.clone();
	FredkinCell& c2 = *c2p;
	ASSERT_TRUE(c.isAlive());
	ASSERT_TRUE(c.age == 0);
	ASSERT_TRUE(c2.isAlive());
	ASSERT_TRUE(c2.age == 0);
	delete c2p;
}

TEST(Life, FredkinCell_clone_dead){
	FredkinCell c(false);
	FredkinCell* c2p = c.clone();
	FredkinCell& c2 = *c2p;
	ASSERT_TRUE(!c.isAlive());
	ASSERT_TRUE(c.age == 0);
	ASSERT_TRUE(!c2.isAlive());
	ASSERT_TRUE(c2.age == 0);
	delete c2p;
}

TEST(Life, FredkinCell_clone_changeState){
	FredkinCell c(true);
	FredkinCell* c2p = c.clone();
	FredkinCell& c2 = *c2p;
	c.die();
	ASSERT_TRUE(!c.isAlive());
	ASSERT_TRUE(c.age == 0);
	ASSERT_TRUE(c2.isAlive());
	ASSERT_TRUE(c2.age == 0);
	delete c2p;
}

TEST(Life, FredkinCell_clone_withAge){
	FredkinCell c(true);
	c.survive();
	FredkinCell* c2p = c.clone();
	FredkinCell& c2 = *c2p;
	ASSERT_TRUE(c.isAlive());
	ASSERT_TRUE(c.age == 1);
	ASSERT_TRUE(c2.isAlive());
	ASSERT_TRUE(c2.age == 1);
	delete c2p;
}

//cellType
TEST(Life, FredkinCell_cellType_alive){
	FredkinCell c(true);
	ASSERT_TRUE('f' == c.cellType());
}

TEST(Life, FredkinCell_cellType_dead){
	FredkinCell c(false);
	ASSERT_TRUE('f' == c.cellType());
}

//getAge
TEST(Life, FredkinCell_getAge_alive){
	FredkinCell c(true);
	ASSERT_EQ(0, c.getAge());
}

TEST(Life, FredkinCell_getAge_dead){
	FredkinCell c(false);
	ASSERT_EQ(0, c.getAge());
}

TEST(Life, FredkinCell_getAge_age1){
	FredkinCell c(true);
	c.age = 1;
	ASSERT_EQ(1, c.getAge());
}

TEST(Life, FredkinCell_getAge_age10){
	FredkinCell c(true);
	c.age = 10;
	ASSERT_EQ(10, c.getAge());
}

// ----
// Cell
// ----

//isAlive
TEST(Life, Cell_isAlive){
	Cell c(new ConwayCell(true));
	ASSERT_TRUE(c.isAlive());
}

TEST(Life, Cell_isNotAlive){
	Cell c(new ConwayCell(false));
	ASSERT_TRUE(!c.isAlive());
}

//survive
TEST(Life, Cell_survive){
	Cell c(new FredkinCell(true));
	int oldAge = c.getAge();
	c.survive();
	ASSERT_TRUE(c.isAlive());
	ASSERT_TRUE(c.getAge() == oldAge+1);
}

//die
TEST(Life, Cell_die){
	Cell c(new FredkinCell(false));
	int oldAge = c.getAge();
	c.die();
	ASSERT_TRUE(!c.isAlive());
	ASSERT_TRUE(c.getAge() == oldAge);
}

//cellType
TEST(Life, Cell_cellType_conway){
	Cell c(new ConwayCell(true));
	ASSERT_TRUE('c' == c.cellType());
}

TEST(Life, Cell_cellType_fredkin){
	Cell c(new FredkinCell(true));
	ASSERT_TRUE('f' == c.cellType());
}

//getAge
TEST(Life, Cell_getAge_conway){
	Cell c(new ConwayCell(true));
	ASSERT_EQ(-1, c.getAge());
}

TEST(Life, Cell_getAge_fredkin){
	Cell c(new FredkinCell(true));
	ASSERT_EQ(0, c.getAge());
}

TEST(Life, Cell_getAge_fredkin2){
	Cell c(new FredkinCell(true));
	c.survive();
	c.survive();
	ASSERT_EQ(2, c.getAge());
}

//mutate
TEST(Life, Cell_mutate){
	Cell c(new FredkinCell(true));
	c.mutate();
	ASSERT_TRUE('c' == c.cellType());
}

// ----
// Life
// ----

//countLiveNeighborsConway
TEST(Life, Life_neighbors_conway) {
	Life<ConwayCell> life(2,2);
	istringstream r("..\n**\n");
	life.life_read(r);

	ASSERT_EQ(2, life.countLiveNeighborsConway(0,0));
	ASSERT_EQ(2, life.countLiveNeighborsConway(0,1));
	ASSERT_EQ(1, life.countLiveNeighborsConway(1,0));
	ASSERT_EQ(1, life.countLiveNeighborsConway(1,1));
}

//countLiveNeighborsFredkin
TEST(Life, Life_neighbors_fredkin) {
	Life<ConwayCell> life(2,2);
	istringstream r("..\n**\n");
	life.life_read(r);

	ASSERT_EQ(1, life.countLiveNeighborsFredkin(0,0));
	ASSERT_EQ(1, life.countLiveNeighborsFredkin(0,1));
	ASSERT_EQ(1, life.countLiveNeighborsFredkin(1,0));
	ASSERT_EQ(1, life.countLiveNeighborsFredkin(1,1));
}


//constructor
TEST(Life, Life_constructor_conway) {
	Life<ConwayCell> life(1,1);
	ASSERT_TRUE(life.rows==1);
	ASSERT_TRUE(life.cols==1);
	ASSERT_TRUE(!life.grid[0][0].isAlive());
}

TEST(Life, Life_constructor_fredkin) {
	Life<FredkinCell> life(1,1);
	ASSERT_TRUE(life.rows==1);
	ASSERT_TRUE(life.cols==1);
	ASSERT_TRUE(!life.grid[0][0].isAlive());
	ASSERT_TRUE(life.grid[0][0].age == 0);
}

TEST(Life, Life_constructor_cell) {
	Life<Cell> life(1,1);
	ASSERT_TRUE(life.rows==1);
	ASSERT_TRUE(life.cols==1);
	ASSERT_TRUE(!life.grid[0][0].isAlive());
}

//life_read
TEST(Life, Life_read_conway) {
	Life<ConwayCell> life(2,2);
	istringstream r("..\n**\n");
	life.life_read(r);
	ASSERT_TRUE(!life.grid[0][0].isAlive());
	ASSERT_TRUE(!life.grid[0][1].isAlive());
	ASSERT_TRUE(life.grid[1][0].isAlive());
	ASSERT_TRUE(life.grid[1][0].isAlive());
}

TEST(Life, Life_read_fredkin) {
	Life<FredkinCell> life(2,2);
	istringstream r("--\n00\n");
	life.life_read(r);
	ASSERT_TRUE(!life.grid[0][0].isAlive());
	ASSERT_TRUE(!life.grid[0][1].isAlive());
	ASSERT_TRUE(life.grid[1][0].isAlive());
	ASSERT_TRUE(life.grid[1][0].isAlive());
}

TEST(Life, Life_read_cell) {
	Life<Cell> life(2,2);
	istringstream r("--\n00\n");
	life.life_read(r);
	ASSERT_TRUE(!life.grid[0][0].isAlive());
	ASSERT_TRUE(!life.grid[0][1].isAlive());
	ASSERT_TRUE(life.grid[1][0].isAlive());
	ASSERT_TRUE(life.grid[1][0].isAlive());
}

//life_print
TEST(Life, Life_print_conway) {
	Life<ConwayCell> life(2,2);
	istringstream r("..\n**\n");
	life.life_read(r);
	
	ostringstream w;
	life.life_print(w);
	ASSERT_EQ("..\n**\n", w.str());
}

TEST(Life, Life_print_fredkin) {
	Life<FredkinCell> life(2,2);
	istringstream r("--\n00\n");
	life.life_read(r);
	
	ostringstream w;
	life.life_print(w);
	ASSERT_EQ("--\n00\n", w.str());
}

TEST(Life, Life_print_cell) {
	Life<Cell> life(2,2);
	istringstream r("--\n00\n");
	life.life_read(r);
	
	ostringstream w;
	life.life_print(w);
	ASSERT_EQ("--\n00\n", w.str());
}

//population
TEST(Life, Life_population_conway) {
	Life<ConwayCell> life(2,2);
	istringstream r("..\n**\n");
	life.life_read(r);
	
	ASSERT_EQ(2, life.population());
}

TEST(Life, Life_population_fredkin) {
	Life<FredkinCell> life(2,2);
	istringstream r("--\n00\n");
	life.life_read(r);
	
	ASSERT_EQ(2, life.population());
}

TEST(Life, Life_population_cell) {
	Life<Cell> life(2,2);
	istringstream r("--\n00\n");
	life.life_read(r);
	
	ASSERT_EQ(2, life.population());
}

//simulate
TEST(Life, Life_simulate_conway) {
	Life<ConwayCell> life(2,2);
	istringstream r("..\n**\n");
	life.life_read(r);

	life.simulate();
	
	ostringstream w;
	life.life_print(w);
	ASSERT_EQ("..\n..\n", w.str());
}

TEST(Life, Life_simulate_fredkin) {
	Life<FredkinCell> life(2,2);
	istringstream r("--\n00\n");
	life.life_read(r);

	life.simulate();
	
	ostringstream w;
	life.life_print(w);
	ASSERT_EQ("00\n11\n", w.str());
}

TEST(Life, Life_simulate_cell) {
	Life<Cell> life(2,2);
	istringstream r("--\n00\n");
	life.life_read(r);

	life.simulate();
	
	ostringstream w;
	life.life_print(w);
	ASSERT_EQ("00\n11\n", w.str());
}

TEST(Life, Life_simulate_cellWithMutation) {
	Life<Cell> life(3,3);
	istringstream r("---\n00-\n---\n");
	life.life_read(r);

	life.simulate();
	life.simulate();
	
	ostringstream w;
	life.life_print(w);
	ASSERT_EQ("---\n*-1\n---\n", w.str());
}

