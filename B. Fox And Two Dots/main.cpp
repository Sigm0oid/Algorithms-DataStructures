#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int vis[50][50];
char tab[50][50];
int n,m;
bool found=false;
int x[4]={0,-1,0,1};
int y[4]={1,0,-1,0};

bool inbound(int i,int j){
return(i<n&&i>=0&&j<m&&j>=0);
}
int cmp;
void dfs(int i, int j,int fx,int fy,int cmp){
vis[i][j]=1;

//cout<<"visited "<< i <<" "<<j<<" tab "<<tab[i][j]<<" "<<cmp<<endl;;
for(int k=0;k<4;k++){
    int xi=x[k]+i;
    int yi=y[k]+j;
    if(inbound(xi,yi)&&tab[i][j]==tab[xi][yi]&&!(xi==fx&&fy==yi)){
        if(vis[xi][yi]==1)
        {
        if(cmp>3){
        found=true;
        return ;
            }
        }
        vis[xi][yi]=1;
        dfs(xi,yi,i,j,cmp+1);
    }
}

}


int main()
{

    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>tab[i][j];
        }
    }

    for(int i=0;i<n&&(!found);i++){
        for(int j=0;j<m&&(!found);j++){
        memset(vis,0,sizeof vis);
            dfs(i,j,-1,-1,1);
        }
    }

    if(found)
    cout<<"Yes"<<endl;
    else
    cout<<"No"<<endl;

    return 0;
}

