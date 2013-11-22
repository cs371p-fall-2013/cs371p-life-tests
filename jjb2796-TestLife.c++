// ----------------------------
// Project by:
//    Jeremiah Bonney (jjb2796)
//    Daniel Roberston (cdr966)
// ----------------------------

// --------
// includes
// --------
#define protected public
#define private public

#include "gtest/gtest.h"
#include "AbstractCell.h"
#include "Cell.h"
#include "FredkinCell.h"
#include "ConwayCell.h"
#include "Life.h"
 
// -----------------
// ConwayCell tests
// -----------------
TEST(ConwayCell, constructor) 
{
	ConwayCell cc; 
    ASSERT_EQ(0, cc.is_alive); 
    ASSERT_TRUE(cc.avatar == '.'); 
}

TEST(ConwayCell, constructor_alive) 
{
	ConwayCell cc(true, '*');
    ASSERT_EQ(1, cc.is_alive); 
    ASSERT_TRUE(cc.avatar == '*'); 
}

TEST(ConwayCell, constructor_dead) 
{
	ConwayCell cc(false, '.');
    ASSERT_EQ(0, cc.is_alive); 
    ASSERT_TRUE(cc.avatar == '.'); 
}

TEST(ConwayCell, resurrect) 
{
	ConwayCell cc; 
    ASSERT_EQ(0, cc.is_alive); 
    ASSERT_TRUE(cc.avatar == '.'); 

	cc.resurrect(); 

	ASSERT_EQ(1, cc.is_alive); 
    ASSERT_TRUE(cc.avatar == '*'); 

    cc.resurrect(); 
	ASSERT_EQ(1, cc.is_alive); 
    ASSERT_TRUE(cc.avatar == '*'); 
}


TEST(ConwayCell, die) 
{
	ConwayCell cc; 
    ASSERT_EQ(0, cc.is_alive); 
    ASSERT_TRUE(cc.avatar == '.'); 
	
	cc.is_alive = true; 
	cc.avatar = '*';
	ASSERT_EQ(1, cc.is_alive); 
    ASSERT_TRUE(cc.avatar == '*'); 
    
	cc.die(); 
	ASSERT_EQ(0, cc.is_alive); 
    ASSERT_TRUE(cc.avatar == '.'); 
}

// ***********************

TEST(ConwayCell, update_dead_unchanged_zero_alive) 
{
	ConwayCell cc; 
	bool neighbors[3][3] = {
		{0,0,0},{0,0,0},{0,0,0}
	}; 
    ASSERT_TRUE(!cc.is_alive); 
    ASSERT_TRUE(cc.avatar == '.'); 

	transition_enum t = cc.update(neighbors); 

	ASSERT_TRUE(t == UNCHANGED); 
}

TEST(ConwayCell, update_dead_unchanged_one_alive) 
{
	ConwayCell cc; 
	bool neighbors[3][3] = {
		{1,0,0},{0,0,0},{0,0,0}
	}; 
    ASSERT_TRUE(!cc.is_alive); 
    ASSERT_TRUE(cc.avatar == '.'); 

	transition_enum t = cc.update(neighbors); 

	ASSERT_TRUE(t == UNCHANGED); 
}

TEST(ConwayCell, update_dead_unchanged_two_alive) 
{
	ConwayCell cc; 
	bool neighbors[3][3] = {
		{1,0,0},{0,1,0},{0,1,0}
	}; 
    ASSERT_TRUE(!cc.is_alive); 
    ASSERT_TRUE(cc.avatar == '.'); 

	transition_enum t = cc.update(neighbors); 

	ASSERT_TRUE(t == UNCHANGED); 
}

TEST(ConwayCell, update_to_alive_exactly_three_alive) 
{
	ConwayCell cc; 
	bool neighbors[3][3] = {
		{1,1,0},{0,1,0},{0,1,0}
	}; 
    ASSERT_TRUE(!cc.is_alive); 
    ASSERT_TRUE(cc.avatar == '.'); 

	transition_enum t = cc.update(neighbors); 

	ASSERT_TRUE(t == TO_ALIVE); 
}

