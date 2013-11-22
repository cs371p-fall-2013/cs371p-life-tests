#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==
#include <unordered_set>

#include "gtest/gtest.h"

//#include "Cell.h"
//#include "ConwayCell.h"
//#include "FredkinCell.h"
#define private public
#include "Life.h"


TEST(Conway, constructor_1) {
  ConwayCell cell(true);  
  ASSERT_TRUE(cell.is_alive());

}
 
TEST(Conway, constructor_2) {
  ConwayCell cell(false);  
  ASSERT_TRUE(!cell.is_alive());
}

TEST(Fredkin, constructor_1) {
  FredkinCell cell(true);  
  ASSERT_TRUE(cell.is_alive());
  ASSERT_TRUE(cell.age() == 0);

}
 
TEST(Fredkin, constructor_2) {
  FredkinCell cell(false);  
  ASSERT_TRUE(!cell.is_alive());
  ASSERT_TRUE(cell.age() == 0);
}



TEST(Cell, constructor_1) {
  std::string s = "-";
  Cell cell(s);
  ASSERT_TRUE(!cell.is_alive());

}

TEST(Cell, constructor_2) {
  std::string s = "0";
  Cell cell(s);
  ASSERT_TRUE(cell.is_alive());

}

TEST(Cell, constructor_3) {
  std::string s = "1";
  Cell cell(s);
  ASSERT_TRUE(cell.is_alive());

}

TEST(Cell, constructor_4) {
  std::string s = ".";
  Cell cell(s);
  ASSERT_TRUE(!cell.is_alive());

}

TEST(Cell, constructor_5) {
  std::string s = "*";
  Cell cell(s);
  ASSERT_TRUE(cell.is_alive());

}



TEST(Conway, kill_1) {
  ConwayCell cell(true);  
  ASSERT_TRUE(cell.is_alive());
  cell.kill();
  ASSERT_TRUE(!cell.is_alive());
}  

TEST(Conway, to_string_1) {
  ConwayCell cell(true);
  ASSERT_TRUE(cell.to_string() == "*");
}

TEST(Conway, to_string_2) {
  ConwayCell cell(false);
  ASSERT_TRUE(cell.to_string() == ".");
}


TEST(Conway, to_string_3) {
  ConwayCell cell(true);
  ASSERT_TRUE(cell.to_string() == "*");
  cell.kill();
  ASSERT_TRUE(cell.to_string() == ".");
}

TEST(Fredkin, to_string_1) {
  FredkinCell cell(true);
  ASSERT_TRUE(cell.to_string() == "0");
}

TEST(Life, read_file_1) {
  Life<ConwayCell> life;
  
  std::istringstream r("4\n3\n***\n**.\n.**\n.*.\n");
  life.read_file(r);
  
  std::ostringstream w;
  life.print_grid(w);
  std::string expected = "\nGeneration = 0, Population = 8.\n***\n**.\n.**\n.*.\n";
  std::string actual = w.str();
  
  std::cout << "Acual: \n" << actual << "\n";
  std::cout << "Expected: \n" << expected << "\n";

  ASSERT_TRUE(actual == expected);
}

 
TEST(Life, read_file_2) {
  Life<ConwayCell> life;
  
  std::istringstream r("3\n4\n***.\n**..\n.**.\n");
  life.read_file(r);
  
  std::ostringstream w;
  life.print_grid(w);
  std::string expected = "\nGeneration = 0, Population = 7.\n***.\n**..\n.**.\n";
  std::string actual = w.str();
  ASSERT_TRUE(actual == expected);
  ASSERT_TRUE(life.grid[0][0].is_alive());
  ASSERT_TRUE(!life.grid[0][3].is_alive());
}

TEST(Life, read_file_3) {
  Life<FredkinCell> life;
  
  std::istringstream r("3\n4\n012-\n11--\n-21-\n");
  life.read_file(r);
  
  std::ostringstream w;
  life.print_grid(w);
  std::string expected = "\nGeneration = 0, Population = 7.\n012-\n11--\n-21-\n";
  std::string actual = w.str();
  ASSERT_TRUE(actual == expected);
  ASSERT_TRUE(life.grid[0][0].is_alive());
  ASSERT_TRUE(!life.grid[0][3].is_alive());
}

