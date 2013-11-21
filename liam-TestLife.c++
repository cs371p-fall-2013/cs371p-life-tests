#include "gtest/gtest.h"

#include <sstream>

#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"
#include "Life.h"

using namespace std;

void readBoard(istream &in, vector<vector<ConwayCell> > &board, int &population) {
		int w, h;
		in >> h;
		in >> w;

		population = 0;
		char charRep;
		for (int r = 0; r < h; ++r) {
			board.push_back(vector<ConwayCell>());
			for (int c = 0; c < w; ++c) {
				in >> charRep;
				board[r].push_back(ConwayCell());
				board[r][c].init(charRep);
				if (board[r][c].checkAlive()) {
					++population;
				}
			}
		}
}

TEST(ConwayCell, initAlive) {
	ConwayCell cell;
	cell.init('*');
	ostringstream out;
	cell.print(out);
	ASSERT_EQ(out.str(), "*");
}

TEST(ConwayCell, initDead) {
	ConwayCell cell;
	cell.init('.');
	ostringstream out;
	cell.print(out);
	ASSERT_EQ(out.str(), ".");
}

TEST(FredkinCell, initAlive) {
	FredkinCell cell;
	cell.init('0');
	ostringstream out;
	cell.print(out);
	ASSERT_EQ(out.str(), "0");
}

TEST(FredkinCell, initDead) {
	FredkinCell cell;
	cell.init('-');
	ostringstream out;
	cell.print(out);
	ASSERT_EQ(out.str(), "-");
}

TEST(Cell, initAlive) {
	Cell cell (new FredkinCell());
	cell.init('0');
	ostringstream out;
	cell.print(out);
	ASSERT_EQ(out.str(), "0");
}

TEST(Cell, initDead) {
	Cell cell(new FredkinCell());
	cell.init('-');
	ostringstream out;
	cell.print(out);
	ASSERT_EQ(out.str(), "-");
}

TEST(Life, readGrid) {
	vector<vector<ConwayCell> > board;
	int pop = 0;
	string s = "4 4....\n.**.\n.**.\n....\n";
	istringstream in(s);
	readBoard(in, board, pop);
	Life<ConwayCell> life(4, 4, board, pop);
	ostringstream out;
	life.print(out, true);
	ASSERT_EQ(out.str(), s);
}

TEST(Life, directNeighbors) {
	vector<vector<ConwayCell> > board;
	int pop = 0;
	string s = "4 4....\n.**.\n.**.\n....\n";
	istringstream in(s);
	readBoard(in, board, pop);
	Life<ConwayCell> life(4, 4, board, pop);
	vector<bool> vec;
	life.getDirectNeighbors(0, 0, vec);
	ASSERT_EQ(2, vec.size());
	life.getDirectNeighbors(1, 0, vec);
	ASSERT_EQ(3, vec.size());
	life.getDirectNeighbors(1, 1, vec);
	ASSERT_EQ(4, vec.size());
}

TEST(Life, cornerNeighbors) {
	vector<vector<ConwayCell> > board;
	int pop = 0;
	string s = "4 4....\n.**.\n.**.\n....\n";
	istringstream in(s);
	readBoard(in, board, pop);
	//	life.readGrid(in);
	Life<ConwayCell> life(4, 4, board, pop);
	vector<bool> vec;
	life.getCornerNeighbors(0, 0, vec);
	ASSERT_EQ(1, vec.size());
	life.getCornerNeighbors(1, 0, vec);
	ASSERT_EQ(2, vec.size());
	life.getCornerNeighbors(1, 1, vec);
	ASSERT_EQ(4, vec.size());
}

TEST(Life, step_unchanged) {
	vector<vector<ConwayCell> > board;
	int pop = 0;
	string s = "4 4....\n.**.\n.**.\n....\n";
	istringstream in(s);
	readBoard(in, board, pop);
	Life<ConwayCell> life(4, 4, board, pop);
	life.step();
	ostringstream out;
	life.print(out, true);
	ASSERT_EQ(s, out.str());
}

TEST(Life, step_die) {
	vector<vector<ConwayCell> > board;
	int pop = 0;
	//	Life<ConwayCell> life(4, 4);
	string s = "4 4....\n.**.\n....\n....\n";
	istringstream in(s);
	readBoard(in, board, pop);
	Life<ConwayCell> life(4, 4, board, pop);
	//	life.readGrid(in);
	life.step();
	ostringstream out;
	life.print(out, true);
	ASSERT_EQ("4 4....\n....\n....\n....\n", out.str());
}

TEST(Life, beehive) {
	vector<vector<ConwayCell> > board;
	int pop = 0;
	//	Life<ConwayCell> life(3, 4);
	string s = "3 4";
	s += ".**.\n";
	s += "*..*\n";
	s += ".**.\n";
	istringstream in(s);
	readBoard(in, board, pop);
	Life<ConwayCell> life(3, 4, board, pop);
	//	life.readGrid(in);
	life.step();
	life.step();
	ostringstream out;
	life.print(out, true);
	ASSERT_EQ(s, out.str());
}

TEST(Life, loaf) {
	vector<vector<ConwayCell> > board;
	int pop = 0;
	//	Life<ConwayCell> life(4, 4);
	string s = "4 4";
	s += ".**.\n";
	s += "*..*\n";
	s += ".*.*\n";
	s += "..*.\n";
	istringstream in(s);
	readBoard(in, board, pop);
	Life<ConwayCell> life(4, 4, board, pop);
	//	life.readGrid(in);
	life.step();
	life.step();
	ostringstream out;
	life.print(out, true);
	ASSERT_EQ(s, out.str());
}

TEST(Life, boat) {
	vector<vector<ConwayCell> > board;
	int pop = 0;
	//	Life<ConwayCell> life(3, 3);
	string s = "3 3";
	s += "**.\n";
	s += "*.*\n";
	s += ".*.\n";
	istringstream in(s);
	readBoard(in, board, pop);
	Life<ConwayCell> life(3, 3, board, pop);
	//	life.readGrid(in);
	life.step();
	life.step();
	ostringstream out;
	life.print(out, true);
	ASSERT_EQ(s, out.str());
}

TEST(Life, blinker) {
	vector<vector<ConwayCell> > board;
	int pop = 0;
	//	Life<ConwayCell> life(3, 3);
	string s = "3 3";
	s += ".*.\n";
	s += ".*.\n";
	s += ".*.\n";
	string s2 = "3 3";
	s2 += "...\n";
	s2 += "***\n";
	s2 += "...\n";
	istringstream in(s);
	ostringstream out;
	ostringstream out2;
	readBoard(in, board, pop);
	Life<ConwayCell> life(3, 3, board, pop);
	//	life.readGrid(in);
	life.step();
	life.print(out, true);
	ASSERT_EQ(s2, out.str());
	life.step();
	life.print(out2, true);
	ASSERT_EQ(s, out2.str());
}

TEST(Life, toad) {
	vector<vector<ConwayCell> > board;
	int pop = 0;
	//	Life<ConwayCell> life(4, 4);
	string s = "4 4";
	s += "....\n";
	s += ".***\n";
	s += "***.\n";
	s += "....\n";
	string s2 = "4 4";
	s2 += "..*.\n";
	s2 += "*..*\n";
	s2 += "*..*\n";
	s2 += ".*..\n";
	istringstream in(s);
	ostringstream out;
	ostringstream out2;
	readBoard(in, board, pop);
	Life<ConwayCell> life(4, 4, board, pop);
	//	life.readGrid(in);
	life.step();
	life.print(out, true);
	ASSERT_EQ(s2, out.str());
	life.step();
	life.print(out2, true);
	ASSERT_EQ(s, out2.str());
}

