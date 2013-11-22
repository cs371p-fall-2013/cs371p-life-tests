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
    EXTRACT_ALL            = YES
    EXTRACT_PRIVATE        = YES
    EXTRACT_STATIC         = YES
    GENERATE_LATEX         = NO

To document the program:
    doxygen Doxyfile
*/

// --------
// includes
// --------

#include <cassert>   // assert
#include <iostream>  // cin, cout, endl
#include <stdexcept> // invalid_argument, out_of_range
#include <fstream>
#include <sstream> 

#include "Life.h"
// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O

    ifstream file1; 
    file1.open("RunLifeConway.in");
    // istream* myOtherStream = static_cast<std::istream*>(myStream);
    ifstream file2;
    file2.open("RunLifeFredkin.in");
    ifstream file3;
    file3.open("RunLifeCell.in");

    // ------------------
    // Conway Cell 109x69
    // ------------------
/*
    try {
        cout << "*** Life<ConwayCell> 109x69 ***" << endl;
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
/*
            Life<ConwayCell> life;
            life.read(file1);//try cin
            ostringstream w;

            for(int i = 0; i < 283 + 40 + 2177; i++){
                if(i < 10 || i == 283 || i == 323)
                    life.printGrid(w);
                life.nextGen();
            }
            life.printGrid(w);
            cout << w.str() << endl;
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        */
//---------------------
// OUR Acceptance Tests
//---------------------

    // ----------
    // ConwayCell 10x15
    // ----------

    try {
        cout << "*** Life<ConwayCell> 10x15 ***" << endl;
        /*
        read RunLifeCell.in // assume all Conway cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
            Life<ConwayCell> life;
            life.read(file1);//try cin
            ostringstream w;

            for(int i = 0; i < 5; i++){
                life.printGrid(w);
                life.nextGen();
            }
            life.printGrid(w);
            cout << w.str() << endl;
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // ConwayCell 15x15
    // ----------

    try {
        cout << "*** Life<ConwayCell> 15x15 ***" << endl;
        /*
        read RunLifeCell.in // assume all Conway cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
            Life<ConwayCell> life;
            life.read(file1);//try cin
            ostringstream w;

            for(int i = 0; i < 5; i++){
                life.printGrid(w);
                life.nextGen();
            }
            life.printGrid(w);
            cout << w.str() << endl;
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // ConwayCell 5x15
    // ----------

    try {
        cout << "*** Life<ConwayCell> 5x15 ***" << endl;
        /*
        read RunLifeCell.in // assume all Conway cells
        Simulate 10 moves.
        Print first 5 grids (i.e. 0, 1, 2...5)
        Print last grid
        */
            Life<ConwayCell> life;
            life.read(file1);//try cin
            ostringstream w;

            for(int i = 0; i < 10; i++){
                if(i <= 5)
                    life.printGrid(w);
                life.nextGen();
            }
            life.printGrid(w);
            cout << w.str() << endl;
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // ConwayCell 10x10
    // ----------

    try {
        cout << "*** Life<ConwayCell> 10x10 ***" << endl;
        /*
        read RunLifeCell.in // assume all Conway cells
        Simulate 6 moves.
        Print first 6 grids (i.e. 0, 1, 2...6)
        Print every 10th 
        */
            Life<ConwayCell> life;
            life.read(file1);//try cin
            ostringstream w;

            for(int i = 0; i < 6; i++){
                life.printGrid(w);
                life.nextGen();
            }
            life.printGrid(w);
            cout << w.str() << endl;
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

//-------------------------
// OUR Acceptance Tests END
//-------------------------


    // ------------------
    // Fredkin Cell 20x20
    // ------------------
/*
    try {
        cout << "*** Life<FredkinCell> 20x20 ***" << endl;
        /*
        read RunLifeFredkin.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        *//*
            Life<FredkinCell> life;
            life.read(file2);//try cin
            ostringstream w;

            for(int i = 0; i < 5; i++){
                life.printGrid(w);
                life.nextGen();
            }
            life.printGrid(w);
            cout << w.str() << endl;
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
*/
//---------------------
// OUR Acceptance Tests
//---------------------

    // ----------
    // FredkinCell 10x20
    // ----------

    try {
        cout << "*** Life<FredkinCell> 10x20 ***" << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
            Life<FredkinCell> life;
            life.read(file2);//try cin
            ostringstream w;

            for(int i = 0; i < 5; i++){
                life.printGrid(w);
                life.nextGen();
            }
            life.printGrid(w);
            cout << w.str() << endl;
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // FredkinCell 20x10
    // ----------

    try {
        cout << "*** Life<FredkinCell> 20x10 ***" << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
            Life<FredkinCell> life;
            life.read(file2);//try cin
            ostringstream w;

            for(int i = 0; i < 5; i++){
                life.printGrid(w);
                life.nextGen();
            }
            life.printGrid(w);
            cout << w.str() << endl;
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // FredkinCell 10x20
    // ----------

    try {
        cout << "*** Life<FredkinCell> 10x20 ***" << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 10 moves.
        Print first 5 grids (i.e. 0, 1, 2...5)
        Print last grid
        */
            Life<FredkinCell> life;
            life.read(file2);//try cin
            ostringstream w;

            for(int i = 0; i < 10; i++){
                if(i < 5)
                    life.printGrid(w);
                life.nextGen();
            }
            life.printGrid(w);
            cout << w.str() << endl;
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // FredkinCell 20x25
    // ----------

    try {
        cout << "*** Life<FredkinCell> 20x25 ***" << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 15 moves.
        Print first 5 grids (i.e. 0, 1, 2...5)
        Print every 10th 
        */
            Life<FredkinCell> life;
            life.read(file2);//try cin
            ostringstream w;

            for(int i = 0; i < 50; i++){
                if(i < 5 || i%10 == 0)
                    life.printGrid(w);
                life.nextGen();
            }
            life.printGrid(w);
            cout << w.str() << endl;
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

//-------------------------
// OUR Acceptance Tests END
//-------------------------


    // ----------
    // Cell 20x20
    // ----------
/*
    try {
        cout << "*** Life<Cell> 20x20 ***" << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        *//*
            Life<Cell> life;
            life.read(file3);//try cin
            ostringstream w;

            for(int i = 0; i < 5; i++){
                life.printGrid(w);
                life.nextGen();
            }
            life.printGrid(w);
            cout << w.str() << endl;
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
*/
//---------------------
// OUR Acceptance Tests
//---------------------

    // ----------
    // Cell 10x20
    // ----------

    try {
        cout << "*** Life<Cell> 10x20 ***" << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
            Life<Cell> life;
            life.read(file3);
            ostringstream w;

            for(int i = 0; i < 5; i++){
                life.printGrid(w);
                life.nextGen();
            }
            life.printGrid(w);
            cout << w.str() << endl;
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // Cell 20x10
    // ----------

    try {
        cout << "*** Life<Cell> 20x10 ***" << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
            Life<Cell> life;
            life.read(file3);//try cin
            ostringstream w;

            for(int i = 0; i < 5; i++){
                life.printGrid(w);
                life.nextGen();
            }
            life.printGrid(w);
            cout << w.str() << endl;
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // Cell 10x20
    // ----------

    try {
        cout << "*** Life<Cell> 10x20 ***" << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 10 moves.
        Print first 5 grids (i.e. 0, 1, 2...5)
        Print last grid
        */
            Life<Cell> life;
            life.read(file3);//try cin
            ostringstream w;

            for(int i = 0; i < 10; i++){
                if(i < 5)
                    life.printGrid(w);
                life.nextGen();
            }
            life.printGrid(w);
            cout << w.str() << endl;
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // Cell 20x25
    // ----------

    try {
        cout << "*** Life<Cell> 20x25 ***" << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 15 moves.
        Print first 5 grids (i.e. 0, 1, 2...5)
        Print every 10th 
        */
            Life<Cell> life;
            life.read(file3);//try cin
            ostringstream w;

            for(int i = 0; i < 50; i++){
                if(i < 5 || i%10 == 0)
                    life.printGrid(w);
                life.nextGen();
            }
            life.printGrid(w);
            cout << w.str() << endl;
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

//-------------------------
// OUR Acceptance Tests END
//-------------------------

        file1.close();
        file2.close();
        file3.close();

    return 0;}
