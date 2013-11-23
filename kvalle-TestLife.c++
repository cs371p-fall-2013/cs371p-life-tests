#define private public
#define protected public

#include "AbstractCell.h"
#include "ConwayCell.h"
#include "Cell.h"
#include "FredkinCell.h"
#include "Life.h"

#include <iostream>
#include <unordered_set>
#include <sstream>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

// ---------
// to_string
// ---------

TEST(Life, to_string1)
{
	ConwayCell conwayCell(0,0,false);
	string pic = conwayCell.to_string();
	ASSERT_TRUE(pic == ".");
}

TEST(Life, to_string2)
{
	FredkinCell fredkinCell(0,0,true,5);
	string pic = fredkinCell.to_string();
	ASSERT_TRUE(pic == "5");
}

TEST(Life, to_string3)
{
	Cell cell = new ConwayCell(0,0,true);
	string pic = cell.to_string();
	ASSERT_TRUE(pic == "*");
}

// -----
// clone
// -----

TEST(Life, clone1)
{
	ConwayCell conwayCell(1,2,false);
	ConwayCell* clone = conwayCell.clone();
	ASSERT_TRUE(conwayCell.is_alive() == clone->is_alive());
	ASSERT_TRUE(conwayCell.get_x() == clone->get_x());
	ASSERT_TRUE(conwayCell.get_y() == clone->get_y());
	delete clone;
}

TEST(Life, clone2)
{
	FredkinCell fredkinCell(1,2,false, 2);
	FredkinCell* clone = fredkinCell.clone();
	ASSERT_TRUE(fredkinCell.is_alive() == clone->is_alive());
	ASSERT_TRUE(fredkinCell.get_x() == clone->get_x());
	ASSERT_TRUE(fredkinCell.get_y() == clone->get_y());
	ASSERT_TRUE(fredkinCell._age == clone->_age);
	delete clone;
}

TEST(Life, clone3)
{
	AbstractCell* fredkinCell = new FredkinCell(1,2,false, 2);
	AbstractCell* clone = fredkinCell->clone();
	ASSERT_TRUE(fredkinCell->is_alive() == clone->is_alive());
	ASSERT_TRUE(fredkinCell->get_x() == clone->get_x());
	ASSERT_TRUE(fredkinCell->get_y() == clone->get_y());
	delete fredkinCell;
	delete clone;
}

// --------
// is_alive
// --------

TEST(Life, is_alive1)
{
	ConwayCell conwayCell(1,1,false);
	bool is_alive = conwayCell.is_alive();
	ASSERT_TRUE(is_alive == false);
}

TEST(Life, is_alive2)
{
	FredkinCell fredkinCell(1,1,true, 0);
	bool is_alive = fredkinCell.is_alive();
	ASSERT_TRUE(is_alive == true);
}

TEST(Life, is_alive3)
{
	Cell cell = new FredkinCell(1,1,true,0);
	bool is_alive = cell.is_alive();
	ASSERT_TRUE(is_alive == true);
}

// ----
// fate
// ----

TEST(Life, fate1)
{
	ConwayCell conwayCell(1,1,false);
	conwayCell.fate(2, 1);
	ASSERT_TRUE(conwayCell._alive_next_turn == true);
}

TEST(Life, fate2)
{
	FredkinCell fredkinCell(1,1,false, 2);
	fredkinCell.fate(2, 1);
	ASSERT_TRUE(fredkinCell._alive_next_turn == false);
}

TEST(Life, fate3)
{
	Cell cell = new FredkinCell(1,1,false, 2);
	cell.fate(2, 1);
	ASSERT_TRUE(cell.is_alive() == false);
}

// ------
// mutate
// ------

TEST(Life, mutate1)
{
	ConwayCell conwayCell(1,1,false);
	conwayCell.mutate();
	ASSERT_TRUE(conwayCell.to_string() == ".");
}

TEST(Life, mutate2)
{
	FredkinCell fredkinCell(1,1,false,2);
	fredkinCell.mutate();
	ASSERT_TRUE(fredkinCell.to_string() == "-");
}

TEST(Life, mutate3)
{
	Cell cell = new FredkinCell(1,1,false,2);
	cell.mutate();
	ASSERT_TRUE(cell.to_string() == "*");
}

// -----
// get_x
// -----

TEST(Life, get_x1)
{
	ConwayCell conwayCell(1,2,false);
	int x = conwayCell.get_x();
	ASSERT_TRUE(x == 1);
}

