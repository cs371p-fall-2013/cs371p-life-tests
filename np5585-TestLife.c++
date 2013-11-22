/**
 *     Generated File!
 *     DO NOT MODIFY! IT WILL BE DELETED!
 */


#include <iostream>
#include <sstream>
#include <string>

#include "gtest/gtest.h"

/* Lazy Hack */
#define private public
#define protected public

TEST(Init, init) {
  ASSERT_TRUE(true);
}
/******************/

/* TestLife.p.c++ */

#include <iostream>
#include <sstream>
#include <string>

#include "Life.h"
#include "Cell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "AbstractCell.h"

/******************************************
 ******************************************
 *****               LIFE             *****
 ******************************************
 ******************************************/

TEST(Life, construction__default)
{
  Life<Cell> l(1, 1);
  l.getNeighbors(0, 0); // to get stuff compiling
}

/*********************
 * Iterate
 *********************/
TEST(Life, iterate__single_iterate_conway)
{
  ConwayCell aliveCell;
  aliveCell._alive = true;
  ConwayCell deadCell;
  deadCell._alive = false;

  Life<ConwayCell> life(3, 3);
  life.my_cur_grid->cells[1][1] = deadCell;
  life.my_cur_grid->cells[0][0] = aliveCell;
  life.my_cur_grid->cells[0][1] = aliveCell;
  life.my_cur_grid->cells[0][2] = aliveCell;

  life.iterate();
  ASSERT_FALSE( life.my_cur_grid->cells[0][0].isAlive() );
  ASSERT_FALSE( life.my_cur_grid->cells[0][2].isAlive() );

  ASSERT_TRUE ( life.my_cur_grid->cells[1][1].isAlive() );
  ASSERT_TRUE ( life.my_cur_grid->cells[0][1].isAlive() );
}

/*********************
 * Load (istream)
 *********************/


TEST(Life, load__istream_1_row)
{
  Life<Cell> l(1, 20);
  std::istringstream i(
    "....*0123456789+----"
  );
  std::ostringstream o;

  l.load(i);
  l.print(o);

  ASSERT_EQ(o.str(), "Generation = 0, Population = 12.\n....*0123456789+----\n\n");
}

TEST(Life, load__istream_2_rows)
{
  Life<Cell> l(2, 20);
  std::istringstream i(
    "....*0123456789+----\n....*0123456789+----"
  );
  std::ostringstream o;

  l.load(i);
  l.print(o);

  ASSERT_EQ(o.str(), "Generation = 0, Population = 24.\n....*0123456789+----\n....*0123456789+----\n\n");
}

/*********************
 * Load
 *********************/

TEST(Life, load__conway_simple)
{
  Life<ConwayCell> l(1, 1);

  l.load('*', 0, 0);

  ASSERT_EQ('*', l.my_cur_grid->cells[0][0].toChar());
}

TEST(Life, load__conway_simple_period)
{
  Life<ConwayCell> l(1, 1);

  l.load('.', 0, 0);

  ASSERT_EQ('.', l.my_cur_grid->cells[0][0].toChar());
}

TEST(Life, load__conway_simple_invalid)
{
  Life<ConwayCell> l(1, 1);

  l.load('9', 0, 0);

  ASSERT_EQ('.', l.my_cur_grid->cells[0][0].toChar());
}

TEST(Life, load__fredkin_simple)
{
  Life<FredkinCell> l(1, 1);

  l.load('0', 0, 0);

  ASSERT_EQ('0', l.my_cur_grid->cells[0][0].toChar());
}

TEST(Life, load__fredkin_hyphen)
{
  Life<FredkinCell> l(1, 1);

  l.load('-', 0, 0);

  ASSERT_EQ('-', l.my_cur_grid->cells[0][0].toChar());
}

TEST(Life, load__fredkin_invalid)
{
  Life<FredkinCell> l(1, 1);

  l.load('~', 0, 0);

  ASSERT_EQ('-', l.my_cur_grid->cells[0][0].toChar());
}


TEST(Life, load__cell_simple_load_0)
{
  Life<Cell> l(1, 1);

  l.load('0', 0, 0);

  ASSERT_EQ('0', l.my_cur_grid->cells[0][0].toChar());
}

TEST(Life, load__cell_simple_load_9)
{
  Life<Cell> l(1, 1);

  l.load('9', 0, 0);

  ASSERT_EQ('9', l.my_cur_grid->cells[0][0].toChar());
}

TEST(Life, load__cell_simple_load_invalid)
{
  Life<Cell> l(1, 1);

  l.load('~', 0, 0);

  ASSERT_EQ('-', l.my_cur_grid->cells[0][0].toChar());
}

