
#define private public
#define protected public

#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>   // rand, srand
#include "gtest/gtest.h"
#include "Life.h"



//---------------
// Conway Cells
//---------------

//tests to make : 12
//tests made : 48

TEST(Life, createBoard1) {
    Life<ConwayCell> board(10,10);
    ASSERT_TRUE(board._w == 10);
    ASSERT_TRUE(board._h == 10);
}
TEST(Life, createBoard2) {
    Life<ConwayCell> board(120,10);
    ASSERT_TRUE(board._w == 120);
    ASSERT_TRUE(board._h == 10);

}
TEST(Life, createBoard3) {
    Life<ConwayCell> board(1,1);
    ASSERT_TRUE(board._w == 1);
    ASSERT_TRUE(board._h == 1);

}
TEST(Life, createBoard4) {
    Life<FredkinCell> board(12,12);
    ASSERT_TRUE(board._w == 12);
    ASSERT_TRUE(board._h == 12);

}
TEST(Life, createBoard5) {
    Life<FredkinCell> board(10,300);
    ASSERT_TRUE(board._w == 10);
    ASSERT_TRUE(board._h == 300);

}
TEST(Life, createBoard6) {
    Life<FredkinCell> board(10,10);
    ASSERT_FALSE(board._w == 1);
    ASSERT_FALSE(board._h == 1);

}
TEST(Life, createBoard7) {
    Life<Cell> board(15,41);
    ASSERT_FALSE(board._w == 10);
    ASSERT_FALSE(board._h == 10);

}
TEST(Life, createBoard8) {
    Life<Cell> board(30,45);
    ASSERT_TRUE(board._w == 30);
    ASSERT_FALSE(board._h == 10);
}
TEST(Life, createBoard9) {
    Life<Cell> board(30, 1);
    ASSERT_TRUE(board._w == 30);
    ASSERT_TRUE(board._h == 1);

}

TEST(Life, Generate_cell1) {
    Life<ConwayCell> board(30, 20);
    ASSERT_TRUE(board._gen == 0);
    board.generate();
    ASSERT_TRUE(board._gen == 1);

}

TEST(Life, Generate_cell2) {
    Life<ConwayCell> board(30, 20);
    ASSERT_TRUE(board._gen == 0);
    for(int i = 0 ; i< 8;i++)
    {
        board.generate();
    }

    ASSERT_TRUE(board._gen == 8);
    ASSERT_FALSE(board._gen == 9);


}
TEST(Life, Generate_cell3) {
    Life<ConwayCell> board(30, 20);
    for(int i = 0 ; i< 20 ; i++)
    {
        board.generate();
    }
    ASSERT_TRUE(board._gen == 20);
    ASSERT_FALSE(board._gen == 0);

}

TEST(Life, Generate_cell4) {
    Life<ConwayCell> board(30, 20);
    for(int i = 0 ; i< 12 ; i++)
    {
        board.generate();
    }
    ASSERT_TRUE(board._gen == 12);
    ASSERT_FALSE(board._gen == 0);


}

TEST(Life, Generate_cell5) {
    Life<ConwayCell> board(30, 20);
    for(int i = 0 ; i< 163 ; i++)
    {
        board.generate();
    }
    ASSERT_TRUE(board._gen == 163);
    ASSERT_FALSE(board._gen == 0);



}
TEST(Life, Generate_cell6) {
    Life<ConwayCell> board(30, 20);
    for(int i = 0 ; i< 33 ; i++)
    {
        board.generate();
    }
    ASSERT_TRUE(board._gen == 33);
    ASSERT_FALSE(board._gen == 0);

}

TEST(Life, number_of_neighbors_Conway1) {
    Life<ConwayCell> board(30, 20);
    board.create(2,2);
    board.create(2,3);
    board.create(3,3);
    board.create(3,2);
    int temp = board.numNeighbors(board._grid,2,3,true);
    ASSERT_TRUE(temp == 3);
    temp = board.numNeighbors(board._grid,0,0,true);
    ASSERT_TRUE(temp == 0);

}