TEST(Life, resize_1) {
  std::vector<std::vector<ConwayCell> > old_grid;
  
}

TEST(Conway, clone_1) {
  using namespace std;
  string dead = ".";
  string alive = ".";
  ConwayCell c1(dead);
  
  ConwayCell* c2 = c1.clone();
  
  ASSERT_TRUE(!c1.is_alive());
  ASSERT_TRUE(!c2->is_alive());
  ASSERT_TRUE(c2->to_string() == ".");
  c1.revive();
  ASSERT_TRUE(c1.to_string() == "*");
  ASSERT_TRUE(c2->to_string() == ".");
  
  delete c2;
}

TEST(Conway, clone_2) {
  using namespace std;
  string dead = ".";
  string alive = "*";
  ConwayCell c1(alive);
  
  ConwayCell* c2 = c1.clone();
  
  ASSERT_TRUE(c1.is_alive());
  ASSERT_TRUE(c2->is_alive());
  
  ASSERT_TRUE(c2->to_string() == "*");
  c1.kill();
  ASSERT_TRUE(c1.to_string() == ".");
  ASSERT_TRUE(c2->to_string() == "*");
  
  
  delete c2;
}


TEST(Life, copy_grid_1) {
  using namespace std;
  vector<vector<ConwayCell> > grid;
  grid.resize(3);
  for(int i = 0; i < 3; i++) {
    grid[i].resize(3);
  }
  
  string dead = ".";
  string alive = "*";
  
  ConwayCell c1(alive);
  grid[0][2] = c1;
  ConwayCell c2(alive);
  grid[1][1] = c2;
  ConwayCell c3(dead);
  grid[2][0] = c3;
  ASSERT_TRUE(!grid[2][0].is_alive());
  ASSERT_TRUE( grid[2][0].to_string() == ".");
  vector<vector<ConwayCell> > newGrid = copy_grid(&grid);
  
  ASSERT_TRUE(&newGrid != &grid);
  
  //cout << newGrid[0][1].to_string() << "\n";
  //ASSERT_TRUE(newGrid[0][1].to_string() == ".");
  ASSERT_TRUE(newGrid[0][2].to_string() == "*");
  ASSERT_TRUE(newGrid[1][1].to_string() == "*");

  ASSERT_TRUE(newGrid[2][0].to_string() == ".");
  
  grid[0][2].kill();
  ASSERT_TRUE(grid[0][2].to_string() == ".");
  ASSERT_TRUE(newGrid[0][2].to_string() == "*");
  
}

TEST(Life, copy_grid_2) {
  using namespace std;
  vector<vector<Cell> > grid;
  grid.resize(3);
  for(int i = 0; i < 3; i++) {
    grid[i].resize(3);
  }
  

  string dead = "-";
  string alive = "0";
  string one = "1";
  
  Cell c1(alive);

  grid[0][2] = c1;
  
  Cell c2(one);

  ASSERT_TRUE(grid[1].size() == 3);
  grid[1][1] = c2;

  Cell c3(dead);
  grid[2][0] = c3;
  

  
  
  ASSERT_TRUE(!grid[2][0].is_alive());
  ASSERT_TRUE( grid[2][0].to_string() == "-");

  vector<vector<Cell> > newGrid = copy_grid(&grid);
  
  ASSERT_TRUE(&newGrid != &grid);
  

  ASSERT_TRUE(newGrid[0][2].to_string() == "0");
  ASSERT_TRUE(newGrid[1][1].to_string() == "1");

  ASSERT_TRUE(newGrid[2][0].to_string() == "-");  
  

  //grid[0][2].kill();
  //ASSERT_TRUE(grid[0][2].to_string() == "-");
  //ASSERT_TRUE(newGrid[0][2].to_string() == "0");

}









TEST(Conway, default_constructor) {
  ConwayCell cell();
  ASSERT_TRUE(true); // no segfault
}

