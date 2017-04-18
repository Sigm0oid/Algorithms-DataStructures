#include <bits/stdc++.h>

using namespace std;
int n;
char tab[110][110];
int vis[110][100];
int xmove[4]={1,-1,0,0};
int ymove[4]={0,0,1,-1};

bool inbound(int i,int j){
return (i>=0&&j>=0&&i<n&&j<n);}

int dfs(int x,int y){
    vis[x][y]=1;
    int res=0;
    if(tab[x][y]=='x'){res++;}
    for(int i=0;i<4;i++){

        int xi=x+xmove[i];
        int yi=y+ymove[i];
        if (inbound(xi,yi)){
        if(tab[xi][yi]!='.'&&vis[xi][yi]==0){

            res+=dfs(xi,yi);
        }
        }
    }

    return res;




}


int main()
{
    //freopen("out.out","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
            int res=0;
        cin>>n;
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                cin>>tab[j][k];
                vis[j][k]=0;
                if(tab[j][k]=='x'){res++;}
            }
        }

     for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
            if(tab[j][k]=='x'&&vis[j][k]==0){


                res-=dfs(j,k);
                res++;
            }
            }
        }
        cout<<"Case "<<i+1<<": "<<res<<endl;

    }

    return 0;
}