TEST(Life, get_x2)
{
	FredkinCell fredkinCell(1,2,false,0);
	int x = fredkinCell.get_x();
	ASSERT_TRUE(x == 1);
}

TEST(Life, get_x3)
{
	Cell cell = new FredkinCell(1,2,false,0);
	int x = cell.get_x();
	ASSERT_TRUE(x == 1);
}

// -----
// get_y
// -----

TEST(Life, get_y1)
{
	ConwayCell conwayCell(1,2,false);
	int y = conwayCell.get_y();
	ASSERT_TRUE(y == 2);
}

TEST(Life, get_y2)
{
	FredkinCell fredkinCell(1,2,false,0);
	int y = fredkinCell.get_y();
	ASSERT_TRUE(y == 2);
}

TEST(Life, get_y3)
{
	Cell cell = new FredkinCell(1,2,false,0);
	int y = cell.get_y();
	ASSERT_TRUE(y == 2);
}

// ---
// add
// ---

TEST(Life, add1)
{
	Life<ConwayCell> life(5,5);
	ConwayCell conwayCell(1,1,false);
	life.add(conwayCell);
	ConwayCell* pointer = life.grid[1][1];
	ASSERT_TRUE(pointer->get_x() == 1);
}

TEST(Life, add2)
{
	Life<FredkinCell> life(5,5);
	FredkinCell fredkinCell(1,1,false,0);
	life.add(fredkinCell);
	FredkinCell* pointer = life.grid[1][1];
	ASSERT_TRUE(pointer->get_x() == 1);
}

TEST(Life, add3)
{
	Life<Cell> life(5,5);
	Cell cell = new FredkinCell(1,1,false,0);
	life.add(cell);
	Cell* pointer = life.grid[1][1];
	ASSERT_TRUE(pointer->get_x() == 1);
}

// -------
// check()
// -------

TEST(Life, check1)
{
	Life<ConwayCell> life(5,5);
	ConwayCell conwayCell(1,1,false);
	life.add(conwayCell);
	int numNeighbors = 0;
	life.check(1,1,numNeighbors);
	ASSERT_TRUE(numNeighbors == 0);
}

TEST(Life, check2)
{
	Life<ConwayCell> life(5,5);
	ConwayCell conwayCell(1,1,false);
	life.add(conwayCell);
	conwayCell._x = -1;
	int numNeighbors = 0;
	life.check(-1,1,numNeighbors);
	ASSERT_TRUE(numNeighbors == 0);
}

TEST(Life, check3)
{
	Life<ConwayCell> life(5,5);
	ConwayCell conwayCell(1,1,true);
	life.add(conwayCell);
	int numNeighbors = 0;
	life.check(1,1,numNeighbors);
	ASSERT_TRUE(numNeighbors == 1);
}

// --------------------
// get_cardinal_count()
// --------------------

TEST(Life, get_cardinal_count1)
{
	Life<ConwayCell>* life;
	vector<ConwayCell> cellArray;

	istringstream cells;
	cells.str(".....\n"
			"..*..\n"
			"...*.\n"
			".***.\n"
			".....\n");

	int rows = 5;
	int columns = 5;
	char cell;

	life = new Life<ConwayCell>(rows, columns);
	for(int i = 0; i<rows; i++)
	{
		for(int j = 0; j<columns; j++)
		{
			cells >> cell;
			switch(cell)
			{
				case '.':
					cellArray.push_back(ConwayCell(i,j,false));
					break;
				case '*':
					cellArray.push_back(ConwayCell(i,j,true));
					break;
			}
		}
	}

	int size = cellArray.size();
	for(int i = 0; i<size; i++)
	{
		life->add(cellArray[i]);
	}
	ConwayCell* cellUnderTest = life->grid[1][2];
	int numCardinalNeighbors = life->get_cardinal_count(*cellUnderTest);
	delete life;
	cellArray.clear();
	ASSERT_TRUE(numCardinalNeighbors == 0);
}

