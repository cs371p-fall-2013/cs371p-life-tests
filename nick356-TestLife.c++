
// --------
// includes
// --------
//
#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==

#define private public
#define protected public
#include "gtest/gtest.h"
#include "ConwayCell.h"
#include "AbstractCell.h"
#include "FredkinCell.h"
#include "Cell.h"
#include "Life.h"

using namespace std;



TEST(ConwayConstru, construct1){
	ConwayCell h("*");
	assert(h.getStat()=="alive");
	assert(h.getName()=="*");
}

TEST(ConwayConstru, construct2){
	ConwayCell h(".");
	assert(h.getStat()=="dead");
	assert(h.getName()==".");
}

TEST(ConwayConstru, construct3){
	ConwayCell h("fd");
	assert(h.getStat()=="dead");
	assert(h.getName()==".");

}

TEST(ConwayConstru, construct4){
	ConwayCell h;
	assert(h.getStat()=="dead");
	assert(h.getName()==".");
}

TEST(ConwayConstru, construct5){
	ConwayCell h;
	ConwayCell x;
	assert(h.getStat()=="dead" && x.getStat()=="dead");
	assert(h.getName()=="." && x.getName()==".");
}

TEST(ConwayConstru, construct6){
	ConwayCell h;
	ConwayCell x;
	ConwayCell y;
	assert(h.getStat()=="dead" && x.getStat()=="dead" && y.getStat()=="dead");
	assert(h.getName()=="." && x.getName()=="." && y.getName()==".");

}

TEST(FredkinConstru, construct1){
	FredkinCell h("-");
	assert(h.getStat()=="dead");
	assert(h.getName()=="-");

}

TEST(FredkinConstru, construct2){
	FredkinCell h("+");
	assert(h.getStat()=="alive");
	assert(h.getName()=="+");

}

TEST(FredkinConstru, construct3){
	FredkinCell h("0");
	assert(h.getStat()=="alive");
	assert(h.getName()=="0");
}

TEST(FredkinConstru, construct4){
	FredkinCell h("5");
	assert(h.getStat()=="alive");
	assert(h.getName()=="5");
}

TEST(FredkinConstru, construct5){
	FredkinCell h;
	assert(h.getStat()=="dead");
	assert(h.getName()=="-");
}

TEST(FredkinConstru, construct6){
	FredkinCell h;
	FredkinCell x;
	assert(h.getStat()=="dead" && x.getStat()=="dead");
	assert(h.getName()=="-" && x.getName()=="-");
}

TEST(FredkinConstru, construct7){
	FredkinCell h;
	FredkinCell x;
	FredkinCell y;
	assert(h.getStat()=="dead" && x.getStat()=="dead" && y.getStat()=="dead");
	assert(h.getName()=="-" && x.getName()=="-" && y.getName()=="-");
}

TEST(Constatswtch, switch1){
	ConwayCell h("*");
	assert(h.switchStat(1));
}

TEST(Constatswtch, switch2){
	ConwayCell h(".");
	assert(h.switchStat(3));
}

TEST(Constatswtch, switch3){
	ConwayCell h("*");
	assert(!h.switchStat(2));
}

TEST(Constatswtch, switch4){
	ConwayCell h(".");
	assert(!h.switchStat(8));
}

TEST(Fredstatswtch, switch1){
	FredkinCell h("-");
	assert(h.switchStat(1) &&h.switchStat(3));
}

TEST(Fredstatswtch, switch2){
	FredkinCell h("+");
	assert(h.switchStat(0) && h.switchStat(2) && h.switchStat(4));
}

TEST(Fredstatswtch, switch3){
	FredkinCell h("0");
	assert(h.switchStat(0) && h.switchStat(2) && h.switchStat(4));
}

TEST(Fredstatswtch, switch4){
	FredkinCell h("-");
	assert(!h.switchStat(0) && !h.switchStat(2) && !h.switchStat(4));
}

TEST(Fredstatswtch, switch5){
	FredkinCell h("0");
	assert(!h.switchStat(1) && !h.switchStat(3));
}

