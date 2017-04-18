#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int  board[8][8];
long long score;
bitset<30> rd,ld,rw;
//int cmp=0;

void backtrack(int c,ll currscore){
           // cout<<"called with new score= "<<currscore<<endl;
if(c==8){

//cmp++;
    if(score<currscore){
        score=currscore;
    }

}else{
for(int r=0;r<8;r++){
    if((!rw[r])&&(!rd[r-c+8-1])&&(!ld[c+r]))
    {
        rw[r]=true;
        rd[r-c+8-1]=true;
        ld[c+r]=true;
        backtrack(c+1,currscore+board[r][c]);
        rw[r]=false;
        rd[r-c+8-1]=false;
        ld[c+r]=false;

    }
}
}
}

int main()
{

//    freopen("out.out","w",stdout);
    rd=false;
    ld=false;
    rw=false;
int k;
cin>>k;
for(int i=0;i<k;i++){
    memset(board,0,sizeof board);
    score=0;
    rd=false;
    ld=false;
    rw=false;


    //Read board
    for(int j=0;j<8;j++){
            for(int k=0;k<8;k++){
                cin>>board[j][k];
            }

    }
    backtrack(0,0);
    if(score/10000==0){
        cout<<" ";
    }
    if(score/1000==0){
        cout<<" ";
    }
    if(score/100==0){
        cout<<" ";
    }
    if(score/10==0){
        cout<<" ";
    }
    cout<<score<<endl;
}
//



    return 0;
}
