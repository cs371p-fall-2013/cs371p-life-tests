// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==

#include "gtest/gtest.h"



#define private public
#define protected public
#include "Life.h"
 #include "ConwayCell.h"
 #include "FredkinCell.h"
 #include "AbstractCell.h"
 #include "Cell.h"
using namespace std;

// -----------
// TestLife
// -----------

// ----
// Life
// ----


// Tests that Dead conway cell lives if there's 3 live neighbors.
TEST(Life, runGame) {
   Life<ConwayCell> game(3, 4, "..*.\n...*\n..*.");
  // game.display(0);
   ASSERT_TRUE(!game.grid[2][3].isAlive());
   game.runGame();
  // game.display(1);
   ASSERT_TRUE(game.grid[2][3].isAlive());
   /*
     ..*.
	 ...*
	 ..*.
   */
}

TEST(Life, runGame2) {
   Life<ConwayCell> game(3, 4, "..*.\n...*\n..*.");
   ASSERT_TRUE(game.grid[2][4].isAlive());
   game.runGame();
   ASSERT_TRUE(game.grid[2][4].isAlive());

   /*
     ..*.
	 ...*
	 ..*.
   */
}

// Corner case, literally
TEST(Life, runGame3) {
   Life<ConwayCell> game(3, 4, "....\n..**\n..*.");
   ASSERT_TRUE(!game.grid[3][4].isAlive());
   game.runGame();
   ASSERT_TRUE(game.grid[3][4].isAlive());
   /*
     ....
	 ..**
	 ..*.
   */
}

TEST(Life, runGame4) {
   Life<ConwayCell> game(3, 4, "....\n**..\n.*..");
   ASSERT_TRUE(!game.grid[3][1].isAlive());
   game.runGame();
   ASSERT_TRUE(game.grid[3][1].isAlive());

   /*
     ....
	 **..
	 .*..
   */
}

//FredkinCell
TEST(Life, runGame5) {
   Life<FredkinCell> game(3, 4, "--0-\n---0\n--0-");
   ASSERT_TRUE(game.grid[2][4].isAlive());
   game.runGame();
   ASSERT_TRUE(!game.grid[2][4].isAlive());

   /*
     --0-
	 ---0   <<testing this cell
	 --0-
   */
}

//FredkinCell
TEST(Life, processTurnFredkin) {
   Life<FredkinCell> game(3, 4, "--0-\n---0\n--0-");
   ASSERT_TRUE(game.grid[2][4].isAlive());
   game.processTurnFredkin(&game.grid[2][4], 2,4); //changes the status
   game.grid[2][4].update(); // updates neighbor count
   ASSERT_TRUE(!game.grid[2][4].isAlive()); //Fredkin cell on the right should die

   /*
     --0-
	 ---0   <<testing this cell
	 --0-
   */
}

//FredkinCell
TEST(Life, processTurnFredkin2) {
   Life<FredkinCell> game(3, 4, "--0-\n----\n--0-");
   ASSERT_TRUE(!game.grid[2][4].isAlive());
   game.processTurnFredkin(&game.grid[2][4], 2,4); //changes the status
   game.grid[2][4].update(); // updates neighbor count
   ASSERT_TRUE(!game.grid[2][4].isAlive()); //Fredkin cell on the right should remain dead

   /*
     --0-
	 ----   <<testing this cell
	 --0-
   */
}

//FredkinCell
TEST(Life, processTurnFredkin3) {
   Life<FredkinCell> game(3, 4, "--0-\n--0-\n--0-");
   ASSERT_TRUE(!game.grid[2][4].isAlive());
   game.processTurnFredkin(&game.grid[2][4], 2,4); //changes the status
   game.grid[2][4].update(); // updates neighbor count
   ASSERT_TRUE(game.grid[2][4].isAlive()); //Fredkin cell on the right should live

   /*
     --0-
	 --0- 
	 --0-
   */
}

//Conway
TEST(Life, processTurnConway) {
   Life<Cell> game(3, 4, "..*.\n..*.\n..*.");
   ASSERT_TRUE(!game.grid[2][4].isAlive());
   game.processTurnConway(&game.grid[2][4], 2,4); //changes the status
   game.grid[2][4].update(); // updates neighbor count
   ASSERT_TRUE(game.grid[2][4].isAlive()); //Fredkin cell on the right should live

   /*
     ..*.
	 ..*. 
	 ..*.
   */
}