TEST(Conwayset, set1){
	ConwayCell h;
	h.setState("alive");
	assert(h.getName()=="*");
}

TEST(Conwayset, set2){
	ConwayCell h;
	h.setState("dead");
	assert(h.getName()==".");
}

TEST(Conwayset, set3){
	ConwayCell h;
	h.setState(".");
	assert(h.getStat()=="dead");
}

TEST(Conwayset, set4){
	ConwayCell h;
	h.setState("*");
	assert(h.getStat()=="alive");

}

TEST(Conwayset, set5){
	ConwayCell h;
	h.setState("5");
	assert(h.getStat()=="dead" && h.getName()==".");
}


TEST(Fredkinset, set1){
	FredkinCell h;
	h.setState("alive");
	assert(h.getStat()=="alive" && h.getName()=="0");
}

TEST(Fredkinset, set2){
	FredkinCell h;
	h.setState("0");
	assert(h.getStat()=="alive" && h.getName()=="0");
}

TEST(Fredkinset, set3){
	FredkinCell h;
	h.setState("+");
	assert(h.getStat()=="alive" && h.getName()=="+");
}

TEST(Fredkinset, set4){
	FredkinCell h;
	h.setState("5");
	assert(h.getStat()=="alive" && h.getName()=="5");
}

TEST(Fredkinset, set5){
	FredkinCell h;
	h.setState("-");
	assert(h.getStat()=="dead" && h.getName()=="-");
}

TEST(Fredkinset, set6){
	FredkinCell h;
	h.setState("dead");
	assert(h.getStat()=="dead" && h.getName()=="-");
}

TEST(Conrules, rules1){
	ConwayCell h;
	vector<int> t=h.retrules();
	assert(t[0]==1 && t[1]==2);
}

TEST(Conrules, rules2){
	ConwayCell h;
	vector<int> t=h.retrules();
	assert(t[2]==3 && t[3]==4);
}

TEST(Conrules, rules3){
	ConwayCell h;
	vector<int> t=h.retrules();
	assert(t[4]==6 && t[5]==7);
}

TEST(Conrules, rules4){
	ConwayCell h;
	vector<int> t=h.retrules();
	assert(t[6]==8 && t[7]==9);
}

TEST(Fredrules, rules1){
	FredkinCell h;
	vector<int> t=h.retrules();
	assert(t[0]==2 && t[1]==4);
}

TEST(Fredrules, rules2){
	FredkinCell h;
	vector<int> t=h.retrules();
	assert(t[2]==6 && t[3]==8);
}

TEST(Conclone, clone1){
	ConwayCell h;
	ConwayCell* t=h.clone();
	assert(h.getStat()==(*t).getStat());
	delete t;
}

TEST(Conclone, clone2){
	ConwayCell h;
	ConwayCell* t=h.clone();
	assert(h.getName()==(*t).getName());
	delete t;
}

TEST(Conclone, clone3){
	ConwayCell h;
	ConwayCell* t=h.clone();
	assert(h.getName()==(*t).getName() && h.getStat()==(*t).getStat());
	delete t;
}

TEST(Fredclone, clone1){
	FredkinCell h;
	FredkinCell* t=h.clone();
	assert(h.getStat()==(*t).getStat());
	delete t;
}

TEST(Fredclone, clone2){
	FredkinCell h;
	FredkinCell* t=h.clone();
	assert(h.getName()==(*t).getName());
	delete t;
}

TEST(Fredclone, clone3){
	FredkinCell h;
	FredkinCell* t=h.clone();
	assert(h.getName()==(*t).getName() && h.getStat()==(*t).getStat());
	delete t;
}


TEST(CellConstr, construct1){
	AbstractCell* t = new FredkinCell("-");
	Cell y(t);
	assert(y.getName()=="-" && y.getStat()=="dead");
}


TEST(CellConstr, construct2){
	AbstractCell* t = new FredkinCell("0");
	Cell y(t);
	assert(y.getName()=="0" && y.getStat()=="alive");
}