TEST(Life, beacon) {
	vector<vector<ConwayCell> > board;
	int pop = 0;
	//	Life<ConwayCell> life(4, 4);
	string s = "4 4";
	s += "**..\n";
	s += "**..\n";
	s += "..**\n";
	s += "..**\n";
	string s2 = "4 4";
	s2 += "**..\n";
	s2 += "*...\n";
	s2 += "...*\n";
	s2 += "..**\n";
	istringstream in(s);
	ostringstream out;
	ostringstream out2;
	readBoard(in, board, pop);
	Life<ConwayCell> life(4, 4, board, pop);
	//	life.readGrid(in);
	life.step();
	life.print(out, true);
	ASSERT_EQ(s2, out.str());
	life.step();
	life.print(out2, true);
	ASSERT_EQ(s, out2.str());
}

TEST(Life, step_unchanged_2) {
	vector<vector<ConwayCell> > board;
	int pop = 0;
	string s = "4 4....\n.**.\n.**.\n....\n";
	istringstream in(s);
	readBoard(in, board, pop);
	Life<ConwayCell> life(4, 4, board, pop);
	life.step();
	life.step();
	ostringstream out;
	life.print(out, true);
	ASSERT_EQ(s, out.str());
}

TEST(Life, step_die_2) {
	vector<vector<ConwayCell> > board;
	int pop = 0;
	//	Life<ConwayCell> life(4, 4);
	string s = "4 4....\n.**.\n....\n....\n";
	istringstream in(s);
	readBoard(in, board, pop);
	Life<ConwayCell> life(4, 4, board, pop);
	//	life.readGrid(in);
	life.step();
	life.step();
	ostringstream out;
	life.print(out, true);
	ASSERT_EQ("4 4....\n....\n....\n....\n", out.str());
}

TEST(Life, beehive_2) {
	vector<vector<ConwayCell> > board;
	int pop = 0;
	//	Life<ConwayCell> life(3, 4);
	string s = "3 4";
	s += ".**.\n";
	s += "*..*\n";
	s += ".**.\n";
	istringstream in(s);
	readBoard(in, board, pop);
	Life<ConwayCell> life(3, 4, board, pop);
	//	life.readGrid(in);
	life.step();
	life.step();
	life.step();
	life.step();
	ostringstream out;
	life.print(out, true);
	ASSERT_EQ(s, out.str());
}

TEST(Life, loaf_2) {
	vector<vector<ConwayCell> > board;
	int pop = 0;
	//	Life<ConwayCell> life(4, 4);
	string s = "4 4";
	s += ".**.\n";
	s += "*..*\n";
	s += ".*.*\n";
	s += "..*.\n";
	istringstream in(s);
	readBoard(in, board, pop);
	Life<ConwayCell> life(4, 4, board, pop);
	//	life.readGrid(in);
	life.step();
	life.step();
	life.step();
	life.step();
	ostringstream out;
	life.print(out, true);
	ASSERT_EQ(s, out.str());
}

TEST(Life, boat_2) {
	vector<vector<ConwayCell> > board;
	int pop = 0;
	//	Life<ConwayCell> life(3, 3);
	string s = "3 3";
	s += "**.\n";
	s += "*.*\n";
	s += ".*.\n";
	istringstream in(s);
	readBoard(in, board, pop);
	Life<ConwayCell> life(3, 3, board, pop);
	//	life.readGrid(in);
	life.step();
	life.step();
	life.step();
	life.step();
	ostringstream out;
	life.print(out, true);
	ASSERT_EQ(s, out.str());
}

TEST(Life, blinker_2) {
	vector<vector<ConwayCell> > board;
	int pop = 0;
	//	Life<ConwayCell> life(3, 3);
	string s = "3 3";
	s += ".*.\n";
	s += ".*.\n";
	s += ".*.\n";
	string s2 = "3 3";
	s2 += "...\n";
	s2 += "***\n";
	s2 += "...\n";
	istringstream in(s);
	ostringstream out;
	ostringstream out2;
	readBoard(in, board, pop);
	Life<ConwayCell> life(3, 3, board, pop);
	//	life.readGrid(in);
	life.step();
	life.step();
	life.step();
	life.print(out, true);
	ASSERT_EQ(s2, out.str());
	life.step();
	life.print(out2, true);
	ASSERT_EQ(s, out2.str());
}

TEST(Life, toad_2) {
	vector<vector<ConwayCell> > board;
	int pop = 0;
	//	Life<ConwayCell> life(4, 4);
	string s = "4 4";
	s += "....\n";
	s += ".***\n";
	s += "***.\n";
	s += "....\n";
	string s2 = "4 4";
	s2 += "..*.\n";
	s2 += "*..*\n";
	s2 += "*..*\n";
	s2 += ".*..\n";
	istringstream in(s);
	ostringstream out;
	ostringstream out2;
	readBoard(in, board, pop);
	Life<ConwayCell> life(4, 4, board, pop);
	//	life.readGrid(in);
	life.step();
	life.step();
	life.step();
	life.print(out, true);
	ASSERT_EQ(s2, out.str());
	life.step();
	life.print(out2, true);
	ASSERT_EQ(s, out2.str());
}

TEST(Life, beacon_2) {
	vector<vector<ConwayCell> > board;
	int pop = 0;
	//	Life<ConwayCell> life(4, 4);
	string s = "4 4";
	s += "**..\n";
	s += "**..\n";
	s += "..**\n";
	s += "..**\n";
	string s2 = "4 4";
	s2 += "**..\n";
	s2 += "*...\n";
	s2 += "...*\n";
	s2 += "..**\n";
	istringstream in(s);
	ostringstream out;
	ostringstream out2;
	readBoard(in, board, pop);
	Life<ConwayCell> life(4, 4, board, pop);
	//	life.readGrid(in);
	life.step();
	life.step();
	life.step();
	life.print(out, true);
	ASSERT_EQ(s2, out.str());
	life.step();
	life.print(out2, true);
	ASSERT_EQ(s, out2.str());
}

TEST(Life, step_unchanged_3) {
	vector<vector<ConwayCell> > board;
	int pop = 0;
	string s = "4 4....\n.**.\n.**.\n....\n";
	istringstream in(s);
	readBoard(in, board, pop);
	Life<ConwayCell> life(4, 4, board, pop);
	life.step();
	life.step();
	life.step();
	ostringstream out;
	life.print(out, true);
	ASSERT_EQ(s, out.str());
}

TEST(Life, step_die_3) {
	vector<vector<ConwayCell> > board;
	int pop = 0;
	//	Life<ConwayCell> life(4, 4);
	string s = "4 4....\n.**.\n....\n....\n";
	istringstream in(s);
	readBoard(in, board, pop);
	Life<ConwayCell> life(4, 4, board, pop);
	//	life.readGrid(in);
	life.step();
	life.step();
	life.step();
	ostringstream out;
	life.print(out, true);
	ASSERT_EQ("4 4....\n....\n....\n....\n", out.str());
}

