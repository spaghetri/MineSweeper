#include <iostream>
#include <string>
#include <cstdlib> 
#include <random>
using namespace std;

class Tile{//Tile class
    public: 
    bool isMine;
    bool broken;
    int sMines;
    bool isFlagged;

    Tile(){
        isMine = false;
        isFlagged=false;
        broken = false;
        sMines = 0;
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
    int rlen, clen;//row and column length
    bool alive;

    public:
    int difficultyFlags;
    GameBoard(string difficulty)
    {
        
        random_device rd;
        int  diff;
        Tile eboard[8][10];
        Tile mboard[14][18];
        Tile hboard[20][24];
        if(difficulty.compare("easy")==0)//easy
        {
            diff=1;
            difficultyFlags=10;
            rlen=8;
            clen=10;
            

            for(int r=0;r<rlen;r++)
            {
                for(int c=0;c<clen;c++)
                {
                    eboard[r][c]= Tile();
                }
            }
        }
        else if(difficulty.compare("hard")==0)//hard
        {
            diff=3;
            difficultyFlags=99;
            rlen=20;
            clen=24;
            
            for(int r=0;r<rlen;r++)
            {
                for(int c=0;c<clen;c++)
                {
                    hboard[r][c]=Tile();
                }
            }
        }
        else//medium, default difficulty
        {
            
            diff=2;
            difficultyFlags=40;
            rlen=14;
            clen=18;
           
            for(int r=0;r<rlen;r++)
            {
                for(int c=0;c<clen;c++)
                {
                    mboard[r][c]=Tile();
                }
            }
            cout<<endl;
        }
        int tempMine=difficultyFlags;
        while(tempMine>0)//populate matrix with mines
        {
            int minex=rd()%rlen;
            int miney=rd()%clen;
            
            //put in case switch for difficulty again
            switch(diff)
            {
                case 1:
                if(eboard[minex][miney].isMine==false)
                {
                    eboard[minex][miney].setMine();
                     --tempMine;
                }
                break;
                case 2:
                if(mboard[minex][miney].isMine==false)
                {
                    mboard[minex][miney].setMine();
                     --tempMine;
                }
                break;
                case 3:
                if(hboard[minex][miney].isMine==false)
                {
                    hboard[minex][miney].setMine();
                     --tempMine;
                }
                break;

            }
            
                   
        }
        
        for(int r=0;r<rlen;r++)
        {
            for(int c=0;c<clen;c++)
            {
                int count=0;
                if((r-1)>=0&&(r-1)<rlen&&(c-1)>=0&&(c-1)<clen&&eboard[r-1][c-1].isMine)
                {
                    count++;
                }
                if((r-1)>=0&&(r-1)<rlen&&c>=0&&c<clen&&eboard[r-1][c].isMine)
                {
                    count++;
                }
                if((r-1)>=0&&(r-1)<rlen&&(c+1)>=0&&(c+1)<clen&&eboard[r-1][c+1].isMine)
                {
                    count++;
                }
                if(r>=0&&r<rlen&&(c-1)>=0&&(c-1)<clen&&eboard[r][c-1].isMine)
                {
                    count++;
                }
                if(r>=0&&r<rlen&&(c+1)>=0&&(c+1)<clen&&eboard[r][c+1].isMine)
                {
                    count++;
                }
                if((r+1)>=0&&(r+1)<rlen&&(c-1)>=0&&(c-1)<clen&&eboard[r+1][c-1].isMine)
                {
                    count++;
                }
                if((r+1)>=0&&(r+1)<rlen&&c>=0&&c<clen&&eboard[r+1][c].isMine)
                {
                    count++;
                }
                if((r+1)>=0&&(r+1)<rlen&&(c+1)>=0&&(c+1)<clen&&eboard[r+1][c+1].isMine)
                {
                    count++;
                }
                eboard[r][c].setSMines(count);
                
            }
        }
        

        
        cout<<""<<endl;

        

    }


        void breakTile(Tile t)
        { 
            if(t.broken == false && t.isMine == false){
                t.broken = true;
                if(t.sMines == 0){
                    
                }
            }
            else if(t.broken == false && t.isMine == true)
            {
                alive = false;
            }
            else{
                cout<<"Tile is already broken";
            }
        }
        void markTile(Tile t)
        {
            if(t.isFlagged==false)
            {
                t.isFlagged=true;
                difficultyFlags--;
            }
            else
            {
                cout<<"already flagged silly";
            }
            
        }
        void unMarkTile(Tile t)
        {
            
            if(t.isFlagged==true)
            {
                t.isFlagged=false;
                difficultyFlags++;
            }
            else
            {
                cout<<"can't unflag a tile without a flag silly";
            }

        }
        void displayBoard()
        {
            int diff=diff;
            switch(diff)
            {
                case 1:
                for(int r=0;r<8;r++)
                {
                    for(int c=0;c<10;c++)
                    {

                    }
                    cout<<endl;
                }

                break;
                case 2:
                for(int r=0;r<14;r++)
                {
                    for(int c=0;c<18;c++)
                    {

                    }
                    cout<<endl;
                }
                break;
                case 3:
                for(int r=0;r<20;r++)
                {
                    for(int c=0;c<24;c++)
                    {

                    }
                    cout<<endl;
                }
                break;
            }

        }
    


    



};
class Player
{

    

};
int main()
{
    cout << "TIME TO HAVE FUN"<<endl;
    GameBoard board("easy");
    do
    {






    }while(5>4);

    return 0;
}