TEST(Fredkin, default_constructor) {
  FredkinCell cell();
  ASSERT_TRUE(true); // no segfault
}

TEST(Cell, default_constructor) {
  Cell cell();
  ASSERT_TRUE(true); // no segfault
}

TEST(Conway, is_alive_1) {
  std::string s = "*";
  ConwayCell cell(s);
  ASSERT_TRUE(cell.is_alive());
  
}

TEST(Conway, is_alive_2) {
  std::string s = ".";
  ConwayCell cell(s);
  ASSERT_TRUE(!cell.is_alive());
  
}

TEST(Fredkin, is_alive_1) {
  std::string s = "0";
  FredkinCell cell(s);
  ASSERT_TRUE(cell.is_alive()); 
}

TEST(Fredkin, is_alive_2) {
  std::string s = "1";
  FredkinCell cell(s);
  ASSERT_TRUE(cell.is_alive()); 
}

TEST(Fredkin, is_alive_3) {
  std::string s = "+";
  FredkinCell cell(s);
  ASSERT_TRUE(cell.is_alive()); 
}

TEST(Fredkin, is_alive_4) {
  std::string s = "-";
  FredkinCell cell(s);
  ASSERT_TRUE(!cell.is_alive()); 
}

TEST(Cell, is_alive_1) {
  std::string s = "-";
  Cell cell(s);
  ASSERT_TRUE(!cell.is_alive());
}

TEST(Cell, is_alive_2) {
  std::string s = "1";
  Cell cell(s);
  ASSERT_TRUE(cell.is_alive());
}


TEST(Conway, kill_2) {
  std::string s = "*";
  ConwayCell cell(s);
  ASSERT_TRUE(cell.is_alive());
  
  cell.kill();
  
  ASSERT_TRUE(!cell.is_alive());
}

TEST(Conway, kill_3) {
  std::string s = ".";
  ConwayCell cell(s);
  ASSERT_TRUE(!cell.is_alive());
  
  cell.kill();
  
  ASSERT_TRUE(!cell.is_alive());
}


TEST(Fredkin, kill_1) {
  std::string s = "0";
  FredkinCell cell(s);
  ASSERT_TRUE(cell.is_alive()); 
  
  cell.kill();
  ASSERT_TRUE(!cell.is_alive());
}

TEST(Fredkin, kill_2) {
  std::string s = "1";
  FredkinCell cell(s);
  ASSERT_TRUE(cell.is_alive()); 
  
  cell.kill();
  ASSERT_TRUE(!cell.is_alive());  
}

TEST(Fredkin, kill_3) {
  std::string s = "+";
  FredkinCell cell(s);
  ASSERT_TRUE(cell.is_alive()); 
  cell.kill();
  ASSERT_TRUE(!cell.is_alive());  
}

TEST(Fredkin, kill_4) {
  std::string s = "-";
  FredkinCell cell(s);
  ASSERT_TRUE(!cell.is_alive()); 
  
  cell.kill();
  ASSERT_TRUE(!cell.is_alive());  
}


TEST(Conway, revive_2) {
  std::string s = "*";
  ConwayCell cell(s);
  ASSERT_TRUE(cell.is_alive());
  
  cell.revive();
  
  ASSERT_TRUE(cell.is_alive());
}

TEST(Conway, revive_3) {
  std::string s = ".";
  ConwayCell cell(s);
  ASSERT_TRUE(!cell.is_alive());
  
  cell.revive();
  
  ASSERT_TRUE(cell.is_alive());
}




TEST(Fredkin, revive_1) {
  std::string s = "0";
  FredkinCell cell(s);
  ASSERT_TRUE(cell.is_alive()); 
  
  cell.revive();
  ASSERT_TRUE(cell.is_alive());
}

TEST(Fredkin, revive_2) {
  std::string s = "1";
  FredkinCell cell(s);
  ASSERT_TRUE(cell.is_alive()); 
  
  cell.revive();
  ASSERT_TRUE(cell.is_alive());
}

TEST(Fredkin, revive_3) {
  std::string s = "+";
  FredkinCell cell(s);
  ASSERT_TRUE(cell.is_alive()); 
  cell.revive();
  ASSERT_TRUE(cell.is_alive());
}

