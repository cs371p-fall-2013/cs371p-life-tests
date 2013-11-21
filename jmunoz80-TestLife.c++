#include <iostream> 
#include <string>
#include <fstream>
#include <sstream>

#include "gtest/gtest.h"

#include "Life.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"

using namespace std;

TEST(Life_Conway, ConwayCell_read) {
	stringstream in;
	in << "2\n2\n**\n**";
        Life<ConwayCell> Clife;
        ASSERT_TRUE(readLife(in, Clife));                
}

TEST(Life_Conway, ConwayCell_read2) {
	stringstream in;
	in << "3\n3\n**.\n**.";
        Life<ConwayCell> Clife;
        ASSERT_TRUE(readLife(in, Clife));                
}

TEST(Life_Conway, ConwayCell_read3) {
	stringstream in;
	in << "2\n10\n**...***..\n***..**...";
        Life<ConwayCell> Clife;
        ASSERT_TRUE(readLife(in, Clife));                
}

TEST(Life_Conway, ConwayCell_live1){
	ConwayCell test(0,0, true);
	ASSERT_TRUE(test.isAlive() == 1);
}

TEST(Life_Conway, ConwayCell_live2){
	ConwayCell test(0,0, false);
	ASSERT_TRUE(test.isAlive() == 0);
}

TEST(Life_Conway, ConwayCell_live3){
	ConwayCell test(10,10, true);
	ASSERT_TRUE(test.isAlive() == 1);
}

TEST(Life_Conway, ConwayCell_getCell1){
	stringstream in;
	in << "2\n2\n*.\n.*";
        Life<ConwayCell> Clife;
        ASSERT_TRUE(readLife(in, Clife));                

	ASSERT_TRUE(Clife.getCell(0,0).isAlive() == 1);
	ASSERT_TRUE(Clife.getCell(1,1).isAlive() == 1);
	ASSERT_TRUE(Clife.getCell(0,1).isAlive() == 0);
	ASSERT_TRUE(Clife.getCell(1,0).isAlive() == 0);
}

TEST(Life_Conway, ConwayCell_getCell2){
	stringstream in;
	in << "3\n3\n...\n...\n...";
        Life<ConwayCell> Clife;
        ASSERT_TRUE(readLife(in, Clife));                

	ASSERT_TRUE(Clife.getCell(0,0).isAlive() == 0);
	ASSERT_TRUE(Clife.getCell(0,1).isAlive() == 0);
	ASSERT_TRUE(Clife.getCell(0,2).isAlive() == 0);
	ASSERT_TRUE(Clife.getCell(1,0).isAlive() == 0);
	ASSERT_TRUE(Clife.getCell(1,1).isAlive() == 0);
	ASSERT_TRUE(Clife.getCell(1,2).isAlive() == 0);
	ASSERT_TRUE(Clife.getCell(2,0).isAlive() == 0);
	ASSERT_TRUE(Clife.getCell(2,1).isAlive() == 0);
	ASSERT_TRUE(Clife.getCell(2,2).isAlive() == 0);
}

TEST(Life_Conway, ConwayCell_getCell3){
	stringstream in;
	in << "3\n3\n*.*\n.*.\n*.*";
        Life<ConwayCell> Clife;
        ASSERT_TRUE(readLife(in, Clife));                

	ASSERT_TRUE(Clife.getCell(0,0).isAlive() == 1);
	ASSERT_TRUE(Clife.getCell(0,1).isAlive() == 0);
	ASSERT_TRUE(Clife.getCell(0,2).isAlive() == 1);
	ASSERT_TRUE(Clife.getCell(1,0).isAlive() == 0);
	ASSERT_TRUE(Clife.getCell(1,1).isAlive() == 1);
	ASSERT_TRUE(Clife.getCell(1,2).isAlive() == 0);
	ASSERT_TRUE(Clife.getCell(2,0).isAlive() == 1);
	ASSERT_TRUE(Clife.getCell(2,1).isAlive() == 0);
	ASSERT_TRUE(Clife.getCell(2,2).isAlive() == 1);
}