TEST(Life, number_of_neighbor_Conway2) {
    Life<ConwayCell> board(30, 20);
    board.create(0,0);
    board.create(2,0);
    board.create(2,2);
    board.create(0,2);
    int temp = board.numNeighbors(board._grid,0,0,true);
    ASSERT_TRUE(temp == 0);


}
TEST(Life, number_of_neighbors_Conway3) {
    Life<ConwayCell> board(30, 20);
    board.create(0,0);
    board.create(0,1);
    board.create(1,1);
    board.create(1,0); 
    int temp = board.numNeighbors(board._grid,0,0,true);
    ASSERT_TRUE(temp == 3);
}


TEST(Life, number_of_neighbors_Fredkin1) {
    Life<FredkinCell> board(30, 20);
    board.create(2,2);
    board.create(2,3);
    board.create(3,3);
    board.create(3,2);
    int temp = board.numNeighbors(board._grid,2,3,false);
    ASSERT_TRUE(temp == 2);
    temp = board.numNeighbors(board._grid,0,0,false);
    ASSERT_TRUE(temp == 0);

}

TEST(Life, number_of_neighbor_Fredkin2) {
    Life<FredkinCell> board(30, 20);
    board.create(0,0);
    board.create(0,1);
    board.create(1,1);
    board.create(1,0); 
    int temp = board.numNeighbors(board._grid,0,0,false);
    ASSERT_TRUE(temp == 2);

}
TEST(Life, number_of_neighbors_Fredkin3) {
    Life<FredkinCell> board(30, 20);
    board.create(0,0);
    board.create(19,29);
    board.create(0,29);
    board.create(19,0); 
    int temp = board.numNeighbors(board._grid,0,0,false);
    ASSERT_TRUE(temp == 0);
}

TEST(Life, kill_Conway1) {
    Life<ConwayCell> board(30, 20);
    board.create(2,2);
    board.create(2,3);
    board.create(3,3);
    board.create(3,2);
    board.kill(2,3);
    ASSERT_TRUE((*(board._grid[2][3])).isAlive() == false);
    ASSERT_TRUE((*(board._grid[3][3])).isAlive() == true);

}

TEST(Life, kill_Conway2) {
    Life<ConwayCell> board(30, 20);
    board.create(0,0);
    board.create(19,29);
    board.create(19,0);
    board.create(0,29);
    board.kill(0,0);
    board.kill(19,29);
    board.kill(19,0);
    board.kill(0,29);
    ASSERT_TRUE((*(board._grid[0][0])).isAlive() == false);
    ASSERT_TRUE((*(board._grid[19][29])).isAlive() == false);
    ASSERT_TRUE((*(board._grid[19][0])).isAlive() == false);
    ASSERT_TRUE((*(board._grid[0][29])).isAlive() == false);

}

TEST(Life, kill_Conway3) {
    Life<ConwayCell> board(30, 20);
    board.create(0,0);
    ASSERT_TRUE((*(board._grid[0][0])).isAlive() == true);
    board.create(2,3);
    ASSERT_TRUE((*(board._grid[2][3])).isAlive() == true);
    board.create(1,1);
    board.kill(0,0);
    board.kill(2,3);
    board.kill(1,1);
    ASSERT_TRUE((*(board._grid[2][3])).isAlive() == false);
    ASSERT_TRUE((*(board._grid[0][0])).isAlive() == false);
    ASSERT_TRUE((*(board._grid[1][1])).isAlive() == false);

}

TEST(Life, kill_Fredkin1) {
    Life<FredkinCell> board(30, 20);
    board.create(2,2);
    board.create(2,3);
    board.create(3,3);
    board.create(3,2);
    board.kill(2,3);
    ASSERT_TRUE((*(board._grid[2][3])).isAlive() == false);
    ASSERT_TRUE((*(board._grid[3][3])).isAlive() == true);

}

