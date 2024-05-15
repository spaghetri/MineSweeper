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
    
    
    Tile eboard[8][10];
    Tile mboard[14][18];
    Tile hboard[20][24];
    public:
    int rlen, clen;//row and column length
    int difficultyFlags;
    bool alive;
    GameBoard(string difficulty)
    {
        
        random_device rd;
        int  diff;
        alive=true;
        
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


        void breakTile(int x, int y, int diff)
        { 
            
            if(diff==1)
                {
                    if(eboard[x][y].broken == false && eboard[x][y].isMine == false){
                    eboard[x][y].broken = true;
                    if(eboard[x][y].sMines == 0){
                        
                    }
                }
                else if(eboard[x][y].broken == false && eboard[x][y].isMine == true)
                {
                    alive = false;
                }
                else{
                    cout<<"Tile is already broken"<<endl;
                }
            }
            else if(diff==3)
            {
                 if(hboard[x][y].broken == false && hboard[x][y].isMine == false){
                hboard[x][y].broken = true;
                if(hboard[x][y].sMines == 0){
                    
                }
            }
            else if(hboard[x][y].broken == false && hboard[x][y].isMine == true)
            {
                alive = false;
            }
            else{
                cout<<"Tile is already broken"<<endl;
            }
            }
            else
            {
                 if(mboard[x][y].broken == false && mboard[x][y].isMine == false){
                mboard[x][y].broken = true;
                if(mboard[x][y].sMines == 0){
                    
                }
            }
            else if(mboard[x][y].broken == false && mboard[x][y].isMine == true)
            {
                alive = false;
            }
            else{
                cout<<"Tile is already broken"<<endl;
            }
            }

            
        }
        void markTile(int x, int y, int diff)
        {
            if(diff==1)
            {
                    if(eboard[x][y].isFlagged==false)
                {
                    eboard[x][y].isFlagged=true;
                    difficultyFlags--;
                }
                else
                {
                    cout<<"already flagged silly"<<endl;
                }

                if(difficultyFlags==0)
                {
                    int count;
                    count=0;
                    for(int r=0;r<rlen;r++)
                    {
                        for(int c=0;c<clen;c++)
                        {
                            if(eboard[r][c].isFlagged&&eboard[r][c].isMine)
                            {
                                count++;
                            }
                        }
                    }
                    if(count==10)
                    {
                        cout<<"YOU WIN";
                        
                    }
                }
            }
            else if(diff==3)
            {
                    if(hboard[x][y].isFlagged==false)
                {
                    hboard[x][y].isFlagged=true;
                    difficultyFlags--;
                }
                else
                {
                    cout<<"already flagged silly"<<endl;
                }
                if(difficultyFlags==0)
                {
                    int count;
                    count=0;
                    for(int r=0;r<rlen;r++)
                    {
                        for(int c=0;c<clen;c++)
                        {
                            if(hboard[r][c].isFlagged&&hboard[r][c].isMine)
                            {
                                count++;
                            }
                        }
                    }
                    if(count==99)
                    {
                        cout<<"YOU WIN";
                        
                    }
                }
            }
            else
            {
                    if(mboard[x][y].isFlagged==false)
                {
                    mboard[x][y].isFlagged=true;
                    difficultyFlags--;
                }
                else
                {
                    cout<<"already flagged silly"<<endl;
                }
            }
            if(difficultyFlags==0)
                {
                    int count;
                    count=0;
                    for(int r=0;r<rlen;r++)
                    {
                        for(int c=0;c<clen;c++)
                        {
                            if(mboard[r][c].isFlagged&&mboard[r][c].isMine)
                            {
                                count++;
                            }
                        }
                    }
                    if(count==40)
                    {
                        cout<<"YOU WIN";
                        
                    }
                }
            
            
        }
        void unMarkTile(int x, int y,int diff)
        {
            
            if(diff==1)
            {
                 if(eboard[x][y].isFlagged==true)
            {
                eboard[x][y].isFlagged=false;
                difficultyFlags++;
            }
            else
            {
                cout<<"can't unflag a tile without a flag silly"<<endl;
            }
            }
            else if(diff==3)
            {
                 if(hboard[x][y].isFlagged==true)
            {
                hboard[x][y].isFlagged=false;
                difficultyFlags++;
            }
            else
            {
                cout<<"can't unflag a tile without a flag silly"<<endl;
            }
            }
            else
            {
                 if(mboard[x][y].isFlagged==true)
            {
                mboard[x][y].isFlagged=false;
                difficultyFlags++;
            }
            else
            {
                cout<<"can't unflag a tile without a flag silly"<<endl;
            }
            }
            

        }
        void displayBoard(int d)
        {
            int diff=d;
            switch(diff)
            {
                case 1:
                for(int r=0;r<8;r++)
                {
                    for(int c=0;c<10;c++)
                    {
                        if(eboard[r][c].isFlagged)
                        {
                            cout<<"* ";
                        }
                        else if(eboard[r][c].broken==false)
                        {
                            cout<<"- ";
                        }
                        else
                        {
                            cout<<eboard[r][c].sMines<<" ";
                        }
                    }
                    cout<<endl;
                }

                break;
                case 2:
                for(int r=0;r<14;r++)
                {
                    for(int c=0;c<18;c++)
                    {
                        if(mboard[r][c].isFlagged==true)
                        {
                            cout<<"* ";
                        }
                        else if(mboard[r][c].broken==false)
                        {
                            cout<<"- ";
                        }
                        else
                        {
                            cout<<mboard[r][c].sMines<<" ";
                        }
                    }
                    cout<<endl;
                }
                break;
                case 3:
                for(int r=0;r<20;r++)
                {
                    for(int c=0;c<24;c++)
                    {
                        if(hboard[r][c].isFlagged==true)
                        {
                            cout<<"* ";
                        }
                        else if(hboard[r][c].broken==false)
                        {
                            cout<<"- ";
                        }
                        else
                        {
                            cout<<hboard[r][c].sMines<<" ";
                        }
                    }
                    cout<<endl;
                }
                break;
            }

        }
    


    



};
int main()
{
    cout << "TIME TO HAVE FUN"<<endl;
    // GameBoard board("easy");
    // board.displayBoard(1);


    cout<<"What difficulty do you want? type in \"easy\", \"medium\", or \"hard\""<<endl;
    string difficulty;
    cin>>difficulty;
    int diff;
    if(difficulty.compare("easy")==0)
    {
        diff=1;
    }
    else if(difficulty.compare("hard")==0)
    {
        diff=3;
    }
    else
    {
        diff=2;
    }
    GameBoard playerboard(difficulty);
    do
    {
        
        playerboard.displayBoard(diff);
        cout<<"would you like to break or flag or unflag a tile? type \"b\" for break and \"f\" for flag or\"u\" for unflag"<<endl;
        string decision;
        cin>>decision;
        if(decision.compare("b")==0)
        {
            cout<<"what x coordinate do you want? Type in numerical value:"<<endl;
            int x;
            cin>>x;
            cout<<"what y coordinate do you want? Type in numerical value:"<<endl;
            int y;
            cin>>y;

            if(x>=playerboard.rlen||x<0||y>=playerboard.clen||y<0)
            {
                cout<<"buddy those coordinates arent valid."<<endl;
            }
            else
            {
                playerboard.breakTile(x,y,diff);
            }
            
        }
        else if(decision.compare("f")==0)
        {
            cout<<"what x coordinate do you want? Type in numerical value:"<<endl;
            int x;
            cin>>x;
            cout<<"what y coordinate do you want? Type in numerical value:"<<endl;
            int y;
            cin>>y;
            if(x>=playerboard.rlen||x<0||y>=playerboard.clen||y<0)
            {
                cout<<"buddy those coordinates arent valid."<<endl;
            }
            else
            {
                playerboard.markTile(x,y,diff);
            }
        }
        else if(decision.compare("u")==0)
        {
            cout<<"what x coordinate do you want? Type in numerical value:"<<endl;
            int x;
            cin>>x;
            cout<<"what y coordinate do you want? Type in numerical value:"<<endl;
            int y;
            cin>>y;
            if(x>=playerboard.rlen||x<0||y>=playerboard.clen||y<0)
            {
                cout<<"buddy those coordinates arent valid."<<endl;
            }
            else
            {
                playerboard.unMarkTile(x,y,diff);
            }
        }
        else
        {
            cout<<"That was not an option buddy."<<endl;
        }

        
        





    }while(playerboard.alive==true);
    if(playerboard.alive!=true)
    {
        cout<<"you died.";
    }

    return 0;
}
