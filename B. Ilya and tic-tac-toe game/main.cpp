#include <bits/stdc++.h>

using namespace std;
char tab[4][4];
int vis[4][4];
int xi[8]={1,1,0,-1,-1,-1,0,1};
int yi[8]={0,1,1,1,0,-1,-1,-1};
bool found=false;
bool inbound(int i,int j){
return (i<4&&j<4&&i>=0&&j>=0);}

bool check(int x,int y){
for(int i=0;i<8;i++){
    int x1=x+xi[i];
    int x2=x-xi[i];
    int y1=y+yi[i];
    int y2=y-yi[i];
    if(inbound(x1,y1)&&inbound(x2,y2)){
        if(tab[x1][y1]=='x'&&tab[x2][y2]=='x')
            return true;
    }
     x1=x+xi[i];
     x2=x1+xi[i];
     y1=y+yi[i];
     y2=y1+yi[i];
    if(inbound(x1,y1)&&inbound(x2,y2)){
        if(tab[x1][y1]=='x'&&tab[x2][y2]=='x')
            return true;
    }
     x1=x-xi[i];
     x2=x1-xi[i];
     y1=y-yi[i];
     y2=y1-yi[i];
    if(inbound(x1,y1)&&inbound(x2,y2)){
        if(tab[x1][y1]=='x'&&tab[x2][y2]=='x')
            return true;
    }
}
return false;
}
int main()
{
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin>>tab[i][j];
        }
    }
    for(int i=0;i<4&&(found==false);i++){
        for(int j=0;j<4&&(found==false);j++){
           if(tab[i][j]=='.'){
                tab[i][j]='x';
                found=check(i,j);
                tab[i][j]='.';
           }
        }
    }
    if(found){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}