TEST(Fredkin, revive_4) {
  std::string s = "-";
  FredkinCell cell(s);
  ASSERT_TRUE(!cell.is_alive()); 
  
  cell.revive();
  ASSERT_TRUE(cell.is_alive());
}

TEST(Conway, age_1) {
  std::vector<bool> surrounding(8, false);
  ConwayCell cell(".");
  ASSERT_TRUE(cell.age() == 0);
}

TEST(Conway, age_2) {
  std::vector<bool> surrounding(8, false);
  ConwayCell cell("*");
  ASSERT_TRUE(cell.age() == 0);
}

TEST(Conway, age_3) {
  std::vector<bool> surrounding(8, false);
  ConwayCell cell("*");
  ASSERT_TRUE(cell.age() == 0);
  
  cell.update(&surrounding);
  ASSERT_TRUE(cell.age() == 0);
}

TEST(Fredkin, age_1) {
  std::vector<bool> surrounding(8, false);
  FredkinCell cell("-");
  ASSERT_TRUE(cell.age() == 0);
}

TEST(Fredkin, age_2) {
  std::vector<bool> surrounding(8, false);
  std::string s = "0";
  FredkinCell cell(s);
  ASSERT_TRUE(cell.age() == 0);
}

TEST(Fredkin, age_3) {
  std::vector<bool> surrounding(8, false);
  std::string s = "1";  
  FredkinCell cell(s);
  ASSERT_TRUE(cell.age() == 1);
}

TEST(Fredkin, age_4) {
  std::vector<bool> surrounding(8, false);

  std::string s = "9";  
  FredkinCell cell(s);
  ASSERT_TRUE(cell.age() == 9);
  
  cell.update(&surrounding);
  ASSERT_TRUE(cell.age() == 9);
}

TEST(Fredkin, age_5) {
  std::vector<bool> surrounding(8, false);
  surrounding[1] = true;
  
  std::string s = "9";  
  FredkinCell cell(s);
  ASSERT_TRUE(cell.age() == 9);
  
  cell.update(&surrounding);
  ASSERT_TRUE(cell.age() == 10);
  ASSERT_TRUE(cell.to_string() == "+");
}





TEST(ConwayCell, update_1) { 

  // 3: live
  // less than 2 or more than 3: dead
  std::vector<bool> surrounding(8, false);
  surrounding[3] = true;
  surrounding[5] = true;
  surrounding[6] = true;
  
  ConwayCell cell(false);
  ASSERT_TRUE(!cell.is_alive());
  ASSERT_TRUE(cell.age() == 0);
  
  cell.update(&surrounding);
  
  ASSERT_TRUE(cell.is_alive());
  ASSERT_TRUE(cell.age() == 0); 

}

TEST(ConwayCell, update_2) { 

  // 3: live
  // less than 2 or more than 3: dead
  std::vector<bool> surrounding(8, false);
  surrounding[0] = true;
  surrounding[2] = true;
  surrounding[6] = true;  
  
  
  ConwayCell cell(true);
  ASSERT_TRUE(cell.is_alive());
  ASSERT_TRUE(cell.age() == 0);
  
  cell.update(&surrounding);
  
  ASSERT_TRUE(cell.is_alive());
  ASSERT_TRUE(cell.age() == 0); 

}

TEST(ConwayCell, update_3) { 

  // 3: live
  // less than 2 or more than 3: dead
  std::vector<bool> surrounding(8, false);
  
  ConwayCell cell(true);
  ASSERT_TRUE(cell.is_alive());
  ASSERT_TRUE(cell.age() == 0);
  
  cell.update(&surrounding);
  
  ASSERT_TRUE(!cell.is_alive());
  ASSERT_TRUE(cell.age() == 0); 

}

