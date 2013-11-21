#include <algorithm> // count
#include <cassert>  // assert
#include <iostream> // endl, istream, ostream 
#include <vector>
#include <string>
#include <stdexcept>

#include "gtest/gtest.h"
#define private public
#define protected public
#include "Life.h"
#include "AbstractCell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"

using namespace std;

//------------------
//AbstractCell Tests
//------------------
TEST(TestLifeAC, AbstractCell_1){
	ConwayCell temp;
	ASSERT_TRUE(!temp.isAlive());
}

TEST(TestLifeAC, AbstractCell_2){
	FredkinCell temp;
	ASSERT_TRUE(!temp.isAlive());
}

TEST(TestLifeAC, isAlive_1){
	ConwayCell temp;
	ASSERT_TRUE(!temp.isAlive());
}

TEST(TestLifeAC, isAlive_2){
	FredkinCell temp;
	ASSERT_TRUE(!temp.isAlive());
}

TEST(TestLifeAC, isAlive_3){
	Cell temp;
	ASSERT_TRUE(!temp.isAlive());
}

TEST(TestLifeAC, isAlive_4){
	ConwayCell temp;
	temp.flipAlive();
	ASSERT_TRUE(temp.isAlive());
}

TEST(TestLifeAC, isAlive_5){
	FredkinCell temp;
	temp.flipAlive();
	ASSERT_TRUE(temp.isAlive());
}

TEST(TestLifeAC, isAlive_6){
	Cell temp;
	temp.flipAlive();
	ASSERT_TRUE(temp.isAlive());
}

TEST(TestLifeAC, flipAlive_1){
	ConwayCell temp;
	ASSERT_TRUE(!temp.isAlive());
	temp.flipAlive();
	ASSERT_TRUE(temp.isAlive());
}

TEST(TestLifeAC, flipAlive_2){
	FredkinCell temp;
	ASSERT_TRUE(!temp.isAlive());
	temp.flipAlive();
	ASSERT_TRUE(temp.isAlive());
}

TEST(TestLifeAC, flipAlive_3){
	Cell temp;
	ASSERT_TRUE(!temp.isAlive());
	temp.flipAlive();
	ASSERT_TRUE(temp.isAlive());
}

//------------------
//ConwayCell Tests
//------------------
TEST(TestLifeCC, ConwayCell_1){
	ConwayCell temp;
	ASSERT_TRUE(!temp.isAlive());
}

TEST(TestLifeCC, print_1){
	ostringstream w;
	ConwayCell temp;
	temp.print(w);
	ASSERT_TRUE(w.str() == ".");
}

TEST(TestLifeCC, print_2){
	ostringstream w;
	ConwayCell temp;
	temp.flipAlive();
	temp.print(w);
	ASSERT_TRUE(w.str() == "*");
}

TEST(TestLifeCC, action_1){
	ostringstream w;
	ConwayCell temp;
	pair<int, int> neighbors= make_pair(2, 0);
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == ".");
}

TEST(TestLifeCC, action_2){
	ostringstream w;
	ConwayCell temp;
	pair<int, int> neighbors= make_pair(2, 2);
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == ".");
}

TEST(TestLifeCC, action_3){
	ostringstream w;
	ConwayCell temp;
	pair<int, int> neighbors= make_pair(1, 2);
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == "*");
}

TEST(TestLifeCC, action_4){
	ostringstream w;
	ConwayCell temp;
	temp.flipAlive(); //alive
	pair<int, int> neighbors= make_pair(1, 2);
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == "*");
}

TEST(TestLifeCC, action_5){
	ostringstream w;
	ConwayCell temp;
	temp.flipAlive(); //alive
	pair<int, int> neighbors= make_pair(0, 2);
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == "*");
}

TEST(TestLifeCC, action_6){
	ostringstream w;
	ConwayCell temp;
	temp.flipAlive(); //alive
	pair<int, int> neighbors= make_pair(4, 2);
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == ".");
}

TEST(TestLifeCC, action_7){
	ostringstream w;
	ConwayCell temp;
	pair<int, int> neighbors= make_pair(4, 2);
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == ".");
}

TEST(TestLifeCC, action_8){
	ostringstream w;
	ConwayCell temp;
	pair<int, int> neighbors= make_pair(3, 0);
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == "*");
}

TEST(TestLifeCC, getAge_1){
	ConwayCell temp;
	ASSERT_TRUE(temp.getAge() == -1);
}