TEST(Life_Conway, Flipper){
	stringstream in;
	in << "3\n3\n...\n***\n...";
	Life<ConwayCell> life;
	ASSERT_TRUE(readLife(in, life));
	life.simulate(1,false);
}

TEST(Life_Conway, simulate1){
	stringstream in;
	in << "3\n3\n...\n***\n...";
	Life<ConwayCell> life;
	ASSERT_TRUE(readLife(in, life));
	life.simulate(1,false);
	ASSERT_TRUE(life.getCell(0,0).isAlive() == 0);
	ASSERT_TRUE(life.getCell(0,1).isAlive() == 1);
	ASSERT_TRUE(life.getCell(0,2).isAlive() == 0);
	ASSERT_TRUE(life.getCell(1,0).isAlive() == 0);
	ASSERT_TRUE(life.getCell(1,1).isAlive() == 1);
	ASSERT_TRUE(life.getCell(1,2).isAlive() == 0);
	ASSERT_TRUE(life.getCell(2,0).isAlive() == 0);
	ASSERT_TRUE(life.getCell(2,1).isAlive() == 1);
	ASSERT_TRUE(life.getCell(2,2).isAlive() == 0);
}

TEST(Life_Conway, update){
	stringstream in;
	in << "3\n3\n...\n***\n...";
	Life<ConwayCell> life;
	ASSERT_TRUE(readLife(in, life));
	life.simulate(1,false);

	int count=0, i,j;
	for(i = 0; i< 3; i++){
		for(j =0; j < 3; j++){
			count+=life.getCell(i,j).isAlive();
		}
	}
	ASSERT_TRUE(count == 3);
}

TEST(Life_Fredkin, FredkinCell_std) {
	ifstream fredkinin("RunLifeFredkin.in" , ifstream::in);
        Life<FredkinCell> Flife;
        ASSERT_TRUE(readLife(fredkinin, Flife));
        fredkinin.close();

        int i;
        for(i = 1; i <= 5; i++)
                Flife.simulate(1, false);
}

TEST(Life_Fredkin, FredkinCell_read) {
	stringstream in;
	in << "2\n2\n00\n00";
        Life<FredkinCell> Clife;
        ASSERT_TRUE(readLife(in, Clife));                
}

TEST(Life_Fredkin, FredkinCell_read2) {
	stringstream in;
	in << "3\n3\n00-\n-00\n0-0";
        Life<FredkinCell> Clife;
        ASSERT_TRUE(readLife(in, Clife));                
}

TEST(Life_Fredkin, FredkinCell_read3) {
	stringstream in;
	in << "3\n5\n00-00\n0--00\n0-0-0";
        Life<FredkinCell> Clife;
        ASSERT_TRUE(readLife(in, Clife));                
}

TEST(Life_Fredkin, FredkinCell_live1){
	FredkinCell test(0,0, true);
	ASSERT_TRUE(test.isAlive() == 1);
}

TEST(Life_Fredkin, FredkinCell_live2){
	FredkinCell test(0,0, false);
	ASSERT_TRUE(test.isAlive() == 0);
}

TEST(Life_Fredkin, FredkinCell_live3){
	FredkinCell test(10,10, true);
	ASSERT_TRUE(test.isAlive() == 1);
}

TEST(Life_Fredkin, FredkinCell_getCell1){
	stringstream in;
	in << "2\n2\n0-\n-0";
        Life<FredkinCell> Clife;
        ASSERT_TRUE(readLife(in, Clife));                

	ASSERT_TRUE(Clife.getCell(0,0).isAlive() == 1);
	ASSERT_TRUE(Clife.getCell(1,1).isAlive() == 1);
	ASSERT_TRUE(Clife.getCell(0,1).isAlive() == 0);
	ASSERT_TRUE(Clife.getCell(1,0).isAlive() == 0);
}

