#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//typedef pair<int,int> ii;
//typedef pair<ii,ii> iiii;
int n;
bool dp[500][500][31][9];
int vis[500][500];
int ti[50];
ll cmp=0;
int xi[8]={0,1,1,1,0,-1,-1,-1};
int yi[8]={1,1,0,-1,-1,-1,0,1};
void dfs(int x,int y,int level,int direction){
int tmp_x=x;
int tmp_y=y;

for(int k=0;k<ti[level];k++)
{
     x+=xi[direction];
     y+=yi[direction];

     cmp+=(vis[x][y]==0);
     vis[x][y]=1;

}
dp[tmp_x][tmp_y][level][direction]=1;

if(level<n-1){
    int dir=direction+1;
    if(dir>7)
    dir=0;
if(dp[x][y][level+1][dir]==0)
dfs(x,y,level+1,(dir));
     dir=direction-1;
    if(dir<0)
    dir=7;
if(dp[x][y][level+1][dir]==0)
dfs(x,y,level+1,(dir));

}


}
int main()
{
    memset(vis,0,sizeof vis);
    memset(dp,0,sizeof dp);

    scanf("%d",&n);

    for(int i=0;i<n;i++){
      scanf("%d",&ti[i]);

    }
    dfs(200,200,0,0);

    printf("%lld\n",cmp);
    return 0;
}