TEST(CellConstr, construct3){
	AbstractCell* t = new FredkinCell("1");
	Cell y(t);
	assert(y.getName()=="1" && y.getStat()=="alive");
}


TEST(CellConstr, construct4){
	AbstractCell* t = new FredkinCell("0");
	Cell y(t);
	y.setState("alive");
	y.setState("alive");
	assert(y.getName()=="*" && y.getStat()=="alive");
}


TEST(Cellswtch, switch1){
	AbstractCell* t = new FredkinCell("-");
	Cell y(t);
	assert(y.switchStat(1) && y.switchStat(3));
}

TEST(Cellswtch, switch2){
	AbstractCell* t = new FredkinCell("0");
	Cell y(t);
	assert(y.switchStat(0) && y.switchStat(2) && y.switchStat(4));
}

TEST(Cellswtch, switch3){
	AbstractCell* t = new FredkinCell("1");
	Cell y(t);
	assert(y.switchStat(0) && y.switchStat(2) && y.switchStat(4));
}

TEST(Cellswtch, switch4){
	AbstractCell* t = new FredkinCell("-");
	Cell y(t);
	assert(!y.switchStat(0) && !y.switchStat(2) && !y.switchStat(4));
}

TEST(Cellswtch, switch5){
	AbstractCell* t = new FredkinCell("0");
	Cell y(t);
	assert(!y.switchStat(1) && !y.switchStat(3));
}

TEST(Cellswtch, switch6){
	AbstractCell* t = new FredkinCell("1");
	Cell y(t);
	assert(!y.switchStat(1) && !y.switchStat(3));
}

TEST(Cellswtch, switch7){
	AbstractCell* t = new FredkinCell("1");
	Cell y(t);
	y.setState("alive");
	assert(y.switchStat(1) && y.switchStat(4));
}

TEST(Cellswtch, switch8){
	AbstractCell* t = new FredkinCell("1");
	Cell y(t);
	y.setState("alive");
	y.setState("dead");
	assert(y.switchStat(3));
}

TEST(Cellswtch, switch9){
	AbstractCell* t = new FredkinCell("1");
	Cell y(t);
	y.setState("alive");
	y.setState("dead");
	assert(!y.switchStat(2) && !y.switchStat(4));
}

TEST(Cellswtch, switch10){
	AbstractCell* t = new FredkinCell("1");
	Cell y(t);
	y.setState("alive");
	assert(!y.switchStat(3) && !y.switchStat(2));
}

TEST(Cellret, return1){
	AbstractCell* t = new FredkinCell("0");
	Cell y(t);
	vector<int> x=y.retrules();
	assert(x[0]==2 && x[1]==4);
}

TEST(Cellret, return2){
	AbstractCell* t = new FredkinCell("0");
	Cell y(t);
	vector<int> x=y.retrules();
	assert(x[2]==6 && x[3]==8);
}

TEST(Cellret, return3){
	AbstractCell* t = new FredkinCell("1");
	Cell y(t);
	y.setState("alive");
	vector<int> x=y.retrules();
	assert(x[0]==1 && x[1]==2);
}

TEST(Cellret, return4){
	AbstractCell* t = new FredkinCell("1");
	Cell y(t);
	y.setState("alive");
	vector<int> x=y.retrules();
	assert(x[2]==3 && x[3]==4);
}

TEST(Cellret, return5){
	AbstractCell* t = new FredkinCell("1");
	Cell y(t);
	y.setState("alive");
	vector<int> x=y.retrules();
	assert(x[4]==6 && x[5]==7);
}

TEST(Cellret, return6){
	AbstractCell* t = new FredkinCell("1");
	Cell y(t);
	y.setState("alive");
	vector<int> x=y.retrules();
	assert(x[6]==8 && x[7]==9);
}

TEST(CellSet, set1){
	AbstractCell* t = new FredkinCell("-");
	Cell y(t);
	y.setState("alive");
	assert(y.getStat()=="alive" && y.getName()=="0");
}

