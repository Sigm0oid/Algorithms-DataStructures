#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int x[8]={1,-1,2,2,1,-1,-2,-2};
int y[8]={2,2,1,-1,-2,-2,1,-1};
bool inbound(int x,int y){
    if((x>7)||(x<0)||(y>7)||(y<0)){
        return false;
    }
    return true;
}
int main()
{
int t;
cin>>t;
for(int h=0;h<t;h++){
    string s,d;
    cin>>s>>d;
    int vis[8][8]={0};
    int lvl[8][8]={0};
    int sy=s[1]-'0'-1;
    int sx=s[0]-'a';
    int dy=d[1]-'0'-1;
    int dx=d[0]-'a';
    queue<int>q;
    q.push(sx);
    q.push(sy);
    lvl[sx][sy]=0;
    while(!q.empty()){
    int ax=q.front();
    q.pop();
    int ay=q.front();
    q.pop();
    //cout<<"level "<<lvl[ax][ay]<<endl;
 //   cout<<" im on "<<ax<<" "<<ay<<endl;


    if((ax==dx)&&(ay==dy)){
        cout<<lvl[ax][ay]<<endl;
        //cout<<"found"<<endl;
        break;
    }
    for(int i=0;i<8;i++){
    if(0==vis[ax+x[i]][ay+y[i]]){
        if(inbound(ax+x[i],ay+y[i])){
        vis[ax+x[i]][ay+y[i]]=1;
        lvl[ax+x[i]][ay+y[i]]=lvl[ax][ay]+1;
        q.push(ax+x[i]);
        q.push(ay+y[i]);
        }
    }

    }
    }

}    return 0;
}