TEST(Life, kill_Fredkin2) {
    Life<FredkinCell> board(30, 20);
    board.create(0,0);
    board.create(19,29);
    board.create(19,0);
    board.create(0,29);
    board.kill(0,0);
    board.kill(19,29);
    board.kill(19,0);
    board.kill(0,29);
    ASSERT_TRUE((*(board._grid[0][0])).isAlive() == false);
    ASSERT_TRUE((*(board._grid[19][29])).isAlive() == false);
    ASSERT_TRUE((*(board._grid[19][0])).isAlive() == false);
    ASSERT_TRUE((*(board._grid[0][29])).isAlive() == false);

}

TEST(Life, kill_Fredkin3) {
    Life<FredkinCell> board(30, 20);
    board.create(0,0);
    ASSERT_TRUE((*(board._grid[0][0])).isAlive() == true);
    board.create(2,3);
    ASSERT_TRUE((*(board._grid[2][3])).isAlive() == true);
    board.create(1,1);
    board.kill(0,0);
    board.kill(2,3);
    board.kill(1,1);
    ASSERT_TRUE((*(board._grid[2][3])).isAlive() == false);
    ASSERT_TRUE((*(board._grid[0][0])).isAlive() == false);
    ASSERT_TRUE((*(board._grid[1][1])).isAlive() == false);

}

TEST(Life, kill_Cell1) {
    Life<Cell> board(30, 20);
    board.create(2,2);
    board.create(2,3);
    board.create(3,3);
    board.create(3,2);
    board.kill(2,3);
    ASSERT_TRUE((*(board._grid[2][3])).isAlive() == false);
    ASSERT_TRUE((*(board._grid[3][3])).isAlive() == true);

}

TEST(Life, kill_Cell2) {
    Life<Cell> board(30, 20);
    board.create(0,0);
    board.create(19,29);
    board.create(19,0);
    board.create(0,29);
    board.kill(0,0);
    board.kill(19,29);
    board.kill(19,0);
    board.kill(0,29);
    ASSERT_TRUE((*(board._grid[0][0])).isAlive() == false);
    ASSERT_TRUE((*(board._grid[19][29])).isAlive() == false);
    ASSERT_TRUE((*(board._grid[19][0])).isAlive() == false);
    ASSERT_TRUE((*(board._grid[0][29])).isAlive() == false);

}

TEST(Life, kill_Cell3) {
    Life<Cell> board(30, 20);
    board.create(0,0);
    ASSERT_TRUE((*(board._grid[0][0])).isAlive() == true);
    board.create(2,3);
    ASSERT_TRUE((*(board._grid[2][3])).isAlive() == true);
    board.create(1,1);
    board.kill(0,0);
    board.kill(2,3);
    board.kill(1,1);
    ASSERT_TRUE((*(board._grid[2][3])).isAlive() == false);
    ASSERT_TRUE((*(board._grid[0][0])).isAlive() == false);
    ASSERT_TRUE((*(board._grid[1][1])).isAlive() == false);

}

TEST(Life, Population_1) {
    Life<Cell> board(30, 20);
    for(int i = 0 ; i < 10;i++)
    {
        board.create(i,i);
    }
    ASSERT_TRUE(board.population() == 10);

}

TEST(Life, Population_2) {
    Life<Cell> board(30, 20);
    board.create(0,0);
    board.create(19,29);
    board.create(19,0);
    board.create(0,29);
    ASSERT_TRUE(board.population() == 4);

}

TEST(Life, Population_3) {
    Life<Cell> board(30, 20);
    board.create(0,0);
    board.create(2,3);
    board.create(1,1);
    board.kill(0,0);
    ASSERT_TRUE( board.population() == 2);

}

TEST(Life, Population_4) {
    Life<Cell> board(30, 20);
    for(int i = 0 ; i < 10;i++)
    {
        for(int j = 0; j < 2 ; j++)
        {

            board.create(i,j);
        }
    }
    ASSERT_TRUE(board.population() == 20);

}

TEST(Life, Population_5) {
    Life<Cell> board(30, 30);
    for(int i = 0 ; i < 10;i++)
    {
        for(int j = 0; j < 3 ; j++)
        {

            board.create(i,j);
        }
    }
    ASSERT_TRUE(board.population() == 30);

}

