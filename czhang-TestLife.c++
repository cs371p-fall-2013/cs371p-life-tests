#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

#include "gtest/gtest.h"

#include "AbstractCell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"
#include "Life.h"

TEST(ConwayCell, constructor_alive)
{
	ConwayCell c(true);
	ASSERT_TRUE(c.is_alive());
}

TEST(ConwayCell, constructor_dead)
{
	ConwayCell c(false);
	ASSERT_FALSE(c.is_alive());
}

TEST(ConwayCell, get_age)
{
	ConwayCell c(true);
	ASSERT_EQ(c.get_age(), -1);
}

TEST(ConwayCell, get_age_increment)
{
	ConwayCell c(true);
	ASSERT_EQ(c.get_age(), -1);
	c.update(true, true, true, false, false, false, false, false);
	c.step();
	ASSERT_EQ(c.get_age(), -1);
}

TEST(ConwayCell, update_and_step)
{
	ConwayCell c(true);

	bool prev_stat = true;

	for (unsigned int i = 0; i < 256; ++i)
	{
		bool t = false, tr = false, r = false, br = false, b = false, bl = false, l = false, tl = false;

		size_t num_alive = 0;

		if (0x1 & i) 
		{
			t = true;
			++num_alive;
		}
		if (0x2 & i)
		{
			tr = true;
			++num_alive;
		}
		if (0x4 & i)
		{
			r = true;
			++num_alive;
		}
		if (0x8 & i)
		{
			br = true;
			++num_alive;
		}
		if (0x10 & i)
		{
			b = true;
			++num_alive;
		}
		if (0x20 & i)
		{
			bl = true;
			++num_alive;
		}
		if (0x40 & i)
		{
			l = true;
			++num_alive;
		}
		if (0x80 & i)
		{
			tl = true;
			++num_alive;
		}

		c.update(t, tr, r, br, b, bl, l, tl);
		c.step();

		if (num_alive < 2 || num_alive > 3)
			ASSERT_FALSE(c.is_alive());
		else if (num_alive == 3)
			ASSERT_TRUE(c.is_alive());
		else
			ASSERT_EQ(prev_stat, c.is_alive());

		prev_stat = c.is_alive();
	}
}

TEST(ConwayCell, clone)
{
	ConwayCell original(true);
	
	ConwayCell * c = original.clone();

	bool prev_stat = true;

	for (unsigned int i = 0; i < 256; ++i)
	{
		bool t = false, tr = false, r = false, br = false, b = false, bl = false, l = false, tl = false;

		size_t num_alive = 0;

		if (0x1 & i) 
		{
			t = true;
			++num_alive;
		}
		if (0x2 & i)
		{
			tr = true;
			++num_alive;
		}
		if (0x4 & i)
		{
			r = true;
			++num_alive;
		}
		if (0x8 & i)
		{
			br = true;
			++num_alive;
		}
		if (0x10 & i)
		{
			b = true;
			++num_alive;
		}
		if (0x20 & i)
		{
			bl = true;
			++num_alive;
		}
		if (0x40 & i)
		{
			l = true;
			++num_alive;
		}
		if (0x80 & i)
		{
			tl = true;
			++num_alive;
		}

		c->update(t, tr, r, br, b, bl, l, tl);
		c->step();

		if (num_alive < 2 || num_alive > 3)
			ASSERT_FALSE(c->is_alive());
		else if (num_alive == 3)
			ASSERT_TRUE(c->is_alive());
		else
			ASSERT_EQ(prev_stat, c->is_alive());

		prev_stat = c->is_alive();
	}

	delete c;
}
TEST(FredkinCell, constructor_alive)
{
	FredkinCell f(true);
	ASSERT_TRUE(f.is_alive());
}

TEST(FredkinCell, constructor_dead)
{
	FredkinCell f(false);
	ASSERT_FALSE(f.is_alive());
}