TEST(Life, load__cell_simple_load_period)
{
  Life<Cell> l(1, 1);

  l.load('.', 0, 0);

  ASSERT_EQ('.', l.my_cur_grid->cells[0][0].toChar());
}

TEST(Life, load__cell_simple_load_hyphen)
{
  Life<Cell> l(1, 1);

  l.load('-', 0, 0);

  ASSERT_EQ('-', l.my_cur_grid->cells[0][0].toChar());
}


/******************************************
 ******************************************
 *****           NEIGHBORHOOD         *****
 ******************************************
 ******************************************/

/*********************
 * Neighborhood
 *********************/
TEST(Neighborhood, construction__assignment)
{
  Neighborhood n;

  n.NORTH      = true;
  n.EAST       = true;
  n.SOUTH      = true;
  n.WEST       = true;
  n.NORTH_EAST = true;
  n.NORTH_WEST = true;
  n.SOUTH_EAST = true;
  n.SOUTH_WEST = true;

  ASSERT_EQ(true, n.NORTH);
  ASSERT_EQ(true, n.EAST );
  ASSERT_EQ(true, n.SOUTH);
  ASSERT_EQ(true, n.WEST );
  ASSERT_EQ(true, n.NORTH_EAST);
  ASSERT_EQ(true, n.NORTH_WEST);
  ASSERT_EQ(true, n.SOUTH_EAST);
  ASSERT_EQ(true, n.SOUTH_WEST);

  for (int i=0; i<4; i++) 
  {
    ASSERT_EQ(true, n.cardinal[i]);
  }
  for (int i=0; i<4; i++) 
  {
    ASSERT_EQ(true, n.ordinal[i]);
  }
}



/******************/

/* TestCell.p.c++ */

#include "Cell.h"
#include "AbstractCell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Handle.h"

/*********************
 *********************
 ****    Cell     ****
 *********************
 *********************/

/*
 * Makes neighborhood w/ the specified number of alive
 * cardinal and ordinal neighbors
 */
Neighborhood customNeighborhood(int cardinalAlive, int ordinalAlive)
{
  Neighborhood neighbors;

  int i=0;
  for (i=0; i<4; i++)
  {
    neighbors.cardinal[i] = i < cardinalAlive;
  }
  for (i=0; i<4; i++)
  {
    neighbors.ordinal[i] = i < ordinalAlive;
  }

  return neighbors;
}

/*********************
 * Cell (handle)
 *********************/

/**
 * Virtual function iterate should be called even 
 * if reference is AbstractCell
 */
class MagicCell : public AbstractCell
{
  public:

    int iterated;

    MagicCell()
      : AbstractCell()
      , iterated(0)
    { }

    MagicCell(int i)
      : AbstractCell()
      , iterated(i)
    { }

    void iterate(Neighborhood* n)
    {
      ++ iterated;
    }

    MagicCell* clone() const
    {
      MagicCell* c = new MagicCell();
      c->iterated = this->iterated;
      return c;
    }

    bool operator== (const MagicCell& other)
    {
      return this->iterated == other.iterated;
    }

    void load(char id) {}
};

/*
 * Confirm virtual function transitivity.. just to be safe
 */
TEST(Cell, iterate__virtual_fns_are_transitive)
{
  Neighborhood neighbors;

  MagicCell p;
  MagicCell m;
  Cell c(m);

  p = *dynamic_cast<MagicCell*>(c.get());
  ASSERT_EQ(p.iterated, 0);

  c->iterate(&neighbors);

  p = *dynamic_cast<MagicCell*>(c.get());
  ASSERT_EQ(p.iterated, 1);

  c->iterate(&neighbors);

  p = *dynamic_cast<MagicCell*>(c.get());
  ASSERT_EQ(p.iterated, 2);
}

TEST(Cell, iterate__fredkin_resurrects_at_last_age)
{
  Neighborhood n = customNeighborhood(0, 4);

  Cell c;
  c.load('0');

  ASSERT_EQ  ( '0', c.toChar() );
  ASSERT_TRUE( c.isAlive() );

  c.iterate( &n );

  ASSERT_EQ  ( '-', c.toChar() );
  ASSERT_TRUE( !c.isAlive() );

  n = customNeighborhood(1, 4);

  c.iterate( &n );

  ASSERT_EQ  ( '0', c.toChar() );
  ASSERT_TRUE( c.isAlive() );
}

