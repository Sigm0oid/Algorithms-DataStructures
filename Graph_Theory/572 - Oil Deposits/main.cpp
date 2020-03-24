#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int > vi;
char mat[110][110];
int vis[110][110];
int x[8]={1,1,1,0,0,-1,-1,-1};
int y[8]={1,0,-1,1,-1,1,0,-1};
int n,m;
int inbound(int i,int j){
return(i<n&&i>=0&&j>=0&&j<m);
}
void dfs(int a,int b ){
    vis[a][b]=1;
    for(int i=0;i<8;i++){
        int xi=x[i]+a;
        int yi=y[i]+b;
        if(inbound(xi,yi)&&(vis[xi][yi]==0)&&(mat[xi][yi]=='@')){
            dfs(xi,yi);
        }
    }
}

int main()
{
    while(cin>>n>>m&&(n>0||m>0)){
            memset(vis,0,sizeof vis);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>mat[i][j];
            }
        }
        memset(vis,0,sizeof vis);
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if((vis[i][j]==0)&&(mat[i][j]=='@')){
                res++;
                dfs(i,j);
               }
            }
        }
        cout<<res<<endl;

    }

    return 0;
}