TEST(TestLifeCC, getAge_2){
	ConwayCell temp;
	pair<int, int> neighbors= make_pair(3, 0);
	temp.action(neighbors);
	ASSERT_TRUE(temp.getAge() == -1);
}

TEST(TestLifeCC, getAge_3){
	ConwayCell temp;
	temp.flipAlive();
	pair<int, int> neighbors= make_pair(3, 0);
	temp.action(neighbors);
	ASSERT_TRUE(temp.getAge() == -1);
}

TEST(TestLifeCC, clone_1){
	ConwayCell temp;
	ConwayCell* cloneTemp = temp.clone();
	ASSERT_TRUE(temp.isAlive() == (*cloneTemp).isAlive());
	delete cloneTemp;
}

TEST(TestLifeCC, clone_2){
	ConwayCell temp;
	temp.flipAlive();
	ConwayCell* cloneTemp = temp.clone();
	ASSERT_TRUE(temp.isAlive() == (*cloneTemp).isAlive());
	delete cloneTemp;
}

TEST(TestLifeCC, clone_3){
	ConwayCell temp;
	ConwayCell* cloneTemp = temp.clone();
	temp.flipAlive();
	ASSERT_TRUE(temp.isAlive() != (*cloneTemp).isAlive());
	delete cloneTemp;
}

TEST(TestLifeCC, clone_4){
	ConwayCell temp;
	ConwayCell* cloneTemp = temp.clone();
	(*cloneTemp).flipAlive();
	ASSERT_TRUE(temp.isAlive() != (*cloneTemp).isAlive());
	delete cloneTemp;
}

//------------------
//FredkinCell Tests
//------------------
TEST(TestLifeFC, FredkinCell_1){
	FredkinCell temp;
	ASSERT_TRUE(!temp.isAlive());
}

TEST(TestLifeFC, FredkinCell_2){
	FredkinCell temp;
	ASSERT_TRUE(temp.getAge() == 0);
}

TEST(TestLifeFC, print_1){
	ostringstream w;
	FredkinCell temp;
	temp.print(w);
	ASSERT_TRUE(w.str() == "-");
}

TEST(TestLifeFC, print_2){
	ostringstream w;
	FredkinCell temp;
	temp.flipAlive();
	temp.print(w);
	ASSERT_TRUE(w.str() == "0");
}

TEST(TestLifeFC, print_3){
	ostringstream w;
	FredkinCell temp;
	temp.flipAlive();
	pair<int, int> neighbors= make_pair(3, 0);
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == "1");
}

TEST(TestLifeFC, action_1){
	ostringstream w;
	FredkinCell temp; 
	pair<int, int> neighbors = make_pair(2, 0);
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == "-");
}

TEST(TestLifeFC, action_2){
	ostringstream w;
	FredkinCell temp;
	pair<int, int> neighbors = make_pair(3, 0);
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == "0");
}

TEST(TestLifeFC, action_3){
	ostringstream w;
	FredkinCell temp;
	pair<int, int> neighbors= make_pair(1, 0);
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == "0");
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == "01");
}

TEST(TestLifeFC, action_4){
	ostringstream w;
	FredkinCell temp;
	temp.flipAlive(); //alive
	pair<int, int> neighbors = make_pair(1, 0);
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == "1");
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == "12");
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == "123");
}

TEST(TestLifeFC, action_5){
	ostringstream w;
	FredkinCell temp;
	temp.flipAlive(); //alive
	pair<int, int> neighbors = make_pair(4, 0);
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == "-");
}

TEST(TestLifeFC, action_6){
	ostringstream w;
	FredkinCell temp;
	temp.flipAlive(); //alive
	pair<int, int> neighbors= make_pair(4, 0);
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == "-");
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == "--");
}

TEST(TestLifeFC, action_7){
	ostringstream w;
	FredkinCell temp;
	pair<int, int> neighbors = make_pair(1, 0);
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == "0");
	neighbors= make_pair(2, 0);
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == "0-");
}

TEST(TestLifeFC, action_8){
	ostringstream w;
	FredkinCell temp;
	temp.flipAlive(); //alive
	pair<int, int> neighbors = make_pair(1, 0);
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == "1");
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == "12");
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == "123");
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == "1234");
	neighbors= make_pair(2, 0);
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == "1234-");
}

TEST(TestLifeFC, getAge_1){
	FredkinCell temp;
	ASSERT_TRUE(temp.getAge() == 0);
}