TEST(Cell, iterate__turns_fredkin_to_conway__then_dies)
{
  Neighborhood n = customNeighborhood(1, 2);

  Cell c;
  c.load('1');

  ASSERT_EQ  ( '1', c.toChar() );
  ASSERT_TRUE( c.isAlive() );

  c.iterate(&n);

  ASSERT_EQ  ( '*', c.toChar() );
  ASSERT_TRUE( c.isAlive() );

  n = customNeighborhood(1, 3); // Should keep fredkin alive, but kill conway

  c.iterate(&n);

  ASSERT_EQ  ( '.', c.toChar() );
  ASSERT_TRUE( !c.isAlive() );
}

TEST(Cell, load__recognizes_conway_dead__then_resurrects)
{
  Neighborhood n = customNeighborhood(1, 2);

  Cell c;
  c.load('.');

  ASSERT_EQ  ( '.', c.toChar() );
  ASSERT_TRUE( !c.isAlive() );

  c.iterate( &n );

  ASSERT_EQ  ( '*', c.toChar() );
  ASSERT_TRUE( c.isAlive() );
}

TEST(Cell, load__recognizes_conway_alive__then_dies)
{
  Neighborhood n = customNeighborhood(1, 0);

  Cell c;
  c.load('*');

  ASSERT_EQ  ( '*', c.toChar() );
  ASSERT_TRUE( c.isAlive() );

  c.iterate( &n );

  ASSERT_EQ  ( '.', c.toChar() );
  ASSERT_TRUE( !c.isAlive() );
}

TEST(Cell, load__recognizes_fredkin_char_num__then_dies)
{
  Neighborhood fredkinId = customNeighborhood(1, 2);

  Cell c;
  c.load('0');

  ASSERT_EQ  ( '0', c.toChar() );
  ASSERT_TRUE( c.isAlive() );

  c.iterate(&fredkinId);

  ASSERT_EQ  ( '1', c.toChar() );
  ASSERT_TRUE( c.isAlive() );

  fredkinId = customNeighborhood(0, 3);

  c.iterate(&fredkinId);

  ASSERT_EQ  ( '-', c.toChar() );
  ASSERT_TRUE( !c.isAlive() );
}

TEST(Cell, load__recognizes_fredkin_char_plus)
{
  Neighborhood fredkinId = customNeighborhood(0, 3);

  Cell c;
  c.load('+');

  ASSERT_EQ  ( '+', c.toChar() );
  ASSERT_TRUE( c.isAlive() );
  c.iterate(&fredkinId);

  ASSERT_EQ  ( '-', c.toChar() );
  ASSERT_TRUE( !c.isAlive() );
}

TEST(Cell, load__recognizes_fredkin_char_minus)
{
  Neighborhood fredkinId = customNeighborhood(1, 2);

  Cell c;
  c.load('-');

  ASSERT_EQ  ( '-', c.toChar() );
  ASSERT_TRUE( !c.isAlive() );
  c.iterate(&fredkinId);

  ASSERT_EQ  ( '0', c.toChar() );
  ASSERT_TRUE( c.isAlive() );
}


/*********************
 * ConwayCell
 *********************/

TEST(ConwayCell, conway_count_neighbors)
{
  ConwayCell cCell;
  Neighborhood m = customNeighborhood(1,1);

  int numNeighbors = cCell._countNeighbors( &m );
  ASSERT_EQ( numNeighbors, 2 );
}

TEST(ConwayCell, iterate_life_to_death)
{
  ConwayCell cCell;
  cCell._alive = true;
  Neighborhood m = customNeighborhood(3,1);
  cCell.iterate(&m);

  ASSERT_FALSE( cCell.isAlive() );
}

TEST(ConwayCell, iterate_death_to_life)
{
  ConwayCell cCell;
  cCell._alive = false;
  Neighborhood m = customNeighborhood(2,1);
  cCell.iterate(&m);
  
  ASSERT_TRUE( cCell.isAlive() );
}

TEST(ConwayCell, load_cell_star_sets_alive)
{
  ConwayCell fCell;
  fCell._alive = false;
  fCell.load('*');
  ASSERT_EQ  ( '*', fCell.toChar() );
  ASSERT_TRUE( fCell.isAlive() );
}

TEST(ConwayCell, load_cell_period_sets_dead)
{
  ConwayCell fCell;
  fCell._alive = true;
  fCell.load('.');
  ASSERT_FALSE( fCell.isAlive() );
}

TEST(ConwayCell, load_cell_invalid_char_sets_dead)
{
  ConwayCell fCell;
  fCell._alive = true;
  fCell.load('p');
  ASSERT_FALSE( fCell.isAlive() );
}


