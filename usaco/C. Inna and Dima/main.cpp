#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
vector<string> tab;
int vis[1010][1010];
int dp[1010][1010];
int res=0;
bool cycle_found=false;
int n,m;
ii start;
int xi[4]={1,0,-1,0};
int yi[4]={0,1,0,-1};
int visit_time=0;
bool inbound(int i,int j){
return (i<n&&i>=0&&j>=0&&j<m);
}
int dfs(int i,int j )
{

    if(dp[i][j]!=-1)
    return (dp[i][j]);
     vis[i][j]=1;
    int ans=0;

    for(int k=0;k<4;k++){
        int x=i+xi[k];
        int y=j+yi[k];
        if(inbound(x,y)){
            if((tab[x][y]=='D'&&tab[i][j]=='A')){
                if(vis[x][y]==1)
                {
               // cout<<" cycle found on "<<x<<" "<<y<<" comming from "<<i<<" "<<j<<endl;
                    cycle_found=true;
                    return 0;
                }
                else {
                ans=max(ans,dfs(x,y));

                }
            }


         if(vis[x][y]!=1){
                if((tab[x][y]=='I'&&tab[i][j]=='D')||(tab[x][y]=='M'&&tab[i][j]=='I'))
                {
                vis[x][y]=1;
                ans=max(ans,dfs(x,y));
                }
                if((tab[x][y]=='A'&&tab[i][j]=='M'))
                {
                vis[x][y]=1;
                ans=max(ans,1+dfs(x,y));
                }

            }

        }
    }

    vis[i][j]=2;
    if(tab[i][j]=='D')
    return dp[i][j]=ans;
    return ans;


}
int main()
{
    //freopen("in.txt","r",stdin);

    scanf("%d %d",&n,&m);
    string s;
    for(int i=0;i<n;i++){

    cin>>s;
    tab.push_back(s);
    }
    memset(dp,-1,sizeof dp);

    for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
       if(tab[i][j]=='D'&&!cycle_found)
       {

           dp[i][j]=-1;
            res=max(dfs(i,j),res);

       }
    }
    }

    if(cycle_found)
   printf("Poor Inna!\n");
    else if(res<=0)
    printf("Poor Dima!\n");
    else
    printf("%d\n",res);
    return 0;
}
