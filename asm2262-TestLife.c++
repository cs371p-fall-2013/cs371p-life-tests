#include "gtest/gtest.h"
#include <sstream>
#include <stdexcept>

#define private public
#define protected public
#include "AbstractCell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"
#include "Life.h"
#undef private
#undef protected

class SimpleCell : public AbstractCell {
    public:
        SimpleCell(bool live = false) : AbstractCell(live){}
        virtual ~SimpleCell(){}
        virtual char image() const {return '!';}
    protected:
        virtual int living_neighbors(const Neighborhood& n,
                                        int x, int y) const {
            return n.live_neighbor(x + 1, y) ? 1 : 0;
        }
        virtual bool lives_near(int x) const {
            return x > 0;
        }
        virtual SimpleCell* clone() const {return 0;}
};

class StateCell: public SimpleCell {
    public:
        bool old;
        bool next;
        bool updated;
    protected:
        virtual void update_state(bool was_alive, bool will_live){
            updated = true;
            old = was_alive;
            next = will_live;
        }
        virtual SimpleCell* clone() const {return 0;}
};

class Crowded : public Neighborhood {
    public:
        virtual bool live_neighbor(int, int) const {
            return true;
        }
};

class BoolArray : public Neighborhood {
    public:
        bool grid[3][3];
        virtual bool live_neighbor(int x, int y) const {
            if (x < 0 || x > 2 || y < 0 || y > 2)
                return false;
            return grid[y][x];
        }
};


TEST(AbstractCell_Tests, living1){
    SimpleCell k;
    k.alive = true;
    ASSERT_TRUE(k.living());        
}


TEST(AbstractCell_Tests, living2){
    SimpleCell k;
    k.alive = false;
    ASSERT_FALSE(k.living());        
}

TEST(AbstractCell_Tests, advancement1){
    SimpleCell k;
    BoolArray g;
    g.grid[0][0] = false; g.grid[0][1] = true;
    k.check_neighbors(g, 0, 0);
    ASSERT_TRUE(k.will_live);        
}

TEST(AbstractCell_Tests, advancement2){
    SimpleCell k;
    BoolArray g;
    g.grid[0][0] = false; g.grid[0][1] = false;
    k.check_neighbors(g, 0, 0);
    ASSERT_FALSE(k.will_live);        
}

TEST(AbstractCell_Tests, advancement3){
    SimpleCell k;
    Crowded n;
    k.check_neighbors(n, 0, 0);
    ASSERT_TRUE(k.will_live);
}

TEST(AbstractCell_Tests, update_check){
    StateCell k;
    k.old = k.next = k.updated = false;
    k.advance();
    ASSERT_TRUE(k.updated);
}

TEST(AbstractCell_Tests, update_old){
    StateCell k;
    k.old = k.next = k.updated = false;
    k.alive = true;
    k.advance();
    ASSERT_TRUE(k.old);
}

TEST(AbstractCell_Tests, update_after){
    StateCell k;
    k.old = k.next = k.updated = false;
    k.will_live = false;
    k.advance();
    ASSERT_FALSE(k.next);
}

TEST(AbstractCell_Tests, neighbors1){
    SimpleCell k;
    Crowded n;
    k.will_live = false;
    k.check_neighbors(n, 0, 0);
    ASSERT_TRUE(k.will_live);
}

TEST(AbstractCell_Tests, neighbors2){
    SimpleCell k;
    k.will_live = true;
    BoolArray g;
    g.grid[0][1] = false;
    k.check_neighbors(g, 0, 0);
    ASSERT_FALSE(k.will_live);
}

TEST(ConwayCell_tests, neighbors){
    ConwayCell k(false);
    BoolArray g;
    g.grid[0][0] = false; g.grid[0][1] = true;  g.grid[0][2] = false;
    g.grid[1][0] = false; g.grid[1][1] = false; g.grid[1][2] = false;
    g.grid[2][0] = true;  g.grid[2][1] = false; g.grid[2][2] = true;
    ASSERT_EQ(3, k.living_neighbors(g, 1, 1));
}