TEST(ConwayCell, update_dead_unchanged_four_alive) 
{
	ConwayCell cc; 
	bool neighbors[3][3] = {
		{1,1,1},{0,1,0},{0,1,0}
	}; 
    ASSERT_TRUE(!cc.is_alive); 
    ASSERT_TRUE(cc.avatar == '.'); 

	transition_enum t = cc.update(neighbors); 

	ASSERT_TRUE(t == UNCHANGED); 
}

TEST(ConwayCell, update_dead_unchanged_five_alive) 
{
	ConwayCell cc; 
	bool neighbors[3][3] = {
		{1,1,1},{0,1,0},{1,1,0}
	}; 
    ASSERT_TRUE(!cc.is_alive); 
    ASSERT_TRUE(cc.avatar == '.'); 

	transition_enum t = cc.update(neighbors); 

	ASSERT_TRUE(t == UNCHANGED); 
}


TEST(ConwayCell, update_to_dead_zero_alive) 
{
	ConwayCell cc; 
	bool neighbors[3][3] = {
		{0,0,0},{0,1,0},{0,0,0}
	}; 
    ASSERT_TRUE(!cc.is_alive); 
    ASSERT_TRUE(cc.avatar == '.'); 

    cc.resurrect(); 

	ASSERT_EQ(1, cc.is_alive); 
    ASSERT_TRUE(cc.avatar == '*'); 

	transition_enum t = cc.update(neighbors); 

	ASSERT_TRUE(t == TO_DEAD); 
}

TEST(ConwayCell, update_to_dead_one_alive) 
{
	ConwayCell cc; 
	bool neighbors[3][3] = {
		{1,0,0},{0,1,0},{0,0,0}
	}; 
    ASSERT_TRUE(!cc.is_alive); 
    ASSERT_TRUE(cc.avatar == '.'); 

    cc.resurrect(); 

	ASSERT_EQ(1, cc.is_alive); 
    ASSERT_TRUE(cc.avatar == '*'); 

	transition_enum t = cc.update(neighbors); 

	ASSERT_TRUE(t == TO_DEAD); 
}

TEST(ConwayCell, update_to_dead_four_alive) 
{
	ConwayCell cc; 
	bool neighbors[3][3] = {
		{1,1,0},{0,1,0},{0,1,1}
	}; 
    ASSERT_TRUE(!cc.is_alive); 
    ASSERT_TRUE(cc.avatar == '.'); 

    cc.resurrect(); 

	ASSERT_EQ(1, cc.is_alive); 
    ASSERT_TRUE(cc.avatar == '*'); 

	transition_enum t = cc.update(neighbors); 

	ASSERT_TRUE(t == TO_DEAD); 
}

TEST(ConwayCell, update_to_dead_five_alive) 
{
	ConwayCell cc; 
	bool neighbors[3][3] = {
		{1,1,1},{0,1,0},{1,1,0}
	}; 
    ASSERT_TRUE(!cc.is_alive); 
    ASSERT_TRUE(cc.avatar == '.'); 

    cc.resurrect(); 

	ASSERT_EQ(1, cc.is_alive); 
    ASSERT_TRUE(cc.avatar == '*'); 

	transition_enum t = cc.update(neighbors); 

	ASSERT_TRUE(t == TO_DEAD); 
}

TEST(ConwayCell, update_to_dead_all_alive) 
{
	ConwayCell cc; 
	bool neighbors[3][3] = {
		{1,1,1},{1,1,1},{1,1,1}
	}; 
    ASSERT_TRUE(!cc.is_alive); 
    ASSERT_TRUE(cc.avatar == '.'); 

    cc.resurrect(); 

	ASSERT_EQ(1, cc.is_alive); 
    ASSERT_TRUE(cc.avatar == '*'); 

	transition_enum t = cc.update(neighbors); 

	ASSERT_TRUE(t == TO_DEAD); 
}

// -----------------
// FredkinCell tests
// -----------------

TEST(FredkinCell, constructor) 
{
	FredkinCell fc; 
    ASSERT_EQ(0, fc.is_alive); 
    ASSERT_TRUE(fc.avatar == '-'); 
}

TEST(FredkinCell, constructor_alive) 
{
	FredkinCell fc(true, '0', 0);
    ASSERT_EQ(1, fc.is_alive); 
    ASSERT_TRUE(fc.avatar == '0'); 
}