TEST(Life, Population_6) {
    Life<Cell> board(30, 20);
    for(int i = 0 ; i < 5;i++)
    {
        for(int j = 0; j < 5 ; j++)
        {

            board.create(i,j);
        }
    }
    ASSERT_TRUE(board.population() == 25);

}



TEST(Life, Population_7) {
    Life<Cell> board(30, 20);
    for(int i = 0 ; i < 30;i++)
    {
        board.create(0,i);
    }
    ASSERT_TRUE(board.population() == 30);

}

TEST(Life, Population_8) {
    Life<Cell> board(30, 30);
    for(int i = 0 ; i < 10;i++)
    {
        for(int j = 0; j < 10 ; j++)
        {

            board.create(i,j);
        }
    }
    ASSERT_TRUE(board.population() == 100);

}

TEST(Life, Population_9) {
    Life<Cell> board(30, 20);
    for(int i = 0 ; i < 30;i++)
    {
        for(int j = 0; j < 20 ; j++)
        {

            board.create(j,i);
        }
    }
    ASSERT_TRUE(board.population() == (30*20));

}

TEST(Life, Generation_and_Population_1) {
    Life<Cell> board(30, 20);
    for(int i = 0 ; i < 10;i++)
    {
        board.create(i,i);
    }
    board.generate();
    ASSERT_TRUE(board.population() == 2);

}

TEST(Life, Generation_and_Population_2) {
    Life<Cell> board(30, 20);
    board.create(0,0);
    board.create(19,29);
    board.create(19,0);
    board.create(0,29);
    board.generate();

    ASSERT_TRUE(board.population() == 8);

}

TEST(Life,Generation_and_Population_3) {
    Life<Cell> board(30, 20);
    board.create(0,0);
    board.create(2,3);
    board.create(1,1);
    board.kill(0,0);
    board.generate();

    ASSERT_TRUE(board.population() == 8);

}

TEST(Life, Generation_and_Population_4) {
    Life<Cell> board(30, 20);
    for(int i = 0 ; i < 10;i++)
    {
        for(int j = 0; j < 2 ; j++)
        {

            board.create(i,j);
        }
    }
        board.generate();
    ASSERT_TRUE(board.population() == 28);

}

TEST(Life, Generation_and_Population_5) {
    Life<Cell> board(30, 30);
    for(int i = 0 ; i < 10;i++)
    {
        for(int j = 0; j < 3 ; j++)
        {

            board.create(i,j);
        }
    }
        board.generate();
    ASSERT_TRUE(board.population() == 31);

}

TEST(Life, Generation_and_Population_6) {
    Life<Cell> board(30, 20);
    for(int i = 0 ; i < 5;i++)
    {
        for(int j = 0; j < 5 ; j++)
        {

            board.create(i,j);
        }
    }
        board.generate();
    ASSERT_TRUE(board.population() == 22);

}



TEST(Life, Generation_and_Population_7) {
    Life<Cell> board(30, 20);
    for(int i = 0 ; i < 30;i++)
    {
        board.create(0,i);
    }
        board.generate();
    ASSERT_TRUE(board.population() == 32);

}

TEST(Life, Generation_and_Population_8) {
    Life<Cell> board(30, 30);
    for(int i = 0 ; i < 10;i++)
    {
        for(int j = 0; j < 10 ; j++)
        {

            board.create(i,j);
        }
    }
        board.generate();
    ASSERT_TRUE(board.population() == 52);

}

TEST(Life, Generation_and_Population_9) {
    Life<Cell> board(30, 20);
    for(int i = 0 ; i < 30;i++)
    {
        for(int j = 0; j < 20 ; j++)
        {

            board.create(j,i);
        }
    }
        board.generate();
    ASSERT_TRUE(board.population() == 92);

}

TEST(Life, RUN_LIFE1){
    Life<Cell> board(1,1);
    board.create(0,0);
    for(int i = 0; i<100;i++)
    {
        board.generate();
    }
    ASSERT_TRUE(board.population() == 0);
}

