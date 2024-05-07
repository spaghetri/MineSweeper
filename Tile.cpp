class Tile{
    public: 
    bool isMine;
    bool broken;
    int sMines;

    Tile(){
        isMine = false;
        broken = false;
        sMines;
    }

    void setMine(){
        isMine = true;
        sMines = -1;
    }
    
    void setSMines(int s){
        sMines = s;
    }

    void breakMine(){
        if(broken == false && isMine == false){
            broken == true;
        }
    }
};
