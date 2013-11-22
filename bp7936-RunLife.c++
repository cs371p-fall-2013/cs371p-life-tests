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
#include <iostream>  // cout, endl
#include <stdexcept> // invalid_argument, out_of_range
#include <stdio.h>
#include <fstream>
#include <sstream>
#include "Cell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Life.h"
#include "AbstractCell.h"

// ----
// main
// ----

int main () {
    using namespace std;
	string buffer;

	/* Begin read from Conway acceptance test file. */
	ifstream conway_in("RunLifeConway.in");

    // ------------------
    // Conway Cell 109x69
    // ------------------

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

        Life<ConwayCell> life(conway_in);

        life.print_grid();
        for (int i = 0; i < 10; ++i) 
		{
            life.simulate_generation();
            life.print_grid();
		}
		life.simulate_life(283);
		life.print_grid();
		life.simulate_life(323);
		life.print_grid();
		life.simulate_life(2500);
		life.print_grid();
		cout << endl;

		/* Advance to the next test in the file. */
		getline(conway_in, buffer);
		getline(conway_in, buffer);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

	// --------------------------
    // Conway Cell 50x50 - bp7936
    // --------------------------

    try {
        cout << "*** Life<ConwayCell> 50x50 ***" << endl;
 
        Life<ConwayCell> life(conway_in);

        life.print_grid();
        for (int i = 0; i < 5; ++i) 
		{
            life.simulate_generation();
            life.print_grid();
		}
		cout << endl;

		/* Advance to the next test in the file. */
		getline(conway_in, buffer);
		getline(conway_in, buffer);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

	// --------------------------
    // Conway Cell 50x50 - bp7936
    // --------------------------

    try {
        cout << "*** Life<ConwayCell> 50x50 ***" << endl;
 
        Life<ConwayCell> life(conway_in);

        life.print_grid();
        for (int i = 0; i < 10; ++i) 
		{
            life.simulate_generation();
            life.print_grid();
		}
		cout << endl;

		/* Advance to the next test in the file. */
		getline(conway_in, buffer);
		getline(conway_in, buffer);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

	// --------------------------
    // Conway Cell 50x50 - bp7936
    // --------------------------

    try {
        cout << "*** Life<ConwayCell> 50x50 ***" << endl;
 
        Life<ConwayCell> life(conway_in);

        life.print_grid();
        for (int i = 0; i < 8; ++i) 
		{
            life.simulate_generation();
            life.print_grid();
		}
		cout << endl;

		/* Advance to the next test in the file. */
		getline(conway_in, buffer);
		getline(conway_in, buffer);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

	// --------------------------
    // Conway Cell 50x50 - bp7936
    // --------------------------

    try {
        cout << "*** Life<ConwayCell> 50x50 ***" << endl;
 
        Life<ConwayCell> life(conway_in);

        life.print_grid();
        for (int i = 0; i < 7; ++i) 
		{
            life.simulate_generation();
            life.print_grid();
		}
		cout << endl;

		/* Advance to the next test in the file. */
		getline(conway_in, buffer);
		getline(conway_in, buffer);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


	/* Close the Conway acceptance test file. */
	conway_in.close();

	/* Begin read from Fredkin acceptance test file. */
	ifstream fredkin_in("RunLifeFredkin.in");

    // ------------------
    // Fredkin Cell 20x20
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 20x20 ***" << endl;
        /*
        read RunLifeFredkin.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */

		Life<FredkinCell> life(fredkin_in);

		life.print_grid();
		for(int i = 0; i < 5; i++)
		{
			life.simulate_generation();
			life.print_grid();
		}
		cout << endl;

		/* Advance to the next test in the file. */
		getline(fredkin_in, buffer);
		getline(fredkin_in, buffer);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

	// ---------------------------
    // Fredkin Cell 30x20 - bp7936
    // ---------------------------

    try {
        cout << "*** Life<FredkinCell> 30x20 ***" << endl;
  
		Life<FredkinCell> life(fredkin_in);

		life.print_grid();
		for(int i = 0; i < 5; i++)
		{
			life.simulate_generation();
			life.print_grid();
		}
		cout << endl;

		/* Advance to the next test in the file. */
		getline(fredkin_in, buffer);
		getline(fredkin_in, buffer);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

	// ---------------------------
    // Fredkin Cell 30x50 - bp7936
    // ---------------------------

    try {
        cout << "*** Life<FredkinCell> 30x50 ***" << endl;

		Life<FredkinCell> life(fredkin_in);

		life.print_grid();
		for(int i = 0; i < 5; i++)
		{
			life.simulate_generation();
			life.print_grid();
		}
		cout << endl;

		/* Advance to the next test in the file. */
		getline(fredkin_in, buffer);
		getline(fredkin_in, buffer);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

	// ---------------------------
    // Fredkin Cell 30x50 - bp7936
    // ---------------------------

    try {
        cout << "*** Life<FredkinCell> 30x50 ***" << endl;

		Life<FredkinCell> life(fredkin_in);

		life.print_grid();
		for(int i = 0; i < 5; i++)
		{
			life.simulate_generation();
			life.print_grid();
		}
		cout << endl;

		/* Advance to the next test in the file. */
		getline(fredkin_in, buffer);
		getline(fredkin_in, buffer);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

	// ---------------------------
    // Fredkin Cell 70x50 - bp7936
    // ---------------------------

    try {
        cout << "*** Life<FredkinCell> 70x50 ***" << endl;

		Life<FredkinCell> life(fredkin_in);

		life.print_grid();
		for(int i = 0; i < 5; i++)
		{
			life.simulate_generation();
			life.print_grid();
		}
		cout << endl;

		/* Advance to the next test in the file. */
		getline(fredkin_in, buffer);
		getline(fredkin_in, buffer);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

	// ---------------------------
    // Fredkin Cell 50x50 - bp7936
    // ---------------------------

    try {
        cout << "*** Life<FredkinCell> 50x50 ***" << endl;

		Life<FredkinCell> life(fredkin_in);

		life.print_grid();
		for(int i = 0; i < 5; i++)
		{
			life.simulate_generation();
			life.print_grid();
		}
		cout << endl;

		/* Advance to the next test in the file. */
		getline(fredkin_in, buffer);
		getline(fredkin_in, buffer);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

	/* Close the Fredkin acceptance test file. */
	fredkin_in.close();


	/* Begin read from Cell acceptance test file. */
	ifstream cell_in("RunLifeCell.in");

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

		Life<Cell> life(cell_in);
		life.print_grid();
		for(int i = 0; i < 5; i++)
		{
			life.simulate_generation();
			life.print_grid();
		}
		cout << endl;

		/* Advance to the next test in the file. */
		getline(cell_in, buffer);
		getline(cell_in, buffer);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

	
    // -------------------
    // Cell 50x50 - bp7936
    // -------------------

    try {
        cout << "*** Life<Cell> 20x20 ***" << endl;

		Life<Cell> life(cell_in);

		life.print_grid();
		for(int i = 0; i < 5; i++)
		{
			life.simulate_generation();
			life.print_grid();
		}
		cout << endl;

		/* Advance to the next test in the file. */
		getline(cell_in, buffer);
		getline(cell_in, buffer);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

	 // -------------------
    // Cell 50x50 - bp7936
    // -------------------

    try {
        cout << "*** Life<Cell> 20x20 ***" << endl;

		Life<Cell> life(cell_in);

		life.print_grid();
		for(int i = 0; i < 6; i++)
		{
			life.simulate_generation();
			life.print_grid();
		}
		cout << endl;

		/* Advance to the next test in the file. */
		getline(cell_in, buffer);
		getline(cell_in, buffer);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

	 // -------------------
    // Cell 50x50 - bp7936
    // -------------------

    try {
        cout << "*** Life<Cell> 20x20 ***" << endl;

		Life<Cell> life(cell_in);

		life.print_grid();
		for(int i = 0; i < 7; i++)
		{
			life.simulate_generation();
			life.print_grid();
		}
		cout << endl;

		/* Advance to the next test in the file. */
		getline(cell_in, buffer);
		getline(cell_in, buffer);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

	 // -------------------
    // Cell 50x50 - bp7936
    // -------------------

    try {
        cout << "*** Life<Cell> 20x20 ***" << endl;

		Life<Cell> life(cell_in);

		life.print_grid();
		for(int i = 0; i < 8; i++)
		{
			life.simulate_generation();
			life.print_grid();
		}
		cout << endl;

		/* Advance to the next test in the file. */
		getline(cell_in, buffer);
		getline(cell_in, buffer);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

	/* Close the Cell acceptance test file. */
	cell_in.close();

    return 0;}