TEST(ConwayCell, update_4) { 

  // 3: live
  // less than 2 or more than 3: dead
  std::vector<bool> surrounding(8, false);
  surrounding[1] = true;
  surrounding[3] = true;
  surrounding[4] = true;
  surrounding[6] = true;
  
  
  ConwayCell cell(false);
  ASSERT_TRUE(!cell.is_alive());
  ASSERT_TRUE(cell.age() == 0);
  
  cell.update(&surrounding);
  
  ASSERT_TRUE(!cell.is_alive());
  ASSERT_TRUE(cell.age() == 0); 

}

TEST(FredkinCell, update_1) { // 1, 3, 4, 6

  // 1 or 3: live
  // 0, 2, or 4: dead
  std::vector<bool> surrounding = {true, true, false, false, false, false, false, true};
  FredkinCell cell(false);
  ASSERT_TRUE(!cell.is_alive());
  ASSERT_TRUE(cell.age() == 0);
  cell.update(&surrounding);
  ASSERT_TRUE(cell.is_alive());

  ASSERT_TRUE(cell.age() == 0); 

}

TEST(FredkinCell, update_2) { // 1, 3, 4, 6

  // 1 or 3: live
  // 0, 2, or 4: dead
  std::vector<bool> surrounding = {true, true, false, false, false, false, false, true};
  FredkinCell cell(true);
  ASSERT_TRUE(cell.is_alive());
  ASSERT_TRUE(cell.age() == 0);
  cell.update(&surrounding);
  ASSERT_TRUE(cell.is_alive());

  ASSERT_TRUE(cell.age() == 1); 

}

TEST(FredkinCell, update_3) { // 1, 3, 4, 6

  // 1 or 3: live
  // 0, 2, or 4: dead
  std::vector<bool> surrounding(8, false);
  surrounding[1] = true;
  surrounding[6] = true;
  
  
  FredkinCell cell(true);
  ASSERT_TRUE(cell.is_alive());
  ASSERT_TRUE(cell.age() == 0);
  cell.update(&surrounding);
  ASSERT_TRUE(!cell.is_alive());

  ASSERT_TRUE(cell.age() == 0); 

}

TEST(FredkinCell, update_4) { // 1, 3, 4, 6

  // 1 or 3: live
  // 0, 2, or 4: dead
  std::vector<bool> surrounding(8, false);
  surrounding[1] = true;
  surrounding[3] = true;
  surrounding[4] = true;
  surrounding[6] = true;
  
  
  FredkinCell cell(false);
  ASSERT_TRUE(!cell.is_alive());
  ASSERT_TRUE(cell.age() == 0);
  
  cell.update(&surrounding);
  
  ASSERT_TRUE(!cell.is_alive());
  ASSERT_TRUE(cell.age() == 0); 

}

TEST(Cell, update_1) {
  Cell cell("0");
  
  std::vector<bool> surrounding(8, false);
  surrounding[1] = true;
  surrounding[3] = true;
  surrounding[4] = true;
  surrounding[6] = true;
  
  ASSERT_TRUE(cell.is_alive());
  ASSERT_TRUE(cell.to_string() == "0");
  
  int pop_change = cell.update(&surrounding);
  
  
  ASSERT_TRUE(pop_change == -1);
  ASSERT_TRUE(!cell.is_alive());
  ASSERT_TRUE(cell.to_string() == "-");   
}

TEST(Cell, update_2) {
  Cell cell("0");
  
  std::vector<bool> surrounding(8, false);
  surrounding[1] = true;
  surrounding[3] = false;
  surrounding[4] = false;
  surrounding[6] = false;
  
  ASSERT_TRUE(cell.is_alive());
  ASSERT_TRUE(cell.to_string() == "0");
  
  int pop_change = cell.update(&surrounding);
  
  ASSERT_TRUE(pop_change == 0);
  ASSERT_TRUE(cell.is_alive());
  ASSERT_TRUE(cell.to_string() == "1");   
  
  surrounding[1] = true;
  surrounding[3] = true;
  surrounding[4] = false;
  surrounding[6] = true;  
  
  pop_change = cell.update(&surrounding);
   
  ASSERT_TRUE(pop_change == 0); 
  ASSERT_TRUE(cell.is_alive());
  ASSERT_TRUE(cell.to_string() == "*"); 
  
  surrounding[1] = false;
  surrounding[3] = false;
  surrounding[4] = false;
  surrounding[6] = false;   
  
  pop_change = cell.update(&surrounding);
  //std::cout << "pop change: " << pop_change << "\n";
  ASSERT_TRUE(pop_change == -1);
  ASSERT_TRUE(!cell.is_alive());
  ASSERT_TRUE(cell.to_string() == ".");   

}