TEST(Life, checkNeighborsConway) {
   Life<ConwayCell> game(3, 4, "..*.\n...*\n..*.");
  // game.display(0);
   ASSERT_TRUE(!game.grid[2][3].isAlive());
   ASSERT_TRUE(game.checkNeighborsConway(2,3) == 3);
   /*
     ..*.
	 ...*
	 ..*.
   */
}

TEST(Life, checkNeighborsConway2) {
   Life<ConwayCell> game(3, 4, "..*.\n...*\n..*.");
  // game.display(0);
   ASSERT_TRUE(!game.grid[2][3].isAlive());
   ASSERT_TRUE(game.checkNeighborsConway(3,3) == 1);
   /*
     ..*.
	 ...*
	 ..*.
   */
}


TEST(Life, checkNeighborsConway3) {
   Life<ConwayCell> game(3, 4, "..*.\n...*\n..*.");
  // game.display(0);
   ASSERT_TRUE(game.checkNeighborsConway(1,3) == 1);
   /*
     ..*.
	 ...*
	 ..*.
   */
}

TEST(Life, checkNeighborsFredkin) {
   Life<ConwayCell> game(3, 4, "--0-\n---0\n--0-");
  // game.display(0);
   ASSERT_TRUE(!game.grid[2][3].isAlive());
   ASSERT_TRUE(game.checkNeighborsFredkin(2,4) == 0);
   /*
     --0-
	 ---0
	 --0-
   */
}

TEST(Life, checkNeighborsFredkin2) {
   Life<ConwayCell> game(3, 4, "--0-\n---0\n--0-");
  // game.display(0);
   ASSERT_TRUE(game.checkNeighborsFredkin(3,3) == 0);
   /*
     --0-
	 ---0
	 --0-
   */
}

TEST(Life, checkNeighborsFredkin3) {
   Life<ConwayCell> game(3, 4, "--0-\n---0\n--00");
  // game.display(0);
   ASSERT_TRUE(game.checkNeighborsFredkin(3,3) == 1);
   /*
     --0-
	 ---0
	 --00
   */
}

// Conway Cell

TEST(Conway, switch1) {
	ConwayCell c;
	ASSERT_TRUE(c.changeStatus == false);
}

TEST(Conway, switch2) {
	ConwayCell c;
	c.switchStatus();
	ASSERT_TRUE(c.changeStatus == true);
}
TEST(Conway, switch3) {
	ConwayCell c;
	c.switchStatus();
	c.switchStatus();
	ASSERT_TRUE(c.changeStatus == false);
}

TEST(Conway, update1) {
	ConwayCell c;
	ASSERT_TRUE(c.changeStatus == false);
	c.switchStatus();
	c.alive = true;
	c.update();
	ASSERT_TRUE(c.displayChar == '.');
}

TEST(Conway, update2) {
	ConwayCell c;
	c.switchStatus();
	ASSERT_TRUE(c.changeStatus == true);
	c.alive = false;
	c.update();
	ASSERT_TRUE(c.displayChar == '*');
}

TEST(Conway, update3) {
	ConwayCell c;
	c.switchStatus();
	c.switchStatus();
	ASSERT_TRUE(c.changeStatus == false);
	c.update();
	ASSERT_TRUE(c.alive == false);
}

TEST(Conway, isAlive1) {
	ConwayCell c;
	ASSERT_TRUE(c.changeStatus == false);
	c.switchStatus();
	c.alive = true;
	c.update();
	ASSERT_TRUE(c.displayChar == '.');
	ASSERT_TRUE(!c.isAlive());
}

TEST(Conway, isAlive2) {
	ConwayCell c;
	ASSERT_TRUE(!c.isAlive());
	c.switchStatus();
	ASSERT_TRUE(c.changeStatus == true);
	c.alive = false;
	c.update();
	ASSERT_TRUE(c.displayChar == '*');
	ASSERT_TRUE(c.isAlive());
}

TEST(Conway, isAlive3) {
	ConwayCell c;
	c.switchStatus();
	c.switchStatus();
	ASSERT_TRUE(c.changeStatus == false);
	c.update();
	ASSERT_TRUE(c.alive == false);
}

TEST(Conway, displayChar1) {
	ConwayCell c;
	ASSERT_TRUE(c.getDisplayChar() == '.');
}