TEST(Life_Fredkin, FredkinCell_getCell2){
	stringstream in;
	in << "3\n3\n---\n---\n---";
        Life<FredkinCell> Clife;
        ASSERT_TRUE(readLife(in, Clife));                

	ASSERT_TRUE(Clife.getCell(0,0).isAlive() == 0);
	ASSERT_TRUE(Clife.getCell(0,1).isAlive() == 0);
	ASSERT_TRUE(Clife.getCell(0,2).isAlive() == 0);
	ASSERT_TRUE(Clife.getCell(1,0).isAlive() == 0);
	ASSERT_TRUE(Clife.getCell(1,1).isAlive() == 0);
	ASSERT_TRUE(Clife.getCell(1,2).isAlive() == 0);
	ASSERT_TRUE(Clife.getCell(2,0).isAlive() == 0);
	ASSERT_TRUE(Clife.getCell(2,1).isAlive() == 0);
	ASSERT_TRUE(Clife.getCell(2,2).isAlive() == 0);
}

TEST(Life_Fredkin, FredkinCell_getCell3){
	stringstream in;
	in << "3\n3\n0-0\n-0-\n0-0";
        Life<FredkinCell> Clife;
        ASSERT_TRUE(readLife(in, Clife));                

	ASSERT_TRUE(Clife.getCell(0,0).isAlive() == 1);
	ASSERT_TRUE(Clife.getCell(0,1).isAlive() == 0);
	ASSERT_TRUE(Clife.getCell(0,2).isAlive() == 1);
	ASSERT_TRUE(Clife.getCell(1,0).isAlive() == 0);
	ASSERT_TRUE(Clife.getCell(1,1).isAlive() == 1);
	ASSERT_TRUE(Clife.getCell(1,2).isAlive() == 0);
	ASSERT_TRUE(Clife.getCell(2,0).isAlive() == 1);
	ASSERT_TRUE(Clife.getCell(2,1).isAlive() == 0);
	ASSERT_TRUE(Clife.getCell(2,2).isAlive() == 1);
}

TEST(Life_Fredkin, Flipper){
	stringstream in;
	in << "2\n2\n00\n00";
	Life<FredkinCell> life;
	ASSERT_TRUE(readLife(in, life));
	life.simulate(1,false);
	ASSERT_TRUE(life.getCell(0,0).isAlive() == 0);
	ASSERT_TRUE(life.getCell(0,1).isAlive() == 0);
	ASSERT_TRUE(life.getCell(1,0).isAlive() == 0);
	ASSERT_TRUE(life.getCell(1,1).isAlive() == 0);
}


TEST(Life_Fredkin, simulate){
	stringstream in;
	in << "3\n3\n0-0\n-0-\n0-0";
	Life<FredkinCell> life;
	ASSERT_TRUE(readLife(in, life));
	life.simulate(1,false);
	ASSERT_TRUE(life.getCell(0,0).isAlive() == 0);
	ASSERT_TRUE(life.getCell(0,1).isAlive() == 1);
	ASSERT_TRUE(life.getCell(0,2).isAlive() == 0);
	ASSERT_TRUE(life.getCell(1,0).isAlive() == 1);
	ASSERT_TRUE(life.getCell(1,1).isAlive() == 0);
	ASSERT_TRUE(life.getCell(1,2).isAlive() == 1);
	ASSERT_TRUE(life.getCell(2,0).isAlive() == 0);
	ASSERT_TRUE(life.getCell(2,1).isAlive() == 1);
	ASSERT_TRUE(life.getCell(2,2).isAlive() == 0);
}

TEST(Life_Fredkin, simulate2){
	stringstream in;
	in << "2\n2\n00\n--";
	Life<FredkinCell> life;
	ASSERT_TRUE(readLife(in, life));
	life.simulate(1,false);
	ASSERT_TRUE(life.getCell(0,0).isAlive() == 1);
	ASSERT_TRUE(life.getCell(0,1).isAlive() == 1);
	ASSERT_TRUE(life.getCell(1,0).isAlive() == 1);
	ASSERT_TRUE(life.getCell(1,1).isAlive() == 1);
}

