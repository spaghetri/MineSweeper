#include <iostream>
#include <string>
using namespace std;

class Tile{//Tile class
    public: 
    bool isMine;
    int sMines;

    Tile(){
        isMine = false;
        sMines;
    }

    void setMine(){
        isMine = true;
        sMines = -1;
    }
    
    void setSMines(int s){
        sMines = s;
    }
};
class GameBoard: public Tile
{
    private:
    

    public:
    GameBoard(string difficulty)
    {
        if(difficulty.compare("easy")==0)//easy
        {
            Tile eboard[8][10];
            for(int r=0;r<8;r++)
            {
                for(int c=0;c<10;c++)
                {
                }
            }
        }
        else if(difficulty.compare("hard")==0)//hard
        {
            Tile hboard[20][25];
            for(int r=0;r<20;r++)
            {
                for(int c=0;c<25;c++)
                {
                }
            }
        }
        else//medium, default difficulty
        {
            Tile mboard[14][18];
            for(int r=0;r<14;r++)
            {
                for(int c=0;c<18;c++)
                {
                }
            }
        }

    }
    


    



};
class Player
{

    

};
int main()
{
    cout << "player class";
    GameBoard("j");


    return 0;
}