TEST(FredkinCell, constructor_alive_ten) 
{
	FredkinCell fc(true, '+', 10);
    ASSERT_EQ(1, fc.is_alive); 
    ASSERT_TRUE(fc.avatar == '+'); 
}

TEST(FredkinCell, constructor_dead_ten) 
{
	FredkinCell fc(false, '-', 10);
    ASSERT_EQ(0, fc.is_alive); 
    ASSERT_TRUE(fc.avatar == '-'); 
}

TEST(FredkinCell, constructor_dead) 
{
	FredkinCell fc(false, '-', 0);
    ASSERT_EQ(0, fc.is_alive); 
    ASSERT_TRUE(fc.avatar == '-'); 
}

TEST(FredkinCell, resurrect_younger_than_10) 
{
	FredkinCell fc; 
    ASSERT_EQ(0, fc.is_alive); 
    ASSERT_TRUE(fc.avatar == '-'); 

	fc.resurrect(); 

	ASSERT_EQ(1, fc.is_alive); 
    ASSERT_TRUE(fc.avatar == '0'); 

    fc.age = 5; 
    fc.resurrect(); 
	ASSERT_EQ(1, fc.is_alive); 
    ASSERT_TRUE(fc.avatar == '5'); 
}

TEST(FredkinCell, resurrect_older_than_10) 
{
	FredkinCell fc; 
    ASSERT_EQ(0, fc.is_alive); 
    ASSERT_TRUE(fc.avatar == '-'); 

 	fc.age = 11; 
	fc.resurrect(); 

	ASSERT_EQ(1, fc.is_alive); 
    ASSERT_TRUE(fc.avatar == '+'); 
}

TEST(FredkinCell, die) 
{
	FredkinCell fc; 
    ASSERT_EQ(0, fc.is_alive); 
    ASSERT_TRUE(fc.avatar == '-'); 
	
	fc.is_alive = true; 
	fc.avatar = '0';
	ASSERT_EQ(1, fc.is_alive); 
    ASSERT_TRUE(fc.avatar == '0'); 
    
	fc.die(); 
	ASSERT_EQ(0, fc.is_alive); 
    ASSERT_TRUE(fc.avatar == '-'); 
}

TEST(FredkinCell, update_dead_unchanged) 
{
	FredkinCell fc; 
	bool neighbors[3][3] = {
		{0,0,0},{0,0,0},{0,0,0}
	}; 
    ASSERT_TRUE(!fc.is_alive); 
    ASSERT_TRUE(fc.avatar == '-'); 

	transition_enum t = fc.update(neighbors); 

	ASSERT_TRUE(t == UNCHANGED); 
}

TEST(FredkinCell, update_dead_to_alive_one_alive) 
{
	FredkinCell fc; 
	bool neighbors[3][3] = {
		{1,1,1},{0,1,0},{1,0,1} 
	}; // ignore cells we don't care about
    ASSERT_TRUE(!fc.is_alive); 
    ASSERT_TRUE(fc.avatar == '-'); 

	transition_enum t = fc.update(neighbors); 

	ASSERT_TRUE(t == TO_ALIVE);
	ASSERT_TRUE(fc.age == 0); 
}

TEST(FredkinCell, update_dead_unchanged_two_alive) 
{
	FredkinCell fc; 
	bool neighbors[3][3] = {
		{0,1,0},{0,0,0},{0,1,0}
	}; 
    ASSERT_TRUE(!fc.is_alive); 
    ASSERT_TRUE(fc.avatar == '-'); 

	transition_enum t = fc.update(neighbors); 

	ASSERT_TRUE(t == UNCHANGED); 
}

TEST(FredkinCell, update_dead_to_alive_three_alive) 
{
	FredkinCell fc; 
	bool neighbors[3][3] = {
		{1,1,1},{1,1,0},{1,1,1} 
	}; 
    ASSERT_TRUE(!fc.is_alive); 
    ASSERT_TRUE(fc.avatar == '-'); 

	transition_enum t = fc.update(neighbors); 

	ASSERT_TRUE(t == TO_ALIVE);
	ASSERT_TRUE(fc.age == 0); 
}