TEST(FredkinCell, get_age)
{
	FredkinCell f(true);
	ASSERT_EQ(f.get_age(), 0);
}

TEST(FredkinCell, get_age_grow)
{
	FredkinCell f(true);
	f.update(true, false, false, false, false, false, false, false);
	f.step();
	ASSERT_EQ(f.get_age(), 1);
}

TEST(FredkinCell, update_and_step)
{
	FredkinCell f(true);

	for (unsigned int i = 0; i < 256; ++i)
	{
		bool t = false, tr = false, r = false, br = false, b = false, bl = false, l = false, tl = false;

		size_t num_alive = 0;

		if (0x1 & i) 
		{
			t = true;
			++num_alive;
		}
		if (0x2 & i)
		{
			tr = true;
		}
		if (0x4 & i)
		{
			r = true;
			++num_alive;
		}
		if (0x8 & i)
		{
			br = true;
		}
		if (0x10 & i)
		{
			b = true;
			++num_alive;
		}
		if (0x20 & i)
		{
			bl = true;
		}
		if (0x40 & i)
		{
			l = true;
			++num_alive;
		}
		if (0x80 & i)
		{
			tl = true;
		}

		f.update(t, tr, r, br, b, bl, l, tl);
		f.step();

		if (num_alive == 0 || num_alive == 2 || num_alive == 4)
			ASSERT_FALSE(f.is_alive());
		else if (num_alive == 1 || num_alive == 3)
			ASSERT_TRUE(f.is_alive());
	}
}

TEST(FredkinCell, update_and_step_with_age)
{
	FredkinCell f(true);

	bool prev_stat = true;

	size_t age = 0;

	for (unsigned int i = 0; i < 256; ++i)
	{
		bool t = false, tr = false, r = false, br = false, b = false, bl = false, l = false, tl = false;

		size_t num_alive = 0;

		if (0x1 & i) 
		{
			t = true;
			++num_alive;
		}
		if (0x2 & i)
		{
			tr = true;
		}
		if (0x4 & i)
		{
			r = true;
			++num_alive;
		}
		if (0x8 & i)
		{
			br = true;
		}
		if (0x10 & i)
		{
			b = true;
			++num_alive;
		}
		if (0x20 & i)
		{
			bl = true;
		}
		if (0x40 & i)
		{
			l = true;
			++num_alive;
		}
		if (0x80 & i)
		{
			tl = true;
		}

		f.update(t, tr, r, br, b, bl, l, tl);
		f.step();

		if (num_alive == 0 || num_alive == 2 || num_alive == 4)
			ASSERT_FALSE(f.is_alive());
		else if (num_alive == 1 || num_alive == 3)
			ASSERT_TRUE(f.is_alive());

		if (prev_stat && f.is_alive())
			ASSERT_EQ(f.get_age(), ++age);

		prev_stat = f.is_alive();
	}
}

TEST(FredkinCell, clone)
{
	FredkinCell original(true);
	FredkinCell * f = original.clone();

	bool prev_stat = true;

	size_t age = 0;

	for (unsigned int i = 0; i < 256; ++i)
	{
		bool t = false, tr = false, r = false, br = false, b = false, bl = false, l = false, tl = false;

		size_t num_alive = 0;

		if (0x1 & i) 
		{
			t = true;
			++num_alive;
		}
		if (0x2 & i)
		{
			tr = true;
		}
		if (0x4 & i)
		{
			r = true;
			++num_alive;
		}
		if (0x8 & i)
		{
			br = true;
		}
		if (0x10 & i)
		{
			b = true;
			++num_alive;
		}
		if (0x20 & i)
		{
			bl = true;
		}
		if (0x40 & i)
		{
			l = true;
			++num_alive;
		}
		if (0x80 & i)
		{
			tl = true;
		}

		f->update(t, tr, r, br, b, bl, l, tl);
		f->step();

		if (num_alive == 0 || num_alive == 2 || num_alive == 4)
			ASSERT_FALSE(f->is_alive());
		else if (num_alive == 1 || num_alive == 3)
			ASSERT_TRUE(f->is_alive());

		if (prev_stat && f->is_alive())
			ASSERT_EQ(f->get_age(), ++age);

		prev_stat = f->is_alive();
	}
	
	delete f;
}