TEST(CellSet, set2){
	AbstractCell* t = new FredkinCell("0");
	Cell y(t);
	y.setState("alive");
	assert(y.getStat()=="alive" && y.getName()=="1");
}

TEST(CellSet, set3){
	AbstractCell* t = new FredkinCell("1");
	Cell y(t);
	y.setState("alive");
	assert(y.getStat()=="alive" && y.getName()=="*");
}

TEST(CellSet, set4){
	AbstractCell* t = new FredkinCell("0");
	Cell y(t);
	y.setState("dead");
	assert(y.getStat()=="dead" && y.getName()=="-");
}

TEST(CellSet, set5){
	AbstractCell* t = new FredkinCell("1");
	Cell y(t);
	y.setState("alive");
	y.setState("dead");
	assert(y.getStat()=="dead" && y.getName()==".");
}

TEST(CellSet, set6){
	AbstractCell* t = new FredkinCell("1");
	Cell y(t);
	y.setState("alive");
	y.setState("dead");
	y.setState("alive");
	assert(y.getStat()=="alive" && y.getName()=="*");
}

TEST(CellSet, set7){
	AbstractCell* t=new FredkinCell("0");
	Cell y(t);
	assert(y.getStat()=="alive" && y.getName()=="0");
	y.setState("-");
	assert(y.getStat()=="dead" && y.getName()=="-");
}

TEST(CellSet, set8){
	AbstractCell* t=new FredkinCell("-");
	Cell y(t);
	assert(y.getStat()=="dead" && y.getName()=="-");
	y.setState("0");
	assert(y.getStat()=="alive" && y.getName()=="0");

}

TEST(CellSet, set9){
	AbstractCell* t=new FredkinCell("-");
	Cell y(t);
	assert(y.getStat()=="dead" && y.getName()=="-");
	y.setState("1");
	assert(y.getStat()=="alive" && y.getName()=="1");
}

TEST(CellSet, set10){
	AbstractCell* t=new FredkinCell("-");
	Cell y(t);
	assert(y.getStat()=="dead" && y.getName()=="-");
	y.setState("alive");
	assert(y.getStat()=="alive" && y.getName()=="0");
	y.setState("alive");
	assert(y.getStat()=="alive" && y.getName()=="1");
	y.setState("alive");
	assert(y.getStat()=="alive" && y.getName()=="*");
	y.setState("alive");
	assert(y.getStat()=="alive" && y.getName()=="*");
	y.setState("dead");
	assert(y.getStat()=="dead" && y.getName()==".");
	y.setState("*");
	assert(y.getStat()=="alive" && y.getName()=="*");
	y.setState(".");
	assert(y.getStat()=="dead" && y.getName()==".");
}

TEST(Conwayget, get1){
	ConwayCell t;
	assert(t.getStat()=="dead" && t.getName()==".");
}

TEST(Conwayget, get2){
	ConwayCell t(".");
	assert(t.getStat()=="dead" && t.getName()==".");
}

TEST(Conwayget, get3){
	ConwayCell t("*");
	assert(t.getStat()=="alive" && t.getName()=="*");
}

TEST(Fredkinget, get1){
	FredkinCell t;
	assert(t.getStat()=="dead" && t.getName()=="-");
}

TEST(Fredkinget, get2){
	FredkinCell t("-");
	assert(t.getStat()=="dead" && t.getName()=="-");
}

TEST(Fredkinget, get3){
	FredkinCell t("0");
	assert(t.getStat()=="alive" && t.getName()=="0");
}

TEST(Lifecon, construct1){
	Life<FredkinCell> x;
	assert(x.generation()==0 && x.population()==0);
}

TEST(Lifecon, construct2){
	Life<FredkinCell> x(10,10);
	assert(x.getSta(1,1)=="dead");
}

TEST(Lifecon, construct3){
	Life<FredkinCell> x(10,10);
	x.init(1,1,"0");
	assert(x.getSta(1,1)=="alive");
}

TEST(Lifecon,construct4){
	Life<Cell> x;
	assert(x.generation()==0 && x.population()==0);
}

