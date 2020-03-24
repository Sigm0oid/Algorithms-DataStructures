#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
vector<int> vi;
int n,m,s;
char tab[500][500];
int vis[500][500];
int xi[4]={1,0,-1,0};
int yi[4]={0,1,0,-1};
bool inbound(int i,int j){
return (i<n&&j<m&&i>=0&&j>=0);
}
void dfs(int x,int y){
//cout<<" im in "<< x<< " "<<y<<endl;
vis[x][y]=1;
for(int i=0;i<4;i++){
   int x1=x+xi[i];
   int y1=y+yi[i];
   if(vis[x1][y1]==0&&tab[x1][y1]=='.'&&inbound(x1,y1)){
   vis[x1][y1]=1;
   dfs(x1,y1);


   }
}

 if(s>0)
   {
   tab[x][y]='X';
   s--;
   }
return;
}

int main()
{
    int tmpx=-1,tmpy=-1;
    cin>>n>>m>>s;
    for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>tab[i][j];
        if(tab[i][j]=='.'&&tmpx==-1&&tmpy==-1)
        {
            tmpx=i;
            tmpy=j;
        }
    }
    }
    memset(vis,0,sizeof vis);


    dfs(tmpx,tmpy);

  //  cout<<endl;
    for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
     cout<<tab[i][j];
    }
    cout<<endl;
    }

    return 0;
}