TEST(Cell, conway_constructor_alive)
{
	Cell c(new ConwayCell(true));
	ASSERT_TRUE(c.is_alive());
}

TEST(Cell, conway_constructor_dead)
{
	Cell c(new ConwayCell(false));
	ASSERT_FALSE(c.is_alive());
}

TEST(Cell, conway_get_age)
{
	Cell c(new ConwayCell(true));
	ASSERT_EQ(c.get_age(), -1);
}

TEST(Cell, conway_update_and_step)
{
	Cell c(new ConwayCell(true));

	bool prev_stat = true;

	for (unsigned int i = 0; i < 256; ++i)
	{
		bool t = false, tr = false, r = false, br = false, b = false, bl = false, l = false, tl = false;

		size_t num_alive = 0;

		if (0x1 & i) 
		{
			t = true;
			++num_alive;
		}
		if (0x2 & i)
		{
			tr = true;
			++num_alive;
		}
		if (0x4 & i)
		{
			r = true;
			++num_alive;
		}
		if (0x8 & i)
		{
			br = true;
			++num_alive;
		}
		if (0x10 & i)
		{
			b = true;
			++num_alive;
		}
		if (0x20 & i)
		{
			bl = true;
			++num_alive;
		}
		if (0x40 & i)
		{
			l = true;
			++num_alive;
		}
		if (0x80 & i)
		{
			tl = true;
			++num_alive;
		}

		c.update(t, tr, r, br, b, bl, l, tl);
		c.step();

		if (num_alive < 2 || num_alive > 3)
			ASSERT_FALSE(c.is_alive());
		else if (num_alive == 3)
			ASSERT_TRUE(c.is_alive());
		else
			ASSERT_EQ(prev_stat, c.is_alive());

		prev_stat = c.is_alive();
	}
}

TEST(Cell, fredkin_constructor_alive)
{
	Cell c(new FredkinCell(true));
	ASSERT_TRUE(c.is_alive());
}

TEST(Cell, Fredkin_constructor_dead)
{
	Cell c(new FredkinCell(false));
	ASSERT_FALSE(c.is_alive());
}

TEST(Cell, fredkin_get_age)
{
	Cell c(new FredkinCell(true));
	ASSERT_EQ(c.get_age(), 0);
}

TEST(Cell, fredkin_get_age_increment)
{
	Cell c(new FredkinCell(true));
	c.update(true, false, false, false, false, false, false, false);
	c.step();
	ASSERT_EQ(c.get_age(), 1);
}

TEST(Cell, fredkin_update_and_step)
{
	for (unsigned int i = 0; i < 256; ++i)
	{
		Cell f(new FredkinCell(true));

		bool t = false, tr = false, r = false, br = false, b = false, bl = false, l = false, tl = false;

		size_t num_alive = 0;

		if (0x1 & i) 
		{
			t = true;
			++num_alive;
		}
		if (0x2 & i)
		{
			tr = true;
		}
		if (0x4 & i)
		{
			r = true;
			++num_alive;
		}
		if (0x8 & i)
		{
			br = true;
		}
		if (0x10 & i)
		{
			b = true;
			++num_alive;
		}
		if (0x20 & i)
		{
			bl = true;
		}
		if (0x40 & i)
		{
			l = true;
			++num_alive;
		}
		if (0x80 & i)
		{
			tl = true;
		}

		f.update(t, tr, r, br, b, bl, l, tl);
		f.step();

		if (num_alive == 0 || num_alive == 2 || num_alive == 4)
			ASSERT_FALSE(f.is_alive());
		else if (num_alive == 1 || num_alive == 3)
			ASSERT_TRUE(f.is_alive());
	}
}