TEST(Cell, update_3) {
  Cell cell("-");
  
  std::vector<bool> surrounding(8, false);
  surrounding[1] = true;
  surrounding[3] = false;
  surrounding[4] = false;
  surrounding[6] = false;
  
  ASSERT_TRUE(!cell.is_alive());
  ASSERT_TRUE(cell.to_string() == "-");
  
  int pop_change = cell.update(&surrounding);
  
  ASSERT_TRUE(pop_change == 1);
  ASSERT_TRUE(cell.is_alive());
  ASSERT_TRUE(cell.to_string() == "0");   
  
  surrounding[1] = true;
  surrounding[3] = false;
  surrounding[4] = false;
  surrounding[6] = true;  
  
  pop_change = cell.update(&surrounding);
   
  ASSERT_TRUE(pop_change == -1); 
  ASSERT_TRUE(!cell.is_alive());
  ASSERT_TRUE(cell.to_string() == "-"); 
}


TEST(Conway, to_string_5) {
  std::string s = ".";
  ConwayCell c(s);
  ASSERT_TRUE(c.to_string() == ".");
}
TEST(Conway, to_string_6) {
  std::string s = "*";
  ConwayCell c(s);
  ASSERT_TRUE(c.to_string() == "*");
}

TEST(Fredkin, to_string_2) {
  std::string s = "-";
  FredkinCell cell(s);
  ASSERT_TRUE(cell.to_string() == "-");
}

TEST(Fredkin, to_string_3) {
  std::string s = "0";
  FredkinCell cell(s);
  ASSERT_TRUE(cell.to_string() == "0");
}

TEST(Fredkin, to_string_4) {
  std::string s = "1";
  FredkinCell cell(s);
  ASSERT_TRUE(cell.to_string() == "1");
}

TEST(Fredkin, to_string_5) {
  FredkinCell cell(false);
  ASSERT_TRUE(cell.to_string() == "-");
 
}

TEST(Fredkin, to_string_6) {
  FredkinCell cell(true);
  ASSERT_TRUE(cell.to_string() == "0");
 
}



TEST(Life, get_surrounding_fredkin_1) {
  using namespace std;
  Life<FredkinCell> life;
  
  std::istringstream r("3\n4\n012-\n11--\n-21-\n");

  life.read_file(r);
  
  std::ostringstream w;
  life.print_grid(w);    
  
  vector<bool> actual = life.get_surrounding(1, 1);
  vector<bool> expected = {true, true, true, true, false, false, true, true};

  
  for(int i = 0; i < 8; i++) {
    //cout << i << ": " << actual[i] << " Should be: "<< expected[i]<< "\n";  
    ASSERT_TRUE(actual[i] == expected[i]);
  }
}


TEST(Life, get_surrounding_fredkin_2) {
  using namespace std;
  Life<FredkinCell> life;
  
  std::istringstream r("3\n4\n----\n-1--\n----\n");
  
  life.read_file(r);
  
  std::ostringstream w;
  life.print_grid(w);    
  
  vector<bool> actual = life.get_surrounding(1, 1);
  vector<bool> expected = {false, false, false, false, false, false, false, false};

  
  for(int i = 0; i < 8; i++) {
    //cout << i << ": " << actual[i] << " Should be: "<< expected[i]<< "\n";  
    ASSERT_TRUE(actual[i] == expected[i]);
  }
  
  ASSERT_TRUE(life.grid[1][1].is_alive());
  
  life.grid[1][1].update(&actual);
  
  ASSERT_TRUE(!life.grid[1][1].is_alive());
}