TEST(ConwayCell_tests, neighbors2){
    ConwayCell k(false);
    BoolArray g;
    g.grid[0][0] = false; g.grid[0][1] = false; g.grid[0][2] = false;
    g.grid[1][0] = false; g.grid[1][1] = false; g.grid[1][2] = false;
    g.grid[2][0] = false; g.grid[2][1] = false; g.grid[2][2] = false;
    ASSERT_EQ(0, k.living_neighbors(g, 1, 1));
}

TEST(ConwayCell_tests, neighbors3){
    ConwayCell k(false);
    BoolArray g;
    g.grid[0][0] = false; g.grid[0][1] = true;  g.grid[0][2] = false;
    g.grid[1][0] = true;  g.grid[1][1] = false; g.grid[1][2] = false;
    g.grid[2][0] = false; g.grid[2][1] = false; g.grid[2][2] = false;
    ASSERT_EQ(2, k.living_neighbors(g, 1, 1));
}

TEST(ConwayCell_tests, nearby){
    ConwayCell k(false);
    ASSERT_TRUE(k.lives_near(3));
}

TEST(ConwayCell_tests, nearby2){
    ConwayCell k(true);
    ASSERT_TRUE(k.lives_near(2));
}

TEST(ConwayCell_tests, nearby3){
    ConwayCell k(false);
    ASSERT_FALSE(k.lives_near(2));
}

TEST(ConwayCell_tests, nearby4){
    ConwayCell k(true);
    ASSERT_FALSE(k.lives_near(5));
}

TEST(ConwayCell_tests, nearby5){
    ConwayCell k(false);
    ASSERT_FALSE(k.lives_near(5));
}

TEST(ConwayCell_tests, image_live){
    ConwayCell k(true);
    ASSERT_EQ('*', k.image());
}

TEST(ConwayCell_tests, image_dead){
    ConwayCell k(false);
    ASSERT_EQ('.', k.image());
}

TEST(ConwayCell_tests, clone1){
    ConwayCell k(true);
    ConwayCell* const k_clone = k.clone();
    ASSERT_EQ(k.living(), k_clone->living());
    delete k_clone;
}

TEST(ConwayCell_tests, clone2){
    ConwayCell k(false);
    ConwayCell* const k_clone = k.clone();
    ASSERT_EQ(k.living(), k_clone->living());
    delete k_clone;
}

TEST(ConwayCell_tests, clone3){
    ConwayCell k(true);
    ConwayCell* const k_clone = k.clone();
    ASSERT_NE(&k, k_clone);
    delete k_clone;
}

TEST(FredkinCell_tests, four_neighbors){
    FredkinCell k(false);
    Crowded g;
    ASSERT_EQ(4, k.living_neighbors(g, 1, 1));
}

TEST(FredkinCell_tests, only_corners){
    FredkinCell k(false);
    BoolArray g;
    g.grid[0][0] = true;  g.grid[0][1] = false; g.grid[0][2] = true;
    g.grid[1][0] = false; g.grid[1][1] = false; g.grid[1][2] = false;
    g.grid[2][0] = true;  g.grid[2][1] = false; g.grid[2][2] = true;
    ASSERT_EQ(0, k.living_neighbors(g, 1, 1));
}

TEST(FredkinCell_tests, one_neighbor){
    FredkinCell k(false);
    BoolArray g;
    g.grid[0][0] = true;  g.grid[0][1] = true;  g.grid[0][2] = true;
    g.grid[1][0] = false; g.grid[1][1] = false; g.grid[1][2] = false;
    g.grid[2][0] = true;  g.grid[2][1] = false; g.grid[2][2] = true;
    ASSERT_EQ(1, k.living_neighbors(g, 1, 1));
}

TEST(FredkinCell_tests, survival_zero){
    FredkinCell k(false);
    ASSERT_FALSE(k.lives_near(0));
}

TEST(FredkinCell_tests, survival_one){
    FredkinCell k(false);
    ASSERT_TRUE(k.lives_near(1));
}

TEST(FredkinCell_tests, survival_four){
    FredkinCell k(false);
    ASSERT_FALSE(k.lives_near(4));
}

TEST(FredkinCell_tests, survival_two){
    FredkinCell k(false);
    ASSERT_FALSE(k.lives_near(2));
}

TEST(FredkinCell_tests, survival_three){
    FredkinCell k(false);
    ASSERT_TRUE(k.lives_near(3));
}

TEST(FredkinCell_tests, image_alive0){
    FredkinCell k(true);
    ASSERT_EQ('0', k.image());
}