TEST(Life, get_cardinal_count2)
{
	Life<ConwayCell>* life;
	vector<ConwayCell> cellArray;

	istringstream cells;
	cells.str(".....\n"
			"..*..\n"
			"...*.\n"
			".***.\n"
			".....\n");

	int rows = 5;
	int columns = 5;
	char cell;

	life = new Life<ConwayCell>(rows, columns);
	for(int i = 0; i<rows; i++)
	{
		for(int j = 0; j<columns; j++)
		{
			cells >> cell;
			switch(cell)
			{
				case '.':
					cellArray.push_back(ConwayCell(i,j,false));
					break;
				case '*':
					cellArray.push_back(ConwayCell(i,j,true));
					break;
			}
		}
	}

	int size = cellArray.size();
	for(int i = 0; i<size; i++)
	{
		life->add(cellArray[i]);
	}
	ConwayCell* cellUnderTest = life->grid[3][2];
	int numCardinalNeighbors = life->get_cardinal_count(*cellUnderTest);
	delete life;
	cellArray.clear();
	ASSERT_TRUE(numCardinalNeighbors == 2);
}

TEST(Life, get_cardinal_count3)
{
	Life<ConwayCell>* life;
	vector<ConwayCell> cellArray;

	istringstream cells;
	cells.str(".....\n"
			"..*..\n"
			"...*.\n"
			".***.\n"
			".....\n");

	int rows = 5;
	int columns = 5;
	char cell;

	life = new Life<ConwayCell>(rows, columns);
	for(int i = 0; i<rows; i++)
	{
		for(int j = 0; j<columns; j++)
		{
			cells >> cell;
			switch(cell)
			{
				case '.':
					cellArray.push_back(ConwayCell(i,j,false));
					break;
				case '*':
					cellArray.push_back(ConwayCell(i,j,true));
					break;
			}
		}
	}

	int size = cellArray.size();
	for(int i = 0; i<size; i++)
	{
		life->add(cellArray[i]);
	}
	ConwayCell* cellUnderTest = life->grid[2][3];
	int numCardinalNeighbors = life->get_cardinal_count(*cellUnderTest);
	delete life;
	cellArray.clear();
	ASSERT_TRUE(numCardinalNeighbors == 1);
}

// -------------------
// get_ordinal_count()
// -------------------

TEST(Life, get_ordinal_count1)
{
	Life<ConwayCell>* life;
	vector<ConwayCell> cellArray;

	istringstream cells;
	cells.str(".....\n"
			"..*..\n"
			"...*.\n"
			".***.\n"
			".....\n");

	int rows = 5;
	int columns = 5;
	char cell;

	life = new Life<ConwayCell>(rows, columns);
	for(int i = 0; i<rows; i++)
	{
		for(int j = 0; j<columns; j++)
		{
			cells >> cell;
			switch(cell)
			{
				case '.':
					cellArray.push_back(ConwayCell(i,j,false));
					break;
				case '*':
					cellArray.push_back(ConwayCell(i,j,true));
					break;
			}
		}
	}

	int size = cellArray.size();
	for(int i = 0; i<size; i++)
	{
		life->add(cellArray[i]);
	}
	ConwayCell* cellUnderTest = life->grid[1][2];
	int numOrdinalNeighbors = life->get_ordinal_count(*cellUnderTest);
	delete life;
	cellArray.clear();
	ASSERT_TRUE(numOrdinalNeighbors == 1);
}

TEST(Life, get_ordinal_count2)
{
	Life<ConwayCell>* life;
	vector<ConwayCell> cellArray;

	istringstream cells;
	cells.str(".....\n"
			"..*..\n"
			"...*.\n"
			".***.\n"
			".....\n");

	int rows = 5;
	int columns = 5;
	char cell;

	life = new Life<ConwayCell>(rows, columns);
	for(int i = 0; i<rows; i++)
	{
		for(int j = 0; j<columns; j++)
		{
			cells >> cell;
			switch(cell)
			{
				case '.':
					cellArray.push_back(ConwayCell(i,j,false));
					break;
				case '*':
					cellArray.push_back(ConwayCell(i,j,true));
					break;
			}
		}
	}

	int size = cellArray.size();
	for(int i = 0; i<size; i++)
	{
		life->add(cellArray[i]);
	}
	ConwayCell* cellUnderTest = life->grid[0][0];
	int numOrdinalNeighbors = life->get_ordinal_count(*cellUnderTest);
	delete life;
	cellArray.clear();
	ASSERT_TRUE(numOrdinalNeighbors == 0);
}