/*********************
 * Fredkin Cell
 *********************/

TEST(FredkinCell, iterate_life_to_death)
{
  FredkinCell fCell;
  Neighborhood m = customNeighborhood(1, 1);

  fCell.iterate(&m);
  ASSERT_TRUE( fCell.isAlive() );

  m = customNeighborhood(0, 3);
  fCell.iterate(&m);

  ASSERT_TRUE( !fCell.isAlive() );
}


TEST(FredkinCell, iterate_death_to_life)
{
  FredkinCell fCell;

  Neighborhood m = customNeighborhood(0, 3);
  fCell.iterate(&m);
  ASSERT_TRUE( !fCell.isAlive() );

  m = customNeighborhood(1, 1);
  fCell.iterate(&m);
  ASSERT_TRUE( fCell.isAlive() );
}


TEST(FredkinCell, fredkin_count_neighbors)
{
  FredkinCell fCell;

  Neighborhood m = customNeighborhood(1,1);
  int numNeighbors = fCell._countNeighbors( &m );

  ASSERT_EQ( numNeighbors, 1 );
}

TEST(FredkinCell, age_is_zero_at_initialization)
{
  FredkinCell fCell;
  ASSERT_EQ( fCell._age, 0 );
}

TEST(FredkinCell, age_is_zero_death_to_life)
{
  FredkinCell fCell;
  Neighborhood m = customNeighborhood(3,0);
  fCell.iterate(&m);
  ASSERT_EQ( fCell._age, 0 );
}

TEST(FredkinCell, age_is_two_with_two_iterations)
{
  FredkinCell fCell;
  fCell._alive = true;
  Neighborhood m = customNeighborhood(3,0);
  fCell.iterate(&m);
  fCell.iterate(&m);
  ASSERT_EQ( fCell._age, 2 );
}

TEST(FredkinCell, age_is_three_with_three_iteration)
{
  FredkinCell fCell;
  fCell._alive = true;
  Neighborhood m = customNeighborhood(3,0);
  fCell.iterate(&m);
  fCell.iterate(&m);
  fCell.iterate(&m);
  ASSERT_EQ( fCell._age, 3 );
}

TEST(FredkinCell, load_cell_int_zero_sets_age_zero)
{
  FredkinCell fCell;
  fCell._alive = false;
  fCell.load('0');
  ASSERT_TRUE( fCell._age == 0);
  ASSERT_TRUE( fCell.isAlive() );
}

TEST(FredkinCell, load_cell_int_9_sets_age_9)
{
  FredkinCell fCell;
  fCell._alive = false;
  fCell.load('9');
  ASSERT_TRUE( fCell._age == 9);
  ASSERT_TRUE( fCell.isAlive() );
}

TEST(FredkinCell, load_cell_hyphen_sets_dead)
{
  FredkinCell fCell;
  fCell._alive = true;
  fCell.load('-');
  ASSERT_TRUE( fCell._age == 0);
  ASSERT_FALSE( fCell.isAlive() );
}

TEST(FredkinCell, load_cell_invalid_char_sets_dead)
{
  FredkinCell fCell;
  fCell._alive = true;
  fCell.load('p');
  ASSERT_TRUE( fCell._age == 0);
  ASSERT_FALSE( fCell.isAlive() );
}

/*********************
 *********************
 * Handle
 *********************
 *********************/

class TestHandleObj
{
  private:
    int _i;

  public:

    TestHandleObj(int i)
      : _i (i)
    { }

    virtual int getMagic()
    {
      return 1;
    }

    virtual TestHandleObj* clone(void) const
    {
      return new TestHandleObj(_i);
    }

    virtual bool operator==(const TestHandleObj& that) const
    {
      return this->_i == that._i;
    }

    virtual bool operator!=(const TestHandleObj& that) const
    {
      return !(*this == that);
    }

    virtual bool operator==(int i) const
    {
      return this->_i == i;
    }

    virtual bool operator!=(int i) const
    {
      return !(this->_i == i);
    }

};

class SubTestHandleObj : public TestHandleObj
{
  private:
    int _j;

  public:

    SubTestHandleObj(int i, int j)
      : TestHandleObj(i)
      , _j (j)
    { }

    virtual int getMagic()
    {
      return 2;
    }

    virtual SubTestHandleObj* clone(void) const
    {
      return new SubTestHandleObj(*this);
    }

    virtual bool operator==(const SubTestHandleObj& that) const
    {
      return TestHandleObj::operator==(that) && _j == that._j;
    }