TEST(FredkinCell, update_dead_unchanged_four_alive) 
{
	FredkinCell fc; 
	bool neighbors[3][3] = {
		{0,1,0},{1,1,1},{0,1,0}
	}; 
    ASSERT_TRUE(!fc.is_alive); 
    ASSERT_TRUE(fc.avatar == '-'); 

	transition_enum t = fc.update(neighbors); 

	ASSERT_TRUE(t == UNCHANGED); 
}

TEST(FredkinCell, update_live_to_dead_zero_alive) 
{
	FredkinCell fc; 
	bool neighbors[3][3] = {
		{0,0,0},{0,1,0},{0,0,0}
	}; 
    ASSERT_TRUE(!fc.is_alive); 
    ASSERT_TRUE(fc.avatar == '-'); 

    fc.resurrect(); 
    ASSERT_TRUE(fc.is_alive); 
    ASSERT_TRUE(fc.avatar == '0'); 

	transition_enum t = fc.update(neighbors); 

	ASSERT_TRUE(t == TO_DEAD); 
}

TEST(FredkinCell, update_live_unchanged_one_alive) 
{
	FredkinCell fc; 
	bool neighbors[3][3] = {
		{0,0,0},{0,1,1},{0,0,0}
	}; 
    ASSERT_TRUE(!fc.is_alive); 
    ASSERT_TRUE(fc.avatar == '-'); 

    fc.resurrect(); 
    ASSERT_TRUE(fc.is_alive); 
    ASSERT_TRUE(fc.avatar == '0'); 

	transition_enum t = fc.update(neighbors); 

	ASSERT_TRUE(t == UNCHANGED); 
}

TEST(FredkinCell, update_live_to_dead_two_alive) 
{
	FredkinCell fc; 
	bool neighbors[3][3] = {
		{0,0,0},{1,1,1},{0,0,0}
	}; 
    ASSERT_TRUE(!fc.is_alive); 
    ASSERT_TRUE(fc.avatar == '-'); 

    fc.resurrect(); 
    ASSERT_TRUE(fc.is_alive); 
    ASSERT_TRUE(fc.avatar == '0'); 

	transition_enum t = fc.update(neighbors); 

	ASSERT_TRUE(t == TO_DEAD); 
}

TEST(FredkinCell, update_live_unchanged_three_alive) 
{
	FredkinCell fc; 
	bool neighbors[3][3] = {
		{0,1,0},{0,1,1},{0,1,0}
	}; 
    ASSERT_TRUE(!fc.is_alive); 
    ASSERT_TRUE(fc.avatar == '-'); 

    fc.resurrect(); 
    ASSERT_TRUE(fc.is_alive); 
    ASSERT_TRUE(fc.avatar == '0'); 

	transition_enum t = fc.update(neighbors); 

	ASSERT_TRUE(t == UNCHANGED); 
}

TEST(FredkinCell, update_live_to_dead_four_alive) 
{
	FredkinCell fc; 
	bool neighbors[3][3] = {
		{0,1,0},{1,1,1},{0,1,0}
	}; 
    ASSERT_TRUE(!fc.is_alive); 
    ASSERT_TRUE(fc.avatar == '-'); 

    fc.resurrect(); 
    ASSERT_TRUE(fc.is_alive); 
    ASSERT_TRUE(fc.avatar == '0'); 

	transition_enum t = fc.update(neighbors); 

	ASSERT_TRUE(t == TO_DEAD); 
}

TEST(FredkinCell, clone) 
{
	FredkinCell fc; ; 
	FredkinCell* fc_ptr = fc.clone();
	ASSERT_TRUE(fc_ptr->avatar == fc.avatar); 
	ASSERT_TRUE(fc_ptr->age == fc.age); 
	ASSERT_TRUE(fc_ptr->is_alive == fc.is_alive); 
	delete fc_ptr;
}

TEST(FredkinCell, clone_alive_age_0) 
{
	FredkinCell fc(true, '0', 0);
	FredkinCell* fc_clone = fc.clone();
	ASSERT_TRUE(fc_clone->avatar == fc.avatar); 
	ASSERT_TRUE(fc_clone->age == fc.age); 
	ASSERT_TRUE(fc_clone->is_alive == fc.is_alive); 
	delete fc_clone;
}