TEST(Life, get_ordinal_count3)
{
	Life<ConwayCell>* life;
	vector<ConwayCell> cellArray;

	istringstream cells;
	cells.str(".....\n"
			"..*..\n"
			"...*.\n"
			".***.\n"
			".....\n");

	int rows = 5;
	int columns = 5;
	char cell;

	life = new Life<ConwayCell>(rows, columns);
	for(int i = 0; i<rows; i++)
	{
		for(int j = 0; j<columns; j++)
		{
			cells >> cell;
			switch(cell)
			{
				case '.':
					cellArray.push_back(ConwayCell(i,j,false));
					break;
				case '*':
					cellArray.push_back(ConwayCell(i,j,true));
					break;
			}
		}
	}

	int size = cellArray.size();
	for(int i = 0; i<size; i++)
	{
		life->add(cellArray[i]);
	}
	ConwayCell* cellUnderTest = life->grid[3][2];
	int numOrdinalNeighbors = life->get_ordinal_count(*cellUnderTest);
	delete life;
	cellArray.clear();
	ASSERT_TRUE(numOrdinalNeighbors == 1);
}

// ----------
// simulate()
// ----------

TEST(Life, simulate1)
{
	Life<ConwayCell>* life;
	vector<ConwayCell> cellArray;

	istringstream cells;
	cells.str(".....\n"
			"..*..\n"
			"...*.\n"
			".***.\n"
			".....\n");

	int rows = 5;
	int columns = 5;
	char cell;

	life = new Life<ConwayCell>(rows, columns);
	for(int i = 0; i<rows; i++)
	{
		for(int j = 0; j<columns; j++)
		{
			cells >> cell;
			switch(cell)
			{
				case '.':
					cellArray.push_back(ConwayCell(i,j,false));
					break;
				case '*':
					cellArray.push_back(ConwayCell(i,j,true));
					break;
			}
		}
	}

	int size = cellArray.size();
	for(int i = 0; i<size; i++)
	{
		life->add(cellArray[i]);
	}
	ConwayCell* cellUnderTest = life->grid[0][0];
	unordered_set<int> specificGrids;
	life->simulate(1, -1, -1, specificGrids);
	delete life;
	cellArray.clear();
	ASSERT_TRUE(cellUnderTest->is_alive() == false);
}

TEST(Life, simulate2)
{
	Life<ConwayCell>* life;
	vector<ConwayCell> cellArray;

	istringstream cells;
	cells.str(".....\n"
			"..*..\n"
			"...*.\n"
			".***.\n"
			".....\n");

	int rows = 5;
	int columns = 5;
	char cell;

	life = new Life<ConwayCell>(rows, columns);
	for(int i = 0; i<rows; i++)
	{
		for(int j = 0; j<columns; j++)
		{
			cells >> cell;
			switch(cell)
			{
				case '.':
					cellArray.push_back(ConwayCell(i,j,false));
					break;
				case '*':
					cellArray.push_back(ConwayCell(i,j,true));
					break;
			}
		}
	}

	int size = cellArray.size();
	for(int i = 0; i<size; i++)
	{
		life->add(cellArray[i]);
	}
	ConwayCell* cellUnderTest = life->grid[3][2];
	unordered_set<int> specificGrids;
	life->simulate(5,-1,-1,specificGrids);
	delete life;
	cellArray.clear();
	ASSERT_TRUE(cellUnderTest->is_alive() == true);
}

TEST(Life, simulate3)
{
	Life<ConwayCell>* life;
	vector<ConwayCell> cellArray;

	istringstream cells;
	cells.str(".....\n"
			"..*..\n"
			"...*.\n"
			".***.\n"
			".....\n");

	int rows = 5;
	int columns = 5;
	char cell;

	life = new Life<ConwayCell>(rows, columns);
	for(int i = 0; i<rows; i++)
	{
		for(int j = 0; j<columns; j++)
		{
			cells >> cell;
			switch(cell)
			{
				case '.':
					cellArray.push_back(ConwayCell(i,j,false));
					break;
				case '*':
					cellArray.push_back(ConwayCell(i,j,true));
					break;
			}
		}
	}

	int size = cellArray.size();
	for(int i = 0; i<size; i++)
	{
		life->add(cellArray[i]);
	}
	ConwayCell* cellUnderTest = life->grid[2][3];
	unordered_set<int> specificGrids;
	life->simulate(5, -1, -1, specificGrids);
	delete life;
	cellArray.clear();
	ASSERT_TRUE(cellUnderTest->is_alive() == false);
}
