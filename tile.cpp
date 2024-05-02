class Tile{
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