TEST(Life, beehive_3) {
	vector<vector<ConwayCell> > board;
	int pop = 0;
	//	Life<ConwayCell> life(3, 4);
	string s = "3 4";
	s += ".**.\n";
	s += "*..*\n";
	s += ".**.\n";
	istringstream in(s);
	readBoard(in, board, pop);
	Life<ConwayCell> life(3, 4, board, pop);
	//	life.readGrid(in);
	life.step();
	life.step();
	life.step();
	life.step();
	life.step();
	ostringstream out;
	life.print(out, true);
	ASSERT_EQ(s, out.str());
}

TEST(Life, loaf_3) {
	vector<vector<ConwayCell> > board;
	int pop = 0;
	//	Life<ConwayCell> life(4, 4);
	string s = "4 4";
	s += ".**.\n";
	s += "*..*\n";
	s += ".*.*\n";
	s += "..*.\n";
	istringstream in(s);
	readBoard(in, board, pop);
	Life<ConwayCell> life(4, 4, board, pop);
	//	life.readGrid(in);
	life.step();
	life.step();
	life.step();
	life.step();
	life.step();
	ostringstream out;
	life.print(out, true);
	ASSERT_EQ(s, out.str());
}

TEST(Life, boat_3) {
	vector<vector<ConwayCell> > board;
	int pop = 0;
	//	Life<ConwayCell> life(3, 3);
	string s = "3 3";
	s += "**.\n";
	s += "*.*\n";
	s += ".*.\n";
	istringstream in(s);
	readBoard(in, board, pop);
	Life<ConwayCell> life(3, 3, board, pop);
	//	life.readGrid(in);
	life.step();
	life.step();
	life.step();
	life.step();
	life.step();
	ostringstream out;
	life.print(out, true);
	ASSERT_EQ(s, out.str());
}

TEST(Life, blinker_3) {
	vector<vector<ConwayCell> > board;
	int pop = 0;
	//	Life<ConwayCell> life(3, 3);
	string s = "3 3";
	s += ".*.\n";
	s += ".*.\n";
	s += ".*.\n";
	string s2 = "3 3";
	s2 += "...\n";
	s2 += "***\n";
	s2 += "...\n";
	istringstream in(s);
	ostringstream out;
	ostringstream out2;
	readBoard(in, board, pop);
	Life<ConwayCell> life(3, 3, board, pop);
	//	life.readGrid(in);
	life.step();
	life.step();
	life.step();
	life.step();
	life.step();
	life.print(out, true);
	ASSERT_EQ(s2, out.str());
	life.step();
	life.print(out2, true);
	ASSERT_EQ(s, out2.str());
}

TEST(Life, toad_3) {
	vector<vector<ConwayCell> > board;
	int pop = 0;
	//	Life<ConwayCell> life(4, 4);
	string s = "4 4";
	s += "....\n";
	s += ".***\n";
	s += "***.\n";
	s += "....\n";
	string s2 = "4 4";
	s2 += "..*.\n";
	s2 += "*..*\n";
	s2 += "*..*\n";
	s2 += ".*..\n";
	istringstream in(s);
	ostringstream out;
	ostringstream out2;
	readBoard(in, board, pop);
	Life<ConwayCell> life(4, 4, board, pop);
	//	life.readGrid(in);
	life.step();
	life.step();
	life.step();
	life.step();
	life.step();
	life.print(out, true);
	ASSERT_EQ(s2, out.str());
	life.step();
	life.print(out2, true);
	ASSERT_EQ(s, out2.str());
}

TEST(Life, beacon_3) {
	vector<vector<ConwayCell> > board;
	int pop = 0;
	//	Life<ConwayCell> life(4, 4);
	string s = "4 4";
	s += "**..\n";
	s += "**..\n";
	s += "..**\n";
	s += "..**\n";
	string s2 = "4 4";
	s2 += "**..\n";
	s2 += "*...\n";
	s2 += "...*\n";
	s2 += "..**\n";
	istringstream in(s);
	ostringstream out;
	ostringstream out2;
	readBoard(in, board, pop);
	Life<ConwayCell> life(4, 4, board, pop);
	//	life.readGrid(in);
	life.step();
	life.step();
	life.step();
	life.step();
	life.step();
	life.print(out, true);
	ASSERT_EQ(s2, out.str());
	life.step();
	life.print(out2, true);
	ASSERT_EQ(s, out2.str());
}

TEST(life_fredkin, moveAlong_0) {
	vector<vector<FredkinCell> > board;
	board.push_back(vector<FredkinCell>());
	string os1 = "1 200";
	string os2 = "1 200";
	const int rows = 200;
	const int before = 0;
	for (int i = 0; i < before; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i + 1 < before) {
			os2 += "-";
		} else {
			os2 += "0";
		}
	}
	board[0].push_back(FredkinCell());
	board[0][before].init('0');
	os1 += "0";
	os2 += "-";
	for (int i = before+1; i < rows; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i == (before + 1)) {
			os2 += "0";
		} else {
			os2 += "-";
		}
	}

	Life<FredkinCell> life(1, 200, board, 1);
	ostringstream out;
	ostringstream out2;
	life.print(out, true);
	ASSERT_EQ(os1 + "\n", out.str());
	life.step();
	life.print(out2, true);
	ASSERT_EQ(os2 + "\n", out2.str());
}

TEST(life_fredkin, moveAlong_1) {
	vector<vector<FredkinCell> > board;
	board.push_back(vector<FredkinCell>());
	string os1 = "1 200";
	string os2 = "1 200";
	const int rows = 200;
	const int before = 1;
	for (int i = 0; i < before; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i + 1 < before) {
			os2 += "-";
		} else {
			os2 += "0";
		}
	}
	board[0].push_back(FredkinCell());
	board[0][before].init('0');
	os1 += "0";
	os2 += "-";
	for (int i = before+1; i < rows; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i == (before + 1)) {
			os2 += "0";
		} else {
			os2 += "-";
		}
	}

	Life<FredkinCell> life(1, 200, board, 1);
	ostringstream out;
	ostringstream out2;
	life.print(out, true);
	ASSERT_EQ(os1 + "\n", out.str());
	life.step();
	life.print(out2, true);
	ASSERT_EQ(os2 + "\n", out2.str());
}

TEST(life_fredkin, moveAlong_2) {
	vector<vector<FredkinCell> > board;
	board.push_back(vector<FredkinCell>());
	string os1 = "1 200";
	string os2 = "1 200";
	const int rows = 200;
	const int before = 2;
	for (int i = 0; i < before; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i + 1 < before) {
			os2 += "-";
		} else {
			os2 += "0";
		}
	}
	board[0].push_back(FredkinCell());
	board[0][before].init('0');
	os1 += "0";
	os2 += "-";
	for (int i = before+1; i < rows; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i == (before + 1)) {
			os2 += "0";
		} else {
			os2 += "-";
		}
	}

	Life<FredkinCell> life(1, 200, board, 1);
	ostringstream out;
	ostringstream out2;
	life.print(out, true);
	ASSERT_EQ(os1 + "\n", out.str());
	life.step();
	life.print(out2, true);
	ASSERT_EQ(os2 + "\n", out2.str());
}

TEST(life_fredkin, moveAlong_3) {
	vector<vector<FredkinCell> > board;
	board.push_back(vector<FredkinCell>());
	string os1 = "1 200";
	string os2 = "1 200";
	const int rows = 200;
	const int before = 3;
	for (int i = 0; i < before; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i + 1 < before) {
			os2 += "-";
		} else {
			os2 += "0";
		}
	}
	board[0].push_back(FredkinCell());
	board[0][before].init('0');
	os1 += "0";
	os2 += "-";
	for (int i = before+1; i < rows; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i == (before + 1)) {
			os2 += "0";
		} else {
			os2 += "-";
		}
	}

	Life<FredkinCell> life(1, 200, board, 1);
	ostringstream out;
	ostringstream out2;
	life.print(out, true);
	ASSERT_EQ(os1 + "\n", out.str());
	life.step();
	life.print(out2, true);
	ASSERT_EQ(os2 + "\n", out2.str());
}