TEST(FredkinCell, clone_alive_age_10) 
{
	FredkinCell fc(true, '+', 10);
	FredkinCell* fc_clone = fc.clone();
	ASSERT_TRUE(fc_clone->avatar == fc.avatar); 
	ASSERT_TRUE(fc_clone->age == fc.age); 
	ASSERT_TRUE(fc_clone->is_alive == fc.is_alive); 
	delete fc_clone;
}

TEST(FredkinCell, copy_constructor_dead_age_0)
{
	FredkinCell fc; 
	FredkinCell fc2(fc); 
	ASSERT_TRUE(fc2.avatar == fc.avatar); 
	ASSERT_TRUE(fc2.age == fc.age); 
	ASSERT_TRUE(fc2.is_alive == fc.is_alive); 
}


TEST(FredkinCell, copy_constructor_alive_age_10)
{
	FredkinCell fc(true, '+', 10); 
	FredkinCell fc2(fc); 
	ASSERT_TRUE(fc2.avatar == fc.avatar); 
	ASSERT_TRUE(fc2.age == fc.age); 
	ASSERT_TRUE(fc2.is_alive == fc.is_alive); 
}

// -----------------
// Life tests
// -----------------

TEST(Life, constructor_2_by_3) 
{
	Life<ConwayCell> life(2, 3); 
    ASSERT_TRUE(life._rows == 2);
    ASSERT_TRUE(life._columns == 3);
    for (int i = 0; i < life._rows; ++i) 
    {
    	for (int j = 0; j < life._columns; ++j)
    	{
    		ASSERT_EQ(0, life._grid[i][j].is_alive);
    	}
    }
}

 
TEST(Life, constructor_500_by_500) 
{
	Life<ConwayCell> life(500, 500); 
    ASSERT_TRUE(life._rows == 500);
    ASSERT_TRUE(life._columns == 500);
    for (int i = 0; i < life._rows; ++i) 
    {
    	for (int j = 0; j < life._columns; ++j)
    	{
    		ASSERT_EQ(0, life._grid[i][j].is_alive);
    	}
    }
}

TEST(Life, constructor_100_by_200)
{
	Life<ConwayCell> life(100, 200); 
    ASSERT_TRUE(life._rows == 100);
    ASSERT_TRUE(life._columns == 200);
    for (int i = 0; i < life._rows; ++i) 
    {
    	for (int j = 0; j < life._columns; ++j)
    	{
    		ASSERT_EQ(0, life._grid[i][j].is_alive);
    	}
    }
}

TEST(Life, resurrect_1_Conway)
{
	Life<ConwayCell> life(10, 10); 
	ASSERT_EQ(0, life._grid[2][2].is_alive);
	ASSERT_EQ('.', life._grid[2][2].avatar);

	life.resurrect(2,2);

	ASSERT_EQ(1, life._grid[2][2].is_alive);
	ASSERT_EQ('*', life._grid[2][2].avatar);
}

TEST(Life, resurrect_10_Conway)
{
	Life<ConwayCell> life(10, 10); 
	for(int i = 0; i < 10; i++)
	{
		life.resurrect(0,i);
		ASSERT_EQ(1, life._grid[0][i].is_alive);
		ASSERT_EQ('*', life._grid[0][i].avatar);
	}
}

TEST(Life, resurrect_all_Conway)
{
	Life<ConwayCell> life(100, 100); 
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			life.resurrect(0,i);
			ASSERT_EQ(1, life._grid[0][i].is_alive);
			ASSERT_EQ('*', life._grid[0][i].avatar);
		}
	}
}

TEST(Life, build_neighbors_all_dead)
{
	Life<ConwayCell> life(10, 10);
	bool neighbors[3][3] = {{false}};
	life.build_neighbors(neighbors, 5, 5);
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			ASSERT_EQ(0, neighbors[i][j]);
		}
	}
}

TEST(Life, build_neighbors_all_alive)
{
	Life<ConwayCell> life(10, 10);
	bool neighbors[3][3] = {{false}};

	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			life.resurrect(i, j);
		}
	}

	life.build_neighbors(neighbors, 5, 5);
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			ASSERT_EQ(1, neighbors[i][j]);
		}
	}
}

