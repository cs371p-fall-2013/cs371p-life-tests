#include <iostream>
#include <sstream>
#include <string>
#include "gtest/gtest.h"

#include "Life.h"
#include "Cell.h"
#include "AbstractCell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"

//---------------
// Conway Cells
//---------------

TEST(Life, Conway1) {
	ConwayCell con(1,1,1);
	assert(con.alive == true);
	assert(con._x == 1);
	assert(con._y == 1);
}

TEST(Life, Conway2) {
	ConwayCell con(1,1,0);
	assert(con.alive == false);
	assert(con._x == 1);
	assert(con._y == 1);
}

TEST(Life, Conway3) {
	ConwayCell con(2,1,1);
	assert(con.alive == true);
	assert(con._x == 2);
	assert(con._y == 1);
}

TEST(Life, Conway4) {
	ConwayCell con(2,1,0);
	assert(con.alive == false);
	assert(con._x == 2);
	assert(con._y == 1);
}

TEST(Life, Conway5) {
	ConwayCell con(3,1,1);
	assert(con.alive == true);
	assert(con._x == 3);
	assert(con._y == 1);
}

TEST(Life, Conway6) {
	ConwayCell con(3,1,0);
	assert(con.alive == false);
	assert(con._x == 3);
	assert(con._y == 1);
}

TEST(Life, Conway7) {
	ConwayCell con(1,2,1);
	assert(con.alive == true);
	assert(con._x == 1);
	assert(con._y == 2);
}

TEST(Life, Conway8) {
	ConwayCell con(1,3,1);
	assert(con.alive == true);
	assert(con._x == 1);
	assert(con._y == 3);
}

TEST(Life, Conway9) {
	ConwayCell con(1,4,1);
	assert(con.alive == true);
	assert(con._x == 1);
	assert(con._y == 4);
}

TEST(Life, Conway10) {
	ConwayCell con(1,5,1);
	assert(con.alive == true);
	assert(con._x == 1);
	assert(con._y == 5);
}

TEST(Life, Conway11) {
	ConwayCell con(1,6,1);
	assert(con.alive == true);
	assert(con._x == 1);
	assert(con._y == 6);
}
TEST(Life, Conway12) {
	ConwayCell con(1,7,1);
	assert(con.alive == true);
	assert(con._x == 1);
	assert(con._y == 7);
}
TEST(Life, Conway13) {
	ConwayCell con(1,8,1);
	assert(con.alive == true);
	assert(con._x == 1);
	assert(con._y == 8);
}

TEST(Life, Conway14) {
	ConwayCell con(1,15,0);
	assert(con.alive == false);
	assert(con._x == 1);
	assert(con._y == 15);
}

TEST(Life, Conway15) {
	ConwayCell con(25,1,1);
	assert(con.alive == true);
	assert(con._x == 25);
	assert(con._y == 1);
}

TEST(Life, Conway16) {
	ConwayCell con(40,40,1);
	assert(con.alive == true);
	assert(con._x == 40);
	assert(con._y == 40);
}

TEST(Life, Conway17) {
	ConwayCell con(80,90,0);
	assert(con.alive == false);
	assert(con._x == 80);
	assert(con._y == 90);
}

TEST(Life, Conway18) {
	ConwayCell con(12,110,0);
	assert(con.alive == false);
	assert(con._x == 12);
	assert(con._y == 110);
}

TEST(Life, Conway19) {
	ConwayCell con(1000,1000,1);
	assert(con.alive == true);
	assert(con._x == 1000);
	assert(con._y == 1000);
}

TEST(Life, Conway20) {
	ConwayCell con(1000,1,1);
	assert(con.alive == true);
	assert(con._x == 1000);
	assert(con._y == 1);
}

//---------------
// Fredkin Cells
//---------------