TEST(life_fredkin, moveAlong_4) {
	vector<vector<FredkinCell> > board;
	board.push_back(vector<FredkinCell>());
	string os1 = "1 200";
	string os2 = "1 200";
	const int rows = 200;
	const int before = 4;
	for (int i = 0; i < before; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i + 1 < before) {
			os2 += "-";
		} else {
			os2 += "0";
		}
	}
	board[0].push_back(FredkinCell());
	board[0][before].init('0');
	os1 += "0";
	os2 += "-";
	for (int i = before+1; i < rows; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i == (before + 1)) {
			os2 += "0";
		} else {
			os2 += "-";
		}
	}

	Life<FredkinCell> life(1, 200, board, 1);
	ostringstream out;
	ostringstream out2;
	life.print(out, true);
	ASSERT_EQ(os1 + "\n", out.str());
	life.step();
	life.print(out2, true);
	ASSERT_EQ(os2 + "\n", out2.str());
}
TEST(life_fredkin, moveAlong_5) {
	vector<vector<FredkinCell> > board;
	board.push_back(vector<FredkinCell>());
	string os1 = "1 200";
	string os2 = "1 200";
	const int rows = 200;
	const int before = 5;
	for (int i = 0; i < before; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i + 1 < before) {
			os2 += "-";
		} else {
			os2 += "0";
		}
	}
	board[0].push_back(FredkinCell());
	board[0][before].init('0');
	os1 += "0";
	os2 += "-";
	for (int i = before+1; i < rows; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i == (before + 1)) {
			os2 += "0";
		} else {
			os2 += "-";
		}
	}

	Life<FredkinCell> life(1, 200, board, 1);
	ostringstream out;
	ostringstream out2;
	life.print(out, true);
	ASSERT_EQ(os1 + "\n", out.str());
	life.step();
	life.print(out2, true);
	ASSERT_EQ(os2 + "\n", out2.str());
}

TEST(life_fredkin, moveAlong_6) {
	vector<vector<FredkinCell> > board;
	board.push_back(vector<FredkinCell>());
	string os1 = "1 200";
	string os2 = "1 200";
	const int rows = 200;
	const int before = 6;
	for (int i = 0; i < before; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i + 1 < before) {
			os2 += "-";
		} else {
			os2 += "0";
		}
	}
	board[0].push_back(FredkinCell());
	board[0][before].init('0');
	os1 += "0";
	os2 += "-";
	for (int i = before+1; i < rows; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i == (before + 1)) {
			os2 += "0";
		} else {
			os2 += "-";
		}
	}

	Life<FredkinCell> life(1, 200, board, 1);
	ostringstream out;
	ostringstream out2;
	life.print(out, true);
	ASSERT_EQ(os1 + "\n", out.str());
	life.step();
	life.print(out2, true);
	ASSERT_EQ(os2 + "\n", out2.str());
}