TEST(TestLifeFC, getAge_2){
	FredkinCell temp;
	pair<int, int> neighbors= make_pair(3, 0);
	temp.action(neighbors);
	ASSERT_TRUE(temp.getAge() == 0);
	temp.action(neighbors);
	ASSERT_TRUE(temp.getAge() == 1);
}

TEST(TestLifeFC, getAge_3){
	FredkinCell temp;
	pair<int, int> neighbors= make_pair(3, 0);
	temp.action(neighbors);
	ASSERT_TRUE(temp.getAge() == 0);
	temp.action(neighbors);
	ASSERT_TRUE(temp.getAge() == 1);
	neighbors = make_pair(2, 0);
	temp.action(neighbors);
	ASSERT_TRUE(temp.getAge() == 1);
}

TEST(TestLifeFC, getAge_4){
	FredkinCell temp;
	pair<int, int> neighbors= make_pair(3, 0);
	temp.action(neighbors);
	ASSERT_TRUE(temp.getAge() == 0);
	temp.action(neighbors);
	ASSERT_TRUE(temp.getAge() == 1);
	neighbors = make_pair(4, 0);
	temp.action(neighbors);
	ASSERT_TRUE(temp.getAge() == 1);
	neighbors = make_pair(3, 0);
	temp.action(neighbors);
	ASSERT_TRUE(temp.getAge() == 1);
	neighbors = make_pair(3, 0);
	temp.action(neighbors);
	ASSERT_TRUE(temp.getAge() == 2);
}

TEST(TestLifeFC, clone_1){
	FredkinCell temp;
	FredkinCell* cloneTemp = temp.clone();
	ASSERT_TRUE(temp.isAlive() == (*cloneTemp).isAlive());
	delete cloneTemp;
}

TEST(TestLifeFC, clone_2){
	FredkinCell temp;
	temp.flipAlive();
	FredkinCell* cloneTemp = temp.clone();
	ASSERT_TRUE(temp.isAlive() == (*cloneTemp).isAlive());
	delete cloneTemp;
}

TEST(TestLifeFC, clone_3){
	FredkinCell temp;
	FredkinCell* cloneTemp = temp.clone();
	temp.flipAlive();
	ASSERT_TRUE(temp.isAlive() != (*cloneTemp).isAlive());
	delete cloneTemp;
}

TEST(TestLifeFC, clone_4){
	FredkinCell temp;
	FredkinCell* cloneTemp = temp.clone();
	(*cloneTemp).flipAlive();
	ASSERT_TRUE(temp.isAlive() != (*cloneTemp).isAlive());
	delete cloneTemp;
}

//----------
//Cell Tests
//----------
TEST(TestLifeC, Cell_1){
	Cell temp;
	ASSERT_TRUE(!temp.isAlive());
}

TEST(TestLifeC, print_1){
	ostringstream w;
	Cell temp;
	temp.print(w);
	ASSERT_TRUE(w.str() == "-");
}

TEST(TestLifeC, print_2){
	ostringstream w;
	Cell temp;
	temp.flipAlive();
	temp.print(w);
	ASSERT_TRUE(w.str() == "0");
}

TEST(TestLifeC, print_3){
	ostringstream w;
	Cell temp;
	temp.flipAlive();
	pair<int, int> neighbors= make_pair(3, 0);
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == "1");
}

TEST(TestLifeC, flipAlive_1){
	Cell temp;
	temp.flipAlive();
	ASSERT_TRUE(temp.isAlive());
}

TEST(TestLifeC, flipAlive_2){
	Cell temp;
	temp.flipAlive();
	temp.flipAlive();
	ASSERT_TRUE(!temp.isAlive());
}

TEST(TestLifeC, isAlive_1){
	Cell temp;
	temp.flipAlive();
	temp.flipAlive();
	ASSERT_TRUE(!temp.isAlive());
}


TEST(TestLifeC, isAlive_2){
	Cell temp;
	temp.flipAlive();
	ASSERT_TRUE(temp.isAlive());
}

TEST(TestLifeC, isAlive_3){
	Cell temp;
	pair<int, int> neighbors = make_pair(3, 0);
	temp.action(neighbors);
	ASSERT_TRUE(temp.isAlive());
}

TEST(TestLifeC, isAlive_4){
	Cell temp;
	pair<int, int> neighbors = make_pair(3, 0);
	temp.action(neighbors);
	neighbors= make_pair(2, 0);
	temp.action(neighbors);
	ASSERT_TRUE(!temp.isAlive());
}