TEST(Lifecon,construct5){
	Life<Cell> x(10,10);
	assert(x.getSta(1,1)=="dead");
}

TEST(Lifecon,construct6){
	Life<Cell> x(10,10);
	x.init(1,1,"0");
	assert(x.getSta(1,1)=="alive");
}

TEST(Lifecon, construct7){
	Life<ConwayCell> x;
	assert(x.generation()==0 && x.population()==0);
}

TEST(Lifecon, construct8){
	Life<ConwayCell> x(10,10);
	assert(x.getSta(1,1)=="dead");
}

TEST(Lifecon, construct9){
	Life<ConwayCell> x(10,10);
	x.init(1,1,"*");
	assert(x.getSta(1,1)=="alive");
}

TEST(Lifegen, generation1){
	Life<ConwayCell> x(10,10);
	x.init(1,1,"*");
	x.init(2,2,"*");
	x.incrementOneGeneration();
	assert(x.population()==0);
}

TEST(Lifegen, generation2){
	Life<ConwayCell> x(10,10);
	x.init(1,1,"*");
	x.init(2,2,"*");
	x.init(1,2,"*");
	x.init(2,1,"*");
	x.incrementOneGeneration();
	assert(x.population()==4 && x.getSta(1,1)=="alive" && x.getSta(2,2)=="alive");
}

TEST(Lifegen, generation3){
	Life<ConwayCell> x(10,10);
	x.init(1,3,"*");
	x.init(1,1,"*");
	x.init(2,2,"*");
	x.init(1,2,"*");
	x.init(2,1,"*");
	x.incrementOneGeneration();
	assert(x.population()==4 && x.getSta(1,2)=="dead" && x.getSta(2,2)=="dead" && x.getSta(1,1)=="alive");
}

TEST(Lifegen, generation4){
	Life<ConwayCell> x(10,10);
	x.init(1,3,"*");
	x.init(1,1,"*");
	x.init(2,2,"*");
	x.init(1,2,"*");
	x.init(2,1,"*");
	x.incrementOneGeneration();
	x.incrementOneGeneration();
	assert(x.population()==0 && x.getSta(1,2)=="dead" && x.getSta(2,2)=="dead" && x.getSta(1,1)=="dead");
}

TEST(Lifegen, generation5){
	Life<FredkinCell> x(10,10);
	x.init(1,1,"0");
	x.init(2,2,"0");
	x.incrementOneGeneration();
	assert(x.population()==2);
}

TEST(Lifegen, generation6){
	Life<FredkinCell> x(10,10);
	x.init(1,1,"0");
	x.init(2,2,"0");
	x.init(1,2,"0");
	x.init(2,1,"0");
	x.incrementOneGeneration();
	assert(x.population()==4 && x.getSta(1,1)=="dead" && x.getSta(2,2)=="dead");
}

TEST(Lifegen, generation7){
	Life<FredkinCell> x(10,10);
	x.init(1,3,"0");
	x.init(1,1,"0");
	x.init(2,2,"0");
	x.init(1,2,"0");
	x.init(2,1,"0");
	x.incrementOneGeneration();
	assert(x.population()==5 && x.getSta(1,2)=="alive" && x.getSta(2,2)=="dead" && x.getSta(1,3)=="alive");
}

TEST(Lifegen, generation8){
	Life<FredkinCell> x(10,10);
	x.init(1,3,"0");
	x.init(1,1,"0");
	x.init(2,2,"0");
	x.init(1,2,"0");
	x.init(2,1,"0");
	x.incrementOneGeneration();
	assert(x.population()==5 && x.getSta(1,2)=="alive" && x.getSta(2,2)=="dead" && x.getSta(1,3)=="alive");
	x.incrementOneGeneration();
	assert(x.population()==12 && x.getSta(1,2)=="alive" && x.getSta(2,2)=="dead" && x.getSta(1,1)=="alive");
}