TEST(Conway, displayChar2) {
	ConwayCell c;
	c.switchStatus();
	c.update(); //changes display char
	ASSERT_TRUE(c.getDisplayChar() == '*');
}

TEST(Conway, displayChar3) {
	ConwayCell c;
	c.switchStatus(); //doesnt change display char
	ASSERT_TRUE(c.getDisplayChar() == '.');
}






// Fredkin Cell

TEST(Fredkin, switch1) {
	FredkinCell c;
	ASSERT_TRUE(c.changeStatus == false);
}

TEST(Fredkin, switch2) {
	FredkinCell c;
	c.switchStatus();
	ASSERT_TRUE(c.changeStatus == true);
}
TEST(Fredkin, switch3) {
	FredkinCell c;
	c.switchStatus();
	c.switchStatus();
	ASSERT_TRUE(c.changeStatus == false);
}

TEST(Fredkin, update1) {
	FredkinCell c;
	ASSERT_TRUE(c.changeStatus == false);
	c.switchStatus();
	c.alive = true;
	c.update();
	ASSERT_TRUE(c.displayChar == '-');
}

TEST(Fredkin, update2) {
	FredkinCell c;
	c.switchStatus();
	ASSERT_TRUE(c.changeStatus == true);
	c.alive = false;
	c.update();
	ASSERT_TRUE(c.displayChar == '0');
}

TEST(Fredkin, update3) {
	FredkinCell c;
	c.switchStatus();
	c.switchStatus();
	ASSERT_TRUE(c.changeStatus == false);
	c.update();
	ASSERT_TRUE(c.alive == false);
}


TEST(Fredkin, isAlive1) {
	FredkinCell c;
	ASSERT_TRUE(c.changeStatus == false);
	c.switchStatus();
	c.alive = true;
	c.update();
	ASSERT_TRUE(c.displayChar == '-');
	ASSERT_TRUE(!c.isAlive());
}

TEST(Fredkin, isAlive2) {
	FredkinCell c;
	ASSERT_TRUE(!c.isAlive());
	c.switchStatus();
	ASSERT_TRUE(c.changeStatus == true);
	c.alive = false;
	c.update();
	ASSERT_TRUE(c.displayChar == '0');
	ASSERT_TRUE(c.isAlive());
}

TEST(Fredkin, isAlive3) {
	FredkinCell c;
	c.switchStatus();
	c.switchStatus();
	ASSERT_TRUE(c.changeStatus == false);
	c.update();
	ASSERT_TRUE(c.alive == false);
}


TEST(Fredkin, displayChar1) {
	FredkinCell c;
	ASSERT_TRUE(c.getDisplayChar() == '-');
}

TEST(Fredkin, displayChar2) {
	FredkinCell c;
	c.switchStatus();
	c.update(); //changes display char
	ASSERT_TRUE(c.getDisplayChar() == '0');
}

TEST(Fredkin, displayChar3) {
	FredkinCell c;
	c.switchStatus(); //doesnt change display char
	ASSERT_TRUE(c.getDisplayChar() == '-');
	
}


// Cell

TEST(Cell, switch1) {
	Cell c;
	ASSERT_TRUE(c.get()->changeStatus == false);
}

TEST(Cell, switch2) {
	Cell c;
	c.switchStatus();
	ASSERT_TRUE(c.get()->changeStatus == true);
}
TEST(Cell, switch3) {
	Cell c;
	c.switchStatus();
	c.switchStatus();
	ASSERT_TRUE(c.get()->changeStatus == false);
}

TEST(Cell, update1) {
	Cell c;
	ASSERT_TRUE(c.get()->changeStatus == false);
	c.switchStatus();
	c.get()->alive = true;
	c.update();
	ASSERT_TRUE( c.get()->getDisplayChar() == '-');
}

TEST(Cell, update2) {
	Cell c;
	c.switchStatus();
	ASSERT_TRUE(c.get()->changeStatus == true);
	c.get()->alive = false;
	c.update();
	ASSERT_TRUE( c.get()->getDisplayChar() == '0');
}

TEST(Cell, update3) {
	Cell c;
	c.switchStatus();
	c.switchStatus();
	ASSERT_TRUE(c.get()->changeStatus == false);
	c.update();
	ASSERT_TRUE(c.get()->alive == false);
}