TEST(TestLifeC, action_1){
	ostringstream w;
	Cell temp;
	pair<int, int> neighbors = make_pair(3, 0);
	temp.action(neighbors);
	neighbors = make_pair(2, 0);
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == "-");
}

TEST(TestLifeC, action_2){
	ostringstream w;
	Cell temp;
	pair<int, int> neighbors = make_pair(3, 0);
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == "0");
}

TEST(TestLifeC, action_3){
	ostringstream w;
	Cell temp;
	pair<int, int> neighbors = make_pair(1, 0);
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == "0");
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == "01");
}

TEST(TestLifeC, action_4){
	ostringstream w;
	Cell temp;
	temp.flipAlive(); //alive
	pair<int, int> neighbors = make_pair(1, 0);
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == "1");
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == "1*");
}

TEST(TestLifeC, action_5){
	ostringstream w;
	Cell temp;
	temp.flipAlive(); //alive
	pair<int, int> neighbors = make_pair(4, 0);
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == "-");
}

TEST(TestLifeC, action_6){
	ostringstream w;
	Cell temp;
	temp.flipAlive(); //alive
	pair<int, int> neighbors= make_pair(4, 0);
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == "-");
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == "--");
}

TEST(TestLifeC, action_7){
	ostringstream w;
	Cell temp;
	pair<int, int> neighbors = make_pair(1, 0);
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == "0");
	neighbors= make_pair(2, 0);
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == "0-");
}

TEST(TestLifeC, action_8){
	ostringstream w;
	Cell temp;
	temp.flipAlive(); //alive
	pair<int, int> neighbors = make_pair(1, 0);
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == "1");
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == "1*");
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == "1*.");
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == "1*..");
	neighbors= make_pair(2, 1);
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == "1*..*");
}

TEST(TestLifeC, action_9){
	ostringstream w;
	Cell temp;
	temp.flipAlive(); //alive
	pair<int, int> neighbors = make_pair(1, 0);
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == "1");
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == "1*");
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == "1*.");
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == "1*..");
	neighbors= make_pair(2, 1);
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == "1*..*");
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == "1*..**");
}

TEST(TestLifeC, action_10){
	ostringstream w;
	Cell temp;
	temp.flipAlive(); //alive
	pair<int, int> neighbors = make_pair(1, 0);
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == "1");
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == "1*");
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == "1*.");
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == "1*..");
	neighbors= make_pair(2, 1);
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == "1*..*");
	neighbors = make_pair(1, 0);
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == "1*..*.");
}

TEST(TestLifeC, mutate_1){
	ostringstream w;
	Cell temp;
	temp.print(w);
	ASSERT_TRUE(w.str() == "-");
	temp.mutate();
	temp.print(w);
	ASSERT_TRUE(w.str() == "-*");
}

TEST(TestLifeC, mutate_2){
	ostringstream w;
	Cell temp;
	temp.print(w);
	ASSERT_TRUE(w.str() == "-");
	pair<int, int> neighbors = make_pair(1, 0);
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == "-0");
	temp.mutate();
	temp.print(w);
	ASSERT_TRUE(w.str() == "-0*");
}

TEST(TestLifeC, mutate_3){
	ostringstream w;
	Cell temp;
	temp.print(w);
	ASSERT_TRUE(w.str() == "-");
	pair<int, int> neighbors = make_pair(1, 0);
	temp.action(neighbors);
	temp.print(w);
	ASSERT_TRUE(w.str() == "-0");
	neighbors = make_pair(1, 0);
	temp.action(neighbors);
	temp.print(w);
	temp.mutate();
	temp.print(w);
	ASSERT_TRUE(w.str() == "-01*");
}

//----------
//Life Tests
//----------
TEST(TestLifeL, Life_1){
	Life<ConwayCell> temp (10, 11);
	ASSERT_TRUE(temp.height == 10);
	ASSERT_TRUE(temp.width == 11);
	ASSERT_TRUE(temp.gen == 0);
}

TEST(TestLifeL, Life_2){
	Life<ConwayCell> temp (15, 100);
	ASSERT_TRUE(temp.height == 15);
	ASSERT_TRUE(temp.width == 100);
	ASSERT_TRUE(temp.gen == 0);
}

TEST(TestLifeL, Life_3){
	Life<ConwayCell> temp (15, 60);
	ASSERT_TRUE(temp.height == 15);
	ASSERT_TRUE(temp.width == 60);
	ASSERT_TRUE(temp.gen == 0);
}