TEST(FredkinCell_tests, image_alive1){
    FredkinCell k(true);
    k.survivals = 1;
    ASSERT_EQ('1', k.image());
}

TEST(FredkinCell_tests, image_dead){
    FredkinCell k(false);
    ASSERT_EQ('-', k.image());
}

TEST(FredkinCell_tests, image_double_digits){
    FredkinCell k(true);
    k.survivals = 10;
    ASSERT_EQ('+', k.image());
}

TEST(FredkinCell_tests, initial_age){
    FredkinCell k(true);
    ASSERT_EQ(0, k.survivals);
}

TEST(FredkinCell_tests, cloning){
    FredkinCell k(true);
    FredkinCell* const k_clone = k.clone();
    ASSERT_EQ(k.age(), k_clone->age());
    ASSERT_EQ(k.living(), k_clone->living());
    delete k_clone;
}

TEST(FredkinCell_tests, cloning2){
    FredkinCell k(false);
    FredkinCell* const k_clone = k.clone();
    ASSERT_EQ(k.age(), k_clone->age());
    ASSERT_EQ(k.living(), k_clone->living());
    delete k_clone;
}

TEST(FredkinCell_tests, cloning3){
    FredkinCell k(false);
    FredkinCell* const k_clone = k.clone();
    ASSERT_EQ(k.living(), k_clone->living());
    k.alive = true;
    ASSERT_EQ(k.age(), k_clone->age());
    ASSERT_NE(k.living(), k_clone->living());
    delete k_clone;
}

TEST(FredkinCell_tests, one_survival){
    FredkinCell k(false);
    BoolArray g;
    g.grid[0][0] = true;  g.grid[0][1] = true;  g.grid[0][2] = true;
    g.grid[1][0] = false; g.grid[1][1] = false; g.grid[1][2] = false;
    g.grid[2][0] = true;  g.grid[2][1] = false; g.grid[2][2] = true;
    k.check_neighbors(g, 1, 1);
    k.advance();
    ASSERT_TRUE(k.living());
    ASSERT_EQ(0, k.age());
    k.check_neighbors(g, 1, 1);
    k.advance();
    ASSERT_EQ(1, k.age());
}

TEST(FredkinCell_tests, two_survivals){
    FredkinCell k(false);
    BoolArray g;
    g.grid[0][0] = true;  g.grid[0][1] = true;  g.grid[0][2] = true;
    g.grid[1][0] = false; g.grid[1][1] = false; g.grid[1][2] = false;
    g.grid[2][0] = true;  g.grid[2][1] = false; g.grid[2][2] = true;
    k.check_neighbors(g, 1, 1);
    k.advance();
    ASSERT_TRUE(k.living());
    ASSERT_EQ(0, k.age());
    k.check_neighbors(g, 1, 1);
    k.advance();
    ASSERT_EQ(1, k.age());
    g.grid[1][0] = true;
    k.check_neighbors(g, 1, 1);
    k.advance();
    ASSERT_EQ(1, k.age());
    ASSERT_FALSE(k.living());
}

TEST(FredkinCell_tests, pause){
    FredkinCell k(false);
    BoolArray g;
    g.grid[0][0] = true;  g.grid[0][1] = true;  g.grid[0][2] = true;
    g.grid[1][0] = false; g.grid[1][1] = false; g.grid[1][2] = false;
    g.grid[2][0] = true;  g.grid[2][1] = false; g.grid[2][2] = true;
    k.check_neighbors(g, 1, 1);
    k.advance();
    ASSERT_TRUE(k.living());
    ASSERT_EQ(0, k.age());
    k.check_neighbors(g, 1, 1);
    k.advance();
    ASSERT_EQ(1, k.age());
    g.grid[1][0] = true;
    k.check_neighbors(g, 1, 1);
    k.advance();
    ASSERT_EQ(1, k.age());
    ASSERT_FALSE(k.living());
    g.grid[1][0] = false;
    k.check_neighbors(g, 1, 1);
    k.advance();
    ASSERT_EQ(1, k.age());
    ASSERT_TRUE(k.living());
}

TEST(FredkinCell_tests, update_state){
    FredkinCell k(true);
    k.update_state(true, true);
    ASSERT_EQ(1, k.survivals);
}