TEST(Life, Fredkin1) {
	FredkinCell fred(1,1,1);
	assert(fred.alive==true);
	assert(fred.age == 0);
	assert(fred._x == 1);
	assert(fred._y == 1);
}
TEST(Life, Fredkin2) {
	FredkinCell fred(2,3,1);
	assert(fred.alive==true);
	assert(fred.age == 0);
	assert(fred._x == 2);
	assert(fred._y == 3);
}
TEST(Life, Fredkin3) {
	FredkinCell fred(4,5,1);
	assert(fred.alive==true);
	assert(fred.age == 0);
	assert(fred._x == 4);
	assert(fred._y == 5);
}
TEST(Life, Fredkin4) {
	FredkinCell fred(6,7,1);
	assert(fred.alive==true);
	assert(fred.age == 0);
	assert(fred._x == 6);
	assert(fred._y == 7);
}
TEST(Life, Fredkin5) {
	FredkinCell fred(8,9,1);
	assert(fred.alive==true);
	assert(fred.age == 0);
	assert(fred._x == 8);
	assert(fred._y == 9);
}
TEST(Life, Fredkin6) {
	FredkinCell fred(9,10,1);
	assert(fred.alive==true);
	assert(fred.age == 0);
	assert(fred._x == 9);
	assert(fred._y == 10);
}
TEST(Life, Fredkin7) {
	FredkinCell fred(11,12,1);
	assert(fred.alive==true);
	assert(fred.age == 0);
	assert(fred._x == 11);
	assert(fred._y == 12);
}
TEST(Life, Fredkin8) {
	FredkinCell fred(13,14,1);
	assert(fred.alive==true);
	assert(fred.age == 0);
	assert(fred._x == 13);
	assert(fred._y == 14);
}
TEST(Life, Fredkin9) {
	FredkinCell fred(15,16,1);
	assert(fred.alive==true);
	assert(fred.age == 0);
	assert(fred._x == 15);
	assert(fred._y == 16);
}
TEST(Life, Fredkin10) {
	FredkinCell fred(17,18,1);
	assert(fred.alive==true);
	assert(fred.age == 0);
	assert(fred._x == 17);
	assert(fred._y == 18);
}
TEST(Life, Fredkin11) {
	FredkinCell fred(19,20,1);
	assert(fred.alive==true);
	assert(fred.age == 0);
	assert(fred._x == 19);
	assert(fred._y == 20);
}
TEST(Life, Fredkin12) {
	FredkinCell fred(11,11,0);
	assert(fred.alive==false);
	assert(fred.age == 0);
	assert(fred._x == 11);
	assert(fred._y == 11);
}
TEST(Life, Fredkin13) {
	FredkinCell fred(123,132,1);
	assert(fred.alive==true);
	assert(fred.age == 0);
	assert(fred._x == 123);
	assert(fred._y == 132);
}
TEST(Life, Fredkin14) {
	FredkinCell fred(140,1,1);
	assert(fred.alive==true);
	assert(fred.age == 0);
	assert(fred._x == 140);
	assert(fred._y == 1);
}
TEST(Life, Fredkin15) {
	FredkinCell fred(1,9,0);
	assert(fred.alive==false);
	assert(fred.age == 0);
	assert(fred._x == 1);
	assert(fred._y == 9);
}
TEST(Life, Fredkin16) {
	FredkinCell fred(7,3,1);
	assert(fred.alive==true);
	assert(fred.age == 0);
	assert(fred._x == 7);
	assert(fred._y == 3);
}
TEST(Life, Fredkin17) {
	FredkinCell fred(10000,1,1);
	assert(fred.alive==true);
	assert(fred.age == 0);
	assert(fred._x == 10000);
	assert(fred._y == 1);
}
TEST(Life, Fredkin18) {
	FredkinCell fred(100000,1,1);
	assert(fred.alive==true);
	assert(fred.age == 0);
	assert(fred._x == 100000);
	assert(fred._y == 1);
}
TEST(Life, Fredkin19) {
	FredkinCell fred(1000000,1,1);
	assert(fred.alive==true);
	assert(fred.age == 0);
	assert(fred._x == 1000000);
	assert(fred._y == 1);
}
TEST(Life, Fredkin20) {
	FredkinCell fred(1,10000000,1);
	assert(fred.alive==true);
	assert(fred.age == 0);
	assert(fred._x == 1);
	assert(fred._y == 10000000);
}

TEST(Life, KillFredkin1) {
	FredkinCell fred(1,1,1);
	fred.age = 3;
	FredkinCell answer(1,1,1);
	answer.updateCell(2,2,answer,fred);
	assert(answer.alive == false);
	assert(answer.age == 3);
}

TEST(Life, KillFredkin2) {
	FredkinCell fred(1,1,1);
	fred.age = 1;
	FredkinCell answer(1,1,1);
	answer.updateCell(4,4,answer,fred);
	assert(answer.alive == false);
	assert(answer.age == 1);
}

//---------------
// Cells
//---------------

TEST(Life, Cells1) {
	Cell c(1,1,1);
	assert(c.alive == true);
	assert(c.cAge==0);
	assert(c.conway == false);
	assert(c.aliveC == '0');
	assert(c.deadC == '-');
}
TEST(Life, Cells2) {
	Cell c(300,20,1);
	assert(c.alive == true);
	assert(c.cAge==0);
	assert(c.conway == false);
	assert(c.aliveC == '0');
	assert(c.deadC == '-');
}

TEST(Life, Cells3) {
	Cell c(1,1,0);
	assert(c.alive == false);
	assert(c.cAge==0);
	assert(c.conway == false);
	assert(c.aliveC == '0');
	assert(c.deadC == '-');
}