TEST(Cell, fredkin_update_and_step_with_age)
{

	bool prev_stat = true;

	for (unsigned int i = 0; i < 256; ++i)
	{
		Cell f(new FredkinCell(true));

		bool t = false, tr = false, r = false, br = false, b = false, bl = false, l = false, tl = false;

		size_t num_alive = 0;

		if (0x1 & i) 
		{
			t = true;
			++num_alive;
		}
		if (0x2 & i)
		{
			tr = true;
		}
		if (0x4 & i)
		{
			r = true;
			++num_alive;
		}
		if (0x8 & i)
		{
			br = true;
		}
		if (0x10 & i)
		{
			b = true;
			++num_alive;
		}
		if (0x20 & i)
		{
			bl = true;
		}
		if (0x40 & i)
		{
			l = true;
			++num_alive;
		}
		if (0x80 & i)
		{
			tl = true;
		}

		f.update(t, tr, r, br, b, bl, l, tl);
		f.step();

		if (num_alive == 0 || num_alive == 2 || num_alive == 4)
			ASSERT_FALSE(f.is_alive());
		else if (num_alive == 1 || num_alive == 3)
			ASSERT_TRUE(f.is_alive());

		if (prev_stat && f.is_alive())
			ASSERT_EQ(f.get_age(), 1);

		prev_stat = f.is_alive();
	}
}

TEST(Cell, fredkin_convert_to_conway)
{
	Cell c(new FredkinCell(true));
	c.update(true, false, false, false, false, false, false, false);
	c.step();
	ASSERT_EQ(c.get_age(), 1);
	c.update(true, false, false, false, false, false, false, false);
	c.step();
	ASSERT_EQ(c.get_age(), -1);
	ASSERT_TRUE(c.is_alive());

	c.update(false, false, false, true, true, true, false, false);
	c.step();
	ASSERT_EQ(c.get_age(), -1);
	ASSERT_TRUE(c.is_alive());
}

TEST(Life, new_grid_conway)
{
	 Life<ConwayCell> l(0, 0);
	 ASSERT_EQ(l.get_turn(), 0);
}

TEST(Life, new_grid_fredkin)
{
	 Life<FredkinCell> l(0, 0);
	 ASSERT_EQ(l.get_turn(), 0);
}

TEST(Life, new_grid_cell)
{
	Life<Cell> l(0, 0);
	ASSERT_EQ(l.get_turn(), 0);
}

TEST(Life, add_row_good_conway)
{
	Life<ConwayCell> l(1, 1);
	std::vector<ConwayCell> v(1, ConwayCell(true));
	ASSERT_TRUE(l.add_row(v));
}

TEST(Life, add_row_good_fredkin)
{
	Life<FredkinCell> l(1, 1);
	std::vector<FredkinCell> v(1, FredkinCell(true));
	ASSERT_TRUE(l.add_row(v));
}

TEST(Life, add_row_good_cell_conway)
{
	Life<Cell> l(1, 1);
	std::vector<Cell> v(1, new ConwayCell(true));
	ASSERT_TRUE(l.add_row(v));
}

TEST(Life, add_row_good_cell_fredkin)
{
	Life<Cell> l(1, 1);
	std::vector<Cell> v(1, new FredkinCell(true));
	ASSERT_TRUE(l.add_row(v));
}

TEST(Life, add_row_bad_width_conway)
{
	Life<ConwayCell> l(1, 1);
	std::vector<ConwayCell> v;
	ASSERT_FALSE(l.add_row(v));
}

TEST(Life, add_row_bad_width_fredkin)
{
	Life<FredkinCell> l(1, 1);
	std::vector<FredkinCell> v;
	ASSERT_FALSE(l.add_row(v));
}