TEST(Life, RUN_LIFE2){
    Life<ConwayCell> board(2,2);
    board.create(0,0);
    board.create(0,1);
    board.create(1,0);
    board.create(1,1);

    for(int i = 0; i<100;i++)
    {
        board.generate();
    }
    ASSERT_TRUE(board.population() == 4);
}

TEST(Life, RUN_LIFE3){
    Life<FredkinCell> board(2,2);
    board.create(0,0);
    board.create(0,1);
    board.create(1,0);
    board.create(1,1);

    for(int i = 0; i<100;i++)
    {
        board.generate();
    }
    ASSERT_TRUE(board.population() == 0);
}

TEST(Life, RUN_LIFE4){
    Life<Cell> board(2,2);
    board.create(0,0);
    board.create(0,1);
    board.create(1,0);
    board.create(1,1);

    for(int i = 0; i<100;i++)
    {
        board.generate();
    }

    ASSERT_TRUE(board.population() == 0);
}

TEST(Life, RUN_LIFE5){
    Life<Cell> board(3,3);
    for(int i = 0 ; i< 3;i++)
    {
        for(int j = 0; j<3;j++)
        {
            board.create(i,j);
        }
    }
    for(int i = 0; i<100;i++)
    {
        board.generate();
    }
    ASSERT_TRUE(board.population() == 0);
}

TEST(Life, RUN_LIFE6){
    Life<ConwayCell> board(10,10);
    srand(0);
    for(int i = 0 ; i< 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(rand() % 2 == 0)
            {
                board.create(i,j);
            }
        }
    }

    ASSERT_TRUE(board.population() == 52);
}
    

TEST(Life, RUN_LIFE7){
    Life<Cell> board(10,10);
    srand(0);
    for(int i = 0 ; i< 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(rand() % 2 == 0)
            {
                board.create(i,j);
            }
        }
    }
    for(int i = 0; i<100;i++)
    {
        board.generate();
    }
    ASSERT_TRUE(board.population() == 8);    
}

TEST(Life, RUN_LIFE8){
    Life<Cell> board(20,20);
    srand(0);
    for(int i = 0 ; i< 20; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            if(rand() % 2 == 0)
            {
                board.create(i,j);
            }
        }
    }
    for(int i = 0; i<100;i++)
    {
        board.generate();
    }
    ASSERT_TRUE(board.population() == 26);  
}

TEST(Life, RUN_LIFE9){
    Life<Cell> board(30,30);
    srand(0);
    for(int i = 0 ; i< 30; i++)
    {
        for(int j = 0; j < 30; j++)
        {
            if(rand() % 2 == 0)
            {
                board.create(i,j);
            }
        }
    }
    for(int i = 0; i<100;i++)
    {
        board.generate();
    }
    ASSERT_TRUE(board.population() == 21);  
}

TEST(Life, RUN_LIFE10){
    Life<Cell> board(40,40);
    srand(0);
    for(int i = 0 ; i< 40; i++)
    {
        for(int j = 0; j < 40; j++)
        {
            if(rand() % 2 == 0)
            {
                board.create(i,j);
            }
        }
    }
    for(int i = 0; i<100;i++)
    {
        board.generate();
    }
    ASSERT_TRUE(board.population() == 107);  
}

TEST(Life, RUN_LIFE11){
    Life<Cell> board(50,50);
    srand(0);
    for(int i = 0 ; i< 50; i++)
    {
        for(int j = 0; j < 50; j++)
        {
            if(rand() % 2 == 0)
            {
                board.create(i,j);
            }
        }
    }
    for(int i = 0; i<100;i++)
    {
        board.generate();
    }
    ASSERT_TRUE(board.population() == 238);  
}

TEST(Life, RUN_LIFE12){
    Life<Cell> board(60,60);
    srand(0);
    for(int i = 0 ; i< 60; i++)
    {
        for(int j = 0; j < 60; j++)
        {
            if(rand() % 2 == 0)
            {
                board.create(i,j);
            }
        }
    }
    for(int i = 0; i<100;i++)
    {
        board.generate();
    }
    ASSERT_TRUE(board.population() == 286);  
}