TEST(Cell, isAlive1) {
	Cell c;
	ASSERT_TRUE(c.get()->changeStatus == false);
	c.switchStatus();
	c.get()->alive = true;
	c.update();
	ASSERT_TRUE(c.get()->getDisplayChar()  == '-');
	ASSERT_TRUE(!c.isAlive());
}

TEST(Cell, isAlive2) {
	Cell c;
	ASSERT_TRUE(!c.isAlive());
	c.switchStatus();
	ASSERT_TRUE(c.get()->changeStatus == true);
	c.get()->alive = false;
	c.update();
	ASSERT_TRUE(c.get()->getDisplayChar()  == '0');
	ASSERT_TRUE(c.isAlive());
}

TEST(Cell, isAlive3) {
	Cell c;
	c.switchStatus();
	c.switchStatus();
	ASSERT_TRUE(c.get()->changeStatus == false);
	c.update();
	ASSERT_TRUE(c.get()->alive == false);
}


TEST(Cell, mutate1) {
	Cell c;
	ASSERT_TRUE(c.get()->changeStatus == false);
	c.get()->alive = true;
	c.update();
	c.update();
	//std::cout << c.get()->getDisplayChar() << " alive " << c.isAlive()<<endl;
	ASSERT_TRUE(c.get()->getDisplayChar()  == '*');
	ASSERT_TRUE(c.isAlive());
}


TEST(Cell, mutate2) {
	Cell c;
	ASSERT_TRUE(c.get()->changeStatus == false);
	c.get()->alive = true;
	c.mutate();
	ConwayCell* q = dynamic_cast<ConwayCell*>(c.get());
	ASSERT_TRUE(q != NULL);
}


TEST(Cell, mutate3) {
	Cell c;
	ASSERT_TRUE(c.get()->changeStatus == false);
	c.get()->alive = true;
	c.mutate();
	FredkinCell* q = dynamic_cast<FredkinCell*>(c.get());
	ASSERT_TRUE(q == NULL);
}

TEST(Cell, mutate4) {
	Cell c;
	ASSERT_TRUE(c.get()->changeStatus == false);
	c.get()->alive = true;
	c.mutate();
	c.mutate();
	FredkinCell* q = dynamic_cast<FredkinCell*>(c.get());
	ASSERT_TRUE(q == NULL);
}

TEST(Cell, mutate5) {
	Cell c;
	ASSERT_TRUE(c.get()->changeStatus == false);
	c.get()->alive = true;
	FredkinCell* q = dynamic_cast<FredkinCell*>(c.get());
	q->age = 4;
	c.update();
	FredkinCell* b = dynamic_cast<FredkinCell*>(c.get());
	ASSERT_TRUE(b != NULL); // didnt change into conway because we
	// artificially made the age greater than 2.
}

TEST(Cell, mutate6) {
	Cell c;
	ASSERT_TRUE(c.get()->changeStatus == false);
	c.get()->alive = true;
	FredkinCell* q = dynamic_cast<FredkinCell*>(c.get());
	q->age = 1;
	c.update(); // increments age by 1
	FredkinCell* b = dynamic_cast<FredkinCell*>(c.get());
	ASSERT_TRUE(b == NULL); // This cell is now a conway cell.
}

TEST(AbstractCell, update) {
	AbstractCell c;
	c.update();
	ASSERT_TRUE(c.alive);
}

TEST(AbstractCell, update2) {
	AbstractCell c;
	c.update();
	c.update();
	ASSERT_TRUE(!c.alive);
}

TEST(AbstractCell, update3) {
	AbstractCell c;
	c.update();
	c.update();
	ASSERT_TRUE(c.changeStatus == false);
}

TEST(AbstractCell, clone) {
	AbstractCell c;
	c.update();
	AbstractCell *d = c.clone();
	d->update();

	ASSERT_TRUE(c.alive);
	ASSERT_TRUE(!d->alive);
	delete d;
}

TEST(AbstractCell, clone2) {
	AbstractCell c;
	c.update();
	AbstractCell *d = c.clone();
	c.update();

	ASSERT_TRUE(!c.alive);
	ASSERT_TRUE(d->alive);
	delete d;
}

TEST(AbstractCell, clone3) {
	AbstractCell c;
	c.update();
	c.update();
	c.update();
	AbstractCell *d = c.clone();
	ASSERT_TRUE(c.changeStatus == false);
	ASSERT_TRUE(c.alive == true);
	ASSERT_TRUE(d->alive == true);
	delete d;
}