TEST(Life, add_row_bad_width_cell_conway)
{
	Life<Cell> l(1, 1);
	std::vector<Cell> v;
	ASSERT_FALSE(l.add_row(v));
}

TEST(Life, add_row_bad_width_cell_fredkin)
{
	Life<Cell> l(1, 1);
	std::vector<Cell> v;
	ASSERT_FALSE(l.add_row(v));
}

TEST(Life, add_row_bad_height_conway)
{
	Life<ConwayCell> l(0, 1);
	std::vector<ConwayCell> v(1, ConwayCell(true));
	ASSERT_FALSE(l.add_row(v));
}

TEST(Life, add_row_bad_height_fredkin)
{
	Life<FredkinCell> l(0, 1);
	std::vector<FredkinCell> v(1, FredkinCell(true));
	ASSERT_FALSE(l.add_row(v));
}

TEST(Life, add_row_bad_height_cell_conway)
{
	Life<Cell> l(0, 1);
	std::vector<Cell> v(1, new ConwayCell(true));
	ASSERT_FALSE(l.add_row(v));
}

TEST(Life, add_row_bad_height_cell_fredkin)
{
	Life<Cell> l(0, 1);
	std::vector<Cell> v(1, new FredkinCell(true));
	ASSERT_FALSE(l.add_row(v));
}

TEST(Life, step_one_size_one_conway)
{
	Life<ConwayCell> l(1, 1);
	std::vector<ConwayCell> v(1, ConwayCell(true));
	ASSERT_TRUE(l.add_row(v));
	ASSERT_TRUE(l.step() == 0);
	l.print();
	printf("\n");
}

TEST(Life, step_one_size_one_fredkin)
{
	Life<FredkinCell> l(1, 1);
	std::vector<FredkinCell> v(1, FredkinCell(true));
	ASSERT_TRUE(l.add_row(v));
	ASSERT_TRUE(l.step() == 0);
	l.print();
	printf("\n");
}

TEST(Life, step_one_size_one_cell_conway)
{
	Life<Cell> l(1, 1);
	std::vector<Cell> v(1, new ConwayCell(true));
	ASSERT_TRUE(l.add_row(v));
	ASSERT_TRUE(l.step() == 0);
	l.print();
	printf("\n");
}

TEST(Life, step_one_size_one_cell_fredkin)
{
	Life<Cell> l(1, 1);
	std::vector<Cell> v(1, new FredkinCell(true));
	ASSERT_TRUE(l.add_row(v));
	ASSERT_TRUE(l.step() == 0);
	l.print();
	printf("\n");
}

TEST(Life, step_one_size_three_conway_one)
{
	Life<ConwayCell> l(3, 3);
	std::vector<ConwayCell> r1;
	std::vector<ConwayCell> r2;
	std::vector<ConwayCell> r3;

	r1.push_back(ConwayCell(false));
	r1.push_back(ConwayCell(false));
	r1.push_back(ConwayCell(false));
	r2.push_back(ConwayCell(false));
	r2.push_back(ConwayCell(true));
	r2.push_back(ConwayCell(false));
	r3.push_back(ConwayCell(false));
	r3.push_back(ConwayCell(false));
	r3.push_back(ConwayCell(false));

	ASSERT_TRUE(l.add_row(r1));
	ASSERT_TRUE(l.add_row(r2));
	ASSERT_TRUE(l.add_row(r3));
	ASSERT_TRUE(l.step() == 0);
	l.print();
	printf("\n");
}

TEST(Life, step_one_size_three_conway_two)
{
	Life<ConwayCell> l(3, 3);
	std::vector<ConwayCell> r1;
	std::vector<ConwayCell> r2;
	std::vector<ConwayCell> r3;

	r1.push_back(ConwayCell(true));
	r1.push_back(ConwayCell(true));
	r1.push_back(ConwayCell(true));
	r2.push_back(ConwayCell(false));
	r2.push_back(ConwayCell(true));
	r2.push_back(ConwayCell(false));
	r3.push_back(ConwayCell(false));
	r3.push_back(ConwayCell(false));
	r3.push_back(ConwayCell(false));

	ASSERT_TRUE(l.add_row(r1));
	ASSERT_TRUE(l.add_row(r2));
	ASSERT_TRUE(l.add_row(r3));
	ASSERT_TRUE(l.step() > 0);
	l.print();
	printf("\n");
}

