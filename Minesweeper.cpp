#include <iostream>
#include <string>
#include <cstdlib> 
using namespace std;

class Tile{//Tile class
    public: 
    bool isMine;
    int sMines;

    Tile(){
        isMine = false;
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

    public:
    int difficultyFlags;
    GameBoard(string difficulty)
    {
        
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
        int tempFlag=difficultyFlags;
        while(tempFlag>0)//populate matrix with mines
        {
            int minex=rand()%rlen;
            int miney=rand()%clen;
            
            //put in case switch for difficulty again
            switch(diff)
            {
                case 1:
                if(eboard[minex][miney].isMine==false)
                {
                    eboard[minex][miney].isMine=true;
                     --tempFlag;
                }
                break;
                case 2:
                if(mboard[minex][miney].isMine==false)
                {
                    mboard[minex][miney].isMine=true;
                     --tempFlag;
                }
                break;
                case 3:
                if(hboard[minex][miney].isMine==false)
                {
                    hboard[minex][miney].isMine=true;
                     --tempFlag;
                }
                break;

            }
            
                   
        }
        
        switch(diff)
            {
                case 1:
                
                break;
                case 2:

                break;
                case 3: 

                break;

            }

        
        cout<<""<<endl;

        

    }
    


    



};
class Player
{

    

};
int main()
{
    cout << "player class";
    GameBoard("easy");


    return 0;
}