TEST(Life, build_neighbors_alive_on_wall)
{
	Life<ConwayCell> life(10, 10);
	bool neighbors[3][3] = {{false}};

	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			life.resurrect(i, j);
		}
	}

	life.build_neighbors(neighbors, 0, 5);
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(i == 0)
			{
				ASSERT_EQ(0, neighbors[i][j]);
			}
			else
			{
				ASSERT_EQ(1, neighbors[i][j]);
			}
		}
	}
}

TEST(Life, build_neighbors_alive_on_corner)
{
	Life<ConwayCell> life(10, 10);
	bool neighbors[3][3] = {{false}};

	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			life.resurrect(i, j);
		}
	}

	life.build_neighbors(neighbors, 0, 0);
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(i == 0 || j == 0)
			{
				ASSERT_EQ(0, neighbors[i][j]);
			}
			else
			{
				ASSERT_EQ(1, neighbors[i][j]);
			}
		}
	}
}

TEST(Life, update_grid_unchanged)
{
	Life<ConwayCell> life(10, 10); // all dead 
	life.update(); 
	for(int i = 0; i < life._rows; i++) 
	{
		for(int j = 0; j < life._columns; j++)
		{
			ASSERT_TRUE(!life._grid[i][j].is_alive);
			ASSERT_TRUE(life._grid[i][j].avatar == '.'); 
		}
	}
}

TEST(Life, update_grid_one_dies_surrounded_by_nothing)
{
	Life<ConwayCell> life(10, 10); 
	life._grid[5][5].resurrect(); 
	ASSERT_TRUE(life._grid[5][5].is_alive); 
	ASSERT_EQ('*', life._grid[5][5].avatar); 

	life.update(); 
	for(int i = 0; i < life._rows; i++) 
	{
		for(int j = 0; j < life._columns; j++)
		{
			ASSERT_TRUE(!life._grid[i][j].is_alive);
			ASSERT_TRUE(life._grid[i][j].avatar == '.'); 
		}
	}
}

TEST(Life, update_two_alive_all_die)
{
	Life<ConwayCell> life(10, 10); 
	life._grid[5][5].resurrect(); 
	ASSERT_TRUE(life._grid[5][5].is_alive); 
	ASSERT_EQ('*', life._grid[5][5].avatar); 

	life._grid[5][6].resurrect(); 
	ASSERT_TRUE(life._grid[5][6].is_alive); 
	ASSERT_EQ('*', life._grid[5][6].avatar); 

	life.update(); 
	for(int i = 0; i < life._rows; i++) 
	{
		for(int j = 0; j < life._columns; j++)
		{
			ASSERT_TRUE(!life._grid[i][j].is_alive);
			ASSERT_TRUE(life._grid[i][j].avatar == '.'); 
		}
	}
}

TEST(Life, update_three_alive_all_die)
{
	Life<ConwayCell> life(10, 10); 
	life._grid[5][5].resurrect(); 
	ASSERT_TRUE(life._grid[5][5].is_alive); 
	ASSERT_EQ('*', life._grid[5][5].avatar); 

	life._grid[5][6].resurrect(); 
	ASSERT_TRUE(life._grid[5][6].is_alive); 
	ASSERT_EQ('*', life._grid[5][6].avatar); 

	life._grid[5][4].resurrect(); 
	ASSERT_TRUE(life._grid[5][4].is_alive); 
	ASSERT_EQ('*', life._grid[5][4].avatar); 

	life.update(); 
	for(int i = 0; i < life._rows; i++) 
	{
		for(int j = 0; j < life._columns; j++)
		{
			if((i == 5 && j == 5) || (i == 4 && j == 5) || (i == 6 && j == 5)) 
			{
				ASSERT_TRUE(life._grid[i][j].is_alive);
				ASSERT_TRUE(life._grid[i][j].avatar == '*'); 
			}
			else 
			{
				ASSERT_TRUE(!life._grid[i][j].is_alive);
				ASSERT_TRUE(life._grid[i][j].avatar == '.'); 				
			}
		}
	}
}

// -----------------
// Cell tests 
// -----------------
TEST(Cell, constructor_default)
{
	Cell c; 
	ASSERT_TRUE(!c.is_alive); 
	ASSERT_EQ('-', c._p->avatar); 
}