TEST(Lifegen, generation9){
	Life<Cell> x(10,10);
	x.init(1,1,"1");
	x.init(2,2,"0");
	x.incrementOneGeneration();
	assert(x.population()==2);
}

TEST(Lifegen, generation10){
	Life<Cell> x(10,10);
	x.init(1,1,"1");
	x.init(2,2,"0");
	x.init(1,2,"0");
	x.init(2,1,"0");
	x.incrementOneGeneration();
	assert(x.population()==4 && x.getSta(1,1)=="dead" && x.getSta(2,2)=="dead");
}

TEST(Lifegen, generatio11){
	Life<Cell> x(10,10);
	x.init(1,3,"0");
	x.init(1,1,"1");
	x.init(2,2,"0");
	x.init(1,2,"0");
	x.init(2,1,"0");
	x.incrementOneGeneration();
	assert(x.population()==5 && x.getSta(1,2)=="alive" && x.getSta(2,2)=="dead" && x.getSta(1,3)=="alive");
}

TEST(Lifegen, generation12){
	Life<Cell> x(10,10);
	x.init(1,3,"0");
	x.init(1,1,"1");
	x.init(2,2,"0");
	x.init(1,2,"0");
	x.init(2,1,"0");
	x.incrementOneGeneration();
	assert(x.population()==5 && x.getSta(1,2)=="alive" && x.getSta(2,2)=="dead" && x.getSta(1,3)=="alive");
	x.incrementOneGeneration();
	assert(x.population()==12 && x.getSta(1,2)=="alive" && x.getSta(2,2)=="dead" && x.getSta(1,1)=="alive");
}

TEST(Lifegen, generation13){
	Life<ConwayCell> x(5,5);
	x.init(1,1,"1");
	assert(x.population()==0 && x.getSta(1,1)=="dead");
	x.incrementOneGeneration();
	assert(x.population()==0 && x.getSta(1,1)=="dead");

}

TEST(Lifegen, generation14){
	Life<Cell> x(5,5);
	x.init(1,1,"0");
	x.init(1,2,"0");
	assert(x.population()==2 && x.getSta(1,1)=="alive");
	x.incrementOneGeneration();
	assert(x.population()==5 && x.getSta(1,1)=="alive");
	x.incrementOneGeneration();
	assert(x.getSta(1,1)=="dead");
}

TEST(Lifegen,generation15){
	Life<Cell> x(1,1);
	x.init(1,1,"0");
	x.incrementOneGeneration();
	assert(x.population()==0);
}

TEST(Lifegen, generation16){
	Life<ConwayCell> x(1,1);
	x.init(1,1,"*");
	x.incrementOneGeneration();
	assert(x.population()==0);
}

TEST(Lifegen, generation17){
	Life<FredkinCell> x(3,3);
	x.init(1,1,"0");
	x.init(1,2,"0");
	x.init(1,3,"0");
	x.init(2,1,"0");
	x.init(2,2,"0");
	x.init(2,3,"0");
	x.init(3,1,"0");
	x.init(3,2,"0");
	x.init(3,3,"0");
	x.incrementOneGeneration();
	assert(x.population()==4);
}

TEST(Lifegen, generation18){
	Life<FredkinCell> x(3,3);
	x.init(1,1,"0");
	x.init(1,2,"0");
	x.init(1,3,"0");
	x.init(2,1,"0");
	x.init(2,2,"0");
	x.init(2,3,"0");
	x.init(3,1,"0");
	x.init(3,2,"0");
	x.init(3,3,"0");
	x.incrementOneGeneration();
	x.incrementOneGeneration();
	assert(x.population()==0);
}

TEST(Lifegen,generation19){
	Life<Cell> x(3,3);
	x.init(1,1,"0");
	x.init(1,2,"0");
	x.init(1,3,"0");
	x.init(2,1,"0");
	x.init(2,2,"0");
	x.init(2,3,"0");
	x.init(3,1,"0");
	x.init(3,2,"0");
	x.init(3,3,"0");
	x.incrementOneGeneration();
	x.incrementOneGeneration();
	assert(x.population()==0);	
}