TEST(Life_Fredkin, simulate3){
	stringstream in;
	in << "2\n2\n00\n--";
	Life<FredkinCell> life;
	ASSERT_TRUE(readLife(in, life));
	life.simulate(2,false);
	ASSERT_TRUE(life.getCell(0,0).isAlive() == 0);
	ASSERT_TRUE(life.getCell(0,1).isAlive() == 0);
	ASSERT_TRUE(life.getCell(1,0).isAlive() == 0);
	ASSERT_TRUE(life.getCell(1,1).isAlive() == 0);
}

TEST(Life_Cell, Cell_std) {

	ifstream Cellin("RunLifeCell.in" , ifstream::in);
        Life<Cell> Cell_life;
        ASSERT_TRUE(readLife(Cellin, Cell_life));
        Cellin.close();

        int i;
        for(i = 1; i <= 5; i++)
                Cell_life.simulate(1, false);
}

TEST(Life_Cell, Cell_read) {
	stringstream in;
	in << "2\n2\n00\n00";
        Life<Cell> Clife;
        ASSERT_TRUE(readLife(in, Clife));                
}

TEST(Life_Cell, Cell_live1){
	Cell test(0,0, true);
	ASSERT_TRUE(test.isAlive() == 1);
}

TEST(Life_Cell, Cell_live2){
	Cell test(0,0, false);
	ASSERT_TRUE(test.isAlive() == 0);
}

TEST(Life_Cell, Cell_live3){
	Cell test(10,10, true);
	ASSERT_TRUE(test.isAlive() == 1);
}

TEST(Life_Cell, Cell_getCell1){
	stringstream in;
	in << "2\n2\n0-\n-0";
        Life<Cell> Clife;
        ASSERT_TRUE(readLife(in, Clife));                

	ASSERT_TRUE(Clife.getCell(0,0).isAlive() == 1);
	ASSERT_TRUE(Clife.getCell(1,1).isAlive() == 1);
	ASSERT_TRUE(Clife.getCell(0,1).isAlive() == 0);
	ASSERT_TRUE(Clife.getCell(1,0).isAlive() == 0);
}

TEST(Life_Cell, Cell_getCell2){
	stringstream in;
	in << "3\n3\n---\n---\n---";
        Life<Cell> Clife;
        ASSERT_TRUE(readLife(in, Clife));                

	ASSERT_TRUE(Clife.getCell(0,0).isAlive() == 0);
	ASSERT_TRUE(Clife.getCell(0,1).isAlive() == 0);
	ASSERT_TRUE(Clife.getCell(0,2).isAlive() == 0);
	ASSERT_TRUE(Clife.getCell(1,0).isAlive() == 0);
	ASSERT_TRUE(Clife.getCell(1,1).isAlive() == 0);
	ASSERT_TRUE(Clife.getCell(1,2).isAlive() == 0);
	ASSERT_TRUE(Clife.getCell(2,0).isAlive() == 0);
	ASSERT_TRUE(Clife.getCell(2,1).isAlive() == 0);
	ASSERT_TRUE(Clife.getCell(2,2).isAlive() == 0);
}

TEST(Life_Cell, Cell_getCell3){
	stringstream in;
	in << "3\n3\n0-0\n-0-\n0-0";
        Life<Cell> Clife;
        ASSERT_TRUE(readLife(in, Clife));                

	ASSERT_TRUE(Clife.getCell(0,0).isAlive() == 1);
	ASSERT_TRUE(Clife.getCell(0,1).isAlive() == 0);
	ASSERT_TRUE(Clife.getCell(0,2).isAlive() == 1);
	ASSERT_TRUE(Clife.getCell(1,0).isAlive() == 0);
	ASSERT_TRUE(Clife.getCell(1,1).isAlive() == 1);
	ASSERT_TRUE(Clife.getCell(1,2).isAlive() == 0);
	ASSERT_TRUE(Clife.getCell(2,0).isAlive() == 1);
	ASSERT_TRUE(Clife.getCell(2,1).isAlive() == 0);
	ASSERT_TRUE(Clife.getCell(2,2).isAlive() == 1);
}