TEST(Cell, constructor_live_fredkin)
{
	Cell c = new FredkinCell(true, '0', 0); 
	ASSERT_TRUE(c.is_alive); 
	ASSERT_EQ('0', c._p->avatar); 
	
}

TEST(Cell, constructor_live_conway)
{
	Cell c = new ConwayCell(); 
	c.resurrect(); 
	ASSERT_TRUE(c.is_alive); 
	ASSERT_EQ('*', c._p->avatar); 
	
}

TEST(Cell, update_fredkin)
{
	Cell c; 
	ASSERT_TRUE(!c.is_alive); 
	ASSERT_EQ('-', c._p->avatar); 

	bool neighbors[3][3] = {{false}};
	c.update(neighbors); 

	ASSERT_TRUE(!c.is_alive); 
	ASSERT_EQ('-', c._p->avatar); 
}

TEST(Cell, update_conway)
{
	Cell c = new ConwayCell(); 
	ASSERT_TRUE(!c.is_alive); 
	ASSERT_EQ('.', c._p->avatar); 

	bool neighbors[3][3] = {{false}};
	c.update(neighbors); 

	ASSERT_TRUE(!c.is_alive); 
	ASSERT_EQ('.', c._p->avatar);
	 
}

TEST(Cell, update_live_fredkin_to_dead)
{
	Cell c; 
	ASSERT_TRUE(!c.is_alive); 
	ASSERT_EQ('-', c._p->avatar); 

	c.resurrect(); 

	bool neighbors[3][3] = {{false}};
	ASSERT_EQ(TO_DEAD, c.update(neighbors));
}

TEST(Cell, update_live_conway_to_dead)
{
	Cell c = new ConwayCell(); 
	ASSERT_TRUE(!c.is_alive); 
	ASSERT_EQ('.', c._p->avatar); 

	c.resurrect(); 

	bool neighbors[3][3] = {{false}};
	c.update(neighbors); 
	ASSERT_EQ(TO_DEAD, c.update(neighbors));
	
}

TEST(Cell, update_live_conway_to_dead_one_live_neighbor)
{
	Cell c = new ConwayCell(); 
	ASSERT_TRUE(!c.is_alive); 
	ASSERT_EQ('.', c._p->avatar); 

	c.resurrect(); 

	bool neighbors[3][3] = {
		{0,1,0},{0,1,0},{0,0,0}
	}; 
	c.update(neighbors); 
	ASSERT_EQ(TO_DEAD, c.update(neighbors));
	
}

TEST(Cell, update_live_conway_to_dead_four_live_neighbors)
{
	Cell c = new ConwayCell(); 
	ASSERT_TRUE(!c.is_alive); 
	ASSERT_EQ('.', c._p->avatar); 

	c.resurrect(); 

	bool neighbors[3][3] = {
		{0,1,1},{1,1,1},{1,0,0}
	}; 
	c.update(neighbors); 
	ASSERT_EQ(TO_DEAD, c.update(neighbors));
	
}

TEST(Cell, update_live_conway_to_dead_five_live_neighbors)
{
	Cell c = new ConwayCell(); 
	ASSERT_TRUE(!c.is_alive); 
	ASSERT_EQ('.', c._p->avatar); 

	c.resurrect(); 

	bool neighbors[3][3] = {
		{0,1,1},{1,1,1},{1,1,0}
	}; 
	c.update(neighbors); 
	ASSERT_EQ(TO_DEAD, c.update(neighbors));
	
}

TEST(Cell, update_live_conway_unchanged_two_live_neighbors)
{
	Cell c = new ConwayCell(); 
	ASSERT_TRUE(!c.is_alive); 
	ASSERT_EQ('.', c._p->avatar); 

	c.resurrect(); 

	bool neighbors[3][3] = {
		{0,1,1},{0,1,0},{0,0,0}
	}; 
	c.update(neighbors); 
	ASSERT_EQ(UNCHANGED, c.update(neighbors));
	
}