TEST(TestLifeL, print_1){
	stringstream w;
	Life<ConwayCell> temp (2, 2);
	temp.print(w);
	ASSERT_TRUE(w.str() == "Generation = 0, Population = 0.\n..\n..\n");
}

TEST(TestLifeL, print_2){
	stringstream w;
	Life<FredkinCell> temp (2, 2);
	temp.print(w);
	ASSERT_TRUE(w.str() == "Generation = 0, Population = 0.\n--\n--\n");
}

TEST(TestLifeL, print_3){
	stringstream w;
	Life<Cell> temp (2, 2);
	temp.print(w);
	ASSERT_TRUE(w.str() == "Generation = 0, Population = 0.\n--\n--\n");
}

TEST(TestLifeL, print_4){
	istringstream r("\n..\n.*\n");
	stringstream w;
	Life<ConwayCell> temp (2, 2);
	temp.readInput(r);
	temp.print(w);
	ASSERT_TRUE(w.str() == "Generation = 0, Population = 1.\n..\n.*\n");
}

TEST(TestLifeL, print_5){
	istringstream r("\n-0\n--\n");
	stringstream w;
	Life<FredkinCell> temp (2, 2);
	temp.readInput(r);
	temp.print(w);
	ASSERT_TRUE(w.str() == "Generation = 0, Population = 1.\n-0\n--\n");
}

TEST(TestLifeL, population_1){
	istringstream r ("\n***\n***");
	stringstream w;
	Life<ConwayCell> temp (2, 3);
	temp.readInput(r);
	temp.print(w);
	ASSERT_TRUE(temp.population() == 6);
}

TEST(TestLifeL, population_2){
	istringstream r ("\n*.*\n.**");
	stringstream w;
	Life<ConwayCell> temp (2, 3);
	temp.readInput(r);
	temp.run();
	temp.print(w);
	ASSERT_TRUE(temp.population() == 3);
}

TEST(TestLifeL, population_3){
	istringstream r ("\n0-0\n-00");
	stringstream w;
	Life<FredkinCell> temp (2, 3);
	temp.readInput(r);
	temp.run();
	temp.print(w);
	ASSERT_TRUE(temp.population() == 3);
}

TEST(TestLifeL, population_4){
	istringstream r ("\n0-0\n-00\n-0-");
	stringstream w;
	Life<FredkinCell> temp (3, 3);
	temp.readInput(r);
	ASSERT_TRUE(temp.population() == 5);
	temp.run();
	ASSERT_TRUE(temp.population() == 4);
	temp.run();
	temp.print(w);
	ASSERT_TRUE(temp.population() == 8);
}

TEST(TestLifeL, population_5){
	istringstream r ("\n0-0\n-00\n-0-");
	stringstream w;
	Life<Cell> temp (3, 3);
	temp.readInput(r);
	ASSERT_TRUE(temp.population() == 5);
	temp.run();
	ASSERT_TRUE(temp.population() == 4);
	temp.run();
	temp.run();
	temp.print(w);
	ASSERT_TRUE(temp.population() == 1);
}

TEST(TestLifeL, run_1){
	istringstream r ("\n0-0\n-00\n-0-");
	stringstream w;
	Life<Cell> temp (3, 3);
	temp.readInput(r);
	temp.run();
	temp.print(w);
	ASSERT_TRUE(w.str() == "Generation = 1, Population = 4.\n-01\n---\n01-\n");
}

TEST(TestLifeL, run_2){
	istringstream r ("\n0-0\n-00\n-0-");
	stringstream w;
	Life<Cell> temp (3, 3);
	temp.readInput(r);
	temp.run();
	temp.run();
	temp.print(w);
	ASSERT_TRUE(w.str() == "Generation = 2, Population = 8.\n01*\n0-0\n1*0\n");
}

TEST(TestLifeL, run_3){
	istringstream r ("\n0--\n-00\n---");
	stringstream w;
	Life<Cell> temp (3, 3);
	temp.readInput(r);
	temp.run();
	temp.print(w);
	ASSERT_TRUE(w.str() == "Generation = 1, Population = 5.\n--0\n-11\n-00\n");
}

TEST(TestLifeL, run_4){
	istringstream r("\n*--\n-**\n**-");
	stringstream w;
	Life<ConwayCell> temp (3, 3);
	temp.readInput(r);
	temp.run();
	temp.print(w);
	ASSERT_TRUE(w.str() == "Generation = 1, Population = 5.\n.*.\n..*\n***\n");
}