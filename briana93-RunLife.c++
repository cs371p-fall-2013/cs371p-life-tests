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
#include <string> 
#include <iostream>  // cout, endl
#include <sstream>
#include <fstream>   // file reading
#include <stdexcept> // invalid_argument, out_of_range
#include "Life.h"
#include "Cell.h"



// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O
	
    // ------------------
    // Conway Cell 109x69
    // ------------------
    ifstream fredkin;
    fredkin.open ("RunLifeFredkin.in");

    ifstream conway;
    conway.open ("RunLifeConway.in");

    ifstream cell;
    cell.open ("RunLifeCell.in");


    try {
            cout << "*** Life<ConwayCell> 109x69 Downing***" << endl;
            Life<ConwayCell> li;
            li.setSize(conway);
            li.populateEnvironment(conway);
            int i = 0;
            for(i = 0; i < 10; i++) {
                li.countPopulation();
                cout << "Generation = " << i << ", " << "Population = " << li.getPopulation() << endl;
                li.printBoard();  
                li.runSimulate();
                
            }
             li.countPopulation();
                cout << "Generation = " << i << ", " << "Population = " << li.getPopulation() << endl;
                li.printBoard();  
                //li.runSimulate();

            for(i = 10; i < 283; i++) {
                li.runSimulate();
            }
            cout << "Generation = " << i << ", " << "Population = " << li.getPopulation() << endl;
            li.printBoard();

            for(i = 283; i < 323; i++) {
                li.runSimulate();
            }
            cout << "Generation = " << i << ", " << "Population = " << li.getPopulation() << endl;
            li.printBoard();

            for(i = 323; i < 2500; i++) {
                li.runSimulate();
            }
             cout << "Generation = " << i << ", " << "Population = " << li.getPopulation() << endl;
            li.printBoard();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Fredkin Cell 20x20
    // ------------------

    try {
            cout << "*** Life<FredkinCell> 20x20 Downing***" << endl;
            Life<FredkinCell> li;
            li.setSize(fredkin);
            li.populateEnvironment(fredkin);

        for(int i = 0; i <= 5; i++) {
            li.countPopulation();
            cout << "Generation = " << i << ", " << "Population = " << li.getPopulation() << endl;
            li.printBoard();
            li.runSimulate();
            
            }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // Cell 20x20
    // ----------

    try {
            cout << "*** Life<Cell> 20x20 Downing***" << endl;
            Life<Cell> li;
            li.setSize(cell);
            li.populateEnvironment(cell);

            for(int i = 0; i <= 5; i++) {
                li.countPopulation();
                cout << "Generation = " << i << ", " << "Population = " << li.getPopulation() << endl;
                li.printBoard();
                li.runSimulate();
                
            }

    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
            cout << "*** Life<ConwayCell> 70x2 ASM2262***" << endl;

            Life<ConwayCell> li;
            li.setSize(conway);
            li.populateEnvironment(conway);

            for(int i = 0; i <= 5; i++) {
                li.countPopulation();
                cout << "Generation = " << i << ", " << "Population = " << li.getPopulation() << endl;
                li.printBoard();
                li.runSimulate();
            }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
            cout << "*** Life<FredkinCell> 10x10 ASM2262***" << endl;

            Life<FredkinCell> li;
            li.setSize(fredkin);
            li.populateEnvironment(fredkin);

            for(int i = 0; i <= 5; i++) {
                li.countPopulation();
                cout << "Generation = " << i << ", " << "Population = " << li.getPopulation() << endl;
                li.printBoard();
                li.runSimulate();
                
            }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
            cout << "*** Life<Cell> 40x25 ASM2262***" << endl;

            Life<Cell> li;
            li.setSize(cell);
            li.populateEnvironment(cell);

            for(int i = 0; i <= 5; i++) {
                li.countPopulation();
                cout << "Generation = " << i << ", " << "Population = " << li.getPopulation() << endl;
                li.printBoard();
                li.runSimulate();
                
            }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
            cout << "*** Life<ConwayCell> 28x46 DAVISMC***" << endl;

            Life<ConwayCell> li;
            li.setSize(conway);
            li.populateEnvironment(conway);

            for(int i = 0; i <= 5; i++) {
                li.countPopulation();
                cout << "Generation = " << i << ", " << "Population = " << li.getPopulation() << endl;
                li.printBoard();
                li.runSimulate();
                
            }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
            cout << "*** Life<FredkinCell> 26x20 DAVISMC***" << endl;

            Life<FredkinCell> li;
            li.setSize(fredkin);
            li.populateEnvironment(fredkin);

            for(int i = 0; i <= 5; i++) {
                li.countPopulation();
                cout << "Generation = " << i << ", " << "Population = " << li.getPopulation() << endl;
                li.printBoard();
                li.runSimulate();
                
            }
        }

    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
            cout << "*** Life<Cell> 15x22 DAVISMC***" << endl;

            Life<Cell> li;
            li.setSize(cell);
            li.populateEnvironment(cell);

            for(int i = 0; i <= 5; i++) {
                li.countPopulation();
                cout << "Generation = " << i << ", " << "Population = " << li.getPopulation() << endl;
                li.printBoard();
                li.runSimulate();
                
            }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
            cout << "*** Life<ConwayCell> 16x34 JKHUST***" << endl;

            Life<ConwayCell> li;
            li.setSize(conway);
            li.populateEnvironment(conway);

            for(int i = 0; i <= 5; i++) {
                li.countPopulation();
                cout << "Generation = " << i << ", " << "Population = " << li.getPopulation() << endl;
                li.printBoard();
                li.runSimulate();
                
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
            cout << "*** Life<FredkinCell> 24x22 JKHUST***" << endl;

            Life<FredkinCell> li;
            li.setSize(fredkin);
            li.populateEnvironment(fredkin);

            for(int i = 0; i <= 5; i++) {
                li.countPopulation();
                cout << "Generation = " << i << ", " << "Population = " << li.getPopulation() << endl;
                li.printBoard();
                li.runSimulate();
                
            }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
            cout << "*** Life<Cell> 10x30 JKHUST***" << endl;

            Life<Cell> li;
            li.setSize(cell);
            li.populateEnvironment(cell);

            for(int i = 0; i <= 5; i++) {
                li.countPopulation();
                cout << "Generation = " << i << ", " << "Population = " << li.getPopulation() << endl;
                li.printBoard();
                li.runSimulate();
                
            }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
            cout << "*** Life<ConwayCell> 17x17 JMADD***" << endl;

            Life<ConwayCell> li;
            li.setSize(conway);
            li.populateEnvironment(conway);

            for(int i = 0; i <= 5; i++) {
                li.countPopulation();
                cout << "Generation = " << i << ", " << "Population = " << li.getPopulation() << endl;
                li.printBoard();
                li.runSimulate();
                
            }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
            cout << "*** Life<FredkinCell> 7x7 JMADD***" << endl;

            Life<FredkinCell> li;
            li.setSize(fredkin);
            li.populateEnvironment(fredkin);

            for(int i = 0; i <= 5; i++) {
                li.countPopulation();
                cout << "Generation = " << i << ", " << "Population = " << li.getPopulation() << endl;
                li.printBoard();
                li.runSimulate();
                
            }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
            cout << "*** Life<Cell> 100x100 JMADD***" << endl;

            Life<Cell> li;
            li.setSize(cell);
            li.populateEnvironment(cell);

            for(int i = 0; i <= 5; i++) {
                li.countPopulation();
                cout << "Generation = " << i << ", " << "Population = " << li.getPopulation() << endl;
                li.printBoard();
                li.runSimulate();
                
            }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
            cout << "*** Life<ConwayCell> 15x9 JMILLS***" << endl;

            Life<ConwayCell> li;
            li.setSize(conway);
            li.populateEnvironment(conway);

            for(int i = 0; i <= 5; i++) {
                li.countPopulation();
                cout << "Generation = " << i << ", " << "Population = " << li.getPopulation() << endl;
                li.printBoard();
                li.runSimulate();
                
            }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
            cout << "*** Life<FredkinCell> 17x17 JMILLS***" << endl;

            Life<FredkinCell> li;
            li.setSize(fredkin);
            li.populateEnvironment(fredkin);

            for(int i = 0; i <= 5; i++) {
                li.countPopulation();
                cout << "Generation = " << i << ", " << "Population = " << li.getPopulation() << endl;
                li.printBoard();
                li.runSimulate();
                
            }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
            cout << "*** Life<Cell> 5x10 JMILLS***" << endl;

            Life<Cell> li;
            li.setSize(cell);
            li.populateEnvironment(cell);

            for(int i = 0; i <= 5; i++) {
                li.countPopulation();
                cout << "Generation = " << i << ", " << "Population = " << li.getPopulation() << endl;
                li.printBoard();
                li.runSimulate();
                
            }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
            cout << "*** Life<ConwayCell> 10x10 BRIEVANS***" << endl;

            Life<ConwayCell> li;
            li.setSize(conway);
            li.populateEnvironment(conway);

            for(int i = 0; i <= 5; i++) {
                li.countPopulation();
                cout << "Generation = " << i << ", " << "Population = " << li.getPopulation() << endl;
                li.printBoard();
                li.runSimulate();
                
            }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
            cout << "*** Life<FredkinCell> 10x10 BRIEVANS***" << endl;

            Life<FredkinCell> li;
            li.setSize(fredkin);
            li.populateEnvironment(fredkin);

            for(int i = 0; i <= 5; i++) {
                li.countPopulation();
                cout << "Generation = " << i << ", " << "Population = " << li.getPopulation() << endl;
                li.printBoard();
                li.runSimulate();
                
            }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);} 

    try {
            cout << "*** Life<Cell> 10x10 BRIEVANS***" << endl;

            Life<Cell> li;
            li.setSize(cell);
            li.populateEnvironment(cell);

            for(int i = 0; i <= 25; i++) {
                li.countPopulation();
                cout << "Generation = " << i << ", " << "Population = " << li.getPopulation() << endl;
                li.printBoard();
                li.runSimulate();
                
            }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}   
    
    try {
            cout << "*** Life<ConwayCell> 15x15 BRIEVANS***" << endl;

            Life<ConwayCell> li;
            li.setSize(conway);
            li.populateEnvironment(conway);

            for(int i = 0; i <= 5; i++) {
                li.countPopulation();
                cout << "Generation = " << i << ", " << "Population = " << li.getPopulation() << endl;
                li.printBoard();
                li.runSimulate();
                
            }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
            cout << "*** Life<FredkinCell> 15x15 BRIEVANS***" << endl;

            Life<FredkinCell> li;
            li.setSize(fredkin);
            li.populateEnvironment(fredkin);

            for(int i = 0; i <= 5; i++) {
                li.countPopulation();
                cout << "Generation = " << i << ", " << "Population = " << li.getPopulation() << endl;
                li.printBoard();
                li.runSimulate();
                
            }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
            cout << "*** Life<Cell> 15x15 BRIEVANS***" << endl;

            Life<Cell> li;
            li.setSize(cell);
            li.populateEnvironment(cell);

            for(int i = 0; i <= 30; i++) {
                li.countPopulation();
                cout << "Generation = " << i << ", " << "Population = " << li.getPopulation() << endl;
                li.printBoard();
                li.runSimulate();
                
            }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
            cout << "*** Life<ConwayCell> 20x20 BRIEVANS***" << endl;

            Life<ConwayCell> li;
            li.setSize(conway);
            li.populateEnvironment(conway);

            for(int i = 0; i <= 5; i++) {
                li.countPopulation();
                cout << "Generation = " << i << ", " << "Population = " << li.getPopulation() << endl;
                li.printBoard();
                li.runSimulate();
                
            }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
            cout << "*** Life<FredkinCell> 20x20 BRIEVANS***" << endl;

            Life<FredkinCell> li;
            li.setSize(fredkin);
            li.populateEnvironment(fredkin);

            for(int i = 0; i <= 30; i++) {
                li.countPopulation();
                cout << "Generation = " << i << ", " << "Population = " << li.getPopulation() << endl;
                li.printBoard();
                li.runSimulate();
                
            }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
            cout << "*** Life<Cell> 20x20 BRIEVANS***" << endl;

            Life<Cell> li;
            li.setSize(cell);
            li.populateEnvironment(cell);

            for(int i = 0; i <= 5; i++) {
                li.countPopulation();
                cout << "Generation = " << i << ", " << "Population = " << li.getPopulation() << endl;
                li.printBoard();
                li.runSimulate();
                
            }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
            cout << "*** Life<ConwayCell> 1x1 BRIEVANS***" << endl;

            Life<ConwayCell> li;
            li.setSize(conway);
            li.populateEnvironment(conway);

            for(int i = 0; i <= 5; i++) {
                li.countPopulation();
                cout << "Generation = " << i << ", " << "Population = " << li.getPopulation() << endl;
                li.printBoard();
                li.runSimulate();
                
            }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
            cout << "*** Life<FredkinCell> 1x1 BRIEVANS***" << endl;

            Life<FredkinCell> li;
            li.setSize(fredkin);
            li.populateEnvironment(fredkin);

            for(int i = 0; i <= 5; i++) {
                li.countPopulation();
                cout << "Generation = " << i << ", " << "Population = " << li.getPopulation() << endl;
                li.printBoard();
                li.runSimulate();
                
            }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
            cout << "*** Life<Cell> 1x1 BRIEVANS***" << endl;

            Life<Cell> li;
            li.setSize(cell);
            li.populateEnvironment(cell);

            for(int i = 0; i <= 30; i++) {
                li.countPopulation();
                cout << "Generation = " << i << ", " << "Population = " << li.getPopulation() << endl;
                li.printBoard();
                li.runSimulate();
                
            }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
            cout << "*** Life<ConwayCell> 20x20 BRIEVANS***" << endl;

            Life<ConwayCell> li;
            li.setSize(conway);
            li.populateEnvironment(conway);

            for(int i = 0; i <= 5; i++) {
                li.countPopulation();
                cout << "Generation = " << i << ", " << "Population = " << li.getPopulation() << endl;
                li.printBoard();
                li.runSimulate();
                
            }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
            cout << "*** Life<FredkinCell> 20x20 BRIEVANS***" << endl;

            Life<FredkinCell> li;
            li.setSize(fredkin);
            li.populateEnvironment(fredkin);

            for(int i = 0; i <= 20; i++) {
                li.countPopulation();
                cout << "Generation = " << i << ", " << "Population = " << li.getPopulation() << endl;
                li.printBoard();
                li.runSimulate();
                
            }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
            cout << "*** Life<Cell> 20x20 BRIEVANS***" << endl;

            Life<Cell> li;
            li.setSize(cell);
            li.populateEnvironment(cell);

            for(int i = 0; i <= 5; i++) {
                li.countPopulation();
                cout << "Generation = " << i << ", " << "Population = " << li.getPopulation() << endl;
                li.printBoard();
                li.runSimulate();
                
            }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
            cout << "*** Life<ConwayCell> 40x40 BRIEVANS***" << endl;

            Life<ConwayCell> li;
            li.setSize(conway);
            li.populateEnvironment(conway);

            for(int i = 0; i <= 5; i++) {
                li.countPopulation();
                cout << "Generation = " << i << ", " << "Population = " << li.getPopulation() << endl;
                li.printBoard();
                li.runSimulate();
                
            }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
            cout << "*** Life<FredkinCell> 40x40 BRIEVANS***" << endl;

            Life<FredkinCell> li;
            li.setSize(fredkin);
            li.populateEnvironment(fredkin);

            for(int i = 0; i <= 30; i++) {
                li.countPopulation();
                cout << "Generation = " << i << ", " << "Population = " << li.getPopulation() << endl;
                li.printBoard();
                li.runSimulate();
                
            }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
            cout << "*** Life<Cell> 40x40 BRIEVANS***" << endl;

            Life<Cell> li;
            li.setSize(cell);
            li.populateEnvironment(cell);

            for(int i = 0; i <= 5; i++) {
                li.countPopulation();
                cout << "Generation = " << i << ", " << "Population = " << li.getPopulation() << endl;
                li.printBoard();
                li.runSimulate();
                
            }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
            cout << "*** Life<ConwayCell> 40x40 BRIEVANS***" << endl;

            Life<ConwayCell> li;
            li.setSize(conway);
            li.populateEnvironment(conway);

            for(int i = 0; i <= 5; i++) {
                li.countPopulation();
                cout << "Generation = " << i << ", " << "Population = " << li.getPopulation() << endl;
                li.printBoard();
                li.runSimulate();
                
            }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
            cout << "*** Life<FredkinCell> 40x40 BRIEVANS***" << endl;

            Life<FredkinCell> li;
            li.setSize(fredkin);
            li.populateEnvironment(fredkin);

            for(int i = 0; i <= 5; i++) {
                li.countPopulation();
                cout << "Generation = " << i << ", " << "Population = " << li.getPopulation() << endl;
                li.printBoard();
                li.runSimulate();
                
            }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
            cout << "*** Life<Cell> 40x40 BRIEVANS***" << endl;

            Life<Cell> li;
            li.setSize(cell);
            li.populateEnvironment(cell);

            for(int i = 0; i <= 5; i++) {
                li.countPopulation();
                cout << "Generation = " << i << ", " << "Population = " << li.getPopulation() << endl;
                li.printBoard();
                li.runSimulate();
                
            }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
            cout << "*** Life<ConwayCell> 20x80 BRIEVANS***" << endl;

            Life<ConwayCell> li;
            li.setSize(conway);
            li.populateEnvironment(conway);

            for(int i = 0; i <= 20; i++) {
                li.countPopulation();
                cout << "Generation = " << i << ", " << "Population = " << li.getPopulation() << endl;
                li.printBoard();
                li.runSimulate();
                
            }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
            cout << "*** Life<FredkinCell> 20x80 BRIEVANS***" << endl;

            Life<FredkinCell> li;
            li.setSize(fredkin);
            li.populateEnvironment(fredkin);

            for(int i = 0; i <= 5; i++) {
                li.countPopulation();
                cout << "Generation = " << i << ", " << "Population = " << li.getPopulation() << endl;
                li.printBoard();
                li.runSimulate();
                
            }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
            cout << "*** Life<Cell> 20x80 BRIEVANS***" << endl;

            Life<Cell> li;
            li.setSize(cell);
            li.populateEnvironment(cell);

            for(int i = 0; i <= 5; i++) {
                li.countPopulation();
                cout << "Generation = " << i << ", " << "Population = " << li.getPopulation() << endl;
                li.printBoard();
                li.runSimulate();
                
            }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
            cout << "*** Life<ConwayCell> 15x15 BRIEVANS***" << endl;

            Life<ConwayCell> li;
            li.setSize(conway);
            li.populateEnvironment(conway);

            for(int i = 0; i <= 5; i++) {
                li.countPopulation();
                cout << "Generation = " << i << ", " << "Population = " << li.getPopulation() << endl;
                li.printBoard();
                li.runSimulate();
                
            }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
            cout << "*** Life<FredkinCell> 15x15 BRIEVANS***" << endl;

            Life<FredkinCell> li;
            li.setSize(fredkin);
            li.populateEnvironment(fredkin);

            for(int i = 0; i <= 5; i++) {
                li.countPopulation();
                cout << "Generation = " << i << ", " << "Population = " << li.getPopulation() << endl;
                li.printBoard();
                li.runSimulate();
                
            }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
            cout << "*** Life<Cell> 15x15 BRIEVANS***" << endl;

            Life<Cell> li;
            li.setSize(cell);
            li.populateEnvironment(cell);

            for(int i = 0; i <= 10; i++) {
                li.countPopulation();
                cout << "Generation = " << i << ", " << "Population = " << li.getPopulation() << endl;
                li.printBoard();
                li.runSimulate();
                
            }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

        cell.close();
        conway.close();
        fredkin.close();

    return 0;}