TEST(Cell, update_live_conway_unchanged_three_live_neighbors)
{
	Cell c = new ConwayCell(); 
	ASSERT_TRUE(!c.is_alive); 
	ASSERT_EQ('.', c._p->avatar); 

	c.resurrect(); 

	bool neighbors[3][3] = {
		{0,1,1},{1,1,0},{0,0,0}
	}; 
	c.update(neighbors); 
	ASSERT_EQ(UNCHANGED, c.update(neighbors));
	
}


TEST(Cell, update_dead_conway_unchanged_zero_live_neighbors)
{
	Cell c = new ConwayCell(); 
	ASSERT_TRUE(!c.is_alive); 
	ASSERT_EQ('.', c._p->avatar); 

	bool neighbors[3][3] = {
		{0,0,0},{0,1,0},{0,0,0}
	}; 
	
	c.update(neighbors); 
	ASSERT_EQ(UNCHANGED, c.update(neighbors));
	
}

TEST(Cell, update_dead_conway_unchanged_one_live_neighbor)
{
	Cell c = new ConwayCell(); 
	ASSERT_TRUE(!c.is_alive); 
	ASSERT_EQ('.', c._p->avatar); 

	bool neighbors[3][3] = {
		{0,1,0},{0,1,0},{0,0,0}
	}; 

	c.update(neighbors); 
	ASSERT_EQ(UNCHANGED, c.update(neighbors));
	
}


TEST(Cell, update_dead_conway_unchanged_two_live_neighbors)
{
	Cell c = new ConwayCell(); 
	ASSERT_TRUE(!c.is_alive); 
	ASSERT_EQ('.', c._p->avatar); 

	bool neighbors[3][3] = {
		{0,1,1},{0,1,0},{0,0,0}
	}; 
	
	c.update(neighbors); 
	ASSERT_EQ(UNCHANGED, c.update(neighbors));
	
}

TEST(Cell, update_dead_conway_unchanged_four_live_neighbors)
{
	Cell c = new ConwayCell(); 
	ASSERT_TRUE(!c.is_alive); 
	ASSERT_EQ('.', c._p->avatar); 

	bool neighbors[3][3] = {
		{0,1,1},{1,1,1},{0,0,0}
	}; 
	
	c.update(neighbors); 
	ASSERT_EQ(UNCHANGED, c.update(neighbors));
	
}

TEST(Cell, update_dead_conway_unchanged_five_live_neighbors)
{
	Cell c = new ConwayCell(); 
	ASSERT_TRUE(!c.is_alive); 
	ASSERT_EQ('.', c._p->avatar); 

	bool neighbors[3][3] = {
		{0,1,1},{1,1,1},{0,0,0}
	}; 
	
	c.update(neighbors); 
	ASSERT_EQ(UNCHANGED, c.update(neighbors));
	
}

TEST(Cell, update_dead_conway_to_alive_three_live_neighbors)
{
	Cell c = new ConwayCell(); 
	ASSERT_TRUE(!c.is_alive); 
	ASSERT_EQ('.', c._p->avatar); 

	bool neighbors[3][3] = {
		{0,1,1},{0,1,1},{0,0,0}
	}; 
	
	c.update(neighbors); 
	ASSERT_EQ(TO_ALIVE, c.update(neighbors));

}

TEST(Cell, mutate)
{
	Cell c; 
	ASSERT_EQ('-', c._p->avatar); 
	c.mutate(); 
	ASSERT_EQ('*', c._p->avatar); 
}

TEST(Cell, mutate_alive)
{
	Cell c;
	ASSERT_EQ('-', c._p->avatar);

	c.resurrect(); 

	c.mutate(); 
	ASSERT_EQ('*', c._p->avatar); 
}

TEST(Cell, die)
{
	Cell c; 
	ASSERT_EQ('-', c._p->avatar); 
	ASSERT_TRUE(!c.is_alive); 
	c.die(); 
	ASSERT_EQ('-', c._p->avatar); 
	ASSERT_TRUE(!c.is_alive); 
}

TEST(Cell, die_alive)
{
	Cell c; 
	c.resurrect(); 
	ASSERT_EQ('0', c._p->avatar); 
	ASSERT_TRUE(c.is_alive);
	c.die(); 
	ASSERT_EQ('-', c._p->avatar); 
	ASSERT_TRUE(!c.is_alive);
}