#include <bits/stdc++.h>

using namespace std;
int n,m;
int tab[101][101];
int dp[101][101];
bool  inbound(int i,int j){
return (i>=0&&j>=0&&i<n&&j<m);}
int x[4]={1,0,0,-1};
int y[4]={0,1,-1,0};;
int dfs(int i,int j){
//if(dp[i][j]!=-1){
// return 1+dp[i][j];}
//else{
int res=1;
for(int k=0;k<4;k++){
    int xi=i+x[k];
    int yi=j+y[k];
    if(inbound(xi,yi)){
    if(tab[xi][yi]<tab[i][j])
    res=max(1+dfs(xi,yi),res);
    }
}
return dp[i][j]=res;
}


int main()
{
freopen("out.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        string name;
        cin>>name>>n>>m;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>tab[i][j];
            }
            }
            memset(dp,-1,sizeof dp);
            int maxx=0;
            for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

               maxx=max(dfs(i,j),maxx);
               //cout<<dp[i][j]<<" ";
            }
            //cout<<endl;
            }
            cout<<name<<": "<<maxx<<endl;

    }
    //cout<<endl;
    return 0;
}
