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
    Tile eboard[8][10];
    Tile mboard[14][18];
    Tile hboard[20][25];
    



};
class Player
{

};