TEST(Life, step_one_size_three_fredkin_one)
{
	Life<FredkinCell> l(3, 3);
	std::vector<FredkinCell> r1;
	std::vector<FredkinCell> r2;
	std::vector<FredkinCell> r3;

	r1.push_back(FredkinCell(false));
	r1.push_back(FredkinCell(false));
	r1.push_back(FredkinCell(false));
	r2.push_back(FredkinCell(false));
	r2.push_back(FredkinCell(true));
	r2.push_back(FredkinCell(false));
	r3.push_back(FredkinCell(false));
	r3.push_back(FredkinCell(false));
	r3.push_back(FredkinCell(false));

	ASSERT_TRUE(l.add_row(r1));
	ASSERT_TRUE(l.add_row(r2));
	ASSERT_TRUE(l.add_row(r3));
	ASSERT_TRUE(l.step() > 0);
	l.print();
	printf("\n");
}

TEST(Life, step_one_size_three_fredkin_two)
{
	Life<FredkinCell> l(3, 3);
	std::vector<FredkinCell> r1;
	std::vector<FredkinCell> r2;
	std::vector<FredkinCell> r3;

	r1.push_back(FredkinCell(true));
	r1.push_back(FredkinCell(true));
	r1.push_back(FredkinCell(true));
	r2.push_back(FredkinCell(false));
	r2.push_back(FredkinCell(true));
	r2.push_back(FredkinCell(false));
	r3.push_back(FredkinCell(false));
	r3.push_back(FredkinCell(false));
	r3.push_back(FredkinCell(false));

	ASSERT_TRUE(l.add_row(r1));
	ASSERT_TRUE(l.add_row(r2));
	ASSERT_TRUE(l.add_row(r3));
	ASSERT_TRUE(l.step() > 0);
	l.print();
	printf("\n");
}

TEST(Life, step_two_size_three_fredkin_three)
{
	Life<FredkinCell> l(3, 3);
	std::vector<FredkinCell> r1;
	std::vector<FredkinCell> r2;
	std::vector<FredkinCell> r3;

	r1.push_back(FredkinCell(true));
	r1.push_back(FredkinCell(true));
	r1.push_back(FredkinCell(true));
	r2.push_back(FredkinCell(false));
	r2.push_back(FredkinCell(true));
	r2.push_back(FredkinCell(false));
	r3.push_back(FredkinCell(false));
	r3.push_back(FredkinCell(false));
	r3.push_back(FredkinCell(false));

	ASSERT_TRUE(l.add_row(r1));
	ASSERT_TRUE(l.add_row(r2));
	ASSERT_TRUE(l.add_row(r3));
	ASSERT_TRUE(l.step() > 0);
	l.print();
	printf("\n");
	ASSERT_TRUE(l.step());
	l.print();
	printf("\n");
}

TEST(Life, step_one_size_three_cell_conway_one)
{
	Life<Cell> l(3, 3);
	std::vector<Cell> r1;
	std::vector<Cell> r2;
	std::vector<Cell> r3;

	r1.push_back(new ConwayCell(false));
	r1.push_back(new ConwayCell(false));
	r1.push_back(new ConwayCell(false));
	r2.push_back(new ConwayCell(false));
	r2.push_back(new ConwayCell(true));
	r2.push_back(new ConwayCell(false));
	r3.push_back(new ConwayCell(false));
	r3.push_back(new ConwayCell(false));
	r3.push_back(new ConwayCell(false));

	ASSERT_TRUE(l.add_row(r1));
	ASSERT_TRUE(l.add_row(r2));
	ASSERT_TRUE(l.add_row(r3));
	ASSERT_TRUE(l.step() == 0);
	l.print();
	printf("\n");
}