TEST(Life_Cell, Flipper){
	stringstream in;
	in << "2\n2\n00\n00";
	Life<Cell> life;
	ASSERT_TRUE(readLife(in, life));
	life.simulate(1,false);
}

TEST(Life_Cell, update){
	stringstream in;
	in << "10\n5\n0----\n-0---\n--0--\n---0-\n----0\n----0\n---0-\n--0--\n-0---\n0----";
	Life<Cell> life;
	ASSERT_TRUE(readLife(in, life));
	life.simulate(2,false);
	int count=0, i,j;
	for(i = 0; i< 10; i++){
		for(j =0; j < 5; j++){
			count+=life.getCell(i,j).isAlive();
		}
	}
	ASSERT_TRUE(count == 6);
}

TEST(Life_Cell, update2){
	stringstream in;
	in << "2\n2\n00\n--";
	Life<Cell> life;
	ASSERT_TRUE(readLife(in, life));
	life.simulate(1,false);
	int count=0, i,j;
	for(i = 0; i< 2; i++){
		for(j =0; j < 2; j++){
			count+=life.getCell(i,j).isAlive();
		}
	}
	ASSERT_TRUE(count == 4);
}

TEST(Life_Cell, update3){
	stringstream in;
	in << "3\n3\n0-0\n-0-\n0-0";
        Life<Cell> Clife;
        ASSERT_TRUE(readLife(in, Clife));                
	Clife.simulate(1,false);
	int count=0, i,j;
	for(i = 0; i< 3; i++){
		for(j =0; j < 3; j++){
			count+=Clife.getCell(i,j).isAlive();
		}
	}
	ASSERT_TRUE(count == 4);
}

TEST(Life_Cell, simulate){
	stringstream in;
	in << "3\n3\n0-0\n-0-\n0-0";
	Life<Cell> life;
	ASSERT_TRUE(readLife(in, life));
	life.simulate(1,false);
	ASSERT_TRUE(life.getCell(0,0).isAlive() == 0);
	ASSERT_TRUE(life.getCell(0,1).isAlive() == 1);
	ASSERT_TRUE(life.getCell(0,2).isAlive() == 0);
	ASSERT_TRUE(life.getCell(1,0).isAlive() == 1);
	ASSERT_TRUE(life.getCell(1,1).isAlive() == 0);
	ASSERT_TRUE(life.getCell(1,2).isAlive() == 1);
	ASSERT_TRUE(life.getCell(2,0).isAlive() == 0);
	ASSERT_TRUE(life.getCell(2,1).isAlive() == 1);
	ASSERT_TRUE(life.getCell(2,2).isAlive() == 0);
}

TEST(Life_Cell, simulate2){
	stringstream in;
	in << "10\n5\n0----\n-0---\n--0--\n---0-\n----0\n----0\n---0-\n--0--\n-0---\n0----";
	Life<Cell> life;
	ASSERT_TRUE(readLife(in, life));
	life.simulate(2,false);
	ASSERT_TRUE(life.getCell(3,4).isAlive() == 1);
	ASSERT_TRUE(life.getCell(4,3).isAlive() == 1);
	ASSERT_TRUE(life.getCell(4,4).isAlive() == 1);
	ASSERT_TRUE(life.getCell(5,3).isAlive() == 1);
	ASSERT_TRUE(life.getCell(5,4).isAlive() == 1);
	ASSERT_TRUE(life.getCell(6,4).isAlive() == 1);
}