TEST(FredkinCell_tests, update_state2){
    FredkinCell k(true);
    k.update_state(false, true);
    ASSERT_EQ(0, k.survivals);
}

TEST(FredkinCell_tests, update_state3){
    FredkinCell k(true);
    k.update_state(true, false);
    ASSERT_EQ(0, k.survivals);
}

TEST(FredkinCell_tests, update_state4){
    FredkinCell k(true);
    k.update_state(false, false);
    ASSERT_EQ(0, k.survivals);
}

TEST(FredkinCell_tests, check_age1){
    FredkinCell k(true);
    ASSERT_EQ(0, k.age());
}

TEST(FredkinCell_tests, check_age2){
    FredkinCell k(true);
    k.survivals = 3;
    ASSERT_EQ(3, k.age());
}

TEST(Cell_tests, living_forwarding){
    Cell k(new ConwayCell(true));
    ASSERT_TRUE(k.living());
}

TEST(Cell_tests, living_forwarding2){
    Cell k(new ConwayCell(false));
    ASSERT_FALSE(k.living());
}

TEST(Cell_tests, image_forwarding){
    ConwayCell* const source = new ConwayCell(true);
    Cell k(source); //frees source
    ASSERT_EQ(source->image(), k.image());
}

TEST(Cell_tests, image_forwarding2){
    ConwayCell* const source = new ConwayCell(false);
    Cell k(source); //frees source
    ASSERT_EQ(source->image(), k.image());
}

TEST(Cell_tests, image_forwarding3){
    FredkinCell* const source = new FredkinCell(false);
    Cell k(source); //frees source
    ASSERT_EQ(source->image(), k.image());
}

TEST(Cell_tests, image_forwarding4){
    FredkinCell* const source = new FredkinCell(true);
    Cell k(source); //frees source
    ASSERT_EQ(source->image(), k.image());
}

TEST(Cell_tests, image_forwarding5){
    FredkinCell* const source = new FredkinCell(true);
    source->survivals = 10;
    Cell k(source); //frees source
    ASSERT_EQ(source->image(), k.image());
}

TEST(Cell_tests, fredkin_conversion){
    Cell k(new FredkinCell(true));
    BoolArray g;
    g.grid[0][0] = true;  g.grid[0][1] = true;  g.grid[0][2] = true;
    g.grid[1][0] = false; g.grid[1][1] = false; g.grid[1][2] = false;
    g.grid[2][0] = true;  g.grid[2][1] = false; g.grid[2][2] = true;
    k.check_neighbors(g, 1, 1);
    k.advance();
    ASSERT_EQ('1', k.image());
    k.advance();
    ASSERT_TRUE(dynamic_cast<ConwayCell*>(k.get()));
}

TEST(Cell_tests, fredkin_no_conversion){
    Cell k(new FredkinCell(true));
    BoolArray g;
    g.grid[0][0] = true;  g.grid[0][1] = true;  g.grid[0][2] = true;
    g.grid[1][0] = false; g.grid[1][1] = false; g.grid[1][2] = false;
    g.grid[2][0] = true;  g.grid[2][1] = false; g.grid[2][2] = true;
    k.check_neighbors(g, 1, 1);
    k.advance();
    ASSERT_EQ('1', k.image());
    g.grid[1][0] = true;
    k.check_neighbors(g, 1, 1);
    k.advance();
    ASSERT_TRUE(dynamic_cast<FredkinCell*>(k.get()));
}

TEST(Cell_tests, conway_advance){
    ConwayCell* source = new ConwayCell(true);
    Cell k(source);
    Crowded g;
    k.check_neighbors(g, 0, 0);
    k.advance();
    ASSERT_EQ(source, k.get());
}

TEST(Cell_tests, check_forwarding){
    ConwayCell* source = new ConwayCell(true);
    source->will_live = true;
    Cell k(source);
    Crowded g;
    k.check_neighbors(g, 0, 0);
    ASSERT_FALSE(source->will_live);
}

TEST(Cell_tests, check_forwarding2){
    ConwayCell* source = new ConwayCell(true);
    source->will_live = false;
    Cell k(source);
    BoolArray g;
    g.grid[0][0] = false; g.grid[0][1] = true;  g.grid[0][2] = true;
    g.grid[1][0] = false; g.grid[1][1] = false; g.grid[1][2] = false;
    g.grid[2][0] = true;  g.grid[2][1] = false; g.grid[2][2] = false;
    k.check_neighbors(g, 1, 1);
    ASSERT_TRUE(source->will_live);
}

