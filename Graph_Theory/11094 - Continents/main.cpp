#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef vector<ll> vi;
int n,m;
char tab[21][21];
int vis[21][21];
int xking ,yking;
int movex[4]={1,0,0,-1};
int movey[4]={0,1,-1,0};
char land,water;
bool inbound(int x, int y){
return (x>=0&&x<m&&y>=0&&y<n);}

int dfs(int x,int y){
    int res=1;
      if(x==xking&&y==yking){
                        res= -1000;
                   }
    if(y==0){

        if(vis[x][n-1]==0&&tab[x][n-1]==land){
                    vis[x][n-1]=1;
                    res+=dfs(x,n-1);
        }


    }
    if(y==n-1){

        if(vis[x][0]==0&&tab[x][0]==land){
                    vis[x][0]=1;
                    res+=dfs(x,0);
        }


    }



    for(int i=0;i<4;i++){
            int xi=x+movex[i];
            int yi=y+movey[i];
            if(inbound(xi,yi)){
                if(vis[xi][yi]==0&&tab[xi][yi]==land){
                    vis[xi][yi]=1;
                    res+=dfs(xi,yi);
                }

            }
             if(xi==xking&&yi==yking){
                        res= -1000;
                   }


    }
return res;
}
int main()
{
    //freopen("out.out","w",stdout);
    while(cin>>m>>n){
            memset(vis,0,sizeof vis);
            char a,b;bool done=false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>tab[i][j];
                if(i==0&&j==0){
                    a=tab[i][j];
                    b=tab[i][j];
                }
                if(tab[i][j]!=a&&!done){
                    done=true;
                    b=tab[i][j];
                }

            }
        }
    cin>>xking>>yking;
    land=tab[xking][yking];
    if(a==land){
        water=b;
    }
    else{
        water=a;
    }





    int res=0;
    if(a==b){cout<<0<<endl;}
    else{
       for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0&&tab[i][j]==land&&(i!=xking||j!=yking))

                   {
                    vis[i][j]=1;
                 //    cout<<"call from "<<i<<" "<<j;
                    res=max(res,dfs(i,j));
                }
            }
     //   cout<<endl;
        }
        cout<<res<<endl;

    }
    }

    return 0;
}