TEST(life_fredkin, moveAlong_7) {
	vector<vector<FredkinCell> > board;
	board.push_back(vector<FredkinCell>());
	string os1 = "1 200";
	string os2 = "1 200";
	const int rows = 200;
	const int before = 7;
	for (int i = 0; i < before; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i + 1 < before) {
			os2 += "-";
		} else {
			os2 += "0";
		}
	}
	board[0].push_back(FredkinCell());
	board[0][before].init('0');
	os1 += "0";
	os2 += "-";
	for (int i = before+1; i < rows; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i == (before + 1)) {
			os2 += "0";
		} else {
			os2 += "-";
		}
	}

	Life<FredkinCell> life(1, 200, board, 1);
	ostringstream out;
	ostringstream out2;
	life.print(out, true);
	ASSERT_EQ(os1 + "\n", out.str());
	life.step();
	life.print(out2, true);
	ASSERT_EQ(os2 + "\n", out2.str());
}
TEST(life_fredkin, moveAlong_8) {
	vector<vector<FredkinCell> > board;
	board.push_back(vector<FredkinCell>());
	string os1 = "1 200";
	string os2 = "1 200";
	const int rows = 200;
	const int before = 8;
	for (int i = 0; i < before; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i + 1 < before) {
			os2 += "-";
		} else {
			os2 += "0";
		}
	}
	board[0].push_back(FredkinCell());
	board[0][before].init('0');
	os1 += "0";
	os2 += "-";
	for (int i = before+1; i < rows; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i == (before + 1)) {
			os2 += "0";
		} else {
			os2 += "-";
		}
	}

	Life<FredkinCell> life(1, 200, board, 1);
	ostringstream out;
	ostringstream out2;
	life.print(out, true);
	ASSERT_EQ(os1 + "\n", out.str());
	life.step();
	life.print(out2, true);
	ASSERT_EQ(os2 + "\n", out2.str());
}
TEST(life_fredkin, moveAlong_9) {
	vector<vector<FredkinCell> > board;
	board.push_back(vector<FredkinCell>());
	string os1 = "1 200";
	string os2 = "1 200";
	const int rows = 200;
	const int before = 9;
	for (int i = 0; i < before; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i + 1 < before) {
			os2 += "-";
		} else {
			os2 += "0";
		}
	}
	board[0].push_back(FredkinCell());
	board[0][before].init('0');
	os1 += "0";
	os2 += "-";
	for (int i = before+1; i < rows; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i == (before + 1)) {
			os2 += "0";
		} else {
			os2 += "-";
		}
	}

	Life<FredkinCell> life(1, 200, board, 1);
	ostringstream out;
	ostringstream out2;
	life.print(out, true);
	ASSERT_EQ(os1 + "\n", out.str());
	life.step();
	life.print(out2, true);
	ASSERT_EQ(os2 + "\n", out2.str());
}
TEST(life_fredkin, moveAlong_10) {
	vector<vector<FredkinCell> > board;
	board.push_back(vector<FredkinCell>());
	string os1 = "1 200";
	string os2 = "1 200";
	const int rows = 200;
	const int before = 10;
	for (int i = 0; i < before; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i + 1 < before) {
			os2 += "-";
		} else {
			os2 += "0";
		}
	}
	board[0].push_back(FredkinCell());
	board[0][before].init('0');
	os1 += "0";
	os2 += "-";
	for (int i = before+1; i < rows; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i == (before + 1)) {
			os2 += "0";
		} else {
			os2 += "-";
		}
	}

	Life<FredkinCell> life(1, 200, board, 1);
	ostringstream out;
	ostringstream out2;
	life.print(out, true);
	ASSERT_EQ(os1 + "\n", out.str());
	life.step();
	life.print(out2, true);
	ASSERT_EQ(os2 + "\n", out2.str());
}
TEST(life_fredkin, moveAlong_11) {
	vector<vector<FredkinCell> > board;
	board.push_back(vector<FredkinCell>());
	string os1 = "1 200";
	string os2 = "1 200";
	const int rows = 200;
	const int before = 11;
	for (int i = 0; i < before; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i + 1 < before) {
			os2 += "-";
		} else {
			os2 += "0";
		}
	}
	board[0].push_back(FredkinCell());
	board[0][before].init('0');
	os1 += "0";
	os2 += "-";
	for (int i = before+1; i < rows; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i == (before + 1)) {
			os2 += "0";
		} else {
			os2 += "-";
		}
	}

	Life<FredkinCell> life(1, 200, board, 1);
	ostringstream out;
	ostringstream out2;
	life.print(out, true);
	ASSERT_EQ(os1 + "\n", out.str());
	life.step();
	life.print(out2, true);
	ASSERT_EQ(os2 + "\n", out2.str());
}
TEST(life_fredkin, moveAlong_12) {
	vector<vector<FredkinCell> > board;
	board.push_back(vector<FredkinCell>());
	string os1 = "1 200";
	string os2 = "1 200";
	const int rows = 200;
	const int before = 12;
	for (int i = 0; i < before; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i + 1 < before) {
			os2 += "-";
		} else {
			os2 += "0";
		}
	}
	board[0].push_back(FredkinCell());
	board[0][before].init('0');
	os1 += "0";
	os2 += "-";
	for (int i = before+1; i < rows; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i == (before + 1)) {
			os2 += "0";
		} else {
			os2 += "-";
		}
	}

	Life<FredkinCell> life(1, 200, board, 1);
	ostringstream out;
	ostringstream out2;
	life.print(out, true);
	ASSERT_EQ(os1 + "\n", out.str());
	life.step();
	life.print(out2, true);
	ASSERT_EQ(os2 + "\n", out2.str());
}
TEST(life_fredkin, moveAlong_13) {
	vector<vector<FredkinCell> > board;
	board.push_back(vector<FredkinCell>());
	string os1 = "1 200";
	string os2 = "1 200";
	const int rows = 200;
	const int before = 13;
	for (int i = 0; i < before; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i + 1 < before) {
			os2 += "-";
		} else {
			os2 += "0";
		}
	}
	board[0].push_back(FredkinCell());
	board[0][before].init('0');
	os1 += "0";
	os2 += "-";
	for (int i = before+1; i < rows; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i == (before + 1)) {
			os2 += "0";
		} else {
			os2 += "-";
		}
	}

	Life<FredkinCell> life(1, 200, board, 1);
	ostringstream out;
	ostringstream out2;
	life.print(out, true);
	ASSERT_EQ(os1 + "\n", out.str());
	life.step();
	life.print(out2, true);
	ASSERT_EQ(os2 + "\n", out2.str());
}
TEST(life_fredkin, moveAlong_14) {
	vector<vector<FredkinCell> > board;
	board.push_back(vector<FredkinCell>());
	string os1 = "1 200";
	string os2 = "1 200";
	const int rows = 200;
	const int before = 14;
	for (int i = 0; i < before; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i + 1 < before) {
			os2 += "-";
		} else {
			os2 += "0";
		}
	}
	board[0].push_back(FredkinCell());
	board[0][before].init('0');
	os1 += "0";
	os2 += "-";
	for (int i = before+1; i < rows; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i == (before + 1)) {
			os2 += "0";
		} else {
			os2 += "-";
		}
	}

	Life<FredkinCell> life(1, 200, board, 1);
	ostringstream out;
	ostringstream out2;
	life.print(out, true);
	ASSERT_EQ(os1 + "\n", out.str());
	life.step();
	life.print(out2, true);
	ASSERT_EQ(os2 + "\n", out2.str());
}
TEST(life_fredkin, moveAlong_15) {
	vector<vector<FredkinCell> > board;
	board.push_back(vector<FredkinCell>());
	string os1 = "1 200";
	string os2 = "1 200";
	const int rows = 200;
	const int before = 15;
	for (int i = 0; i < before; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i + 1 < before) {
			os2 += "-";
		} else {
			os2 += "0";
		}
	}
	board[0].push_back(FredkinCell());
	board[0][before].init('0');
	os1 += "0";
	os2 += "-";
	for (int i = before+1; i < rows; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i == (before + 1)) {
			os2 += "0";
		} else {
			os2 += "-";
		}
	}

	Life<FredkinCell> life(1, 200, board, 1);
	ostringstream out;
	ostringstream out2;
	life.print(out, true);
	ASSERT_EQ(os1 + "\n", out.str());
	life.step();
	life.print(out2, true);
	ASSERT_EQ(os2 + "\n", out2.str());
}
TEST(life_fredkin, moveAlong_16) {
	vector<vector<FredkinCell> > board;
	board.push_back(vector<FredkinCell>());
	string os1 = "1 200";
	string os2 = "1 200";
	const int rows = 200;
	const int before = 16;
	for (int i = 0; i < before; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i + 1 < before) {
			os2 += "-";
		} else {
			os2 += "0";
		}
	}
	board[0].push_back(FredkinCell());
	board[0][before].init('0');
	os1 += "0";
	os2 += "-";
	for (int i = before+1; i < rows; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i == (before + 1)) {
			os2 += "0";
		} else {
			os2 += "-";
		}
	}

	Life<FredkinCell> life(1, 200, board, 1);
	ostringstream out;
	ostringstream out2;
	life.print(out, true);
	ASSERT_EQ(os1 + "\n", out.str());
	life.step();
	life.print(out2, true);
	ASSERT_EQ(os2 + "\n", out2.str());
}
TEST(life_fredkin, moveAlong_17) {
	vector<vector<FredkinCell> > board;
	board.push_back(vector<FredkinCell>());
	string os1 = "1 200";
	string os2 = "1 200";
	const int rows = 200;
	const int before = 17;
	for (int i = 0; i < before; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i + 1 < before) {
			os2 += "-";
		} else {
			os2 += "0";
		}
	}
	board[0].push_back(FredkinCell());
	board[0][before].init('0');
	os1 += "0";
	os2 += "-";
	for (int i = before+1; i < rows; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i == (before + 1)) {
			os2 += "0";
		} else {
			os2 += "-";
		}
	}

	Life<FredkinCell> life(1, 200, board, 1);
	ostringstream out;
	ostringstream out2;
	life.print(out, true);
	ASSERT_EQ(os1 + "\n", out.str());
	life.step();
	life.print(out2, true);
	ASSERT_EQ(os2 + "\n", out2.str());
}
TEST(life_fredkin, moveAlong_18) {
	vector<vector<FredkinCell> > board;
	board.push_back(vector<FredkinCell>());
	string os1 = "1 200";
	string os2 = "1 200";
	const int rows = 200;
	const int before = 18;
	for (int i = 0; i < before; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i + 1 < before) {
			os2 += "-";
		} else {
			os2 += "0";
		}
	}
	board[0].push_back(FredkinCell());
	board[0][before].init('0');
	os1 += "0";
	os2 += "-";
	for (int i = before+1; i < rows; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i == (before + 1)) {
			os2 += "0";
		} else {
			os2 += "-";
		}
	}

	Life<FredkinCell> life(1, 200, board, 1);
	ostringstream out;
	ostringstream out2;
	life.print(out, true);
	ASSERT_EQ(os1 + "\n", out.str());
	life.step();
	life.print(out2, true);
	ASSERT_EQ(os2 + "\n", out2.str());
}
TEST(life_fredkin, moveAlong_19) {
	vector<vector<FredkinCell> > board;
	board.push_back(vector<FredkinCell>());
	string os1 = "1 200";
	string os2 = "1 200";
	const int rows = 200;
	const int before = 19;
	for (int i = 0; i < before; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i + 1 < before) {
			os2 += "-";
		} else {
			os2 += "0";
		}
	}
	board[0].push_back(FredkinCell());
	board[0][before].init('0');
	os1 += "0";
	os2 += "-";
	for (int i = before+1; i < rows; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i == (before + 1)) {
			os2 += "0";
		} else {
			os2 += "-";
		}
	}

	Life<FredkinCell> life(1, 200, board, 1);
	ostringstream out;
	ostringstream out2;
	life.print(out, true);
	ASSERT_EQ(os1 + "\n", out.str());
	life.step();
	life.print(out2, true);
	ASSERT_EQ(os2 + "\n", out2.str());
}
TEST(life_fredkin, moveAlong_20) {
	vector<vector<FredkinCell> > board;
	board.push_back(vector<FredkinCell>());
	string os1 = "1 200";
	string os2 = "1 200";
	const int rows = 200;
	const int before = 20;
	for (int i = 0; i < before; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i + 1 < before) {
			os2 += "-";
		} else {
			os2 += "0";
		}
	}
	board[0].push_back(FredkinCell());
	board[0][before].init('0');
	os1 += "0";
	os2 += "-";
	for (int i = before+1; i < rows; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i == (before + 1)) {
			os2 += "0";
		} else {
			os2 += "-";
		}
	}

	Life<FredkinCell> life(1, 200, board, 1);
	ostringstream out;
	ostringstream out2;
	life.print(out, true);
	ASSERT_EQ(os1 + "\n", out.str());
	life.step();
	life.print(out2, true);
	ASSERT_EQ(os2 + "\n", out2.str());
}
TEST(life_fredkin, moveAlong_21) {
	vector<vector<FredkinCell> > board;
	board.push_back(vector<FredkinCell>());
	string os1 = "1 200";
	string os2 = "1 200";
	const int rows = 200;
	const int before = 21;
	for (int i = 0; i < before; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i + 1 < before) {
			os2 += "-";
		} else {
			os2 += "0";
		}
	}
	board[0].push_back(FredkinCell());
	board[0][before].init('0');
	os1 += "0";
	os2 += "-";
	for (int i = before+1; i < rows; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i == (before + 1)) {
			os2 += "0";
		} else {
			os2 += "-";
		}
	}

	Life<FredkinCell> life(1, 200, board, 1);
	ostringstream out;
	ostringstream out2;
	life.print(out, true);
	ASSERT_EQ(os1 + "\n", out.str());
	life.step();
	life.print(out2, true);
	ASSERT_EQ(os2 + "\n", out2.str());
}
TEST(life_fredkin, moveAlong_22) {
	vector<vector<FredkinCell> > board;
	board.push_back(vector<FredkinCell>());
	string os1 = "1 200";
	string os2 = "1 200";
	const int rows = 200;
	const int before = 22;
	for (int i = 0; i < before; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i + 1 < before) {
			os2 += "-";
		} else {
			os2 += "0";
		}
	}
	board[0].push_back(FredkinCell());
	board[0][before].init('0');
	os1 += "0";
	os2 += "-";
	for (int i = before+1; i < rows; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i == (before + 1)) {
			os2 += "0";
		} else {
			os2 += "-";
		}
	}

	Life<FredkinCell> life(1, 200, board, 1);
	ostringstream out;
	ostringstream out2;
	life.print(out, true);
	ASSERT_EQ(os1 + "\n", out.str());
	life.step();
	life.print(out2, true);
	ASSERT_EQ(os2 + "\n", out2.str());
}
TEST(life_fredkin, moveAlong_23) {
	vector<vector<FredkinCell> > board;
	board.push_back(vector<FredkinCell>());
	string os1 = "1 200";
	string os2 = "1 200";
	const int rows = 200;
	const int before = 23;
	for (int i = 0; i < before; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i + 1 < before) {
			os2 += "-";
		} else {
			os2 += "0";
		}
	}
	board[0].push_back(FredkinCell());
	board[0][before].init('0');
	os1 += "0";
	os2 += "-";
	for (int i = before+1; i < rows; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i == (before + 1)) {
			os2 += "0";
		} else {
			os2 += "-";
		}
	}

	Life<FredkinCell> life(1, 200, board, 1);
	ostringstream out;
	ostringstream out2;
	life.print(out, true);
	ASSERT_EQ(os1 + "\n", out.str());
	life.step();
	life.print(out2, true);
	ASSERT_EQ(os2 + "\n", out2.str());
}
TEST(life_fredkin, moveAlong_24) {
	vector<vector<FredkinCell> > board;
	board.push_back(vector<FredkinCell>());
	string os1 = "1 200";
	string os2 = "1 200";
	const int rows = 200;
	const int before = 24;
	for (int i = 0; i < before; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i + 1 < before) {
			os2 += "-";
		} else {
			os2 += "0";
		}
	}
	board[0].push_back(FredkinCell());
	board[0][before].init('0');
	os1 += "0";
	os2 += "-";
	for (int i = before+1; i < rows; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i == (before + 1)) {
			os2 += "0";
		} else {
			os2 += "-";
		}
	}

	Life<FredkinCell> life(1, 200, board, 1);
	ostringstream out;
	ostringstream out2;
	life.print(out, true);
	ASSERT_EQ(os1 + "\n", out.str());
	life.step();
	life.print(out2, true);
	ASSERT_EQ(os2 + "\n", out2.str());
}
TEST(life_fredkin, moveAlong_25) {
	vector<vector<FredkinCell> > board;
	board.push_back(vector<FredkinCell>());
	string os1 = "1 200";
	string os2 = "1 200";
	const int rows = 200;
	const int before = 25;
	for (int i = 0; i < before; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i + 1 < before) {
			os2 += "-";
		} else {
			os2 += "0";
		}
	}
	board[0].push_back(FredkinCell());
	board[0][before].init('0');
	os1 += "0";
	os2 += "-";
	for (int i = before+1; i < rows; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i == (before + 1)) {
			os2 += "0";
		} else {
			os2 += "-";
		}
	}

	Life<FredkinCell> life(1, 200, board, 1);
	ostringstream out;
	ostringstream out2;
	life.print(out, true);
	ASSERT_EQ(os1 + "\n", out.str());
	life.step();
	life.print(out2, true);
	ASSERT_EQ(os2 + "\n", out2.str());
}
TEST(life_fredkin, moveAlong_26) {
	vector<vector<FredkinCell> > board;
	board.push_back(vector<FredkinCell>());
	string os1 = "1 200";
	string os2 = "1 200";
	const int rows = 200;
	const int before = 26;
	for (int i = 0; i < before; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i + 1 < before) {
			os2 += "-";
		} else {
			os2 += "0";
		}
	}
	board[0].push_back(FredkinCell());
	board[0][before].init('0');
	os1 += "0";
	os2 += "-";
	for (int i = before+1; i < rows; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i == (before + 1)) {
			os2 += "0";
		} else {
			os2 += "-";
		}
	}

	Life<FredkinCell> life(1, 200, board, 1);
	ostringstream out;
	ostringstream out2;
	life.print(out, true);
	ASSERT_EQ(os1 + "\n", out.str());
	life.step();
	life.print(out2, true);
	ASSERT_EQ(os2 + "\n", out2.str());
}
TEST(life_fredkin, moveAlong_27) {
	vector<vector<FredkinCell> > board;
	board.push_back(vector<FredkinCell>());
	string os1 = "1 200";
	string os2 = "1 200";
	const int rows = 200;
	const int before = 27;
	for (int i = 0; i < before; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i + 1 < before) {
			os2 += "-";
		} else {
			os2 += "0";
		}
	}
	board[0].push_back(FredkinCell());
	board[0][before].init('0');
	os1 += "0";
	os2 += "-";
	for (int i = before+1; i < rows; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i == (before + 1)) {
			os2 += "0";
		} else {
			os2 += "-";
		}
	}

	Life<FredkinCell> life(1, 200, board, 1);
	ostringstream out;
	ostringstream out2;
	life.print(out, true);
	ASSERT_EQ(os1 + "\n", out.str());
	life.step();
	life.print(out2, true);
	ASSERT_EQ(os2 + "\n", out2.str());
}
TEST(life_fredkin, moveAlong_28) {
	vector<vector<FredkinCell> > board;
	board.push_back(vector<FredkinCell>());
	string os1 = "1 200";
	string os2 = "1 200";
	const int rows = 200;
	const int before = 28;
	for (int i = 0; i < before; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i + 1 < before) {
			os2 += "-";
		} else {
			os2 += "0";
		}
	}
	board[0].push_back(FredkinCell());
	board[0][before].init('0');
	os1 += "0";
	os2 += "-";
	for (int i = before+1; i < rows; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i == (before + 1)) {
			os2 += "0";
		} else {
			os2 += "-";
		}
	}

	Life<FredkinCell> life(1, 200, board, 1);
	ostringstream out;
	ostringstream out2;
	life.print(out, true);
	ASSERT_EQ(os1 + "\n", out.str());
	life.step();
	life.print(out2, true);
	ASSERT_EQ(os2 + "\n", out2.str());
}