TEST(Life_tests, insertion_initial){
    Life<ConwayCell> game(3,3);
    game.add_cell(ConwayCell(false));
    ASSERT_EQ(1, game.grid.size());
    ASSERT_EQ(1, game.grid.at(0).size());
}

TEST(Life_tests, insertion_row){
    Life<ConwayCell> game(3,1);
    game.add_cell(ConwayCell(false));
    game.add_cell(ConwayCell(true));
    ASSERT_EQ(2, game.grid.size());
    ASSERT_EQ(1, game.grid.at(0).size());
    ASSERT_EQ(1, game.grid.at(1).size());
}

TEST(Life_tests, insertion_fillup){
    Life<ConwayCell> game(2,2);
    game.add_cell(ConwayCell(false));
    game.add_cell(ConwayCell(true));
    game.add_cell(ConwayCell(false));
    game.add_cell(ConwayCell(true));
    ASSERT_EQ(2, game.grid.size());
}

TEST(Life_tests, printing1){
    Life<ConwayCell> game(1,1);
    game.add_cell(ConwayCell(false));
    std::ostringstream o;
    game.print(o);
    ASSERT_STREQ("Generation = 0, Population = 0.\n.\n\n", o.str().c_str());
}

TEST(Life_tests, printing2){
    Life<ConwayCell> game(1,1);
    game.add_cell(ConwayCell(true));
    std::ostringstream o;
    game.print(o);
    ASSERT_STREQ("Generation = 0, Population = 1.\n*\n\n", o.str().c_str());
}

TEST(Life_tests, printing3){
    Life<ConwayCell> game(2,1);
    game.add_cell(ConwayCell(true));
    game.add_cell(ConwayCell(false));
    std::ostringstream o;
    game.print(o);
    ASSERT_STREQ("Generation = 0, Population = 1.\n*\n.\n\n", o.str().c_str());
}

TEST(Life_tests, printing4){
    Life<ConwayCell> game(1,1);
    game.add_cell(ConwayCell(true));
    game.generations++;
    std::ostringstream o;
    game.print(o);
    ASSERT_STREQ("Generation = 1, Population = 1.\n*\n\n", o.str().c_str());
}

TEST(Life_tests, neighborhood1){
    Life<ConwayCell> game(2,1);
    game.add_cell(ConwayCell(true));
    game.add_cell(ConwayCell(false));
    ASSERT_TRUE(game.live_neighbor(0,0));
}

TEST(Life_tests, neighborhood2){
    Life<ConwayCell> game(2,1);
    game.add_cell(ConwayCell(true));
    game.add_cell(ConwayCell(false));
    ASSERT_FALSE(game.live_neighbor(0,1));
}

TEST(Life_tests, neighborhood_bounds){
    Life<ConwayCell> game(2,1);
    game.add_cell(ConwayCell(true));
    game.add_cell(ConwayCell(false));
    ASSERT_FALSE(game.live_neighbor(-1,0));
    ASSERT_FALSE(game.live_neighbor(0,-1));
    ASSERT_FALSE(game.live_neighbor(3,0));
    ASSERT_FALSE(game.live_neighbor(0,3));
}

TEST(Life_tests, step1){
    Life<SimpleCell> game(1,2);
    game.add_cell(SimpleCell(false));
    game.add_cell(SimpleCell(true));
    ASSERT_EQ(1, game.population);
    game.step();
    ASSERT_EQ(1, game.population);
}

TEST(Life_tests, step2){
    Life<SimpleCell> game(1,2);
    game.add_cell(SimpleCell(false));
    game.add_cell(SimpleCell(true));
    game.step();
    ASSERT_EQ(1, game.generations);
}

TEST(Life_tests, step3){
    Life<SimpleCell> game(1,2);
    game.add_cell(SimpleCell(false));
    game.add_cell(SimpleCell(true));
    game.step();
    ASSERT_TRUE(game.grid.at(0).at(0).living());
    ASSERT_FALSE(game.grid.at(0).at(1).living());
}