TEST(Life, step_one_size_three_cell_conway_two)
{
	Life<Cell> l(3, 3);
	std::vector<Cell> r1;
	std::vector<Cell> r2;
	std::vector<Cell> r3;

	r1.push_back(new ConwayCell(true));
	r1.push_back(new ConwayCell(true));
	r1.push_back(new ConwayCell(true));
	r2.push_back(new ConwayCell(false));
	r2.push_back(new ConwayCell(true));
	r2.push_back(new ConwayCell(false));
	r3.push_back(new ConwayCell(false));
	r3.push_back(new ConwayCell(false));
	r3.push_back(new ConwayCell(false));

	ASSERT_TRUE(l.add_row(r1));
	ASSERT_TRUE(l.add_row(r2));
	ASSERT_TRUE(l.add_row(r3));
	ASSERT_TRUE(l.step() > 0);
	l.print();
	printf("\n");
}

TEST(Life, step_one_size_three_cell_fredkin_one)
{
	Life<Cell> l(3, 3);
	std::vector<Cell> r1;
	std::vector<Cell> r2;
	std::vector<Cell> r3;

	r1.push_back(new FredkinCell(false));
	r1.push_back(new FredkinCell(false));
	r1.push_back(new FredkinCell(false));
	r2.push_back(new FredkinCell(false));
	r2.push_back(new FredkinCell(true));
	r2.push_back(new FredkinCell(false));
	r3.push_back(new FredkinCell(false));
	r3.push_back(new FredkinCell(false));
	r3.push_back(new FredkinCell(false));

	ASSERT_TRUE(l.add_row(r1));
	ASSERT_TRUE(l.add_row(r2));
	ASSERT_TRUE(l.add_row(r3));
	ASSERT_TRUE(l.step() > 0);
	l.print();
	printf("\n");
}

TEST(Life, step_one_size_three_cell_fredkin_two)
{
	Life<Cell> l(3, 3);
	std::vector<Cell> r1;
	std::vector<Cell> r2;
	std::vector<Cell> r3;

	r1.push_back(new FredkinCell(true));
	r1.push_back(new FredkinCell(true));
	r1.push_back(new FredkinCell(true));
	r2.push_back(new FredkinCell(false));
	r2.push_back(new FredkinCell(true));
	r2.push_back(new FredkinCell(false));
	r3.push_back(new FredkinCell(false));
	r3.push_back(new FredkinCell(false));
	r3.push_back(new FredkinCell(false));

	ASSERT_TRUE(l.add_row(r1));
	ASSERT_TRUE(l.add_row(r2));
	ASSERT_TRUE(l.add_row(r3));
	ASSERT_TRUE(l.step() > 0);
	l.print();
	printf("\n");
}

TEST(Life, step_two_size_three_cell_fredkin_three)
{
	Life<Cell> l(3, 3);
	std::vector<Cell> r1;
	std::vector<Cell> r2;
	std::vector<Cell> r3;

	r1.push_back(new FredkinCell(true));
	r1.push_back(new FredkinCell(true));
	r1.push_back(new FredkinCell(true));
	r2.push_back(new FredkinCell(false));
	r2.push_back(new FredkinCell(true));
	r2.push_back(new FredkinCell(false));
	r3.push_back(new FredkinCell(false));
	r3.push_back(new FredkinCell(false));
	r3.push_back(new FredkinCell(false));

	ASSERT_TRUE(l.add_row(r1));
	ASSERT_TRUE(l.add_row(r2));
	ASSERT_TRUE(l.add_row(r3));
	ASSERT_TRUE(l.step() > 0);
	l.print();
	printf("\n");
	ASSERT_TRUE(l.step());
	l.print();
	printf("\n");
}