    virtual bool operator!=(const SubTestHandleObj& that) const
    {
      return !(*this == that);
    }
};

class SubSubTestHandleObj : public TestHandleObj
{
  public:
    SubSubTestHandleObj(int i)
      : TestHandleObj(i)
    { }

    virtual SubSubTestHandleObj* clone(void) const
    {
      return new SubSubTestHandleObj(*this);
    }

    virtual int getMagic()
    {
      return 3;
    }
};

/*********************
 * Handle Construction 
 ********************/

/**
 * Needs to no-arg construction so life can construct empty
 * cells
 */
TEST(Handle, construction__default)
{
  Handle<TestHandleObj> h;
  // Make sure delete is never called on its NULL internal pointer
}

/**
 * We can construct a handle for an object
 */
TEST(Handle, construction__from_object)
{
  TestHandleObj o = 5;
  Handle<TestHandleObj> h(o);

  ASSERT_EQ(*h,  o);
}

/**
 * .. OR a pointer
 */
TEST(Handle, construction__from_pointer)
{
  TestHandleObj o = 5;
  Handle<TestHandleObj> h(&o);

  ASSERT_EQ(*h,  o);
}

/**
 * Copy construction from an existing handle
 */
TEST(Handle, construction__copy)
{
  TestHandleObj o = 5;

  Handle<TestHandleObj> h1(&o);
  Handle<TestHandleObj> h2(h1);

  ASSERT_EQ(*h1, o);
  ASSERT_EQ(*h2, o);
  ASSERT_EQ(*h2, *h1);
}


/*********************
 * Handle Assignment
 ********************/

TEST(Handle, operator__copy_assignment)
{
  TestHandleObj o = 5;

  Handle<TestHandleObj> h1(&o);
  Handle<TestHandleObj> h2(0);

  h2 = h1;

  ASSERT_EQ(*h1, o);
  ASSERT_EQ(*h2, o);
  ASSERT_EQ(*h2, *h1);
}

TEST(Handle, operator__assignment_object)
{
  TestHandleObj one = 1;
  TestHandleObj two = 2;

  Handle<TestHandleObj> h1(&one);

  ASSERT_EQ(*h1, one);
  ASSERT_EQ(*h1, 1);

  h1 = two;

  ASSERT_EQ(*h1, two);
  ASSERT_EQ(*h1, 2);
}

TEST(Handle, operator__assignment_pointer)
{
  TestHandleObj one = 1;
  TestHandleObj two = 2;

  Handle<TestHandleObj> h1(&one);

  ASSERT_EQ(*h1, one);
  ASSERT_EQ(*h1, 1);

  h1 = &two;

  ASSERT_EQ(*h1, two);
  ASSERT_EQ(*h1, 2);
}

TEST(Handle, operator__copy_assignment_swap)
{
  TestHandleObj f = 5;
  TestHandleObj s = 6;

  Handle<TestHandleObj> h1(&f);
  Handle<TestHandleObj> h2(&s);

  ASSERT_EQ(*h1, 5);
  ASSERT_EQ(*h2, 6);
  ASSERT_NE(*h2, *h1);

  Handle<TestHandleObj> tmp = h1;
  h1 = h2;
  h2 = tmp;

  ASSERT_EQ(*h1, 6);
  ASSERT_EQ(*h2, 5);
  ASSERT_NE(*h2, *h1);
  ASSERT_EQ(*h2, *tmp);
}

TEST(Handle, operator__member_access_from_object)
{
  Handle<TestHandleObj> h1(5);

  ASSERT_EQ(h1->getMagic(), 1);
}

/**
 * Handle should return TestHandleObj, but the virtual getMagic() function
 * should return different values based on the underlying type.
 */
TEST(Handle, operator__assignment_respects_inheritance)
{
  Handle<TestHandleObj> h1;
  Handle<TestHandleObj> h2;

  SubSubTestHandleObj e(8);
  ASSERT_EQ(e.getMagic(), 3);   // E

  SubTestHandleObj f(5, 5);
  ASSERT_EQ(f.getMagic(), 2);   // F

  TestHandleObj s(6);
  ASSERT_EQ(s.getMagic(), 1);   // S

  h1 = f;
  h2 = s;

  ASSERT_EQ(h1->getMagic(), 2);  // F
  ASSERT_EQ(h2->getMagic(), 1);  // S

  ASSERT_EQ(*h1, f);
  ASSERT_NE(*h1, s);
  ASSERT_EQ(*h2, s);
  ASSERT_NE(*h2, f);

  h2 = e;
  ASSERT_EQ(h2->getMagic(), 3);  // E
}


