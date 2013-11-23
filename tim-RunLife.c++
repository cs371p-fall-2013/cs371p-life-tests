// -------------------------
// projects/life/RunLife.c++
// Copyright (C) 2013
// Glenn P. Downing
// -------------------------

/*
 To run the program:
 % g++ -pedantic -std=c++0x -Wall AbstractCell.c++ Cell.c++ ConwayCell.c++ FredkinCell.c++ -o RunLife
 % valgrind RunLife > RunLife.out
 
 To configure Doxygen:
 doxygen -g
 That creates the file Doxyfile.
 Make the following edits:
 EXTRACT_ALL = YES
 EXTRACT_PRIVATE = YES
 EXTRACT_STATIC = YES
 GENERATE_LATEX = NO
 
 To document the program:
 doxygen Doxyfile
 */

// --------
// includes
// --------

#include <cassert> // assert
#include <iostream> // cout, endl
#include <fstream>
#include <stdexcept> // invalid_argument, out_of_range
#include "AbstractCell.h"
#include "FredkinCell.h"
#include "ConwayCell.h"
#include "Life.h"
#include "Cell.h"

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O
    
    
    fstream f;
    
    
    // ----------------------------
    // Start RunConwayCell.in Tests
    // ----------------------------
    
    f.open("RunLifeConway.in");
    
    // ------------------
    // Conway Cell 109x69
    // ------------------
    try {
        cout << "*** Life<ConwayCell> 109x69 Downing ***" << endl;
        /*
         read RunLifeConway.in // assume all Conway cells
         Simulate 283 moves.
         Print the first 10 grids (i.e. 0, 1, 2...9).
         Print the 283rd grid.
         Simulate 40 moves.
         Print the 323rd grid.
         Simulate 2177 moves.
         Print the 2500th grid.
         */
        
        bool pbool[2502];
        //fill pbool
        for(int i=0; i<10; i++){pbool[i]=true;}
        for(int i=10; i<2501; i++){pbool[i]=false;}
        pbool[283]=true;
        pbool[323]=true;
        pbool[2500]=true;
        Life<ConwayCell> L(pbool, f, cout, 2501);
        L.updateBoard();
        
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    try {
        cout << "*** Life<ConwayCell> 20x20 from austind ***" << endl;
        /*
         ----------- Test #1 From austind ------------
         read RunLifeConway.in // assume all Conway cells
         Simulate 10 moves.
         Print the 10th grid.
         */
        
        bool pbool[12] = {false};
        //fill pbool
        pbool[10] = true;
        Life<ConwayCell> L(pbool, f, cout, 11);
        L.updateBoard();
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    try {
        cout << "*** Life<ConwayCell> 24x16 from austind ***" << endl;
        /*
         ----------- Test #2 From austind ------------
         read RunLifeConway.in // assume all Conway cells
         Simulate 10 moves.
         Print the 10th grid.
         */
        
        bool pbool[12];
        //fill pbool
        pbool[10] = true;
        Life<ConwayCell> L(pbool, f, cout, 11);
        L.updateBoard();
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    try {
        cout << "*** Life<ConwayCell> 10x10 from tbarnett ***" << endl;
        /*
         ----------- Test #1 From tbarnett ------------
         read RunLifeConway.in // assume all Conway cells
         Simulate 3 moves.
         Print all 4 grids (includes generation 0).
         Population on Generation 0 = 50
         Population on Generation 1 = 48
         Population on Generation 2 = 28
         Population on Generation 3 = 22
         */
        
        bool pbool[5];
        //fill pbool
        pbool[0] = true;
        pbool[1] = true;
        pbool[2] = true;
        pbool[3] = true;
        
        Life<ConwayCell> L(pbool, f, cout, 4);
        L.updateBoard();
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    try {
        cout << "*** Life<ConwayCell> 20x20 from tbarnett ***" << endl;
        
        //----------- Test #2 From tbarnett ------------
        //read RunLifeConway.in // assume all Conway cells
        // Simulate 3 moves.
        // Print all 4 grids (includes generation 0).
        // Population on Generation 0 = 110
        // Population on Generation 1 = 20
        // Population on Generation 2 = 18
        // Population on Generation 3 = 20
        
        
        bool pbool[5] = {false};
        pbool[0] = true;
        pbool[1] = true;
        pbool[2] = true;
        pbool[3] = true;
        
        Life<ConwayCell> L(pbool, f, cout, 4);
        L.updateBoard();
        f.get();
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    try {
        cout << "*** Life<ConwayCell> 10x10 - Alternating Stars from jmunoz80 ***" << endl;
        
        //----------- Test #1 From jmunoz80 ------------
        //read RunLifeConway.in // assume all Conway cells
        // Simulate 100 moves.
        // Print grids:0, 1, 5, 10, 100
        
        bool pbool[102] = {false};
        pbool[0] = true;
        pbool[1] = true;
        pbool[5] = true;
        pbool[10] = true;
        pbool[101] = true;
        
        Life<ConwayCell> L(pbool, f, cout, 101);
        L.updateBoard();
        f.get();
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    try {
        cout << "*** Life<ConwayCell> 10x10 - Bow Shape from jmunoz80 ***" << endl;
        
        //----------- Test #2 From jmunoz80 ------------
        //read RunLifeConway.in // assume all Conway cells
        // Simulate 100 moves.
        // Print grids:0, 1, 5, 10, 100
        
        bool pbool[102] = {false};
        pbool[0] = true;
        pbool[1] = true;
        pbool[5] = true;
        pbool[10] = true;
        pbool[101] = true;
        
        Life<ConwayCell> L(pbool, f, cout, 101);
        L.updateBoard();
        f.get();
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<ConwayCell> 100x2 - Conway Trail ***" << endl;
        
        //----------- Test #2 From jmunoz80 ------------
        //read RunLifeConway.in // assume all Conway cells
        // Simulate 10 moves.
        // Print grids:0, 10
        
        bool pbool[11] = {false};
        pbool[0] = true;
        pbool[10] = true;
        
        Life<ConwayCell> L(pbool, f, cout, 11);
        L.updateBoard();
        f.get();
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    
    
    // // ------------------------------
    // // End of RunConwayCell.in Tests
    // // ------------------------------
    f.close();
    
    // // -----------------------------
    // // Start RunFredkinCell.in Tests
    // // -----------------------------
    
    f.open("RunLifeFredkin.in");
    
    // // ------------------
    // // Fredkin Cell 20x20
    // // ------------------
    
    try {
        cout << "*** Life<FredkinCell> 20x20 Downing ***" << endl;
    //     /*
    //     read RunLifeFredkin.in // assume all Fredkin cells
    //     Simulate 5 moves.
    //     Print every grid (i.e. 0, 1, 2...5)
        bool pbool[7] = {false};
        //fill pbool
        for(int x=0; x<6; x++)
            pbool[x]=true;
        Life<FredkinCell> L(pbool, f, cout, 6);
        L.updateBoard();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    try {
        cout << "*** Life<FredkinCell> 29x45 psteiner UT ***" << endl;
    //     /*
    //     ----------- Test #1 From psteiner ------------
    //     read RunLifeFredkin.in // assume all Fredkin cells
    //     Simulate 8 moves.
    //     Print every grid (i.e. 0, 1, 2...8)
    //     Generation = 0, Population = 31.
    //     Generation = 1, Population = 34.
    //     Generation = 2, Population = 54.
    //     Generation = 3, Population = 76.
    //     Generation = 4, Population = 106.
    //     Generation = 5, Population = 100.
    //     Generation = 6, Population = 138.
    //     Generation = 7, Population = 134.
    //     Generation = 8, Population = 124.
    //     // */
        bool pbool[10];
        for (int i = 0; i < 9; ++i)
        {
            pbool[i] = 1;
        }
        // //fill pbool
        Life<FredkinCell> L(pbool, f, cout, 9);
        L.updateBoard();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    try {
        cout << "*** Life<FredkinCell> 3x2 psteiner - Age test ***" << endl;
    //     /*
    //     ----------- Test #2 From psteiner ------------
    //     read RunLifeFredkin.in // assume all Fredkin cells
    //     Simulate 10 moves.
    //     Print every grid (i.e. 0, 1, 2...10)
    
    //     Every cell should remain in position, but increment in age
        bool pbool[12];
        for (int i = 0; i < 12; ++i)
        {
            pbool[i] = 1;
        }
        //fill pbool
        Life<FredkinCell> L(pbool, f, cout, 11);
        L.updateBoard();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    try {
        cout << "*** Life<FredkinCell> 33x9 Fredkin Game Tim ***" << endl;
    //     /*
    //     read RunLifeFredkin.in // assume all Fredkin cells
    //     Simulate 10 moves.
    //     Print every grid (i.e. 0, 1, 2...10)
    
    //     Every cell should remain in position, but increment in age    
        bool pbool[12];
        for (int i = 0; i < 12; ++i)
        {
            pbool[i] = 1;
        }
        //fill pbool
        Life<FredkinCell> L(pbool, f, cout, 11);
        L.updateBoard();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    // // ------------------------------
    // // End of RunFredkinCell.in Tests
    // // ------------------------------
    f.close();
    
    // --------------------------
    // Start RunLifeCell.in Tests
    // --------------------------
    
    f.open("RunLifeCell.in");
    
    // ----------
    // Cell 20x20
    // ----------
    try {
        cout << "*** Life<Cell> 20x20 ***" << endl;
        /*
         read RunLifeCell.in // assume all Fredkin cells
         Simulate 5 moves.
         Print every grid (i.e. 0, 1, 2...5)
         */
        bool pbool[7];
        //fill pbool
        for(int i=0; i<=5; i++){pbool[i]=true;}
        Life<Cell> L(pbool, f, cout, 6);
        L.updateBoard();
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    try {
        cout << "*** Life<Cell> 10x5 - Wave Shape from jmunoz80 ***" << endl;
        /*
         read RunLifeCell.in // assume all Fredkin cells
         Simulate 5 moves.
         Print every grid (i.e. 0, 1, 2...5)
         */
        bool pbool[7];
        //fill pbool
        for(int i=0; i<=5; i++){pbool[i]=true;}
        Life<Cell> L(pbool, f, cout, 6);
        L.updateBoard();
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    try {
        cout << "*** Life<Cell> 10x5 - Supersymmetry from jmunoz80 ***" << endl;
        /*
         read RunLifeCell.in // assume all Fredkin cells
         Simulate 5 moves.
         Print every grid (i.e. 0, 1, 2...5)
         */
        bool pbool[7];
        //fill pbool
        for(int i=0; i<=5; i++){pbool[i]=true;}
        Life<Cell> L(pbool, f, cout, 6);
        L.updateBoard();
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    try {
        cout << "*** Life<Cell> 8x13 - HI from andrews ***" << endl;
        /*
         read RunLifeCell.in // assume all Fredkin cells
         Simulate 5 moves.
         Print every grid (i.e. 0, 1, 2...5)
         */
        bool pbool[7];
        //fill pbool
        for(int i=0; i<=5; i++){pbool[i]=true;}
        Life<Cell> L(pbool, f, cout, 6);
        L.updateBoard();
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    try {
        cout << "*** Life<Cell> 33x9 - Mixed Game Tim***" << endl;
        /*
         read RunLifeCell.in // assume all Fredkin cells
         Simulate 5 moves.
         Print every grid (i.e. 0, 1, 2...5)
         */
        bool pbool[7];
        //fill pbool
        for(int i=0; i<=5; i++){pbool[i]=true;}
        Life<Cell> L(pbool, f, cout, 6);
        L.updateBoard();
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    // ---------------------------
    // End of RunLifeCell.in Tests
    // ---------------------------
    f.close();
    
    return 0;
}