TEST(life_fredkin, moveAlong_29) {
	vector<vector<FredkinCell> > board;
	board.push_back(vector<FredkinCell>());
	string os1 = "1 200";
	string os2 = "1 200";
	const int rows = 200;
	const int before = 29;
	for (int i = 0; i < before; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i + 1 < before) {
			os2 += "-";
		} else {
			os2 += "0";
		}
	}
	board[0].push_back(FredkinCell());
	board[0][before].init('0');
	os1 += "0";
	os2 += "-";
	for (int i = before+1; i < rows; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i == (before + 1)) {
			os2 += "0";
		} else {
			os2 += "-";
		}
	}

	Life<FredkinCell> life(1, 200, board, 1);
	ostringstream out;
	ostringstream out2;
	life.print(out, true);
	ASSERT_EQ(os1 + "\n", out.str());
	life.step();
	life.print(out2, true);
	ASSERT_EQ(os2 + "\n", out2.str());
}

TEST(life_fredkin, moveAlong_30) {
	vector<vector<FredkinCell> > board;
	board.push_back(vector<FredkinCell>());
	string os1 = "1 200";
	string os2 = "1 200";
	const int rows = 200;
	const int before = 30;
	for (int i = 0; i < before; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i + 1 < before) {
			os2 += "-";
		} else {
			os2 += "0";
		}
	}
	board[0].push_back(FredkinCell());
	board[0][before].init('0');
	os1 += "0";
	os2 += "-";
	for (int i = before+1; i < rows; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i == (before + 1)) {
			os2 += "0";
		} else {
			os2 += "-";
		}
	}

	Life<FredkinCell> life(1, 200, board, 1);
	ostringstream out;
	ostringstream out2;
	life.print(out, true);
	ASSERT_EQ(os1 + "\n", out.str());
	life.step();
	life.print(out2, true);
	ASSERT_EQ(os2 + "\n", out2.str());
}

