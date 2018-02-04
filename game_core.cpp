//
// Created by peyman on 1/31/18.
//
#include "game_core.h"

Core::Core() {
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            board.a[i][j]=0;
        }
    }
    board.a[3][3]=1;
    board.a[4][4]=1;
    board.a[3][4]=2;
    board.a[4][3]=2;
    cordinations[0]=Point(-1,-1);
    cordinations[1]=Point(-1,0);
    cordinations[2]=Point(-1,1);
    cordinations[3]=Point(0,-1);
    cordinations[4]=Point(0,1);
    cordinations[5]=Point(1,-1);
    cordinations[6]=Point(1,0);
    cordinations[7]=Point(1,1);
}
Board Core::getBoard() {
    return board;
}
void Core::setBoard(int x, int y, int c) {
    board.a[x][y]=c;
}
int Core::score(int player) {
    int res=0;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(board.a[i][j]==player)
                res+=1;
        }
    }
    return res;
}
std::vector<Suggestion> Core ::suggest(int player) {
    std::vector<Suggestion> res;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(board.a[i][j])
                continue;
            Suggestion temp(i,j);
            for(int k=0;k<8;k++)
            {
                int cx=i+cordinations[k].x;
                int cy=j+cordinations[k].y;
                for(int l=0;cx<8 && cy<8 && cx>=0 && cy>=0;l++)
                {
                    if(board.a[cx][cy]==0)
                    {
                        break;
                    }
                    if(board.a[cx][cy]==player)
                    {
                        if(l) {
                            temp.reverseCords.push_back(cordinations[k]);
                            temp.flips++;
                        }
                        break;
                    }
                    cx=cx+cordinations[k].x;
                    cy=cy+cordinations[k].y;
                }

            }
            if(temp.flips)
            {
                res.push_back(temp);
            }
        }
    }
    return res;
}
void Core::AIchoice() {
    std::vector<Suggestion> ss=suggest(2);
    if(ss.size()==0)
        return;
    int max=0,max_index=0;
    for(int i=0;i<ss.size();i++)
    {
        if(ss[i].flips>max)
        {
            max=ss[i].flips;
            max_index=i;
        }
    }
    Suggestion mychoice=ss[max_index];
    board.a[mychoice.x][mychoice.y]=2;
    for(int i=0;i<mychoice.reverseCords.size();i++)
    {
        int cx=mychoice.x+mychoice.reverseCords[i].x;
        int cy=mychoice.y+mychoice.reverseCords[i].y;
        while(cx>=0 && cy>=0 && cx<8 && cy<8 && board.a[cx][cy]!=2)
        {
            board.a[cx][cy]=2;
            cx=cx+mychoice.reverseCords[i].x;
            cy=cy+mychoice.reverseCords[i].y;
        }

    }
}