TEST(Life, get_surrounding_fredkin_3) {
  using namespace std;
  Life<FredkinCell> life;
  
  std::istringstream r("3\n4\n-1--\n-1--\n-23-\n");

  life.read_file(r);
  
  std::ostringstream w;
  life.print_grid(w);    
  
  vector<bool> actual = life.get_surrounding(1, 1);
  vector<bool> expected = {false, true, false, false, false, false, true, true};

  
  for(int i = 0; i < 8; i++) {
    //cout << i << ": " << actual[i] << " Should be: "<< expected[i]<< "\n";  
    ASSERT_TRUE(actual[i] == expected[i]);
  }
  
  ASSERT_TRUE(life.grid[1][1].is_alive()); 
  
  life.grid[1][1].update(&actual);
  
  ASSERT_TRUE(!life.grid[1][1].is_alive());
}

TEST(Life, get_surrounding_fredkin_4) {
  using namespace std;
  Life<FredkinCell> life;
  
  std::istringstream r("3\n4\n-1--\n-1--\n2-3-\n\n");
  
  life.read_file(r);
  
  std::ostringstream w;
  life.print_grid(w);    
  
  vector<bool> actual = life.get_surrounding(1, 1);
  vector<bool> expected = {false, true, false, false, false, true, false, true};

  
  for(int i = 0; i < 8; i++) {
    //cout << i << ": " << actual[i] << " Should be: "<< expected[i]<< "\n";  
    ASSERT_TRUE(actual[i] == expected[i]);
  }
  
  ASSERT_TRUE(life.grid[1][1].is_alive());
  
  life.grid[1][1].update(&actual);
  
  ASSERT_TRUE(life.grid[1][1].is_alive());
}

TEST(Life, get_surrounding_conway_1) {
  using namespace std;
  Life<ConwayCell> life;
  
  std::istringstream r("3\n4\n.*..\n.*..\n*.*.\n\n");
  
  life.read_file(r);
  
  std::ostringstream w;
  life.print_grid(w);    
  
  vector<bool> actual = life.get_surrounding(1, 1);
  vector<bool> expected = {false, true, false, false, false, true, false, true};

  
  for(int i = 0; i < 8; i++) {
    //cout << i << ": " << actual[i] << " Should be: "<< expected[i]<< "\n";  
    ASSERT_TRUE(actual[i] == expected[i]);
  }
  
  ASSERT_TRUE(life.grid[1][1].is_alive());
  
  life.grid[1][1].update(&actual);
  
  ASSERT_TRUE(life.grid[1][1].is_alive());
}

TEST(Life, get_surrounding_conway_2) {
  using namespace std;
  Life<ConwayCell> life;
  
  std::istringstream r("3\n4\n.*..\n....\n*.*.\n\n");

  
  // .*..
  // ....
  // *.*.
  
  life.read_file(r);
  
  std::ostringstream w;
  life.print_grid(w);    
  
  vector<bool> actual = life.get_surrounding(1, 1);
  vector<bool> expected = {false, true, false, false, false, true, false, true};

  
  for(int i = 0; i < 8; i++) {
    ASSERT_TRUE(actual[i] == expected[i]);
  }
  
  ASSERT_TRUE(!life.grid[1][1].is_alive());
  
  life.grid[1][1].update(&actual);
  
  ASSERT_TRUE(life.grid[1][1].is_alive());
}

TEST(Life, resize_grid_1) {
  using namespace std;
  vector<vector<FredkinCell> > grid;
  
  resize_grid(grid, 3, 4);
  
  ASSERT_TRUE(grid.size() == 3);
  ASSERT_TRUE(grid[0].size() == 4);
}

TEST(Life, resize_grid_2) {
  using namespace std;
  vector<vector<ConwayCell> > grid;
  
  resize_grid(grid, 4, 10);
  
  ASSERT_TRUE(grid.size() == 4);
  ASSERT_TRUE(grid[0].size() == 10);
}

TEST(Life, resize_grid_3) {
  using namespace std;
  vector<vector<Cell> > grid;
  
  resize_grid(grid, 1, 4);
  
  ASSERT_TRUE(grid.size() == 1);
  ASSERT_TRUE(grid[0].size() == 4);
}