TEST(life_fredkin, moveAlong_31) {
	vector<vector<FredkinCell> > board;
	board.push_back(vector<FredkinCell>());
	string os1 = "1 200";
	string os2 = "1 200";
	const int rows = 200;
	const int before = 31;
	for (int i = 0; i < before; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i + 1 < before) {
			os2 += "-";
		} else {
			os2 += "0";
		}
	}
	board[0].push_back(FredkinCell());
	board[0][before].init('0');
	os1 += "0";
	os2 += "-";
	for (int i = before+1; i < rows; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i == (before + 1)) {
			os2 += "0";
		} else {
			os2 += "-";
		}
	}

	Life<FredkinCell> life(1, 200, board, 1);
	ostringstream out;
	ostringstream out2;
	life.print(out, true);
	ASSERT_EQ(os1 + "\n", out.str());
	life.step();
	life.print(out2, true);
	ASSERT_EQ(os2 + "\n", out2.str());
}

TEST(life_fredkin, moveAlong_32) {
	vector<vector<FredkinCell> > board;
	board.push_back(vector<FredkinCell>());
	string os1 = "1 200";
	string os2 = "1 200";
	const int rows = 200;
	const int before = 32;
	for (int i = 0; i < before; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i + 1 < before) {
			os2 += "-";
		} else {
			os2 += "0";
		}
	}
	board[0].push_back(FredkinCell());
	board[0][before].init('0');
	os1 += "0";
	os2 += "-";
	for (int i = before+1; i < rows; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i == (before + 1)) {
			os2 += "0";
		} else {
			os2 += "-";
		}
	}

	Life<FredkinCell> life(1, 200, board, 1);
	ostringstream out;
	ostringstream out2;
	life.print(out, true);
	ASSERT_EQ(os1 + "\n", out.str());
	life.step();
	life.print(out2, true);
	ASSERT_EQ(os2 + "\n", out2.str());
}
TEST(life_fredkin, moveAlong_33) {
	vector<vector<FredkinCell> > board;
	board.push_back(vector<FredkinCell>());
	string os1 = "1 200";
	string os2 = "1 200";
	const int rows = 200;
	const int before = 33;
	for (int i = 0; i < before; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i + 1 < before) {
			os2 += "-";
		} else {
			os2 += "0";
		}
	}
	board[0].push_back(FredkinCell());
	board[0][before].init('0');
	os1 += "0";
	os2 += "-";
	for (int i = before+1; i < rows; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i == (before + 1)) {
			os2 += "0";
		} else {
			os2 += "-";
		}
	}

	Life<FredkinCell> life(1, 200, board, 1);
	ostringstream out;
	ostringstream out2;
	life.print(out, true);
	ASSERT_EQ(os1 + "\n", out.str());
	life.step();
	life.print(out2, true);
	ASSERT_EQ(os2 + "\n", out2.str());
}
TEST(life_fredkin, moveAlong_34) {
	vector<vector<FredkinCell> > board;
	board.push_back(vector<FredkinCell>());
	string os1 = "1 200";
	string os2 = "1 200";
	const int rows = 200;
	const int before = 34;
	for (int i = 0; i < before; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i + 1 < before) {
			os2 += "-";
		} else {
			os2 += "0";
		}
	}
	board[0].push_back(FredkinCell());
	board[0][before].init('0');
	os1 += "0";
	os2 += "-";
	for (int i = before+1; i < rows; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i == (before + 1)) {
			os2 += "0";
		} else {
			os2 += "-";
		}
	}

	Life<FredkinCell> life(1, 200, board, 1);
	ostringstream out;
	ostringstream out2;
	life.print(out, true);
	ASSERT_EQ(os1 + "\n", out.str());
	life.step();
	life.print(out2, true);
	ASSERT_EQ(os2 + "\n", out2.str());
}
TEST(life_fredkin, moveAlong_35) {
	vector<vector<FredkinCell> > board;
	board.push_back(vector<FredkinCell>());
	string os1 = "1 200";
	string os2 = "1 200";
	const int rows = 200;
	const int before = 35;
	for (int i = 0; i < before; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i + 1 < before) {
			os2 += "-";
		} else {
			os2 += "0";
		}
	}
	board[0].push_back(FredkinCell());
	board[0][before].init('0');
	os1 += "0";
	os2 += "-";
	for (int i = before+1; i < rows; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i == (before + 1)) {
			os2 += "0";
		} else {
			os2 += "-";
		}
	}

	Life<FredkinCell> life(1, 200, board, 1);
	ostringstream out;
	ostringstream out2;
	life.print(out, true);
	ASSERT_EQ(os1 + "\n", out.str());
	life.step();
	life.print(out2, true);
	ASSERT_EQ(os2 + "\n", out2.str());
}
TEST(life_fredkin, moveAlong_36) {
	vector<vector<FredkinCell> > board;
	board.push_back(vector<FredkinCell>());
	string os1 = "1 200";
	string os2 = "1 200";
	const int rows = 200;
	const int before = 36;
	for (int i = 0; i < before; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i + 1 < before) {
			os2 += "-";
		} else {
			os2 += "0";
		}
	}
	board[0].push_back(FredkinCell());
	board[0][before].init('0');
	os1 += "0";
	os2 += "-";
	for (int i = before+1; i < rows; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i == (before + 1)) {
			os2 += "0";
		} else {
			os2 += "-";
		}
	}

	Life<FredkinCell> life(1, 200, board, 1);
	ostringstream out;
	ostringstream out2;
	life.print(out, true);
	ASSERT_EQ(os1 + "\n", out.str());
	life.step();
	life.print(out2, true);
	ASSERT_EQ(os2 + "\n", out2.str());
}
TEST(life_fredkin, moveAlong_37) {
	vector<vector<FredkinCell> > board;
	board.push_back(vector<FredkinCell>());
	string os1 = "1 200";
	string os2 = "1 200";
	const int rows = 200;
	const int before = 37;
	for (int i = 0; i < before; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i + 1 < before) {
			os2 += "-";
		} else {
			os2 += "0";
		}
	}
	board[0].push_back(FredkinCell());
	board[0][before].init('0');
	os1 += "0";
	os2 += "-";
	for (int i = before+1; i < rows; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i == (before + 1)) {
			os2 += "0";
		} else {
			os2 += "-";
		}
	}

	Life<FredkinCell> life(1, 200, board, 1);
	ostringstream out;
	ostringstream out2;
	life.print(out, true);
	ASSERT_EQ(os1 + "\n", out.str());
	life.step();
	life.print(out2, true);
	ASSERT_EQ(os2 + "\n", out2.str());
}
TEST(life_fredkin, moveAlong_38) {
	vector<vector<FredkinCell> > board;
	board.push_back(vector<FredkinCell>());
	string os1 = "1 200";
	string os2 = "1 200";
	const int rows = 200;
	const int before = 38;
	for (int i = 0; i < before; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i + 1 < before) {
			os2 += "-";
		} else {
			os2 += "0";
		}
	}
	board[0].push_back(FredkinCell());
	board[0][before].init('0');
	os1 += "0";
	os2 += "-";
	for (int i = before+1; i < rows; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i == (before + 1)) {
			os2 += "0";
		} else {
			os2 += "-";
		}
	}

	Life<FredkinCell> life(1, 200, board, 1);
	ostringstream out;
	ostringstream out2;
	life.print(out, true);
	ASSERT_EQ(os1 + "\n", out.str());
	life.step();
	life.print(out2, true);
	ASSERT_EQ(os2 + "\n", out2.str());
}
TEST(life_fredkin, moveAlong_39) {
	vector<vector<FredkinCell> > board;
	board.push_back(vector<FredkinCell>());
	string os1 = "1 200";
	string os2 = "1 200";
	const int rows = 200;
	const int before = 39;
	for (int i = 0; i < before; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i + 1 < before) {
			os2 += "-";
		} else {
			os2 += "0";
		}
	}
	board[0].push_back(FredkinCell());
	board[0][before].init('0');
	os1 += "0";
	os2 += "-";
	for (int i = before+1; i < rows; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i == (before + 1)) {
			os2 += "0";
		} else {
			os2 += "-";
		}
	}

	Life<FredkinCell> life(1, 200, board, 1);
	ostringstream out;
	ostringstream out2;
	life.print(out, true);
	ASSERT_EQ(os1 + "\n", out.str());
	life.step();
	life.print(out2, true);
	ASSERT_EQ(os2 + "\n", out2.str());
}
TEST(life_fredkin, moveAlong_40) {
	vector<vector<FredkinCell> > board;
	board.push_back(vector<FredkinCell>());
	string os1 = "1 200";
	string os2 = "1 200";
	const int rows = 200;
	const int before = 40;
	for (int i = 0; i < before; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i + 1 < before) {
			os2 += "-";
		} else {
			os2 += "0";
		}
	}
	board[0].push_back(FredkinCell());
	board[0][before].init('0');
	os1 += "0";
	os2 += "-";
	for (int i = before+1; i < rows; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i == (before + 1)) {
			os2 += "0";
		} else {
			os2 += "-";
		}
	}

	Life<FredkinCell> life(1, 200, board, 1);
	ostringstream out;
	ostringstream out2;
	life.print(out, true);
	ASSERT_EQ(os1 + "\n", out.str());
	life.step();
	life.print(out2, true);
	ASSERT_EQ(os2 + "\n", out2.str());
}
TEST(life_fredkin, moveAlong_41) {
	vector<vector<FredkinCell> > board;
	board.push_back(vector<FredkinCell>());
	string os1 = "1 200";
	string os2 = "1 200";
	const int rows = 200;
	const int before = 41;
	for (int i = 0; i < before; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i + 1 < before) {
			os2 += "-";
		} else {
			os2 += "0";
		}
	}
	board[0].push_back(FredkinCell());
	board[0][before].init('0');
	os1 += "0";
	os2 += "-";
	for (int i = before+1; i < rows; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i == (before + 1)) {
			os2 += "0";
		} else {
			os2 += "-";
		}
	}

	Life<FredkinCell> life(1, 200, board, 1);
	ostringstream out;
	ostringstream out2;
	life.print(out, true);
	ASSERT_EQ(os1 + "\n", out.str());
	life.step();
	life.print(out2, true);
	ASSERT_EQ(os2 + "\n", out2.str());
}
TEST(life_fredkin, moveAlong_42) {
	vector<vector<FredkinCell> > board;
	board.push_back(vector<FredkinCell>());
	string os1 = "1 200";
	string os2 = "1 200";
	const int rows = 200;
	const int before = 42;
	for (int i = 0; i < before; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i + 1 < before) {
			os2 += "-";
		} else {
			os2 += "0";
		}
	}
	board[0].push_back(FredkinCell());
	board[0][before].init('0');
	os1 += "0";
	os2 += "-";
	for (int i = before+1; i < rows; ++i) {
		board[0].push_back(FredkinCell());
		board[0][i].init('-');
		os1 += "-";
		if (i == (before + 1)) {
			os2 += "0";
		} else {
			os2 += "-";
		}
	}

	Life<FredkinCell> life(1, 200, board, 1);
	ostringstream out;
	ostringstream out2;
	life.print(out, true);
	ASSERT_EQ(os1 + "\n", out.str());
	life.step();
	life.print(out2, true);
	ASSERT_EQ(os2 + "\n", out2.str());
}

